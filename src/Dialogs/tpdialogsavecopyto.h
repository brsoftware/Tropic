#ifndef TPDIALOGSAVECOPYTO_H
#define TPDIALOGSAVECOPYTO_H

#include <QFileDialog>

#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;

class TpDialogSaveCopyTo : public QFileDialog
{
    Q_OBJECT

    DEF_PROP(bool, successful);

public:
    TpDialogSaveCopyTo(TpMainWindow *parent = nullptr);

public slots:
    bool fileSelected();
    DEF_PROP_FUNC(bool, successful, Successful);

private:
    TpMainWindow *m_parent;
};

TP_END_NAMESPACE

#endif // TPDIALOGSAVECOPYTO_H
