#include <Views/TpFileView>
#include <Widgets/TpFileDock>
#include <TpMainWindow>

TP_NAMESPACE

TpFileDock::TpFileDock(TpMainWindow *parent)
    : QDockWidget(parent),
    m_parent(parent)
{
    setAcceptDrops(true);
    setAllowedAreas(Qt::DockWidgetArea::AllDockWidgetAreas);
    setObjectName("fileDock");
    setWindowTitle(tr("Tropic File Browser"));

    m_view = new TpFileView(m_parent);
    setWidget(m_view);

    connect(m_view,
            &TpFileView::fileDoubleClicked,
            this,
            &TpFileDock::fileDoubleClicked);
}

TpFileView *TpFileDock::fileView() const
{
    return m_view;
}

TP_END_NAMESPACE
