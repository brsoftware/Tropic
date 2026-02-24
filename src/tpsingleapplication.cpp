#include <QCryptographicHash>
#include <QRandomGenerator>
#include <QThread>

#include <TpSingleApplication>

#ifdef Q_OS_WIN
#ifndef NOMINMAX
#define NOMINMAX 1
#endif
#include <windows.h>
#include <lmcons.h>
#endif

#ifdef Q_OS_UNIX
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#endif

#if QT_VERSION_MAJOR <= 5
#include <QDataStream>
#endif

TP_NAMESPACE

TpSingleApplication::TpSingleApplication(TpApplication *parent)
    : m_parent(parent)
{
    appServer = nullptr;
    appSocket = nullptr;
    appMemory = nullptr;
    appInstanceNumber = 0;
}

TpSingleApplication::~TpSingleApplication()
{
    if (appSocket != nullptr)
    {
        appSocket->close();
        delete appSocket;
    }

    if (appMemory != nullptr)
    {
        appMemory->lock();
        auto *instance = static_cast<TpAppInstanceInfo*>(appMemory->data());

        if (appServer != nullptr)
        {
            appServer->close();
            delete appServer;
            instance->primary = false;
            instance->primaryPid = -1;
            instance->primaryUser[0] = '\0';
            instance->checksum = blockChecksum();
        }

        appMemory->unlock();

        delete appMemory;
    }
}

QString TpSingleApplication::getUsername()
{
#ifdef Q_OS_WIN
    wchar_t username[UNLEN + 1];
    DWORD usernameLength = UNLEN + 1;
    if (GetUserNameW(username, &usernameLength))
        return QString::fromWCharArray(username);
#if QT_VERSION < QT_VERSION_CHECK(5, 10, 0)
    return QString::fromLocal8Bit(qgetenv("USERNAME"));
#else
    return qEnvironmentVariable("USERNAME");
#endif
#endif

#ifdef Q_OS_UNIX
    QString username;
    uid_t uid = geteuid();
    struct passwd *password = getpwuid(uid);

    if (password)
        username = QString::fromLocal8Bit(password->pw_name);

    if (username.isEmpty())
    {
#if QT_VERSION < QT_VERSION_CHECK(5, 10, 0)
        username = QString::fromLocal8Bit(qgetenv("USER"));
#else
        username = qEnvironmentVariable("USER");
#endif
    }

    return username;
#endif
}

void TpSingleApplication::randomSleep()
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
    QThread::msleep(QRandomGenerator::global()->bounded(8u, 18u));
#else
    qsrand(QDateTime::currentMSecsSinceEpoch() % std::numeric_limits<uint>::max());
    QThread::msleep(qrand() % 11 + 8);
#endif
}

void TpSingleApplication::addAppData(const QString &data)
{
    appDataList.push_back(data);
}

QStringList TpSingleApplication::appData() const
{
    return appDataList;
}

quint16 TpSingleApplication::blockChecksum() const
{
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    quint16 checksum =
        qChecksum(QByteArray(static_cast<const char*>(appMemory->constData()), offsetof(TpAppInstanceInfo, checksum)));
#else
    quint16 checksum =
        qChecksum(static_cast<const char*>(appMemory->constData()), offsetof(TpAppInstanceInfo, checksum));
#endif

    return checksum;
}

bool TpSingleApplication::connectToPrimary(int millisecs, TpSingleApplication::ConnectionType connectionType)
{
    QElapsedTimer timer;
    timer.start();

    if (appSocket == nullptr)
        appSocket = new QLocalSocket();

    if (appSocket->state() == QLocalSocket::LocalSocketState::ConnectedState)
        return true;

    if (appSocket->state() != QLocalSocket::LocalSocketState::ConnectedState)
    {
        while (true)
        {
            randomSleep();

            if (appSocket->state() != QLocalSocket::LocalSocketState::ConnectingState)
                appSocket->connectToServer(appBlockServerName);

            if (appSocket->state() == QLocalSocket::LocalSocketState::ConnectingState)
                appSocket->waitForConnected(static_cast<int>(millisecs - timer.elapsed()));

            if (appSocket->state() == QLocalSocket::LocalSocketState::ConnectedState)
                break;

            if (timer.elapsed() >= millisecs)
                return false;
        }
    }

    QByteArray initMessage;
    QDataStream writeStream(&initMessage, QIODevice::OpenModeFlag::WriteOnly);

#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
    writeStream.setVersion(QDataStream::Version::Qt_5_6);
#endif

    writeStream << appBlockServerName.toLatin1();
    writeStream << static_cast<quint8>(connectionType);
    writeStream << appInstanceNumber;

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    quint16 checksum = qChecksum(QByteArray(initMessage.constData(), static_cast<quint32>(initMessage.length())));
#else
    quint16 checksum = qChecksum(initMessage.constData(), static_cast<quint32>(initMessage.length()));
#endif
    writeStream << checksum;

    return writeConfirmedMessage(static_cast<int>(millisecs - timer.elapsed()), initMessage);
}

