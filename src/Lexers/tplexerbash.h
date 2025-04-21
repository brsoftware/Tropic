#ifndef TPLEXERBASH_H
#define TPLEXERBASH_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerBash : public TpGeneralLexer
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
        Number = 3,
        Keyword = 4,
        DoubleQuotedString = 5,
        SingleQuotedString = 6,
        Operator = 7,
        Identifier = 8,
        Scalar = 9,
        ParameterExpansion = 10,
        Backticks = 11,
        HereDocumentDelimiter = 12,
        SingleQuotedHereDocument = 13,
    };

    enum
    {
        PropFoldComments,
        PropFoldCompact,
    };

public:
    TpLexerBash(QObject *parent = nullptr);
    virtual ~TpLexerBash();

public:
    const char *language() const override;
    const char *lexer() const override;
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

#endif // TPLEXERBASH_H
