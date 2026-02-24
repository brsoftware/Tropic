#ifndef TPLEXERVERILOG_H
#define TPLEXERVERILOG_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerVerilogKeyword1 =
"always and assign automatic begin buf bufif0 bufif1 case casex casez cell cmos config deassign default defparam "
"design disable edge else end endcase endconfig endfunction endgenerate endmodule endprimitiveendspecify endtable "
"endtask event for force forever fork function generate genvar highz0 highz1 if ifnone incdir include initial inout "
"input instance integer join large liblist library localparam macromodule medium module nand negedge nmos nor "
"noshowcancelled not notif0 notif1 or output parameter pmos posedge primitive pull0 pull1 pulldown pullup "
"pulsestyle_ondetect pulsestyle_onevent rcmos real realtime reg release repeat rnmos rpmos rtran rtranif0 rtranif1 "
"scalared showcancelled signed small specify specparam strong0 strong1 supply0 supply1 table task time tran tranif0 "
"tranif1 tri tri0 tri1 triand trior trireg unsigned use vectored wait wand weak0 weak1 while wire wor xnor xor";

inline const char *lexerVerilogKeyword3 =
"$async$and$array $async$and$plane $async$nand$array $async$nand$plane $async$nor$array $async$nor$plane "
"$async$or$array $async$or$plane $bitstoreal $countdrivers $display $displayb $displayh $displayo $dist_chi_square "
"$dist_erlang $dist_exponential $dist_normal $dist_poisson $dist_t $dist_uniform $dumpall $dumpfile $dumpflush "
"$dumplimit $dumpoff $dumpon $dumpportsall $dumpportsflush $dumpportslimit $dumpportsoff $dumpportson $dumpvars "
"$fclose $fdisplayh $fdisplay $fdisplayf $fdisplayb $ferror $fflush $fgetc $fgets $finish $fmonitorb $fmonitor "
"$fmonitorf $fmonitorh $fopen $fread $fscanf $fseek $fsscanf $fstrobe $fstrobebb $fstrobef $fstrobeh $ftel $fullskew "
"$fwriteb $fwritef $fwriteh $fwrite $getpattern $history $hold $incsave $input $itor $key $list $log $monitorb "
"$monitorh $monitoroff $monitoron $monitor $monitoro $nochange $nokey $nolog $period $printtimescale $q_add $q_exam "
"$q_full $q_initialize $q_remove $random $readmemb $readmemh $readmemh $realtime $realtobits $recovery $recrem "
"$removal $reset_count $reset $reset_value $restart $rewind $rtoi $save $scale $scope $sdf_annotate $setup $setuphold "
"$sformat $showscopes $showvariables $showvars $signed $skew $sreadmemb $sreadmemh $stime $stop $strobeb $strobe "
"$strobeh $strobeo $swriteb $swriteh $swriteo $swrite $sync$and$array $sync$and$plane $sync$nand$array "
"$sync$nand$plane $sync$nor$array $sync$nor$plane $sync$or$array $sync$or$plane $test$plusargs $time $timeformat "
"$timeskew $ungetc $unsigned $value$plusargs $width $writeb $writeh $write $writeo";

class TpLexerVerilog : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldAtElse);
    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldPreprocessor);
    DEF_PROP(bool, foldAtModule);

public:
    enum
    {
        Default = 0,
        InactiveDefault = Default + 64,
        Comment = 1,
        InactiveComment = Comment + 64,
        CommentLine = 2,
        InactiveCommentLine = CommentLine + 64,
        CommentBang = 3,
        InactiveCommentBang = CommentBang + 64,
        Number = 4,
        InactiveNumber = Number + 64,
        Keyword = 5,
        InactiveKeyword = Keyword + 64,
        String = 6,
        InactiveString = String + 64,
        KeywordSet2 = 7,
        InactiveKeywordSet2 = KeywordSet2 + 64,
        SystemTask = 8,
        InactiveSystemTask = SystemTask + 64,
        Preprocessor = 9,
        InactivePreprocessor = Preprocessor + 64,
        Operator = 10,
        InactiveOperator = Operator + 64,
        Identifier = 11,
        InactiveIdentifier = Identifier + 64,
        UnclosedString = 12,
        InactiveUnclosedString = UnclosedString + 64,
        UserKeywordSet = 19,
        InactiveUserKeywordSet = UserKeywordSet + 64,
        CommentKeyword = 20,
        InactiveCommentKeyword = CommentKeyword + 64,
        DeclareInputPort = 21,
        InactiveDeclareInputPort = DeclareInputPort + 64,
        DeclareOutputPort = 22,
        InactiveDeclareOutputPort = DeclareOutputPort + 64,
        DeclareInputOutputPort = 23,
        InactiveDeclareInputOutputPort = DeclareInputOutputPort + 64,
        PortConnection = 24,
        InactivePortConnection = PortConnection + 64,
    };

    enum
    {
        PropFoldAtElse,
        PropFoldComments,
        PropFoldCompact,
        PropFoldPreprocessor,
        PropFoldAtModule,
    };

public:
    TpLexerVerilog(QObject *parent = nullptr);
    virtual ~TpLexerVerilog();

public:
    const char *language() const override;
    const char *lexer() const override;
    int braceStyle() const override;
    const char *wordCharacters() const override;

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

#endif // TPLEXERBASH_H
