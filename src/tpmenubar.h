#ifndef TPMENUBAR_H
#define TPMENUBAR_H

#include <QMenuBar>

#include <TpGeneralAction>
#include <TpGeneralActionGroup>
#include <TpGeneralMenu>

TP_NAMESPACE

class TpTabWidget;

class TpMenuBar : public QMenuBar
{
    Q_OBJECT

    friend class TpDocumentView;
    friend class TpFindContainer;
    friend class TpFindToolBar;
    friend class TpMainWindow;
    friend class TpTabWidget;

public:
    TpMenuBar(QWidget *parent);

public:
    void updateGeneralAccessibility(bool hasEditor, bool f);
    void updateToSettings();
    void updateCheckability(TpTabWidget *tab);

private:
    void createOpenRecentActions();

private:
    // [[Menu]] &File:
    //     [[Menu]] &New File
    //         [[Action]] New File on Next &Tab
    //         [[Action]] New File on New &Window
    //     [[Menu]] &Open File
    //         [[Action]] Open File on Next &Tab
    //         [[Action]] Open File on New &Window
    //     [[Menu]] Open &Recent
    //         [[Action]] ...
    //         [[Separator]]
    //         [[Action]] &Clear Recent Files List
    //         [[Action]] &Open All Recent Files
    //         [[Action]] Open The &Latest Entry
    //     [[Separator]]
    //     [[Menu]] Open &The Containing Folder
    //         [[Action]] &File Explorer
    //         [[Action]] &Command Line Interface
    //         [[Separator]]
    //         [[Action]] &Tropic File Browser
    //     [[Action]] R&eload from Disk...
    //     [[Action]] Reveal in &Default Viewer...
    //     [[Action]] Open Tropic File Bro&wser...
    //     [[Menu]] File &Browser Operations
    //         [[Action]] &Rename...
    //         [[Action]] &Delete...
    //         [[Separator]]
    //         [[Action]] Copy &File Name
    //         [[Action]] Copy &Absolute Path
    //         [[Action]] Copy Directory &Name
    //     [[Separator]]
    //     [[Action]] &Save...
    //     [[Action]] Save &As...
    //     [[Action]] Save A Cop&y To...
    //     [[Action]] Save All&...
    //     [[Separator]]
    //     [[Action]] &Close...
    //     [[Action]] Close A&ll...
    //     [[Action]] Close All &(This Tab Only)...
    //     [[Menu]] Close &Multiple Documents
    //         [[Action]] Close All &But This...
    //         [[Action]] Close All To The &Left...
    //         [[Action]] Close All To The &Right...
    //         [[Action]] Close All &Unchanged
    //     [[Separator]]
    //#    &Print...
    //#    Print Pre&view...
    //     [[Separator]]
    //     [[Action]] &Quit
    // [[Menu]] &Edit:
    //     [[Action]] &Undo
    //     [[Action]] &Redo
    //     [[Separator]]
    //     [[Action]] &Cut
    //     [[Action]] C&opy
    //     [[Action]] &Paste
    //     [[Separator]]
    //     [[Menu]] &Deletion Operations
    //         [[Action]] &Delete
    //         [[Action]] &Backspace
    //         [[Action]] Backspace &If Not Start of Line
    //         [[Action]] Delete Word &Left
    //         [[Action]] Delete Word &Right
    //         [[Action]] Delete Word Right &End
    //         [[Action]] Delete Li&ne Left
    //         [[Action]] Delete Line Ri&ght
    //     [[Menu]] &Move Operations
    //         [[Action]] &A. Line Down
    //         [[Action]] &B. Line Up
    //         [[Action]] &C. Line End
    //         [[Action]] &D. Line End Display
    //         [[Action]] &E. Line End Wrap
    //         [[Action]] &F. Paragraph Down
    //         [[Action]] &G. Paragraph Up
    //         [[Action]] &H. Character Left
    //         [[Action]] &I. Character Right
    //         [[Action]] &J. Word Left
    //         [[Action]] &K. Word Right
    //         [[Action]] &L. Word Left End
    //         [[Action]] &M. Word Right End
    //         [[Action]] &N. Word Part Left
    //         [[Action]] &O. Word Part Right
    //         [[Action]] &P. Home
    //         [[Action]] &Q. Home Display
    //         [[Action]] &R. Home Wrap
    //         [[Action]] &S. Visible Character Home
    //         [[Action]] &T. Visible Character Home Wrap
    //         [[Action]] &U. Document Start
    //         [[Action]] &V. Document End
    //         [[Action]] &W. Page Up
    //         [[Action]] &X. Page Down
    //         [[Action]] &Y. Stuttered Page Up
    //         [[Action]] &Z. Stuttered Page Down
    //     [[Menu]] &Selection Operations
    //         [[Action]] &A. Select All
    //         [[Separator]]
    //         [[Action]] &B. Line Down
    //         [[Action]] &C. Line Down Rectangular
    //         [[Action]] &D. Line Up
    //         [[Action]] &E. Line Up Rectangular
    //         [[Action]] &F. Line End
    //         [[Action]] &G. Line End Rectangular
    //         [[Action]] &H. Line End Display
    //         [[Action]] &I. Line End Wrap
    //         [[Action]] &J. Paragraph Down
    //         [[Action]] &K. Paragraph Up
    //         [[Action]] &L. Character Left
    //         [[Action]] &M. Character Left Rectangular
    //         [[Action]] &N. Character Right
    //         [[Action]] &O. Character Right Rectangular
    //         [[Action]] &P. Word Left
    //         [[Action]] &Q. Word Right
    //         [[Action]] &R. Word Left End
    //         [[Action]] &S. Word Right End
    //         [[Action]] &T. Word Part Left
    //         [[Action]] &U. Word Part Right
    //         [[Action]] &V. Home
    //         [[Action]] &W. Home Rectangular
    //         [[Action]] &X. Home Display
    //         [[Action]] &Y. Home Wrap
    //         [[Action]] &Z. Visible Character Home
    //         [[Action]] &0. Visible Character Home Rectangular
    //         [[Action]] &1. Visible Character Home Wrap
    //         [[Action]] &2. Document Start
    //         [[Action]] &3. Document End
    //         [[Action]] &4. Page Up
    //         [[Action]] &5. Page Up Rectangular
    //         [[Action]] &6. Page Down
    //         [[Action]] &7. Page Down Rectangular
    //         [[Action]] &8. Stuttered Page Up
    //         [[Action]] &9. Stuttered Page Down
    //     [[Menu]] &Indentation Operations
    //         [[Action]] &Increase Indentation
    //         [[Action]] &Decrease Indentation
    //     [[Menu]] &Line Operations
    //         [[Action]] &Delete
    //         [[Action]] &Cut
    //         [[Action]] C&opy
    //         [[Action]] &Transpose
    //         [[Separator]]
    //         [[Action]] Move &Up
    //         [[Action]] Move Do&wn
    //     [[Menu]] Duplic&ation Operations
    //         [[Action]] &Line
    //         [[Action]] &Selection
    //     [[Separator]]
    //     [[Action]] To&ggle Overtype
    //     [[Separator]]
    //     [[Menu]] S&earch
    //         [[Action]] &Find...
    //         [[Action]] Find &In Files...
    //         [[Action]] Find &Next...
    //         [[Action]] Find &Previous...
    //         [[Action]] Find Ne&xt Using Selection...
    //         [[Action]] Find Previous &Using Selection...
    //         [[Action]] &Light Search...
    //         [[Action]] &Go To...
    //         [[Action]] Go To &Matching Brace
    //         [[Action]] &Select To Matching Brace
    //     [[Menu]] &Bookmarks
    //         [[Action]] &Toggle
    //         [[Action]] &Next
    //         [[Action]] &Previous
    //         [[Action]] &Cut All Bookmarked Lines
    //         [[Action]] C&opy All Bookmarked Lines
    //         [[Action]] &Remove All Bookmarks
    //         [[Action]] Remove &All Bookmarked Lines
    //         [[Action]] Remove All Non&-bookmarked Lines
    //         [[Action]] &Inverse
    // [[Menu]] &View:
    //     [[Action]] &Always-on-top Mode
    //     [[Action]] &Full Screen Mode
    //     [[Action]] Post&-it Mode
    //     [[Separator]]
    //     [[Menu]] Show S&ymbols
    //         [[Action]] &Spaces and Tabs (All)
    //         [[Action]] Spaces &and Tabs (After Indentation)
    //         [[Action]] Spaces and &Tabs (In Indentation)
    //         [[Action]] &Non-printable
    //         [[Separator]]
    //         [[Action]] &Wrap Visual Flags
    //         [[Action]] &Indentation Guides
    //     [[Menu]] &Zoom
    //         [[Action]] Zoom &In
    //         [[Action]] Zoom &Out
    //         [[Separator]]
    //         [[Action]] &To 100%
    //     [[Menu]] &Tab
    //         [[Action]] To Tab &1
    //         [[Action]] To Tab &2
    //         [[Action]] To Tab &3
    //         [[Action]] To Tab &4
    //         [[Action]] To Tab &5
    //         [[Action]] To Tab &6
    //         [[Action]] To Tab &7
    //         [[Action]] To Tab &8
    //         [[Action]] To Tab &9
    //         [[Action]] To Tab 1&0
    //         [[Separator]]
    //         [[Action]] To The &Last
    //         [[Action]] To The &Next
    //         [[Action]] To The &First
    //         [[Action]] To The &Previous
    //         [[Separator]]
    //         [[Action]] &Move To Left
    //         [[Action]] Move To &Right
    //         [[Action]] Move To The &Start
    //         [[Action]] Move To &The Last
    //     [[Menu]] &Word Wrap
    //         [[Action]] &None
    //         [[Action]] &Word
    //         [[Action]] &Character
    //         [[Action]] W&hitespace
    //     [[Menu]] Sp&lit Views
    //         [[Action]] &Move To Next View
    //#        [[Action]] Move &To Previous View
    //#        [[Separator]]
    //#        [[Action]] &Clone To Next View
    //     [[Action]] Show L&ine Numbers
    //     [[Separator]]
    //     [[Menu]] S&crolling Operations
    //         [[Action]] Line &Down
    //         [[Action]] Line &Up
    //         [[Action]] To &Start
    //         [[Action]] To &End
    //         [[Action]] To &Vertical Center Caret
    //     [[Menu]] Folding &Operations
    //         [[Action]] Fold &Here
    //         [[Action]] Fold &All
    //         [[Action]] Fold All (Including &Children)
    //         [[Action]] &Expand All
    //         [[Separator]]
    //         [[Menu]] &Style
    //             [[Action]] &Disable Folding
    //             [[Action]] &Plain
    //             [[Action]] &Circled
    //             [[Action]] &Boxed
    //             [[Action]] Circled &Tree
    //             [[Action]] Bo&xed Tree
    // [[Menu]] &Insert:
    //     [[Action]] &Formfeed
    //     [[Action]] &Tab
    //     [[Action]] &Vertical Tab
    //     [[Separator]]
    //     [[Menu]] &Newlines
    //         [[Action]] &Windows
    //         [[Action]] Classical &Mac
    //         [[Action]] &Unix
    //     [[Menu]] &Date and Time
    //         [[Action]] &Date
    //         [[Action]] &Time
    //         [[Action]] Date &and Time
    //     [[Separator]]
    //     [[Action]] &Other Special Characters...
    // [[Menu]] F&ormat:
    //     [[Menu]] &Languages
    //         [[Action]] None &(Nothing Applied)
    //         [[Separator]]
    //         [[Menu]] &A
    //             [[Action]] A&ctionScript
    //             [[Action]] A&SP
    //             [[Action]] &AviSynth
    //         [[Menu]] &B
    //             [[Action]] &Bash
    //             [[Action]] Ba&tch
    //             [[Action]] BA&SIC (BlitzBasic)
    //             [[Action]] B&ASIC (PureBasic)
    //             [[Action]] BASIC (&FreeBasic)
    //         [[Menu]] &C
    //             [[Action]] &C
    //             [[Action]] C&++
    //             [[Action]] C++ &(Qt)
    //             [[Action]] C&#
    //             [[Action]] C&Make
    //             [[Action]] C&offeeScript
    //             [[Action]] C&SS
    //         [[Menu]] &D
    //             [[Action]] &D
    //             [[Action]] D&iff
    //         [[Menu]] &F
    //             [[Action]] &Fortran
    //             [[Action]] Fortran &77
    //         [[Menu]] &G
    //             [[Action]] &GDScript
    //         [[Menu]] &H
    //             [[Action]] &HTML
    //             [[Action]] H&TML (Full)
    //         [[Menu]] &I
    //             [[Action]] &IDL
    //             [[Action]] Intel &Hex
    //         [[Menu]] &J
    //             [[Action]] &Java
    //             [[Action]] Java&Script
    //             [[Action]] JS&ON
    //         [[Menu]] &L
    //             [[Action]] La&TeX
    //             [[Action]] &Lua
    //         [[Menu]] &M
    //             [[Action]] Make&file
    //             [[Action]] Mark&down
    //             [[Action]] &MASM
    //             [[Action]] Mat&lab
    //         [[Menu]] &N
    //             [[Action]] &NASM
    //         [[Menu]] &O
    //             [[Action]] &Octave
    //         [[Menu]] &P
    //             [[Action]] &Pascal
    //             [[Action]] P&erl
    //             [[Action]] P&HP
    //             [[Action]] P&O
    //             [[Action]] Post&Script
    //             [[Action]] PO&V
    //             [[Action]] P&roperties
    //             [[Action]] Python &2
    //             [[Action]] Python &3
    //             [[Action]] Python 3 (E&xtended)
    //         [[Menu]] &Q
    //             [[Action]] &QML
    //             [[Action]] Q&SS
    //             [[Action]] Q&UI
    //         [[Menu]] &R
    //             [[Action]] &Ruby
    //         [[Menu]] &S
    //             [[Action]] &Spice
    //             [[Action]] S&QL
    //             [[Action]] S-&Record
    //         [[Menu]] &T
    //             [[Action]] &TCL
    //             [[Action]] Tektronix &Hex
    //             [[Action]] Te&X
    //         [[Menu]] &V
    //             [[Action]] &Verilog
    //             [[Action]] V&HDL
    //         [[Menu]] &X
    //             [[Action]] &XML
    //         [[Menu]] &Y
    //             [[Action]] &YAML
    //     [[Menu]] &Newline Conversion
    //         [[Action]] &Use Windows
    //         [[Action]] Use &Classical Mac
    //         [[Action]] Us&e Unix
    //         [[Separator]]
    //         [[Action]] Convert &To Windows
    //         [[Action]] Convert To Classical &Mac
    //         [[Action]] Convert To Uni&x
    //     [[Separator]]
    //     [[Menu]] &Indentation Configuration
    //         [[Action]] Use &Tabs To Indent
    //         [[Action]] &Backspace Unindents
    //         [[Action]] Tab To &Indent
    //     [[Menu]] &Representing Tabs
    //         [[Action]] &Long Arrow
    //         [[Action]] &Strike Out
    //     [[Action]] &Select First Wrapped Line Only
    //     [[Action]] Read&-only
    //     [[Separator]]
    //     [[Menu]] C&ase Conversion
    //         [[Action]] &UPPERCASE
    //         [[Action]] &lowercase
    // [[Menu]] &Tools:
    //#    [[Action]] &Preferences...
    //     [[Separator]]
    //     [[Menu]] &Autocompletion
    //         [[Action]] &Case Sensitive
    //         [[Action]] &Fill-ups Enabled
    //         [[Action]] &Replace Word
    //         [[Menu]] &When Single Entry
    //             [[Action]] Do &Not Display
    //             [[Action]] &Only Manually
    //             [[Action]] Always &Display
    //         [[Separator]]
    //         [[Menu]] &Sources
    //             [[Action]] &Do Not Display Autocompletion
    //             [[Action]] &All
    //             [[Action]] D&ocument
    //             [[Action]] &Lexer
    //         [[Menu]] &Trigger Now
    //             [[Action]] From &All Sources
    //             [[Action]] From &Document
    //             [[Action]] From &Lexer
    //     [[Menu]] Auto&-indentation
    //         [[Action]] &Auto-indentation
    //         [[Separator]]
    //         [[Menu]] &Style
    //             [[Action]] &Auto
    //             [[Separator}]
    //             [[Action]] &Maintain
    //             [[Action]] &Opening
    //             [[Action]] &Closing
    //     [[Menu]] &Brace Matching
    //         [[Action]] &No Brace Matching
    //         [[Action]] &Sloppy Brace Match
    //         [[Action]] Strict &Brace Match
    //     [[Menu]] &Call Tips
    //         [[Action]] &Trigger Immediately
    //         [[Separator]]
    //         [[Menu]] &Position
    //             [[Action]] &Below Text
    //             [[Action]] &Above Text
    //         [[Menu]] &Style
    //             [[Action]] &Disable Call Tips
    //             [[Action]] &No Context or Scope
    //             [[Action]] No &Autocompletion Context
    //             [[Action]] &With All Context
    //     [[Menu]] &Edge Mode
    //         [[Action]] &None
    //         [[Action]] &Line
    //         [[Action]] &Background
    //     [[Menu]] Caret and &Virtual Selection
    //         [[Action]] &Selection Till Border
    //         [[Action]] &Multiplie Selection
    //         [[Action]] &Additional Selection Typing
    //         [[Action]] Multiple &Paste
    //         [[Separator]]
    //         [[Menu]] &Virtual Space
    //             [[Action]] &Disabled
    //             [[Action]] On &Rectangular Selections
    //             [[Action]] &Users Accessible
    //             [[Action]] No &Wrap Line Start
    //         [[Menu]] &Rectangular Selection Modifier
    //             [[Action]] &Control Key (CTRL)
    //             [[Action]] &Alternate Key (ALT)
    //         [[Separator]]
    //         [[Menu]] &Caret Sticky
    //             [[Action]] &Off
    //             [[Action]] O&n
    //             [[Action]] &With Whitespaces Only
    //         [[Action]] Caret &Line Visible
    //     [[Menu]] &Search Tools
    //         [[Menu]] &Regular Expression
    //             [[Action]] &No
    //             [[Action]] &Simple
    //             [[Action]] &POSIX
    //             [[Action]] C&++
    //         [[Action]] &Case-sensitive
    //         [[Action]] Whole Word &Only
    //         [[Action]] &Word Wrap
    //         [[Action]] &Show
    //         [[Action]] &Go Previous
    //     [[Menu]] &Wrapping Tools
    //         [[Menu]] &Indentation
    //             [[Action]] &Predefined
    //             [[Action]] &Same as First Sub-line
    //             [[Action]] &Indented
    //             [[Action]] &Double-indented
    //         [[Separator]]
    //         [[Menu]] &Start Flag
    //             [[Action]] &None
    //             [[Action]] By &Text
    //             [[Action]] By &Border
    //             [[Action]] In &Margin
    //         [[Menu]] &End Flag
    //             [[Action]] &None
    //             [[Action]] By &Text
    //             [[Action]] By &Border
    //             [[Action]] In &Margin
    //     [[Separator]]
    //     [[Menu]] &Miscellaneous
    //         [[Action]] &Buffered Draw
    //         [[Menu]] &Phases Draw
    //             [[Action]] Phase &One
    //             [[Action]] Phase &Two
    //             [[Action]] Phase &Multiple
    //         [[Separator]]
    //         [[Action]] Font &Quality
    //             [[Action]] &Default
    //             [[Action]] &Non-antialized
    //             [[Action]] &Antialized
    //             [[Action]] &LCD Optimized
    // [[Menu]] &Windows:
    //     [[Action]] &File Browser
    //     [[Action]] Document &List
    //     [[Action]] &Bookmarks
    //     [[Action]] Find &Dock
    //     [[Action]] Find &In Files Dock
    //#    [[Action]] &QSS Viewer

