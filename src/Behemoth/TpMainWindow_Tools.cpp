#include <Widgets/TpFindContainer>
#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

void TpMainWindow::onAction_T_P(bool)
{
    m_dialogSettings->exec();
}

void TpMainWindow::onAction_T_R(bool)
{
    m_dialogCommands->exec();
}

void TpMainWindow::onAction_T_A_C(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionCaseSensitivity(isChecked);
        SET_SETTINGS("Tools/Autocompletion/CaseSensitive", isChecked);
    }
}

void TpMainWindow::onAction_T_A_F(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionFillupsEnabled(isChecked);
        SET_SETTINGS("Tools/Autocompletion/FillupsEnabled", isChecked);
    }
}

void TpMainWindow::onAction_T_A_R(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionReplaceWord(isChecked);
        SET_SETTINGS("Tools/Autocompletion/ReplaceWord", isChecked);
    }
}

void TpMainWindow::onAction_T_A_W_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionUseSingle(TpEditor::AutoCompletionUseSingle::AcusNever);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/DoNotDisplay", true);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/OnlyManually", false);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/AlwaysDisplay", false);
    }
}

void TpMainWindow::onAction_T_A_W_O(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionUseSingle(TpEditor::AutoCompletionUseSingle::AcusExplicit);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/DoNotDisplay", false);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/OnlyManually", true);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/AlwaysDisplay", false);
    }
}

void TpMainWindow::onAction_T_A_W_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionUseSingle(TpEditor::AutoCompletionUseSingle::AcusAlways);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/DoNotDisplay", false);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/OnlyManually", false);
        SET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/AlwaysDisplay", true);
    }
}

void TpMainWindow::onAction_T_A_S_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionSource(TpEditor::AutoCompletionSource::AcsNone);
        SET_SETTINGS("Tools/Autocompletion/Sources/DoNotDisplay", true);
        SET_SETTINGS("Tools/Autocompletion/Sources/All", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Document", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Lexer", false);
    }
}

void TpMainWindow::onAction_T_A_S_A(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionSource(TpEditor::AutoCompletionSource::AcsAll);
        SET_SETTINGS("Tools/Autocompletion/Sources/DoNotDisplay", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/All", true);
        SET_SETTINGS("Tools/Autocompletion/Sources/Document", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Lexer", false);
    }
}

void TpMainWindow::onAction_T_A_S_O(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionSource(TpEditor::AutoCompletionSource::AcsDocument);
        SET_SETTINGS("Tools/Autocompletion/Sources/DoNotDisplay", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/All", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Document", true);
        SET_SETTINGS("Tools/Autocompletion/Sources/Lexer", false);
    }
}

void TpMainWindow::onAction_T_A_S_L(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoCompletionSource(TpEditor::AutoCompletionSource::AcsAPIs);
        SET_SETTINGS("Tools/Autocompletion/Sources/DoNotDisplay", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/All", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Document", false);
        SET_SETTINGS("Tools/Autocompletion/Sources/Lexer", true);
    }
}

void TpMainWindow::onAction_T_A_T_A(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->autoCompleteFromAll();
    }
}

void TpMainWindow::onAction_T_A_T_D(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->autoCompleteFromDocument();
    }
}

void TpMainWindow::onAction_T_A_T_L(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->autoCompleteFromAPIs();
    }
}

void TpMainWindow::onAction_T_h_A(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoIndent(isChecked);
        SET_SETTINGS("Tools/Autoindentation/Autoindentation", isChecked);
    }
}

void TpMainWindow::onAction_T_h_S_A(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        int sty = /*TpEditor::AiMaintain*/ 0;
        // if (m_menuBar->T_h_S_O->isChecked())
        //     sty |= TpEditor::AiOpening;
        // if (m_menuBar->T_h_S_C->isChecked())
        //     sty |= TpEditor::AiClosing;

        editor->setAutoCompletionStyle(sty);

        bool isMaintain = /*(isChecked ?*/ false /*: (editor->autoCompletionStyle() | TpEditor::AiMaintain))*/;
        bool isOpening = /*(isChecked ?*/ false /*: (editor->autoCompletionStyle() | TpEditor::AiOpening))*/;
        bool isClosing = /*(isChecked ?*/ false /*: (editor->autoCompletionStyle() | TpEditor::AiClosing))*/;

        SET_SETTINGS("Tools/Autoindentation/Style/Auto", isChecked);
        SET_SETTINGS("Tools/Autoindentation/Style/Maintain", isMaintain);
        SET_SETTINGS("Tools/Autoindentation/Style/Opening", isOpening);
        SET_SETTINGS("Tools/Autoindentation/Style/Closing", isClosing);

        m_menuBar->T_h_S_M->setChecked(isMaintain);
        m_menuBar->T_h_S_O->setChecked(isOpening);
        m_menuBar->T_h_S_C->setChecked(isClosing);
    }
}

