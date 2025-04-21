#ifndef TPLEXERGDSCRIPT_H
#define TPLEXERGDSCRIPT_H

#include <Lexers/TpFamilyPythonLexer>

TP_NAMESPACE

class TpLexerGDScript : public TpFamilyPythonLexer
{
    Q_OBJECT

public:
    TpLexerGDScript(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERGDSCRIPT_H