    TpGeneralMenu *F;
    TpGeneralMenu *F_N;
    TpGeneralAction *F_N_T;
    TpGeneralAction *F_N_W;
    TpGeneralMenu *F_O;
    TpGeneralAction *F_O_T;
    TpGeneralAction *F_O_W;
    TpGeneralMenu *F_R;
    TpGeneralAction *F_R_C;
    TpGeneralAction *F_R_O;
    TpGeneralAction *F_R_L;
    TpGeneralMenu *F_T;
    TpGeneralAction *F_T_F;
    TpGeneralAction *F_T_C;
    TpGeneralAction *F_T_T;
    TpGeneralAction *F_E;
    TpGeneralAction *F_D;
    TpGeneralAction *F_W;
    TpGeneralMenu *F_B;
    TpGeneralAction *F_B_R;
    TpGeneralAction *F_B_D;
    TpGeneralAction *F_B_F;
    TpGeneralAction *F_B_A;
    TpGeneralAction *F_B_N;
    TpGeneralAction *F_S;
    TpGeneralAction *F_A;
    TpGeneralAction *F_Y;
    TpGeneralAction *F_d;
    TpGeneralAction *F_C;
    TpGeneralAction *F_L;
    TpGeneralAction *F_p;
    TpGeneralMenu *F_M;
    TpGeneralAction *F_M_B;
    TpGeneralAction *F_M_L;
    TpGeneralAction *F_M_R;
    TpGeneralAction *F_M_U;
    // TpGeneralAction *F_P;
    // TpGeneralAction *F_V;
    TpGeneralAction *F_Q;
    TpGeneralMenu *E;
    TpGeneralAction *E_U;
    TpGeneralAction *E_R;
    TpGeneralAction *E_C;
    TpGeneralAction *E_O;
    TpGeneralAction *E_P;
    TpGeneralMenu *E_D;
    TpGeneralAction *E_D_D;
    TpGeneralAction *E_D_B;
    TpGeneralAction *E_D_I;
    TpGeneralAction *E_D_L;
    TpGeneralAction *E_D_R;
    TpGeneralAction *E_D_E;
    TpGeneralAction *E_D_N;
    TpGeneralAction *E_D_G;
    TpGeneralMenu *E_M;
    TpGeneralAction *E_M_A;
    TpGeneralAction *E_M_B;
    TpGeneralAction *E_M_C;
    TpGeneralAction *E_M_D;
    TpGeneralAction *E_M_E;
    TpGeneralAction *E_M_F;
    TpGeneralAction *E_M_G;
    TpGeneralAction *E_M_H;
    TpGeneralAction *E_M_I;
    TpGeneralAction *E_M_J;
    TpGeneralAction *E_M_K;
    TpGeneralAction *E_M_L;
    TpGeneralAction *E_M_M;
    TpGeneralAction *E_M_N;
    TpGeneralAction *E_M_O;
    TpGeneralAction *E_M_P;
    TpGeneralAction *E_M_Q;
    TpGeneralAction *E_M_R;
    TpGeneralAction *E_M_S;
    TpGeneralAction *E_M_T;
    TpGeneralAction *E_M_U;
    TpGeneralAction *E_M_V;
    TpGeneralAction *E_M_W;
    TpGeneralAction *E_M_X;
    TpGeneralAction *E_M_Y;
    TpGeneralAction *E_M_Z;
    TpGeneralMenu *E_S;
    TpGeneralAction *E_S_A;
    TpGeneralAction *E_S_B;
    TpGeneralAction *E_S_C;
    TpGeneralAction *E_S_D;
    TpGeneralAction *E_S_E;
    TpGeneralAction *E_S_F;
    TpGeneralAction *E_S_G;
    TpGeneralAction *E_S_H;
    TpGeneralAction *E_S_I;
    TpGeneralAction *E_S_J;
    TpGeneralAction *E_S_K;
    TpGeneralAction *E_S_L;
    TpGeneralAction *E_S_M;
    TpGeneralAction *E_S_N;
    TpGeneralAction *E_S_O;
    TpGeneralAction *E_S_P;
    TpGeneralAction *E_S_Q;
    TpGeneralAction *E_S_R;
    TpGeneralAction *E_S_S;
    TpGeneralAction *E_S_T;
    TpGeneralAction *E_S_U;
    TpGeneralAction *E_S_V;
    TpGeneralAction *E_S_W;
    TpGeneralAction *E_S_X;
    TpGeneralAction *E_S_Y;
    TpGeneralAction *E_S_Z;
    TpGeneralAction *E_S_0;
    TpGeneralAction *E_S_1;
    TpGeneralAction *E_S_2;
    TpGeneralAction *E_S_3;
    TpGeneralAction *E_S_4;
    TpGeneralAction *E_S_5;
    TpGeneralAction *E_S_6;
    TpGeneralAction *E_S_7;
    TpGeneralAction *E_S_8;
    TpGeneralAction *E_S_9;
    TpGeneralMenu *E_I;
    TpGeneralAction *E_I_I;
    TpGeneralAction *E_I_D;
    TpGeneralMenu *E_L;
    TpGeneralAction *E_L_D;
    TpGeneralAction *E_L_C;
    TpGeneralAction *E_L_O;
    TpGeneralAction *E_L_T;
    TpGeneralAction *E_L_U;
    TpGeneralAction *E_L_W;
    TpGeneralMenu *E_A;
    TpGeneralAction *E_A_L;
    TpGeneralAction *E_A_S;
    TpGeneralAction *E_G;
    TpGeneralMenu *E_E;
    TpGeneralAction *E_E_F;
    TpGeneralAction *E_E_I;
    TpGeneralAction *E_E_N;
    TpGeneralAction *E_E_P;
    TpGeneralAction *E_E_X;
    TpGeneralAction *E_E_U;
    TpGeneralAction *E_E_L;
    TpGeneralAction *E_E_G;
    TpGeneralAction *E_E_M;
    TpGeneralAction *E_E_S;
    TpGeneralMenu *E_B;
    TpGeneralAction *E_B_T;
    TpGeneralAction *E_B_N;
    TpGeneralAction *E_B_P;
    TpGeneralAction *E_B_C;
    TpGeneralAction *E_B_O;
    TpGeneralAction *E_B_R;
    TpGeneralAction *E_B_A;
    TpGeneralAction *E_B_h;
    TpGeneralAction *E_B_I;
    TpGeneralMenu *V;
    TpGeneralAction *V_A;
    TpGeneralAction *V_F;
    TpGeneralAction *V_h;
    TpGeneralMenu *V_Y;
    TpGeneralAction *V_Y_S;
    TpGeneralAction *V_Y_A;
    TpGeneralAction *V_Y_T;
    TpGeneralAction *V_Y_N;
    TpGeneralAction *V_Y_W;
    TpGeneralAction *V_Y_I;
    TpGeneralMenu *V_Z;
    TpGeneralAction *V_Z_I;
    TpGeneralAction *V_Z_O;
    TpGeneralAction *V_Z_T;
    TpGeneralMenu *V_T;
    TpGeneralAction *V_T_1;
    TpGeneralAction *V_T_2;
    TpGeneralAction *V_T_3;
    TpGeneralAction *V_T_4;
    TpGeneralAction *V_T_5;
    TpGeneralAction *V_T_6;
    TpGeneralAction *V_T_7;
    TpGeneralAction *V_T_8;
    TpGeneralAction *V_T_9;
    TpGeneralAction *V_T_0;
    TpGeneralAction *V_T_L;
    TpGeneralAction *V_T_N;
    TpGeneralAction *V_T_F;
    TpGeneralAction *V_T_P;
    TpGeneralAction *V_T_M;
    TpGeneralAction *V_T_R;
    TpGeneralAction *V_T_S;
    TpGeneralAction *V_T_T;
    TpGeneralMenu *V_W;
    TpGeneralAction *V_W_N;
    TpGeneralAction *V_W_W;
    TpGeneralAction *V_W_C;
    TpGeneralAction *V_W_H;
    TpGeneralMenu *V_L;
    TpGeneralAction *V_L_M;
    // TpGeneralAction *V_L_T;
    // TpGeneralAction *V_L_C;
    TpGeneralAction *V_I;
    TpGeneralMenu *V_C;
    TpGeneralAction *V_C_D;
    TpGeneralAction *V_C_U;
    TpGeneralAction *V_C_S;
    TpGeneralAction *V_C_E;
    TpGeneralAction *V_C_V;
    TpGeneralMenu *V_O;
    TpGeneralAction *V_O_H;
    TpGeneralAction *V_O_A;
    TpGeneralAction *V_O_C;
    TpGeneralAction *V_O_E;
    TpGeneralMenu *V_O_S;
    TpGeneralAction *V_O_S_D;
    TpGeneralAction *V_O_S_P;
    TpGeneralAction *V_O_S_C;
    TpGeneralAction *V_O_S_B;
    TpGeneralAction *V_O_S_T;
    TpGeneralAction *V_O_S_X;
    TpGeneralMenu *I;
    TpGeneralAction *I_F;
    TpGeneralAction *I_T;
    TpGeneralAction *I_V;
    TpGeneralMenu *I_N;
    TpGeneralAction *I_N_W;
    TpGeneralAction *I_N_M;
    TpGeneralAction *I_N_U;
    TpGeneralMenu *I_D;
    TpGeneralAction *I_D_D;
    TpGeneralAction *I_D_T;
    TpGeneralAction *I_D_A;
    TpGeneralAction *I_O;
    TpGeneralMenu *O;
    TpGeneralMenu *O_L;
    TpGeneralAction *O_L_p;
    TpGeneralMenu *O_L_A;
    TpGeneralAction *O_L_A_C;
    TpGeneralAction *O_L_A_S;
    TpGeneralAction *O_L_A_A;
    TpGeneralMenu *O_L_B;
    TpGeneralAction *O_L_B_B;
    TpGeneralAction *O_L_B_T;
    TpGeneralAction *O_L_B_S;
    TpGeneralAction *O_L_B_A;
    TpGeneralAction *O_L_B_F;
    TpGeneralMenu *O_L_C;
    TpGeneralAction *O_L_C_C;
    TpGeneralAction *O_L_C_pl;
    TpGeneralAction *O_L_C_p;
    TpGeneralAction *O_L_C_s;
    TpGeneralAction *O_L_C_M;
    TpGeneralAction *O_L_C_O;
    TpGeneralAction *O_L_C_S;
    TpGeneralMenu *O_L_D;
    TpGeneralAction *O_L_D_D;
    TpGeneralAction *O_L_D_I;
    TpGeneralMenu *O_L_F;
    TpGeneralAction *O_L_F_F;
    TpGeneralAction *O_L_F_7;
    TpGeneralMenu *O_L_G;
    TpGeneralAction *O_L_G_G;
    TpGeneralMenu *O_L_H;
    TpGeneralAction *O_L_H_H;
    TpGeneralAction *O_L_H_T;
    TpGeneralMenu *O_L_I;
    TpGeneralAction *O_L_I_I;
    TpGeneralAction *O_L_I_H;
    TpGeneralMenu *O_L_J;
    TpGeneralAction *O_L_J_J;
    TpGeneralAction *O_L_J_S;
    TpGeneralAction *O_L_J_O;
    TpGeneralMenu *O_L_L;
    TpGeneralAction *O_L_L_T;
    TpGeneralAction *O_L_L_L;
    TpGeneralMenu *O_L_M;
    TpGeneralAction *O_L_M_F;
    TpGeneralAction *O_L_M_D;
    TpGeneralAction *O_L_M_M;
    TpGeneralAction *O_L_M_L;
    TpGeneralMenu *O_L_N;
    TpGeneralAction *O_L_N_N;
    TpGeneralMenu *O_L_O;
    TpGeneralAction *O_L_O_O;
    TpGeneralMenu *O_L_P;
    TpGeneralAction *O_L_P_P;
    TpGeneralAction *O_L_P_E;
    TpGeneralAction *O_L_P_H;
    TpGeneralAction *O_L_P_O;
    TpGeneralAction *O_L_P_S;
    TpGeneralAction *O_L_P_V;
    TpGeneralAction *O_L_P_R;
    TpGeneralAction *O_L_P_2;
    TpGeneralAction *O_L_P_3;
    TpGeneralAction *O_L_P_X;
    TpGeneralMenu *O_L_Q;
    TpGeneralAction *O_L_Q_Q;
    TpGeneralAction *O_L_Q_S;
    TpGeneralAction *O_L_Q_U;
    TpGeneralMenu *O_L_R;
    TpGeneralAction *O_L_R_R;
    TpGeneralMenu *O_L_S;
    TpGeneralAction *O_L_S_S;
    TpGeneralAction *O_L_S_Q;
    TpGeneralAction *O_L_S_R;
    TpGeneralMenu *O_L_T;
    TpGeneralAction *O_L_T_T;
    TpGeneralAction *O_L_T_H;
    TpGeneralAction *O_L_T_X;
    TpGeneralMenu *O_L_V;
    TpGeneralAction *O_L_V_V;
    TpGeneralAction *O_L_V_H;
    TpGeneralMenu *O_L_X;
    TpGeneralAction *O_L_X_X;
    TpGeneralMenu *O_L_Y;
    TpGeneralAction *O_L_Y_Y;
    TpGeneralMenu *O_N;
    TpGeneralAction *O_N_U;
    TpGeneralAction *O_N_C;
    TpGeneralAction *O_N_E;
    TpGeneralAction *O_N_T;
    TpGeneralAction *O_N_M;
    TpGeneralAction *O_N_X;
    TpGeneralMenu *O_I;
    TpGeneralAction *O_I_T;
    TpGeneralAction *O_I_B;
    TpGeneralAction *O_I_I;
    TpGeneralMenu *O_R;
    TpGeneralAction *O_R_L;
    TpGeneralAction *O_R_S;
    TpGeneralAction *O_S;
    TpGeneralAction *O_h;
    TpGeneralMenu *O_A;
    TpGeneralAction *O_A_U;
    TpGeneralAction *O_A_L;
    TpGeneralMenu *T;
    // TpGeneralAction *T_P;
    TpGeneralMenu *T_A;
    TpGeneralAction *T_A_C;
    TpGeneralAction *T_A_F;
    TpGeneralAction *T_A_R;
    TpGeneralMenu *T_A_W;
    TpGeneralAction *T_A_W_N;
    TpGeneralAction *T_A_W_O;
    TpGeneralAction *T_A_W_D;
    TpGeneralMenu *T_A_S;
    TpGeneralAction *T_A_S_D;
    TpGeneralAction *T_A_S_A;
    TpGeneralAction *T_A_S_O;
    TpGeneralAction *T_A_S_L;
    TpGeneralMenu *T_A_T;
    TpGeneralAction *T_A_T_A;
    TpGeneralAction *T_A_T_D;
    TpGeneralAction *T_A_T_L;
    TpGeneralMenu *T_h;
    TpGeneralAction *T_h_A;
    TpGeneralMenu *T_h_S;
    TpGeneralAction *T_h_S_A;
    TpGeneralAction *T_h_S_M;
    TpGeneralAction *T_h_S_O;
    TpGeneralAction *T_h_S_C;
    TpGeneralMenu *T_B;
    TpGeneralAction *T_B_N;
    TpGeneralAction *T_B_S;
    TpGeneralAction *T_B_B;
    TpGeneralMenu *T_C;
    TpGeneralAction *T_C_T;
    TpGeneralMenu *T_C_P;
    TpGeneralAction *T_C_P_B;
    TpGeneralAction *T_C_P_A;
    TpGeneralMenu *T_C_S;
    TpGeneralAction *T_C_S_D;
    TpGeneralAction *T_C_S_N;
    TpGeneralAction *T_C_S_A;
    TpGeneralAction *T_C_S_W;
    TpGeneralMenu *T_E;
    TpGeneralAction *T_E_N;
    TpGeneralAction *T_E_L;
    TpGeneralAction *T_E_B;
    TpGeneralMenu *T_V;
    TpGeneralAction *T_V_S;
    TpGeneralAction *T_V_M;
    TpGeneralAction *T_V_A;
    TpGeneralAction *T_V_P;
    TpGeneralMenu *T_V_V;
    TpGeneralAction *T_V_V_D;
    TpGeneralAction *T_V_V_R;
    TpGeneralAction *T_V_V_U;
    TpGeneralAction *T_V_V_W;
    TpGeneralMenu *T_V_R;
    TpGeneralAction *T_V_R_C;
    TpGeneralAction *T_V_R_A;
    TpGeneralMenu *T_V_C;
    TpGeneralAction *T_V_C_O;
    TpGeneralAction *T_V_C_N;
    TpGeneralAction *T_V_C_W;
    TpGeneralAction *T_V_L;
    TpGeneralMenu *T_S;
    TpGeneralMenu *T_S_R;
    TpGeneralAction *T_S_R_N;
    TpGeneralAction *T_S_R_S;
    TpGeneralAction *T_S_R_P;
    TpGeneralAction *T_S_R_pl;
    TpGeneralAction *T_S_C;
    TpGeneralAction *T_S_O;
    TpGeneralAction *T_S_W;
    TpGeneralAction *T_S_S;
    TpGeneralAction *T_S_G;
    TpGeneralMenu *T_W;
    TpGeneralMenu *T_W_I;
    TpGeneralAction *T_W_I_P;
    TpGeneralAction *T_W_I_S;
    TpGeneralAction *T_W_I_I;
    TpGeneralAction *T_W_I_D;
    TpGeneralMenu *T_W_S;
    TpGeneralAction *T_W_S_N;
    TpGeneralAction *T_W_S_T;
    TpGeneralAction *T_W_S_B;
    TpGeneralAction *T_W_S_M;
    TpGeneralMenu *T_W_E;
    TpGeneralAction *T_W_E_N;
    TpGeneralAction *T_W_E_T;
    TpGeneralAction *T_W_E_B;
    TpGeneralAction *T_W_E_M;
    TpGeneralMenu *T_M;
    TpGeneralAction *T_M_B;
    TpGeneralMenu *T_M_P;
    TpGeneralAction *T_M_P_O;
    TpGeneralAction *T_M_P_T;
    TpGeneralAction *T_M_P_M;
    TpGeneralMenu *T_M_Q;
    TpGeneralAction *T_M_Q_D;
    TpGeneralAction *T_M_Q_N;
    TpGeneralAction *T_M_Q_A;
    TpGeneralAction *T_M_Q_L;
    TpGeneralMenu *W;
    TpGeneralAction *W_F;
    TpGeneralAction *W_L;
    TpGeneralAction *W_B;
    TpGeneralAction *W_D;
    TpGeneralAction *W_I;
    // TpGeneralAction *W_Q;

private:
    // [[Action Group]] Show Spaces and Tabs
    // [[Action Group]] Word Wrap
    // [[Action Group]] Folding Style
    // [[Action Group]] Languages
    // [[Action Group]] Newline
    // [[Action Group]] Representing Tabs
    // [[Action Group]] Autocompletion When Single Entry
    // [[Action Group]] Autocompletion Source
    // [[Action Group]] Brace Matching
    // [[Action Group]] Call Tips Position
    // [[Action Group]] Call Tips Style
    // [[Action Group]] Edge Mode
    // [[Action Group]] Virtual Space
    // [[Action Group]] Rectangular Selection Modifier
    // [[Action Group]] Caret Sticky
    // [[Action Group]] Search Regex
    // [[Action Group]] Wrap Indentation
    // [[Action Group]] Wrap Start Flag
    // [[Action Group]] Wrap End Flag
    // [[Action Group]] Phrase Draw
    // [[Action Group]] Font Quality

