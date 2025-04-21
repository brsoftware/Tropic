#include <Lexers/TpLexerMatlab>

TP_NAMESPACE

TpLexerMatlab::TpLexerMatlab(QObject *parent)
    : TpFamilyMatlabLexer(parent)
{}

QColor TpLexerMatlab::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Matlab/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Matlab/Color/Comment", QColor);
    case Command:
        return GET_SETTINGS("Lexer/Matlab/Color/Command", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Matlab/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Matlab/Color/Keyword", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Matlab/Color/SingleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Matlab/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Matlab/Color/Identifier", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Matlab/Color/DoubleQuotedString", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerMatlab::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Matlab/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Matlab/Fill/Comment", bool);
    case Command:
        return GET_SETTINGS("Lexer/Matlab/Fill/Command", bool);
    case Number:
        return GET_SETTINGS("Lexer/Matlab/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Matlab/Fill/Keyword", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Matlab/Fill/SingleQuotedString", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Matlab/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Matlab/Fill/Identifier", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Matlab/Fill/DoubleQuotedString", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerMatlab::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Matlab/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Matlab/Font/Comment", QFont);
    case Command:
        return GET_SETTINGS("Lexer/Matlab/Font/Command", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Matlab/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Matlab/Font/Keyword", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Matlab/Font/SingleQuotedString", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Matlab/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Matlab/Font/Identifier", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Matlab/Font/DoubleQuotedString", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerMatlab::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Matlab/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Matlab/BgColor/Comment", QColor);
    case Command:
        return GET_SETTINGS("Lexer/Matlab/BgColor/Command", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Matlab/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Matlab/BgColor/Keyword", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Matlab/BgColor/SingleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Matlab/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Matlab/BgColor/Identifier", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Matlab/BgColor/DoubleQuotedString", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

TP_END_NAMESPACE
