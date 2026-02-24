#include <QApplication>
#include <QMouseEvent>

#include <TpEditor>
#include <TpGeneralMenu>
#include <TpMainWindow>
#include <TpStackedWidget>
#include <TpTabBar>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpTabBar::TpTabBar(TpTabWidget *parent)
    : QTabBar(parent),
    m_parent(parent)
{
    setAutoHide(isDarwin);
    setChangeCurrentOnDrag(false);
    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    setDocumentMode(true);
    setElideMode(Qt::TextElideMode::ElideRight);
    setExpanding(isDarwin);
    setMovable(false);
    setObjectName("tabBar");
    setSelectionBehaviorOnRemove(SelectPreviousTab);
    setTabsClosable(true);
    setUsesScrollButtons(true);

    connect(this,
            &TpTabBar::customContextMenuRequested,
            this,
            &TpTabBar::onCustomContextMenuRequested);
}

void TpTabBar::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::LeftButton)
        m_dragPosition = event->globalPosition().toPoint();
    if (event->button() & Qt::MouseButton::MiddleButton)
        emit midButtonTabCloseRequested(currentIndex());
    QTabBar::mousePressEvent(event);
}

void TpTabBar::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::MouseButton::LeftButton))
        return QTabBar::mouseMoveEvent(event);
    if ((event->globalPosition().toPoint() - m_dragPosition).manhattanLength() < qApp->startDragDistance())
        return QTabBar::mouseMoveEvent(event);
    emit dragged();
    QTabBar::mouseMoveEvent(event);
}

void TpTabBar::onCustomContextMenuRequested(const QPoint &point)
{
    if (m_parent->tab())
        m_parent->tab()->setFocus(Qt::FocusReason::OtherFocusReason);
    setCurrentIndex(tabAt(point));

    TpMainWindow *ultimate = m_parent->m_parent->m_parent->m_parent;
    TpGeneralMenu *menu = new TpGeneralMenu(this, tr("&Tab"));
    menu->addAction(ultimate->m_menuBar->F_N_T);
    menu->addAction(ultimate->m_menuBar->F_O_T);
    menu->addSeparator();
    menu->addMenu(ultimate->m_menuBar->F_T);
    menu->addAction(ultimate->m_menuBar->F_E);
    menu->addAction(ultimate->m_menuBar->F_D);
    menu->addAction(ultimate->m_menuBar->F_W);
    menu->addMenu(ultimate->m_menuBar->F_B);
    menu->addSeparator();
    menu->addAction(ultimate->m_menuBar->F_S);
    menu->addAction(ultimate->m_menuBar->F_C);
    menu->addMenu(ultimate->m_menuBar->F_M);
    menu->addSeparator();
    menu->addMenu(ultimate->m_menuBar->V_T);
    menu->addMenu(ultimate->m_menuBar->V_L);
    menu->exec(mapToGlobal(point));
}

TP_END_NAMESPACE
