#include <Widgets/TpFindContainer>
#include <Widgets/TpFindDock>
#include <TpEditor>
#include <TpMainWindow>

TP_NAMESPACE

TpFindDock::TpFindDock(TpMainWindow *parent)
    : QDockWidget(parent),
    m_container(nullptr)
{
    setAcceptDrops(true);
    setAllowedAreas(Qt::DockWidgetArea::AllDockWidgetAreas);
    setObjectName("findDock");
    setWindowTitle(tr("Find Dock"));
}

void TpFindDock::setContainer(TpFindContainer *findContainer)
{
    m_container = findContainer;
    setWidget(m_container);
}

TpFindContainer *TpFindDock::container() const
{
    return m_container;
}

void TpFindDock::closeEvent(QCloseEvent *event)
{
    if (m_container)
        m_container->clearFindIndicators();

    QDockWidget::closeEvent(event);
}

TP_END_NAMESPACE
