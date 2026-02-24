#include <Widgets/TpGeneralToolButton>

TP_NAMESPACE

TpGeneralToolButton::TpGeneralToolButton(bool isFind, QWidget *parent)
    : QToolButton(parent)
{
    if (isFind)
    {
        setArrowType(Qt::ArrowType::NoArrow);
        setAutoRaise(false);
        setPopupMode(MenuButtonPopup);
        setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextOnly);
    }

    else
    {
        setArrowType(Qt::ArrowType::DownArrow);
        setAutoRaise(true);
        setPopupMode(MenuButtonPopup);
        setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonFollowStyle);
    }
}

TP_END_NAMESPACE
