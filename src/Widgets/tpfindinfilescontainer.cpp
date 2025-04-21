#include <QDirIterator>
#include <QEvent>
#include <QFileInfo>

#if QT_VERSION_MAJOR <= 5
#include <QTextStream>
#endif

#include <Dialogs/TpMessageCritical>
#include <Widgets/TpFindInFilesContainer>

TP_NAMESPACE

TpFindInFilesContainer::TpFindInFilesContainer(QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QVBoxLayout();
    setLayout(m_layout);
    m_findLayout = new QFormLayout();
    m_layout->addLayout(m_findLayout);
    m_findLabel = new QLabel(this);
    m_findLabel->setText(tr("&Find: "));
    m_findLabel->setObjectName("findInFiles_findLabel");
    m_findEdit = new TpGeneralLineEdit(this);
    m_findEdit->setObjectName("findInFiles_findEdit");
    m_findLabel->setBuddy(m_findEdit);
    m_findLayout->addRow(m_findLabel, m_findEdit);
    m_replaceLabel = new QLabel(this);
    m_replaceLabel->setText(tr("&Replace: "));
    m_replaceLabel->setObjectName("findInFiles_replaceLabel");
    m_replaceEdit = new TpGeneralLineEdit(this);
    m_replaceEdit->setObjectName("findInFiles_replaceEdit");
    m_replaceLabel->setBuddy(m_replaceEdit);
    m_findLayout->addRow(m_replaceLabel, m_replaceEdit);
    m_toolBox = new QToolBox(this);
    m_toolBox->setObjectName("findInFiles_toolBox");
    m_toolBox->installEventFilter(this);
    m_layout->addWidget(m_toolBox);
    m_groupBox = new QGroupBox(m_toolBox);
    m_groupBox->setTitle(tr("&Directories"));
    m_groupBox->setObjectName("findInFiles_groupBox");
    m_groupBox->setCheckable(false);
    m_groupBox->setChecked(false);
    m_groupBoxLayout = new QVBoxLayout();
    m_groupBox->setLayout(m_groupBoxLayout);
    m_toolBox->addItem(m_groupBox, tr("Configurations"));
    m_groupBoxRegex = new QGroupBox(m_groupBox);
    m_groupBoxRegex->setTitle(tr("Regular E&xpression"));
    m_groupBoxRegex->setObjectName("findInFiles_groupBoxRegex");
    m_groupBoxRegex->setCheckable(true);
    m_groupBoxRegex->setChecked(true);
    m_groupBoxRegexLayout = new QHBoxLayout();
    m_groupBoxRegex->setLayout(m_groupBoxRegexLayout);
    m_groupBoxLayout->addWidget(m_groupBoxRegex);
    m_groupBoxRegexOptions = new QGroupBox(m_groupBoxRegex);
    m_groupBoxRegexOptions->setTitle(tr("Options"));
    m_groupBoxRegexOptions->setObjectName("findInFiles_groupBoxRegexOptions");
    m_groupBoxRegexOptions->setCheckable(false);
    m_groupBoxRegexOptions->setChecked(false);
    m_groupBoxRegexOptionsLayout = new QGridLayout();
    m_groupBoxRegexOptions->setLayout(m_groupBoxRegexOptionsLayout);
    m_groupBoxRegexLayout->addWidget(m_groupBoxRegexOptions);
    m_checkRegexCaseInsensitive = new QCheckBox(m_groupBoxRegexOptions);
    m_checkRegexCaseInsensitive->setText(tr("&Case Insensitive"));
    m_checkRegexCaseInsensitive->setObjectName("findInFiles_checkRegexCaseInsensitive");
    m_checkRegexCaseInsensitive->setChecked(true);
    m_groupBoxRegexOptionsLayout->addWidget(m_checkRegexCaseInsensitive, 0, 0);
    m_checkRegexMatchNewlines = new QCheckBox(m_groupBoxRegexOptions);
    m_checkRegexMatchNewlines->setText(tr("'&.' Matches Newlines"));
    m_checkRegexMatchNewlines->setObjectName("findInFiles_checkRegexMatchNewlines");
    m_checkRegexMatchNewlines->setChecked(false);
    m_groupBoxRegexOptionsLayout->addWidget(m_checkRegexMatchNewlines, 0, 1);
    m_checkRegexMultiline = new QCheckBox(m_groupBoxRegexOptions);
    m_checkRegexMultiline->setText(tr("Multi&-line Search"));
    m_checkRegexMultiline->setObjectName("findInFiles_checkRegexMultiline");
    m_checkRegexMultiline->setChecked(true);
    m_groupBoxRegexOptionsLayout->addWidget(m_checkRegexMultiline, 1, 0);
    m_checkRegexExtendedSyntax = new QCheckBox(m_groupBoxRegexOptions);
    m_checkRegexExtendedSyntax->setText(tr("Extended Pattern S&yntax"));
    m_checkRegexExtendedSyntax->setObjectName("findInFiles_checkRegexExtendedSyntax");
    m_checkRegexExtendedSyntax->setChecked(true);
    m_groupBoxRegexOptionsLayout->addWidget(m_checkRegexExtendedSyntax, 1, 1);
    m_checkRegexInvertedGreediness = new QCheckBox(m_groupBoxRegexOptions);
    m_checkRegexInvertedGreediness->setText(tr("Inverted &Greediness"));
    m_checkRegexInvertedGreediness->setObjectName("findInFiles_checkRegexInvertedGreediness");
    m_checkRegexInvertedGreediness->setChecked(false);
    m_groupBoxRegexOptionsLayout->addWidget(m_checkRegexInvertedGreediness, 2, 0);
    m_checkRegexDontCapture = new QCheckBox(m_groupBoxRegexOptions);
    m_checkRegexDontCapture->setText(tr("Don&'t Capture As Groups"));
    m_checkRegexDontCapture->setObjectName("findInFiles_checkRegexDontCapture");
    m_checkRegexDontCapture->setChecked(false);
    m_groupBoxRegexOptionsLayout->addWidget(m_checkRegexDontCapture, 2, 1);
    m_checkRegexUnicode = new QCheckBox(m_groupBoxRegexOptions);
    m_checkRegexUnicode->setText(tr("&Use Unicode Properties"));
    m_checkRegexUnicode->setObjectName("findInFiles_checkRegexUnicode");
    m_checkRegexUnicode->setChecked(false);
    m_groupBoxRegexOptionsLayout->addWidget(m_checkRegexUnicode, 3, 0);
    m_checkRegexAnchoredAtOffset = new QCheckBox(m_groupBoxRegexOptions);
    m_checkRegexAnchoredAtOffset->setText(tr("&Anchored At Offset"));
    m_checkRegexAnchoredAtOffset->setObjectName("findInFiles_checkRegexAnchoredAtOffset");
    m_checkRegexAnchoredAtOffset->setChecked(false);
    m_groupBoxRegexOptionsLayout->addWidget(m_checkRegexAnchoredAtOffset, 3, 1);
    m_groupBoxRegexType = new QGroupBox(m_groupBox);
    m_groupBoxRegexType->setTitle(tr("Match Type"));
    m_groupBoxRegexType->setObjectName("findInFiles_groupBoxRegexType");
    m_groupBoxRegexType->setCheckable(false);
    m_groupBoxRegexType->setChecked(false);
    m_groupBoxRegexTypeLayout = new QGridLayout();
    m_groupBoxRegexType->setLayout(m_groupBoxRegexTypeLayout);
    m_groupBoxRegexLayout->addWidget(m_groupBoxRegexType);
    m_checkRegexNormal = new QRadioButton(m_groupBoxRegexType);
    m_checkRegexNormal->setText(tr("Normal &Match"));
    m_checkRegexNormal->setObjectName("findInFiles_checkRegexNormal");
    m_checkRegexNormal->setChecked(true);
    m_groupBoxRegexTypeLayout->addWidget(m_checkRegexNormal, 0, 0);
    m_checkRegexPartialComplete = new QRadioButton(m_groupBoxRegexType);
    m_checkRegexPartialComplete->setText(tr("Partial Prefer Match &(Complete)"));
    m_checkRegexPartialComplete->setObjectName("findInFiles_checkRegexPartialComplete");
    m_checkRegexPartialComplete->setChecked(false);
    m_groupBoxRegexTypeLayout->addWidget(m_checkRegexPartialComplete, 0, 1);
    m_checkRegexPartialFirst = new QRadioButton(m_groupBoxRegexType);
    m_checkRegexPartialFirst->setText(tr("Partial Prefer Match (&1st)"));
    m_checkRegexPartialFirst->setObjectName("findInFiles_checkRegexPartialFirst");
    m_checkRegexPartialFirst->setChecked(false);
    m_groupBoxRegexTypeLayout->addWidget(m_checkRegexPartialFirst, 1, 0);
    m_checkSubDirectories = new QCheckBox(m_groupBox);
    m_checkSubDirectories->setText(tr("Su&b Directories"));
    m_checkSubDirectories->setObjectName("findInFiles_checkSubDirectories");
    m_checkSubDirectories->setChecked(true);
    m_groupBoxLayout->addWidget(m_checkSubDirectories);
    m_groupBoxDir = new QGroupBox(m_groupBox);
    m_groupBoxDir->setTitle(tr("Directory"));
    m_groupBoxDir->setObjectName("findInFiles_groupBoxDir");
    m_groupBoxDir->setCheckable(false);
    m_groupBoxDir->setChecked(false);
    m_groupBoxDirLayout = new QFormLayout();
    m_groupBoxDir->setLayout(m_groupBoxDirLayout);
    m_groupBoxLayout->addWidget(m_groupBoxDir);
    m_dirNameLabel = new QLabel(this);
    m_dirNameLabel->setText(tr("Directory Name&: "));
    m_dirNameLabel->setObjectName("findInFiles_dirNameLabel");
    m_dirNameEdit = new TpGeneralLineEdit(this);
    m_dirNameEdit->setObjectName("findInFiles_dirNameEdit");
    m_dirNameLabel->setBuddy(m_dirNameEdit);
    m_groupBoxDirLayout->addRow(m_dirNameLabel, m_dirNameEdit);
    m_dirFilterLabel = new QLabel(this);
    m_dirFilterLabel->setText(tr("Directory F&ilter: "));
    m_dirFilterLabel->setObjectName("findInFiles_dirFilterLabel");
    m_dirFilterEdit = new QComboBox(this);
    m_dirFilterEdit->setObjectName("findInFiles_dirFilterEdit");
    m_dirFilterEdit->setInsertPolicy(QComboBox::InsertPolicy::InsertAtTop);
    m_dirFilterEdit->setEditable(true);
    m_dirFilterEdit->addItem("*.*");
    m_dirFilterLabel->setBuddy(m_dirFilterEdit);
    m_groupBoxDirLayout->addRow(m_dirFilterLabel, m_dirFilterEdit);
    m_buttonBox = new QDialogButtonBox(this);
    m_buttonBox->setObjectName("findInFiles_buttonBox");
    m_layout->addWidget(m_buttonBox);
    m_buttonFind = new QPushButton(m_buttonBox);
    m_buttonFind->setText(tr("G&o"));
    m_buttonFind->setObjectName("findInFiles_buttonFind");
    m_buttonBox->addButton(m_buttonFind, QDialogButtonBox::ButtonRole::AcceptRole);
    m_buttonReplace = new QPushButton(m_buttonBox);
    m_buttonReplace->setText(tr("Go a&nd Replace"));
    m_buttonReplace->setObjectName("findInFiles_buttonReplace");
    m_buttonBox->addButton(m_buttonReplace, QDialogButtonBox::ButtonRole::AcceptRole);
    m_buttonClearFilter = new QPushButton(m_buttonBox);
    m_buttonClearFilter->setText(tr("C&lear Current Directory Filters"));
    m_buttonClearFilter->setObjectName("findInFiles_buttonClearFilter");
    m_buttonBox->addButton(m_buttonClearFilter, QDialogButtonBox::ButtonRole::ResetRole);
    m_treeWidget = new QTreeWidget(this);
    m_treeWidget->setObjectName("findInFiles_treeWidget");
    m_treeWidget->setHeaderLabels({tr("Line"), tr("Context")});
    m_layout->addWidget(m_treeWidget);
    m_errorLabel = new QLabel(this);
    m_errorLabel->setStyleSheet(QString("color: #ff0000;") + m_errorLabel->styleSheet());
    m_errorLabel->setObjectName("findInFiles_errorLabel");
    m_layout->addWidget(m_errorLabel);
    m_infoLabel = new QLabel(this);
    m_infoLabel->setStyleSheet(m_infoLabel->styleSheet());
    m_infoLabel->setObjectName("findInFiles_infoLabel");
    m_layout->addWidget(m_infoLabel);
    m_delegate = new TpHtmlDelegate(this);
    m_treeWidget->setItemDelegate(m_delegate);

    connect(m_buttonFind,
            &QPushButton::clicked,
            this,
            &TpFindInFilesContainer::onFindClicked);
    connect(m_buttonReplace,
            &QPushButton::clicked,
            this,
            &TpFindInFilesContainer::onReplaceClicked);
    connect(m_buttonClearFilter,
            &QPushButton::clicked,
            this,
            &TpFindInFilesContainer::onClearFilterClicked);
    connect(m_treeWidget,
            &QTreeWidget::itemDoubleClicked,
            this,
            &TpFindInFilesContainer::onTreeWidgetDoubleClicked);
}

