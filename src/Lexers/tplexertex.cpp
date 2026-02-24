#include <Lexers/TpLexerTeX>

TP_NAMESPACE

TpLexerTeX::TpLexerTeX(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true),
    m_foldCompact(true),
    m_processComments(true),
    m_processIf(true)
{}

TpLexerTeX::~TpLexerTeX()
{}

const char *TpLexerTeX::language() const
{
    return "TeX";
}

const char *TpLexerTeX::lexer() const
{
    return "tex";
}

const char *TpLexerTeX::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\\@";
}

QColor TpLexerTeX::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TeX/Color/Universal", QColor);
    case Special:
        return GET_SETTINGS("Lexer/TeX/Color/Special", QColor);
    case Group:
        return GET_SETTINGS("Lexer/TeX/Color/Group", QColor);
    case Symbol:
        return GET_SETTINGS("Lexer/TeX/Color/Symbol", QColor);
    case Command:
        return GET_SETTINGS("Lexer/TeX/Color/Command", QColor);
    case Text:
        return GET_SETTINGS("Lexer/TeX/Color/Text", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerTeX::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TeX/Fill/Universal", bool);
    case Special:
        return GET_SETTINGS("Lexer/TeX/Fill/Special", bool);
    case Group:
        return GET_SETTINGS("Lexer/TeX/Fill/Group", bool);
    case Symbol:
        return GET_SETTINGS("Lexer/TeX/Fill/Symbol", bool);
    case Command:
        return GET_SETTINGS("Lexer/TeX/Fill/Command", bool);
    case Text:
        return GET_SETTINGS("Lexer/TeX/Fill/Text", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerTeX::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TeX/Font/Universal", QFont);
    case Special:
        return GET_SETTINGS("Lexer/TeX/Font/Special", QFont);
    case Group:
        return GET_SETTINGS("Lexer/TeX/Font/Group", QFont);
    case Symbol:
        return GET_SETTINGS("Lexer/TeX/Font/Symbol", QFont);
    case Command:
        return GET_SETTINGS("Lexer/TeX/Font/Command", QFont);
    case Text:
        return GET_SETTINGS("Lexer/TeX/Font/Text", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerTeX::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TeX/BgColor/Universal", QColor);
    case Special:
        return GET_SETTINGS("Lexer/TeX/BgColor/Special", QColor);
    case Group:
        return GET_SETTINGS("Lexer/TeX/BgColor/Group", QColor);
    case Symbol:
        return GET_SETTINGS("Lexer/TeX/BgColor/Symbol", QColor);
    case Command:
        return GET_SETTINGS("Lexer/TeX/BgColor/Command", QColor);
    case Text:
        return GET_SETTINGS("Lexer/TeX/BgColor/Text", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerTeX::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerTeXKeyword1;
    default:
        return 0;
    }
}

QString TpLexerTeX::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Special:
        return tr("Special");
    case Group:
        return tr("Group");
    case Symbol:
        return tr("Symbol");
    case Command:
        return tr("Command");
    case Text:
        return tr("Text");
    }

    return QString();
}

void TpLexerTeX::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
    setLexerProperty(PropProcessComments, m_processComments);
    setLexerProperty(PropProcessIf, m_processIf);
}

void TpLexerTeX::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    case PropFoldComments: {
        m_foldComments = value.toBool();
        emit propertyChanged("fold.comment", (m_foldComments ? "1" : "0"));
        break;
    }
    case PropProcessComments: {
        m_processComments = value.toBool();
        emit propertyChanged("lexer.tex.comment.process", (m_processComments ? "1" : "0"));
        break;
    }
    case PropProcessIf: {
        m_processIf = value.toBool();
        emit propertyChanged("lexer.tex.auto.if", (m_processIf ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerTeX::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldComments:
        return m_foldComments;
    case PropProcessComments:
        return m_processComments;
    case PropProcessIf:
        return m_processIf;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerTeX::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_processComments = GET_SETTINGS_WITH(prefix + "processComments", bool, true);
    m_processIf = GET_SETTINGS_WITH(prefix + "processIf", bool, true);

    return true;
}

bool TpLexerTeX::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "processComments", m_processComments);
    SET_SETTINGS(prefix + "processIf", m_processIf);

    return true;
}

TP_END_NAMESPACE
