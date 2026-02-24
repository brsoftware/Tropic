#include <QApplication>
#include <QBoxLayout>
#include <QCheckBox>
#include <QClipboard>
#include <QDialogButtonBox>
#include <QFontComboBox>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QTextStream>

#include <Dialogs/TpDialogCharacter>
#include <Widgets/TpCharacterWidget>
#include <TpMainWindow>
#include <TpEditor>
#include <TpTabSplitter>
#include <TpTabWidget>

Q_DECLARE_METATYPE(QFontComboBox::FontFilter)

TP_NAMESPACE

TpDialogCharacter::TpDialogCharacter(TpMainWindow *parent)
    : QDialog(parent),
    m_parent(parent)
{
    setWindowModality(Qt::WindowModality::WindowModal);
    setWindowTitle(tr("Other Special Characters - Tropic"));

    m_layout = new QVBoxLayout();
    setLayout(m_layout);
    m_formLayout = new QFormLayout();
    m_layout->addLayout(m_formLayout);
    m_label_Filter = new QLabel(this);
    m_label_Filter->setObjectName("charDialog_Label_Filter");
    m_label_Filter->setText(tr("&Filter:"));
    m_comboBox_Filter = new QComboBox(this);
    m_comboBox_Filter->setObjectName("charDialog_ComboBox_Filter");
    m_comboBox_Filter->addItem(tr("All"), QVariant::fromValue(QFontComboBox::FontFilter::AllFonts));
    m_comboBox_Filter->addItem(tr("Scalable"), QVariant::fromValue(QFontComboBox::FontFilter::ScalableFonts));
    m_comboBox_Filter->addItem(tr("Monospace"), QVariant::fromValue(QFontComboBox::FontFilter::MonospacedFonts));
    m_comboBox_Filter->addItem(tr("Proportional"), QVariant::fromValue(QFontComboBox::FontFilter::ProportionalFonts));
    m_comboBox_Filter->setCurrentIndex(0);
    m_label_Filter->setBuddy(m_comboBox_Filter);
    m_formLayout->addRow(m_label_Filter, m_comboBox_Filter);
    m_label_Font = new QLabel(this);
    m_label_Font->setObjectName("charDialog_Label_Font");
    m_label_Font->setText(tr("F&ont:"));
    m_comboBox_Font = new QFontComboBox(this);
    m_comboBox_Font->setObjectName("charDialog_ComboBox_Font");
    m_label_Font->setBuddy(m_comboBox_Font);
    m_formLayout->addRow(m_label_Font, m_comboBox_Font);
    m_label_Size = new QLabel(this);
    m_label_Size->setObjectName("charDialog_Label_Size");
    m_label_Size->setText(tr("&Size:"));
    m_comboBox_Size = new QComboBox(this);
    m_comboBox_Size->setObjectName("charDialog_Label_Size");
    m_label_Size->setBuddy(m_comboBox_Size);
    m_formLayout->addRow(m_label_Size, m_comboBox_Size);
    m_label_Style = new QLabel(this);
    m_label_Style->setObjectName("charDialog_Label_Style");
    m_label_Style->setText(tr("St&yle"));
    m_comboBox_Style = new QComboBox(this);
    m_comboBox_Style->setObjectName("charDialog_ComboBox_Style");
    m_label_Style->setBuddy(m_comboBox_Style);
    m_formLayout->addRow(m_label_Style, m_comboBox_Style);
    m_check_Merge = new QCheckBox(this);
    m_check_Merge->setChecked(true);
    m_check_Merge->setObjectName("charDialog_Check_Merge");
    m_check_Merge->setText(tr("Merge Font Automatically"));
    m_formLayout->addWidget(m_check_Merge);
    m_scrollArea = new QScrollArea(this);
    m_scrollArea->setObjectName("charDialog_ScrollArea");
    m_widget = new TpCharacterWidget(this);
    m_scrollArea->setWidget(m_widget);
    m_layout->addWidget(m_scrollArea);
    onFindStyles(m_comboBox_Font->currentFont());
    onFindSizes(m_comboBox_Font->currentFont());
    m_buffer = new QLineEdit(this);
    m_buffer->setObjectName("charDialog_Buffer");
    m_buffer->setClearButtonEnabled(true);
    m_layout->addWidget(m_buffer);
    m_buttonBox = new QDialogButtonBox(this);
    m_buttonBox->setObjectName("charDialog_ButtonBox");
    m_button_Insert = new QPushButton(this);
    m_button_Insert->setObjectName("charDialog_Button_Insert");
    m_button_Insert->setText("&Insert");
    m_buttonBox->addButton(m_button_Insert, QDialogButtonBox::ButtonRole::AcceptRole);
    m_button_Clipboard = new QPushButton(this);
    m_button_Clipboard->setObjectName("charDialog_Button_Clipboard");
    m_button_Clipboard->setText("To Clip&board");
    m_buttonBox->addButton(m_button_Clipboard, QDialogButtonBox::ButtonRole::ActionRole);
    m_button_Cancel = new QPushButton(this);
    m_button_Cancel->setObjectName("charDialog_Button_Cancel");
    m_button_Cancel->setText("Cance&l");
    m_buttonBox->addButton(m_button_Cancel, QDialogButtonBox::ButtonRole::RejectRole);
    m_layout->addWidget(m_buttonBox);

    connect(m_comboBox_Filter,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            &TpDialogCharacter::onFilterChanged);
    connect(m_comboBox_Font,
            &QFontComboBox::currentFontChanged,
            this,
            &TpDialogCharacter::onFindStyles);
    connect(m_comboBox_Font,
            &QFontComboBox::currentFontChanged,
            this,
            &TpDialogCharacter::onFindSizes);
    connect(m_comboBox_Font,
            &QFontComboBox::currentFontChanged,
            m_widget,
            &TpCharacterWidget::redrawUsing);
    connect(m_comboBox_Size,
            &QComboBox::currentTextChanged,
            m_widget,
            &TpCharacterWidget::redrawUsingSize);
    connect(m_comboBox_Style,
            &QComboBox::currentTextChanged,
            m_widget,
            &TpCharacterWidget::redrawUsingStyle);
    connect(m_widget,
            &TpCharacterWidget::characterSelected,
            this,
            &TpDialogCharacter::onInsertCharacter);
#ifndef QT_NO_CLIPBOARD
    connect(m_button_Clipboard,
            &QPushButton::clicked,
            this,
            &TpDialogCharacter::updateClipboard);
#endif
    connect(m_check_Merge,
            &QCheckBox::toggled,
            m_widget,
            &TpCharacterWidget::redrawMerged);
    connect(m_button_Insert,
            &QPushButton::clicked,
            this,
            &TpDialogCharacter::onInsertButtonClicked);
    connect(m_button_Cancel,
            &QPushButton::clicked,
            this,
            &TpDialogCharacter::close);
}

