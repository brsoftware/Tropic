#ifndef TPLEXERHTML_H
#define TPLEXERHTML_H

#include <Lexers/TpFamilyHTMLLexer>

TP_NAMESPACE

class TpLexerHTML : public TpFamilyHTMLLexer
{
    Q_OBJECT

public:
    TpLexerHTML(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERHTML_H
