#include <Widgets/TpGeneralLineEdit>

TP_NAMESPACE

TpGeneralLineEdit::TpGeneralLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    setAcceptDrops(true);
    setAlignment(Qt::AlignmentFlag::AlignLeft);
    setClearButtonEnabled(true);
    setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
    setDragEnabled(true);
    setEchoMode(Normal);
    setReadOnly(false);
}

TP_END_NAMESPACE
