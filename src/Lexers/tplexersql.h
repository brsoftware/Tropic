#ifndef TPLEXERSQL_H
#define TPLEXERSQL_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerSQLKeyword1 =
"absolute action add admin after aggregate alias all allocate alter and any are array as asc assertion at "
"authorization before begin binary bit blob boolean both breadth by call cascade cascaded case cast catalog char "
"character check class clob close collate collation column commit completion connect connection constraint constraints "
"constructor continue corresponding create cross cube current current_date current_path current_role current_time "
"current_timestamp current_user cursor cycle data date day deallocate dec decimal declare default deferrable deferred "
"delete depth deref desc describe descriptor destroy destructor deterministic dictionary diagnostics disconnect "
"distinct domain double drop dynamic each else end end-exec equals escape every except exception exec execute external "
"false fetch first float for foreign found from free full function general get global go goto grant group grouping "
"having host hour identity if ignore immediate in indicator initialize initially inner inout input insert int integer "
"intersect interval into is isolation iterate join key language large last lateral leading left less level like limit "
"local localtime localtimestamp locator map match minute modifies modify module month names national natural nchar "
"nclob new next no none not null numeric object of off old on only open operation option or order ordinality out outer "
"output pad parameter parameters partial path postfix precision prefix preorder prepare preserve primary prior "
"privileges procedure public read reads real recursive ref references referencing relative restrict result return "
"returns revoke right role rollback rollup routine row rows savepoint schema scroll scope search second section select "
"sequence session session_user set sets size smallint some| space specific specifictype sql sqlexception sqlstate "
"sqlwarning start state statement static structure system_user table temporary terminate than then time timestamp "
"timezone_hour timezone_minute to trailing transaction translation treat trigger true under union unique unknown "
"unnest update usage user using value values varchar variable varying view when whenever where with without work write "
"year zone";

inline const char *lexerSQLKeyword4 =
"acc~ept a~ppend archive log attribute bre~ak bti~tle c~hange cl~ear col~umn comp~ute conn~ect copy def~ine del "
"desc~ribe disc~onnect e~dit exec~ute exit get help ho~st i~nput l~ist passw~ord pau~se pri~nt pro~mpt quit recover "
"rem~ark repf~ooter reph~eader r~un sav~e set sho~w shutdown spo~ol sta~rt startup store timi~ng tti~tle undef~ine "
"var~iable whenever oserror whenever sqlerror";

inline const char *lexerSQLKeyword5 =
"dbms_output.disable dbms_output.enable dbms_output.get_line dbms_output.get_lines dbms_output.new_line "
"dbms_output.put dbms_output.put_line";

class TpLexerSQL : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, fold);
    DEF_PROP(bool, foldAtElse);
    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldOnlyBegin);
    DEF_PROP(bool, backticksIdentifier);
    DEF_PROP(bool, numbersignComment);
    DEF_PROP(bool, backslashEscapes);
    DEF_PROP(bool, allowDottedWord);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        CommentLine = 2,
        CommentDoc = 3,
        Number = 4,
        Keyword = 5,
        DoubleQuotedString = 6,
        SingleQuotedString = 7,
        PlusKeyword = 8,
        PlusPrompt = 9,
        Operator = 10,
        Identifier = 11,
        PlusComment = 13,
        CommentLineHash = 15,
        CommentDocKeyword = 17,
        CommentDocKeywordError = 18,
        KeywordSet5 = 19,
        KeywordSet6 = 20,
        KeywordSet7 = 21,
        KeywordSet8 = 22,
        QuotedIdentifier = 23,
        QuotedOperator = 24,
    };

    enum
    {
        PropFold,
        PropFoldAtElse,
        PropFoldComments,
        PropFoldCompact,
        PropFoldOnlyBegin,
        PropBackticksIdentifier,
        PropNumbersignComment,
        PropBackslashEscapes,
        PropAllowDottedWord,
    };

public:
    TpLexerSQL(QObject *parent = nullptr);
    virtual ~TpLexerSQL();

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

#endif // TPLEXERSQL_H
