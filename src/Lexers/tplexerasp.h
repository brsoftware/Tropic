#ifndef TPLEXERASP_H
#define TPLEXERASP_H

#include <Lexers/TpFamilyHTMLLexer>

TP_NAMESPACE

class TpLexerASP : public TpFamilyHTMLLexer
{
    Q_OBJECT

public:
    TpLexerASP(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERASP_H
