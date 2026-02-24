#ifndef TPSAVEASSISTANT_H
#define TPSAVEASSISTANT_H

#include <TpGlobals>

TP_NAMESPACE

class TpEditor;
class TpMainWindow;

class TpSaveAssistant : public QObject
{
    Q_OBJECT

    DEF_PROP(TpMainWindow*, parent);

public:
    TpSaveAssistant(TpMainWindow *parent);

public:
    bool saveFile(QString filePath);
};

TP_END_NAMESPACE

#endif // TPSAVEASSISTANT_H
