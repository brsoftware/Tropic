#include <QHeaderView>

#include <Dialogs/TpDialogCommands>
#include <Views/TpCommandsView>
#include <TpGeneralAction>
#include <TpGeneralMenu>

TP_NAMESPACE

TpCommandsView::TpCommandsView(TpDialogCommands *parent)
    : QTreeWidget(parent),
    m_parent(parent),
    m_best(nullptr),
    m_bestScore(0)
{
    setAcceptDrops(false);
    setAllColumnsShowFocus(true);
    setAlternatingRowColors(false);
    setAnimated(true);
    setAutoExpandDelay(250);
    setAutoScroll(true);
    setAutoScrollMargin(16);
    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    setDefaultDropAction(Qt::DropAction::MoveAction);
    setDragEnabled(false);
    setEditTriggers(NoEditTriggers);
    setEnabled(true);
    setExpandsOnDoubleClick(true);
    setHeaderHidden(true);
    setHidden(false);
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    setObjectName("commandsView");
    setSelectionBehavior(SelectRows);
    setSelectionMode(SingleSelection);
    setSortingEnabled(false);
    setUniformRowHeights(true);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);

    header()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);

    connect(this,
            &TpCommandsView::customContextMenuRequested,
            this,
            &TpCommandsView::onCustomContextMenuRequested);
    connect(this,
            &TpCommandsView::itemDoubleClicked,
            this,
            &TpCommandsView::onItemDoubleClicked);
}

TpCommandsItem *TpCommandsView::add(QMenu *menu)
{
    TpCommandsItem *topLevel = new TpCommandsItem(this, menu);
    addTopLevelItem(topLevel);

    for (const auto &child : menu->children())
    {
        if (QMenu *m = qobject_cast<QMenu*>(child))
        {
            takeSubmenu(topLevel, m);
        }

        else if (QAction *a = qobject_cast<QAction*>(child))
        {
            if (a == menu->menuAction() || !menu->actions().contains(a))
                continue;
            takeAction(topLevel, a);
        }
    }

    return topLevel;
}

void TpCommandsView::onLineEditTextChanged(const QString &text)
{
    m_best = nullptr;
    m_bestScore = 0;

    if (text.isEmpty())
    {
        for (int i = 0; i < topLevelItemCount(); i++)
            unhideRecursively(static_cast<TpCommandsItem*>(topLevelItem(i)));
        return;
    }

    /*for (int i = 0; i < topLevelItemCount(); i++)
    {
        TpCommandsItem *topLevel = static_cast<TpCommandsItem*>(topLevelItem(i));
        filterItem(topLevel, text);
    }*/

    for (int i = 0; i < topLevelItemCount(); i++)
        filterByScore(static_cast<TpCommandsItem*>(topLevelItem(i)), text);

    if (m_best)
    {
        setCurrentItem(m_best);
        scrollToItem(m_best);
    }
}

void TpCommandsView::takeAction(TpCommandsItem *parent, QAction *action)
{
    if (action->isSeparator() || action->text().isEmpty())
        return;
    TpCommandsItem *a = new TpCommandsItem(parent, action);
    parent->addChild(a);
}

void TpCommandsView::takeSubmenu(TpCommandsItem *parent, QMenu *menu)
{
    TpCommandsItem *m = new TpCommandsItem(parent, menu);
    parent->addChild(m);

    for (const auto &child : menu->children())
    {
        if (QMenu *mn = qobject_cast<QMenu*>(child))
        {
            takeSubmenu(m, mn);
        }

        else if (QAction *a = qobject_cast<QAction*>(child))
        {
            if (a == menu->menuAction() || !menu->actions().contains(a))
                continue;
            takeAction(m, a);
        }
    }
}

bool TpCommandsView::filterItem(TpCommandsItem *item, const QString &filter)
{
    bool anyChildVisible = false;

    for (int index = 0; index < item->childCount(); index++)
    {
        TpCommandsItem *child = static_cast<TpCommandsItem*>(item->child(index));
        anyChildVisible |= filterItem(child, filter);
    }

    QString name = item->text(0).toLower().simplified();
    QString needle = filter.toLower().simplified();

    bool thisMatch = name.contains(needle) || levenshteinDistance(name, needle) <= 2;
    bool visible = thisMatch || anyChildVisible;
    item->setHidden(!visible);

    if (visible)
        item->setExpanded(true);

    return visible;
}

int TpCommandsView::filterByScore(TpCommandsItem *item, const QString &filter)
{
    int bestChildScore = 0;

    for (int index = 0; index < item->childCount(); index++)
    {
        auto *child = static_cast<TpCommandsItem*>(item->child(index));
        bestChildScore = qMax(bestChildScore, filterByScore(child, filter));
    }

    int score = scoreItem(item, filter);

    if (item->type() == TpCommandsItem::Type::Action)
        score += 50;

    int finalScore = qMax(score, bestChildScore);

    item->setHidden(finalScore <= 50 && bestChildScore <= 50);

    if (finalScore > 50)
        item->setExpanded(true);

    if (score > m_bestScore)
    {
        m_bestScore = score;
        m_best = item;
    }

    return finalScore;
}

void TpCommandsView::unhideRecursively(TpCommandsItem *item)
{
    item->setHidden(false);
    for (int i = 0; i < item->childCount(); i++)
        unhideRecursively(static_cast<TpCommandsItem*>(item->child(i)));
}

int TpCommandsView::scoreItem(TpCommandsItem *item, const QString &filter)
{
    QString name = item->text(0).toLower().simplified();
    QString q = filter.toLower().simplified();

    if (q.isEmpty())
        return 0;
    if (name == q)
        return 1'000;
    if (name.startsWith(q))
        return 700;
    if (name.contains(q))
        return 500;

    QString initials;
    for (const auto &part : name.split(' '))
        if (!part.isEmpty())
            initials += part.at(0);
    if (initials.startsWith(q))
        return 400;

    int qi = 0;
    for (const auto &c : std::as_const(name))
        if (qi < q.size() && c == q.at(qi))
            qi++;
    if (qi == q.length())
        return 300;

    int dist = levenshteinDistance(name, q);
    if (dist <= 2)
        return 100 - dist * 20;
    return 0;
}

void TpCommandsView::onCustomContextMenuRequested(const QPoint &point)
{
#ifndef QT_NO_CONTEXTMENU
    TpCommandsItem *item = static_cast<TpCommandsItem*>(itemAt(point));

    if (item)
    {
        bool isAction = (item->type() == TpCommandsItem::Type::Action);

        if (isAction)
        {
            TpGeneralMenu *menu = new TpGeneralMenu(this, tr("&Commands View"));
            TpGeneralAction *trigger = new TpGeneralAction(menu, tr("&Trigger the Action"), QKeySequence(), true);

            connect(trigger,
                    &QAction::triggered,
                    this,
            [=, this](bool){
                if (QAction *ac = qobject_cast<QAction*>(item->action()))
                    if (ac->isEnabled())
                        ac->trigger();
            });

            menu->exec(mapToGlobal(point));
        }
    }
#endif
}

void TpCommandsView::onItemDoubleClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);

    TpCommandsItem *i = static_cast<TpCommandsItem*>(item);
    emit commandsItemDoubleClicked(i->action());

    if (QAction *ac = qobject_cast<QAction*>(i->action()))
    {
        if (ac->isEnabled())
        {
            ac->trigger();
            m_parent->close();
        }
    }
}

TP_END_NAMESPACE
