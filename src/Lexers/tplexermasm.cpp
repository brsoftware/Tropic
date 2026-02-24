#include <Lexers/TpLexerMASM>

TP_NAMESPACE

TpLexerMASM::TpLexerMASM(QObject *parent)
    : TpFamilyASMLexer(parent)
{}

TpLexerMASM::~TpLexerMASM()
{}

const char *TpLexerMASM::language() const
{
    return "MASM";
}

QColor TpLexerMASM::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/MASM/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/MASM/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/MASM/Color/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/MASM/Color/DoubleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/MASM/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/MASM/Color/Identifier", QColor);
    case CPUInstruction:
        return GET_SETTINGS("Lexer/MASM/Color/CPUInstruction", QColor);
    case FPUInstruction:
        return GET_SETTINGS("Lexer/MASM/Color/FPUInstruction", QColor);
    case Register:
        return GET_SETTINGS("Lexer/MASM/Color/Register", QColor);
    case Directive:
        return GET_SETTINGS("Lexer/MASM/Color/Directive", QColor);
    case DirectiveOperand:
        return GET_SETTINGS("Lexer/MASM/Color/DirectiveOperand", QColor);
    case BlockComment:
        return GET_SETTINGS("Lexer/MASM/Color/BlockComment", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/MASM/Color/SingleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/MASM/Color/UnclosedString", QColor);
    case ExtendedInstruction:
        return GET_SETTINGS("Lexer/MASM/Color/ExtendedInstruction", QColor);
    case CommentDirective:
        return GET_SETTINGS("Lexer/MASM/Color/CommentDirective", QColor);
    }

    return TpFamilyASMLexer::defaultColor(style);
}

bool TpLexerMASM::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/MASM/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/MASM/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/MASM/Fill/Number", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/MASM/Fill/DoubleQuotedString", bool);
    case Operator:
        return GET_SETTINGS("Lexer/MASM/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/MASM/Fill/Identifier", bool);
    case CPUInstruction:
        return GET_SETTINGS("Lexer/MASM/Fill/CPUInstruction", bool);
    case FPUInstruction:
        return GET_SETTINGS("Lexer/MASM/Fill/FPUInstruction", bool);
    case Register:
        return GET_SETTINGS("Lexer/MASM/Fill/Register", bool);
    case Directive:
        return GET_SETTINGS("Lexer/MASM/Fill/Directive", bool);
    case DirectiveOperand:
        return GET_SETTINGS("Lexer/MASM/Fill/DirectiveOperand", bool);
    case BlockComment:
        return GET_SETTINGS("Lexer/MASM/Fill/BlockComment", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/MASM/Fill/SingleQuotedString", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/MASM/Fill/UnclosedString", bool);
    case ExtendedInstruction:
        return GET_SETTINGS("Lexer/MASM/Fill/ExtendedInstruction", bool);
    case CommentDirective:
        return GET_SETTINGS("Lexer/MASM/Fill/CommentDirective", bool);
    }

    return TpFamilyASMLexer::defaultEolFill(style);
}

QFont TpLexerMASM::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/MASM/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/MASM/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/MASM/Font/Number", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/MASM/Font/DoubleQuotedString", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/MASM/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/MASM/Font/Identifier", QFont);
    case CPUInstruction:
        return GET_SETTINGS("Lexer/MASM/Font/CPUInstruction", QFont);
    case FPUInstruction:
        return GET_SETTINGS("Lexer/MASM/Font/FPUInstruction", QFont);
    case Register:
        return GET_SETTINGS("Lexer/MASM/Font/Register", QFont);
    case Directive:
        return GET_SETTINGS("Lexer/MASM/Font/Directive", QFont);
    case DirectiveOperand:
        return GET_SETTINGS("Lexer/MASM/Font/DirectiveOperand", QFont);
    case BlockComment:
        return GET_SETTINGS("Lexer/MASM/Font/BlockComment", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/MASM/Font/SingleQuotedString", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/MASM/Font/UnclosedString", QFont);
    case ExtendedInstruction:
        return GET_SETTINGS("Lexer/MASM/Font/ExtendedInstruction", QFont);
    case CommentDirective:
        return GET_SETTINGS("Lexer/MASM/Font/CommentDirective", QFont);
    }

    return TpFamilyASMLexer::defaultFont(style);
}

QColor TpLexerMASM::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/MASM/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/MASM/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/MASM/BgColor/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/MASM/BgColor/DoubleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/MASM/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/MASM/BgColor/Identifier", QColor);
    case CPUInstruction:
        return GET_SETTINGS("Lexer/MASM/BgColor/CPUInstruction", QColor);
    case FPUInstruction:
        return GET_SETTINGS("Lexer/MASM/BgColor/FPUInstruction", QColor);
    case Register:
        return GET_SETTINGS("Lexer/MASM/BgColor/Register", QColor);
    case Directive:
        return GET_SETTINGS("Lexer/MASM/BgColor/Directive", QColor);
    case DirectiveOperand:
        return GET_SETTINGS("Lexer/MASM/BgColor/DirectiveOperand", QColor);
    case BlockComment:
        return GET_SETTINGS("Lexer/MASM/BgColor/BlockComment", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/MASM/BgColor/SingleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/MASM/BgColor/UnclosedString", QColor);
    case ExtendedInstruction:
        return GET_SETTINGS("Lexer/MASM/BgColor/ExtendedInstruction", QColor);
    case CommentDirective:
        return GET_SETTINGS("Lexer/MASM/BgColor/CommentDirective", QColor);
    }

    return TpFamilyASMLexer::defaultPaper(style);
}

TP_END_NAMESPACE
