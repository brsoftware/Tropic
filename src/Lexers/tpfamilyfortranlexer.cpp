#include <Lexers/TpFamilyFortranLexer>

TP_NAMESPACE

TpFamilyFortranLexer::TpFamilyFortranLexer(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true),
    m_foldCompact(true)
{}

TpFamilyFortranLexer::~TpFamilyFortranLexer()
{}

const char *TpFamilyFortranLexer::language() const
{
    return "Fortran 77";
}

const char *TpFamilyFortranLexer::lexer() const
{
    return "f77";
}

int TpFamilyFortranLexer::braceStyle() const
{
    return Default;
}

QColor TpFamilyFortranLexer::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Editor/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Editor/Color/Number", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Color/SingleQuotedString", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Color/DoubleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Editor/Color/UnclosedString", QColor);
    case Operator:
        return GET_SETTINGS("Editor/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/Color/Identifier", QColor);
    case Keyword:
        return GET_SETTINGS("Editor/Color/Keyword", QColor);
    case IntrinsicFunction:
        return GET_SETTINGS("Editor/Color/PrimitiveType", QColor);
    case ExtendedFunction:
        return GET_SETTINGS("Editor/Color/Type", QColor);
    case PreProcessor:
        return GET_SETTINGS("Editor/Color/PreProcessor", QColor);
    case DottedOperator:
        return GET_SETTINGS("Editor/Color/UUID", QColor);
    case Label:
        return GET_SETTINGS("Editor/Color/KeywordSet2", QColor);
    case Continuation:
        return GET_SETTINGS("Editor/Color/EscapeSequence", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpFamilyFortranLexer::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Editor/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Editor/Fill/Number", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Fill/SingleQuotedString", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Fill/DoubleQuotedString", bool);
    case UnclosedString:
        return GET_SETTINGS("Editor/Fill/UnclosedString", bool);
    case Operator:
        return GET_SETTINGS("Editor/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Editor/Fill/Identifier", bool);
    case Keyword:
        return GET_SETTINGS("Editor/Fill/Keyword", bool);
    case IntrinsicFunction:
        return GET_SETTINGS("Editor/Fill/PrimitiveType", bool);
    case ExtendedFunction:
        return GET_SETTINGS("Editor/Fill/Type", bool);
    case PreProcessor:
        return GET_SETTINGS("Editor/Fill/PreProcessor", bool);
    case DottedOperator:
        return GET_SETTINGS("Editor/Fill/UUID", bool);
    case Label:
        return GET_SETTINGS("Editor/Fill/KeywordSet2", bool);
    case Continuation:
        return GET_SETTINGS("Editor/Fill/EscapeSequence", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpFamilyFortranLexer::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Editor/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Editor/Font/Number", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Font/SingleQuotedString", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Font/DoubleQuotedString", QFont);
    case UnclosedString:
        return GET_SETTINGS("Editor/Font/UnclosedString", QFont);
    case Operator:
        return GET_SETTINGS("Editor/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Editor/Font/Identifier", QFont);
    case Keyword:
        return GET_SETTINGS("Editor/Font/Keyword", QFont);
    case IntrinsicFunction:
        return GET_SETTINGS("Editor/Font/PrimitiveType", QFont);
    case ExtendedFunction:
        return GET_SETTINGS("Editor/Font/Type", QFont);
    case PreProcessor:
        return GET_SETTINGS("Editor/Font/PreProcessor", QFont);
    case DottedOperator:
        return GET_SETTINGS("Editor/Font/UUID", QFont);
    case Label:
        return GET_SETTINGS("Editor/Font/KeywordSet2", QFont);
    case Continuation:
        return GET_SETTINGS("Editor/Font/EscapeSequence", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpFamilyFortranLexer::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Editor/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Editor/BgColor/Number", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/BgColor/SingleQuotedString", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/BgColor/DoubleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Editor/BgColor/UnclosedString", QColor);
    case Operator:
        return GET_SETTINGS("Editor/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/BgColor/Identifier", QColor);
    case Keyword:
        return GET_SETTINGS("Editor/BgColor/Keyword", QColor);
    case IntrinsicFunction:
        return GET_SETTINGS("Editor/BgColor/PrimitiveType", QColor);
    case ExtendedFunction:
        return GET_SETTINGS("Editor/BgColor/Type", QColor);
    case PreProcessor:
        return GET_SETTINGS("Editor/BgColor/PreProcessor", QColor);
    case DottedOperator:
        return GET_SETTINGS("Editor/BgColor/UUID", QColor);
    case Label:
        return GET_SETTINGS("Editor/BgColor/KeywordSet2", QColor);
    case Continuation:
        return GET_SETTINGS("Editor/BgColor/EscapeSequence", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpFamilyFortranLexer::keywords(int set) const
{
    switch (set)
    {
    default:
        return 0;
    }
}

QString TpFamilyFortranLexer::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case Number:
        return tr("Number");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case DoubleQuotedString:
        return tr("Double-quoted string");
    case UnclosedString:
        return tr("Unclosed string");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case Keyword:
        return tr("Keyword");
    case IntrinsicFunction:
        return tr("Intrinsic function");
    case ExtendedFunction:
        return tr("Extended function");
    case PreProcessor:
        return tr("Pre-processor block");
    case DottedOperator:
        return tr("Dotted operator");
    case Label:
        return tr("Label");
    case Continuation:
        return tr("Continuation");
    }

    return QString();
}

void TpFamilyFortranLexer::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
}

void TpFamilyFortranLexer::setLexerProperty(int prop, QVariant value)
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

QVariant TpFamilyFortranLexer::lexerProperty(int prop) const
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

bool TpFamilyFortranLexer::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);

    return true;
}

bool TpFamilyFortranLexer::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);

    return true;
}

TP_END_NAMESPACE
