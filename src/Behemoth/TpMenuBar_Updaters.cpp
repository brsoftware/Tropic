#include <Widgets/TpFindContainer>
#include <TpEditor>
#include <TpMenuBar>
#include <TpTabWidget>

TP_NAMESPACE

void TpMenuBar::updateGeneralAccessibility(bool h, bool f)
{
    if (h)
    {
        F_E->setEnabled(h);
        F_T_F->setEnabled(f);
        F_T_C->setEnabled(f);
        F_T_T->setEnabled(f);
        F_D->setEnabled(f);
        F_B_R->setEnabled(h);
        F_B_D->setEnabled(h);
        F_B_F->setEnabled(h);
        F_B_A->setEnabled(h);
        F_B_N->setEnabled(h);
    }

    F_S->setEnabled(h);
    F_A->setEnabled(h);
    F_Y->setEnabled(h);
    F_d->setEnabled(h);
    F_C->setEnabled(h);
    F_L->setEnabled(h);
    F_p->setEnabled(h);
    F_M_B->setEnabled(h);
    F_M_L->setEnabled(h);
    F_M_R->setEnabled(h);
    F_M_U->setEnabled(h);
    // F_P->setEnabled(h);
    // F_V->setEnabled(h);
    E_U->setEnabled(h);
    E_R->setEnabled(h);
    E_C->setEnabled(h);
    E_O->setEnabled(h);
    E_P->setEnabled(h);
    E_D_D->setEnabled(h);
    E_D_B->setEnabled(h);
    E_D_I->setEnabled(h);
    E_D_L->setEnabled(h);
    E_D_R->setEnabled(h);
    E_D_E->setEnabled(h);
    E_D_N->setEnabled(h);
    E_D_G->setEnabled(h);
    E_M_A->setEnabled(h);
    E_M_B->setEnabled(h);
    E_M_C->setEnabled(h);
    E_M_D->setEnabled(h);
    E_M_E->setEnabled(h);
    E_M_F->setEnabled(h);
    E_M_G->setEnabled(h);
    E_M_H->setEnabled(h);
    E_M_I->setEnabled(h);
    E_M_J->setEnabled(h);
    E_M_K->setEnabled(h);
    E_M_L->setEnabled(h);
    E_M_M->setEnabled(h);
    E_M_N->setEnabled(h);
    E_M_O->setEnabled(h);
    E_M_P->setEnabled(h);
    E_M_Q->setEnabled(h);
    E_M_R->setEnabled(h);
    E_M_S->setEnabled(h);
    E_M_T->setEnabled(h);
    E_M_U->setEnabled(h);
    E_M_V->setEnabled(h);
    E_M_W->setEnabled(h);
    E_M_X->setEnabled(h);
    E_M_Y->setEnabled(h);
    E_M_Z->setEnabled(h);
    E_S_A->setEnabled(h);
    E_S_B->setEnabled(h);
    E_S_C->setEnabled(h);
    E_S_D->setEnabled(h);
    E_S_E->setEnabled(h);
    E_S_F->setEnabled(h);
    E_S_G->setEnabled(h);
    E_S_H->setEnabled(h);
    E_S_I->setEnabled(h);
    E_S_J->setEnabled(h);
    E_S_K->setEnabled(h);
    E_S_L->setEnabled(h);
    E_S_M->setEnabled(h);
    E_S_N->setEnabled(h);
    E_S_O->setEnabled(h);
    E_S_P->setEnabled(h);
    E_S_Q->setEnabled(h);
    E_S_R->setEnabled(h);
    E_S_S->setEnabled(h);
    E_S_T->setEnabled(h);
    E_S_U->setEnabled(h);
    E_S_V->setEnabled(h);
    E_S_W->setEnabled(h);
    E_S_X->setEnabled(h);
    E_S_Y->setEnabled(h);
    E_S_Z->setEnabled(h);
    E_S_0->setEnabled(h);
    E_S_1->setEnabled(h);
    E_S_2->setEnabled(h);
    E_S_3->setEnabled(h);
    E_S_4->setEnabled(h);
    E_S_5->setEnabled(h);
    E_S_6->setEnabled(h);
    E_S_7->setEnabled(h);
    E_S_8->setEnabled(h);
    E_S_9->setEnabled(h);
    E_I_I->setEnabled(h);
    E_I_D->setEnabled(h);
    E_L_D->setEnabled(h);
    E_L_C->setEnabled(h);
    E_L_O->setEnabled(h);
    E_L_T->setEnabled(h);
    E_L_U->setEnabled(h);
    E_L_W->setEnabled(h);
    E_L_R->setEnabled(h);
    E_L_N->setEnabled(h);
    E_L_E->setEnabled(h);
    E_L_B->setEnabled(h);
    E_L_V->setEnabled(h);
    E_L_Z->setEnabled(h);
    E_W_T->setEnabled(h);
    E_W_L->setEnabled(h);
    E_W_B->setEnabled(h);
    E_W_S->setEnabled(h);
    E_W_P->setEnabled(h);
    E_W_A->setEnabled(h);
    E_A_L->setEnabled(h);
    E_A_S->setEnabled(h);
    E_G->setEnabled(h);
    E_E_F->setEnabled(h);
    E_E_I->setEnabled(h);
    E_E_N->setEnabled(h);
    E_E_P->setEnabled(h);
    E_E_X->setEnabled(h);
    E_E_U->setEnabled(h);
    E_E_L->setEnabled(h);
    E_E_G->setEnabled(h);
    E_E_S->setEnabled(h);
    E_E_M->setEnabled(h);
    E_B_T->setEnabled(h);
    E_B_N->setEnabled(h);
    E_B_P->setEnabled(h);
    E_B_C->setEnabled(h);
    E_B_O->setEnabled(h);
    E_B_R->setEnabled(h);
    E_B_A->setEnabled(h);
    E_B_h->setEnabled(h);
    E_B_I->setEnabled(h);
    V_Y_S->setEnabled(h);
    V_Y_A->setEnabled(h);
    V_Y_T->setEnabled(h);
    V_Y_N->setEnabled(h);
    V_Y_W->setEnabled(h);
    V_Y_I->setEnabled(h);
    V_Z_I->setEnabled(h);
    V_Z_O->setEnabled(h);
    V_Z_T->setEnabled(h);
    V_T_1->setEnabled(h);
    V_T_2->setEnabled(h);
    V_T_3->setEnabled(h);
    V_T_4->setEnabled(h);
    V_T_5->setEnabled(h);
    V_T_6->setEnabled(h);
    V_T_7->setEnabled(h);
    V_T_8->setEnabled(h);
    V_T_9->setEnabled(h);
    V_T_0->setEnabled(h);
    V_T_L->setEnabled(h);
    V_T_N->setEnabled(h);
    V_T_F->setEnabled(h);
    V_T_P->setEnabled(h);
    V_T_M->setEnabled(h);
    V_T_R->setEnabled(h);
    V_T_S->setEnabled(h);
    V_T_T->setEnabled(h);
    V_W_N->setEnabled(h);
    V_W_W->setEnabled(h);
    V_W_C->setEnabled(h);
    V_W_H->setEnabled(h);
    V_L_M->setEnabled(h);
    V_L_T->setEnabled(h);
    V_L_C->setEnabled(h);
    V_I->setEnabled(h);
    V_C_D->setEnabled(h);
    V_C_U->setEnabled(h);
    V_C_S->setEnabled(h);
    V_C_E->setEnabled(h);
    V_C_V->setEnabled(h);
    V_O_H->setEnabled(h);
    V_O_A->setEnabled(h);
    V_O_C->setEnabled(h);
    V_O_E->setEnabled(h);
    V_O_S_D->setEnabled(h);
    V_O_S_P->setEnabled(h);
    V_O_S_C->setEnabled(h);
    V_O_S_B->setEnabled(h);
    V_O_S_T->setEnabled(h);
    V_O_S_X->setEnabled(h);
    I_F->setEnabled(h);
    I_T->setEnabled(h);
    I_V->setEnabled(h);
    I_A->setEnabled(h);
    I_B->setEnabled(h);
    I_N_W->setEnabled(h);
    I_N_M->setEnabled(h);
    I_N_U->setEnabled(h);
    I_D_D->setEnabled(h);
    I_D_T->setEnabled(h);
    I_D_A->setEnabled(h);
    I_O->setEnabled(h);
    O_L_p->setEnabled(h);
    O_L_A_C->setEnabled(h);
    O_L_A_S->setEnabled(h);
    O_L_A_A->setEnabled(h);
    O_L_B_B->setEnabled(h);
    O_L_B_T->setEnabled(h);
    O_L_B_S->setEnabled(h);
    O_L_B_A->setEnabled(h);
    O_L_B_F->setEnabled(h);
    O_L_C_C->setEnabled(h);
    O_L_C_pl->setEnabled(h);
    O_L_C_p->setEnabled(h);
    O_L_C_s->setEnabled(h);
    O_L_C_M->setEnabled(h);
    O_L_C_O->setEnabled(h);
    O_L_C_S->setEnabled(h);
    O_L_D_D->setEnabled(h);
    O_L_D_I->setEnabled(h);
    O_L_E_E->setEnabled(h);
    O_L_F_F->setEnabled(h);
    O_L_F_7->setEnabled(h);
    O_L_G_G->setEnabled(h);
    O_L_H_H->setEnabled(h);
    O_L_H_T->setEnabled(h);
    O_L_I_I->setEnabled(h);
    O_L_I_H->setEnabled(h);
    O_L_J_J->setEnabled(h);
    O_L_J_S->setEnabled(h);
    O_L_J_O->setEnabled(h);
    O_L_L_T->setEnabled(h);
    O_L_L_L->setEnabled(h);
    O_L_M_F->setEnabled(h);
    O_L_M_D->setEnabled(h);
    O_L_M_M->setEnabled(h);
    O_L_M_L->setEnabled(h);
    O_L_N_N->setEnabled(h);
    O_L_O_O->setEnabled(h);
    O_L_P_P->setEnabled(h);
    O_L_P_E->setEnabled(h);
    O_L_P_H->setEnabled(h);
    O_L_P_O->setEnabled(h);
    O_L_P_S->setEnabled(h);
    O_L_P_V->setEnabled(h);
    O_L_P_R->setEnabled(h);
    O_L_P_2->setEnabled(h);
    O_L_P_3->setEnabled(h);
    O_L_P_X->setEnabled(h);
    O_L_Q_Q->setEnabled(h);
    O_L_Q_S->setEnabled(h);
    O_L_Q_U->setEnabled(h);
    O_L_R_R->setEnabled(h);
    O_L_S_S->setEnabled(h);
    O_L_S_Q->setEnabled(h);
    O_L_S_R->setEnabled(h);
    O_L_T_T->setEnabled(h);
    O_L_T_H->setEnabled(h);
    O_L_T_X->setEnabled(h);
    O_L_V_V->setEnabled(h);
    O_L_V_H->setEnabled(h);
    O_L_X_X->setEnabled(h);
    O_L_Y_Y->setEnabled(h);
    O_N_U->setEnabled(h);
    O_N_C->setEnabled(h);
    O_N_E->setEnabled(h);
    O_N_T->setEnabled(h);
    O_N_M->setEnabled(h);
    O_N_X->setEnabled(h);
    O_C_U->setEnabled(h);
    O_C_L->setEnabled(h);
    O_C_T->setEnabled(h);
    O_C_S->setEnabled(h);
    O_C_I->setEnabled(h);
    O_C_R->setEnabled(h);
    O_I_T->setEnabled(h);
    O_I_B->setEnabled(h);
    O_I_I->setEnabled(h);
    O_R_L->setEnabled(h);
    O_R_S->setEnabled(h);
    O_S->setEnabled(h);
    O_h->setEnabled(h);
    O_A_U->setEnabled(h);
    O_A_L->setEnabled(h);
    T_A_C->setEnabled(h);
    T_A_F->setEnabled(h);
    T_A_R->setEnabled(h);
    T_A_W_N->setEnabled(h);
    T_A_W_O->setEnabled(h);
    T_A_W_D->setEnabled(h);
    T_A_S_D->setEnabled(h);
    T_A_S_A->setEnabled(h);
    T_A_S_O->setEnabled(h);
    T_A_S_L->setEnabled(h);
    T_A_T_A->setEnabled(h);
    T_A_T_D->setEnabled(h);
    T_A_T_L->setEnabled(h);
    T_h_A->setEnabled(h);
    T_h_S_A->setEnabled(h);
    T_h_S_M->setEnabled(h);
    T_h_S_O->setEnabled(h);
    T_h_S_C->setEnabled(h);
    T_B_N->setEnabled(h);
    T_B_S->setEnabled(h);
    T_B_B->setEnabled(h);
    T_B_I_B->setEnabled(h);
    T_B_I_N->setEnabled(h);
    T_B_I_S->setEnabled(h);
    T_B_D_B->setEnabled(h);
    T_C_T->setEnabled(h);
    T_C_P_B->setEnabled(h);
    T_C_P_A->setEnabled(h);
    T_C_S_D->setEnabled(h);
    T_C_S_N->setEnabled(h);
    T_C_S_A->setEnabled(h);
    T_C_S_W->setEnabled(h);
    T_E_N->setEnabled(h);
    T_E_L->setEnabled(h);
    T_E_B->setEnabled(h);
    T_V_S->setEnabled(h);
    T_V_M->setEnabled(h);
    T_V_A->setEnabled(h);
    T_V_P->setEnabled(h);
    T_V_V_D->setEnabled(h);
    T_V_V_R->setEnabled(h);
    T_V_V_U->setEnabled(h);
    T_V_V_W->setEnabled(h);
    T_V_R_C->setEnabled(h);
    T_V_R_A->setEnabled(h);
    T_V_C_O->setEnabled(h);
    T_V_C_N->setEnabled(h);
    T_V_C_W->setEnabled(h);
    T_V_L->setEnabled(h);
    T_S_R_N->setEnabled(h);
    T_S_R_S->setEnabled(h);
    T_S_R_P->setEnabled(h);
    T_S_R_pl->setEnabled(h);
    T_S_C->setEnabled(h);
    T_S_O->setEnabled(h);
    T_S_W->setEnabled(h);
    T_S_S->setEnabled(h);
    T_S_G->setEnabled(h);
    T_W_I_P->setEnabled(h);
    T_W_I_S->setEnabled(h);
    T_W_I_I->setEnabled(h);
    T_W_I_D->setEnabled(h);
    T_W_S_N->setEnabled(h);
    T_W_S_T->setEnabled(h);
    T_W_S_B->setEnabled(h);
    T_W_S_M->setEnabled(h);
    T_W_E_N->setEnabled(h);
    T_W_E_T->setEnabled(h);
    T_W_E_B->setEnabled(h);
    T_W_E_M->setEnabled(h);
    T_M_B->setEnabled(h);
    T_M_P_O->setEnabled(h);
    T_M_P_T->setEnabled(h);
    T_M_P_M->setEnabled(h);
    T_M_Q_D->setEnabled(h);
    T_M_Q_N->setEnabled(h);
    T_M_Q_A->setEnabled(h);
    T_M_Q_L->setEnabled(h);
    W_B->setEnabled(h);
    W_D->setEnabled(h);
    // W_Q->setEnabled(h);
}

