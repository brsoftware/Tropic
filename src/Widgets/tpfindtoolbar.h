#ifndef TPFINDTOOLBAR_H
#define TPFINDTOOLBAR_H

#include <Widgets/TpGeneralLineEdit>
#include <TpGeneralAction>
#include <TpGeneralToolBar>

TP_NAMESPACE

class TpMainWindow;

class TpFindToolBar : public TpGeneralToolBar
{
    Q_OBJECT

    friend class TpEditor;
    friend class TpMainWindow;

public:
    TpFindToolBar(TpMainWindow *parent);

signals:
    void textChanged(const QString &text);

private slots:
    void on_Exit(bool);
    void on_ReturnPressed();

private:
    TpGeneralLineEdit *m_findEdit;
    TpGeneralAction *m_exit;
    TpMainWindow *m_parent;
};

TP_END_NAMESPACE

#endif // TPFINDTOOLBAR_H
