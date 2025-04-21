#include <Lexers/TpLexerPython2>

TP_NAMESPACE

TpLexerPython2::TpLexerPython2(QObject *parent)
    : TpFamilyPythonLexer(parent)
{
    setLexerProperty(PropBinaryLiterals, false);
    setLexerProperty(PropBinaryStrings, false);
}

const char *TpLexerPython2::language() const
{
    return "Python 2";
}

QColor TpLexerPython2::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python2/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Python2/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Python2/Color/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Color/SingleQuotedString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Python2/Color/Keyword", QColor);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Color/TripleSingleQuotedString", QColor);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Color/TripleDoubleQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Lexer/Python2/Color/ClassName", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python2/Color/FunctionMethodName", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Python2/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Python2/Color/Identifier", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python2/Color/CommentBlock", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python2/Color/UnclosedString", QColor);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python2/Color/HighlightIdentifier", QColor);
    case Decorator:
        return GET_SETTINGS("Lexer/Python2/Color/Decorator", QColor);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Color/DoubleQuotedFString", QColor);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Color/SingleQuotedFString", QColor);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Color/TripleSingleQuotedFString", QColor);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Color/TripleDoubleQuotedFString", QColor);
    }

    return TpFamilyPythonLexer::defaultColor(style);
}

bool TpLexerPython2::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python2/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Python2/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/Python2/Fill/Number", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Fill/SingleQuotedString", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Python2/Fill/Keyword", bool);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Fill/TripleSingleQuotedString", bool);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Fill/TripleDoubleQuotedString", bool);
    case ClassName:
        return GET_SETTINGS("Lexer/Python2/Fill/ClassName", bool);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python2/Fill/FunctionMethodName", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Python2/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Python2/Fill/Identifier", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python2/Fill/CommentBlock", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python2/Fill/UnclosedString", bool);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python2/Fill/HighlightIdentifier", bool);
    case Decorator:
        return GET_SETTINGS("Lexer/Python2/Fill/Decorator", bool);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Fill/DoubleQuotedString", bool);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Fill/SingleQuotedString", bool);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Fill/TripleSingleQuotedFString", bool);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Fill/TripleDoubleQuotedFString", bool);
    }

    return TpFamilyPythonLexer::defaultEolFill(style);
}

QFont TpLexerPython2::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python2/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Python2/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Python2/Font/Number", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Font/SingleQuotedString", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Python2/Font/Keyword", QFont);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Font/TripleSingleQuotedString", QFont);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python2/Font/TripleDoubleQuotedString", QFont);
    case ClassName:
        return GET_SETTINGS("Lexer/Python2/Font/ClassName", QFont);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python2/Font/FunctionMethodName", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Python2/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Python2/Font/Identifier", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python2/Font/CommentBlock", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python2/Font/UnclosedString", QFont);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python2/Font/HighlightIdentifier", QFont);
    case Decorator:
        return GET_SETTINGS("Lexer/Python2/Font/Decorator", QFont);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Font/DoubleQuotedFString", QFont);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Font/SingleQuotedFString", QFont);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Font/TripleSingleQuotedFString", QFont);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/Font/TripleDoubleQuotedFString", QFont);
    }

    return TpFamilyPythonLexer::defaultFont(style);
}

QColor TpLexerPython2::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Python2/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Python2/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Python2/BgColor/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/Python2/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Python2/BgColor/SingleQuotedString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Python2/BgColor/Keyword", QColor);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/Python2/BgColor/TripleSingleQuotedString", QColor);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/Python2/BgColor/TripleDoubleQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Lexer/Python2/BgColor/ClassName", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/Python2/BgColor/FunctionMethodName", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Python2/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Python2/BgColor/Identifier", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/Python2/BgColor/CommentBlock", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Python2/BgColor/UnclosedString", QColor);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/Python2/BgColor/HighlightIdentifier", QColor);
    case Decorator:
        return GET_SETTINGS("Lexer/Python2/BgColor/Decorator", QColor);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/BgColor/DoubleQuotedFString", QColor);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/BgColor/SingleQuotedFString", QColor);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/BgColor/TripleDoubleQuotedFString", QColor);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/Python2/BgColor/TripleDoubleQuotedFString", QColor);
    }

    return TpFamilyPythonLexer::defaultPaper(style);
}

const char *TpLexerPython2::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerPython2Keyword1;
    case 2:
        return lexerPython2Keyword2;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
