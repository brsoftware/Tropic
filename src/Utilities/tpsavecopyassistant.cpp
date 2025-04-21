#include <QDir>
#include <QFileIconProvider>
#include <QFileInfo>

#if QT_VERSION_MAJOR <= 5
#include <QTextCodec>
#include <QTextStream>
#endif

#include <Dialogs/TpMessageCritical>
#include <Utilities/TpSaveCopyAssistant>
#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpSaveCopyAssistant::TpSaveCopyAssistant(TpMainWindow *parent)
    : QObject(parent),
    m_parent(parent)
{}

bool TpSaveCopyAssistant::saveFile(QString filePath)
{
    DEF_SETTINGS;

    QString path = filePath;
    QFile file(path);
    QFileInfo fileInfo(file);

    if (path.isNull() || path.isEmpty())
        return false;

    if (file.open(QFile::OpenModeFlag::WriteOnly | QFile::OpenModeFlag::Text))
    {
        QTextStream textStream(&file);
#if QT_VERSION_MAJOR >= 6
        textStream.setEncoding(QStringConverter::Encoding::Utf8);
#else
        QTextCodec *textCodec = QTextCodec::codecForName("UTF-8");
        textStream.setCodec(textCodec);
#endif
        QString content = m_parent->m_widget->tabs()->tab()->tab()->text();
        textStream << content;

        SET_SETTINGS("App/CurrentDirectory", fileInfo.dir().absolutePath());
    }

    else
    {
        TpMessageCritical *critical = new TpMessageCritical(m_parent);
        critical->say(
            tr("File Error"),
            tr("The file of the following file path could not be copied and saved: '%1'").arg(path),
            tr(fileErrorReason(file.error()))
        );

        file.close();
        return false;
    }

    file.close();
    return true;
}

TP_END_NAMESPACE