void TpMainWindow::onAction_T_h_S_M(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        int sty = TpEditor::AiMaintain;
        if (m_menuBar->T_h_S_O->isChecked())
            sty |= TpEditor::AiOpening;
        if (m_menuBar->T_h_S_C->isChecked())
            sty |= TpEditor::AiClosing;

        editor->setAutoCompletionStyle(sty);
        SET_SETTINGS("Tools/Autoindentation/Style/Maintain", isChecked);
        SET_SETTINGS("Tools/Autoindentation/Style/Auto", false);
        m_menuBar->T_h_S_A->setChecked(false);
    }
}

void TpMainWindow::onAction_T_h_S_O(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        int sty = TpEditor::AiOpening;
        if (m_menuBar->T_h_S_M->isChecked())
            sty |= TpEditor::AiMaintain;
        if (m_menuBar->T_h_S_C->isChecked())
            sty |= TpEditor::AiClosing;

        editor->setAutoCompletionStyle(sty);
        SET_SETTINGS("Tools/Autoindentation/Style/Opening", isChecked);
        SET_SETTINGS("Tools/Autoindentation/Style/Auto", false);
        m_menuBar->T_h_S_A->setChecked(false);
    }
}

void TpMainWindow::onAction_T_h_S_C(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        int sty = TpEditor::AiClosing;
        if (m_menuBar->T_h_S_M->isChecked())
            sty |= TpEditor::AiMaintain;
        if (m_menuBar->T_h_S_C->isChecked())
            sty |= TpEditor::AiOpening;

        editor->setAutoCompletionStyle(sty);
        SET_SETTINGS("Tools/Autoindentation/Style/Closing", isChecked);
        SET_SETTINGS("Tools/Autoindentation/Style/Auto", false);
        m_menuBar->T_h_S_A->setChecked(false);
    }
}

void TpMainWindow::onAction_T_B_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setBraceMatching(TpEditor::BraceMatch::NoBraceMatch);
        SET_SETTINGS("Tools/BraceMatching/NoBraceMatching", true);
        SET_SETTINGS("Tools/BraceMatching/SloppyBraceMatch", false);
        SET_SETTINGS("Tools/BraceMatching/StrictBraceMatch", false);
    }
}

void TpMainWindow::onAction_T_B_S(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setBraceMatching(TpEditor::BraceMatch::SloppyBraceMatch);
        SET_SETTINGS("Tools/BraceMatching/NoBraceMatching", false);
        SET_SETTINGS("Tools/BraceMatching/SloppyBraceMatch", true);
        SET_SETTINGS("Tools/BraceMatching/StrictBraceMatch", false);
    }
}

void TpMainWindow::onAction_T_B_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setBraceMatching(TpEditor::BraceMatch::StrictBraceMatch);
        SET_SETTINGS("Tools/BraceMatching/NoBraceMatching", false);
        SET_SETTINGS("Tools/BraceMatching/SloppyBraceMatch", false);
        SET_SETTINGS("Tools/BraceMatching/StrictBraceMatch", true);
    }
}

void TpMainWindow::onAction_T_B_I_B(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoInsertBrackets(isChecked);
        SET_SETTINGS("Tools/BraceMatching/AutoInsert/Brackets", isChecked);
    }
}

void TpMainWindow::onAction_T_B_I_N(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoBrace(isChecked);
        SET_SETTINGS("Tools/BraceMatching/AutoInsert/BracesOnNewlines", isChecked);
    }
}

void TpMainWindow::onAction_T_B_I_S(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoBrace(isChecked);
        SET_SETTINGS("Tools/BraceMatching/AutoInsert/BracketsAndQuotesWithinSelection", isChecked);
    }
}

void TpMainWindow::onAction_T_B_D_B(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setAutoBrace(isChecked);
        SET_SETTINGS("Tools/BraceMatching/AutoDelete/BracketsAndQuotes", isChecked);
    }
}

void TpMainWindow::onAction_T_C_T(bool)
{
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->callTip();
    }
}

void TpMainWindow::onAction_T_C_P_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsPosition(TpEditor::CallTipsPosition::CallTipsBelowText);
        SET_SETTINGS("Tools/CallTips/Position/BelowText", true);
        SET_SETTINGS("Tools/CallTips/Position/AboveText", false);
    }
}

