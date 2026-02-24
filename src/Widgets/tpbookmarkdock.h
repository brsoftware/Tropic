#ifndef TPBOOKMARKDOCK_H
#define TPBOOKMARKDOCK_H

#include <QDockWidget>

#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;
class TpBookmarkView;

class TpBookmarkDock : public QDockWidget
{
    Q_OBJECT

public:
    TpBookmarkDock(TpMainWindow *parent);

public:
    void setView(TpBookmarkView *view);
    TpBookmarkView *view() const;

private:
    TpBookmarkView *m_view;
};

TP_END_NAMESPACE

#endif // TPBOOKMARKDOCK_H
