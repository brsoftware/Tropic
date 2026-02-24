#ifndef TPDOCUMENTSVIEW_H
#define TPDOCUMENTSVIEW_H

#include <QTreeWidget>

#include <Models/TpDocumentsItem>
#include <TpGlobals>

TP_NAMESPACE

class TpTabSplitter;

class TpDocumentsView : public QTreeWidget
{
    Q_OBJECT

public:
    TpDocumentsView(TpTabSplitter *parent);

public:
    TpDocumentsItem *addItem(QString text, int tabSerial);
    void removeItem(QString text, int tabSerial);

signals:
    void documentsItemDoubleClicked(int line);
    void actionCompleted();

public slots:
    void onLineEditTextChanged(const QString &text);
    void onItemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    int filterByScore(TpDocumentsItem *item, const QString &filter);
    int scoreItem(TpDocumentsItem *item, const QString &filter);

private:
    TpTabSplitter *m_parent;
    TpDocumentsItem *m_best;
    int m_bestScore;
};

TP_END_NAMESPACE

#endif // TPDOCUMENTSVIEW_H
