#include <QFileInfo>
#include <QKeyEvent>

#include <Lexers/TpLexerActionScript>
#include <Lexers/TpLexerASP>
#include <Lexers/TpLexerAviSynth>
#include <Lexers/TpLexerBash>
#include <Lexers/TpLexerBatch>
#include <Lexers/TpLexerBlitzBasic>
#include <Lexers/TpLexerC>
#include <Lexers/TpLexerCMake>
#include <Lexers/TpLexerCoffeeScript>
#include <Lexers/TpLexerCPP>
#include <Lexers/TpLexerCPPQt>
#include <Lexers/TpLexerCS>
#include <Lexers/TpLexerCSS>
#include <Lexers/TpLexerD>
#include <Lexers/TpLexerDiff>
#include <Lexers/TpLexerFortran>
#include <Lexers/TpLexerFortran77>
#include <Lexers/TpLexerGDScript>
#include <Lexers/TpLexerFreeBasic>
#include <Lexers/TpLexerHTML>
#include <Lexers/TpLexerHTMLFull>
#include <Lexers/TpLexerIDL>
#include <Lexers/TpLexerIntelHex>
#include <Lexers/TpLexerJava>
#include <Lexers/TpLexerJavaScript>
#include <Lexers/TpLexerJSON>
#include <Lexers/TpLexerLaTeX>
#include <Lexers/TpLexerLua>
#include <Lexers/TpLexerMakefile>
#include <Lexers/TpLexerMarkdown>
#include <Lexers/TpLexerMASM>
#include <Lexers/TpLexerMatlab>
#include <Lexers/TpLexerNASM>
#include <Lexers/TpLexerNone>
#include <Lexers/TpLexerOctave>
#include <Lexers/TpLexerPascal>
#include <Lexers/TpLexerPerl>
#include <Lexers/TpLexerPHP>
#include <Lexers/TpLexerPO>
#include <Lexers/TpLexerPostScript>
#include <Lexers/TpLexerPOV>
#include <Lexers/TpLexerProperties>
#include <Lexers/TpLexerPureBasic>
#include <Lexers/TpLexerPython2>
#include <Lexers/TpLexerPython3>
#include <Lexers/TpLexerPython3Extended>
#include <Lexers/TpLexerQML>
#include <Lexers/TpLexerQSS>
#include <Lexers/TpLexerQUI>
#include <Lexers/TpLexerRuby>
#include <Lexers/TpLexerSpice>
#include <Lexers/TpLexerSQL>
#include <Lexers/TpLexerSRecord>
#include <Lexers/TpLexerTCL>
#include <Lexers/TpLexerTektronixHex>
#include <Lexers/TpLexerTeX>
#include <Lexers/TpLexerVerilog>
#include <Lexers/TpLexerVHDL>
#include <Lexers/TpLexerXML>
#include <Lexers/TpLexerYAML>
#include <Views/TpBookmarkView>
#include <Views/TpDocumentView>
#include <Widgets/TpFindContainer>
#include <TpColorScheme>
#include <TpEditor>
#include <TpMainWindow>
#include <TpStackedWidget>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpEditor::TpEditor(TpTabWidget *parent)
    : QsciScintilla(parent),
    m_parent(parent)
{
    m_content = "";
    m_filePath = "";
    m_untitled = -1;
    m_startFlag = WrapFlagNone;
    m_endFlag = WrapFlagNone;
    m_lineNumbers = true;

    m_bracketing = false;
    m_bracing = false;
    m_parenthesizing = false;
    m_apostrophing = false;
    m_stringing = false;

    m_lexers = {
        {None, new TpLexerNone(this)},
        {ActionScript, new TpLexerActionScript(this)},
        {ASP, new TpLexerASP(this)},
        {AviSynth, new TpLexerAviSynth(this)},
        {Bash, new TpLexerBash(this)},
        {Batch, new TpLexerBatch(this)},
        {BlitzBasic, new TpLexerBlitzBasic(this)},
        {PureBasic, new TpLexerPureBasic(this)},
        {FreeBasic, new TpLexerFreeBasic(this)},
        {C, new TpLexerC(this)},
        {CPP, new TpLexerCPP(this)},
        {CPPQt, new TpLexerCPPQt(this)},
        {CS, new TpLexerCS(this)},
        {CMake, new TpLexerCMake(this)},
        {CoffeeScript, new TpLexerCoffeeScript(this)},
        {CSS, new TpLexerCSS(this)},
        {D, new TpLexerD(this)},
        {Diff, new TpLexerDiff(this)},
        {Fortran, new TpLexerFortran(this)},
        {Fortran77, new TpLexerFortran77(this)},
        {GDScript, new TpLexerGDScript(this)},
        {HTML, new TpLexerHTML(this)},
        {HTMLFull, new TpLexerHTMLFull(this)},
        {IDL, new TpLexerIDL(this)},
        {IntelHex, new TpLexerIntelHex(this)},
        {Java, new TpLexerJava(this)},
        {JavaScript, new TpLexerJavaScript(this)},
        {JSON, new TpLexerJSON(this)},
        {LaTeX, new TpLexerLaTeX(this)},
        {Lua, new TpLexerLua(this)},
        {Makefile, new TpLexerMakefile(this)},
        {Markdown, new TpLexerMarkdown(this)},
        {MASM, new TpLexerMASM(this)},
        {Matlab, new TpLexerMatlab(this)},
        {NASM, new TpLexerNASM(this)},
        {Octave, new TpLexerOctave(this)},
        {Pascal, new TpLexerPascal(this)},
        {Perl, new TpLexerPerl(this)},
        {PHP, new TpLexerPHP(this)},
        {PO, new TpLexerPO(this)},
        {PostScript, new TpLexerPostScript(this)},
        {POV, new TpLexerPOV(this)},
        {Properties, new TpLexerProperties(this)},
        {Python2, new TpLexerPython2(this)},
        {Python3, new TpLexerPython3(this)},
        {Python3Extended, new TpLexerPython3Extended(this)},
        {QML, new TpLexerQML(this)},
        {QSS, new TpLexerQSS(this)},
        {QUI, new TpLexerQUI(this)},
        {Ruby, new TpLexerRuby(this)},
        {Spice, new TpLexerSpice(this)},
        {SQL, new TpLexerSQL(this)},
        {SRecord, new TpLexerSRecord(this)},
        {TCL, new TpLexerTCL(this)},
        {TektronixHex, new TpLexerTektronixHex(this)},
        {TeX, new TpLexerTeX(this)},
        {Verilog, new TpLexerVerilog(this)},
        {VHDL, new TpLexerVHDL(this)},
        {XML, new TpLexerXML(this)},
        {YAML, new TpLexerYAML(this)},
    };

    emit fileNameChanged(m_filePath, ((m_filePath == "") ? tr("Untitled %1").arg(m_untitled) : ""));

    setWhitespaceVisibility(WsInvisible);
    setEolVisibility(false);
    setStartFlag(WrapFlagNone);
    setEndFlag(WrapFlagNone);
    setIndentationGuides(true);
    setWrapMode(WrapNone);
    setFolding(PlainFoldStyle);

    setEolMode(EolUnix);
    setIndentationsUseTabs(false);
    setBackspaceUnindents(true);
    setTabIndents(true);
    setTabDrawMode(TabLongArrow);
    setMarginOptions(MoNone);

    setAutoCompletionCaseSensitivity(false);
    setAutoCompletionFillupsEnabled(true);
    setAutoCompletionReplaceWord(true);
    setAutoCompletionUseSingle(AcusExplicit);
    setAutoCompletionSource(AcsAll);
    setAutoIndent(true);
    setAutoCompletionStyle(AiMaintain);
    setBraceMatching(SloppyBraceMatch);
    setCallTipsPosition(CallTipsAboveText);
    setCallTipsStyle(CallTipsContext);
    setEdgeMode(EdgeNone);
    setSelectionToEol(true);
    SendScintilla(SCI_SETMULTIPLESELECTION, true);
    SendScintilla(SCI_SETADDITIONALSELECTIONTYPING, true);
    SendScintilla(SCI_SETMULTIPASTE, true);
    SendScintilla(SCI_SETVIRTUALSPACEOPTIONS, 1);
    SendScintilla(SCI_SETRECTANGULARSELECTIONMODIFIER, 4);
    SendScintilla(SCI_SETCARETSTICKY, 0);
    setCaretLineVisible(true);
    setWrapIndentMode(WrapIndentSame);
    SendScintilla(SCI_SETBUFFEREDDRAW, false);
    SendScintilla(SCI_SETPHASESDRAW, 1);
    SendScintilla(SCI_SETFONTQUALITY, 0);

    setAutoCompletionThreshold(1);
    setCallTipsVisible(-1);
    setCaretWidth(3);
    setEdgeColumn(120);
    setExtraAscent(2);
    setExtraDescent(2);
    setTabWidth(4);

    setMarginType(1, SymbolMargin);
    setMarginSensitivity(1, true);
    setMarginWidth(1, (QFontMetrics(font()).horizontalAdvance("000")));

    setLineNumbers(m_lineNumbers);

    m_findIndicator = indicatorDefine(DiagonalIndicator);
    setIndicatorDrawUnder(true, m_findIndicator);
    setIndicatorForegroundColor(defaultColorScheme->BgFindIndicator);

    m_incrementalIndicator = indicatorDefine(StraightBoxIndicator);
    setIndicatorDrawUnder(true, m_incrementalIndicator);
    setIndicatorForegroundColor(defaultColorScheme->BgIncrementalIndicator);

    m_bookmarkMarker = markerDefine(QImage(":/app/bookmark.png").scaled(QSize(16, 16)));
    m_bookmarkView = new TpBookmarkView(this);

    m_findContainer = new TpFindContainer(this);

    connect(this,
            SIGNAL(cursorPositionChanged(int,int)),
            this,
            SLOT(onCursorPositionChanged(int,int)));
    connect(this,
            SIGNAL(marginClicked(int,int,Qt::KeyboardModifiers)),
            this,
            SLOT(onMarginClicked(int,int,Qt::KeyboardModifiers)));

    connect(m_findContainer,
            &TpFindContainer::checkBoxChecked,
            this,
            &TpEditor::checkBoxChecked);
}

