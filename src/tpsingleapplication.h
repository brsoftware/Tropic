#ifndef TPSINGLEAPPLICATION_H
#define TPSINGLEAPPLICATION_H

#include <QLocalServer>
#include <QLocalSocket>
#include <QSharedMemory>

#include <TpAppConnectionInfo>
#include <TpAppInstanceInfo>
#include <TpApplication>
#include <TpGlobals>

TP_NAMESPACE

class TpSingleApplication : public QObject
{
    Q_OBJECT

public:
    enum ConnectionType : quint8
    {
        InvalidConnection = 0,
        NewInstance = 1,
        SecondaryInstance = 2,
        Reconnect = 3
    };
    Q_ENUM(ConnectionType)

    enum ConnectionStage : quint8
    {
        StageInitHeader = 0,
        StageInitBody = 1,
        StageConnectedHeader = 2,
        StageConnectedBody = 3
    };
    Q_ENUM(ConnectionStage)

public:
    TpSingleApplication(TpApplication *parent);
    ~TpSingleApplication() override;

public:
    static QString getUsername();
    static void randomSleep();

public:
    void addAppData(const QString &data);
    QStringList appData() const;
    quint16 blockChecksum() const;
    bool connectToPrimary(int millisecs, ConnectionType connectionType);
    void generateBlockServerName();
    void initializeMemoryBlock() const;
    bool isFrameComplete(QLocalSocket *socket);
    qint64 primaryPid() const;
    QString primaryUser() const;
    void startPrimary();
    void startSecondary();
    void readInitMessageBody(QLocalSocket *socket);
    void readMessageHeader(QLocalSocket *socket, ConnectionStage nextStage);
    void writeAcknowledgement(QLocalSocket *socket);
    bool writeConfirmedFrame(int millisecs, const QByteArray &message);
    bool writeConfirmedMessage(int millisecs, const QByteArray &message,
                               TpApplication::SendMode sendMode = TpApplication::SendMode::NonBlocking);

public slots:
    void onClientConnectionClosed(QLocalSocket *socket, quint32 instanceId);
    void onConnectionEstablished();
    void onDataAvailable(QLocalSocket *socket, quint32 instanceId);

public:
    QSharedMemory *appMemory;
    QLocalSocket *appSocket;
    QLocalServer *appServer;
    quint32 appInstanceNumber;
    QString appBlockServerName;
    TpApplication::Options appOptions;
    QMap<QLocalSocket*, TpAppConnectionInfo> appConnectionMap;
    QStringList appDataList;

private:
    TpApplication *m_parent;
};

TP_END_NAMESPACE

#endif // TPSINGLEAPPLICATION_H
