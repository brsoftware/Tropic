#include <Dialogs/TpDialogSaveCopyTo>
#include <Utilities/TpSaveCopyAssistant>
#include <TpMainWindow>

TP_NAMESPACE

TpDialogSaveCopyTo::TpDialogSaveCopyTo(TpMainWindow *parent)
    : QFileDialog(parent),
    m_parent(parent)
{
    DEF_SETTINGS;

    setAcceptDrops(true);
    setAcceptMode(AcceptSave);
    setDirectory(GET_SETTINGS("App/CurrentDirectory", QString));
    setEnabled(true);
    setFileMode(ExistingFile);
    setNameFilters(extensions);
    setObjectName("dialogSaveCopyTo");
    setWindowModality(Qt::WindowModality::WindowModal);
    setWindowTitle(tr("Save A Copy To"));

    selectNameFilter(defaultNameFilter[m_parent->currentLexer()]);

    connect(this,
            &TpDialogSaveCopyTo::accepted,
            this,
            &TpDialogSaveCopyTo::fileSelected);
}

bool TpDialogSaveCopyTo::fileSelected()
{
    QString file = selectedFiles().at(0);
    TpSaveCopyAssistant *assistant = new TpSaveCopyAssistant(m_parent);

    m_successful = assistant->saveFile(file);
    return m_successful;
}

TP_END_NAMESPACE