void TpMainWindow::onAction_T_C_P_A(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsPosition(TpEditor::CallTipsPosition::CallTipsAboveText);
        SET_SETTINGS("Tools/CallTips/Position/BelowText", false);
        SET_SETTINGS("Tools/CallTips/Position/AboveText", true);
    }
}

void TpMainWindow::onAction_T_C_S_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsStyle(TpEditor::CallTipsStyle::CallTipsNone);
        SET_SETTINGS("Tools/CallTips/Style/DisableCallTips", true);
        SET_SETTINGS("Tools/CallTips/Style/NoContextOrScope", false);
        SET_SETTINGS("Tools/CallTips/Style/NoAutocompletionContext", false);
        SET_SETTINGS("Tools/CallTips/Style/WithAllContext", false);
    }
}

void TpMainWindow::onAction_T_C_S_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsStyle(TpEditor::CallTipsStyle::CallTipsNoContext);
        SET_SETTINGS("Tools/CallTips/Style/DisableCallTips", false);
        SET_SETTINGS("Tools/CallTips/Style/NoContextOrScope", true);
        SET_SETTINGS("Tools/CallTips/Style/NoAutocompletionContext", false);
        SET_SETTINGS("Tools/CallTips/Style/WithAllContext", false);
    }
}

void TpMainWindow::onAction_T_C_S_A(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsStyle(TpEditor::CallTipsStyle::CallTipsNoAutoCompletionContext);
        SET_SETTINGS("Tools/CallTips/Style/DisableCallTips", false);
        SET_SETTINGS("Tools/CallTips/Style/NoContextOrScope", false);
        SET_SETTINGS("Tools/CallTips/Style/NoAutocompletionContext", true);
        SET_SETTINGS("Tools/CallTips/Style/WithAllContext", false);
    }
}

void TpMainWindow::onAction_T_C_S_W(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCallTipsStyle(TpEditor::CallTipsStyle::CallTipsContext);
        SET_SETTINGS("Tools/CallTips/Style/DisableCallTips", false);
        SET_SETTINGS("Tools/CallTips/Style/NoContextOrScope", false);
        SET_SETTINGS("Tools/CallTips/Style/NoAutocompletionContext", false);
        SET_SETTINGS("Tools/CallTips/Style/WithAllContext", true);
    }
}

void TpMainWindow::onAction_T_E_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEdgeMode(TpEditor::EdgeMode::EdgeNone);
        SET_SETTINGS("Tools/EdgeMode/None", true);
        SET_SETTINGS("Tools/EdgeMode/Line", false);
        SET_SETTINGS("Tools/EdgeMode/Background", false);
    }
}

void TpMainWindow::onAction_T_E_L(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEdgeMode(TpEditor::EdgeMode::EdgeLine);
        SET_SETTINGS("Tools/EdgeMode/None", false);
        SET_SETTINGS("Tools/EdgeMode/Line", true);
        SET_SETTINGS("Tools/EdgeMode/Background", false);
    }
}

void TpMainWindow::onAction_T_E_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEdgeMode(TpEditor::EdgeMode::EdgeBackground);
        SET_SETTINGS("Tools/EdgeMode/None", false);
        SET_SETTINGS("Tools/EdgeMode/Line", false);
        SET_SETTINGS("Tools/EdgeMode/Background", true);
    }
}

void TpMainWindow::onAction_T_V_S(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setSelectionToEol(isChecked);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/SelectionTillBorder", isChecked);
    }
}

void TpMainWindow::onAction_T_V_M(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETMULTIPLESELECTION, isChecked);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/MultipleSelection", isChecked);
    }
}

void TpMainWindow::onAction_T_V_A(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETADDITIONALSELECTIONTYPING, isChecked);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/AdditionalSelectionTyping", isChecked);
    }
}

void TpMainWindow::onAction_T_V_P(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETMULTIPASTE, isChecked);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/MultiplePaste", isChecked);
    }
}

void TpMainWindow::onAction_T_V_V_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETVIRTUALSPACEOPTIONS, 0);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/Disabled", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/OnRectangularSelections", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/UsersAccessible", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/NoWrapLineStart", false);
    }
}

void TpMainWindow::onAction_T_V_V_R(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETVIRTUALSPACEOPTIONS, 1);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/Disabled", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/OnRectangularSelections", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/UsersAccessible", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/NoWrapLineStart", false);
    }
}

