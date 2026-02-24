#ifndef TPLEXERQUI_H
#define TPLEXERQUI_H

#include <Lexers/TpFamilyHTMLLexer>

TP_NAMESPACE

inline const char *lexerQUIKeyword1 =
"UI class comment author include pixmapfunction widget class property attribute item column hbox vbox grid string "
"cstring bool number enum set rect x y width height point x y size width height font family pointsize weight italic "
"underline strikeout color red green blue pximap image imageset sizepolicy hsizetype vsizetype palette active disabled "
"inactive cursor hbox property widget spacer vbox property widget spacer grid property widget spacer spacer name "
"orientation sizeType geometry item text pixmap column text pixmap resizable movable customwidget class header "
"location sizehint pixmap signal slots property type sender signal receiver slot access tabstops tabstop data row col "
"iconset normaloff normalon sizepolicy horstretch verstretch brush pen brushstyle penstyle alpha role colorrole "
"resources include location resource xml connections connection hint type hsizetype vsizetype layout column item";

class TpLexerQUI : public TpFamilyHTMLLexer
{
    Q_OBJECT

public:
    TpLexerQUI(QObject *parent = nullptr);

public:
    const char *language() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERQUI_H
