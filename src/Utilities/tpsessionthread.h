#ifndef TPSESSIONTHREAD_H
#define TPSESSIONTHREAD_H

#include <QThread>

#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;

class TpSessionThread : public QThread
{
    Q_OBJECT

public:
    explicit TpSessionThread(TpMainWindow *parent);

protected:
    void run() override;

private:
    TpMainWindow *m_parent;
};

TP_END_NAMESPACE

#endif // TPSESSIONTHREAD_H