void TpMainWindow::onAction_T_V_V_U(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETVIRTUALSPACEOPTIONS, 2);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/Disabled", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/OnRectangularSelections", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/UsersAccessible", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/NoWrapLineStart", false);
    }
}

void TpMainWindow::onAction_T_V_V_W(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETVIRTUALSPACEOPTIONS, 4);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/Disabled", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/OnRectangularSelections", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/UsersAccessible", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/NoWrapLineStart", true);
    }
}

void TpMainWindow::onAction_T_V_R_C(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETRECTANGULARSELECTIONMODIFIER, 2);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/RectangularSelectionModifier/CTRL", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/RectangularSelectionModifier/ALT", false);
    }
}

void TpMainWindow::onAction_T_V_R_A(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETRECTANGULARSELECTIONMODIFIER, 4);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/RectangularSelectionModifier/CTRL", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/RectangularSelectionModifier/ALT", true);
    }
}

void TpMainWindow::onAction_T_V_C_O(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETCARETSTICKY, 0);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/Off", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/On", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/WithWhitespacesOnly", false);
    }
}

void TpMainWindow::onAction_T_V_C_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETCARETSTICKY, 1);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/Off", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/On", true);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/WithWhitespacesOnly", false);
    }
}

void TpMainWindow::onAction_T_V_C_W(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETCARETSTICKY, 2);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/Off", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/On", false);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/WithWhitespacesOnly", true);
    }
}

void TpMainWindow::onAction_T_V_L(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setCaretLineVisible(isChecked);
        SET_SETTINGS("Tools/CaretAndVirtualSelection/CaretLineVisible", isChecked);
    }
}

void TpMainWindow::onAction_T_S_R_N(bool)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkSimpleRegex->setChecked(false);
            container->m_checkPosixRegex->setChecked(false);
            container->m_checkCppRegex->setChecked(false);

            SET_SETTINGS("Tools/Search/RegularExpression/No", true);
            SET_SETTINGS("Tools/Search/RegularExpression/Simple", false);
            SET_SETTINGS("Tools/Search/RegularExpression/POSIX", false);
            SET_SETTINGS("Tools/Search/RegularExpression/C++", false);
        }
    }
}

void TpMainWindow::onAction_T_S_R_S(bool)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkSimpleRegex->setChecked(true);
            container->m_checkPosixRegex->setChecked(false);
            container->m_checkCppRegex->setChecked(false);

            SET_SETTINGS("Tools/Search/RegularExpression/No", false);
            SET_SETTINGS("Tools/Search/RegularExpression/Simple", true);
            SET_SETTINGS("Tools/Search/RegularExpression/POSIX", false);
            SET_SETTINGS("Tools/Search/RegularExpression/C++", false);
        }
    }
}

void TpMainWindow::onAction_T_S_R_P(bool)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkSimpleRegex->setChecked(false);
            container->m_checkPosixRegex->setChecked(true);
            container->m_checkCppRegex->setChecked(false);

            SET_SETTINGS("Tools/Search/RegularExpression/No", false);
            SET_SETTINGS("Tools/Search/RegularExpression/Simple", false);
            SET_SETTINGS("Tools/Search/RegularExpression/POSIX", true);
            SET_SETTINGS("Tools/Search/RegularExpression/C++", false);
        }
    }
}

void TpMainWindow::onAction_T_S_R_pl(bool)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkSimpleRegex->setChecked(false);
            container->m_checkPosixRegex->setChecked(false);
            container->m_checkCppRegex->setChecked(true);

            SET_SETTINGS("Tools/Search/RegularExpression/No", false);
            SET_SETTINGS("Tools/Search/RegularExpression/Simple", false);
            SET_SETTINGS("Tools/Search/RegularExpression/POSIX", false);
            SET_SETTINGS("Tools/Search/RegularExpression/C++", true);
        }
    }
}

void TpMainWindow::onAction_T_S_C(bool isChecked)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkCase->setChecked(isChecked);
            SET_SETTINGS("Tools/Search/Casesensitive", isChecked);
        }
    }
}

void TpMainWindow::onAction_T_S_O(bool isChecked)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkWord->setChecked(isChecked);
            SET_SETTINGS("Tools/Search/WholeWordOnly", isChecked);
        }
    }
}

void TpMainWindow::onAction_T_S_W(bool isChecked)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkWrap->setChecked(isChecked);
            SET_SETTINGS("Tools/Search/WordWrap", isChecked);
        }
    }
}

