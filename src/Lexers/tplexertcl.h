#ifndef TPLEXERTCL_H
#define TPLEXERTCL_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerTCLKeyword1 =
"after append array auto_execok auto_import auto_load auto_load_index auto_qualify beep bgerror binary break case "
"catch cd clock close concat continue dde default echo else elseif encoding eof error eval exec exit expr fblocked "
"fconfigure fcopy file fileevent flush for foreach format gets glob global history http if incr info interp join "
"lappend lindex linsert list llength load loadTk lrange lreplace lsearch lset lsort memory msgcat namespace open "
"package pid pkg::create pkg_mkIndex Platform-specific proc puts pwd re_syntax read regexp registry regsub rename "
"resource return scan seek set socket source split string subst switch tclLog tclMacPkgSearch tclPkgSetup "
"tclPkgUnknown tell time trace unknown unset update uplevel upvar variable vwait while";

inline const char *lexerTCLKeyword2 =
"bell bind bindtags bitmap button canvas checkbutton clipboard colors console cursors destroy entry event focus font "
"frame grab grid image Inter-client keysyms label labelframe listbox lower menu menubutton message option options pack "
"panedwindow photo place radiobutton raise scale scrollbar selection send spinbox text tk tk_chooseColor "
"tk_chooseDirectory tk_dialog tk_focusNext tk_getOpenFile tk_messageBox tk_optionMenu tk_popup tk_setPalette tkerror "
"tkvars tkwait toplevel winfo wish wm";

inline const char *lexerTCLKeyword3 =
"@scope body class code common component configbody constructor define destructor hull import inherit itcl itk "
"itk_component itk_initialize itk_interior itk_option iwidgets keep method private protected public";

