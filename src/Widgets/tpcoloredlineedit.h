#ifndef TPCOLOREDLINEEDIT_H
#define TPCOLOREDLINEEDIT_H

#include <QPushButton>

#include <Widgets/TpGeneralLineEdit>
#include <TpGeneralAction>

TP_NAMESPACE

class TpColoredLineEdit : public TpGeneralLineEdit
{
    Q_OBJECT

public:
    TpColoredLineEdit(QWidget *parent = nullptr);

public:
    const QColor &color() const;

signals:
    void colorChangedByUser();

public slots:
    void setColor(const QColor &color);

private slots:
    void onActionTriggered(bool);
    void onEditingFinished();

private:
    QAction *m_action;
    QColor m_color;
    bool m_mutexLocker = false;
};

TP_END_NAMESPACE

#endif // TPCOLOREDLINEEDIT_H
