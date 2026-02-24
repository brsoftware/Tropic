#ifndef TPCOMMANDSITEM_H
#define TPCOMMANDSITEM_H

#include <QTreeWidgetItem>

#include <TpGlobals>

TP_NAMESPACE

class TpCommandsView;

class TpCommandsItem : public QTreeWidgetItem
{
    Q_GADGET

    DEF_PROP(QObject*, action);

public:
    enum Type
    {
        Menu = UserType + 1,
        Action = UserType + 2,
        Submenu = UserType + 3,
    };

public:
    TpCommandsItem(TpCommandsView *parent, QMenu *action);
    TpCommandsItem(TpCommandsItem *parent, QMenu *action);
    TpCommandsItem(TpCommandsItem *parent, QAction *action);

public:
    void setAction(QObject *action);
    QObject *action() const;
    const QString &name() const;

private:
    TpCommandsView *m_parentView;
    TpCommandsItem *m_parentItem;
};

TP_END_NAMESPACE

#endif // TPCOMMANDSITEM_H
