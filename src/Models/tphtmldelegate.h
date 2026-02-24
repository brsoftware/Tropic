#ifndef TPHTMLDELEGATE_H
#define TPHTMLDELEGATE_H

#include <QStyledItemDelegate>

#include <TpGlobals>

TP_NAMESPACE

class TpHtmlDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    TpHtmlDelegate(QObject *parent = nullptr);

public:
    void paint(QPainter *paint, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

TP_END_NAMESPACE

#endif // TPHTMLDELEGATE
