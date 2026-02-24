#include <Lexers/TpLexerFreeBasic>

TP_NAMESPACE

TpLexerFreeBasic::TpLexerFreeBasic(QObject *parent)
    : TpFamilyBasicLexer(parent)
{
    m_mode = FreeBasic;
}

const char *TpLexerFreeBasic::language() const
{
    return "BASIC (Free)";
}

QColor TpLexerFreeBasic::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/FreeBasic/Color/String", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/FreeBasic/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Identifier", QColor);
    case Date:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Date", QColor);
    case StringEol:
        return GET_SETTINGS("Lexer/FreeBasic/Color/StringEol", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/FreeBasic/Color/KeywordSet2", QColor);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/FreeBasic/Color/KeywordSet3", QColor);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/FreeBasic/Color/KeywordSet4", QColor);
    case Constant:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Constant", QColor);
    case Asm:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Asm", QColor);
    case Label:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Label", QColor);
    case Error:
        return GET_SETTINGS("Lexer/FreeBasic/Color/Error", QColor);
    case HexNumber:
        return GET_SETTINGS("Lexer/FreeBasic/Color/HexNumber", QColor);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/FreeBasic/Color/BinaryNumber", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/FreeBasic/Color/CommentBlock", QColor);
    case DocLine:
        return GET_SETTINGS("Lexer/FreeBasic/Color/DocLine", QColor);
    case DocBlock:
        return GET_SETTINGS("Lexer/FreeBasic/Color/DocBlock", QColor);
    case DocKeyword:
        return GET_SETTINGS("Lexer/FreeBasic/Color/DocKeyword", QColor);
    }

    return TpFamilyBasicLexer::defaultColor(style);
}

bool TpLexerFreeBasic::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Keyword", bool);
    case String:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/String", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Identifier", bool);
    case Date:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Date", bool);
    case StringEol:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/StringEol", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/KeywordSet2", bool);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/KeywordSet3", bool);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/KeywordSet4", bool);
    case Constant:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Constant", bool);
    case Asm:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Asm", bool);
    case Label:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Label", bool);
    case Error:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/Error", bool);
    case HexNumber:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/HexNumber", bool);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/BinaryNumber", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/CommentBlock", bool);
    case DocLine:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/DocLine", bool);
    case DocBlock:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/DocBlock", bool);
    case DocKeyword:
        return GET_SETTINGS("Lexer/FreeBasic/Fill/DocKeyword", bool);
    }

    return TpFamilyBasicLexer::defaultEolFill(style);
}

QFont TpLexerFreeBasic::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Keyword", QFont);
    case String:
        return GET_SETTINGS("Lexer/FreeBasic/Font/String", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/FreeBasic/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Identifier", QFont);
    case Date:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Date", QFont);
    case StringEol:
        return GET_SETTINGS("Lexer/FreeBasic/Font/StringEol", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/FreeBasic/Font/KeywordSet2", QFont);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/FreeBasic/Font/KeywordSet3", QFont);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/FreeBasic/Font/KeywordSet4", QFont);
    case Constant:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Constant", QFont);
    case Asm:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Asm", QFont);
    case Label:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Label", QFont);
    case Error:
        return GET_SETTINGS("Lexer/FreeBasic/Font/Error", QFont);
    case HexNumber:
        return GET_SETTINGS("Lexer/FreeBasic/Font/HexNumber", QFont);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/FreeBasic/Font/BinaryNumber", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/FreeBasic/Font/CommentBlock", QFont);
    case DocLine:
        return GET_SETTINGS("Lexer/FreeBasic/Font/DocLine", QFont);
    case DocBlock:
        return GET_SETTINGS("Lexer/FreeBasic/Font/DocBlock", QFont);
    case DocKeyword:
        return GET_SETTINGS("Lexer/FreeBasic/Font/DocKeyword", QFont);
    }

    return TpFamilyBasicLexer::defaultFont(style);
}

QColor TpLexerFreeBasic::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/String", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Identifier", QColor);
    case Date:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Date", QColor);
    case StringEol:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/StringEol", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/KeywordSet2", QColor);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/KeywordSet3", QColor);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/KeywordSet4", QColor);
    case Constant:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Constant", QColor);
    case Asm:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Asm", QColor);
    case Label:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Label", QColor);
    case Error:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/Error", QColor);
    case HexNumber:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/HexNumber", QColor);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/BinaryNumber", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/CommentBlock", QColor);
    case DocLine:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/DocLine", QColor);
    case DocBlock:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/DocBlock", QColor);
    case DocKeyword:
        return GET_SETTINGS("Lexer/FreeBasic/BgColor/DocKeyword", QColor);
    }

    return TpFamilyBasicLexer::defaultPaper(style);
}

const char *TpLexerFreeBasic::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerFreeBasicKeyword1;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
