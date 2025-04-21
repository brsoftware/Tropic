#ifndef TPLEXERRUBY_H
#define TPLEXERRUBY_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerRuby : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);

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
        ClassName = 8,
        FunctionMethodName = 9,
        Operator = 10,
        Identifier = 11,
        Regex = 12,
        Global = 13,
        Symbol = 14,
        ModuleName = 15,
        InstanceVariable = 16,
        ClassVariable = 17,
        Backticks = 18,
        DataSection = 19,
        HereDocumentDelimiter = 20,
        HereDocument = 21,
        PercentStringq = 24,
        PercentStringQ = 25,
        PercentStringx = 26,
        PercentStringr = 27,
        PercentStringw = 28,
        DemotedKeyword = 29,
        Stdin = 30,
        Stdout = 31,
        Stderr = 40,
    };

    enum
    {
        PropFoldComments,
        PropFoldCompact,
    };

public:
    TpLexerRuby(QObject *parent = nullptr);
    virtual ~TpLexerRuby();

public:
    const char *language() const override;
    const char *lexer() const override;

    const char *blockEnd(int *style = nullptr) const override;
    const char *blockStart(int *style = nullptr) const override;
    const char *blockStartKeyword(int *style = nullptr) const override;
    int braceStyle() const override;

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

#endif // TPLEXERRUBY_H
