#ifndef TPFAMILYPYTHONLEXER_H
#define TPFAMILYPYTHONLEXER_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpFamilyPythonLexer : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(int, indentationWarning);
    DEF_PROP(bool, binaryLiterals);
    DEF_PROP(bool, unicodeStrings);
    DEF_PROP(bool, binaryStrings);
    DEF_PROP(bool, formatStrings);
    DEF_PROP(bool, disableSubIdentifiers);
    DEF_PROP(bool, fold);
    DEF_PROP(bool, foldQuotes);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, enableUnicodeIdentifiers);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        Number = 2,
        DoubleQuotedString = 3,
        SingleQuotedString = 4,
        Keyword = 5,
        TripleSingleQuotedString = 6,
        TripleDoubleQuotedString = 7,
        ClassName = 8,
        FunctionMethodName = 9,
        Operator = 10,
        Identifier = 11,
        CommentBlock = 12,
        UnclosedString = 13,
        HighlightIdentifier = 14,
        Decorator = 15,
        DoubleQuotedFString = 16,
        SingleQuotedFString = 17,
        TripleSingleQuotedFString = 18,
        TripleDoubleQuotedFString = 19,
    };

    enum
    {
        PropIndentationWarning,
        PropBinaryLiterals,
        PropUnicodeStrings,
        PropBinaryStrings,
        PropFormatStrings,
        PropDisableSubIdentifiers,
        PropFold,
        PropFoldQuotes,
        PropFoldCompact,
        PropEnableUnicodeIdentifiers,
    };

    enum
    {
        IndentationNoWarning = 0,
        IndentationWarnsInconsistency = 1,
        IndentationWarnsTabsAfterSpaces = 2,
        IndentationWarnsSpaces = 3,
        IndentationWarnsTabs = 4,
    };

public:
    TpFamilyPythonLexer(QObject *parent = nullptr);
    virtual ~TpFamilyPythonLexer();

public:
    const char *language() const override;
    const char *lexer() const override;

    QStringList autoCompletionWordSeparators() const override;
    int blockLookback() const override;
    const char *blockStart(int *style = nullptr) const override;
    int braceStyle() const override;
    int indentationGuideView() const override;

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

#endif // TPFAMILYPYTHONLEXER_H
