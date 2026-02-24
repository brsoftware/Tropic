#include <Widgets/TpSettingsStack>

TP_NAMESPACE

TpSettingsStack::TpSettingsStack(QWidget *parent)
    : QWidget(parent),
    m_parent(parent)
{
    setObjectName("settingsStack");

    m_layout = new QHBoxLayout();
    setLayout(m_layout);
    m_nav = new QListWidget(this);
    m_layout->addWidget(m_nav);
    m_widget = new QStackedWidget(this);
    m_layout->addWidget(m_widget);

    connect(m_nav,
            &QListWidget::itemDoubleClicked,
            this,
            &TpSettingsStack::onNavigatorDoubleClicked);
}

int TpSettingsStack::addPage(TpSettingsPage *page)
{
    int idx = m_widget->addWidget(page);
    m_nav->addItem(page->name());
    m_widget->setCurrentIndex(idx);
    return idx;
}

QListWidget *TpSettingsStack::navigator() const
{
    return m_nav;
}

QStackedWidget *TpSettingsStack::stackedWidget() const
{
    return m_widget;
}

void TpSettingsStack::onNavigatorDoubleClicked(QListWidgetItem *item)
{
    m_widget->setCurrentIndex(m_nav->row(item));
}

TP_END_NAMESPACE
