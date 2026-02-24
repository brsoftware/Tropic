#ifndef TPDOCUMENTVIEW_H
#define TPDOCUMENTVIEW_H

#include <QTreeWidget>

#include <Models/TpDocumentItem>
#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;

class TpDocumentView : public QTreeWidget
{
    Q_OBJECT

public:
    TpDocumentView(TpMainWindow *parent);

public:
    TpDocumentItem *addTab(TpTabWidget *tab);
    TpDocumentItem *addFile(TpTabWidget *tab, QString path, QString name);

signals:
    void fileDoubleClicked(TpTabWidget *tab, const QString &path);

public slots:
    void onCustomContextMenuRequested(const QPoint &point);
    void onItemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    TpMainWindow *m_parent;
    QMap<TpDocumentItem*, TpTabWidget*> m_items;
};

TP_END_NAMESPACE

#endif // TPDOCUMENTVIEW_H
