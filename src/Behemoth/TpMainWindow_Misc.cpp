#include <QDate>
#include <QDateTime>
#include <QTime>

#include <Utilities/TpCaseEngine>
#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

void TpMainWindow::onAction_I_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\f");
        editor->SendScintilla(TpEditor::SCI_CHARRIGHT);
    }
}

void TpMainWindow::onAction_I_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\t");
        editor->SendScintilla(TpEditor::SCI_CHARRIGHT);
    }
}

void TpMainWindow::onAction_I_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\v");
    }
}

void TpMainWindow::onAction_I_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insertAt(editor->eolChar(), editor->currentLine(), 0);
    }
}

void TpMainWindow::onAction_I_B(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insertAt(editor->eolChar(), editor->currentLine() + 1, 0);
    }
}

void TpMainWindow::onAction_I_N_W(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\r\n");
    }
}

void TpMainWindow::onAction_I_N_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\r");
    }
}

void TpMainWindow::onAction_I_N_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert("\n");
    }
}

void TpMainWindow::onAction_I_D_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert(QDate::currentDate().toString(Qt::DateFormat::ISODate));
    }
}

void TpMainWindow::onAction_I_D_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert(QTime::currentTime().toString(Qt::DateFormat::ISODate));
    }
}

void TpMainWindow::onAction_I_D_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->insert(QDateTime::currentDateTime().toString(Qt::DateFormat::ISODate));
    }
}

void TpMainWindow::onAction_I_O(bool)
{
    m_dialogCharacter->exec();
}

void TpMainWindow::onAction_O_L_p(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->adjustAppearance();
        // editor->setLexer(editor->m_lexers[None]);
        editor->setLexer(nullptr);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_A_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[ActionScript]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_A_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[ASP]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_A_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[AviSynth]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_B_B(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Bash]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_B_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Batch]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_B_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[BlitzBasic]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_B_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[PureBasic]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_B_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[FreeBasic]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_C(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[C]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_pl(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CPP]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_p(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CPPQt]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_s(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CS]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CMake]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CoffeeScript]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_C_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[CSS]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_D_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[D]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_D_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Diff]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_E_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Erlang]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_F_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Fortran]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_F_7(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Fortran77]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_G_G(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[GDScript]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_H_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[HTML]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_H_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[HTMLFull]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_I_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[IDL]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_I_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[IntelHex]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_J_J(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Java]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_J_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[JavaScript]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_J_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[JSON]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_L_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[LaTeX]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_L_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Lua]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_M_F(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Makefile]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_M_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Markdown]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_M_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[MASM]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_M_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Matlab]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_N_N(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[NASM]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_O_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Octave]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_P(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Pascal]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_E(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Perl]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[PHP]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_O(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[PO]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[PostScript]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[POV]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Properties]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_2(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Python2]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_3(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Python3]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_P_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Python3Extended]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_Q_Q(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[QML]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_Q_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[QSS]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_Q_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[QUI]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_R_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Ruby]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_S_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Spice]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_S_Q(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[SQL]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_S_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[SRecord]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_T_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[TCL]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_T_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[TektronixHex]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_T_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[TeX]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_V_V(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[Verilog]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_V_H(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[VHDL]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_X_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[XML]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_L_Y_Y(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setLexer(editor->m_lexers[YAML]);
        editor->adjustAppearance();
        updateLexerComboBox();
    }
}

void TpMainWindow::onAction_O_N_U(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEolMode(TpEditor::EolMode::EolWindows);
        updateNewLineComboBox();
        SET_SETTINGS("Format/Newline/UseWindows", true);
        SET_SETTINGS("Format/Newline/UseClassicalMac", false);
        SET_SETTINGS("Format/Newline/UseUnix", false);
    }
}

void TpMainWindow::onAction_O_N_C(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEolMode(TpEditor::EolMode::EolMac);
        updateNewLineComboBox();
        SET_SETTINGS("Format/Newline/UseWindows", false);
        SET_SETTINGS("Format/Newline/UseClassicalMac", true);
        SET_SETTINGS("Format/Newline/UseUnix", false);
    }
}

void TpMainWindow::onAction_O_N_E(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEolMode(TpEditor::EolMode::EolUnix);
        updateNewLineComboBox();
        SET_SETTINGS("Format/Newline/UseWindows", false);
        SET_SETTINGS("Format/Newline/UseClassicalMac", false);
        SET_SETTINGS("Format/Newline/UseUnix", true);
    }
}

void TpMainWindow::onAction_O_N_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->convertEols(TpEditor::EolMode::EolWindows);
    }
}

void TpMainWindow::onAction_O_N_M(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->convertEols(TpEditor::EolMode::EolMac);
    }
}

void TpMainWindow::onAction_O_N_X(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->convertEols(TpEditor::EolMode::EolUnix);
    }
}

void TpMainWindow::onAction_O_C_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    TpCaseEngine::convertCase(editor, TpCaseEngine::Case::Upper);
}

void TpMainWindow::onAction_O_C_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    TpCaseEngine::convertCase(editor, TpCaseEngine::Case::Lower);
}

void TpMainWindow::onAction_O_C_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    TpCaseEngine::convertCase(editor, TpCaseEngine::Case::Title);
}

void TpMainWindow::onAction_O_C_S(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    TpCaseEngine::convertCase(editor, TpCaseEngine::Case::Sentence);
}

void TpMainWindow::onAction_O_C_I(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    TpCaseEngine::convertCase(editor, TpCaseEngine::Case::Invert);
}

void TpMainWindow::onAction_O_C_R(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();
    TpCaseEngine::convertCase(editor, TpCaseEngine::Case::Random);
}

void TpMainWindow::onAction_O_I_T(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setIndentationsUseTabs(isChecked);
        SET_SETTINGS("Format/Indentation/UseTabsToIndent", isChecked);
    }
}

void TpMainWindow::onAction_O_I_B(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setBackspaceUnindents(isChecked);
        SET_SETTINGS("Format/Indentation/BackspaceUnindents", isChecked);
    }
}

void TpMainWindow::onAction_O_I_I(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setTabIndents(isChecked);
        SET_SETTINGS("Format/Indentation/TabToIndent", isChecked);
    }
}

void TpMainWindow::onAction_O_R_L(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setTabDrawMode(TpEditor::TabDrawMode::TabLongArrow);
        SET_SETTINGS("Format/RepresentingTabs/LongArrow", true);
        SET_SETTINGS("Format/RepresentingTabs/StrikeOut", false);
    }
}

void TpMainWindow::onAction_O_R_S(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setTabDrawMode(TpEditor::TabDrawMode::TabStrikeOut);
        SET_SETTINGS("Format/RepresentingTabs/LongArrow", false);
        SET_SETTINGS("Format/RepresentingTabs/StrikeOut", true);
    }
}

void TpMainWindow::onAction_O_S(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        if (isChecked)
        {
            editor->setMarginOptions(TpEditor::MoSublineSelect);
        }

        else
        {
            editor->setMarginOptions(TpEditor::MoNone);
        }

        SET_SETTINGS("Format/SelectFirstWrappedLineOnly", isChecked);
    }
}

void TpMainWindow::onAction_O_h(bool isChecked)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setReadOnly(isChecked);
    }
}

void TpMainWindow::onAction_O_A_U(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_UPPERCASE);
    }
}

void TpMainWindow::onAction_O_A_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_LOWERCASE);
    }
}

TP_END_NAMESPACE
