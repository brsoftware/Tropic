#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFileIconProvider>
#include <QFileInfo>

#if QT_VERSION_MAJOR <= 5
#include <QTextCodec>
#include <QTextStream>
#endif

#include <Dialogs/TpMessageCritical>
#include <Utilities/TpOpenAssistant>
#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpOpenAssistant::TpOpenAssistant(TpMainWindow *parent)
    : QObject(parent),
    m_parent(parent)
{}

void TpOpenAssistant::openFiles(QStringList files)
{
    for (const auto &file : std::as_const(files))
    {
        openFile(file);
    }
}

Tropic::TpEditor *TpOpenAssistant::openFile(QString path)
{
    DEF_SETTINGS;

    TpEditor *opened = nullptr;

    QFile file(path);

    if (!file.exists())
    {
        TpMessageCritical *critical = new TpMessageCritical(m_parent);
        critical->say(
            tr("File Error"),
            tr("The file of the following file path could not be opened: '%1'").arg(path),
            tr("The file does not exist on your computer.\nError code: 0x0000F001")
        );

        return opened;
    }

    if (file.open(QFile::OpenModeFlag::ReadOnly | QFile::OpenModeFlag::Text))
    {
        QTextStream textStream(&file);
#if QT_VERSION_MAJOR >= 6
        textStream.setEncoding(QStringConverter::Encoding::Utf8);
#else
        QTextCodec *textCodec = QTextCodec::codecForName("UTF-8");
        textStream.setCodec(textCodec);
#endif

        QString content = textStream.readAll();
        QFileInfo fileInfo(file);
        QString currentName = fileInfo.fileName();
        QFileIconProvider provider;
        QIcon icon = provider.icon(fileInfo);
        QString extension = fileInfo.completeSuffix().toLower();

        bool existed = false;
        QList<TpEditor*> openedDocuments = m_parent->m_widget->tabs()->tab()->acquire();

        for (const auto &editor : std::as_const(openedDocuments))
        {
            if (editor->filePath() == fileInfo.absoluteFilePath())
            {
                existed = true;
                break;
            }
        }

        if (existed)
            return opened;

        opened = m_parent->m_widget->tabs()->tab()->addEditor(path, currentName, content);
        opened->setText(content);

        if (extensionToLanguages.keys().contains(extension))
            opened->setLexer(opened->m_lexers[extensionToLanguages[extension]]);
        else
            opened->setLexer(opened->m_lexers[None]);

        if ((currentName == "CMakeLists.txt")
            || (currentName == "CMakeCache.txt"))
            opened->setLexer(opened->m_lexers[CMake]);
        if (content.startsWith("<?xml version="))
            opened->setLexer(opened->m_lexers[XML]);
        if (((content.startsWith("#include"))
             || (content.startsWith("#ifndef"))
             || (content.split("\n").at(0).toLower().contains(fileInfo.baseName().toLower())))
                && (opened->lexer() == opened->m_lexers[C]))
            opened->setLexer(opened->m_lexers[CPP]);
        if ((content.startsWith("#!/usr/bin/sh"))
            || (content.startsWith("#!/usr/bin/bash"))
            || (content.startsWith("#!/usr/bin/csh"))
            || (content.startsWith("#!/usr/bin/ksh"))
            || (content.startsWith("#!/usr/bin/tcsh"))
            || (content.startsWith("#!/usr/bin/zsh"))
            || (content.startsWith("#!/bin/sh"))
            || (content.startsWith("#!/bin/bash"))
            || (content.startsWith("#!/bin/csh"))
            || (content.startsWith("#!/bin/ksh"))
            || (content.startsWith("#!/bin/tcsh"))
            || (content.startsWith("#!/bin/zsh"))
            || (content.startsWith("#!/usr/bin/env sh"))
            || (content.startsWith("#!/usr/bin/env bash"))
            || (content.startsWith("#!/usr/bin/env csh"))
            || (content.startsWith("#!/usr/bin/env ksh"))
            || (content.startsWith("#!/usr/bin/env tcsh"))
            || (content.startsWith("#!/usr/bin/env zsh")))
            opened->setLexer(opened->m_lexers[Bash]);
        if ((content.startsWith("#!/usr/bin/python"))
            || (content.startsWith("#!/usr/bin/python3"))
            || (content.startsWith("#!/bin/python"))
            || (content.startsWith("#!/bin/python3"))
            || (content.startsWith("#!/usr/bin/env python"))
            || (content.startsWith("#!/usr/bin/env python3")))
            opened->setLexer(opened->m_lexers[Python3Extended]);
        if ((content.startsWith("#!/usr/bin/python2"))
            || (content.startsWith("#!/bin/python2"))
            || (content.startsWith("#!/usr/bin/env python2")))
            opened->setLexer(opened->m_lexers[Python2]);
        if ((content.startsWith("#!/usr/bin/perl"))
            || (content.startsWith("#!/bin/perl"))
            || (content.startsWith("#!/usr/bin/env perl")))
            opened->setLexer(opened->m_lexers[Perl]);

        SET_SETTINGS("App/CurrentDirectory", fileInfo.dir().absolutePath());

        QStringList recentFilePaths = GET_SETTINGS("App/RecentFiles", QStringList);
        recentFilePaths.removeAll(path);
        recentFilePaths.prepend(path);

        while (recentFilePaths.size() > maximumRecentFiles)
            recentFilePaths.removeLast();

        SET_SETTINGS("App/RecentFiles", recentFilePaths);

        for (QWidget *widget : qApp->topLevelWidgets())
        {
            TpMainWindow *mainWindow = qobject_cast<TpMainWindow*>(widget);

            if (mainWindow)
                mainWindow->updateRecentFiles();
        }
    }

    else
    {
        TpMessageCritical *critical = new TpMessageCritical(m_parent);
        critical->say(
            tr("File Error"),
            tr("The file of the following file path could not be opened: '%1'").arg(path),
            tr(fileErrorReason(file.error()))
        );

        return opened;
    }

    file.close();

    return opened;
}

TP_END_NAMESPACE
