#include <Lexers/TpFamilyCLexer>

TP_NAMESPACE

TpFamilyCLexer::TpFamilyCLexer(QObject *parent)
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

TpFamilyCLexer::~TpFamilyCLexer()
{}

int TpFamilyCLexer::autoIndentStyle()
{
    DEF_SETTINGS;
    if (GET_SETTINGS("Tools/Autoindentation/Style/Auto", bool))
        return 0;

    return TpGeneralLexer::autoIndentStyle();
}

const char *TpFamilyCLexer::language() const
{
    return "C++";
}

const char *TpFamilyCLexer::lexer() const
{
    return "cpp";
}

QStringList TpFamilyCLexer::autoCompletionWordSeparators() const
{
    QStringList wordList;
    wordList << "::" << "->" << ".";
    return wordList;
}

const char *TpFamilyCLexer::blockStartKeyword(int *style) const
{
    if (style)
        *style = Keyword;

    return "case catch class default do else finally for if private protected public struct try union while";
}

const char *TpFamilyCLexer::blockStart(int *style) const
{
    if (style)
        *style = Operator;

    return "{";
}

const char *TpFamilyCLexer::blockEnd(int *style) const
{
    if (style)
        *style = Operator;

    return "}";
}

int TpFamilyCLexer::braceStyle() const
{
    return Operator;
}

const char *TpFamilyCLexer::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_#";
}

