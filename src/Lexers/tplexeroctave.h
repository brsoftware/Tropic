#ifndef TPLEXEROCTAVE_H
#define TPLEXEROCTAVE_H

#include <Lexers/TpFamilyMatlabLexer>

TP_NAMESPACE

class TpLexerOctave : public TpFamilyMatlabLexer
{
    Q_OBJECT

public:
    TpLexerOctave(QObject *parent = nullptr);

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

#endif // TPFAMILYMATLABLEXER_H
