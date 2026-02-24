#include <Lexers/TpLexerQUI>

TP_NAMESPACE

TpLexerQUI::TpLexerQUI(QObject *parent)
    : TpFamilyHTMLLexer(parent)
{}

const char *TpLexerQUI::language() const
{
    return "Qt UI Files";
}

QColor TpLexerQUI::defaultColor(int style) const
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
        return GET_SETTINGS("Lexer/QUI/Color/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/QUI/Color/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/QUI/Color/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/QUI/Color/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/QUI/Color/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/QUI/Color/ASPAtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/QUI/Color/ASPStart", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/QUI/Color/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/QUI/Color/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/QUI/Color/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/QUI/Color/ASPXCComment", QColor);
    }

    return TpFamilyHTMLLexer::defaultColor(style);
}

bool TpLexerQUI::defaultEolFill(int style) const
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
        return GET_SETTINGS("Lexer/QUI/Fill/Universal", bool);
    case Tag:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLTag", bool);
    case UnknownTag:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLUnknownTag", bool);
    case Attribute:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLAttribute", bool);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLUnknownAttribute", bool);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLNumber", bool);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLDoubleQuotedString", bool);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLSingleQuotedString", bool);
    case OtherInTag:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLOtherInTag", bool);
    case HTMLComment:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLComment", bool);
    case Entity:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLEntity", bool);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/QUI/Fill/XMLTagEnd", bool);
    case XMLStart:
        return GET_SETTINGS("Lexer/QUI/Fill/XMLStart", bool);
    case XMLEnd:
        return GET_SETTINGS("Lexer/QUI/Fill/XMLEnd", bool);
    case Script:
        return GET_SETTINGS("Lexer/QUI/Fill/Script", bool);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/QUI/Fill/ASPAtStart", bool);
    case ASPStart:
        return GET_SETTINGS("Lexer/QUI/Fill/ASPStart", bool);
    case CDATA:
        return GET_SETTINGS("Lexer/QUI/Fill/CDATA", bool);
    case PHPStart:
        return GET_SETTINGS("Lexer/QUI/Fill/PHPStart", bool);
    case HTMLValue:
        return GET_SETTINGS("Lexer/QUI/Fill/HTMLValue", bool);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/QUI/Fill/ASPXCComment", bool);
    }

    return TpFamilyHTMLLexer::defaultEolFill(style);
}

QFont TpLexerQUI::defaultFont(int style) const
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
        return GET_SETTINGS("Lexer/QUI/Font/Universal", QFont);
    case Tag:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLTag", QFont);
    case UnknownTag:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLUnknownTag", QFont);
    case Attribute:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLAttribute", QFont);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLUnknownAttribute", QFont);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLNumber", QFont);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLDoubleQuotedString", QFont);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLSingleQuotedString", QFont);
    case OtherInTag:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLOtherInTag", QFont);
    case HTMLComment:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLComment", QFont);
    case Entity:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLEntity", QFont);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/QUI/Font/XMLTagEnd", QFont);
    case XMLStart:
        return GET_SETTINGS("Lexer/QUI/Font/XMLStart", QFont);
    case XMLEnd:
        return GET_SETTINGS("Lexer/QUI/Font/XMLEnd", QFont);
    case Script:
        return GET_SETTINGS("Lexer/QUI/Font/Script", QFont);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/QUI/Font/ASPAtStart", QFont);
    case ASPStart:
        return GET_SETTINGS("Lexer/QUI/Font/ASPStart", QFont);
    case CDATA:
        return GET_SETTINGS("Lexer/QUI/Font/CDATA", QFont);
    case PHPStart:
        return GET_SETTINGS("Lexer/QUI/Font/PHPStart", QFont);
    case HTMLValue:
        return GET_SETTINGS("Lexer/QUI/Font/HTMLValue", QFont);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/QUI/Font/ASPXCComment", QFont);
    }

    return TpFamilyHTMLLexer::defaultFont(style);
}

QColor TpLexerQUI::defaultPaper(int style) const
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
        return GET_SETTINGS("Lexer/QUI/BgColor/Universal", QColor);
    case Tag:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLTag", QColor);
    case UnknownTag:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLUnknownTag", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLAttribute", QColor);
    case UnknownAttribute:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLUnknownAttribute", QColor);
    case HTMLNumber:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLNumber", QColor);
    case HTMLDoubleQuotedString:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLDoubleQuotedString", QColor);
    case HTMLSingleQuotedString:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLSingleQuotedString", QColor);
    case OtherInTag:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLOtherInTag", QColor);
    case HTMLComment:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLComment", QColor);
    case Entity:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLEntity", QColor);
    case XMLTagEnd:
        return GET_SETTINGS("Lexer/QUI/BgColor/XMLTagEnd", QColor);
    case XMLStart:
        return GET_SETTINGS("Lexer/QUI/BgColor/XMLStart", QColor);
    case XMLEnd:
        return GET_SETTINGS("Lexer/QUI/BgColor/XMLEnd", QColor);
    case Script:
        return GET_SETTINGS("Lexer/QUI/BgColor/Script", QColor);
    case ASPAtStart:
        return GET_SETTINGS("Lexer/QUI/BgColor/ASPAtStart", QColor);
    case ASPStart:
        return GET_SETTINGS("Lexer/QUI/BgColor/ASPStart", QColor);
    case CDATA:
        return GET_SETTINGS("Lexer/QUI/BgColor/CDATA", QColor);
    case PHPStart:
        return GET_SETTINGS("Lexer/QUI/BgColor/PHPStart", QColor);
    case HTMLValue:
        return GET_SETTINGS("Lexer/QUI/BgColor/HTMLValue", QColor);
    case ASPXCComment:
        return GET_SETTINGS("Lexer/QUI/BgColor/ASPXCComment", QColor);
    }

    return TpFamilyHTMLLexer::defaultPaper(style);
}

const char *TpLexerQUI::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerQUIKeyword1;
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
