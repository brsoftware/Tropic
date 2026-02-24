#ifndef TPLEXERMATLAB_H
#define TPLEXERMATLAB_H

#include <Lexers/TpFamilyMatlabLexer>

TP_NAMESPACE

class TpLexerMatlab : public TpFamilyMatlabLexer
{
    Q_OBJECT

public:
    TpLexerMatlab(QObject *parent = nullptr);

public:
    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;
};

TP_END_NAMESPACE

#endif // TPFAMILYMATLABLEXER_H
