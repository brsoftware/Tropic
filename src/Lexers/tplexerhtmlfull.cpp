#include <Lexers/TpLexerHTMLFull>

TP_NAMESPACE

TpLexerHTMLFull::TpLexerHTMLFull(QObject *parent)
    : TpFamilyHTMLLexer(parent)
{}

const char *TpLexerHTMLFull::language() const
{
    return "HTML (Full)";
}

QColor TpLexerHTMLFull::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/HTMLFull/Color/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/HTMLFull/Color/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/HTMLFull/Color/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/HTMLFull/Color/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/HTMLFull/Color/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPAtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPStart", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/HTMLFull/Color/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/HTMLFull/Color/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPXCComment", QColor);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Color/SGMLUniversal", QColor);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/HTMLFull/Color/SGMLCommand", QColor);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/HTMLFull/Color/SGMLParameter", QColor);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/SGMLDoubleQuotedString", QColor);
    case SGMLError:
        return GET_SETTINGS("Lexer/HTMLFull/Color/SGMLError", QColor);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/HTMLFull/Color/SGMLSpecial", QColor);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/HTMLFull/Color/SGMLEntity", QColor);
    case SGMLComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/SGMLComment", QColor);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/SGMLParameterComment", QColor);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Color/SGMLBlockUniversal", QColor);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptStart", QColor);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptUniversal", QColor);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptComment", QColor);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptCommentLine", QColor);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptCommentDoc", QColor);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptNumber", QColor);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptWord", QColor);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptKeyword", QColor);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptDoubleQuotedString", QColor);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptSingleQuotedString", QColor);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptSymbol", QColor);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptUnclosedString", QColor);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/HTMLFull/Color/JavaScriptRegex", QColor);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Color/VBScriptStart", QColor);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Color/VBScriptUniversal", QColor);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/VBScriptComment", QColor);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Color/VBScriptNumber", QColor);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Color/VBScriptKeyword", QColor);
    case VBScriptString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/VBScriptString", QColor);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Color/VBScriptIdentifier", QColor);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/VBScriptUnclosedString", QColor);
    case PythonStart:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonStart", QColor);
    case PythonDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonUniversal", QColor);
    case PythonComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonComment", QColor);
    case PythonNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonNumber", QColor);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonDoubleQuotedString", QColor);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonKeyword", QColor);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonTripleSingleQuotedString", QColor);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonTripleDoubleQuotedString", QColor);
    case PythonClassName:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonClassName", QColor);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonFunctionMethodName", QColor);
    case PythonOperator:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonOperator", QColor);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PythonIdentifier", QColor);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptStart", QColor);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptUniversal", QColor);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptComment", QColor);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptCommentLine", QColor);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptCommentDoc", QColor);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptNumber", QColor);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptWord", QColor);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptKeyword", QColor);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptDoubleQuotedString", QColor);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptSingleQuotedString", QColor);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptSymbol", QColor);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptUnclosedString", QColor);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPJavaScriptRegex", QColor);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPVBScriptStart", QColor);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPVBScriptUniversal", QColor);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPVBScriptComment", QColor);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPVBScriptNumber", QColor);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPVBScriptKeyword", QColor);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPVBScriptString", QColor);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPVBScriptIdentifier", QColor);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPVBScriptUnclosedString", QColor);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonStart", QColor);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonUniversal", QColor);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonComment", QColor);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonNumber", QColor);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonDoubleQuotedString", QColor);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonKeyword", QColor);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonTripleSingleQuotedString", QColor);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonTripleDoubleQuotedString", QColor);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonClassName", QColor);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonFunctionMethodName", QColor);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonOperator", QColor);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Color/ASPPythonIdentifier", QColor);
    case PHPDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPUniversal", QColor);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPDoubleQuotedString", QColor);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPSingleQuotedString", QColor);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPKeyword", QColor);
    case PHPNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPNumber", QColor);
    case PHPVariable:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPVariable", QColor);
    case PHPComment:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPComment", QColor);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPCommentLine", QColor);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPDoubleQuotedVariable", QColor);
    case PHPOperator:
        return GET_SETTINGS("Lexer/HTMLFull/Color/PHPOperator", QColor);
    }

    return TpFamilyHTMLLexer::defaultColor(style);
}

