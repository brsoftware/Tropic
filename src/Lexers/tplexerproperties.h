#ifndef TPLEXERPROPERTIES_H
#define TPLEXERPROPERTIES_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerProperties : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, initialSpaces);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        Section = 2,
        Assignment = 3,
        DefaultValue = 4,
        Key = 5,
    };

    enum
    {
        PropFoldCompact,
        PropInitialSpaces
    };

public:
    TpLexerProperties(QObject *parent = nullptr);
    virtual ~TpLexerProperties();

public:
    const char *language() const override;
    const char *lexer() const override;
    const char *wordCharacters() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    QString description(int style) const override;

    void refreshProperties() override;

    void setLexerProperty(int prop, QVariant value) override;
    QVariant lexerProperty(int prop) const override;

protected:
    bool readProperties(QSettings &settings, const QString &prefix) override;
    bool writeProperties(QSettings &settings, const QString &prefix) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERPROPERTIES_H