TpEditor::~TpEditor()
{
    emit fileNameChanged(m_filePath, ((m_filePath == "") ? tr("Untitled %1").arg(m_untitled) : ""));

    if (m_untitled != -1)
        untitledList.removeOne(m_untitled);
}

const QString &TpEditor::content() const
{
    return m_content;
}

const QString &TpEditor::filePath() const
{
    return m_filePath;
}

unsigned int TpEditor::untitled() const
{
    return m_untitled;
}

void TpEditor::setStartFlag(TpEditor::WrapVisualFlag startFlag)
{
    m_startFlag = startFlag;
    setWrapVisualFlags(m_startFlag, m_endFlag);
}

TpEditor::WrapVisualFlag TpEditor::startFlag() const
{
    return m_startFlag;
}

void TpEditor::setEndFlag(TpEditor::WrapVisualFlag endFlag)
{
    m_endFlag = endFlag;
    setWrapVisualFlags(m_startFlag, m_endFlag);
}

TpEditor::WrapVisualFlag TpEditor::endFlag() const
{
    return m_endFlag;
}

void TpEditor::setLineNumbers(bool lineNumbers)
{
    m_lineNumbers = lineNumbers;
    setMarginLineNumbers(0, lineNumbers);
}

bool TpEditor::lineNumbers() const
{
    return m_lineNumbers;
}

