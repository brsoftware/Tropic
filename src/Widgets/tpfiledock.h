#ifndef TPFILEDOCK_H
#define TPFILEDOCK_H

#include <QDockWidget>

#include <TpGlobals>

TP_NAMESPACE

class TpFileView;
class TpMainWindow;

class TpFileDock : public QDockWidget
{
    Q_OBJECT

    DEF_PROP(TpMainWindow*, parent);

public:
    TpFileDock(TpMainWindow *parent);

public:
    TpFileView *fileView() const;

signals:
    void fileDoubleClicked(const QString &path);

private:
    TpFileView *m_view;
};

TP_END_NAMESPACE

#endif // TPFILEDOCK_H
