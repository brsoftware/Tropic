#ifndef TPLEXERPOSTSCRIPT_H
#define TPLEXERPOSTSCRIPT_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerPostScript : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, tokenize);
    DEF_PROP(int, level);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldAtElse);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        DSCComment = 2,
        DSCCommentValue = 3,
        Number = 4,
        Name = 5,
        Keyword = 6,
        Literal = 7,
        ImmediateEvalLiteral = 8,
        ArrayParenthesis = 9,
        DictionaryParenthesis = 10,
        ProcedureParenthesis = 11,
        Text = 12,
        HexString = 13,
        Base85String = 14,
        BadStringCharacter = 15,
    };

    enum
    {
        PropTokenize,
        PropLevel,
        PropFoldCompact,
        PropFoldAtElse,
    };

    enum
    {
        PSFirstLevel = 1,
        PSSecondLevel = 2,
        PSThirdLevel = 3,
    };

public:
    TpLexerPostScript(QObject *parent = nullptr);
    virtual ~TpLexerPostScript();

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

#endif // TPLEXERPOSTSCRIPT_H
