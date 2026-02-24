#include <random>

#include <QClipboard>
#include <QCloseEvent>
#include <QDateTime>

#if QT_VERSION_MAJOR <= 5
#include <QTextCodec>
#include <QTextStream>
#endif

#include <Dialogs/TpDialogOpen>
#include <Dialogs/TpDialogOpenDir>
#include <Dialogs/TpDialogSave>
#include <Dialogs/TpDialogSaveCopyTo>
#include <Dialogs/TpMessageConfirmClose>
#include <Dialogs/TpMessageCritical>
#include <Utilities/TpFileSystemAssistants>
#include <Utilities/TpOpenAssistant>
#include <Utilities/TpSaveAssistant>
#include <Utilities/TpSessionThread>
#include <Views/TpCommandsView>
#include <Views/TpDocumentView>
#include <Views/TpDocumentsView>
#include <Views/TpFileView>
#include <Widgets/TpFindContainer>
#include <Widgets/TpGeneralComboBox>
#include <TpApplication>
#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

#include <Qsci/qsciscintilla.h>

TP_NAMESPACE

TpMainWindow::TpMainWindow(bool create, bool open, TpEditor *dropped, QWidget *parent)
    : QMainWindow(parent),
    m_confirmClose(new TpMessageConfirmClose(this))
{
    setAcceptDrops(true);
    setAnimated(true);
    setDockNestingEnabled(true);
    setDockOptions(AllowTabbedDocks | GroupedDragging);
    setDocumentMode(true);
    setEnabled(true);
    setObjectName("mainWindow");
    setUnifiedTitleAndToolBarOnMac(true);
    setWindowTitle(tr("[*]Tropic"));
    resize(1000, 800);

    m_menuBar = new TpMenuBar(this);
    setMenuBar(m_menuBar);

    m_widget = new TpStackedWidget(this);
    setCentralWidget(m_widget);

    m_fileDock = new TpFileDock(this);
    addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, m_fileDock);
    m_fileDock->setVisible(true);

    m_documentDock = new TpDocumentDock(this);
    addDockWidget(Qt::DockWidgetArea::LeftDockWidgetArea, m_documentDock);
    m_documentDock->setVisible(true);

    m_bookmarkDock = new TpBookmarkDock(this);
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, m_bookmarkDock);
    m_bookmarkDock->setVisible(false);

    m_findDock = new TpFindDock(this);
    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, m_findDock);
    m_findDock->setVisible(false);

    m_findInFilesDock = new TpFindInFilesDock(this);
    addDockWidget(Qt::DockWidgetArea::BottomDockWidgetArea, m_findInFilesDock);
    tabifyDockWidget(m_findDock, m_findInFilesDock);
    m_findInFilesDock->setVisible(false);

    m_findToolBar = new TpFindToolBar(this);
    addToolBar(Qt::ToolBarArea::BottomToolBarArea, m_findToolBar);
    m_findToolBar->setVisible(false);

    m_statusBar = new TpStatusBar(this);
    setStatusBar(m_statusBar);

    m_dialogCommands = new TpDialogCommands(this);
    m_dialogDocuments = new TpDialogDocuments(this);
    m_dialogGoto = new TpDialogGoto(this);
    m_dialogCharacter = new TpDialogCharacter(this);
    m_dialogSettings = new TpDialogSettings(this);

    updateSettingsPages();

    for (const auto &child : m_menuBar->children())
    {
        if (QMenu *menu = qobject_cast<QMenu*>(child))
            m_dialogCommands->view()->add(menu);
    }

    connectSignals();

    if (create)
        onAction_F_N_T(0);

    if (open)
        onAction_F_O_T(0);

    DEF_SETTINGS;

    if (GET_SETTINGS("App/Geometry", QString) != "")
        restoreState(GET_SETTINGS("App/Geometry", QByteArray));

    if (!create && !open && !dropped)
    {
        QMap<QString, QVariant> editorsMap = qvariant_cast<QMap<QString, QVariant>>(settings.value("App/Editors"));
        QMap<QString, QVariant> settingsMap =
            qvariant_cast<QMap<QString, QVariant>>(settings.value("App/EditorSettings"));

        if (!editorsMap.isEmpty())
        {
            unsigned int oldSerial = UINT_MAX;
            TpTabWidget *t = m_widget->tabs()->tab();

            for (const auto &key : editorsMap.keys())
            {
                unsigned int readingSerial = settingsMap[key].toMap().value("Parent/Serial").toUInt();
                if (oldSerial == UINT_MAX)
                    oldSerial = readingSerial;

                if (readingSerial != oldSerial)
                {
                    oldSerial = readingSerial;
                    t = new TpTabWidget(m_widget->tabs());
                    m_widget->tabs()->addTab(t);
                }

                QFile file(key);
                QFileInfo fileInfo(file);
                QString content;
                if (file.open(QFile::OpenModeFlag::ReadOnly))
                    content = file.readAll();
                TpEditor *editor
                    = t->addEditor((fileInfo.exists() ? key : ""), fileInfo.fileName(), content);
                editor->setText(editorsMap[key].toString());
                QString potentialError = editor->fromMap(settingsMap[key].toMap());

                if (!potentialError.isEmpty())
                {
                    TpMessageCritical *critical = new TpMessageCritical(this);
                    critical->genericSay(tr("Error while parsing settings file"), potentialError,
                        tr("If you have just migrated from an older version of Tropic, this should be normal."), true);
                }

                onTabChanged(t, t->currentIndex());
            }
        }

        QStringList args = qApp->arguments();
        args.takeFirst();  // [[Tropic]] executable
        QStringList filteredArgs = {};

        for (const auto &item : std::as_const(args))
        {
            if (QFile(item).exists())
                filteredArgs.append(item);
        }

        TpOpenAssistant *assistant = new TpOpenAssistant(this);
        assistant->openFiles(filteredArgs);
    }

    if (dropped)
    {
        TpTabWidget *newTab = m_widget->tabs()->tab();
        TpTabWidget *oldTab = dropped->m_parent;
        oldTab->removeEditor(dropped, true);
        newTab->addEditor(dropped);
        updateEditorsMap();
    }

    m_statusBar->setVisible(GET_SETTINGS("Windows/StatusBar", bool));
    m_menuBar->W_S->setChecked(GET_SETTINGS("Windows/StatusBar", bool));

    updateRecentFiles();
}

TpMainWindow::~TpMainWindow()
{}

Languages TpMainWindow::currentLexer() const
{
    if (m_widget->tabs()->tab()->hasTab())
        return m_widget->tabs()->tab()->tab()->currentLexer();

    return None;
}

void TpMainWindow::closeEvent(QCloseEvent *event)
{
    DEF_SETTINGS;
    SET_SETTINGS("App/Geometry", saveState());

    event->accept();
}

void TpMainWindow::onAppMessageReceived(int, QByteArray message)
{
    QList<QByteArray> split = message.split('\f');
    split.takeFirst();  // b"[[Tropic]] source file"
    QStringList filtered = {};

    for (const auto &item : std::as_const(split))
        if (QFile(QString::fromUtf8(item)).exists())
            filtered.append(QString::fromUtf8(item));

    TpOpenAssistant *assistant = new TpOpenAssistant(this);
    assistant->openFiles(filtered);
}

