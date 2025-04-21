#include <Widgets/TpGeneralComboBox>
#include <TpMainWindow>
#include <TpStatusBar>

TP_NAMESPACE

TpStatusBar::TpStatusBar(TpMainWindow *parent)
    : QStatusBar(parent)
{
#if defined(Q_OS_MAC) || defined(Q_OS_DARWIN)
    setSizeGripEnabled(false);
#endif

    comboBoxLangItems = {
        "None",
        "ActionScript",
        "ASP",
        "AviSynth",
        "Bash",
        "Batch",
        "BlitzBasic",
        "PureBasic",
        "FreeBasic",
        "C",
        "C++",
        "C++ (Qt)",
        "C#",
        "CMake",
        "CoffeeScript",
        "CSS",
        "D",
        "Diff",
        "Fortran",
        "Fortran77",
        "GDScript",
        "HTML",
        "HTML (Full)",
        "IDL",
        "Intel Hex",
        "Java",
        "JavaScript",
        "JSON",
        "LaTeX",
        "Lua",
        "Makefile",
        "Markdown",
        "MASM",
        "Matlab",
        "NASM",
        "Octave",
        "Pascal",
        "Perl",
        "PHP",
        "PO",
        "PostScript",
        "POV",
        "Properties",
        "Python 2",
        "Python 3",
        "Python 3 (Extended)",
        "QML",
        "QSS",
        "QUI",
        "Ruby",
        "Spice",
        "SQL",
        "S-Record",
        "TCL",
        "Tektronix Hex",
        "TeX",
        "Verilog",
        "VHDL",
        "XML",
        "YAML",
    };

    languagesMap = {
        {"None", None},
        {"ActionScript", ActionScript},
        {"ASP", ASP},
        {"AviSynth", AviSynth},
        {"Bash", Bash},
        {"Batch", Batch},
        {"BlitzBasic", BlitzBasic},
        {"PureBasic", PureBasic},
        {"FreeBasic", FreeBasic},
        {"C", C},
        {"C++", CPP},
        {"C++ (Qt)", CPPQt},
        {"C#", CS},
        {"CMake", CMake},
        {"CoffeeScript", CoffeeScript},
        {"CSS", CSS},
        {"D", D},
        {"Diff", Diff},
        {"Fortran", Fortran},
        {"Fortran77", Fortran77},
        {"GDScript", GDScript},
        {"HTML", HTML},
        {"HTML (Full)", HTMLFull},
        {"IDL", IDL},
        {"Intel Hex", IntelHex},
        {"Java", Java},
        {"JavaScript", JavaScript},
        {"JSON", JSON},
        {"LaTeX", LaTeX},
        {"Lua", Lua},
        {"Makefile", Makefile},
        {"Markdown", Markdown},
        {"MASM", MASM},
        {"Matlab", Matlab},
        {"NASM", NASM},
        {"Octave", Octave},
        {"Pascal", Pascal},
        {"Perl", Perl},
        {"PHP", PHP},
        {"PO", PO},
        {"PostScript", PostScript},
        {"POV", POV},
        {"Properties", Properties},
        {"Python 2", Python2},
        {"Python 3", Python3},
        {"Python 3 (Extended)", Python3Extended},
        {"QML", QML},
        {"QSS", QSS},
        {"QUI", QUI},
        {"Ruby", Ruby},
        {"Spice", Spice},
        {"SQL", SQL},
        {"S-Record", SRecord},
        {"TCL", TCL},
        {"Tektronix Hex", TektronixHex},
        {"TeX", TeX},
        {"Verilog", Verilog},
        {"VHDL", VHDL},
        {"XML", XML},
        {"YAML", YAML},
    };

    iteratedLangMap = [this](){
        QMap<Languages, QString> result;
        for (auto it = languagesMap.keyValueBegin(); it != languagesMap.keyValueEnd(); it++)
            result[it->second] = it->first;
        return result;
    }();

    comboBoxNewLineItems = {
        "Windows",        // SC_EOL_CRLF == [0]
        "Classical Mac",  // SC_EOL_CR   == [1]
        "Unix",           // SC_EOL_LF   == [2]
    };

    m_labelStats = new QLabel(this);
    m_labelStats->setEnabled(false);
    m_labelStats->setText(tr(""));
    m_labelStats->setToolTip(tr("Basic Statistics"));
    m_labelStats->setObjectName("label_statusBar_Stats");
    addPermanentWidget(m_labelStats);
    m_labelPosition = new QLabel(this);
    m_labelPosition->setEnabled(false);
    m_labelPosition->setText(tr(""));
    m_labelPosition->setToolTip(tr("Position"));
    m_labelPosition->setObjectName("label_statusBar_Position");
    addPermanentWidget(m_labelPosition);
    m_labelLineAndColumn = new QLabel(this);
    m_labelLineAndColumn->setEnabled(false);
    m_labelLineAndColumn->setText(tr(""));
    m_labelLineAndColumn->setToolTip(tr("Line and Column"));
    m_labelLineAndColumn->setObjectName("label_statusBar_LineAndColumn");
    addPermanentWidget(m_labelLineAndColumn);
    m_spinBoxTabWidth = new QSpinBox(this);
    m_spinBoxTabWidth->setMinimum(1);
    m_spinBoxTabWidth->setMaximum(120);
    m_spinBoxTabWidth->setValue(4);
    m_spinBoxTabWidth->setAcceptDrops(false);
    m_spinBoxTabWidth->setEnabled(false);
    m_spinBoxTabWidth->setToolTip(tr("Tab Width"));
    m_spinBoxTabWidth->setObjectName("spinBox_statusBar_TabWidth");
    addPermanentWidget(m_spinBoxTabWidth);
    m_comboBoxLang = new TpGeneralComboBox(this);
    m_comboBoxLang->setEditable(false);
    m_comboBoxLang->addItems(comboBoxLangItems);
    m_comboBoxLang->insertSeparator(1);
    m_comboBoxLang->setCurrentIndex(0);
    m_comboBoxLang->setEnabled(false);
    m_comboBoxLang->setToolTip(tr("Language Lexers"));
    m_comboBoxLang->setObjectName("comboBox_statusBar_Lang");
    addPermanentWidget(m_comboBoxLang);
    m_comboBoxNewLine = new TpGeneralComboBox(this);
    m_comboBoxNewLine->setEditable(false);
    m_comboBoxNewLine->addItems(comboBoxNewLineItems);
    m_comboBoxNewLine->setCurrentIndex(2);
    m_comboBoxNewLine->setEnabled(false);
    m_comboBoxNewLine->setToolTip(tr("End-of-line Modes"));
    m_comboBoxNewLine->setObjectName("comboBox_statusBar_NewLine");
    addPermanentWidget(m_comboBoxNewLine);
}

void TpStatusBar::updateAccessibility(bool h)
{
    m_labelStats->setEnabled(h);
    m_labelPosition->setEnabled(h);
    m_labelLineAndColumn->setEnabled(h);
    m_spinBoxTabWidth->setEnabled(h);
    m_comboBoxLang->setEnabled(h);
    m_comboBoxNewLine->setEnabled(h);
}

TP_END_NAMESPACE
