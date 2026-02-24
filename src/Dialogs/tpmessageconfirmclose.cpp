#include <Dialogs/TpMessageConfirmClose>

TP_NAMESPACE

TpMessageConfirmClose::TpMessageConfirmClose(QWidget *parent)
    : QObject(parent),
    m_parent(parent)
{}

int TpMessageConfirmClose::say()
{
    QMessageBox *message = new QMessageBox(m_parent);

    message->setStandardButtons(
        QMessageBox::StandardButton::Save | QMessageBox::StandardButton::Discard | QMessageBox::StandardButton::Cancel
    );

    message->setDefaultButton(QMessageBox::StandardButton::Save);
    message->setEscapeButton(QMessageBox::StandardButton::Cancel);
    message->setIcon(QMessageBox::Icon::Question);
    message->setObjectName("msgConfirmSave");

    message->setInformativeText(msgcc_InfoText);
    message->setText(msgcc_Text);
    message->setWindowTitle(msgcc_Title);

    switch (message->exec())
    {
    case QMessageBox::StandardButton::Save:
        return Save;
    case QMessageBox::StandardButton::Discard:
        return Discard;
    case QMessageBox::StandardButton::Cancel:
        return Cancel;
    }

    return Cancel;
}

TP_END_NAMESPACE
