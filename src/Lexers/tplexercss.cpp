#include <Lexers/TpLexerCSS>

TP_NAMESPACE

TpLexerCSS::TpLexerCSS(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldCompact(true),
    m_foldComments(true),
    m_language(CSS)
{}

TpLexerCSS::~TpLexerCSS()
{}

int TpLexerCSS::autoIndentStyle()
{
    DEF_SETTINGS;
    if (GET_SETTINGS("Tools/Autoindentation/Style/Auto", bool))
        return 0;

    return TpGeneralLexer::autoIndentStyle();
}

const char *TpLexerCSS::language() const
{
    return "CSS";
}

const char *TpLexerCSS::lexer() const
{
    return "css";
}

const char *TpLexerCSS::blockEnd(int *style) const
{
    if (style)
        *style = Operator;

    return "}";
}

const char *TpLexerCSS::blockStart(int *style) const
{
    if (style)
        *style = Operator;

    return "{";
}

const char *TpLexerCSS::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
}

QColor TpLexerCSS::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CSS/Color/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/CSS/Color/Tag", QColor);
    case ClassSelector:
        return GET_SETTINGS("Lexer/CSS/Color/ClassSelector", QColor);
    case PseudoClass:
        return GET_SETTINGS("Lexer/CSS/Color/PseudoClass", QColor);
    case UnknownPseudoClass:
        return GET_SETTINGS("Lexer/CSS/Color/UnknownPseudoClass", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/CSS/Color/Operator", QColor);
    case ObsoleteProperty:
        return GET_SETTINGS("Lexer/CSS/Color/ObsoleteProperty", QColor);
    case UnknownProperty:
        return GET_SETTINGS("Lexer/CSS/Color/UnknownProperty", QColor);
    case Value:
        return GET_SETTINGS("Lexer/CSS/Color/Value", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CSS/Color/Comment", QColor);
    case IDSelector:
        return GET_SETTINGS("Lexer/CSS/Color/IDSelector", QColor);
    case Important:
        return GET_SETTINGS("Lexer/CSS/Color/Important", QColor);
    case AtRule:
        return GET_SETTINGS("Lexer/CSS/Color/AtRule", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CSS/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CSS/Color/SingleQuotedString", QColor);
    case Property:
        return GET_SETTINGS("Lexer/CSS/Color/Property", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/CSS/Color/Attribute", QColor);
    case ExperimentalProperty:
        return GET_SETTINGS("Lexer/CSS/Color/ExperimentalProperty", QColor);
    case PseudoElement:
        return GET_SETTINGS("Lexer/CSS/Color/PseudoElement", QColor);
    case BrowserSpecificProperty:
        return GET_SETTINGS("Lexer/CSS/Color/BrowserSpecificProperty", QColor);
    case BrowserSpecificPseudoClass:
        return GET_SETTINGS("Lexer/CSS/Color/BrowserSpecificPseudoClass", QColor);
    case BrowserSpecificPseudoElement:
        return GET_SETTINGS("Lexer/CSS/Color/BrowserSpecificPseudoElement", QColor);
    case MediaRule:
        return GET_SETTINGS("Lexer/CSS/Color/MediaRule", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/CSS/Color/Variable", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerCSS::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CSS/Fill/Universal", bool);
    case Tag:
        return GET_SETTINGS("Lexer/CSS/Fill/Tag", bool);
    case ClassSelector:
        return GET_SETTINGS("Lexer/CSS/Fill/ClassSelector", bool);
    case PseudoClass:
        return GET_SETTINGS("Lexer/CSS/Fill/PseudoClass", bool);
    case UnknownPseudoClass:
        return GET_SETTINGS("Lexer/CSS/Fill/UnknownPseudoClass", bool);
    case Operator:
        return GET_SETTINGS("Lexer/CSS/Fill/Operator", bool);
    case ObsoleteProperty:
        return GET_SETTINGS("Lexer/CSS/Fill/ObsoleteProperty", bool);
    case UnknownProperty:
        return GET_SETTINGS("Lexer/CSS/Fill/UnknownProperty", bool);
    case Value:
        return GET_SETTINGS("Lexer/CSS/Fill/Value", bool);
    case Comment:
        return GET_SETTINGS("Lexer/CSS/Fill/Comment", bool);
    case IDSelector:
        return GET_SETTINGS("Lexer/CSS/Fill/IDSelector", bool);
    case Important:
        return GET_SETTINGS("Lexer/CSS/Fill/Important", bool);
    case AtRule:
        return GET_SETTINGS("Lexer/CSS/Fill/AtRule", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CSS/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CSS/Fill/SingleQuotedString", bool);
    case Property:
        return GET_SETTINGS("Lexer/CSS/Fill/Property", bool);
    case Attribute:
        return GET_SETTINGS("Lexer/CSS/Fill/Attribute", bool);
    case ExperimentalProperty:
        return GET_SETTINGS("Lexer/CSS/Fill/ExperimentalProperty", bool);
    case PseudoElement:
        return GET_SETTINGS("Lexer/CSS/Fill/PseudoElement", bool);
    case BrowserSpecificProperty:
        return GET_SETTINGS("Lexer/CSS/Fill/BrowserSpecificProperty", bool);
    case BrowserSpecificPseudoClass:
        return GET_SETTINGS("Lexer/CSS/Fill/BrowserSpecificPseudoClass", bool);
    case BrowserSpecificPseudoElement:
        return GET_SETTINGS("Lexer/CSS/Fill/BrowserSpecificPseudoElement", bool);
    case MediaRule:
        return GET_SETTINGS("Lexer/CSS/Fill/MediaRule", bool);
    case Variable:
        return GET_SETTINGS("Lexer/CSS/Fill/Variable", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerCSS::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CSS/Font/Universal", QFont);
    case Tag:
        return GET_SETTINGS("Lexer/CSS/Font/Tag", QFont);
    case ClassSelector:
        return GET_SETTINGS("Lexer/CSS/Font/ClassSelector", QFont);
    case PseudoClass:
        return GET_SETTINGS("Lexer/CSS/Font/PseudoClass", QFont);
    case UnknownPseudoClass:
        return GET_SETTINGS("Lexer/CSS/Font/UnknownPseudoClass", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/CSS/Font/Operator", QFont);
    case ObsoleteProperty:
        return GET_SETTINGS("Lexer/CSS/Font/ObsoleteProperty", QFont);
    case UnknownProperty:
        return GET_SETTINGS("Lexer/CSS/Font/UnknownProperty", QFont);
    case Value:
        return GET_SETTINGS("Lexer/CSS/Font/Value", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/CSS/Font/Comment", QFont);
    case IDSelector:
        return GET_SETTINGS("Lexer/CSS/Font/IDSelector", QFont);
    case Important:
        return GET_SETTINGS("Lexer/CSS/Font/Important", QFont);
    case AtRule:
        return GET_SETTINGS("Lexer/CSS/Font/AtRule", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CSS/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CSS/Font/SingleQuotedString", QFont);
    case Property:
        return GET_SETTINGS("Lexer/CSS/Font/Property", QFont);
    case Attribute:
        return GET_SETTINGS("Lexer/CSS/Font/Attribute", QFont);
    case ExperimentalProperty:
        return GET_SETTINGS("Lexer/CSS/Font/ExperimentalProperty", QFont);
    case PseudoElement:
        return GET_SETTINGS("Lexer/CSS/Font/PseudoElement", QFont);
    case BrowserSpecificProperty:
        return GET_SETTINGS("Lexer/CSS/Font/BrowserSpecificProperty", QFont);
    case BrowserSpecificPseudoClass:
        return GET_SETTINGS("Lexer/CSS/Font/BrowserSpecificPseudoClass", QFont);
    case BrowserSpecificPseudoElement:
        return GET_SETTINGS("Lexer/CSS/Font/BrowserSpecificPseudoElement", QFont);
    case MediaRule:
        return GET_SETTINGS("Lexer/CSS/Font/MediaRule", QFont);
    case Variable:
        return GET_SETTINGS("Lexer/CSS/Font/Variable", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerCSS::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CSS/BgColor/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/CSS/BgColor/Tag", QColor);
    case ClassSelector:
        return GET_SETTINGS("Lexer/CSS/BgColor/ClassSelector", QColor);
    case PseudoClass:
        return GET_SETTINGS("Lexer/CSS/BgColor/PseudoClass", QColor);
    case UnknownPseudoClass:
        return GET_SETTINGS("Lexer/CSS/BgColor/UnknownPseudoClass", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/CSS/BgColor/Operator", QColor);
    case ObsoleteProperty:
        return GET_SETTINGS("Lexer/CSS/BgColor/ObsoleteProperty", QColor);
    case UnknownProperty:
        return GET_SETTINGS("Lexer/CSS/BgColor/UnknownProperty", QColor);
    case Value:
        return GET_SETTINGS("Lexer/CSS/BgColor/Value", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CSS/BgColor/Comment", QColor);
    case IDSelector:
        return GET_SETTINGS("Lexer/CSS/BgColor/IDSelector", QColor);
    case Important:
        return GET_SETTINGS("Lexer/CSS/BgColor/Important", QColor);
    case AtRule:
        return GET_SETTINGS("Lexer/CSS/BgColor/AtRule", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/CSS/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/CSS/BgColor/SingleQuotedString", QColor);
    case Property:
        return GET_SETTINGS("Lexer/CSS/BgColor/Property", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/CSS/BgColor/Attribute", QColor);
    case ExperimentalProperty:
        return GET_SETTINGS("Lexer/CSS/BgColor/ExperimentalProperty", QColor);
    case PseudoElement:
        return GET_SETTINGS("Lexer/CSS/BgColor/PseudoElement", QColor);
    case BrowserSpecificProperty:
        return GET_SETTINGS("Lexer/CSS/BgColor/BrowserSpecificProperty", QColor);
    case BrowserSpecificPseudoClass:
        return GET_SETTINGS("Lexer/CSS/BgColor/BrowserSpecificPseudoClass", QColor);
    case BrowserSpecificPseudoElement:
        return GET_SETTINGS("Lexer/CSS/BgColor/BrowserSpecificPseudoElement", QColor);
    case MediaRule:
        return GET_SETTINGS("Lexer/CSS/BgColor/MediaRule", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/CSS/BgColor/Variable", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerCSS::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerCSSKeyword1;
    case 2:
        return lexerCSSKeyword2;
    case 3:
        return lexerCSSKeyword3;
    case 4:
        return lexerCSSKeyword4;
    case 5:
        return lexerCSSKeyword5;
    case 6:
        return lexerCSSKeyword6;
    case 7:
        return lexerCSSKeyword7;
    case 8:
        return lexerCSSKeyword8;
    default:
        return 0;
    }
}

QString TpLexerCSS::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case Tag:
        return tr("Tag");
    case ClassSelector:
        return tr("Class selector");
    case PseudoClass:
        return tr("Pseudo-class");
    case UnknownPseudoClass:
        return tr("Unknown pseudo-class");
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
    case IDSelector:
        return tr("ID selector");
    case Important:
        return tr("Important");
    case AtRule:
        return tr("@-rule");
    case DoubleQuotedString:
        return tr("Double-quoted string");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case Property:
        return tr("CSS property");
    case Attribute:
        return tr("Attribute");
    case ExperimentalProperty:
        return tr("Experimental (Future) property");
    case PseudoElement:
        return tr("Pseudo-element");
    case BrowserSpecificProperty:
        return tr("Browser-specific CSS property");
    case BrowserSpecificPseudoClass:
        return tr("Browser-specific pseudo-class");
    case BrowserSpecificPseudoElement:
        return tr("Browser-specific pseudo-element");
    case MediaRule:
        return tr("Media rule");
    case Variable:
        return tr("Variable");
    }

    return QString();

    return QString();
}

void TpLexerCSS::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
    setLexerProperty(PropLanguage, m_language);
}

void TpLexerCSS::setLexerProperty(int prop, QVariant value)
{
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
    case PropLanguage: {
        m_language = value.toInt();
        emit propertyChanged("lexer.css.scss.language", ((m_language == SCSS) ? "1" : "0"));
        emit propertyChanged("lexer.css.less.language", ((m_language == LESS) ? "1" : "0"));
        emit propertyChanged("lexer.css.hss.language", ((m_language == HSS) ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerCSS::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldComments:
        return m_foldComments;
    case PropLanguage:
        return m_language;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerCSS::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_language = GET_SETTINGS_WITH(prefix + "language", int, CSS);

    return true;
}

bool TpLexerCSS::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "language", m_language);

    return true;
}

TP_END_NAMESPACE
