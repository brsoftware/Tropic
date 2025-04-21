#include <Widgets/TpFindContainer>
#include <TpEditor>
#include <TpMenuBar>
#include <TpTabWidget>

TP_NAMESPACE

#if QT_VERSION_MAJOR <= 5
#define UnknownKey QKeySequence::StandardKey::UnknownKey
#define HelpContents QKeySequence::StandardKey::HelpContents
#define WhatsThis QKeySequence::StandardKey::WhatsThis
#define Open QKeySequence::StandardKey::Open
#define Close QKeySequence::StandardKey::Close
#define Save QKeySequence::StandardKey::Save
#define New QKeySequence::StandardKey::New
#define Delete QKeySequence::StandardKey::Delete
#define Cut QKeySequence::StandardKey::Cut
#define Copy QKeySequence::StandardKey::Copy
#define Paste QKeySequence::StandardKey::Paste
#define Undo QKeySequence::StandardKey::Undo
#define Redo QKeySequence::StandardKey::Redo
#define Back QKeySequence::StandardKey::Back
#define Forward QKeySequence::StandardKey::Forward
#define Refresh QKeySequence::StandardKey::Refresh
#define ZoomIn QKeySequence::StandardKey::ZoomIn
#define ZoomOut QKeySequence::StandardKey::ZoomOut
#define Print QKeySequence::StandardKey::Print
#define AddTab QKeySequence::StandardKey::AddTab
#define NextChild QKeySequence::StandardKey::NextChild
#define PreviousChild QKeySequence::StandardKey::PreviousChild
#define Find QKeySequence::StandardKey::Find
#define FindNext QKeySequence::StandardKey::FindNext
#define FindPrevious QKeySequence::StandardKey::FindPrevious
#define Replace QKeySequence::StandardKey::Replace
#define SelectAll QKeySequence::StandardKey::SelectAll
#define Bold QKeySequence::StandardKey::Bold
#define Italic QKeySequence::StandardKey::Italic
#define Underline QKeySequence::StandardKey::Underline
#define MoveToNextChar QKeySequence::StandardKey::MoveToNextChar
#define MoveToPreviousChar QKeySequence::StandardKey::MoveToPreviousChar
#define MoveToNextWord QKeySequence::StandardKey::MoveToNextWord
#define MoveToPreviousWord QKeySequence::StandardKey::MoveToPreviousWord
#define MoveToNextLine QKeySequence::StandardKey::MoveToNextLine
#define MoveToPreviousLine QKeySequence::StandardKey::MoveToPreviousLine
#define MoveToNextPage QKeySequence::StandardKey::MoveToNextPage
#define MoveToPreviousPage QKeySequence::StandardKey::MoveToPreviousPage
#define MoveToStartOfLine QKeySequence::StandardKey::MoveToStartOfLine
#define MoveToEndOfLine QKeySequence::StandardKey::MoveToEndOfLine
#define MoveToStartOfBlock QKeySequence::StandardKey::MoveToStartOfBlock
#define MoveToEndOfBlock QKeySequence::StandardKey::MoveToEndOfBlock
#define MoveToStartOfDocument QKeySequence::StandardKey::MoveToStartOfDocument
#define MoveToEndOfDocument QKeySequence::StandardKey::MoveToEndOfDocument
#define SelectNextChar QKeySequence::StandardKey::SelectNextChar
#define SelectPreviousChar QKeySequence::StandardKey::SelectPreviousChar
#define SelectNextWord QKeySequence::StandardKey::SelectNextWord
#define SelectPreviousWord QKeySequence::StandardKey::SelectPreviousWord
#define SelectNextLine QKeySequence::StandardKey::SelectNextLine
#define SelectPreviousLine QKeySequence::StandardKey::SelectPreviousLine
#define SelectNextPage QKeySequence::StandardKey::SelectNextPage
#define SelectPreviousPage QKeySequence::StandardKey::SelectPreviousPage
#define SelectStartOfLine QKeySequence::StandardKey::SelectStartOfLine
#define SelectEndOfLine QKeySequence::StandardKey::SelectEndOfLine
#define SelectStartOfBlock QKeySequence::StandardKey::SelectStartOfBlock
#define SelectEndOfBlock QKeySequence::StandardKey::SelectEndOfBlock
#define SelectStartOfDocument QKeySequence::StandardKey::SelectStartOfDocument
#define SelectEndOfDocument QKeySequence::StandardKey::SelectEndOfDocument
#define DeleteStartOfWord QKeySequence::StandardKey::DeleteStartOfWord
#define DeleteEndOfWord QKeySequence::StandardKey::DeleteEndOfWord
#define DeleteEndOfLine QKeySequence::StandardKey::DeleteEndOfLine
#define InsertParagraphSeparator QKeySequence::StandardKey::InsertParagraphSeparator
#define InsertLineSeparator QKeySequence::StandardKey::InsertLineSeparator
#define SaveAs QKeySequence::StandardKey::SaveAs
#define Preferences QKeySequence::StandardKey::Preferences
#define Quit QKeySequence::StandardKey::Quit
#define FullScreen QKeySequence::StandardKey::FullScreen
#define Deselect QKeySequence::StandardKey::Deselect
#define DeleteCompleteLine QKeySequence::StandardKey::DeleteCompleteLine
#define Backspace QKeySequence::StandardKey::Backspace
#define Cancel QKeySequence::StandardKey::Cancel

#define Key_Escape Qt::Key::Key_Escape
#define Key_Tab Qt::Key::Key_Tab
#define Key_Backtab Qt::Key::Key_Backtab
#define Key_Backspace Qt::Key::Key_Backspace
#define Key_Return Qt::Key::Key_Return
#define Key_Enter Qt::Key::Key_Enter
#define Key_Insert Qt::Key::Key_Insert
#define Key_Delete Qt::Key::Key_Delete
#define Key_Pause Qt::Key::Key_Pause
#define Key_Print Qt::Key::Key_Print
#define Key_SysReq Qt::Key::Key_SysReq
#define Key_Clear Qt::Key::Key_Clear
#define Key_Home Qt::Key::Key_Home
#define Key_End Qt::Key::Key_End
#define Key_Left Qt::Key::Key_Left
#define Key_Up Qt::Key::Key_Up
#define Key_Right Qt::Key::Key_Right
#define Key_Down Qt::Key::Key_Down
#define Key_PageUp Qt::Key::Key_PageUp
#define Key_PageDown Qt::Key::Key_PageDown
#define Key_Shift Qt::Key::Key_Shift
#define Key_Control Qt::Key::Key_Control
#define Key_Meta Qt::Key::Key_Meta
#define Key_Alt Qt::Key::Key_Alt
#define Key_CapsLock Qt::Key::Key_CapsLock
#define Key_NumLock Qt::Key::Key_NumLock
#define Key_ScrollLock Qt::Key::Key_ScrollLock
#define Key_F1 Qt::Key::Key_F1
#define Key_F2 Qt::Key::Key_F2
#define Key_F3 Qt::Key::Key_F3
#define Key_F4 Qt::Key::Key_F4
#define Key_F5 Qt::Key::Key_F5
#define Key_F6 Qt::Key::Key_F6
#define Key_F7 Qt::Key::Key_F7
#define Key_F8 Qt::Key::Key_F8
#define Key_F9 Qt::Key::Key_F9
#define Key_F10 Qt::Key::Key_F10
#define Key_F11 Qt::Key::Key_F11
#define Key_F12 Qt::Key::Key_F12
#define Key_F13 Qt::Key::Key_F13
#define Key_F14 Qt::Key::Key_F14
#define Key_F15 Qt::Key::Key_F15
#define Key_F16 Qt::Key::Key_F16
#define Key_F17 Qt::Key::Key_F17
#define Key_F18 Qt::Key::Key_F18
#define Key_F19 Qt::Key::Key_F19
#define Key_F20 Qt::Key::Key_F20
#define Key_F21 Qt::Key::Key_F21
#define Key_F22 Qt::Key::Key_F22
#define Key_F23 Qt::Key::Key_F23
#define Key_F24 Qt::Key::Key_F24
#define Key_F25 Qt::Key::Key_F25
#define Key_F26 Qt::Key::Key_F26
#define Key_F27 Qt::Key::Key_F27
#define Key_F28 Qt::Key::Key_F28
#define Key_F29 Qt::Key::Key_F29
#define Key_F30 Qt::Key::Key_F30
#define Key_F31 Qt::Key::Key_F31
#define Key_F32 Qt::Key::Key_F32
#define Key_F33 Qt::Key::Key_F33
#define Key_F34 Qt::Key::Key_F34
#define Key_F35 Qt::Key::Key_F35
#define Key_Super_L Qt::Key::Key_Super_L
#define Key_Super_R Qt::Key::Key_Super_R
#define Key_Menu Qt::Key::Key_Menu
#define Key_Hyper_L Qt::Key::Key_Hyper_L
#define Key_Hyper_R Qt::Key::Key_Hyper_R
#define Key_Help Qt::Key::Key_Help
#define Key_Direction_L Qt::Key::Key_Direction_L
#define Key_Direction_R Qt::Key::Key_Direction_R
#define Key_Space Qt::Key::Key_Space
#define Key_Any Qt::Key::Key_Any
#define Key_Exclam Qt::Key::Key_Exclam
#define Key_QuoteDbl Qt::Key::Key_QuoteDbl
#define Key_NumberSign Qt::Key::Key_NumberSign
#define Key_Dollar Qt::Key::Key_Dollar
#define Key_Percent Qt::Key::Key_Percent
#define Key_Ampersand Qt::Key::Key_Ampersand
#define Key_Apostrophe Qt::Key::Key_Apostrophe
#define Key_ParenLeft Qt::Key::Key_ParenLeft
#define Key_ParenRight Qt::Key::Key_ParenRight
#define Key_Asterisk Qt::Key::Key_Asterisk
#define Key_Plus Qt::Key::Key_Plus
#define Key_Comma Qt::Key::Key_Comma
#define Key_Minus Qt::Key::Key_Minus
#define Key_Period Qt::Key::Key_Period
#define Key_Slash Qt::Key::Key_Slash
#define Key_0 Qt::Key::Key_0
#define Key_1 Qt::Key::Key_1
#define Key_2 Qt::Key::Key_2
#define Key_3 Qt::Key::Key_3
#define Key_4 Qt::Key::Key_4
#define Key_5 Qt::Key::Key_5
#define Key_6 Qt::Key::Key_6
#define Key_7 Qt::Key::Key_7
#define Key_8 Qt::Key::Key_8
#define Key_9 Qt::Key::Key_9
#define Key_Colon Qt::Key::Key_Colon
#define Key_Semicolon Qt::Key::Key_Semicolon
#define Key_Less Qt::Key::Key_Less
#define Key_Equal Qt::Key::Key_Equal
#define Key_Greater Qt::Key::Key_Greater
#define Key_Question Qt::Key::Key_Question
#define Key_At Qt::Key::Key_At
#define Key_A Qt::Key::Key_A
#define Key_B Qt::Key::Key_B
#define Key_C Qt::Key::Key_C
#define Key_D Qt::Key::Key_D
#define Key_E Qt::Key::Key_E
#define Key_F Qt::Key::Key_F
#define Key_G Qt::Key::Key_G
#define Key_H Qt::Key::Key_H
#define Key_I Qt::Key::Key_I
#define Key_J Qt::Key::Key_J
#define Key_K Qt::Key::Key_K
#define Key_L Qt::Key::Key_L
#define Key_M Qt::Key::Key_M
#define Key_N Qt::Key::Key_N
#define Key_O Qt::Key::Key_O
#define Key_P Qt::Key::Key_P
#define Key_Q Qt::Key::Key_Q
#define Key_R Qt::Key::Key_R
#define Key_S Qt::Key::Key_S
#define Key_T Qt::Key::Key_T
#define Key_U Qt::Key::Key_U
#define Key_V Qt::Key::Key_V
#define Key_W Qt::Key::Key_W
#define Key_X Qt::Key::Key_X
#define Key_Y Qt::Key::Key_Y
#define Key_Z Qt::Key::Key_Z
#define Key_BracketLeft Qt::Key::Key_BracketLeft
#define Key_Backslash Qt::Key::Key_Backslash
#define Key_BracketRight Qt::Key::Key_BracketRight
#define Key_AsciiCircum Qt::Key::Key_AsciiCircum
#define Key_Underscore Qt::Key::Key_Underscore
#define Key_QuoteLeft Qt::Key::Key_QuoteLeft
#define Key_BraceLeft Qt::Key::Key_BraceLeft
#define Key_Bar Qt::Key::Key_Bar
#define Key_BraceRight Qt::Key::Key_BraceRight
#define Key_AsciiTilde Qt::Key::Key_AsciiTilde

