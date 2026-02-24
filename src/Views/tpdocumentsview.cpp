#include <QHeaderView>

#include <Views/TpDocumentsView>
#include <TpEditor>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpDocumentsView::TpDocumentsView(TpTabSplitter *parent)
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
    setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
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

    header()->setSectionsClickable(true);
    header()->setSectionResizeMode(QHeaderView::ResizeMode::Interactive);

    connect(this,
            &TpDocumentsView::itemDoubleClicked,
            this,
            &TpDocumentsView::onItemDoubleClicked);
}

TpDocumentsItem *TpDocumentsView::addItem(QString text, int tabSerial)
{
    TpDocumentsItem *item = new TpDocumentsItem(this, text, tabSerial);
    addTopLevelItem(item);

    return item;
}

void TpDocumentsView::removeItem(QString text, int tabSerial)
{
    for (int idx = 0; idx < topLevelItemCount(); idx++)
    {
        if (TpDocumentsItem *item = static_cast<TpDocumentsItem*>(topLevelItem(idx)))
        {
            if (item->name() == text && item->tabSerial() == tabSerial)
            {
                delete item;
                break;
            }
        }
    }
}

void TpDocumentsView::onLineEditTextChanged(const QString &text)
{
    m_best = nullptr;
    m_bestScore = 0;

    if (text.isEmpty())
    {
        for (int i = 0; i < topLevelItemCount(); i++)
            topLevelItem(i)->setHidden(false);
        return;
    }

    for (int i = 0; i < topLevelItemCount(); i++)
        filterByScore(static_cast<TpDocumentsItem*>(topLevelItem(i)), text);

    if (m_best)
    {
        setCurrentItem(m_best);
        scrollToItem(m_best);
    }
}

int TpDocumentsView::filterByScore(TpDocumentsItem *item, const QString &filter)
{
    int score = scoreItem(item, filter);
    item->setHidden(score <= 0);

    if (score > m_bestScore)
    {
        m_bestScore = score;
        m_best = item;
    }

    return score;
}

int TpDocumentsView::scoreItem(TpDocumentsItem *item, const QString &filter)
{
    QString name = item->text(0).toLower().simplified();
    QString q = filter.toLower().simplified();

    if (q.isEmpty())
        return 0;
    if (name == q)
        return 10'000;
    if (name.startsWith(q))
        return 500;
    if (name.contains(q))
        return 1'000;

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

void TpDocumentsView::onItemDoubleClicked(QTreeWidgetItem *item, int column)
{
    Q_UNUSED(column);
    TpDocumentsItem *itm = static_cast<TpDocumentsItem*>(item);

    for (const auto &it : std::as_const(m_parent->m_tabs))
    {
        if (it->serial() == itm->tabSerial())
        {
            for (const auto &i : it->acquire())
            {
                if (i->filePath() == itm->name() ||
                    (itm->name().startsWith(tr("Untitled ")) && itm->name().endsWith(QString::number(i->untitled()))))
                {
                    it->setCurrentIndex(it->indexOf(i));
                    emit actionCompleted();

                    QTimer::singleShot(0, i, [i](){i->setFocus(Qt::FocusReason::OtherFocusReason);});
                    return;
                }
            }

            return;
        }
    }

    emit documentsItemDoubleClicked(item->text(0).toInt());
}

TP_END_NAMESPACE
