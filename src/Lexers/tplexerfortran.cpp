#include <Lexers/TpLexerFortran>

TP_NAMESPACE

TpLexerFortran::TpLexerFortran(QObject *parent)
    : TpFamilyFortranLexer(parent)
{}

const char *TpLexerFortran::language() const
{
    return "Fortran";
}

const char *TpLexerFortran::lexer() const
{
    return "fortran";
}

QColor TpLexerFortran::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Fortran/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Fortran/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Fortran/Color/Number", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Fortran/Color/SingleQuotedString", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Fortran/Color/DoubleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Fortran/Color/UnclosedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Fortran/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Fortran/Color/Identifier", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Fortran/Color/Keyword", QColor);
    case IntrinsicFunction:
        return GET_SETTINGS("Lexer/Fortran/Color/IntrinsicFunction", QColor);
    case ExtendedFunction:
        return GET_SETTINGS("Lexer/Fortran/Color/ExtendedFunction", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Fortran/Color/PreProcessor", QColor);
    case DottedOperator:
        return GET_SETTINGS("Lexer/Fortran/Color/DottedOperator", QColor);
    case Label:
        return GET_SETTINGS("Lexer/Fortran/Color/Label", QColor);
    case Continuation:
        return GET_SETTINGS("Lexer/Fortran/Color/Continuation", QColor);
    }

    return TpFamilyFortranLexer::defaultColor(style);
}

bool TpLexerFortran::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Fortran/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Fortran/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/Fortran/Fill/Number", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Fortran/Fill/SingleQuotedString", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Fortran/Fill/DoubleQuotedString", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Fortran/Fill/UnclosedString", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Fortran/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Fortran/Fill/Identifier", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Fortran/Fill/Keyword", bool);
    case IntrinsicFunction:
        return GET_SETTINGS("Lexer/Fortran/Fill/IntrinsicFunction", bool);
    case ExtendedFunction:
        return GET_SETTINGS("Lexer/Fortran/Fill/ExtendedFunction", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Fortran/Fill/PreProcessor", bool);
    case DottedOperator:
        return GET_SETTINGS("Lexer/Fortran/Fill/DottedOperator", bool);
    case Label:
        return GET_SETTINGS("Lexer/Fortran/Fill/Label", bool);
    case Continuation:
        return GET_SETTINGS("Lexer/Fortran/Fill/Continuation", bool);
    }

    return TpFamilyFortranLexer::defaultEolFill(style);
}

QFont TpLexerFortran::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Fortran/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Fortran/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Fortran/Font/Number", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Fortran/Font/SingleQuotedString", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Fortran/Font/DoubleQuotedString", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Fortran/Font/UnclosedString", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Fortran/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Fortran/Font/Identifier", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Fortran/Font/Keyword", QFont);
    case IntrinsicFunction:
        return GET_SETTINGS("Lexer/Fortran/Font/IntrinsicFunction", QFont);
    case ExtendedFunction:
        return GET_SETTINGS("Lexer/Fortran/Font/ExtendedFunction", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Fortran/Font/PreProcessor", QFont);
    case DottedOperator:
        return GET_SETTINGS("Lexer/Fortran/Font/DottedOperator", QFont);
    case Label:
        return GET_SETTINGS("Lexer/Fortran/Font/Label", QFont);
    case Continuation:
        return GET_SETTINGS("Lexer/Fortran/Font/Continuation", QFont);
    }

    return TpFamilyFortranLexer::defaultFont(style);
}

QColor TpLexerFortran::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Fortran/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Fortran/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Fortran/BgColor/Number", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Fortran/BgColor/SingleQuotedString", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Fortran/BgColor/DoubleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Fortran/BgColor/UnclosedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Fortran/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Fortran/BgColor/Identifier", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Fortran/BgColor/Keyword", QColor);
    case IntrinsicFunction:
        return GET_SETTINGS("Lexer/Fortran/BgColor/IntrinsicFunction", QColor);
    case ExtendedFunction:
        return GET_SETTINGS("Lexer/Fortran/BgColor/ExtendedFunction", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Fortran/BgColor/PreProcessor", QColor);
    case DottedOperator:
        return GET_SETTINGS("Lexer/Fortran/BgColor/DottedOperator", QColor);
    case Label:
        return GET_SETTINGS("Lexer/Fortran/BgColor/Label", QColor);
    case Continuation:
        return GET_SETTINGS("Lexer/Fortran/BgColor/Continuation", QColor);
    }

    return TpFamilyFortranLexer::defaultPaper(style);
}

const char *TpLexerFortran::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerFortranKeyword1;
    case 2:
        return lexerFortranKeyword2;
    case 3:
        return lexerFortranKeyword3;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
