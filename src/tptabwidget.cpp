#include <QFileIconProvider>

#include <Views/TpDocumentView>
#include <TpEditor>
#include <TpMainWindow>
#include <TpStackedWidget>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpTabWidget::TpTabWidget(TpTabSplitter *parent)
    : QTabWidget(parent),
    m_parent(parent),
    m_bar(new TpTabBar(this)),
    m_serial(0)
{
    setObjectName("tab");
    setTabBar(m_bar);

    emit tabNameChanged();
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
    QFileIconProvider provider;
    const QIcon &fileIcon = provider.icon(QFileIconProvider::IconType::File);

    QString text;

    if (editor->filePath() == "")
        text = QString("Untitled %1").arg(editor->m_untitled);
    else
        text = QFileInfo(QFile(editor->filePath())).fileName();

    int index = addTab(editor, fileIcon, text);

    setTabToolTip(index, text);
    setCurrentIndex(index);

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

    disconnect(editor,
               &TpEditor::fileNameChanged,
               m_parent->m_parent->m_parent,
               &TpMainWindow::onEditorFileNameChanged);
    disconnect(editor,
               &TpEditor::checkBoxChecked,
               m_parent->m_parent->m_parent,
               &TpMainWindow::onEditorCheckBoxChecked);
    disconnect(editor,
               &TpEditor::positionChanged,
               m_parent->m_parent->m_parent,
               &TpMainWindow::onEditorPositionChanged);
    disconnect(editor,
               SIGNAL(selectionChanged()),
               m_parent->m_parent->m_parent,
               SLOT(onEditorSelectionChanged()));
    disconnect(editor,
               &TpEditor::punctuation,
               m_parent->m_parent->m_parent,
               &TpMainWindow::onEditorPunctuation);

    removeTab(indexOf(editor));

    emit m_parent->tabsListChanged(m_parent->m_tabs.length());

    if (!noDelete)
        // delete editor;
        editor->deleteLater();
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

TP_END_NAMESPACE
