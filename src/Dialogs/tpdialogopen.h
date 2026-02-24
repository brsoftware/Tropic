#ifndef TPDIALOGOPEN_H
#define TPDIALOGOPEN_H

#include <QFileDialog>

#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;

class TpDialogOpen : public QFileDialog
{
    Q_OBJECT

public:
    TpDialogOpen(TpMainWindow *parent = nullptr);

public slots:
    void fileSelected();

private:
    TpMainWindow *m_parent;
};

TP_END_NAMESPACE

#endif // TPDIALOGOPEN_H
