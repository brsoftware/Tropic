#ifndef TPGENERALACTIONGROUP_H
#define TPGENERALACTIONGROUP_H

#include <QActionGroup>

#include <TpGlobals>

TP_NAMESPACE

class TpGeneralAction;
class TpMenuBar;

class TpGeneralActionGroup : public QActionGroup
{
    Q_OBJECT

public:
#if QT_VERSION_MAJOR >= 6
    using enum ExclusionPolicy;
#endif

public:
    TpGeneralActionGroup(TpMenuBar *parent, std::initializer_list<TpGeneralAction*> actions);

public:
    void initialize(std::initializer_list<TpGeneralAction*> actions);
};

TP_END_NAMESPACE

#endif // TPGENERALACTIONGROUP_H
