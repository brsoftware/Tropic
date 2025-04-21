#include <Lexers/TpLexerActionScript>

TP_NAMESPACE

TpLexerActionScript::TpLexerActionScript(QObject *parent)
    : TpFamilyCLexer(parent)
{}

const char *TpLexerActionScript::language() const
{
    return "ActionScript";
}

QStringList TpLexerActionScript::autoCompletionWordSeparators() const
{
    QStringList wordList;
    wordList << ".";
    return wordList;
}

QColor TpLexerActionScript::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/ActionScript/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/ActionScript/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/ActionScript/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/ActionScript/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/ActionScript/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Color/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/ActionScript/Color/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/ActionScript/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/ActionScript/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/ActionScript/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/ActionScript/Color/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Color/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/ActionScript/Color/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Color/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/ActionScript/Color/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/ActionScript/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/ActionScript/Color/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/ActionScript/Color/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/ActionScript/Color/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Color/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Color/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/ActionScript/Color/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Color/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/ActionScript/Color/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/ActionScript/Color/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/ActionScript/Color/InactiveTaskMarker", QColor);
    default:
        return GET_SETTINGS("Lexer/ActionScript/Color/Universal", QColor);
    }

    return TpFamilyCLexer::defaultColor(style);
}

bool TpLexerActionScript::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/ActionScript/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/ActionScript/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/ActionScript/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/ActionScript/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/ActionScript/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/SingleQuotedString", bool);
    case UUID:
        return GET_SETTINGS("Lexer/ActionScript/Fill/UUID", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/ActionScript/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/ActionScript/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/ActionScript/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/UnclosedString", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/VerbatimString", bool);
    case Regex:
        return GET_SETTINGS("Lexer/ActionScript/Fill/Regex", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Fill/CommentLineDoc", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/ActionScript/Fill/KeywordSet2", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/ActionScript/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/ActionScript/Fill/CommentDocKeywordError", bool);
    case GlobalClass:
        return GET_SETTINGS("Lexer/ActionScript/Fill/GlobalClass", bool);
    case RawString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/RawString", bool);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/TripleQuotedVerbatimString", bool);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/HashQuotedString", bool);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/ActionScript/Fill/PreProcessorComment", bool);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Fill/PreProcessorCommentLineDoc", bool);
    case UserLiteral:
        return GET_SETTINGS("Lexer/ActionScript/Fill/UserLiteral", bool);
    case TaskMarker:
        return GET_SETTINGS("Lexer/ActionScript/Fill/TaskMarker", bool);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveCommentLine", bool);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveCommentDoc", bool);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveKeyword", bool);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveDoubleQuotedString", bool);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveSingleQuotedString", bool);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveUUID", bool);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactivePreProcessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveUnclosedString", bool);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveVerbatimString", bool);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveRegex", bool);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveCommentLineDoc", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveKeywordSet2", bool);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveCommentDocKeyword", bool);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveCommentDocKeywordError", bool);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveGlobalClass", bool);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveRawString", bool);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveTripleQuotedVerbatimString", bool);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveHashQuotedString", bool);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactivePreProcessorComment", bool);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactivePreProcessorCommentLineDoc", bool);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveUserLiteral", bool);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/ActionScript/Fill/InactiveTaskMarker", bool);
    default:
        return GET_SETTINGS("Lexer/ActionScript/Fill/Universal", bool);
    }

    return GET_SETTINGS("Lexer/ActionScript/Fill/Universal", bool);
}

