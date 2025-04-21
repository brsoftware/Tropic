#include <QHeaderView>

#include <Views/TpBookmarkView>
#include <TpEditor>

TP_NAMESPACE

TpBookmarkView::TpBookmarkView(TpEditor *parent)
    : QTreeWidget(parent),
    m_parent(parent)
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
    setHeaderHidden(false);
    setHeaderLabels({tr("Line"), tr("Context")});
    setHidden(false);
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    setObjectName("bookmarkView");
    setSelectionBehavior(SelectRows);
    setSelectionMode(SingleSelection);
    setSortingEnabled(true);
    setUniformRowHeights(true);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    sortByColumn(0, Qt::SortOrder::AscendingOrder);

    header()->setSectionsClickable(true);
    header()->setSectionResizeMode(QHeaderView::ResizeMode::Interactive);

    connect(this,
            &TpBookmarkView::itemDoubleClicked,
            this,
            &TpBookmarkView::onItemDoubleClicked);
}

TpBookmarkItem *TpBookmarkView::addItem(int line)
{
    TpBookmarkItem *item = new TpBookmarkItem(this, line, m_parent->text().split('\n').at(line - 1));
    addTopLevelItem(item);
    m_items[line] = item;

    return item;
}

void TpBookmarkView::removeItem(int line)
{
    if (m_items.contains(line))
        delete m_items[line];
}

void TpBookmarkView::onItemDoubleClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);

    emit bookmarkItemDoubleClicked(item->text(0).toInt());
}

TP_END_NAMESPACE
