#ifndef TPLEXERQSS_H
#define TPLEXERQSS_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerQSS : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldComments);

public:
    enum
    {
        Default = 0,
        QtType = 1,
        QtClass = 2,
        PseudoQtClass = 3,
        UnknownPseudoQtClass = 4,
        Operator = 5,
        ObsoleteProperty = 6,
        UnknownProperty = 7,
        Value = 8,
        Comment = 9,
        QtIDSelector = 10,
        Important = 11,
        AtRule = 12,
        DoubleQuotedString = 13,
        SingleQuotedString = 14,
        Property = 15,
        Attribute = 16,
        ExperimentalProperty = 17,
        PseudoQtElement = 18,
        SpecificProperty = 19,
        SpecificPseudoQtClass = 20,
        SpecificPseudoQtElement = 21,
        MediaRule = 22,
        Variable = 23,
    };

    enum
    {
        PropFoldCompact,
        PropFoldComments,
    };

public:
    TpLexerQSS(QObject *parent = nullptr);
    virtual ~TpLexerQSS();

public:
    int autoIndentStyle();

    const char *language() const override;
    const char *lexer() const override;
    const char *blockEnd(int *style = nullptr) const override;
    const char *blockStart(int *style = nullptr) const override;
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

#endif // TPLEXERQSS_H
