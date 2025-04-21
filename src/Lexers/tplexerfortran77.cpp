#include <Lexers/TpLexerFortran77>

TP_NAMESPACE

TpLexerFortran77::TpLexerFortran77(QObject *parent)
    : TpFamilyFortranLexer(parent)
{}

const char *TpLexerFortran77::language() const
{
    return "Fortran77";
}

const char *TpLexerFortran77::lexer() const
{
    return "f77";
}

QColor TpLexerFortran77::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Fortran77/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Fortran77/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Fortran77/Color/Number", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Fortran77/Color/SingleQuotedString", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Fortran77/Color/DoubleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Fortran77/Color/UnclosedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Fortran77/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Fortran77/Color/Identifier", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Fortran77/Color/Keyword", QColor);
    case IntrinsicFunction:
        return GET_SETTINGS("Lexer/Fortran77/Color/IntrinsicFunction", QColor);
    case ExtendedFunction:
        return GET_SETTINGS("Lexer/Fortran77/Color/ExtendedFunction", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Fortran77/Color/PreProcessor", QColor);
    case DottedOperator:
        return GET_SETTINGS("Lexer/Fortran77/Color/DottedOperator", QColor);
    case Label:
        return GET_SETTINGS("Lexer/Fortran77/Color/Label", QColor);
    case Continuation:
        return GET_SETTINGS("Lexer/Fortran77/Color/Continuation", QColor);
    }

    return TpFamilyFortranLexer::defaultColor(style);
}

bool TpLexerFortran77::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Fortran77/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Fortran77/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/Fortran77/Fill/Number", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Fortran77/Fill/SingleQuotedString", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Fortran77/Fill/DoubleQuotedString", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Fortran77/Fill/UnclosedString", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Fortran77/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Fortran77/Fill/Identifier", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Fortran77/Fill/Keyword", bool);
    case IntrinsicFunction:
        return GET_SETTINGS("Lexer/Fortran77/Fill/IntrinsicFunction", bool);
    case ExtendedFunction:
        return GET_SETTINGS("Lexer/Fortran77/Fill/ExtendedFunction", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Fortran77/Fill/PreProcessor", bool);
    case DottedOperator:
        return GET_SETTINGS("Lexer/Fortran77/Fill/DottedOperator", bool);
    case Label:
        return GET_SETTINGS("Lexer/Fortran77/Fill/Label", bool);
    case Continuation:
        return GET_SETTINGS("Lexer/Fortran77/Fill/Continuation", bool);
    }

    return TpFamilyFortranLexer::defaultEolFill(style);
}

QFont TpLexerFortran77::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Fortran77/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Fortran77/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Fortran77/Font/Number", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Fortran77/Font/SingleQuotedString", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Fortran77/Font/DoubleQuotedString", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Fortran77/Font/UnclosedString", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Fortran77/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Fortran77/Font/Identifier", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Fortran77/Font/Keyword", QFont);
    case IntrinsicFunction:
        return GET_SETTINGS("Lexer/Fortran77/Font/IntrinsicFunction", QFont);
    case ExtendedFunction:
        return GET_SETTINGS("Lexer/Fortran77/Font/ExtendedFunction", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Fortran77/Font/PreProcessor", QFont);
    case DottedOperator:
        return GET_SETTINGS("Lexer/Fortran77/Font/DottedOperator", QFont);
    case Label:
        return GET_SETTINGS("Lexer/Fortran77/Font/Label", QFont);
    case Continuation:
        return GET_SETTINGS("Lexer/Fortran77/Font/Continuation", QFont);
    }

    return TpFamilyFortranLexer::defaultFont(style);
}

QColor TpLexerFortran77::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/Number", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/SingleQuotedString", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/DoubleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/UnclosedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/Identifier", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/Keyword", QColor);
    case IntrinsicFunction:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/IntrinsicFunction", QColor);
    case ExtendedFunction:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/ExtendedFunction", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/PreProcessor", QColor);
    case DottedOperator:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/DottedOperator", QColor);
    case Label:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/Label", QColor);
    case Continuation:
        return GET_SETTINGS("Lexer/Fortran77/BgColor/Continuation", QColor);
    }

    return TpFamilyFortranLexer::defaultPaper(style);
}

const char *TpLexerFortran77::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerFortranKeyword1;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
