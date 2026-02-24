#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

#include <Utilities/TpOpenAssistant>
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

    setAcceptDrops(true);
    setAlignment(Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignVCenter);
    setObjectName("welcomeLabel");
    setText(text);
    setTextFormat(Qt::TextFormat::RichText);
}

void TpWelcomeLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void TpWelcomeLabel::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();

    if (mimeData)
    {
        if (mimeData->hasUrls())
        {
            QStringList sl;

            for (const auto &item : mimeData->urls())
                if (item.isLocalFile())
                    sl << item.toLocalFile();

            if (sl.empty())
            {
                QLabel::dropEvent(event);
                return;
            }

            TpOpenAssistant *assistant = new TpOpenAssistant(m_parent->m_parent);
            assistant->openFiles(sl);
            event->accept();
            return;
        }
    }

    QLabel::dropEvent(event);
}

TP_END_NAMESPACE
