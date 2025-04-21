#ifndef TPDOCUMENTDOCK_H
#define TPDOCUMENTDOCK_H

#include <QDockWidget>

#include <TpGlobals>

TP_NAMESPACE

class TpDocumentView;
class TpMainWindow;
class TpTabWidget;

class TpDocumentDock : public QDockWidget
{
    Q_OBJECT

public:
    TpDocumentDock(TpMainWindow *parent);

public:
    TpDocumentView *documentView() const;

signals:
    void fileDoubleClicked(TpTabWidget *tab, const QString &path);

private:
    TpMainWindow *m_parent;
    TpDocumentView *m_view;
};

TP_END_NAMESPACE

#endif // TPDOCUMENTDOCK_H