QFont TpLexerActionScript::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/ActionScript/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/ActionScript/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/ActionScript/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/ActionScript/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/ActionScript/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Font/SingleQuotedString", QFont);
    case UUID:
        return GET_SETTINGS("Lexer/ActionScript/Font/UUID", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/ActionScript/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/ActionScript/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/ActionScript/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/ActionScript/Font/UnclosedString", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Font/VerbatimString", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/ActionScript/Font/Regex", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Font/CommentLineDoc", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/ActionScript/Font/KeywordSet2", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/ActionScript/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/ActionScript/Font/CommentDocKeywordError", QFont);
    case GlobalClass:
        return GET_SETTINGS("Lexer/ActionScript/Font/GlobalClass", QFont);
    case RawString:
        return GET_SETTINGS("Lexer/ActionScript/Font/RawString", QFont);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Font/TripleQuotedVerbatimString", QFont);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Font/HashQuotedString", QFont);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/ActionScript/Font/PreProcessorComment", QFont);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Font/PreProcessorCommentLineDoc", QFont);
    case UserLiteral:
        return GET_SETTINGS("Lexer/ActionScript/Font/UserLiteral", QFont);
    case TaskMarker:
        return GET_SETTINGS("Lexer/ActionScript/Font/TaskMarker", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveCommentLine", QFont);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveCommentDoc", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveKeyword", QFont);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveDoubleQuotedString", QFont);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveSingleQuotedString", QFont);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveUUID", QFont);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactivePreProcessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveUnclosedString", QFont);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveVerbatimString", QFont);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveRegex", QFont);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveCommentLineDoc", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveKeywordSet2", QFont);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveCommentDocKeyword", QFont);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveCommentDocKeywordError", QFont);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveGlobalClass", QFont);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveRawString", QFont);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveTripleQuotedVerbatimString", QFont);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveHashQuotedString", QFont);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactivePreProcessorComment", QFont);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactivePreProcessorCommentLineDoc", QFont);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveUserLiteral", QFont);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/ActionScript/Font/InactiveTaskMarker", QFont);
    default:
        return GET_SETTINGS("Lexer/ActionScript/Font/Universal", QFont);
    }

    return TpFamilyCLexer::defaultFont(style);
}

QColor TpLexerActionScript::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/SingleQuotedString", QColor);
    case UUID:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/UUID", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/UnclosedString", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/VerbatimString", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/Regex", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/CommentLineDoc", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/KeywordSet2", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/CommentDocKeywordError", QColor);
    case GlobalClass:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/GlobalClass", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/RawString", QColor);
    case TripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/TripleQuotedVerbatimString", QColor);
    case HashQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/HashQuotedString", QColor);
    case PreProcessorComment:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/PreProcessorComment", QColor);
    case PreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/PreProcessorCommentLineDoc", QColor);
    case UserLiteral:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/UserLiteral", QColor);
    case TaskMarker:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/TaskMarker", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentDoc:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveCommentDoc", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveKeyword", QColor);
    case InactiveDoubleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveDoubleQuotedString", QColor);
    case InactiveSingleQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveSingleQuotedString", QColor);
    case InactiveUUID:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveUUID", QColor);
    case InactivePreProcessor:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactivePreProcessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveUnclosedString", QColor);
    case InactiveVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveVerbatimString", QColor);
    case InactiveRegex:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveRegex", QColor);
    case InactiveCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveCommentLineDoc", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveKeywordSet2", QColor);
    case InactiveCommentDocKeyword:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveCommentDocKeyword", QColor);
    case InactiveCommentDocKeywordError:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveCommentDocKeywordError", QColor);
    case InactiveGlobalClass:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveGlobalClass", QColor);
    case InactiveRawString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveRawString", QColor);
    case InactiveTripleQuotedVerbatimString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveTripleQuotedVerbatimString", QColor);
    case InactiveHashQuotedString:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveHashQuotedString", QColor);
    case InactivePreProcessorComment:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactivePreProcessorComment", QColor);
    case InactivePreProcessorCommentLineDoc:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactivePreProcessorCommentLineDoc", QColor);
    case InactiveUserLiteral:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveUserLiteral", QColor);
    case InactiveTaskMarker:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/InactiveTaskMarker", QColor);
    default:
        return GET_SETTINGS("Lexer/ActionScript/BgColor/Universal", QColor);
    }

    return TpFamilyCLexer::defaultPaper(style);
}

const char *TpLexerActionScript::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerActionScriptKeyword1;
    case 3:
        return lexerGeneralDoxygen;
    case 5:
        return lexerActionScriptKeyword5;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
