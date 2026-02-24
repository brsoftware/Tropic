#include <QHeaderView>

#include <Views/TpDocumentView>
#include <TpGeneralAction>
#include <TpGeneralMenu>
#include <TpMainWindow>
#include <TpTabWidget>

TP_NAMESPACE

TpDocumentView::TpDocumentView(TpMainWindow *parent)
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
    setHeaderHidden(true);
    setHidden(false);
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    setObjectName("documentView");
    setSelectionBehavior(SelectRows);
    setSelectionMode(SingleSelection);
    setSortingEnabled(true);
    setUniformRowHeights(true);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    sortByColumn(0, Qt::SortOrder::AscendingOrder);

    header()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);

    connect(this,
            &TpDocumentView::customContextMenuRequested,
            this,
            &TpDocumentView::onCustomContextMenuRequested);
    connect(this,
            &TpDocumentView::itemDoubleClicked,
            this,
            &TpDocumentView::onItemDoubleClicked);
}

TpDocumentItem *TpDocumentView::addTab(TpTabWidget *tab)
{
    TpDocumentItem *item = new TpDocumentItem(this, tab);
    addTopLevelItem(item);
    m_items[item] = tab;

    return item;
}

TpDocumentItem *TpDocumentView::addFile(TpTabWidget *tab, QString path, QString name)
{
    TpDocumentItem *parent = m_items.key(tab, nullptr);

    if (parent)
    {
        TpDocumentItem *item = new TpDocumentItem(parent, tab, path, name);
        parent->addChild(item);
        return item;
    }

    return nullptr;
}

void TpDocumentView::onCustomContextMenuRequested(const QPoint &point)
{
#ifndef QT_NO_CONTEXTMENU
    TpDocumentItem *item = static_cast<TpDocumentItem*>(itemAt(point));

    if (item)
    {
        bool isTab = (item->type() == TpDocumentItem::ItemType::Tab);
        bool isFile = (item->type() == TpDocumentItem::ItemType::File);

        TpGeneralMenu *menu = new TpGeneralMenu(this, tr("&Opened Documents"));

        if (isTab)
        {
            TpGeneralAction *focus = new TpGeneralAction(menu, tr("&Focus Tab"), QKeySequence(), true);

            connect(focus,
                    &QAction::triggered,
                    this,
            [=, this](bool){
                if (item->tab()->hasTab())
                    item->tab()->currentWidget()->setFocus();
            });
        }

        else if (isFile)
        {
            onItemDoubleClicked(item, 0);

            menu->addMenu(m_parent->m_menuBar->F_T);
            menu->addAction(m_parent->m_menuBar->F_D);
            menu->addSeparator();
            menu->addAction(m_parent->m_menuBar->F_C);
            menu->addAction(m_parent->m_menuBar->F_p);
            menu->addMenu(m_parent->m_menuBar->F_M);
            menu->addSeparator();
            menu->addAction(m_parent->m_menuBar->F_S);
            menu->addAction(m_parent->m_menuBar->F_A);
            menu->addAction(m_parent->m_menuBar->F_Y);
            menu->addAction(m_parent->m_menuBar->F_d);
            menu->addSeparator();
            menu->addAction(m_parent->m_menuBar->F_B_F);
            menu->addAction(m_parent->m_menuBar->F_B_A);
            menu->addAction(m_parent->m_menuBar->F_B_N);
        }

        menu->exec(mapToGlobal(point));
    }
#endif
}

void TpDocumentView::onItemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if (item->type() == TpDocumentItem::ItemType::File)
    {
        QString file = item->toolTip(column);
        if (file.isEmpty())
            file = item->text(column);
        emit fileDoubleClicked(nullptr, file);
    }
}

TP_END_NAMESPACE
