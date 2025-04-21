#ifndef TPGENERALTOOLBUTTON_H
#define TPGENERALTOOLBUTTON_H

#include <QToolButton>

#include <TpGlobals>

TP_NAMESPACE

class TpGeneralToolButton : public QToolButton
{
    Q_OBJECT

public:
    TpGeneralToolButton(bool isFind = false, QWidget *parent = nullptr);
};

TP_END_NAMESPACE

#endif // TPGENERALTOOLBUTTON_H
