#ifndef TPDIALOGCHARACTER_H
#define TPDIALOGCHARACTER_H

#include <QDialog>

#include <TpGlobals>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QClipboard;
class QComboBox;
class QDialogButtonBox;
class QFontComboBox;
class QFormLayout;
class QLabel;
class QLineEdit;
class QScrollArea;
class QVBoxLayout;
QT_END_NAMESPACE

TP_NAMESPACE

class TpCharacterWidget;
class TpMainWindow;

class TpDialogCharacter : public QDialog
{
    Q_OBJECT

public:
    TpDialogCharacter(TpMainWindow *parent);

public slots:
    void onFilterChanged(int filter);
    void onFindStyles(const QFont &font);
    void onFindSizes(const QFont &font);
    void onInsertCharacter(const QString &character);
    void onInsertButtonClicked(bool);
#ifndef QT_NO_CLIPBOARD
    void updateClipboard();
#endif

private:
    TpMainWindow *m_parent;
    QVBoxLayout *m_layout;
    QFormLayout *m_formLayout;
    QLabel *m_label_Filter;
    QComboBox *m_comboBox_Filter;
    QLabel *m_label_Style;
    QComboBox *m_comboBox_Style;
    QLabel *m_label_Size;
    QComboBox *m_comboBox_Size;
    QLabel *m_label_Font;
    QFontComboBox *m_comboBox_Font;
    QCheckBox *m_check_Merge;
    QScrollArea *m_scrollArea;
    TpCharacterWidget *m_widget;
    QLineEdit *m_buffer;
    QDialogButtonBox *m_buttonBox;
    QPushButton *m_button_Insert;
    QPushButton *m_button_Clipboard;
    QPushButton *m_button_Cancel;
};

TP_END_NAMESPACE

#endif // TPDIALOGCHARACTER_H
