#include <Utilities/TpTabInfo>

TP_NAMESPACE

TpTabInfo::TpTabInfo(const QString &name, TpEditor *widget)
    : m_name(name),
    m_widget(widget)
{}

TP_END_NAMESPACE
