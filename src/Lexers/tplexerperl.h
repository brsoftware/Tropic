#ifndef TPLEXERPERL_H
#define TPLEXERPERL_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerPerlKeyword1 =
"abs accept alarm atan2 AUTOLOAD BEGIN bind binmode bless break caller chdir CHECK chmod chomp chop chown chr chroot "
"close closedir connect cos crypt dbmclose dbmopen defined delete DESTROY die dump each END endgrent endhostent "
"endnetent endprotoent endpwent endservent eof eval exec exists exit fcntl fileno flock fork format formline getc "
"getgrent getgrgid getgrnam gethostbyaddr gethostbyname gethostent getlogin getnetbyaddr getnetbyname getnetent "
"getpeername getpgrp getppid getpriority getprotobyname getprotobynumber getprotoent getpwent getpwnam getpwuid "
"getservbyname getservbyport getservent getsockname getsockopt glob gmtime goto grep hex index INIT int ioctl join "
"keys kill last lc lcfirst length link listen local localtime log lstat map mkdir msgctl msgget msgrcv msgsnd my next "
"not oct open opendir ord our pack pipe pop pos print printf prototype push quotemeta rand read readdir readline "
"readlink readpipe recv redo ref rename require reset return reverse rewinddir rindex rmdir say scalar seek seekdir "
"select semctl semget semop send setgrent sethostent setnetent setpgrp setpriority setprotoent setpwent setservent "
"setsockopt shift shmctl shmget shmread shmwrite shutdown sin sleep socket socketpair sort splice split sprintf sqrt "
"srand stat state study substr symlink syscall sysopen sysread sysseek system syswrite tell telldir tie tied time "
"times truncate uc ucfirst umask undef UNITCHECK unlink unpack unshift untie use utime values vec wait waitpid "
"wantarray warn write"
" "
"__DATA__ __END__ __FILE__ __LINE__ __PACKAGE__ and cmp continue CORE do else elsif eq exp for foreach ge gt if le "
"lock lt m ne no or package q qq qr qw qx s sub tr unless until while xor y"
" "
"$_ $a $ACCUMULATOR $ARG $ARGV $b $BASETIME $CHILD_ERROR $COMPILING $DEBUGGING $EFFECTIVE_GROUP_ID $EFFECTIVE_USER_ID "
"$EGID $ERRNO $EUID $EVAL_ERROR $EXCEPTIONS_BEING_CAUGHT $EXECUTABLE_NAME $EXTENDED_OS_ERROR $FORMAT_FORMFEED "
"$FORMAT_LINE_BREAK_CHARACTERS $FORMAT_LINES_LEFT $FORMAT_LINES_PER_PAGE $FORMAT_NAME $FORMAT_PAGE_NUMBER "
"$FORMAT_TOP_NAME $GID $INPLACE_EDIT $INPUT_LINE_NUMBER $INPUT_RECORD_SEPARATOR $LAST_MATCH_END $LAST_PAREN_MATCH "
"$LAST_REGEXP_CODE_RESULT $LIST_SEPARATOR $MATCH $MULTILINE_MATCHING $NR $OFMT $OFS $ORS $OS_ERROR $OSNAME "
"$OUTPUT_AUTO_FLUSH $OUTPUT_FIELD_SEPARATOR $OUTPUT_RECORD_SEPARATOR $PERL_VERSION $PERLDB $PID $POSTMATCH $PREMATCH "
"$PROCESS_ID $PROGRAM_NAME $REAL_GROUP_ID $REAL_USER_ID $RS $SUBSCRIPT_SEPARATOR $SUBSEP $SYSTEM_FD_MAX $UID $WARNING "
"%ENV %INC %OVERLOAD %SIG @_ @ARGV @INC @LAST_MATCH_START"
" "
"ARGV ARGVOUT STDERR STDIN STDOUT"
" "
"@F _ __DIE__ __WARN__ a abs2rel ACCUMULATOR ARG b back basename BASETIME begin builder can can_ok canonpath carp "
"case_tolerant catdir catfile catpath CHILD_ERROR CHILD_ERROR_NATIVE CLEAR CLOSE cluck cmp_ok COMPILING confess copy "
"cp croak curdir cut DATA DEBUGGING DELETE devnull diag dirname EFFECTIVE_GROUP_ID EFFECTIVE_USER_ID EGID ENCODING end "
"ENV eq_array eq_hash eq_set ERRNO EUID EVAL_ERROR EXCEPTIONS_BEING_CAUGHT EXECUTABLE_NAME EXISTS EXTEND "
"EXTENDED_OS_ERROR fail FETCH FETCHSIZE file_name_is_absolute fileparse fileparse_set_fstype find finddepth FIRSTKEY "
"FORMAT_FORMFEED FORMAT_LINE_BREAK_CHARACTERS FORMAT_LINES_LEFT FORMAT_LINES_PER_PAGE FORMAT_TOP_NAME freeze GETC "
"GetOptions GID head1 head2 head3 head4 HOME INC INPLACE_EDIT INPUT_LINE_NUMBER INPUT_RECORD_SEPARATOR is is_deeply "
"ISA isa isa_ok isnt item LAST_MATCH_END LAST_MATCH_START LAST_PAREN_MATCH LAST_REGEXP_CODE_RESULT "
"LAST_SUBMATCH_RESULT like LIST_SEPARATOR LOGDIR longmess MATCH mkdtemp mkpath mkstemp mkstemps mktemp move "
"MULTILINE_MATCHING mv NEXTKEY no_upwards NR OFS ok OPEN ORS OS_ERROR OSNAME OUTPUT_AUTOFLUSH OUTPUT_FIELD_SEPARATOR "
"OUTPUT_RECORD_SEPARATOR over pass PATH path PERL5DB PERL5DB_THREADED PERL5LIB PERL5OPT PERL5SHELL "
"PERL_ALLOW_NON_IFS_LSP PERL_DEBUG_MSTATS PERL_DESTRUCT_LEVEL PERL_DL_NONLAZY PERL_ENCODING PERL_HASH_SEED "
"PERL_HASH_SEED_DEBUG PERL_ROOT PERL_SIGNALS PERL_UNICODE PERL_VERSION PERLDB PERLIO PERLIO_DEBUG PERLLIB PID plan pod "
"POP POSTMATCH PREMATCH PRINT PRINTF PROCESS_ID PROGRAM_NAME PUSH RE_DEBUG_FLAGS RE_TRIE_MAXBUF READ READLINE "
"REAL_GROUP_ID REAL_USER_ID rel2abs require_ok rmscopy rmtree rootdir RS safe_level SHIFT shortmess SIG skip SKIP "
"SPLICE splitdir STORE STORESIZE SUBSCRIPT_SEPARATOR SUBSEP SYSTEM_FD_MAX TAINT tempdir tempfile thaw TIEARRAY "
"TIEHANDLE TIEHASH TIESCALAR tmpdir tmpfile tmpnam TODO todo_skip UID UNICODE unlike unlink0 UNSHIFT UNTIE updir "
"use_ok UTF8CACHE UTF8LOCALE VERSION WARNING WARNING_BITS WIN32_SLOPPY_STAT WRITE";

