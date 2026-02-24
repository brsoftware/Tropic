#ifndef TPSETTINGSVIEW_H
#define TPSETTINGSVIEW_H

#include <QIcon>
#include <QTimer>
#include <QTreeWidget>

#include <Models/TpSettingsItem>
#include <Models/TpVariantDelegate>

TP_NAMESPACE

class TpSettingsView : public QTreeWidget
{
    Q_OBJECT

public:
    TpSettingsView(QWidget *parent = nullptr);
    ~TpSettingsView() = default;

public:
    void setSettings(const TpSettingsPtr &settings);
    QSize sizeHint() const override;

public slots:
    void setAutoRefresh(bool autoRefesh);
    void setFallbacks(bool enabled);
    void refreshLater();
    void refresh();
    void revertModelValues();

protected:
    bool event(QEvent *event) override;

private:
    void updateChildItems(TpSettingsItem *parent);
    TpSettingsItem *create(const QString &text, TpSettingsItem *parent, int index);
    TpSettingsItem *childAt(TpSettingsItem *parent, int index) const;
    int childrenCount(TpSettingsItem *parent) const;
    int findChild(TpSettingsItem *parent, const QString &text, int start) const;
    void moveForward(TpSettingsItem *parent, int oldIndex, int newIndex);

private slots:
    void updateSettings(TpSettingsItem *item);

private:
    TpSettingsPtr m_settings;
    TpTypeCheckerPtr m_checker;
    QTimer m_refreshTimer;
    QIcon m_groupIcon;
    QIcon m_keyIcon;
    bool m_autoRefresh = true;
    TpVariantDelegate *m_delegate;
};

TP_END_NAMESPACE

#endif // TPSETTINGSVIEW_H
