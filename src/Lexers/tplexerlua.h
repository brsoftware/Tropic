#ifndef TPLEXERLUA_H
#define TPLEXERLUA_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerLuaKeyword1 =
"and break do else elseif end false for function if in local nil not or repeat return then true until while";

inline const char *lexerLuaKeyword2 =
"assert collectgarbage dofile error _G getfenv getmetatable ipairs load loadfile loadstring next pairs pcall print "
"rawequal rawget rawset select setfenv setmetatable tonumber tostring type unpack _VERSION xpcall"
" "
"module require"
" "
"string table math coroutine package io os debug"
" "
"_ALERT _ERRORMESSAGE _INPUT _PROMPT _OUTPUT _STDERR _STDIN _STDOUT call dostring foreach foreachi getn globals "
"newtype tinsert tremove loadlib xpcall";

inline const char *lexerLuaKeyword3 =
"byte char dump find format gmatch gsub len lower match rep reverse sub upper"
" "
"concat foreach foreachi getn setn insert maxn remove sort"
" "
"abs acos asin atan atan2 ceil cos cosh deg exp floor fmod frexp huge ldexp log log10 max min modf pi pow rad random "
"randomseed sin sinh sqrt tan tanh"
" "
"strchar strfind strlen strlower strrep strsub strupper";

inline const char *lexerLuaKeyword4 =
"create resume running status wrap yield"
" "
"cpath loaded loaders loadlib path preload"
" "
"close flush input lines open output popen read tmpfile type write close flush lines read seek setvbuf write"
" "
"clock date difftime execute exit getenv remove rename setlocale time tmpname"
" "
"debug getfenv gethook getinfo getlocal getmetatable getregistry getupvalue setfenv sethook setlocal setmetatable "
"setupvalue traceback"
" "
"openfile closefile readfrom writeto appendto rename flush";

class TpLexerLua : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldCompact);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        CommentLine = 2,
        CommentDoc = 3,
        Number = 4,
        Keyword = 5,
        String = 6,
        Character = 7,
        LiteralString = 8,
        Preprocessor = 9,
        Operator = 10,
        Identifier = 11,
        UnclosedString = 12,
        BasicFunctions = 13,
        StringTableMathsFunctions = 14,
        CoroutinesIOSystemFacilities = 15,
        KeywordSet5 = 16,
        KeywordSet6 = 17,
        KeywordSet7 = 18,
        KeywordSet8 = 19,
        Label = 20,
    };

    enum
    {
        PropFoldCompact,
    };

public:
    TpLexerLua(QObject *parent = nullptr);
    virtual ~TpLexerLua();

public:
    const char *language() const override;
    const char *lexer() const override;
    QStringList autoCompletionWordSeparators() const override;
    const char *blockStart(int *style = nullptr) const override;
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

#endif // TPLEXERLUA_H