void TpMainWindow::onAction_F_N_T(bool)
{
    m_widget->tabs()->tab()->addEditor();
}

void TpMainWindow::onAction_F_N_W(bool)
{
    TpMainWindow *mainwindow = new TpMainWindow(true);
    mainwindow->show();
}

void TpMainWindow::onAction_F_O_T(bool)
{
    TpDialogOpen *dialog = new TpDialogOpen(this);
    dialog->exec();
}

void TpMainWindow::onAction_F_O_W(bool)
{
    TpMainWindow *mainwindow = new TpMainWindow(false, true);
    mainwindow->show();
}

void TpMainWindow::onAction_F_R(bool)
{
    TpGeneralAction *action = qobject_cast<TpGeneralAction*>(sender());

    if (action)
    {
        TpOpenAssistant *assistant = new TpOpenAssistant(this);
        assistant->openFile(action->data().toString());
    }
}

void TpMainWindow::onAction_F_R_C(bool)
{
    DEF_SETTINGS;

    SET_SETTINGS("App/RecentFiles", QStringList());

    for (const auto &item : std::as_const(m_menuBar->m_recentFileActions))
        item->setVisible(false);

    for (QWidget *widget : qApp->topLevelWidgets())
    {
        TpMainWindow *mainWindow = qobject_cast<TpMainWindow*>(widget);

        if (mainWindow)
            mainWindow->updateRecentFiles();
    }
}

void TpMainWindow::onAction_F_R_O(bool)
{
    for (const auto &item : std::as_const(m_menuBar->m_recentFileActions))
    {
        if (item->data().toString() == "")
            break;

        if (item->isVisible())
        {
            TpOpenAssistant *assistant = new TpOpenAssistant(this);
            assistant->openFile(item->data().toString());
        }
    }
}

void TpMainWindow::onAction_F_R_L(bool)
{
    TpOpenAssistant *assistant = new TpOpenAssistant(this);
    assistant->openFile(m_menuBar->m_recentFileActions.at(0)->data().toString());
}

void TpMainWindow::onAction_F_U(bool)
{
    m_dialogDocuments->exec();
}

void TpMainWindow::onAction_F_T_F(bool)
{
    revealInExplorer(m_widget->tabs()->tab()->tab()->m_filePath);
}

void TpMainWindow::onAction_F_T_C(bool)
{
    openInCMD(m_widget->tabs()->tab()->tab()->m_filePath);
}

void TpMainWindow::onAction_F_T_T(bool)
{
    TpFileView *view = m_fileDock->fileView();
    view->fileModel()->setRootPath(QDir::rootPath());
    QString dir = QFileInfo(QFile(m_widget->tabs()->tab()->tab()->m_filePath)).path();
    view->setRootIndex(view->fileModel()->index(dir));
    DEF_SETTINGS;
    SET_SETTINGS("App/BrowserDirectory", dir);
    m_fileDock->setVisible(true);
}

void TpMainWindow::onAction_F_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->beginUndoAction();

        const QString &path = editor->m_filePath;

        QFile file(path);

        if (!file.exists())
        {
            TpMessageCritical *critical = new TpMessageCritical(this);
            critical->say(
                tr("File Error"),
                tr("The file of the following file path could not be reloaded: '%1'").arg(path),
                tr("The file does not exist on your computer.\nError code: 0x0000F001")
            );
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
            editor->clear();
            editor->insert(content);
        }

        else
        {
            TpMessageCritical *critical = new TpMessageCritical(this);
            critical->say(
                tr("File Error"),
                tr("The file of the following file path could not be reloaded: '%1'").arg(path),
                tr(fileErrorReason(file.error()))
            );
        }

        file.close();

        editor->endUndoAction();
        updateEditorsMap();
    }
}

void TpMainWindow::onAction_F_D(bool)
{
    revealInDefaultViewer(m_widget->tabs()->tab()->tab()->m_filePath);
}

void TpMainWindow::onAction_F_B_R(bool)
{
    QString path = m_widget->tabs()->tab()->tab()->m_filePath;
    TpFileView *view = m_fileDock->fileView();
    m_fileDock->setVisible(true);
    QModelIndex index = view->fileModel()->index(path);
    DEF_SETTINGS;
    SET_SETTINGS("App/BrowserDirectory", path);

    if (path.startsWith(view->fileModel()->filePath(view->rootIndex())))
    {
        view->expand(index);
        view->edit(index);
    }

    else
    {
        TpMessageCritical *critical = new TpMessageCritical(this);
        critical->say(
            tr("File Error"),
            tr("The file of the following file path could not be renamed: '%1'").arg(path),
            tr("You have not opened the corresponding directory in the Tropic File Browser to let it rename your file "
               "%1 yet.\nError code: 0x0000B001").arg(path)
        );
    }
}

void TpMainWindow::onAction_F_B_D(bool)
{
    QString path = m_widget->tabs()->tab()->tab()->m_filePath;
    QFile file(path);

    if (!file.moveToTrash())
    {
        TpMessageCritical *critical = new TpMessageCritical(this);
        critical->say(
            tr("File Error"),
            tr("The file of the following file path could not be deleted: '%1'").arg(path),
            tr(fileErrorReason(file.error()))
        );
    }
}

void TpMainWindow::onAction_F_B_F(bool)
{
    QString path = QFileInfo(QFile(m_widget->tabs()->tab()->tab()->m_filePath)).fileName();
    QClipboard *clipboard = qApp->clipboard();
    clipboard->setText(path, QClipboard::Mode::Clipboard);
}

void TpMainWindow::onAction_F_B_A(bool)
{
    QString path = m_widget->tabs()->tab()->tab()->m_filePath;
    QClipboard *clipboard = qApp->clipboard();
    clipboard->setText(path, QClipboard::Mode::Clipboard);
}

void TpMainWindow::onAction_F_B_N(bool)
{
    QString path = QFileInfo(QFile(m_widget->tabs()->tab()->tab()->m_filePath)).path();
    QClipboard *clipboard = qApp->clipboard();
    clipboard->setText(path, QClipboard::Mode::Clipboard);
}

void TpMainWindow::onAction_F_W(bool)
{
    TpDialogOpenDir *dialog = new TpDialogOpenDir(this);
    dialog->exec();
}

bool TpMainWindow::onAction_F_S(bool)
{
    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());

    if (m_widget->tabs()->tab()->tab()->m_filePath != "")
    {
        QString file = m_widget->tabs()->tab()->tab()->m_filePath;
        TpSaveAssistant *assistant = new TpSaveAssistant(this);
        return assistant->saveFile(file);
    }

    else
    {
        return onAction_F_A(0);
    }
}

bool TpMainWindow::onAction_F_A(bool)
{
    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());

    TpDialogSave *dialog = new TpDialogSave(this);
    dialog->exec();
    return dialog->successful();
}

bool TpMainWindow::onAction_F_Y(bool)
{
    TpDialogSaveCopyTo *dialog = new TpDialogSaveCopyTo(this);
    dialog->exec();
    return dialog->successful();
}

void TpMainWindow::onAction_F_d(bool)
{
    for (auto &i : m_widget->tabs()->tab()->acquire(TpTabWidget::AllEditors))
    {
        m_widget->tabs()->tab()->setCurrentWidget(i);
        m_widget->tabs()->tab()->currentWidget()->setFocus();

        onAction_F_S(0);
    }
}

