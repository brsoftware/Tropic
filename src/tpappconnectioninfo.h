#ifndef TPAPPCONNECTIONINFO_H
#define TPAPPCONNECTIONINFO_H

#include <TpGlobals>

TP_NAMESPACE

struct TpAppConnectionInfo
{
    qint64 messageLength = 0;
    quint32 instanceId = 0;
    quint8 stage = 0;
};

TP_END_NAMESPACE

#endif // TPAPPCONNECTIONINFO_H
