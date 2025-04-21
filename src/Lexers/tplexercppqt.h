#ifndef TPLEXERCPPQT_H
#define TPLEXERCPPQT_H

#include <Lexers/TpFamilyCLexer>

TP_NAMESPACE

class TpLexerCPPQt : public TpFamilyCLexer
{
    Q_OBJECT

public:
    TpLexerCPPQt(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERCPPQT_H