int TpMainWindow::onAction_F_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (editor)
    {
        bool isSame = (editor->content() == editor->text());

        if (!isSame)
        {
            switch (m_confirmClose->say())
            {
            case TpMessageConfirmClose::Save:
                if (!onAction_F_S(0))
                    return TpMessageConfirmClose::Cancel;
            case TpMessageConfirmClose::Cancel:
                return TpMessageConfirmClose::Cancel;
            }
        }

        DEF_SETTINGS;

        QMap<QString, QVariant> editors = qvariant_cast<QMap<QString, QVariant>>(settings.value("App/Editor"));
        QMap<QString, QVariant> editorSettings
            = qvariant_cast<QMap<QString, QVariant>>(settings.value("App/EditorSettings"));
        QString key = (editor->filePath() == "") ? (tr("Untitled %1").arg(editor->m_untitled)) : editor->filePath();

        if (editors.contains(key))
        {
            editors.remove(key);
        }

        if (editorSettings.contains(key))
        {
            editorSettings.remove(key);
        }

        SET_SETTINGS("App/Editors", editors);
        SET_SETTINGS("App/EditorSettings", editors);

        m_widget->tabs()->tab()->removeEditor(editor);

        if (tab)
        {
            if (tab->count() <= 0)
            {
                m_widget->tabs()->removeTab(tab);
                if (m_widget->tabs()->m_tabs.length() >= 1)
                    m_widget->tabs()->m_tabs.last()->setFocus();
                return TpMessageConfirmClose::Discard;
            }
        }

        if (m_widget->tabs()->tab())
            if (m_widget->tabs()->tab()->tab())
                m_widget->tabs()->tab()->tab()->setFocus();

        emit m_widget->tabs()->tab()->tabNameChanged();

        return TpMessageConfirmClose::Discard;
    }

    return TpMessageConfirmClose::Cancel;
}

void TpMainWindow::onAction_F_L(bool)
{
    for (auto &i : m_widget->tabs()->m_tabs)
    {
        if (i->isVisible())
        {
            i->currentWidget()->setFocus();

            TpTabWidget *currentTab = m_widget->tabs()->tab();

            for (auto &i : currentTab->acquire(TpTabWidget::AllEditors))
            {
                currentTab->setCurrentWidget(i);
                currentTab->currentWidget()->setFocus();

                onAction_F_C(0);
            }
        }
    }

    if (!m_widget->tabs()->hasTab())
        m_widget->setCurrentIndex(0);
}

void TpMainWindow::onAction_F_p(bool)
{
    TpTabWidget *currentTab = m_widget->tabs()->tab();
    TpEditor *current = currentTab->tab();

    for (auto &i : currentTab->acquire(TpTabWidget::AllEditors))
    {
        currentTab->setCurrentWidget(i);
        currentTab->currentWidget()->setFocus();

        onAction_F_C(0);
    }

    if (currentTab == m_widget->tabs()->tab())
    {
        if (currentTab->hasTab())
        {
            if (currentTab->contains(current))
            {
                currentTab->setCurrentIndex(currentTab->indexOf(current));
                current->setFocus();
            }
        }

        else
        {
            currentTab->hide();
            emit currentTab->tabNameChanged();

            bool allInvisible = true;

            for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
            {
                if (!m_widget->tabs()->m_tabs.at(index)->isHidden())
                {
                    allInvisible = false;
                    break;
                }
            }

            if (allInvisible)
                m_widget->setCurrentIndex(0);
            else
                m_widget->tabs()->tab()->currentWidget()->setFocus();
        }
    }
}

void TpMainWindow::onAction_F_M_B(bool)
{
    TpTabWidget *currentTab = m_widget->tabs()->tab();
    TpEditor *current = currentTab->tab();

    for (auto &i : currentTab->acquire(TpTabWidget::ExceptCurrent))
    {
        currentTab->setCurrentWidget(i);
        currentTab->currentWidget()->setFocus();

        onAction_F_C(0);
    }

    if (currentTab == m_widget->tabs()->tab())
    {
        if (currentTab->hasTab())
        {
            if (currentTab->contains(current))
            {
                currentTab->setCurrentIndex(currentTab->indexOf(current));
                current->setFocus();
            }
        }

        else
        {
            currentTab->hide();
            emit currentTab->tabNameChanged();

            bool allInvisible = true;

            for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
            {
                if (!m_widget->tabs()->m_tabs.at(index)->isHidden())
                {
                    allInvisible = false;
                    break;
                }
            }

            if (allInvisible)
                m_widget->setCurrentIndex(0);
            else
                m_widget->tabs()->tab()->currentWidget()->setFocus();
        }
    }
}

void TpMainWindow::onAction_F_M_L(bool)
{
    TpTabWidget *currentTab = m_widget->tabs()->tab();
    TpEditor *current = currentTab->tab();

    for (auto &i : currentTab->acquire(TpTabWidget::ToTheLeft))
    {
        currentTab->setCurrentWidget(i);
        currentTab->currentWidget()->setFocus();

        onAction_F_C(0);
    }

    if (currentTab == m_widget->tabs()->tab())
    {
        if (currentTab->hasTab())
        {
            if (currentTab->contains(current))
            {
                currentTab->setCurrentIndex(currentTab->indexOf(current));
                current->setFocus();
            }
        }

        else
        {
            currentTab->hide();
            emit currentTab->tabNameChanged();

            bool allInvisible = true;

            for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
            {
                if (!m_widget->tabs()->m_tabs.at(index)->isHidden())
                {
                    allInvisible = false;
                    break;
                }
            }

            if (allInvisible)
                m_widget->setCurrentIndex(0);
            else
                m_widget->tabs()->tab()->currentWidget()->setFocus();
        }
    }
}

void TpMainWindow::onAction_F_M_R(bool)
{
    TpTabWidget *currentTab = m_widget->tabs()->tab();
    TpEditor *current = currentTab->tab();

    for (auto &i : currentTab->acquire(TpTabWidget::ToTheRight))
    {
        currentTab->setCurrentWidget(i);
        currentTab->currentWidget()->setFocus();

        onAction_F_C(0);
    }

    if (currentTab == m_widget->tabs()->tab())
    {
        if (currentTab->hasTab())
        {
            if (currentTab->contains(current))
            {
                currentTab->setCurrentIndex(currentTab->indexOf(current));
                current->setFocus();
            }
        }

        else
        {
            currentTab->hide();
            emit currentTab->tabNameChanged();

            bool allInvisible = true;

            for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
            {
                if (!m_widget->tabs()->m_tabs.at(index)->isHidden())
                {
                    allInvisible = false;
                    break;
                }
            }

            if (allInvisible)
                m_widget->setCurrentIndex(0);
            else
                m_widget->tabs()->tab()->currentWidget()->setFocus();
        }
    }
}

