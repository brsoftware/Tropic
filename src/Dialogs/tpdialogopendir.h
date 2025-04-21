#ifndef TPDIALOGOPENDIR_H
#define TPDIALOGOPENDIR_H

#include <QFileDialog>

#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;

class TpDialogOpenDir : public QFileDialog
{
    Q_OBJECT

public:
    TpDialogOpenDir(TpMainWindow *parent = nullptr);

public slots:
    void fileSelected();

private:
    TpMainWindow *m_parent;
};

TP_END_NAMESPACE

#endif // TPDIALOGOPENDIR_H
