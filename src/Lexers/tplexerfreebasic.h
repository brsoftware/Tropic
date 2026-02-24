#ifndef TPLEXERFREEBASIC_H
#define TPLEXERFREEBASIC_H

#include <Lexers/TpFamilyBasicLexer>

TP_NAMESPACE

inline const char *lexerFreeBasicKeyword1 =
"append as asc asin asm atan2 atn beep bin binary bit bitreset bitset bload bsave byref byte byval call callocate case "
"cbyte cdbl cdecl chain chdir chr cint circle clear clng clngint close cls color command common cons const continue "
"cos cshort csign csng csrlin cubyte cuint culngint cunsg curdir cushort custom cvd cvi cvl cvlongint cvs cvshort data "
"date deallocate declare defbyte defdbl defined defint deflng deflngint defshort defsng defstr defubyte defuint "
"defulngint defushort dim dir do double draw dylibload dylibsymbol else elseif end enum environ environ$ eof eqv erase "
"err error exec exepath exit exp export extern field fix flip for fre freefile function get getjoystick getkey "
"getmouse gosub goto hex hibyte hiword if iif imagecreate imagedestroy imp inkey inp input instr int integer is kill "
"lbound lcase left len let lib line lobyte loc local locate lock lof log long longint loop loword lset ltrim mid mkd "
"mkdir mki mkl mklongint mks mkshort mod multikey mutexcreate mutexdestroy mutexlock mutexunlock name next not oct on "
"once open option or out output overload paint palette pascal pcopy peek peeki peeks pipe pmap point pointer poke "
"pokei pokes pos preserve preset print private procptr pset ptr public put random randomize read reallocate redim rem "
"reset restore resume resume next return rgb rgba right rmdir rnd rset rtrim run sadd screen screencopy screeninfo "
"screenlock screenptr screenres screenset screensync screenunlock seek statement seek function selectcase setdate "
"setenviron setmouse settime sgn shared shell shl short shr sin single sizeof sleep space spc sqr static stdcall step "
"stop str string string strptr sub swap system tab tan then threadcreate threadwait time time timer to trans trim type "
"ubound ubyte ucase uinteger ulongint union unlock unsigned until ushort using va_arg va_first va_next val val64 "
"valint varptr view viewprint wait wend while width window windowtitle with write xor zstring";

class TpLexerFreeBasic : public TpFamilyBasicLexer
{
    Q_OBJECT

public:
    TpLexerFreeBasic(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERFREEBASIC_H