void TpMainWindow::onAction_F_M_U(bool)
{
    TpTabWidget *currentTab = m_widget->tabs()->tab();
    TpEditor *current = currentTab->tab();

    for (auto &i : currentTab->acquire(TpTabWidget::Unchanged))
    {
        currentTab->setCurrentWidget(i);
        currentTab->currentWidget()->setFocus();

        onAction_F_C(0);
    }

    if (currentTab == m_widget->tabs()->tab())
    {
        if (currentTab->hasTab())
        {
            if (currentTab->contains(current))
            {
                currentTab->setCurrentIndex(currentTab->indexOf(current));
                current->setFocus();
            }
        }

        else
        {
            currentTab->hide();
            emit currentTab->tabNameChanged();

            bool allInvisible = true;

            for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
            {
                if (!m_widget->tabs()->m_tabs.at(index)->isHidden())
                {
                    allInvisible = false;
                    break;
                }
            }

            if (allInvisible)
                m_widget->setCurrentIndex(0);
            else
                m_widget->tabs()->tab()->currentWidget()->setFocus();
        }
    }
}

void TpMainWindow::onAction_F_Q(bool)
{
    QApplication::quit();
}

void TpMainWindow::onAction_E_L_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    int currentLine = firstLine;
    QSet<QString> setOfLines;
    editor->beginUndoAction();

    while (currentLine <= lastLine && currentLine < editor->lines())
    {
        const int sizeBefore = setOfLines.size();
        setOfLines.insert(editor->text(currentLine));

        if (sizeBefore == setOfLines.size())
        {
            editor->setCursorPosition(currentLine, 0);
            editor->SendScintilla(TpEditor::SCI_LINEDELETE);

            lastLine--;
        }

        else
        {
            currentLine++;
        }
    }

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_L_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    int currentLine = firstLine;
    QString prev, cur;

    editor->beginUndoAction();

    while (currentLine <= lastLine && currentLine < editor->lines())
    {
        prev = cur;
        cur = editor->text(currentLine);

        if (currentLine != firstLine && prev == cur)
        {
            editor->setCursorPosition(currentLine, 0);
            editor->SendScintilla(TpEditor::SCI_LINEDELETE);
            lastLine--;
        }

        else
        {
            currentLine++;
        }
    }

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_L_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    int currentLine = firstLine;
    editor->beginUndoAction();

    while (currentLine <= lastLine && currentLine < editor->lines())
    {
        if (editor->text(currentLine) == editor->eolChar())
        {
            editor->setCursorPosition(currentLine, 0);
            editor->SendScintilla(TpEditor::SCI_LINEDELETE);
            lastLine--;
        }

        else
        {
            currentLine++;
        }
    }

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_L_B(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    editor->beginUndoAction();

    for (int line = lastLine; line >= firstLine; line--)
    {
        if (line >= editor->lines())
            continue;

        if (editor->text(line).simplified().isEmpty())
        {
            editor->setCursorPosition(line, 0);
            editor->SendScintilla(TpEditor::SCI_LINEDELETE);
        }
    }

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_L_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    QList<QString> lines;
    lines.reserve(lastLine - firstLine + 1);

    for (int line = firstLine; line <= lastLine; line++)
        lines.append(editor->text(line));

    std::reverse(lines.begin(), lines.end());

    editor->beginUndoAction();

    editor->setSelection(firstLine, 0, lastLine + 1, 0);
    editor->removeSelectedText();
    editor->insert(lines.join(""));

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_L_Z(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    QList<QString> lines;
    lines.reserve(lastLine - firstLine + 1);

    for (int line = firstLine; line <= lastLine; line++)
        lines.append(editor->text(line));

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(lines.begin(), lines.end(), g);

    editor->beginUndoAction();

    editor->setSelection(firstLine, 0, lastLine + 1, 0);
    editor->removeSelectedText();
    editor->insert(lines.join(""));

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_W_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    editor->beginUndoAction();

    for (int line = firstLine; line <= lastLine && line < editor->lines(); line++)
    {
        QString text = editor->text(line);
        if (text.length() < 2)
            continue;

        int last = text.length() - 1;
        while (last >= 0 && (text.at(last) == '\r' || text.at(last) == '\n'))
            --last;

        int trimPos = last;
        while (trimPos >= 0 && text.at(trimPos).isSpace() && text.at(trimPos) != '\r' && text.at(trimPos) != '\n')
            --trimPos;

        if (trimPos < last)
        {
            editor->setCursorPosition(line, trimPos + 1);
            for (int pos = trimPos + 1; pos <= last; pos++)
                editor->SendScintilla(TpEditor::SCI_CLEAR);
        }
    }

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_W_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    editor->beginUndoAction();

    for (int line = firstLine; line <= lastLine && line < editor->lines(); line++)
    {
        QString text = editor->text(line);
        if (text.length() < 2)
            continue;

        editor->setCursorPosition(line, 0);

        QChar ch = editor->charAt(editor->getPosition());

        while (ch.isSpace() && ch != '\r' && ch != '\n')
        {
            editor->SendScintilla(TpEditor::SCI_CLEAR);
            ch = editor->charAt(editor->getPosition());
        }
    }

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_W_B(bool)
{
    onAction_E_W_T(false);
    onAction_E_W_L(false);
}

void TpMainWindow::onAction_E_W_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    editor->beginUndoAction();

    editor->setSelection(firstLine, 0, lastLine + 1, 0);
    QString text = editor->selectedText();
    text.replace("\t", QString(editor->tabWidth(), ' '));
    editor->removeSelectedText();
    editor->insert(text);

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_W_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    editor->beginUndoAction();

    editor->setSelection(firstLine, 0, lastLine + 1, 0);
    QString text = editor->selectedText();
    text.replace(QString(editor->tabWidth(), ' '), "\t");
    editor->removeSelectedText();
    editor->insert(text);

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_W_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    if (!editor)
        return;

    int firstLine, lastLine;
    editor->selectionLineRange(firstLine, lastLine);

    editor->beginUndoAction();
    const int tabWidth = editor->tabWidth();

    for (int line = firstLine; line <= lastLine && line < editor->lines(); line++)
    {
        QString text = editor->text(line);
        if (text.length() < 2)
            continue;

        int indentChars = 0;
        while (indentChars < text.size() && (text.at(indentChars) == ' ' || text.at(indentChars) == '\t'))
            indentChars++;
        if (indentChars == 0)
            continue;

        QString snippet = text.left(indentChars);
        int spaces = snippet.count(' ');
        int tabs = snippet.count('\t');

        QString replacement;
        replacement.reserve(indentChars);

        if (tabWidth > 0)
        {
            int tabsFromSpaces = spaces / tabWidth;
            int remainingSpaces = spaces % tabWidth;
            replacement += QString(tabsFromSpaces, '\t');
            replacement += QString(tabs, '\t');
            replacement += QString(remainingSpaces, ' ');
        }

        else
        {
            replacement = snippet;
        }

        editor->setSelection(line, 0, line, indentChars);
        editor->removeSelectedText();
        editor->insert(replacement);
    }

    editor->endUndoAction();
}

void TpMainWindow::onAction_E_E_F(bool)
{
    m_findDock->setVisible(true);
    m_findDock->container()->m_findEdit->setFocus();
}

void TpMainWindow::onAction_E_E_N(bool)
{
    if (m_findToolBar->m_findEdit->hasFocus() && m_findDock->container())
    {
        m_widget->tabs()->tab()->tab()->findFirst(
            m_findToolBar->m_findEdit->text(),
            m_findDock->container()->m_checkSimpleRegex->isChecked(),
            m_findDock->container()->m_checkCase->isChecked(),
            m_findDock->container()->m_checkWord->isChecked(),
            m_findDock->container()->m_checkWrap->isChecked(),
            true, -1, -1, true,
            m_findDock->container()->m_checkPosixRegex->isChecked(),
            m_findDock->container()->m_checkCppRegex->isChecked()
        );
    }

    else
    {
        if (m_findDock->container())
            m_findDock->container()->onFindButtonClicked(0);
    }
}

void TpMainWindow::onAction_E_E_P(bool)
{
    if (m_findToolBar->m_findEdit->hasFocus() && m_findDock->container())
    {
        m_widget->tabs()->tab()->tab()->findFirst(
            m_findToolBar->m_findEdit->text(),
            m_findDock->container()->m_checkSimpleRegex->isChecked(),
            m_findDock->container()->m_checkCase->isChecked(),
            m_findDock->container()->m_checkWord->isChecked(),
            m_findDock->container()->m_checkWrap->isChecked(),
            false, -1, -1, true,
            m_findDock->container()->m_checkPosixRegex->isChecked(),
            m_findDock->container()->m_checkCppRegex->isChecked()
        );
    }

    else
    {
        if (m_findDock->container())
        {
            m_findDock->container()->m_checkPrevious->setChecked(true);
            m_findDock->container()->onFindButtonClicked(0);
        }
    }
}

void TpMainWindow::onAction_E_E_X(bool)
{
    if (m_findToolBar->m_findEdit->hasFocus() && m_findDock->container())
    {
        m_widget->tabs()->tab()->tab()->findFirstInSelection(
            m_findToolBar->m_findEdit->text(),
            m_findDock->container()->m_checkSimpleRegex->isChecked(),
            m_findDock->container()->m_checkCase->isChecked(),
            m_findDock->container()->m_checkWord->isChecked(),
            true, true,
            m_findDock->container()->m_checkPosixRegex->isChecked(),
            m_findDock->container()->m_checkCppRegex->isChecked()
        );
    }

    else
    {
        if (m_findDock->container())
        {
            m_findDock->container()->m_checkSelection->setChecked(true);
            m_findDock->container()->onFindButtonClicked(0);
        }
    }
}

void TpMainWindow::onAction_E_E_U(bool)
{
    if (m_findToolBar->m_findEdit->hasFocus() && m_findDock->container())
    {
        m_widget->tabs()->tab()->tab()->findFirstInSelection(
            m_findToolBar->m_findEdit->text(),
            m_findDock->container()->m_checkSimpleRegex->isChecked(),
            m_findDock->container()->m_checkCase->isChecked(),
            m_findDock->container()->m_checkWord->isChecked(),
            false, true,
            m_findDock->container()->m_checkPosixRegex->isChecked(),
            m_findDock->container()->m_checkCppRegex->isChecked()
        );
    }

    else
    {
        if (m_findDock->container())
        {
            m_findDock->container()->m_checkPrevious->setChecked(true);
            m_findDock->container()->m_checkSelection->setChecked(true);
            m_findDock->container()->onFindButtonClicked(0);
        }
    }
}

void TpMainWindow::onAction_E_E_L(bool)
{
    m_findToolBar->setVisible(true);
    m_findToolBar->m_findEdit->setFocus();
}

void TpMainWindow::onAction_E_E_G(bool)
{
    m_dialogGoto->exec();
}

void TpMainWindow::onAction_E_E_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->moveToMatchingBrace();
    }
}

