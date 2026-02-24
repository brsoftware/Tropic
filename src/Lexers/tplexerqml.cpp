#include <Lexers/TpLexerQML>

TP_NAMESPACE

TpLexerQML::TpLexerQML(QObject *parent)
    : TpFamilyCLexer(parent)
{}

const char *TpLexerQML::language() const
{
    return "C++";
}

QColor TpLexerQML::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/QML/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/QML/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/QML/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/QML/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/QML/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/QML/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/QML/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/QML/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/QML/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/QML/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/QML/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/QML/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/QML/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/QML/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/QML/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/QML/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/QML/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/QML/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/QML/Color/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/QML/Color/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/QML/Color/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/QML/Color/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/QML/Color/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Color/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/QML/Color/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/QML/Color/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/QML/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/QML/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/QML/Color/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/QML/Color/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/QML/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/QML/Color/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/QML/Color/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/QML/Color/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/QML/Color/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/QML/Color/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/QML/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/QML/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/QML/Color/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/QML/Color/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/QML/Color/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Color/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/QML/Color/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/QML/Color/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/QML/Color/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/QML/Color/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/QML/Color/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/QML/Color/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/QML/Color/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/QML/Color/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Color/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/QML/Color/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/QML/Color/InactiveTaskMarker", QColor);
    }

    return TpFamilyCLexer::defaultColor(style);
}

bool TpLexerQML::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/QML/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/QML/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/QML/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/QML/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/QML/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/QML/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/QML/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/QML/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Lexer/QML/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/QML/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/QML/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/QML/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/QML/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/QML/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Lexer/QML/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/QML/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/QML/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/QML/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Lexer/QML/Fill/GlobalClass", bool);
    case RawString:
        return GET_SETTINGS("Lexer/QML/Fill/RawString", bool);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/QML/Fill/TripleQuotedVerbatimString", bool);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/QML/Fill/HashQuotedString", bool);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/QML/Fill/PreProcessorComment", bool);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Fill/PreProcessorCommentLineDoc", bool);
    case UserLiteral:
        return GET_SETTINGS("Lexer/QML/Fill/UserLiteral", bool);
    case TaskMarker:
        return GET_SETTINGS("Lexer/QML/Fill/TaskMarker", bool);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveCommentLine", bool);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveCommentDoc", bool);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveKeyword", bool);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveDoubleQuotedString", bool);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveSingleQuotedString", bool);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveUUID", bool);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/QML/Fill/InactivePreProcessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveUnclosedString", bool);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveVerbatimString", bool);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveRegex", bool);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveCommentLineDoc", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveKeywordSet2", bool);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveCommentDocKeyword", bool);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveCommentDocKeywordError", bool);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveGlobalClass", bool);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveRawString", bool);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveTripleQuotedVerbatimString", bool);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveHashQuotedString", bool);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/QML/Fill/InactivePreProcessorComment", bool);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Fill/InactivePreProcessorCommentLineDoc", bool);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveUserLiteral", bool);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/QML/Fill/InactiveTaskMarker", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerQML::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/QML/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/QML/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/QML/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/QML/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/QML/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/QML/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/QML/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/QML/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Lexer/QML/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/QML/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/QML/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/QML/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/QML/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/QML/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/QML/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/QML/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/QML/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/QML/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Lexer/QML/Font/GlobalClass", QFont);
    case RawString:
        return GET_SETTINGS("Lexer/QML/Font/RawString", QFont);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/QML/Font/TripleQuotedVerbatimString", QFont);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/QML/Font/HashQuotedString", QFont);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/QML/Font/PreProcessorComment", QFont);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Font/PreProcessorCommentLineDoc", QFont);
    case UserLiteral:
        return GET_SETTINGS("Lexer/QML/Font/UserLiteral", QFont);
    case TaskMarker:
        return GET_SETTINGS("Lexer/QML/Font/TaskMarker", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/QML/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Lexer/QML/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/QML/Font/InactiveCommentLine", QFont);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/QML/Font/InactiveCommentDoc", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/QML/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/QML/Font/InactiveKeyword", QFont);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/QML/Font/InactiveDoubleQuotedString", QFont);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/QML/Font/InactiveSingleQuotedString", QFont);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/QML/Font/InactiveUUID", QFont);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/QML/Font/InactivePreProcessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/QML/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/QML/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/QML/Font/InactiveUnclosedString", QFont);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/QML/Font/InactiveVerbatimString", QFont);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/QML/Font/InactiveRegex", QFont);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Font/InactiveCommentLineDoc", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/QML/Font/InactiveKeywordSet2", QFont);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/QML/Font/InactiveCommentDocKeyword", QFont);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/QML/Font/InactiveCommentDocKeywordError", QFont);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/QML/Font/InactiveGlobalClass", QFont);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/QML/Font/InactiveRawString", QFont);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/QML/Font/InactiveTripleQuotedVerbatimString", QFont);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/QML/Font/InactiveHashQuotedString", QFont);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/QML/Font/InactivePreProcessorComment", QFont);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/Font/InactivePreProcessorCommentLineDoc", QFont);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/QML/Font/InactiveUserLiteral", QFont);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/QML/Font/InactiveTaskMarker", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerQML::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/QML/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/QML/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/QML/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/QML/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/QML/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/QML/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/QML/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/QML/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/QML/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/QML/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/QML/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/QML/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/QML/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/QML/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/QML/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/QML/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/QML/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/QML/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/QML/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/QML/BgColor/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/QML/BgColor/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/QML/BgColor/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/QML/BgColor/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/QML/BgColor/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/BgColor/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/QML/BgColor/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/QML/BgColor/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/QML/BgColor/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/QML/BgColor/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/QML/BgColor/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/QML/BgColor/InactiveTaskMarker", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerQML::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerQMLKeyword1;
    case 2:
        return lexerQMLKeyword2;
    case 3:
        return lexerGeneralDoxygen;
    case 4:
        return lexerQMLKeyword4;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
