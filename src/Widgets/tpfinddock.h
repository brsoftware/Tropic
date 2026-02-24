#ifndef TPFINDDOCK_H
#define TPFINDDOCK_H

#include <QDockWidget>

#include <TpGlobals>

TP_NAMESPACE

class TpEditor;
class TpFindContainer;
class TpMainWindow;

class TpFindDock : public QDockWidget
{
    Q_OBJECT

public:
    TpFindDock(TpMainWindow *parent);

public:
    void setContainer(TpFindContainer *container);
    TpFindContainer *container() const;

protected:
    virtual void closeEvent(QCloseEvent *event) override;

private:
    TpFindContainer *m_container;
};

TP_END_NAMESPACE

#endif // TPFINDDOCK_H
