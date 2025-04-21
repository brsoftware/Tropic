#ifndef TPLEXERPOV_H
#define TPLEXERPOV_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerPOV : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldDirectives);

public:
    enum
    {
        Default = 0,
        Comment = 1,
        CommentLine = 2,
        Number = 3,
        Operator = 4,
        Identifier = 5,
        String = 6,
        UnclosedString = 7,
        Directive = 8,
        BadDirective = 9,
        ObjectsCSGAppearance = 10,
        TypesModifiersItems = 11,
        PredefinedIdentifiers = 12,
        PredefinedFunctions = 13,
        KeywordSet6 = 14,
        KeywordSet7 = 15,
        KeywordSet8 = 16,
    };

    enum
    {
        PropFoldComments,
        PropFoldCompact,
        PropFoldDirectives,
    };

public:
    TpLexerPOV(QObject *parent = nullptr);
    virtual ~TpLexerPOV();

public:
    const char *language() const override;
    const char *lexer() const override;
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

#endif // TPLEXERPOV_H
