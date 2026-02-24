#include <Lexers/TpLexerGDScript>

TP_NAMESPACE

TpLexerGDScript::TpLexerGDScript(QObject *parent)
    : TpFamilyPythonLexer(parent)
{
    setLexerProperty(PropUnicodeStrings, false);
}

const char *TpLexerGDScript::language() const
{
    return "Python 3";
}

QColor TpLexerGDScript::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/GDScript/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/GDScript/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/GDScript/Color/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Color/SingleQuotedString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/GDScript/Color/Keyword", QColor);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Color/TripleSingleQuotedString", QColor);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Color/TripleDoubleQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Lexer/GDScript/Color/ClassName", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/GDScript/Color/FunctionMethodName", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/GDScript/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/GDScript/Color/Identifier", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/GDScript/Color/CommentBlock", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/GDScript/Color/UnclosedString", QColor);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/GDScript/Color/HighlightIdentifier", QColor);
    case Decorator:
        return GET_SETTINGS("Lexer/GDScript/Color/Decorator", QColor);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Color/DoubleQuotedFString", QColor);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Color/SingleQuotedFString", QColor);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Color/TripleSingleQuotedFString", QColor);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Color/TripleDoubleQuotedFString", QColor);
    }

    return TpFamilyPythonLexer::defaultColor(style);
}

bool TpLexerGDScript::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/GDScript/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/GDScript/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Lexer/GDScript/Fill/Number", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Fill/SingleQuotedString", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/GDScript/Fill/Keyword", bool);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Fill/TripleSingleQuotedString", bool);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Fill/TripleDoubleQuotedString", bool);
    case ClassName:
        return GET_SETTINGS("Lexer/GDScript/Fill/ClassName", bool);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/GDScript/Fill/FunctionMethodName", bool);
    case Operator:
        return GET_SETTINGS("Lexer/GDScript/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/GDScript/Fill/Identifier", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/GDScript/Fill/CommentBlock", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/GDScript/Fill/UnclosedString", bool);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/GDScript/Fill/HighlightIdentifier", bool);
    case Decorator:
        return GET_SETTINGS("Lexer/GDScript/Fill/Decorator", bool);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Fill/DoubleQuotedString", bool);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Fill/SingleQuotedString", bool);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Fill/TripleSingleQuotedFString", bool);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Fill/TripleDoubleQuotedFString", bool);
    }

    return TpFamilyPythonLexer::defaultEolFill(style);
}

QFont TpLexerGDScript::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/GDScript/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/GDScript/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Lexer/GDScript/Font/Number", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Font/SingleQuotedString", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/GDScript/Font/Keyword", QFont);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Font/TripleSingleQuotedString", QFont);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/Font/TripleDoubleQuotedString", QFont);
    case ClassName:
        return GET_SETTINGS("Lexer/GDScript/Font/ClassName", QFont);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/GDScript/Font/FunctionMethodName", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/GDScript/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/GDScript/Font/Identifier", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/GDScript/Font/CommentBlock", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/GDScript/Font/UnclosedString", QFont);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/GDScript/Font/HighlightIdentifier", QFont);
    case Decorator:
        return GET_SETTINGS("Lexer/GDScript/Font/Decorator", QFont);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Font/DoubleQuotedFString", QFont);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Font/SingleQuotedFString", QFont);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Font/TripleSingleQuotedFString", QFont);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/Font/TripleDoubleQuotedFString", QFont);
    }

    return TpFamilyPythonLexer::defaultFont(style);
}

QColor TpLexerGDScript::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/GDScript/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/GDScript/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Lexer/GDScript/BgColor/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/BgColor/SingleQuotedString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/GDScript/BgColor/Keyword", QColor);
    case TripleSingleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/BgColor/TripleSingleQuotedString", QColor);
    case TripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/GDScript/BgColor/TripleDoubleQuotedString", QColor);
    case ClassName:
        return GET_SETTINGS("Lexer/GDScript/BgColor/ClassName", QColor);
    case FunctionMethodName:
        return GET_SETTINGS("Lexer/GDScript/BgColor/FunctionMethodName", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/GDScript/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/GDScript/BgColor/Identifier", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/GDScript/BgColor/CommentBlock", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/GDScript/BgColor/UnclosedString", QColor);
    case HighlightIdentifier:
        return GET_SETTINGS("Lexer/GDScript/BgColor/HighlightIdentifier", QColor);
    case Decorator:
        return GET_SETTINGS("Lexer/GDScript/BgColor/Decorator", QColor);
    case DoubleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/BgColor/DoubleQuotedFString", QColor);
    case SingleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/BgColor/SingleQuotedFString", QColor);
    case TripleSingleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/BgColor/TripleDoubleQuotedFString", QColor);
    case TripleDoubleQuotedFString:
        return GET_SETTINGS("Lexer/GDScript/BgColor/TripleDoubleQuotedFString", QColor);
    }

    return TpFamilyPythonLexer::defaultPaper(style);
}

const char *TpLexerGDScript::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerGDScriptKeyword1;
    case 2:
        return lexerGDScriptKeyword2;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
