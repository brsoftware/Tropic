#include <Lexers/TpLexerCoffeeScript>

TP_NAMESPACE

TpLexerCoffeeScript::TpLexerCoffeeScript(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldAtElse(true),
    m_foldComments(true),
    m_foldCompact(true),
    m_foldPreprocessor(true),
    m_stylePreprocessor(true),
    m_enableDollars(true),
    m_enableTripleQuotedStrings(false),
    m_enableHashQuotedStrings(false),
    m_enableEscapeSequence(true),
    m_enableVerbatimEscapeSequence(false),
    m_trackPreprocessor(true),
    m_updatePreprocessor(true),
    m_syntaxBasedFold(true),
    m_explicitStart("//{"),
    m_explicitEnd("//}"),
    m_explicitAnywhere(false),
    m_foldPreprocessorAtElse(true)
{}

TpLexerCoffeeScript::~TpLexerCoffeeScript()
{}

int TpLexerCoffeeScript::autoIndentStyle()
{
    DEF_SETTINGS;
    if (GET_SETTINGS("Tools/Autoindentation/Style/Auto", bool))
        return 0;

    return TpGeneralLexer::autoIndentStyle();
}

const char *TpLexerCoffeeScript::language() const
{
    return "CoffeeScript";
}

const char *TpLexerCoffeeScript::lexer() const
{
    return "coffeescript";
}

QStringList TpLexerCoffeeScript::autoCompletionWordSeparators() const
{
    QStringList wordList;

    wordList << ".";

    return wordList;
}

const char *TpLexerCoffeeScript::blockEnd(int *style) const
{
    if (style)
        *style = Operator;

    return "}";
}

const char *TpLexerCoffeeScript::blockStart(int *style) const
{
    if (style)
        *style = Operator;

    return "{";
}

const char *TpLexerCoffeeScript::blockStartKeyword(int *style) const
{
    if (style)
        *style = Keyword;

    return "catch class do else finally for if try until when while";
}

int TpLexerCoffeeScript::braceStyle() const
{
    return Operator;
}

const char *TpLexerCoffeeScript::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_#";
}

QColor TpLexerCoffeeScript::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/GlobalClass", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/CommentBlock", QColor);
    case BlockRegex:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/BlockRegex", QColor);
    case BlockRegexComment:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/BlockRegexComment", QColor);
    case InstanceProperty:
        return GET_SETTINGS("Lexer/CoffeeScript/Color/InstanceProperty", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerCoffeeScript::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/GlobalClass", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/CommentBlock", bool);
    case BlockRegex:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/BlockRegex", bool);
    case BlockRegexComment:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/BlockRegexComment", bool);
    case InstanceProperty:
        return GET_SETTINGS("Lexer/CoffeeScript/Fill/InstanceProperty", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerCoffeeScript::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/GlobalClass", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/CommentBlock", QFont);
    case BlockRegex:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/BlockRegex", QFont);
    case BlockRegexComment:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/BlockRegexComment", QFont);
    case InstanceProperty:
        return GET_SETTINGS("Lexer/CoffeeScript/Font/InstanceProperty", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerCoffeeScript::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/GlobalClass", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/CommentBlock", QColor);
    case BlockRegex:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/BlockRegex", QColor);
    case BlockRegexComment:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/BlockRegexComment", QColor);
    case InstanceProperty:
        return GET_SETTINGS("Lexer/CoffeeScript/BgColor/InstanceProperty", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerCoffeeScript::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerCoffeeScriptKeyword1;
    case 2:
        return lexerCoffeeScriptKeyword2;
    default:
        return 0;
    }
}

QString TpLexerCoffeeScript::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case Comment:
        return tr("C-style comment");
    case CommentLine:
        return tr("C++-style comment");
    case CommentDoc:
        return tr("JavaDoc C-style comment");
    case Number:
        return tr("Number");
    case Keyword:
        return tr("Keyword");
    case DoubleQuotedString:
        return tr("Double-quoted string");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case UUID:
        return tr("IDL UUID");
    case PreProcessor:
        return tr("Pre-processor block");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case UnclosedString:
        return tr("Unclosed string");
    case VerbatimString:
        return tr("C# verbatim string");
    case Regex:
        return tr("Regular expression");
    case CommentLineDoc:
        return tr("JavaDoc C++-style comment");
    case KeywordSet2:
        return tr("Secondary keywords and identifiers");
    case CommentDocKeyword:
        return tr("JavaDoc keyword");
    case CommentDocKeywordError:
        return tr("JavaDoc keyword error");
    case GlobalClass:
        return tr("Global classes");
    case CommentBlock:
        return tr("Block comment");
    case BlockRegex:
        return tr("Block regular expression");
    case BlockRegexComment:
        return tr("Block regular expression comment");
    case InstanceProperty:
        return tr("Instance property");
    }

    return QString();
}

