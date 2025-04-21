#ifndef TPLEXERPYTHON3_H
#define TPLEXERPYTHON3_H

#include <Lexers/TpFamilyPythonLexer>

TP_NAMESPACE

class TpLexerPython3 : public TpFamilyPythonLexer
{
    Q_OBJECT

public:
    TpLexerPython3(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERPYTHON3_H