void TpSingleApplication::generateBlockServerName()
{
#if defined(Q_OS_MACOS) || defined(Q_OS_DARWIN)
    QCryptographicHash appData(QCryptographicHash::Algorithm::Md5);
#else
    QCryptographicHash appData(QCryptographicHash::Algorithm::Sha256);
#endif

#if QT_VERSION < QT_VERSION_CHECK(6, 3, 0)
    appData.addData("TpApplication", 17);
#else
    appData.addData(QByteArrayView{"SingleApplication"});
#endif

    appData.addData(TpApplication::QApplication::applicationName().toUtf8());
    appData.addData(TpApplication::QApplication::organizationName().toUtf8());
    appData.addData(TpApplication::QApplication::organizationDomain().toUtf8());

    if (!appDataList.isEmpty())
        appData.addData(appDataList.join(QString()).toUtf8());

    if (!(appOptions & TpApplication::Mode::ExcludeAppVersion))
    {
        appData.addData(TpApplication::QApplication::applicationVersion().toUtf8());
    }

    if (!(appOptions & TpApplication::Mode::ExcludeAppPath))
    {
#if defined(Q_OS_WIN)
        appData.addData(TpApplication::QApplication::applicationFilePath().toLower().toUtf8());
#elif defined(Q_OS_LINUX)
        const QByteArray appImagePath = qgetenv("APPIMAGE");

        if (appImagePath.isEmpty())
            appData.addData(TpApplication::QApplication::applicationFilePath().toUtf8());
        else
            appData.addData(appImagePath);
#else
        appData.addData(TpApplication::QApplication::applicationFilePath().toUtf8());
#endif
    }

    if (appOptions & TpApplication::Mode::User)
    {
        appData.addData(getUsername().toUtf8());
    }

    appBlockServerName = QString::fromUtf8(appData.result().toBase64().replace("/", "_"));
}

void TpSingleApplication::initializeMemoryBlock() const
{
    auto *instance = static_cast<TpAppInstanceInfo*>(appMemory->data());

    instance->primary = false;
    instance->secondary = 0;
    instance->primaryPid = -1;
    instance->primaryUser[0] = '\0';
    instance->checksum = blockChecksum();
}

bool TpSingleApplication::isFrameComplete(QLocalSocket *socket)
{
    if (!appConnectionMap.contains(socket))
        return false;

    TpAppConnectionInfo &info = appConnectionMap[socket];

    if (socket->bytesAvailable() < (qint64)(info.messageLength))
        return false;

    return true;
}

qint64 TpSingleApplication::primaryPid() const
{
    qint64 pid;

    appMemory->lock();
    auto *instance = static_cast<TpAppInstanceInfo*>(appMemory->data());
    pid = instance->primaryPid;
    appMemory->unlock();

    return pid;
}

QString TpSingleApplication::primaryUser() const
{
    QByteArray username;

    appMemory->lock();
    auto *instance = static_cast<TpAppInstanceInfo*>(appMemory->data());
    username = instance->primaryUser;
    appMemory->unlock();

    return QString::fromUtf8(username);
}

void TpSingleApplication::startPrimary()
{
    auto *instance = static_cast<TpAppInstanceInfo*>(appMemory->data());

    instance->primary = true;
    instance->primaryPid = QApplication::applicationPid();
    qstrncpy(instance->primaryUser, getUsername().toUtf8().data(), sizeof(instance->primaryUser));

    instance->checksum = blockChecksum();
    appInstanceNumber = 0;

    QLocalServer::removeServer(appBlockServerName);
    appServer = new QLocalServer();

    if (appOptions & TpApplication::Mode::User)
        appServer->setSocketOptions(QLocalServer::SocketOption::UserAccessOption);
    else
        appServer->setSocketOptions(QLocalServer::SocketOption::WorldAccessOption);

    appServer->listen(appBlockServerName);

    connect(appServer,
            &QLocalServer::newConnection,
            this,
            &TpSingleApplication::onConnectionEstablished);
}

void TpSingleApplication::startSecondary()
{
    auto *instance = static_cast<TpAppInstanceInfo*>(appMemory->data());

    instance->secondary++;
    instance->checksum = blockChecksum();
    appInstanceNumber = instance->secondary;
}

