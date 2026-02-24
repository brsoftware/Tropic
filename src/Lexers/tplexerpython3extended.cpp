#include <Lexers/TpLexerPython3Extended>

TP_NAMESPACE

TpLexerPython3Extended::TpLexerPython3Extended(QObject *parent)
    : TpFamilyPythonLexer(parent)
{}

const char *TpLexerPython3Extended::language() const
{
    return "Python 3 (Extended)";
}

QColor TpLexerPython3Extended::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python3Extended/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Python3Extended/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Python3Extended/Color/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Color/SingleQuotedString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Python3Extended/Color/Keyword", QColor);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Color/TripleSingleQuotedString", QColor);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Color/TripleDoubleQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Lexer/Python3Extended/Color/ClassName", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python3Extended/Color/FunctionMethodName", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Python3Extended/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Python3Extended/Color/Identifier", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python3Extended/Color/CommentBlock", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python3Extended/Color/UnclosedString", QColor);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python3Extended/Color/HighlightIdentifier", QColor);
    case Decorator:
        return GET_SETTINGS("Lexer/Python3Extended/Color/Decorator", QColor);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Color/DoubleQuotedFString", QColor);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Color/SingleQuotedFString", QColor);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Color/TripleSingleQuotedFString", QColor);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Color/TripleDoubleQuotedFString", QColor);
    }

    return TpFamilyPythonLexer::defaultColor(style);
}

bool TpLexerPython3Extended::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/Number", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/SingleQuotedString", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/Keyword", bool);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/TripleSingleQuotedString", bool);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/TripleDoubleQuotedString", bool);
    case ClassName:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/ClassName", bool);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/FunctionMethodName", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/Identifier", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/CommentBlock", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/UnclosedString", bool);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/HighlightIdentifier", bool);
    case Decorator:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/Decorator", bool);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/DoubleQuotedString", bool);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/SingleQuotedString", bool);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/TripleSingleQuotedFString", bool);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Fill/TripleDoubleQuotedFString", bool);
    }

    return TpFamilyPythonLexer::defaultEolFill(style);
}

QFont TpLexerPython3Extended::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python3Extended/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Python3Extended/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Python3Extended/Font/Number", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Font/SingleQuotedString", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Python3Extended/Font/Keyword", QFont);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Font/TripleSingleQuotedString", QFont);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/Font/TripleDoubleQuotedString", QFont);
    case ClassName:
        return GET_SETTINGS("Lexer/Python3Extended/Font/ClassName", QFont);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python3Extended/Font/FunctionMethodName", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Python3Extended/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Python3Extended/Font/Identifier", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python3Extended/Font/CommentBlock", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python3Extended/Font/UnclosedString", QFont);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python3Extended/Font/HighlightIdentifier", QFont);
    case Decorator:
        return GET_SETTINGS("Lexer/Python3Extended/Font/Decorator", QFont);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Font/DoubleQuotedFString", QFont);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Font/SingleQuotedFString", QFont);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Font/TripleSingleQuotedFString", QFont);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/Font/TripleDoubleQuotedFString", QFont);
    }

    return TpFamilyPythonLexer::defaultFont(style);
}

QColor TpLexerPython3Extended::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/SingleQuotedString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/Keyword", QColor);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/TripleSingleQuotedString", QColor);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/TripleDoubleQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/ClassName", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/FunctionMethodName", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/Identifier", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/CommentBlock", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/UnclosedString", QColor);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/HighlightIdentifier", QColor);
    case Decorator:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/Decorator", QColor);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/DoubleQuotedFString", QColor);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/SingleQuotedFString", QColor);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/TripleDoubleQuotedFString", QColor);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python3Extended/BgColor/TripleDoubleQuotedFString", QColor);
    }

    return TpFamilyPythonLexer::defaultPaper(style);
}

const char *TpLexerPython3Extended::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerPythonExtendedKeyword1;
    case 2:
        return lexerPythonExtendedKeyword2;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
