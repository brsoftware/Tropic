#include <QPushButton>

#include <Dialogs/TpDialogSettings>
#include <TpApplication>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpDialogSettings::TpDialogSettings(QWidget *parent)
    : QDialog(parent),
    m_parent(parent)
{
    m_layout = new QVBoxLayout();
    m_layout->setObjectName("settingsDialog_layout");
    setLayout(m_layout);
    m_widget = new TpSettingsStack(this);
    m_layout->addWidget(m_widget);
    m_hint = new QLabel(this);
    m_hint->setObjectName("settingsDialog_Hint");
    m_hint->setText(tr("Note: Some changes in the entries of the settings may be unavailable until restart."));
    m_layout->addWidget(m_hint);
    m_box = new QDialogButtonBox(this);
    m_box->setObjectName("settingsDialog_box");
    m_applyButton = new QPushButton(this);
    m_applyButton->setAutoDefault(false);
    m_applyButton->setDefault(false);
    m_applyButton->setText(tr("&Apply"));
    m_applyButton->setObjectName("settingsDialog_buttonApply");
    m_box->addButton(m_applyButton, QDialogButtonBox::ButtonRole::ApplyRole);
    m_setButton = new QPushButton(this);
    m_setButton->setAutoDefault(false);
    m_setButton->setDefault(false);
    m_setButton->setText(tr("&Set"));
    m_setButton->setObjectName("settingsDialog_buttonSet");
    m_box->addButton(m_setButton, QDialogButtonBox::ButtonRole::ActionRole);
    m_cancelButton = new QPushButton(this);
    m_cancelButton->setAutoDefault(false);
    m_cancelButton->setDefault(false);
    m_cancelButton->setText(tr("&Cancel"));
    m_cancelButton->setObjectName("settingsDialog_buttonCancel");
    m_box->addButton(m_cancelButton, QDialogButtonBox::ButtonRole::RejectRole);
    m_layout->addWidget(m_box);

    connect(m_applyButton,
            &QPushButton::clicked,
            this,
            &TpDialogSettings::onApplyButtonClicked);
    connect(m_setButton,
            &QPushButton::clicked,
            this,
            &TpDialogSettings::onSetButtonClicked);
    connect(m_cancelButton,
            &QPushButton::clicked,
            this,
            &TpDialogSettings::onCancelButtonClicked);
}

TpSettingsStack *TpDialogSettings::stack() const
{
    return m_widget;
}

void TpDialogSettings::onApplyButtonClicked(bool)
{
    for (const auto &item : qApp->topLevelWidgets())
        if (auto mw = qobject_cast<TpMainWindow*>(item))
            for (const auto &tabs : std::as_const(mw->m_widget->m_splitter->m_tabs))
                for (const auto &ed : tabs->acquire())
                    for (int i = 0; i < m_widget->stackedWidget()->count(); i++)
                        qobject_cast<TpSettingsPage*>(m_widget->stackedWidget()->widget(i))->m_edAcceptor(ed);
    for (int i = 0; i < m_widget->stackedWidget()->count(); i++)
        qobject_cast<TpSettingsPage*>(m_widget->stackedWidget()->widget(i))->m_acceptor();
}

void TpDialogSettings::onSetButtonClicked(bool)
{
    onApplyButtonClicked(false);
    close();
}

void TpDialogSettings::onCancelButtonClicked(bool)
{
    for (const auto &item : qApp->topLevelWidgets())
        if (auto mw = qobject_cast<TpMainWindow*>(item))
            for (const auto &tabs : std::as_const(mw->m_widget->m_splitter->m_tabs))
                for (const auto &ed : tabs->acquire())
                    for (int i = 0; i < m_widget->stackedWidget()->count(); i++)
                        qobject_cast<TpSettingsPage*>(m_widget->stackedWidget()->widget(i))->m_edRejector(ed);
    for (int i = 0; i < m_widget->stackedWidget()->count(); i++)
        qobject_cast<TpSettingsPage*>(m_widget->stackedWidget()->widget(i))->m_rejector();

    close();
}

TP_END_NAMESPACE
