#ifndef TPFAMILYHTMLLEXER_H
#define TPFAMILYHTMLLEXER_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpFamilyHTMLLexer : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(int, aspDefaultLanguage);
    DEF_PROP(bool, caseSensitiveTags);
    DEF_PROP(bool, allowXMLScripts);
    DEF_PROP(bool, makoTemplate);
    DEF_PROP(bool, djangoTemplate);
    DEF_PROP(bool, enableFolding);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldHTML);
    DEF_PROP(bool, foldHTMLComment);
    DEF_PROP(bool, foldHTMLHeredoc);
    DEF_PROP(bool, foldHTMLPreprocessor);

public:
    enum
    {
        Default = 0,
        Tag = 1,
        UnknownTag = 2,
        Attribute = 3,
        UnknownAttribute = 4,
        HTMLNumber = 5,
        HTMLDoubleQuotedString = 6,
        HTMLSingleQuotedString = 7,
        OtherInTag = 8,
        HTMLComment = 9,
        Entity = 10,
        XMLTagEnd = 11,
        XMLStart = 12,
        XMLEnd = 13,
        Script = 14,
        ASPAtStart = 15,
        ASPStart = 16,
        CDATA = 17,
        PHPStart = 18,
        HTMLValue = 19,
        ASPXCComment = 20,
        SGMLDefault = 21,
        SGMLCommand = 22,
        SGMLParameter = 23,
        SGMLDoubleQuotedString = 24,
        SGMLSingleQuotedString = 25,
        SGMLError = 26,
        SGMLSpecial = 27,
        SGMLEntity = 28,
        SGMLComment = 29,
        SGMLParameterComment = 30,
        SGMLBlockDefault = 31,
        JavaScriptStart = 40,
        JavaScriptDefault = 41,
        JavaScriptComment = 42,
        JavaScriptCommentLine = 43,
        JavaScriptCommentDoc = 44,
        JavaScriptNumber = 45,
        JavaScriptWord = 46,
        JavaScriptKeyword = 47,
        JavaScriptDoubleQuotedString = 48,
        JavaScriptSingleQuotedString = 49,
        JavaScriptSymbol = 50,
        JavaScriptUnclosedString = 51,
        JavaScriptRegex = 52,
        ASPJavaScriptStart = 55,
        ASPJavaScriptDefault = 56,
        ASPJavaScriptComment = 57,
        ASPJavaScriptCommentLine = 58,
        ASPJavaScriptCommentDoc = 59,
        ASPJavaScriptNumber = 60,
        ASPJavaScriptWord = 61,
        ASPJavaScriptKeyword = 62,
        ASPJavaScriptDoubleQuotedString = 63,
        ASPJavaScriptSingleQuotedString = 64,
        ASPJavaScriptSymbol = 65,
        ASPJavaScriptUnclosedString = 66,
        ASPJavaScriptRegex = 67,
        VBScriptStart = 70,
        VBScriptDefault = 71,
        VBScriptComment = 72,
        VBScriptNumber = 73,
        VBScriptKeyword = 74,
        VBScriptString = 75,
        VBScriptIdentifier = 76,
        VBScriptUnclosedString = 77,
        ASPVBScriptStart = 80,
        ASPVBScriptDefault = 81,
        ASPVBScriptComment = 82,
        ASPVBScriptNumber = 83,
        ASPVBScriptKeyword = 84,
        ASPVBScriptString = 85,
        ASPVBScriptIdentifier = 86,
        ASPVBScriptUnclosedString = 87,
        PythonStart = 90,
        PythonDefault = 91,
        PythonComment = 92,
        PythonNumber = 93,
        PythonDoubleQuotedString = 94,
        PythonSingleQuotedString = 95,
        PythonKeyword = 96,
        PythonTripleSingleQuotedString = 97,
        PythonTripleDoubleQuotedString = 98,
        PythonClassName = 99,
        PythonFunctionMethodName = 100,
        PythonOperator = 101,
        PythonIdentifier = 102,
        ASPPythonStart = 105,
        ASPPythonDefault = 106,
        ASPPythonComment = 107,
        ASPPythonNumber = 108,
        ASPPythonDoubleQuotedString = 109,
        ASPPythonSingleQuotedString = 110,
        ASPPythonKeyword = 111,
        ASPPythonTripleSingleQuotedString = 112,
        ASPPythonTripleDoubleQuotedString = 113,
        ASPPythonClassName = 114,
        ASPPythonFunctionMethodName = 115,
        ASPPythonOperator = 116,
        ASPPythonIdentifier = 117,
        PHPDefault = 118,
        PHPDoubleQuotedString = 119,
        PHPSingleQuotedString = 120,
        PHPKeyword = 121,
        PHPNumber = 122,
        PHPVariable = 123,
        PHPComment = 124,
        PHPCommentLine = 125,
        PHPDoubleQuotedVariable = 126,
        PHPOperator = 127,
    };

    enum
    {
        PropAspDefaultLanguage,
        PropCaseSensitiveTags,
        PropAllowXMLScripts,
        PropMakoTemplate,
        PropDjangoTemplate,
        PropEnableFolding,
        PropFoldCompact,
        PropFoldHTML,
        PropFoldHTMLComment,
        PropFoldHTMLHeredoc,
        PropFoldHTMLPreprocessor,
    };

    enum
    {
        AspDefaultsJavaScript = 1,
        AspDefaultsVBScript = 2,
        AspDefaultsPython = 3,
    };

public:
    TpFamilyHTMLLexer(QObject *parent = nullptr);
    virtual ~TpFamilyHTMLLexer();

public:
    const char *language() const override;
    const char *lexer() const override;
    const char *autoCompletionFillups() const override;
    const char *wordCharacters() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
    QString description(int style) const override;
    void refreshProperties() override;

    void setLexerProperty(int prop, QVariant value) override;
    QVariant lexerProperty(int prop) const override;

protected:
    bool readProperties(QSettings &settings, const QString &prefix) override;
    bool writeProperties(QSettings &settings, const QString &prefix) const override;
};

TP_END_NAMESPACE

#endif // TPFAMILYHTMLLEXER_H
