#ifndef TPFINDINFILESCONTAINER_H
#define TPFINDINFILESCONTAINER_H

#include <QCheckBox>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QToolBox>
#include <QTreeWidget>
#include <QVBoxLayout>

#include <Models/TpHtmlDelegate>
#include <Widgets/TpGeneralLineEdit>

TP_NAMESPACE

class TpFindInFilesContainer : public QWidget
{
    Q_OBJECT

    enum TreeWidgetItemDataRole
    {
        PositionRole = Qt::ItemDataRole::UserRole + 1,
        FilePathRole = Qt::ItemDataRole::UserRole + 2,
        RegexRole = Qt::ItemDataRole::UserRole + 3,
    };

public:
    TpFindInFilesContainer(QWidget *parent);

signals:
    void resultClicked(const QString &directory, int position);

protected:
    bool eventFilter(QObject *object, QEvent *event) override;

private:
    static int findLineNumber(QString str, int index);

private slots:
    void onFindClicked();
    void onReplaceClicked();
    void onClearFilterClicked();
    void onTreeWidgetDoubleClicked(QTreeWidgetItem *item, int column);

private:
    QVBoxLayout *m_layout;
    QFormLayout *m_findLayout;
    QLabel *m_findLabel;
    TpGeneralLineEdit *m_findEdit;
    QLabel *m_replaceLabel;
    TpGeneralLineEdit *m_replaceEdit;
    QToolBox *m_toolBox;
    QGroupBox *m_groupBox;
    QVBoxLayout *m_groupBoxLayout;
    QGroupBox *m_groupBoxRegex;
    QHBoxLayout *m_groupBoxRegexLayout;
    QGroupBox *m_groupBoxRegexOptions;
    QGridLayout *m_groupBoxRegexOptionsLayout;
    QCheckBox *m_checkRegexCaseInsensitive;
    QCheckBox *m_checkRegexMatchNewlines;
    QCheckBox *m_checkRegexMultiline;
    QCheckBox *m_checkRegexExtendedSyntax;
    QCheckBox *m_checkRegexInvertedGreediness;
    QCheckBox *m_checkRegexDontCapture;
    QCheckBox *m_checkRegexUnicode;
    QCheckBox *m_checkRegexAnchoredAtOffset;
    QGroupBox *m_groupBoxRegexType;
    QGridLayout *m_groupBoxRegexTypeLayout;
    QRadioButton *m_checkRegexNormal;
    QRadioButton *m_checkRegexPartialComplete;
    QRadioButton *m_checkRegexPartialFirst;
    QCheckBox *m_checkSubDirectories;
    QGroupBox *m_groupBoxDir;
    QFormLayout *m_groupBoxDirLayout;
    QLabel *m_dirNameLabel;
    TpGeneralLineEdit *m_dirNameEdit;
    QLabel *m_dirFilterLabel;
    QComboBox *m_dirFilterEdit;
    QDialogButtonBox *m_buttonBox;
    QPushButton *m_buttonFind;
    QPushButton *m_buttonReplace;
    QPushButton *m_buttonClearFilter;
    QTreeWidget *m_treeWidget;
    QLabel *m_errorLabel;
    QLabel *m_infoLabel;

private:
    TpHtmlDelegate *m_delegate;
};

TP_END_NAMESPACE

#endif // TPFINDINFILESCONTAINER_H
