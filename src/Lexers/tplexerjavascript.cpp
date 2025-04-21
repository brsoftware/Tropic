#include <Lexers/TpLexerJavaScript>

TP_NAMESPACE

TpLexerJavaScript::TpLexerJavaScript(QObject *parent)
    : TpFamilyCLexer(parent)
{}

const char *TpLexerJavaScript::language() const
{
    return "JavaScript";
}

QColor TpLexerJavaScript::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/JavaScript/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/JavaScript/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/JavaScript/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/JavaScript/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/JavaScript/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/JavaScript/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/JavaScript/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/JavaScript/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/JavaScript/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/JavaScript/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/JavaScript/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/JavaScript/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/JavaScript/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/JavaScript/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/JavaScript/Color/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/JavaScript/Color/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Color/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Color/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/JavaScript/Color/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Color/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/JavaScript/Color/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/JavaScript/Color/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/JavaScript/Color/InactiveTaskMarker", QColor);
    default:
        return GET_SETTINGS("Lexer/JavaScript/Color/Universal", QColor);
    }

    return TpFamilyCLexer::defaultColor(style);
}

bool TpLexerJavaScript::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/JavaScript/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/JavaScript/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/JavaScript/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/JavaScript/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/JavaScript/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Lexer/JavaScript/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/JavaScript/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/JavaScript/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/JavaScript/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Lexer/JavaScript/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/JavaScript/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/JavaScript/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/JavaScript/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Lexer/JavaScript/Fill/GlobalClass", bool);
    case RawString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/RawString", bool);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/TripleQuotedVerbatimString", bool);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/HashQuotedString", bool);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/JavaScript/Fill/PreProcessorComment", bool);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Fill/PreProcessorCommentLineDoc", bool);
    case UserLiteral:
        return GET_SETTINGS("Lexer/JavaScript/Fill/UserLiteral", bool);
    case TaskMarker:
        return GET_SETTINGS("Lexer/JavaScript/Fill/TaskMarker", bool);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveCommentLine", bool);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveCommentDoc", bool);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveKeyword", bool);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveDoubleQuotedString", bool);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveSingleQuotedString", bool);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveUUID", bool);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactivePreProcessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveUnclosedString", bool);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveVerbatimString", bool);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveRegex", bool);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveCommentLineDoc", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveKeywordSet2", bool);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveCommentDocKeyword", bool);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveCommentDocKeywordError", bool);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveGlobalClass", bool);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveRawString", bool);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveTripleQuotedVerbatimString", bool);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveHashQuotedString", bool);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactivePreProcessorComment", bool);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactivePreProcessorCommentLineDoc", bool);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveUserLiteral", bool);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/JavaScript/Fill/InactiveTaskMarker", bool);
    default:
        return GET_SETTINGS("Lexer/JavaScript/Fill/Universal", bool);
    }

    return GET_SETTINGS("Lexer/JavaScript/Fill/Universal", bool);
}

QFont TpLexerJavaScript::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/JavaScript/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/JavaScript/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/JavaScript/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/JavaScript/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/JavaScript/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Lexer/JavaScript/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/JavaScript/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/JavaScript/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/JavaScript/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/JavaScript/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/JavaScript/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/JavaScript/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/JavaScript/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/JavaScript/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Lexer/JavaScript/Font/GlobalClass", QFont);
    case RawString:
        return GET_SETTINGS("Lexer/JavaScript/Font/RawString", QFont);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Font/TripleQuotedVerbatimString", QFont);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Font/HashQuotedString", QFont);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/JavaScript/Font/PreProcessorComment", QFont);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Font/PreProcessorCommentLineDoc", QFont);
    case UserLiteral:
        return GET_SETTINGS("Lexer/JavaScript/Font/UserLiteral", QFont);
    case TaskMarker:
        return GET_SETTINGS("Lexer/JavaScript/Font/TaskMarker", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveCommentLine", QFont);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveCommentDoc", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveKeyword", QFont);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveDoubleQuotedString", QFont);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveSingleQuotedString", QFont);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveUUID", QFont);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactivePreProcessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveUnclosedString", QFont);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveVerbatimString", QFont);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveRegex", QFont);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveCommentLineDoc", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveKeywordSet2", QFont);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveCommentDocKeyword", QFont);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveCommentDocKeywordError", QFont);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveGlobalClass", QFont);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveRawString", QFont);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveTripleQuotedVerbatimString", QFont);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveHashQuotedString", QFont);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactivePreProcessorComment", QFont);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactivePreProcessorCommentLineDoc", QFont);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveUserLiteral", QFont);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/JavaScript/Font/InactiveTaskMarker", QFont);
    default:
        return GET_SETTINGS("Lexer/JavaScript/Font/Universal", QFont);
    }

    return TpFamilyCLexer::defaultFont(style);
}

QColor TpLexerJavaScript::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/InactiveTaskMarker", QColor);
    default:
        return GET_SETTINGS("Lexer/JavaScript/BgColor/Universal", QColor);
    }

    return TpFamilyCLexer::defaultPaper(style);
}

const char *TpLexerJavaScript::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerJavaScriptKeyword1;
    case 3:
        return lexerGeneralDoxygen;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
