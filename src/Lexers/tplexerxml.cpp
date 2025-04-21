#include <Lexers/TpLexerXML>

TP_NAMESPACE

TpLexerXML::TpLexerXML(QObject *parent)
    : TpFamilyHTMLLexer(parent)
{}

const char *TpLexerXML::language() const
{
    return "XML";
}

QColor TpLexerXML::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/XML/Color/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/XML/Color/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/XML/Color/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/XML/Color/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/XML/Color/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/XML/Color/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/XML/Color/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/XML/Color/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/XML/Color/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/XML/Color/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/XML/Color/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/XML/Color/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/XML/Color/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/XML/Color/ASPAtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/XML/Color/ASPStart", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/XML/Color/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/XML/Color/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/XML/Color/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/XML/Color/ASPXCComment", QColor);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/XML/Color/SGMLUniversal", QColor);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/XML/Color/SGMLCommand", QColor);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/XML/Color/SGMLParameter", QColor);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/SGMLDoubleQuotedString", QColor);
    case SGMLError:
        return GET_SETTINGS("Lexer/XML/Color/SGMLError", QColor);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/XML/Color/SGMLSpecial", QColor);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/XML/Color/SGMLEntity", QColor);
    case SGMLComment:
        return GET_SETTINGS("Lexer/XML/Color/SGMLComment", QColor);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/XML/Color/SGMLParameterComment", QColor);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/XML/Color/SGMLBlockUniversal", QColor);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptStart", QColor);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptUniversal", QColor);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptComment", QColor);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptCommentLine", QColor);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptCommentDoc", QColor);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptNumber", QColor);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptWord", QColor);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptKeyword", QColor);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptDoubleQuotedString", QColor);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptSingleQuotedString", QColor);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptSymbol", QColor);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptUnclosedString", QColor);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/XML/Color/JavaScriptRegex", QColor);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/XML/Color/VBScriptStart", QColor);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/XML/Color/VBScriptUniversal", QColor);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/XML/Color/VBScriptComment", QColor);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/XML/Color/VBScriptNumber", QColor);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Color/VBScriptKeyword", QColor);
    case VBScriptString:
        return GET_SETTINGS("Lexer/XML/Color/VBScriptString", QColor);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/XML/Color/VBScriptIdentifier", QColor);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Color/VBScriptUnclosedString", QColor);
    case PythonStart:
        return GET_SETTINGS("Lexer/XML/Color/PythonStart", QColor);
    case PythonDefault:
        return GET_SETTINGS("Lexer/XML/Color/PythonUniversal", QColor);
    case PythonComment:
        return GET_SETTINGS("Lexer/XML/Color/PythonComment", QColor);
    case PythonNumber:
        return GET_SETTINGS("Lexer/XML/Color/PythonNumber", QColor);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/PythonDoubleQuotedString", QColor);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/XML/Color/PythonKeyword", QColor);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/PythonTripleSingleQuotedString", QColor);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/PythonTripleDoubleQuotedString", QColor);
    case PythonClassName:
        return GET_SETTINGS("Lexer/XML/Color/PythonClassName", QColor);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/XML/Color/PythonFunctionMethodName", QColor);
    case PythonOperator:
        return GET_SETTINGS("Lexer/XML/Color/PythonOperator", QColor);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/XML/Color/PythonIdentifier", QColor);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptStart", QColor);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptUniversal", QColor);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptComment", QColor);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptCommentLine", QColor);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptCommentDoc", QColor);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptNumber", QColor);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptWord", QColor);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptKeyword", QColor);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptDoubleQuotedString", QColor);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptSingleQuotedString", QColor);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptSymbol", QColor);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptUnclosedString", QColor);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/XML/Color/ASPJavaScriptRegex", QColor);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/XML/Color/ASPVBScriptStart", QColor);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/XML/Color/ASPVBScriptUniversal", QColor);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/XML/Color/ASPVBScriptComment", QColor);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/XML/Color/ASPVBScriptNumber", QColor);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Color/ASPVBScriptKeyword", QColor);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/XML/Color/ASPVBScriptString", QColor);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/XML/Color/ASPVBScriptIdentifier", QColor);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Color/ASPVBScriptUnclosedString", QColor);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonStart", QColor);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonUniversal", QColor);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonComment", QColor);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonNumber", QColor);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonDoubleQuotedString", QColor);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonKeyword", QColor);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonTripleSingleQuotedString", QColor);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonTripleDoubleQuotedString", QColor);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonClassName", QColor);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonFunctionMethodName", QColor);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonOperator", QColor);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/XML/Color/ASPPythonIdentifier", QColor);
    case PHPDefault:
        return GET_SETTINGS("Lexer/XML/Color/PHPUniversal", QColor);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/PHPDoubleQuotedString", QColor);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Color/PHPSingleQuotedString", QColor);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/XML/Color/PHPKeyword", QColor);
    case PHPNumber:
        return GET_SETTINGS("Lexer/XML/Color/PHPNumber", QColor);
    case PHPVariable:
        return GET_SETTINGS("Lexer/XML/Color/PHPVariable", QColor);
    case PHPComment:
        return GET_SETTINGS("Lexer/XML/Color/PHPComment", QColor);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/XML/Color/PHPCommentLine", QColor);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/XML/Color/PHPDoubleQuotedVariable", QColor);
    case PHPOperator:
        return GET_SETTINGS("Lexer/XML/Color/PHPOperator", QColor);
    }

    return TpFamilyHTMLLexer::defaultColor(style);
}

