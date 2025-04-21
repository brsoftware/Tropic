#ifndef TPDOCUMENTITEM_H
#define TPDOCUMENTITEM_H

#include <QTreeWidgetItem>

#include <TpGlobals>

TP_NAMESPACE

class TpDocumentView;
class TpTabWidget;

class TpDocumentItem : public QTreeWidgetItem
{
    Q_GADGET

    DEF_PROP(QString, path);
    DEF_PROP(QString, name);
    DEF_PROP(TpTabWidget*, tab);

public:
    enum ItemType
    {
        Tab = UserType + 1,
        File = UserType + 2,
    };

public:
    TpDocumentItem(TpDocumentView *parent, TpTabWidget *tab);
    TpDocumentItem(TpDocumentItem *parent, TpTabWidget *tab, QString path, QString name);

public:
    void setPath(const QString &path);
    const QString &path() const;
    void setName(const QString &name);
    const QString &name() const;
    void setTab(TpTabWidget *tab);
    TpTabWidget *tab() const;

private:
    TpDocumentView *m_parentView;
    TpDocumentItem *m_parentItem;
};

TP_END_NAMESPACE

#endif // TPDOCUMENTITEM_H
