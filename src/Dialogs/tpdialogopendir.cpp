#include <Dialogs/TpDialogOpenDir>
#include <Models/TpFileModel>
#include <Views/TpFileView>
#include <TpMainWindow>

TP_NAMESPACE

TpDialogOpenDir::TpDialogOpenDir(TpMainWindow *parent)
    : QFileDialog(parent),
    m_parent(parent)
{
    DEF_SETTINGS;

    setAcceptDrops(true);
    setAcceptMode(AcceptOpen);
    setDirectory(GET_SETTINGS("App/CurrentDirectory", QString));
    setEnabled(true);
    setFileMode(Directory);
    setObjectName("dialogOpenDir");
    setWindowModality(Qt::WindowModality::WindowModal);
    setWindowTitle(tr("Navigate"));

    connect(this,
            &TpDialogOpenDir::accepted,
            this,
            &TpDialogOpenDir::fileSelected);
}

void TpDialogOpenDir::fileSelected()
{
    QDir dir(selectedFiles().at(0));
    TpFileView *view = m_parent->m_fileDock->fileView();
    view->fileModel()->setRootPath(QDir::rootPath());
    view->setRootIndex(view->fileModel()->index(selectedFiles().at(0)));
    m_parent->m_fileDock->setVisible(true);
}

TP_END_NAMESPACE
