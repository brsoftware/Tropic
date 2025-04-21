#include <Lexers/TpLexerNone>

TP_NAMESPACE

TpLexerNone::TpLexerNone(QObject *parent)
    : TpGeneralLexer(parent)
{}

TpLexerNone::~TpLexerNone()
{}

const char *TpLexerNone::language() const
{
    return "";
}

const char *TpLexerNone::lexer() const
{
    return "";
}

QColor TpLexerNone::defaultColor(int style) const
{
    Q_UNUSED(style)

    DEF_SETTINGS;
    return GET_SETTINGS("Editor/Color/Universal", QColor);
}

bool TpLexerNone::defaultEolFill(int style) const
{
    return QsciLexer::defaultEolFill(style);
}

QFont TpLexerNone::defaultFont(int style) const
{
    Q_UNUSED(style)

    DEF_SETTINGS;
    return GET_SETTINGS("Editor/Font/Universal", QFont);
}

QString TpLexerNone::description(int style) const
{
    return QString();
}

QColor TpLexerNone::defaultPaper(int style) const
{
    Q_UNUSED(style)

    DEF_SETTINGS;
    return GET_SETTINGS("Editor/BgColor/Universal", QColor);
}

TP_END_NAMESPACE