int TpEditor::currentLine() const
{
    return SendScintilla(SCI_LINEFROMPOSITION, SendScintilla(SCI_GETCURRENTPOS));
}

void TpEditor::setCurrentLine(int line)
{
    SendScintilla(SCI_SETCURRENTPOS, positionFromLineIndex(line, 0));
    int newLine = 0;
    int newIndex = 0;
    lineIndexFromPosition(getPosition(), &newLine, &newIndex);
    setSelection(newLine, newIndex, newLine, newIndex);
}

Languages TpEditor::currentLexer() const
{
    for (auto item : m_lexers.keys())
    {
        if (lexer() == m_lexers[item])
            return item;
    }

    return None;
}

bool TpEditor::setCurrentLexer(Languages currentLexer)
{
    if (!m_lexers.contains(currentLexer))
        return false;

    if (currentLexer != None)
        setLexer(m_lexers[currentLexer]);
    else
        setLexer(nullptr);

    adjustAppearance();

    return true;
}

int TpEditor::getLength() const
{
    return SendScintilla(SCI_GETLENGTH);
}

int TpEditor::getPosition() const
{
    return SendScintilla(SCI_GETCURRENTPOS);
}

int TpEditor::findIndicator() const
{
    return m_findIndicator;
}

int TpEditor::findIndicatorStart(int position) const
{
    return SendScintilla(SCI_INDICATORSTART, m_findIndicator, position);
}

