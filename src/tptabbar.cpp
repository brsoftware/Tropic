#include <TpTabBar>
#include <TpTabWidget>

TP_NAMESPACE

TpTabBar::TpTabBar(TpTabWidget *parent)
    : QTabBar(parent),
    m_parent(parent)
{
    setAutoHide(isDarwin);
    setChangeCurrentOnDrag(false);
    setDocumentMode(true);
    setElideMode(Qt::TextElideMode::ElideRight);
    setExpanding(isDarwin);
    setMovable(true);
    setObjectName("tabBar");
    setSelectionBehaviorOnRemove(SelectPreviousTab);
    setTabsClosable(true);
    setUsesScrollButtons(true);
}

TP_END_NAMESPACE
