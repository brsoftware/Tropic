#include <Lexers/TpLexerPHP>

TP_NAMESPACE

TpLexerPHP::TpLexerPHP(QObject *parent)
    : TpFamilyHTMLLexer(parent)
{}

const char *TpLexerPHP::language() const
{
    return "PHP";
}

QColor TpLexerPHP::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case SGMLDefault:
    case SGMLCommand:
    case SGMLParameter:
    case SGMLDoubleQuotedString:
    case SGMLError:
    case SGMLSpecial:
    case SGMLEntity:
    case SGMLComment:
    case SGMLParameterComment:
    case SGMLBlockDefault:
    case JavaScriptStart:
    case JavaScriptDefault:
    case JavaScriptComment:
    case JavaScriptCommentLine:
    case JavaScriptCommentDoc:
    case JavaScriptNumber:
    case JavaScriptWord:
    case JavaScriptKeyword:
    case JavaScriptDoubleQuotedString:
    case JavaScriptSingleQuotedString:
    case JavaScriptSymbol:
    case JavaScriptUnclosedString:
    case JavaScriptRegex:
    case VBScriptStart:
    case VBScriptDefault:
    case VBScriptComment:
    case VBScriptNumber:
    case VBScriptKeyword:
    case VBScriptString:
    case VBScriptIdentifier:
    case VBScriptUnclosedString:
    case PythonStart:
    case PythonDefault:
    case PythonComment:
    case PythonNumber:
    case PythonDoubleQuotedString:
    case PythonKeyword:
    case PythonTripleSingleQuotedString:
    case PythonTripleDoubleQuotedString:
    case PythonClassName:
    case PythonFunctionMethodName:
    case PythonOperator:
    case PythonIdentifier:
    case ASPJavaScriptStart:
    case ASPJavaScriptDefault:
    case ASPJavaScriptComment:
    case ASPJavaScriptCommentLine:
    case ASPJavaScriptCommentDoc:
    case ASPJavaScriptNumber:
    case ASPJavaScriptWord:
    case ASPJavaScriptKeyword:
    case ASPJavaScriptDoubleQuotedString:
    case ASPJavaScriptSingleQuotedString:
    case ASPJavaScriptSymbol:
    case ASPJavaScriptUnclosedString:
    case ASPJavaScriptRegex:
    case ASPVBScriptStart:
    case ASPVBScriptDefault:
    case ASPVBScriptComment:
    case ASPVBScriptNumber:
    case ASPVBScriptKeyword:
    case ASPVBScriptString:
    case ASPVBScriptIdentifier:
    case ASPVBScriptUnclosedString:
    case ASPPythonStart:
    case ASPPythonDefault:
    case ASPPythonComment:
    case ASPPythonNumber:
    case ASPPythonDoubleQuotedString:
    case ASPPythonKeyword:
    case ASPPythonTripleSingleQuotedString:
    case ASPPythonTripleDoubleQuotedString:
    case ASPPythonClassName:
    case ASPPythonFunctionMethodName:
    case ASPPythonOperator:
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLUniversal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/PHP/Color/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/PHP/Color/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/PHP/Color/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/PHP/Color/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/PHP/Color/AtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/PHP/Color/Start", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/PHP/Color/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/PHP/Color/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/PHP/Color/HTMLValue", QColor);
    case PHPDefault:
        return GET_SETTINGS("Lexer/PHP/Color/Universal", QColor);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Color/DoubleQuotedString", QColor);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Color/SingleQuotedString", QColor);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/PHP/Color/Keyword", QColor);
    case PHPNumber:
        return GET_SETTINGS("Lexer/PHP/Color/Number", QColor);
    case PHPVariable:
        return GET_SETTINGS("Lexer/PHP/Color/Variable", QColor);
    case PHPComment:
        return GET_SETTINGS("Lexer/PHP/Color/Comment", QColor);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/PHP/Color/CommentLine", QColor);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/PHP/Color/DoubleQuotedVariable", QColor);
    case PHPOperator:
        return GET_SETTINGS("Lexer/PHP/Color/Operator", QColor);
    }

    return TpFamilyHTMLLexer::defaultColor(style);
}

