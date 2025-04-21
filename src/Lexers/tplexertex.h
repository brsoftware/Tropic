#ifndef TPLEXERTEX_H
#define TPLEXERTEX_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerTeX : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, processComments);
    DEF_PROP(bool, processIf);

public:
    enum
    {
        Default = 0,
        Special = 1,
        Group = 2,
        Symbol = 3,
        Command = 4,
        Text = 5,
    };

    enum
    {
        PropFoldComments,
        PropFoldCompact,
        PropProcessComments,
        PropProcessIf,
    };

public:
    TpLexerTeX(QObject *parent = nullptr);
    virtual ~TpLexerTeX();

public:
    const char *language() const override;
    const char *lexer() const override;
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

#endif // TPLEXERTEX_H
