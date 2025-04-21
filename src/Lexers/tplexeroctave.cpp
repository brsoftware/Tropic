#include <Lexers/TpLexerOctave>

TP_NAMESPACE

TpLexerOctave::TpLexerOctave(QObject *parent)
    : TpFamilyMatlabLexer(parent)
{}

const char *TpLexerOctave::language() const
{
    return "GNU/Octave";
}

const char *TpLexerOctave::lexer() const
{
    return "octave";
}

QColor TpLexerOctave::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Octave/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Octave/Color/Comment", QColor);
    case Command:
        return GET_SETTINGS("Lexer/Octave/Color/Command", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Octave/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Octave/Color/Keyword", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Octave/Color/SingleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Octave/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Octave/Color/Identifier", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Octave/Color/DoubleQuotedString", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerOctave::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Octave/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Octave/Fill/Comment", bool);
    case Command:
        return GET_SETTINGS("Lexer/Octave/Fill/Command", bool);
    case Number:
        return GET_SETTINGS("Lexer/Octave/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Octave/Fill/Keyword", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Octave/Fill/SingleQuotedString", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Octave/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Octave/Fill/Identifier", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Octave/Fill/DoubleQuotedString", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerOctave::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Octave/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Octave/Font/Comment", QFont);
    case Command:
        return GET_SETTINGS("Lexer/Octave/Font/Command", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Octave/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Octave/Font/Keyword", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Octave/Font/SingleQuotedString", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Octave/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Octave/Font/Identifier", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Octave/Font/DoubleQuotedString", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerOctave::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Octave/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Octave/BgColor/Comment", QColor);
    case Command:
        return GET_SETTINGS("Lexer/Octave/BgColor/Command", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Octave/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Octave/BgColor/Keyword", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Octave/BgColor/SingleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Octave/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Octave/BgColor/Identifier", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Octave/BgColor/DoubleQuotedString", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerOctave::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerOctaveKeyword1;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