inline const char *lexerTCLKeyword4 =
"tk_bisque tk_chooseColor tk_dialog tk_focusFollowsMouse tk_focusNext tk_focusPrev tk_getOpenFile tk_getSaveFile "
"tk_messageBox tk_optionMenu tk_popup tk_setPalette tk_textCopy tk_textCut tk_textPaste tkButtonAutoInvoke "
"tkButtonDown tkButtonEnter tkButtonInvoke tkButtonLeave tkButtonUp tkCancelRepeat tkCheckRadioDown tkCheckRadioEnter "
"tkCheckRadioInvoke tkColorDialog tkColorDialog_BuildDialog tkColorDialog_CancelCmd tkColorDialog_Config "
"tkColorDialog_CreateSelector tkColorDialog_DrawColorScale tkColorDialog_EnterColorBar tkColorDialog_HandleRGB Entry "
"tkColorDialog_HandleSelEntry tkColorDialog_InitValues tkColorDialog_LeaveColorBar tkColorDialog_MoveSelector "
"tkColorDialog_OkCmd tkColorDialog_RedrawColorBars tkColorDialog_RedrawFinalColor tkColorDialog_ReleaseMouse "
"tkColorDialog_ResizeColorBars tkColorDialog_RgbToX tkColorDialog_SetRGBValue tkColorDialog_StartMove "
"tkColorDialog_XToRgb tkConsoleAbout tkConsoleBind tkConsoleExit tkConsoleHistory tkConsoleInit tkConsoleInsert "
"tkConsoleInvoke tkConsoleOutput tkConsolePrompt tkConsoleSource tkDarken tkEntryAutoScan tkEntryBackspace "
"tkEntryButton1 tkEntryClosestGap tkEntryGetSelection tkEntryInsert tkEntryKeySelect tkEntryMouseSelect "
"tkEntryNextWord tkEntryPaste tkEntryPreviousWord tkEntrySeeInsert tkEntrySetCursor tkEntryTranspose "
"tkEventMotifBindings tkFDGetFileTypes tkFirstMenu tkFocusGroup_BindIn tkFocusGroup_BindOut tkFocusGroup_Create "
"tkFocusGroup_Destroy tkFocusGroup_In tkFocusGroup_Out tkFocusOK tkGenerateMenuSelect tkIconList tkIconList_Add "
"tkIconList_Arrange tkIconList_AutoScan tkIconList_Btn1 tkIconList_Config tkIconList_Create tkIconList_CtrlBtn1 "
"tkIconList_Curselection tkIconList_DeleteAll tkIconList_Double1 tkIconList_DrawSelection tkIconList_FocusIn "
"tkIconList_FocusOut tkIconList_Get tkIconList_Goto tkIconList_Index tkIconList_Invoke tkIconList_KeyPress "
"tkIconList_Leave1 tkIconList_LeftRight tkIconList_Motion1 tkIconList_Reset tkIconList_ReturnKey tkIconList_See "
"tkIconList_Select tkIconList_Selection tkIconList_ShiftBtn1 tkIconList_UpDown tkListbox tkListboxAutoScan "
"tkListboxBeginExtend tkListboxBeginSelect tkListboxBeginToggle tkListboxCancel tkListboxDataExtend "
"tkListboxExtendUpDown tkListboxKeyAccel_Goto tkListboxKeyAccel_Key tkListboxKeyAccel_Reset tkListboxKeyAccel_Set "
"tkListboxKeyAccel_Unset tkListboxMotion tkListboxSelectAll tkListboxUpDown tkMbButtonUp tkMbEnter tkMbLeave "
"tkMbMotion tkMbPost tkMenuButtonDown tkMenuDownArrow tkMenuDup tkMenuEscape tkMenuFind tkMenuFindName "
"tkMenuFirstEntry tkMenuInvoke tkMenuLeave tkMenuLeftArrow tkMenuMotion tkMenuNextEntry tkMenuNextMenu "
"tkMenuRightArrow tkMenuUnpost tkMenuUpArrow tkMessageBox tkMotifFDialog tkMotifFDialog_ActivateDList "
"tkMotifFDialog_ActivateFEnt tkMotifFDialog_ActivateFList tkMotifFDialog_ActivateSEnt tkMotifFDialog_BrowseDList "
"tkMotifFDialog_BrowseFList tkMotifFDialog_BuildUI tkMotifFDialog_CancelCmd tkMotifFDialog_Config "
"tkMotifFDialog_Create tkMotifFDialog_FileTypes tkMotifFDialog_FilterCmd tkMotifFDialog_InterpFilter "
"tkMotifFDialog_LoadFiles tkMotifFDialog_MakeSList tkMotifFDialog_OkCmd tkMotifFDialog_SetFilter "
"tkMotifFDialog_SetListMode tkMotifFDialog_Update tkPostOverPoint tkRecolorTree tkRestoreOldGrab tkSaveGrabInfo "
"tkScaleActivate tkScaleButton2Down tkScaleButtonDown tkScaleControlPress tkScaleDrag tkScaleEndDrag tkScaleIncrement "
"tkScreenChanged tkScrollButton2Down tkScrollButtonDown tkScrollButtonDrag tkScrollButtonUp tkScrollByPages "
"tkScrollByUnits tkScrollDrag tkScrollEndDrag tkScrollSelect tkScrollStartDrag tkScrollTopBottom tkScrollToPos "
"tkTabToWindow tkTearOffMenu tkTextAutoScan tkTextButton1 tkTextClosestGap tkTextInsert tkTextKeyExtend "
"tkTextKeySelect tkTextNextPara tkTextNextPos tkTextNextWord tkTextPaste tkTextPrevPara tkTextPrevPos tkTextPrevWord "
"tkTextResetAnchor tkTextScrollPages tkTextSelectTo tkTextSetCursor tkTextTranspose tkTextUpDownLine tkTraverseToMenu "
"tkTraverseWithinMenu";

inline const char *lexerTCLKeyword5 =
"expand";

class TpLexerTCL : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        CommentLine = 2,
        Number = 3,
        QuotedKeyword = 4,
        QuotedString = 5,
        Operator = 6,
        Identifier = 7,
        Substitution = 8,
        SubstitutionBrace = 9,
        Modifier = 10,
        ExpandKeyword = 11,
        TCLKeyword = 12,
        TkKeyword = 13,
        ITCLKeyword = 14,
        TkCommand = 15,
        KeywordSet6 = 16,
        KeywordSet7 = 17,
        KeywordSet8 = 18,
        KeywordSet9 = 19,
        CommentBox = 20,
        CommentBlock = 21,
    };

    enum
    {
        PropFoldComments,
    };

public:
    TpLexerTCL(QObject *parent = nullptr);
    virtual ~TpLexerTCL();

public:
    const char *language() const override;
    const char *lexer() const override;
    int braceStyle() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
    QString description(int style) const override;

    void refreshProperties() override;

    void setLexerProperty(int prop, QVariant value) override;
    QVariant lexerProperty(int prop) const override;

protected:
    bool readProperties(QSettings &settings, const QString &prefix) override;
    bool writeProperties(QSettings &settings, const QString &prefix) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERTCL_H
