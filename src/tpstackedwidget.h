#ifndef TPSTACKEDWIDGET_H
#define TPSTACKEDWIDGET_H

#include <QStackedWidget>

#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;
class TpTabSplitter;
class TpWelcomeLabel;

class TpStackedWidget : public QStackedWidget
{
    Q_OBJECT

    friend class TpEditor;
    friend class TpTabSplitter;
    friend class TpTabWidget;

public:
    TpStackedWidget(TpMainWindow *parent);

public:
    TpTabSplitter *tabs() const;

private slots:
    void onTabsListChanged(int count);

private:
    TpMainWindow *m_parent;
    TpWelcomeLabel *m_label;
    TpTabSplitter *m_splitter;
};

TP_END_NAMESPACE

#endif // TPSTACKEDWIDGET_H
