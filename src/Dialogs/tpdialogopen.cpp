#include <Dialogs/TpDialogOpen>
#include <Utilities/TpOpenAssistant>
#include <TpMainWindow>

TP_NAMESPACE

TpDialogOpen::TpDialogOpen(TpMainWindow *parent)
    : QFileDialog(parent),
    m_parent(parent)
{
    DEF_SETTINGS;

    setAcceptDrops(true);
    setAcceptMode(AcceptOpen);
    setDirectory(GET_SETTINGS("App/CurrentDirectory", QString));
    setEnabled(true);
    setFileMode(ExistingFiles);
    setNameFilters(extensions);
    setObjectName("dialogOpen");
    setWindowModality(Qt::WindowModality::WindowModal);
    setWindowTitle(tr("Open"));

    selectNameFilter(defaultNameFilter[None]);

    connect(this,
            &TpDialogOpen::accepted,
            this,
            &TpDialogOpen::fileSelected);
}

void TpDialogOpen::fileSelected()
{
    QStringList files = selectedFiles();
    TpOpenAssistant *assistant = new TpOpenAssistant(m_parent);

    assistant->openFiles(files);
}

TP_END_NAMESPACE
