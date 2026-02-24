#include <Lexers/TpLexerErlang>

TP_NAMESPACE

TpLexerErlang::TpLexerErlang(QObject *parent)
    : TpGeneralLexer(parent)
{}

TpLexerErlang::~TpLexerErlang()
{}

const char *TpLexerErlang::language() const
{
    return "Erlang";
}

const char *TpLexerErlang::lexer() const
{
    return "erlang";
}

const char *TpLexerErlang::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_";
}

QColor TpLexerErlang::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case Default:
        return GET_SETTINGS("Lexer/Erlang/Color/Default", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Erlang/Color/Comment", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/Erlang/Color/Variable", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Erlang/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Erlang/Color/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/Erlang/Color/String", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Erlang/Color/Operator", QColor);
    case Atom:
        return GET_SETTINGS("Lexer/Erlang/Color/Atom", QColor);
    case FunctionName:
        return GET_SETTINGS("Lexer/Erlang/Color/FunctionName", QColor);
    case Character:
        return GET_SETTINGS("Lexer/Erlang/Color/Character", QColor);
    case Macro:
        return GET_SETTINGS("Lexer/Erlang/Color/Macro", QColor);
    case Record:
        return GET_SETTINGS("Lexer/Erlang/Color/Record", QColor);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Erlang/Color/Preprocessor", QColor);
    case NodeName:
        return GET_SETTINGS("Lexer/Erlang/Color/NodeName", QColor);
    case CommentFunction:
        return GET_SETTINGS("Lexer/Erlang/Color/CommentFunction", QColor);
    case CommentModule:
        return GET_SETTINGS("Lexer/Erlang/Color/CommentModule", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Erlang/Color/CommentDoc", QColor);
    case CommentDocMacro:
        return GET_SETTINGS("Lexer/Erlang/Color/CommentDocMacro", QColor);
    case QuotedAtom:
        return GET_SETTINGS("Lexer/Erlang/Color/QuotedAtom", QColor);
    case QuotedMacro:
        return GET_SETTINGS("Lexer/Erlang/Color/QuotedMacro", QColor);
    case QuotedRecord:
        return GET_SETTINGS("Lexer/Erlang/Color/QuotedRecord", QColor);
    case QuotedNodeName:
        return GET_SETTINGS("Lexer/Erlang/Color/QuotedNodeName", QColor);
    case BIFS:
        return GET_SETTINGS("Lexer/Erlang/Color/BIFS", QColor);
    case Modules:
        return GET_SETTINGS("Lexer/Erlang/Color/Modules", QColor);
    case ATTModules:
        return GET_SETTINGS("Lexer/Erlang/Color/ATTModules", QColor);
    case Unknown:
        return GET_SETTINGS("Lexer/Erlang/Color/Unknown", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerErlang::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case Default:
        return GET_SETTINGS("Lexer/Erlang/Fill/Default", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Erlang/Fill/Comment", bool);
    case Variable:
        return GET_SETTINGS("Lexer/Erlang/Fill/Variable", bool);
    case Number:
        return GET_SETTINGS("Lexer/Erlang/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Erlang/Fill/Keyword", bool);
    case String:
        return GET_SETTINGS("Lexer/Erlang/Fill/String", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Erlang/Fill/Operator", bool);
    case Atom:
        return GET_SETTINGS("Lexer/Erlang/Fill/Atom", bool);
    case FunctionName:
        return GET_SETTINGS("Lexer/Erlang/Fill/FunctionName", bool);
    case Character:
        return GET_SETTINGS("Lexer/Erlang/Fill/Character", bool);
    case Macro:
        return GET_SETTINGS("Lexer/Erlang/Fill/Macro", bool);
    case Record:
        return GET_SETTINGS("Lexer/Erlang/Fill/Record", bool);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Erlang/Fill/Preprocessor", bool);
    case NodeName:
        return GET_SETTINGS("Lexer/Erlang/Fill/NodeName", bool);
    case CommentFunction:
        return GET_SETTINGS("Lexer/Erlang/Fill/CommentFunction", bool);
    case CommentModule:
        return GET_SETTINGS("Lexer/Erlang/Fill/CommentModule", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Erlang/Fill/CommentDoc", bool);
    case CommentDocMacro:
        return GET_SETTINGS("Lexer/Erlang/Fill/CommentDocMacro", bool);
    case QuotedAtom:
        return GET_SETTINGS("Lexer/Erlang/Fill/QuotedAtom", bool);
    case QuotedMacro:
        return GET_SETTINGS("Lexer/Erlang/Fill/QuotedMacro", bool);
    case QuotedRecord:
        return GET_SETTINGS("Lexer/Erlang/Fill/QuotedRecord", bool);
    case QuotedNodeName:
        return GET_SETTINGS("Lexer/Erlang/Fill/QuotedNodeName", bool);
    case BIFS:
        return GET_SETTINGS("Lexer/Erlang/Fill/BIFS", bool);
    case Modules:
        return GET_SETTINGS("Lexer/Erlang/Fill/Modules", bool);
    case ATTModules:
        return GET_SETTINGS("Lexer/Erlang/Fill/ATTModules", bool);
    case Unknown:
        return GET_SETTINGS("Lexer/Erlang/Fill/Unknown", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerErlang::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case Default:
        return GET_SETTINGS("Lexer/Erlang/Font/Default", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Erlang/Font/Comment", QFont);
    case Variable:
        return GET_SETTINGS("Lexer/Erlang/Font/Variable", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Erlang/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Erlang/Font/Keyword", QFont);
    case String:
        return GET_SETTINGS("Lexer/Erlang/Font/String", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Erlang/Font/Operator", QFont);
    case Atom:
        return GET_SETTINGS("Lexer/Erlang/Font/Atom", QFont);
    case FunctionName:
        return GET_SETTINGS("Lexer/Erlang/Font/FunctionName", QFont);
    case Character:
        return GET_SETTINGS("Lexer/Erlang/Font/Character", QFont);
    case Macro:
        return GET_SETTINGS("Lexer/Erlang/Font/Macro", QFont);
    case Record:
        return GET_SETTINGS("Lexer/Erlang/Font/Record", QFont);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Erlang/Font/Preprocessor", QFont);
    case NodeName:
        return GET_SETTINGS("Lexer/Erlang/Font/NodeName", QFont);
    case CommentFunction:
        return GET_SETTINGS("Lexer/Erlang/Font/CommentFunction", QFont);
    case CommentModule:
        return GET_SETTINGS("Lexer/Erlang/Font/CommentModule", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Erlang/Font/CommentDoc", QFont);
    case CommentDocMacro:
        return GET_SETTINGS("Lexer/Erlang/Font/CommentDocMacro", QFont);
    case QuotedAtom:
        return GET_SETTINGS("Lexer/Erlang/Font/QuotedAtom", QFont);
    case QuotedMacro:
        return GET_SETTINGS("Lexer/Erlang/Font/QuotedMacro", QFont);
    case QuotedRecord:
        return GET_SETTINGS("Lexer/Erlang/Font/QuotedRecord", QFont);
    case QuotedNodeName:
        return GET_SETTINGS("Lexer/Erlang/Font/QuotedNodeName", QFont);
    case BIFS:
        return GET_SETTINGS("Lexer/Erlang/Font/BIFS", QFont);
    case Modules:
        return GET_SETTINGS("Lexer/Erlang/Font/Modules", QFont);
    case ATTModules:
        return GET_SETTINGS("Lexer/Erlang/Font/ATTModules", QFont);
    case Unknown:
        return GET_SETTINGS("Lexer/Erlang/Font/Unknown", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerErlang::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case Default:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Default", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Comment", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Variable", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/Erlang/BgColor/String", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Operator", QColor);
    case Atom:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Atom", QColor);
    case FunctionName:
        return GET_SETTINGS("Lexer/Erlang/BgColor/FunctionName", QColor);
    case Character:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Character", QColor);
    case Macro:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Macro", QColor);
    case Record:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Record", QColor);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Preprocessor", QColor);
    case NodeName:
        return GET_SETTINGS("Lexer/Erlang/BgColor/NodeName", QColor);
    case CommentFunction:
        return GET_SETTINGS("Lexer/Erlang/BgColor/CommentFunction", QColor);
    case CommentModule:
        return GET_SETTINGS("Lexer/Erlang/BgColor/CommentModule", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Erlang/BgColor/CommentDoc", QColor);
    case CommentDocMacro:
        return GET_SETTINGS("Lexer/Erlang/BgColor/CommentDocMacro", QColor);
    case QuotedAtom:
        return GET_SETTINGS("Lexer/Erlang/BgColor/QuotedAtom", QColor);
    case QuotedMacro:
        return GET_SETTINGS("Lexer/Erlang/BgColor/QuotedMacro", QColor);
    case QuotedRecord:
        return GET_SETTINGS("Lexer/Erlang/BgColor/QuotedRecord", QColor);
    case QuotedNodeName:
        return GET_SETTINGS("Lexer/Erlang/BgColor/QuotedNodeName", QColor);
    case BIFS:
        return GET_SETTINGS("Lexer/Erlang/BgColor/BIFS", QColor);
    case Modules:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Modules", QColor);
    case ATTModules:
        return GET_SETTINGS("Lexer/Erlang/BgColor/ATTModules", QColor);
    case Unknown:
        return GET_SETTINGS("Lexer/Erlang/BgColor/Unknown", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerErlang::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerErlangKeyword1;
    case 2:
        return lexerErlangKeyword2;
    case 3:
        return lexerErlangKeyword3;
    case 4:
        return lexerErlangKeyword4;
    case 5:
        return lexerErlangKeyword5;
    case 6:
        return lexerErlangKeyword6;
    default:
        return 0;
    }
}

QString TpLexerErlang::description(int style) const
{
    switch (style)
    {
    case Default:
        return "Default";
    case Comment:
        return "Comment";
    case Variable:
        return "Variable";
    case Number:
        return "Number";
    case Keyword:
        return "Keyword";
    case String:
        return "String";
    case Operator:
        return "Operator";
    case Atom:
        return "Atom";
    case FunctionName:
        return "Function Name";
    case Character:
        return "Character";
    case Macro:
        return "Macro";
    case Record:
        return "Record";
    case Preprocessor:
        return "Preprocessor";
    case NodeName:
        return "NodeName";
    case CommentFunction:
        return "Function Comment";
    case CommentModule:
        return "Module Comment";
    case CommentDoc:
        return "Comment Doc";
    case CommentDocMacro:
        return "Comment Doc Macro";
    case QuotedAtom:
        return "Quoted Atom";
    case QuotedMacro:
        return "Quoted Macro";
    case QuotedRecord:
        return "Quoted Record";
    case QuotedNodeName:
        return "Quoted Node Name";
    case BIFS:
        return "BIFs";
    case Modules:
        return "Modules";
    case ATTModules:
        return "ATT Modules";
    case Unknown:
        return "Unknown";
    }

    return QString();
}

TP_END_NAMESPACE
