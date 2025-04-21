#include <Lexers/TpLexerASP>

TP_NAMESPACE

TpLexerASP::TpLexerASP(QObject *parent)
    : TpFamilyHTMLLexer(parent)
{}

const char *TpLexerASP::language() const
{
    return "HTML/ASP";
}

QColor TpLexerASP::defaultColor(int style) const
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
        return GET_SETTINGS("Lexer/ASP/Color/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/ASP/Color/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/ASP/Color/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/ASP/Color/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/ASP/Color/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/ASP/Color/AtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/ASP/Color/Start", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/ASP/Color/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/ASP/Color/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/ASP/Color/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/ASP/Color/XCComment", QColor);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptStart", QColor);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptUniversal", QColor);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptComment", QColor);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptCommentLine", QColor);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptCommentDoc", QColor);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptNumber", QColor);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptWord", QColor);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptKeyword", QColor);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptDoubleQuotedString", QColor);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptSingleQuotedString", QColor);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptSymbol", QColor);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptUnclosedString", QColor);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/ASP/Color/JavaScriptRegex", QColor);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/ASP/Color/VBScriptStart", QColor);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/ASP/Color/VBScriptUniversal", QColor);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/ASP/Color/VBScriptComment", QColor);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/ASP/Color/VBScriptNumber", QColor);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/ASP/Color/VBScriptKeyword", QColor);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/ASP/Color/VBScriptString", QColor);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/ASP/Color/VBScriptIdentifier", QColor);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/ASP/Color/VBScriptUnclosedString", QColor);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/ASP/Color/PythonStart", QColor);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/ASP/Color/PythonUniversal", QColor);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/ASP/Color/PythonComment", QColor);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/ASP/Color/PythonNumber", QColor);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Color/PythonDoubleQuotedString", QColor);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/ASP/Color/PythonKeyword", QColor);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Color/PythonTripleSingleQuotedString", QColor);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Color/PythonTripleDoubleQuotedString", QColor);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/ASP/Color/PythonClassName", QColor);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/ASP/Color/PythonFunctionMethodName", QColor);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/ASP/Color/PythonOperator", QColor);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/ASP/Color/PythonIdentifier", QColor);
    }

    return TpFamilyHTMLLexer::defaultColor(style);
}

bool TpLexerASP::defaultEolFill(int style) const
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
        return GET_SETTINGS("Lexer/ASP/Fill/Universal", bool);
    case Tag:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLTag", bool);
    case UnknownTag:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLUnknownTag", bool);
    case Attribute:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLAttribute", bool);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLUnknownAttribute", bool);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLNumber", bool);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLDoubleQuotedString", bool);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLSingleQuotedString", bool);
    case OtherInTag:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLOtherInTag", bool);
    case HTMLComment:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLComment", bool);
    case Entity:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLEntity", bool);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/ASP/Fill/XMLTagEnd", bool);
    case XMLStart:
        return GET_SETTINGS("Lexer/ASP/Fill/XMLStart", bool);
    case XMLEnd:
        return GET_SETTINGS("Lexer/ASP/Fill/XMLEnd", bool);
    case Script:
        return GET_SETTINGS("Lexer/ASP/Fill/Script", bool);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/ASP/Fill/AtStart", bool);
    case ASPStart:
        return GET_SETTINGS("Lexer/ASP/Fill/Start", bool);
    case CDATA:
        return GET_SETTINGS("Lexer/ASP/Fill/CDATA", bool);
    case PHPStart:
        return GET_SETTINGS("Lexer/ASP/Fill/PHPStart", bool);
    case HTMLValue:
        return GET_SETTINGS("Lexer/ASP/Fill/HTMLValue", bool);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/ASP/Fill/XCComment", bool);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptStart", bool);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptUniversal", bool);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptComment", bool);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptCommentLine", bool);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptCommentDoc", bool);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptNumber", bool);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptWord", bool);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptKeyword", bool);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptDoubleQuotedString", bool);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptSingleQuotedString", bool);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptSymbol", bool);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptUnclosedString", bool);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/ASP/Fill/JavaScriptRegex", bool);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/ASP/Fill/VBScriptStart", bool);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/ASP/Fill/VBScriptUniversal", bool);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/ASP/Fill/VBScriptComment", bool);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/ASP/Fill/VBScriptNumber", bool);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/ASP/Fill/VBScriptKeyword", bool);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/ASP/Fill/VBScriptString", bool);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/ASP/Fill/VBScriptIdentifier", bool);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/ASP/Fill/VBScriptUnclosedString", bool);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonStart", bool);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonUniversal", bool);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonComment", bool);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonNumber", bool);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonDoubleQuotedString", bool);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonKeyword", bool);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonTripleSingleQuotedString", bool);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonTripleDoubleQuotedString", bool);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonClassName", bool);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonFunctionMethodName", bool);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonOperator", bool);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/ASP/Fill/PythonIdentifier", bool);
    }

    return TpFamilyHTMLLexer::defaultEolFill(style);
}