QColor TpFamilyCLexer::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Editor/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Editor/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Editor/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Editor/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Editor/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Editor/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Editor/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Editor/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Editor/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Editor/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Editor/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Editor/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Editor/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Editor/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Editor/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Editor/Color/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Editor/Color/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Editor/Color/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Editor/Color/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Editor/Color/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Editor/Color/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Editor/Color/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Editor/Color/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Editor/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Editor/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Editor/Color/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Editor/Color/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Editor/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Editor/Color/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Editor/Color/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Editor/Color/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Editor/Color/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Editor/Color/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Editor/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Editor/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Editor/Color/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Editor/Color/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Editor/Color/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Editor/Color/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Editor/Color/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Editor/Color/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Editor/Color/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Editor/Color/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Editor/Color/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Editor/Color/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Editor/Color/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Editor/Color/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Editor/Color/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Editor/Color/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Editor/Color/InactiveTaskMarker", QColor);
    default:
        return GET_SETTINGS("Editor/Color/Universal", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpFamilyCLexer::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Editor/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Editor/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Editor/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Editor/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Editor/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Editor/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Editor/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Editor/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Editor/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Editor/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Editor/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Editor/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Editor/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Editor/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Editor/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Editor/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Editor/Fill/GlobalClass", bool);
    case RawString:
        return GET_SETTINGS("Editor/Fill/RawString", bool);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Editor/Fill/TripleQuotedVerbatimString", bool);
    case HashQuotedString:
        return GET_SETTINGS("Editor/Fill/HashQuotedString", bool);
    case PreProcessorComment:
        return GET_SETTINGS("Editor/Fill/PreProcessorComment", bool);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Editor/Fill/PreProcessorCommentLineDoc", bool);
    case UserLiteral:
        return GET_SETTINGS("Editor/Fill/UserLiteral", bool);
    case TaskMarker:
        return GET_SETTINGS("Editor/Fill/TaskMarker", bool);
    case InactiveDefault:
        return GET_SETTINGS("Editor/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Editor/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Editor/Fill/InactiveCommentLine", bool);
    case InactiveCommentDoc:
        return GET_SETTINGS("Editor/Fill/InactiveCommentDoc", bool);
    case InactiveNumber:
        return GET_SETTINGS("Editor/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Editor/Fill/InactiveKeyword", bool);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Editor/Fill/InactiveDoubleQuotedString", bool);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Editor/Fill/InactiveSingleQuotedString", bool);
    case InactiveUUID:
        return GET_SETTINGS("Editor/Fill/InactiveUUID", bool);
    case InactivePreProcessor:
        return GET_SETTINGS("Editor/Fill/InactivePreProcessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Editor/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Editor/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Editor/Fill/InactiveUnclosedString", bool);
    case InactiveVerbatimString:
        return GET_SETTINGS("Editor/Fill/InactiveVerbatimString", bool);
    case InactiveRegex:
        return GET_SETTINGS("Editor/Fill/InactiveRegex", bool);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Editor/Fill/InactiveCommentLineDoc", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Editor/Fill/InactiveKeywordSet2", bool);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Editor/Fill/InactiveCommentDocKeyword", bool);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Editor/Fill/InactiveCommentDocKeywordError", bool);
    case InactiveGlobalClass:
        return GET_SETTINGS("Editor/Fill/InactiveGlobalClass", bool);
    case InactiveRawString:
        return GET_SETTINGS("Editor/Fill/InactiveRawString", bool);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Editor/Fill/InactiveTripleQuotedVerbatimString", bool);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Editor/Fill/InactiveHashQuotedString", bool);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Editor/Fill/InactivePreProcessorComment", bool);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Editor/Fill/InactivePreProcessorCommentLineDoc", bool);
    case InactiveUserLiteral:
        return GET_SETTINGS("Editor/Fill/InactiveUserLiteral", bool);
    case InactiveTaskMarker:
        return GET_SETTINGS("Editor/Fill/InactiveTaskMarker", bool);
    default:
        return GET_SETTINGS("Editor/Fill/Universal", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpFamilyCLexer::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Editor/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Editor/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Editor/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Editor/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Editor/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Editor/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Editor/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Editor/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Editor/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Editor/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Editor/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Editor/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Editor/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Editor/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Editor/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Editor/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Editor/Font/GlobalClass", QFont);
    case RawString:
        return GET_SETTINGS("Editor/Font/RawString", QFont);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Editor/Font/TripleQuotedVerbatimString", QFont);
    case HashQuotedString:
        return GET_SETTINGS("Editor/Font/HashQuotedString", QFont);
    case PreProcessorComment:
        return GET_SETTINGS("Editor/Font/PreProcessorComment", QFont);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Editor/Font/PreProcessorCommentLineDoc", QFont);
    case UserLiteral:
        return GET_SETTINGS("Editor/Font/UserLiteral", QFont);
    case TaskMarker:
        return GET_SETTINGS("Editor/Font/TaskMarker", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Editor/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Editor/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Editor/Font/InactiveCommentLine", QFont);
    case InactiveCommentDoc:
        return GET_SETTINGS("Editor/Font/InactiveCommentDoc", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Editor/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Editor/Font/InactiveKeyword", QFont);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Editor/Font/InactiveDoubleQuotedString", QFont);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Editor/Font/InactiveSingleQuotedString", QFont);
    case InactiveUUID:
        return GET_SETTINGS("Editor/Font/InactiveUUID", QFont);
    case InactivePreProcessor:
        return GET_SETTINGS("Editor/Font/InactivePreProcessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Editor/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Editor/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Editor/Font/InactiveUnclosedString", QFont);
    case InactiveVerbatimString:
        return GET_SETTINGS("Editor/Font/InactiveVerbatimString", QFont);
    case InactiveRegex:
        return GET_SETTINGS("Editor/Font/InactiveRegex", QFont);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Editor/Font/InactiveCommentLineDoc", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Editor/Font/InactiveKeywordSet2", QFont);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Editor/Font/InactiveCommentDocKeyword", QFont);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Editor/Font/InactiveCommentDocKeywordError", QFont);
    case InactiveGlobalClass:
        return GET_SETTINGS("Editor/Font/InactiveGlobalClass", QFont);
    case InactiveRawString:
        return GET_SETTINGS("Editor/Font/InactiveRawString", QFont);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Editor/Font/InactiveTripleQuotedVerbatimString", QFont);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Editor/Font/InactiveHashQuotedString", QFont);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Editor/Font/InactivePreProcessorComment", QFont);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Editor/Font/InactivePreProcessorCommentLineDoc", QFont);
    case InactiveUserLiteral:
        return GET_SETTINGS("Editor/Font/InactiveUserLiteral", QFont);
    case InactiveTaskMarker:
        return GET_SETTINGS("Editor/Font/InactiveTaskMarker", QFont);
    default:
        return GET_SETTINGS("Editor/Font/Universal", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpFamilyCLexer::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Editor/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Editor/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Editor/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Editor/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Editor/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Editor/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Editor/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Editor/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Editor/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Editor/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Editor/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Editor/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Editor/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Editor/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Editor/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Editor/BgColor/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Editor/BgColor/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Editor/BgColor/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Editor/BgColor/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Editor/BgColor/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Editor/BgColor/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Editor/BgColor/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Editor/BgColor/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Editor/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Editor/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Editor/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Editor/BgColor/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Editor/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Editor/BgColor/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Editor/BgColor/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Editor/BgColor/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Editor/BgColor/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Editor/BgColor/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Editor/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Editor/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Editor/BgColor/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Editor/BgColor/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Editor/BgColor/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Editor/BgColor/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Editor/BgColor/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Editor/BgColor/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Editor/BgColor/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Editor/BgColor/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Editor/BgColor/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Editor/BgColor/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Editor/BgColor/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Editor/BgColor/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Editor/BgColor/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Editor/BgColor/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Editor/BgColor/InactiveTaskMarker", QColor);
    default:
        return GET_SETTINGS("Editor/BgColor/Universal", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpFamilyCLexer::keywords(int set) const
{
    return 0;
}

QString TpFamilyCLexer::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case InactiveDefault:
        return tr("Inactive default");
    case Comment:
        return tr("C comment");
    case InactiveComment:
        return tr("Inactive C comment");
    case CommentLine:
        return tr("C++ comment");
    case InactiveCommentLine:
        return tr("Inactive C++ comment");
    case CommentDoc:
        return tr("JavaDoc style C comment");
    case InactiveCommentDoc:
        return tr("Inactive JavaDoc style C comment");
    case Number:
        return tr("Number");
    case InactiveNumber:
        return tr("Inactive number");
    case Keyword:
        return tr("Keyword");
    case InactiveKeyword:
        return tr("Inactive keyword");
    case DoubleQuotedString:
        return tr("Double-quoted string");
    case InactiveDoubleQuotedString:
        return tr("Inactive double-quoted string");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case InactiveSingleQuotedString:
        return tr("Inactive single-quoted string");
    case UUID:
        return tr("IDL UUID");
    case InactiveUUID:
        return tr("Inactive IDL UUID");
    case PreProcessor:
        return tr("Pre-processor block");
    case InactivePreProcessor:
        return tr("Inactive pre-processor block");
    case Operator:
        return tr("Operator");
    case InactiveOperator:
        return tr("Inactive operator");
    case Identifier:
        return tr("Identifier");
    case InactiveIdentifier:
        return tr("Inactive identifier");
    case UnclosedString:
        return tr("Unclosed string");
    case InactiveUnclosedString:
        return tr("Inactive unclosed string");
    case VerbatimString:
        return tr("C# verbatim string");
    case InactiveVerbatimString:
        return tr("Inactive C# verbatim string");
    case Regex:
        return tr("JavaScript regular expression");
    case InactiveRegex:
        return tr("Inactive JavaScript regular expression");
    case CommentLineDoc:
        return tr("JavaDoc style C++ comment");
    case InactiveCommentLineDoc:
        return tr("Inactive JavaDoc style C++ comment");
    case KeywordSet2:
        return tr("Secondary keywords and identifiers");
    case InactiveKeywordSet2:
        return tr("Inactive secondary keywords and identifiers");
    case CommentDocKeyword:
        return tr("JavaDoc keyword");
    case InactiveCommentDocKeyword:
        return tr("Inactive JavaDoc keyword");
    case CommentDocKeywordError:
        return tr("JavaDoc keyword error");
    case InactiveCommentDocKeywordError:
        return tr("Inactive JavaDoc keyword error");
    case GlobalClass:
        return tr("Global classes and typedefs");
    case InactiveGlobalClass:
        return tr("Inactive global classes and typedefs");
    case RawString:
        return tr("C++ raw string");
    case InactiveRawString:
        return tr("Inactive C++ raw string");
    case TripleQuotedVerbatimString:
        return tr("Vala triple-quoted verbatim string");
    case InactiveTripleQuotedVerbatimString:
        return tr("Inactive Vala triple-quoted verbatim string");
    case HashQuotedString:
        return tr("Pike hash-quoted string");
    case InactiveHashQuotedString:
        return tr("Inactive Pike hash-quoted string");
    case PreProcessorComment:
        return tr("Pre-processor C comment");
    case InactivePreProcessorComment:
        return tr("Inactive pre-processor C comment");
    case PreProcessorCommentLineDoc:
        return tr("JavaDoc style pre-processor comment");
    case InactivePreProcessorCommentLineDoc:
        return tr("Inactive JavaDoc style pre-processor comment");
    case UserLiteral:
        return tr("User-defined literal");
    case InactiveUserLiteral:
        return tr("Inactive user-defined literal");
    case TaskMarker:
        return tr("Task marker");
    case InactiveTaskMarker:
        return tr("Inactive task marker");
    case EscapeSequence:
        return tr("Escape sequence");
    case InactiveEscapeSequence:
        return tr("Inactive escape sequence");
    }

    return QString();
}

void TpFamilyCLexer::refreshProperties()
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

void TpFamilyCLexer::setLexerProperty(int prop, QVariant value)
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

QVariant TpFamilyCLexer::lexerProperty(int prop) const
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

bool TpFamilyCLexer::readProperties(QSettings &settings, const QString &prefix)
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

bool TpFamilyCLexer::writeProperties(QSettings &settings, const QString &prefix) const
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