void TpMainWindow::onAction_T_S_S(bool isChecked)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkShow->setChecked(isChecked);
            SET_SETTINGS("Tools/Search/Show", isChecked);
        }
    }
}

void TpMainWindow::onAction_T_S_G(bool isChecked)
{
    DEF_SETTINGS;

    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        TpFindContainer *container = editor->m_findContainer;

        if (container)
        {
            container->m_checkPrevious->setChecked(isChecked);
            SET_SETTINGS("Tools/Search/GoPrevious", isChecked);
        }
    }
}

void TpMainWindow::onAction_T_W_I_P(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapIndentMode(TpEditor::WrapIndentMode::WrapIndentFixed);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Predefined", true);
        SET_SETTINGS("Tools/WrappingTools/Indentation/SameAsFirstSubline", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Indented", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Doubleindented", false);
    }
}

void TpMainWindow::onAction_T_W_I_S(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapIndentMode(TpEditor::WrapIndentMode::WrapIndentSame);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Predefined", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/SameAsFirstSubline", true);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Indented", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Doubleindented", false);
    }
}

void TpMainWindow::onAction_T_W_I_I(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapIndentMode(TpEditor::WrapIndentMode::WrapIndentIndented);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Predefined", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/SameAsFirstSubline", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Indented", true);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Doubleindented", false);
    }
}

void TpMainWindow::onAction_T_W_I_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setWrapIndentMode(TpEditor::WrapIndentMode::WrapIndentDeeplyIndented);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Predefined", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/SameAsFirstSubline", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Indented", false);
        SET_SETTINGS("Tools/WrappingTools/Indentation/Doubleindented", true);
    }
}

void TpMainWindow::onAction_T_W_S_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setStartFlag(TpEditor::WrapVisualFlag::WrapFlagNone);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/None", true);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_S_T(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setStartFlag(TpEditor::WrapVisualFlag::WrapFlagByText);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByText", true);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_S_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setStartFlag(TpEditor::WrapVisualFlag::WrapFlagByBorder);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByBorder", true);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_S_M(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setStartFlag(TpEditor::WrapVisualFlag::WrapFlagInMargin);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/StartFlag/InMargin", true);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_E_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEndFlag(TpEditor::WrapVisualFlag::WrapFlagNone);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/None", true);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_E_T(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEndFlag(TpEditor::WrapVisualFlag::WrapFlagByText);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByText", true);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_E_B(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEndFlag(TpEditor::WrapVisualFlag::WrapFlagByBorder);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByBorder", true);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/InMargin", false);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_W_E_M(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->setEndFlag(TpEditor::WrapVisualFlag::WrapFlagInMargin);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/None", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByText", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/ByBorder", false);
        SET_SETTINGS("Tools/WrappingTools/EndFlag/InMargin", true);
        emit wrapVisualFlagChanged();
    }
}

void TpMainWindow::onAction_T_M_B(bool isChecked)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETBUFFEREDDRAW, isChecked);
        SET_SETTINGS("Tools/Miscellaneous/BufferedDraw", isChecked);
    }
}

void TpMainWindow::onAction_T_M_P_O(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETPHASESDRAW, 0);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseOne", true);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseTwo", false);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseMultiple", false);
    }
}

void TpMainWindow::onAction_T_M_P_T(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETPHASESDRAW, 1);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseOne", false);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseTwo", true);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseMultiple", false);
    }
}

void TpMainWindow::onAction_T_M_P_M(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETPHASESDRAW, 2);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseOne", false);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseTwo", false);
        SET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseMultiple", true);
    }
}

void TpMainWindow::onAction_T_M_Q_D(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETFONTQUALITY, 0);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Default", true);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Nonantialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Antialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/LCDOptimized", false);
    }
}

void TpMainWindow::onAction_T_M_Q_N(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETFONTQUALITY, 1);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Default", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Nonantialized", true);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Antialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/LCDOptimized", false);
    }
}

void TpMainWindow::onAction_T_M_Q_A(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETFONTQUALITY, 2);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Default", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Nonantialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Antialized", true);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/LCDOptimized", false);
    }
}

void TpMainWindow::onAction_T_M_Q_L(bool)
{
    DEF_SETTINGS;
    TpEditor *editor = m_widget->tabs()->tab()->tab();

    if (editor)
    {
        editor->SendScintilla(TpEditor::SCI_SETFONTQUALITY, 3);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Default", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Nonantialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/Antialized", false);
        SET_SETTINGS("Tools/Miscellaneous/FontQuality/LCDOptimized", true);
    }
}

TP_END_NAMESPACE