QFont TpLexerASP::defaultFont(int style) const
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
        return GET_SETTINGS("Lexer/ASP/Font/Universal", QFont);
    case Tag:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLTag", QFont);
    case UnknownTag:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLUnknownTag", QFont);
    case Attribute:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLAttribute", QFont);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLUnknownAttribute", QFont);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLNumber", QFont);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLDoubleQuotedString", QFont);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLSingleQuotedString", QFont);
    case OtherInTag:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLOtherInTag", QFont);
    case HTMLComment:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLComment", QFont);
    case Entity:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLEntity", QFont);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/ASP/Font/XMLTagEnd", QFont);
    case XMLStart:
        return GET_SETTINGS("Lexer/ASP/Font/XMLStart", QFont);
    case XMLEnd:
        return GET_SETTINGS("Lexer/ASP/Font/XMLEnd", QFont);
    case Script:
        return GET_SETTINGS("Lexer/ASP/Font/Script", QFont);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/ASP/Font/AtStart", QFont);
    case ASPStart:
        return GET_SETTINGS("Lexer/ASP/Font/Start", QFont);
    case CDATA:
        return GET_SETTINGS("Lexer/ASP/Font/CDATA", QFont);
    case PHPStart:
        return GET_SETTINGS("Lexer/ASP/Font/PHPStart", QFont);
    case HTMLValue:
        return GET_SETTINGS("Lexer/ASP/Font/HTMLValue", QFont);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/ASP/Font/XCComment", QFont);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptStart", QFont);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptUniversal", QFont);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptComment", QFont);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptCommentLine", QFont);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptCommentDoc", QFont);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptNumber", QFont);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptWord", QFont);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptKeyword", QFont);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptDoubleQuotedString", QFont);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptSingleQuotedString", QFont);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptSymbol", QFont);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptUnclosedString", QFont);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/ASP/Font/JavaScriptRegex", QFont);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/ASP/Font/VBScriptStart", QFont);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/ASP/Font/VBScriptUniversal", QFont);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/ASP/Font/VBScriptComment", QFont);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/ASP/Font/VBScriptNumber", QFont);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/ASP/Font/VBScriptKeyword", QFont);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/ASP/Font/VBScriptString", QFont);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/ASP/Font/VBScriptIdentifier", QFont);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/ASP/Font/VBScriptUnclosedString", QFont);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/ASP/Font/PythonStart", QFont);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/ASP/Font/PythonUniversal", QFont);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/ASP/Font/PythonComment", QFont);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/ASP/Font/PythonNumber", QFont);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Font/PythonDoubleQuotedString", QFont);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/ASP/Font/PythonKeyword", QFont);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Font/PythonTripleSingleQuotedString", QFont);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/Font/PythonTripleDoubleQuotedString", QFont);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/ASP/Font/PythonClassName", QFont);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/ASP/Font/PythonFunctionMethodName", QFont);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/ASP/Font/PythonOperator", QFont);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/ASP/Font/PythonIdentifier", QFont);
    }

    return TpFamilyHTMLLexer::defaultFont(style);
}

