#include <Lexers/TpLexerHTML>

TP_NAMESPACE

TpLexerHTML::TpLexerHTML(QObject *parent)
    : TpFamilyHTMLLexer(parent)
{}

const char *TpLexerHTML::language() const
{
    return "HTML (Old)";
}

QColor TpLexerHTML::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case PHPDefault:
    case PHPDoubleQuotedString:
    case PHPSingleQuotedString:
    case PHPKeyword:
    case PHPNumber:
    case PHPVariable:
    case PHPComment:
    case PHPCommentLine:
    case PHPDoubleQuotedVariable:
    case PHPOperator:
        return GET_SETTINGS("Lexer/HTML/Color/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/HTML/Color/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/HTML/Color/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/HTML/Color/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/HTML/Color/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/HTML/Color/ASPAtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/HTML/Color/ASPStart", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/HTML/Color/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/HTML/Color/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/HTML/Color/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/HTML/Color/ASPXCComment", QColor);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/HTML/Color/SGMLUniversal", QColor);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/HTML/Color/SGMLCommand", QColor);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/HTML/Color/SGMLParameter", QColor);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/SGMLDoubleQuotedString", QColor);
    case SGMLError:
        return GET_SETTINGS("Lexer/HTML/Color/SGMLError", QColor);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/HTML/Color/SGMLSpecial", QColor);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/HTML/Color/SGMLEntity", QColor);
    case SGMLComment:
        return GET_SETTINGS("Lexer/HTML/Color/SGMLComment", QColor);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/HTML/Color/SGMLParameterComment", QColor);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/HTML/Color/SGMLBlockUniversal", QColor);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptStart", QColor);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptUniversal", QColor);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptComment", QColor);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptCommentLine", QColor);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptCommentDoc", QColor);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptNumber", QColor);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptWord", QColor);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptKeyword", QColor);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptDoubleQuotedString", QColor);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptSingleQuotedString", QColor);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptSymbol", QColor);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptUnclosedString", QColor);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/HTML/Color/JavaScriptRegex", QColor);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/HTML/Color/VBScriptStart", QColor);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Color/VBScriptUniversal", QColor);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/HTML/Color/VBScriptComment", QColor);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Color/VBScriptNumber", QColor);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Color/VBScriptKeyword", QColor);
    case VBScriptString:
        return GET_SETTINGS("Lexer/HTML/Color/VBScriptString", QColor);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTML/Color/VBScriptIdentifier", QColor);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Color/VBScriptUnclosedString", QColor);
    case PythonStart:
        return GET_SETTINGS("Lexer/HTML/Color/PythonStart", QColor);
    case PythonDefault:
        return GET_SETTINGS("Lexer/HTML/Color/PythonUniversal", QColor);
    case PythonComment:
        return GET_SETTINGS("Lexer/HTML/Color/PythonComment", QColor);
    case PythonNumber:
        return GET_SETTINGS("Lexer/HTML/Color/PythonNumber", QColor);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/PythonDoubleQuotedString", QColor);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/HTML/Color/PythonKeyword", QColor);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/PythonTripleSingleQuotedString", QColor);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/PythonTripleDoubleQuotedString", QColor);
    case PythonClassName:
        return GET_SETTINGS("Lexer/HTML/Color/PythonClassName", QColor);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTML/Color/PythonFunctionMethodName", QColor);
    case PythonOperator:
        return GET_SETTINGS("Lexer/HTML/Color/PythonOperator", QColor);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/HTML/Color/PythonIdentifier", QColor);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptStart", QColor);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptUniversal", QColor);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptComment", QColor);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptCommentLine", QColor);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptCommentDoc", QColor);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptNumber", QColor);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptWord", QColor);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptKeyword", QColor);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptDoubleQuotedString", QColor);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptSingleQuotedString", QColor);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptSymbol", QColor);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptUnclosedString", QColor);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/HTML/Color/ASPJavaScriptRegex", QColor);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/HTML/Color/ASPVBScriptStart", QColor);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Color/ASPVBScriptUniversal", QColor);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/HTML/Color/ASPVBScriptComment", QColor);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Color/ASPVBScriptNumber", QColor);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Color/ASPVBScriptKeyword", QColor);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/HTML/Color/ASPVBScriptString", QColor);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTML/Color/ASPVBScriptIdentifier", QColor);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Color/ASPVBScriptUnclosedString", QColor);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonStart", QColor);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonUniversal", QColor);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonComment", QColor);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonNumber", QColor);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonDoubleQuotedString", QColor);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonKeyword", QColor);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonTripleSingleQuotedString", QColor);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonTripleDoubleQuotedString", QColor);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonClassName", QColor);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonFunctionMethodName", QColor);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonOperator", QColor);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/HTML/Color/ASPPythonIdentifier", QColor);
    }

    return TpFamilyHTMLLexer::defaultColor(style);
}

