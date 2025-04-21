#include <QButtonGroup>

#include <Widgets/TpFindContainer>
#include <TpMainWindow>

TP_NAMESPACE

TpFindContainer::TpFindContainer(TpEditor *editor)
    : QWidget(editor),
    m_editor(editor)
{
    m_config = {
        {SimpleRegex, true},
        {PosixRegex, false},
        {CppRegex, false},
        {CaseSensitive, false},
        {WholeWord, false},
        {WordWrap, true},
        {Previous, false},
        {ShowText, true}
    };

    m_text = "";

    setObjectName("find");

    m_mainLayout = new QVBoxLayout(this);
    setLayout(m_mainLayout);
    m_widget = new QWidget(this);
    m_widget->setObjectName("find_Widget");
    m_mainLayout->addWidget(m_widget);
    m_widgetLayout = new QFormLayout(m_widget);
    m_widget->setLayout(m_widgetLayout);
    m_findEdit = new TpGeneralLineEdit(m_widget);
    m_findEdit->setObjectName("find_findEdit");
    m_findLabel = new QLabel(m_widget);
    m_findLabel->setText(tr("&Find: "));
    m_findLabel->setBuddy(m_findEdit);
    m_findLabel->setObjectName("find_findLabel");
    m_widgetLayout->addRow(m_findLabel, m_findEdit);
    m_replaceEdit = new TpGeneralLineEdit(m_widget);
    m_replaceEdit->setObjectName("find_replaceEdit");
    m_replaceLabel = new QLabel(m_widget);
    m_replaceLabel->setText(tr("&Replace: "));
    m_replaceLabel->setBuddy(m_replaceEdit);
    m_replaceLabel->setObjectName("find_replaceLabel");
    m_widgetLayout->addRow(m_replaceLabel, m_replaceEdit);
    m_options = new QGroupBox(m_widget);
    m_widgetLayout->addWidget(m_options);
    m_options->setTitle(tr("Options"));
    m_options->setCheckable(false);
    m_options->setObjectName("find_Options");
    m_optionsLayout = new QGridLayout(m_options);
    m_options->setLayout(m_optionsLayout);
    m_checkSimpleRegex = new QCheckBox(m_options);
    m_checkSimpleRegex->setText(tr("Simple Regular E&xpression"));
    m_checkSimpleRegex->setCheckable(true);
    m_checkSimpleRegex->setChecked(editor->ultimateParent()->m_menuBar->T_S_R_S->isChecked());
    m_checkSimpleRegex->setObjectName("find_checkSimpleRegex");
    m_optionsLayout->addWidget(m_checkSimpleRegex, 0, 0);
    m_checkPosixRegex = new QCheckBox(m_options);
    m_checkPosixRegex->setText(tr("POSIX Re&gular Expression"));
    m_checkPosixRegex->setCheckable(true);
    m_checkPosixRegex->setChecked(editor->ultimateParent()->m_menuBar->T_S_R_P->isChecked());
    m_checkPosixRegex->setObjectName("find_checkPosixRegex");
    m_optionsLayout->addWidget(m_checkPosixRegex, 0, 1);
    m_checkCppRegex = new QCheckBox(m_options);
    m_checkCppRegex->setText(tr("C&++ Regular Expression"));
    m_checkCppRegex->setCheckable(true);
    m_checkCppRegex->setChecked(editor->ultimateParent()->m_menuBar->T_S_R_pl->isChecked());
    m_checkCppRegex->setObjectName("find_checkCppRegex");
    m_optionsLayout->addWidget(m_checkCppRegex, 0, 2);
    m_checkCase = new QCheckBox(m_options);
    m_checkCase->setText(tr("&Case Sensitive"));
    m_checkCase->setCheckable(true);
    m_checkCase->setChecked(editor->ultimateParent()->m_menuBar->T_S_C->isChecked());
    m_checkCase->setObjectName("find_checkCase");
    m_optionsLayout->addWidget(m_checkCase, 1, 0);
    m_checkWord = new QCheckBox(m_options);
    m_checkWord->setText(tr("Whole Word &Only"));
    m_checkWord->setCheckable(true);
    m_checkWord->setChecked(editor->ultimateParent()->m_menuBar->T_S_O->isChecked());
    m_checkWord->setObjectName("find_checkWord");
    m_optionsLayout->addWidget(m_checkWord, 1, 1);
    m_checkWrap = new QCheckBox(m_options);
    m_checkWrap->setText(tr("&Word Wrap"));
    m_checkWrap->setCheckable(true);
    m_checkWrap->setChecked(editor->ultimateParent()->m_menuBar->T_S_W->isChecked());
    m_checkWrap->setObjectName("find_checkWrap");
    m_optionsLayout->addWidget(m_checkWrap, 1, 2);
    m_checkShow = new QCheckBox(m_options);
    m_checkShow->setText(tr("S&how Text"));
    m_checkShow->setCheckable(true);
    m_checkShow->setChecked(editor->ultimateParent()->m_menuBar->T_S_S->isChecked());
    m_checkShow->setObjectName("find_checkShow");
    m_optionsLayout->addWidget(m_checkShow, 2, 0);
    m_checkSelection = new QCheckBox(m_options);
    m_checkSelection->setText(tr("&In Selection"));
    m_checkSelection->setCheckable(true);
    m_checkSelection->setChecked(false);
    m_checkSelection->setObjectName("find_checkSelection");
    m_optionsLayout->addWidget(m_checkSelection, 2, 1);
    m_checkPrevious = new QCheckBox(m_options);
    m_checkPrevious->setText(tr("&Go Previous"));
    m_checkPrevious->setCheckable(true);
    m_checkPrevious->setChecked(editor->ultimateParent()->m_menuBar->T_S_G->isChecked());
    m_checkPrevious->setObjectName("find_checkPrevious");
    m_optionsLayout->addWidget(m_checkPrevious, 2, 2);
    m_buttonBox = new QDialogButtonBox(this);
    m_mainLayout->addWidget(m_buttonBox);
    m_findButton = new QPushButton(m_buttonBox);
    m_findButton->setText(tr("F&ind"));
    m_findButton->setObjectName("find_findButton");
    m_buttonBox->addButton(m_findButton, QDialogButtonBox::ButtonRole::AcceptRole);
    m_replaceButton = new QPushButton(m_buttonBox);
    m_replaceButton->setText(tr("R&eplace"));
    m_replaceButton->setObjectName("find_replaceButton");
    m_buttonBox->addButton(m_replaceButton, QDialogButtonBox::ButtonRole::AcceptRole);
    m_replaceAllButton = new QPushButton(m_buttonBox);
    m_replaceAllButton->setText(tr("Replace &All"));
    m_replaceAllButton->setObjectName("find_replaceAllButton");
    m_buttonBox->addButton(m_replaceAllButton, QDialogButtonBox::ButtonRole::AcceptRole);

    m_buttonGroupRegex = new QButtonGroup(this);
    m_buttonGroupRegex->addButton(m_checkSimpleRegex);
    m_buttonGroupRegex->addButton(m_checkPosixRegex);
    m_buttonGroupRegex->addButton(m_checkCppRegex);

    m_indicator = m_editor->findIndicator();

    connect(m_checkSelection,
            &QCheckBox::clicked,
            this,
            &TpFindContainer::onCheckSelectionClicked);
    connect(m_findButton,
            &QPushButton::clicked,
            this,
            &TpFindContainer::onFindButtonClicked);
    connect(m_replaceButton,
            &QPushButton::clicked,
            this,
            &TpFindContainer::onReplaceButtonClicked);
    connect(m_replaceAllButton,
            &QPushButton::clicked,
            this,
            &TpFindContainer::onReplaceAllButtonClicked);

    connect(m_checkSimpleRegex,
            &QCheckBox::clicked,
            this,
            &TpFindContainer::checkBoxChecked);
    connect(m_checkPosixRegex,
            &QCheckBox::clicked,
            this,
            &TpFindContainer::checkBoxChecked);
    connect(m_checkCppRegex,
            &QCheckBox::clicked,
            this,
            &TpFindContainer::checkBoxChecked);
    connect(m_checkCase,
            &QCheckBox::clicked,
            this,
            &TpFindContainer::checkBoxChecked);
    connect(m_checkWord,
            &QCheckBox::clicked,
            this,
            &TpFindContainer::checkBoxChecked);
    connect(m_checkWrap,
            &QCheckBox::clicked,
            this,
            &TpFindContainer::checkBoxChecked);
    connect(m_checkShow,
            &QCheckBox::clicked,
            this,
            &TpFindContainer::checkBoxChecked);
    connect(m_checkPrevious,
            &QCheckBox::clicked,
            this,
            &TpFindContainer::checkBoxChecked);
}

