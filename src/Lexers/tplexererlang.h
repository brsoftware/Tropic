#ifndef TPLEXERERLANG_H
#define TPLEXERERLANG_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerErlangKeyword1 =
"after and andalso band begin bnot bor bsl bsr bxor case catch cond div end fun if let not of or orelse query receive "
"rem try when xor";

inline const char *lexerErlangKeyword2 =
"erlang: abs adler32 adler32_combine erlang:append_element apply atom_to_binary atom_to_list binary_to_atom "
"binary_to_existing_atom binary_to_list bitstring_to_list binary_to_term bit_size erlang:bump_reductions byte_size "
"erlang:cancel_timer check_process_code concat_binary crc32 crc32_combine date decode_packet delete_module "
"erlang:demonitor disconnect_node erlang:display element erase erlang:error exit float float_to_list erlang:fun_info "
"erlang:fun_to_list erlang:function_exported garbage_collect get erlang:get_cookie get_keys erlang:get_stacktrace "
"group_leader halt erlang:hash hd erlang:hibernate integer_to_list erlang:integer_to_list iolist_to_binary iolist_size "
"is_alive is_atom is_binary is_bitstring is_boolean erlang:is_builtin is_float is_function is_integer is_list "
"is_number is_pid is_port is_process_alive is_record is_reference is_tuple length link list_to_atom list_to_binary "
"list_to_bitstring list_to_existing_atom list_to_float list_to_integer erlang:list_to_integer list_to_pid "
"list_to_tuple load_module erlang:load_nif erlang:loaded erlang:localtime erlang:localtime_to_universaltime make_ref "
"erlang:make_tuple erlang:max erlang:md5 erlang:md5_final erlang:md5_init erlang:md5_update erlang:memory erlang:min "
"module_loaded erlang:monitor monitor_node node nodes now open_port erlang:phash erlang:phash2 pid_to_list port_close "
"port_command erlang:port_command port_connect port_control erlang:port_call erlang:port_info erlang:port_to_list "
"erlang:ports pre_loaded erlang:process_display process_flag process_info processes purge_module put erlang:raise "
"erlang:read_timer erlang:ref_to_list register registered erlang:resume_process round self erlang:send "
"erlang:send_after erlang:send_nosuspend erlang:set_cookie setelement size spawn spawn_link spawn_monitor spawn_opt "
"split_binary erlang:start_timer statistics erlang:suspend_process erlang:system_flag erlang:system_info "
"erlang:system_monitor erlang:system_profile term_to_binary throw time tl erlang:trace erlang:trace_delivered "
"erlang:trace_info erlang:trace_pattern trunc tuple_size tuple_to_list erlang:universaltime "
"erlang:universaltime_to_localtime unlink unregister whereis erlang:yield";

inline const char *lexerErlangKeyword3 =
"-define -else -endif -ifdef -ifndef -include -include_lib -undef";

inline const char *lexerErlangKeyword4 =
"-behavior -behaviour -compile -created -created_by -export -file -import -module -modified -modified_by -record "
"-revision -spec -type -vsn";

inline const char *lexerErlangKeyword5 =
"@author @clear @copyright @deprecated @doc @docfile @end @equiv @headerfile @hidden @private @reference @see @since "
"@spec @throws @title @todo @TODO @type @version";

inline const char *lexerErlangKeyword6 =
"@date @docRoot @link @module @package @section @time @type @version";

class TpLexerErlang : public TpGeneralLexer
{
    Q_OBJECT

public:
    enum
    {
        Default = 0,
        Comment = 1,
        Variable = 2,
        Number = 3,
        Keyword = 4,
        String = 5,
        Operator = 6,
        Atom = 7,
        FunctionName = 8,
        Character = 9,
        Macro = 10,
        Record = 11,
        Preprocessor = 12,
        NodeName = 13,
        CommentFunction = 14,
        CommentModule = 15,
        CommentDoc = 16,
        CommentDocMacro = 17,
        QuotedAtom = 18,
        QuotedMacro = 19,
        QuotedRecord = 20,
        QuotedNodeName = 21,
        BIFS = 22,
        Modules = 23,
        ATTModules = 24,
        Unknown = 31,
    };

public:
    TpLexerErlang(QObject *parent = nullptr);
    virtual ~TpLexerErlang();

public:
    const char *language() const override;
    const char *lexer() const override;
    const char *wordCharacters() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
    QString description(int style) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERLUA_H
