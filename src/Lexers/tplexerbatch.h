#ifndef TPLEXERBATCH_H
#define TPLEXERBATCH_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerBatchKeyword1 =
"rem set if exist errorlevel for in do break call chcp cd chdir choice cls country ctty date del erase dir echo exit "
"goto loadfix loadhigh mkdir md move path pause prompt rename ren rmdir rd shift time type ver verify vol com con lpt "
"nul";

class TpLexerBatch : public TpGeneralLexer
{
    Q_OBJECT

public:
    enum
    {
        Default = 0,
        Comment = 1,
        Keyword = 2,
        Label = 3,
        HideCommandChar = 4,
        ExternalCommand = 5,
        Variable = 6,
        Operator = 7
    };

public:
    TpLexerBatch(QObject *parent = nullptr);
    virtual ~TpLexerBatch();

public:
    const char *language() const override;
    const char *lexer() const override;
    const char *wordCharacters() const override;
    bool caseSensitive() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
    QString description(int style) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERBATCH_H