QColor TpLexerASP::defaultPaper(int style) const
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
        return GET_SETTINGS("Lexer/ASP/BgColor/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/ASP/BgColor/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/ASP/BgColor/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/ASP/BgColor/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/ASP/BgColor/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/ASP/BgColor/AtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/ASP/BgColor/Start", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/ASP/BgColor/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/ASP/BgColor/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/ASP/BgColor/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/ASP/BgColor/XCComment", QColor);
    case ASPJavaScriptStart:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptStart", QColor);
    case ASPJavaScriptDefault:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptUniversal", QColor);
    case ASPJavaScriptComment:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptComment", QColor);
    case ASPJavaScriptCommentLine:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptCommentLine", QColor);
    case ASPJavaScriptCommentDoc:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptCommentDoc", QColor);
    case ASPJavaScriptNumber:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptNumber", QColor);
    case ASPJavaScriptWord:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptWord", QColor);
    case ASPJavaScriptKeyword:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptKeyword", QColor);
    case ASPJavaScriptDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptDoubleQuotedString", QColor);
    case ASPJavaScriptSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptSingleQuotedString", QColor);
    case ASPJavaScriptSymbol:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptSymbol", QColor);
    case ASPJavaScriptUnclosedString:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptUnclosedString", QColor);
    case ASPJavaScriptRegex:
        return GET_SETTINGS("Lexer/ASP/BgColor/JavaScriptRegex", QColor);
    case ASPVBScriptStart:
        return GET_SETTINGS("Lexer/ASP/BgColor/VBScriptStart", QColor);
    case ASPVBScriptDefault:
        return GET_SETTINGS("Lexer/ASP/BgColor/VBScriptUniversal", QColor);
    case ASPVBScriptComment:
        return GET_SETTINGS("Lexer/ASP/BgColor/VBScriptComment", QColor);
    case ASPVBScriptNumber:
        return GET_SETTINGS("Lexer/ASP/BgColor/VBScriptNumber", QColor);
    case ASPVBScriptKeyword:
        return GET_SETTINGS("Lexer/ASP/BgColor/VBScriptKeyword", QColor);
    case ASPVBScriptString:
        return GET_SETTINGS("Lexer/ASP/BgColor/VBScriptString", QColor);
    case ASPVBScriptIdentifier:
        return GET_SETTINGS("Lexer/ASP/BgColor/VBScriptIdentifier", QColor);
    case ASPVBScriptUnclosedString:
        return GET_SETTINGS("Lexer/ASP/BgColor/VBScriptUnclosedString", QColor);
    case ASPPythonStart:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonStart", QColor);
    case ASPPythonDefault:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonUniversal", QColor);
    case ASPPythonComment:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonComment", QColor);
    case ASPPythonNumber:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonNumber", QColor);
    case ASPPythonDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonDoubleQuotedString", QColor);
    case ASPPythonKeyword:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonKeyword", QColor);
    case ASPPythonTripleSingleQuotedString:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonTripleSingleQuotedString", QColor);
    case ASPPythonTripleDoubleQuotedString:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonTripleDoubleQuotedString", QColor);
    case ASPPythonClassName:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonClassName", QColor);
    case ASPPythonFunctionMethodName:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonFunctionMethodName", QColor);
    case ASPPythonOperator:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonOperator", QColor);
    case ASPPythonIdentifier:
        return GET_SETTINGS("Lexer/ASP/BgColor/PythonIdentifier", QColor);
    }

    return TpFamilyHTMLLexer::defaultPaper(style);
}

const char *TpLexerASP::keywords(int set) const
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
