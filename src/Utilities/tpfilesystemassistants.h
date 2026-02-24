#include <QDesktopServices>
#include <QDir>
#include <QFileInfo>
#include <QProcess>
#include <QUrl>

#include <TpGlobals>

TP_NAMESPACE

inline void revealInExplorer(QString path)
{
    QFileInfo fileInfo(path);

#if defined(Q_OS_WIN) || defined(Q_OS_WIN32) || defined(Q_OS_WINDOWS)
    QStringList args;
    if (!fileInfo.isDir())
        args << "/select,";
    args << QDir::toNativeSeparators(path);

    if (QProcess::startDetached("explorer", args))
        return;
#elif defined(Q_OS_MAC) || defined(Q_OS_DARWIN)
    QStringList args;
    args << "-e";
    args << "tell application \"Finder\"";
    args << "-e";
    args << "activate";
    args << "-e";
    args << "select POSIX file \"" + path + "\"";
    args << "-e";
    args << "end tell";
    args << "-e";
    args << "return";
    if (!(QProcess::execute("/usr/bin/osascript", args)))
        return;
#endif

    QDesktopServices::openUrl(QUrl::fromLocalFile(fileInfo.isDir() ? path : fileInfo.path()));
}

inline void openInCMD(QString path)
{
    QFileInfo fileInfo(path);
    if (fileInfo.isFile())
        path = fileInfo.absoluteDir().absolutePath();
    QString command;
    QStringList args;

#if defined(Q_OS_WIN) || defined(Q_OS_WIN32) || defined(Q_OS_WINDOWS)
    command = "cmd /C start \"\" cmd /K cd /d \"" + path + "\"";
    QProcess process;
    QStringList arg = QProcess::splitCommand(command);
    if (arg.isEmpty())
        return;
    process.setProgram(arg.takeFirst());
    process.setArguments(arg);
    process.startDetached();
    return;
#elif defined(Q_OS_MAC) || defined(Q_OS_DARWIN)
    command = "open";
    args << "-a";
    args << "Terminal";
    args << "\"" + path + "\"";
#else
    command = "gnome-terminal";
    args << "--working-directory=\"" + path + "\"";
#endif

    QProcess::startDetached(command, args);
}

inline void revealInDefaultViewer(QString path)
{
    QUrl fileUrl = QUrl::fromLocalFile(path);
    QDesktopServices::openUrl(fileUrl);
}

TP_END_NAMESPACE
