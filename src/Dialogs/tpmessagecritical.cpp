#include <Dialogs/TpMessageCritical>

TP_NAMESPACE

TpMessageCritical::TpMessageCritical(QWidget *parent)
    : QObject(parent),
    m_parent(parent)
{}

int TpMessageCritical::genericSay(QString title, QString text, QString infoText, bool warning)
{
    QMessageBox *message = new QMessageBox(m_parent);

    message->setStandardButtons(
        QMessageBox::StandardButton::Cancel |
        QMessageBox::StandardButton::Ok
    );

    message->setDefaultButton(QMessageBox::StandardButton::Ok);
    message->setEscapeButton(QMessageBox::StandardButton::Cancel);
    message->setIcon(warning ? QMessageBox::Icon::Warning : QMessageBox::Icon::Critical);
    message->setObjectName("msgGenericSay");

    message->setInformativeText(infoText);
    message->setText(text);
    message->setWindowTitle(title);

    message->exec();

    return message->result();
}

int TpMessageCritical::say(QString title, QString text, QString infoText)
{
    QMessageBox *message = new QMessageBox(m_parent);

    message->setStandardButtons(
        QMessageBox::StandardButton::Ok
    );

    message->setDefaultButton(QMessageBox::StandardButton::Save);
    message->setEscapeButton(QMessageBox::StandardButton::Cancel);
    message->setIcon(QMessageBox::Icon::Question);
    message->setObjectName("msgConfirmSave");

    message->setInformativeText(infoText);
    message->setText(text);
    message->setWindowTitle(title);

    return message->exec();
}

TP_END_NAMESPACE
