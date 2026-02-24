#include <Lexers/TpFamilyPythonLexer>

TP_NAMESPACE

TpFamilyPythonLexer::TpFamilyPythonLexer(QObject *parent)
    : TpGeneralLexer(parent),
    m_indentationWarning(IndentationWarnsInconsistency),
    m_binaryLiterals(true),
    m_unicodeStrings(true),
    m_binaryStrings(true),
    m_formatStrings(true),
    m_disableSubIdentifiers(true),
    m_fold(true),
    m_foldQuotes(true),
    m_foldCompact(true),
    m_enableUnicodeIdentifiers(true)
{}

TpFamilyPythonLexer::~TpFamilyPythonLexer()
{}

const char *TpFamilyPythonLexer::language() const
{
    return "Python";
}

const char *TpFamilyPythonLexer::lexer() const
{
    return "python";
}

QStringList TpFamilyPythonLexer::autoCompletionWordSeparators() const
{
    QStringList wordList;

    wordList << ".";

    return wordList;
}

int TpFamilyPythonLexer::blockLookback() const
{
    return 0;
}

const char *TpFamilyPythonLexer::blockStart(int *style) const
{
    if (style)
        *style = Operator;

    return ":";
}

int TpFamilyPythonLexer::braceStyle() const
{
    return Operator;
}

int TpFamilyPythonLexer::indentationGuideView() const
{
    // QsciScintillaBase::SC_IV_LOOKFORWARD;
    return 2;
}

QColor TpFamilyPythonLexer::defaultColor(int style) const
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
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Color/SingleQuotedString", QColor);
    case Keyword:
        return GET_SETTINGS("Editor/Color/Keyword", QColor);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Editor/Color/RawString", QColor);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Editor/Color/HashQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Editor/Color/Type", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Editor/Color/GlobalClass", QColor);
    case Operator:
        return GET_SETTINGS("Editor/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/Color/Identifier", QColor);
    case CommentBlock:
        return GET_SETTINGS("Editor/Color/CommentDoc", QColor);
    case UnclosedString:
        return GET_SETTINGS("Editor/Color/UnclosedString", QColor);
    case HighlightIdentifier:
        return GET_SETTINGS("Editor/Color/PrimitiveType", QColor);
    case Decorator:
        return GET_SETTINGS("Editor/Color/PreProcessor", QColor);
    case DoubleQuotedFString:
        return GET_SETTINGS("Editor/Color/InactiveDoubleQuotedString", QColor);
    case SingleQuotedFString:
        return GET_SETTINGS("Editor/Color/InactiveDoubleQuotedString", QColor);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Editor/Color/InactiveRawString", QColor);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Editor/Color/InactiveHashQuotedString", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpFamilyPythonLexer::defaultEolFill(int style) const
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
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Fill/SingleQuotedString", bool);
    case Keyword:
        return GET_SETTINGS("Editor/Fill/Keyword", bool);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Editor/Fill/RawString", bool);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Editor/Fill/HashQuotedString", bool);
    case ClassName:
        return GET_SETTINGS("Editor/Fill/Type", bool);
    case FunctionMethodName:
        return GET_SETTINGS("Editor/Fill/GlobalClass", bool);
    case Operator:
        return GET_SETTINGS("Editor/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Editor/Fill/Identifier", bool);
    case CommentBlock:
        return GET_SETTINGS("Editor/Fill/CommentDoc", bool);
    case UnclosedString:
        return GET_SETTINGS("Editor/Fill/UnclosedString", bool);
    case HighlightIdentifier:
        return GET_SETTINGS("Editor/Fill/PrimitiveType", bool);
    case Decorator:
        return GET_SETTINGS("Editor/Fill/PreProcessor", bool);
    case DoubleQuotedFString:
        return GET_SETTINGS("Editor/Fill/InactiveDoubleQuotedString", bool);
    case SingleQuotedFString:
        return GET_SETTINGS("Editor/Fill/InactiveDoubleQuotedString", bool);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Editor/Fill/InactiveRawString", bool);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Editor/Fill/InactiveHashQuotedString", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpFamilyPythonLexer::defaultFont(int style) const
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
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Font/SingleQuotedString", QFont);
    case Keyword:
        return GET_SETTINGS("Editor/Font/Keyword", QFont);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Editor/Font/RawString", QFont);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Editor/Font/HashQuotedString", QFont);
    case ClassName:
        return GET_SETTINGS("Editor/Font/Type", QFont);
    case FunctionMethodName:
        return GET_SETTINGS("Editor/Font/GlobalClass", QFont);
    case Operator:
        return GET_SETTINGS("Editor/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Editor/Font/Identifier", QFont);
    case CommentBlock:
        return GET_SETTINGS("Editor/Font/CommentDoc", QFont);
    case UnclosedString:
        return GET_SETTINGS("Editor/Font/UnclosedString", QFont);
    case HighlightIdentifier:
        return GET_SETTINGS("Editor/Font/PrimitiveType", QFont);
    case Decorator:
        return GET_SETTINGS("Editor/Font/PreProcessor", QFont);
    case DoubleQuotedFString:
        return GET_SETTINGS("Editor/Font/InactiveDoubleQuotedString", QFont);
    case SingleQuotedFString:
        return GET_SETTINGS("Editor/Font/InactiveDoubleQuotedString", QFont);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Editor/Font/InactiveRawString", QFont);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Editor/Font/InactiveHashQuotedString", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpFamilyPythonLexer::defaultPaper(int style) const
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
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/BgColor/SingleQuotedString", QColor);
    case Keyword:
        return GET_SETTINGS("Editor/BgColor/Keyword", QColor);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Editor/BgColor/RawString", QColor);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Editor/BgColor/HashQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Editor/BgColor/Type", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Editor/BgColor/GlobalClass", QColor);
    case Operator:
        return GET_SETTINGS("Editor/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/BgColor/Identifier", QColor);
    case CommentBlock:
        return GET_SETTINGS("Editor/BgColor/CommentDoc", QColor);
    case UnclosedString:
        return GET_SETTINGS("Editor/BgColor/UnclosedString", QColor);
    case HighlightIdentifier:
        return GET_SETTINGS("Editor/BgColor/PrimitiveType", QColor);
    case Decorator:
        return GET_SETTINGS("Editor/BgColor/PreProcessor", QColor);
    case DoubleQuotedFString:
        return GET_SETTINGS("Editor/BgColor/InactiveDoubleQuotedString", QColor);
    case SingleQuotedFString:
        return GET_SETTINGS("Editor/BgColor/InactiveDoubleQuotedString", QColor);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Editor/BgColor/InactiveRawString", QColor);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Editor/BgColor/InactiveHashQuotedString", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpFamilyPythonLexer::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerPythonKeyword1;
    case 2:
        return lexerPythonKeyword2;
    default:
        return 0;
    }
}

