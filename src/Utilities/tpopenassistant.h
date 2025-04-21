#ifndef TPOPENASSISTANT_H
#define TPOPENASSISTANT_H

#include <TpGlobals>

TP_NAMESPACE

class TpEditor;
class TpMainWindow;

class TpOpenAssistant : public QObject
{
    Q_OBJECT

    DEF_PROP(TpMainWindow*, parent);

public:
    TpOpenAssistant(TpMainWindow *parent);

public:
    void openFiles(QStringList files);
    TpEditor *openFile(QString path);
};

TP_END_NAMESPACE

#endif // TPOPENASSISTANT_H