bool TpLexerPHP::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case SGMLDefault:
    case SGMLCommand:
    case SGMLParameter:
    case SGMLDoubleQuotedString:
    case SGMLError:
    case SGMLSpecial:
    case SGMLEntity:
    case SGMLComment:
    case SGMLParameterComment:
    case SGMLBlockDefault:
    case JavaScriptStart:
    case JavaScriptDefault:
    case JavaScriptComment:
    case JavaScriptCommentLine:
    case JavaScriptCommentDoc:
    case JavaScriptNumber:
    case JavaScriptWord:
    case JavaScriptKeyword:
    case JavaScriptDoubleQuotedString:
    case JavaScriptSingleQuotedString:
    case JavaScriptSymbol:
    case JavaScriptUnclosedString:
    case JavaScriptRegex:
    case VBScriptStart:
    case VBScriptDefault:
    case VBScriptComment:
    case VBScriptNumber:
    case VBScriptKeyword:
    case VBScriptString:
    case VBScriptIdentifier:
    case VBScriptUnclosedString:
    case PythonStart:
    case PythonDefault:
    case PythonComment:
    case PythonNumber:
    case PythonDoubleQuotedString:
    case PythonKeyword:
    case PythonTripleSingleQuotedString:
    case PythonTripleDoubleQuotedString:
    case PythonClassName:
    case PythonFunctionMethodName:
    case PythonOperator:
    case PythonIdentifier:
    case ASPJavaScriptStart:
    case ASPJavaScriptDefault:
    case ASPJavaScriptComment:
    case ASPJavaScriptCommentLine:
    case ASPJavaScriptCommentDoc:
    case ASPJavaScriptNumber:
    case ASPJavaScriptWord:
    case ASPJavaScriptKeyword:
    case ASPJavaScriptDoubleQuotedString:
    case ASPJavaScriptSingleQuotedString:
    case ASPJavaScriptSymbol:
    case ASPJavaScriptUnclosedString:
    case ASPJavaScriptRegex:
    case ASPVBScriptStart:
    case ASPVBScriptDefault:
    case ASPVBScriptComment:
    case ASPVBScriptNumber:
    case ASPVBScriptKeyword:
    case ASPVBScriptString:
    case ASPVBScriptIdentifier:
    case ASPVBScriptUnclosedString:
    case ASPPythonStart:
    case ASPPythonDefault:
    case ASPPythonComment:
    case ASPPythonNumber:
    case ASPPythonDoubleQuotedString:
    case ASPPythonKeyword:
    case ASPPythonTripleSingleQuotedString:
    case ASPPythonTripleDoubleQuotedString:
    case ASPPythonClassName:
    case ASPPythonFunctionMethodName:
    case ASPPythonOperator:
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLUniversal", bool);
    case Tag:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLTag", bool);
    case UnknownTag:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLUnknownTag", bool);
    case Attribute:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLAttribute", bool);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLUnknownAttribute", bool);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLNumber", bool);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLDoubleQuotedString", bool);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLSingleQuotedString", bool);
    case OtherInTag:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLOtherInTag", bool);
    case HTMLComment:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLComment", bool);
    case Entity:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLEntity", bool);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/PHP/Fill/XMLTagEnd", bool);
    case XMLStart:
        return GET_SETTINGS("Lexer/PHP/Fill/XMLStart", bool);
    case XMLEnd:
        return GET_SETTINGS("Lexer/PHP/Fill/XMLEnd", bool);
    case Script:
        return GET_SETTINGS("Lexer/PHP/Fill/Script", bool);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/PHP/Fill/AtStart", bool);
    case ASPStart:
        return GET_SETTINGS("Lexer/PHP/Fill/Start", bool);
    case CDATA:
        return GET_SETTINGS("Lexer/PHP/Fill/CDATA", bool);
    case PHPStart:
        return GET_SETTINGS("Lexer/PHP/Fill/PHPStart", bool);
    case HTMLValue:
        return GET_SETTINGS("Lexer/PHP/Fill/HTMLValue", bool);
    case PHPDefault:
        return GET_SETTINGS("Lexer/PHP/Fill/Universal", bool);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Fill/DoubleQuotedString", bool);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Fill/SingleQuotedString", bool);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/PHP/Fill/Keyword", bool);
    case PHPNumber:
        return GET_SETTINGS("Lexer/PHP/Fill/Number", bool);
    case PHPVariable:
        return GET_SETTINGS("Lexer/PHP/Fill/Variable", bool);
    case PHPComment:
        return GET_SETTINGS("Lexer/PHP/Fill/Comment", bool);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/PHP/Fill/CommentLine", bool);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/PHP/Fill/DoubleQuotedVariable", bool);
    case PHPOperator:
        return GET_SETTINGS("Lexer/PHP/Fill/Operator", bool);
    }

    return TpFamilyHTMLLexer::defaultEolFill(style);
}

