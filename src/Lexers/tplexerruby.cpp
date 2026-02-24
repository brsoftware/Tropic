#include <Lexers/TpLexerRuby>

TP_NAMESPACE

TpLexerRuby::TpLexerRuby(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true),
    m_foldCompact(true)
{}

TpLexerRuby::~TpLexerRuby()
{}

const char *TpLexerRuby::language() const
{
    return "Ruby";
}

const char *TpLexerRuby::lexer() const
{
    return "ruby";
}

const char *TpLexerRuby::blockEnd(int *style) const
{
    if (style)
        *style = Keyword;

    return "end";
}

const char *TpLexerRuby::blockStart(int *style) const
{
    if (style)
        *style = Keyword;

    return "do";
}

const char *TpLexerRuby::blockStartKeyword(int *style) const
{
    if (style)
        *style = Keyword;

    return "def class if do elseif else case while for";
}

int TpLexerRuby::braceStyle() const
{
    return Operator;
}

QColor TpLexerRuby::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Ruby/Color/Universal", QColor);
    case Error:
        return GET_SETTINGS("Lexer/Ruby/Color/Error", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Ruby/Color/Comment", QColor);
    case POD:
        return GET_SETTINGS("Lexer/Ruby/Color/POD", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Ruby/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Ruby/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Ruby/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Ruby/Color/SingleQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Lexer/Ruby/Color/ClassName", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Ruby/Color/FunctionMethodName", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Ruby/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Ruby/Color/Identifier", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/Ruby/Color/Regex", QColor);
    case Global:
        return GET_SETTINGS("Lexer/Ruby/Color/Global", QColor);
    case Symbol:
        return GET_SETTINGS("Lexer/Ruby/Color/Symbol", QColor);
    case ModuleName:
        return GET_SETTINGS("Lexer/Ruby/Color/ModuleName", QColor);
    case InstanceVariable:
        return GET_SETTINGS("Lexer/Ruby/Color/InstanceVariable", QColor);
    case ClassVariable:
        return GET_SETTINGS("Lexer/Ruby/Color/ClassVariable", QColor);
    case Backticks:
        return GET_SETTINGS("Lexer/Ruby/Color/Backticks", QColor);
    case DataSection:
        return GET_SETTINGS("Lexer/Ruby/Color/DataSection", QColor);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Ruby/Color/HereDocumentDelimiter", QColor);
    case HereDocument:
        return GET_SETTINGS("Lexer/Ruby/Color/HereDocument", QColor);
    case PercentStringq:
        return GET_SETTINGS("Lexer/Ruby/Color/PercentStringq", QColor);
    case PercentStringQ:
        return GET_SETTINGS("Lexer/Ruby/Color/PercentStringQ", QColor);
    case PercentStringx:
        return GET_SETTINGS("Lexer/Ruby/Color/PercentStringx", QColor);
    case PercentStringr:
        return GET_SETTINGS("Lexer/Ruby/Color/PercentStringr", QColor);
    case PercentStringw:
        return GET_SETTINGS("Lexer/Ruby/Color/PercentStringw", QColor);
    case DemotedKeyword:
        return GET_SETTINGS("Lexer/Ruby/Color/DemotedKeyword", QColor);
    case Stdin:
        return GET_SETTINGS("Lexer/Ruby/Color/Stdin", QColor);
    case Stdout:
        return GET_SETTINGS("Lexer/Ruby/Color/Stdout", QColor);
    case Stderr:
        return GET_SETTINGS("Lexer/Ruby/Color/Stderr", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerRuby::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Ruby/Fill/Universal", bool);
    case Error:
        return GET_SETTINGS("Lexer/Ruby/Fill/Error", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Ruby/Fill/Comment", bool);
    case POD:
        return GET_SETTINGS("Lexer/Ruby/Fill/POD", bool);
    case Number:
        return GET_SETTINGS("Lexer/Ruby/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Ruby/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Ruby/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Ruby/Fill/SingleQuotedString", bool);
    case ClassName:
        return GET_SETTINGS("Lexer/Ruby/Fill/ClassName", bool);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Ruby/Fill/FunctionMethodName", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Ruby/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Ruby/Fill/Identifier", bool);
    case Regex:
        return GET_SETTINGS("Lexer/Ruby/Fill/Regex", bool);
    case Global:
        return GET_SETTINGS("Lexer/Ruby/Fill/Global", bool);
    case Symbol:
        return GET_SETTINGS("Lexer/Ruby/Fill/Symbol", bool);
    case ModuleName:
        return GET_SETTINGS("Lexer/Ruby/Fill/ModuleName", bool);
    case InstanceVariable:
        return GET_SETTINGS("Lexer/Ruby/Fill/InstanceVariable", bool);
    case ClassVariable:
        return GET_SETTINGS("Lexer/Ruby/Fill/ClassVariable", bool);
    case Backticks:
        return GET_SETTINGS("Lexer/Ruby/Fill/Backticks", bool);
    case DataSection:
        return GET_SETTINGS("Lexer/Ruby/Fill/DataSection", bool);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Ruby/Fill/HereDocumentDelimiter", bool);
    case HereDocument:
        return GET_SETTINGS("Lexer/Ruby/Fill/HereDocument", bool);
    case PercentStringq:
        return GET_SETTINGS("Lexer/Ruby/Fill/PercentStringq", bool);
    case PercentStringQ:
        return GET_SETTINGS("Lexer/Ruby/Fill/PercentStringQ", bool);
    case PercentStringx:
        return GET_SETTINGS("Lexer/Ruby/Fill/PercentStringx", bool);
    case PercentStringr:
        return GET_SETTINGS("Lexer/Ruby/Fill/PercentStringr", bool);
    case PercentStringw:
        return GET_SETTINGS("Lexer/Ruby/Fill/PercentStringw", bool);
    case DemotedKeyword:
        return GET_SETTINGS("Lexer/Ruby/Fill/DemotedKeyword", bool);
    case Stdin:
        return GET_SETTINGS("Lexer/Ruby/Fill/Stdin", bool);
    case Stdout:
        return GET_SETTINGS("Lexer/Ruby/Fill/Stdout", bool);
    case Stderr:
        return GET_SETTINGS("Lexer/Ruby/Fill/Stderr", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerRuby::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Ruby/Font/Universal", QFont);
    case Error:
        return GET_SETTINGS("Lexer/Ruby/Font/Error", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Ruby/Font/Comment", QFont);
    case POD:
        return GET_SETTINGS("Lexer/Ruby/Font/POD", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Ruby/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Ruby/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Ruby/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Ruby/Font/SingleQuotedString", QFont);
    case ClassName:
        return GET_SETTINGS("Lexer/Ruby/Font/ClassName", QFont);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Ruby/Font/FunctionMethodName", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Ruby/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Ruby/Font/Identifier", QFont);
    case Regex:
        return GET_SETTINGS("Lexer/Ruby/Font/Regex", QFont);
    case Global:
        return GET_SETTINGS("Lexer/Ruby/Font/Global", QFont);
    case Symbol:
        return GET_SETTINGS("Lexer/Ruby/Font/Symbol", QFont);
    case ModuleName:
        return GET_SETTINGS("Lexer/Ruby/Font/ModuleName", QFont);
    case InstanceVariable:
        return GET_SETTINGS("Lexer/Ruby/Font/InstanceVariable", QFont);
    case ClassVariable:
        return GET_SETTINGS("Lexer/Ruby/Font/ClassVariable", QFont);
    case Backticks:
        return GET_SETTINGS("Lexer/Ruby/Font/Backticks", QFont);
    case DataSection:
        return GET_SETTINGS("Lexer/Ruby/Font/DataSection", QFont);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Ruby/Font/HereDocumentDelimiter", QFont);
    case HereDocument:
        return GET_SETTINGS("Lexer/Ruby/Font/HereDocument", QFont);
    case PercentStringq:
        return GET_SETTINGS("Lexer/Ruby/Font/PercentStringq", QFont);
    case PercentStringQ:
        return GET_SETTINGS("Lexer/Ruby/Font/PercentStringQ", QFont);
    case PercentStringx:
        return GET_SETTINGS("Lexer/Ruby/Font/PercentStringx", QFont);
    case PercentStringr:
        return GET_SETTINGS("Lexer/Ruby/Font/PercentStringr", QFont);
    case PercentStringw:
        return GET_SETTINGS("Lexer/Ruby/Font/PercentStringw", QFont);
    case DemotedKeyword:
        return GET_SETTINGS("Lexer/Ruby/Font/DemotedKeyword", QFont);
    case Stdin:
        return GET_SETTINGS("Lexer/Ruby/Font/Stdin", QFont);
    case Stdout:
        return GET_SETTINGS("Lexer/Ruby/Font/Stdout", QFont);
    case Stderr:
        return GET_SETTINGS("Lexer/Ruby/Font/Stderr", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerRuby::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Universal", QColor);
    case Error:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Error", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Comment", QColor);
    case POD:
        return GET_SETTINGS("Lexer/Ruby/BgColor/POD", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Ruby/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Ruby/BgColor/SingleQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Lexer/Ruby/BgColor/ClassName", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Ruby/BgColor/FunctionMethodName", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Identifier", QColor);
    case Regex:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Regex", QColor);
    case Global:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Global", QColor);
    case Symbol:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Symbol", QColor);
    case ModuleName:
        return GET_SETTINGS("Lexer/Ruby/BgColor/ModuleName", QColor);
    case InstanceVariable:
        return GET_SETTINGS("Lexer/Ruby/BgColor/InstanceVariable", QColor);
    case ClassVariable:
        return GET_SETTINGS("Lexer/Ruby/BgColor/ClassVariable", QColor);
    case Backticks:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Backticks", QColor);
    case DataSection:
        return GET_SETTINGS("Lexer/Ruby/BgColor/DataSection", QColor);
    case HereDocumentDelimiter:
        return GET_SETTINGS("Lexer/Ruby/BgColor/HereDocumentDelimiter", QColor);
    case HereDocument:
        return GET_SETTINGS("Lexer/Ruby/BgColor/HereDocument", QColor);
    case PercentStringq:
        return GET_SETTINGS("Lexer/Ruby/BgColor/PercentStringq", QColor);
    case PercentStringQ:
        return GET_SETTINGS("Lexer/Ruby/BgColor/PercentStringQ", QColor);
    case PercentStringx:
        return GET_SETTINGS("Lexer/Ruby/BgColor/PercentStringx", QColor);
    case PercentStringr:
        return GET_SETTINGS("Lexer/Ruby/BgColor/PercentStringr", QColor);
    case PercentStringw:
        return GET_SETTINGS("Lexer/Ruby/BgColor/PercentStringw", QColor);
    case DemotedKeyword:
        return GET_SETTINGS("Lexer/Ruby/BgColor/DemotedKeyword", QColor);
    case Stdin:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Stdin", QColor);
    case Stdout:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Stdout", QColor);
    case Stderr:
        return GET_SETTINGS("Lexer/Ruby/BgColor/Stderr", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

const char *TpLexerRuby::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerRubyKeyword1;
    default:
        return 0;
    }
}

QString TpLexerRuby::description(int style) const
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
    case ClassName:
        return tr("Class name");
    case FunctionMethodName:
        return tr("Function or method name");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case Regex:
        return tr("Regular expression");
    case Global:
        return tr("Global");
    case Symbol:
        return tr("Symbol");
    case ModuleName:
        return tr("Module name");
    case InstanceVariable:
        return tr("Instance variable");
    case ClassVariable:
        return tr("Class variable");
    case Backticks:
        return tr("Backticks");
    case DataSection:
        return tr("Data section");
    case HereDocumentDelimiter:
        return tr("Here document delimiter");
    case HereDocument:
        return tr("Here document");
    case PercentStringq:
        return tr("%q string");
    case PercentStringQ:
        return tr("%Q string");
    case PercentStringx:
        return tr("%x string");
    case PercentStringr:
        return tr("%r string");
    case PercentStringw:
        return tr("%w string");
    case DemotedKeyword:
        return tr("Demoted keyword");
    case Stdin:
        return tr("stdin");
    case Stdout:
        return tr("stdout");
    case Stderr:
        return tr("stderr");
    }

    return QString();
}

void TpLexerRuby::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
}

void TpLexerRuby::setLexerProperty(int prop, QVariant value)
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

QVariant TpLexerRuby::lexerProperty(int prop) const
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

bool TpLexerRuby::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);

    return true;
}

bool TpLexerRuby::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);

    return true;
}

TP_END_NAMESPACE
