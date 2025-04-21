#ifndef TPLEXERC_H
#define TPLEXERC_H

#include <Lexers/TpFamilyCLexer>

TP_NAMESPACE

class TpLexerC : public TpFamilyCLexer
{
    Q_OBJECT

public:
    TpLexerC(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERC_H