void TpMainWindow::onAction_E_E_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->selectToMatchingBrace();
    }
}

void TpMainWindow::onAction_E_B_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    editor->onMarginClicked(1, editor->currentLine(), Qt::KeyboardModifier::NoModifier);
}

void TpMainWindow::onAction_E_B_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    editor->setCurrentLine(editor->markerFindNext(
        editor->currentLine() + (m_menuBar->E_B_T->isChecked() ? 1 : 0),
        (editor->marginMarkerMask(1) & (editor->m_bookmarkMarker + 1)))
    );
}

void TpMainWindow::onAction_E_B_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    editor->setCurrentLine(editor->markerFindPrevious(
        editor->currentLine() - (m_menuBar->E_B_T->isChecked() ? 1 : 0),
        (editor->marginMarkerMask(1) & (editor->m_bookmarkMarker + 1)))
    );
}

void TpMainWindow::onAction_E_B_C(bool isChecked)
{
    QString bookmarked = onAction_E_B_A(isChecked);
    QClipboard *clipboard = qApp->clipboard();

    if (bookmarked != "")
        clipboard->setText(bookmarked);
}

void TpMainWindow::onAction_E_B_O(bool)
{
    QString bookmarked = "";
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    const QString content = editor->text();
    int lines = editor->lines();

    for (int line = 0; line < lines; line++)
    {
        if (editor->markersAtLine(line) & (editor->m_bookmarkMarker + 1))
        {
            bookmarked += content.split('\n').at(line);
            bookmarked += '\n';
        }
    }

    QClipboard *clipboard = qApp->clipboard();

    if (bookmarked != "")
        clipboard->setText(bookmarked);
}

void TpMainWindow::onAction_E_B_R(bool)
{
    m_widget->tabs()->tab()->tab()->markerDeleteAll(m_widget->tabs()->tab()->tab()->m_bookmarkMarker);
}

QString TpMainWindow::onAction_E_B_A(bool)
{
    QString bookmarked = "";
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    int lines = editor->lines();

    editor->beginUndoAction();

    for (int line = 0; line < lines; line++)
    {
        editor->setCurrentLine(line);

        if (editor->markersAtLine(line) & (editor->m_bookmarkMarker + 1))
        {
            // To not contaminate the other lines
            editor->markerDelete(line);

            editor->SendScintilla(TpEditor::SCI_LINEENDEXTEND);
            editor->SendScintilla(TpEditor::SCI_CHARRIGHTEXTEND);
            bookmarked += (editor->selectedText());
            editor->removeSelectedText();
            line--;
        }
    }

    editor->endUndoAction();

    editor->adjustBookmarks();

    return bookmarked;
}

QString TpMainWindow::onAction_E_B_h(bool)
{
    QString bookmarked = "";
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    int lines = editor->lines();

    editor->beginUndoAction();

    for (int line = 0; line < lines; line++)
    {
        editor->setCurrentLine(line);

        if (!(editor->markersAtLine(line) & (editor->m_bookmarkMarker + 1)))
        {
            editor->SendScintilla(TpEditor::SCI_LINEENDEXTEND);
            editor->SendScintilla(TpEditor::SCI_CHARRIGHTEXTEND);
            bookmarked += (editor->selectedText());
            editor->removeSelectedText();
        }
    }

    editor->endUndoAction();

    editor->adjustBookmarks();

    return bookmarked;
}

void TpMainWindow::onAction_E_B_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    for (int line = 0; line < editor->lines(); line++)
    {
        if (editor->markersAtLine(line) & (editor->m_bookmarkMarker + 1))
            editor->markerDelete(line, editor->m_bookmarkMarker);
        else
            editor->markerAdd(line, editor->m_bookmarkMarker);
    }

    editor->adjustBookmarks();
}

void TpMainWindow::onAction_V_A(bool isChecked)
{
    if (isChecked)
        setWindowFlags(Qt::WindowType::WindowStaysOnTopHint | windowFlags());
    else
        setWindowFlag(Qt::WindowType::WindowStaysOnTopHint, false);

    show();
}