#define Key_nobreakspace Qt::Key::Key_nobreakspace
#define Key_exclamdown Qt::Key::Key_exclamdown
#define Key_cent Qt::Key::Key_cent
#define Key_sterling Qt::Key::Key_sterling
#define Key_currency Qt::Key::Key_currency
#define Key_yen Qt::Key::Key_yen
#define Key_brokenbar Qt::Key::Key_brokenbar
#define Key_section Qt::Key::Key_section
#define Key_diaeresis Qt::Key::Key_diaeresis
#define Key_copyright Qt::Key::Key_copyright
#define Key_ordfeminine Qt::Key::Key_ordfeminine
#define Key_guillemotleft Qt::Key::Key_guillemotleft
#define Key_notsign Qt::Key::Key_notsign
#define Key_hyphen Qt::Key::Key_hyphen
#define Key_registered Qt::Key::Key_registered
#define Key_macron Qt::Key::Key_macron
#define Key_degree Qt::Key::Key_degree
#define Key_plusminus Qt::Key::Key_plusminus
#define Key_twosuperior Qt::Key::Key_twosuperior
#define Key_threesuperior Qt::Key::Key_threesuperior
#define Key_acute Qt::Key::Key_acute
#define Key_mu Qt::Key::Key_mu
#define Key_paragraph Qt::Key::Key_paragraph
#define Key_periodcentered Qt::Key::Key_periodcentered
#define Key_cedilla Qt::Key::Key_cedilla
#define Key_onesuperior Qt::Key::Key_onesuperior
#define Key_masculine Qt::Key::Key_masculine
#define Key_guillemotright Qt::Key::Key_guillemotright
#define Key_onequarter Qt::Key::Key_onequarter
#define Key_onehalf Qt::Key::Key_onehalf
#define Key_threequarters Qt::Key::Key_threequarters
#define Key_questiondown Qt::Key::Key_questiondown
#define Key_Agrave Qt::Key::Key_Agrave
#define Key_Aacute Qt::Key::Key_Aacute
#define Key_Acircumflex Qt::Key::Key_Acircumflex
#define Key_Atilde Qt::Key::Key_Atilde
#define Key_Adiaeresis Qt::Key::Key_Adiaeresis
#define Key_Aring Qt::Key::Key_Aring
#define Key_AE Qt::Key::Key_AE
#define Key_Ccedilla Qt::Key::Key_Ccedilla
#define Key_Egrave Qt::Key::Key_Egrave
#define Key_Eacute Qt::Key::Key_Eacute
#define Key_Ecircumflex Qt::Key::Key_Ecircumflex
#define Key_Ediaeresis Qt::Key::Key_Ediaeresis
#define Key_Igrave Qt::Key::Key_Igrave
#define Key_Iacute Qt::Key::Key_Iacute
#define Key_Icircumflex Qt::Key::Key_Icircumflex
#define Key_Idiaeresis Qt::Key::Key_Idiaeresis
#define Key_ETH Qt::Key::Key_ETH
#define Key_Ntilde Qt::Key::Key_Ntilde
#define Key_Ograve Qt::Key::Key_Ograve
#define Key_Oacute Qt::Key::Key_Oacute
#define Key_Ocircumflex Qt::Key::Key_Ocircumflex
#define Key_Otilde Qt::Key::Key_Otilde
#define Key_Odiaeresis Qt::Key::Key_Odiaeresis
#define Key_multiply Qt::Key::Key_multiply
#define Key_Ooblique Qt::Key::Key_Ooblique
#define Key_Ugrave Qt::Key::Key_Ugrave
#define Key_Uacute Qt::Key::Key_Uacute
#define Key_Ucircumflex Qt::Key::Key_Ucircumflex
#define Key_Udiaeresis Qt::Key::Key_Udiaeresis
#define Key_Yacute Qt::Key::Key_Yacute
#define Key_THORN Qt::Key::Key_THORN
#define Key_ssharp Qt::Key::Key_ssharp
#define Key_division Qt::Key::Key_division
#define Key_ydiaeresis Qt::Key::Key_ydiaeresis
#define Key_AltGr               Qt::Key::Key_AltGr
#define Key_Multi_key           Qt::Key::Key_Multi_key
#define Key_Codeinput           Qt::Key::Key_Codeinput
#define Key_SingleCandidate     Qt::Key::Key_SingleCandidate
#define Key_MultipleCandidate   Qt::Key::Key_MultipleCandidate
#define Key_PreviousCandidate   Qt::Key::Key_PreviousCandidate
#define Key_Mode_switch         Qt::Key::Key_Mode_switch
#define Key_Kanji               Qt::Key::Key_Kanji
#define Key_Muhenkan            Qt::Key::Key_Muhenkan
#define Key_Henkan              Qt::Key::Key_Henkan
#define Key_Romaji              Qt::Key::Key_Romaji
#define Key_Hiragana            Qt::Key::Key_Hiragana
#define Key_Katakana            Qt::Key::Key_Katakana
#define Key_Hiragana_Katakana   Qt::Key::Key_Hiragana_Katakana
#define Key_Zenkaku             Qt::Key::Key_Zenkaku
#define Key_Hankaku             Qt::Key::Key_Hankaku
#define Key_Zenkaku_Hankaku     Qt::Key::Key_Zenkaku_Hankaku
#define Key_Touroku             Qt::Key::Key_Touroku
#define Key_Massyo              Qt::Key::Key_Massyo
#define Key_Kana_Lock           Qt::Key::Key_Kana_Lock
#define Key_Kana_Shift          Qt::Key::Key_Kana_Shift
#define Key_Eisu_Shift          Qt::Key::Key_Eisu_Shift
#define Key_Eisu_toggle         Qt::Key::Key_Eisu_toggle
#define Key_Hangul              Qt::Key::Key_Hangul
#define Key_Hangul_Start        Qt::Key::Key_Hangul_Start
#define Key_Hangul_End          Qt::Key::Key_Hangul_End
#define Key_Hangul_Hanja        Qt::Key::Key_Hangul_Hanja
#define Key_Hangul_Jamo         Qt::Key::Key_Hangul_Jamo
#define Key_Hangul_Romaja       Qt::Key::Key_Hangul_Romaja
#define Key_Hangul_Jeonja       Qt::Key::Key_Hangul_Jeonja
#define Key_Hangul_Banja        Qt::Key::Key_Hangul_Banja
#define Key_Hangul_PreHanja     Qt::Key::Key_Hangul_PreHanja
#define Key_Hangul_PostHanja    Qt::Key::Key_Hangul_PostHanja
#define Key_Hangul_Special      Qt::Key::Key_Hangul_Special
#define Key_Dead_Grave          Qt::Key::Key_Dead_Grave
#define Key_Dead_Acute          Qt::Key::Key_Dead_Acute
#define Key_Dead_Circumflex     Qt::Key::Key_Dead_Circumflex
#define Key_Dead_Tilde          Qt::Key::Key_Dead_Tilde
#define Key_Dead_Macron         Qt::Key::Key_Dead_Macron
#define Key_Dead_Breve          Qt::Key::Key_Dead_Breve
#define Key_Dead_Abovedot       Qt::Key::Key_Dead_Abovedot
#define Key_Dead_Diaeresis      Qt::Key::Key_Dead_Diaeresis
#define Key_Dead_Abovering      Qt::Key::Key_Dead_Abovering
#define Key_Dead_Doubleacute    Qt::Key::Key_Dead_Doubleacute
#define Key_Dead_Caron          Qt::Key::Key_Dead_Caron
#define Key_Dead_Cedilla        Qt::Key::Key_Dead_Cedilla
#define Key_Dead_Ogonek         Qt::Key::Key_Dead_Ogonek
#define Key_Dead_Iota           Qt::Key::Key_Dead_Iota
#define Key_Dead_Voiced_Sound   Qt::Key::Key_Dead_Voiced_Sound
#define Key_Dead_Semivoiced_Sound Qt::Key::Key_Dead_Semivoiced_Sound
#define Key_Dead_Belowdot       Qt::Key::Key_Dead_Belowdot
#define Key_Dead_Hook           Qt::Key::Key_Dead_Hook
#define Key_Dead_Horn           Qt::Key::Key_Dead_Horn
#define Key_Dead_Stroke         Qt::Key::Key_Dead_Stroke
#define Key_Dead_Abovecomma     Qt::Key::Key_Dead_Abovecomma
#define Key_Dead_Abovereversedcomma Qt::Key::Key_Dead_Abovereversedcomma
#define Key_Dead_Doublegrave    Qt::Key::Key_Dead_Doublegrave
#define Key_Dead_Belowring      Qt::Key::Key_Dead_Belowring
#define Key_Dead_Belowmacron    Qt::Key::Key_Dead_Belowmacron
#define Key_Dead_Belowcircumflex Qt::Key::Key_Dead_Belowcircumflex
#define Key_Dead_Belowtilde     Qt::Key::Key_Dead_Belowtilde
#define Key_Dead_Belowbreve     Qt::Key::Key_Dead_Belowbreve
#define Key_Dead_Belowdiaeresis Qt::Key::Key_Dead_Belowdiaeresis
#define Key_Dead_Invertedbreve  Qt::Key::Key_Dead_Invertedbreve
#define Key_Dead_Belowcomma     Qt::Key::Key_Dead_Belowcomma
#define Key_Dead_Currency       Qt::Key::Key_Dead_Currency
#define Key_Dead_a              Qt::Key::Key_Dead_a
#define Key_Dead_A              Qt::Key::Key_Dead_A
#define Key_Dead_e              Qt::Key::Key_Dead_e
#define Key_Dead_E              Qt::Key::Key_Dead_E
#define Key_Dead_i              Qt::Key::Key_Dead_i
#define Key_Dead_I              Qt::Key::Key_Dead_I
#define Key_Dead_o              Qt::Key::Key_Dead_o
#define Key_Dead_O              Qt::Key::Key_Dead_O
#define Key_Dead_u              Qt::Key::Key_Dead_u
#define Key_Dead_U              Qt::Key::Key_Dead_U
#define Key_Dead_Small_Schwa    Qt::Key::Key_Dead_Small_Schwa
#define Key_Dead_Capital_Schwa  Qt::Key::Key_Dead_Capital_Schwa
#define Key_Dead_Greek          Qt::Key::Key_Dead_Greek
#define Key_Dead_Lowline        Qt::Key::Key_Dead_Lowline
#define Key_Dead_Aboveverticalline Qt::Key::Key_Dead_Aboveverticalline
#define Key_Dead_Belowverticalline Qt::Key::Key_Dead_Belowverticalline
#define Key_Dead_Longsolidusoverlay Qt::Key::Key_Dead_Longsolidusoverlay
#define Key_Back  Qt::Key::Key_Back
#define Key_Forward  Qt::Key::Key_Forward
#define Key_Stop  Qt::Key::Key_Stop
#define Key_Refresh  Qt::Key::Key_Refresh
#define Key_VolumeDown Qt::Key::Key_VolumeDown
#define Key_VolumeMute  Qt::Key::Key_VolumeMute
#define Key_VolumeUp Qt::Key::Key_VolumeUp
#define Key_BassBoost Qt::Key::Key_BassBoost
#define Key_BassUp Qt::Key::Key_BassUp
#define Key_BassDown Qt::Key::Key_BassDown
#define Key_TrebleUp Qt::Key::Key_TrebleUp
#define Key_TrebleDown Qt::Key::Key_TrebleDown
#define Key_MediaPlay  Qt::Key::Key_MediaPlay
#define Key_MediaStop  Qt::Key::Key_MediaStop
#define Key_MediaPrevious  Qt::Key::Key_MediaPrevious
#define Key_MediaNext  Qt::Key::Key_MediaNext
#define Key_MediaRecord Qt::Key::Key_MediaRecord
#define Key_MediaPause Qt::Key::Key_MediaPause
#define Key_MediaTogglePlayPause Qt::Key::Key_MediaTogglePlayPause
#define Key_HomePage  Qt::Key::Key_HomePage
#define Key_Favorites  Qt::Key::Key_Favorites
#define Key_Search  Qt::Key::Key_Search
#define Key_Standby Qt::Key::Key_Standby
#define Key_OpenUrl Qt::Key::Key_OpenUrl
#define Key_LaunchMail  Qt::Key::Key_LaunchMail
#define Key_LaunchMedia Qt::Key::Key_LaunchMedia
#define Key_Launch0  Qt::Key::Key_Launch0
#define Key_Launch1  Qt::Key::Key_Launch1
#define Key_Launch2  Qt::Key::Key_Launch2
#define Key_Launch3  Qt::Key::Key_Launch3
#define Key_Launch4  Qt::Key::Key_Launch4
#define Key_Launch5  Qt::Key::Key_Launch5
#define Key_Launch6  Qt::Key::Key_Launch6
#define Key_Launch7  Qt::Key::Key_Launch7
#define Key_Launch8  Qt::Key::Key_Launch8
#define Key_Launch9  Qt::Key::Key_Launch9
#define Key_LaunchA  Qt::Key::Key_LaunchA
#define Key_LaunchB  Qt::Key::Key_LaunchB
#define Key_LaunchC  Qt::Key::Key_LaunchC
#define Key_LaunchD  Qt::Key::Key_LaunchD
#define Key_LaunchE  Qt::Key::Key_LaunchE
#define Key_LaunchF  Qt::Key::Key_LaunchF
#define Key_MonBrightnessUp Qt::Key::Key_MonBrightnessUp
#define Key_MonBrightnessDown Qt::Key::Key_MonBrightnessDown
#define Key_KeyboardLightOnOff Qt::Key::Key_KeyboardLightOnOff
#define Key_KeyboardBrightnessUp Qt::Key::Key_KeyboardBrightnessUp
#define Key_KeyboardBrightnessDown Qt::Key::Key_KeyboardBrightnessDown
#define Key_PowerOff Qt::Key::Key_PowerOff
#define Key_WakeUp Qt::Key::Key_WakeUp
#define Key_Eject Qt::Key::Key_Eject
#define Key_ScreenSaver Qt::Key::Key_ScreenSaver
#define Key_WWW Qt::Key::Key_WWW
#define Key_Memo Qt::Key::Key_Memo
#define Key_LightBulb Qt::Key::Key_LightBulb
#define Key_Shop Qt::Key::Key_Shop
#define Key_History Qt::Key::Key_History
#define Key_AddFavorite Qt::Key::Key_AddFavorite
#define Key_HotLinks Qt::Key::Key_HotLinks
#define Key_BrightnessAdjust Qt::Key::Key_BrightnessAdjust
#define Key_Finance Qt::Key::Key_Finance
#define Key_Community Qt::Key::Key_Community
#define Key_AudioRewind Qt::Key::Key_AudioRewind
#define Key_BackForward Qt::Key::Key_BackForward
#define Key_ApplicationLeft Qt::Key::Key_ApplicationLeft
#define Key_ApplicationRight Qt::Key::Key_ApplicationRight
#define Key_Book Qt::Key::Key_Book
#define Key_CD Qt::Key::Key_CD
#define Key_Calculator Qt::Key::Key_Calculator
#define Key_ToDoList Qt::Key::Key_ToDoList
#define Key_ClearGrab Qt::Key::Key_ClearGrab
#define Key_Close Qt::Key::Key_Close
#define Key_Copy Qt::Key::Key_Copy
#define Key_Cut Qt::Key::Key_Cut
#define Key_Display Qt::Key::Key_Display
#define Key_DOS Qt::Key::Key_DOS
#define Key_Documents Qt::Key::Key_Documents
#define Key_Excel Qt::Key::Key_Excel
#define Key_Explorer Qt::Key::Key_Explorer
#define Key_Game Qt::Key::Key_Game
#define Key_Go Qt::Key::Key_Go
#define Key_iTouch Qt::Key::Key_iTouch
#define Key_LogOff Qt::Key::Key_LogOff
#define Key_Market Qt::Key::Key_Market
#define Key_Meeting Qt::Key::Key_Meeting
#define Key_MenuKB Qt::Key::Key_MenuKB
#define Key_MenuPB Qt::Key::Key_MenuPB
#define Key_MySites Qt::Key::Key_MySites
#define Key_News Qt::Key::Key_News
#define Key_OfficeHome Qt::Key::Key_OfficeHome
#define Key_Option Qt::Key::Key_Option
#define Key_Paste Qt::Key::Key_Paste
#define Key_Phone Qt::Key::Key_Phone
#define Key_Calendar Qt::Key::Key_Calendar
#define Key_Reply Qt::Key::Key_Reply
#define Key_Reload Qt::Key::Key_Reload
#define Key_RotateWindows Qt::Key::Key_RotateWindows
#define Key_RotationPB Qt::Key::Key_RotationPB
#define Key_RotationKB Qt::Key::Key_RotationKB
#define Key_Save Qt::Key::Key_Save
#define Key_Send Qt::Key::Key_Send
#define Key_Spell Qt::Key::Key_Spell
#define Key_SplitScreen Qt::Key::Key_SplitScreen
#define Key_Support Qt::Key::Key_Support
#define Key_TaskPane Qt::Key::Key_TaskPane
#define Key_Terminal Qt::Key::Key_Terminal
#define Key_Tools Qt::Key::Key_Tools
#define Key_Travel Qt::Key::Key_Travel
#define Key_Video Qt::Key::Key_Video
#define Key_Word Qt::Key::Key_Word
#define Key_Xfer Qt::Key::Key_Xfer
#define Key_ZoomIn Qt::Key::Key_ZoomIn
#define Key_ZoomOut Qt::Key::Key_ZoomOut
#define Key_Away Qt::Key::Key_Away
#define Key_Messenger Qt::Key::Key_Messenger
#define Key_WebCam Qt::Key::Key_WebCam
#define Key_MailForward Qt::Key::Key_MailForward
#define Key_Pictures Qt::Key::Key_Pictures
#define Key_Music Qt::Key::Key_Music
#define Key_Battery Qt::Key::Key_Battery
#define Key_Bluetooth Qt::Key::Key_Bluetooth
#define Key_WLAN Qt::Key::Key_WLAN
#define Key_UWB Qt::Key::Key_UWB
#define Key_AudioForward Qt::Key::Key_AudioForward
#define Key_AudioRepeat Qt::Key::Key_AudioRepeat
#define Key_AudioRandomPlay Qt::Key::Key_AudioRandomPlay
#define Key_Subtitle Qt::Key::Key_Subtitle
#define Key_AudioCycleTrack Qt::Key::Key_AudioCycleTrack
#define Key_Time Qt::Key::Key_Time
#define Key_Hibernate Qt::Key::Key_Hibernate
#define Key_View Qt::Key::Key_View
#define Key_TopMenu Qt::Key::Key_TopMenu
#define Key_PowerDown Qt::Key::Key_PowerDown
#define Key_Suspend Qt::Key::Key_Suspend
#define Key_ContrastAdjust Qt::Key::Key_ContrastAdjust
#define Key_LaunchG  Qt::Key::Key_LaunchG
#define Key_LaunchH  Qt::Key::Key_LaunchH
#define Key_TouchpadToggle Qt::Key::Key_TouchpadToggle
#define Key_TouchpadOn Qt::Key::Key_TouchpadOn
#define Key_TouchpadOff Qt::Key::Key_TouchpadOff
#define Key_MicMute Qt::Key::Key_MicMute
#define Key_Red Qt::Key::Key_Red
#define Key_Green Qt::Key::Key_Green
#define Key_Yellow Qt::Key::Key_Yellow
#define Key_Blue Qt::Key::Key_Blue
#define Key_ChannelUp Qt::Key::Key_ChannelUp
#define Key_ChannelDown Qt::Key::Key_ChannelDown
#define Key_Guide    Qt::Key::Key_Guide
#define Key_Info     Qt::Key::Key_Info
#define Key_Settings Qt::Key::Key_Settings
#define Key_MicVolumeUp   Qt::Key::Key_MicVolumeUp
#define Key_MicVolumeDown Qt::Key::Key_MicVolumeDown
#define Key_New      Qt::Key::Key_New
#define Key_Open     Qt::Key::Key_Open
#define Key_Find     Qt::Key::Key_Find
#define Key_Undo     Qt::Key::Key_Undo
#define Key_Redo     Qt::Key::Key_Redo
#define Key_MediaLast Qt::Key::Key_MediaLast
#define Key_Select Qt::Key::Key_Select
#define Key_Yes Qt::Key::Key_Yes
#define Key_No Qt::Key::Key_No
#define Key_Cancel  Qt::Key::Key_Cancel
#define Key_Printer Qt::Key::Key_Printer
#define Key_Execute Qt::Key::Key_Execute
#define Key_Sleep   Qt::Key::Key_Sleep
#define Key_Play    Qt::Key::Key_Play
#define Key_Zoom    Qt::Key::Key_Zoom
#define Key_Exit    Qt::Key::Key_Exit
#define Key_Context1 Qt::Key::Key_Context1
#define Key_Context2 Qt::Key::Key_Context2
#define Key_Context3 Qt::Key::Key_Context3
#define Key_Context4 Qt::Key::Key_Context4
#define Key_Call Qt::Key::Key_Call
#define Key_Hangup Qt::Key::Key_Hangup
#define Key_Flip Qt::Key::Key_Flip
#define Key_ToggleCallHangup Qt::Key::Key_ToggleCallHangup
#define Key_VoiceDial Qt::Key::Key_VoiceDial
#define Key_LastNumberRedial Qt::Key::Key_LastNumberRedial
#define Key_Camera Qt::Key::Key_Camera
#define Key_CameraFocus Qt::Key::Key_CameraFocus

