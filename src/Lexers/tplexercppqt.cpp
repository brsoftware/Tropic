#include <Lexers/TpLexerCPPQt>

TP_NAMESPACE

TpLexerCPPQt::TpLexerCPPQt(QObject *parent)
    : TpFamilyCLexer(parent)
{}

const char *TpLexerCPPQt::language() const
{
    return "C++ (Qt)";
}

QColor TpLexerCPPQt::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CPPQt/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CPPQt/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/CPPQt/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CPPQt/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/CPPQt/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/CPPQt/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/CPPQt/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CPPQt/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/CPPQt/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/CPPQt/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CPPQt/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/CPPQt/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CPPQt/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CPPQt/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPPQt/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CPPQt/Color/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/CPPQt/Color/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Color/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Color/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CPPQt/Color/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Color/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CPPQt/Color/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CPPQt/Color/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CPPQt/Color/InactiveTaskMarker", QColor);
    }

    return TpFamilyCLexer::defaultColor(style);
}

bool TpLexerCPPQt::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CPPQt/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/CPPQt/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/CPPQt/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CPPQt/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/CPPQt/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/CPPQt/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Lexer/CPPQt/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CPPQt/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/CPPQt/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/CPPQt/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Lexer/CPPQt/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CPPQt/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CPPQt/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPPQt/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CPPQt/Fill/GlobalClass", bool);
    case RawString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/RawString", bool);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/TripleQuotedVerbatimString", bool);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/HashQuotedString", bool);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CPPQt/Fill/PreProcessorComment", bool);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Fill/PreProcessorCommentLineDoc", bool);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CPPQt/Fill/UserLiteral", bool);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CPPQt/Fill/TaskMarker", bool);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveCommentLine", bool);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveCommentDoc", bool);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveKeyword", bool);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveDoubleQuotedString", bool);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveSingleQuotedString", bool);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveUUID", bool);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactivePreProcessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveUnclosedString", bool);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveVerbatimString", bool);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveRegex", bool);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveCommentLineDoc", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveKeywordSet2", bool);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveCommentDocKeyword", bool);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveCommentDocKeywordError", bool);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveGlobalClass", bool);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveRawString", bool);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveTripleQuotedVerbatimString", bool);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveHashQuotedString", bool);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactivePreProcessorComment", bool);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactivePreProcessorCommentLineDoc", bool);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveUserLiteral", bool);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CPPQt/Fill/InactiveTaskMarker", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerCPPQt::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CPPQt/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/CPPQt/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/CPPQt/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CPPQt/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/CPPQt/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/CPPQt/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Lexer/CPPQt/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CPPQt/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/CPPQt/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/CPPQt/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CPPQt/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/CPPQt/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CPPQt/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CPPQt/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPPQt/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CPPQt/Font/GlobalClass", QFont);
    case RawString:
        return GET_SETTINGS("Lexer/CPPQt/Font/RawString", QFont);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Font/TripleQuotedVerbatimString", QFont);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Font/HashQuotedString", QFont);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CPPQt/Font/PreProcessorComment", QFont);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Font/PreProcessorCommentLineDoc", QFont);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CPPQt/Font/UserLiteral", QFont);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CPPQt/Font/TaskMarker", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveCommentLine", QFont);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveCommentDoc", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveKeyword", QFont);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveDoubleQuotedString", QFont);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveSingleQuotedString", QFont);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveUUID", QFont);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactivePreProcessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveUnclosedString", QFont);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveVerbatimString", QFont);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveRegex", QFont);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveCommentLineDoc", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveKeywordSet2", QFont);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveCommentDocKeyword", QFont);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveCommentDocKeywordError", QFont);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveGlobalClass", QFont);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveRawString", QFont);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveTripleQuotedVerbatimString", QFont);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveHashQuotedString", QFont);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactivePreProcessorComment", QFont);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactivePreProcessorCommentLineDoc", QFont);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveUserLiteral", QFont);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CPPQt/Font/InactiveTaskMarker", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerCPPQt::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CPPQt/BgColor/InactiveTaskMarker", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerCPPQt::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerCPPQtKeyword1;
    case 2:
    case 5:
        return lexerCPPQtKeyword2;
    case 3:
        return lexerGeneralDoxygen;
    case 4:
        return lexerCPPQtKeyword4;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
