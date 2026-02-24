#include <Lexers/TpLexerMakefile>

TP_NAMESPACE

TpLexerMakefile::TpLexerMakefile(QObject *parent)
    : TpGeneralLexer(parent)
{}

TpLexerMakefile::~TpLexerMakefile()
{}

const char *TpLexerMakefile::language() const
{
    return "Makefile";
}

const char *TpLexerMakefile::lexer() const
{
    return "makefile";
}

const char *TpLexerMakefile::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-";
}

QColor TpLexerMakefile::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Makefile/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Makefile/Color/Comment", QColor);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Makefile/Color/Preprocessor", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/Makefile/Color/Variable", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Makefile/Color/Operator", QColor);
    case Target:
        return GET_SETTINGS("Lexer/Makefile/Color/Target", QColor);
    case Error:
        return GET_SETTINGS("Lexer/Makefile/Color/Error", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerMakefile::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Makefile/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Makefile/Fill/Comment", bool);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Makefile/Fill/Preprocessor", bool);
    case Variable:
        return GET_SETTINGS("Lexer/Makefile/Fill/Variable", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Makefile/Fill/Operator", bool);
    case Target:
        return GET_SETTINGS("Lexer/Makefile/Fill/Target", bool);
    case Error:
        return GET_SETTINGS("Lexer/Makefile/Fill/Error", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerMakefile::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Makefile/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Makefile/Font/Comment", QFont);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Makefile/Font/Preprocessor", QFont);
    case Variable:
        return GET_SETTINGS("Lexer/Makefile/Font/Variable", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Makefile/Font/Operator", QFont);
    case Target:
        return GET_SETTINGS("Lexer/Makefile/Font/Target", QFont);
    case Error:
        return GET_SETTINGS("Lexer/Makefile/Font/Error", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerMakefile::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Makefile/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Makefile/BgColor/Comment", QColor);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Makefile/BgColor/Preprocessor", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/Makefile/BgColor/Variable", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Makefile/BgColor/Operator", QColor);
    case Target:
        return GET_SETTINGS("Lexer/Makefile/BgColor/Target", QColor);
    case Error:
        return GET_SETTINGS("Lexer/Makefile/BgColor/Error", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

QString TpLexerMakefile::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case Preprocessor:
        return tr("Preprocessor");
    case Variable:
        return tr("Variable");
    case Operator:
        return tr("Operator");
    case Target:
        return tr("Target");
    case Error:
        return tr("Error");
    }

    return QString();
}

TP_END_NAMESPACE
