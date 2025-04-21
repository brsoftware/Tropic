#include <Lexers/TpLexerQSS>

TP_NAMESPACE

TpLexerQSS::TpLexerQSS(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldCompact(true),
    m_foldComments(true)
{}

TpLexerQSS::~TpLexerQSS()
{}

int TpLexerQSS::autoIndentStyle()
{
    DEF_SETTINGS;
    if (GET_SETTINGS("Tools/Autoindentation/Style/Auto", bool))
        return 0;

    return TpGeneralLexer::autoIndentStyle();
}

const char *TpLexerQSS::language() const
{
    return "QSS";
}

const char *TpLexerQSS::lexer() const
{
    return "css";
}

const char *TpLexerQSS::blockEnd(int *style) const
{
    if (style)
        *style = Operator;

    return "}";
}

const char *TpLexerQSS::blockStart(int *style) const
{
    if (style)
        *style = Operator;

    return "{";
}

const char *TpLexerQSS::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
}

QColor TpLexerQSS::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/QSS/Color/Universal", QColor);
    case QtType:
        return GET_SETTINGS("Lexer/QSS/Color/QtType", QColor);
    case QtClass:
        return GET_SETTINGS("Lexer/QSS/Color/QtClass", QColor);
    case PseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/Color/PseudoQtClass", QColor);
    case UnknownPseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/Color/UnknownPseudoQtClass", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/QSS/Color/Operator", QColor);
    case ObsoleteProperty:
        return GET_SETTINGS("Lexer/QSS/Color/ObsoleteProperty", QColor);
    case UnknownProperty:
        return GET_SETTINGS("Lexer/QSS/Color/UnknownProperty", QColor);
    case Value:
        return GET_SETTINGS("Lexer/QSS/Color/Value", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/QSS/Color/Comment", QColor);
    case QtIDSelector:
        return GET_SETTINGS("Lexer/QSS/Color/QtIDSelector", QColor);
    case Important:
        return GET_SETTINGS("Lexer/QSS/Color/Important", QColor);
    case AtRule:
        return GET_SETTINGS("Lexer/QSS/Color/AtRule", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/QSS/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/QSS/Color/SingleQuotedString", QColor);
    case Property:
        return GET_SETTINGS("Lexer/QSS/Color/Property", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/QSS/Color/Attribute", QColor);
    case ExperimentalProperty:
        return GET_SETTINGS("Lexer/QSS/Color/ExperimentalProperty", QColor);
    case PseudoQtElement:
        return GET_SETTINGS("Lexer/QSS/Color/PseudoQtElement", QColor);
    case SpecificProperty:
        return GET_SETTINGS("Lexer/QSS/Color/BrowserSpecificProperty", QColor);
    case SpecificPseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/Color/SpecificPseudoQtClass", QColor);
    case SpecificPseudoQtElement:
        return GET_SETTINGS("Lexer/QSS/Color/SpecificPseudoQtElement", QColor);
    case MediaRule:
        return GET_SETTINGS("Lexer/QSS/Color/MediaRule", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/QSS/Color/Variable", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerQSS::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/QSS/Fill/Universal", bool);
    case QtType:
        return GET_SETTINGS("Lexer/QSS/Fill/QtType", bool);
    case QtClass:
        return GET_SETTINGS("Lexer/QSS/Fill/QtClass", bool);
    case PseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/Fill/PseudoQtClass", bool);
    case UnknownPseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/Fill/UnknownPseudoQtClass", bool);
    case Operator:
        return GET_SETTINGS("Lexer/QSS/Fill/Operator", bool);
    case ObsoleteProperty:
        return GET_SETTINGS("Lexer/QSS/Fill/ObsoleteProperty", bool);
    case UnknownProperty:
        return GET_SETTINGS("Lexer/QSS/Fill/UnknownProperty", bool);
    case Value:
        return GET_SETTINGS("Lexer/QSS/Fill/Value", bool);
    case Comment:
        return GET_SETTINGS("Lexer/QSS/Fill/Comment", bool);
    case QtIDSelector:
        return GET_SETTINGS("Lexer/QSS/Fill/QtIDSelector", bool);
    case Important:
        return GET_SETTINGS("Lexer/QSS/Fill/Important", bool);
    case AtRule:
        return GET_SETTINGS("Lexer/QSS/Fill/AtRule", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/QSS/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/QSS/Fill/SingleQuotedString", bool);
    case Property:
        return GET_SETTINGS("Lexer/QSS/Fill/Property", bool);
    case Attribute:
        return GET_SETTINGS("Lexer/QSS/Fill/Attribute", bool);
    case ExperimentalProperty:
        return GET_SETTINGS("Lexer/QSS/Fill/ExperimentalProperty", bool);
    case PseudoQtElement:
        return GET_SETTINGS("Lexer/QSS/Fill/PseudoQtElement", bool);
    case SpecificProperty:
        return GET_SETTINGS("Lexer/QSS/Fill/BrowserSpecificProperty", bool);
    case SpecificPseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/Fill/SpecificPseudoQtClass", bool);
    case SpecificPseudoQtElement:
        return GET_SETTINGS("Lexer/QSS/Fill/SpecificPseudoQtElement", bool);
    case MediaRule:
        return GET_SETTINGS("Lexer/QSS/Fill/MediaRule", bool);
    case Variable:
        return GET_SETTINGS("Lexer/QSS/Fill/Variable", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerQSS::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/QSS/Font/Universal", QFont);
    case QtType:
        return GET_SETTINGS("Lexer/QSS/Font/QtType", QFont);
    case QtClass:
        return GET_SETTINGS("Lexer/QSS/Font/QtClass", QFont);
    case PseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/Font/PseudoQtClass", QFont);
    case UnknownPseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/Font/UnknownPseudoQtClass", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/QSS/Font/Operator", QFont);
    case ObsoleteProperty:
        return GET_SETTINGS("Lexer/QSS/Font/ObsoleteProperty", QFont);
    case UnknownProperty:
        return GET_SETTINGS("Lexer/QSS/Font/UnknownProperty", QFont);
    case Value:
        return GET_SETTINGS("Lexer/QSS/Font/Value", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/QSS/Font/Comment", QFont);
    case QtIDSelector:
        return GET_SETTINGS("Lexer/QSS/Font/QtIDSelector", QFont);
    case Important:
        return GET_SETTINGS("Lexer/QSS/Font/Important", QFont);
    case AtRule:
        return GET_SETTINGS("Lexer/QSS/Font/AtRule", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/QSS/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/QSS/Font/SingleQuotedString", QFont);
    case Property:
        return GET_SETTINGS("Lexer/QSS/Font/Property", QFont);
    case Attribute:
        return GET_SETTINGS("Lexer/QSS/Font/Attribute", QFont);
    case ExperimentalProperty:
        return GET_SETTINGS("Lexer/QSS/Font/ExperimentalProperty", QFont);
    case PseudoQtElement:
        return GET_SETTINGS("Lexer/QSS/Font/PseudoQtElement", QFont);
    case SpecificProperty:
        return GET_SETTINGS("Lexer/QSS/Font/BrowserSpecificProperty", QFont);
    case SpecificPseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/Font/SpecificPseudoQtClass", QFont);
    case SpecificPseudoQtElement:
        return GET_SETTINGS("Lexer/QSS/Font/SpecificPseudoQtElement", QFont);
    case MediaRule:
        return GET_SETTINGS("Lexer/QSS/Font/MediaRule", QFont);
    case Variable:
        return GET_SETTINGS("Lexer/QSS/Font/Variable", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerQSS::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/QSS/BgColor/Universal", QColor);
    case QtType:
        return GET_SETTINGS("Lexer/QSS/BgColor/QtType", QColor);
    case QtClass:
        return GET_SETTINGS("Lexer/QSS/BgColor/QtClass", QColor);
    case PseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/BgColor/PseudoQtClass", QColor);
    case UnknownPseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/BgColor/UnknownPseudoQtClass", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/QSS/BgColor/Operator", QColor);
    case ObsoleteProperty:
        return GET_SETTINGS("Lexer/QSS/BgColor/ObsoleteProperty", QColor);
    case UnknownProperty:
        return GET_SETTINGS("Lexer/QSS/BgColor/UnknownProperty", QColor);
    case Value:
        return GET_SETTINGS("Lexer/QSS/BgColor/Value", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/QSS/BgColor/Comment", QColor);
    case QtIDSelector:
        return GET_SETTINGS("Lexer/QSS/BgColor/QtIDSelector", QColor);
    case Important:
        return GET_SETTINGS("Lexer/QSS/BgColor/Important", QColor);
    case AtRule:
        return GET_SETTINGS("Lexer/QSS/BgColor/AtRule", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/QSS/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/QSS/BgColor/SingleQuotedString", QColor);
    case Property:
        return GET_SETTINGS("Lexer/QSS/BgColor/Property", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/QSS/BgColor/Attribute", QColor);
    case ExperimentalProperty:
        return GET_SETTINGS("Lexer/QSS/BgColor/ExperimentalProperty", QColor);
    case PseudoQtElement:
        return GET_SETTINGS("Lexer/QSS/BgColor/PseudoQtElement", QColor);
    case SpecificProperty:
        return GET_SETTINGS("Lexer/QSS/BgColor/BrowserSpecificProperty", QColor);
    case SpecificPseudoQtClass:
        return GET_SETTINGS("Lexer/QSS/BgColor/SpecificPseudoQtClass", QColor);
    case SpecificPseudoQtElement:
        return GET_SETTINGS("Lexer/QSS/BgColor/SpecificPseudoQtElement", QColor);
    case MediaRule:
        return GET_SETTINGS("Lexer/QSS/BgColor/MediaRule", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/QSS/BgColor/Variable", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerQSS::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerQSSKeyword1;
    case 2:
        return lexerQSSKeyword2;
    case 5:
        return lexerQSSKeyword5;
    case 6:
        return lexerQSSKeyword6;
    default:
        return 0;
    }
}

QString TpLexerQSS::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case QtType:
        return tr("Qt type");
    case QtClass:
        return tr("Qt class");
    case PseudoQtClass:
        return tr("Pseudo Qt class");
    case UnknownPseudoQtClass:
        return tr("Unknown pseudo Qt class");
    case Operator:
        return tr("Operator");
    case ObsoleteProperty:
        return tr("Obsolete property");
    case UnknownProperty:
        return tr("Unknown property");
    case Value:
        return tr("Value");
    case Comment:
        return tr("Comment");
    case QtIDSelector:
        return tr("Qt ID selector");
    case Important:
        return tr("Important");
    case AtRule:
        return tr("@-rule");
    case DoubleQuotedString:
        return tr("Double-quoted string");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case Property:
        return tr("QSS property");
    case Attribute:
        return tr("Attribute");
    case ExperimentalProperty:
        return tr("Experimental (Future) property");
    case PseudoQtElement:
        return tr("Pseudo Qt element");
    case SpecificProperty:
        return tr("Specific QSS property");
    case SpecificPseudoQtClass:
        return tr("Browser-specific pseudo Qt class");
    case SpecificPseudoQtElement:
        return tr("Browser-specific pseudo Qt element");
    case MediaRule:
        return tr("Media rule");
    case Variable:
        return tr("Variable");
    }

    return QString();

    return QString();
}

void TpLexerQSS::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
}

void TpLexerQSS::setLexerProperty(int prop, QVariant value)
{
    emit propertyChanged("lexer.css.scss.language", "0");
    emit propertyChanged("lexer.css.less.language", "0");
    emit propertyChanged("lexer.css.hss.language", "0");

    switch (prop)
    {
    case PropFoldComments: {
        m_foldComments = value.toBool();
        emit propertyChanged("fold.comments", (m_foldComments ? "1" : "0"));
        break;
    }
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerQSS::lexerProperty(int prop) const
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

bool TpLexerQSS::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);

    return true;
}

bool TpLexerQSS::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);

    return true;
}

TP_END_NAMESPACE
