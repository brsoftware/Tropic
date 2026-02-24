#ifndef TPLEXERQSS_H
#define TPLEXERQSS_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerQSSKeyword1 =
"accent-color alternate-background-color background background-color background-image background-repeat "
"background-position background-attachment background-clip background-origin border border-top border-right "
"border-bottom border-left border-color border-top-color border-right-color border-bottom-color border-left-color "
"border-image border-radius border-top-left-radius border-top-right-radius border-bottom-right-radius "
"border-bottom-left-radius border-style border-top-style border-right-style border-bottom-style border-left-style "
"border-width border-top-width border-right-width border-bottom-width border-left-width bottom button-layout color "
"dialogbuttonbox-buttons-have-icons font font-family font-size font-style font-weight height icon icon-size "
"image-position left margin margin-top margin-right margin-bottom margin-left max-height max-width min-height "
"min-width outline outline-color outline-offset outline-style outline-radius outline-bottom-left-radius "
"outline-bottom-right-radius outline-top-left-radius outline-top-right-radius padding padding-top padding-right "
"padding-bottom padding-left paint-alternating-row-colors-for-empty-area position right "
"titlebar-show-tooltips-on-buttons text-align text-decoration top width -qt-background-role -qt-style-features";

inline const char *lexerQSSKeyword2 =
"active adjoins-item alternate bottom checked closable closed default disabled editable edit-focus enabled exclusive "
"first flat floatable focus has-children has-siblings horizontal hover indeterminate last left maximized middle "
"minimized movable no-frame non-exclusive off on only-one open next-selected pressed previous-selected read-only right "
"selected top unchecked vertical window ";

inline const char *lexerQSSKeyword5 =
"add-line add-page branch chunk close-button corner down-arrow down-button drop-down float-button groove indicator "
"handle icon item left-arrow left-corner menu-arrow menu-button menu-indicator right-arrow pane right-corner scroller "
"section separator sub-line sub-page tab tab-bar tear tearoff text title up-arrow up-button";

inline const char *lexerQSSKeyword6 =
"gridline-color image lineedit-password-character lineedit-password-mask-delay messagebox-text-interaction-flags "
"opacity placeholder-text-color selection-background-color selection-color show-decoration-selected spacing "
"subcontrol-origin subcontrol-position widget-animation-duration";

class TpLexerQSS : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldComments);

public:
    enum
    {
        Default = 0,
        QtType = 1,
        QtClass = 2,
        PseudoQtClass = 3,
        UnknownPseudoQtClass = 4,
        Operator = 5,
        ObsoleteProperty = 6,
        UnknownProperty = 7,
        Value = 8,
        Comment = 9,
        QtIDSelector = 10,
        Important = 11,
        AtRule = 12,
        DoubleQuotedString = 13,
        SingleQuotedString = 14,
        Property = 15,
        Attribute = 16,
        ExperimentalProperty = 17,
        PseudoQtElement = 18,
        SpecificProperty = 19,
        SpecificPseudoQtClass = 20,
        SpecificPseudoQtElement = 21,
        MediaRule = 22,
        Variable = 23,
    };

    enum
    {
        PropFoldCompact,
        PropFoldComments,
    };

public:
    TpLexerQSS(QObject *parent = nullptr);
    virtual ~TpLexerQSS();

public:
    int autoIndentStyle();

    const char *language() const override;
    const char *lexer() const override;
    const char *blockEnd(int *style = nullptr) const override;
    const char *blockStart(int *style = nullptr) const override;
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

#endif // TPLEXERQSS_H
