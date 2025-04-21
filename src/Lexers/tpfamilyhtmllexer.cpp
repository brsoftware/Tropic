#include <Lexers/TpFamilyHTMLLexer>

TP_NAMESPACE

TpFamilyHTMLLexer::TpFamilyHTMLLexer(QObject *parent)
    : TpGeneralLexer(parent),
    m_aspDefaultLanguage(1),
    m_caseSensitiveTags(false),
    m_allowXMLScripts(true),
    m_makoTemplate(false),
    m_djangoTemplate(false),
    m_enableFolding(true),
    m_foldCompact(true),
    m_foldHTML(true),
    m_foldHTMLComment(true),
    m_foldHTMLHeredoc(true),
    m_foldHTMLPreprocessor(true)
{}

TpFamilyHTMLLexer::~TpFamilyHTMLLexer()
{}

const char *TpFamilyHTMLLexer::language() const
{
    return "HTML";
}

const char *TpFamilyHTMLLexer::lexer() const
{
    return "hypertext";
}

const char *TpFamilyHTMLLexer::autoCompletionFillups() const
{
    return "/>";
}

const char *TpFamilyHTMLLexer::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-";
}

QColor TpFamilyHTMLLexer::defaultColor(int style) const
{
    DEF_SETTINGS;
    return GET_SETTINGS("Editor/Color/Universal", QColor);
}

