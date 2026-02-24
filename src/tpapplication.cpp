#if QT_VERSION_MAJOR <= 5
#include <QElapsedTimer>
#endif

#include <TpApplication>
#include <TpSingleApplication>

TP_NAMESPACE

TpApplication::TpApplication(int &argc, char *argv[],
    bool allowSecondary, Options options, int timeout,
    const QString &userData)
    : QApplication(argc, argv),
    m_app(new TpSingleApplication(this))
{
    setApplicationDisplayName(tr("Tropic"));
    setApplicationName("Tropic");
    setApplicationVersion(tr("0.8.0"));
    setObjectName("application");
    setOrganizationName(tr("Bright Software Foundation"));
    setOrganizationDomain("BrightSoftwareFoundation.org");

    initOtherSettings();
    initStyleSettings();

#if defined(Q_OS_ANDROID) || defined(Q_OS_IOS)
    qWarning() << "TpApplication: the app may lack singleton features on Android or iOS.";
    return;
#endif

    m_app->appOptions = options;

    if (!userData.isEmpty())
        m_app->addAppData(userData);

    m_app->generateBlockServerName();
    TpSingleApplication::randomSleep();

#ifdef Q_OS_UNIX
#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
    m_app->appMemory = new QSharedMemory(QNativeIpcKey(m_app->appBlockServerName));
#else
    m_app->appMemory = new QSharedMemory(m_app->appBlockServerName);
#endif
    m_app->appMemory->attach();
    delete m_app->appMemory;
#endif

#if QT_VERSION >= QT_VERSION_CHECK(6, 6, 0)
    m_app->appMemory = new QSharedMemory(QNativeIpcKey(m_app->appBlockServerName));
#else
    m_app->appMemory = new QSharedMemory(m_app->appBlockServerName);
#endif

    if (m_app->appMemory->create(sizeof(TpAppInstanceInfo)))
    {
        if (!m_app->appMemory->lock())
        {
            qCritical() << "TpApplication: Unable to lock memory block after create.";
            abortSafely();
        }

        m_app->initializeMemoryBlock();
    }

    else
    {
        if (m_app->appMemory->error() == QSharedMemory::SharedMemoryError::AlreadyExists)
        {
            if (!m_app->appMemory->attach())
            {
                qCritical() << "TpApplication: Unable to attach to shared memory block.";
                abortSafely();
            }

            if (!m_app->appMemory->lock())
            {
                qCritical() << "TpApplication: Unable to lock memory block after attach.";
                abortSafely();
            }
        }

        else
        {
            qCritical() << "TpApplication: Unable to create block.";
            abortSafely();
        }
    }

    auto *instance = static_cast<TpAppInstanceInfo*>(m_app->appMemory->data());
    QElapsedTimer timer;
    timer.start();

    while (true)
    {
        if (m_app->blockChecksum() == instance->checksum)
            break;

        if (timer.elapsed() > 5000)
        {
            qWarning() << "TpApplication: Shared memory block has been in an inconsistent state from"
                          "more than 5s. Assuming primary instance failure.";
            m_app->initializeMemoryBlock();
        }

        if (!m_app->appMemory->unlock())
        {
            qDebug() << "TpApplication: Unable to unlock memory for random wait.";
            qDebug() << m_app->appMemory->errorString();
        }

        TpSingleApplication::randomSleep();

        if (!m_app->appMemory->lock())
        {
            qCritical() << "TpApplication: Unable to lock memory after random wait.";
            abortSafely();
        }
    }

    if (!instance->primary)
    {
        m_app->startPrimary();

        if (!m_app->appMemory->unlock())
        {
            qDebug() << "TpApplication: Unable to unlock memory after primary start.";
            qDebug() << m_app->appMemory->errorString();
        }

        return;
    }

    if (allowSecondary)
    {
        m_app->startSecondary();

        if (m_app->appOptions & SecondaryNotification)
        {
            m_app->connectToPrimary(timeout, TpSingleApplication::ConnectionType::SecondaryInstance);
        }

        if (!m_app->appMemory->unlock())
        {
            qDebug() << "TpApplication: Unable to unlock memory after secondary start.";
            qDebug() << m_app->appMemory->errorString();
        }

        return;
    }

    if (!m_app->appMemory->unlock())
    {
        qDebug() << "TpApplication: Unable to unlock memory at the end of execution.";
        qDebug() << m_app->appMemory->errorString();
    }

    m_app->connectToPrimary(timeout, TpSingleApplication::ConnectionType::NewInstance);

    ::exit(0);
}

TpApplication::~TpApplication()
{
    delete m_app;
}

bool TpApplication::isPrimary() const
{
    return m_app->appServer != nullptr;
}

bool TpApplication::isSecondary() const
{
    return m_app->appServer == nullptr;
}

quint32 TpApplication::instanceId() const
{
    return m_app->appInstanceNumber;
}

qint64 TpApplication::primaryPid() const
{
    return m_app->primaryPid();
}

QString TpApplication::primaryUser() const
{
    return m_app->primaryUser();
}

QString TpApplication::currentUser() const
{
    return TpSingleApplication::getUsername();
}

QStringList TpApplication::userData() const
{
    return m_app->appData();
}

bool TpApplication::sendMessage(QString message, int timeout, TpApplication::SendMode sendMode)
{
    return sendMessage(message.toUtf8(), timeout, sendMode);
}

bool TpApplication::sendMessage(const QByteArray &message, int timeout, TpApplication::SendMode sendMode)
{
    if (isPrimary())
        return false;

    if (!m_app->connectToPrimary(timeout, TpSingleApplication::ConnectionType::Reconnect))
        return false;

    return m_app->writeConfirmedMessage(timeout, message, sendMode);
}

void TpApplication::abortSafely()
{
    qCritical() << "TpApplication: " << m_app->appMemory->error() << m_app->appMemory->errorString();
    ::exit(1);
}

TP_END_NAMESPACE
