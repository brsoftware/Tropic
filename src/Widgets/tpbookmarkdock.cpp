#include <Views/TpBookmarkView>
#include <Widgets/TpBookmarkDock>
#include <TpMainWindow>

TP_NAMESPACE

TpBookmarkDock::TpBookmarkDock(TpMainWindow *parent)
    : QDockWidget(parent),
    m_view(nullptr)
{
    setAcceptDrops(true);
    setAllowedAreas(Qt::DockWidgetArea::AllDockWidgetAreas);
    setObjectName("bookmarkDock");
    setWindowTitle(tr("Bookmarks"));
}

void TpBookmarkDock::setView(TpBookmarkView *view)
{
    m_view = view;
    setWidget(view);
}

TpBookmarkView *TpBookmarkDock::view() const
{
    return m_view;
}

TP_END_NAMESPACE
