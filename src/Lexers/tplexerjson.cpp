#include <Lexers/TpLexerJSON>

TP_NAMESPACE

TpLexerJSON::TpLexerJSON(QObject *parent)
    : TpGeneralLexer(parent),
    m_escapeSequence(true),
    m_allowComments(true),
    m_foldCompact(true),
    m_fold(true)
{}

TpLexerJSON::~TpLexerJSON()
{}

int TpLexerJSON::autoIndentStyle()
{
    DEF_SETTINGS;
    if (GET_SETTINGS("Tools/Autoindentation/Style/Auto", bool))
        return 0;

    return TpGeneralLexer::autoIndentStyle();
}

const char *TpLexerJSON::language() const
{
    return "JSON";
}

const char *TpLexerJSON::lexer() const
{
    return "json";
}

QColor TpLexerJSON::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Default:
        return GET_SETTINGS("Lexer/JSON/Color/Universal", QColor);
    case Number:
        return GET_SETTINGS("Lexer/JSON/Color/Number", QColor);
    case String:
        return GET_SETTINGS("Lexer/JSON/Color/String", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/JSON/Color/UnclosedString", QColor);
    case Property:
        return GET_SETTINGS("Lexer/JSON/Color/Property", QColor);
    case EscapeSequence:
        return GET_SETTINGS("Lexer/JSON/Color/EscapeSequence", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/JSON/Color/CommentLine", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/JSON/Color/CommentBlock", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/JSON/Color/Operator", QColor);
    case IRI:
        return GET_SETTINGS("Lexer/JSON/Color/IRI", QColor);
    case IRICompact:
        return GET_SETTINGS("Lexer/JSON/Color/IRICompact", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/JSON/Color/Keyword", QColor);
    case KeywordLD:
        return GET_SETTINGS("Lexer/JSON/Color/KeywordLD", QColor);
    case Error:
        return GET_SETTINGS("Lexer/JSON/Color/Error", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerJSON::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Default:
        return GET_SETTINGS("Lexer/JSON/Fill/Universal", bool);
    case Number:
        return GET_SETTINGS("Lexer/JSON/Fill/Number", bool);
    case String:
        return GET_SETTINGS("Lexer/JSON/Fill/String", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/JSON/Fill/UnclosedString", bool);
    case Property:
        return GET_SETTINGS("Lexer/JSON/Fill/Property", bool);
    case EscapeSequence:
        return GET_SETTINGS("Lexer/JSON/Fill/EscapeSequence", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/JSON/Fill/CommentLine", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/JSON/Fill/CommentBlock", bool);
    case Operator:
        return GET_SETTINGS("Lexer/JSON/Fill/Operator", bool);
    case IRI:
        return GET_SETTINGS("Lexer/JSON/Fill/IRI", bool);
    case IRICompact:
        return GET_SETTINGS("Lexer/JSON/Fill/IRICompact", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/JSON/Fill/Keyword", bool);
    case KeywordLD:
        return GET_SETTINGS("Lexer/JSON/Fill/KeywordLD", bool);
    case Error:
        return GET_SETTINGS("Lexer/JSON/Fill/Error", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerJSON::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Default:
        return GET_SETTINGS("Lexer/JSON/Font/Universal", QFont);
    case Number:
        return GET_SETTINGS("Lexer/JSON/Font/Number", QFont);
    case String:
        return GET_SETTINGS("Lexer/JSON/Font/String", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/JSON/Font/UnclosedString", QFont);
    case Property:
        return GET_SETTINGS("Lexer/JSON/Font/Property", QFont);
    case EscapeSequence:
        return GET_SETTINGS("Lexer/JSON/Font/EscapeSequence", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/JSON/Font/CommentLine", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/JSON/Font/CommentBlock", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/JSON/Font/Operator", QFont);
    case IRI:
        return GET_SETTINGS("Lexer/JSON/Font/IRI", QFont);
    case IRICompact:
        return GET_SETTINGS("Lexer/JSON/Font/IRICompact", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/JSON/Font/Keyword", QFont);
    case KeywordLD:
        return GET_SETTINGS("Lexer/JSON/Font/KeywordLD", QFont);
    case Error:
        return GET_SETTINGS("Lexer/JSON/Font/Error", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerJSON::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Default:
        return GET_SETTINGS("Lexer/JSON/BgColor/Universal", QColor);
    case Number:
        return GET_SETTINGS("Lexer/JSON/BgColor/Number", QColor);
    case String:
        return GET_SETTINGS("Lexer/JSON/BgColor/String", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/JSON/BgColor/UnclosedString", QColor);
    case Property:
        return GET_SETTINGS("Lexer/JSON/BgColor/Property", QColor);
    case EscapeSequence:
        return GET_SETTINGS("Lexer/JSON/BgColor/EscapeSequence", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/JSON/BgColor/CommentLine", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/JSON/BgColor/CommentBlock", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/JSON/BgColor/Operator", QColor);
    case IRI:
        return GET_SETTINGS("Lexer/JSON/BgColor/IRI", QColor);
    case IRICompact:
        return GET_SETTINGS("Lexer/JSON/BgColor/IRICompact", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/JSON/BgColor/Keyword", QColor);
    case KeywordLD:
        return GET_SETTINGS("Lexer/JSON/BgColor/KeywordLD", QColor);
    case Error:
        return GET_SETTINGS("Lexer/JSON/BgColor/Error", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerJSON::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerJSONKeyword1;
    case 2:
        return lexerJSONKeyword2;
    default:
        return 0;
    }
}

QString TpLexerJSON::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Number:
        return tr("Number");
    case String:
        return tr("String");
    case UnclosedString:
        return tr("Unclosed string");
    case Property:
        return tr("Property");
    case EscapeSequence:
        return tr("Escape sequence");
    case CommentLine:
        return tr("Line comment");
    case CommentBlock:
        return tr("Block comment");
    case Operator:
        return tr("Operator");
    case IRI:
        return tr("IRI");
    case IRICompact:
        return tr("JSON-LD compact IRI");
    case Keyword:
        return tr("JSON keyword");
    case KeywordLD:
        return tr("JSON-LD keyword");
    case Error:
        return tr("Parsing error");
    }

    return QString();
}

void TpLexerJSON::refreshProperties()
{
    setLexerProperty(PropEscapeSequence, m_escapeSequence);
    setLexerProperty(PropAllowComments, m_allowComments);
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFold, m_fold);
}

void TpLexerJSON::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropEscapeSequence: {
        m_escapeSequence = value.toBool();
        emit propertyChanged("lexer.json.escape.sequence", (m_escapeSequence ? "1" : "0"));
        break;
    }
    case PropAllowComments: {
        m_allowComments = value.toBool();
        emit propertyChanged("lexer.json.allow.comments", (m_allowComments ? "1" : "0"));
        break;
    }
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    case PropFold: {
        m_fold = value.toBool();
        emit propertyChanged("fold", (m_fold ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerJSON::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropEscapeSequence:
        return m_escapeSequence;
    case PropAllowComments:
        return m_allowComments;
    case PropFoldCompact:
        return m_foldCompact;
    case PropFold:
        return m_fold;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerJSON::readProperties(QSettings &settings, const QString &prefix)
{
    m_escapeSequence = GET_SETTINGS_WITH(prefix + "escapesequence", bool, true);
    m_allowComments = GET_SETTINGS_WITH(prefix + "allowcomments", bool, true);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_fold = GET_SETTINGS_WITH(prefix + "fold", bool, true);

    return true;
}

bool TpLexerJSON::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "escapesequence", m_escapeSequence);
    SET_SETTINGS(prefix + "allowcomments", m_allowComments);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "fold", m_fold);

    return true;
}

TP_END_NAMESPACE
