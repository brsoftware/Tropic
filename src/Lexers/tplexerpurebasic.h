#ifndef TPLEXERPUREBASIC_H
#define TPLEXERPUREBASIC_H

#include <Lexers/TpFamilyBasicLexer>

TP_NAMESPACE

inline const char *lexerPureBasicKeyword1 =
"and break case continue data datasection declare declarecdll declaredll default deftype dim else elseif end "
"enddatasection endenumeration endif endinterface endprocedure endselect endstructure endstructureunion enumeration "
"extends fakereturn for foreach forever global gosub goto if includebinary includefile includepath interface newlist "
"next or procedure procedurecdll proceduredll procedurereturn protected read repeat restore return select shared "
"static step structure structureunion to until wend while xincludefile";

class TpLexerPureBasic : public TpFamilyBasicLexer
{
    Q_OBJECT

public:
    TpLexerPureBasic(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERPUREBASIC_H
