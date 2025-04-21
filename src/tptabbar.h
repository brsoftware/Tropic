#ifndef TPTABBAR_H
#define TPTABBAR_H

#include <QTabBar>

#include <TpGlobals>

TP_NAMESPACE

class TpTabWidget;

class TpTabBar : public QTabBar
{
    Q_OBJECT

public:
    TpTabBar(TpTabWidget *parent);

private:
    TpTabWidget *m_parent;
};

TP_END_NAMESPACE

#endif // TPTABBAR_H