bool TpLexerHTML::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case PHPDefault:
    case PHPDoubleQuotedString:
    case PHPSingleQuotedString:
    case PHPKeyword:
    case PHPNumber:
    case PHPVariable:
    case PHPComment:
    case PHPCommentLine:
    case PHPDoubleQuotedVariable:
    case PHPOperator:
        return GET_SETTINGS("Lexer/HTML/Fill/Universal", bool);
    case Tag:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLTag", bool);
    case UnknownTag:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLUnknownTag", bool);
    case Attribute:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLAttribute", bool);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLUnknownAttribute", bool);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLNumber", bool);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLDoubleQuotedString", bool);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLSingleQuotedString", bool);
    case OtherInTag:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLOtherInTag", bool);
    case HTMLComment:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLComment", bool);
    case Entity:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLEntity", bool);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/HTML/Fill/XMLTagEnd", bool);
    case XMLStart:
        return GET_SETTINGS("Lexer/HTML/Fill/XMLStart", bool);
    case XMLEnd:
        return GET_SETTINGS("Lexer/HTML/Fill/XMLEnd", bool);
    case Script:
        return GET_SETTINGS("Lexer/HTML/Fill/Script", bool);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPAtStart", bool);
    case ASPStart:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPStart", bool);
    case CDATA:
        return GET_SETTINGS("Lexer/HTML/Fill/CDATA", bool);
    case PHPStart:
        return GET_SETTINGS("Lexer/HTML/Fill/PHPStart", bool);
    case HTMLValue:
        return GET_SETTINGS("Lexer/HTML/Fill/HTMLValue", bool);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPXCComment", bool);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/HTML/Fill/SGMLUniversal", bool);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/HTML/Fill/SGMLCommand", bool);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/HTML/Fill/SGMLParameter", bool);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/SGMLDoubleQuotedString", bool);
    case SGMLError:
        return GET_SETTINGS("Lexer/HTML/Fill/SGMLError", bool);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/HTML/Fill/SGMLSpecial", bool);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/HTML/Fill/SGMLEntity", bool);
    case SGMLComment:
        return GET_SETTINGS("Lexer/HTML/Fill/SGMLComment", bool);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/HTML/Fill/SGMLParameterComment", bool);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/HTML/Fill/SGMLBlockUniversal", bool);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptStart", bool);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptUniversal", bool);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptComment", bool);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptCommentLine", bool);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptCommentDoc", bool);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptNumber", bool);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptWord", bool);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptKeyword", bool);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptDoubleQuotedString", bool);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptSingleQuotedString", bool);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptSymbol", bool);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptUnclosedString", bool);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/HTML/Fill/JavaScriptRegex", bool);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/HTML/Fill/VBScriptStart", bool);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Fill/VBScriptUniversal", bool);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/HTML/Fill/VBScriptComment", bool);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Fill/VBScriptNumber", bool);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Fill/VBScriptKeyword", bool);
    case VBScriptString:
        return GET_SETTINGS("Lexer/HTML/Fill/VBScriptString", bool);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTML/Fill/VBScriptIdentifier", bool);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Fill/VBScriptUnclosedString", bool);
    case PythonStart:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonStart", bool);
    case PythonDefault:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonUniversal", bool);
    case PythonComment:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonComment", bool);
    case PythonNumber:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonNumber", bool);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonDoubleQuotedString", bool);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonKeyword", bool);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonTripleSingleQuotedString", bool);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonTripleDoubleQuotedString", bool);
    case PythonClassName:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonClassName", bool);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonFunctionMethodName", bool);
    case PythonOperator:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonOperator", bool);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/HTML/Fill/PythonIdentifier", bool);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptStart", bool);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptUniversal", bool);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptComment", bool);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptCommentLine", bool);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptCommentDoc", bool);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptNumber", bool);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptWord", bool);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptKeyword", bool);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptDoubleQuotedString", bool);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptSingleQuotedString", bool);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptSymbol", bool);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptUnclosedString", bool);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPJavaScriptRegex", bool);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPVBScriptStart", bool);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPVBScriptUniversal", bool);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPVBScriptComment", bool);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPVBScriptNumber", bool);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPVBScriptKeyword", bool);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPVBScriptString", bool);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPVBScriptIdentifier", bool);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPVBScriptUnclosedString", bool);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonStart", bool);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonUniversal", bool);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonComment", bool);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonNumber", bool);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonDoubleQuotedString", bool);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonKeyword", bool);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonTripleSingleQuotedString", bool);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonTripleDoubleQuotedString", bool);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonClassName", bool);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonFunctionMethodName", bool);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonOperator", bool);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/HTML/Fill/ASPPythonIdentifier", bool);
    }

    return TpFamilyHTMLLexer::defaultEolFill(style);
}

