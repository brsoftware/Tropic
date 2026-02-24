#include <QMenu>

#include <Models/TpCommandsItem>
#include <Views/TpCommandsView>

TP_NAMESPACE

TpCommandsItem::TpCommandsItem(TpCommandsView *parent, QMenu *action)
    : QTreeWidgetItem(parent, Menu),
    m_parentView(parent),
    m_parentItem(nullptr),
    m_action(action)
{
    setChildIndicatorPolicy(DontShowIndicatorWhenChildless);
    setDisabled(false);
    setExpanded(true);
    setFirstColumnSpanned(true);
    setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled);
    setAction(action);
}

TpCommandsItem::TpCommandsItem(TpCommandsItem *parent, QMenu *action)
    : QTreeWidgetItem(parent, Submenu)
{
    m_parentView = nullptr;
    m_parentItem = parent;
    m_action = action;

    setChildIndicatorPolicy(DontShowIndicatorWhenChildless);
    setDisabled(false);
    setExpanded(true);
    setFirstColumnSpanned(true);
    setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled);
    setAction(action);
}

TpCommandsItem::TpCommandsItem(TpCommandsItem *parent, QAction *action)
    : QTreeWidgetItem(parent, Action)
{
    m_parentView = nullptr;
    m_parentItem = parent;
    m_action = action;

    setChildIndicatorPolicy(DontShowIndicatorWhenChildless);
    setDisabled(false);
    setExpanded(true);
    setFirstColumnSpanned(true);
    setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled);
    setAction(action);
}

void TpCommandsItem::setAction(QObject *action)
{
    m_action = action;

    if (type() == Action)
        setText(0, qobject_cast<QAction*>(m_action)->toolTip());
    else
        setText(0, qobject_cast<QMenu*>(m_action)->title().replace("&", ""));

    setToolTip(0, name());
}

QObject *TpCommandsItem::action() const
{
    return m_action;
}

const QString &TpCommandsItem::name() const
{
    static QString result;
    TpCommandsItem *p = m_parentItem;
    if (type() != Menu)
        result = p->name() + QString(" > %1").arg(text(0).replace("&", ""));
    else
        result = text(0);
    return result;
}

TP_END_NAMESPACE
