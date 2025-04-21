#include <Lexers/TpLexerJava>

TP_NAMESPACE

TpLexerJava::TpLexerJava(QObject *parent)
    : TpFamilyCLexer(parent)
{}

const char *TpLexerJava::language() const
{
    return "Java";
}

QColor TpLexerJava::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/Java/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/Java/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Java/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Java/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Java/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Java/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Java/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/Java/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Java/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Java/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Java/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Java/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/Java/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/Java/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/Java/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/Java/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/Java/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/Java/Color/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/Java/Color/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/Java/Color/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/Java/Color/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/Java/Color/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Color/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/Java/Color/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/Java/Color/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/Java/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/Java/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/Java/Color/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/Java/Color/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/Java/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/Java/Color/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/Java/Color/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/Java/Color/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/Java/Color/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/Java/Color/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/Java/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/Java/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/Java/Color/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/Java/Color/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/Java/Color/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Color/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/Java/Color/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/Java/Color/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/Java/Color/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/Java/Color/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/Java/Color/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/Java/Color/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/Java/Color/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/Java/Color/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Color/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/Java/Color/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/Java/Color/InactiveTaskMarker", QColor);
    default:
        return GET_SETTINGS("Lexer/Java/Color/Universal", QColor);
    }

    return TpFamilyCLexer::defaultColor(style);
}

bool TpLexerJava::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/Java/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/Java/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Java/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/Java/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Java/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Java/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Java/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Lexer/Java/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Java/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Java/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Java/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Java/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/Java/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Lexer/Java/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/Java/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/Java/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/Java/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Lexer/Java/Fill/GlobalClass", bool);
    case RawString:
        return GET_SETTINGS("Lexer/Java/Fill/RawString", bool);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/Java/Fill/TripleQuotedVerbatimString", bool);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/Java/Fill/HashQuotedString", bool);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/Java/Fill/PreProcessorComment", bool);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Fill/PreProcessorCommentLineDoc", bool);
    case UserLiteral:
        return GET_SETTINGS("Lexer/Java/Fill/UserLiteral", bool);
    case TaskMarker:
        return GET_SETTINGS("Lexer/Java/Fill/TaskMarker", bool);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveCommentLine", bool);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveCommentDoc", bool);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveKeyword", bool);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveDoubleQuotedString", bool);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveSingleQuotedString", bool);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveUUID", bool);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/Java/Fill/InactivePreProcessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveUnclosedString", bool);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveVerbatimString", bool);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveRegex", bool);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveCommentLineDoc", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveKeywordSet2", bool);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveCommentDocKeyword", bool);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveCommentDocKeywordError", bool);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveGlobalClass", bool);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveRawString", bool);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveTripleQuotedVerbatimString", bool);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveHashQuotedString", bool);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/Java/Fill/InactivePreProcessorComment", bool);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Fill/InactivePreProcessorCommentLineDoc", bool);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveUserLiteral", bool);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/Java/Fill/InactiveTaskMarker", bool);
    default:
        return GET_SETTINGS("Lexer/Java/Fill/Universal", bool);
    }

    return GET_SETTINGS("Lexer/Java/Fill/Universal", bool);
}

QFont TpLexerJava::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/Java/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/Java/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Java/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Java/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Java/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Java/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Java/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Lexer/Java/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Java/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Java/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Java/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Java/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/Java/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/Java/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/Java/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/Java/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/Java/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Lexer/Java/Font/GlobalClass", QFont);
    case RawString:
        return GET_SETTINGS("Lexer/Java/Font/RawString", QFont);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/Java/Font/TripleQuotedVerbatimString", QFont);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/Java/Font/HashQuotedString", QFont);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/Java/Font/PreProcessorComment", QFont);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Font/PreProcessorCommentLineDoc", QFont);
    case UserLiteral:
        return GET_SETTINGS("Lexer/Java/Font/UserLiteral", QFont);
    case TaskMarker:
        return GET_SETTINGS("Lexer/Java/Font/TaskMarker", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/Java/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Lexer/Java/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/Java/Font/InactiveCommentLine", QFont);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/Java/Font/InactiveCommentDoc", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/Java/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/Java/Font/InactiveKeyword", QFont);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/Java/Font/InactiveDoubleQuotedString", QFont);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/Java/Font/InactiveSingleQuotedString", QFont);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/Java/Font/InactiveUUID", QFont);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/Java/Font/InactivePreProcessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/Java/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/Java/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/Java/Font/InactiveUnclosedString", QFont);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/Java/Font/InactiveVerbatimString", QFont);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/Java/Font/InactiveRegex", QFont);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Font/InactiveCommentLineDoc", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/Java/Font/InactiveKeywordSet2", QFont);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/Java/Font/InactiveCommentDocKeyword", QFont);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/Java/Font/InactiveCommentDocKeywordError", QFont);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/Java/Font/InactiveGlobalClass", QFont);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/Java/Font/InactiveRawString", QFont);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/Java/Font/InactiveTripleQuotedVerbatimString", QFont);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/Java/Font/InactiveHashQuotedString", QFont);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/Java/Font/InactivePreProcessorComment", QFont);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/Font/InactivePreProcessorCommentLineDoc", QFont);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/Java/Font/InactiveUserLiteral", QFont);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/Java/Font/InactiveTaskMarker", QFont);
    default:
        return GET_SETTINGS("Lexer/Java/Font/Universal", QFont);
    }

    return TpFamilyCLexer::defaultFont(style);
}

QColor TpLexerJava::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/Java/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/Java/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Java/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Java/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Java/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Java/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Java/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/Java/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Java/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Java/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Java/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Java/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/Java/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/Java/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/Java/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/Java/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/Java/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/Java/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/Java/BgColor/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/Java/BgColor/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/Java/BgColor/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/Java/BgColor/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/Java/BgColor/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/BgColor/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/Java/BgColor/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/Java/BgColor/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/Java/BgColor/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/Java/BgColor/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/Java/BgColor/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/Java/BgColor/InactiveTaskMarker", QColor);
    default:
        return GET_SETTINGS("Lexer/Java/BgColor/Universal", QColor);
    }

    return TpFamilyCLexer::defaultPaper(style);
}

const char *TpLexerJava::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerJavaKeyword1;
    case 3:
        return lexerGeneralDoxygen;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