bool TpLexerHTMLFull::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/Universal", bool);
    case Tag:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLTag", bool);
    case UnknownTag:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLUnknownTag", bool);
    case Attribute:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLAttribute", bool);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLUnknownAttribute", bool);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLNumber", bool);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLDoubleQuotedString", bool);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLSingleQuotedString", bool);
    case OtherInTag:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLOtherInTag", bool);
    case HTMLComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLComment", bool);
    case Entity:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLEntity", bool);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/XMLTagEnd", bool);
    case XMLStart:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/XMLStart", bool);
    case XMLEnd:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/XMLEnd", bool);
    case Script:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/Script", bool);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPAtStart", bool);
    case ASPStart:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPStart", bool);
    case CDATA:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/CDATA", bool);
    case PHPStart:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPStart", bool);
    case HTMLValue:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/HTMLValue", bool);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPXCComment", bool);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/SGMLUniversal", bool);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/SGMLCommand", bool);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/SGMLParameter", bool);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/SGMLDoubleQuotedString", bool);
    case SGMLError:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/SGMLError", bool);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/SGMLSpecial", bool);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/SGMLEntity", bool);
    case SGMLComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/SGMLComment", bool);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/SGMLParameterComment", bool);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/SGMLBlockUniversal", bool);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptStart", bool);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptUniversal", bool);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptComment", bool);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptCommentLine", bool);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptCommentDoc", bool);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptNumber", bool);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptWord", bool);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptKeyword", bool);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptDoubleQuotedString", bool);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptSingleQuotedString", bool);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptSymbol", bool);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptUnclosedString", bool);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/JavaScriptRegex", bool);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/VBScriptStart", bool);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/VBScriptUniversal", bool);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/VBScriptComment", bool);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/VBScriptNumber", bool);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/VBScriptKeyword", bool);
    case VBScriptString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/VBScriptString", bool);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/VBScriptIdentifier", bool);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/VBScriptUnclosedString", bool);
    case PythonStart:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonStart", bool);
    case PythonDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonUniversal", bool);
    case PythonComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonComment", bool);
    case PythonNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonNumber", bool);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonDoubleQuotedString", bool);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonKeyword", bool);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonTripleSingleQuotedString", bool);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonTripleDoubleQuotedString", bool);
    case PythonClassName:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonClassName", bool);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonFunctionMethodName", bool);
    case PythonOperator:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonOperator", bool);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PythonIdentifier", bool);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptStart", bool);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptUniversal", bool);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptComment", bool);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptCommentLine", bool);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptCommentDoc", bool);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptNumber", bool);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptWord", bool);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptKeyword", bool);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptDoubleQuotedString", bool);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptSingleQuotedString", bool);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptSymbol", bool);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptUnclosedString", bool);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPJavaScriptRegex", bool);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPVBScriptStart", bool);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPVBScriptUniversal", bool);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPVBScriptComment", bool);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPVBScriptNumber", bool);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPVBScriptKeyword", bool);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPVBScriptString", bool);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPVBScriptIdentifier", bool);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPVBScriptUnclosedString", bool);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonStart", bool);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonUniversal", bool);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonComment", bool);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonNumber", bool);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonDoubleQuotedString", bool);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonKeyword", bool);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonTripleSingleQuotedString", bool);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonTripleDoubleQuotedString", bool);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonClassName", bool);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonFunctionMethodName", bool);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonOperator", bool);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/ASPPythonIdentifier", bool);
    case PHPDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPUniversal", bool);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPDoubleQuotedString", bool);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPSingleQuotedString", bool);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPKeyword", bool);
    case PHPNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPNumber", bool);
    case PHPVariable:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPVariable", bool);
    case PHPComment:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPComment", bool);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPCommentLine", bool);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPDoubleQuotedVariable", bool);
    case PHPOperator:
        return GET_SETTINGS("Lexer/HTMLFull/Fill/PHPOperator", bool);
    }

    return TpFamilyHTMLLexer::defaultEolFill(style);
}

