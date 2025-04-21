#ifndef TPLEXERPASCAL_H
#define TPLEXERPASCAL_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerPascal : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldPreprocessor);
    DEF_PROP(bool, smartHighlight);

public:
    enum
    {
        Default = 0,
        Identifier = 1,
        Comment = 2,
        CommentParenthesis = 3,
        CommentLine = 4,
        PreProcessor = 5,
        PreProcessorParenthesis = 6,
        Number = 7,
        HexNumber = 8,
        Keyword = 9,
        SingleQuotedString = 10,
        UnclosedString = 11,
        Character = 12,
        Operator = 13,
        Asm = 14,
    };

    enum
    {
        PropFoldComments,
        PropFoldCompact,
        PropFoldPreprocessor,
        PropSmartHighlight,
    };

public:
    TpLexerPascal(QObject *parent = nullptr);
    virtual ~TpLexerPascal();

public:
    const char *language() const override;
    const char *lexer() const override;

    QStringList autoCompletionWordSeparators() const override;
    const char *blockEnd(int *style = nullptr) const override;
    const char *blockStart(int *style = nullptr) const override;
    const char *blockStartKeyword(int *style = nullptr) const override;
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

#endif // TPLEXERPASCAL_H
