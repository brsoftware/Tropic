#include <QMenu>

#include <TpGeneralAction>

TP_NAMESPACE

TpGeneralAction::
    TpGeneralAction(QMenu *parent, QString content, QKeySequence::StandardKey shortcut, bool enabled, bool checkable,
                    bool checked)
    : QAction(parent),
    m_parent(parent)
{
    initialize(content, QKeySequence(shortcut), enabled, checkable, checked);
}

TpGeneralAction::
    TpGeneralAction(QMenu *parent, QString content, QKeySequence shortcut, bool enabled, bool checkable, bool checked)
    : QAction(parent),
    m_parent(parent)
{
    initialize(content, shortcut, enabled, checkable, checked);
}

TpGeneralAction::TpGeneralAction(QToolBar *parent, QString content, QKeySequence shortcut)
{
    const QString &contents = content;

    QString bareContentWithDot = content.replace("&", "");
    QString bareContentWithSpace = bareContentWithDot.replace("...", "");
    QString bareContent = bareContentWithSpace.replace(" ", "");

    setActionGroup(nullptr);
    setAutoRepeat(false);
    setCheckable(false);
    setChecked(false);
    setDisabled(!false);
    setEnabled(true);
    setIcon(QIcon());
    setIconText(bareContentWithSpace);
    setIconVisibleInMenu(false);
    setMenuRole(NoRole);
    setObjectName(parent->objectName() + "_" + bareContent);
    setParent(parent);
    setPriority(NormalPriority);
    setSeparator(false);
    setShortcut(shortcut);
    setShortcutContext(Qt::ShortcutContext::WindowShortcut);
    setShortcutVisibleInContextMenu(false);
    setStatusTip("");
    setText(contents);
    setToolTip(bareContentWithDot);
    setVisible(true);
    setWhatsThis("");

    parent->addAction(this);
}

void TpGeneralAction::initialize(QString content, QKeySequence shortcut, bool enabled, bool checkable, bool checked)
{
    const QString &contents = content;

    QString bareContentWithDot = content.replace("&", "");
    QString bareContentWithSpace = bareContentWithDot.replace("...", "");
    QString bareContent = bareContentWithSpace.replace(" ", "");

    setActionGroup(nullptr);
    setAutoRepeat(false);
    setCheckable(checkable);
    setChecked(checked);
    setDisabled(!enabled);
    setEnabled(enabled);
    setIcon(QIcon());
    setIconText(bareContentWithSpace);
    setIconVisibleInMenu(false);
    setMenuRole(NoRole);
    setObjectName(m_parent->objectName() + "_" + bareContent);
    setParent(m_parent);
    setPriority(NormalPriority);
    setSeparator(false);
    setShortcut(shortcut);
    setShortcutContext(Qt::ShortcutContext::WindowShortcut);
    setShortcutVisibleInContextMenu(false);
    setStatusTip("");
    setText(contents);
    setToolTip(bareContentWithDot);
    setVisible(true);
    setWhatsThis("");

    m_parent->addAction(this);
}

TP_END_NAMESPACE