QFont TpLexerPHP::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case SGMLDefault:
    case SGMLCommand:
    case SGMLParameter:
    case SGMLDoubleQuotedString:
    case SGMLError:
    case SGMLSpecial:
    case SGMLEntity:
    case SGMLComment:
    case SGMLParameterComment:
    case SGMLBlockDefault:
    case JavaScriptStart:
    case JavaScriptDefault:
    case JavaScriptComment:
    case JavaScriptCommentLine:
    case JavaScriptCommentDoc:
    case JavaScriptNumber:
    case JavaScriptWord:
    case JavaScriptKeyword:
    case JavaScriptDoubleQuotedString:
    case JavaScriptSingleQuotedString:
    case JavaScriptSymbol:
    case JavaScriptUnclosedString:
    case JavaScriptRegex:
    case VBScriptStart:
    case VBScriptDefault:
    case VBScriptComment:
    case VBScriptNumber:
    case VBScriptKeyword:
    case VBScriptString:
    case VBScriptIdentifier:
    case VBScriptUnclosedString:
    case PythonStart:
    case PythonDefault:
    case PythonComment:
    case PythonNumber:
    case PythonDoubleQuotedString:
    case PythonKeyword:
    case PythonTripleSingleQuotedString:
    case PythonTripleDoubleQuotedString:
    case PythonClassName:
    case PythonFunctionMethodName:
    case PythonOperator:
    case PythonIdentifier:
    case ASPJavaScriptStart:
    case ASPJavaScriptDefault:
    case ASPJavaScriptComment:
    case ASPJavaScriptCommentLine:
    case ASPJavaScriptCommentDoc:
    case ASPJavaScriptNumber:
    case ASPJavaScriptWord:
    case ASPJavaScriptKeyword:
    case ASPJavaScriptDoubleQuotedString:
    case ASPJavaScriptSingleQuotedString:
    case ASPJavaScriptSymbol:
    case ASPJavaScriptUnclosedString:
    case ASPJavaScriptRegex:
    case ASPVBScriptStart:
    case ASPVBScriptDefault:
    case ASPVBScriptComment:
    case ASPVBScriptNumber:
    case ASPVBScriptKeyword:
    case ASPVBScriptString:
    case ASPVBScriptIdentifier:
    case ASPVBScriptUnclosedString:
    case ASPPythonStart:
    case ASPPythonDefault:
    case ASPPythonComment:
    case ASPPythonNumber:
    case ASPPythonDoubleQuotedString:
    case ASPPythonKeyword:
    case ASPPythonTripleSingleQuotedString:
    case ASPPythonTripleDoubleQuotedString:
    case ASPPythonClassName:
    case ASPPythonFunctionMethodName:
    case ASPPythonOperator:
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLUniversal", QFont);
    case Tag:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLTag", QFont);
    case UnknownTag:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLUnknownTag", QFont);
    case Attribute:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLAttribute", QFont);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLUnknownAttribute", QFont);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLNumber", QFont);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLDoubleQuotedString", QFont);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLSingleQuotedString", QFont);
    case OtherInTag:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLOtherInTag", QFont);
    case HTMLComment:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLComment", QFont);
    case Entity:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLEntity", QFont);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/PHP/Font/XMLTagEnd", QFont);
    case XMLStart:
        return GET_SETTINGS("Lexer/PHP/Font/XMLStart", QFont);
    case XMLEnd:
        return GET_SETTINGS("Lexer/PHP/Font/XMLEnd", QFont);
    case Script:
        return GET_SETTINGS("Lexer/PHP/Font/Script", QFont);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/PHP/Font/AtStart", QFont);
    case ASPStart:
        return GET_SETTINGS("Lexer/PHP/Font/Start", QFont);
    case CDATA:
        return GET_SETTINGS("Lexer/PHP/Font/CDATA", QFont);
    case PHPStart:
        return GET_SETTINGS("Lexer/PHP/Font/PHPStart", QFont);
    case HTMLValue:
        return GET_SETTINGS("Lexer/PHP/Font/HTMLValue", QFont);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/PHP/Font/XCComment", QFont);
    case PHPDefault:
        return GET_SETTINGS("Lexer/PHP/Font/Universal", QFont);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Font/DoubleQuotedString", QFont);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/PHP/Font/SingleQuotedString", QFont);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/PHP/Font/Keyword", QFont);
    case PHPNumber:
        return GET_SETTINGS("Lexer/PHP/Font/Number", QFont);
    case PHPVariable:
        return GET_SETTINGS("Lexer/PHP/Font/Variable", QFont);
    case PHPComment:
        return GET_SETTINGS("Lexer/PHP/Font/Comment", QFont);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/PHP/Font/CommentLine", QFont);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/PHP/Font/DoubleQuotedVariable", QFont);
    case PHPOperator:
        return GET_SETTINGS("Lexer/PHP/Font/Operator", QFont);
    }

    return TpFamilyHTMLLexer::defaultFont(style);
}

