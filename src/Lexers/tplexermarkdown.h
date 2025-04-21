#ifndef TPLEXERMARKDOWN_H
#define TPLEXERMARKDOWN_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerMarkdown : public TpGeneralLexer
{
    Q_OBJECT

public:
    enum
    {
        Default = 0,
        Special = 1,
        StrongEmphasisAsterisks = 2,
        StrongEmphasisUnderscores = 3,
        EmphasisAsterisks = 4,
        EmphasisUnderscores = 5,
        Header1 = 6,
        Header2 = 7,
        Header3 = 8,
        Header4 = 9,
        Header5 = 10,
        Header6 = 11,
        Prechar = 12,
        UnorderedListItem = 13,
        OrderedListItem = 14,
        BlockQuote = 15,
        StrikeOut = 16,
        HorizontalRule = 17,
        Link = 18,
        CodeBackticks = 19,
        CodeDoubleBackticks = 20,
        CodeBlock = 21,
    };

public:
    TpLexerMarkdown(QObject *parnet = nullptr);
    virtual ~TpLexerMarkdown();

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

#endif // TPLEXERMARKDOWN_H
