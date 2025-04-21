#include <Models/TpDocumentItem>
#include <Views/TpDocumentView>
#include <TpTabWidget>

TP_NAMESPACE

TpDocumentItem::TpDocumentItem(TpDocumentView *parent, TpTabWidget *tab)
    : QTreeWidgetItem(parent, Tab),
    m_parentView(parent),
    m_parentItem(nullptr),
    m_tab(tab),
    m_path(""),
    m_name("")
{
    setChildIndicatorPolicy(DontShowIndicatorWhenChildless);
    setDisabled(false);
    setExpanded(true);
    setFirstColumnSpanned(true);
    setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsDragEnabled | Qt::ItemFlag::ItemIsDropEnabled);
    setText(0, QObject::tr("Tab %1").arg(m_tab->serial()));
    setToolTip(0, QObject::tr("Tab %1").arg(m_tab->serial()));
}

TpDocumentItem::TpDocumentItem(TpDocumentItem *parent, TpTabWidget *tab, QString path, QString name)
    : QTreeWidgetItem(parent, File)/*,
    m_parentView(nullptr),
    m_parentItem(parent),
    m_tab(tab),
    m_path(path),
    m_name(name)*/
{
    m_parentView = nullptr;
    m_parentItem = parent;
    m_tab = tab;
    m_path = path;
    m_name = name;

    setChildIndicatorPolicy(DontShowIndicatorWhenChildless);
    setDisabled(false);
    setExpanded(true);
    setFirstColumnSpanned(true);
    setFlags(Qt::ItemFlag::ItemIsSelectable);
    setText(0, name);
    setToolTip(0, path);
}

void TpDocumentItem::setPath(const QString &path)
{
    m_path = path;
    setToolTip(0, m_path);
}

void TpDocumentItem::setName(const QString &name)
{
    m_name = name;
    setText(0, m_name);
}

void TpDocumentItem::setTab(TpTabWidget *tab)
{
    m_tab = tab;
    setText(0, QObject::tr("Tab %1").arg(m_tab->serial()));
    setToolTip(0, QObject::tr("Tab %1").arg(m_tab->serial()));
}

const QString &TpDocumentItem::path() const
{
    return m_path;
}

const QString &TpDocumentItem::name() const
{
    return m_name;
}

TpTabWidget *TpDocumentItem::tab() const
{
    return m_tab;
}

TP_END_NAMESPACE
