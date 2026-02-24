#ifndef TPGENERALLEXER_H
#define TPGENERALLEXER_H

#include <Qsci/qscilexer.h>

#include <TpGlobals>

TP_NAMESPACE

inline const char *lexerGeneralDoxygen =
"a addindex addtogroup anchor arg attention author authors b brief bug c callergraph callgraph category cite class "
"code collaborationgraph concept cond copybrief copydoc copyright date def defgroup deprecated details diafile dir "
"directorygraph docbookinclude docbookonly dontinclude dot dotfile doxyconfig e else elseif em emoji endcode endcond "
"enddocbookonly enddot endhtmlonly endif endinternal endlatexonly endlink endmanonly endmsc endparblock endrtfonly "
"endsecreflist endverbatim enduml endxmlonly enum example exception extends f( f) f$ f[ f] f{ f} file fileinfo fn "
"groupgraph headerfile hidecallergraph hidecallgraph hidecollaborationgraph hidedirectorygraph hideenumvalues "
"hidegroupgraph hideincludebygraph hideincludegraph hideinheritancegraph hideinlinesource hiderefby hiderefs "
"hideinitializer htmlinclude  htmlonly idlexcept if ifnot image implements important include includedoc "
"includedbygraph includegraph includelineno ingroup inheritancegraph internal invariant interface latexinclude "
"latexonly li line lineinfo link mainpage maninclude manonly memberof module msc mscfile n name namespace noop "
"nosubgrouping note overload p package page par paragraph param parblock post pre private privatesection property "
"protected protectedsection protocol public publicsection pure qualifier raisewarning ref refitem related relates "
"relatedalso relatesalso remark remarks result return retval rtfinclude rtfonly sa secreflist section see short "
"showdate showenumvalues showinitializer showinlinesource showrefby showrefs since skip skipline snippet snippetdoc "
"snippetlineno static startuml struct subpage subparagraph subsection subsubparagraph subsubsection tableofcontents "
"test throw throws todo tparam typedef plantumfile union until var verbatim verbinclude version vhdlflow warning "
"weakgroup xmlinclude xmlonly xrefitem $ @ \\ & ~ < > # % \" . :: | -- ---";

inline const char *lexerHTMLKeyword1 =
"a abbr acronym address area article aside audio b base bdi bdo big blockquote body br button canvas caption center "
"cite code col colgroup data datalist dd del details dfn dialog dir div dl dt em embed fencedframe fieldset figcaption "
"figure font footer form frame frameset h1 h2 h3 h4 h5 h6 head header hgroup hr html i iframe img input ins kbd label "
"legend li link main map mark marquee menu meta meter nav nobr noembed noframes noscript object ol optgroup option "
"output p param picture plaintext portal pre progress q rb rp rt rtc ruby s samp script search section select slot "
"small source span strike strong style sub table tbody td template textarea tfoot th thead time title tr track tt u ul "
"var video wbr xmp"
" "
"!doctype abbr accept accept-charset accesskey action align alink alt applet archive axis b background basefont "
"bgcolor border caption cellpadding cellspacing char charoff charset checkbox checked cite classid clear codebase "
"codetype color cols colspan compact content coords data datafld dataformatas datapagesize datasrc datetime dd declare "
"defer em enctype event face fieldset file frameborder h1 headers height hidden href hreflang hspace http-equiv i id "
"image isindex ismap kbd label language leftmargin legend longdesc map marginheight marginwidth media method multiple "
"name noframes nohref noresize noshade nowrap object onblur onchange onclick ondblclick onfocus onkeydown onkeypress "
"onkeyup onload onmousedown onmousemove onmouseout onmouseover onmouseup onreset onselect onsubmit onunload p password "
"p password profile prompt public q radio readonly reset rev rows rowspan rules s scheme scope selected shape small "
"src standby start sub submit summary sup tabindex table target text topmargin u usemap valign value valuetype version "
"vlink vspace width xml xmlns"
" "
"onafterprint onbeforeprint onbeforeunload onerror onhashchange onload onmessage onoffline ononline onpagehide "
"onpageshow onpopstate onresize onstorage onunload onblur onchange oncontextmenu onfocus oninput oninvalid onrest "
"onsearch onselect onsubmit onkeydown onkeypress onkeyup onclick ondblclick onmousedown onmousemove onmouseout "
"onmouseover onmouseup onmousewheel onwheel ondrag ondragend ondragenter ondragleave ondragover ondragstart ondrop "
"onscroll oncopy oncut onpaste onabort oncanplay oncanplaythrough oncuechange ondurationchange onemptied onended "
"onerror onloadeddata onloadedmetadata onloadstart onpause onplay onplaying onprogress onratechange onseeked onseeking "
"onstalled onsuspend ontimeupdate onvolumechange onwaiting ontoggle"
" "
"accesskey anchor autocapitalize autocorrect autofocus class contenteditable data dir draggable enterkeyhint "
"exportparts hidden id inert inputmode is itemid itemprop itemref itemscope itemtype lang nonce part popover slot "
"spellcheck style tabindex title translate virtualkeyboardpolicy writingsuggestions"
" "
"accept autocomplete capture crossorigin dirname disabled elementtiming for max maxlength min minlength multiple "
"pattern placeholder readonly rel required size step type";

