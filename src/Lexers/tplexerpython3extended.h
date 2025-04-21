#ifndef TPLEXERPYTHON3EXTENDED_H
#define TPLEXERPYTHON3EXTENDED_H

#include <Lexers/TpFamilyPythonLexer>

TP_NAMESPACE

class TpLexerPython3Extended : public TpFamilyPythonLexer
{
    Q_OBJECT

public:
    TpLexerPython3Extended(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERPYTHON3EXTENDED_H
