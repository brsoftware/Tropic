#include <Dialogs/TpDialogSave>
#include <Utilities/TpSaveAssistant>
#include <TpMainWindow>

TP_NAMESPACE

TpDialogSave::TpDialogSave(TpMainWindow *parent)
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
    setObjectName("dialogSave");
    setWindowModality(Qt::WindowModality::WindowModal);
    setWindowTitle(tr("Save"));

    selectNameFilter(defaultNameFilter[m_parent->currentLexer()]);

    connect(this,
            &TpDialogSave::accepted,
            this,
            &TpDialogSave::fileSelected);
}

bool TpDialogSave::fileSelected()
{
    QString file = selectedFiles().at(0);
    TpSaveAssistant *assistant = new TpSaveAssistant(m_parent);

    m_successful = assistant->saveFile(file);
    return m_successful;
}

TP_END_NAMESPACE