int TpEditor::findIndicatorEnd(int position) const
{
    return SendScintilla(SCI_INDICATOREND, m_findIndicator, position);
}

int TpEditor::incrementalIndicator() const
{
    return m_incrementalIndicator;
}

int TpEditor::bookmarkMarker() const
{
    return m_bookmarkMarker;
}

QMap<QString, QVariant> TpEditor::toMap()
{
    QMap<QString, QVariant> map{
        {"View/ShowSymbols/SpacesAndTabs", whitespaceVisibility()},
        {"View/ShowSymbols/NonPrintable", eolVisibility()},
        {"View/ShowSymbols/IndentationGuides", indentationGuides()},
        {"View/WordWrap", wrapMode()},
        {"View/Folding", folding()},
        {"Format/Language", currentLexer()},
        {"Format/Newline", eolMode()},
        {"Format/Indentation/UseTabsToIndent", indentationsUseTabs()},
        {"Format/Indentation/Width", indentationWidth()},
        {"Format/Indentation/BackspaceUnindents", backspaceUnindents()},
        {"Format/Indentation/TabToIndent", tabIndents()},
        {"Format/RepresentingTabs", tabDrawMode()},
        {"Format/SelectFirstWrappedLineOnly", (marginOptions() & MoSublineSelect)},
        {"Tools/Autocompletion/CaseSensitive", autoCompletionCaseSensitivity()},
        {"Tools/Autocompletion/FillupsEnabled", autoCompletionFillupsEnabled()},
        {"Tools/Autocompletion/ReplaceWord", autoCompletionReplaceWord()},
        {"Tools/Autocompletion/WhenSingleEntry", autoCompletionUseSingle()},
        {"Tools/Autocompletion/Sources", autoCompletionSource()},
        {"Tools/Autoindentation", autoIndent()},
        {"Tools/Autoindentation/Style", autoCompletionStyle()},
        {"Tools/BraceMatching", braceMatching()},
        {"Tools/CallTips/Position", callTipsPosition()},
        {"Tools/CallTips/Style", callTipsStyle()},
        {"Tools/EdgeMode", edgeMode()},
        {"Tools/CaretAndVirtualSelection/SelectTillBorder", selectionToEol()},
        {"Tools/CaretAndVirtualSelection/MultipleSelection", ((int)SendScintilla(SCI_GETMULTIPLESELECTION))},
        {"Tools/CaretAndVirtualSelection/AdditionalSelectionTyping",
            ((int)SendScintilla(SCI_GETADDITIONALSELECTIONTYPING))},
        {"Tools/CaretAndVirtualSelection/MultiplePaste", ((int)SendScintilla(SCI_GETMULTIPASTE))},
        {"Tools/CaretAndVirtualSelection/VirtualSpace", ((int)SendScintilla(SCI_GETVIRTUALSPACEOPTIONS))},
        {"Tools/CaretAndVirtualSelection/RectangularSelectionModifier",
            ((int)SendScintilla(SCI_GETRECTANGULARSELECTIONMODIFIER))},
        {"Tools/CaretAndVirtualSelection/CaretSticky", ((int)SendScintilla(SCI_GETCARETSTICKY))},
        {"Tools/CaretAndVirtualSelection/CaretLineVisible", ((int)SendScintilla(SCI_GETCARETLINEVISIBLE))},
        {"Tools/Search/Flags", ((int)m_findContainer->optionsFlag())},
        {"Tools/WrappingTools/Indentation", wrapIndentMode()},
        {"Tools/WrappingTools/StartFlag", startFlag()},
        {"Tools/WrappingTools/EndFlag", endFlag()},
        {"Tools/Miscellaneous/PhaseDraw", ((int)SendScintilla(SCI_GETPHASESDRAW))},
        {"Tools/Miscellaneous/FontQuality", ((int)SendScintilla(SCI_GETFONTQUALITY))},
    };

    return map;
}