QString TpFamilyPythonLexer::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case Number:
        return tr("Number");
    case DoubleQuotedString:
        return tr("Double-quoted string");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case Keyword:
        return tr("Keyword");
    case TripleSingleQuotedString:
        return tr("Triple single-quoted string");
    case TripleDoubleQuotedString:
        return tr("Triple double-quoted string");
    case ClassName:
        return tr("Class name");
    case FunctionMethodName:
        return tr("Function or method name");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case CommentBlock:
        return tr("Comment block");
    case UnclosedString:
        return tr("Unclosed string");
    case HighlightIdentifier:
        return tr("Highlight identifier");
    case Decorator:
        return tr("Decorator");
    case DoubleQuotedFString:
        return tr("Double-quoted f-string");
    case SingleQuotedFString:
        return tr("Single-quoted f-string");
    case TripleSingleQuotedFString:
        return tr("Triple single-quoted f-string");
    case TripleDoubleQuotedFString:
        return tr("Triple double-quoted f-string");
    }

    return QString();
}

void TpFamilyPythonLexer::refreshProperties()
{
    setLexerProperty(PropIndentationWarning, m_indentationWarning);
    setLexerProperty(PropBinaryLiterals, m_binaryLiterals);
    setLexerProperty(PropUnicodeStrings, m_unicodeStrings);
    setLexerProperty(PropBinaryStrings, m_binaryStrings);
    setLexerProperty(PropFormatStrings, m_formatStrings);
    setLexerProperty(PropDisableSubIdentifiers, m_disableSubIdentifiers);
    setLexerProperty(PropFold, m_fold);
    setLexerProperty(PropFoldQuotes, m_foldQuotes);
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropEnableUnicodeIdentifiers, m_enableUnicodeIdentifiers);
}