bool TpLexerXML::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/XML/Fill/Universal", bool);
    case Tag:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLTag", bool);
    case UnknownTag:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLUnknownTag", bool);
    case Attribute:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLAttribute", bool);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLUnknownAttribute", bool);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLNumber", bool);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLDoubleQuotedString", bool);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLSingleQuotedString", bool);
    case OtherInTag:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLOtherInTag", bool);
    case HTMLComment:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLComment", bool);
    case Entity:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLEntity", bool);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/XML/Fill/XMLTagEnd", bool);
    case XMLStart:
        return GET_SETTINGS("Lexer/XML/Fill/XMLStart", bool);
    case XMLEnd:
        return GET_SETTINGS("Lexer/XML/Fill/XMLEnd", bool);
    case Script:
        return GET_SETTINGS("Lexer/XML/Fill/Script", bool);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/XML/Fill/ASPAtStart", bool);
    case ASPStart:
        return GET_SETTINGS("Lexer/XML/Fill/ASPStart", bool);
    case CDATA:
        return GET_SETTINGS("Lexer/XML/Fill/CDATA", bool);
    case PHPStart:
        return GET_SETTINGS("Lexer/XML/Fill/PHPStart", bool);
    case HTMLValue:
        return GET_SETTINGS("Lexer/XML/Fill/HTMLValue", bool);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/XML/Fill/ASPXCComment", bool);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/XML/Fill/SGMLUniversal", bool);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/XML/Fill/SGMLCommand", bool);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/XML/Fill/SGMLParameter", bool);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/SGMLDoubleQuotedString", bool);
    case SGMLError:
        return GET_SETTINGS("Lexer/XML/Fill/SGMLError", bool);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/XML/Fill/SGMLSpecial", bool);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/XML/Fill/SGMLEntity", bool);
    case SGMLComment:
        return GET_SETTINGS("Lexer/XML/Fill/SGMLComment", bool);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/XML/Fill/SGMLParameterComment", bool);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/XML/Fill/SGMLBlockUniversal", bool);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptStart", bool);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptUniversal", bool);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptComment", bool);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptCommentLine", bool);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptCommentDoc", bool);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptNumber", bool);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptWord", bool);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptKeyword", bool);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptDoubleQuotedString", bool);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptSingleQuotedString", bool);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptSymbol", bool);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptUnclosedString", bool);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/XML/Fill/JavaScriptRegex", bool);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/XML/Fill/VBScriptStart", bool);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/XML/Fill/VBScriptUniversal", bool);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/XML/Fill/VBScriptComment", bool);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/XML/Fill/VBScriptNumber", bool);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Fill/VBScriptKeyword", bool);
    case VBScriptString:
        return GET_SETTINGS("Lexer/XML/Fill/VBScriptString", bool);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/XML/Fill/VBScriptIdentifier", bool);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Fill/VBScriptUnclosedString", bool);
    case PythonStart:
        return GET_SETTINGS("Lexer/XML/Fill/PythonStart", bool);
    case PythonDefault:
        return GET_SETTINGS("Lexer/XML/Fill/PythonUniversal", bool);
    case PythonComment:
        return GET_SETTINGS("Lexer/XML/Fill/PythonComment", bool);
    case PythonNumber:
        return GET_SETTINGS("Lexer/XML/Fill/PythonNumber", bool);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/PythonDoubleQuotedString", bool);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/XML/Fill/PythonKeyword", bool);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/PythonTripleSingleQuotedString", bool);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/PythonTripleDoubleQuotedString", bool);
    case PythonClassName:
        return GET_SETTINGS("Lexer/XML/Fill/PythonClassName", bool);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/XML/Fill/PythonFunctionMethodName", bool);
    case PythonOperator:
        return GET_SETTINGS("Lexer/XML/Fill/PythonOperator", bool);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/XML/Fill/PythonIdentifier", bool);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptStart", bool);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptUniversal", bool);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptComment", bool);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptCommentLine", bool);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptCommentDoc", bool);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptNumber", bool);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptWord", bool);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptKeyword", bool);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptDoubleQuotedString", bool);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptSingleQuotedString", bool);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptSymbol", bool);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptUnclosedString", bool);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/XML/Fill/ASPJavaScriptRegex", bool);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/XML/Fill/ASPVBScriptStart", bool);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/XML/Fill/ASPVBScriptUniversal", bool);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/XML/Fill/ASPVBScriptComment", bool);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/XML/Fill/ASPVBScriptNumber", bool);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Fill/ASPVBScriptKeyword", bool);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/XML/Fill/ASPVBScriptString", bool);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/XML/Fill/ASPVBScriptIdentifier", bool);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Fill/ASPVBScriptUnclosedString", bool);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonStart", bool);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonUniversal", bool);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonComment", bool);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonNumber", bool);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonDoubleQuotedString", bool);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonKeyword", bool);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonTripleSingleQuotedString", bool);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonTripleDoubleQuotedString", bool);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonClassName", bool);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonFunctionMethodName", bool);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonOperator", bool);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/XML/Fill/ASPPythonIdentifier", bool);
    case PHPDefault:
        return GET_SETTINGS("Lexer/XML/Fill/PHPUniversal", bool);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/PHPDoubleQuotedString", bool);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Fill/PHPSingleQuotedString", bool);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/XML/Fill/PHPKeyword", bool);
    case PHPNumber:
        return GET_SETTINGS("Lexer/XML/Fill/PHPNumber", bool);
    case PHPVariable:
        return GET_SETTINGS("Lexer/XML/Fill/PHPVariable", bool);
    case PHPComment:
        return GET_SETTINGS("Lexer/XML/Fill/PHPComment", bool);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/XML/Fill/PHPCommentLine", bool);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/XML/Fill/PHPDoubleQuotedVariable", bool);
    case PHPOperator:
        return GET_SETTINGS("Lexer/XML/Fill/PHPOperator", bool);
    }

    return TpFamilyHTMLLexer::defaultEolFill(style);
}

