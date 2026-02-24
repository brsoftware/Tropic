#ifndef TPDIALOGGOTO_H
#define TPDIALOGGOTO_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QSpinBox>
#include <QVBoxLayout>

#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;

class TpDialogGoto : public QDialog
{
    Q_OBJECT

public:
    enum CurrentMode
    {
        Line,
        Position
    };

public:
    explicit TpDialogGoto(TpMainWindow *parent);

private slots:
    void onRadioLineToggled(bool);
    void onRadioPositionToggled(bool);
    void onButtonGotoClicked(bool);
    void onButtonCloseClicked(bool);

private:
    TpMainWindow *m_parent;
    QVBoxLayout *m_mainLayout;
    QFormLayout *m_editLayout;
    QGroupBox *m_groupBox;
    QHBoxLayout *m_groupBoxLayout;
    QRadioButton *m_radioLine;
    QRadioButton *m_radioPosition;
    QLabel *m_editLabel;
    QSpinBox *m_edit;
    QDialogButtonBox *m_box;
    QPushButton *m_buttonGoto;
    QPushButton *m_buttonClose;

    CurrentMode m_currentMode;
};

TP_END_NAMESPACE

#endif // TPDIALOGGOTO_H
