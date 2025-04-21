#ifndef TPTABSPLITTER_H
#define TPTABSPLITTER_H

#include <QSplitter>

#include <TpGlobals>

TP_NAMESPACE

class TpStackedWidget;
class TpTabWidget;

class TpTabSplitter : public QSplitter
{
    Q_OBJECT

    friend class TpEditor;
    friend class TpMainWindow;
    friend class TpStackedWidget;
    friend class TpTabWidget;

public:
    TpTabSplitter(TpStackedWidget *parent);

public:
    TpTabWidget *tab();

    void addTab(TpTabWidget *tab);
    bool removeTab(TpTabWidget *tab);
    bool hasTab() const;

signals:
    void tabsListChanged(int count);
    void tabChanged(TpTabWidget *tab, int index);
    void tabCloseRequested(TpTabWidget *tab, int index);

protected:
    bool eventFilter(QObject *object, QEvent *event) override;

private slots:
    void onTabIndexChanged(int index);
    void onTabCloseRequested(int index);

private:
    TpStackedWidget *m_parent;
    QList<TpTabWidget*> m_tabs;
};

TP_END_NAMESPACE

#endif // TPTABSPLITTER_H
