#include <Dialogs/TpDialogGoto>
#include <TpEditor>
#include <TpMainWindow>
#include <TpTabSplitter>
#include <TpTabWidget>

TP_NAMESPACE

TpDialogGoto::TpDialogGoto(TpMainWindow *parent)
    : QDialog(parent),
    m_parent(parent),
    m_currentMode(Line)
{
    setWindowModality(Qt::WindowModality::WindowModal);
    setWindowTitle(tr("Go To - Tropic"));

    m_mainLayout = new QVBoxLayout();
    m_mainLayout->setObjectName("gotoDialog_mainLayout");
    setLayout(m_mainLayout);
    m_editLayout = new QFormLayout();
    m_editLayout->setObjectName("gotoDialog_editLayout");
    m_mainLayout->addLayout(m_editLayout);
    m_groupBox = new QGroupBox(this);
    m_groupBox->setCheckable(false);
    m_groupBox->setChecked(false);
    m_groupBox->setObjectName("gotoDialog_groupBox");
    m_groupBox->setTitle(tr("Mode"));
    m_groupBoxLayout = new QHBoxLayout();
    m_groupBox->setLayout(m_groupBoxLayout);
    m_mainLayout->addWidget(m_groupBox);
    m_radioLine = new QRadioButton(m_groupBox);
    m_radioLine->setText(tr("&Line"));
    m_radioLine->setChecked(true);
    m_radioLine->setObjectName("gotoDialog_radioLine");
    m_groupBoxLayout->addWidget(m_radioLine);
    m_radioPosition = new QRadioButton(m_groupBox);
    m_radioPosition->setText(tr("&Position"));
    m_radioPosition->setChecked(false);
    m_radioPosition->setObjectName("gotoDialog_radioPosition");
    m_groupBoxLayout->addWidget(m_radioPosition);
    m_editLabel = new QLabel(this);
    m_editLabel->setText(tr("&Go To:"));
    m_edit = new QSpinBox(this);
    m_edit->setMinimum(1);
    m_editLabel->setBuddy(m_edit);
    m_editLayout->addRow(m_editLabel, m_edit);
    m_box = new QDialogButtonBox(this);
    m_box->setObjectName("gotoDialog_box");
    m_buttonGoto = new QPushButton(m_box);
    m_buttonGoto->setText(tr("&Go To"));
    m_buttonGoto->setObjectName("gotoDialog_buttonGoto");
    m_box->addButton(m_buttonGoto, QDialogButtonBox::ButtonRole::AcceptRole);
    m_buttonClose = new QPushButton(m_box);
    m_buttonClose->setText(tr("&Close"));
    m_buttonClose->setObjectName("gotoDialog_buttonClose");
    m_box->addButton(m_buttonClose, QDialogButtonBox::ButtonRole::RejectRole);
    m_mainLayout->addWidget(m_box);

    connect(m_radioLine,
            &QRadioButton::clicked,
            this,
            &TpDialogGoto::onRadioLineToggled);
    connect(m_radioPosition,
            &QRadioButton::clicked,
            this,
            &TpDialogGoto::onRadioPositionToggled);
    connect(m_buttonGoto,
            &QPushButton::clicked,
            this,
            &TpDialogGoto::onButtonGotoClicked);
    connect(m_buttonClose,
            &QPushButton::clicked,
            this,
            &TpDialogGoto::onButtonCloseClicked);

    onRadioLineToggled(true);
}

void TpDialogGoto::onRadioLineToggled(bool)
{
    if (!m_parent->m_widget->tabs()->tab()->hasTab())
    {
        close();
        return;
    }

    m_currentMode = Line;
    m_edit->setMinimum(1);
    m_edit->setMaximum(m_parent->m_widget->tabs()->tab()->tab()->lines());
    m_edit->setValue(m_parent->m_widget->tabs()->tab()->tab()->currentLine());
}

void TpDialogGoto::onRadioPositionToggled(bool)
{
    if (!m_parent->m_widget->tabs()->tab()->hasTab())
    {
        close();
        return;
    }

    m_currentMode = Position;
    m_edit->setMinimum(0);
    m_edit->setMaximum(static_cast<int>(m_parent->m_widget->tabs()->tab()->tab()->text().length()));
    m_edit->setValue(m_parent->m_widget->tabs()->tab()->tab()->getPosition());
}

void TpDialogGoto::onButtonGotoClicked(bool)
{
    TpEditor *editor = m_parent->m_widget->tabs()->tab()->tab();

    if (!editor)
    {
        close();
        return;
    }

    if (m_currentMode == Line)
    {
        editor->SendScintilla(TpEditor::SCI_SETCURRENTPOS, editor->positionFromLineIndex(m_edit->value() - 1, 0));
    }

    else
    {
        editor->SendScintilla(TpEditor::SCI_SETCURRENTPOS, m_edit->value());
    }

    editor->selectAll(false);

    close();
}

void TpDialogGoto::onButtonCloseClicked(bool)
{
    close();
}

TP_END_NAMESPACE
