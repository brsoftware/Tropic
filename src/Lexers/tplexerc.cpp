#include <Lexers/TpLexerC>

TP_NAMESPACE

TpLexerC::TpLexerC(QObject *parent)
    : TpFamilyCLexer(parent)
{}

const char *TpLexerC::language() const
{
    return "C";
}

QColor TpLexerC::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/C/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/C/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/C/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/C/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/C/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/C/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/C/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/C/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/C/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/C/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/C/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/C/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/C/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/C/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/C/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/C/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/C/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/C/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/C/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/C/Color/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/C/Color/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/C/Color/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/C/Color/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/C/Color/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/C/Color/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/C/Color/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/C/Color/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/C/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/C/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/C/Color/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/C/Color/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/C/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/C/Color/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/C/Color/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/C/Color/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/C/Color/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/C/Color/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/C/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/C/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/C/Color/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/C/Color/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/C/Color/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/C/Color/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/C/Color/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/C/Color/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/C/Color/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/C/Color/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/C/Color/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/C/Color/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/C/Color/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/C/Color/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/C/Color/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/C/Color/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/C/Color/InactiveTaskMarker", QColor);
    }

    return TpFamilyCLexer::defaultColor(style);
}

bool TpLexerC::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/C/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/C/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/C/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/C/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/C/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/C/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/C/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/C/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Lexer/C/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/C/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/C/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/C/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/C/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/C/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Lexer/C/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/C/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/C/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/C/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/C/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Lexer/C/Fill/GlobalClass", bool);
    case RawString:
        return GET_SETTINGS("Lexer/C/Fill/RawString", bool);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/C/Fill/TripleQuotedVerbatimString", bool);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/C/Fill/HashQuotedString", bool);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/C/Fill/PreProcessorComment", bool);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/C/Fill/PreProcessorCommentLineDoc", bool);
    case UserLiteral:
        return GET_SETTINGS("Lexer/C/Fill/UserLiteral", bool);
    case TaskMarker:
        return GET_SETTINGS("Lexer/C/Fill/TaskMarker", bool);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/C/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Lexer/C/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/C/Fill/InactiveCommentLine", bool);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/C/Fill/InactiveCommentDoc", bool);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/C/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/C/Fill/InactiveKeyword", bool);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/C/Fill/InactiveDoubleQuotedString", bool);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/C/Fill/InactiveSingleQuotedString", bool);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/C/Fill/InactiveUUID", bool);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/C/Fill/InactivePreProcessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/C/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/C/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/C/Fill/InactiveUnclosedString", bool);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/C/Fill/InactiveVerbatimString", bool);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/C/Fill/InactiveRegex", bool);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/C/Fill/InactiveCommentLineDoc", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/C/Fill/InactiveKeywordSet2", bool);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/C/Fill/InactiveCommentDocKeyword", bool);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/C/Fill/InactiveCommentDocKeywordError", bool);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/C/Fill/InactiveGlobalClass", bool);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/C/Fill/InactiveRawString", bool);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/C/Fill/InactiveTripleQuotedVerbatimString", bool);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/C/Fill/InactiveHashQuotedString", bool);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/C/Fill/InactivePreProcessorComment", bool);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/C/Fill/InactivePreProcessorCommentLineDoc", bool);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/C/Fill/InactiveUserLiteral", bool);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/C/Fill/InactiveTaskMarker", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerC::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/C/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/C/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/C/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/C/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/C/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/C/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/C/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/C/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Lexer/C/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/C/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/C/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/C/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/C/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/C/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/C/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/C/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/C/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/C/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/C/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Lexer/C/Font/GlobalClass", QFont);
    case RawString:
        return GET_SETTINGS("Lexer/C/Font/RawString", QFont);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/C/Font/TripleQuotedVerbatimString", QFont);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/C/Font/HashQuotedString", QFont);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/C/Font/PreProcessorComment", QFont);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/C/Font/PreProcessorCommentLineDoc", QFont);
    case UserLiteral:
        return GET_SETTINGS("Lexer/C/Font/UserLiteral", QFont);
    case TaskMarker:
        return GET_SETTINGS("Lexer/C/Font/TaskMarker", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/C/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Lexer/C/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/C/Font/InactiveCommentLine", QFont);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/C/Font/InactiveCommentDoc", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/C/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/C/Font/InactiveKeyword", QFont);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/C/Font/InactiveDoubleQuotedString", QFont);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/C/Font/InactiveSingleQuotedString", QFont);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/C/Font/InactiveUUID", QFont);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/C/Font/InactivePreProcessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/C/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/C/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/C/Font/InactiveUnclosedString", QFont);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/C/Font/InactiveVerbatimString", QFont);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/C/Font/InactiveRegex", QFont);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/C/Font/InactiveCommentLineDoc", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/C/Font/InactiveKeywordSet2", QFont);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/C/Font/InactiveCommentDocKeyword", QFont);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/C/Font/InactiveCommentDocKeywordError", QFont);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/C/Font/InactiveGlobalClass", QFont);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/C/Font/InactiveRawString", QFont);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/C/Font/InactiveTripleQuotedVerbatimString", QFont);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/C/Font/InactiveHashQuotedString", QFont);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/C/Font/InactivePreProcessorComment", QFont);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/C/Font/InactivePreProcessorCommentLineDoc", QFont);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/C/Font/InactiveUserLiteral", QFont);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/C/Font/InactiveTaskMarker", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerC::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/C/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/C/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/C/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/C/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/C/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/C/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/C/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/C/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/C/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/C/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/C/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/C/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/C/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/C/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/C/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/C/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/C/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/C/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/C/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/C/BgColor/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/C/BgColor/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/C/BgColor/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/C/BgColor/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/C/BgColor/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/C/BgColor/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/C/BgColor/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/C/BgColor/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/C/BgColor/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/C/BgColor/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/C/BgColor/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/C/BgColor/InactiveTaskMarker", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerC::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerCKeyword1;
    case 2:
        return lexerCKeyword2;
    case 3:
        return lexerGeneralDoxygen;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
