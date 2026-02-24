#include <Lexers/TpLexerAviSynth>

TP_NAMESPACE

TpLexerAviSynth::TpLexerAviSynth(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldCompact(true),
    m_foldComments(true)
{}

TpLexerAviSynth::~TpLexerAviSynth()
{}

const char *TpLexerAviSynth::language() const
{
    return "AviSynth";
}

const char *TpLexerAviSynth::lexer() const
{
    return "avs";
}

int TpLexerAviSynth::braceStyle() const
{
    return Operator;
}

const char *TpLexerAviSynth::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_#";
}

QColor TpLexerAviSynth::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/AviSynth/Color/Universal", QColor);
    case BlockComment:
        return GET_SETTINGS("Lexer/AviSynth/Color/BlockComment", QColor);
    case NestedBlockComment:
        return GET_SETTINGS("Lexer/AviSynth/Color/NestedBlockComment", QColor);
    case LineComment:
        return GET_SETTINGS("Lexer/AviSynth/Color/LineComment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/AviSynth/Color/Number", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/AviSynth/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/AviSynth/Color/Identifier", QColor);
    case String:
        return GET_SETTINGS("Lexer/AviSynth/Color/String", QColor);
    case TripleString:
        return GET_SETTINGS("Lexer/AviSynth/Color/TripleString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/AviSynth/Color/Keyword", QColor);
    case Filter:
        return GET_SETTINGS("Lexer/AviSynth/Color/Filter", QColor);
    case Plugin:
        return GET_SETTINGS("Lexer/AviSynth/Color/Plugin", QColor);
    case Function:
        return GET_SETTINGS("Lexer/AviSynth/Color/Function", QColor);
    case ClipProperty:
        return GET_SETTINGS("Lexer/AviSynth/Color/ClipProperty", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/AviSynth/Color/KeywordSet6", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerAviSynth::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/AviSynth/Fill/Universal", bool);
    case BlockComment:
        return GET_SETTINGS("Lexer/AviSynth/Fill/BlockComment", bool);
    case NestedBlockComment:
        return GET_SETTINGS("Lexer/AviSynth/Fill/NestedBlockComment", bool);
    case LineComment:
        return GET_SETTINGS("Lexer/AviSynth/Fill/LineComment", bool);
    case Number:
        return GET_SETTINGS("Lexer/AviSynth/Fill/Number", bool);
    case Operator:
        return GET_SETTINGS("Lexer/AviSynth/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/AviSynth/Fill/Identifier", bool);
    case String:
        return GET_SETTINGS("Lexer/AviSynth/Fill/String", bool);
    case TripleString:
        return GET_SETTINGS("Lexer/AviSynth/Fill/TripleString", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/AviSynth/Fill/Keyword", bool);
    case Filter:
        return GET_SETTINGS("Lexer/AviSynth/Fill/Filter", bool);
    case Plugin:
        return GET_SETTINGS("Lexer/AviSynth/Fill/Plugin", bool);
    case Function:
        return GET_SETTINGS("Lexer/AviSynth/Fill/Function", bool);
    case ClipProperty:
        return GET_SETTINGS("Lexer/AviSynth/Fill/ClipProperty", bool);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/AviSynth/Fill/KeywordSet6", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerAviSynth::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/AviSynth/Font/Universal", QFont);
    case BlockComment:
        return GET_SETTINGS("Lexer/AviSynth/Font/BlockComment", QFont);
    case NestedBlockComment:
        return GET_SETTINGS("Lexer/AviSynth/Font/NestedBlockComment", QFont);
    case LineComment:
        return GET_SETTINGS("Lexer/AviSynth/Font/LineComment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/AviSynth/Font/Number", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/AviSynth/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/AviSynth/Font/Identifier", QFont);
    case String:
        return GET_SETTINGS("Lexer/AviSynth/Font/String", QFont);
    case TripleString:
        return GET_SETTINGS("Lexer/AviSynth/Font/TripleString", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/AviSynth/Font/Keyword", QFont);
    case Filter:
        return GET_SETTINGS("Lexer/AviSynth/Font/Filter", QFont);
    case Plugin:
        return GET_SETTINGS("Lexer/AviSynth/Font/Plugin", QFont);
    case Function:
        return GET_SETTINGS("Lexer/AviSynth/Font/Function", QFont);
    case ClipProperty:
        return GET_SETTINGS("Lexer/AviSynth/Font/ClipProperty", QFont);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/AviSynth/Font/KeywordSet6", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerAviSynth::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/Universal", QColor);
    case BlockComment:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/BlockComment", QColor);
    case NestedBlockComment:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/NestedBlockComment", QColor);
    case LineComment:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/LineComment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/Number", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/Identifier", QColor);
    case String:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/String", QColor);
    case TripleString:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/TripleString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/Keyword", QColor);
    case Filter:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/Filter", QColor);
    case Plugin:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/Plugin", QColor);
    case Function:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/Function", QColor);
    case ClipProperty:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/ClipProperty", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/AviSynth/BgColor/KeywordSet6", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerAviSynth::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerAviSynthKeyword1;
    case 2:
        return lexerAviSynthKeyword2;
    case 3:
        return lexerAviSynthKeyword3;
    case 4:
        return lexerAviSynthKeyword4;
    case 5:
        return lexerAviSynthKeyword5;
    default:
        return 0;
    }
}

QString TpLexerAviSynth::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case BlockComment:
        return tr("Block comment");
    case NestedBlockComment:
        return tr("Nested block comment");
    case LineComment:
        return tr("Line comment");
    case Number:
        return tr("Number");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case String:
        return tr("Double-quoted string");
    case TripleString:
        return tr("Triple double-quoted string");
    case Keyword:
        return tr("Keyword");
    case Filter:
        return tr("Filter");
    case Plugin:
        return tr("Plugin");
    case Function:
        return tr("Function");
    case ClipProperty:
        return tr("Clip property");
    case KeywordSet6:
        return tr("User defined");
    }

    return QString();
}

void TpLexerAviSynth::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
}

void TpLexerAviSynth::setLexerProperty(int prop, QVariant value)
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

QVariant TpLexerAviSynth::lexerProperty(int prop) const
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

bool TpLexerAviSynth::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);

    return true;
}

bool TpLexerAviSynth::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);

    return true;
}

TP_END_NAMESPACE