class TpLexerPerl : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, fold);
    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldPOD);
    DEF_PROP(bool, foldPackage);
    DEF_PROP(bool, foldAtElse);

public:
    enum
    {
        Default = 0,
        Error = 1,
        Comment = 2,
        POD = 3,
        Number = 4,
        Keyword = 5,
        DoubleQuotedString = 6,
        SingleQuotedString = 7,
        Operator = 10,
        Identifier = 11,
        Scalar = 12,
        Array = 13,
        Hash = 14,
        SymbolTable = 15,
        Regex = 17,
        Substitution = 18,
        Backticks = 20,
        DataSection = 21,
        HereDocumentDelimiter = 22,
        SingleQuotedHereDocument = 23,
        DoubleQuotedHereDocument = 24,
        BacktickHereDocument = 25,
        QuotedStringQ = 26,
        QuotedStringQQ = 27,
        QuotedStringQX = 28,
        QuotedStringQR = 29,
        QuotedStringQW = 30,
        PODVerbatim = 31,
        SubroutinePrototype = 40,
        FormatIdentifier = 41,
        FormatBody = 42,
        DoubleQuotedStringVar = 43,
        Translation = 44,
        RegexVar = 54,
        SubstitutionVar = 55,
        BackticksVar = 57,
        DoubleQuotedHereDocumentVar = 61,
        BacktickHereDocumentVar = 62,
        QuotedStringQQVar = 64,
        QuotedStringQXVar = 65,
        QuotedStringQRVar = 66,
    };

    enum
    {
        PropFold,
        PropFoldComments,
        PropFoldCompact,
        PropFoldPOD,
        PropFoldPackage,
        PropFoldAtElse,
    };

public:
    TpLexerPerl(QObject *parent = nullptr);
    virtual ~TpLexerPerl();

public:
    const char *language() const override;
    const char *lexer() const override;
    QStringList autoCompletionWordSeparators() const override;
    const char *blockEnd(int *style = nullptr) const override;
    const char *blockStart(int *style = nullptr) const override;
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

#endif // TPLEXERPERL_H
