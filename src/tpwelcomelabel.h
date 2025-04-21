#ifndef TPWELCOMELABEL_H
#define TPWELCOMELABEL_H

#include <QLabel>

#include <TpGlobals>

TP_NAMESPACE

class TpStackedWidget;

class TpWelcomeLabel : public QLabel
{
    Q_OBJECT

public:
    TpWelcomeLabel(TpStackedWidget *parent);

private:
    TpStackedWidget *m_parent;
};

TP_END_NAMESPACE

#endif // TPWELCOMELABEL_H
