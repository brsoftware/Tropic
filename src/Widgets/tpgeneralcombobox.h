#ifndef TPGENERALCOMBOBOX_H
#define TPGENERALCOMBOBOX_H

#include <QComboBox>

#include <TpGlobals>

TP_NAMESPACE

class TpGeneralComboBox : public QComboBox
{
    Q_OBJECT

public:
    TpGeneralComboBox(QWidget *parent = nullptr);
};

TP_END_NAMESPACE

#endif // TPGENERALCOMBOBOX_H
