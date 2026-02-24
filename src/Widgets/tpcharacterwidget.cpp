#include <QFontDatabase>
#include <QMouseEvent>
#include <QPainter>
#include <QToolTip>

#include <Widgets/TpCharacterWidget>

TP_NAMESPACE

TpCharacterWidget::TpCharacterWidget(QWidget *parent)
    : QWidget(parent)
{
    setObjectName("characterWidget");
    squareSize();
    setMouseTracking(true);
}

QSize TpCharacterWidget::sizeHint() const
{
    return QSize(m_columns * m_squareSize, (65536 / m_columns) * m_squareSize);
}

void TpCharacterWidget::redrawUsing(const QFont &font)
{
    m_font.setFamily(font.family());
    squareSize();
    adjustSize();
    update();
}

void TpCharacterWidget::redrawUsingSize(const QString &fontSize)
{
    m_font.setPointSize(fontSize.toInt());
    squareSize();
    adjustSize();
    update();
}

void TpCharacterWidget::redrawUsingStyle(const QString &fontStyle)
{
    const QFont::StyleStrategy oldOne = m_font.styleStrategy();
    m_font = QFontDatabase::font(m_font.family(), fontStyle, m_font.pointSize());
    m_font.setStyleStrategy(oldOne);
    squareSize();
    adjustSize();
    update();
}

void TpCharacterWidget::redrawMerged(bool enable)
{
    m_font.setStyleStrategy(enable ? QFont::StyleStrategy::PreferDefault : QFont::StyleStrategy::NoFontMerging);
    adjustSize();
    update();
}

void TpCharacterWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = mapFromGlobal(event->globalPosition()).toPoint();
    uint key = (pos.y() / m_squareSize) * m_columns + pos.x() / m_squareSize;
    QString toolTip = tr("<p>Character: <span style=\"font-size:20pt;font-family:%1\">").arg(m_font.family())
        + QChar(key) + tr("</span><p>Value: 0x") + QString::number(key, 16);
    QToolTip::showText(event->globalPosition().toPoint(), toolTip, this);
}

void TpCharacterWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::LeftButton)
    {
        m_lastKey = (event->position().toPoint().y() / m_squareSize)
            * m_columns + event->position().toPoint().x() / m_squareSize;
        if (QChar(m_lastKey).category() != QChar::Category::Other_NotAssigned)
            emit characterSelected(QString(QChar(m_lastKey)));
        update();
    }

    else
    {
        QWidget::mousePressEvent(event);
    }
}

void TpCharacterWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setFont(m_font);
    QPalette palette = qApp->palette();
    painter.fillRect(event->rect(), palette.window());
    QRect redrawRect = event->rect();
    int bRow = redrawRect.top() / m_squareSize;
    int eRow = redrawRect.bottom() / m_squareSize;
    int bCol = redrawRect.left() / m_squareSize;
    int eCol = redrawRect.right() / m_squareSize;
    painter.setPen(QPen(palette.mid(), 2));
    for (int row = bRow; row <= eRow; row++)
        for (int col = bCol; col <= eCol; col++)
            painter.drawRect(col * m_squareSize, row * m_squareSize, m_squareSize, m_squareSize);
    QFontMetrics fontMetrics(m_font);
    painter.setPen(QPen(palette.windowText(), 2));

    for (int row = bRow; row <= eRow; row++)
    {
        for (int col = bCol; col <= eCol; col++)
        {
            int key = row * m_columns + col;
            painter.setClipRect(col * m_squareSize, row * m_squareSize, m_squareSize, m_squareSize);
            if (key == m_lastKey)
                painter.fillRect(col * m_squareSize + 1, row * m_squareSize + 1,
                    m_squareSize, m_squareSize, palette.brightText());
            painter.drawText(col * m_squareSize + (m_squareSize / 2) - fontMetrics.horizontalAdvance(QChar(key)) / 2,
                row * m_squareSize + 4 + fontMetrics.ascent(), QString(QChar(key)));
        }
    }
}

void TpCharacterWidget::squareSize()
{
    m_squareSize = qMax(16, 4 + QFontMetrics(m_font, this).height());
}

TP_END_NAMESPACE
