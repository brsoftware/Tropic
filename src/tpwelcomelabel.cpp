#include <TpStackedWidget>
#include <TpWelcomeLabel>

TP_NAMESPACE

TpWelcomeLabel::TpWelcomeLabel(TpStackedWidget *parent)
    : QLabel(parent),
    m_parent(parent)
{
    QString text =
        "<center><h1>Create a new document</h1></center>"
        "Click <kbd>Ctrl+N</kbd> to create a new document.<br>"
        "Click <kbd>Ctrl+O</kbd> to open a new document.<br>"
        "Drag a file from anywhere to here.<br>";

    setAlignment(Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignVCenter);
    setObjectName("welcomeLabel");
    setText(text);
    setTextFormat(Qt::TextFormat::RichText);
}

TP_END_NAMESPACE
