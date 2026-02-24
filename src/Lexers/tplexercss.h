#ifndef TPLEXERCSS_H
#define TPLEXERCSS_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

inline const char *lexerCSSKeyword1 =
"box-align box-direction box-flex box-flex-group box-lines box-ordinal-group box-orient box-pack clip font-smooth "
"user-modify";

inline const char *lexerCSSKeyword2 =
"active any-link autofill blank buffering checked current default defined dir disabled empty enabled first first-child "
"first-of-type focus focus-visible focus-within fullscreen future has has-slotted host host-context hover in-range "
"indeterminate invalid is lang last-child last-of-type left link local-link modal muted not nth-child nth-last-child "
"nth-of-type only-child only-of-type optional out-of-range past paused picture-in-picture placeholder-shown playing "
"popover-open read-only read-write required right root scope seeking stalled state target target-within user-invalid "
"user-valid valid visited volume-locked where";

inline const char *lexerCSSKeyword3 =
"align-content align-items align-self all animation animation-composition animation-delay animation-direction "
"animation-duration animation-fill-mode animation iteration-count animation-name animation-play-state "
"animation-timing-function appearance aspect-ratio backdrop-filter backface-visibility background "
"background-attachment background-blend-mode background-clip background-color background-image background-origin "
"background-position background-position-x background-position-y background-repeat background-size block-size border "
"border-block border-block-color border-block-end border-block-end-color border-block-end-style border-block-end-width "
"border-block-start border-block-start-color border-block-start-style border-block-start-width border-block-style "
"border-block-width border-bottom border-bottom-color border-bottom-left-radius border-bottom-right-radius "
"border-bottom-style border-bottom-width border-collapse border-color border-end-end-radius border-end-start-radius "
"border-image border-image-outset border-image-repeat border-image-slice border-image-source border-image-width "
"border-inline border-inline-color border-inline-end border-inline-end-color border-inline-end-style "
"border-inline-end-width border-inline-start border-inline-start-color border-inline-start-style "
"border-inline-start-width border-inline-style border-inline-width border-left border-left-color border-left-style "
"border-left-width border-radius border-right border-right-color border-right-style border-right-width "
"border-right-style border-right-width border-spacing border-start-end-radius border-start-start-radius border-style "
"border-top border-top-color border-top-left-radius border-top-right-radius border-top-style border-top-width "
"border-width bottom box-decoration-break box-shadow box-sizing break-after break-before break-inside caption-side "
"caret-color clear clip-path clip-rule color color-interpolation color-interpolation-filters color-scheme column-count "
"column-fill column-gap column-rule column-rule-color column-rule-style column-rule-width column-span column-width "
"columns contain contain-intrinsic-block-size contain-intrinsic-height contain-intrinsic-inline-size "
"contain-intrinsic-size contain-intrinsic-width container-name container-type content content-visibility "
"counter-increment counter-reset counter-set cursor cx cy d direction display dominant-baseline empty-cells fill "
"fill-opacity fill-rule filter flex flex-basis flex-direction flex-flow flex-grow flex-shrink flex-wrap float "
"flood-color flood-opacity font font-family font-feature-settings font-kerning font-language-override "
"font-optical-sizing font-palette font-size font-size-adjust font-stretch font-style font-synthesis "
"font-synthesis-small-caps font-synthesis-style font-synthesis-weight font-variant font-variant-alternates "
"font-variant-caps font-variant-east-asian font-variant-emoji font-variant-ligatures font-variant-numeric "
"font-variant-position font-variation-settings font-weight forced-color-adjust gap grid grid-area grid-auto-columns "
"grid-auto-rows grid-column grid-column-end grid-column-start grid-row grid-row-end grid-row-start grid-template "
"grid-template-areas grid-template-columns grid-template-rows hanging-punctuation height hyphenate-character "
"hyphenate-limit-chars hyphens image-orientation image-rendering initial-letter inline-size inset inset-block "
"inset-block-end inset-block-start inset-inline inset-inline-end inset-inline-start isolation justify-content "
"justify-items justify-self left letter-spacing lighting-color line-break line-height list-style list-style-image "
"list-style-position list-style-type margin margin-block margin-block-end margin-block-start margin-bottom "
"margin-inline margin-inline-end margin-inline-start margin-left margin-right margin-top marker marker-end marker-mid "
"marker-start mask mask-border mask-border-mode mask-border-outset mask-border-repeat mask-border-slice "
"mask-border-source mask-border-width mask-clip mask-composite mask-image mask-mode mask-origin mask-position "
"mask-repeat mask-size mask-type math-depth math-style max-block-size max-height max-inline-size max-width "
"min-block-size min-height min-inline-size min-width mix-blend-mode object-fit object-position offset offset-anchor "
"offset-distance offset-path offset-position offset-rotate opacity order orphans outline outline-color outline-offset "
"outline style outline-width overflow overflow-anchor overflow-block overflow-clip-margin overflow-inline "
"overflow-wrap overflow-x overflow-y overscroll-behavior overscroll-behavior-block overscroll-behavior-inline "
"overscroll-behavior-x overscroll-behavior-y padding padding-block padding-block-end padding-block-start "
"padding-bottom padding-inline padding-inline-end padding-inline-start padding-left padding-right padding-top page "
"page-break-after page-break-before page-break-inside paint-order perspective perspective-origin place-content "
"place-items place-self pointer-events position print-color-adjust quotes r resize right rotate row-gap ruby-align "
"ruby-position rx ry scale scroll-behavior scroll-margin scroll-margin-block scroll-margin-block-end "
"scroll-margin-block-start scroll-margin-bottom scroll-margin-inline scroll-margin-inline-end "
"scroll-margin-inline-start scroll-margin-left scroll-margin-right scroll-margin-top scroll-padding "
"scroll-padding-block scroll-padding-block-end scroll-padding-block-start scroll-padding-bottom scroll-padding-inline "
"scroll-padding-inline-end scroll-padding-inline-start scroll-padding-left scroll-padding-right scroll-padding-top "
"scroll-snap-align scroll-snap-stop scroll-snap-type scrollbar-color scrollbar-gutter scrollbar-width "
"shape-image-threshold shape-margin shape-outside shape-rendering stop-color stop-opacity stroke stroke-dasharray "
"stroke-dashoffset stroke-linecap stroke-linejoin stroke-miterlimit stroke-opacity stroke-width tab-size table-layout "
"text-align text-align-last text-anchor text-combine-upright text-decoration text-decoration-color "
"text-decoration-line text-decoration-skip-ink text-decoration-style text-decoration-thickness text-emphasis "
"text-emphasis-color text-emphasis-position text-emphasis-style text-indent text-justify text-orientation "
"text-overflow text-rendering text-shadow text-transform text-underline-offset text-underline-position text-wrap "
"text-wrap-mode text-wrap-style top touch-action transform transform-box transform-origin transform-style transition "
"transition-behavior transition-delay transition-duration transition-property transition-timing-function translate "
"unicode-bidi user-select vector-effect vertical-align view-transition-name visibility white-space "
"white-space-collapse widows width will-change word-break word-spacing writing-mode x y z-index zoom"
" "
"align-content align-items align-self alignment-adjust alignment-baseline all animation animation-delay "
"animation-direction animation-duration animation-fill-mode animation-iteration-count animation-name "
"animation-play-state animation-timing-function appearance azimuth backface-visibility background "
"background-attachment background-blend-mode background-break background-clip background-color background-image "
"background-origin background-position background-position-x background-position-y background-repeat background-size "
"baseline-shift binding bleed block-size bookmark-label bookmark-level bookmark-state bookmark-target border "
"border-block border-block-end border-block-start border-bottom border-bottom-color border-bottom-left-radius "
"border-bottom-right-radius border-bottom-style border-bottom-width border-collapse border-color border-image "
"border-image-outset border-image-repeat border-image-slice border-image-source border-image-width border-inline "
"border-inline-end border-inline-end-width border-inline-start border-inline-start-color border-inline-start-style "
"border-inline-start-width border-left border-left-color border-left-style border-left-width border-radius "
"border-right border-right-color border-right-style border-right-width border-spacing border-style border-top "
"border-top-color border-top-left-radius border-top-right-radius border-top-style border-top-width border-width bottom "
"box-decoration-break box-orient "
"box-shadow box-sizing break-after break-before break-inside caption-side caret-color clear color color-profile "
"column-count column-fill column-gap column-rule column-rule-color column-rule-style column-rule-width column-span "
"column-width columns content counter-increment counter-reset crop cue cue-after cue-before cursor direction display "
"dominant-baseline drop-initial-after-adjust drop-initial-after-align drop-initial-before-adjust "
"drop-initial-before-align drop-initial-size drop-initial-value elevation empty-cells fill fill-opacity filter fit "
"fit-position flex flex-basis flex-direction flex-flow flex-grow flex-shrink flex-wrap float float-offset font "
"font-effect font-emphasize font-family font-size font-size-adjust font-stretch font-style font-variant "
"font-variant-ligatures font-weight gap grid-area grid-auto-flow grid-auto-rows grid-column grid-column-end "
"grid-column-gap grid-column-start grid-columns grid-gap grid-row grid-row-gap grid-rows grid-template-areas "
"grid-template-columns grid-template-rows hanging-punctuation height hyphenate-after hyphenate-before "
"hyphenate-character hyphenate-lines hyphenate-resource hyphens icon image-orientation image-rendering "
"inline-box-align inline-size inset inset-inline-end inset-inline-start justify-content justify-items "
"justify-self left letter-spacing line-height line-stacking line-stacking-ruby line-stacking-shift "
"line-stacking-strategy list-style list-style-image list-style-position list-style-type margin margin-block "
"margin-block-end margin-block-start margin-bottom margin-inline margin-inline-end margin-inline-start margin-left "
"margin-right margin-top mark mark-after mark-before marker-offset marks marquee-direction marquee-play-count "
"marquee-speed marquee-style mask mask-clip mask-image mask-origin mask-position mask-position-x mask-repeat mask-size "
"max-height max-width min-block-size min-height min-inline-size min-width mix-blend-mode move-to nav-down nav-index "
"nav-left nav-right nav-up object-fit opacity order orphans outline outline-color outline-offset outline-style "
"outline-width overflow overflow-anchor overflow-style overflow-wrap overflow-x overflow-y padding padding-block "
"padding-block-end padding-block-start padding-bottom padding-inline padding-inline-end padding-inline-start "
"padding-left padding-right padding-top page page-break-after page-break-before page-break-inside page-policy "
"paint-order pause pause-after pause-before perspective perspective-origin phonemes pitch pitch-range play-during "
"pointer-events position presentation-level punctuation-trim quotes rendering-intent resize rest rest-after "
"rest-before richness right rotation rotation-point ruby-align ruby-overhang ruby-position ruby-span scrollbar-color "
"size speak speak-header speak-numeral speak-punctuation speech-rate stress string-set stroke stroke-dasharray "
"stroke-linejoin stroke-opacity stroke-width tab-size table-layout target target-name target-new target-position "
"text-align text-align-last text-anchor text-decoration text-decoration-color text-decoration-line "
"text-decoration-style text-emphasis text-height text-indent text-justify text-outline text-overflow text-rendering "
"text-shadow text-transform text-wrap top transform transform-origin transform-style transition transition-delay "
"transition-duration transition-property transition-timing-function unicode-bidi user-select vector-effect "
"vertical-align visibility voice-balance voice-duration voice-family voice-pitch voice-pitch-range voice-rate "
"voice-stress voice-volume volume white-space white-space-collapse widows width will-change word-break word-spacing "
"word-wrap z-index";

