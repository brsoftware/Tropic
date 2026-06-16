#include <Widgets/TpColoredLineEdit>
#include <Widgets/TpFontButton>
#include <Widgets/TpSettingsStack>

TP_NAMESPACE

TpSettingsPage::TpSettingsPage(Type type, TpSettingsStack *parent)
    : QWidget(parent),
    m_type(type),
    m_parent(parent),
    m_editors({})
{
    m_layout = new QVBoxLayout();
    setLayout(m_layout);
    m_layout->setContentsMargins(0, 0, 0, 0);

    if (m_type == Form)
    {
        m_formWidget = new QScrollArea(this);
        m_formContainer = new QWidget(m_formWidget);
        m_formWidget->setWidgetResizable(true);
        m_formLayout = new QFormLayout();
        m_formContainer->setLayout(m_formLayout);
        m_formWidget->setWidget(m_formContainer);
        m_layout->addWidget(m_formWidget);
    }
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

void TpSettingsPage::addEntry(QString key, QMetaType::Type type, QVariant defaultValue)
{
    if (m_type != Form)
        return;

    switch (type)
    {
    case QMetaType::Type::QColor: {
        auto editor = new TpColoredLineEdit(this);
        if (defaultValue.isValid())
            editor->setColor(qvariant_cast<QColor>(defaultValue));
        m_editors[key] = editor;
        m_formLayout->addRow(key, editor);
        break;
    }

    case QMetaType::Type::QFont: {
        auto editor = new TpFontButton(this);
        if (defaultValue.isValid())
            editor->setFont(qvariant_cast<QFont>(defaultValue));
        m_editors[key] = editor;
        m_formLayout->addRow(key, editor);
        break;
    }

    case QMetaType::Type::QString: {
        auto editor = new TpGeneralLineEdit(this);
        if (defaultValue.isValid())
            editor->setText(defaultValue.toString());
        m_editors[key] = editor;
        m_formLayout->addRow(key, editor);
        break;
    }

    default:
        Q_ASSERT_X(0, "Unknown Type", QString::number(type).toLatin1());
    }
}

QVariant TpSettingsPage::entry(QString key) const
{
    if (!m_editors.contains(key))
        return 0;

    QWidget *ed = m_editors[key];
    if (TpColoredLineEdit *editor = qobject_cast<TpColoredLineEdit*>(ed))
        return editor->color();
    else if (TpFontButton *editor = qobject_cast<TpFontButton*>(ed))
        return editor->font();
    else if (TpGeneralLineEdit *editor = qobject_cast<TpGeneralLineEdit*>(ed))
        return editor->text();

    return 0;
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
