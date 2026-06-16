#ifndef TPFONTBUTTON_H
#define TPFONTBUTTON_H

#include <QPushButton>

#include <TpGlobals>

TP_NAMESPACE

class TpFontButton : public QPushButton
{
    Q_OBJECT

    DEF_PROP(QFont, font);

public:
    TpFontButton(QWidget *parent = nullptr);

public:
    DEF_PROP_FUNC(QFont, font, Font)

private slots:
    void showFontDialog(bool);
};

TP_END_NAMESPACE

#endif // TPFONTBUTTON_H
