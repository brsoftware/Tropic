#ifndef TPDOCUMENTSITEM_H
#define TPDOCUMENTSITEM_H

#include <QTreeWidgetItem>

#include <TpGlobals>

TP_NAMESPACE

class TpDocumentsView;

class TpDocumentsItem : public QTreeWidgetItem
{
    Q_GADGET

    DEF_PROP(QString, name);
    DEF_PROP(int, tabSerial);

public:
    TpDocumentsItem(TpDocumentsView *parent, QString name, int tabSerial);

public:
    void setName(QString name);
    const QString &name() const;
    void setTabSerial(int tabSerial);
    int tabSerial() const;
};

TP_END_NAMESPACE

#endif // TPDOCUMENTSITEM_H
