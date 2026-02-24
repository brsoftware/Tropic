#ifndef TPTABINFO_H
#define TPTABINFO_H

#include <TpGlobals>

TP_NAMESPACE

class TpEditor;

class TpTabInfo
{
    DEF_PROP(TpEditor*, widget);
    DEF_PROP(QString, name);

public:
    TpTabInfo(const QString &name, TpEditor *widget);

public:
    DEF_PROP_FUNC(TpEditor*, widget, Widget);
    DEF_PROP_FUNC(QString, name, Name);
};

TP_END_NAMESPACE

#endif // TPTABINFO_H
