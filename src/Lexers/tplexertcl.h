#ifndef TPLEXERTCL_H
#define TPLEXERTCL_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerTCL : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        CommentLine = 2,
        Number = 3,
        QuotedKeyword = 4,
        QuotedString = 5,
        Operator = 6,
        Identifier = 7,
        Substitution = 8,
        SubstitutionBrace = 9,
        Modifier = 10,
        ExpandKeyword = 11,
        TCLKeyword = 12,
        TkKeyword = 13,
        ITCLKeyword = 14,
        TkCommand = 15,
        KeywordSet6 = 16,
        KeywordSet7 = 17,
        KeywordSet8 = 18,
        KeywordSet9 = 19,
        CommentBox = 20,
        CommentBlock = 21,
    };

    enum
    {
        PropFoldComments,
    };

public:
    TpLexerTCL(QObject *parent = nullptr);
    virtual ~TpLexerTCL();

public:
    const char *language() const override;
    const char *lexer() const override;
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

#endif // TPLEXERTCL_H
