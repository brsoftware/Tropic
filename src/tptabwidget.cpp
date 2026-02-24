#include <QDragEnterEvent>
#include <QDropEvent>
#include <QFileIconProvider>
#include <QMimeData>

#include <Utilities/TpOpenAssistant>
#include <Views/TpDocumentView>
#include <TpEditor>
#include <TpMainWindow>
#include <TpStackedWidget>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

QMap<int, TpTabInfo> TpTabWidget::m_dragInfo;
int TpTabWidget::m_keyValue = 0;

TpTabWidget::TpTabWidget(TpTabSplitter *parent)
    : QTabWidget(parent),
    m_parent(parent),
    m_bar(new TpTabBar(this)),
    m_serial(0)
{
    setAcceptDrops(true);
    setObjectName("tab");
    setTabBar(m_bar);

    connect(m_bar,
            &TpTabBar::dragged,
            this,
            &TpTabWidget::onBarDragged);
    connect(m_bar,
            &TpTabBar::tabCloseRequested,
            this,
            &TpTabWidget::tabCloseRequested);
    connect(m_bar,
            &TpTabBar::midButtonTabCloseRequested,
            this,
            &TpTabWidget::tabCloseRequested);
}

TpTabWidget::~TpTabWidget()
{
    emit tabNameChanged();
}

bool TpTabWidget::hasTab() const
{
    // return (bool)tab();
    return count() > 0;
}

TpEditor *TpTabWidget::tab() const
{
    return qobject_cast<TpEditor*>(currentWidget());
}

TpEditor *TpTabWidget::tabAt(int index) const
{
    return qobject_cast<TpEditor*>(widget(index));
}

unsigned int TpTabWidget::serial() const
{
    return m_serial;
}

TpEditor *TpTabWidget::addEditor()
{
    return addEditor("", "", "");
}

TpEditor *TpTabWidget::addEditor(QString currentPath, QString currentText, QString currentContent)
{
    DEF_SETTINGS;

    TpEditor *editor = new TpEditor(this);
    editor->m_content = currentContent;
    editor->m_filePath = currentPath;

    connectEditorSignals(editor);

    if ((currentPath == "") && (currentContent == ""))
    {
        int minimum = 1;

        for (;;minimum++)
            if (!untitledList.contains(minimum))
                break;

        editor->m_untitled = minimum;
        untitledList.push_back(minimum);
    }

    editor->setAutoCompletionThreshold(GET_SETTINGS("Editor/Values/AutoCompletionThreshold", int));
    editor->setCallTipsVisible(GET_SETTINGS("Editor/Values/CallTipsMaximum", int));
    editor->setCaretWidth(GET_SETTINGS("Editor/Values/CaretLineWidth", int));
    editor->setEdgeColumn(GET_SETTINGS("Editor/Values/EdgeColumn", int));
    editor->setExtraAscent(GET_SETTINGS("Editor/Values/ExtraAscent", int));
    editor->setExtraDescent(GET_SETTINGS("Editor/Values/ExtraDescent", int));
    editor->setTabWidth(GET_SETTINGS("Editor/Values/TabWidth", int));
    editor->setIndentationWidth(GET_SETTINGS("Editor/Values/TabWidth", int));

    QFileIconProvider provider;
    const QIcon &fileIcon = provider.icon(QFileIconProvider::IconType::File);

    QString text;

    if ((currentPath == "") || (currentText == ""))
        text = QString("Untitled %1").arg(editor->m_untitled);
    else
        text = currentText;

    int index = addTab(editor, fileIcon, text);

    setTabToolTip(index, text);
    setCurrentIndex(index);

    m_parent->m_parent->m_parent->m_menuBar->updateToSettings();

    emit m_parent->tabsListChanged(m_parent->m_tabs.length());

    emit editor->fileNameChanged(editor->m_filePath, currentText);
    editor->setFocus();

    return editor;
}

TpEditor *TpTabWidget::addEditor(TpEditor *editor)
{
    editor->disconnect();

    QFileIconProvider provider;
    const QIcon &fileIcon = provider.icon(QFileIconProvider::IconType::File);

    QString text;

    if (editor->filePath() == "")
        text = QString("Untitled %1").arg(editor->m_untitled);
    else
        text = QFileInfo(QFile(editor->filePath())).fileName();

    editor->m_parent = this;
    editor->setParent(this);
    int index = addTab(editor, fileIcon, text);

    setTabToolTip(index, text);
    setCurrentIndex(index);

    connectEditorSignals(editor);

    DEF_SETTINGS;

    editor->setAutoCompletionThreshold(GET_SETTINGS("Editor/Values/AutoCompletionThreshold", int));
    editor->setCallTipsVisible(GET_SETTINGS("Editor/Values/CallTipsMaximum", int));
    editor->setCaretWidth(GET_SETTINGS("Editor/Values/CaretLineWidth", int));
    editor->setEdgeColumn(GET_SETTINGS("Editor/Values/EdgeColumn", int));
    editor->setExtraAscent(GET_SETTINGS("Editor/Values/ExtraAscent", int));
    editor->setExtraDescent(GET_SETTINGS("Editor/Values/ExtraDescent", int));
    editor->setTabWidth(GET_SETTINGS("Editor/Values/TabWidth", int));
    editor->setIndentationWidth(GET_SETTINGS("Editor/Values/TabWidth", int));

    emit m_parent->tabsListChanged(m_parent->m_tabs.length());

    emit editor->fileNameChanged(editor->m_filePath, text);
    editor->setFocus();

    return editor;
}