QFont TpLexerXML::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/XML/Font/Universal", QFont);
    case Tag:
        return GET_SETTINGS("Lexer/XML/Font/HTMLTag", QFont);
    case UnknownTag:
        return GET_SETTINGS("Lexer/XML/Font/HTMLUnknownTag", QFont);
    case Attribute:
        return GET_SETTINGS("Lexer/XML/Font/HTMLAttribute", QFont);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/XML/Font/HTMLUnknownAttribute", QFont);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/XML/Font/HTMLNumber", QFont);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/HTMLDoubleQuotedString", QFont);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/HTMLSingleQuotedString", QFont);
    case OtherInTag:
        return GET_SETTINGS("Lexer/XML/Font/HTMLOtherInTag", QFont);
    case HTMLComment:
        return GET_SETTINGS("Lexer/XML/Font/HTMLComment", QFont);
    case Entity:
        return GET_SETTINGS("Lexer/XML/Font/HTMLEntity", QFont);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/XML/Font/XMLTagEnd", QFont);
    case XMLStart:
        return GET_SETTINGS("Lexer/XML/Font/XMLStart", QFont);
    case XMLEnd:
        return GET_SETTINGS("Lexer/XML/Font/XMLEnd", QFont);
    case Script:
        return GET_SETTINGS("Lexer/XML/Font/Script", QFont);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/XML/Font/ASPAtStart", QFont);
    case ASPStart:
        return GET_SETTINGS("Lexer/XML/Font/ASPStart", QFont);
    case CDATA:
        return GET_SETTINGS("Lexer/XML/Font/CDATA", QFont);
    case PHPStart:
        return GET_SETTINGS("Lexer/XML/Font/PHPStart", QFont);
    case HTMLValue:
        return GET_SETTINGS("Lexer/XML/Font/HTMLValue", QFont);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/XML/Font/ASPXCComment", QFont);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/XML/Font/SGMLUniversal", QFont);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/XML/Font/SGMLCommand", QFont);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/XML/Font/SGMLParameter", QFont);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/SGMLDoubleQuotedString", QFont);
    case SGMLError:
        return GET_SETTINGS("Lexer/XML/Font/SGMLError", QFont);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/XML/Font/SGMLSpecial", QFont);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/XML/Font/SGMLEntity", QFont);
    case SGMLComment:
        return GET_SETTINGS("Lexer/XML/Font/SGMLComment", QFont);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/XML/Font/SGMLParameterComment", QFont);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/XML/Font/SGMLBlockUniversal", QFont);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptStart", QFont);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptUniversal", QFont);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptComment", QFont);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptCommentLine", QFont);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptCommentDoc", QFont);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptNumber", QFont);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptWord", QFont);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptKeyword", QFont);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptDoubleQuotedString", QFont);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptSingleQuotedString", QFont);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptSymbol", QFont);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptUnclosedString", QFont);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/XML/Font/JavaScriptRegex", QFont);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/XML/Font/VBScriptStart", QFont);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/XML/Font/VBScriptUniversal", QFont);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/XML/Font/VBScriptComment", QFont);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/XML/Font/VBScriptNumber", QFont);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Font/VBScriptKeyword", QFont);
    case VBScriptString:
        return GET_SETTINGS("Lexer/XML/Font/VBScriptString", QFont);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/XML/Font/VBScriptIdentifier", QFont);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Font/VBScriptUnclosedString", QFont);
    case PythonStart:
        return GET_SETTINGS("Lexer/XML/Font/PythonStart", QFont);
    case PythonDefault:
        return GET_SETTINGS("Lexer/XML/Font/PythonUniversal", QFont);
    case PythonComment:
        return GET_SETTINGS("Lexer/XML/Font/PythonComment", QFont);
    case PythonNumber:
        return GET_SETTINGS("Lexer/XML/Font/PythonNumber", QFont);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/PythonDoubleQuotedString", QFont);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/XML/Font/PythonKeyword", QFont);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/PythonTripleSingleQuotedString", QFont);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/PythonTripleDoubleQuotedString", QFont);
    case PythonClassName:
        return GET_SETTINGS("Lexer/XML/Font/PythonClassName", QFont);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/XML/Font/PythonFunctionMethodName", QFont);
    case PythonOperator:
        return GET_SETTINGS("Lexer/XML/Font/PythonOperator", QFont);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/XML/Font/PythonIdentifier", QFont);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptStart", QFont);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptUniversal", QFont);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptComment", QFont);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptCommentLine", QFont);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptCommentDoc", QFont);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptNumber", QFont);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptWord", QFont);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptKeyword", QFont);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptDoubleQuotedString", QFont);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptSingleQuotedString", QFont);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptSymbol", QFont);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptUnclosedString", QFont);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/XML/Font/ASPJavaScriptRegex", QFont);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/XML/Font/ASPVBScriptStart", QFont);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/XML/Font/ASPVBScriptUniversal", QFont);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/XML/Font/ASPVBScriptComment", QFont);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/XML/Font/ASPVBScriptNumber", QFont);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/XML/Font/ASPVBScriptKeyword", QFont);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/XML/Font/ASPVBScriptString", QFont);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/XML/Font/ASPVBScriptIdentifier", QFont);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/Font/ASPVBScriptUnclosedString", QFont);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonStart", QFont);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonUniversal", QFont);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonComment", QFont);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonNumber", QFont);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonDoubleQuotedString", QFont);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonKeyword", QFont);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonTripleSingleQuotedString", QFont);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonTripleDoubleQuotedString", QFont);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonClassName", QFont);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonFunctionMethodName", QFont);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonOperator", QFont);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/XML/Font/ASPPythonIdentifier", QFont);
    case PHPDefault:
        return GET_SETTINGS("Lexer/XML/Font/PHPUniversal", QFont);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/PHPDoubleQuotedString", QFont);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/Font/PHPSingleQuotedString", QFont);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/XML/Font/PHPKeyword", QFont);
    case PHPNumber:
        return GET_SETTINGS("Lexer/XML/Font/PHPNumber", QFont);
    case PHPVariable:
        return GET_SETTINGS("Lexer/XML/Font/PHPVariable", QFont);
    case PHPComment:
        return GET_SETTINGS("Lexer/XML/Font/PHPComment", QFont);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/XML/Font/PHPCommentLine", QFont);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/XML/Font/PHPDoubleQuotedVariable", QFont);
    case PHPOperator:
        return GET_SETTINGS("Lexer/XML/Font/PHPOperator", QFont);
    }

    return TpFamilyHTMLLexer::defaultFont(style);
}

