#ifndef TPLEXERYAML_H
#define TPLEXERYAML_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerYAML : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        Identifier = 2,
        Keyword = 3,
        Number = 4,
        Reference = 5,
        DocumentDelimiter = 6,
        TextBlockMarker = 7,
        SyntaxErrorMarker = 8,
        Operator = 9,
    };

    enum
    {
        PropFoldComments,
    };

public:
    TpLexerYAML(QObject *parent = nullptr);
    virtual ~TpLexerYAML();

public:
    const char *language() const override;
    const char *lexer() const override;

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

#endif // TPLEXERYAML_H
