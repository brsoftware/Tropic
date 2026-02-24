#ifndef TPLEXEROCTAVE_H
#define TPLEXEROCTAVE_H

#include <Lexers/TpFamilyMatlabLexer>

TP_NAMESPACE

inline const char *lexerOctaveKeyword1 =
"__FILE__ __LINE__ break case catch classdef continue do else elseif end end_try_catch end_unwind_protect endclassdef "
"endenumeration endevents endfor endfunction endif endmethods endparfor endproperties endswitch endwhile enumeration "
"events for function get global if methods otherwise parfor persistent properties return set static switch try until "
"unwind_protect unwind_protect_cleanup while";

class TpLexerOctave : public TpFamilyMatlabLexer
{
    Q_OBJECT

public:
    TpLexerOctave(QObject *parent = nullptr);

public:
    const char *language() const override;
    const char *lexer() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPFAMILYMATLABLEXER_H
