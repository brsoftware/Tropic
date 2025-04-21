#include <QApplication>
#include <QClipboard>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QHeaderView>
#include <QMimeData>
#include <QMouseEvent>

#include <Dialogs/TpMessageCritical>
#include <Utilities/TpFileSystemAssistants>
#include <Utilities/TpOpenAssistant>
#include <Views/TpFileView>
#include <TpGeneralAction>
#include <TpGeneralMenu>
#include <TpMainWindow>

TP_NAMESPACE

TpFileView::TpFileView(TpMainWindow *parent)
    : QTreeView(parent),
    m_parent(parent)
{
    setAcceptDrops(true);
    setAllColumnsShowFocus(true);
    setAlternatingRowColors(false);
    setAnimated(true);
    setAutoExpandDelay(250);
    setAutoScroll(true);
    setAutoScrollMargin(16);
    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    setDefaultDropAction(Qt::DropAction::MoveAction);
    setDragEnabled(true);
    setEditTriggers(SelectedClicked | EditKeyPressed);
    setEnabled(true);
    setExpandsOnDoubleClick(true);
    setHeaderHidden(false);
    setHidden(false);
    setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
    setObjectName("fileView");
    setSelectionBehavior(SelectRows);
    setSelectionMode(SingleSelection);
    setUniformRowHeights(true);
    setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);

    header()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents);

    m_model = new TpFileModel(this);
    setModel(m_model);

    connect(this,
            &TpFileView::customContextMenuRequested,
            this,
            &TpFileView::onCustomContextMenuRequested);
}

TpFileModel *TpFileView::fileModel() const
{
    return m_model;
}

void TpFileView::onCustomContextMenuRequested(const QPoint &point)
{
#ifndef QT_NO_CONTEXTMENU

    const QModelIndex &index = indexAt(point);
    bool isDir = m_model->isDir(index);
    const QString &path = m_model->filePath(index);

    bool entity = (path != "");

    TpGeneralMenu *menu = new TpGeneralMenu(this, "&File System View");
    TpGeneralAction *newFile =
        new TpGeneralAction(menu, (isDir ? tr("&New File...") : tr("&New File Here...")), QKeySequence(), entity);
    TpGeneralAction *newFolder =
        new TpGeneralAction(menu, (isDir ? tr("New &Folder...") : tr("New &Folder Here...")), QKeySequence(), entity);

    connect(newFile,
            &QAction::triggered,
            this,
    [=, this](bool) {
        QFileInfo fileInfo = m_model->fileInfo(index);
        QDir dir{fileInfo.absoluteDir()};

        if (m_model->isDir(index))
        {
            dir.setPath(path);
            expand(index);
        }

        if (m_model->fileName(index).isEmpty())
            dir.setPath(m_model->filePath(rootIndex()));

        QString absDir = QDir::toNativeSeparators(dir.absolutePath() + "/");
        QStringList entryList = dir.entryList(QStringList() << "Untitled*", QDir::Filter::Files);
        int highestNumber = 0;
        static QRegularExpression regex("Untitled (\\d+)\\.txt");

        for (const auto &entry : std::as_const(entryList))
        {
            QRegularExpressionMatch match = regex.match(entry);

            if (match.hasMatch())
            {
                bool ok;
                int queryNumber = match.captured(1).toInt(&ok);

                if (ok && queryNumber > highestNumber)
                    highestNumber = queryNumber;
            }
        }

        QString fileName = QString("Untitled %1.txt").arg(highestNumber + 1);
        QFile file(absDir + fileName);
        file.open(QFile::OpenModeFlag::WriteOnly);
        file.close();

        QModelIndex appended = m_model->index(absDir + fileName);
        edit(appended);
    });

    connect(newFolder,
            &QAction::triggered,
            this,
    [=, this](bool) {
        QFileInfo fileInfo = m_model->fileInfo(index);
        QDir dir{fileInfo.absoluteDir()};

        if (m_model->isDir(index))
        {
            dir.setPath(path);
            expand(index);
        }

        if (m_model->fileName(index).isEmpty())
            dir.setPath(m_model->filePath(rootIndex()));

        QString absDir = QDir::toNativeSeparators(dir.absolutePath() + "/");
        QStringList entryList = dir.entryList(QStringList() << "Untitled*", QDir::Filter::Dirs);
        int highestNumber = 0;
        static QRegularExpression regex("Untitled (\\d+)");

        for (const auto &entry : std::as_const(entryList))
        {
            QRegularExpressionMatch match = regex.match(entry);

            if (match.hasMatch())
            {
                bool ok;
                int queryNumber = match.captured(1).toInt(&ok);

                if (ok && queryNumber > highestNumber)
                    highestNumber = queryNumber;
            }
        }

        QString folderName = QString("Untitled %1").arg(highestNumber + 1);
        dir.mkdir(folderName);

        QModelIndex appended = m_model->index(absDir + folderName);
        edit(appended);
    });

    if (m_model->fileInfo(index).isFile())
    {
        menu->addSeparator();

        TpGeneralAction *open = new TpGeneralAction(menu, tr("&Open..."), QKeySequence(), entity);
        TpGeneralAction *viewer = new TpGeneralAction(menu, tr("Review In &Default Viewer..."), QKeySequence(), entity);

        connect(open,
                &QAction::triggered,
                this,
        [=, this](bool){
            TpOpenAssistant *assistant = new TpOpenAssistant(m_parent);
            assistant->openFile(path);
        });

        connect(viewer,
                &QAction::triggered,
                this,
        [=, this](bool){
            revealInDefaultViewer(path);
        });
    }

    menu->addSeparator();

    TpGeneralAction *explorer = new TpGeneralAction(menu, tr("&Reveal In File Explorer..."), QKeySequence(), entity);
    TpGeneralAction *cmd = new TpGeneralAction(menu, tr("Open In &Command Line Interface..."), QKeySequence(), entity);

    menu->addSeparator();

    TpGeneralAction *absPath = new TpGeneralAction(menu, tr("Copy &Absolute Path"), QKeySequence(), entity);
    TpGeneralAction *name =
        new TpGeneralAction(menu, tr(isDir ? "Cop&y Folder Name" : "Cop&y File Name"), QKeySequence(), entity);
    TpGeneralAction *dir = new TpGeneralAction(menu, tr("Copy D&irectory Name"), QKeySequence(), entity);

    connect(explorer,
            &QAction::triggered,
            this,
    [=, this](bool){
        QString dir = path;
        if (m_model->filePath(index).isEmpty())
            dir = m_model->filePath(rootIndex());
        revealInExplorer(dir);
    });

    connect(cmd,
            &QAction::triggered,
            this,
    [=, this](bool){
        QString dir = path;
        if (m_model->filePath(index).isEmpty())
            dir = m_model->filePath(rootIndex());
        openInCMD(dir);
    });

    connect(absPath,
            &QAction::triggered,
            this,
            [=, this](bool){
        QString dir = path;
        if (m_model->filePath(index).isEmpty())
            dir = m_model->filePath(rootIndex());
        QClipboard *clipboard = qApp->clipboard();
        clipboard->setText(dir, QClipboard::Mode::Clipboard);
    });

    connect(name,
            &QAction::triggered,
            this,
    [=, this](bool){
        QString dir = m_model->fileName(index);
        if (m_model->filePath(index).isEmpty())
            dir = m_model->filePath(rootIndex());
        QClipboard *clipboard = qApp->clipboard();
        clipboard->setText(dir, QClipboard::Mode::Clipboard);
    });

    connect(dir,
            &QAction::triggered,
            this,
            [=, this](bool){
        QString dir = QFileInfo(QFile(path)).path();
        if (m_model->filePath(index).isEmpty())
            dir = QFileInfo(QFile(m_model->filePath(rootIndex()))).path();
        QClipboard *clipboard = qApp->clipboard();
        clipboard->setText(dir, QClipboard::Mode::Clipboard);
    });

    if (!m_model->filePath(index).isEmpty())
    {
        menu->addSeparator();

        TpGeneralAction *rename = new TpGeneralAction(menu, tr("R&ename"), QKeySequence(), entity);
        TpGeneralAction *del = new TpGeneralAction(menu, tr("De&lete"), QKeySequence(), entity);

        connect(rename,
                &QAction::triggered,
                this,
        [=, this](bool){
            edit(index);
        });

        connect(del,
                &QAction::triggered,
                this,
        [=, this](bool){
            QFile file(path);

            if (!file.moveToTrash())
            {
                TpMessageCritical *critical = new TpMessageCritical(m_parent);
                critical->say(
                    tr("File Error"),
                    tr("The file of the following file path could not be opened: '%1'").arg(path),
                    tr(fileErrorReason(file.error()))
                );
            }
        });
    }

    menu->exec(mapToGlobal(point));

#endif
}

void TpFileView::dragEnterEvent(QDragEnterEvent *event)
{
    const QMimeData *mimeData = event->mimeData();

    if (mimeData->hasUrls())
        event->acceptProposedAction();

    QTreeView::dragEnterEvent(event);
}

void TpFileView::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();

    if (mimeData->hasUrls())
    {
        QStringList pathList;
        QList<QUrl> urlList = mimeData->urls();

        for (const auto &urlListItem : std::as_const(urlList))
            pathList.append(urlListItem.toLocalFile());

        for (const auto &pathListItem : std::as_const(pathList))
        {
            QFile file(pathListItem);
            QFileInfo fileInfo(file);

            if (!(fileInfo.isFile()))
            {
                m_model->setRootPath(QDir::rootPath());
                const QModelIndex &index = m_model->index(pathListItem);
                setRootIndex(index);
            }
        }
    }

    QTreeView::dropEvent(event);
}

void TpFileView::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::LeftButton)
    {
        const QModelIndex &index = indexAt(event->pos());

        if (m_model->isDir(index))
        {
            if (isExpanded(index))
                collapse(index);
            else
                expand(index);
        }

        else
        {
            const QString &path = m_model->filePath(index);
            emit fileDoubleClicked(path);
        }
    }

    QTreeView::mouseDoubleClickEvent(event);
}

TP_END_NAMESPACE
