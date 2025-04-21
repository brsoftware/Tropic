#ifndef TPLEXERCPP_H
#define TPLEXERCPP_H

#include <Lexers/TpFamilyCLexer>

TP_NAMESPACE

class TpLexerCPP : public TpFamilyCLexer
{
    Q_OBJECT

public:
    TpLexerCPP(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERCPP_H
