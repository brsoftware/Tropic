#ifndef TPGENERALTOOLBAR_H
#define TPGENERALTOOLBAR_H

#include <QToolBar>

#include <TpGlobals>

TP_NAMESPACE

class TpGeneralToolBar : public QToolBar
{
    Q_OBJECT

public:
    TpGeneralToolBar(QWidget *parent = nullptr, QString name = "");
};

TP_END_NAMESPACE

#endif // TPGENERALTOOLBAR_H
