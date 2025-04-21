#include <Lexers/TpLexerBash>

TP_NAMESPACE

TpLexerBash::TpLexerBash(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true),
    m_foldCompact(true)
{}

TpLexerBash::~TpLexerBash()
{}

const char *TpLexerBash::language() const
{
    return "Bash";
}

const char *TpLexerBash::lexer() const
{
    return "bash";
}

int TpLexerBash::braceStyle() const
{
    return Operator;
}

const char *TpLexerBash::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-$@%&";
}

QColor TpLexerBash::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Bash/Color/Universal", QColor);
    case Error:
        return GET_SETTINGS("Lexer/Bash/Color/Error", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Bash/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Bash/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Bash/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Bash/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Bash/Color/SingleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Bash/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Bash/Color/Identifier", QColor);
    case Scalar:
        return GET_SETTINGS("Lexer/Bash/Color/Scalar", QColor);
    case ParameterExpansion:
        return GET_SETTINGS("Lexer/Bash/Color/ParameterExpansion", QColor);
    case Backticks:
        return GET_SETTINGS("Lexer/Bash/Color/Backticks", QColor);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Bash/Color/HereDocumentDelimiter", QColor);
    case SingleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Bash/Color/SingleQuotedHereDocument", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerBash::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Bash/Fill/Universal", bool);
    case Error:
        return GET_SETTINGS("Lexer/Bash/Fill/Error", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Bash/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/Bash/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Bash/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Bash/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Bash/Fill/SingleQuotedString", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Bash/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Bash/Fill/Identifier", bool);
    case Scalar:
        return GET_SETTINGS("Lexer/Bash/Fill/Scalar", bool);
    case ParameterExpansion:
        return GET_SETTINGS("Lexer/Bash/Fill/ParameterExpansion", bool);
    case Backticks:
        return GET_SETTINGS("Lexer/Bash/Fill/Backticks", bool);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Bash/Fill/HereDocumentDelimiter", bool);
    case SingleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Bash/Fill/SingleQuotedHereDocument", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerBash::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Bash/Font/Universal", QFont);
    case Error:
        return GET_SETTINGS("Lexer/Bash/Font/Error", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Bash/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Bash/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Bash/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Bash/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Bash/Font/SingleQuotedString", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Bash/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Bash/Font/Identifier", QFont);
    case Scalar:
        return GET_SETTINGS("Lexer/Bash/Font/Scalar", QFont);
    case ParameterExpansion:
        return GET_SETTINGS("Lexer/Bash/Font/ParameterExpansion", QFont);
    case Backticks:
        return GET_SETTINGS("Lexer/Bash/Font/Backticks", QFont);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Bash/Font/HereDocumentDelimiter", QFont);
    case SingleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Bash/Font/SingleQuotedHereDocument", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerBash::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Bash/BgColor/Universal", QColor);
    case Error:
        return GET_SETTINGS("Lexer/Bash/BgColor/Error", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Bash/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Bash/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Bash/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Bash/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Bash/BgColor/SingleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Bash/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Bash/BgColor/Identifier", QColor);
    case Scalar:
        return GET_SETTINGS("Lexer/Bash/BgColor/Scalar", QColor);
    case ParameterExpansion:
        return GET_SETTINGS("Lexer/Bash/BgColor/ParameterExpansion", QColor);
    case Backticks:
        return GET_SETTINGS("Lexer/Bash/BgColor/Backticks", QColor);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Bash/BgColor/HereDocumentDelimiter", QColor);
    case SingleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Bash/BgColor/SingleQuotedHereDocument", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerBash::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerBashKeyword1;
    default:
        return 0;
    }
}

QString TpLexerBash::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case Error:
        return tr("Error");
    case Comment:
        return tr("Comment");
    case Number:
        return tr("Number");
    case Keyword:
        return tr("Keyword");
    case DoubleQuotedString:
        return tr("Double-quoted string");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case Scalar:
        return tr("Scalar");
    case ParameterExpansion:
        return tr("Parameter expansion");
    case Backticks:
        return tr("Backticks");
    case HereDocumentDelimiter:
        return tr("Here document delimiter");
    case SingleQuotedHereDocument:
        return tr("Single-quoted here document");
    }

    return QString();
}

void TpLexerBash::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
}

void TpLexerBash::setLexerProperty(int prop, QVariant value)
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
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerBash::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldComments:
        return m_foldComments;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerBash::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);

    return true;
}

bool TpLexerBash::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);

    return true;
}

TP_END_NAMESPACE
