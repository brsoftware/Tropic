#ifndef TPFAMILYNASMLEXER_H
#define TPFAMILYNASMLEXER_H

#include <Lexers/TpFamilyASMLexer>

TP_NAMESPACE

class TpLexerNASM : public TpFamilyASMLexer
{
    Q_OBJECT

public:
    TpLexerNASM(QObject *parent = nullptr);
    virtual ~TpLexerNASM();

public:
    const char *language() const override;
    const char *lexer() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;
};

TP_END_NAMESPACE

#endif // TPFAMILYNASMLEXER_H
