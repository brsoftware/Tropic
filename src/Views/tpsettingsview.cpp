#include <QApplication>
#include <QHeaderView>
#include <QScreen>

#include <Models/TpVariantDelegate>
#include <Views/TpSettingsView>

TP_NAMESPACE

TpSettingsView::TpSettingsView(QWidget *parent)
    : QTreeWidget(parent),
    m_checker(new TpDelegateTypeChecker),
    m_delegate(new TpVariantDelegate(m_checker, this))
{
    setAcceptDrops(false);
    setAllColumnsShowFocus(true);
    setAlternatingRowColors(false);
    setAnimated(true);
    setAutoExpandDelay(250);
    setAutoScroll(true);
    setAutoScrollMargin(16);
    setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
    setDefaultDropAction(Qt::DropAction::IgnoreAction);
    setDragEnabled(false);
    setEditTriggers(DoubleClicked | SelectedClicked | EditKeyPressed);
    setExpandsOnDoubleClick(true);
    setEnabled(true);
    setHeaderHidden(false);
    setHeaderLabels({tr("Entry"), tr("Type"), tr("Value")});
    setHidden(false);
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    setItemDelegate(m_delegate);
    setObjectName("settingsView");
    setSelectionBehavior(SelectItems);
    setSelectionMode(SingleSelection);
    setSortingEnabled(false);
    setUniformRowHeights(true);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    header()->setSectionResizeMode(0, QHeaderView::ResizeMode::ResizeToContents);
    header()->setSectionResizeMode(1, QHeaderView::ResizeMode::ResizeToContents);
    header()->setSectionResizeMode(2, QHeaderView::ResizeMode::Stretch);

    m_refreshTimer.setInterval(2'000);

    m_groupIcon.addPixmap(style()->standardPixmap(QStyle::StandardPixmap::SP_DirClosedIcon),
        QIcon::Mode::Normal, QIcon::State::Off);
    m_groupIcon.addPixmap(style()->standardPixmap(QStyle::StandardPixmap::SP_DirOpenIcon),
        QIcon::Mode::Normal, QIcon::State::On);
    m_keyIcon.addPixmap(style()->standardPixmap(QStyle::StandardPixmap::SP_FileIcon));

    connect(&m_refreshTimer,
            &QTimer::timeout,
            this,
            &TpSettingsView::refreshLater);
}

void TpSettingsView::setSettings(const TpSettingsPtr &settings)
{
    m_settings = settings;
    clear();

    if (settings.isNull())
    {
        m_refreshTimer.stop();
    }

    else
    {
        refresh();

        if (m_autoRefresh)
            m_refreshTimer.start();
    }
}

QSize TpSettingsView::sizeHint() const
{
    const QRect geom = screen()->availableGeometry();
    return QSize(geom.width() * 2 / 3, geom.height() * 2 / 3);
}

void TpSettingsView::setAutoRefresh(bool autoRefresh)
{
    m_autoRefresh = autoRefresh;

    if (!m_settings.isNull())
    {
        if (m_autoRefresh)
        {
            refreshLater();
            m_refreshTimer.start();
        }

        else
        {
            m_refreshTimer.stop();
        }
    }
}

void TpSettingsView::setFallbacks(bool enabled)
{
    if (!m_settings.isNull())
    {
        m_settings->setFallbacksEnabled(enabled);
        refresh();
    }
}

void TpSettingsView::refreshLater()
{
    if (state() != EditingState)
        refresh();
}

void TpSettingsView::refresh()
{
    if (m_settings.isNull())
        return;

    disconnect(this,
               &TpSettingsView::itemChanged,
               this,
               &TpSettingsView::updateSettings);

    m_settings->sync();
    updateChildItems(nullptr);

    connect(this,
            &TpSettingsView::itemChanged,
            this,
            &TpSettingsView::updateSettings);
}

void TpSettingsView::revertModelValues()
{
    if (m_settings.isNull())
        return;

    QSignalBlocker blocker(this);

    m_delegate->revertModelValues(model());
    refresh();
}

bool TpSettingsView::event(QEvent *event)
{
    if (event->type() == QEvent::Type::WindowActivate)
        if (isActiveWindow() && m_autoRefresh)
            refreshLater();
    return QTreeWidget::event(event);
}

void TpSettingsView::updateSettings(TpSettingsItem *item)
{
    QString key = item->text(0);
    TpSettingsItem *ancestor = item->parent();

    while (ancestor)
    {
        key.prepend(ancestor->text(0) + QLatin1Char('/'));
        ancestor = ancestor->parent();
    }

    m_settings->setValue(key, item->data(2, Qt::ItemDataRole::UserRole));
    if (m_autoRefresh)
        refresh();
}

void TpSettingsView::updateChildItems(TpSettingsItem *parent)
{
    int dividerIndex = 0;

    const QStringList childGroups = m_settings->childGroups();

    for (const auto &group : std::as_const(childGroups))
    {
        TpSettingsItem *child;
        int childIndex = findChild(parent, group, dividerIndex);

        if (childIndex != -1)
        {
            child = childAt(parent, childIndex);
            child->setText(1, QString());
            child->setText(2, QString());
            child->setData(2, Qt::ItemDataRole::UserRole, QVariant());
            moveForward(parent, childIndex, dividerIndex);
        }

        else
        {
            child = create(group, parent, dividerIndex);
        }

        child->setIcon(0, m_groupIcon);
        dividerIndex++;

        m_settings->beginGroup(group);
        updateChildItems(child);
        m_settings->endGroup();
    }

    const QStringList childKeys = m_settings->childKeys();

    for (const auto &key : std::as_const(childKeys))
    {
        TpSettingsItem *child;
        int childIndex = findChild(parent, key, 0);

        if (childIndex == -1 || childIndex >= dividerIndex)
        {
            if (childIndex != -1)
            {
                child = childAt(parent, childIndex);
                for (int i = 0; i < child->childCount(); i++)
                    delete childAt(child, i);
                moveForward(parent, childIndex, dividerIndex);
            }

            else
            {
                child = create(key, parent, dividerIndex);
            }

            child->setIcon(0, m_keyIcon);
            dividerIndex++;
        }

        else
        {
            child = childAt(parent, childIndex);
        }

        QVariant value = m_settings->value(key);

        if (value.userType() == QMetaType::Type::UnknownType)
        {
            child->setText(1, "Invalid");
        }

        else
        {
            if (value.typeId() == QMetaType::Type::QString)
            {
                const QString stringValue = value.toString();
                if (m_checker->regexBool.match(stringValue).hasMatch())
                    value.setValue(stringValue.compare("true", Qt::CaseSensitivity::CaseInsensitive) == 0);
                else if (m_checker->regexSignedInt.match(stringValue).hasMatch())
                    value.setValue(stringValue.toInt());
            }

            child->setText(1, value.typeName());
        }

        child->setText(2, TpVariantDelegate::displayText(value));
        child->setData(2, Qt::ItemDataRole::UserRole, value);
    }

    while (dividerIndex < childrenCount(parent))
        delete childAt(parent, dividerIndex);
}

TpSettingsItem *TpSettingsView::create(const QString &text, TpSettingsItem *parent, int index)
{
    TpSettingsItem *after = nullptr;
    if (index != 0)
        after = childAt(parent, index - 1);
    TpSettingsItem *item;
    if (parent)
        item = new TpSettingsItem(parent, after);
    else
        item = new TpSettingsItem(this, after);
    item->setText(0, text);
    item->setFlags(item->flags() | Qt::ItemFlag::ItemIsEditable);
    return item;
}

TpSettingsItem *TpSettingsView::childAt(TpSettingsItem *parent, int index) const
{
    return (parent ? parent->child(index) : topLevelItem(index));
}

int TpSettingsView::childrenCount(TpSettingsItem *parent) const
{
    return (parent ? parent->childCount() : topLevelItemCount());
}

int TpSettingsView::findChild(TpSettingsItem *parent, const QString &text, int start) const
{
    for (int i = start; i < childrenCount(parent); i++)
        if (childAt(parent, i)->text(0) == text)
            return i;
    return -1;
}

void TpSettingsView::moveForward(TpSettingsItem *parent, int oldIndex, int newIndex)
{
    for (int i = 0; i < oldIndex - newIndex; i++)
        delete childAt(parent, newIndex);
}

TP_END_NAMESPACE
