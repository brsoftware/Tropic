#ifndef TPFAMILYBASICLEXER_H
#define TPFAMILYBASICLEXER_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpFamilyBasicLexer : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, fold);
    DEF_PROP(bool, foldSyntaxBased);
    DEF_PROP(bool, foldCommentExplicit);
    DEF_PROP(QString, foldExplicitStart);
    DEF_PROP(QString, foldExplicitEnd);
    DEF_PROP(bool, foldExplicitAnywhere);
    DEF_PROP(bool, foldCompact);

protected:
    DEF_PROP(int, mode);

public:
    enum
    {
        BlitzBasic,
        PureBasic,
        FreeBasic,
    };

    enum
    {
        Default = 0,
        Comment = 1,
        Number = 2,
        Keyword = 3,
        String = 4,
        PreProcessor = 5,
        Operator = 6,
        Identifier = 7,
        Date = 8,
        StringEol = 9,
        KeywordSet2 = 10,
        KeywordSet3 = 11,
        KeywordSet4 = 12,
        Constant = 13,
        Asm = 14,
        Label = 15,
        Error = 16,
        HexNumber = 17,
        BinaryNumber = 18,
        CommentBlock = 19,
        DocLine = 20,
        DocBlock = 21,
        DocKeyword = 22,
    };

    enum
    {
        PropMode,
        PropFold,
        PropFoldSyntaxBased,
        PropFoldCommentExplicit,
        PropFoldExplicitStart,
        PropFoldExplicitEnd,
        PropFoldExplicitAnywhere,
        PropFoldCompact,
    };

public:
    TpFamilyBasicLexer(QObject *parent = nullptr);
    ~TpFamilyBasicLexer();

public:
    const char *language() const override;
    const char *lexer() const override;
    QStringList autoCompletionWordSeparators() const override;
    const char *blockStartKeyword(int *style = nullptr) const override;
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

#endif // TPFAMILYBASICLEXER_H