void TpFindContainer::onCheckSelectionClicked(bool isChecked)
{
    if (isChecked)
    {
        int lineFrom;
        int indexFrom;
        int lineTo;
        int indexTo;

        m_editor->getSelection(&lineFrom, &indexFrom, &lineTo, &indexTo);
        m_editor->fillIndicatorRange(lineFrom, indexFrom, lineTo, indexTo, m_indicator);
    }

    else
    {
        clearFindIndicators();
    }
}

bool TpFindContainer::onFindButtonClicked(bool)
{
#define FIND_COMMAND result = m_editor->findFirst( \
    m_findEdit->text(), \
    (m_checkSimpleRegex->isChecked() || m_checkPosixRegex->isChecked() || m_checkCppRegex->isChecked()), \
    m_checkCase->isChecked(), \
    m_checkWord->isChecked(), \
    m_checkWrap->isChecked(), \
    !(m_checkPrevious->isChecked()), \
    lineFrom, \
    indexFrom, \
    m_checkShow->isChecked(), \
    m_checkPosixRegex->isChecked(), \
    m_checkCppRegex->isChecked() \
)

    if (m_findEdit->text() == "")
        return false;

    int lineFrom = -1;
    int indexFrom = -1;
    int lineTo = -1;
    int indexTo = -1;

    int posFromStart = m_editor->findIndicatorStart(0);
    int posFromEnd = m_editor->findIndicatorEnd(0);
    int posToStart = m_editor->findIndicatorStart(m_editor->getLength());
    int posToEnd = m_editor->findIndicatorEnd(m_editor->getLength());

    bool startIndicator = isStartIndicator();

    int status = Situation0;

    if (posFromEnd == 0)
    {
        status = Situation0;

        lineFrom = 0;
        indexFrom = 0;

        m_editor->lineIndexFromPosition(m_editor->getLength(), &lineTo, &indexTo);
    }

    else if ((posToStart == posFromEnd) && startIndicator)
    {
        status = Situation1;

        lineFrom = 0;
        indexFrom = 0;

        m_editor->lineIndexFromPosition(posToStart, &lineTo, &indexTo);
    }

    else if (posToStart == posFromEnd)
    {
        status = Situation2;

        m_editor->lineIndexFromPosition(posFromEnd, &lineFrom, &indexFrom);
        m_editor->lineIndexFromPosition(posToStart, &lineTo, &indexTo);
    }

    else
    {
        status = Situation3;

        m_editor->lineIndexFromPosition(posFromEnd, &lineFrom, &indexFrom);
        m_editor->lineIndexFromPosition(posToStart, &lineTo, &indexTo);
    }

    if (m_checkPrevious->isChecked() && m_editor->hasSelectedText())
    {
        int selLineFrom, selIndexFrom, selLineTo, selIndexTo = -1;
        m_editor->getSelection(&selLineFrom, &selIndexFrom, &selLineTo, &selIndexTo);
        m_editor->setCursorPosition(selLineFrom, selIndexFrom);
    }

    bool result;

    if (
        (m_findEdit->text() == m_text) &&
        (m_checkSimpleRegex->isChecked() == m_config[SimpleRegex]) &&
        (m_checkPosixRegex->isChecked() == m_config[PosixRegex]) &&
        (m_checkCppRegex->isChecked() == m_config[CppRegex]) &&
        (m_checkCase->isChecked() == m_config[CaseSensitive]) &&
        (m_checkWord->isChecked() == m_config[WholeWord]) &&
        (m_checkWrap->isChecked() == m_config[WordWrap]) &&
        (m_checkPrevious->isChecked() == m_config[Previous]) &&
        (m_checkShow->isChecked() == m_config[ShowText])
    )
    {
        result = m_editor->findNext();
    }

    else
    {
        FIND_COMMAND;

        m_text = m_findEdit->text();
        m_config[SimpleRegex] = m_checkSimpleRegex->isChecked();
        m_config[PosixRegex] = m_checkPosixRegex->isChecked();
        m_config[CppRegex] = m_checkCppRegex->isChecked();
        m_config[CaseSensitive] = m_checkCase->isChecked();
        m_config[WholeWord] = m_checkWord->isChecked();
        m_config[WordWrap] = m_checkWrap->isChecked();
        m_config[Previous] = m_checkPrevious->isChecked();
        m_config[ShowText] = m_checkShow->isChecked();
    }

    int resultLineStart;
    int resultIndexStart;
    int resultLineEnd;
    int resultIndexEnd;

    m_editor->getSelection(&resultLineStart, &resultIndexStart, &resultLineEnd, &resultIndexEnd);

    if (status == Situation1)
    {
        if (
            result &&
            (m_editor->positionFromLineIndex(resultLineEnd, resultIndexEnd) >=
             m_editor->positionFromLineIndex(lineTo, indexTo))
        )
            FIND_COMMAND;
    }

    else if (status == Situation2)
    {
        if (
            result &&
            (m_editor->positionFromLineIndex(resultLineStart, resultIndexStart) <
             m_editor->positionFromLineIndex(lineFrom, indexFrom))
        )
            FIND_COMMAND;
    }

    else if (status == Situation3)
    {
        if (result)
            if ((m_editor->positionFromLineIndex(resultLineEnd, resultIndexEnd) >=
                 m_editor->positionFromLineIndex(lineTo, indexTo)) ||
                (m_editor->positionFromLineIndex(resultLineStart, resultIndexStart) <
                 m_editor->positionFromLineIndex(lineFrom, indexFrom)))
                FIND_COMMAND;
    }

    return result;

