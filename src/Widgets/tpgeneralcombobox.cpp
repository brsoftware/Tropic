#include <Widgets/TpGeneralComboBox>

TP_NAMESPACE

TpGeneralComboBox::TpGeneralComboBox(QWidget *parent)
    : QComboBox(parent)
{
    setAcceptDrops(true);
    setEditable(true);
    setInsertPolicy(InsertAtBottom);
}

TP_END_NAMESPACE
