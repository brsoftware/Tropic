#ifndef TPLEXERCMAKE_H
#define TPLEXERCMAKE_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerCMake : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldAtElse);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        String = 2,
        StringLeftQuote = 3,
        StringRightQuote = 4,
        Function = 5,
        Variable = 6,
        Label = 7,
        KeywordSet3 = 8,
        BlockWhile = 9,
        BlockForeach = 10,
        BlockIf = 11,
        BlockMacro = 12,
        StringVariable = 13,
        Number = 14
    };

    enum
    {
        PropFoldAtElse,
    };

public:
    TpLexerCMake(QObject *parent = nullptr);
    virtual ~TpLexerCMake();

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

#endif // TPLEXERCMAKE_H
