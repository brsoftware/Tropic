#include <Lexers/TpLexerPOV>

TP_NAMESPACE

TpLexerPOV::TpLexerPOV(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true),
    m_foldCompact(true),
    m_foldDirectives(true)
{}

TpLexerPOV::~TpLexerPOV()
{}

const char *TpLexerPOV::language() const
{
    return "POV-Ray";
}

const char *TpLexerPOV::lexer() const
{
    return "pov";
}

int TpLexerPOV::braceStyle() const
{
    return Operator;
}

const char *TpLexerPOV::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_#";
}

QColor TpLexerPOV::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/POV/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/POV/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/POV/Color/CommentLine", QColor);
    case Number:
        return GET_SETTINGS("Lexer/POV/Color/Number", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/POV/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/POV/Color/Identifier", QColor);
    case String:
        return GET_SETTINGS("Lexer/POV/Color/String", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/POV/Color/UnclosedString", QColor);
    case Directive:
        return GET_SETTINGS("Lexer/POV/Color/Directive", QColor);
    case BadDirective:
        return GET_SETTINGS("Lexer/POV/Color/BadDirective", QColor);
    case ObjectsCSGAppearance:
        return GET_SETTINGS("Lexer/POV/Color/ObjectsCSGAppearance", QColor);
    case TypesModifiersItems:
        return GET_SETTINGS("Lexer/POV/Color/TypesModifiersItems", QColor);
    case PredefinedIdentifiers:
        return GET_SETTINGS("Lexer/POV/Color/PredefinedIdentifiers", QColor);
    case PredefinedFunctions:
        return GET_SETTINGS("Lexer/POV/Color/PredefinedFunctions", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/POV/Color/KeywordSet6", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/POV/Color/KeywordSet7", QColor);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/POV/Color/KeywordSet8", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerPOV::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/POV/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/POV/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/POV/Fill/CommentLine", bool);
    case Number:
        return GET_SETTINGS("Lexer/POV/Fill/Number", bool);
    case Operator:
        return GET_SETTINGS("Lexer/POV/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/POV/Fill/Identifier", bool);
    case String:
        return GET_SETTINGS("Lexer/POV/Fill/String", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/POV/Fill/UnclosedString", bool);
    case Directive:
        return GET_SETTINGS("Lexer/POV/Fill/Directive", bool);
    case BadDirective:
        return GET_SETTINGS("Lexer/POV/Fill/BadDirective", bool);
    case ObjectsCSGAppearance:
        return GET_SETTINGS("Lexer/POV/Fill/ObjectsCSGAppearance", bool);
    case TypesModifiersItems:
        return GET_SETTINGS("Lexer/POV/Fill/TypesModifiersItems", bool);
    case PredefinedIdentifiers:
        return GET_SETTINGS("Lexer/POV/Fill/PredefinedIdentifiers", bool);
    case PredefinedFunctions:
        return GET_SETTINGS("Lexer/POV/Fill/PredefinedFunctions", bool);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/POV/Fill/KeywordSet6", bool);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/POV/Fill/KeywordSet7", bool);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/POV/Fill/KeywordSet8", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerPOV::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/POV/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/POV/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/POV/Font/CommentLine", QFont);
    case Number:
        return GET_SETTINGS("Lexer/POV/Font/Number", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/POV/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/POV/Font/Identifier", QFont);
    case String:
        return GET_SETTINGS("Lexer/POV/Font/String", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/POV/Font/UnclosedString", QFont);
    case Directive:
        return GET_SETTINGS("Lexer/POV/Font/Directive", QFont);
    case BadDirective:
        return GET_SETTINGS("Lexer/POV/Font/BadDirective", QFont);
    case ObjectsCSGAppearance:
        return GET_SETTINGS("Lexer/POV/Font/ObjectsCSGAppearance", QFont);
    case TypesModifiersItems:
        return GET_SETTINGS("Lexer/POV/Font/TypesModifiersItems", QFont);
    case PredefinedIdentifiers:
        return GET_SETTINGS("Lexer/POV/Font/PredefinedIdentifiers", QFont);
    case PredefinedFunctions:
        return GET_SETTINGS("Lexer/POV/Font/PredefinedFunctions", QFont);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/POV/Font/KeywordSet6", QFont);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/POV/Font/KeywordSet7", QFont);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/POV/Font/KeywordSet8", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerPOV::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/POV/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/POV/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/POV/BgColor/CommentLine", QColor);
    case Number:
        return GET_SETTINGS("Lexer/POV/BgColor/Number", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/POV/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/POV/BgColor/Identifier", QColor);
    case String:
        return GET_SETTINGS("Lexer/POV/BgColor/String", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/POV/BgColor/UnclosedString", QColor);
    case Directive:
        return GET_SETTINGS("Lexer/POV/BgColor/Directive", QColor);
    case BadDirective:
        return GET_SETTINGS("Lexer/POV/BgColor/BadDirective", QColor);
    case ObjectsCSGAppearance:
        return GET_SETTINGS("Lexer/POV/BgColor/ObjectsCSGAppearance", QColor);
    case TypesModifiersItems:
        return GET_SETTINGS("Lexer/POV/BgColor/TypesModifiersItems", QColor);
    case PredefinedIdentifiers:
        return GET_SETTINGS("Lexer/POV/BgColor/PredefinedIdentifiers", QColor);
    case PredefinedFunctions:
        return GET_SETTINGS("Lexer/POV/BgColor/PredefinedFunctions", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/POV/BgColor/KeywordSet6", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/POV/BgColor/KeywordSet7", QColor);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/POV/BgColor/KeywordSet8", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerPOV::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerPOVKeyword1;
    case 2:
        return lexerPOVKeyword2;
    case 3:
        return lexerPOVKeyword3;
    case 4:
        return lexerPOVKeyword4;
    case 5:
        return lexerPOVKeyword5;
    default:
        return 0;
    }
}

QString TpLexerPOV::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case CommentLine:
        return tr("Comment line");
    case Number:
        return tr("Number");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case String:
        return tr("String");
    case UnclosedString:
        return tr("Unclosed string");
    case Directive:
        return tr("Directive");
    case BadDirective:
        return tr("Bad directive");
    case ObjectsCSGAppearance:
        return tr("Objects, CSG and appearance");
    case TypesModifiersItems:
        return tr("Types, modifiers and items");
    case PredefinedIdentifiers:
        return tr("Predefined identifiers");
    case PredefinedFunctions:
        return tr("Predefined functions");
    case KeywordSet6:
        return tr("User defined 1");
    case KeywordSet7:
        return tr("User defined 2");
    case KeywordSet8:
        return tr("User defined 3");
    }

    return QString();
}

void TpLexerPOV::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
    setLexerProperty(PropFoldDirectives, m_foldDirectives);
}

void TpLexerPOV::setLexerProperty(int prop, QVariant value)
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
    case PropFoldDirectives: {
        m_foldDirectives = value.toBool();
        emit propertyChanged("fold.directive", (m_foldDirectives ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerPOV::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldComments:
        return m_foldComments;
    case PropFoldDirectives:
        return m_foldDirectives;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerPOV::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_foldDirectives = GET_SETTINGS_WITH(prefix + "folddirectives", bool, true);

    return true;
}

bool TpLexerPOV::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "folddirectives", m_foldDirectives);

    return true;
}

TP_END_NAMESPACE
