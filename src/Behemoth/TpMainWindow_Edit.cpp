#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

void TpMainWindow::onAction_E_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_UNDO);
    }
}

void TpMainWindow::onAction_E_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_REDO);
    }
}

void TpMainWindow::onAction_E_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CUT);
    }
}

void TpMainWindow::onAction_E_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_COPY);
    }
}

void TpMainWindow::onAction_E_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PASTE);
    }
}

void TpMainWindow::onAction_E_D_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CLEAR);
    }
}

void TpMainWindow::onAction_E_D_B(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELETEBACK);
    }
}

void TpMainWindow::onAction_E_D_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELETEBACKNOTLINE);
    }
}

void TpMainWindow::onAction_E_D_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELWORDLEFT);
    }
}

void TpMainWindow::onAction_E_D_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELWORDRIGHT);
    }
}

void TpMainWindow::onAction_E_D_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELWORDRIGHTEND);
    }
}

void TpMainWindow::onAction_E_D_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELLINELEFT);
    }
}

void TpMainWindow::onAction_E_D_G(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DELLINERIGHT);
    }
}

void TpMainWindow::onAction_E_M_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEDOWN);
    }
}

void TpMainWindow::onAction_E_M_B(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEUP);
    }
}

void TpMainWindow::onAction_E_M_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEEND);
    }
}

void TpMainWindow::onAction_E_M_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDDISPLAY);
    }
}

void TpMainWindow::onAction_E_M_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDWRAP);
    }
}

void TpMainWindow::onAction_E_M_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PARADOWN);
    }
}

void TpMainWindow::onAction_E_M_G(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PARAUP);
    }
}

void TpMainWindow::onAction_E_M_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARLEFT);
    }
}

void TpMainWindow::onAction_E_M_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARRIGHT);
    }
}

void TpMainWindow::onAction_E_M_J(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDLEFT);
    }
}

void TpMainWindow::onAction_E_M_K(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDRIGHT);
    }
}

void TpMainWindow::onAction_E_M_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDLEFTEND);
    }
}

void TpMainWindow::onAction_E_M_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDRIGHTEND);
    }
}

void TpMainWindow::onAction_E_M_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDPARTLEFT);
    }
}

void TpMainWindow::onAction_E_M_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDPARTRIGHT);
    }
}

void TpMainWindow::onAction_E_M_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOME);
    }
}

void TpMainWindow::onAction_E_M_Q(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMEDISPLAY);
    }
}

void TpMainWindow::onAction_E_M_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMEWRAP);
    }
}

void TpMainWindow::onAction_E_M_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_VCHOME);
    }
}

void TpMainWindow::onAction_E_M_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_VCHOMEWRAP);
    }
}

void TpMainWindow::onAction_E_M_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DOCUMENTSTART);
    }
}

void TpMainWindow::onAction_E_M_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DOCUMENTEND);
    }
}

void TpMainWindow::onAction_E_M_W(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEUP);
    }
}

void TpMainWindow::onAction_E_M_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEDOWN);
    }
}

void TpMainWindow::onAction_E_M_Y(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_STUTTEREDPAGEUP);
    }
}

void TpMainWindow::onAction_E_M_Z(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_STUTTEREDPAGEDOWN);
    }
}

void TpMainWindow::onAction_E_S_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SELECTALL);
    }
}

void TpMainWindow::onAction_E_S_B(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEDOWNEXTEND);
    }
}

void TpMainWindow::onAction_E_S_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEDOWNRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEUPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEUPRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDEXTEND);
    }
}

void TpMainWindow::onAction_E_S_G(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDDISPLAYEXTEND);
    }
}

void TpMainWindow::onAction_E_S_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEENDWRAPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_J(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PARADOWNEXTEND);
    }
}

void TpMainWindow::onAction_E_S_K(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PARAUPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARLEFTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARLEFTRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARRIGHTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_CHARRIGHTRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDLEFTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_Q(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDRIGHTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDLEFTENDEXTEND);
    }
}

void TpMainWindow::onAction_E_S_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDRIGHTENDEXTEND);
    }
}

void TpMainWindow::onAction_E_S_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDPARTLEFTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_WORDPARTRIGHTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMEEXTEND);
    }
}

void TpMainWindow::onAction_E_S_W(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMERECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMEDISPLAYEXTEND);
    }
}

void TpMainWindow::onAction_E_S_Y(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_HOMEWRAPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_Z(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_VCHOMEEXTEND);
    }
}

void TpMainWindow::onAction_E_S_0(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_VCHOMERECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_1(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_VCHOMEWRAPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_2(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DOCUMENTSTARTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_3(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_DOCUMENTENDEXTEND);
    }
}

void TpMainWindow::onAction_E_S_4(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEUPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_5(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEUPRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_6(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEDOWNEXTEND);
    }
}

void TpMainWindow::onAction_E_S_7(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_PAGEDOWNRECTEXTEND);
    }
}

void TpMainWindow::onAction_E_S_8(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_STUTTEREDPAGEUPEXTEND);
    }
}

void TpMainWindow::onAction_E_S_9(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_STUTTEREDPAGEDOWNEXTEND);
    }
}

void TpMainWindow::onAction_E_I_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_TAB);
    }
}

void TpMainWindow::onAction_E_I_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_BACKTAB);
    }
}

void TpMainWindow::onAction_E_L_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEDELETE);
    }
}

void TpMainWindow::onAction_E_L_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINECUT);
    }
}

void TpMainWindow::onAction_E_L_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINECOPY);
    }
}

void TpMainWindow::onAction_E_L_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINETRANSPOSE);
    }
}

void TpMainWindow::onAction_E_L_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_MOVESELECTEDLINESUP);
    }
}

void TpMainWindow::onAction_E_L_W(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_MOVESELECTEDLINESDOWN);
    }
}

void TpMainWindow::onAction_E_A_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LINEDUPLICATE);
    }
}

void TpMainWindow::onAction_E_A_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SELECTIONDUPLICATE);
    }
}

void TpMainWindow::onAction_E_G(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_EDITTOGGLEOVERTYPE);
    }
}

TP_END_NAMESPACE
