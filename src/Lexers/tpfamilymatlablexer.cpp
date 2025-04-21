#include <Lexers/TpFamilyMatlabLexer>

TP_NAMESPACE

TpFamilyMatlabLexer::TpFamilyMatlabLexer(QObject *parent)
    : TpGeneralLexer(parent)
{}

TpFamilyMatlabLexer::~TpFamilyMatlabLexer()
{}

const char *TpFamilyMatlabLexer::language() const
{
    return "Matlab";
}

const char *TpFamilyMatlabLexer::lexer() const
{
    return "matlab";
}

QColor TpFamilyMatlabLexer::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Editor/Color/Comment", QColor);
    case Command:
        return GET_SETTINGS("Editor/Color/Command", QColor);
    case Number:
        return GET_SETTINGS("Editor/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Editor/Color/Keyword", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Color/SingleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Editor/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/Color/Identifier", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Color/DoubleQuotedString", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpFamilyMatlabLexer::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Editor/Fill/Comment", bool);
    case Command:
        return GET_SETTINGS("Editor/Fill/Command", bool);
    case Number:
        return GET_SETTINGS("Editor/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Editor/Fill/Keyword", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Fill/SingleQuotedString", bool);
    case Operator:
        return GET_SETTINGS("Editor/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Editor/Fill/Identifier", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Fill/DoubleQuotedString", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpFamilyMatlabLexer::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Editor/Font/Comment", QFont);
    case Command:
        return GET_SETTINGS("Editor/Font/Command", QFont);
    case Number:
        return GET_SETTINGS("Editor/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Editor/Font/Keyword", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Font/SingleQuotedString", QFont);
    case Operator:
        return GET_SETTINGS("Editor/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Editor/Font/Identifier", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Font/DoubleQuotedString", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpFamilyMatlabLexer::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Editor/BgColor/Comment", QColor);
    case Command:
        return GET_SETTINGS("Editor/BgColor/Command", QColor);
    case Number:
        return GET_SETTINGS("Editor/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Editor/BgColor/Keyword", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/BgColor/SingleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Editor/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/BgColor/Identifier", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/BgColor/DoubleQuotedString", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpFamilyMatlabLexer::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerMatlabKeyword1;
    default:
        return 0;
    }
}

QString TpFamilyMatlabLexer::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case Command:
        return tr("Command");
    case Number:
        return tr("Number");
    case Keyword:
        return tr("Keyword");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case DoubleQuotedString:
        return tr("Double-quoted string");
    }

    return QString();
}

TP_END_NAMESPACE
