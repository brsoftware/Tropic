#ifndef TPGENERALACTION_H
#define TPGENERALACTION_H

#include <QAction>
#include <QToolBar>

#include <TpGlobals>

TP_NAMESPACE

class TpGeneralAction : public QAction
{
    Q_OBJECT

public:
    TpGeneralAction(QMenu *parent, QString content, QKeySequence::StandardKey shortcut,
                    bool enabled = false, bool checkable = false, bool checked = false);
    TpGeneralAction(QMenu *parent, QString content = "", QKeySequence shortcut = QKeySequence(),
                    bool enabled = false, bool checkable = false, bool checked = false);
    TpGeneralAction(QToolBar *parent, QString content = "", QKeySequence shortcut = QKeySequence());

public:
    void initialize(QString content, QKeySequence shortcut = QKeySequence(),
                    bool enabled = false, bool checkable = false, bool checked = false);

private:
    QMenu *m_parent;
};

typedef QList<TpGeneralAction*> TpActionList;

TP_END_NAMESPACE

#endif // TPGENERALACTION_H
