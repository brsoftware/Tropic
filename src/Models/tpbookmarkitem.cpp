#include <Models/TpBookmarkItem>
#include <Views/TpBookmarkView>

TP_NAMESPACE

TpBookmarkItem::TpBookmarkItem(TpBookmarkView *view, int line, QString context)
    : QTreeWidgetItem(view)
{
    setChildIndicatorPolicy(DontShowIndicatorWhenChildless);
    setDisabled(false);
    setExpanded(true);
    setFirstColumnSpanned(false);
    setFlags(Qt::ItemFlag::ItemIsSelectable);
    setLine(line);
    setContext(context);
}

void TpBookmarkItem::setLine(int line)
{
    m_line = line;
    setText(0, QString::number(line));
}

int TpBookmarkItem::line() const
{
    return m_line;
}

void TpBookmarkItem::setContext(QString context)
{
    m_context = context;
    setText(1, context);
}

const QString &TpBookmarkItem::context() const
{
    return m_context;
}

TP_END_NAMESPACE
