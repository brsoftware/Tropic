#ifndef TPFINDINFILESDOCK_H
#define TPFINDINFILESDOCK_H

#include <QDockWidget>

#include <TpGlobals>

TP_NAMESPACE

class TpEditor;
class TpFindInFilesContainer;
class TpMainWindow;

class TpFindInFilesDock : public QDockWidget
{
    Q_OBJECT

public:
    TpFindInFilesDock(TpMainWindow *parent);

signals:
    void resultClicked(const QString &directory, int position);

private:
    TpFindInFilesContainer *m_container;
};

TP_END_NAMESPACE

#endif // TPFINDINFILESDOCK_H
