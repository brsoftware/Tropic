#ifndef TPLEXERNONE_H
#define TPLEXERNONE_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerNone : public TpGeneralLexer
{
    Q_OBJECT

public:
    TpLexerNone(QObject *parent = nullptr);
    virtual ~TpLexerNone();

public:
    const char *language() const override;
    const char *lexer() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    QString description(int style) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERNONE_H
