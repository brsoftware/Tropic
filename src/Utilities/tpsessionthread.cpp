#include <Utilities/TpSessionThread>
#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpSessionThread::TpSessionThread(TpMainWindow *parent)
    : QThread(parent),
    m_parent(parent)
{}

void TpSessionThread::run()
{
    DEF_SETTINGS;

    QMap<QString, QVariant> map = qvariant_cast<QMap<QString, QVariant>>(settings.value("App/Editors"));
    QMap<QString, QVariant> settingsMap = qvariant_cast<QMap<QString, QVariant>>(settings.value("App/EditorSettings"));

    for (int index = 0; index < m_parent->m_widget->tabs()->m_tabs.count(); index++)
    {
        TpTabWidget *t = m_parent->m_widget->tabs()->m_tabs.at(index);
        if (!t)
            continue;

        for (int idx = 0; idx < t->count(); idx++)
        {
            if (TpEditor *editor = t->tabAt(idx))
            {
                if (editor->text().size() <= INT_MAX)
                    map[(editor->filePath() == "") ? tr("Untitled %1").arg(editor->m_untitled) : editor->filePath()] =
                        editor->text();
                settingsMap[(editor->filePath() == "")
                    ? tr("Untitled %1").arg(editor->m_untitled) : editor->filePath()] = editor->toMap();
            }
        }
    }

    SET_SETTINGS("App/Editors", map);
    SET_SETTINGS("App/EditorSettings", settingsMap);
}

TP_END_NAMESPACE
