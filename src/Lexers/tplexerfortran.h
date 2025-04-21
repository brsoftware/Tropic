#ifndef TPLEXERFORTRAN_H
#define TPLEXERFORTRAN_H

#include <Lexers/TpFamilyFortranLexer>

TP_NAMESPACE

class TpLexerFortran : public TpFamilyFortranLexer
{
    Q_OBJECT

public:
    TpLexerFortran(QObject *parent = nullptr);

public:
    const char *language() const override;
    const char *lexer() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERFORTRAN_H