bool TpFamilyHTMLLexer::defaultEolFill(int style) const
{
    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpFamilyHTMLLexer::defaultFont(int style) const
{
    DEF_SETTINGS;
    return GET_SETTINGS("Editor/Font/Universal", QFont);
}

QColor TpFamilyHTMLLexer::defaultPaper(int style) const
{
    DEF_SETTINGS;
    return GET_SETTINGS("Editor/BgColor/Universal", QColor);
}

const char *TpFamilyHTMLLexer::keywords(int set) const
{
    return 0;
}

QString TpFamilyHTMLLexer::description(int style) const
{
    switch (style)
    {
    default:
        return tr("HTML default");
    case Tag:
        return tr("Tag");
    case UnknownTag:
        return tr("Unknown tag");
    case Attribute:
        return tr("Attribute");
    case UnknownAttribute:
        return tr("Unknown attribute");
    case HTMLNumber:
        return tr("HTML number");
    case HTMLDoubleQuotedString:
        return tr("HTML double-quoted string");
    case HTMLSingleQuotedString:
        return tr("HTML single-quoted string");
    case OtherInTag:
        return tr("Other text in a tag");
    case HTMLComment:
        return tr("HTML comment");
    case Entity:
        return tr("Entity");
    case XMLTagEnd:
        return tr("End of a tag");
    case XMLStart:
        return tr("Start of an XML fragment");
    case XMLEnd:
        return tr("End of an XML fragment");
    case Script:
        return tr("Script tag");
    case ASPAtStart:
        return tr("Start of an ASP fragment with @");
    case ASPStart:
        return tr("Start of an ASP fragment");
    case CDATA:
        return tr("CDATA");
    case PHPStart:
        return tr("Start of a PHP fragment");
    case HTMLValue:
        return tr("Unquoted HTML value");
    case ASPXCComment:
        return tr("ASP X-Code comment");
    case SGMLDefault:
        return tr("SGML default");
    case SGMLCommand:
        return tr("SGML command");
    case SGMLParameter:
        return tr("First parameter of an SGML command");
    case SGMLDoubleQuotedString:
        return tr("SGML double-quoted string");
    case SGMLSingleQuotedString:
        return tr("SGML single-quoted string");
    case SGMLError:
        return tr("SGML error");
    case SGMLSpecial:
        return tr("SGML special entity");
    case SGMLComment:
        return tr("SGML comment");
    case SGMLParameterComment:
        return tr("First parameter comment of an SGML command");
    case SGMLBlockDefault:
        return tr("SGML block default");
    case JavaScriptStart:
        return tr("Start of a JavaScript fragment");
    case JavaScriptDefault:
        return tr("JavaScript default");
    case JavaScriptComment:
        return tr("JavaScript comment");
    case JavaScriptCommentLine:
        return tr("JavaScript line comment");
    case JavaScriptCommentDoc:
        return tr("JavaDoc style JavaScript comment");
    case JavaScriptNumber:
        return tr("JavaScript number");
    case JavaScriptWord:
        return tr("JavaScript word");
    case JavaScriptKeyword:
        return tr("JavaScript keyword");
    case JavaScriptDoubleQuotedString:
        return tr("JavaScript double-quoted string");
    case JavaScriptSingleQuotedString:
        return tr("JavaScript single-quoted string");
    case JavaScriptSymbol:
        return tr("JavaScript symbol");
    case JavaScriptUnclosedString:
        return tr("JavaScript unclosed string");
    case JavaScriptRegex:
        return tr("JavaScript regular expression");
    case ASPJavaScriptStart:
        return tr("Start of an ASP JavaScript fragment");
    case ASPJavaScriptDefault:
        return tr("ASP JavaScript default");
    case ASPJavaScriptComment:
        return tr("ASP JavaScript comment");
    case ASPJavaScriptCommentLine:
        return tr("ASP JavaScript line comment");
    case ASPJavaScriptCommentDoc:
        return tr("JavaDoc style ASP JavaScript comment");
    case ASPJavaScriptNumber:
        return tr("ASP JavaScript number");
    case ASPJavaScriptWord:
        return tr("ASP JavaScript word");
    case ASPJavaScriptKeyword:
        return tr("ASP JavaScript keyword");
    case ASPJavaScriptDoubleQuotedString:
        return tr("ASP JavaScript double-quoted string");
    case ASPJavaScriptSingleQuotedString:
        return tr("ASP JavaScript single-quoted string");
    case ASPJavaScriptSymbol:
        return tr("ASP JavaScript symbol");
    case ASPJavaScriptUnclosedString:
        return tr("ASP JavaScript unclosed string");
    case ASPJavaScriptRegex:
        return tr("ASP JavaScript regular expression");
    case VBScriptStart:
        return tr("Start of a VBScript fragment");
    case VBScriptDefault:
        return tr("VBScript default");
    case VBScriptComment:
        return tr("VBScript comment");
    case VBScriptNumber:
        return tr("VBScript number");
    case VBScriptKeyword:
        return tr("VBScript keyword");
    case VBScriptString:
        return tr("VBScript string");
    case VBScriptIdentifier:
        return tr("VBScript identifier");
    case VBScriptUnclosedString:
        return tr("VBScript unclosed string");
    case ASPVBScriptStart:
        return tr("Start of an ASP VBScript fragment");
    case ASPVBScriptDefault:
        return tr("ASP VBScript default");
    case ASPVBScriptComment:
        return tr("ASP VBScript comment");
    case ASPVBScriptNumber:
        return tr("ASP VBScript number");
    case ASPVBScriptKeyword:
        return tr("ASP VBScript keyword");
    case ASPVBScriptString:
        return tr("ASP VBScript string");
    case ASPVBScriptIdentifier:
        return tr("ASP VBScript identifier");
    case ASPVBScriptUnclosedString:
        return tr("ASP VBScript unclosed string");
    case PythonStart:
        return tr("Start of a Python fragment");
    case PythonDefault:
        return tr("Python default");
    case PythonComment:
        return tr("Python comment");
    case PythonNumber:
        return tr("Python number");
    case PythonDoubleQuotedString:
        return tr("Python double-quoted string");
    case PythonSingleQuotedString:
        return tr("Python single-quoted string");
    case PythonKeyword:
        return tr("Python keyword");
    case PythonTripleDoubleQuotedString:
        return tr("Python triple double-quoted string");
    case PythonTripleSingleQuotedString:
        return tr("Python triple single-quoted string");
    case PythonClassName:
        return tr("Python class name");
    case PythonFunctionMethodName:
        return tr("Python function or method name");
    case PythonOperator:
        return tr("Python operator");
    case PythonIdentifier:
        return tr("Python identifier");
    case ASPPythonStart:
        return tr("Start of an ASP Python fragment");
    case ASPPythonDefault:
        return tr("ASP Python default");
    case ASPPythonComment:
        return tr("ASP Python comment");
    case ASPPythonNumber:
        return tr("ASP Python number");
    case ASPPythonDoubleQuotedString:
        return tr("ASP Python double-quoted string");
    case ASPPythonSingleQuotedString:
        return tr("ASP Python single-quoted string");
    case ASPPythonKeyword:
        return tr("ASP Python keyword");
    case ASPPythonTripleDoubleQuotedString:
        return tr("ASP Python triple double-quoted string");
    case ASPPythonTripleSingleQuotedString:
        return tr("ASP Python triple single-quoted string");
    case ASPPythonClassName:
        return tr("ASP Python class name");
    case ASPPythonFunctionMethodName:
        return tr("ASP Python function or method name");
    case ASPPythonOperator:
        return tr("ASP Python operator");
    case ASPPythonIdentifier:
        return tr("ASP Python identifier");
    case PHPDefault:
        return tr("PHP default");
    case PHPDoubleQuotedString:
        return tr("PHP double-quoted string");
    case PHPSingleQuotedString:
        return tr("PHP single-quoted string");
    case PHPKeyword:
        return tr("PHP keyword");
    case PHPNumber:
        return tr("PHP number");
    case PHPVariable:
        return tr("PHP variable");
    case PHPComment:
        return tr("PHP comment");
    case PHPCommentLine:
        return tr("PHP line comment");
    case PHPDoubleQuotedVariable:
        return tr("PHP double-quoted variable");
    case PHPOperator:
        return tr("PHP operator");
    }

    return QString();
}

void TpFamilyHTMLLexer::refreshProperties()
{
    setLexerProperty(PropAspDefaultLanguage, m_aspDefaultLanguage);
    setLexerProperty(PropCaseSensitiveTags, m_caseSensitiveTags);
    setLexerProperty(PropAllowXMLScripts, m_allowXMLScripts);
    setLexerProperty(PropMakoTemplate, m_makoTemplate);
    setLexerProperty(PropDjangoTemplate, m_djangoTemplate);
    setLexerProperty(PropEnableFolding, m_enableFolding);
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldHTML, m_foldHTML);
    setLexerProperty(PropFoldHTMLComment, m_foldHTMLComment);
    setLexerProperty(PropFoldHTMLHeredoc, m_foldHTMLHeredoc);
    setLexerProperty(PropFoldHTMLPreprocessor, m_foldHTMLPreprocessor);
}

