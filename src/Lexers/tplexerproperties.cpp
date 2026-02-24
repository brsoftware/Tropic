#include <Lexers/TpLexerProperties>

TP_NAMESPACE

TpLexerProperties::TpLexerProperties(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldCompact(true),
    m_initialSpaces(true)
{}

TpLexerProperties::~TpLexerProperties()
{}

const char *TpLexerProperties::language() const
{
    return "Properties";
}

const char *TpLexerProperties::lexer() const
{
    return "props";
}

const char *TpLexerProperties::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-";
}

QColor TpLexerProperties::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Properties/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Properties/Color/Comment", QColor);
    case Section:
        return GET_SETTINGS("Lexer/Properties/Color/Section", QColor);
    case Assignment:
        return GET_SETTINGS("Lexer/Properties/Color/Assignment", QColor);
    case DefaultValue:
        return GET_SETTINGS("Lexer/Properties/Color/DefaultValue", QColor);
    case Key:
        return GET_SETTINGS("Lexer/Properties/Color/Key", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerProperties::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Properties/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Properties/Fill/Comment", bool);
    case Section:
        return GET_SETTINGS("Lexer/Properties/Fill/Section", bool);
    case Assignment:
        return GET_SETTINGS("Lexer/Properties/Fill/Assignment", bool);
    case DefaultValue:
        return GET_SETTINGS("Lexer/Properties/Fill/DefaultValue", bool);
    case Key:
        return GET_SETTINGS("Lexer/Properties/Fill/Key", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerProperties::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Properties/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Properties/Font/Comment", QFont);
    case Section:
        return GET_SETTINGS("Lexer/Properties/Font/Section", QFont);
    case Assignment:
        return GET_SETTINGS("Lexer/Properties/Font/Assignment", QFont);
    case DefaultValue:
        return GET_SETTINGS("Lexer/Properties/Font/DefaultValue", QFont);
    case Key:
        return GET_SETTINGS("Lexer/Properties/Font/Key", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerProperties::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Properties/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Properties/BgColor/Comment", QColor);
    case Section:
        return GET_SETTINGS("Lexer/Properties/BgColor/Section", QColor);
    case Assignment:
        return GET_SETTINGS("Lexer/Properties/BgColor/Assignment", QColor);
    case DefaultValue:
        return GET_SETTINGS("Lexer/Properties/BgColor/DefaultValue", QColor);
    case Key:
        return GET_SETTINGS("Lexer/Properties/BgColor/Key", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

QString TpLexerProperties::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case Section:
        return tr("Section");
    case Assignment:
        return tr("Assignment");
    case DefaultValue:
        return tr("Default value");
    case Key:
        return tr("Key");
    }

    return QString();
}

void TpLexerProperties::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropInitialSpaces, m_initialSpaces);
}

void TpLexerProperties::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    case PropInitialSpaces: {
        m_initialSpaces = value.toBool();
        emit propertyChanged("lexer.props.allow.initial.spaces", (m_initialSpaces ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerProperties::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldCompact:
        return m_foldCompact;
    case PropInitialSpaces:
        return m_initialSpaces;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerProperties::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_initialSpaces = GET_SETTINGS_WITH(prefix + "initialspaces", bool, true);

    return true;
}

bool TpLexerProperties::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "initialspaces", m_initialSpaces);

    return true;
}

TP_END_NAMESPACE
