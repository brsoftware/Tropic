#ifndef TPLEXERDIFF_H
#define TPLEXERDIFF_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerDiff : public TpGeneralLexer
{
    Q_OBJECT

public:
    enum
    {
        Default = 0,
        Comment = 1,
        Command = 2,
        Header = 3,
        Position = 4,
        LineRemoved = 5,
        LineAdded = 6,
        LineChanged = 7,
        AddingPatchAdded = 8,
        RemovingPatchAdded = 9,
        AddingPatchRemoved = 10,
        RemovingPatchRemoved = 11,
    };

public:
    TpLexerDiff(QObject *parent = nullptr);
    virtual ~TpLexerDiff();

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

#endif // TPLEXERDIFF_H
