#include <Lexers/TpLexerCPP>

TP_NAMESPACE

TpLexerCPP::TpLexerCPP(QObject *parent)
    : TpFamilyCLexer(parent)
{}

const char *TpLexerCPP::language() const
{
    return "C++";
}

QColor TpLexerCPP::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CPP/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CPP/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/CPP/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CPP/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/CPP/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/CPP/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/CPP/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CPP/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/CPP/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/CPP/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CPP/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CPP/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/CPP/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CPP/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CPP/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPP/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CPP/Color/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/CPP/Color/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPP/Color/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CPP/Color/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CPP/Color/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Color/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CPP/Color/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CPP/Color/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CPP/Color/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CPP/Color/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Color/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CPP/Color/InactiveTaskMarker", QColor);
    }

    return TpFamilyCLexer::defaultColor(style);
}

bool TpLexerCPP::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CPP/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/CPP/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/CPP/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CPP/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/CPP/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/CPP/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Lexer/CPP/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CPP/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/CPP/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/CPP/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CPP/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CPP/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Lexer/CPP/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CPP/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CPP/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPP/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CPP/Fill/GlobalClass", bool);
    case RawString:
        return GET_SETTINGS("Lexer/CPP/Fill/RawString", bool);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPP/Fill/TripleQuotedVerbatimString", bool);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CPP/Fill/HashQuotedString", bool);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CPP/Fill/PreProcessorComment", bool);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Fill/PreProcessorCommentLineDoc", bool);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CPP/Fill/UserLiteral", bool);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CPP/Fill/TaskMarker", bool);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveCommentLine", bool);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveCommentDoc", bool);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveKeyword", bool);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveDoubleQuotedString", bool);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveSingleQuotedString", bool);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveUUID", bool);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CPP/Fill/InactivePreProcessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveUnclosedString", bool);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveVerbatimString", bool);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveRegex", bool);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveCommentLineDoc", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveKeywordSet2", bool);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveCommentDocKeyword", bool);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveCommentDocKeywordError", bool);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveGlobalClass", bool);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveRawString", bool);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveTripleQuotedVerbatimString", bool);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveHashQuotedString", bool);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CPP/Fill/InactivePreProcessorComment", bool);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Fill/InactivePreProcessorCommentLineDoc", bool);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveUserLiteral", bool);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CPP/Fill/InactiveTaskMarker", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerCPP::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CPP/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/CPP/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/CPP/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CPP/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/CPP/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/CPP/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Lexer/CPP/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CPP/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/CPP/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/CPP/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CPP/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CPP/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/CPP/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CPP/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CPP/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPP/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CPP/Font/GlobalClass", QFont);
    case RawString:
        return GET_SETTINGS("Lexer/CPP/Font/RawString", QFont);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPP/Font/TripleQuotedVerbatimString", QFont);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CPP/Font/HashQuotedString", QFont);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CPP/Font/PreProcessorComment", QFont);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Font/PreProcessorCommentLineDoc", QFont);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CPP/Font/UserLiteral", QFont);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CPP/Font/TaskMarker", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveCommentLine", QFont);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveCommentDoc", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveKeyword", QFont);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveDoubleQuotedString", QFont);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveSingleQuotedString", QFont);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveUUID", QFont);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CPP/Font/InactivePreProcessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveUnclosedString", QFont);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveVerbatimString", QFont);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveRegex", QFont);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveCommentLineDoc", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveKeywordSet2", QFont);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveCommentDocKeyword", QFont);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveCommentDocKeywordError", QFont);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveGlobalClass", QFont);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveRawString", QFont);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveTripleQuotedVerbatimString", QFont);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveHashQuotedString", QFont);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CPP/Font/InactivePreProcessorComment", QFont);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/Font/InactivePreProcessorCommentLineDoc", QFont);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveUserLiteral", QFont);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CPP/Font/InactiveTaskMarker", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerCPP::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CPP/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CPP/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/CPP/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/CPP/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/CPP/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/CPP/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CPP/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CPP/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/CPP/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/CPP/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/CPP/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/CPP/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/CPP/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/CPP/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/CPP/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/CPP/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/CPP/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPP/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/CPP/BgColor/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/CPP/BgColor/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPP/BgColor/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/CPP/BgColor/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/CPP/BgColor/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/BgColor/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/CPP/BgColor/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/CPP/BgColor/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/CPP/BgColor/InactiveTaskMarker", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerCPP::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerCPPKeyword1;
    case 2:
        return lexerCPPKeyword2;
    case 3:
        return lexerGeneralDoxygen;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
