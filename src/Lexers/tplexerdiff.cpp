#include <Lexers/TpLexerDiff>

TP_NAMESPACE

TpLexerDiff::TpLexerDiff(QObject *parent)
    : TpGeneralLexer(parent)
{}

TpLexerDiff::~TpLexerDiff()
{}

const char *TpLexerDiff::language() const
{
    return "Diff";
}

const char *TpLexerDiff::lexer() const
{
    return "diff";
}

const char *TpLexerDiff::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-";
}

QColor TpLexerDiff::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case LineRemoved:
    case LineAdded:
    case LineChanged:
    case AddingPatchAdded:
    case RemovingPatchAdded:
    case AddingPatchRemoved:
    case RemovingPatchRemoved:
        return GET_SETTINGS("Lexer/Diff/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Diff/Color/Comment", QColor);
    case Command:
        return GET_SETTINGS("Lexer/Diff/Color/Command", QColor);
    case Header:
        return GET_SETTINGS("Lexer/Diff/Color/Header", QColor);
    case Position:
        return GET_SETTINGS("Lexer/Diff/Color/Position", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerDiff::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case LineRemoved:
    case LineAdded:
    case LineChanged:
    case AddingPatchAdded:
    case RemovingPatchAdded:
    case AddingPatchRemoved:
    case RemovingPatchRemoved:
        return GET_SETTINGS("Lexer/Diff/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Diff/Fill/Comment", bool);
    case Command:
        return GET_SETTINGS("Lexer/Diff/Fill/Command", bool);
    case Header:
        return GET_SETTINGS("Lexer/Diff/Fill/Header", bool);
    case Position:
        return GET_SETTINGS("Lexer/Diff/Fill/Position", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerDiff::defaultFont(int style) const
{
    DEF_SETTINGS;

    return GET_SETTINGS("Lexer/Diff/Font", QFont);
}

QColor TpLexerDiff::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Diff/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Diff/BgColor/Comment", QColor);
    case Command:
        return GET_SETTINGS("Lexer/Diff/BgColor/Command", QColor);
    case Header:
        return GET_SETTINGS("Lexer/Diff/BgColor/Header", QColor);
    case Position:
        return GET_SETTINGS("Lexer/Diff/BgColor/Position", QColor);
    case LineRemoved:
        return GET_SETTINGS("Lexer/Diff/BgColor/LineRemoved", QColor);
    case LineAdded:
        return GET_SETTINGS("Lexer/Diff/BgColor/LineAdded", QColor);
    case LineChanged:
        return GET_SETTINGS("Lexer/Diff/BgColor/LineChanged", QColor);
    case AddingPatchAdded:
        return GET_SETTINGS("Lexer/Diff/BgColor/AddingPatchAdded", QColor);
    case RemovingPatchAdded:
        return GET_SETTINGS("Lexer/Diff/BgColor/RemovingPatchAdded", QColor);
    case AddingPatchRemoved:
        return GET_SETTINGS("Lexer/Diff/BgColor/AddingPatchRemoved", QColor);
    case RemovingPatchRemoved:
        return GET_SETTINGS("Lexer/Diff/BgColor/RemovingPatchRemoved", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

QString TpLexerDiff::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case Command:
        return tr("Command");
    case Header:
        return tr("Header");
    case Position:
        return tr("Position");
    case LineRemoved:
        return tr("Removed line");
    case LineAdded:
        return tr("Added line");
    case LineChanged:
        return tr("Changed line");
    case AddingPatchAdded:
        return tr("Added adding patch");
    case RemovingPatchAdded:
        return tr("Removed adding patch");
    case AddingPatchRemoved:
        return tr("Added removing patch");
    case RemovingPatchRemoved:
        return tr("Removed removing patch");
    }

    return QString();
}

TP_END_NAMESPACE
