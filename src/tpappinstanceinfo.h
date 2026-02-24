#ifndef TPAPPINSTANCEINFO_H
#define TPAPPINSTANCEINFO_H

#include <TpGlobals>

TP_NAMESPACE

struct TpAppInstanceInfo
{
    bool primary;
    qint64 primaryPid;
    char primaryUser[128];
    quint32 secondary;
    quint16 checksum;
};

TP_END_NAMESPACE

#endif // TPAPPINSTANCEINFO_H
