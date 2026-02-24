#include <Lexers/TpLexerSpice>

TP_NAMESPACE

TpLexerSpice::TpLexerSpice(QObject *parent)
    : TpGeneralLexer(parent)
{}

TpLexerSpice::~TpLexerSpice()
{}

const char *TpLexerSpice::language() const
{
    return "Spice";
}

const char *TpLexerSpice::lexer() const
{
    return "spice";
}

int TpLexerSpice::braceStyle() const
{
    return Parameter;
}

QColor TpLexerSpice::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Spice/Color/Universal", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Spice/Color/Identifier", QColor);
    case Command:
        return GET_SETTINGS("Lexer/Spice/Color/Command", QColor);
    case Function:
        return GET_SETTINGS("Lexer/Spice/Color/Function", QColor);
    case Parameter:
        return GET_SETTINGS("Lexer/Spice/Color/Parameter", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Spice/Color/Number", QColor);
    case Delimiter:
        return GET_SETTINGS("Lexer/Spice/Color/Delimiter", QColor);
    case Value:
        return GET_SETTINGS("Lexer/Spice/Color/Value", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Spice/Color/Comment", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerSpice::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Spice/Fill/Universal", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Spice/Fill/Identifier", bool);
    case Command:
        return GET_SETTINGS("Lexer/Spice/Fill/Command", bool);
    case Function:
        return GET_SETTINGS("Lexer/Spice/Fill/Function", bool);
    case Parameter:
        return GET_SETTINGS("Lexer/Spice/Fill/Parameter", bool);
    case Number:
        return GET_SETTINGS("Lexer/Spice/Fill/Number", bool);
    case Delimiter:
        return GET_SETTINGS("Lexer/Spice/Fill/Delimiter", bool);
    case Value:
        return GET_SETTINGS("Lexer/Spice/Fill/Value", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Spice/Fill/Comment", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerSpice::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Spice/Font/Universal", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Spice/Font/Identifier", QFont);
    case Command:
        return GET_SETTINGS("Lexer/Spice/Font/Command", QFont);
    case Function:
        return GET_SETTINGS("Lexer/Spice/Font/Function", QFont);
    case Parameter:
        return GET_SETTINGS("Lexer/Spice/Font/Parameter", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Spice/Font/Number", QFont);
    case Delimiter:
        return GET_SETTINGS("Lexer/Spice/Font/Delimiter", QFont);
    case Value:
        return GET_SETTINGS("Lexer/Spice/Font/Value", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Spice/Font/Comment", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerSpice::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Spice/BgColor/Universal", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Spice/BgColor/Identifier", QColor);
    case Command:
        return GET_SETTINGS("Lexer/Spice/BgColor/Command", QColor);
    case Function:
        return GET_SETTINGS("Lexer/Spice/BgColor/Function", QColor);
    case Parameter:
        return GET_SETTINGS("Lexer/Spice/BgColor/Parameter", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Spice/BgColor/Number", QColor);
    case Delimiter:
        return GET_SETTINGS("Lexer/Spice/BgColor/Delimiter", QColor);
    case Value:
        return GET_SETTINGS("Lexer/Spice/BgColor/Value", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Spice/BgColor/Comment", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerSpice::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerSpiceKeyword1;
    case 2:
        return lexerSpiceKeyword2;
    default:
        return 0;
    }
}

QString TpLexerSpice::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Identifier:
        return tr("Identifier");
    case Command:
        return tr("Command");
    case Function:
        return tr("Function");
    case Parameter:
        return tr("Parameter");
    case Number:
        return tr("Number");
    case Delimiter:
        return tr("Delimiter");
    case Value:
        return tr("Value");
    case Comment:
        return tr("Comment");
    }

    return QString();
}

TP_END_NAMESPACE