void TpFamilyPythonLexer::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropIndentationWarning: {
        m_indentationWarning = value.toInt();
        emit propertyChanged("tab.timmy.whinge.level", textAsBytes(QString::number(m_indentationWarning)).constData());
        break;
    }
    case PropBinaryLiterals: {
        m_binaryLiterals = value.toBool();
        emit propertyChanged("lexer.python.literals.binary", (m_binaryLiterals ? "1" : "0"));
        break;
    }
    case PropUnicodeStrings: {
        m_unicodeStrings = value.toBool();
        emit propertyChanged("lexer.python.strings.u", (m_unicodeStrings ? "1" : "0"));
        break;
    }
    case PropBinaryStrings: {
        m_binaryStrings = value.toBool();
        emit propertyChanged("lexer.python.strings.b", (m_binaryStrings ? "1" : "0"));
        break;
    }
    case PropFormatStrings: {
        m_formatStrings = value.toBool();
        emit propertyChanged("lexer.python.strings.f", (m_formatStrings ? "1" : "0"));
        break;
    }
    case PropDisableSubIdentifiers: {
        m_disableSubIdentifiers = value.toBool();
        emit propertyChanged("lexer.python.keywords2.no.sub.identifiers", (m_disableSubIdentifiers ? "1" : "0"));
        break;
    }
    case PropFold: {
        m_fold = value.toBool();
        emit propertyChanged("fold", (m_fold ? "1" : "0"));
        break;
    }
    case PropFoldQuotes: {
        m_foldQuotes = value.toBool();
        emit propertyChanged("fold.quotes.python", (m_foldQuotes ? "1" : "0"));
        break;
    }
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    case PropEnableUnicodeIdentifiers: {
        m_enableUnicodeIdentifiers = value.toBool();
        emit propertyChanged("lexer.python.unicode.identifiers", (m_enableUnicodeIdentifiers ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpFamilyPythonLexer::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropIndentationWarning:
        return m_indentationWarning;
    case PropBinaryLiterals:
        return m_binaryLiterals;
    case PropUnicodeStrings:
        return m_unicodeStrings;
    case PropBinaryStrings:
        return m_binaryStrings;
    case PropFormatStrings:
        return m_formatStrings;
    case PropDisableSubIdentifiers:
        return m_disableSubIdentifiers;
    case PropFold:
        return m_fold;
    case PropFoldQuotes:
        return m_foldQuotes;
    case PropFoldCompact:
        return m_foldCompact;
    case PropEnableUnicodeIdentifiers:
        return m_enableUnicodeIdentifiers;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpFamilyPythonLexer::readProperties(QSettings &settings, const QString &prefix)
{
    m_indentationWarning = GET_SETTINGS_WITH(prefix + "indentationwarning", int, IndentationWarnsInconsistency);
    m_binaryLiterals = GET_SETTINGS_WITH(prefix + "binaryliterals", bool, true);
    m_unicodeStrings = GET_SETTINGS_WITH(prefix + "unicodestrings", bool, true);
    m_binaryStrings = GET_SETTINGS_WITH(prefix + "binarystrings", bool, true);
    m_formatStrings = GET_SETTINGS_WITH(prefix + "formatstrings", bool, true);
    m_disableSubIdentifiers = GET_SETTINGS_WITH(prefix + "disablesubidentifiers", bool, true);
    m_fold = GET_SETTINGS_WITH(prefix + "fold", bool, true);
    m_foldQuotes = GET_SETTINGS_WITH(prefix + "foldquotes", bool, true);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_enableUnicodeIdentifiers = GET_SETTINGS_WITH(prefix + "enableunicodeidentifiers", bool, true);

    return true;
}

bool TpFamilyPythonLexer::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "indentationwarning", m_indentationWarning);
    SET_SETTINGS(prefix + "binaryliterals", m_binaryLiterals);
    SET_SETTINGS(prefix + "unicodestrings", m_unicodeStrings);
    SET_SETTINGS(prefix + "binarystrings", m_binaryStrings);
    SET_SETTINGS(prefix + "formatstrings", m_formatStrings);
    SET_SETTINGS(prefix + "disablesubidentifiers", m_disableSubIdentifiers);
    SET_SETTINGS(prefix + "fold", m_fold);
    SET_SETTINGS(prefix + "foldquotes", m_foldQuotes);
    SET_SETTINGS(prefix + "foldcompact", m_foldQuotes);
    SET_SETTINGS(prefix + "enableunicodeidentifiers", m_enableUnicodeIdentifiers);

    return true;
}

TP_END_NAMESPACE