void TpLexerCoffeeScript::refreshProperties()
{
    setLexerProperty(PropFoldAtElse, m_foldAtElse);
    setLexerProperty(PropFoldComments, m_foldComments);
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldPreprocessor, m_foldPreprocessor);
    setLexerProperty(PropStylePreprocessor, m_stylePreprocessor);
    setLexerProperty(PropEnableDollars, m_enableDollars);
    setLexerProperty(PropEnableTripleQuotedStrings, m_enableTripleQuotedStrings);
    setLexerProperty(PropEnableHashQuotedStrings, m_enableHashQuotedStrings);
    setLexerProperty(PropEnableBackQuotedStrings, m_enableBackQuotedString);
    setLexerProperty(PropEnableEscapeSequence, m_enableEscapeSequence);
    setLexerProperty(PropEnableVerbatimEscapeSequence, m_enableVerbatimEscapeSequence);
    setLexerProperty(PropTrackPreprocessor, m_trackPreprocessor);
    setLexerProperty(PropUpdatePreprocessor, m_updatePreprocessor);
    setLexerProperty(PropFoldSyntaxBased, m_syntaxBasedFold);
    setLexerProperty(PropExplicitStart, m_explicitStart);
    setLexerProperty(PropExplicitEnd, m_explicitEnd);
    setLexerProperty(PropExplicitAnywhere, m_explicitAnywhere);
    setLexerProperty(PropFoldPreprocessorAtElse, m_foldPreprocessorAtElse);
}

