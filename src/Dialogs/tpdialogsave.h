#ifndef TPDIALOGSAVE_H
#define TPDIALOGSAVE_H

#include <QFileDialog>

#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;

class TpDialogSave : public QFileDialog
{
    Q_OBJECT

    DEF_PROP(bool, successful);

public:
    TpDialogSave(TpMainWindow *parent = nullptr);

public slots:
    bool fileSelected();
    DEF_PROP_FUNC(bool, successful, Successful);

private:
    TpMainWindow *m_parent;
};

TP_END_NAMESPACE

#endif // TPDIALOGSAVE_H
