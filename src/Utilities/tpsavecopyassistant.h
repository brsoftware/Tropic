#ifndef TPSAVECOPYASSISTANT_H
#define TPSAVECOPYASSISTANT_H

#include <TpGlobals>

TP_NAMESPACE

class TpEditor;
class TpMainWindow;

class TpSaveCopyAssistant : public QObject
{
    Q_OBJECT

    DEF_PROP(TpMainWindow*, parent);

public:
    TpSaveCopyAssistant(TpMainWindow *parent);

public:
    bool saveFile(QString filePath);
};

TP_END_NAMESPACE

#endif // TPSAVECOPYASSISTANT_H
