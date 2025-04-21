#ifndef TPLEXERSRECORD_H
#define TPLEXERSRECORD_H

#include <Lexers/TpFamilyHexLexer>

TP_NAMESPACE

class TpLexerSRecord : public TpFamilyHexLexer
{
    Q_OBJECT

public:
    TpLexerSRecord(QObject *parent = nullptr);

public:
    const char *language() const override;
    const char *lexer() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERSRECORD_H
