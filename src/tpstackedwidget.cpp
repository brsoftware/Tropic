#include <TpMainWindow>
#include <TpStackedWidget>
#include <TpTabSplitter>
#include <TpTabWidget>
#include <TpWelcomeLabel>

TP_NAMESPACE

TpStackedWidget::TpStackedWidget(TpMainWindow *parent)
    : QStackedWidget(parent),
    m_parent(parent),
    m_label(new TpWelcomeLabel(this)),
    m_splitter(new TpTabSplitter(this))
{
    addWidget(m_label);
    addWidget(m_splitter);

    setCurrentIndex(0);
    setObjectName("stackedWidget");

    connect(m_splitter,
            &TpTabSplitter::tabsListChanged,
            this,
            &TpStackedWidget::onTabsListChanged);
}

TpTabSplitter *TpStackedWidget::tabs() const
{
    return m_splitter;
}

void TpStackedWidget::onTabsListChanged(int count)
{
    if (count != 0)
        setCurrentIndex(1);
    else
        setCurrentIndex(0);

    if (m_splitter->m_tabs.length() == 1)
        if ((m_splitter->m_tabs.at(0)->count() == 0) && (count == 1))
            setCurrentIndex(0);
}

TP_END_NAMESPACE
