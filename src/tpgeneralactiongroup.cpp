#include <TpGeneralAction>
#include <TpGeneralActionGroup>
#include <TpMenuBar>

TP_NAMESPACE

TpGeneralActionGroup::TpGeneralActionGroup(TpMenuBar *parent, std::initializer_list<TpGeneralAction*> actions)
    : QActionGroup(parent)
{
    initialize(actions);
}

void TpGeneralActionGroup::initialize(std::initializer_list<TpGeneralAction*> actions)
{
#if QT_VERSION_MAJOR >= 6
    setExclusionPolicy(Exclusive);
#else
    setExclusionPolicy(QActionGroup::ExclusionPolicy::Exclusive);
#endif

    for (const auto &action : std::as_const(actions))
    {
        addAction(action);
    }
}

TP_END_NAMESPACE
