#ifndef TPSETTINGSPAGE_H
#define TPSETTINGSPAGE_H

#include <functional>

#include <QFormLayout>
#include <QScrollArea>
#include <QStackedWidget>
#include <QVBoxLayout>

#include <TpGlobals>

TP_NAMESPACE

class TpEditor;
class TpSettingsStack;

class TpSettingsPage : public QWidget
{
    Q_OBJECT

    friend class TpDialogSettings;

    DEF_PROP(QString, name);

public:
    enum Type
    {
        Page,
        Form,
    };
    Q_ENUM(Type)

public:
    TpSettingsPage(Type type, TpSettingsStack *parent);

public:
    Type type() const;
    DEF_PROP_FUNC(QString, name, Name)

    void addEntry(QWidget *entry);
    void addEntry(QString key, QMetaType::Type type, QVariant defaultValue = QVariant());
    QVariant entry(QString key) const;

    void setEditorAcceptor(std::function<void(TpEditor*)> func);
    void setAcceptor(std::function<void()> func);
    void setEditorRejector(std::function<void(TpEditor*)> func);
    void setRejector(std::function<void()> func);

private:
    QVBoxLayout *m_layout;
    QScrollArea *m_formWidget;
    QWidget *m_formContainer;
    QFormLayout *m_formLayout;
    Type m_type;
    TpSettingsStack *m_parent;

    QMap<QString, QWidget*> m_editors;

    std::function<void(TpEditor*)> m_edAcceptor = [](TpEditor*){};
    std::function<void()> m_acceptor = [](){};
    std::function<void(TpEditor*)> m_edRejector = [](TpEditor*){};
    std::function<void()> m_rejector = [](){};
};

TP_END_NAMESPACE

#endif // TPSETTINGSPAGE_H