void TpLexerCoffeeScript::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFoldAtElse: {
        m_foldAtElse = value.toBool();
        emit propertyChanged("fold.at.else", (m_foldAtElse ? "1" : "0"));
        break;
    }
    case PropFoldComments: {
        m_foldComments = value.toBool();
        emit propertyChanged("fold.comments", (m_foldComments ? "1" : "0"));
        break;
    }
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    case PropFoldPreprocessor: {
        m_foldPreprocessor = value.toBool();
        emit propertyChanged("fold.preprocessor", (m_foldPreprocessor ? "1" : "0"));
        break;
    }
    case PropStylePreprocessor: {
        m_stylePreprocessor = value.toBool();
        emit propertyChanged("styling.within.preprocessor", (m_stylePreprocessor ? "1" : "0"));
        break;
    }
    case PropEnableDollars: {
        m_enableDollars = value.toBool();
        emit propertyChanged("lexer.cpp.allow.dollars", (m_enableDollars ? "1" : "0"));
        break;
    }
    case PropEnableTripleQuotedStrings: {
        m_enableTripleQuotedStrings = value.toBool();
        emit propertyChanged("lexer.cpp.triplequoted.strings", (m_enableTripleQuotedStrings ? "1" : "0"));
        break;
    }
    case PropEnableHashQuotedStrings: {
        m_enableHashQuotedStrings = value.toBool();
        emit propertyChanged("lexer.cpp.hashquoted.strings", (m_enableHashQuotedStrings ? "1" : "0"));
        break;
    }
    case PropEnableBackQuotedStrings: {
        m_enableBackQuotedString = value.toBool();
        emit propertyChanged("lexer.cpp.backquoted.strings", (m_enableBackQuotedString ? "1" : "0"));
        break;
    }
    case PropEnableEscapeSequence: {
        m_enableEscapeSequence = value.toBool();
        emit propertyChanged("lexer.cpp.escape.sequence", (m_enableEscapeSequence ? "1" : "0"));
        break;
    }
    case PropEnableVerbatimEscapeSequence: {
        m_enableVerbatimEscapeSequence = value.toBool();
        emit propertyChanged("lexer.cpp.verbatim.strings.allow.escapes", (m_enableVerbatimEscapeSequence ? "1" : "0"));
        break;
    }
    case PropTrackPreprocessor: {
        m_trackPreprocessor = value.toBool();
        emit propertyChanged("lexer.cpp.track.preprocessor", (m_trackPreprocessor ? "1" : "0"));
        break;
    }
    case PropUpdatePreprocessor: {
        m_trackPreprocessor = value.toBool();
        emit propertyChanged("lexer.cpp.update.preprocessor", (m_updatePreprocessor ? "1" : "0"));
        break;
    }
    case PropFoldSyntaxBased: {
        m_syntaxBasedFold = value.toBool();
        emit propertyChanged("fold.cpp.syntax.based", (m_syntaxBasedFold ? "1" : "0"));
        break;
    }
    case PropExplicitStart: {
        m_explicitStart = value.toString();
        emit propertyChanged("fold.cpp.explicit.start", textAsBytes(m_explicitStart).constData());
        break;
    }
    case PropExplicitEnd: {
        m_explicitEnd = value.toString();
        emit propertyChanged("fold.cpp.explicit.end", textAsBytes(m_explicitEnd).constData());
        break;
    }
    case PropExplicitAnywhere: {
        m_explicitAnywhere = value.toBool();
        emit propertyChanged("fold.cpp.explicit.anywhere", (m_explicitAnywhere ? "1" : "0"));
        break;
    }
    case PropFoldPreprocessorAtElse: {
        m_foldPreprocessorAtElse = value.toBool();
        emit propertyChanged("fold.preprocessor.at.else", (m_foldPreprocessorAtElse ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerCoffeeScript::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldAtElse:
        return m_foldAtElse;
    case PropFoldComments:
        return m_foldComments;
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldPreprocessor:
        return m_foldPreprocessor;
    case PropStylePreprocessor:
        return m_stylePreprocessor;
    case PropEnableDollars:
        return m_enableDollars;
    case PropEnableTripleQuotedStrings:
        return m_enableTripleQuotedStrings;
    case PropEnableBackQuotedStrings:
        return m_enableBackQuotedString;
    case PropEnableEscapeSequence:
        return m_enableEscapeSequence;
    case PropEnableVerbatimEscapeSequence:
        return m_enableVerbatimEscapeSequence;
    case PropTrackPreprocessor:
        return m_trackPreprocessor;
    case PropUpdatePreprocessor:
        return m_updatePreprocessor;
    case PropFoldSyntaxBased:
        return m_syntaxBasedFold;
    case PropExplicitStart:
        return m_explicitStart;
    case PropExplicitEnd:
        return m_explicitEnd;
    case PropExplicitAnywhere:
        return m_explicitAnywhere;
    case PropFoldPreprocessorAtElse:
        return m_foldPreprocessorAtElse;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerCoffeeScript::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldAtElse = GET_SETTINGS_WITH(prefix + "foldatelse", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldPreprocessor = GET_SETTINGS_WITH(prefix + "foldpreprocessor", bool, true);
    m_stylePreprocessor = GET_SETTINGS_WITH(prefix + "stylepreprocessor", bool, true);
    m_enableDollars = GET_SETTINGS_WITH(prefix + "dollars", bool, true);
    m_enableTripleQuotedStrings = GET_SETTINGS_WITH(prefix + "highlighttripl", bool, false);
    m_enableHashQuotedStrings = GET_SETTINGS_WITH(prefix + "highlighthash", bool, false);
    m_enableEscapeSequence = GET_SETTINGS_WITH(prefix + "highlightescape", bool, true);
    m_enableVerbatimEscapeSequence = GET_SETTINGS_WITH(prefix + "verbatimstringescape", bool, false);
    m_trackPreprocessor = GET_SETTINGS_WITH(prefix + "trackpreprocessor", bool, true);
    m_updatePreprocessor = GET_SETTINGS_WITH(prefix + "updatepreprocessor", bool, true);
    m_syntaxBasedFold = GET_SETTINGS_WITH(prefix + "foldsyntax", bool, true);
    m_explicitStart = GET_SETTINGS_WITH(prefix + "explicitstart", QString, "//{");
    m_explicitEnd = GET_SETTINGS_WITH(prefix + "explicitend", QString, "//}");
    m_explicitAnywhere = GET_SETTINGS_WITH(prefix + "explicitanywhere", bool, false);
    m_foldPreprocessorAtElse = GET_SETTINGS_WITH(prefix + "foldpreprocessoratelse", bool, true);

    return true;
}

bool TpLexerCoffeeScript::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldatelse", m_foldAtElse);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldpreprocessor", m_foldPreprocessor);
    SET_SETTINGS(prefix + "stylepreprocessor", m_stylePreprocessor);
    SET_SETTINGS(prefix + "dollars", m_enableDollars);
    SET_SETTINGS(prefix + "highlighttriple", m_enableTripleQuotedStrings);
    SET_SETTINGS(prefix + "highlighthash", m_enableHashQuotedStrings);
    SET_SETTINGS(prefix + "highlightback", m_enableBackQuotedString);
    SET_SETTINGS(prefix + "highlightescape", m_enableEscapeSequence);
    SET_SETTINGS(prefix + "verbatimstringescape", m_enableVerbatimEscapeSequence);
    SET_SETTINGS(prefix + "trackpreprocessor", m_trackPreprocessor);
    SET_SETTINGS(prefix + "updatepreprocessor", m_updatePreprocessor);
    SET_SETTINGS(prefix + "foldsyntax", m_syntaxBasedFold);
    SET_SETTINGS(prefix + "explicitanywhere", m_explicitAnywhere);
    SET_SETTINGS(prefix + "foldpreprocessoratelse", m_foldPreprocessorAtElse);

    return true;
}

TP_END_NAMESPACE