QString TpEditor::fromMap(QMap<QString, QVariant> map)
{
#define CHECK_MAP(item) \
    if (!map.contains(item)) \
        return QString("Invalid map: %1 does not exist").arg(item)
#define M(func, key, type) \
    if (!map[key].canConvert<type>()) \
        potentialError = QString("Invalid value: %1 cannot be converted to desired type").arg(key); \
    func(qvariant_cast<type>(map[key]))  // M stands for "Modify"
#define SCI_M(sci, key) \
    if (!map[key].canConvert<int>()) \
        potentialError = QString("Invalid value: SCI's %1 cannot be converted to int").arg(key); \
    SendScintilla(sci, qvariant_cast<int>(map[key]))

#if QT_VERSION_MAJOR >= 6
#define E_M(func, key, type) M(func, key, type)  // E stands for "Enum"
#else
#define E_M(func, key, type) \
    if (!map[key].canConvert<int>()) \
        potentialError = QString("Invalid value: %1 cannot be converted to enum/ int type").arg(key); \
    func(static_cast<type>(qvariant_cast<int>(map[key])))  // E stands for "Enum"
#endif

    CHECK_MAP("View/ShowSymbols/SpacesAndTabs");
    CHECK_MAP("View/ShowSymbols/NonPrintable");
    CHECK_MAP("View/ShowSymbols/IndentationGuides");
    CHECK_MAP("View/WordWrap");
    CHECK_MAP("View/Folding");
    CHECK_MAP("Format/Language");
    CHECK_MAP("Format/Newline");
    CHECK_MAP("Format/Indentation/UseTabsToIndent");
    CHECK_MAP("Format/Indentation/Width");
    CHECK_MAP("Format/Indentation/BackspaceUnindents");
    CHECK_MAP("Format/Indentation/TabToIndent");
    CHECK_MAP("Format/RepresentingTabs");
    CHECK_MAP("Format/SelectFirstWrappedLineOnly");
    CHECK_MAP("Tools/Autocompletion/CaseSensitive");
    CHECK_MAP("Tools/Autocompletion/FillupsEnabled");
    CHECK_MAP("Tools/Autocompletion/ReplaceWord");
    CHECK_MAP("Tools/Autocompletion/WhenSingleEntry");
    CHECK_MAP("Tools/Autocompletion/Sources");
    CHECK_MAP("Tools/Autoindentation");
    CHECK_MAP("Tools/Autoindentation/Style");
    CHECK_MAP("Tools/BraceMatching");
    CHECK_MAP("Tools/CallTips/Position");
    CHECK_MAP("Tools/CallTips/Style");
    CHECK_MAP("Tools/EdgeMode");
    CHECK_MAP("Tools/CaretAndVirtualSelection/SelectTillBorder");
    CHECK_MAP("Tools/CaretAndVirtualSelection/MultipleSelection");
    CHECK_MAP("Tools/CaretAndVirtualSelection/AdditionalSelectionTyping");
    CHECK_MAP("Tools/CaretAndVirtualSelection/MultiplePaste");
    CHECK_MAP("Tools/CaretAndVirtualSelection/VirtualSpace");
    CHECK_MAP("Tools/CaretAndVirtualSelection/RectangularSelectionModifier");
    CHECK_MAP("Tools/CaretAndVirtualSelection/CaretSticky");
    CHECK_MAP("Tools/CaretAndVirtualSelection/CaretLineVisible");
    CHECK_MAP("Tools/Search/Flags");
    CHECK_MAP("Tools/WrappingTools/Indentation");
    CHECK_MAP("Tools/WrappingTools/StartFlag");
    CHECK_MAP("Tools/WrappingTools/EndFlag");
    CHECK_MAP("Tools/Miscellaneous/PhaseDraw");
    CHECK_MAP("Tools/Miscellaneous/FontQuality");

    QString potentialError;

    E_M(setWhitespaceVisibility, "View/ShowSymbols/SpacesAndTabs", WhitespaceVisibility);
    M(setEolVisibility, "View/ShowSymbols/NonPrintable", bool);
    M(setIndentationGuides, "View/ShowSymbols/IndentationGuides", bool);
    E_M(setWrapMode, "View/WordWrap", WrapMode);
    E_M(setFolding, "View/Folding", FoldStyle);
    E_M(setCurrentLexer, "Format/Language", Languages);
    E_M(setEolMode, "Format/Newline", EolMode);
    M(setIndentationsUseTabs, "Format/Indentation/UseTabsToIndent", bool);
    M(setTabWidth, "Format/Indentation/Width", int);
    M(setIndentationWidth, "Format/Indentation/Width", int);
    M(setBackspaceUnindents, "Format/Indentation/BackspaceUnindents", bool);
    M(setTabIndents, "Format/Indentation/TabToIndent", bool);
    E_M(setTabDrawMode, "Format/RepresentingTabs", TabDrawMode);
    setMarginOptions((map["Format/SelectFirstWrappedLineOnly"].toBool() ? MoSublineSelect : MoNone));
    M(setAutoCompletionCaseSensitivity, "Tools/Autocompletion/CaseSensitive", bool);
    M(setAutoCompletionFillupsEnabled, "Tools/Autocompletion/FillupsEnabled", bool);
    M(setAutoCompletionReplaceWord, "Tools/Autocompletion/ReplaceWord", bool);
    E_M(setAutoCompletionUseSingle, "Tools/Autocompletion/WhenSingleEntry", AutoCompletionUseSingle);
    E_M(setAutoCompletionSource, "Tools/Autocompletion/Sources", AutoCompletionSource);
    M(setAutoIndent, "Tools/Autoindentation", bool);
    M(setAutoCompletionStyle, "Tools/Autoindentation/Style", int);
    E_M(setBraceMatching, "Tools/BraceMatching", BraceMatch);
    E_M(setCallTipsPosition, "Tools/CallTips/Position", CallTipsPosition);
    E_M(setCallTipsStyle, "Tools/CallTips/Style", CallTipsStyle);
    E_M(setEdgeMode, "Tools/EdgeMode", EdgeMode);
    M(setSelectionToEol, "Tools/CaretAndVirtualSelection/SelectTillBorder", bool);
    SCI_M(SCI_SETMULTIPLESELECTION, "Tools/CaretAndVirtualSelection/MultipleSelection");
    SCI_M(SCI_SETADDITIONALSELECTIONTYPING, "Tools/CaretAndVirtualSelection/MultiplePaste");
    SCI_M(SCI_SETVIRTUALSPACEOPTIONS, "Tools/CaretAndVirtualSelection/RectangularSelectionModifier");
    SCI_M(SCI_SETRECTANGULARSELECTIONMODIFIER, "Tools/CaretAndVirtualSelection/RectangularSelectionModifier");
    SCI_M(SCI_SETCARETSTICKY, "Tools/CaretAndVirtualSelection/CaretSticky");
    SCI_M(SCI_SETCARETLINEVISIBLE, "Tools/CaretAndVirtualSelection/CaretLineVisible");
    E_M(m_findContainer->setOptions, "Tools/Search/Flags", TpFindContainer::Options);
    E_M(setWrapIndentMode, "Tools/WrappingTools/Indentation", WrapIndentMode);
    E_M(setStartFlag, "Tools/WrappingTools/StartFlag", WrapVisualFlag);
    E_M(setEndFlag, "Tools/WrappingTools/EndFlag", WrapVisualFlag);
    SCI_M(SCI_SETPHASESDRAW, "Tools/Miscellaneous/PhaseDraw");
    SCI_M(SCI_SETFONTQUALITY, "Tools/Miscellaneous/FontQuality");

    return potentialError;

#undef CHECK_MAP
#undef M
#undef SCI_M
}

