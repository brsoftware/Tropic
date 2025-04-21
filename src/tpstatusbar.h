#ifndef TPSTATUSBAR_H
#define TPSTATUSBAR_H

#include <QLabel>
#include <QSpinBox>
#include <QStatusBar>

#include <TpGlobals>

TP_NAMESPACE

class TpGeneralComboBox;
class TpMainWindow;

class TpStatusBar : public QStatusBar
{
    Q_OBJECT

    friend class TpMainWindow;

public:
    TpStatusBar(TpMainWindow *parent);

public:
    void updateAccessibility(bool h);

public:
    QList<QString> comboBoxLangItems;
    QMap<QString, Languages> languagesMap;
    QMap<Languages, QString> iteratedLangMap;
    QList<QString> comboBoxNewLineItems;

private:
    // [[Label]] Basic Statistics
    // [[Label]] Position
    // [[Label]] Line and Column
    // [[Spin Box]] Tab Width
    // [[Combo Box]] Languages
    // [[Combo Box]] New Line
    QLabel *m_labelStats;
    QLabel *m_labelPosition;
    QLabel *m_labelLineAndColumn;
    QSpinBox *m_spinBoxTabWidth;
    TpGeneralComboBox *m_comboBoxLang;
    TpGeneralComboBox *m_comboBoxNewLine;

private:
    TpMainWindow *m_parent;
};

TP_END_NAMESPACE

#endif // TPSTATUSBAR_H
