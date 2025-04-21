#ifndef TPLEXERSPICE_H
#define TPLEXERSPICE_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerSpice : public TpGeneralLexer
{
    Q_OBJECT

public:
    enum
    {
        Default = 0,
        Identifier = 1,
        Command = 2,
        Function = 3,
        Parameter = 4,
        Number = 5,
        Delimiter = 6,
        Value = 7,
        Comment = 8,
    };

public:
    TpLexerSpice(QObject *parent = nullptr);
    virtual ~TpLexerSpice();

public:
    const char *language() const override;
    const char *lexer() const override;
    int braceStyle() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
    QString description(int style) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERSPICE_H
