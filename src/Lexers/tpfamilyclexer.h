#ifndef TPFAMILYCLEXER_H
#define TPFAMILYCLEXER_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpFamilyCLexer : public TpGeneralLexer
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
        InactiveDefault = Default + 64,
        Comment = 1,
        InactiveComment = Comment + 64,
        CommentLine = 2,
        InactiveCommentLine = CommentLine + 64,
        CommentDoc = 3,
        InactiveCommentDoc = CommentDoc + 64,
        Number = 4,
        InactiveNumber = Number + 64,
        Keyword = 5,
        InactiveKeyword = Keyword + 64,
        DoubleQuotedString = 6,
        InactiveDoubleQuotedString = DoubleQuotedString + 64,
        SingleQuotedString = 7,
        InactiveSingleQuotedString = SingleQuotedString + 64,
        UUID = 8,
        InactiveUUID = UUID + 64,
        PreProcessor = 9,
        InactivePreProcessor = PreProcessor + 64,
        Operator = 10,
        InactiveOperator = Operator + 64,
        Identifier = 11,
        InactiveIdentifier = Identifier + 64,
        UnclosedString = 12,
        InactiveUnclosedString = UnclosedString + 64,
        VerbatimString = 13,
        InactiveVerbatimString = VerbatimString + 64,
        Regex = 14,
        InactiveRegex = Regex + 64,
        CommentLineDoc = 15,
        InactiveCommentLineDoc = CommentLineDoc + 64,
        KeywordSet2 = 16,
        InactiveKeywordSet2 = KeywordSet2 + 64,
        CommentDocKeyword = 17,
        InactiveCommentDocKeyword = CommentDocKeyword + 64,
        CommentDocKeywordError = 18,
        InactiveCommentDocKeywordError = CommentDocKeywordError + 64,
        GlobalClass = 19,
        InactiveGlobalClass = GlobalClass + 64,
        RawString = 20,
        InactiveRawString = RawString + 64,
        TripleQuotedVerbatimString = 21,
        InactiveTripleQuotedVerbatimString = TripleQuotedVerbatimString + 64,
        HashQuotedString = 22,
        InactiveHashQuotedString = HashQuotedString + 64,
        PreProcessorComment = 23,
        InactivePreProcessorComment = PreProcessorComment + 64,
        PreProcessorCommentLineDoc = 24,
        InactivePreProcessorCommentLineDoc = PreProcessorCommentLineDoc + 64,
        UserLiteral = 25,
        InactiveUserLiteral = UserLiteral + 64,
        TaskMarker = 26,
        InactiveTaskMarker = TaskMarker + 64,
        EscapeSequence = 27,
        InactiveEscapeSequence = EscapeSequence + 64,
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
    TpFamilyCLexer(QObject *parent = nullptr);
    virtual ~TpFamilyCLexer();

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

#endif // TPFAMILYCLEXER_H
