#include <Lexers/TpLexerLaTeX>

TP_NAMESPACE

TpLexerLaTeX::TpLexerLaTeX(QObject *parent)
    : TpGeneralLexer(parent)
{}

TpLexerLaTeX::~TpLexerLaTeX()
{}

const char *TpLexerLaTeX::language() const
{
    return "LaTeX";
}

const char *TpLexerLaTeX::lexer() const
{
    return "latex";
}

QColor TpLexerLaTeX::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/LaTeX/Color/Universal", QColor);
    case Command:
        return GET_SETTINGS("Lexer/LaTeX/Color/Command", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/LaTeX/Color/Tag", QColor);
    case Math:
        return GET_SETTINGS("Lexer/LaTeX/Color/Math", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/LaTeX/Color/Comment", QColor);
    case TagSet2:
        return GET_SETTINGS("Lexer/LaTeX/Color/TagSet2", QColor);
    case MathSet2:
        return GET_SETTINGS("Lexer/LaTeX/Color/MathSet2", QColor);
    case CommentSet2:
        return GET_SETTINGS("Lexer/LaTeX/Color/CommentSet2", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/LaTeX/Color/VerbatimString", QColor);
    case ShortCommand:
        return GET_SETTINGS("Lexer/LaTeX/Color/ShortCommand", QColor);
    case Special:
        return GET_SETTINGS("Lexer/LaTeX/Color/Special", QColor);
    case CommandOption:
        return GET_SETTINGS("Lexer/LaTeX/Color/CommandOption", QColor);
    case Error:
        return GET_SETTINGS("Lexer/LaTeX/Color/Error", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerLaTeX::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/LaTeX/Fill/Universal", bool);
    case Command:
        return GET_SETTINGS("Lexer/LaTeX/Fill/Command", bool);
    case Tag:
        return GET_SETTINGS("Lexer/LaTeX/Fill/Tag", bool);
    case Math:
        return GET_SETTINGS("Lexer/LaTeX/Fill/Math", bool);
    case Comment:
        return GET_SETTINGS("Lexer/LaTeX/Fill/Comment", bool);
    case TagSet2:
        return GET_SETTINGS("Lexer/LaTeX/Fill/TagSet2", bool);
    case MathSet2:
        return GET_SETTINGS("Lexer/LaTeX/Fill/MathSet2", bool);
    case CommentSet2:
        return GET_SETTINGS("Lexer/LaTeX/Fill/CommentSet2", bool);
    case VerbatimString:
        return GET_SETTINGS("Lexer/LaTeX/Fill/VerbatimString", bool);
    case ShortCommand:
        return GET_SETTINGS("Lexer/LaTeX/Fill/ShortCommand", bool);
    case Special:
        return GET_SETTINGS("Lexer/LaTeX/Fill/Special", bool);
    case CommandOption:
        return GET_SETTINGS("Lexer/LaTeX/Fill/CommandOption", bool);
    case Error:
        return GET_SETTINGS("Lexer/LaTeX/Fill/Error", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerLaTeX::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/LaTeX/Font/Universal", QFont);
    case Command:
        return GET_SETTINGS("Lexer/LaTeX/Font/Command", QFont);
    case Tag:
        return GET_SETTINGS("Lexer/LaTeX/Font/Tag", QFont);
    case Math:
        return GET_SETTINGS("Lexer/LaTeX/Font/Math", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/LaTeX/Font/Comment", QFont);
    case TagSet2:
        return GET_SETTINGS("Lexer/LaTeX/Font/TagSet2", QFont);
    case MathSet2:
        return GET_SETTINGS("Lexer/LaTeX/Font/MathSet2", QFont);
    case CommentSet2:
        return GET_SETTINGS("Lexer/LaTeX/Font/CommentSet2", QFont);
    case VerbatimString:
        return GET_SETTINGS("Lexer/LaTeX/Font/VerbatimString", QFont);
    case ShortCommand:
        return GET_SETTINGS("Lexer/LaTeX/Font/ShortCommand", QFont);
    case Special:
        return GET_SETTINGS("Lexer/LaTeX/Font/Special", QFont);
    case CommandOption:
        return GET_SETTINGS("Lexer/LaTeX/Font/CommandOption", QFont);
    case Error:
        return GET_SETTINGS("Lexer/LaTeX/Font/Error", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerLaTeX::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/Universal", QColor);
    case Command:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/Command", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/Tag", QColor);
    case Math:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/Math", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/Comment", QColor);
    case TagSet2:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/TagSet2", QColor);
    case MathSet2:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/MathSet2", QColor);
    case CommentSet2:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/CommentSet2", QColor);
    case VerbatimString:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/VerbatimString", QColor);
    case ShortCommand:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/ShortCommand", QColor);
    case Special:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/Special", QColor);
    case CommandOption:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/CommandOption", QColor);
    case Error:
        return GET_SETTINGS("Lexer/LaTeX/BgColor/Error", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

QString TpLexerLaTeX::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Command:
        return tr("Command");
    case Tag:
        return tr("Tag");
    case Math:
        return tr("Math command");
    case TagSet2:
        return tr("Tag set 2");
    case MathSet2:
        return tr("Math command set 2");
    case CommentSet2:
        return tr("Comment set 2");
    case VerbatimString:
        return tr("Verbatim string");
    case ShortCommand:
        return tr("Short command");
    case Special:
        return tr("Special");
    case CommandOption:
        return tr("Command option");
    case Error:
        return tr("Error");
    }

    return QString();
}

TP_END_NAMESPACE
