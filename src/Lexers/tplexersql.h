#ifndef TPLEXERSQL_H
#define TPLEXERSQL_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerSQL : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, fold);
    DEF_PROP(bool, foldAtElse);
    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldOnlyBegin);
    DEF_PROP(bool, backticksIdentifier);
    DEF_PROP(bool, numbersignComment);
    DEF_PROP(bool, backslashEscapes);
    DEF_PROP(bool, allowDottedWord);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        CommentLine = 2,
        CommentDoc = 3,
        Number = 4,
        Keyword = 5,
        DoubleQuotedString = 6,
        SingleQuotedString = 7,
        PlusKeyword = 8,
        PlusPrompt = 9,
        Operator = 10,
        Identifier = 11,
        PlusComment = 13,
        CommentLineHash = 15,
        CommentDocKeyword = 17,
        CommentDocKeywordError = 18,
        KeywordSet5 = 19,
        KeywordSet6 = 20,
        KeywordSet7 = 21,
        KeywordSet8 = 22,
        QuotedIdentifier = 23,
        QuotedOperator = 24,
    };

    enum
    {
        PropFold,
        PropFoldAtElse,
        PropFoldComments,
        PropFoldCompact,
        PropFoldOnlyBegin,
        PropBackticksIdentifier,
        PropNumbersignComment,
        PropBackslashEscapes,
        PropAllowDottedWord,
    };

public:
    TpLexerSQL(QObject *parent = nullptr);
    virtual ~TpLexerSQL();

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

#endif // TPLEXERSQL_H