#define META Qt::Modifier::META
#define SHIFT Qt::Modifier::SHIFT
#define CTRL Qt::Modifier::CTRL
#define ALT Qt::Modifier::ALT
#endif

TpMenuBar::TpMenuBar(QWidget *parent)
    : QMenuBar(parent)
{
    setObjectName("menuBar");

#if QT_VERSION_MAJOR >= 6
    using enum QKeySequence::StandardKey;
    using enum Qt::Key;
    using enum Qt::Modifier;
#endif

    F = new TpGeneralMenu(this, tr("&File"));
    F_N = new TpGeneralMenu(F, tr("&New File"));
    F_N_T = new TpGeneralAction(F_N, tr("New File on Next &Tab"), New, true);
    F_N_W = new TpGeneralAction(F_N, tr("New File on New &Window"), QKeySequence(CTRL | SHIFT | Key_N), true);
    F_O = new TpGeneralMenu(F, tr("&Open File"));
    F_O_T = new TpGeneralAction(F_O, tr("Open File on Next &Tab"), Open, true);
    F_O_W = new TpGeneralAction(F_O, tr("Open File on New &Window"), QKeySequence(CTRL | SHIFT | Key_O), true);
    F_R = new TpGeneralMenu(F, tr("Open &Recent"));
    createOpenRecentActions();
    F_R->addSeparator();
    F_R_C = new TpGeneralAction(F_R, tr("&Clear Recent Files List"), QKeySequence(), true);
    F_R_O = new TpGeneralAction(F_R, tr("&Open All Recent Files"), QKeySequence(), true);
    F_R_L = new TpGeneralAction(F_R, tr("Open The &Latest Entry"), QKeySequence(), true);
    F->addSeparator();
    F_T = new TpGeneralMenu(F, tr("Open &The Containing Folder"));
    F_T_F = new TpGeneralAction(F_T, tr("&File Explorer"));
    F_T_C = new TpGeneralAction(F_T, tr("&Command Line Interface"));
    F_T->addSeparator();
    F_T_T = new TpGeneralAction(F_T, tr("&Tropic File Browser"), QKeySequence(CTRL | SHIFT | Key_B));
    F_E = new TpGeneralAction(F, tr("R&eload From Disk..."));
    F_D = new TpGeneralAction(F, tr("Reveal in &Default Viewer..."));
    F_W = new TpGeneralAction(F, tr("Open Tropic File Bro&wser"), QKeySequence(CTRL | SHIFT | ALT | Key_B), true);
    F_B = new TpGeneralMenu(F, tr("File &Browser Operations"));
    F_B_R = new TpGeneralAction(F_B, tr("&Rename..."), QKeySequence(Key_F2));
    F_B_D = new TpGeneralAction(F_B, tr("&Delete..."));
    F_B->addSeparator();
    F_B_F = new TpGeneralAction(F_B, tr("Copy &File Name"));
    F_B_A = new TpGeneralAction(F_B, tr("Copy &Absolute Path"));
    F_B_N = new TpGeneralAction(F_B, tr("Copy Directory &Name"));
    F->addSeparator();
    F_S = new TpGeneralAction(F, tr("&Save"), Save);
    F_A = new TpGeneralAction(F, tr("Save &As"), QKeySequence(CTRL | SHIFT | Key_A));
    F_Y = new TpGeneralAction(F, tr("Save A Cop&y To..."));
    F_d = new TpGeneralAction(F, tr("Save All&..."), QKeySequence(CTRL | SHIFT | Key_S));
    F->addSeparator();
    F_C = new TpGeneralAction(F, tr("&Close"), QKeySequence(CTRL | Key_W));
    F_L = new TpGeneralAction(F, tr("Close A&ll"), QKeySequence(CTRL | SHIFT | ALT | Key_W));
    F_p = new TpGeneralAction(F, tr("Close All &(This Tab Only)..."), QKeySequence(CTRL | SHIFT | Key_W));
    F_M = new TpGeneralMenu(F, tr("Close &Multiple Documents"));
    F_M_B = new TpGeneralAction(F_M, tr("Close All &But This..."));
    F_M_L = new TpGeneralAction(F_M, tr("Close All To The &Left..."));
    F_M_R = new TpGeneralAction(F_M, tr("Close All To The &Right..."));
    F_M_U = new TpGeneralAction(F_M, tr("Close All &Unchanged"));
    F->addSeparator();
    // F_P = new TpGeneralAction(F, tr("&Print"), Print);
    // F_V = new TpGeneralAction(F, tr("Print Pre&view..."), QKeySequence(CTRL | SHIFT | Key_P));
    // F->addSeparator();
    F_Q = new TpGeneralAction(F, tr("&Quit"), QKeySequence(CTRL | Key_Q), true);
    E = new TpGeneralMenu(this, tr("&Edit"));
    E_U = new TpGeneralAction(E, tr("&Undo"), Undo);
    E_R = new TpGeneralAction(E, tr("&Redo"), Redo);
    E->addSeparator();
    E_C = new TpGeneralAction(E, tr("&Cut"), Cut);
    E_O = new TpGeneralAction(E, tr("C&opy"), Copy);
    E_P = new TpGeneralAction(E, tr("&Paste"), Paste);
    E->addSeparator();
    E_D = new TpGeneralMenu(E, tr("&Deletion Operations"));
    E_D_D = new TpGeneralAction(E_D, tr("&Delete"), Delete);
    E_D_B = new TpGeneralAction(E_D, tr("&Backspace"), Backspace);
    E_D_I = new TpGeneralAction(E_D, tr("Backspace &If Not Start of Line"));
    E_D_L = new TpGeneralAction(E_D, tr("Delete Word &Left"), QKeySequence(CTRL | Key_Backspace));
    E_D_R = new TpGeneralAction(E_D, tr("Delete Word &Right"), QKeySequence(CTRL | Key_Delete));
    E_D_E = new TpGeneralAction(E_D, tr("Delete Word Right &End"));
    E_D_N = new TpGeneralAction(E_D, tr("Delete Li&ne Left"), QKeySequence(CTRL | SHIFT | Key_Backspace));
    E_D_G = new TpGeneralAction(E_D, tr("Delete Line Ri&ght")), QKeySequence(CTRL | SHIFT | Key_Delete);
    E_M = new TpGeneralMenu(E, tr("&Move Operations"));
    E_M_A = new TpGeneralAction(E_M, tr("&A. Line Down"), QKeySequence(Key_Down));
    E_M_B = new TpGeneralAction(E_M, tr("&B. Line Up"), QKeySequence(Key_Up));
    E_M_C = new TpGeneralAction(E_M, tr("&C. Line End"), QKeySequence(Key_End));
    E_M_D = new TpGeneralAction(E_M, tr("&D. Line End Display"), QKeySequence(ALT | Key_End));
    E_M_E = new TpGeneralAction(E_M, tr("&E. Line End Wrap"));
    E_M_F = new TpGeneralAction(E_M, tr("&F. Paragraph Down"), QKeySequence(CTRL | Key_BracketRight));
    E_M_G = new TpGeneralAction(E_M, tr("&G. Paragraph Up"), QKeySequence(CTRL | Key_BracketLeft));
    E_M_H = new TpGeneralAction(E_M, tr("&H. Character Left"), QKeySequence(Key_Left));
    E_M_I = new TpGeneralAction(E_M, tr("&I. Character Right"), QKeySequence(Key_Right));
    E_M_J = new TpGeneralAction(E_M, tr("&J. Word Left"), QKeySequence(CTRL | Key_Left));
    E_M_K = new TpGeneralAction(E_M, tr("&K. Word Right"), QKeySequence(CTRL | Key_Right));
    E_M_L = new TpGeneralAction(E_M, tr("&L. Word Left End"));
    E_M_M = new TpGeneralAction(E_M, tr("&M. Word Right End"));
    E_M_N = new TpGeneralAction(E_M, tr("&N. Word Part Left"), QKeySequence(CTRL | Key_Slash));
    E_M_O = new TpGeneralAction(E_M, tr("&O. Word Part Right"), QKeySequence(CTRL | Key_Backslash));
    E_M_P = new TpGeneralAction(E_M, tr("&P. Home"));
    E_M_Q = new TpGeneralAction(E_M, tr("&Q. Home Display"), QKeySequence(ALT | Key_Home));
    E_M_R = new TpGeneralAction(E_M, tr("&R. Home Wrap"));
    E_M_S = new TpGeneralAction(E_M, tr("&S. Visible Character Home"), QKeySequence(Key_Home));
    E_M_T = new TpGeneralAction(E_M, tr("&T. Visible Character Home Wrap"));
    E_M_U = new TpGeneralAction(E_M, tr("&U. Document Start"), QKeySequence(CTRL | Key_Home));
    E_M_V = new TpGeneralAction(E_M, tr("&V. Document End"), QKeySequence(CTRL | Key_End));
    E_M_W = new TpGeneralAction(E_M, tr("&W. Page Up"), QKeySequence(Key_PageUp));
    E_M_X = new TpGeneralAction(E_M, tr("&X. Page Down"), QKeySequence(Key_PageDown));
    E_M_Y = new TpGeneralAction(E_M, tr("&Y. Stuttered Page Up"));
    E_M_Z = new TpGeneralAction(E_M, tr("&Z. Stuttered Page Down"));
    E_S = new TpGeneralMenu(E, tr("&Selection Operations"));
    E_S_A = new TpGeneralAction(E_S, tr("&A. Select All"), SelectAll);
    E_S->addSeparator();
    E_S_B = new TpGeneralAction(E_S, tr("&B. Line Down"), QKeySequence(SHIFT | Key_Down));
    E_S_C = new TpGeneralAction(E_S, tr("&C. Line Down Rectangular"), QKeySequence(SHIFT | ALT | Key_Down));
    E_S_D = new TpGeneralAction(E_S, tr("&D. Line Up"), QKeySequence(SHIFT | Key_Up));
    E_S_E = new TpGeneralAction(E_S, tr("&E. Line Up Rectangular"), QKeySequence(SHIFT | ALT | Key_Up));
    E_S_F = new TpGeneralAction(E_S, tr("&F. Line End"), QKeySequence(SHIFT | Key_End));
    E_S_G = new TpGeneralAction(E_S, tr("&G. Line End Rectangular"), QKeySequence(SHIFT | ALT | Key_End));
    E_S_H = new TpGeneralAction(E_S, tr("&H. Line End Display"));
    E_S_I = new TpGeneralAction(E_S, tr("&I. Line End Wrap"));
    E_S_J = new TpGeneralAction(E_S, tr("&J. Paragraph Down"), QKeySequence(CTRL | SHIFT | Key_BracketRight));
    E_S_K = new TpGeneralAction(E_S, tr("&K. Paragraph Up"), QKeySequence(CTRL | SHIFT | Key_BracketLeft));
    E_S_L = new TpGeneralAction(E_S, tr("&L. Character Left"), QKeySequence(SHIFT | Key_Left));
    E_S_M = new TpGeneralAction(E_S, tr("&M. Character Left Rectangular"), QKeySequence(SHIFT | ALT | Key_Left));
    E_S_N = new TpGeneralAction(E_S, tr("&N. Character Right"), QKeySequence(SHIFT | Key_Right));
    E_S_O = new TpGeneralAction(E_S, tr("&O. Character Right Rectangular"), QKeySequence(SHIFT | ALT | Key_Right));
    E_S_P = new TpGeneralAction(E_S, tr("&P. Word Left"), QKeySequence(CTRL | SHIFT | Key_Left));
    E_S_Q = new TpGeneralAction(E_S, tr("&Q. Word Right"), QKeySequence(CTRL | SHIFT | Key_Right));
    E_S_R = new TpGeneralAction(E_S, tr("&R. Word Left End"));
    E_S_S = new TpGeneralAction(E_S, tr("&S. Word Right End"));
    E_S_T = new TpGeneralAction(E_S, tr("&T. Word Part Left"), QKeySequence(CTRL | SHIFT | Key_Slash));
    E_S_U = new TpGeneralAction(E_S, tr("&U. Word Part Right"), QKeySequence(CTRL | Key_Backslash));
    E_S_V = new TpGeneralAction(E_S, tr("&V. Home"));
    E_S_W = new TpGeneralAction(E_S, tr("&W. Home Rectangular"));
    E_S_X = new TpGeneralAction(E_S, tr("&X. Home Display"));
    E_S_Y = new TpGeneralAction(E_S, tr("&Y. Home Wrap"));
    E_S_Z = new TpGeneralAction(E_S, tr("&Z. Visible Character Home"), QKeySequence(SHIFT | Key_Home));
    E_S_0 =
        new TpGeneralAction(E_S, tr("&0. Visible Character Home Rectangular"), QKeySequence(SHIFT | ALT | Key_Home));
    E_S_1 = new TpGeneralAction(E_S, tr("&1. Visible Character Home Wrap"));
    E_S_2 = new TpGeneralAction(E_S, tr("&2. Document Start"), QKeySequence(CTRL | SHIFT | Key_Home));
    E_S_3 = new TpGeneralAction(E_S, tr("&3. Document End"), QKeySequence(CTRL | SHIFT | Key_End));
    E_S_4 = new TpGeneralAction(E_S, tr("&4. Page Up"), QKeySequence(SHIFT | Key_PageUp));
    E_S_5 = new TpGeneralAction(E_S, tr("&5. Page Up Rectangular"), QKeySequence(SHIFT | ALT | Key_PageUp));
    E_S_6 = new TpGeneralAction(E_S, tr("&6. Page Down"), QKeySequence(SHIFT | Key_PageDown));
    E_S_7 = new TpGeneralAction(E_S, tr("&7. Page Down Rectangular"), QKeySequence(SHIFT | ALT | Key_PageDown));
    E_S_8 = new TpGeneralAction(E_S, tr("&8. Stuttered Page Up"));
    E_S_9 = new TpGeneralAction(E_S, tr("&9. Stuttered Page Down"));
    E_I = new TpGeneralMenu(E, tr("&Indentation Operations"));
    E_I_I = new TpGeneralAction(E_I, tr("&Increase Indentation"), QKeySequence(Key_Tab));
    E_I_D = new TpGeneralAction(E_I, tr("&Decrease Indentation"), QKeySequence(Key_Backtab));
    E_L = new TpGeneralMenu(E, tr("&Line Operations"));
    E_L_D = new TpGeneralAction(E_L, tr("&Delete"), QKeySequence(CTRL | SHIFT | Key_L));
    E_L_C = new TpGeneralAction(E_L, tr("&Cut"), QKeySequence(CTRL | Key_L));
    E_L_O = new TpGeneralAction(E_L, tr("C&opy"), QKeySequence(CTRL | SHIFT | Key_T));
    E_L_T = new TpGeneralAction(E_L, tr("&Transpose"), QKeySequence(CTRL | Key_T));
    E_L->addSeparator();
    E_L_U = new TpGeneralAction(E_L, tr("Move &Up"));
    E_L_W = new TpGeneralAction(E_L, tr("Move Do&wn"));
    E_A = new TpGeneralMenu(E, tr("Duplic&ation Operations"));
    E_A_L = new TpGeneralAction(E_A, tr("&Line"));
    E_A_S = new TpGeneralAction(E_A, tr("&Selection"), QKeySequence(CTRL | Key_D));
    E->addSeparator();
    E_G = new TpGeneralAction(E, tr("To&ggle Overtype"), QKeySequence(Key_Insert), false, true, false);
    E->addSeparator();
    E_E = new TpGeneralMenu(E, tr("S&earch"));
    E_E_F = new TpGeneralAction(E_E, tr("&Find..."), QKeySequence(CTRL | SHIFT | Key_Find));
    E_E_I = new TpGeneralAction(E_E, tr("Find &In Files..."));
    E_E_N = new TpGeneralAction(E_E, tr("Find &Next..."), FindNext);
    E_E_P = new TpGeneralAction(E_E, tr("Find &Previous"), FindPrevious);
    E_E_X = new TpGeneralAction(E_E, tr("Find Ne&xt Using Selection..."));
    E_E_U = new TpGeneralAction(E_E, tr("Find Previous &Using Selection..."));
    E_E_L = new TpGeneralAction(E_E, tr("&Light Search..."), Find);
    E_E_G = new TpGeneralAction(E_E, tr("&Go To..."), QKeySequence(CTRL | Key_G));
    E_E_M = new TpGeneralAction(E_E, tr("Go To &Matching Brace"), QKeySequence(CTRL | SHIFT | Key_G));
    E_E_S = new TpGeneralAction(E_E, tr("&Select To Matching Brace"), QKeySequence(CTRL | SHIFT | ALT | Key_G));
    E_B = new TpGeneralMenu(E, tr("&Bookmarks"));
    E_B_T = new TpGeneralAction(E_B, tr("&Toggle"), QKeySequence(CTRL | Key_F2), false, true, false);
    E_B_N = new TpGeneralAction(E_B, tr("&Next"), QKeySequence(SHIFT | Key_F2));
    E_B_P = new TpGeneralAction(E_B, tr("&Previous"), QKeySequence(SHIFT | ALT | Key_F2));
    E_B_C = new TpGeneralAction(E_B, tr("&Cut All Bookmarked Lines"));
    E_B_O = new TpGeneralAction(E_B, tr("C&opy All Bookmarked Lines"));
    E_B_R = new TpGeneralAction(E_B, tr("&Remove All Bookmarks"));
    E_B_A = new TpGeneralAction(E_B, tr("Remove &All Bookmarked Lines"));
    E_B_h = new TpGeneralAction(E_B, tr("Remove All Non&-bookmarked Lines"));
    E_B_I = new TpGeneralAction(E_B, tr("&Inverse"));
    V = new TpGeneralMenu(this, tr("&View"));
    V_A = new TpGeneralAction(V, tr("&Always-on-top Mode"), QKeySequence(), true, true, false);
    V_F = new TpGeneralAction(V, tr("&Full Screen Mode"), FullScreen, true, true, false);
    V_h = new TpGeneralAction(V, tr("Post&-it Mode"), QKeySequence(), true, true, false);
    V->addSeparator();
    V_Y = new TpGeneralMenu(V, tr("Show S&ymbol"));
    V_Y_S = new TpGeneralAction(V_Y, tr("&Spaces and Tabs (All)"), QKeySequence(), false, true, false);
    V_Y_A = new TpGeneralAction(V_Y, tr("Spaces &and Tabs (After Indentation)"), QKeySequence(), false, true, false);
    V_Y_T = new TpGeneralAction(V_Y, tr("Spaces and &Tabs (In Indentation)"), QKeySequence(), false, true, false);
    V_Y_N = new TpGeneralAction(V_Y, tr("&Non-printable"), QKeySequence(), false, true, false);
    V_Y->addSeparator();
    V_Y_W = new TpGeneralAction(V_Y, tr("&Wrap Visual Flags"), QKeySequence(), false, true, false);
    V_Y_I = new TpGeneralAction(V_Y, tr("&Indentation Guides"), QKeySequence(), false, true, false);
    V_Z = new TpGeneralMenu(V, tr("&Zoom"));
    V_Z_I = new TpGeneralAction(V_Z, tr("Zoom &In"), ZoomIn);
    V_Z_O = new TpGeneralAction(V_Z, tr("Zoom &Out"), ZoomOut);
    V_Z->addSeparator();
    V_Z_T = new TpGeneralAction(V_Z, tr("&To 100%"), QKeySequence(CTRL | SHIFT | Key_0));
    V_T = new TpGeneralMenu(V, tr("&Tabs"));
    V_T_1 = new TpGeneralAction(V_T, tr("To Tab &1"), QKeySequence(CTRL | Key_1));
    V_T_2 = new TpGeneralAction(V_T, tr("To Tab &2"), QKeySequence(CTRL | Key_2));
    V_T_3 = new TpGeneralAction(V_T, tr("To Tab &3"), QKeySequence(CTRL | Key_3));
    V_T_4 = new TpGeneralAction(V_T, tr("To Tab &4"), QKeySequence(CTRL | Key_4));
    V_T_5 = new TpGeneralAction(V_T, tr("To Tab &5"), QKeySequence(CTRL | Key_5));
    V_T_6 = new TpGeneralAction(V_T, tr("To Tab &6"), QKeySequence(CTRL | Key_6));
    V_T_7 = new TpGeneralAction(V_T, tr("To Tab &7"), QKeySequence(CTRL | Key_7));
    V_T_8 = new TpGeneralAction(V_T, tr("To Tab &8"), QKeySequence(CTRL | Key_8));
    V_T_9 = new TpGeneralAction(V_T, tr("To Tab &9"), QKeySequence(CTRL | Key_9));
    V_T_0 = new TpGeneralAction(V_T, tr("To Tab 1&0"), QKeySequence(CTRL | Key_0));
    V_T->addSeparator();
    V_T_L = new TpGeneralAction(V_T, tr("To The &Last"));
    V_T_N = new TpGeneralAction(V_T, tr("To The &Next"), NextChild);
    V_T_F = new TpGeneralAction(V_T, tr("To The &First"));
    V_T_P = new TpGeneralAction(V_T, tr("To The &Previous"), PreviousChild);
    V_T->addSeparator();
    V_T_M = new TpGeneralAction(V_T, tr("&Move To Left"));
    V_T_R = new TpGeneralAction(V_T, tr("Move To &Right"));
    V_T_S = new TpGeneralAction(V_T, tr("Move To The &Start"));
    V_T_T = new TpGeneralAction(V_T, tr("Move To &The Last"));
    V_W = new TpGeneralMenu(V, tr("&Word Wrap"));
    V_W_N = new TpGeneralAction(V_W, tr("&None"), QKeySequence(), false, true, false);
    V_W_W = new TpGeneralAction(V_W, tr("&Word"), QKeySequence(), false, true, false);
    V_W_C = new TpGeneralAction(V_W, tr("&Character"), QKeySequence(), false, true, false);
    V_W_H = new TpGeneralAction(V_W, tr("W&hitespace"), QKeySequence(), false, true, false);
    V_L = new TpGeneralMenu(V, "Sp&lit Views");
    V_L_M = new TpGeneralAction(V_L, tr("&Move To Next View"), QKeySequence(CTRL | Key_F6));
    // V_L_T = new TpGeneralAction(V_L, tr("Move &To Previous View"), QKeySequence(CTRL | SHIFT | Key_F6));
    // V_L->addSeparator();
    // V_L_C = new TpGeneralAction(V_L, tr("&Clone To Next View"));
    V_I = new TpGeneralAction(V, tr("Show L&ine Numbers"), QKeySequence(), false, true, false);
    V->addSeparator();
    V_C = new TpGeneralMenu(V, tr("S&crolling Operations"));
    V_C_D = new TpGeneralAction(V_C, tr("Line &Down"));
    V_C_U = new TpGeneralAction(V_C, tr("Line &Up"));
    V_C_S = new TpGeneralAction(V_C, tr("To &Start"));
    V_C_E = new TpGeneralAction(V_C, tr("To &End"));
    V_C_V = new TpGeneralAction(V_C, tr("To &Vertical Central Caret"));
    V_O = new TpGeneralMenu(V, tr("Folding &Operations"));
    V_O_H = new TpGeneralAction(V_O, tr("Fold &Here"));
    V_O_A = new TpGeneralAction(V_O, tr("Fold &All"));
    V_O_C = new TpGeneralAction(V_O, tr("Fold All (Including &Children)"));
    V_O_E = new TpGeneralAction(V_O, tr("&Expand All"));
    V_O->addSeparator();
    V_O_S = new TpGeneralMenu(V_O, tr("&Style"));
    V_O_S_D = new TpGeneralAction(V_O_S, tr("&Disable Folding"), QKeySequence(), false, true, false);
    V_O_S_P = new TpGeneralAction(V_O_S, tr("&Plain"), QKeySequence(), false, true, false);
    V_O_S_C = new TpGeneralAction(V_O_S, tr("&Circled"), QKeySequence(), false, true, false);
    V_O_S_B = new TpGeneralAction(V_O_S, tr("&Boxed"), QKeySequence(), false, true, false);
    V_O_S_T = new TpGeneralAction(V_O_S, tr("Circled &Tree"), QKeySequence(), false, true, false);
    V_O_S_X = new TpGeneralAction(V_O_S, tr("Bo&xed Tree"), QKeySequence(), false, true, false);
    I = new TpGeneralMenu(this, tr("&Insert"));
    I_F = new TpGeneralAction(I, tr("&Formfeed"));
    I_T = new TpGeneralAction(I, tr("&Tab"));
    I_V = new TpGeneralAction(I, tr("&Vertical Tab"));
    I->addSeparator();
    I_N = new TpGeneralMenu(I, tr("&Newlines"));
    I_N_W = new TpGeneralAction(I_N, tr("&Windows"));
    I_N_M = new TpGeneralAction(I_N, tr("Classical &Mac"));
    I_N_U = new TpGeneralAction(I_N, tr("&Unix"));
    I_D = new TpGeneralMenu(I, tr("&Date and Time"));
    I_D_D = new TpGeneralAction(I_D, tr("&Date"));
    I_D_T = new TpGeneralAction(I_D, tr("&Time"));
    I_D_A = new TpGeneralAction(I_D, tr("Date &and Time"));
    I->addSeparator();
    I_O = new TpGeneralAction(I, tr("&Ohter Special Characters..."));
    O = new TpGeneralMenu(this, tr("F&ormat"));
    O_L = new TpGeneralMenu(O, tr("&Languages"));
    O_L_p = new TpGeneralAction(O_L, tr("None &(Nothing Applied)"), QKeySequence(), false, true, true);
    O_L->addSeparator();
    O_L_A = new TpGeneralMenu(O_L, tr("&A"));
    O_L_A_C = new TpGeneralAction(O_L_A, tr("A&ctionScript"), QKeySequence(), false, true, false);
    O_L_A_S = new TpGeneralAction(O_L_A, tr("A&SP"), QKeySequence(), false, true, false);
    O_L_A_A = new TpGeneralAction(O_L_A, tr("&AviSynth"), QKeySequence(), false, true, false);
    O_L_B = new TpGeneralMenu(O_L, tr("&B"));
    O_L_B_B = new TpGeneralAction(O_L_B, tr("&Bash"), QKeySequence(), false, true, false);
    O_L_B_T = new TpGeneralAction(O_L_B, tr("Ba&tch"), QKeySequence(), false, true, false);
    O_L_B_S = new TpGeneralAction(O_L_B, tr("BA&SIC (BlitzBasic)"), QKeySequence(), false, true, false);
    O_L_B_A = new TpGeneralAction(O_L_B, tr("B&ASIC (PureBasic)"), QKeySequence(), false, true, false);
    O_L_B_F = new TpGeneralAction(O_L_B, tr("BASIC (&FreeBasic)"), QKeySequence(), false, true, false);
    O_L_C = new TpGeneralMenu(O_L, tr("&C"));
    O_L_C_C = new TpGeneralAction(O_L_C, tr("&C"), QKeySequence(), false, true, false);
    O_L_C_pl = new TpGeneralAction(O_L_C, tr("C&++"), QKeySequence(), false, true, false);
    O_L_C_p = new TpGeneralAction(O_L_C, tr("C++ &(Qt)"), QKeySequence(), false, true, false);
    O_L_C_s = new TpGeneralAction(O_L_C, tr("C&#"), QKeySequence(), false, true, false);
    O_L_C_M = new TpGeneralAction(O_L_C, tr("C&Make"), QKeySequence(), false, true, false);
    O_L_C_O = new TpGeneralAction(O_L_C, tr("C&offeeScript"), QKeySequence(), false, true, false);
    O_L_C_S = new TpGeneralAction(O_L_C, tr("C&SS"), QKeySequence(), false, true, false);
    O_L_D = new TpGeneralMenu(O_L, tr("&D"));
    O_L_D_D = new TpGeneralAction(O_L_D, tr("&D"), QKeySequence(), false, true, false);
    O_L_D_I = new TpGeneralAction(O_L_D, tr("D&iff"), QKeySequence(), false, true, false);
    O_L_F = new TpGeneralMenu(O_L, tr("&F"));
    O_L_F_F = new TpGeneralAction(O_L_F, tr("&Fortran (Free Format)"), QKeySequence(), false, true, false);
    O_L_F_7 = new TpGeneralAction(O_L_F, tr("Fortran &77 (Fixed Format)"), QKeySequence(), false, true, false);
    O_L_G = new TpGeneralMenu(O_L, tr("&G"));
    O_L_G_G = new TpGeneralAction(O_L_G, tr("&GDScript"), QKeySequence(), false, true, false);
    O_L_H = new TpGeneralMenu(O_L, tr("&H"));
    O_L_H_H = new TpGeneralAction(O_L_H, tr("&HTML"), QKeySequence(), false, true, false);
    O_L_H_T = new TpGeneralAction(O_L_H, tr("H&TML (Full)"), QKeySequence(), false, true, false);
    O_L_I = new TpGeneralMenu(O_L, tr("&I"));
    O_L_I_I = new TpGeneralAction(O_L_I, tr("&IDL"), QKeySequence(), false, true, false);
    O_L_I_H = new TpGeneralAction(O_L_I, tr("Intel &Hex"), QKeySequence(), false, true, false);
    O_L_J = new TpGeneralMenu(O_L, tr("&J"));
    O_L_J_J = new TpGeneralAction(O_L_J, tr("&Java"), QKeySequence(), false, true, false);
    O_L_J_S = new TpGeneralAction(O_L_J, tr("Java&Script"), QKeySequence(), false, true, false);
    O_L_J_O = new TpGeneralAction(O_L_J, tr("JS&ON"), QKeySequence(), false, true, false);
    O_L_L = new TpGeneralMenu(O_L, tr("&L"));
    O_L_L_T = new TpGeneralAction(O_L_L, tr("La&TeX"), QKeySequence(), false, true, false);
    O_L_L_L = new TpGeneralAction(O_L_L, tr("&Lua"), QKeySequence(), false, true, false);
    O_L_M = new TpGeneralMenu(O_L, tr("&M"));
    O_L_M_F = new TpGeneralAction(O_L_M, tr("Make&file"), QKeySequence(), false, true, false);
    O_L_M_D = new TpGeneralAction(O_L_M, tr("Mark&down"), QKeySequence(), false, true, false);
    O_L_M_M = new TpGeneralAction(O_L_M, tr("&MASM"), QKeySequence(), false, true, false);
    O_L_M_L = new TpGeneralAction(O_L_M, tr("Mat&lab"), QKeySequence(), false, true, false);
    O_L_N = new TpGeneralMenu(O_L, tr("&N"));
    O_L_N_N = new TpGeneralAction(O_L_N, tr("&NASM"), QKeySequence(), false, true, false);
    O_L_O = new TpGeneralMenu(O_L, tr("&O"));
    O_L_O_O = new TpGeneralAction(O_L_O, tr("&Octave"), QKeySequence(), false, true, false);
    O_L_P = new TpGeneralMenu(O_L, tr("&P"));
    O_L_P_P = new TpGeneralAction(O_L_P, tr("&Pascal"), QKeySequence(), false, true, false);
    O_L_P_E = new TpGeneralAction(O_L_P, tr("P&erl"), QKeySequence(), false, true, false);
    O_L_P_H = new TpGeneralAction(O_L_P, tr("P&HP"), QKeySequence(), false, true, false);
    O_L_P_O = new TpGeneralAction(O_L_P, tr("P&O"), QKeySequence(), false, true, false);
    O_L_P_S = new TpGeneralAction(O_L_P, tr("Post&Script"), QKeySequence(), false, true, false);
    O_L_P_V = new TpGeneralAction(O_L_P, tr("PO&V"), QKeySequence(), false, true, false);
    O_L_P_R = new TpGeneralAction(O_L_P, tr("P&roperties"), QKeySequence(), false, true, false);
    O_L_P_2 = new TpGeneralAction(O_L_P, tr("Python &2"), QKeySequence(), false, true, false);
    O_L_P_3 = new TpGeneralAction(O_L_P, tr("Python &3"), QKeySequence(), false, true, false);
    O_L_P_X = new TpGeneralAction(O_L_P, tr("Python 3 (E&xtended)"), QKeySequence(), false, true, false);
    O_L_Q = new TpGeneralMenu(O_L, tr("&Q"));
    O_L_Q_Q = new TpGeneralAction(O_L_Q, tr("&QML"), QKeySequence(), false, true, false);
    O_L_Q_S = new TpGeneralAction(O_L_Q, tr("Q&SS"), QKeySequence(), false, true, false);
    O_L_Q_U = new TpGeneralAction(O_L_Q, tr("Q&UI"), QKeySequence(), false, true, false);
    O_L_R = new TpGeneralMenu(O_L, tr("&R"));
    O_L_R_R = new TpGeneralAction(O_L_R, tr("&Ruby"), QKeySequence(), false, true, false);
    O_L_S = new TpGeneralMenu(O_L, tr("&S"));
    O_L_S_S = new TpGeneralAction(O_L_S, tr("&Spice"), QKeySequence(), false, true, false);
    O_L_S_Q = new TpGeneralAction(O_L_S, tr("S&QL"), QKeySequence(), false, true, false);
    O_L_S_R = new TpGeneralAction(O_L_S, tr("S-&Record"), QKeySequence(), false, true, false);
    O_L_T = new TpGeneralMenu(O_L, tr("&T"));
    O_L_T_T = new TpGeneralAction(O_L_T, tr("&TCL"), QKeySequence(), false, true, false);
    O_L_T_H = new TpGeneralAction(O_L_T, tr("Tektronix &Hex"), QKeySequence(), false, true, false);
    O_L_T_X = new TpGeneralAction(O_L_T, tr("Te&X"), QKeySequence(), false, true, false);
    O_L_V = new TpGeneralMenu(O_L, tr("&V"));
    O_L_V_V = new TpGeneralAction(O_L_V, tr("&Verilog"), QKeySequence(), false, true, false);
    O_L_V_H = new TpGeneralAction(O_L_V, tr("V&HDL"), QKeySequence(), false, true, false);
    O_L_X = new TpGeneralMenu(O_L, tr("&X"));
    O_L_X_X = new TpGeneralAction(O_L_X, tr("&XML"), QKeySequence(), false, true, false);
    O_L_Y = new TpGeneralMenu(O_L, tr("&Y"));
    O_L_Y_Y = new TpGeneralAction(O_L_Y, tr("&YAML"), QKeySequence(), false, true, false);
    O_N = new TpGeneralMenu(O, tr("&Newline Conversion"));
    O_N_U = new TpGeneralAction(O_N, tr("&Use Windows"), QKeySequence(), false, true, false);
    O_N_C = new TpGeneralAction(O_N, tr("Use &Classical Mac"), QKeySequence(), false, true, false);
    O_N_E = new TpGeneralAction(O_N, tr("Us&e Unix"), QKeySequence(), false, true, false);
    O_N->addSeparator();
    O_N_T = new TpGeneralAction(O_N, tr("Convert &To Windows"));
    O_N_M = new TpGeneralAction(O_N, tr("Convert To Classical &Mac"));
    O_N_X = new TpGeneralAction(O_N, tr("Convert To Uni&x"));
    O->addSeparator();
    O_I = new TpGeneralMenu(O, tr("&Indentation Configuration"));
    O_I_T = new TpGeneralAction(O_I, tr("Use &Tabs To Indent"), QKeySequence(), false, true, false);
    O_I_B = new TpGeneralAction(O_I, tr("&Backspace Unindents"), QKeySequence(), false, true, false);
    O_I_I = new TpGeneralAction(O_I, tr("Tab To &Indent"), QKeySequence(), false, true, false);
    O_R = new TpGeneralMenu(O, tr("&Representing Tabs"));
    O_R_L = new TpGeneralAction(O_R, tr("&Long Arrow"), QKeySequence(), false, true, false);
    O_R_S = new TpGeneralAction(O_R, tr("&Strike Out"), QKeySequence(), false, true, false);
    O_S = new TpGeneralAction(O, tr("&Select First Wrapped Line Only"), QKeySequence(), false, true, false);
    O_h = new TpGeneralAction(O, tr("Read&-only"), QKeySequence(), false, true, false);
    O->addSeparator();
    O_A = new TpGeneralMenu(O, tr("C&ase Conversion"));
    O_A_U = new TpGeneralAction(O_A, tr("UPPERCASE"), QKeySequence(CTRL | SHIFT | Key_U));
    O_A_L = new TpGeneralAction(O_A, tr("&lowercase"), QKeySequence(CTRL | Key_U));
    T = new TpGeneralMenu(this, tr("&Tools"));
    // T_P = new TpGeneralAction(T, tr("&Preferences..."), QKeySequence(CTRL | Key_Comma), true);
    // T->addSeparator();
    T_A = new TpGeneralMenu(T, tr("&Autocompletion"));
    T_A_C = new TpGeneralAction(T_A, tr("&Case Sensitive"), QKeySequence(), false, true, false);
    T_A_F = new TpGeneralAction(T_A, tr("&Fill-ups Enabled"), QKeySequence(), false, true, false);
    T_A_R = new TpGeneralAction(T_A, tr("&Replace Word"), QKeySequence(), false, true, false);
    T_A->addSeparator();
    T_A_W = new TpGeneralMenu(T_A, tr("&When Single Entry"));
    T_A_W_N = new TpGeneralAction(T_A_W, tr("Do &Not Display"), QKeySequence(), false, true, false);
    T_A_W_O = new TpGeneralAction(T_A_W, tr("&Only Manually"), QKeySequence(), false, true, false);
    T_A_W_D = new TpGeneralAction(T_A_W, tr("Always &Display"), QKeySequence(), false, true, false);
    T_A->addSeparator();
    T_A_S = new TpGeneralMenu(T_A, tr("&Sources"));
    T_A_S_D = new TpGeneralAction(T_A_S, tr("&Do Not Display Autocompletion"), QKeySequence(), false, true, false);
    T_A_S_A = new TpGeneralAction(T_A_S, tr("&All"), QKeySequence(), false, true, false);
    T_A_S_O = new TpGeneralAction(T_A_S, tr("D&ocument"), QKeySequence(), false, true, false);
    T_A_S_L = new TpGeneralAction(T_A_S, tr("&Lexer"), QKeySequence(), false, true, false);
    T_A_T = new TpGeneralMenu(T_A, tr("&Trigger Now"));
    T_A_T_A = new TpGeneralAction(T_A_T, tr("From &All Sources"));
    T_A_T_D = new TpGeneralAction(T_A_T, tr("From &Document"));
    T_A_T_L = new TpGeneralAction(T_A_T, tr("From &Lexer"));
    T_h = new TpGeneralMenu(T, tr("Auto&-indentation"));
    T_h_A = new TpGeneralAction(T_h, tr("&Auto-indentation"), QKeySequence(), false, true, false);
    T_h->addSeparator();
    T_h_S = new TpGeneralMenu(T_h, tr("&Style"));
    T_h_S_A = new TpGeneralAction(T_h_S, tr("&Auto"), QKeySequence(), false, true, false);
    T_h_S->addSeparator();
    T_h_S_M = new TpGeneralAction(T_h_S, tr("&Maintain"), QKeySequence(), false, true, false);
    T_h_S_O = new TpGeneralAction(T_h_S, tr("&Opening"), QKeySequence(), false, true, false);
    T_h_S_C = new TpGeneralAction(T_h_S, tr("&Closing"), QKeySequence(), false, true, false);
    T_B = new TpGeneralMenu(T, tr("&Brace Matching"));
    T_B_N = new TpGeneralAction(T_B, tr("&No Brace Matching"), QKeySequence(), false, true, false);
    T_B_S = new TpGeneralAction(T_B, tr("&Sloppy Brace Match"), QKeySequence(), false, true, false);
    T_B_B = new TpGeneralAction(T_B, tr("Strict &Brace Match"), QKeySequence(), false, true, false);
    T_C = new TpGeneralMenu(T, tr("&Call Tips"));
    T_C_T = new TpGeneralAction(T_C, tr("&Trigger Immediately"));
    T_C->addSeparator();
    T_C_P = new TpGeneralMenu(T_C, tr("&Position"));
    T_C_P_B = new TpGeneralAction(T_C_P, tr("&Below Text"), QKeySequence(), false, true, false);
    T_C_P_A = new TpGeneralAction(T_C_P, tr("&Above Text"), QKeySequence(), false, true, false);
    T_C_S = new TpGeneralMenu(T_C, tr("&Style"));
    T_C_S_D = new TpGeneralAction(T_C_S, tr("&Disable Call Tips"), QKeySequence(), false, true, false);
    T_C_S_N = new TpGeneralAction(T_C_S, tr("&No Context or Scope"), QKeySequence(), false, true, false);
    T_C_S_A = new TpGeneralAction(T_C_S, tr("No &AutoCompletion Context"), QKeySequence(), false, true, false);
    T_C_S_W = new TpGeneralAction(T_C_S, tr("&With All Context"), QKeySequence(), false, true, false);
    T_E = new TpGeneralMenu(T, tr("&Edge Mode"));
    T_E_N = new TpGeneralAction(T_E, tr("&None"), QKeySequence(), false, true, false);
    T_E_L = new TpGeneralAction(T_E, tr("&Line"), QKeySequence(), false, true, false);
    T_E_B = new TpGeneralAction(T_E, tr("&Background"), QKeySequence(), false, true, false);
    T_V = new TpGeneralMenu(T, tr("Caret and &Virtual Selection"));
    T_V_S = new TpGeneralAction(T_V, tr("&Selection Till Border"), QKeySequence(), false, true, false);
    T_V_M = new TpGeneralAction(T_V, tr("&Multiple Selection Typing"), QKeySequence(), false, true, false);
    T_V_A = new TpGeneralAction(T_V, tr("&Additional Selection Typing"), QKeySequence(), false, true, false);
    T_V_P = new TpGeneralAction(T_V, tr("Multiple &Paste"), QKeySequence(), false, true, false);
    T_V->addSeparator();
    T_V_V = new TpGeneralMenu(T_V, tr("&Virtual Space"));
    T_V_V_D = new TpGeneralAction(T_V_V, tr("&Disabled"), QKeySequence(), false, true, false);
    T_V_V_R = new TpGeneralAction(T_V_V, tr("On &Rectangular Selections"), QKeySequence(), false, true, false);
    T_V_V_U = new TpGeneralAction(T_V_V, tr("&Users Accessible"), QKeySequence(), false, true, false);
    T_V_V_W = new TpGeneralAction(T_V_V, tr("No &Wrap Line Start"), QKeySequence(), false, true, false);
    T_V_R = new TpGeneralMenu(T_V, tr("&Rectangular Selection Modifier"));
    T_V_R_C = new TpGeneralAction(T_V_R, tr("&Control Key (CTRL)"), QKeySequence(), false, true, false);
    T_V_R_A = new TpGeneralAction(T_V_R, tr("&Alternate Key (ALT)"), QKeySequence(), false, true, false);
    T_V->addSeparator();
    T_V_C = new TpGeneralMenu(T_V, tr("&Caret Sticky"));
    T_V_C_O = new TpGeneralAction(T_V_C, tr("&Off"), QKeySequence(), false, true, false);
    T_V_C_N = new TpGeneralAction(T_V_C, tr("O&n"), QKeySequence(), false, true, false);
    T_V_C_W = new TpGeneralAction(T_V_C, tr("&With Whitespaces Only"), QKeySequence(), false, true, false);
    T_V_L = new TpGeneralAction(T_V, tr("Caret &Line Visible"), QKeySequence(), false, true, false);
    T_S = new TpGeneralMenu(T, tr("&Search Tools"));
    T_S_R = new TpGeneralMenu(T_S, tr("&Regular Expression"));
    T_S_R_N = new TpGeneralAction(T_S_R, tr("&No"), QKeySequence(), false, true, false);
    T_S_R_S = new TpGeneralAction(T_S_R, tr("&Simple"), QKeySequence(), false, true, false);
    T_S_R_P = new TpGeneralAction(T_S_R, tr("&POSIX"), QKeySequence(), false, true, false);
    T_S_R_pl = new TpGeneralAction(T_S_R, tr("C&++"), QKeySequence(), false, true, false);
    T_S_C = new TpGeneralAction(T_S, tr("&Case-sensitive"), QKeySequence(), false, true, false);
    T_S_O = new TpGeneralAction(T_S, tr("Whole Word &Only"), QKeySequence(), false, true, false);
    T_S_W = new TpGeneralAction(T_S, tr("&Word Wrap"), QKeySequence(), false, true, false);
    T_S_S = new TpGeneralAction(T_S, tr("&Show"), QKeySequence(), false, true, false);
    T_S_G = new TpGeneralAction(T_S, tr("&Go Previous"), QKeySequence(), false, true, false);
    T_W = new TpGeneralMenu(T, tr("&Wrapping Tools"));
    T_W_I = new TpGeneralMenu(T_W, tr("&Indentation"));
    T_W_I_P = new TpGeneralAction(T_W_I, tr("&Predefined"), QKeySequence(), false, true, false);
    T_W_I_S = new TpGeneralAction(T_W_I, tr("&Same as First Sub-line"), QKeySequence(), false, true, false);
    T_W_I_I = new TpGeneralAction(T_W_I, tr("&Indented"), QKeySequence(), false, true, false);
    T_W_I_D = new TpGeneralAction(T_W_I, tr("&Double-indented"), QKeySequence(), false, true, false);
    T_W->addSeparator();
    T_W_S = new TpGeneralMenu(T_W, tr("&Start Flag"));
    T_W_S_N = new TpGeneralAction(T_W_S, tr("&None"), QKeySequence(), false, true, false);
    T_W_S_T = new TpGeneralAction(T_W_S, tr("By &Text"), QKeySequence(), false, true, false);
    T_W_S_B = new TpGeneralAction(T_W_S, tr("By &Border"), QKeySequence(), false, true, false);
    T_W_S_M = new TpGeneralAction(T_W_S, tr("In &Margin"), QKeySequence(), false, true, false);
    T_W_E = new TpGeneralMenu(T_W, tr("&End Flag"));
    T_W_E_N = new TpGeneralAction(T_W_E, tr("&None"), QKeySequence(), false, true, false);
    T_W_E_T = new TpGeneralAction(T_W_E, tr("By &Text"), QKeySequence(), false, true, false);
    T_W_E_B = new TpGeneralAction(T_W_E, tr("By &Border"), QKeySequence(), false, true, false);
    T_W_E_M = new TpGeneralAction(T_W_E, tr("In &Margin"), QKeySequence(), false, true, false);
    T->addSeparator();
    T_M = new TpGeneralMenu(T, tr("&Miscellaneous"));
    T_M_B = new TpGeneralAction(T_M, tr("&Buffered Draw"), QKeySequence(), false, true, false);
    T_M_P = new TpGeneralMenu(T_M, tr("&Phases Draw"));
    T_M_P_O = new TpGeneralAction(T_M_P, tr("Phase &One"), QKeySequence(), false, true, false);
    T_M_P_T = new TpGeneralAction(T_M_P, tr("Phase &Two"), QKeySequence(), false, true, false);
    T_M_P_M = new TpGeneralAction(T_M_P, tr("Phase &Multiple"), QKeySequence(), false, true, false);
    T_M->addSeparator();
    T_M_Q = new TpGeneralMenu(T_M, tr("Font &Quality"));
    T_M_Q_D = new TpGeneralAction(T_M_Q, tr("&Default"), QKeySequence(), false, true, false);
    T_M_Q_N = new TpGeneralAction(T_M_Q, tr("&Non-antialized"), QKeySequence(), false, true, false);
    T_M_Q_A = new TpGeneralAction(T_M_Q, tr("&Antialized"), QKeySequence(), false, true, false);
    T_M_Q_L = new TpGeneralAction(T_M_Q, tr("&LCD Optimized"), QKeySequence(), false, true, false);
    W = new TpGeneralMenu(this, tr("&Windows"));
    W_F = new TpGeneralAction(W, tr("&File Browser"), QKeySequence(), true, true, false);
    W_L = new TpGeneralAction(W, tr("Document &List"), QKeySequence(), true, true, false);
    W_B = new TpGeneralAction(W, tr("&Bookmark"), QKeySequence(), false, true, false);
    W_D = new TpGeneralAction(W, tr("Find &Dock"), QKeySequence(), false, true, false);
    W_I = new TpGeneralAction(W, tr("Find &In Files Dock"), QKeySequence(), true, true, false);
    // W_Q = new TpGeneralAction(W, tr("&QSS Viewer"), QKeySequence(), false, true, false);

    ag_ShowSpacesAndTabs = new TpGeneralActionGroup(this,
        {V_Y_S, V_Y_A, V_Y_T}
    );
    ag_ShowSpacesAndTabs->setExclusionPolicy(TpGeneralActionGroup::ExclusionPolicy::ExclusiveOptional);

    ag_WordWrap = new TpGeneralActionGroup(this,
        {V_W_N, V_W_W, V_W_C, V_W_H}
    );

    ag_FoldingStyle = new TpGeneralActionGroup(this,
        {V_O_S_D, V_O_S_P, V_O_S_C, V_O_S_B, V_O_S_T, V_O_S_X}
    );

    ag_Languages = new TpGeneralActionGroup(this,
        {O_L_A_C, O_L_A_S, O_L_A_A, O_L_B_B, O_L_B_T, O_L_B_S, O_L_B_A, O_L_B_F, O_L_C_C, O_L_C_p, O_L_C_pl, O_L_C_s,
         O_L_C_M, O_L_C_O, O_L_C_S, O_L_D_D, O_L_D_I, O_L_F_F, O_L_F_7, O_L_H_H, O_L_H_T, O_L_I_I, O_L_I_H, O_L_J_J,
         O_L_J_S, O_L_J_O, O_L_L_T, O_L_L_L, O_L_M_F, O_L_M_D, O_L_M_M, O_L_M_L, O_L_N_N, O_L_O_O, O_L_P_P, O_L_P_E,
         O_L_P_H, O_L_P_O, O_L_P_S, O_L_P_V, O_L_P_R, O_L_P_2, O_L_P_3, O_L_P_X, O_L_Q_Q, O_L_Q_S, O_L_R_R, O_L_S_S,
         O_L_S_Q, O_L_S_R, O_L_T_T, O_L_T_H, O_L_T_X, O_L_V_V, O_L_V_H, O_L_X_X, O_L_Y_Y, O_L_p,
         O_L_G_G, O_L_Q_U}
    );

    ag_Newline = new TpGeneralActionGroup(this,
        {O_N_U, O_N_C, O_N_E}
    );

    ag_RepresentingTabs = new TpGeneralActionGroup(this,
        {O_R_L, O_R_S}
    );

    ag_AutocompletionWhenSingleEntry = new TpGeneralActionGroup(this,
        {T_A_W_N, T_A_W_O, T_A_W_D}
    );

    ag_AutocompletionSource = new TpGeneralActionGroup(this,
        {T_A_S_D, T_A_S_A, T_A_S_O, T_A_S_L}
    );

    ag_BraceMatching = new TpGeneralActionGroup(this,
        {T_B_N, T_B_S, T_B_B}
    );

    ag_CallTipsPosition = new TpGeneralActionGroup(this,
        {T_C_P_B, T_C_P_A}
    );

    ag_CallTipsStyle = new TpGeneralActionGroup(this,
        {T_C_S_D, T_C_S_N, T_C_S_A, T_C_S_W}
    );

    ag_EdgeMode = new TpGeneralActionGroup(this,
        {T_E_N, T_E_L, T_E_B}
    );

    ag_VirtualSpace = new TpGeneralActionGroup(this,
        {T_V_V_D, T_V_V_R, T_V_V_U, T_V_V_W}
    );

    ag_RectangularSelectionModifier = new TpGeneralActionGroup(this,
        {T_V_R_C, T_V_R_A}
    );

    ag_CaretSticky = new TpGeneralActionGroup(this,
        {T_V_C_O, T_V_C_N, T_V_C_W}
    );

    ag_SearchRegex = new TpGeneralActionGroup(this,
        {T_S_R_N, T_S_R_S, T_S_R_P, T_S_R_pl}
    );

    ag_WrapIndentation = new TpGeneralActionGroup(this,
        {T_W_I_P, T_W_I_S, T_W_I_I, T_W_I_D}
    );

    ag_WrapStartFlag = new TpGeneralActionGroup(this,
        {T_W_S_N, T_W_S_T, T_W_S_B, T_W_S_M}
    );

    ag_WrapEndFlag = new TpGeneralActionGroup(this,
        {T_W_E_N, T_W_E_T, T_W_E_B, T_W_E_M}
    );

    ag_PhraseDraw = new TpGeneralActionGroup(this,
        {T_M_P_O, T_M_P_T, T_M_P_M}
    );

    ag_FontQuality = new TpGeneralActionGroup(this,
        {T_M_Q_D, T_M_Q_N, T_M_Q_A, T_M_Q_L}
    );
}

