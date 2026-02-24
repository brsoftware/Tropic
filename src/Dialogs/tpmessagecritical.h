#ifndef TPMESSAGECRITICAL_H
#define TPMESSAGECRITICAL_H

#include <QMessageBox>

#include <TpGlobals>

TP_NAMESPACE

class TpMessageCritical : public QObject
{
    Q_OBJECT

    DEF_PROP(QWidget*, parent);

public:
    enum
    {
        Save,
        Discard,
        Cancel
    };

public:
    TpMessageCritical(QWidget *parent);

public:
    int genericSay(QString title, QString text, QString infoText, bool warning);
    int say(QString title, QString text, QString infoText);
};

TP_END_NAMESPACE

#endif // TPMESSAGECRITICAL_H
