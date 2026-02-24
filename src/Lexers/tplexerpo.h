#ifndef TPLEXERPO_H
#define TPLEXERPO_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerPO : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        MessageId = 2,
        MessageIdText = 3,
        MessageString = 4,
        MessageStringText = 5,
        MessageContext = 6,
        MessageContextText = 7,
        Fuzzy = 8,
        ProgrammerComment = 9,
        Reference = 10,
        Flags = 11,
        MessageIdTextEOL = 12,
        MessageStringTextEOL = 13,
        MessageContextTextEOL = 14,
    };

    enum
    {
        PropFoldComments,
        PropFoldCompact,
    };

public:
    TpLexerPO(QObject *parent = nullptr);
    virtual ~TpLexerPO();

public:
    const char *language() const override;
    const char *lexer() const override;

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

#endif // TPLEXERPO_H
