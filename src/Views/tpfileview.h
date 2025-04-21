#ifndef TPFILEVIEW_H
#define TPFILEVIEW_H

#include <QTreeView>

#include <Models/TpFileModel>
#include <TpGlobals>

TP_NAMESPACE

class TpMainWindow;

class TpFileView : public QTreeView
{
    Q_OBJECT

public:
    explicit TpFileView(TpMainWindow *parent);

public:
    TpFileModel *fileModel() const;

signals:
    void fileDoubleClicked(const QString &path);

public slots:
    void onCustomContextMenuRequested(const QPoint &point);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

private:
    TpFileModel *m_model;
    TpMainWindow *m_parent;
};

TP_END_NAMESPACE

#endif // TPFILEVIEW_H
