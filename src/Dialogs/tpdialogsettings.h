#ifndef TPDIALOGSETTINGS_H
#define TPDIALOGSETTINGS_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QVBoxLayout>

#include <Widgets/TpSettingsStack>

TP_NAMESPACE

class TpDialogSettings : public QDialog
{
    Q_OBJECT

public:
    TpDialogSettings(QWidget *parent);

public:
    TpSettingsStack *stack() const;

private slots:
    void onApplyButtonClicked(bool);
    void onSetButtonClicked(bool);
    void onCancelButtonClicked(bool);

private:
    QWidget *m_parent;
    QVBoxLayout *m_layout;
    TpSettingsStack *m_widget;
    QLabel *m_hint;
    QDialogButtonBox *m_box;
    QPushButton *m_applyButton;
    QPushButton *m_cancelButton;
    QPushButton *m_setButton;
};

TP_END_NAMESPACE

#endif // TPDIALOGSETTINGS_H
