#ifndef TPLEXERLUA_H
#define TPLEXERLUA_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerLua : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldCompact);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        CommentLine = 2,
        CommentDoc = 3,
        Number = 4,
        Keyword = 5,
        String = 6,
        Character = 7,
        LiteralString = 8,
        Preprocessor = 9,
        Operator = 10,
        Identifier = 11,
        UnclosedString = 12,
        BasicFunctions = 13,
        StringTableMathsFunctions = 14,
        CoroutinesIOSystemFacilities = 15,
        KeywordSet5 = 16,
        KeywordSet6 = 17,
        KeywordSet7 = 18,
        KeywordSet8 = 19,
        Label = 20,
    };

    enum
    {
        PropFoldCompact,
    };

public:
    TpLexerLua(QObject *parent = nullptr);
    virtual ~TpLexerLua();

public:
    const char *language() const override;
    const char *lexer() const override;
    QStringList autoCompletionWordSeparators() const override;
    const char *blockStart(int *style = nullptr) const override;
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

#endif // TPLEXERLUA_H
