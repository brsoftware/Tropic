#ifndef TPLEXERTEKTRONIXHEX_H
#define TPLEXERTEKTRONIXHEX_H

#include <Lexers/TpFamilyHexLexer>

TP_NAMESPACE

class TpLexerTektronixHex : public TpFamilyHexLexer
{
    Q_OBJECT

public:
    TpLexerTektronixHex(QObject *parent = nullptr);

public:
    const char *language() const override;
    const char *lexer() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERTEKTRONIXHEX_H
