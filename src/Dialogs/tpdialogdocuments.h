#ifndef TPDIALOGDOCUMENTS_H
#define TPDIALOGDOCUMENTS_H

#include <QDialog>
#include <QVBoxLayout>

#include <Widgets/TpGeneralLineEdit>
#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;
class TpDocumentsView;

class TpDialogDocuments : public QDialog
{
    Q_OBJECT

public:
    TpDialogDocuments(TpMainWindow *parent);

public:
    void setView(TpDocumentsView *view);
    TpDocumentsView *view() const;

public slots:
    void onLineEditReturnPressed();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    TpMainWindow *m_parent;
    QVBoxLayout *m_layout;
    TpGeneralLineEdit *m_lineEdit;
    TpDocumentsView *m_view;
};

TP_END_NAMESPACE

#endif // TPDIALOGDOCUMENTS_H
