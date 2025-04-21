#ifndef TPLEXERLATEX_H
#define TPLEXERLATEX_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerLaTeX : public TpGeneralLexer
{
    Q_OBJECT

public:
    enum
    {
        Default = 0,
        Command = 1,
        Tag = 2,
        Math = 3,
        Comment = 4,
        TagSet2 = 5,
        MathSet2 = 6,
        CommentSet2 = 7,
        VerbatimString = 8,
        ShortCommand = 9,
        Special = 10,
        CommandOption = 11,
        Error = 12,
    };

public:
    TpLexerLaTeX(QObject *parent = nullptr);
    virtual ~TpLexerLaTeX();

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

#endif // TPLEXERLATEX_H
