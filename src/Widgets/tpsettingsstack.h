#ifndef TPSETTINGSSTACK_H
#define TPSETTINGSSTACK_H

#include <QHBoxLayout>
#include <QListWidget>

#include <Widgets/TpSettingsPage>

TP_NAMESPACE

class TpSettingsStack : public QWidget
{
    Q_OBJECT

public:
    TpSettingsStack(QWidget *parent);

public:
    int addPage(TpSettingsPage *page);

    QListWidget *navigator() const;
    QStackedWidget *stackedWidget() const;

private slots:
    void onNavigatorDoubleClicked(QListWidgetItem *item);

private:
    QWidget *m_parent;
    QHBoxLayout *m_layout;
    QListWidget *m_nav;
    QStackedWidget *m_widget;
};

TP_END_NAMESPACE

#endif // TPSETTINGSSTACK_H
