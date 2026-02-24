#include <Lexers/TpLexerBatch>

TP_NAMESPACE

TpLexerBatch::TpLexerBatch(QObject *parent)
    : TpGeneralLexer(parent)
{}

TpLexerBatch::~TpLexerBatch()
{}

const char *TpLexerBatch::language() const
{
    return "Batch";
}

const char *TpLexerBatch::lexer() const
{
    return "batch";
}

const char *TpLexerBatch::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-";
}

bool TpLexerBatch::caseSensitive() const
{
    return false;
}

QColor TpLexerBatch::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Batch/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Batch/Color/Comment", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Batch/Color/Keyword", QColor);
    case Label:
        return GET_SETTINGS("Lexer/Batch/Color/Label", QColor);
    case HideCommandChar:
        return GET_SETTINGS("Lexer/Batch/Color/HideCommandChar", QColor);
    case ExternalCommand:
        return GET_SETTINGS("Lexer/Batch/Color/ExternalCommand", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/Batch/Color/Variable", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Batch/Color/Operator", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerBatch::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Batch/Color/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Batch/Color/Comment", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Batch/Color/Keyword", bool);
    case Label:
        return GET_SETTINGS("Lexer/Batch/Color/Label", bool);
    case HideCommandChar:
        return GET_SETTINGS("Lexer/Batch/Color/HideCommandChar", bool);
    case ExternalCommand:
        return GET_SETTINGS("Lexer/Batch/Color/ExternalCommand", bool);
    case Variable:
        return GET_SETTINGS("Lexer/Batch/Color/Variable", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Batch/Color/Operator", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerBatch::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Batch/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Batch/Font/Comment", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Batch/Font/Keyword", QFont);
    case Label:
        return GET_SETTINGS("Lexer/Batch/Font/Label", QFont);
    case HideCommandChar:
        return GET_SETTINGS("Lexer/Batch/Font/HideCommandChar", QFont);
    case ExternalCommand:
        return GET_SETTINGS("Lexer/Batch/Font/ExternalCommand", QFont);
    case Variable:
        return GET_SETTINGS("Lexer/Batch/Font/Variable", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Batch/Font/Operator", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerBatch::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Batch/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Batch/BgColor/Comment", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Batch/BgColor/Keyword", QColor);
    case Label:
        return GET_SETTINGS("Lexer/Batch/BgColor/Label", QColor);
    case HideCommandChar:
        return GET_SETTINGS("Lexer/Batch/BgColor/HideCommandChar", QColor);
    case ExternalCommand:
        return GET_SETTINGS("Lexer/Batch/BgColor/ExternalCommand", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/Batch/BgColor/Variable", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Batch/BgColor/Operator", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerBatch::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerBatchKeyword1;
    default:
        return 0;
    }
}

QString TpLexerBatch::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case Keyword:
        return tr("Keyword");
    case Label:
        return tr("Label");
    case HideCommandChar:
        return tr("Hide command character");
    case ExternalCommand:
        return tr("External command");
    case Variable:
        return tr("Variable");
    case Operator:
        return tr("Operator");
    }

    return QString();
}

TP_END_NAMESPACE
