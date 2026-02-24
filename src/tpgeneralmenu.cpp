#include <QMenuBar>

#include <TpGeneralMenu>

TP_NAMESPACE

TpGeneralMenu::TpGeneralMenu(QWidget *parent, QString name)
    : QMenu(parent)
{
    initialize(name);
}

void TpGeneralMenu::initialize(QString name)
{
    QString n = name;
    const QString &objectNameString = n.replace("&", "").replace("...", "").replace(" ", "");

    setAcceptDrops(false);
    setIcon(QIcon());
    setObjectName(parent()->objectName() + (parent()->objectName().isEmpty() ? "" : "_") + objectNameString);
    setTitle(name);

    QMenu *menu = qobject_cast<QMenu*>(parent());
    QMenuBar *menuBar = qobject_cast<QMenuBar*>(parent());

    if (menu)
        menu->addMenu(this);

    if (menuBar)
        menuBar->addMenu(this);
}

TP_END_NAMESPACE
