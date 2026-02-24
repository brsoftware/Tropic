#include <Lexers/TpLexerPureBasic>

TP_NAMESPACE

TpLexerPureBasic::TpLexerPureBasic(QObject *parent)
    : TpFamilyBasicLexer(parent)
{
    m_mode = PureBasic;
}

const char *TpLexerPureBasic::language() const
{
    return "BASIC (Pure)";
}

QColor TpLexerPureBasic::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PureBasic/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/PureBasic/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/PureBasic/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/PureBasic/Color/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/PureBasic/Color/String", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/PureBasic/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/PureBasic/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/PureBasic/Color/Identifier", QColor);
    case Date:
        return GET_SETTINGS("Lexer/PureBasic/Color/Date", QColor);
    case StringEol:
        return GET_SETTINGS("Lexer/PureBasic/Color/StringEol", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/PureBasic/Color/KeywordSet2", QColor);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/PureBasic/Color/KeywordSet3", QColor);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/PureBasic/Color/KeywordSet4", QColor);
    case Constant:
        return GET_SETTINGS("Lexer/PureBasic/Color/Constant", QColor);
    case Asm:
        return GET_SETTINGS("Lexer/PureBasic/Color/Asm", QColor);
    case Label:
        return GET_SETTINGS("Lexer/PureBasic/Color/Label", QColor);
    case Error:
        return GET_SETTINGS("Lexer/PureBasic/Color/Error", QColor);
    case HexNumber:
        return GET_SETTINGS("Lexer/PureBasic/Color/HexNumber", QColor);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/PureBasic/Color/BinaryNumber", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/PureBasic/Color/CommentBlock", QColor);
    case DocLine:
        return GET_SETTINGS("Lexer/PureBasic/Color/DocLine", QColor);
    case DocBlock:
        return GET_SETTINGS("Lexer/PureBasic/Color/DocBlock", QColor);
    case DocKeyword:
        return GET_SETTINGS("Lexer/PureBasic/Color/DocKeyword", QColor);
    }

    return TpFamilyBasicLexer::defaultColor(style);
}

bool TpLexerPureBasic::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Keyword", bool);
    case String:
        return GET_SETTINGS("Lexer/PureBasic/Fill/String", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/PureBasic/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Identifier", bool);
    case Date:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Date", bool);
    case StringEol:
        return GET_SETTINGS("Lexer/PureBasic/Fill/StringEol", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/PureBasic/Fill/KeywordSet2", bool);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/PureBasic/Fill/KeywordSet3", bool);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/PureBasic/Fill/KeywordSet4", bool);
    case Constant:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Constant", bool);
    case Asm:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Asm", bool);
    case Label:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Label", bool);
    case Error:
        return GET_SETTINGS("Lexer/PureBasic/Fill/Error", bool);
    case HexNumber:
        return GET_SETTINGS("Lexer/PureBasic/Fill/HexNumber", bool);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/PureBasic/Fill/BinaryNumber", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/PureBasic/Fill/CommentBlock", bool);
    case DocLine:
        return GET_SETTINGS("Lexer/PureBasic/Fill/DocLine", bool);
    case DocBlock:
        return GET_SETTINGS("Lexer/PureBasic/Fill/DocBlock", bool);
    case DocKeyword:
        return GET_SETTINGS("Lexer/PureBasic/Fill/DocKeyword", bool);
    }

    return TpFamilyBasicLexer::defaultEolFill(style);
}

QFont TpLexerPureBasic::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PureBasic/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/PureBasic/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/PureBasic/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/PureBasic/Font/Keyword", QFont);
    case String:
        return GET_SETTINGS("Lexer/PureBasic/Font/String", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/PureBasic/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/PureBasic/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/PureBasic/Font/Identifier", QFont);
    case Date:
        return GET_SETTINGS("Lexer/PureBasic/Font/Date", QFont);
    case StringEol:
        return GET_SETTINGS("Lexer/PureBasic/Font/StringEol", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/PureBasic/Font/KeywordSet2", QFont);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/PureBasic/Font/KeywordSet3", QFont);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/PureBasic/Font/KeywordSet4", QFont);
    case Constant:
        return GET_SETTINGS("Lexer/PureBasic/Font/Constant", QFont);
    case Asm:
        return GET_SETTINGS("Lexer/PureBasic/Font/Asm", QFont);
    case Label:
        return GET_SETTINGS("Lexer/PureBasic/Font/Label", QFont);
    case Error:
        return GET_SETTINGS("Lexer/PureBasic/Font/Error", QFont);
    case HexNumber:
        return GET_SETTINGS("Lexer/PureBasic/Font/HexNumber", QFont);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/PureBasic/Font/BinaryNumber", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/PureBasic/Font/CommentBlock", QFont);
    case DocLine:
        return GET_SETTINGS("Lexer/PureBasic/Font/DocLine", QFont);
    case DocBlock:
        return GET_SETTINGS("Lexer/PureBasic/Font/DocBlock", QFont);
    case DocKeyword:
        return GET_SETTINGS("Lexer/PureBasic/Font/DocKeyword", QFont);
    }

    return TpFamilyBasicLexer::defaultFont(style);
}

QColor TpLexerPureBasic::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/String", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Identifier", QColor);
    case Date:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Date", QColor);
    case StringEol:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/StringEol", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/KeywordSet2", QColor);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/KeywordSet3", QColor);
    case KeywordSet4:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/KeywordSet4", QColor);
    case Constant:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Constant", QColor);
    case Asm:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Asm", QColor);
    case Label:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Label", QColor);
    case Error:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/Error", QColor);
    case HexNumber:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/HexNumber", QColor);
    case BinaryNumber:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/BinaryNumber", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/CommentBlock", QColor);
    case DocLine:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/DocLine", QColor);
    case DocBlock:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/DocBlock", QColor);
    case DocKeyword:
        return GET_SETTINGS("Lexer/PureBasic/BgColor/DocKeyword", QColor);
    }

    return TpFamilyBasicLexer::defaultPaper(style);
}

const char *TpLexerPureBasic::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerPureBasicKeyword1;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
