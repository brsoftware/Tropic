#ifndef TPLEXERAVISYNTH_H
#define TPLEXERAVISYNTH_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerAviSynth : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldComments);

public:
    enum
    {
        Default = 0,
        BlockComment = 1,
        NestedBlockComment = 2,
        LineComment = 3,
        Number = 4,
        Operator = 5,
        Identifier = 6,
        String = 7,
        TripleString = 8,
        Keyword = 9,
        Filter = 10,
        Plugin = 11,
        Function = 12,
        ClipProperty = 13,
        KeywordSet6 = 14,
    };

    enum
    {
        PropFoldComments,
        PropFoldCompact,
    };

public:
    TpLexerAviSynth(QObject *parent = nullptr);
    virtual ~TpLexerAviSynth();

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

#endif // TPLEXERAVISYNTH_H
