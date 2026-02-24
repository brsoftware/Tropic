#ifndef TPCOMMANDSVIEW_H
#define TPCOMMANDSVIEW_H

#include <QTreeWidget>

#include <Models/TpCommandsItem>
#include <TpGlobals>

TP_NAMESPACE

class TpDialogCommands;

class TpCommandsView : public QTreeWidget
{
    Q_OBJECT

public:
    TpCommandsView(TpDialogCommands *parent);

public:
    TpCommandsItem *add(QMenu *menu);

signals:
    void commandsItemDoubleClicked(QObject *action);

public slots:
    void onLineEditTextChanged(const QString &text);

private:
    void takeAction(TpCommandsItem *parent, QAction *action);
    void takeSubmenu(TpCommandsItem *parent, QMenu *menu);
    bool filterItem(TpCommandsItem *item, const QString &filter);
    int filterByScore(TpCommandsItem *item, const QString &filter);
    void unhideRecursively(TpCommandsItem *item);
    int scoreItem(TpCommandsItem *item, const QString &filter);

private slots:
    void onCustomContextMenuRequested(const QPoint &point);
    void onItemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    TpDialogCommands *m_parent;
    TpCommandsItem *m_best;
    int m_bestScore;
};

TP_END_NAMESPACE

#endif // TPBOOKMARKVIEW_H
