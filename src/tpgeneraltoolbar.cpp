#include <TpGeneralToolBar>

TP_NAMESPACE

TpGeneralToolBar::TpGeneralToolBar(QWidget *parent, QString name)
    : QToolBar(parent)
{
    setAcceptDrops(true);
    setAllowedAreas(Qt::ToolBarArea::AllToolBarAreas);
    setFloatable(true);
    setMovable(true);
    setOrientation(Qt::Orientation::Horizontal);
    setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
    setWindowTitle(name);
}

TP_END_NAMESPACE