void TpDialogCharacter::onFindStyles(const QFont &font)
{
    QString currentItem = m_comboBox_Style->currentText();
    m_comboBox_Style->clear();
    const QStringList styles = QFontDatabase::styles(font.family());
    for (const auto &style : std::as_const(styles))
        m_comboBox_Style->addItem(style);
    int styleIdx = m_comboBox_Style->findText(currentItem);
    m_comboBox_Style->setCurrentIndex(styleIdx == -1 ? 0 : styleIdx);
}

void TpDialogCharacter::onFilterChanged(int filter)
{
    const QFontComboBox::FontFilter f = qvariant_cast<QFontComboBox::FontFilter>(m_comboBox_Filter->itemData(filter));
    m_comboBox_Font->setFontFilters(f);
}

void TpDialogCharacter::onFindSizes(const QFont &font)
{
    QString currentSize = m_comboBox_Size->currentText();
    {
        const QSignalBlocker blk(m_comboBox_Size);
        m_comboBox_Size->clear();

        if (QFontDatabase::isSmoothlyScalable(font.family(), QFontDatabase::styleString(font)))
        {
            const QList<int> sizes = QFontDatabase::standardSizes();
            for (const auto size : sizes)
                m_comboBox_Size->addItem(QVariant(size).toString());
            m_comboBox_Size->setEditable(true);
        }

        else
        {
            const QList<int> sizes = QFontDatabase::smoothSizes(font.family(), QFontDatabase::styleString(font));
            for (const auto size : sizes)
                m_comboBox_Size->addItem(QVariant(size).toString());
            m_comboBox_Size->setEditable(false);
        }
    }

    int sizeIdx = m_comboBox_Size->findText(currentSize);
    m_comboBox_Size->setCurrentIndex(sizeIdx == -1 ? qMax(0, m_comboBox_Size->count() / 3) : sizeIdx);
}

void TpDialogCharacter::onInsertCharacter(const QString &character)
{
    m_buffer->insert(character);
}

#ifndef QT_NO_CLIPBOARD
void TpDialogCharacter::updateClipboard()
{
    qApp->clipboard()->setText(m_buffer->text(), QClipboard::Mode::Clipboard);
    qApp->clipboard()->setText(m_buffer->text(), QClipboard::Mode::Selection);
}
#endif

void TpDialogCharacter::onInsertButtonClicked(bool)
{
    if (TpEditor *editor = m_parent->m_widget->tabs()->tab()->tab())
    {
        editor->insert(m_buffer->text());
    }
}

TP_END_NAMESPACE
