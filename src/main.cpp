#include <TpApplication>
#include <TpColorScheme>
#include <TpMainWindow>

#if QT_VERSION_MAJOR <= 5
#include <QDebug>
#endif

using namespace TP_NAMESPACE_NAME;

int main(int argc, char *argv[])
{
    TpApplication app(argc, argv, true);

    qSetMessagePattern("[%{time HH:mm:ss.zzz}][%{function}:%{line}] %{message}");

    if (app.isSecondary())
    {
        app.sendMessage(app.arguments().join('\f'));
        qDebug() << "Tropic: App already running.";
        qDebug() << "Primary instance PID:" << app.primaryPid();
        qDebug() << "Primary instance user:" << app.primaryUser();
        return 0;
    }

    readFromSettingsToDefaultColorScheme();

    TpMainWindow *mainWindow = new TpMainWindow;
    mainWindow->showMaximized();

    return app.exec();
}