QFont TpLexerHTMLFull::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/HTMLFull/Font/Universal", QFont);
    case Tag:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLTag", QFont);
    case UnknownTag:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLUnknownTag", QFont);
    case Attribute:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLAttribute", QFont);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLUnknownAttribute", QFont);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLNumber", QFont);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLDoubleQuotedString", QFont);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLSingleQuotedString", QFont);
    case OtherInTag:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLOtherInTag", QFont);
    case HTMLComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLComment", QFont);
    case Entity:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLEntity", QFont);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/HTMLFull/Font/XMLTagEnd", QFont);
    case XMLStart:
        return GET_SETTINGS("Lexer/HTMLFull/Font/XMLStart", QFont);
    case XMLEnd:
        return GET_SETTINGS("Lexer/HTMLFull/Font/XMLEnd", QFont);
    case Script:
        return GET_SETTINGS("Lexer/HTMLFull/Font/Script", QFont);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPAtStart", QFont);
    case ASPStart:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPStart", QFont);
    case CDATA:
        return GET_SETTINGS("Lexer/HTMLFull/Font/CDATA", QFont);
    case PHPStart:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPStart", QFont);
    case HTMLValue:
        return GET_SETTINGS("Lexer/HTMLFull/Font/HTMLValue", QFont);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPXCComment", QFont);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Font/SGMLUniversal", QFont);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/HTMLFull/Font/SGMLCommand", QFont);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/HTMLFull/Font/SGMLParameter", QFont);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/SGMLDoubleQuotedString", QFont);
    case SGMLError:
        return GET_SETTINGS("Lexer/HTMLFull/Font/SGMLError", QFont);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/HTMLFull/Font/SGMLSpecial", QFont);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/HTMLFull/Font/SGMLEntity", QFont);
    case SGMLComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/SGMLComment", QFont);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/SGMLParameterComment", QFont);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Font/SGMLBlockUniversal", QFont);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptStart", QFont);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptUniversal", QFont);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptComment", QFont);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptCommentLine", QFont);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptCommentDoc", QFont);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptNumber", QFont);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptWord", QFont);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptKeyword", QFont);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptDoubleQuotedString", QFont);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptSingleQuotedString", QFont);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptSymbol", QFont);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptUnclosedString", QFont);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/HTMLFull/Font/JavaScriptRegex", QFont);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Font/VBScriptStart", QFont);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Font/VBScriptUniversal", QFont);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/VBScriptComment", QFont);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Font/VBScriptNumber", QFont);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Font/VBScriptKeyword", QFont);
    case VBScriptString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/VBScriptString", QFont);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Font/VBScriptIdentifier", QFont);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/VBScriptUnclosedString", QFont);
    case PythonStart:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonStart", QFont);
    case PythonDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonUniversal", QFont);
    case PythonComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonComment", QFont);
    case PythonNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonNumber", QFont);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonDoubleQuotedString", QFont);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonKeyword", QFont);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonTripleSingleQuotedString", QFont);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonTripleDoubleQuotedString", QFont);
    case PythonClassName:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonClassName", QFont);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonFunctionMethodName", QFont);
    case PythonOperator:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonOperator", QFont);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PythonIdentifier", QFont);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptStart", QFont);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptUniversal", QFont);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptComment", QFont);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptCommentLine", QFont);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptCommentDoc", QFont);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptNumber", QFont);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptWord", QFont);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptKeyword", QFont);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptDoubleQuotedString", QFont);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptSingleQuotedString", QFont);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptSymbol", QFont);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptUnclosedString", QFont);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPJavaScriptRegex", QFont);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPVBScriptStart", QFont);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPVBScriptUniversal", QFont);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPVBScriptComment", QFont);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPVBScriptNumber", QFont);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPVBScriptKeyword", QFont);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPVBScriptString", QFont);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPVBScriptIdentifier", QFont);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPVBScriptUnclosedString", QFont);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonStart", QFont);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonUniversal", QFont);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonComment", QFont);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonNumber", QFont);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonDoubleQuotedString", QFont);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonKeyword", QFont);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonTripleSingleQuotedString", QFont);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonTripleDoubleQuotedString", QFont);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonClassName", QFont);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonFunctionMethodName", QFont);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonOperator", QFont);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/Font/ASPPythonIdentifier", QFont);
    case PHPDefault:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPUniversal", QFont);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPDoubleQuotedString", QFont);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPSingleQuotedString", QFont);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPKeyword", QFont);
    case PHPNumber:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPNumber", QFont);
    case PHPVariable:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPVariable", QFont);
    case PHPComment:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPComment", QFont);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPCommentLine", QFont);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPDoubleQuotedVariable", QFont);
    case PHPOperator:
        return GET_SETTINGS("Lexer/HTMLFull/Font/PHPOperator", QFont);
    }

    return TpFamilyHTMLLexer::defaultFont(style);
}

