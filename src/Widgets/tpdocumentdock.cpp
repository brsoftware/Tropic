#include <Views/TpDocumentView>
#include <Widgets/TpDocumentDock>
#include <TpMainWindow>

#if QT_VERSION_MAJOR <= 5
#include <TpTabWidget>
#endif

TP_NAMESPACE

TpDocumentDock::TpDocumentDock(TpMainWindow *parent)
    : QDockWidget(parent),
    m_parent(parent)
{
    setAcceptDrops(true);
    setAllowedAreas(Qt::DockWidgetArea::AllDockWidgetAreas);
    setObjectName("documentDock");
    setWindowTitle(tr("Opened Documents"));

    m_view = new TpDocumentView(m_parent);
    setWidget(m_view);

    connect(m_view,
            &TpDocumentView::fileDoubleClicked,
            this,
            &TpDocumentDock::fileDoubleClicked);
}

TpDocumentView *TpDocumentDock::documentView() const
{
    return m_view;
}

TP_END_NAMESPACE