QFont TpLexerHTML::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case PHPDefault:
    case PHPDoubleQuotedString:
    case PHPSingleQuotedString:
    case PHPKeyword:
    case PHPNumber:
    case PHPVariable:
    case PHPComment:
    case PHPCommentLine:
    case PHPDoubleQuotedVariable:
    case PHPOperator:
        return GET_SETTINGS("Lexer/HTML/Font/Universal", QFont);
    case Tag:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLTag", QFont);
    case UnknownTag:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLUnknownTag", QFont);
    case Attribute:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLAttribute", QFont);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLUnknownAttribute", QFont);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLNumber", QFont);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLDoubleQuotedString", QFont);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLSingleQuotedString", QFont);
    case OtherInTag:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLOtherInTag", QFont);
    case HTMLComment:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLComment", QFont);
    case Entity:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLEntity", QFont);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/HTML/Font/XMLTagEnd", QFont);
    case XMLStart:
        return GET_SETTINGS("Lexer/HTML/Font/XMLStart", QFont);
    case XMLEnd:
        return GET_SETTINGS("Lexer/HTML/Font/XMLEnd", QFont);
    case Script:
        return GET_SETTINGS("Lexer/HTML/Font/Script", QFont);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/HTML/Font/ASPAtStart", QFont);
    case ASPStart:
        return GET_SETTINGS("Lexer/HTML/Font/ASPStart", QFont);
    case CDATA:
        return GET_SETTINGS("Lexer/HTML/Font/CDATA", QFont);
    case PHPStart:
        return GET_SETTINGS("Lexer/HTML/Font/PHPStart", QFont);
    case HTMLValue:
        return GET_SETTINGS("Lexer/HTML/Font/HTMLValue", QFont);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/HTML/Font/ASPXCComment", QFont);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/HTML/Font/SGMLUniversal", QFont);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/HTML/Font/SGMLCommand", QFont);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/HTML/Font/SGMLParameter", QFont);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/SGMLDoubleQuotedString", QFont);
    case SGMLError:
        return GET_SETTINGS("Lexer/HTML/Font/SGMLError", QFont);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/HTML/Font/SGMLSpecial", QFont);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/HTML/Font/SGMLEntity", QFont);
    case SGMLComment:
        return GET_SETTINGS("Lexer/HTML/Font/SGMLComment", QFont);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/HTML/Font/SGMLParameterComment", QFont);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/HTML/Font/SGMLBlockUniversal", QFont);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptStart", QFont);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptUniversal", QFont);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptComment", QFont);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptCommentLine", QFont);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptCommentDoc", QFont);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptNumber", QFont);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptWord", QFont);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptKeyword", QFont);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptDoubleQuotedString", QFont);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptSingleQuotedString", QFont);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptSymbol", QFont);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptUnclosedString", QFont);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/HTML/Font/JavaScriptRegex", QFont);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/HTML/Font/VBScriptStart", QFont);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Font/VBScriptUniversal", QFont);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/HTML/Font/VBScriptComment", QFont);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Font/VBScriptNumber", QFont);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Font/VBScriptKeyword", QFont);
    case VBScriptString:
        return GET_SETTINGS("Lexer/HTML/Font/VBScriptString", QFont);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTML/Font/VBScriptIdentifier", QFont);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Font/VBScriptUnclosedString", QFont);
    case PythonStart:
        return GET_SETTINGS("Lexer/HTML/Font/PythonStart", QFont);
    case PythonDefault:
        return GET_SETTINGS("Lexer/HTML/Font/PythonUniversal", QFont);
    case PythonComment:
        return GET_SETTINGS("Lexer/HTML/Font/PythonComment", QFont);
    case PythonNumber:
        return GET_SETTINGS("Lexer/HTML/Font/PythonNumber", QFont);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/PythonDoubleQuotedString", QFont);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/HTML/Font/PythonKeyword", QFont);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/PythonTripleSingleQuotedString", QFont);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/PythonTripleDoubleQuotedString", QFont);
    case PythonClassName:
        return GET_SETTINGS("Lexer/HTML/Font/PythonClassName", QFont);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTML/Font/PythonFunctionMethodName", QFont);
    case PythonOperator:
        return GET_SETTINGS("Lexer/HTML/Font/PythonOperator", QFont);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/HTML/Font/PythonIdentifier", QFont);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptStart", QFont);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptUniversal", QFont);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptComment", QFont);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptCommentLine", QFont);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptCommentDoc", QFont);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptNumber", QFont);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptWord", QFont);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptKeyword", QFont);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptDoubleQuotedString", QFont);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptSingleQuotedString", QFont);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptSymbol", QFont);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptUnclosedString", QFont);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/HTML/Font/ASPJavaScriptRegex", QFont);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/HTML/Font/ASPVBScriptStart", QFont);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/HTML/Font/ASPVBScriptUniversal", QFont);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/HTML/Font/ASPVBScriptComment", QFont);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/HTML/Font/ASPVBScriptNumber", QFont);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/Font/ASPVBScriptKeyword", QFont);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/HTML/Font/ASPVBScriptString", QFont);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTML/Font/ASPVBScriptIdentifier", QFont);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/Font/ASPVBScriptUnclosedString", QFont);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonStart", QFont);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonUniversal", QFont);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonComment", QFont);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonNumber", QFont);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonDoubleQuotedString", QFont);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonKeyword", QFont);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonTripleSingleQuotedString", QFont);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonTripleDoubleQuotedString", QFont);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonClassName", QFont);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonFunctionMethodName", QFont);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonOperator", QFont);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/HTML/Font/ASPPythonIdentifier", QFont);
    }

    return TpFamilyHTMLLexer::defaultFont(style);
}