void TpSingleApplication::readInitMessageBody(QLocalSocket *socket)
{
    if (!isFrameComplete(socket))
        return;

    QByteArray messageBytes = socket->readAll();
    QDataStream readStream(messageBytes);

#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
    readStream.setVersion(QDataStream::Version::Qt_5_6);
#endif

    QByteArray latin1Name;
    readStream >> latin1Name;

    ConnectionType connectionType = InvalidConnection;
    quint8 connectionTypeValue = InvalidConnection;
    readStream >> connectionTypeValue;
    connectionType = static_cast<ConnectionType>(connectionTypeValue);

    quint32 instanceId = 0;
    readStream >> instanceId;

    quint16 messageChecksum = 0;
    readStream >> messageChecksum;

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    const quint16 actualChecksum =
        qChecksum(QByteArray(messageBytes.constData(), static_cast<quint32>(messageBytes.length() - sizeof(quint16))));
#else
    const quint16 actualChecksum =
        qChecksum(messageBytes.constData(), static_cast<quint32>(messageBytes.length() - sizeof(quint16)));
#endif

    bool isValid = readStream.status() == QDataStream::Status::Ok && QLatin1String(latin1Name) == appBlockServerName &&
        messageChecksum == actualChecksum;

    if (!isValid)
    {
        socket->close();
        return;
    }

    TpAppConnectionInfo &info = appConnectionMap[socket];
    info.instanceId = instanceId;
    info.stage = StageConnectedHeader;

    if (connectionType == NewInstance ||
        (connectionType == SecondaryInstance && appOptions & TpApplication::Mode::SecondaryNotification))
        emit m_parent->instanceStarted();

    writeAcknowledgement(socket);
}

void TpSingleApplication::readMessageHeader(QLocalSocket *socket, TpSingleApplication::ConnectionStage nextStage)
{
    if (!appConnectionMap.contains(socket))
        return;

    if (socket->bytesAvailable() < (qint64)(sizeof(quint64)))
        return;

    QDataStream headerStream(socket);

#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
    headerStream.setVersion(QDataStream::Version::Qt_5_6);
#endif

    quint64 messageLength = 0;
    headerStream >> messageLength;
    TpAppConnectionInfo &info = appConnectionMap[socket];
    info.stage = nextStage;
    info.messageLength = messageLength;

    writeAcknowledgement(socket);
}

void TpSingleApplication::writeAcknowledgement(QLocalSocket *socket)
{
    socket->putChar('\n');
}

bool TpSingleApplication::writeConfirmedFrame(int millisecs, const QByteArray &message)
{
    appSocket->write(message);
    appSocket->flush();

    bool result = appSocket->waitForReadyRead(millisecs);

    if (result)
    {
        appSocket->read(1);
        return true;
    }

    return false;
}

bool TpSingleApplication::
    writeConfirmedMessage(int millisecs, const QByteArray& message, TpApplication::SendMode sendMode)
{
    QElapsedTimer timer;
    timer.start();

    QByteArray header;
    QDataStream headerStream(&header, QIODevice::OpenModeFlag::WriteOnly);

#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
    headerStream.setVersion(QDataStream::Version::Qt_5_6);
#endif

    headerStream << static_cast<quint64>(message.length());

    if (!writeConfirmedFrame(static_cast<int>(millisecs - timer.elapsed()), header))
        return false;

    const bool result = writeConfirmedFrame(static_cast<int>(millisecs - timer.elapsed()), message);

    if (appSocket && sendMode == TpApplication::SendMode::BlockUntilPrimaryExit)
        appSocket->waitForDisconnected(-1);

    return result;
}
void TpSingleApplication::onClientConnectionClosed(QLocalSocket *socket, quint32 instanceId)
{
    if (socket->bytesAvailable() > 0)
        onDataAvailable(socket, instanceId);
}

void TpSingleApplication::onConnectionEstablished()
{
    QLocalSocket *nextSocket = appServer->nextPendingConnection();
    appConnectionMap.insert(nextSocket, TpAppConnectionInfo());

    connect(nextSocket,
            &QLocalSocket::aboutToClose,
            this,
            [nextSocket, this](){
                auto &info = appConnectionMap[nextSocket];
                onClientConnectionClosed(nextSocket, info.instanceId);
            });

    connect(nextSocket,
            &QLocalSocket::disconnected,
            nextSocket,
            &QLocalSocket::deleteLater);

    connect(nextSocket,
            &QLocalSocket::destroyed,
            this,
            [nextSocket, this](){
                appConnectionMap.remove(nextSocket);
            });

    connect(nextSocket,
            &QLocalSocket::readyRead,
            this,
            [nextSocket, this](){
                auto &info = appConnectionMap[nextSocket];

                switch (info.stage)
                {
                case StageInitHeader:
                    readMessageHeader(nextSocket, StageInitBody);
                    break;
                case StageInitBody:
                    readInitMessageBody(nextSocket);
                    break;
                case StageConnectedHeader:
                    readMessageHeader(nextSocket, StageConnectedBody);
                    break;
                case StageConnectedBody:
                    onDataAvailable(nextSocket, info.instanceId);
                    break;
                default:
                    break;
                }
            });
}

void TpSingleApplication::onDataAvailable(QLocalSocket *socket, quint32 instanceId)
{
    if (!isFrameComplete(socket))
        return;

    const QByteArray message = socket->readAll();

    writeAcknowledgement(socket);

    TpAppConnectionInfo &info = appConnectionMap[socket];
    info.stage = StageConnectedHeader;

    emit m_parent->messageReceived(instanceId, message);
}

TP_END_NAMESPACE
