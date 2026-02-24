#ifndef TPLEXERFORTRAN77_H
#define TPLEXERFORTRAN77_H

#include <Lexers/TpFamilyFortranLexer>

TP_NAMESPACE

inline const char *lexerFortran77Keyword1 =
"access action advance allocatable allocate apostrophe assign assignment associate asynchronous backspace bind blank "
"blockdata call case character class close common complex contains continue cycle data deallocate decimal delim "
"default dimension direct do dowhile double doubleprecision else elseif elsewhere encoding end endassociate "
"endblockdata enddo endfile endforall endfunction endif endinterface endmodule endprogram endselect endsubroutine "
"endtype endwhere entry eor equivalence err errmsg exist exit external file flush fmt forall form format formatted "
"function go goto id if implicit in include inout integer inquire intent interface intrinsic iomsg iolength iostat "
"kind len logical module name named namelist nextrec nml none nullify number only open opened operator optional out "
"pad parameter pass pause pending pointer pos position precision print private program protected public quote read "
"readwrite real rec recl recursive result return rewind save select selectcase selecttype sequential sign size stat "
"status stop stream subroutine target then to type unformatted unit use value volatile wait where while write";


class TpLexerFortran77 : public TpFamilyFortranLexer
{
    Q_OBJECT

public:
    TpLexerFortran77(QObject *parent = nullptr);

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

#endif // TPLEXERFORTRAN77_H
