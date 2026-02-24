#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

void TpMainWindow::onAction_V_Y_S(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        if (isChecked)
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsVisible);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsAll", true);
        }

        else
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsInvisible);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsAll", false);
        }
    }
}

void TpMainWindow::onAction_V_Y_A(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        if (isChecked)
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsVisibleAfterIndent);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsAfterIndentation", true);
        }

        else
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsInvisible);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsAfterIndentation", false);
        }
    }
}

void TpMainWindow::onAction_V_Y_T(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        if (isChecked)
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsVisibleOnlyInIndent);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsInIndentation", true);
        }

        else
        {
            editor->setWhitespaceVisibility(TpEditor::WhitespaceVisibility::WsInvisible);
            SET_SETTINGS("View/ShowSymbols/SpacesAndTabsInIndentation", false);
        }
    }
}

void TpMainWindow::onAction_V_Y_N(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEolVisibility(isChecked);
        SET_SETTINGS("View/ShowSymbols/NonPrintable", isChecked);
    }
}

void TpMainWindow::onAction_V_Y_W(bool isChecked)
{
    if (isChecked)
    {
        m_menuBar->T_W_S_B->trigger();
        m_menuBar->T_W_E_B->trigger();
    }

    else
    {
        m_menuBar->T_W_S_N->trigger();
        m_menuBar->T_W_E_N->trigger();
    }
}

void TpMainWindow::onAction_V_Y_I(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setIndentationGuides(isChecked);
        SET_SETTINGS("View/ShowSymbols/IndentationGuides", isChecked);
    }
}

void TpMainWindow::onAction_V_Z_I(bool isChecked)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->zoomIn();
    }
}

void TpMainWindow::onAction_V_Z_O(bool isChecked)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->zoomOut();
    }
}

void TpMainWindow::onAction_V_Z_T(bool isChecked)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->zoomTo(0);
    }
}

void TpMainWindow::onAction_V_T_1(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(0);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_2(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(1);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_3(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(2);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_4(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(3);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_5(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(4);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_6(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(5);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_7(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(6);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_8(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(7);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_9(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(8);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_0(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(9);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_L(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(tab->count() - 1);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_N(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();
    TpTabWidgetList tabs = m_widget->tabs()->m_tabs;

    if (tab)
    {
        // if (tab->currentIndex() == tab->count() - 1)
        //     tab->setCurrentIndex(0);
        // else
        //     tab->setCurrentIndex(tab->currentIndex() + 1);

        if (tab->currentIndex() == tab->count() - 1)
        {
            int count = tabs.count();

            if (count > 1)
            {
                if (tabs.indexOf(tab) < count - 1)
                    tab = tabs[tabs.indexOf(tab) + 1];
                else
                    tab = tabs[0];
            }

            emit tab->tabNameChanged();
            tab->setCurrentIndex(0);
        }

        else
        {
            tab->setCurrentIndex(tab->currentIndex() + 1);
        }

        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_F(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->setCurrentIndex(0);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_P(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();
    TpTabWidgetList tabs = m_widget->tabs()->m_tabs;

    if (tab)
    {
        if (tab->currentIndex() == 0)
        {
            int count = tabs.count();

            if (count > 1)
            {
                if (tabs.indexOf(tab) > 0)
                    tab = tabs[tabs.indexOf(tab) - 1];
                else
                    tab = tabs[tabs.count() - 1];
            }

            emit tab->tabNameChanged();
            tab->setCurrentIndex(tab->count() - 1);
        }

        else
        {
            tab->setCurrentIndex(tab->currentIndex() - 1);
        }

        // tab->setCurrentIndex(tab->currentIndex() - 1);
        tab->currentWidget()->setFocus();
    }
}

void TpMainWindow::onAction_V_T_M(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        if (tab->currentIndex() == 0)
            return;

        tab->tabBar()->moveTab(tab->currentIndex(), tab->currentIndex() - 1);
    }
}

void TpMainWindow::onAction_V_T_R(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        if (tab->currentIndex() == (tab->count() - 1))
            return;

        tab->tabBar()->moveTab(tab->currentIndex(), tab->currentIndex() + 1);
    }
}

void TpMainWindow::onAction_V_T_S(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->tabBar()->moveTab(tab->currentIndex(), 0);
    }
}

void TpMainWindow::onAction_V_T_T(bool)
{
    TpTabWidget *tab = m_widget->tabs()->tab();

    if (tab)
    {
        tab->tabBar()->moveTab(tab->currentIndex(), tab->count() - 1);
    }
}

void TpMainWindow::onAction_V_T_O(bool)
{
    if (m_widget->tabs()->m_tabs.length() >= 2)
    {
        int index = m_widget->tabs()->m_tabs.indexOf(m_widget->tabs()->tab());
        if (++index >= m_widget->tabs()->m_tabs.count())
            index = 0;
        m_widget->tabs()->m_tabs.at(index)->tab()->setFocus(Qt::FocusReason::OtherFocusReason);
    }
}

void TpMainWindow::onAction_V_T_U(bool)
{
    if (m_widget->tabs()->m_tabs.length() >= 2)
    {
        int index = m_widget->tabs()->m_tabs.indexOf(m_widget->tabs()->tab());
        if (--index < 0)
            index = m_widget->tabs()->m_tabs.count() - 1;
        m_widget->tabs()->m_tabs.at(index)->tab()->setFocus(Qt::FocusReason::OtherFocusReason);
    }
}

void TpMainWindow::onAction_V_W_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapMode(TpEditor::WrapMode::WrapNone);
        SET_SETTINGS("View/WordWrap/None", true);
        SET_SETTINGS("View/WordWrap/Word", false);
        SET_SETTINGS("View/WordWrap/Character", false);
        SET_SETTINGS("View/WordWrap/Whitespace", false);
    }
}

void TpMainWindow::onAction_V_W_W(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapMode(TpEditor::WrapMode::WrapWord);
        SET_SETTINGS("View/WordWrap/None", false);
        SET_SETTINGS("View/WordWrap/Word", true);
        SET_SETTINGS("View/WordWrap/Character", false);
        SET_SETTINGS("View/WordWrap/Whitespace", false);
    }
}

void TpMainWindow::onAction_V_W_C(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapMode(TpEditor::WrapMode::WrapCharacter);
        SET_SETTINGS("View/WordWrap/None", false);
        SET_SETTINGS("View/WordWrap/Word", false);
        SET_SETTINGS("View/WordWrap/Character", true);
        SET_SETTINGS("View/WordWrap/Whitespace", false);
    }
}

void TpMainWindow::onAction_V_W_H(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapMode(TpEditor::WrapMode::WrapWhitespace);
        SET_SETTINGS("View/WordWrap/None", false);
        SET_SETTINGS("View/WordWrap/Word", false);
        SET_SETTINGS("View/WordWrap/Character", false);
        SET_SETTINGS("View/WordWrap/Whitespace", true);
    }
}

void TpMainWindow::onAction_V_C_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINESCROLLDOWN);
    }
}

void TpMainWindow::onAction_V_C_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINESCROLLUP);
    }
}

