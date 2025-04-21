#ifndef TPLEXERCOFFEESCRIPT_H
#define TPLEXERCOFFEESCRIPT_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerCoffeeScript : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldAtElse);
    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldPreprocessor);
    DEF_PROP(bool, stylePreprocessor);
    DEF_PROP(bool, enableDollars);
    DEF_PROP(bool, enableTripleQuotedStrings);
    DEF_PROP(bool, enableHashQuotedStrings);
    DEF_PROP(bool, enableBackQuotedString);
    DEF_PROP(bool, enableEscapeSequence);
    DEF_PROP(bool, enableVerbatimEscapeSequence);
    DEF_PROP(bool, trackPreprocessor);
    DEF_PROP(bool, updatePreprocessor);
    DEF_PROP(bool, syntaxBasedFold);
    DEF_PROP(QString, explicitStart);
    DEF_PROP(QString, explicitEnd);
    DEF_PROP(bool, explicitAnywhere);
    DEF_PROP(bool, foldPreprocessorAtElse);

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
        UUID = 8,
        PreProcessor = 9,
        Operator = 10,
        Identifier = 11,
        UnclosedString = 12,
        VerbatimString = 13,
        Regex = 14,
        CommentLineDoc = 15,
        KeywordSet2 = 16,
        CommentDocKeyword = 17,
        CommentDocKeywordError = 18,
        GlobalClass = 19,
        CommentBlock = 22,
        BlockRegex = 23,
        BlockRegexComment = 24,
        InstanceProperty = 25,
    };

    enum
    {
        PropFoldAtElse,
        PropFoldComments,
        PropFoldCompact,
        PropFoldPreprocessor,
        PropStylePreprocessor,
        PropEnableDollars,
        PropEnableTripleQuotedStrings,
        PropEnableHashQuotedStrings,
        PropEnableBackQuotedStrings,
        PropEnableEscapeSequence,
        PropEnableVerbatimEscapeSequence,
        PropTrackPreprocessor,
        PropUpdatePreprocessor,
        PropFoldSyntaxBased,
        PropExplicitStart,
        PropExplicitEnd,
        PropExplicitAnywhere,
        PropFoldPreprocessorAtElse,
    };

public:
    TpLexerCoffeeScript(QObject *parent = nullptr);
    virtual ~TpLexerCoffeeScript();

public:
    int autoIndentStyle();

    const char *language() const override;
    const char *lexer() const override;
    QStringList autoCompletionWordSeparators() const override;
    const char *blockEnd(int *style = nullptr) const override;
    const char *blockStart(int *style = nullptr) const override;
    const char *blockStartKeyword(int *style = nullptr) const override;
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

#endif // TPLEXERCOFFEESCRIPT_H
