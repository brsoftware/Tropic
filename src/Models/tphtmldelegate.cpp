#include <QAbstractTextDocumentLayout>
#include <QApplication>
#include <QPainter>
#include <QTextDocument>

#include <Models/TpHtmlDelegate>

TP_NAMESPACE

TpHtmlDelegate::TpHtmlDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{}

void TpHtmlDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);
    QStyle *style = opt.widget ? opt.widget->style() : QApplication::style();

    QTextDocument *doc = new QTextDocument();
    doc->setHtml(opt.text);
    opt.text = "";

    style->drawControl(QStyle::ControlElement::CE_ItemViewItem, &opt, painter);
    QAbstractTextDocumentLayout::PaintContext context;

    if (opt.state & QStyle::StateFlag::State_Selected)
        context.palette.setColor(
            QPalette::ColorRole::Text,
            opt.palette.color(QPalette::ColorGroup::Active, QPalette::ColorRole::HighlightedText)
        );

    QRect textRect = style->subElementRect(QStyle::SubElement::SE_ItemViewItemText, &option);

    painter->save();
    painter->translate(textRect.topLeft());
    painter->setClipRect(textRect.translated(-textRect.topLeft()));

    doc->documentLayout()->draw(painter, context);
    painter->restore();
}

QSize TpHtmlDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);

    QTextDocument *doc = new QTextDocument();
    doc->setHtml(option.text);
    doc->setTextWidth(option.rect.width());

    return QSize(doc->idealWidth(), doc->size().height());
}

TP_END_NAMESPACE
