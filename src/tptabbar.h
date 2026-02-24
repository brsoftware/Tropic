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

signals:
    void dragged();
    void midButtonTabCloseRequested(int index);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void onCustomContextMenuRequested(const QPoint &point);

private:
    TpTabWidget *m_parent;
    QPoint m_dragPosition;
};

TP_END_NAMESPACE

#endif // TPTABBAR_H
