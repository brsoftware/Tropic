#ifndef TPLEXERPUREBASIC_H
#define TPLEXERPUREBASIC_H

#include <Lexers/TpFamilyBasicLexer>

TP_NAMESPACE

class TpLexerPureBasic : public TpFamilyBasicLexer
{
    Q_OBJECT

public:
    TpLexerPureBasic(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERPUREBASIC_H