QColor TpLexerXML::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/XML/BgColor/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/XML/BgColor/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/XML/BgColor/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/XML/BgColor/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/XML/BgColor/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPAtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPStart", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/XML/BgColor/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/XML/BgColor/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPXCComment", QColor);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/XML/BgColor/SGMLUniversal", QColor);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/XML/BgColor/SGMLCommand", QColor);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/XML/BgColor/SGMLParameter", QColor);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/SGMLDoubleQuotedString", QColor);
    case SGMLError:
        return GET_SETTINGS("Lexer/XML/BgColor/SGMLError", QColor);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/XML/BgColor/SGMLSpecial", QColor);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/XML/BgColor/SGMLEntity", QColor);
    case SGMLComment:
        return GET_SETTINGS("Lexer/XML/BgColor/SGMLComment", QColor);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/XML/BgColor/SGMLParameterComment", QColor);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/XML/BgColor/SGMLBlockUniversal", QColor);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptStart", QColor);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptUniversal", QColor);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptComment", QColor);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptCommentLine", QColor);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptCommentDoc", QColor);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptNumber", QColor);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptWord", QColor);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptKeyword", QColor);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptDoubleQuotedString", QColor);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptSingleQuotedString", QColor);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptSymbol", QColor);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptUnclosedString", QColor);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/XML/BgColor/JavaScriptRegex", QColor);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/XML/BgColor/VBScriptStart", QColor);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/XML/BgColor/VBScriptUniversal", QColor);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/XML/BgColor/VBScriptComment", QColor);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/XML/BgColor/VBScriptNumber", QColor);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/XML/BgColor/VBScriptKeyword", QColor);
    case VBScriptString:
        return GET_SETTINGS("Lexer/XML/BgColor/VBScriptString", QColor);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/XML/BgColor/VBScriptIdentifier", QColor);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/BgColor/VBScriptUnclosedString", QColor);
    case PythonStart:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonStart", QColor);
    case PythonDefault:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonUniversal", QColor);
    case PythonComment:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonComment", QColor);
    case PythonNumber:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonNumber", QColor);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonDoubleQuotedString", QColor);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonKeyword", QColor);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonTripleSingleQuotedString", QColor);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonTripleDoubleQuotedString", QColor);
    case PythonClassName:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonClassName", QColor);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonFunctionMethodName", QColor);
    case PythonOperator:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonOperator", QColor);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/XML/BgColor/PythonIdentifier", QColor);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptStart", QColor);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptUniversal", QColor);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptComment", QColor);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptCommentLine", QColor);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptCommentDoc", QColor);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptNumber", QColor);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptWord", QColor);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptKeyword", QColor);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptDoubleQuotedString", QColor);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptSingleQuotedString", QColor);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptSymbol", QColor);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptUnclosedString", QColor);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPJavaScriptRegex", QColor);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPVBScriptStart", QColor);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPVBScriptUniversal", QColor);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPVBScriptComment", QColor);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPVBScriptNumber", QColor);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPVBScriptKeyword", QColor);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPVBScriptString", QColor);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPVBScriptIdentifier", QColor);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPVBScriptUnclosedString", QColor);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonStart", QColor);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonUniversal", QColor);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonComment", QColor);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonNumber", QColor);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonDoubleQuotedString", QColor);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonKeyword", QColor);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonTripleSingleQuotedString", QColor);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonTripleDoubleQuotedString", QColor);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonClassName", QColor);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonFunctionMethodName", QColor);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonOperator", QColor);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/XML/BgColor/ASPPythonIdentifier", QColor);
    case PHPDefault:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPUniversal", QColor);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPDoubleQuotedString", QColor);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPSingleQuotedString", QColor);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPKeyword", QColor);
    case PHPNumber:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPNumber", QColor);
    case PHPVariable:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPVariable", QColor);
    case PHPComment:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPComment", QColor);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPCommentLine", QColor);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPDoubleQuotedVariable", QColor);
    case PHPOperator:
        return GET_SETTINGS("Lexer/XML/BgColor/PHPOperator", QColor);
    }

    return TpFamilyHTMLLexer::defaultColor(style);
}

const char *TpLexerXML::keywords(int set) const
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
