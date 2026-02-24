#include <Widgets/TpFindInFilesContainer>
#include <Widgets/TpFindInFilesDock>
#include <TpEditor>
#include <TpMainWindow>

TP_NAMESPACE

TpFindInFilesDock::TpFindInFilesDock(TpMainWindow *parent)
    : QDockWidget(parent),
    m_container(nullptr)
{
    setAcceptDrops(true);
    setAllowedAreas(Qt::DockWidgetArea::AllDockWidgetAreas);
    setObjectName("findinFilesDock");
    setWindowTitle(tr("Find In Files Dock"));

    m_container = new TpFindInFilesContainer(this);
    setWidget(m_container);

    connect(m_container,
            &TpFindInFilesContainer::resultClicked,
            this,
            &TpFindInFilesDock::resultClicked);
}

TP_END_NAMESPACE
