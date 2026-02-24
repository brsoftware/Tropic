#include <Lexers/TpLexerPerl>

TP_NAMESPACE

TpLexerPerl::TpLexerPerl(QObject *parent)
    : TpGeneralLexer(parent),
    m_fold(true),
    m_foldComments(true),
    m_foldCompact(true),
    m_foldPOD(true),
    m_foldPackage(true),
    m_foldAtElse(true)
{}

TpLexerPerl::~TpLexerPerl()
{}

const char *TpLexerPerl::language() const
{
    return "Perl";
}

const char *TpLexerPerl::lexer() const
{
    return "perl";
}

QStringList TpLexerPerl::autoCompletionWordSeparators() const
{
    QStringList wordList;

    wordList << "::" << "->";

    return wordList;
}

const char *TpLexerPerl::blockEnd(int *style) const
{
    if (style)
        *style = Operator;

    return "}";
}

const char *TpLexerPerl::blockStart(int *style) const
{
    if (style)
        *style = Operator;

    return "{";
}

int TpLexerPerl::braceStyle() const
{
    return Operator;
}

const char *TpLexerPerl::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_$@%&";
}

QColor TpLexerPerl::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Perl/Color/Universal", QColor);
    case Error:
        return GET_SETTINGS("Lexer/Perl/Color/Error", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Perl/Color/Comment", QColor);
    case POD:
        return GET_SETTINGS("Lexer/Perl/Color/POD", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Perl/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Perl/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Perl/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Perl/Color/SingleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Perl/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Perl/Color/Identifier", QColor);
    case Scalar:
        return GET_SETTINGS("Lexer/Perl/Color/Scalar", QColor);
    case Array:
        return GET_SETTINGS("Lexer/Perl/Color/Array", QColor);
    case Hash:
        return GET_SETTINGS("Lexer/Perl/Color/Hash", QColor);
    case SymbolTable:
        return GET_SETTINGS("Lexer/Perl/Color/SymbolTable", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/Perl/Color/Regex", QColor);
    case Substitution:
        return GET_SETTINGS("Lexer/Perl/Color/Substitution", QColor);
    case Backticks:
        return GET_SETTINGS("Lexer/Perl/Color/Backticks", QColor);
    case DataSection:
        return GET_SETTINGS("Lexer/Perl/Color/DataSection", QColor);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Perl/Color/HereDocumentDelimiter", QColor);
    case SingleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Perl/Color/SingleQuotedHereDocument", QColor);
    case DoubleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Perl/Color/DoubleQuotedHereDocument", QColor);
    case BacktickHereDocument:
        return GET_SETTINGS("Lexer/Perl/Color/BacktickHereDocument", QColor);
    case QuotedStringQ:
        return GET_SETTINGS("Lexer/Perl/Color/QuotedStringQ", QColor);
    case QuotedStringQQ:
        return GET_SETTINGS("Lexer/Perl/Color/QuotedStringQQ", QColor);
    case QuotedStringQX:
        return GET_SETTINGS("Lexer/Perl/Color/QuotedStringQX", QColor);
    case QuotedStringQR:
        return GET_SETTINGS("Lexer/Perl/Color/QuotedStringQR", QColor);
    case QuotedStringQW:
        return GET_SETTINGS("Lexer/Perl/Color/QuotedStringQW", QColor);
    case PODVerbatim:
        return GET_SETTINGS("Lexer/Perl/Color/PODVerbatim", QColor);
    case SubroutinePrototype:
        return GET_SETTINGS("Lexer/Perl/Color/SubroutinePrototype", QColor);
    case FormatIdentifier:
        return GET_SETTINGS("Lexer/Perl/Color/FormatIdentifier", QColor);
    case FormatBody:
        return GET_SETTINGS("Lexer/Perl/Color/FormatBody", QColor);
    case DoubleQuotedStringVar:
        return GET_SETTINGS("Lexer/Perl/Color/DoubleQuotedStringVar", QColor);
    case Translation:
        return GET_SETTINGS("Lexer/Perl/Color/Translation", QColor);
    case RegexVar:
        return GET_SETTINGS("Lexer/Perl/Color/RegexVar", QColor);
    case SubstitutionVar:
        return GET_SETTINGS("Lexer/Perl/Color/SubstitutionVar", QColor);
    case BackticksVar:
        return GET_SETTINGS("Lexer/Perl/Color/BackticksVar", QColor);
    case DoubleQuotedHereDocumentVar:
        return GET_SETTINGS("Lexer/Perl/Color/DoubleQuotedHereDocumentVar", QColor);
    case BacktickHereDocumentVar:
        return GET_SETTINGS("Lexer/Perl/Color/BacktickHereDocumentVar", QColor);
    case QuotedStringQQVar:
        return GET_SETTINGS("Lexer/Perl/Color/QuotedStringQQVar", QColor);
    case QuotedStringQXVar:
        return GET_SETTINGS("Lexer/Perl/Color/QuotedStringQXVar", QColor);
    case QuotedStringQRVar:
        return GET_SETTINGS("Lexer/Perl/Color/QuotedStringQRVar", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerPerl::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Perl/Fill/Universal", bool);
    case Error:
        return GET_SETTINGS("Lexer/Perl/Fill/Error", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Perl/Fill/Comment", bool);
    case POD:
        return GET_SETTINGS("Lexer/Perl/Fill/POD", bool);
    case Number:
        return GET_SETTINGS("Lexer/Perl/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Perl/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Perl/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Perl/Fill/SingleQuotedString", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Perl/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Perl/Fill/Identifier", bool);
    case Scalar:
        return GET_SETTINGS("Lexer/Perl/Fill/Scalar", bool);
    case Array:
        return GET_SETTINGS("Lexer/Perl/Fill/Array", bool);
    case Hash:
        return GET_SETTINGS("Lexer/Perl/Fill/Hash", bool);
    case SymbolTable:
        return GET_SETTINGS("Lexer/Perl/Fill/SymbolTable", bool);
    case Regex:
        return GET_SETTINGS("Lexer/Perl/Fill/Regex", bool);
    case Substitution:
        return GET_SETTINGS("Lexer/Perl/Fill/Substitution", bool);
    case Backticks:
        return GET_SETTINGS("Lexer/Perl/Fill/Backticks", bool);
    case DataSection:
        return GET_SETTINGS("Lexer/Perl/Fill/DataSection", bool);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Perl/Fill/HereDocumentDelimiter", bool);
    case SingleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Perl/Fill/SingleQuotedHereDocument", bool);
    case DoubleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Perl/Fill/DoubleQuotedHereDocument", bool);
    case BacktickHereDocument:
        return GET_SETTINGS("Lexer/Perl/Fill/BacktickHereDocument", bool);
    case QuotedStringQ:
        return GET_SETTINGS("Lexer/Perl/Fill/QuotedStringQ", bool);
    case QuotedStringQQ:
        return GET_SETTINGS("Lexer/Perl/Fill/QuotedStringQQ", bool);
    case QuotedStringQX:
        return GET_SETTINGS("Lexer/Perl/Fill/QuotedStringQX", bool);
    case QuotedStringQR:
        return GET_SETTINGS("Lexer/Perl/Fill/QuotedStringQR", bool);
    case QuotedStringQW:
        return GET_SETTINGS("Lexer/Perl/Fill/QuotedStringQW", bool);
    case PODVerbatim:
        return GET_SETTINGS("Lexer/Perl/Fill/PODVerbatim", bool);
    case SubroutinePrototype:
        return GET_SETTINGS("Lexer/Perl/Fill/SubroutinePrototype", bool);
    case FormatIdentifier:
        return GET_SETTINGS("Lexer/Perl/Fill/FormatIdentifier", bool);
    case FormatBody:
        return GET_SETTINGS("Lexer/Perl/Fill/FormatBody", bool);
    case DoubleQuotedStringVar:
        return GET_SETTINGS("Lexer/Perl/Fill/DoubleQuotedStringVar", bool);
    case Translation:
        return GET_SETTINGS("Lexer/Perl/Fill/Translation", bool);
    case RegexVar:
        return GET_SETTINGS("Lexer/Perl/Fill/RegexVar", bool);
    case SubstitutionVar:
        return GET_SETTINGS("Lexer/Perl/Fill/SubstitutionVar", bool);
    case BackticksVar:
        return GET_SETTINGS("Lexer/Perl/Fill/BackticksVar", bool);
    case DoubleQuotedHereDocumentVar:
        return GET_SETTINGS("Lexer/Perl/Fill/DoubleQuotedHereDocumentVar", bool);
    case BacktickHereDocumentVar:
        return GET_SETTINGS("Lexer/Perl/Fill/BacktickHereDocumentVar", bool);
    case QuotedStringQQVar:
        return GET_SETTINGS("Lexer/Perl/Fill/QuotedStringQQVar", bool);
    case QuotedStringQXVar:
        return GET_SETTINGS("Lexer/Perl/Fill/QuotedStringQXVar", bool);
    case QuotedStringQRVar:
        return GET_SETTINGS("Lexer/Perl/Fill/QuotedStringQRVar", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerPerl::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Perl/Font/Universal", QFont);
    case Error:
        return GET_SETTINGS("Lexer/Perl/Font/Error", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Perl/Font/Comment", QFont);
    case POD:
        return GET_SETTINGS("Lexer/Perl/Font/POD", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Perl/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Perl/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Perl/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Perl/Font/SingleQuotedString", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Perl/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Perl/Font/Identifier", QFont);
    case Scalar:
        return GET_SETTINGS("Lexer/Perl/Font/Scalar", QFont);
    case Array:
        return GET_SETTINGS("Lexer/Perl/Font/Array", QFont);
    case Hash:
        return GET_SETTINGS("Lexer/Perl/Font/Hash", QFont);
    case SymbolTable:
        return GET_SETTINGS("Lexer/Perl/Font/SymbolTable", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/Perl/Font/Regex", QFont);
    case Substitution:
        return GET_SETTINGS("Lexer/Perl/Font/Substitution", QFont);
    case Backticks:
        return GET_SETTINGS("Lexer/Perl/Font/Backticks", QFont);
    case DataSection:
        return GET_SETTINGS("Lexer/Perl/Font/DataSection", QFont);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Perl/Font/HereDocumentDelimiter", QFont);
    case SingleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Perl/Font/SingleQuotedHereDocument", QFont);
    case DoubleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Perl/Font/DoubleQuotedHereDocument", QFont);
    case BacktickHereDocument:
        return GET_SETTINGS("Lexer/Perl/Font/BacktickHereDocument", QFont);
    case QuotedStringQ:
        return GET_SETTINGS("Lexer/Perl/Font/QuotedStringQ", QFont);
    case QuotedStringQQ:
        return GET_SETTINGS("Lexer/Perl/Font/QuotedStringQQ", QFont);
    case QuotedStringQX:
        return GET_SETTINGS("Lexer/Perl/Font/QuotedStringQX", QFont);
    case QuotedStringQR:
        return GET_SETTINGS("Lexer/Perl/Font/QuotedStringQR", QFont);
    case QuotedStringQW:
        return GET_SETTINGS("Lexer/Perl/Font/QuotedStringQW", QFont);
    case PODVerbatim:
        return GET_SETTINGS("Lexer/Perl/Font/PODVerbatim", QFont);
    case SubroutinePrototype:
        return GET_SETTINGS("Lexer/Perl/Font/SubroutinePrototype", QFont);
    case FormatIdentifier:
        return GET_SETTINGS("Lexer/Perl/Font/FormatIdentifier", QFont);
    case FormatBody:
        return GET_SETTINGS("Lexer/Perl/Font/FormatBody", QFont);
    case DoubleQuotedStringVar:
        return GET_SETTINGS("Lexer/Perl/Font/DoubleQuotedStringVar", QFont);
    case Translation:
        return GET_SETTINGS("Lexer/Perl/Font/Translation", QFont);
    case RegexVar:
        return GET_SETTINGS("Lexer/Perl/Font/RegexVar", QFont);
    case SubstitutionVar:
        return GET_SETTINGS("Lexer/Perl/Font/SubstitutionVar", QFont);
    case BackticksVar:
        return GET_SETTINGS("Lexer/Perl/Font/BackticksVar", QFont);
    case DoubleQuotedHereDocumentVar:
        return GET_SETTINGS("Lexer/Perl/Font/DoubleQuotedHereDocumentVar", QFont);
    case BacktickHereDocumentVar:
        return GET_SETTINGS("Lexer/Perl/Font/BacktickHereDocumentVar", QFont);
    case QuotedStringQQVar:
        return GET_SETTINGS("Lexer/Perl/Font/QuotedStringQQVar", QFont);
    case QuotedStringQXVar:
        return GET_SETTINGS("Lexer/Perl/Font/QuotedStringQXVar", QFont);
    case QuotedStringQRVar:
        return GET_SETTINGS("Lexer/Perl/Font/QuotedStringQRVar", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerPerl::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Perl/BgColor/Universal", QColor);
    case Error:
        return GET_SETTINGS("Lexer/Perl/BgColor/Error", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Perl/BgColor/Comment", QColor);
    case POD:
        return GET_SETTINGS("Lexer/Perl/BgColor/POD", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Perl/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Perl/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Perl/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Perl/BgColor/SingleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Perl/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Perl/BgColor/Identifier", QColor);
    case Scalar:
        return GET_SETTINGS("Lexer/Perl/BgColor/Scalar", QColor);
    case Array:
        return GET_SETTINGS("Lexer/Perl/BgColor/Array", QColor);
    case Hash:
        return GET_SETTINGS("Lexer/Perl/BgColor/Hash", QColor);
    case SymbolTable:
        return GET_SETTINGS("Lexer/Perl/BgColor/SymbolTable", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/Perl/BgColor/Regex", QColor);
    case Substitution:
        return GET_SETTINGS("Lexer/Perl/BgColor/Substitution", QColor);
    case Backticks:
        return GET_SETTINGS("Lexer/Perl/BgColor/Backticks", QColor);
    case DataSection:
        return GET_SETTINGS("Lexer/Perl/BgColor/DataSection", QColor);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Perl/BgColor/HereDocumentDelimiter", QColor);
    case SingleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Perl/BgColor/SingleQuotedHereDocument", QColor);
    case DoubleQuotedHereDocument:
        return GET_SETTINGS("Lexer/Perl/BgColor/DoubleQuotedHereDocument", QColor);
    case BacktickHereDocument:
        return GET_SETTINGS("Lexer/Perl/BgColor/BacktickHereDocument", QColor);
    case QuotedStringQ:
        return GET_SETTINGS("Lexer/Perl/BgColor/QuotedStringQ", QColor);
    case QuotedStringQQ:
        return GET_SETTINGS("Lexer/Perl/BgColor/QuotedStringQQ", QColor);
    case QuotedStringQX:
        return GET_SETTINGS("Lexer/Perl/BgColor/QuotedStringQX", QColor);
    case QuotedStringQR:
        return GET_SETTINGS("Lexer/Perl/BgColor/QuotedStringQR", QColor);
    case QuotedStringQW:
        return GET_SETTINGS("Lexer/Perl/BgColor/QuotedStringQW", QColor);
    case PODVerbatim:
        return GET_SETTINGS("Lexer/Perl/BgColor/PODVerbatim", QColor);
    case SubroutinePrototype:
        return GET_SETTINGS("Lexer/Perl/BgColor/SubroutinePrototype", QColor);
    case FormatIdentifier:
        return GET_SETTINGS("Lexer/Perl/BgColor/FormatIdentifier", QColor);
    case FormatBody:
        return GET_SETTINGS("Lexer/Perl/BgColor/FormatBody", QColor);
    case DoubleQuotedStringVar:
        return GET_SETTINGS("Lexer/Perl/BgColor/DoubleQuotedStringVar", QColor);
    case Translation:
        return GET_SETTINGS("Lexer/Perl/BgColor/Translation", QColor);
    case RegexVar:
        return GET_SETTINGS("Lexer/Perl/BgColor/RegexVar", QColor);
    case SubstitutionVar:
        return GET_SETTINGS("Lexer/Perl/BgColor/SubstitutionVar", QColor);
    case BackticksVar:
        return GET_SETTINGS("Lexer/Perl/BgColor/BackticksVar", QColor);
    case DoubleQuotedHereDocumentVar:
        return GET_SETTINGS("Lexer/Perl/BgColor/DoubleQuotedHereDocumentVar", QColor);
    case BacktickHereDocumentVar:
        return GET_SETTINGS("Lexer/Perl/BgColor/BacktickHereDocumentVar", QColor);
    case QuotedStringQQVar:
        return GET_SETTINGS("Lexer/Perl/BgColor/QuotedStringQQVar", QColor);
    case QuotedStringQXVar:
        return GET_SETTINGS("Lexer/Perl/BgColor/QuotedStringQXVar", QColor);
    case QuotedStringQRVar:
        return GET_SETTINGS("Lexer/Perl/BgColor/QuotedStringQRVar", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerPerl::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerPerlKeyword1;
    default:
        return 0;
    }
}

QString TpLexerPerl::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Error:
        return tr("Error");
    case Comment:
        return tr("Comment");
    case POD:
        return tr("POD");
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
    case Array:
        return tr("Array");
    case Hash:
        return tr("Hash");
    case SymbolTable:
        return tr("Symbol table");
    case Regex:
        return tr("Regular expression");
    case Substitution:
        return tr("Substitution");
    case Backticks:
        return tr("Backticks");
    case DataSection:
        return tr("Data section");
    case HereDocumentDelimiter:
        return tr("Here document delimiter");
    case SingleQuotedHereDocument:
        return tr("Single-quoted here document");
    case DoubleQuotedHereDocument:
        return tr("Double-quoted here document");
    case BacktickHereDocument:
        return tr("Backtick here document");
    case QuotedStringQ:
        return tr("Quoted string (q)");
    case QuotedStringQQ:
        return tr("Quoted string (qq)");
    case QuotedStringQX:
        return tr("Quoted string (qx)");
    case QuotedStringQR:
        return tr("Quoted string (qr)");
    case QuotedStringQW:
        return tr("Quoted string (qw)");
    case PODVerbatim:
        return tr("POD verbatim");
    case SubroutinePrototype:
        return tr("Subroutine prototype");
    case FormatIdentifier:
        return tr("Format identifier");
    case FormatBody:
        return tr("Format body");
    case DoubleQuotedStringVar:
        return tr("Double-quoted string (interpolated variable)");
    case Translation:
        return tr("Translation");
    case RegexVar:
        return tr("Regular expression (interpolated variable)");
    case SubstitutionVar:
        return tr("Substitution (interpolated variable)");
    case BackticksVar:
        return tr("Backticks (interpolated variable)");
    case DoubleQuotedHereDocumentVar:
        return tr("Double-quoted here document (interpolated variable)");
    case BacktickHereDocumentVar:
        return tr("Backtick here document (interpolated variable)");
    case QuotedStringQQVar:
        return tr("Quoted string (qq, interpolated variable)");
    case QuotedStringQXVar:
        return tr("Quoted string (qx, interpolated variable)");
    case QuotedStringQRVar:
        return tr("Quoted string (qr, interpolated variable)");
    }

    return QString();
}

void TpLexerPerl::refreshProperties()
{
    setLexerProperty(PropFold, m_fold);
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
    setLexerProperty(PropFoldPOD, m_foldPOD);
    setLexerProperty(PropFoldPackage, m_foldPackage);
    setLexerProperty(PropFoldAtElse, m_foldAtElse);
}

void TpLexerPerl::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFold: {
        m_fold = value.toBool();
        emit propertyChanged("fold", (m_fold ? "1" : "0"));
        break;
    }
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
    case PropFoldPOD: {
        m_foldPOD = value.toBool();
        emit propertyChanged("fold.perl.pod", (m_foldPOD ? "1" : "0"));
        break;
    }
    case PropFoldPackage: {
        m_foldPackage = value.toBool();
        emit propertyChanged("fold.perl.package", (m_foldPackage ? "1" : "0"));
        break;
    }
    case PropFoldAtElse: {
        m_foldAtElse = value.toBool();
        emit propertyChanged("fold.perl.at.else", (m_foldAtElse ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerPerl::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFold:
        return m_fold;
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldComments:
        return m_foldComments;
    case PropFoldPOD:
        return m_foldPOD;
    case PropFoldPackage:
        return m_foldPackage;
    case PropFoldAtElse:
        return m_foldAtElse;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerPerl::readProperties(QSettings &settings, const QString &prefix)
{
    m_fold = GET_SETTINGS_WITH(prefix + "fold", bool, true);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_foldPOD = GET_SETTINGS_WITH(prefix + "foldpod", bool, true);
    m_foldPackage = GET_SETTINGS_WITH(prefix + "foldpackage", bool, true);
    m_foldAtElse = GET_SETTINGS_WITH(prefix + "foldatelse", bool, true);

    return true;
}

bool TpLexerPerl::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "fold", m_fold);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "foldpod", m_foldPOD);
    SET_SETTINGS(prefix + "foldpackage", m_foldPackage);
    SET_SETTINGS(prefix + "foldatelse", m_foldAtElse);

    return true;
}

TP_END_NAMESPACE
