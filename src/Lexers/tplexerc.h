#ifndef TPLEXERC_H
#define TPLEXERC_H

#include <Lexers/TpFamilyCLexer>

TP_NAMESPACE

inline const char *lexerCKeyword1 =
"_Alignof _Generic _Static_assert alignof and and_eq bitand bitor break case compl continue default do else false for "
"goto if not not_eq NULL offsetof or or_eq return sizeof switch true typedef while xor xor_eq";

inline const char *lexerCKeyword2 =
"void struct union enum char short int long double float signed unsigned const static extern auto register volatile "
"restrict _Atomic bool _Bool complex _Complex imaginary _Imaginary inline noreturn _Noreturn alignas _Alignas "
"thread_local _Thread_local uint8_t uint16_t uint32_t uint64_t int8_t int16_t int32_t int64_t uint_least8_t "
"uint_least16_t uint_least32_t uint_least64_t int_least8_t int_least16_t int_least32_t int_least64_t uint_fast8_t "
"uint_fast16_t uint_fast32_t uint_fast64_t int_fast8_t int_fast16_t int_fast32_t int_fast64_t uintptr_t intptr_t "
"uintmax_t intmax_t ptrdiff_t max_align_t div_t ldiv_t lldiv_t imaxdiv_t size_t time_t clock_t wchar_t char16_t "
"char32_t sig_atomic_t FILE";

class TpLexerC : public TpFamilyCLexer
{
    Q_OBJECT

public:
    TpLexerC(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERC_H