// lexerHTMLKeyword2 == lexerJavaScriptKeyword1

inline const char *lexerHTMLKeyword3 =
"AddHandler AddressOf Alias And AndAlso As Boolean ByRef Byte ByVal Call Case Catch CBool CByte CChar CDate CDbl CDec "
"Char CInt Class CLng CObj Const Continue CSByte CShort CSng CStr CType CUInt CULng CUShort Date Decimal Declare "
"Default Delegate Dim DirectCast Do Double Each Else ElseIf End EndIf Enum Erase Error Event Exit False Finally For "
"Friend Function Get GetType GetXMLNamespace Global GoSub GoTo Handles If Implements Imports In Inherits Integer "
"Interface Is IsNot Let Lib Like Long Loop Me Mod Module MoustInherit MustOverride MyBase MyClass NameOf Namespace "
"Narrowing New Next Not Nothing NotInheritable NotOverridable Object Of On Operator Option Optional Or OrElse Out "
"Overloads Overridable ParamArray Partial Private Property Protected Public RaiseEvent ReadOnly ReDim REM "
"RemoveHandler Resume Return SByte Select Set Shadows Shared Short Single Static Step Stop String Structure Sub "
"SyncLock Then Throw To True Try TryCast TypeOf UInteger ULong UShort Using Variant Wend While Widening With "
"WithEvents WriteOnly Xor ";

// lexerHTMLKeyword4 == lexerPythonKeyword1

inline const char *lexerHTMLKeyword5 =
"__halt_compiler abstract and array as break callable case catch class clone const continue declare default die do "
"echo else elseif empty enddeclare endfor endforeach endif endswitch endwhile eval exit extends final finally fn for "
"foreach from function global goto if implements inlcude include_once instanceof insteadof interface isset list match "
"namespace new or print private protected public readonly require require_once return static switch throw trait try "
"unset use var while xor yield"
" "
"__CLASS__ __DIR__ __FILE__ __FUNCTION__ __LINE__ __METHOD__ __NAMESPACE__ __TRAIT__";

inline const char *lexerHTMLKeyword6 =
"DOCTYPE ELEMENT ATTLIST"
" "
"CDATA ID IDREF IDREFS NMTOKEN NMTOKENS ENTITY ENTITIES NOTATION xml REQUIRED IMPLIED FIXED";

inline const char *lexerHTMLIncompleteKeyword1 =
"a abbr acronym address area article aside audio b base bdi bdo big blockquote body br button canvas caption center "
"cite code col colgroup data datalist dd del details dfn dialog dir div dl dt em embed fencedframe fieldset figcaption "
"figure font footer form frame frameset h1 h2 h3 h4 h5 h6 head header hgroup hr html i iframe img input ins kbd label "
"legend li link main map mark marquee menu meta meter nav nobr noembed noframes noscript object ol optgroup option "
"output p param picture plaintext portal pre progress q rb rp rt rtc ruby s samp script search section select slot "
"small source span strike strong style sub table tbody td template textarea tfoot th thead time title tr track tt u ul "
"var video wbr xmp";

inline const char *lexerJavaScriptKeyword1 =
"abstract arguments await boolean break byte case catch char class const continue debugger default delete do double "
"else enum eval export extends false final finally float for function goto if implements import in instanceof int "
"interface let long native new null package private protected public return short static super switch synchronized "
"this throw throws transient true try typeof var void volatile while with yield";

inline const char *lexerPythonKeyword1 =
"False None True and as assert async await break class continue def del elif else except finally for from global if "
"import in is lambda nonlocal not or pass raise return try while with yield __debug__";

inline const char *lexerPython2Keyword1 =
"and as assert break class continue def del elif else except exec finally for from global if import in is lambda not "
"or pass print raise return try while with yield";

inline const char *lexerPython2Keyword2 =
"abs all any basestring bin bool bytearray callable chr classmethod cmp compile complex delattr dict dir divmod "
"enumerate eval execfile file filter float format frozenset getattr globals hasattr hash help hex id input int "
"isinstance issubclass iter len list locals long map max memoryview min next object oct open ord pow print property "
"range raw_input reduce reload repr reversed round set setattr slice sorted staticmethod str sum super tuple type "
"unichr unicode vars xrange zip __import__"
" "
"apply buffer coerce intern"
" "
"int float long complex None True False iterator buffer"
" "
"BaseException SystemExit KeyboardInterrupt GeneratorExit Exception StopIteration StandardError BufferError "
"ArithmeticError FloatingPointError OverflowError ZeroDivisionError AssertionError AttributeError EnvironmentError "
"IOError OSError WindowsError VMSError EOFError ImportError LookupError IndexError KeyError MemoryError NameError "
"UnboundLocalError ReferenceError RuntimeError NotImplementedError SyntaxError IndentationError TabError SystemError "
"TypeError ValueError UnicodeError UnicodeDecodeError UnicodeEncodeError UnicodeTranslateError Warning "
"DeprecationWarning PendingDeprecationWarning RuntimeWarning SyntaxWarning UserWarning FutureWarning ImportWarning "
"UnicodeWarning BytesWarning";