void TpMenuBar::updateToSettings()
{
#define TRIGGER(action) {if (action->isChecked()) {action->trigger(); action->trigger();} else {action->trigger();}}

    DEF_SETTINGS;

    if (GET_SETTINGS("View/ShowSymbols/SpacesAndTabsAll", bool))
        TRIGGER(V_Y_S);
    if (GET_SETTINGS("View/ShowSymbols/SpacesAndTabsAfterIndentation", bool))
        TRIGGER(V_Y_A);
    if (GET_SETTINGS("View/ShowSymbols/SpacesAndTabsInIndentation", bool))
        TRIGGER(V_Y_T);
    if (GET_SETTINGS("View/ShowSymbols/NonPrintable", bool))
        TRIGGER(V_Y_N);
    if (GET_SETTINGS("View/ShowSymbols/WrapVisualFlags", bool))
        TRIGGER(V_Y_W);
    if (GET_SETTINGS("View/ShowSymbols/IndentationGuides", bool))
        TRIGGER(V_Y_I);
    if (GET_SETTINGS("View/WordWrap/None", bool))
        TRIGGER(V_W_N);
    if (GET_SETTINGS("View/WordWrap/Word", bool))
        TRIGGER(V_W_W);
    if (GET_SETTINGS("View/WordWrap/Character", bool))
        TRIGGER(V_W_C);
    if (GET_SETTINGS("View/WordWrap/Whitespace", bool))
        TRIGGER(V_W_H);
    if (GET_SETTINGS("View/LineNumbers", bool))
        TRIGGER(V_I);
    if (GET_SETTINGS("View/Folding/DisableFolding", bool))
        TRIGGER(V_O_S_D);
    if (GET_SETTINGS("View/Folding/Plain", bool))
        TRIGGER(V_O_S_P);
    if (GET_SETTINGS("View/Folding/Circled", bool))
        TRIGGER(V_O_S_C);
    if (GET_SETTINGS("View/Folding/Boxed", bool))
        TRIGGER(V_O_S_B);
    if (GET_SETTINGS("View/Folding/CircledTree", bool))
        TRIGGER(V_O_S_T);
    if (GET_SETTINGS("View/Folding/BoxedTree", bool))
        TRIGGER(V_O_S_X);
    O_L_p->trigger();
    if (GET_SETTINGS("Format/Newline/UseWindows", bool))
        TRIGGER(O_N_U);
    if (GET_SETTINGS("Format/Newline/UseClassicalMac", bool))
        TRIGGER(O_N_C);
    if (GET_SETTINGS("Format/Newline/UseUnix", bool))
        TRIGGER(O_N_E);
    if (GET_SETTINGS("Format/Indentation/UseTabsToIndent", bool))
        TRIGGER(O_I_T);
    if (GET_SETTINGS("Format/Indentation/BackspaceUnindents", bool))
        TRIGGER(O_I_B);
    if (GET_SETTINGS("Format/Indentation/TabToIndent", bool))
        TRIGGER(O_I_I);
    if (GET_SETTINGS("Format/RepresentingTabs/LongArrow", bool))
        TRIGGER(O_R_L);
    if (GET_SETTINGS("Format/RepresentingTabs/StrikeOut", bool))
        TRIGGER(O_R_S);
    if (GET_SETTINGS("Format/SelectFirstWrappedLineOnly", bool))
        TRIGGER(O_S);
    if (GET_SETTINGS("Tools/Autocompletion/CaseSensitive", bool))
        TRIGGER(T_A_C);
    if (GET_SETTINGS("Tools/Autocompletion/FillupsEnabled", bool))
        TRIGGER(T_A_F);
    if (GET_SETTINGS("Tools/Autocompletion/ReplaceWord", bool))
        TRIGGER(T_A_R);
    if (GET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/DoNotDisplay", bool))
        TRIGGER(T_A_W_N);
    if (GET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/OnlyManually", bool))
        TRIGGER(T_A_W_O);
    if (GET_SETTINGS("Tools/Autocompletion/WhenSingleEntry/AlwaysDisplay", bool))
        TRIGGER(T_A_W_D);
    if (GET_SETTINGS("Tools/Autocompletion/Sources/DoNotDisplay", bool))
        TRIGGER(T_A_S_D);
    if (GET_SETTINGS("Tools/Autocompletion/Sources/All", bool))
        TRIGGER(T_A_S_A);
    if (GET_SETTINGS("Tools/Autocompletion/Sources/Document", bool))
        TRIGGER(T_A_S_O);
    if (GET_SETTINGS("Tools/Autocompletion/Sources/Lexer", bool))
        TRIGGER(T_A_S_L);
    if (GET_SETTINGS("Tools/Autoindentation/Autoindentation", bool))
        TRIGGER(T_h_A);
    if (GET_SETTINGS("Tools/Autoindentation/Style/Auto", bool))
        TRIGGER(T_h_S_A);
    if (GET_SETTINGS("Tools/Autoindentation/Style/Maintain", bool))
        TRIGGER(T_h_S_M);
    if (GET_SETTINGS("Tools/Autoindentation/Style/Opening", bool))
        TRIGGER(T_h_S_O);
    if (GET_SETTINGS("Tools/Autoindentation/Style/Closing", bool))
        TRIGGER(T_h_S_C);
    if (GET_SETTINGS("Tools/BraceMatching/NoBraceMatching", bool))
        TRIGGER(T_B_N);
    if (GET_SETTINGS("Tools/BraceMatching/SloppyBraceMatch", bool))
        TRIGGER(T_B_S);
    if (GET_SETTINGS("Tools/BraceMatching/StrictBraceMatch", bool))
        TRIGGER(T_B_B);
    if (GET_SETTINGS("Tools/BraceMatching/AutoInsert/Brackets", bool))
        TRIGGER(T_B_I_B);
    if (GET_SETTINGS("Tools/BraceMatching/AutoInsert/BracesOnNewlines", bool))
        TRIGGER(T_B_I_N);
    if (GET_SETTINGS("Tools/BraceMatching/AutoInsert/BracketsAndQuotesWithinSelection", bool))
        TRIGGER(T_B_I_S);
    if (GET_SETTINGS("Tools/BraceMatching/AutoDelete/BracketsAndQuotes", bool))
        TRIGGER(T_B_D_B);
    if (GET_SETTINGS("Tools/CallTips/Position/BelowText", bool))
        TRIGGER(T_C_P_B);
    if (GET_SETTINGS("Tools/CallTips/Position/AboveText", bool))
        TRIGGER(T_C_P_A);
    if (GET_SETTINGS("Tools/CallTips/Style/DisableCallTips", bool))
        TRIGGER(T_C_S_D);
    if (GET_SETTINGS("Tools/CallTips/Style/NoContextOrScope", bool))
        TRIGGER(T_C_S_N);
    if (GET_SETTINGS("Tools/CallTips/Style/NoAutocompletionContext", bool))
        TRIGGER(T_C_S_A);
    if (GET_SETTINGS("Tools/CallTips/Style/WithAllContext", bool))
        TRIGGER(T_C_S_W);
    if (GET_SETTINGS("Tools/EdgeMode/None", bool))
        TRIGGER(T_E_N);
    if (GET_SETTINGS("Tools/EdgeMode/Line", bool))
        TRIGGER(T_E_L);
    if (GET_SETTINGS("Tools/EdgeMode/Background", bool))
        TRIGGER(T_E_B);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/SelectionTillBorder", bool))
        TRIGGER(T_V_S);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/MultipleSelection", bool))
        TRIGGER(T_V_M);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/AdditionalSelectionTyping", bool))
        TRIGGER(T_V_A);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/MultiplePaste", bool))
        TRIGGER(T_V_P);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/Disabled", bool))
        TRIGGER(T_V_V_D);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/OnRectangularSelections", bool))
        TRIGGER(T_V_V_R);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/UserAccessible", bool))
        TRIGGER(T_V_V_U);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/VirtualSpace/NoWrapLineStart", bool))
        TRIGGER(T_V_V_W);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/RectangularSelectionModifier/CTRL", bool))
        TRIGGER(T_V_R_C);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/RectangularSelectionModifier/ALT", bool))
        TRIGGER(T_V_R_A);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/Off", bool))
        TRIGGER(T_V_C_O);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/On", bool))
        TRIGGER(T_V_C_N);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/CaretSticky/WithWhitespacesOnly", bool))
        TRIGGER(T_V_C_W);
    if (GET_SETTINGS("Tools/CaretAndVirtualSelection/CaretLineVisible", bool))
        TRIGGER(T_V_L);
    if (GET_SETTINGS("Tools/Search/RegularExpression/No", bool))
        TRIGGER(T_S_R_N);
    if (GET_SETTINGS("Tools/Search/RegularExpression/Simple", bool))
        TRIGGER(T_S_R_S);
    if (GET_SETTINGS("Tools/Search/RegularExpression/POSIX", bool))
        TRIGGER(T_S_R_P);
    if (GET_SETTINGS("Tools/Search/RegularExpression/C++", bool))
        TRIGGER(T_S_R_pl);
    if (GET_SETTINGS("Tools/Search/Casesensitive", bool))
        TRIGGER(T_S_C);
    if (GET_SETTINGS("Tools/Search/WholeWordOnly", bool))
        TRIGGER(T_S_O);
    if (GET_SETTINGS("Tools/Search/WordWrap", bool))
        TRIGGER(T_S_W);
    if (GET_SETTINGS("Tools/Search/Show", bool))
        TRIGGER(T_S_S);
    if (GET_SETTINGS("Tools/Search/GoPrevious", bool))
        TRIGGER(T_S_G);
    if (GET_SETTINGS("Tools/WrappingTools/Indentation/Predefined", bool))
        TRIGGER(T_W_I_P);
    if (GET_SETTINGS("Tools/WrappingTools/Indentation/SameAsFirstSubline", bool))
        TRIGGER(T_W_I_S);
    if (GET_SETTINGS("Tools/WrappingTools/Indentation/Indented", bool))
        TRIGGER(T_W_I_I);
    if (GET_SETTINGS("Tools/WrappingTools/Indentation/Doubleindented", bool))
        TRIGGER(T_W_I_D);
    if (GET_SETTINGS("Tools/WrappingTools/StartFlag/None", bool))
        TRIGGER(T_W_S_N);
    if (GET_SETTINGS("Tools/WrappingTools/StartFlag/ByText", bool))
        TRIGGER(T_W_S_T);
    if (GET_SETTINGS("Tools/WrappingTools/StartFlag/ByBorder", bool))
        TRIGGER(T_W_S_B);
    if (GET_SETTINGS("Tools/WrappingTools/StartFlag/InMargin", bool))
        TRIGGER(T_W_S_M);
    if (GET_SETTINGS("Tools/WrappingTools/EndFlag/None", bool))
        TRIGGER(T_W_E_N);
    if (GET_SETTINGS("Tools/WrappingTools/EndFlag/ByText", bool))
        TRIGGER(T_W_E_T);
    if (GET_SETTINGS("Tools/WrappingTools/EndFlag/ByBorder", bool))
        TRIGGER(T_W_E_B);
    if (GET_SETTINGS("Tools/WrappingTools/EndFlag/InMargin", bool))
        TRIGGER(T_W_E_M);
    if (GET_SETTINGS("Tools/Miscellaneous/BufferedDraw", bool))
        TRIGGER(T_M_B);
    if (GET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseOne", bool))
        TRIGGER(T_M_P_O);
    if (GET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseTwo", bool))
        TRIGGER(T_M_P_T);
    if (GET_SETTINGS("Tools/Miscellaneous/PhaseDraw/PhaseMultiple", bool))
        TRIGGER(T_M_P_M);
    if (GET_SETTINGS("Tools/Miscellaneous/FontQuality/Default", bool))
        TRIGGER(T_M_Q_D);
    if (GET_SETTINGS("Tools/Miscellaneous/FontQuality/Nonantialized", bool))
        TRIGGER(T_M_Q_N);
    if (GET_SETTINGS("Tools/Miscellaneous/FontQuality/Antialized", bool))
        TRIGGER(T_M_Q_A);
    if (GET_SETTINGS("Tools/Miscellaneous/FontQuality/LCDOptimized", bool))
        TRIGGER(T_M_Q_L);

#undef TRIGGER
}

void TpMenuBar::updateCheckability(TpTabWidget *tab)
{
    TpEditor *ed = tab->tab();

    if (ed)
    {
        E_G->setChecked(ed->overwriteMode());
        V_Y_S->setChecked(ed->whitespaceVisibility() == TpEditor::WhitespaceVisibility::WsVisible);
        V_Y_A->setChecked(ed->whitespaceVisibility() == TpEditor::WhitespaceVisibility::WsVisibleAfterIndent);
        V_Y_T->setChecked(ed->whitespaceVisibility() == TpEditor::WhitespaceVisibility::WsVisibleOnlyInIndent);
        V_Y_N->setChecked(ed->eolVisibility());
        V_Y_W->setChecked(ed->startFlag() != TpEditor::WrapVisualFlag::WrapFlagNone);
        V_Y_I->setChecked(ed->indentationGuides());
        V_W_N->setChecked(ed->wrapMode() == TpEditor::WrapMode::WrapNone);
        V_W_W->setChecked(ed->wrapMode() == TpEditor::WrapMode::WrapWord);
        V_W_C->setChecked(ed->wrapMode() == TpEditor::WrapMode::WrapCharacter);
        V_W_H->setChecked(ed->wrapMode() == TpEditor::WrapMode::WrapWhitespace);
        V_I->setChecked(ed->lineNumbers());
        V_O_S_D->setChecked(ed->folding() == TpEditor::FoldStyle::NoFoldStyle);
        V_O_S_P->setChecked(ed->folding() == TpEditor::FoldStyle::PlainFoldStyle);
        V_O_S_C->setChecked(ed->folding() == TpEditor::FoldStyle::CircledFoldStyle);
        V_O_S_B->setChecked(ed->folding() == TpEditor::FoldStyle::BoxedFoldStyle);
        V_O_S_T->setChecked(ed->folding() == TpEditor::FoldStyle::CircledTreeFoldStyle);
        V_O_S_X->setChecked(ed->folding() == TpEditor::FoldStyle::BoxedTreeFoldStyle);
        O_L_p->setChecked(ed->currentLexer() == None);
        O_L_A_C->setChecked(ed->currentLexer() == ActionScript);
        O_L_A_S->setChecked(ed->currentLexer() == ASP);
        O_L_A_A->setChecked(ed->currentLexer() == AviSynth);
        O_L_B_B->setChecked(ed->currentLexer() == Bash);
        O_L_B_T->setChecked(ed->currentLexer() == Batch);
        O_L_B_S->setChecked(ed->currentLexer() == BlitzBasic);
        O_L_B_A->setChecked(ed->currentLexer() == PureBasic);
        O_L_B_F->setChecked(ed->currentLexer() == FreeBasic);
        O_L_C_C->setChecked(ed->currentLexer() == C);
        O_L_C_pl->setChecked(ed->currentLexer() == CPP);
        O_L_C_p->setChecked(ed->currentLexer() == CPPQt);
        O_L_C_s->setChecked(ed->currentLexer() == CS);
        O_L_C_M->setChecked(ed->currentLexer() == CMake);
        O_L_C_O->setChecked(ed->currentLexer() == CoffeeScript);
        O_L_C_S->setChecked(ed->currentLexer() == CSS);
        O_L_D_D->setChecked(ed->currentLexer() == D);
        O_L_D_I->setChecked(ed->currentLexer() == Diff);
        O_L_E_E->setChecked(ed->currentLexer() == Erlang);
        O_L_F_F->setChecked(ed->currentLexer() == Fortran);
        O_L_F_7->setChecked(ed->currentLexer() == Fortran77);
        O_L_G_G->setChecked(ed->currentLexer() == GDScript);
        O_L_H_H->setChecked(ed->currentLexer() == HTML);
        O_L_H_T->setChecked(ed->currentLexer() == HTMLFull);
        O_L_I_I->setChecked(ed->currentLexer() == IDL);
        O_L_I_H->setChecked(ed->currentLexer() == IntelHex);
        O_L_J_J->setChecked(ed->currentLexer() == Java);
        O_L_J_S->setChecked(ed->currentLexer() == JavaScript);
        O_L_J_O->setChecked(ed->currentLexer() == JSON);
        O_L_L_T->setChecked(ed->currentLexer() == LaTeX);
        O_L_L_L->setChecked(ed->currentLexer() == Lua);
        O_L_M_F->setChecked(ed->currentLexer() == Makefile);
        O_L_M_D->setChecked(ed->currentLexer() == Markdown);
        O_L_M_M->setChecked(ed->currentLexer() == MASM);
        O_L_M_L->setChecked(ed->currentLexer() == Matlab);
        O_L_N_N->setChecked(ed->currentLexer() == NASM);
        O_L_O_O->setChecked(ed->currentLexer() == Octave);
        O_L_P_P->setChecked(ed->currentLexer() == Pascal);
        O_L_P_E->setChecked(ed->currentLexer() == Perl);
        O_L_P_H->setChecked(ed->currentLexer() == PHP);
        O_L_P_O->setChecked(ed->currentLexer() == PO);
        O_L_P_S->setChecked(ed->currentLexer() == PostScript);
        O_L_P_V->setChecked(ed->currentLexer() == POV);
        O_L_P_R->setChecked(ed->currentLexer() == Properties);
        O_L_P_2->setChecked(ed->currentLexer() == Python2);
        O_L_P_3->setChecked(ed->currentLexer() == Python3);
        O_L_P_X->setChecked(ed->currentLexer() == Python3Extended);
        O_L_Q_Q->setChecked(ed->currentLexer() == QML);
        O_L_Q_S->setChecked(ed->currentLexer() == QSS);
        O_L_Q_U->setChecked(ed->currentLexer() == QUI);
        O_L_R_R->setChecked(ed->currentLexer() == Ruby);
        O_L_S_S->setChecked(ed->currentLexer() == Spice);
        O_L_S_Q->setChecked(ed->currentLexer() == SQL);
        O_L_S_R->setChecked(ed->currentLexer() == SRecord);
        O_L_T_T->setChecked(ed->currentLexer() == TCL);
        O_L_T_H->setChecked(ed->currentLexer() == TektronixHex);
        O_L_T_X->setChecked(ed->currentLexer() == TeX);
        O_L_V_V->setChecked(ed->currentLexer() == Verilog);
        O_L_V_H->setChecked(ed->currentLexer() == VHDL);
        O_L_X_X->setChecked(ed->currentLexer() == XML);
        O_L_Y_Y->setChecked(ed->currentLexer() == YAML);
        O_N_U->setChecked(ed->eolMode() == TpEditor::EolMode::EolWindows);
        O_N_C->setChecked(ed->eolMode() == TpEditor::EolMode::EolMac);
        O_N_E->setChecked(ed->eolMode() == TpEditor::EolMode::EolUnix);
        O_I_T->setChecked(ed->indentationsUseTabs());
        O_I_B->setChecked(ed->backspaceUnindents());
        O_I_I->setChecked(ed->tabIndents());
        O_R_L->setChecked(ed->tabDrawMode() == TpEditor::TabDrawMode::TabLongArrow);
        O_R_S->setChecked(ed->tabDrawMode() == TpEditor::TabDrawMode::TabStrikeOut);
        O_S->setChecked(ed->marginOptions() & TpEditor::MoSublineSelect);
        T_A_C->setChecked(ed->autoCompletionCaseSensitivity());
        T_A_F->setChecked(ed->autoCompletionFillupsEnabled());
        T_A_R->setChecked(ed->autoCompletionReplaceWord());
        T_A_W_N->setChecked(ed->autoCompletionUseSingle() == TpEditor::AutoCompletionUseSingle::AcusNever);
        T_A_W_O->setChecked(ed->autoCompletionUseSingle() == TpEditor::AutoCompletionUseSingle::AcusExplicit);
        T_A_W_D->setChecked(ed->autoCompletionUseSingle() == TpEditor::AutoCompletionUseSingle::AcusAlways);
        T_A_S_D->setChecked(ed->autoCompletionSource() == TpEditor::AutoCompletionSource::AcsNone);
        T_A_S_A->setChecked(ed->autoCompletionSource() == TpEditor::AutoCompletionSource::AcsAll);
        T_A_S_O->setChecked(ed->autoCompletionSource() == TpEditor::AutoCompletionSource::AcsDocument);
        T_A_S_L->setChecked(ed->autoCompletionSource() == TpEditor::AutoCompletionSource::AcsAPIs);
        T_h_A->setChecked(ed->autoIndent());
        T_h_S_A->setChecked(ed->autoCompletionStyle() == 0);
        T_h_S_M->setChecked(ed->autoCompletionStyle() & TpEditor::AiMaintain);
        T_h_S_O->setChecked(ed->autoCompletionStyle() & TpEditor::AiOpening);
        T_h_S_C->setChecked(ed->autoCompletionStyle() & TpEditor::AiClosing);
        T_B_N->setChecked(ed->braceMatching() == TpEditor::BraceMatch::NoBraceMatch);
        T_B_S->setChecked(ed->braceMatching() == TpEditor::BraceMatch::SloppyBraceMatch);
        T_B_B->setChecked(ed->braceMatching() == TpEditor::BraceMatch::StrictBraceMatch);
        T_B_I_B->setChecked(ed->autoInsertBrackets());
        T_B_I_N->setChecked(ed->autoBrace());
        T_B_I_S->setChecked(ed->autoSelectionWrap());
        T_B_D_B->setChecked(ed->autoDelete());
        T_C_P_B->setChecked(ed->callTipsPosition() == TpEditor::CallTipsPosition::CallTipsBelowText);
        T_C_P_A->setChecked(ed->callTipsPosition() == TpEditor::CallTipsPosition::CallTipsAboveText);
        T_C_S_D->setChecked(ed->callTipsStyle() == TpEditor::CallTipsStyle::CallTipsNone);
        T_C_S_N->setChecked(ed->callTipsStyle() == TpEditor::CallTipsStyle::CallTipsNoContext);
        T_C_S_A->setChecked(ed->callTipsStyle() == TpEditor::CallTipsStyle::CallTipsNoAutoCompletionContext);
        T_C_S_W->setChecked(ed->callTipsStyle() == TpEditor::CallTipsStyle::CallTipsContext);
        T_E_N->setChecked(ed->edgeMode() == TpEditor::EdgeMode::EdgeNone);
        T_E_L->setChecked(ed->edgeMode() == TpEditor::EdgeMode::EdgeLine);
        T_E_B->setChecked(ed->edgeMode() == TpEditor::EdgeMode::EdgeBackground);
        T_V_S->setChecked(ed->selectionToEol());
        T_V_M->setChecked(ed->SendScintilla(TpEditor::SCI_GETMULTIPLESELECTION));
        T_V_A->setChecked(ed->SendScintilla(TpEditor::SCI_GETADDITIONALSELECTIONTYPING));
        T_V_P->setChecked(ed->SendScintilla(TpEditor::SCI_GETMULTIPASTE));
        T_V_V_D->setChecked(ed->SendScintilla(TpEditor::SCI_GETVIRTUALSPACEOPTIONS) == 0);
        T_V_V_R->setChecked(ed->SendScintilla(TpEditor::SCI_GETVIRTUALSPACEOPTIONS) == 1);
        T_V_V_U->setChecked(ed->SendScintilla(TpEditor::SCI_GETVIRTUALSPACEOPTIONS) == 2);
        T_V_V_W->setChecked(ed->SendScintilla(TpEditor::SCI_GETVIRTUALSPACEOPTIONS) == 4);
        T_V_R_C->setChecked(ed->SendScintilla(TpEditor::SCI_GETRECTANGULARSELECTIONMODIFIER) == 2);
        T_V_R_A->setChecked(ed->SendScintilla(TpEditor::SCI_GETRECTANGULARSELECTIONMODIFIER) == 4);
        T_V_C_O->setChecked(ed->SendScintilla(TpEditor::SCI_GETCARETSTICKY) == 0);
        T_V_C_N->setChecked(ed->SendScintilla(TpEditor::SCI_GETCARETSTICKY) == 1);
        T_V_C_W->setChecked(ed->SendScintilla(TpEditor::SCI_SETCARETSTICKY) == 2);
        T_V_L->setChecked(ed->SendScintilla(TpEditor::SCI_GETCARETLINEVISIBLE));
#define FIC(c) (ed->m_findContainer->m_check##c##Regex->isChecked())
        T_S_R_N->setChecked(!(FIC(Simple) && FIC(Posix) && FIC(Cpp)));
        T_S_R_S->setChecked(FIC(Simple));
        T_S_R_P->setChecked(FIC(Posix));
        T_S_R_pl->setChecked(FIC(Cpp));
#undef FIC
        T_S_C->setChecked(ed->m_findContainer->m_checkCase->isChecked());
        T_S_O->setChecked(ed->m_findContainer->m_checkWord->isChecked());
        T_S_W->setChecked(ed->m_findContainer->m_checkWrap->isChecked());
        T_S_S->setChecked(ed->m_findContainer->m_checkShow->isChecked());
        T_S_G->setChecked(ed->m_findContainer->m_checkPrevious->isChecked());
        T_W_I_P->setChecked(ed->wrapIndentMode() == TpEditor::WrapIndentMode::WrapIndentFixed);
        T_W_I_S->setChecked(ed->wrapIndentMode() == TpEditor::WrapIndentMode::WrapIndentSame);
        T_W_I_I->setChecked(ed->wrapIndentMode() == TpEditor::WrapIndentMode::WrapIndentIndented);
        T_W_I_D->setChecked(ed->wrapIndentMode() == TpEditor::WrapIndentMode::WrapIndentDeeplyIndented);
        T_W_S_N->setChecked(ed->startFlag() == TpEditor::WrapVisualFlag::WrapFlagNone);
        T_W_S_T->setChecked(ed->startFlag() == TpEditor::WrapVisualFlag::WrapFlagByText);
        T_W_S_B->setChecked(ed->startFlag() == TpEditor::WrapVisualFlag::WrapFlagByBorder);
        T_W_S_M->setChecked(ed->startFlag() == TpEditor::WrapVisualFlag::WrapFlagInMargin);
        T_W_E_N->setChecked(ed->endFlag() == TpEditor::WrapVisualFlag::WrapFlagNone);
        T_W_E_T->setChecked(ed->endFlag() == TpEditor::WrapVisualFlag::WrapFlagByText);
        T_W_E_B->setChecked(ed->endFlag() == TpEditor::WrapVisualFlag::WrapFlagByBorder);
        T_W_E_M->setChecked(ed->endFlag() == TpEditor::WrapVisualFlag::WrapFlagInMargin);
        T_M_B->setChecked(ed->SendScintilla(TpEditor::SCI_GETBUFFEREDDRAW));
        T_M_P_O->setChecked(ed->SendScintilla(TpEditor::SCI_GETPHASESDRAW) == 0);
        T_M_P_T->setChecked(ed->SendScintilla(TpEditor::SCI_GETPHASESDRAW) == 1);
        T_M_P_M->setChecked(ed->SendScintilla(TpEditor::SCI_GETPHASESDRAW) == 2);
        T_M_Q_D->setChecked(ed->SendScintilla(TpEditor::SCI_GETFONTQUALITY) == 0);
        T_M_Q_N->setChecked(ed->SendScintilla(TpEditor::SCI_GETFONTQUALITY) == 1);
        T_M_Q_A->setChecked(ed->SendScintilla(TpEditor::SCI_GETFONTQUALITY) == 2);
        T_M_Q_L->setChecked(ed->SendScintilla(TpEditor::SCI_GETFONTQUALITY) == 3);
    }
}

void TpMenuBar::createOpenRecentActions()
{
    TpGeneralAction *recentFileAction;

    for (int i = 0; i < maximumRecentFiles; i++)
    {
        recentFileAction = new TpGeneralAction(F_R, tr(""), QKeySequence(), true);
        recentFileAction->setVisible(false);
        m_recentFileActions.append(recentFileAction);
    }
}

TP_END_NAMESPACE