void TpMainWindow::onAction_V_F(bool isChecked)
{
    if (isChecked)
        showFullScreen();
    else
        showNormal();
}

void TpMainWindow::onAction_V_h(bool isChecked)
{
    if (isChecked)
        setWindowFlags(Qt::WindowType::FramelessWindowHint | windowFlags());
    else
        setWindowFlag(Qt::WindowType::FramelessWindowHint, false);

    show();
}

void TpMainWindow::onAction_V_L_M(bool)
{
    TpTabWidget *oldTab = m_widget->tabs()->tab();

    if (!oldTab || oldTab->count() <= 1)
        return;

    TpEditor *editor = oldTab->tab();
    TpTabSplitter *splitter = m_widget->tabs();

    if (!editor)
        return;

    TpTabWidget *newTab = new TpTabWidget(splitter);
    splitter->addTab(newTab);
    oldTab->removeEditor(editor, true);
    newTab->addEditor(editor);

    updateEditorsMap();
    splitter->update();
    m_widget->update();
}

void TpMainWindow::onAction_V_L_T(bool)
{
    if (m_widget->tabs()->m_tabs.size() < 2)
        return;

    TpTabWidget *oldTab = m_widget->tabs()->tab();

    if (!oldTab || oldTab->count() <= 1)
        return;

    TpEditor *editor = oldTab->tab();
    if (!editor)
        return;

    TpTabSplitter *splitter = m_widget->tabs();
    int index = splitter->m_tabs.indexOf(oldTab) + 1;
    if (index >= splitter->m_tabs.size())
        index = 0;

    TpTabWidget *newTab = splitter->m_tabs[index];
    oldTab->removeEditor(editor, true);
    newTab->addEditor(editor);

    if (oldTab->count() == 0)
        splitter->removeTab(oldTab);

    editor->setFocus();

    updateEditorsMap();
}

void TpMainWindow::onAction_V_L_C(bool)
{
    bool createNew = m_widget->tabs()->m_tabs.size() < 2;
    TpEditor *curTab = m_widget->tabs()->tab()->tab();
    TpTabSplitter *splitter = m_widget->tabs();
    TpTabWidget *toTab;

    if (!curTab)
        return;

    if (createNew)
    {
        toTab = new TpTabWidget(m_widget->tabs());
        m_widget->tabs()->addTab(toTab);
    }

    else
    {
        int index = splitter->m_tabs.indexOf(curTab->m_parent);
        if (index >= splitter->m_tabs.size())
            index = 0;
        toTab = m_widget->tabs()->m_tabs.at(index);
    }

    TpEditor *cloned = curTab->cloneEditor(toTab);
    toTab->addEditor(cloned);

    cloned->setFocus();
    updateEditorsMap();
}

void TpMainWindow::onAction_V_I(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLineNumbers(isChecked);
        SET_SETTINGS("View/LineNumbers", isChecked);
    }
}

void TpMainWindow::onAction_W_F(bool isChecked)
{
    m_fileDock->setVisible(isChecked);
}

void TpMainWindow::onAction_W_L(bool isChecked)
{
    m_documentDock->setVisible(isChecked);
}

void TpMainWindow::onAction_W_B(bool isChecked)
{
    m_bookmarkDock->setVisible(isChecked);
}

void TpMainWindow::onAction_W_D(bool isChecked)
{
    m_findDock->setVisible(isChecked);
}

void TpMainWindow::onAction_W_I(bool isChecked)
{
    m_findInFilesDock->setVisible(isChecked);
}

void TpMainWindow::onAction_W_S(bool isChecked)
{
    DEF_SETTINGS;
    m_statusBar->setVisible(isChecked);
    SET_SETTINGS("Windows/StatusBar", isChecked);
}

void TpMainWindow::onEditorFileNameChanged(const QString &path, const QString &name)
{
    (void) path;
    (void) name;

    updateDocumentDock();
}

void TpMainWindow::onEditorCheckBoxChecked(bool)
{
    DEF_SETTINGS;
    bool noRe, simpleRe, posixRe, cppRe, cs, wo, wrap, show, prev;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            simpleRe = container->m_checkSimpleRegex->isChecked();
            posixRe = container->m_checkPosixRegex->isChecked();
            cppRe = container->m_checkCppRegex->isChecked();
            noRe = !(simpleRe) && !(posixRe) && !(cppRe);
            cs = container->m_checkCase->isChecked();
            wo = container->m_checkWord->isChecked();
            wrap = container->m_checkWrap->isChecked();
            show = container->m_checkShow->isChecked();
            prev = container->m_checkPrevious->isChecked();

            m_menuBar->T_S_R_N->setChecked(noRe);
            m_menuBar->T_S_R_S->setChecked(simpleRe);
            m_menuBar->T_S_R_P->setChecked(posixRe);
            m_menuBar->T_S_R_pl->setChecked(cppRe);
            m_menuBar->T_S_C->setChecked(cs);
            m_menuBar->T_S_O->setChecked(wo);
            m_menuBar->T_S_W->setChecked(wrap);
            m_menuBar->T_S_S->setChecked(show);
            m_menuBar->T_S_G->setChecked(prev);

            SET_SETTINGS("Tools/Search/RegularExpression/No", noRe);
            SET_SETTINGS("Tools/Search/RegularExpression/Simple", simpleRe);
            SET_SETTINGS("Tools/Search/RegularExpression/POSIX", posixRe);
            SET_SETTINGS("Tools/Search/RegularExpression/C++", cppRe);
            SET_SETTINGS("Tools/Search/Casesensitive", cs);
            SET_SETTINGS("Tools/Search/WholeWordOnly", wo);
            SET_SETTINGS("Tools/Search/WordWrap", wrap);
            SET_SETTINGS("Tools/Search/Show", show);
            SET_SETTINGS("Tools/Search/GoPrevious", prev);
        }
    }
}

void TpMainWindow::onEditorSelectionChanged()
{
    if (m_widget->tabs()->tab())
    {
        if (m_widget->tabs()->tab()->tab())
        {
            const QString &selectedText = m_widget->tabs()->tab()->tab()->selectedText();
            updateIncrementalSearch(selectedText);

            m_widget->tabs()->tab()->tab()->adjustBookmarks();

            int line = 0;
            int index = 0;

            m_widget->tabs()->tab()->tab()
                    ->lineIndexFromPosition(m_widget->tabs()->tab()->tab()->getPosition(), &line, &index);
            onEditorPositionChanged(m_widget->tabs()->tab()->tab()->getPosition(), line, index);
        }
    }
}

void TpMainWindow::onEditorPositionChanged(int position, int line, int index)
{
    if (m_widget->tabs()->tab())
    {
        TpEditor *editor = m_widget->tabs()->tab()->tab();

        if (editor)
        {
            m_menuBar->E_B_T->setChecked(editor->markersAtLine(line) & (editor->m_bookmarkMarker + 1));

            m_statusBar->m_labelStats
                    ->setText(tr("Length: %1, Lines: %2").arg(m_widget->tabs()->tab()->tab()->getLength())
                              .arg(m_widget->tabs()->tab()->tab()->lines()));
            m_statusBar->m_labelPosition->setText(tr("Position: %1").arg(position + 1));
            m_statusBar->m_labelLineAndColumn->setText(tr("Line: %1, Column: %2").arg(line + 1).arg(index + 1));
        }
    }
}

