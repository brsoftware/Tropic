#include <Widgets/TpSettingsStack>

TP_NAMESPACE

TpSettingsPage::TpSettingsPage(Type type, TpSettingsStack *parent)
    : QWidget(parent),
    m_type(type),
    m_parent(parent)
{
    m_layout = new QVBoxLayout();
    setLayout(m_layout);
    m_layout->setContentsMargins(0, 0, 0, 0);
}

TpSettingsPage::Type TpSettingsPage::type() const
{
    return m_type;
}

void TpSettingsPage::addEntry(QWidget *entry)
{
    if (m_type != Page)
        return;

    m_layout->addWidget(entry);
}

void TpSettingsPage::setEditorAcceptor(std::function<void(TpEditor*)> func)
{
    m_edAcceptor = func;
}

void TpSettingsPage::setAcceptor(std::function<void()> func)
{
    m_acceptor = func;
}

void TpSettingsPage::setEditorRejector(std::function<void(TpEditor*)> func)
{
    m_edRejector = func;
}

void TpSettingsPage::setRejector(std::function<void()> func)
{
    m_rejector = func;
}

TP_END_NAMESPACE