void TpEditor::adjustMargins()
{
    setMarginWidth(0, (QFontMetrics(font()).horizontalAdvance("000" + QString::number(lines()))));
}

void TpEditor::adjustAppearance()
{
    DEF_SETTINGS;

    setFont(GET_SETTINGS("Editor/Font/Universal", QFont));
    setMarginsFont(GET_SETTINGS("Editor/Font/Universal", QFont));

    setColor(GET_SETTINGS("Editor/Color/Universal", QColor));
    setPaper(GET_SETTINGS("Editor/BgColor/Universal", QColor));
    setCaretForegroundColor(GET_SETTINGS("Editor/Color/Caret", QColor));
    setCaretLineBackgroundColor(GET_SETTINGS("Editor/BgColor/Caret", QColor));
    setIndentationGuidesForegroundColor(GET_SETTINGS("Editor/Color/IndentationGuides", QColor));
    setIndentationGuidesBackgroundColor(GET_SETTINGS("Editor/BgColor/IndentationGuides", QColor));
    setMarginsForegroundColor(GET_SETTINGS("Editor/Color/Margin", QColor));
    setMarginsBackgroundColor(GET_SETTINGS("Editor/BgColor/Margin", QColor));
    setFoldMarginColors(GET_SETTINGS("Editor/BgColor/Margin", QColor), GET_SETTINGS("Editor/BgColor/Margin", QColor));
    setSelectionForegroundColor(GET_SETTINGS("Editor/Color/Selection", QColor));
    setSelectionBackgroundColor(GET_SETTINGS("Editor/BgColor/Selection", QColor));

    if ((lexer() == m_lexers[None]) || (!lexer()))
    {
        // Workaround for a QScintilla bug
        beginUndoAction();
        QString currentText = text();
        int currentPos = SendScintilla(SCI_GETCURRENTPOS);
        clear();
        insert(currentText);
        SendScintilla(SCI_GOTOPOS, currentPos);
        endUndoAction();
    }
}

