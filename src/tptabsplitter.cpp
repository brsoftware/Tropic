#include <QEvent>

#include <Views/TpDocumentView>
#include <TpApplication>
#include <TpEditor>
#include <TpMainWindow>
#include <TpStackedWidget>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpTabSplitter::TpTabSplitter(TpStackedWidget *parent)
    : QSplitter(parent),
    m_parent(parent),
    m_tabs({}),
    m_currentFocus(nullptr)
{
    setObjectName("tabSplitter");

    connect(qApp,
            &TpApplication::focusChanged,
            this,
            &TpTabSplitter::onApplicationFocusChanged);
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
        return m_currentFocus;
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

    m_currentFocus = tab;

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

    tab->disconnect();
    tab->setParent(nullptr);
    tab->deleteLater();
    // delete tab;

    emit tabsListChanged(m_tabs.count());
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

void TpTabSplitter::onApplicationFocusChanged(QWidget *oldWidget, QWidget *newWidget)
{
    if (TpEditor *editor = qobject_cast<TpEditor*>(newWidget))
    {
        if (editor->m_parent)
            m_currentFocus = editor->m_parent;
        emit tabChanged(m_currentFocus, m_currentFocus->currentIndex());
    }

    else if (TpTabWidget *tab = qobject_cast<TpTabWidget*>(newWidget))
    {
        m_currentFocus = tab;
        emit tabChanged(m_currentFocus, m_currentFocus->currentIndex());
    }
}

TP_END_NAMESPACE
