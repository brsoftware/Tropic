#ifndef TPBOOKMARKVIEW_H
#define TPBOOKMARKVIEW_H

#include <QTreeWidget>

#include <Models/TpBookmarkItem>
#include <TpGlobals>

TP_NAMESPACE

class TpEditor;

class TpBookmarkView : public QTreeWidget
{
    Q_OBJECT

public:
    TpBookmarkView(TpEditor *parent);

public:
    TpBookmarkItem *addItem(int line);
    void removeItem(int line);

signals:
    void bookmarkItemDoubleClicked(int line);

private slots:
    void onItemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    TpEditor *m_parent;
    QMap<int, QTreeWidgetItem*> m_items;
};

TP_END_NAMESPACE

#endif // TPBOOKMARKVIEW_H
