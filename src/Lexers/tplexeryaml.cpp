#include <Lexers/TpLexerYAML>

TP_NAMESPACE

TpLexerYAML::TpLexerYAML(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true)
{}

TpLexerYAML::~TpLexerYAML()
{}

const char *TpLexerYAML::language() const
{
    return "YAML";
}

const char *TpLexerYAML::lexer() const
{
    return "yaml";
}

QColor TpLexerYAML::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/YAML/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/YAML/Color/Comment", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/YAML/Color/Identifier", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/YAML/Color/Keyword", QColor);
    case Number:
        return GET_SETTINGS("Lexer/YAML/Color/Number", QColor);
    case Reference:
        return GET_SETTINGS("Lexer/YAML/Color/Reference", QColor);
    case DocumentDelimiter:
        return GET_SETTINGS("Lexer/YAML/Color/DocumentDelimiter", QColor);
    case TextBlockMarker:
        return GET_SETTINGS("Lexer/YAML/Color/TextBlockMarker", QColor);
    case SyntaxErrorMarker:
        return GET_SETTINGS("Lexer/YAML/Color/SyntaxErrorMarker", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/YAML/Color/Operator", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerYAML::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/YAML/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/YAML/Fill/Comment", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/YAML/Fill/Identifier", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/YAML/Fill/Keyword", bool);
    case Number:
        return GET_SETTINGS("Lexer/YAML/Fill/Number", bool);
    case Reference:
        return GET_SETTINGS("Lexer/YAML/Fill/Reference", bool);
    case DocumentDelimiter:
        return GET_SETTINGS("Lexer/YAML/Fill/DocumentDelimiter", bool);
    case TextBlockMarker:
        return GET_SETTINGS("Lexer/YAML/Fill/TextBlockMarker", bool);
    case SyntaxErrorMarker:
        return GET_SETTINGS("Lexer/YAML/Fill/SyntaxErrorMarker", bool);
    case Operator:
        return GET_SETTINGS("Lexer/YAML/Fill/Operator", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerYAML::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/YAML/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/YAML/Font/Comment", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/YAML/Font/Identifier", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/YAML/Font/Keyword", QFont);
    case Number:
        return GET_SETTINGS("Lexer/YAML/Font/Number", QFont);
    case Reference:
        return GET_SETTINGS("Lexer/YAML/Font/Reference", QFont);
    case DocumentDelimiter:
        return GET_SETTINGS("Lexer/YAML/Font/DocumentDelimiter", QFont);
    case TextBlockMarker:
        return GET_SETTINGS("Lexer/YAML/Font/TextBlockMarker", QFont);
    case SyntaxErrorMarker:
        return GET_SETTINGS("Lexer/YAML/Font/SyntaxErrorMarker", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/YAML/Font/Operator", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerYAML::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/YAML/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/YAML/BgColor/Comment", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/YAML/BgColor/Identifier", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/YAML/BgColor/Keyword", QColor);
    case Number:
        return GET_SETTINGS("Lexer/YAML/BgColor/Number", QColor);
    case Reference:
        return GET_SETTINGS("Lexer/YAML/BgColor/Reference", QColor);
    case DocumentDelimiter:
        return GET_SETTINGS("Lexer/YAML/BgColor/DocumentDelimiter", QColor);
    case TextBlockMarker:
        return GET_SETTINGS("Lexer/YAML/BgColor/TextBlockMarker", QColor);
    case SyntaxErrorMarker:
        return GET_SETTINGS("Lexer/YAML/BgColor/SyntaxErrorMarker", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/YAML/BgColor/Operator", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerYAML::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerYAMLKeyword1;
    default:
        return 0;
    }
}

QString TpLexerYAML::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case Identifier:
        return tr("Identifier");
    case Keyword:
        return tr("Keyword");
    case Number:
        return tr("Number");
    case Reference:
        return tr("Reference");
    case DocumentDelimiter:
        return tr("Document delimiter");
    case TextBlockMarker:
        return tr("Text block marker");
    case SyntaxErrorMarker:
        return tr("Syntax error marker");
    case Operator:
        return tr("Operator");
    }

    return QString();
}

void TpLexerYAML::refreshProperties()
{
    setLexerProperty(PropFoldComments, m_foldComments);
}

void TpLexerYAML::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFoldComments: {
        m_foldComments = value.toBool();
        emit propertyChanged("fold.comment.yaml", (m_foldComments ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerYAML::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldComments:
        return m_foldComments;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerYAML::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);

    return true;
}

bool TpLexerYAML::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);

    return true;
}

TP_END_NAMESPACE
