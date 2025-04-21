#ifndef TPGENERALMENU_H
#define TPGENERALMENU_H

#include <QMenu>

#include <TpGlobals>

TP_NAMESPACE

class TpGeneralMenu : public QMenu
{
    Q_OBJECT

public:
    TpGeneralMenu(QWidget *parent, QString name = "");

public:
    void initialize(QString name);
};

TP_END_NAMESPACE

#endif // TPGENERALMENU_H
