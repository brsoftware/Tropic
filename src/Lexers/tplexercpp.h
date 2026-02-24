#ifndef TPLEXERCPP_H
#define TPLEXERCPP_H

#include <Lexers/TpFamilyCLexer>

TP_NAMESPACE

inline const char *lexerCPPKeyword1 =
"alignof and and_eq atomic_cancel atomic_commit atomic_noexcept bitand bitor break case catch co_await co_return "
"co_yield compl const_cast continue default delete do dynamic_cast else false for goto if namespace new not not_eq "
"nullptr operator or or_eq reflexpr reinterpret_cast return sizeof static_assert static_cast switch synchronized this "
"throw true try typedef typeid using while xor xor_eq NULL";

inline const char *lexerCPPKeyword2 =
"alignas asm auto bool char char8_t char16_t char32_t class clock_t concept const consteval constexpr constinit "
"decltype double enum explicit export extern final float friend inline int int8_t int16_t int32_t int64_t int_fast8_t "
"int_fast16_t int_fast32_t int_fast64_t int_least8_t int_least16_t int_least32_t int_least64_t intmax_t intptr_t long "
"mutable noexcept override private protected ptrdiff_t public register requires short signed size_t ssize_t static "
"struct template thread_local time_t typename uint8_t uint16_t uint32_t uint64_t uint_fast8_t uint_fast16_t "
"uint_fast32_t uint_fast64_t uint_least8_t uint_least16_t uint_least32_t uint_least64_t uintmax_t uintptr_t union "
"unsigned virtual void volatile wchar_t";

class TpLexerCPP : public TpFamilyCLexer
{
    Q_OBJECT

public:
    TpLexerCPP(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERCPP_H