void TpEditor::adjustBookmarks()
{
    m_bookmarkView->clear();

    for (int line = 0; line < lines(); line++)
    {
        if (markersAtLine(line) & (m_bookmarkMarker + 1))
            m_bookmarkView->addItem(line + 1);
    }
}

TpMainWindow *TpEditor::ultimateParent() const
{
    return m_parent->m_parent->m_parent->m_parent;
}

void TpEditor::keyPressEvent(QKeyEvent *event)
{
#define TEST_FLAG(k) (event->key() == Qt::Key::Key_##k)

    QString peekNext;

    if (text().length() > getPosition())
        peekNext = text().at(getPosition());

    if (lexer() != nullptr)
    {
        m_bracketing = (TEST_FLAG(BracketRight) && (peekNext == "]"));
        m_bracing = (TEST_FLAG(BraceRight) && (peekNext == "}"));
        m_parenthesizing = (TEST_FLAG(ParenRight) && (peekNext == ")"));
        m_apostrophing = (TEST_FLAG(Apostrophe) && (peekNext == "'"));
        m_stringing = (TEST_FLAG(QuoteDbl) && (peekNext == "\""));
    }

    if (!m_bracketing && !m_bracing && !m_parenthesizing && !m_apostrophing && !m_stringing)
        QsciScintilla::keyPressEvent(event);
}

void TpEditor::keyReleaseEvent(QKeyEvent *event)
{
    QString peekNext;

    if (text().length() > getPosition())
        peekNext = text().at(getPosition());

    if (event)
    {
        if (TEST_FLAG(Enter) || TEST_FLAG(Return))
        {
            emit punctuation();
            emit returnPressed();
        }

        if (TEST_FLAG(Tab) || ((event->key() >= 0x20) && (event->key() <= 0x40)) || ((event->key() >= 0x5b)))
        {
            emit punctuation();
        }

        if (lexer() != nullptr)
        {
            if ((TEST_FLAG(BracketRight) && (peekNext == "]")) ||
                (TEST_FLAG(BraceRight) && (peekNext == "}")) ||
                (TEST_FLAG(ParenRight) && (peekNext == ")")) ||
                (TEST_FLAG(Apostrophe) && (peekNext == "'")) ||
                (TEST_FLAG(QuoteDbl) && (peekNext == "\"")))
            {
                SendScintilla(SCI_CHARRIGHT);
                return;
            }
        }
    }

    if (!m_bracketing && !m_bracing && !m_parenthesizing && !m_apostrophing && !m_stringing)
        QsciScintilla::keyReleaseEvent(event);

    if (event)
    {
        if (lexer() != nullptr)
        {
            if (TEST_FLAG(BracketLeft))
            {
                insert("]");
            }

            if (TEST_FLAG(BraceLeft))
            {
                insert("}");
            }

            if (TEST_FLAG(ParenLeft))
            {
                insert(")");
            }

            if (TEST_FLAG(Apostrophe))
            {
                insert("'");
            }

            if (TEST_FLAG(QuoteDbl))
            {
                insert("\"");
            }
        }
    }

#undef TEST_FLAG
}

void TpEditor::onCursorPositionChanged(int line, int index)
{
    adjustMargins();
    adjustBookmarks();

    emit positionChanged(positionFromLineIndex(line, index), line, index);
}

void TpEditor::onMarginClicked(int margin, int line, Qt::KeyboardModifiers modifiers)
{
    if (margin != 1)
        return;

    if (modifiers != 0x0)
        return;

    if (markersAtLine(line) & (m_bookmarkMarker + 1))
        markerDelete(line, m_bookmarkMarker);
    else
        markerAdd(line, m_bookmarkMarker);

    adjustBookmarks();
}

void TpEditor::onBookmarkViewDoubleClicked(int line)
{
    setCurrentLine(line - 1);
}

TP_END_NAMESPACE
