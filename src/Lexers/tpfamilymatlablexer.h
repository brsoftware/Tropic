#ifndef TPFAMILYMATLABLEXER_H
#define TPFAMILYMATLABLEXER_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpFamilyMatlabLexer : public TpGeneralLexer
{
    Q_OBJECT

public:
    enum
    {
        Default = 0,
        Comment = 1,
        Command = 2,
        Number = 3,
        Keyword = 4,
        SingleQuotedString = 5,
        Operator = 6,
        Identifier = 7,
        DoubleQuotedString = 8,
    };

public:
    TpFamilyMatlabLexer(QObject *parent = nullptr);
    virtual ~TpFamilyMatlabLexer();

public:
    const char *language() const override;
    const char *lexer() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
    QString description(int style) const override;
};

TP_END_NAMESPACE

#endif // TPFAMILYMATLABLEXER_H
