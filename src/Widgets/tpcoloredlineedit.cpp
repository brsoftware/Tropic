#include <QColorDialog>

#include <Utilities/TpDelegateTypeChecker>
#include <Widgets/TpColoredLineEdit>

TP_NAMESPACE

TpColoredLineEdit::TpColoredLineEdit(QWidget *parent)
    : TpGeneralLineEdit(parent)
{
    m_action = new QAction(this);
    m_action->setText(tr(""));
    m_action->setObjectName("coloredLineEdit_Button");
    addAction(m_action, TrailingPosition);
    setColor(QColor());
    setInputMask("(000,000,000,000);_");

    connect(m_action,
            &QAction::triggered,
            this,
            &TpColoredLineEdit::onActionTriggered);
    connect(this,
            &TpColoredLineEdit::editingFinished,
            this,
            &TpColoredLineEdit::onEditingFinished);
    connect(this,
            &TpColoredLineEdit::returnPressed,
            this,
            &TpColoredLineEdit::onEditingFinished);
}

void TpColoredLineEdit::setColor(const QColor &color)
{
    m_mutexLocker = true;
    QColor c = color;
    if (!color.isValid())
        c = QColor(0x00, 0x00, 0x00, 0x00);
    QPixmap pm(16, 16);
    pm.fill(c);
    m_action->setIcon(pm);
    m_color = c;
    setText(QString("(%1,%2,%3,%4)").arg(c.red()).arg(c.green()).arg(c.blue()).arg(c.alpha()));
    setModified(true);
    m_mutexLocker = false;
    emit colorChangedByUser();
}

const QColor &TpColoredLineEdit::color() const
{
    return m_color;
}

void TpColoredLineEdit::onActionTriggered(bool)
{
    QColorDialog *dlg = new QColorDialog(this);
    dlg->setCurrentColor(m_color);
    dlg->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose, true);
    dlg->setOption(QColorDialog::ColorDialogOption::ShowAlphaChannel, true);
    connect(dlg,
            &QColorDialog::colorSelected,
            this,
            &TpColoredLineEdit::setColor);
    dlg->setWindowTitle(tr("Select Color"));
    dlg->setObjectName("coloredLineEdit_Dialog");
    dlg->exec();
}

void TpColoredLineEdit::onEditingFinished()
{
    if (m_mutexLocker)
        return;
    setModified(true);
    auto checker = new TpDelegateTypeChecker();
    auto match = checker->regexColor.match(text());
    if (!match.hasMatch())
        return;
    QColor col = QColor(qMin(match.captured(1).toInt(), 255),
                        qMin(match.captured(2).toInt(), 255),
                        qMin(match.captured(3).toInt(), 255),
                        qMin(match.captured(4).toInt(), 255));
    setColor(col);
}

TP_END_NAMESPACE