#undef FIND_COMMAND
}

bool TpFindContainer::onReplaceButtonClicked(bool)
{
    if (onFindButtonClicked(m_findButton->isChecked()))
    {
        m_editor->replace(m_replaceEdit->text());
        return true;
    }

    return false;
}

bool TpFindContainer::onReplaceAllButtonClicked(bool)
{
    int posFromEnd = m_editor->findIndicatorEnd(0);

    if (posFromEnd == 0)
    {
        m_editor->beginUndoAction();

        while (onFindButtonClicked(m_findButton->isChecked()))
            m_editor->replace(m_replaceEdit->text());

        m_editor->endUndoAction();

        return true;
    }

    m_editor->beginUndoAction();

    while (onFindButtonClicked(m_findButton->isChecked()))
    {
        bool has = isOnIndicator(m_editor->getPosition());

        if (has)
            m_editor->replace(m_replaceEdit->text());
        else
            break;
    }

    m_editor->endUndoAction();

    return true;
}

void TpFindContainer::clearFindIndicators()
{
    int lineTo;
    int indexTo;

    m_editor->lineIndexFromPosition(m_editor->getLength(), &lineTo, &indexTo);
    m_editor->clearIndicatorRange(0, 0, lineTo, indexTo, m_indicator);
}

bool TpFindContainer::isStartIndicator() const
{
    return isOnIndicator(0);
}