#if QT_VERSION_MAJOR <= 5
#undef UnknownKey
#undef HelpContents
#undef WhatsThis
#undef Open
#undef Close
#undef Save
#undef New
#undef Delete
#undef Cut
#undef Copy
#undef Paste
#undef Undo
#undef Redo
#undef Back
#undef Forward
#undef Refresh
#undef ZoomIn
#undef ZoomOut
#undef Print
#undef AddTab
#undef NextChild
#undef PreviousChild
#undef Find
#undef FindNext
#undef FindPrevious
#undef Replace
#undef SelectAll
#undef Bold
#undef Italic
#undef Underline
#undef MoveToNextChar
#undef MoveToPreviousChar
#undef MoveToNextWord
#undef MoveToPreviousWord
#undef MoveToNextLine
#undef MoveToPreviousLine
#undef MoveToNextPage
#undef MoveToPreviousPage
#undef MoveToStartOfLine
#undef MoveToEndOfLine
#undef MoveToStartOfBlock
#undef MoveToEndOfBlock
#undef MoveToStartOfDocument
#undef MoveToEndOfDocument
#undef SelectNextChar
#undef SelectPreviousChar
#undef SelectNextWord
#undef SelectPreviousWord
#undef SelectNextLine
#undef SelectPreviousLine
#undef SelectNextPage
#undef SelectPreviousPage
#undef SelectStartOfLine
#undef SelectEndOfLine
#undef SelectStartOfBlock
#undef SelectEndOfBlock
#undef SelectStartOfDocument
#undef SelectEndOfDocument
#undef DeleteStartOfWord
#undef DeleteEndOfWord
#undef DeleteEndOfLine
#undef InsertParagraphSeparator
#undef InsertLineSeparator
#undef SaveAs
#undef Preferences
#undef Quit
#undef FullScreen
#undef Deselect
#undef DeleteCompleteLine
#undef Backspace
#undef Cancel