QColor TpLexerHTML::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
    case PHPDefault:
    case PHPDoubleQuotedString:
    case PHPSingleQuotedString:
    case PHPKeyword:
    case PHPNumber:
    case PHPVariable:
    case PHPComment:
    case PHPCommentLine:
    case PHPDoubleQuotedVariable:
    case PHPOperator:
        return GET_SETTINGS("Lexer/HTML/BgColor/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/HTML/BgColor/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/HTML/BgColor/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/HTML/BgColor/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/HTML/BgColor/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPAtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPStart", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/HTML/BgColor/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/HTML/BgColor/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/HTML/BgColor/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPXCComment", QColor);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/HTML/BgColor/SGMLUniversal", QColor);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/HTML/BgColor/SGMLCommand", QColor);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/HTML/BgColor/SGMLParameter", QColor);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/SGMLDoubleQuotedString", QColor);
    case SGMLError:
        return GET_SETTINGS("Lexer/HTML/BgColor/SGMLError", QColor);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/HTML/BgColor/SGMLSpecial", QColor);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/HTML/BgColor/SGMLEntity", QColor);
    case SGMLComment:
        return GET_SETTINGS("Lexer/HTML/BgColor/SGMLComment", QColor);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/HTML/BgColor/SGMLParameterComment", QColor);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/HTML/BgColor/SGMLBlockUniversal", QColor);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptStart", QColor);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptUniversal", QColor);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptComment", QColor);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptCommentLine", QColor);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptCommentDoc", QColor);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptNumber", QColor);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptWord", QColor);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptKeyword", QColor);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptDoubleQuotedString", QColor);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptSingleQuotedString", QColor);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptSymbol", QColor);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptUnclosedString", QColor);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/HTML/BgColor/JavaScriptRegex", QColor);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/HTML/BgColor/VBScriptStart", QColor);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/HTML/BgColor/VBScriptUniversal", QColor);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/HTML/BgColor/VBScriptComment", QColor);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/HTML/BgColor/VBScriptNumber", QColor);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/BgColor/VBScriptKeyword", QColor);
    case VBScriptString:
        return GET_SETTINGS("Lexer/HTML/BgColor/VBScriptString", QColor);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTML/BgColor/VBScriptIdentifier", QColor);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/VBScriptUnclosedString", QColor);
    case PythonStart:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonStart", QColor);
    case PythonDefault:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonUniversal", QColor);
    case PythonComment:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonComment", QColor);
    case PythonNumber:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonNumber", QColor);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonDoubleQuotedString", QColor);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonKeyword", QColor);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonTripleSingleQuotedString", QColor);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonTripleDoubleQuotedString", QColor);
    case PythonClassName:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonClassName", QColor);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonFunctionMethodName", QColor);
    case PythonOperator:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonOperator", QColor);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/HTML/BgColor/PythonIdentifier", QColor);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptStart", QColor);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptUniversal", QColor);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptComment", QColor);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptCommentLine", QColor);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptCommentDoc", QColor);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptNumber", QColor);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptWord", QColor);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptKeyword", QColor);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptDoubleQuotedString", QColor);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptSingleQuotedString", QColor);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptSymbol", QColor);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptUnclosedString", QColor);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPJavaScriptRegex", QColor);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPVBScriptStart", QColor);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPVBScriptUniversal", QColor);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPVBScriptComment", QColor);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPVBScriptNumber", QColor);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPVBScriptKeyword", QColor);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPVBScriptString", QColor);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPVBScriptIdentifier", QColor);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPVBScriptUnclosedString", QColor);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonStart", QColor);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonUniversal", QColor);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonComment", QColor);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonNumber", QColor);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonDoubleQuotedString", QColor);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonKeyword", QColor);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonTripleSingleQuotedString", QColor);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonTripleDoubleQuotedString", QColor);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonClassName", QColor);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonFunctionMethodName", QColor);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonOperator", QColor);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/HTML/BgColor/ASPPythonIdentifier", QColor);
    }

    return TpFamilyHTMLLexer::defaultColor(style);
}

const char *TpLexerHTML::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerHTMLIncompleteKeyword1;
    case 2:
        return lexerJavaScriptKeyword1;
    case 3:
        return lexerHTMLKeyword3;
    case 4:
        return lexerPythonKeyword1;
    case 6:
        return lexerHTMLKeyword6;
    default:
        return 0;
    }
}

TP_END_NAMESPACE