bool TpFindContainer::isOnIndicator(int position) const
{
    int allIndicators = m_editor->SendScintilla(TpEditor::SCI_INDICATORALLONFOR, position);

    QString allString = QString::number(allIndicators, 2);

    if (allString.size() < m_indicator)
        allString.append(QString('0').repeated(m_indicator));

    return allString.chopped(m_indicator).endsWith('1');
}

TpFindContainer::Options TpFindContainer::optionsFlag() const
{
    Options options = NoFlags;

    if (m_checkSimpleRegex->isChecked())
        options |= SimpleRegex;
    if (m_checkCppRegex->isChecked())
        options |= CppRegex;
    if (m_checkPosixRegex->isChecked())
        options |= PosixRegex;
    if (m_checkCase->isChecked())
        options |= CaseSensitive;
    if (m_checkWord->isChecked())
        options |= WholeWord;
    if (m_checkWrap->isChecked())
        options |= WordWrap;
    if (m_checkPrevious->isChecked())
        options |= Previous;
    if (m_checkShow->isChecked())
        options |= ShowText;

    return options;
}

void TpFindContainer::setOptions(TpFindContainer::Options options)
{
#define CHECK_CORR(flag, btn) btn->setChecked(options & flag)

    CHECK_CORR(SimpleRegex, m_checkSimpleRegex);
    CHECK_CORR(CppRegex, m_checkCppRegex);
    CHECK_CORR(PosixRegex, m_checkPosixRegex);
    CHECK_CORR(CaseSensitive, m_checkCase);
    CHECK_CORR(WholeWord, m_checkWord);
    CHECK_CORR(WordWrap, m_checkWord);
    CHECK_CORR(Previous, m_checkPrevious);
    CHECK_CORR(ShowText, m_checkShow);

#undef CHECK_CORR
}

TP_END_NAMESPACE