#undef Key_Escape
#undef Key_Tab
#undef Key_Backtab
#undef Key_Backspace
#undef Key_Return
#undef Key_Enter
#undef Key_Insert
#undef Key_Delete
#undef Key_Pause
#undef Key_Print
#undef Key_SysReq
#undef Key_Clear
#undef Key_Home
#undef Key_End
#undef Key_Left
#undef Key_Up
#undef Key_Right
#undef Key_Down
#undef Key_PageUp
#undef Key_PageDown
#undef Key_Shift
#undef Key_Control
#undef Key_Meta
#undef Key_Alt
#undef Key_CapsLock
#undef Key_NumLock
#undef Key_ScrollLock
#undef Key_F1
#undef Key_F2
#undef Key_F3
#undef Key_F4
#undef Key_F5
#undef Key_F6
#undef Key_F7
#undef Key_F8
#undef Key_F9
#undef Key_F10
#undef Key_F11
#undef Key_F12
#undef Key_F13
#undef Key_F14
#undef Key_F15
#undef Key_F16
#undef Key_F17
#undef Key_F18
#undef Key_F19
#undef Key_F20
#undef Key_F21
#undef Key_F22
#undef Key_F23
#undef Key_F24
#undef Key_F25
#undef Key_F26
#undef Key_F27
#undef Key_F28
#undef Key_F29
#undef Key_F30
#undef Key_F31
#undef Key_F32
#undef Key_F33
#undef Key_F34
#undef Key_F35
#undef Key_Super_L
#undef Key_Super_R
#undef Key_Menu
#undef Key_Hyper_L
#undef Key_Hyper_R
#undef Key_Help
#undef Key_Direction_L
#undef Key_Direction_R
#undef Key_Space
#undef Key_Any
#undef Key_Exclam
#undef Key_QuoteDbl
#undef Key_NumberSign
#undef Key_Dollar
#undef Key_Percent
#undef Key_Ampersand
#undef Key_Apostrophe
#undef Key_ParenLeft
#undef Key_ParenRight
#undef Key_Asterisk
#undef Key_Plus
#undef Key_Comma
#undef Key_Minus
#undef Key_Period
#undef Key_Slash
#undef Key_0
#undef Key_1
#undef Key_2
#undef Key_3
#undef Key_4
#undef Key_5
#undef Key_6
#undef Key_7
#undef Key_8
#undef Key_9
#undef Key_Colon
#undef Key_Semicolon
#undef Key_Less
#undef Key_Equal
#undef Key_Greater
#undef Key_Question
#undef Key_At
#undef Key_A
#undef Key_B
#undef Key_C
#undef Key_D
#undef Key_E
#undef Key_F
#undef Key_G
#undef Key_H
#undef Key_I
#undef Key_J
#undef Key_K
#undef Key_L
#undef Key_M
#undef Key_N
#undef Key_O
#undef Key_P
#undef Key_Q
#undef Key_R
#undef Key_S
#undef Key_T
#undef Key_U
#undef Key_V
#undef Key_W
#undef Key_X
#undef Key_Y
#undef Key_Z
#undef Key_BracketLeft
#undef Key_Backslash
#undef Key_BracketRight
#undef Key_AsciiCircum
#undef Key_Underscore
#undef Key_QuoteLeft
#undef Key_BraceLeft
#undef Key_Bar
#undef Key_BraceRight
#undef Key_AsciiTilde
#undef Key_nobreakspace
#undef Key_exclamdown
#undef Key_cent
#undef Key_sterling
#undef Key_currency
#undef Key_yen
#undef Key_brokenbar
#undef Key_section
#undef Key_diaeresis
#undef Key_copyright
#undef Key_ordfeminine
#undef Key_guillemotleft
#undef Key_notsign
#undef Key_hyphen
#undef Key_registered
#undef Key_macron
#undef Key_degree
#undef Key_plusminus
#undef Key_twosuperior
#undef Key_threesuperior
#undef Key_acute
#undef Key_mu
#undef Key_paragraph
#undef Key_periodcentered
#undef Key_cedilla
#undef Key_onesuperior
#undef Key_masculine
#undef Key_guillemotright
#undef Key_onequarter
#undef Key_onehalf
#undef Key_threequarters
#undef Key_questiondown
#undef Key_Agrave
#undef Key_Aacute
#undef Key_Acircumflex
#undef Key_Atilde
#undef Key_Adiaeresis
#undef Key_Aring
#undef Key_AE
#undef Key_Ccedilla
#undef Key_Egrave
#undef Key_Eacute
#undef Key_Ecircumflex
#undef Key_Ediaeresis
#undef Key_Igrave
#undef Key_Iacute
#undef Key_Icircumflex
#undef Key_Idiaeresis
#undef Key_ETH
#undef Key_Ntilde
#undef Key_Ograve
#undef Key_Oacute
#undef Key_Ocircumflex
#undef Key_Otilde
#undef Key_Odiaeresis
#undef Key_multiply
#undef Key_Ooblique
#undef Key_Ugrave
#undef Key_Uacute
#undef Key_Ucircumflex
#undef Key_Udiaeresis
#undef Key_Yacute
#undef Key_THORN
#undef Key_ssharp
#undef Key_division
#undef Key_ydiaeresis
#undef Key_AltGr
#undef Key_Multi_key
#undef Key_Codeinput
#undef Key_SingleCandidate
#undef Key_MultipleCandidate
#undef Key_PreviousCandidate
#undef Key_Mode_switch
#undef Key_Kanji
#undef Key_Muhenkan
#undef Key_Henkan
#undef Key_Romaji
#undef Key_Hiragana
#undef Key_Katakana
#undef Key_Hiragana_Katakana
#undef Key_Zenkaku
#undef Key_Hankaku
#undef Key_Zenkaku_Hankaku
#undef Key_Touroku
#undef Key_Massyo
#undef Key_Kana_Lock
#undef Key_Kana_Shift
#undef Key_Eisu_Shift
#undef Key_Eisu_toggle
#undef Key_Hangul
#undef Key_Hangul_Start
#undef Key_Hangul_End
#undef Key_Hangul_Hanja
#undef Key_Hangul_Jamo
#undef Key_Hangul_Romaja
#undef Key_Hangul_Jeonja
#undef Key_Hangul_Banja
#undef Key_Hangul_PreHanja
#undef Key_Hangul_PostHanja
#undef Key_Hangul_Special
#undef Key_Dead_Grave
#undef Key_Dead_Acute
#undef Key_Dead_Circumflex
#undef Key_Dead_Tilde
#undef Key_Dead_Macron
#undef Key_Dead_Breve
#undef Key_Dead_Abovedot
#undef Key_Dead_Diaeresis
#undef Key_Dead_Abovering
#undef Key_Dead_Doubleacute
#undef Key_Dead_Caron
#undef Key_Dead_Cedilla
#undef Key_Dead_Ogonek
#undef Key_Dead_Iota
#undef Key_Dead_Voiced_Sound
#undef Key_Dead_Semivoiced_Sound
#undef Key_Dead_Belowdot
#undef Key_Dead_Hook
#undef Key_Dead_Horn
#undef Key_Dead_Stroke
#undef Key_Dead_Abovecomma
#undef Key_Dead_Abovereversedcomma
#undef Key_Dead_Doublegrave
#undef Key_Dead_Belowring
#undef Key_Dead_Belowmacron
#undef Key_Dead_Belowcircumflex
#undef Key_Dead_Belowtilde
#undef Key_Dead_Belowbreve
#undef Key_Dead_Belowdiaeresis
#undef Key_Dead_Invertedbreve
#undef Key_Dead_Belowcomma
#undef Key_Dead_Currency
#undef Key_Dead_a
#undef Key_Dead_A
#undef Key_Dead_e
#undef Key_Dead_E
#undef Key_Dead_i
#undef Key_Dead_I
#undef Key_Dead_o
#undef Key_Dead_O
#undef Key_Dead_u
#undef Key_Dead_U
#undef Key_Dead_Small_Schwa
#undef Key_Dead_Capital_Schwa
#undef Key_Dead_Greek
#undef Key_Dead_Lowline
#undef Key_Dead_Aboveverticalline
#undef Key_Dead_Belowverticalline
#undef Key_Dead_Longsolidusoverlay
#undef Key_Back
#undef Key_Forward
#undef Key_Stop
#undef Key_Refresh
#undef Key_VolumeDown
#undef Key_VolumeMute
#undef Key_VolumeUp
#undef Key_BassBoost
#undef Key_BassUp
#undef Key_BassDown
#undef Key_TrebleUp
#undef Key_TrebleDown
#undef Key_MediaPlay
#undef Key_MediaStop
#undef Key_MediaPrevious
#undef Key_MediaNext
#undef Key_MediaRecord
#undef Key_MediaPause
#undef Key_MediaTogglePlayPause
#undef Key_HomePage
#undef Key_Favorites
#undef Key_Search
#undef Key_Standby
#undef Key_OpenUrl
#undef Key_LaunchMail
#undef Key_LaunchMedia
#undef Key_Launch0
#undef Key_Launch1
#undef Key_Launch2
#undef Key_Launch3
#undef Key_Launch4
#undef Key_Launch5
#undef Key_Launch6
#undef Key_Launch7
#undef Key_Launch8
#undef Key_Launch9
#undef Key_LaunchA
#undef Key_LaunchB
#undef Key_LaunchC
#undef Key_LaunchD
#undef Key_LaunchE
#undef Key_LaunchF
#undef Key_MonBrightnessUp
#undef Key_MonBrightnessDown
#undef Key_KeyboardLightOnOff
#undef Key_KeyboardBrightnessUp
#undef Key_KeyboardBrightnessDown
#undef Key_PowerOff
#undef Key_WakeUp
#undef Key_Eject
#undef Key_ScreenSaver
#undef Key_WWW
#undef Key_Memo
#undef Key_LightBulb
#undef Key_Shop
#undef Key_History
#undef Key_AddFavorite
#undef Key_HotLinks
#undef Key_BrightnessAdjust
#undef Key_Finance
#undef Key_Community
#undef Key_AudioRewind
#undef Key_BackForward
#undef Key_ApplicationLeft
#undef Key_ApplicationRight
#undef Key_Book
#undef Key_CD
#undef Key_Calculator
#undef Key_ToDoList
#undef Key_ClearGrab
#undef Key_Close
#undef Key_Copy
#undef Key_Cut
#undef Key_Display
#undef Key_DOS
#undef Key_Documents
#undef Key_Excel
#undef Key_Explorer
#undef Key_Game
#undef Key_Go
#undef Key_iTouch
#undef Key_LogOff
#undef Key_Market
#undef Key_Meeting
#undef Key_MenuKB
#undef Key_MenuPB
#undef Key_MySites
#undef Key_News
#undef Key_OfficeHome
#undef Key_Option
#undef Key_Paste
#undef Key_Phone
#undef Key_Calendar
#undef Key_Reply
#undef Key_Reload
#undef Key_RotateWindows
#undef Key_RotationPB
#undef Key_RotationKB
#undef Key_Save
#undef Key_Send
#undef Key_Spell
#undef Key_SplitScreen
#undef Key_Support
#undef Key_TaskPane
#undef Key_Terminal
#undef Key_Tools
#undef Key_Travel
#undef Key_Video
#undef Key_Word
#undef Key_Xfer
#undef Key_ZoomIn
#undef Key_ZoomOut
#undef Key_Away
#undef Key_Messenger
#undef Key_WebCam
#undef Key_MailForward
#undef Key_Pictures
#undef Key_Music
#undef Key_Battery
#undef Key_Bluetooth
#undef Key_WLAN
#undef Key_UWB
#undef Key_AudioForward
#undef Key_AudioRepeat
#undef Key_AudioRandomPlay
#undef Key_Subtitle
#undef Key_AudioCycleTrack
#undef Key_Time
#undef Key_Hibernate
#undef Key_View
#undef Key_TopMenu
#undef Key_PowerDown
#undef Key_Suspend
#undef Key_ContrastAdjust
#undef Key_LaunchG
#undef Key_LaunchH
#undef Key_TouchpadToggle
#undef Key_TouchpadOn
#undef Key_TouchpadOff
#undef Key_MicMute
#undef Key_Red
#undef Key_Green
#undef Key_Yellow
#undef Key_Blue
#undef Key_ChannelUp
#undef Key_ChannelDown
#undef Key_Guide
#undef Key_Info
#undef Key_Settings
#undef Key_MicVolumeUp
#undef Key_MicVolumeDown
#undef Key_New
#undef Key_Open
#undef Key_Find
#undef Key_Undo
#undef Key_Redo
#undef Key_MediaLast
#undef Key_Select
#undef Key_Yes
#undef Key_No
#undef Key_Cancel
#undef Key_Printer
#undef Key_Execute
#undef Key_Sleep
#undef Key_Play
#undef Key_Zoom
#undef Key_Exit
#undef Key_Context1
#undef Key_Context2
#undef Key_Context3
#undef Key_Context4
#undef Key_Call
#undef Key_Hangup
#undef Key_Flip
#undef Key_ToggleCallHangup
#undef Key_VoiceDial
#undef Key_LastNumberRedial
#undef Key_Camera
#undef Key_CameraFocus

#undef META
#undef SHIFT
#undef CTRL
#undef ALT
#endif

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
    // V_L_T->setEnabled(h);
    // V_L_C->setEnabled(h);
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
