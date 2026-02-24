#ifndef TPLEXERJAVA_H
#define TPLEXERJAVA_H

#include <Lexers/TpFamilyCLexer>

TP_NAMESPACE

inline const char *lexerJavaKeyword1 =
"abstract assert boolean break byte case catch char class const continue default do double else enum extends final "
"finally float for goto if implements import instanceof int interface long native new package private protected public "
"return short static strictfp super switch synchronized this throw throws transient try void volatile while";

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