void TpMainWindow::onAction_V_C_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SCROLLTOSTART);
    }
}

void TpMainWindow::onAction_V_C_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SCROLLTOEND);
    }
}

void TpMainWindow::onAction_V_C_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SCROLLCARET);
    }
}

void TpMainWindow::onAction_V_O_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->foldLine(editor->currentLine());
    }
}

void TpMainWindow::onAction_V_O_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->foldAll(false);
    }
}

void TpMainWindow::onAction_V_O_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->foldAll(true);
    }
}

void TpMainWindow::onAction_V_O_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->clearFolds();
    }
}

void TpMainWindow::onAction_V_O_S_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::NoFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", true);
        SET_SETTINGS("View/Folding/Plain", false);
        SET_SETTINGS("View/Folding/Circled", false);
        SET_SETTINGS("View/Folding/Boxed", false);
        SET_SETTINGS("View/Folding/CircledTree", false);
        SET_SETTINGS("View/Folding/BoxedTree", false);
    }
}

void TpMainWindow::onAction_V_O_S_P(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::PlainFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", false);
        SET_SETTINGS("View/Folding/Plain", true);
        SET_SETTINGS("View/Folding/Circled", false);
        SET_SETTINGS("View/Folding/Boxed", false);
        SET_SETTINGS("View/Folding/CircledTree", false);
        SET_SETTINGS("View/Folding/BoxedTree", false);
    }
}

void TpMainWindow::onAction_V_O_S_C(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::CircledFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", false);
        SET_SETTINGS("View/Folding/Plain", false);
        SET_SETTINGS("View/Folding/Circled", true);
        SET_SETTINGS("View/Folding/Boxed", false);
        SET_SETTINGS("View/Folding/CircledTree", false);
        SET_SETTINGS("View/Folding/BoxedTree", false);
    }
}

void TpMainWindow::onAction_V_O_S_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::BoxedFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", false);
        SET_SETTINGS("View/Folding/Plain", false);
        SET_SETTINGS("View/Folding/Circled", false);
        SET_SETTINGS("View/Folding/Boxed", true);
        SET_SETTINGS("View/Folding/CircledTree", false);
        SET_SETTINGS("View/Folding/BoxedTree", false);
    }
}

void TpMainWindow::onAction_V_O_S_T(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::CircledTreeFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", false);
        SET_SETTINGS("View/Folding/Plain", false);
        SET_SETTINGS("View/Folding/Circled", false);
        SET_SETTINGS("View/Folding/Boxed", false);
        SET_SETTINGS("View/Folding/CircledTree", true);
        SET_SETTINGS("View/Folding/BoxedTree", false);
    }
}

void TpMainWindow::onAction_V_O_S_X(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setFolding(TpEditor::FoldStyle::BoxedTreeFoldStyle);
        SET_SETTINGS("View/Folding/DisableFolding", false);
        SET_SETTINGS("View/Folding/Plain", false);
        SET_SETTINGS("View/Folding/Circled", false);
        SET_SETTINGS("View/Folding/Boxed", false);
        SET_SETTINGS("View/Folding/CircledTree", false);
        SET_SETTINGS("View/Folding/BoxedTree", true);
    }
}

TP_END_NAMESPACE
