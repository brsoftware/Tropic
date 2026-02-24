#ifndef TPLEXERVHDL_H
#define TPLEXERVHDL_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerVHDLKeyword1 =
"access after alias all architecture array assert attribute begin block body buffer bus case component configuration "
"constant disconnect downto else elsif end entity exit file for function generate generic group guarded if impure in "
"inertial inout is label library linkage literal loop map new next null of on open others out package port postponed "
"procedure process pure range record register reject report return select severity shared signal subtype then to "
"transport type unaffected units until use variable wait when while with";

inline const char *lexerVHDLKeyword2 =
"abs and mod nand nor not or rem rol ror sla sll sra srl xnor xor";

inline const char *lexerVHDLKeyword3 =
"left right low high ascending image value pos val succ pred leftof rightof base range reverse_range length delayed "
"stable quiet transaction event active last_event last_active last_value driving driving_value simple_name path_name "
"instance_name";

inline const char *lexerVHDLKeyword4 =
"now readline read writeline write endfile resolved to_bit to_bitvector to_stdulogic to_stdlogicvector "
"to_stdulogicvector to_x01 to_x01z to_UX01 rising_edge falling_edge is_x shift_left shift_right rotate_left "
"rotate_right resize to_integer to_unsigned to_signed std_match to_01";

inline const char *lexerVHDLKeyword5 =
"std ieee work standard textio std_logic_1164 std_logic_arith std_logic_misc std_logic_signed std_logic_textio "
"std_logic_unsigned numeric_bit numeric_std math_complex math_real vital_primitives vital_timing";

inline const char *lexerVHDLKeyword6 =
"boolean bit character severity_level integer real time delay_length natural positive string bit_vector file_open_kind "
"file_open_status line text side width std_ulogic std_ulogic_vector std_logic std_logic_vector X01 X01Z UX01 UX01Z "
"unsigned signed";

class TpLexerVHDL : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldAtElse);
    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldAtBegin);
    DEF_PROP(bool, foldAtParenthesis);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        CommentLine = 2,
        Number = 3,
        String = 4,
        Operator = 5,
        Identifier = 6,
        UnclosedString = 7,
        Keyword = 8,
        StandardOperator = 9,
        Attribute = 10,
        StandardFunction = 11,
        StandardPackage = 12,
        StandardType = 13,
        KeywordSet7 = 14,
        CommentBlock = 15,
    };

    enum
    {
        PropFoldAtElse,
        PropFoldComments,
        PropFoldCompact,
        PropFoldAtBegin,
        PropFoldAtParenthesis,
    };

public:
    TpLexerVHDL(QObject *parent = nullptr);
    virtual ~TpLexerVHDL();

public:
    const char *language() const override;
    const char *lexer() const override;
    int braceStyle() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
    QString description(int style) const override;

    void refreshProperties() override;

    void setLexerProperty(int prop, QVariant value) override;
    QVariant lexerProperty(int prop) const override;

protected:
    bool readProperties(QSettings &settings, const QString &prefix) override;
    bool writeProperties(QSettings &settings, const QString &prefix) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERVHDL_H
