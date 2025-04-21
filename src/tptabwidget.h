#ifndef TPTABWIDGET_H
#define TPTABWIDGET_H

#include <QTabWidget>

#include <Models/TpDocumentItem>
#include <TpGlobals>
#include <TpTabBar>

TP_NAMESPACE

class TpEditor;
class TpTabSplitter;

class TpTabWidget : public QTabWidget
{
    Q_OBJECT

    friend class TpEditor;
    friend class TpMainWindow;
    friend class TpTabSplitter;

public:
    enum
    {
        AllEditors,
        ToTheLeft,
        ToTheRight,
        Unchanged,
        ExceptCurrent,
    };

public:
    TpTabWidget(TpTabSplitter *parent);
    ~TpTabWidget();

public:
    bool hasTab() const;
    TpEditor *tab() const;
    TpEditor *tabAt(int index) const;
    unsigned int serial() const;

    TpEditor *addEditor();
    TpEditor *addEditor(QString currentPath, QString currentText, QString currentContent);
    TpEditor *addEditor(TpEditor *editor);
    void removeEditor(TpEditor *editor, bool noDelete = false);

    QList<TpEditor*> acquire(int mode = AllEditors) const;
    bool contains(QWidget *widget) const;

    TpDocumentItem *currentItem() const;

signals:
    void tabNameChanged();

private:
    TpTabSplitter *m_parent;
    TpTabBar *m_bar;
    unsigned int m_serial;
};

typedef QList<TpTabWidget*> TpTabWidgetList;

TP_END_NAMESPACE

#endif // TPTABWIDGET_H
