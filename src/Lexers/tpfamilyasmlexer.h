#ifndef TPFAMILYASMLEXER_H
#define TPFAMILYASMLEXER_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpFamilyASMLexer : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(QChar, commentDelimiter);
    DEF_PROP(bool, foldSyntaxBased);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        Number = 2,
        DoubleQuotedString = 3,
        Operator = 4,
        Identifier = 5,
        CPUInstruction = 6,
        FPUInstruction = 7,
        Register = 8,
        Directive = 9,
        DirectiveOperand = 11,
        BlockComment = 12,
        SingleQuotedString = 13,
        UnclosedString = 14,
        ExtendedInstruction = 15,
        CommentDirective = 16,
    };

    enum
    {
        PropFoldComments,
        PropFoldCompact,
        PropCommentDelimiter,
        PropFoldSyntaxBased,
    };

public:
    TpFamilyASMLexer(QObject *parent = nullptr);
    virtual ~TpFamilyASMLexer();

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

#endif // TPFAMILYASMLEXER_H
