#ifndef TPAPPLICATION_H
#define TPAPPLICATION_H

#include <QApplication>

#include <TpGlobals>

TP_NAMESPACE

class TpSingleApplication;

class TpApplication : public QApplication
{
    Q_OBJECT

public:
    enum Mode
    {
        User = 1 << 0,
        System = 1 << 1,
        SecondaryNotification = 1 << 2,
        ExcludeAppVersion = 1 << 3,
        ExcludeAppPath = 1 << 4
    };
    Q_ENUM(Mode)
    Q_DECLARE_FLAGS(Options, Mode)
    Q_FLAG(Options)

    enum SendMode
    {
        NonBlocking,
        BlockUntilPrimaryExit
    };

public:
    explicit TpApplication(int &argc, char *argv[],
        bool allowSecondary = false, Options options = User, int timeout = 1000,
        const QString &userData = {});
    ~TpApplication() override;

public:
    bool isPrimary() const;
    bool isSecondary() const;

public:
    quint32 instanceId() const;
    qint64 primaryPid() const;
    QString primaryUser() const;
    QString currentUser() const;
    QStringList userData() const;

public:
    bool sendMessage(QString message, int timeout = 100, SendMode sendMode = NonBlocking);
    bool sendMessage(const QByteArray &message, int timeout = 100, SendMode sendMode = NonBlocking);

signals:
    void instanceStarted();
    void messageReceived(qint32 instanceId, QByteArray message);

private:
    void abortSafely();

private:
    TpSingleApplication *m_app;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(TpApplication::Options)

TP_END_NAMESPACE

#endif // TPAPPLICATION_H
