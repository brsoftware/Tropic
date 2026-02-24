#ifndef TPDIALOGCOMMANDS_H
#define TPDIALOGCOMMANDS_H

#include <QDialog>
#include <QVBoxLayout>

#include <Widgets/TpGeneralLineEdit>
#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;
class TpCommandsView;

class TpDialogCommands : public QDialog
{
    Q_OBJECT

public:
    TpDialogCommands(TpMainWindow *parent);

public:
    void setView(TpCommandsView *view);
    TpCommandsView *view() const;

public slots:
    void onLineEditReturnPressed();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    TpMainWindow *m_parent;
    QVBoxLayout *m_layout;
    TpGeneralLineEdit *m_lineEdit;
    TpCommandsView *m_view;
};

TP_END_NAMESPACE

#endif // TPDIALOGDOCUMENTS_H