void TpMainWindow::onEditorPunctuation()
{
    updateEditorsMap();
}

void TpMainWindow::onEditorTextChanged()
{
    TpTabWidget *t = m_widget->tabs()->tab();
    TpEditor *ed = t->tab();

    if (!ed)
    {
        setWindowTitle(tr("[*]Tropic"));
        setWindowModified(false);
        return;
    }

    bool mod = false;
    QString pristine = t->tabText(t->currentIndex());
    if (pristine.startsWith("*"))
        pristine.removeFirst();
    QString modified = "*" + pristine;
    t->setTabText(t->currentIndex(), ((mod = (ed->text() != ed->m_content)) ? modified : pristine));
    setWindowModified(mod);
}

void TpMainWindow::onTabChanged(TpTabWidget *tab, int index)
{
    if (tab)
    {
        if (tab->tab())
        {
            tab->tab()->setFocus();
            // tab->tab()->fromMap(tab->tab()->m_config);

            int line = 0;
            int index = 0;

            tab->tab()->lineIndexFromPosition(tab->tab()->getPosition(), &line, &index);
            onEditorPositionChanged(tab->tab()->getPosition(), line, index);
            onEditorTextChanged();

            m_statusBar->m_spinBoxTabWidth->setValue(tab->tab()->indentationWidth());
            m_statusBar->m_comboBoxLang->setCurrentText(m_statusBar->iteratedLangMap[tab->tab()->currentLexer()]);
            m_statusBar->m_comboBoxNewLine->setCurrentText(m_statusBar->comboBoxNewLineItems[tab->tab()->eolMode()]);

            setWindowTitle(tr("%1[*] - Tropic").arg(tab->tab()->m_filePath.isEmpty()
                ? tr("Untitled %1").arg(tab->tab()->m_untitled) : tab->tab()->m_filePath));
            setWindowFilePath(tab->tab()->m_filePath);

            updateEditorsMap();

            m_bookmarkDock->setView(tab->tab()->m_bookmarkView);
            m_findDock->setContainer(tab->tab()->m_findContainer);
        }

        else
        {
            setWindowModified(false);
            setWindowTitle(tr("[*]Tropic"));
            setWindowFilePath("");

            m_statusBar->m_labelStats->setText(tr("Statistics not available"));
            m_statusBar->m_labelPosition->setText(tr("Positions not available"));
            m_statusBar->m_labelLineAndColumn->setText(tr("Information not available"));
            m_bookmarkDock->setView(nullptr);
            m_findDock->setContainer(nullptr);
        }

        m_menuBar->updateGeneralAccessibility(tab->hasTab(), (tab->hasTab() ? (tab->tab()->filePath() != "") : false));
        m_menuBar->updateCheckability(tab);
        m_statusBar->updateAccessibility(tab->hasTab());

        updateDocumentDock();
        updateDocumentsDialog();
    }
}

void TpMainWindow::onTabCloseRequested(TpTabWidget *tab, int index)
{
    if (tab)
    {
        tab->setCurrentIndex(index);
        if (tab->currentIndex() >= 0)
            tab->currentWidget()->setFocus();
        onAction_F_C(false);
    }
}

void TpMainWindow::onTabNameChanged()
{
    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());
    updateDocumentDock();
    updateDocumentsDialog();
}

void TpMainWindow::onTabsListChanged(int length)
{
    updateDocumentDock();
    updateDocumentsDialog();
}

void TpMainWindow::onWrapVisualFlagChanged()
{
    DEF_SETTINGS;

    if (GET_SETTINGS("Tools/WrappingTools/StartFlag/None", bool)
        || (GET_SETTINGS("Tools/WrappingTools/EndFlag/None", bool)))
    {
        m_menuBar->V_Y_W->setChecked(false);
        SET_SETTINGS("View/ShowSymbols/WrapVisualFlags", false);
    }

    else
    {
        m_menuBar->V_Y_W->setChecked(true);
        SET_SETTINGS("View/ShowSymbols/WrapVisualFlags", true);
    }
}

void TpMainWindow::onFileDockVisibilityChanged(bool isVisible)
{
    DEF_SETTINGS;
    m_menuBar->W_F->setChecked(isVisible);
    SET_SETTINGS("Windows/FileBrowser", isVisible);
}

void TpMainWindow::onFileDockDoubleClicked(const QString &path)
{
    TpOpenAssistant *assistant = new TpOpenAssistant(this);
    assistant->openFile(path);
}

void TpMainWindow::onDocumentDockVisibilityChanged(bool isVisible)
{
    DEF_SETTINGS;
    m_menuBar->W_L->setChecked(isVisible);
    SET_SETTINGS("Windows/DocumentList", isVisible);
}

void TpMainWindow::onDocumentDockDoubleClicked(TpTabWidget *tab, const QString &path)
{
    for (int tabs = 0; tabs < m_widget->tabs()->m_tabs.count(); tabs++)
    {
        for (int index = 0; index < m_widget->tabs()->m_tabs.at(tabs)->count(); index++)
        {
            if (m_widget->tabs()->m_tabs.at(tabs)->tabToolTip(index) == path)
            {
                m_widget->tabs()->m_tabs.at(tabs)->setCurrentIndex(index);
                m_widget->tabs()->m_tabs.at(tabs)->tab()->setFocus();
                break;
            }
        }
    }
}

void TpMainWindow::onBookmarkDockVisibilityChanged(bool isVisible)
{
    DEF_SETTINGS;
    m_menuBar->W_B->setChecked(isVisible);
    SET_SETTINGS("Windows/Bookmarks", isVisible);
}

void TpMainWindow::onFindDockVisibilityChanged(bool isVisible)
{
    DEF_SETTINGS;
    m_menuBar->W_D->setChecked(isVisible);
    SET_SETTINGS("Windows/FindDock", isVisible);

    if (tabifiedDockWidgets(m_findDock).contains(m_findInFilesDock) && isVisible)
        m_findInFilesDock->setVisible(isVisible);
}

void TpMainWindow::onFindInFilesDockVisibilityChanged(bool isVisible)
{
    DEF_SETTINGS;
    m_menuBar->W_I->setChecked(isVisible);
    SET_SETTINGS("Windows/FindInFilesDock", isVisible);

    if (tabifiedDockWidgets(m_findInFilesDock).contains(m_findDock) && isVisible)
        m_findDock->setVisible(isVisible);
}

void TpMainWindow::onFindInFilesDockDoubleClicked(const QString &path, int position)
{
    TpOpenAssistant *assistant = new TpOpenAssistant(this);
    assistant->openFile(path);

    if (m_widget->tabs()->tab()->tab())
    {
        if (m_widget->tabs()->tab()->tab()->m_filePath == path)
        {
            int line = 0;
            int index = 0;
            m_widget->tabs()->tab()->tab()->lineIndexFromPosition(position, &line, &index);
            m_widget->tabs()->tab()->tab()->setCursorPosition(line, index);
        }
    }
}

void TpMainWindow::onFindToolBarTextChanged(const QString &text)
{
    if (m_widget->tabs()->tab()->hasTab())
        updateIncrementalSearch(text);
}

