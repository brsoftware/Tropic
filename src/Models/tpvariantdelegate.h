#ifndef TPVARIANTDELEGATE_H
#define TPVARIANTDELEGATE_H

#include <QSharedPointer>
#include <QStyledItemDelegate>

#include <Utilities/TpDelegateTypeChecker>

TP_NAMESPACE

class TpSettingsView;

class TpVariantDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit TpVariantDelegate(const QSharedPointer<TpDelegateTypeChecker> &checker,
        TpSettingsView *parent);

public:
    static bool isSupported(int type);
    static QString displayText(const QVariant &value);

public:
    void revertModelValues(QAbstractItemModel *model);
    QMap<QPersistentModelIndex, QVariant> history() const;

public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

private slots:
    void committingColoredLineEdit();

private:
    QSharedPointer<TpDelegateTypeChecker> m_checker;
    TpSettingsView *m_parent;
    mutable QMap<QPersistentModelIndex, QVariant> m_history;
};

TP_END_NAMESPACE

#endif // TPVARIANTDELEGATE_H
