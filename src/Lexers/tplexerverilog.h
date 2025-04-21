#ifndef TPLEXERVERILOG_H
#define TPLEXERVERILOG_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpLexerVerilog : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldAtElse);
    DEF_PROP(bool, foldComments);
    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldPreprocessor);
    DEF_PROP(bool, foldAtModule);

public:
    enum
    {
        Default = 0,
        InactiveDefault = Default + 64,
        Comment = 1,
        InactiveComment = Comment + 64,
        CommentLine = 2,
        InactiveCommentLine = CommentLine + 64,
        CommentBang = 3,
        InactiveCommentBang = CommentBang + 64,
        Number = 4,
        InactiveNumber = Number + 64,
        Keyword = 5,
        InactiveKeyword = Keyword + 64,
        String = 6,
        InactiveString = String + 64,
        KeywordSet2 = 7,
        InactiveKeywordSet2 = KeywordSet2 + 64,
        SystemTask = 8,
        InactiveSystemTask = SystemTask + 64,
        Preprocessor = 9,
        InactivePreprocessor = Preprocessor + 64,
        Operator = 10,
        InactiveOperator = Operator + 64,
        Identifier = 11,
        InactiveIdentifier = Identifier + 64,
        UnclosedString = 12,
        InactiveUnclosedString = UnclosedString + 64,
        UserKeywordSet = 19,
        InactiveUserKeywordSet = UserKeywordSet + 64,
        CommentKeyword = 20,
        InactiveCommentKeyword = CommentKeyword + 64,
        DeclareInputPort = 21,
        InactiveDeclareInputPort = DeclareInputPort + 64,
        DeclareOutputPort = 22,
        InactiveDeclareOutputPort = DeclareOutputPort + 64,
        DeclareInputOutputPort = 23,
        InactiveDeclareInputOutputPort = DeclareInputOutputPort + 64,
        PortConnection = 24,
        InactivePortConnection = PortConnection + 64,
    };

    enum
    {
        PropFoldAtElse,
        PropFoldComments,
        PropFoldCompact,
        PropFoldPreprocessor,
        PropFoldAtModule,
    };

public:
    TpLexerVerilog(QObject *parent = nullptr);
    virtual ~TpLexerVerilog();

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

#endif // TPLEXERBASH_H
