#ifndef TPLEXERPOSTSCRIPT_H
#define TPLEXERPOSTSCRIPT_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerPostScriptKeyword1 =
"$error = == FontDirectory StandardEncoding UserObjects abs add aload anchorsearch and arc arcn arcto array ashow "
"astore atan awidthshow begin bind bitshift bytesavailable cachestatus ceiling charpath clear cleardictstack "
"cleartomark clip clippath closefile closepath concat concatmatrix copy copypage cos count countdictstack "
"countexecstack counttomark currentcmykcolor currentcolorspace currentdash currentdict currentfile currentflat "
"currentfont currentgray currenthsbcolor currentlinecap currentlinejoin currentlinewidth currentmatrix "
"currentmiterlimit currentpagedevice currentpoint currentrgbcolor currentscreen currenttransfer cvi cvlit cvn cvr cvrs "
"cvs cvx def defaultmatrix definefont dict dictstack div dtransform dup echo end eoclip eofill eq erasepage errordict "
"exch exec execstack executeonly executive exit exp false file fill findfont flattenpath floor flush flushfile for "
"forall ge get getinterval grestore grestoreall gsave gt idetmatrix idiv idtransform if ifelse image imagemask index "
"initclip initgraphics initmatrix inustroke invertmatrix itransform known kshow le length lineto ln load log loop lt "
"makefont mark matrix maxlength mod moveto mul ne neg newpath noaccess nor not null nulldevice or pathbbox pathforall "
"pop print prompt pstack put putinterval quit rand rcheck rcurveto read readhexstring readline readonly readstring "
"rectstroke repeat resetfile restore reversepath rlineto rmoveto roll rotate round rrand run save scale scalefont "
"search setblackgeneration setcachedevice setcachelimit setcharwidth setcolorscreen setcolortransfer setdash setflat "
"setfont setgray sethsbcolor setlinecap setlinejoin setlinewidth setmatrix setmiterlimit setpagedevice setrgbcolor "
"setscreen settransfer setvmthreshold show showpage sin sqrt srand stack start status statusdict stop stopped store "
"string stringwidth stroke strokepath sub systemdict token token transform translate true truncate type ueofill "
"undefineresource userdict usertime version vmstatus wcheck where widthshow write writehexstring writestring xcheck "
"xor";

inline const char *lexerPostScriptKeyword2 =
"GlobalFontDirectory ISOLatin1Encoding SharedFontDirectory UserObject arct colorimage cshow currentblackgeneration "
"currentcacheparams currentcmykcolor currentcolor currentcolorrendering currentcolorscreen currentcolorspace "
"currentcolortransfer currentdevparams currentglobal currentgstate currenthalftone currentobjectformat "
"currentoverprint currentpacking currentpagedevice currentshared currentstrokeadjust currentsystemparams "
"currentundercolorremoval currentuserparams defineresource defineuserobject deletefile execform execuserobject "
"filenameforall fileposition filter findencoding findresource gcheck globaldict glyphshow gstate ineofill infill "
"instroke inueofill inufill inustroke languagelevel makepattern packedarray printobject product realtime rectclip "
"rectfill rectstroke renamefile resourceforall resourcestatus revision rootfont scheck selectfont serialnumber setbbox "
"setblackgeneration setcachedevice2 setcacheparams setcmykcolor setcolor setcolorrendering setcolorscreen "
"setcolorspace setcolortranfer setdevparams setfileposition setglobal setgstate sethalftone setobjectformat "
"setoverprint setpacking setpagedevice setpattern setshared setstrokeadjust setsystemparams setucacheparams "
"setundercolorremoval setuserparams setvmthreshold shareddict startjob uappend ucache ucachestatus ueofill ufill undef "
"undefinefont undefineresource undefineuserobject upath ustroke ustrokepath vmreclaim writeobject xshow xyshow yshow";

inline const char *lexerPostScriptKeyword3 =
"cliprestore clipsave composefont currentsmoothness findcolorrendering setsmoothness shfill";

inline const char *lexerPostScriptKeyword4 =
".begintransparencygroup .begintransparencymask .bytestring .charboxpath .currentaccuratecurves .currentblendmode "
".currentcurvejoin .currentdashadapt .currentdotlength .currentfilladjust2 .currentlimitclamp .currentopacityalpha "
".currentoverprintmode .currentrasterop .currentshapealpha .currentsourcetransparent .currenttextknockout "
".currenttexturetransparent .dashpath .dicttomark .discardtransparencygroup .discardtransparencymask "
".endtransparencygroup .endtransparencymask .execn .filename .filename .fileposition .forceput .forceundef .forgetsave "
".getbitsrect .getdevice .inittransparencymask .knownget .locksafe .makeoperator .namestring .oserrno .oserrorstring "
".peekstring .rectappend .runandhide .setaccuratecurves .setblendmode .setcurvejoin .setdashadapt .setdebug "
".setdefaultmatrix .setdotlength .setfilladjust2 .setlimitclamp .setmaxlength .setopacityalpha .setoverprintmode "
".setrasterop .setsafe .setshapealpha .setsourcetransparent .settextknockout .settexturetransparent .stringbreak "
".stringmatch .tempfile .type1decrypt .type1encrypt .type1execchar .unread arccos arcsin copydevice copyscanlines "
"currentdevice finddevice findlibfile findprotodevice flushpage getdeviceprops getenv makeimagedevice "
"makewordimagedevice max min putdeviceprops setdevice";

class TpLexerPostScript : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, tokenize);
    DEF_PROP(int, level);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldAtElse);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        DSCComment = 2,
        DSCCommentValue = 3,
        Number = 4,
        Name = 5,
        Keyword = 6,
        Literal = 7,
        ImmediateEvalLiteral = 8,
        ArrayParenthesis = 9,
        DictionaryParenthesis = 10,
        ProcedureParenthesis = 11,
        Text = 12,
        HexString = 13,
        Base85String = 14,
        BadStringCharacter = 15,
    };

    enum
    {
        PropTokenize,
        PropLevel,
        PropFoldCompact,
        PropFoldAtElse,
    };

    enum
    {
        PSFirstLevel = 1,
        PSSecondLevel = 2,
        PSThirdLevel = 3,
    };

public:
    TpLexerPostScript(QObject *parent = nullptr);
    virtual ~TpLexerPostScript();

public:
    const char *language() const override;
    const char *lexer() const override;
    int braceStyle() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
    QString description(int style) const override;

    void refreshProperties() override;

    void setLexerProperty(int prop, QVariant value) override;
    QVariant lexerProperty(int prop) const override;

protected:
    bool readProperties(QSettings &settings, const QString &prefix) override;
    bool writeProperties(QSettings &settings, const QString &prefix) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERPOSTSCRIPT_H
