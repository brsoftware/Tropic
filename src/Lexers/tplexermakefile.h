#ifndef TPLEXERMAKEFILE_H
#define TPLEXERMAKEFILE_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerMakefile : public TpGeneralLexer
{
    Q_OBJECT

public:
    enum
    {
        Default = 0,
        Comment = 1,
        Preprocessor = 2,
        Variable = 3,
        Operator = 4,
        Target = 5,
        Error = 9,
    };

public:
    TpLexerMakefile(QObject *parent = nullptr);
    virtual ~TpLexerMakefile();

public:
    const char *language() const override;
    const char *lexer() const override;
    const char *wordCharacters() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    QString description(int style) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERMAKEFILE_H