inline const char *lexerPythonKeyword2 =
"ArithmeticError AssertionError AttributeError BaseException BaseExceptionGroup BlockingIOError BrokenPipeError "
"BufferError BytesWarning ChildProcessError ConnectionAbortedError ConnectionError ConnectionRefusedError "
"ConnectionResetError DeprecationWarning EOFError Ellipsis EncodingWarning EnvironmentError Exception ExceptionGroup "
"False FileExistsError FileNotFoundError FloatingPointError FutureWarning GeneratorExit IOError ImportError "
"ImportWarning IndentationError IndexError InterruptedError IsADirectoryError KeyError KeyboardInterrupt LookupError "
"MemoryError ModuleNotFoundError NameError None NotADirectoryError NotImplemented NotImplementedError OSError "
"OverflowError PendingDeprecationWarning PermissionError ProcessLookupError RecursionError ReferenceError "
"ResourceWarning RuntimeError RuntimeWarning StopAsyncIteration StopIteration SyntaxError SyntaxWarning SystemError "
"SystemExit TabError TimeoutError True TypeError UnboundLocalError UnicodeDecodeError UnicodeEncodeError UnicodeError "
"UnicodeTranslateError UnicodeWarning UserWarning ValueError Warning WindowsError ZeroDivisionError abs aiter all "
"anext any ascii bin bool breakpoint bytearray bytes callable chr classmethod compile complex copyright credits "
"delattr dict dir divmod enumerate eval exec exit filter float format frozenset getattr globals hasattr hash help hex "
"id input int isinstance issubclass iter len license list locals map max memoryview min next object oct open ord pow "
"print property quit range repr reversed round set setattr slice sorted staticmethod str sum super tuple type vars zip";

inline const char *lexerPythonExtendedKeyword1 =
"False None True and as assert async await break class continue def del elif else except finally for from global if "
"import in is lambda nonlocal not or pass raise return try while with yield __debug__"
" "
"match case";

inline const char *lexerPythonExtendedKeyword2 =
"ArithmeticError AssertionError AttributeError BaseException BaseExceptionGroup BlockingIOError BrokenPipeError "
"BufferError BytesWarning ChildProcessError ConnectionAbortedError ConnectionError ConnectionRefusedError "
"ConnectionResetError DeprecationWarning EOFError Ellipsis EncodingWarning EnvironmentError Exception ExceptionGroup "
"False FileExistsError FileNotFoundError FloatingPointError FutureWarning GeneratorExit IOError ImportError "
"ImportWarning IndentationError IndexError InterruptedError IsADirectoryError KeyError KeyboardInterrupt LookupError "
"MemoryError ModuleNotFoundError NameError None NotADirectoryError NotImplemented NotImplementedError OSError "
"OverflowError PendingDeprecationWarning PermissionError ProcessLookupError RecursionError ReferenceError "
"ResourceWarning RuntimeError RuntimeWarning StopAsyncIteration StopIteration SyntaxError SyntaxWarning SystemError "
"SystemExit TabError TimeoutError True TypeError UnboundLocalError UnicodeDecodeError UnicodeEncodeError UnicodeError "
"UnicodeTranslateError UnicodeWarning UserWarning ValueError Warning WindowsError ZeroDivisionError abs aiter all "
"anext any ascii bin bool breakpoint bytearray bytes callable chr classmethod compile complex copyright credits "
"delattr dict dir divmod enumerate eval exec exit filter float format frozenset getattr globals hasattr hash help hex "
"id input int isinstance issubclass iter len license list locals map max memoryview min next object oct open ord pow "
"print property quit range repr reversed round set setattr slice sorted staticmethod str sum super tuple type vars zip";

// lexerQUIKeyword[2...6] == lexerHTMLKeyword[2...6]

class QSCINTILLA_EXPORT TpGeneralLexer : public QsciLexer
{
    Q_OBJECT

protected:
    TpGeneralLexer(QObject *parent = nullptr);

public:
    virtual int blockLookback() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    virtual void setLexerProperty(int prop, QVariant value);
    virtual QVariant lexerProperty(int prop) const;

    QByteArray textAsBytes(const QString &text) const;
    QString bytesAsText(const QByteArray &bytes) const;
};

TP_END_NAMESPACE

#endif // TPGENERALLEXER_H