void TpMainWindow::onStatusBarSpinBoxTabWidthChanged(int value)
{
    DEF_SETTINGS;

    if (TpEditor *editor = m_widget->tabs()->tab()->tab())
    {
        editor->setTabWidth(value);
        editor->setIndentationWidth(value);
    }

    SET_SETTINGS("Editor/Values/TabWidth", value);
}

void TpMainWindow::onStatusBarComboBoxLangIndexChanged(int index)
{
    Languages newLang = m_statusBar->languagesMap[m_statusBar->m_comboBoxLang->itemText(index)];
    if (TpEditor *editor = m_widget->tabs()->tab()->tab())
        editor->setCurrentLexer(newLang);
    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());
}

void TpMainWindow::onStatusBarComboBoxNewLineIndexChanged(int index)
{
    TpEditor::EolMode eolMode = static_cast<TpEditor::EolMode>(index);
    if (TpEditor *editor = m_widget->tabs()->tab()->tab())
        editor->setEolMode(eolMode);
    onTabChanged(m_widget->tabs()->tab(), m_widget->tabs()->tab()->currentIndex());
}

void TpMainWindow::clearDocumentDock(QTreeWidgetItem *item)
{
    TpDocumentView *view = m_documentDock->documentView();

    for (int index = 0; index < item->childCount(); index++)
        clearDocumentDock(item->child(index));

    if (!(item == view->invisibleRootItem()))
    {
        view->removeItemWidget(item, 0);
        delete item;
    }
}

void TpMainWindow::updateDocumentDock()
{
    TpDocumentView *view = m_documentDock->documentView();

    // clearDocumentDock(view->invisibleRootItem());
    view->clear();

    for (int index = 0; index < m_widget->tabs()->m_tabs.count(); index++)
    {
        TpTabWidget *tab = m_widget->tabs()->m_tabs.at(index);

        if (tab)
        {
            TpDocumentItem *tabItem = view->addTab(tab);

            for (int editor = 0; editor < tab->count(); editor++)
            {
                TpEditor *ed = tab->tabAt(editor);

                if (ed)
                {
                    // view->addFile(tab, ed->m_filePath, ((ed->m_filePath.isEmpty())
                    //     ? tr("Untitled %1").arg(ed->m_untitled) : QFileInfo(QFile(ed->m_filePath)).fileName()));

                    QTreeWidgetItem *fileItem = new QTreeWidgetItem(tabItem, TpDocumentItem::ItemType::File);
                    fileItem->setToolTip(0, ed->m_filePath);

                    if (ed->m_filePath.isEmpty())
                        fileItem->setText(0, tab->tabText(tab->indexOf(ed)));
                    else
                        fileItem->setText(0, QFileInfo(QFile(ed->m_filePath)).fileName());

                    tabItem->addChild(fileItem);
                }
            }
        }
    }
}

void TpMainWindow::updateRecentFiles()
{
    DEF_SETTINGS;

    QStringList recentFilePaths = GET_SETTINGS("App/RecentFiles", QStringList);

    auto iteratorEnd = 0u;

    if (recentFilePaths.size() <= maximumRecentFiles)
        iteratorEnd = recentFilePaths.size();
    else
        iteratorEnd = maximumRecentFiles;

    for (auto i = 0u; i < iteratorEnd; i++)
    {
        QString strippedName = QFileInfo(recentFilePaths.at(i)).fileName();
        m_menuBar->m_recentFileActions.at(i)->setText(tr("&%1. %2").arg(i + 1).arg(strippedName));
        m_menuBar->m_recentFileActions.at(i)->setData(recentFilePaths.at(i));
        m_menuBar->m_recentFileActions.at(i)->setVisible(true);
    }

    for (auto i = iteratorEnd; i < maximumRecentFiles; i++)
        m_menuBar->m_recentFileActions.at(i)->setVisible(false);
}

void TpMainWindow::updateIncrementalSearch(const QString &text)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    const QString &content = editor->text();
    int indic = editor->incrementalIndicator();
    int clearLineTo = 0;
    int clearIndexTo = 0;
    editor->lineIndexFromPosition(editor->getLength(), &clearLineTo, &clearIndexTo);
    editor->clearIndicatorRange(0, 0, clearLineTo, clearIndexTo, indic);

    if (text.isEmpty())
        return;

    int indexOf = 0;

    while ((indexOf = content.indexOf(text, indexOf)) != -1)
    {
        int lineFrom;
        int indexFrom;
        int lineTo;
        int indexTo;

        lineFrom = indexFrom = lineTo = indexTo = 0;

        editor->lineIndexFromPosition(indexOf, &lineFrom, &indexFrom);
        editor->lineIndexFromPosition(indexOf + text.length(), &lineTo, &indexTo);

        editor->fillIndicatorRange(lineFrom, indexFrom, lineTo, indexTo, indic);

        indexOf++;
    }
}

void TpMainWindow::updateEditorsMap()
{
    TpSessionThread *thread = new TpSessionThread(this);
    connect(thread,
            &TpSessionThread::finished,
            thread,
            &TpSessionThread::deleteLater);
    thread->start(QThread::Priority::HighPriority);
}

void TpMainWindow::updateLexerComboBox()
{
    m_statusBar->m_comboBoxLang
        ->setCurrentText(m_statusBar->iteratedLangMap[m_widget->tabs()->tab()->tab()->currentLexer()]);
}

void TpMainWindow::updateNewLineComboBox()
{
    m_statusBar->m_comboBoxNewLine
        ->setCurrentText(m_statusBar->comboBoxNewLineItems[m_widget->tabs()->tab()->tab()->eolMode()]);
}

void TpMainWindow::updateDocumentsDialog()
{
    m_dialogDocuments->view()->clear();

    for (const auto &tab : std::as_const(m_widget->tabs()->m_tabs))
    {
        QList<TpEditor*> lst = tab->acquire();
        for (const auto &ed : std::as_const(lst))
            m_dialogDocuments->view()->addItem(ed->m_filePath.isEmpty()
                ? tr("Untitled %1").arg(ed->m_untitled) : ed->m_filePath, tab->m_serial);
    }
}

void TpMainWindow::updateSettingsPages()
{
    auto stack = m_dialogSettings->stack();
    TpSettingsPage *stylesSettingsPage = new TpSettingsPage(TpSettingsPage::Type::Page, stack);
    stylesSettingsPage->setName(tr("Configuring Styles"));
    auto stylesSettingsView = new TpSettingsView(this);
    auto settings = QSharedPointer<QSettings>::create();
    settings->beginGroup("Lexer");
    stylesSettingsView->setSettings(settings);
    stylesSettingsPage->addEntry(stylesSettingsView);

    stylesSettingsPage->setEditorAcceptor([](TpEditor *ed){
        DEF_SETTINGS;
        settings.sync();

        TpGeneralLexer *lexer = ed->m_lexers[ed->currentLexer()];

        if (lexer)
        {
            ed->setLexer(nullptr);
            ed->setLexer(lexer);
            ed->recolor(0, -1);
            ed->viewport()->update();
        }
    });

    stylesSettingsPage->setRejector([stylesSettingsView](){
        stylesSettingsView->revertModelValues();
    });

    stack->addPage(stylesSettingsPage);
}

TP_END_NAMESPACE
