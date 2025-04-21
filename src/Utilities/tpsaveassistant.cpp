#include <QApplication>
#include <QDir>
#include <QFileIconProvider>
#include <QFileInfo>

#if QT_VERSION_MAJOR <= 5
#include <QTextCodec>
#include <QTextStream>
#endif

#include <Dialogs/TpMessageCritical>
#include <Utilities/TpSaveAssistant>
#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpSaveAssistant::TpSaveAssistant(TpMainWindow *parent)
    : QObject(parent),
    m_parent(parent)
{}

bool TpSaveAssistant::saveFile(QString filePath)
{
    DEF_SETTINGS;

    QString path = filePath;
    QFile file(path);
    QFileInfo fileInfo(file);

    if (path.isNull() || path.isEmpty())
        return false;

    if (file.open(QFile::OpenModeFlag::WriteOnly))
    {
        QTextStream textStream(&file);
#if QT_VERSION_MAJOR >= 6
        textStream.setEncoding(QStringConverter::Encoding::Utf8);
#else
        QTextCodec *textCodec = QTextCodec::codecForName("UTF-8");
        textStream.setCodec(textCodec);
#endif
        QString content = m_parent->m_widget->tabs()->tab()->tab()->text();
        textStream << content;

        QFileIconProvider fileIconProvider;
        QIcon icon = fileIconProvider.icon(fileInfo);
        QString extension = fileInfo.completeSuffix().toLower();

        TpTabWidget *tab = m_parent->m_widget->tabs()->tab();
        TpEditor *editor = tab->tab();

        editor->m_filePath = fileInfo.absoluteFilePath();
        editor->m_content = content;

        if (editor->m_untitled != -1)
            untitledList.removeOne(editor->m_untitled);

        editor->m_untitled = -1;

        emit editor->fileNameChanged(editor->m_filePath, fileInfo.fileName());

        int index = tab->currentIndex();
        tab->setTabIcon(index, icon);
        tab->setTabToolTip(index, fileInfo.absoluteFilePath());
        tab->setTabText(index, fileInfo.fileName());

        if (extensionToLanguages.keys().contains(extension))
            editor->setLexer(editor->m_lexers[extensionToLanguages[extension]]);

        if ((fileInfo.fileName() == "CMakeLists.txt")
            || (fileInfo.fileName() == "CMakeCache.txt"))
            editor->setLexer(editor->m_lexers[CMake]);
        if (content.startsWith("<?xml version="))
            editor->setLexer(editor->m_lexers[XML]);
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
            editor->setLexer(editor->m_lexers[Bash]);
        if ((content.startsWith("#!/usr/bin/python"))
            || (content.startsWith("#!/usr/bin/python3"))
            || (content.startsWith("#!/bin/python"))
            || (content.startsWith("#!/bin/python3"))
            || (content.startsWith("#!/usr/bin/env python"))
            || (content.startsWith("#!/usr/bin/env python3")))
            editor->setLexer(editor->m_lexers[Python3Extended]);
        if ((content.startsWith("#!/usr/bin/python2"))
            || (content.startsWith("#!/bin/python2"))
            || (content.startsWith("#!/usr/bin/env python2")))
            editor->setLexer(editor->m_lexers[Python2]);
        if ((content.startsWith("#!/usr/bin/perl"))
            || (content.startsWith("#!/bin/perl"))
            || (content.startsWith("#!/usr/bin/env perl")))
            editor->setLexer(editor->m_lexers[Perl]);

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
            tr("The file of the following file path could not be saved: '%1'").arg(path),
            tr(fileErrorReason(file.error()))
        );

        file.close();
        return false;
    }

    file.close();
    return true;
}

TP_END_NAMESPACE
