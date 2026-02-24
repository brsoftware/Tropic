#include <Lexers/TpLexerIDL>

TP_NAMESPACE

TpLexerIDL::TpLexerIDL(QObject *parent)
    : TpFamilyCLexer(parent)
{}

const char *TpLexerIDL::language() const
{
    return "IDL";
}

QColor TpLexerIDL::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/IDL/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/IDL/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/IDL/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/IDL/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/IDL/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/IDL/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/IDL/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/IDL/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/IDL/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/IDL/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/IDL/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/IDL/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/IDL/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/IDL/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/IDL/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/IDL/Color/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/IDL/Color/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/IDL/Color/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/IDL/Color/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/IDL/Color/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Color/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/IDL/Color/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/IDL/Color/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/IDL/Color/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/IDL/Color/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Color/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/IDL/Color/InactiveTaskMarker", QColor);
    default:
        return GET_SETTINGS("Lexer/IDL/Color/Universal", QColor);
    }

    return TpFamilyCLexer::defaultColor(style);
}

bool TpLexerIDL::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/IDL/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/IDL/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/IDL/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/IDL/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/IDL/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Lexer/IDL/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/IDL/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/IDL/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/IDL/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/IDL/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/IDL/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Lexer/IDL/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/IDL/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/IDL/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/IDL/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Lexer/IDL/Fill/GlobalClass", bool);
    case RawString:
        return GET_SETTINGS("Lexer/IDL/Fill/RawString", bool);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/IDL/Fill/TripleQuotedVerbatimString", bool);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/IDL/Fill/HashQuotedString", bool);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/IDL/Fill/PreProcessorComment", bool);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Fill/PreProcessorCommentLineDoc", bool);
    case UserLiteral:
        return GET_SETTINGS("Lexer/IDL/Fill/UserLiteral", bool);
    case TaskMarker:
        return GET_SETTINGS("Lexer/IDL/Fill/TaskMarker", bool);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveCommentLine", bool);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveCommentDoc", bool);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveKeyword", bool);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveDoubleQuotedString", bool);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveSingleQuotedString", bool);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveUUID", bool);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/IDL/Fill/InactivePreProcessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveUnclosedString", bool);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveVerbatimString", bool);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveRegex", bool);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveCommentLineDoc", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveKeywordSet2", bool);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveCommentDocKeyword", bool);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveCommentDocKeywordError", bool);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveGlobalClass", bool);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveRawString", bool);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveTripleQuotedVerbatimString", bool);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveHashQuotedString", bool);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/IDL/Fill/InactivePreProcessorComment", bool);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Fill/InactivePreProcessorCommentLineDoc", bool);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveUserLiteral", bool);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/IDL/Fill/InactiveTaskMarker", bool);
    default:
        return GET_SETTINGS("Lexer/IDL/Fill/Universal", bool);
    }

    return GET_SETTINGS("Lexer/IDL/Fill/Universal", bool);
}

QFont TpLexerIDL::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/IDL/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/IDL/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/IDL/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/IDL/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/IDL/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Lexer/IDL/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/IDL/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/IDL/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/IDL/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/IDL/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/IDL/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/IDL/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/IDL/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/IDL/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/IDL/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Lexer/IDL/Font/GlobalClass", QFont);
    case RawString:
        return GET_SETTINGS("Lexer/IDL/Font/RawString", QFont);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/IDL/Font/TripleQuotedVerbatimString", QFont);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/IDL/Font/HashQuotedString", QFont);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/IDL/Font/PreProcessorComment", QFont);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Font/PreProcessorCommentLineDoc", QFont);
    case UserLiteral:
        return GET_SETTINGS("Lexer/IDL/Font/UserLiteral", QFont);
    case TaskMarker:
        return GET_SETTINGS("Lexer/IDL/Font/TaskMarker", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveCommentLine", QFont);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveCommentDoc", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveKeyword", QFont);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveDoubleQuotedString", QFont);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveSingleQuotedString", QFont);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveUUID", QFont);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/IDL/Font/InactivePreProcessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveUnclosedString", QFont);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveVerbatimString", QFont);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveRegex", QFont);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveCommentLineDoc", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveKeywordSet2", QFont);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveCommentDocKeyword", QFont);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveCommentDocKeywordError", QFont);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveGlobalClass", QFont);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveRawString", QFont);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveTripleQuotedVerbatimString", QFont);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveHashQuotedString", QFont);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/IDL/Font/InactivePreProcessorComment", QFont);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/Font/InactivePreProcessorCommentLineDoc", QFont);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveUserLiteral", QFont);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/IDL/Font/InactiveTaskMarker", QFont);
    default:
        return GET_SETTINGS("Lexer/IDL/Font/Universal", QFont);
    }

    return TpFamilyCLexer::defaultFont(style);
}

QColor TpLexerIDL::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/IDL/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/IDL/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/IDL/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/IDL/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/IDL/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/IDL/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/IDL/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/IDL/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/IDL/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/IDL/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/IDL/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/IDL/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/IDL/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/IDL/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/IDL/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/IDL/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/IDL/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/IDL/BgColor/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/IDL/BgColor/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/IDL/BgColor/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/IDL/BgColor/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/IDL/BgColor/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/BgColor/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/IDL/BgColor/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/IDL/BgColor/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/IDL/BgColor/InactiveTaskMarker", QColor);
    default:
        return GET_SETTINGS("Lexer/IDL/BgColor/Universal", QColor);
    }

    return TpFamilyCLexer::defaultPaper(style);
}

const char *TpLexerIDL::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerIDLKeyword1;
    case 3:
        return lexerGeneralDoxygen;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