bool TpFindInFilesContainer::eventFilter(QObject *object, QEvent *event)
{
    if (object == m_toolBox)
    {
        if (event->type() == QEvent::Type::MouseButtonRelease)
        {
            if (m_groupBox->isVisible())
                m_groupBox->setVisible(false);
            else
                m_groupBox->setVisible(true);
        }
    }

    return QWidget::eventFilter(object, event);
}

int TpFindInFilesContainer::findLineNumber(QString string, int index)
{
    int lineNumber = 1;

    for (int i = 0; i < index; i++)
        if (string.at(i) == '\n')
            lineNumber++;

    return lineNumber;
}

void TpFindInFilesContainer::onFindClicked()
{
    m_errorLabel->setText("");

    if (m_findEdit->text() == "")
    {
        m_errorLabel->setText(tr("Error: No target string."));
        return;
    }

    if (m_dirNameEdit->text() == "")
    {
        m_errorLabel->setText(tr("Error: No target directory."));
        return;
    }

    if (!QFileInfo(m_dirNameEdit->text()).exists())
    {
        m_errorLabel->setText(tr("Error: Target directory does not exist."));
        return;
    }

    m_errorLabel->setText("");

    QDirIterator::IteratorFlags dirIteratorFlag = QDirIterator::IteratorFlag::NoIteratorFlags;

    if (m_checkSubDirectories->isChecked())
        dirIteratorFlag = QDirIterator::IteratorFlag::Subdirectories | QDirIterator::IteratorFlag::FollowSymlinks;

    bool doRegex = m_groupBoxRegex->isChecked();

    QRegularExpression::PatternOptions regexFlags = QRegularExpression::PatternOption::NoPatternOption;

    if (m_checkRegexCaseInsensitive->isChecked())
        regexFlags |= QRegularExpression::PatternOption::CaseInsensitiveOption;
    if (m_checkRegexMatchNewlines->isChecked())
        regexFlags |= QRegularExpression::PatternOption::DotMatchesEverythingOption;
    if (m_checkRegexMultiline->isChecked())
        regexFlags |= QRegularExpression::PatternOption::MultilineOption;
    if (m_checkRegexExtendedSyntax->isChecked())
        regexFlags |= QRegularExpression::PatternOption::ExtendedPatternSyntaxOption;
    if (m_checkRegexInvertedGreediness->isChecked())
        regexFlags |= QRegularExpression::PatternOption::InvertedGreedinessOption;
    if (m_checkRegexDontCapture->isChecked())
        regexFlags |= QRegularExpression::PatternOption::DontCaptureOption;
    if (m_checkRegexUnicode->isChecked())
        regexFlags |= QRegularExpression::PatternOption::UseUnicodePropertiesOption;

    QRegularExpression::MatchType regexType = QRegularExpression::MatchType::NormalMatch;

    if (m_checkRegexPartialComplete->isChecked())
        regexType = QRegularExpression::MatchType::PartialPreferCompleteMatch;
    else if (m_checkRegexPartialFirst->isChecked())
        regexType = QRegularExpression::MatchType::PartialPreferFirstMatch;

    QRegularExpression::MatchOptions regexMatchOption = QRegularExpression::MatchOption::NoMatchOption;

    if (m_checkRegexAnchoredAtOffset->isChecked())
#if QT_VERSION_MAJOR >= 6
        regexMatchOption |= QRegularExpression::MatchOption::AnchorAtOffsetMatchOption;
#else
        regexMatchOption |= QRegularExpression::MatchOption::AnchoredMatchOption;
#endif

    QDir::Filters dirFlags = QDir::Filter::NoDotAndDotDot | QDir::Filter::AllEntries | QDir::Filter::Readable;
    QStringList dirFilters = {};

    for (int index = 0; index < m_dirFilterEdit->count(); index++)
        dirFilters.append(m_dirFilterEdit->itemText(index));

    QDir dir(m_dirNameEdit->text(), dirFilters.join(";;"), QDir::SortFlag::Name, dirFlags);
    QDirIterator it = QDirIterator(dir, dirIteratorFlag);

    if (it.hasNext())
        m_treeWidget->clear();
    else
        return;

    unsigned long long hits = 0;
    unsigned long long hitFiles = 0;
    unsigned long long totalFiles = 0;

    while (it.hasNext())
    {
        QString fileName = it.next();
        QFileInfo fileInfo(fileName);

        if (fileInfo.isDir() || !fileInfo.exists())
            continue;

        QFile file(fileName);

        if (file.open(QFile::OpenModeFlag::ReadOnly))
        {
            totalFiles++;
            QString content = file.readAll();

            if (doRegex)
            {
                QRegularExpression regex;
                regex.setPattern(m_findEdit->text());

                if (regex.patternErrorOffset() != -1)
                {
                    m_errorLabel->setText(QString("Error: SyntaxError (Regex): %1 at %2.")
                        .arg(regex.errorString()).arg(regex.patternErrorOffset()));
                    return;
                }

                m_errorLabel->setText("");

                regex.setPatternOptions(regexFlags);

                QRegularExpressionMatchIterator regexIt = regex.globalMatch(
                    content, 0, regexType, regexMatchOption
                );

                if (regexIt.hasNext())
                {
                    hitFiles++;
                    QList<int> lines = {};

                    QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(m_treeWidget);
                    treeWidgetItem->setText(0, fileInfo.absoluteFilePath());
                    treeWidgetItem->setFirstColumnSpanned(true);
                    treeWidgetItem->setData(0, RegexRole, regex);
                    m_treeWidget->addTopLevelItem(treeWidgetItem);

                    while (regexIt.hasNext())
                    {
                        QRegularExpressionMatch regexMatch = regexIt.next();
                        int currentLine = findLineNumber(content, regexMatch.capturedStart());
                        hits++;

                        if (lines.contains(currentLine))
                            continue;

                        lines.append(currentLine);

                        QTreeWidgetItem *resultItem = new QTreeWidgetItem(treeWidgetItem);
                        resultItem->setText(0, QString::number(currentLine));
                        resultItem->setText(1,
                            content.split("\n")[currentLine - 1].replace(regexMatch.captured(),
                                QString("<b>%1</b>").arg(regexMatch.captured()))
                        );
                        resultItem->setData(0, PositionRole, regexMatch.capturedStart());
                        resultItem->setData(1, FilePathRole, fileInfo.absoluteFilePath());
                        treeWidgetItem->addChild(resultItem);
                    }
                }
            }

            else
            {
                if (content.contains(m_findEdit->text()))
                {
                    hitFiles++;
                    int indexOf = 0;
                    QList<int> lines = {};

                    QTreeWidgetItem *treeWidgetItem = new QTreeWidgetItem(m_treeWidget);
                    treeWidgetItem->setText(0, fileInfo.absoluteFilePath());
                    treeWidgetItem->setFirstColumnSpanned(true);
                    treeWidgetItem->setData(0, RegexRole, QRegularExpression());
                    m_treeWidget->addTopLevelItem(treeWidgetItem);

                    while ((indexOf = content.indexOf(m_findEdit->text(), indexOf)) != -1)
                    {
                        int currentLine = findLineNumber(content, indexOf);
                        hits++;

                        if (lines.contains(currentLine))
                            continue;

                        lines.append(currentLine);
                        QTreeWidgetItem *resultItem = new QTreeWidgetItem(treeWidgetItem);
                        resultItem->setText(0, QString::number(currentLine));
                        resultItem->setText(1,
                            content.split("\n")[currentLine - 1].replace(m_findEdit->text(),
                                QString("<b>%1</b>").arg(m_findEdit->text()))
                        );
                        resultItem->setData(0, PositionRole, indexOf);
                        resultItem->setData(1, FilePathRole, fileInfo.absoluteFilePath());
                        treeWidgetItem->addChild(resultItem);
                        indexOf++;
                    }
                }
            }
        }
    }

    m_infoLabel->setText(tr("%1 hits in %2 files wihle %3 searched").arg(hits).arg(hitFiles).arg(totalFiles));
}

