#ifndef TPLEXERVHDL_H
#define TPLEXERVHDL_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerVHDL : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldAtElse);
    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldAtBegin);
    DEF_PROP(bool, foldAtParenthesis);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        CommentLine = 2,
        Number = 3,
        String = 4,
        Operator = 5,
        Identifier = 6,
        UnclosedString = 7,
        Keyword = 8,
        StandardOperator = 9,
        Attribute = 10,
        StandardFunction = 11,
        StandardPackage = 12,
        StandardType = 13,
        KeywordSet7 = 14,
        CommentBlock = 15,
    };

    enum
    {
        PropFoldAtElse,
        PropFoldComments,
        PropFoldCompact,
        PropFoldAtBegin,
        PropFoldAtParenthesis,
    };

public:
    TpLexerVHDL(QObject *parent = nullptr);
    virtual ~TpLexerVHDL();

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

#endif // TPLEXERVHDL_H