inline const char *lexerCSSKeyword4 =
"anchor-name animation-range animation-range-end animation-range-start animation-timeline field-sizing "
"font-synthesis-position image-resolution interpolate-size line-height-step margin-trim math-shift overlay "
"position-anchor position-area position-try position-try-fallbacks position-try-order position-visibility "
"scroll-timeline scroll-timeline-axis scroll-timeline-name text-decoration-skip text-size-adjust text-spacing-trim "
"timeline-scope view-timeline view-timeline-axis view-timeline-inset view-timeline-name";

inline const char *lexerCSSKeyword5 =
"after backdrop before cue file-selector-button first-letter first-line grammar-error highlight marker part "
"placeholder selection slotted spelling-error target-text view-transition view-transition-group "
"view-transition-image-pair view-transition-new view-transition-old";

inline const char *lexerCSSKeyword6 =
"-moz-float-edge -moz-force-broken-image-icon -moz-image-region -moz-orient -moz-user-focus -moz-user-input"
" "
"-webkit-border-before -webkit-box-reflect -webkit-line-clamp -webkit-mask-box-image -webkit-mask-composite "
"-webkit-mask-position-x -webkit-mask-position-y -webkit-mask-repeat-x -webkit-mask-repeat-y "
"-webkit-tap-highlight-color -webkit-text-fill-color -webkit-text-security -webkit-text-stroke "
"-webkit-text-stroke-color -webkit-text-stroke-width -webkit-touch-callout"
" "
"-khtml-background-clip -khtml-background-origin -khtml-background-size -khtml-border-bottom-left-radius "
"-khtml-border-bottom-right-radius -khtml-border-radius -khtml-border-top-left-radius -khtml-border-top-right-radius "
"-khtml-opacity -moz-animation -moz-animation-delay -moz-animation-direction -moz-animation-duration "
"-moz-animation-fill-mode -moz-animation-iteration-count -moz-animation-name -moz-animation-play-state "
"-moz-animation-timing-function -moz-appearance -moz-background-clip -moz-background-inline-policy "
"-moz-background-origin -moz-background-size -moz-binding -moz-border-bottom-colors -moz-border-end "
"-moz-border-end-color -moz-border-end-style -moz-border-end-width -moz-border-image -moz-border-left-colors "
"-moz-border-radius -moz-border-radius-bottomleft -moz-border-radius-bottomright -moz-border-radius-topleft "
"-moz-border-radius-topright -moz-border-right-colors -moz-border-start -moz-border-start-color "
"-moz-border-start-style -moz-border-start-width -moz-border-top-colors -moz-box-align -moz-box-direction "
"-moz-box-flex -moz-box-flex-group -moz-box-flexgroup -moz-box-ordinal-group -moz-box-orient -moz-box-pack "
"-moz-box-shadow -moz-box-sizing -moz-column-count -moz-column-gap -moz-column-rule -moz-column-rule-color "
"-moz-column-rule-style -moz-column-rule-width -moz-column-width -moz-context-properties -moz-float-edge "
"-moz-force-broken-image-icon -moz-image-region -moz-linear-gradient -moz-margin-end -moz-margin-start -moz-opacity "
"-moz-outline -moz-outline-color -moz-outline-offset -moz-outline-radius -moz-outline-radius-bottomleft "
"-moz-outline-radius-bottomright -moz-outline-radius-topleft -moz-outline-radius-topright -moz-outline-style "
"-moz-outline-width -moz-padding-end -moz-padding-start -moz-radial-gradient -moz-stack-sizing "
"-moz-text-decoration-color -moz-text-decoration-line -moz-text-decoration-style -moz-transform -moz-transform-origin "
"-moz-transition -moz-transition-delay -moz-transition-duration -moz-transition-property "
"-moz-transition-timing-function -moz-user-focus -moz-user-input -moz-user-modify -moz-user-select -moz-window-shadow "
"-ms-filter -ms-transform -ms-transform-origin -o-transform -webkit-animation -webkit-animation-delay "
"-webkit-animation-direction -webkit-animation-duration -webkit-animation-fill-mode -webkit-animation-iteration-count "
"-webkit-animation-name -webkit-animation-play-state -webkit-animation-timing-function -webkit-appearance "
"-webkit-backface-visibility -webkit-background-clip -webkit-background-composite -webkit-background-origin "
"-webkit-background-size -webkit-border-bottom-left-radius -webkit-border-bottom-right-radius "
"-webkit-border-horizontal-spacing -webkit-border-image -webkit-border-radius -webkit-border-top-left-radius "
"-webkit-border-top-right-radius -webkit-border-vertical-spacing -webkit-box-align -webkit-box-direction "
"-webkit-box-flex -webkit-box-flex-group -webkit-box-lines -webkit-box-ordinal-group -webkit-box-orient "
"-webkit-box-pack -webkit-box-reflect -webkit-box-shadow -webkit-box-sizing -webkit-column-break-after "
"-webkit-column-break-before -webkit-column-break-inside -webkit-column-count -webkit-column-gap -webkit-column-rule "
"-webkit-column-rule-color -webkit-column-rule-style -webkit-column-rule-width -webkit-column-width -webkit-columns "
"-webkit-dashboard-region -webkit-font-smoothing -webkit-gradient -webkit-line-break -webkit-linear-gradient "
"-webkit-margin-bottom-collapse -webkit-margin-collapse -webkit-margin-start -webkit-margin-top-collapse "
"-webkit-marquee -webkit-marquee-direction -webkit-marquee-increment -webkit-marquee-repetition -webkit-marquee-speed "
"-webkit-marquee-style -webkit-mask -webkit-mask-attachment -webkit-mask-box-image -webkit-mask-clip "
"-webkit-mask-composite -webkit-mask-image -webkit-mask-origin -webkit-mask-position -webkit-mask-position-x "
"-webkit-mask-position-y -webkit-mask-repeat -webkit-mask-size -webkit-nbsp-mode -webkit-padding-start "
"-webkit-perspective -webkit-perspective-origin -webkit-radial-gradient -webkit-rtl-ordering "
"-webkit-tap-highlight-color -webkit-text-fill-color -webkit-text-security -webkit-text-size-adjust "
"-webkit-text-stroke -webkit-text-stroke-color -webkit-text-stroke-width -webkit-touch-callout -webkit-transform "
"-webkit-transform-origin -webkit-transform-origin-x -webkit-transform-origin-y -webkit-transform-origin-z "
"-webkit-transform-style -webkit-transition -webkit-transition-delay -webkit-transition-duration "
"-webkit-transition-property -webkit-transition-timing-function -webkit-user-drag -webkit-user-modify "
"-webkit-user-select";