void TpTabWidget::removeEditor(TpEditor *editor, bool noDelete)
{
    if (indexOf(editor) < 0)
    {
        Q_ASSERT_X(false, Q_FUNC_INFO, "Editor not in the tab widget.");
        return;
    }

    editor->disconnect();
    removeTab(indexOf(editor));

    emit m_parent->tabsListChanged(m_parent->m_tabs.length());

    if (!noDelete)
    {
        editor->m_parent = nullptr;
        // editor->deleteLater();
        delete editor;
    }
}

QList<TpEditor*> TpTabWidget::acquire(int mode) const
{
    QList<TpEditor*> result;

    if (mode == AllEditors)
    {
        for (int item = 0; item < count(); item++)
        {
            result.append(tabAt(item));
        }
    }

    else if (mode == ToTheLeft)
    {
        for (int item = 0; item < currentIndex(); item++)
        {
            result.append(tabAt(item));
        }
    }

    else if (mode == ToTheRight)
    {
        for (int item = currentIndex() + 1; item < count(); item++)
        {
            result.append(tabAt(item));
        }
    }

    else if (mode == Unchanged)
    {
        for (int item = 0; item < count(); item++)
        {
            if (tabAt(item)->content() == tabAt(item)->text())
                result.append(tabAt(item));
        }
    }

    else if (mode == ExceptCurrent)
    {
        TpEditor *now = tab();

        for (int item = 0; item < count(); item++)
        {
            if (tabAt(item) != now)
                result.append(tabAt(item));
        }
    }

    else
    {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unkown mode: " + QString::number(mode)));
    }

    return result;
}

bool TpTabWidget::contains(QWidget *widget) const
{
    for (int item = 0; item < count(); item++)
    {
        if (tab() == widget)
            return true;
    }

    return false;
}

void TpTabWidget::onBarDragged()
{
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;
    int key = m_keyValue++;
    m_dragInfo.insert(key, {m_bar->tabToolTip(currentIndex()), tab()});
    mimeData->setData(tabMimeType, QByteArray::number(key));
    QPixmap pixmap = currentWidget()->grab();
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    Qt::DropAction action = drag->exec(Qt::DropAction::CopyAction | Qt::DropAction::MoveAction);

    if (action == Qt::DropAction::IgnoreAction)
    {
        // if (count() <= 1)
        //     return;
        TpMainWindow *newWindow = new TpMainWindow(false, false, tab());
        newWindow->show();
        if (count() <= 0)
            m_parent->removeTab(this);
        m_parent->m_parent->m_parent->updateDocumentDock();
    }
}

void TpTabWidget::dragEnterEvent(QDragEnterEvent *event)
{
    const QMimeData *mime = event->mimeData();
    if (mime->hasUrls() || mime->hasText() || mime->hasFormat(tabMimeType))
        event->acceptProposedAction();
}

void TpTabWidget::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();

    if (mimeData)
    {
        if (mimeData->hasUrls())
        {
            event->acceptProposedAction();
            QStringList sl;
            for (const auto &item : mimeData->urls())
                if (item.isLocalFile())
                    sl << item.toLocalFile();
            if (sl.empty())
                goto acceptor;

            TpOpenAssistant *assistant = new TpOpenAssistant(m_parent->m_parent->m_parent);
            assistant->openFiles(sl);
            event->accept();
            return;
        }

        else if (mimeData->hasText())
        {
            event->acceptProposedAction();
            tab()->insert(mimeData->text());
            event->accept();
            return;
        }

        else if (mimeData->hasFormat(tabMimeType))
        {
            event->acceptProposedAction();
            int key = mimeData->data(tabMimeType).toInt();
            auto it = m_dragInfo.find(key);
            if (it == m_dragInfo.end())
                goto acceptor;
            TpTabInfo info = it.value();
            m_dragInfo.erase(it);
            int idx = m_bar->tabAt(event->position().toPoint());
            TpEditor *ed = info.widget();
            TpTabWidget *oldParent = ed->m_parent;
            if (oldParent == this && count() <= 1)
                goto acceptor;
            oldParent->removeEditor(ed, true);
            if (oldParent->count() <= 0)
                oldParent->m_parent->removeTab(oldParent);
            addEditor(ed);

            if (idx < count() && idx >= 0)
            {
                m_bar->moveTab(currentIndex(), idx);
                setCurrentIndex(idx);
            }

            m_parent->m_parent->m_parent->updateDocumentDock();
            event->accept();
            return;
        }
    }

    goto acceptor;

    acceptor:
        QTabWidget::dropEvent(event);
}

void TpTabWidget::connectEditorSignals(TpEditor *editor)
{
    connect(editor,
            &TpEditor::fileNameChanged,
            m_parent->m_parent->m_parent,
            &TpMainWindow::onEditorFileNameChanged);
    connect(editor,
            &TpEditor::checkBoxChecked,
            m_parent->m_parent->m_parent,
            &TpMainWindow::onEditorCheckBoxChecked);
    connect(editor,
            &TpEditor::positionChanged,
            m_parent->m_parent->m_parent,
            &TpMainWindow::onEditorPositionChanged);
    connect(editor,
            SIGNAL(selectionChanged()),
            m_parent->m_parent->m_parent,
            SLOT(onEditorSelectionChanged()));
    connect(editor,
            &TpEditor::punctuation,
            m_parent->m_parent->m_parent,
            &TpMainWindow::onEditorPunctuation);
    connect(editor,
            SIGNAL(textChanged()),
            m_parent->m_parent->m_parent,
            SLOT(onEditorTextChanged()));
}

TP_END_NAMESPACE
