#include <Lexers/TpLexerNASM>

TP_NAMESPACE

TpLexerNASM::TpLexerNASM(QObject *parent)
    : TpFamilyASMLexer(parent)
{}

TpLexerNASM::~TpLexerNASM()
{}

const char *TpLexerNASM::language() const
{
    return "NASM";
}

const char *TpLexerNASM::lexer() const
{
    return "as";
}

QColor TpLexerNASM::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/NASM/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/NASM/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/NASM/Color/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/NASM/Color/DoubleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/NASM/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/NASM/Color/Identifier", QColor);
    case CPUInstruction:
        return GET_SETTINGS("Lexer/NASM/Color/CPUInstruction", QColor);
    case FPUInstruction:
        return GET_SETTINGS("Lexer/NASM/Color/FPUInstruction", QColor);
    case Register:
        return GET_SETTINGS("Lexer/NASM/Color/Register", QColor);
    case Directive:
        return GET_SETTINGS("Lexer/NASM/Color/Directive", QColor);
    case DirectiveOperand:
        return GET_SETTINGS("Lexer/NASM/Color/DirectiveOperand", QColor);
    case BlockComment:
        return GET_SETTINGS("Lexer/NASM/Color/BlockComment", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/NASM/Color/SingleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/NASM/Color/UnclosedString", QColor);
    case ExtendedInstruction:
        return GET_SETTINGS("Lexer/NASM/Color/ExtendedInstruction", QColor);
    case CommentDirective:
        return GET_SETTINGS("Lexer/NASM/Color/CommentDirective", QColor);
    }

    return TpFamilyASMLexer::defaultColor(style);
}

bool TpLexerNASM::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/NASM/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/NASM/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/NASM/Fill/Number", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/NASM/Fill/DoubleQuotedString", bool);
    case Operator:
        return GET_SETTINGS("Lexer/NASM/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/NASM/Fill/Identifier", bool);
    case CPUInstruction:
        return GET_SETTINGS("Lexer/NASM/Fill/CPUInstruction", bool);
    case FPUInstruction:
        return GET_SETTINGS("Lexer/NASM/Fill/FPUInstruction", bool);
    case Register:
        return GET_SETTINGS("Lexer/NASM/Fill/Register", bool);
    case Directive:
        return GET_SETTINGS("Lexer/NASM/Fill/Directive", bool);
    case DirectiveOperand:
        return GET_SETTINGS("Lexer/NASM/Fill/DirectiveOperand", bool);
    case BlockComment:
        return GET_SETTINGS("Lexer/NASM/Fill/BlockComment", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/NASM/Fill/SingleQuotedString", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/NASM/Fill/UnclosedString", bool);
    case ExtendedInstruction:
        return GET_SETTINGS("Lexer/NASM/Fill/ExtendedInstruction", bool);
    case CommentDirective:
        return GET_SETTINGS("Lexer/NASM/Fill/CommentDirective", bool);
    }

    return TpFamilyASMLexer::defaultEolFill(style);
}

QFont TpLexerNASM::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/NASM/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/NASM/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/NASM/Font/Number", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/NASM/Font/DoubleQuotedString", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/NASM/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/NASM/Font/Identifier", QFont);
    case CPUInstruction:
        return GET_SETTINGS("Lexer/NASM/Font/CPUInstruction", QFont);
    case FPUInstruction:
        return GET_SETTINGS("Lexer/NASM/Font/FPUInstruction", QFont);
    case Register:
        return GET_SETTINGS("Lexer/NASM/Font/Register", QFont);
    case Directive:
        return GET_SETTINGS("Lexer/NASM/Font/Directive", QFont);
    case DirectiveOperand:
        return GET_SETTINGS("Lexer/NASM/Font/DirectiveOperand", QFont);
    case BlockComment:
        return GET_SETTINGS("Lexer/NASM/Font/BlockComment", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/NASM/Font/SingleQuotedString", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/NASM/Font/UnclosedString", QFont);
    case ExtendedInstruction:
        return GET_SETTINGS("Lexer/NASM/Font/ExtendedInstruction", QFont);
    case CommentDirective:
        return GET_SETTINGS("Lexer/NASM/Font/CommentDirective", QFont);
    }

    return TpFamilyASMLexer::defaultFont(style);
}

QColor TpLexerNASM::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/NASM/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/NASM/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/NASM/BgColor/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/NASM/BgColor/DoubleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/NASM/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/NASM/BgColor/Identifier", QColor);
    case CPUInstruction:
        return GET_SETTINGS("Lexer/NASM/BgColor/CPUInstruction", QColor);
    case FPUInstruction:
        return GET_SETTINGS("Lexer/NASM/BgColor/FPUInstruction", QColor);
    case Register:
        return GET_SETTINGS("Lexer/NASM/BgColor/Register", QColor);
    case Directive:
        return GET_SETTINGS("Lexer/NASM/BgColor/Directive", QColor);
    case DirectiveOperand:
        return GET_SETTINGS("Lexer/NASM/BgColor/DirectiveOperand", QColor);
    case BlockComment:
        return GET_SETTINGS("Lexer/NASM/BgColor/BlockComment", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/NASM/BgColor/SingleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/NASM/BgColor/UnclosedString", QColor);
    case ExtendedInstruction:
        return GET_SETTINGS("Lexer/NASM/BgColor/ExtendedInstruction", QColor);
    case CommentDirective:
        return GET_SETTINGS("Lexer/NASM/BgColor/CommentDirective", QColor);
    }

    return TpFamilyASMLexer::defaultPaper(style);
}

TP_END_NAMESPACE
