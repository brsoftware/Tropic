#ifndef TPFAMILYMASMLEXER_H
#define TPFAMILYMASMLEXER_H

#include <Lexers/TpFamilyASMLexer>

TP_NAMESPACE

class TpLexerMASM : public TpFamilyASMLexer
{
    Q_OBJECT

public:
    TpLexerMASM(QObject *parent = nullptr);
    virtual ~TpLexerMASM();

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;
};

TP_END_NAMESPACE

#endif // TPFAMILYMASMLEXER_H
