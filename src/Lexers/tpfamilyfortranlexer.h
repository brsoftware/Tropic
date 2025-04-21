#ifndef TPFAMILYFORTRANLEXER_H
#define TPFAMILYFORTRANLEXER_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpFamilyFortranLexer : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        Number = 2,
        SingleQuotedString = 3,
        DoubleQuotedString = 4,
        UnclosedString = 5,
        Operator = 6,
        Identifier = 7,
        Keyword = 8,
        IntrinsicFunction = 9,
        ExtendedFunction = 10,
        PreProcessor = 11,
        DottedOperator = 12,
        Label = 13,
        Continuation = 14,
    };

    enum
    {
        PropFoldComments,
        PropFoldCompact,
    };

public:
    TpFamilyFortranLexer(QObject *parent = nullptr);
    virtual ~TpFamilyFortranLexer();

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

#endif // TPFAMILYFORTRANLEXER_H
