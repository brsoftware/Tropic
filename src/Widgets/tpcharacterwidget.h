#ifndef TPCHARACTERWIDGET_H
#define TPCHARACTERWIDGET_H

#include <QWidget>

#include <TpGlobals>

TP_NAMESPACE

class TpCharacterWidget : public QWidget
{
    Q_OBJECT

public:
    TpCharacterWidget(QWidget *parent);

public:
    QSize sizeHint() const override;

public slots:
    void redrawUsing(const QFont &font);
    void redrawUsingSize(const QString &fontSize);
    void redrawUsingStyle(const QString &fontStyle);
    void redrawMerged(bool enable);

signals:
    void characterSelected(const QString &character);

protected:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    void squareSize();

private:
    QWidget *m_parent;
    QFont m_font;
    int m_columns = 16;
    int m_lastKey = -1;
    int m_squareSize = 0;
};

TP_END_NAMESPACE

#endif // TPCHARACTERWIDGET_H
