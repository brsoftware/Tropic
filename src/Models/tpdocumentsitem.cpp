#include <Models/TpDocumentsItem>
#include <Views/TpDocumentsView>

TP_NAMESPACE

TpDocumentsItem::TpDocumentsItem(TpDocumentsView *parent, QString name, int tabSerial)
    : QTreeWidgetItem(parent),
    m_name(name),
    m_tabSerial(tabSerial)
{
    setChildIndicatorPolicy(DontShowIndicatorWhenChildless);
    setDisabled(false);
    setExpanded(true);
    setFirstColumnSpanned(false);
    setFlags(Qt::ItemFlag::ItemIsSelectable | Qt::ItemFlag::ItemIsEnabled);
    setName(name);
    setTabSerial(tabSerial);
}

void TpDocumentsItem::setName(QString name)
{
    m_name = name;
    setText(0, name);
}

const QString &TpDocumentsItem::name() const
{
    return m_name;
}

void TpDocumentsItem::setTabSerial(int tabSerial)
{
    m_tabSerial = tabSerial;
    setToolTip(0, QObject::tr("Tab number: %1").arg(QString::number(tabSerial)));
}

int TpDocumentsItem::tabSerial() const
{
    return m_tabSerial;
}

TP_END_NAMESPACE