void TpFindInFilesContainer::onReplaceClicked()
{
    onFindClicked();

    if (m_treeWidget->topLevelItemCount() <= 0)
        return;

    TpMessageCritical *msg = new TpMessageCritical(this);
    int msgResult = msg->genericSay(
        tr("Replace"), tr("Do you really want to replace?"),
        tr("This action is irreversible. Click 'Cancel' to check the found results."),
    true);

    if (msgResult != QMessageBox::StandardButton::Ok)
        return;

    QString replaceText = m_replaceEdit->text();

    for (int index = 0; index < m_treeWidget->topLevelItemCount(); index++)
    {
        QTreeWidgetItem *item = m_treeWidget->topLevelItem(index);
        QFile file(item->text(0));

        if (file.open(QFile::OpenModeFlag::ReadWrite))
        {
            QTextStream stream(&file);
            QString content = file.readAll();
            file.resize(0);

            if (item->data(0, RegexRole).toRegularExpression().isValid())
                content.replace(item->data(0, RegexRole).toRegularExpression(), m_replaceEdit->text());
            else
                content.replace(m_findEdit->text(), m_replaceEdit->text());

            stream << content;
        }

        file.close();
    }
}

void TpFindInFilesContainer::onClearFilterClicked()
{
    m_dirFilterEdit->removeItem(m_dirFilterEdit->currentIndex());
}

void TpFindInFilesContainer::onTreeWidgetDoubleClicked(QTreeWidgetItem *item, int column)
{
    if (item->isFirstColumnSpanned())
        return;

    // Seems like that the Scintilla component is designed to not count the new lines
    emit resultClicked(
        item->data(1, FilePathRole).toString(), (item->data(0, PositionRole).toInt() - item->text(0).toInt() + 1)
    );
}

TP_END_NAMESPACE
