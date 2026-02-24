#ifndef TPLEXERJSON_H
#define TPLEXERJSON_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerJSONKeyword1 =
"type pattern string regex number object array boolean true false null"
" "
"additionalProperties allOf anyOf const contains contentEncoding contentMediaType contentSchema default "
"dependentRequired dependentSchemas deprecated description else enum examples exclusiveMaximum exclusiveMinimum format "
"if items maxContains maximum maxItems maxLength maxProperties minContains minimum minItems minLength minProperties "
"multipleOf not oneOf patternProperties prefixItems properties propertyNames readOnly required then title type "
"unevaluatedItems unevaluatedProperties uniqueItems writeOnly";

inline const char *lexerJSONKeyword2 =
"@base @container @context @direction @graph @id @import @included @index @json @language @list @nest @none @prefix "
"@propagate @protected @reverse @set @type @value @version @vocab";

class TpLexerJSON : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, escapeSequence);
    DEF_PROP(bool, allowComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, fold);

public:
    enum
    {
        Default = 0,
        Number = 1,
        String = 2,
        UnclosedString = 3,
        Property = 4,
        EscapeSequence = 5,
        CommentLine = 6,
        CommentBlock = 7,
        Operator = 8,
        IRI = 9,
        IRICompact = 10,
        Keyword = 11,
        KeywordLD = 12,
        Error = 13,
    };

    enum
    {
        PropEscapeSequence,
        PropAllowComments,
        PropFoldCompact,
        PropFold,
    };

public:
    TpLexerJSON(QObject *parent = nullptr);
    virtual ~TpLexerJSON();

public:
    int autoIndentStyle();

    const char *language() const override;
    const char *lexer() const override;

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

#endif // TPLEXERJSON_H
