#ifndef TPLEXERFORTRAN77_H
#define TPLEXERFORTRAN77_H

#include <Lexers/TpFamilyFortranLexer>

TP_NAMESPACE

class TpLexerFortran77 : public TpFamilyFortranLexer
{
    Q_OBJECT

public:
    TpLexerFortran77(QObject *parent = nullptr);

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

#endif // TPLEXERFORTRAN77_H