void TpFamilyHTMLLexer::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropAspDefaultLanguage: {
        m_aspDefaultLanguage = value.toInt();
        emit propertyChanged("asp.default.language", textAsBytes(QString::number(m_aspDefaultLanguage)).constData());
        break;
    }
    case PropCaseSensitiveTags: {
        m_caseSensitiveTags = value.toBool();
        emit propertyChanged("html.tags.case.sensitive", (m_caseSensitiveTags ? "1" : "0"));
        break;
    }
    case PropAllowXMLScripts: {
        m_allowXMLScripts = value.toBool();
        emit propertyChanged("lexer.xml.allow.scripts", (m_allowXMLScripts ? "1" : "0"));
        break;
    }
    case PropMakoTemplate: {
        m_makoTemplate = value.toBool();
        emit propertyChanged("lexer.html.mako", (m_makoTemplate ? "1" : "0"));
        break;
    }
    case PropDjangoTemplate: {
        m_djangoTemplate = value.toBool();
        emit propertyChanged("lexer.html.django", (m_djangoTemplate ? "1" : "0"));
        break;
    }
    case PropEnableFolding: {
        m_enableFolding = value.toBool();
        emit propertyChanged("fold", (m_enableFolding ? "1" : "0"));
        break;
    }
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    case PropFoldHTML: {
        m_foldHTML = value.toBool();
        emit propertyChanged("fold.html", (m_foldHTML ? "1" : "0"));
        break;
    }
    case PropFoldHTMLComment: {
        m_foldHTMLComment = value.toBool();
        emit propertyChanged("fold.hypertext.comment", (m_foldHTMLComment ? "1" : "0"));
        break;
    }
    case PropFoldHTMLHeredoc: {
        m_foldHTMLHeredoc = value.toBool();
        emit propertyChanged("fold.hypertext.heredoc", (m_foldHTMLHeredoc ? "1" : "0"));
        break;
    }
    case PropFoldHTMLPreprocessor: {
        m_foldHTMLPreprocessor = value.toBool();
        emit propertyChanged("fold.html.preprocessor", (m_foldHTMLPreprocessor ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpFamilyHTMLLexer::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropAspDefaultLanguage:
        return m_aspDefaultLanguage;
    case PropCaseSensitiveTags:
        return m_caseSensitiveTags;
    case PropAllowXMLScripts:
        return m_allowXMLScripts;
    case PropMakoTemplate:
        return m_makoTemplate;
    case PropDjangoTemplate:
        return m_djangoTemplate;
    case PropEnableFolding:
        return m_enableFolding;
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldHTML:
        return m_foldHTML;
    case PropFoldHTMLComment:
        return m_foldHTMLComment;
    case PropFoldHTMLHeredoc:
        return m_foldHTMLHeredoc;
    case PropFoldHTMLPreprocessor:
        return m_foldHTMLPreprocessor;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpFamilyHTMLLexer::readProperties(QSettings &settings, const QString &prefix)
{
    m_aspDefaultLanguage = GET_SETTINGS_WITH(prefix + "aspdefaultlanguage", int, AspDefaultsJavaScript);
    m_caseSensitiveTags = GET_SETTINGS_WITH(prefix + "casesensitivetags", bool, false);
    m_allowXMLScripts = GET_SETTINGS_WITH(prefix + "allowxmlscripts", bool, true);
    m_makoTemplate = GET_SETTINGS_WITH(prefix + "makotemplate", bool, false);
    m_djangoTemplate = GET_SETTINGS_WITH(prefix + "djangotemplate", bool, false);
    m_enableFolding = GET_SETTINGS_WITH(prefix + "enablefolding", bool, true);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldHTML = GET_SETTINGS_WITH(prefix + "foldhtml", bool, true);
    m_foldHTMLComment = GET_SETTINGS_WITH(prefix + "foldhtmlcomment", bool, true);
    m_foldHTMLHeredoc = GET_SETTINGS_WITH(prefix + "foldhtmlheredoc", bool, true);
    m_foldHTMLPreprocessor = GET_SETTINGS_WITH(prefix + "foldhtmlpreprocessor", bool, true);

    return true;
}

bool TpFamilyHTMLLexer::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "aspdefaultlanguage", m_aspDefaultLanguage);
    SET_SETTINGS(prefix + "casesensitivetags", m_caseSensitiveTags);
    SET_SETTINGS(prefix + "allowxmlscripts", m_allowXMLScripts);
    SET_SETTINGS(prefix + "makotemplate", m_makoTemplate);
    SET_SETTINGS(prefix + "djangotemplate", m_djangoTemplate);
    SET_SETTINGS(prefix + "enablefolding", m_enableFolding);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldhtml", m_foldHTML);
    SET_SETTINGS(prefix + "foldhtmlcomment", m_foldHTMLComment);
    SET_SETTINGS(prefix + "foldhtmlheredoc", m_foldHTMLHeredoc);
    SET_SETTINGS(prefix + "foldhtmlpreprocessor", m_foldHTMLPreprocessor);

    return true;
}

TP_END_NAMESPACE
