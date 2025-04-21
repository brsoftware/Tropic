#include <Lexers/TpLexerCS>

TP_NAMESPACE

TpLexerCS::TpLexerCS(QObject *parent)
    : TpFamilyCLexer(parent)
{}

const char *TpLexerCS::language() const
{
    return "C#";
}

QColor TpLexerCS::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CS/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CS/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/CS/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CS/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/CS/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/CS/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CS/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CS/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/CS/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CS/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/CS/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/CS/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CS/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CS/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/CS/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CS/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CS/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CS/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CS/Color/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/CS/Color/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CS/Color/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CS/Color/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CS/Color/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Color/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CS/Color/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CS/Color/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CS/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CS/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CS/Color/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CS/Color/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CS/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CS/Color/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CS/Color/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CS/Color/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CS/Color/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CS/Color/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CS/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CS/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CS/Color/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CS/Color/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CS/Color/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Color/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CS/Color/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CS/Color/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CS/Color/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CS/Color/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CS/Color/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CS/Color/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CS/Color/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CS/Color/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Color/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CS/Color/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CS/Color/InactiveTaskMarker", QColor);
    }

    return TpFamilyCLexer::defaultColor(style);
}

bool TpLexerCS::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CS/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/CS/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/CS/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CS/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/CS/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/CS/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CS/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CS/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Lexer/CS/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CS/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/CS/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/CS/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CS/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CS/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Lexer/CS/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CS/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CS/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CS/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CS/Fill/GlobalClass", bool);
    case RawString:
        return GET_SETTINGS("Lexer/CS/Fill/RawString", bool);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CS/Fill/TripleQuotedVerbatimString", bool);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CS/Fill/HashQuotedString", bool);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CS/Fill/PreProcessorComment", bool);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Fill/PreProcessorCommentLineDoc", bool);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CS/Fill/UserLiteral", bool);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CS/Fill/TaskMarker", bool);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveCommentLine", bool);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveCommentDoc", bool);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveKeyword", bool);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveDoubleQuotedString", bool);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveSingleQuotedString", bool);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveUUID", bool);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CS/Fill/InactivePreProcessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveUnclosedString", bool);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveVerbatimString", bool);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveRegex", bool);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveCommentLineDoc", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveKeywordSet2", bool);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveCommentDocKeyword", bool);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveCommentDocKeywordError", bool);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveGlobalClass", bool);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveRawString", bool);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveTripleQuotedVerbatimString", bool);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveHashQuotedString", bool);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CS/Fill/InactivePreProcessorComment", bool);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Fill/InactivePreProcessorCommentLineDoc", bool);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveUserLiteral", bool);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CS/Fill/InactiveTaskMarker", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerCS::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CS/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/CS/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/CS/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CS/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/CS/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/CS/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CS/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CS/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Lexer/CS/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CS/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/CS/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/CS/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CS/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CS/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/CS/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CS/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CS/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CS/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CS/Font/GlobalClass", QFont);
    case RawString:
        return GET_SETTINGS("Lexer/CS/Font/RawString", QFont);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CS/Font/TripleQuotedVerbatimString", QFont);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CS/Font/HashQuotedString", QFont);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CS/Font/PreProcessorComment", QFont);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Font/PreProcessorCommentLineDoc", QFont);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CS/Font/UserLiteral", QFont);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CS/Font/TaskMarker", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CS/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CS/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CS/Font/InactiveCommentLine", QFont);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CS/Font/InactiveCommentDoc", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CS/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CS/Font/InactiveKeyword", QFont);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CS/Font/InactiveDoubleQuotedString", QFont);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CS/Font/InactiveSingleQuotedString", QFont);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CS/Font/InactiveUUID", QFont);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CS/Font/InactivePreProcessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CS/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CS/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CS/Font/InactiveUnclosedString", QFont);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CS/Font/InactiveVerbatimString", QFont);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CS/Font/InactiveRegex", QFont);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Font/InactiveCommentLineDoc", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CS/Font/InactiveKeywordSet2", QFont);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CS/Font/InactiveCommentDocKeyword", QFont);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CS/Font/InactiveCommentDocKeywordError", QFont);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CS/Font/InactiveGlobalClass", QFont);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CS/Font/InactiveRawString", QFont);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CS/Font/InactiveTripleQuotedVerbatimString", QFont);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CS/Font/InactiveHashQuotedString", QFont);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CS/Font/InactivePreProcessorComment", QFont);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/Font/InactivePreProcessorCommentLineDoc", QFont);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CS/Font/InactiveUserLiteral", QFont);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CS/Font/InactiveTaskMarker", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerCS::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CS/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CS/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/CS/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CS/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/CS/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/CS/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CS/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CS/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/CS/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CS/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/CS/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/CS/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CS/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CS/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/CS/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CS/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CS/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CS/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CS/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CS/BgColor/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/CS/BgColor/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CS/BgColor/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CS/BgColor/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CS/BgColor/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/BgColor/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CS/BgColor/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CS/BgColor/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CS/BgColor/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CS/BgColor/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CS/BgColor/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CS/BgColor/InactiveTaskMarker", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerCS::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerCSKeyword1;
    case 2:
        return lexerCSKeyword2;
    case 3:
        return lexerGeneralDoxygen;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
