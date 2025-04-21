#ifndef TPBOOKMARKITEM_H
#define TPBOOKMARKITEM_H

#include <QTreeWidgetItem>

#include <TpGlobals>

TP_NAMESPACE

class TpBookmarkView;

class TpBookmarkItem : public QTreeWidgetItem
{
    Q_GADGET

    DEF_PROP(int, line);
    DEF_PROP(QString, context);

public:
    TpBookmarkItem(TpBookmarkView *view, int line, QString context);

public:
    void setLine(int line);
    int line() const;
    void setContext(QString context);
    const QString &context() const;
};

TP_END_NAMESPACE

#endif // TPBOOKMARKITEM_H
