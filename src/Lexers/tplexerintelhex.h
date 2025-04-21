#ifndef TPLEXERINTELHEX_H
#define TPLEXERINTELHEX_H

#include <Lexers/TpFamilyHexLexer>

TP_NAMESPACE

class TpLexerIntelHex : public TpFamilyHexLexer
{
    Q_OBJECT

public:
    TpLexerIntelHex(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERINTELHEX_H