inline const char *lexerCSSKeyword7 =
"-moz-broken -moz-drag-over -moz-first-node -moz-handler-blocked -moz-handler-crashed -moz-handler-disabled "
"-moz-last-node -most-loading -moz-locale-dir -moz-only-whitespace -moz-submit-invalid -moz-suppressed "
"-moz-user-disabled -moz-window-inactive";

inline const char *lexerCSSKeyword8 =
"-moz-color-swatch -moz-focus-inner -moz-list-bullet -moz-list-number -moz-meter-bar -moz-progress-bar "
"-moz-range-progress -moz-range-thumb -moz-range-track -webkit-inner-spin-button -webkit-meter-bar "
"-webkit-meter-even-less-good-value -webkit-meter-inner-element -webkit-meter-optimum-value "
"-webkit-meter-suboptimum-value -webkit-progress-bar -webkit-progress-inner-element -webkit-progress-value "
"-webkit-scrollbar -webkit-search-cancel-button -webkit-search-results-button -webkit-slider-runnable-track "
"-webkit-slider-thumb";

class TpLexerCSS : public TpGeneralLexer
{
    Q_OBJECT

    DEF_PROP(bool, foldCompact);
    DEF_PROP(bool, foldComments);
    DEF_PROP(int, language);

public:
    enum
    {
        CSS,
        SCSS,
        LESS,
        HSS,
    };

    enum
    {
        Default = 0,
        Tag = 1,
        ClassSelector = 2,
        PseudoClass = 3,
        UnknownPseudoClass = 4,
        Operator = 5,
        ObsoleteProperty = 6,
        UnknownProperty = 7,
        Value = 8,
        Comment = 9,
        IDSelector = 10,
        Important = 11,
        AtRule = 12,
        DoubleQuotedString = 13,
        SingleQuotedString = 14,
        Property = 15,
        Attribute = 16,
        ExperimentalProperty = 17,
        PseudoElement = 18,
        BrowserSpecificProperty = 19,
        BrowserSpecificPseudoClass = 20,
        BrowserSpecificPseudoElement = 21,
        MediaRule = 22,
        Variable = 23,
    };

    enum
    {
        PropFoldCompact,
        PropFoldComments,
        PropLanguage,
    };

public:
    TpLexerCSS(QObject *parent = nullptr);
    virtual ~TpLexerCSS();

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

#endif // TPLEXERCSS_H
