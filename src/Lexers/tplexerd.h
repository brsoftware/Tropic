#ifndef TPLEXERD_H
#define TPLEXERD_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerD : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, fold);
    DEF_PROP(bool, foldSyntaxBased);
    DEF_PROP(bool, foldComment);
    DEF_PROP(bool, foldCommentMultiline);
    DEF_PROP(bool, foldCommentExplicit);
    DEF_PROP(QString, foldExplicitStart);
    DEF_PROP(QString, foldExplicitEnd);
    DEF_PROP(bool, foldExplicitAnywhere);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldAtElse);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        CommentLine = 2,
        CommentDoc = 3,
        CommentNested = 4,
        Number = 5,
        Keyword = 6,
        KeywordSecondary = 7,
        KeywordDoc = 8,
        Typedefs = 9,
        String = 10,
        UnclosedString = 11,
        Character = 12,
        Operator = 13,
        Identifier = 14,
        CommentLineDoc = 15,
        CommentDocKeyword = 16,
        CommentDocKeywordError = 17,
        BackquoteString = 18,
        RawString = 19,
        KeywordSet5 = 20,
        KeywordSet6 = 21,
        KeywordSet7 = 22,
    };

    enum
    {
        PropFold,
        PropFoldSyntaxBased,
        PropFoldComment,
        PropFoldCommentMultiline,
        PropFoldCommentExplicit,
        PropFoldExplicitStart,
        PropFoldExplicitEnd,
        PropFoldExplicitAnywhere,
        PropFoldCompact,
        PropFoldAtElse,
    };

public:
    TpLexerD(QObject *parent = nullptr);
    virtual ~TpLexerD();

public:
    const char *language() const override;
    const char *lexer() const override;
    QStringList autoCompletionWordSeparators() const override;
    const char *blockEnd(int *style = nullptr) const override;
    const char *blockStart(int *style = nullptr) const override;
    const char *blockStartKeyword(int *style = nullptr) const override;
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

#endif // TPLEXERD_H
