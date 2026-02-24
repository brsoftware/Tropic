#include <Models/TpFileModel>

TP_NAMESPACE

TpFileModel::TpFileModel(QObject *parent)
    : QFileSystemModel(parent)
{
    setObjectName("fileModel");
    setOption(DontWatchForChanges, false);
    setOption(DontResolveSymlinks, false);
    setOption(DontUseCustomDirectoryIcons, false);
    setReadOnly(false);
    setResolveSymlinks(true);
}

TP_END_NAMESPACE