QColor TpLexerPHP::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case SGMLDefault:
    case SGMLCommand:
    case SGMLParameter:
    case SGMLDoubleQuotedString:
    case SGMLError:
    case SGMLSpecial:
    case SGMLEntity:
    case SGMLComment:
    case SGMLParameterComment:
    case SGMLBlockDefault:
    case JavaScriptStart:
    case JavaScriptDefault:
    case JavaScriptComment:
    case JavaScriptCommentLine:
    case JavaScriptCommentDoc:
    case JavaScriptNumber:
    case JavaScriptWord:
    case JavaScriptKeyword:
    case JavaScriptDoubleQuotedString:
    case JavaScriptSingleQuotedString:
    case JavaScriptSymbol:
    case JavaScriptUnclosedString:
    case JavaScriptRegex:
    case VBScriptStart:
    case VBScriptDefault:
    case VBScriptComment:
    case VBScriptNumber:
    case VBScriptKeyword:
    case VBScriptString:
    case VBScriptIdentifier:
    case VBScriptUnclosedString:
    case PythonStart:
    case PythonDefault:
    case PythonComment:
    case PythonNumber:
    case PythonDoubleQuotedString:
    case PythonKeyword:
    case PythonTripleSingleQuotedString:
    case PythonTripleDoubleQuotedString:
    case PythonClassName:
    case PythonFunctionMethodName:
    case PythonOperator:
    case PythonIdentifier:
    case ASPJavaScriptStart:
    case ASPJavaScriptDefault:
    case ASPJavaScriptComment:
    case ASPJavaScriptCommentLine:
    case ASPJavaScriptCommentDoc:
    case ASPJavaScriptNumber:
    case ASPJavaScriptWord:
    case ASPJavaScriptKeyword:
    case ASPJavaScriptDoubleQuotedString:
    case ASPJavaScriptSingleQuotedString:
    case ASPJavaScriptSymbol:
    case ASPJavaScriptUnclosedString:
    case ASPJavaScriptRegex:
    case ASPVBScriptStart:
    case ASPVBScriptDefault:
    case ASPVBScriptComment:
    case ASPVBScriptNumber:
    case ASPVBScriptKeyword:
    case ASPVBScriptString:
    case ASPVBScriptIdentifier:
    case ASPVBScriptUnclosedString:
    case ASPPythonStart:
    case ASPPythonDefault:
    case ASPPythonComment:
    case ASPPythonNumber:
    case ASPPythonDoubleQuotedString:
    case ASPPythonKeyword:
    case ASPPythonTripleSingleQuotedString:
    case ASPPythonTripleDoubleQuotedString:
    case ASPPythonClassName:
    case ASPPythonFunctionMethodName:
    case ASPPythonOperator:
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLUniversal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/PHP/BgColor/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/PHP/BgColor/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/PHP/BgColor/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/PHP/BgColor/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/PHP/BgColor/AtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/PHP/BgColor/Start", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/PHP/BgColor/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/PHP/BgColor/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/PHP/BgColor/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/PHP/BgColor/XCComment", QColor);
    case PHPDefault:
        return GET_SETTINGS("Lexer/PHP/BgColor/Universal", QColor);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/PHP/BgColor/DoubleQuotedString", QColor);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/PHP/BgColor/SingleQuotedString", QColor);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/PHP/BgColor/Keyword", QColor);
    case PHPNumber:
        return GET_SETTINGS("Lexer/PHP/BgColor/Number", QColor);
    case PHPVariable:
        return GET_SETTINGS("Lexer/PHP/BgColor/Variable", QColor);
    case PHPComment:
        return GET_SETTINGS("Lexer/PHP/BgColor/Comment", QColor);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/PHP/BgColor/CommentLine", QColor);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/PHP/BgColor/DoubleQuotedVariable", QColor);
    case PHPOperator:
        return GET_SETTINGS("Lexer/PHP/BgColor/Operator", QColor);
    }

    return TpFamilyHTMLLexer::defaultPaper(style);
}

const char *TpLexerPHP::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerHTMLKeyword1;
    case 2:
        return lexerJavaScriptKeyword1;
    case 3:
        return lexerHTMLKeyword3;
    case 4:
        return lexerPythonKeyword1;
    case 5:
        return lexerHTMLKeyword5;
    case 6:
        return lexerHTMLKeyword6;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