    TpGeneralActionGroup *ag_ShowSpacesAndTabs;
    TpGeneralActionGroup *ag_WordWrap;
    TpGeneralActionGroup *ag_FoldingStyle;
    TpGeneralActionGroup *ag_Languages;
    TpGeneralActionGroup *ag_Newline;
    TpGeneralActionGroup *ag_RepresentingTabs;
    TpGeneralActionGroup *ag_AutocompletionWhenSingleEntry;
    TpGeneralActionGroup *ag_AutocompletionSource;
    TpGeneralActionGroup *ag_BraceMatching;
    TpGeneralActionGroup *ag_CallTipsPosition;
    TpGeneralActionGroup *ag_CallTipsStyle;
    TpGeneralActionGroup *ag_EdgeMode;
    TpGeneralActionGroup *ag_VirtualSpace;
    TpGeneralActionGroup *ag_RectangularSelectionModifier;
    TpGeneralActionGroup *ag_CaretSticky;
    TpGeneralActionGroup *ag_SearchRegex;
    TpGeneralActionGroup *ag_WrapIndentation;
    TpGeneralActionGroup *ag_WrapStartFlag;
    TpGeneralActionGroup *ag_WrapEndFlag;
    TpGeneralActionGroup *ag_PhraseDraw;
    TpGeneralActionGroup *ag_FontQuality;

private:
    TpActionList m_recentFileActions;
};

TP_END_NAMESPACE

#endif // TPMENUBAR_H