QColor TpLexerHTMLFull::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPAtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPStart", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPXCComment", QColor);
    case SGMLDefault:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/SGMLUniversal", QColor);
    case SGMLCommand:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/SGMLCommand", QColor);
    case SGMLParameter:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/SGMLParameter", QColor);
    case SGMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/SGMLDoubleQuotedString", QColor);
    case SGMLError:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/SGMLError", QColor);
    case SGMLSpecial:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/SGMLSpecial", QColor);
    case SGMLEntity:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/SGMLEntity", QColor);
    case SGMLComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/SGMLComment", QColor);
    case SGMLParameterComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/SGMLParameterComment", QColor);
    case SGMLBlockDefault:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/SGMLBlockUniversal", QColor);
    case JavaScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptStart", QColor);
    case JavaScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptUniversal", QColor);
    case JavaScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptComment", QColor);
    case JavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptCommentLine", QColor);
    case JavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptCommentDoc", QColor);
    case JavaScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptNumber", QColor);
    case JavaScriptWord:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptWord", QColor);
    case JavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptKeyword", QColor);
    case JavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptDoubleQuotedString", QColor);
    case JavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptSingleQuotedString", QColor);
    case JavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptSymbol", QColor);
    case JavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptUnclosedString", QColor);
    case JavaScriptRegex:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/JavaScriptRegex", QColor);
    case VBScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/VBScriptStart", QColor);
    case VBScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/VBScriptUniversal", QColor);
    case VBScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/VBScriptComment", QColor);
    case VBScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/VBScriptNumber", QColor);
    case VBScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/VBScriptKeyword", QColor);
    case VBScriptString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/VBScriptString", QColor);
    case VBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/VBScriptIdentifier", QColor);
    case VBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/VBScriptUnclosedString", QColor);
    case PythonStart:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonStart", QColor);
    case PythonDefault:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonUniversal", QColor);
    case PythonComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonComment", QColor);
    case PythonNumber:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonNumber", QColor);
    case PythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonDoubleQuotedString", QColor);
    case PythonKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonKeyword", QColor);
    case PythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonTripleSingleQuotedString", QColor);
    case PythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonTripleDoubleQuotedString", QColor);
    case PythonClassName:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonClassName", QColor);
    case PythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonFunctionMethodName", QColor);
    case PythonOperator:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonOperator", QColor);
    case PythonIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PythonIdentifier", QColor);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptStart", QColor);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptUniversal", QColor);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptComment", QColor);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptCommentLine", QColor);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptCommentDoc", QColor);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptNumber", QColor);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptWord", QColor);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptKeyword", QColor);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptDoubleQuotedString", QColor);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptSingleQuotedString", QColor);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptSymbol", QColor);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptUnclosedString", QColor);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPJavaScriptRegex", QColor);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPVBScriptStart", QColor);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPVBScriptUniversal", QColor);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPVBScriptComment", QColor);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPVBScriptNumber", QColor);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPVBScriptKeyword", QColor);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPVBScriptString", QColor);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPVBScriptIdentifier", QColor);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPVBScriptUnclosedString", QColor);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonStart", QColor);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonUniversal", QColor);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonComment", QColor);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonNumber", QColor);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonDoubleQuotedString", QColor);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonKeyword", QColor);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonTripleSingleQuotedString", QColor);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonTripleDoubleQuotedString", QColor);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonClassName", QColor);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonFunctionMethodName", QColor);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonOperator", QColor);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/ASPPythonIdentifier", QColor);
    case PHPDefault:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPUniversal", QColor);
    case PHPDoubleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPDoubleQuotedString", QColor);
    case PHPSingleQuotedString:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPSingleQuotedString", QColor);
    case PHPKeyword:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPKeyword", QColor);
    case PHPNumber:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPNumber", QColor);
    case PHPVariable:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPVariable", QColor);
    case PHPComment:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPComment", QColor);
    case PHPCommentLine:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPCommentLine", QColor);
    case PHPDoubleQuotedVariable:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPDoubleQuotedVariable", QColor);
    case PHPOperator:
        return GET_SETTINGS("Lexer/HTMLFull/BgColor/PHPOperator", QColor);
    }

    return TpFamilyHTMLLexer::defaultColor(style);
}

const char *TpLexerHTMLFull::keywords(int set) const
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
