#ifndef TPFINDCONTAINER_H
#define TPFINDCONTAINER_H

#include <QCheckBox>
#include <QDialogButtonBox>
#include <QDockWidget>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>

#include <Widgets/TpGeneralLineEdit>
#include <TpEditor>

TP_NAMESPACE

class TpMainWindow;

class TpFindContainer : public QWidget
{
    Q_OBJECT

    friend class TpMainWindow;
    friend class TpMenuBar;

public:
    typedef enum
    {
        NoFlags = 0,
        SimpleRegex = 1,
        PosixRegex = 2,
        CppRegex = 4,
        CaseSensitive = 8,
        WholeWord = 16,
        WordWrap = 32,
        Previous = 64,
        ShowText = 128
    } Option;
    Q_DECLARE_FLAGS(Options, Option)

public:
    TpFindContainer(TpEditor *editor);

signals:
    void checkBoxChecked(bool isChceked);

public slots:
    void onCheckSelectionClicked(bool isChecked);
    bool onFindButtonClicked(bool);
    bool onReplaceButtonClicked(bool);
    bool onReplaceAllButtonClicked(bool);

public:
    void clearFindIndicators();
    bool isStartIndicator() const;
    bool isOnIndicator(int position) const;

    Options optionsFlag() const;
    void setOptions(Options options);

private:
    enum
    {
        Situation0,
        Situation1,
        Situation2,
        Situation3,
    };

private:
    QVBoxLayout *m_mainLayout;
    QWidget *m_widget;
    QFormLayout *m_widgetLayout;
    TpGeneralLineEdit *m_findEdit;
    QLabel *m_findLabel;
    TpGeneralLineEdit *m_replaceEdit;
    QLabel *m_replaceLabel;
    QGroupBox *m_options;
    QGridLayout *m_optionsLayout;
    QCheckBox *m_checkSimpleRegex;
    QCheckBox *m_checkPosixRegex;
    QCheckBox *m_checkCppRegex;
    QCheckBox *m_checkCase;
    QCheckBox *m_checkWord;
    QCheckBox *m_checkWrap;
    QCheckBox *m_checkShow;
    QCheckBox *m_checkSelection;
    QCheckBox *m_checkPrevious;
    QDialogButtonBox *m_buttonBox;
    QPushButton *m_findButton;
    QPushButton *m_replaceButton;
    QPushButton *m_replaceAllButton;

    TpEditor *m_editor;
    int m_indicator;

    QButtonGroup *m_buttonGroupRegex;

private:
    QMap<Option, bool> m_config;
    QString m_text;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(TpFindContainer::Options)

TP_END_NAMESPACE

#endif // TPFINDCONTAINER_H
