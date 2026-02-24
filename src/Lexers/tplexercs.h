#ifndef TPLEXERCS_H
#define TPLEXERCS_H

#include <Lexers/TpFamilyCLexer>

TP_NAMESPACE

inline const char *lexerCSKeyword1 =
"abstract add alias as ascending async await base break case catch checked continue default delegate descending do "
"dynamic else event explicit extern false finally fixed for foreach from get global goto group if implicit in "
"interface internal into is join let lock nameof namespace new null object operator orderby out override params "
"partial private protected public readonly ref remove return sealed select set sizeof stackalloc switch this throw "
"true try typeof unchecked unsafe using value virtual when where while yield";

inline const char *lexerCSKeyword2 =
"bool byte char class const decimal double enum float int long nint nuint sbyte short static string struct uint ulong "
"ushort var void";

class TpLexerCS : public TpFamilyCLexer
{
    Q_OBJECT

public:
    TpLexerCS(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERCS_H
