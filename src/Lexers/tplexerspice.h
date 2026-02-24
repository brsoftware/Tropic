#ifndef TPLEXERSPICE_H
#define TPLEXERSPICE_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerSpiceKeyword1 =
"ac alias alter alterparam append askvalues assertvalid utoscale break compose copy copytodoc dc delete destroy "
"estroyvec diff display disto dowhile echo else end errorstop ftinit filter foreach fourier freqtotime function "
"unctionundef goto homecursors if isdisplayed label let inearize listing load loadaccumulator makelabel movelabel "
"akesmithplot movecursorleft movecursorright msgbox nameplot ewplot nextparam noise nopoints op plot plotf plotref "
"poly rint printcursors printevent printname printplot printstatus rinttext printtol printunits printval printvector "
"pwl pz quit emovesmithplot rename repeat resume rotate runs rusage save endplot sendscript sens set setcursor setdoc "
"setlabel etlabeltype setmargins setnthtrigger setunits setvec setparam etplot setquery setscaletype settracecolor "
"settracestyle etsource settrigger setvec setxlimits setylimits show showmod ort status step stop switch tf timetofreq "
"timetowave tran nalias unlet unset unalterparam update version view wavefilter wavetotime where while write";

inline const char *lexerSpiceKeyword2 =
"abs askvalue atan average ceil cos db differentiate differentiatex exp finalvalue floor getcursorx getcursory "
"getcursory0 getcursory1 getparam im ln initialvalue integrate integratex interpolate isdef isdisplayed j log length "
"mag max maxscale mean meanpts min minscale nextplot nextvector norm operatingpoint ph phase phaseextend pk_pk pos "
"pulse re rms rmspts rnd sameplot sin sqrt stddev stddevpts tan tfall tolerance trise unitvec vector";

class TpLexerSpice : public TpGeneralLexer
{
    Q_OBJECT

public:
    enum
    {
        Default = 0,
        Identifier = 1,
        Command = 2,
        Function = 3,
        Parameter = 4,
        Number = 5,
        Delimiter = 6,
        Value = 7,
        Comment = 8,
    };

public:
    TpLexerSpice(QObject *parent = nullptr);
    virtual ~TpLexerSpice();

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
};

TP_END_NAMESPACE

#endif // TPLEXERSPICE_H
