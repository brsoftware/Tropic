#include <QFontDialog>

#include <Widgets/TpFontButton>

TP_NAMESPACE

TpFontButton::TpFontButton(QWidget *parent)
    : QPushButton(parent),
    m_font()
{
    setObjectName("fontButton");
    setText(tr("Choose Font..."));

    connect(this,
            &TpFontButton::clicked,
            this,
            &TpFontButton::showFontDialog);
}

void TpFontButton::showFontDialog(bool)
{
    QFontDialog *dlg = new QFontDialog(this);
    dlg->setObjectName("fontButton_fontDialog");
    dlg->setCurrentFont(m_font);
    connect(dlg,
            &QFontDialog::currentFontChanged,
            this,
            [this](const QFont &font){m_font = font;});
    dlg->exec();
}

TP_END_NAMESPACE
