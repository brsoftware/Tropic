#include <Lexers/TpLexerPython3>

TP_NAMESPACE

TpLexerPython3::TpLexerPython3(QObject *parent)
    : TpFamilyPythonLexer(parent)
{
    setLexerProperty(PropUnicodeStrings, false);
}

const char *TpLexerPython3::language() const
{
    return "Python 3";
}

QColor TpLexerPython3::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python3/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Python3/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Python3/Color/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Color/SingleQuotedString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Python3/Color/Keyword", QColor);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Color/TripleSingleQuotedString", QColor);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Color/TripleDoubleQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Lexer/Python3/Color/ClassName", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python3/Color/FunctionMethodName", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Python3/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Python3/Color/Identifier", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python3/Color/CommentBlock", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python3/Color/UnclosedString", QColor);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python3/Color/HighlightIdentifier", QColor);
    case Decorator:
        return GET_SETTINGS("Lexer/Python3/Color/Decorator", QColor);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Color/DoubleQuotedFString", QColor);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Color/SingleQuotedFString", QColor);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Color/TripleSingleQuotedFString", QColor);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Color/TripleDoubleQuotedFString", QColor);
    }

    return TpFamilyPythonLexer::defaultColor(style);
}

bool TpLexerPython3::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python3/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Python3/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/Python3/Fill/Number", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Fill/SingleQuotedString", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Python3/Fill/Keyword", bool);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Fill/TripleSingleQuotedString", bool);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Fill/TripleDoubleQuotedString", bool);
    case ClassName:
        return GET_SETTINGS("Lexer/Python3/Fill/ClassName", bool);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python3/Fill/FunctionMethodName", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Python3/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Python3/Fill/Identifier", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python3/Fill/CommentBlock", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python3/Fill/UnclosedString", bool);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python3/Fill/HighlightIdentifier", bool);
    case Decorator:
        return GET_SETTINGS("Lexer/Python3/Fill/Decorator", bool);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Fill/DoubleQuotedString", bool);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Fill/SingleQuotedString", bool);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Fill/TripleSingleQuotedFString", bool);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Fill/TripleDoubleQuotedFString", bool);
    }

    return TpFamilyPythonLexer::defaultEolFill(style);
}

QFont TpLexerPython3::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python3/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Python3/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Python3/Font/Number", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Font/SingleQuotedString", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Python3/Font/Keyword", QFont);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Font/TripleSingleQuotedString", QFont);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3/Font/TripleDoubleQuotedString", QFont);
    case ClassName:
        return GET_SETTINGS("Lexer/Python3/Font/ClassName", QFont);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python3/Font/FunctionMethodName", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Python3/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Python3/Font/Identifier", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python3/Font/CommentBlock", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python3/Font/UnclosedString", QFont);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python3/Font/HighlightIdentifier", QFont);
    case Decorator:
        return GET_SETTINGS("Lexer/Python3/Font/Decorator", QFont);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Font/DoubleQuotedFString", QFont);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Font/SingleQuotedFString", QFont);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Font/TripleSingleQuotedFString", QFont);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/Font/TripleDoubleQuotedFString", QFont);
    }

    return TpFamilyPythonLexer::defaultFont(style);
}

QColor TpLexerPython3::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python3/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Python3/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Python3/BgColor/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python3/BgColor/SingleQuotedString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Python3/BgColor/Keyword", QColor);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python3/BgColor/TripleSingleQuotedString", QColor);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3/BgColor/TripleDoubleQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Lexer/Python3/BgColor/ClassName", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python3/BgColor/FunctionMethodName", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Python3/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Python3/BgColor/Identifier", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python3/BgColor/CommentBlock", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python3/BgColor/UnclosedString", QColor);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python3/BgColor/HighlightIdentifier", QColor);
    case Decorator:
        return GET_SETTINGS("Lexer/Python3/BgColor/Decorator", QColor);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/BgColor/DoubleQuotedFString", QColor);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/BgColor/SingleQuotedFString", QColor);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/BgColor/TripleDoubleQuotedFString", QColor);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3/BgColor/TripleDoubleQuotedFString", QColor);
    }

    return TpFamilyPythonLexer::defaultPaper(style);
}

TP_END_NAMESPACE
