#ifndef TPLEXERJAVA_H
#define TPLEXERJAVA_H

#include <Lexers/TpFamilyCLexer>

TP_NAMESPACE

class TpLexerJava : public TpFamilyCLexer
{
    Q_OBJECT

public:
    TpLexerJava(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERJava_H
