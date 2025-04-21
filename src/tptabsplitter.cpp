#include <QEvent>

#include <Views/TpDocumentView>
#include <TpEditor>
#include <TpMainWindow>
#include <TpStackedWidget>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpTabSplitter::TpTabSplitter(TpStackedWidget *parent)
    : QSplitter(parent),
    m_parent(parent),
    m_tabs({})
{
    setObjectName("tabSplitter");
}

TpTabWidget *TpTabSplitter::tab()
{
    if (m_tabs.count() <= 0)
    {
        TpTabWidget *newTab = new TpTabWidget(this);
        addTab(newTab);
        return newTab;
    }

    else if (m_tabs.count() >= 2)
    {
        for (const auto &child : std::as_const(m_tabs))
            if (child->isVisible())
                if (child->tab())
                    if (child->tab()->hasFocus())
                        return child;
    }

    return m_tabs.at(0);
}

void TpTabSplitter::addTab(TpTabWidget *tab)
{
    int minimum = 1;

    for (;;minimum++)
        if (!tabSerialList.contains(minimum))
            break;

    tab->m_serial = minimum;
    tabSerialList.push_back(minimum);

    m_tabs.append(tab);
    tab->installEventFilter(this);

    connect(tab,
            &TpTabWidget::currentChanged,
            this,
            &TpTabSplitter::onTabIndexChanged);
    connect(tab,
            &TpTabWidget::tabCloseRequested,
            this,
            &TpTabSplitter::onTabCloseRequested);
    connect(tab,
            &TpTabWidget::tabNameChanged,
            m_parent->m_parent,
            &TpMainWindow::onTabNameChanged);

    emit tab->tabNameChanged();
    emit tabsListChanged(m_tabs.count());
}

bool TpTabSplitter::removeTab(TpTabWidget *tab)
{
    bool ok = m_tabs.removeOne(tab);

    tabSerialList.removeOne(tab->m_serial);

    disconnect(tab,
               &TpTabWidget::currentChanged,
               this,
               &TpTabSplitter::onTabIndexChanged);
    disconnect(tab,
               &TpTabWidget::tabCloseRequested,
               this,
               &TpTabSplitter::onTabCloseRequested);

    // tab->hide();

    // tab->deleteLater();
    tab->setParent(nullptr);
    delete tab;

    emit tabsListChanged(m_tabs.count());
    // emit tab->tabNameChanged();

    return ok;
}

bool TpTabSplitter::hasTab() const
{
    for (auto &i : m_tabs)
        if (i->isVisible())
            return true;

    return false;
}

bool TpTabSplitter::eventFilter(QObject *object, QEvent *event)
{
    TpTabWidget *tab = qobject_cast<TpTabWidget*>(object);

    if (tab)
    {
        if ((event->type() == QEvent::Type::FocusIn) && (hasFocus()))
            emit tabChanged(tab, tab->currentIndex());
    }

    return QSplitter::eventFilter(object, event);
}

void TpTabSplitter::onTabIndexChanged(int index)
{
    emit tabChanged(qobject_cast<TpTabWidget*>(sender()), index);
}

void TpTabSplitter::onTabCloseRequested(int index)
{
    emit tabCloseRequested(qobject_cast<TpTabWidget*>(sender()), index);
}

TP_END_NAMESPACE
