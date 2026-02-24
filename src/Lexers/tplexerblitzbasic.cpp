#include <Lexers/TpLexerBlitzBasic>

TP_NAMESPACE

TpLexerBlitzBasic::TpLexerBlitzBasic(QObject *parent)
    : TpFamilyBasicLexer(parent)
{
    m_mode = BlitzBasic;
}

const char *TpLexerBlitzBasic::language() const
{
    return "BASIC (Blitz)";
}

QColor TpLexerBlitzBasic::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/String", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Identifier", QColor);
    case Date:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Date", QColor);
    case StringEol:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/StringEol", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/KeywordSet2", QColor);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/KeywordSet3", QColor);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/KeywordSet4", QColor);
    case Constant:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Constant", QColor);
    case Asm:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Asm", QColor);
    case Label:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Label", QColor);
    case Error:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/Error", QColor);
    case HexNumber:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/HexNumber", QColor);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/BinaryNumber", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/CommentBlock", QColor);
    case DocLine:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/DocLine", QColor);
    case DocBlock:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/DocBlock", QColor);
    case DocKeyword:
        return GET_SETTINGS("Lexer/BlitzBasic/Color/DocKeyword", QColor);
    }

    return TpFamilyBasicLexer::defaultColor(style);
}

bool TpLexerBlitzBasic::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Keyword", bool);
    case String:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/String", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Identifier", bool);
    case Date:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Date", bool);
    case StringEol:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/StringEol", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/KeywordSet2", bool);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/KeywordSet3", bool);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/KeywordSet4", bool);
    case Constant:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Constant", bool);
    case Asm:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Asm", bool);
    case Label:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Label", bool);
    case Error:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/Error", bool);
    case HexNumber:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/HexNumber", bool);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/BinaryNumber", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/CommentBlock", bool);
    case DocLine:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/DocLine", bool);
    case DocBlock:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/DocBlock", bool);
    case DocKeyword:
        return GET_SETTINGS("Lexer/BlitzBasic/Fill/DocKeyword", bool);
    }

    return TpFamilyBasicLexer::defaultEolFill(style);
}

QFont TpLexerBlitzBasic::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Keyword", QFont);
    case String:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/String", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Identifier", QFont);
    case Date:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Date", QFont);
    case StringEol:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/StringEol", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/KeywordSet2", QFont);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/KeywordSet3", QFont);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/KeywordSet4", QFont);
    case Constant:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Constant", QFont);
    case Asm:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Asm", QFont);
    case Label:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Label", QFont);
    case Error:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/Error", QFont);
    case HexNumber:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/HexNumber", QFont);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/BinaryNumber", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/CommentBlock", QFont);
    case DocLine:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/DocLine", QFont);
    case DocBlock:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/DocBlock", QFont);
    case DocKeyword:
        return GET_SETTINGS("Lexer/BlitzBasic/Font/DocKeyword", QFont);
    }

    return TpFamilyBasicLexer::defaultFont(style);
}

QColor TpLexerBlitzBasic::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/String", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Identifier", QColor);
    case Date:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Date", QColor);
    case StringEol:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/StringEol", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/KeywordSet2", QColor);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/KeywordSet3", QColor);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/KeywordSet4", QColor);
    case Constant:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Constant", QColor);
    case Asm:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Asm", QColor);
    case Label:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Label", QColor);
    case Error:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/Error", QColor);
    case HexNumber:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/HexNumber", QColor);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/BinaryNumber", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/CommentBlock", QColor);
    case DocLine:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/DocLine", QColor);
    case DocBlock:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/DocBlock", QColor);
    case DocKeyword:
        return GET_SETTINGS("Lexer/BlitzBasic/BgColor/DocKeyword", QColor);
    }

    return TpFamilyBasicLexer::defaultPaper(style);
}

const char *TpLexerBlitzBasic::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerBlitzBasicKeyword1;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
