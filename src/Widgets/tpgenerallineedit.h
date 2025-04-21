#ifndef TPGENERALLINEEDIT_H
#define TPGENERALLINEEDIT_H

#include <QLineEdit>

#include <TpGlobals>

TP_NAMESPACE

class TpGeneralLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    TpGeneralLineEdit(QWidget *parent = nullptr);
};

TP_END_NAMESPACE

#endif // TPGENERALLINEEDIT_H
