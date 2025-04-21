#ifndef TPLEXERPERL_H
#define TPLEXERPERL_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerPerl : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, fold);
    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldPOD);
    DEF_PROP(bool, foldPackage);
    DEF_PROP(bool, foldAtElse);

public:
    enum
    {
        Default = 0,
        Error = 1,
        Comment = 2,
        POD = 3,
        Number = 4,
        Keyword = 5,
        DoubleQuotedString = 6,
        SingleQuotedString = 7,
        Operator = 10,
        Identifier = 11,
        Scalar = 12,
        Array = 13,
        Hash = 14,
        SymbolTable = 15,
        Regex = 17,
        Substitution = 18,
        Backticks = 20,
        DataSection = 21,
        HereDocumentDelimiter = 22,
        SingleQuotedHereDocument = 23,
        DoubleQuotedHereDocument = 24,
        BacktickHereDocument = 25,
        QuotedStringQ = 26,
        QuotedStringQQ = 27,
        QuotedStringQX = 28,
        QuotedStringQR = 29,
        QuotedStringQW = 30,
        PODVerbatim = 31,
        SubroutinePrototype = 40,
        FormatIdentifier = 41,
        FormatBody = 42,
        DoubleQuotedStringVar = 43,
        Translation = 44,
        RegexVar = 54,
        SubstitutionVar = 55,
        BackticksVar = 57,
        DoubleQuotedHereDocumentVar = 61,
        BacktickHereDocumentVar = 62,
        QuotedStringQQVar = 64,
        QuotedStringQXVar = 65,
        QuotedStringQRVar = 66,
    };

    enum
    {
        PropFold,
        PropFoldComments,
        PropFoldCompact,
        PropFoldPOD,
        PropFoldPackage,
        PropFoldAtElse,
    };

public:
    TpLexerPerl(QObject *parent = nullptr);
    virtual ~TpLexerPerl();

public:
    const char *language() const override;
    const char *lexer() const override;
    QStringList autoCompletionWordSeparators() const override;
    const char *blockEnd(int *style = nullptr) const override;
    const char *blockStart(int *style = nullptr) const override;
    int braceStyle() const override;
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

#endif // TPLEXERPERL_H
