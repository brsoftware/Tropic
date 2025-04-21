#ifndef TPGLOBALS_H
#define TPGLOBALS_H

#define TP_NAMESPACE_NAME Tropic
#define TP_NAMESPACE namespace TP_NAMESPACE_NAME {
#define TP_END_NAMESPACE }

#define DEF_SETTINGS QSettings settings
#define INIT_SETTINGS(key, val) settings.setValue(key, settings.value(key, val));
#define SET_SETTINGS(key, val) settings.setValue(key, val)
#define GET_SETTINGS(key, type) qvariant_cast<type>(settings.value(key))
#define GET_SETTINGS_WITH(key, type, fail) qvariant_cast<type>(settings.value(key, fail))

#define DEF_PROP(proptype, propname) proptype m_##propname
#define DEF_PROP_FUNC(proptype, propname, funcname) \
void set##funcname(proptype propname) { \
    m_##propname = propname; \
} \
proptype propname() { \
    return m_##propname; \
}

#if QT_VERSION_MAJOR >= 6
#include <qtypes.h>
#endif

#include <QColor>
#include <QFile>
#include <QFont>
#include <QMap>
#include <QObject>
#include <QSettings>
#include <QString>

#if defined(Q_OS_DARWIN) || defined(Q_OS_MAC)
inline bool isDarwin = true;
#else
inline bool isDarwin = false;
#endif

inline unsigned long long maximumRecentFiles = 10;

inline QList<unsigned long long> untitledList = {};
inline QList<unsigned long long> tabSerialList = {};

enum Languages
{
    None,
    ActionScript,
    ASP,
    AviSynth,
    Bash,
    Batch,
    BlitzBasic,
    PureBasic,
    FreeBasic,
    C,
    CPP,
    CPPQt,
    CS,
    CMake,
    CoffeeScript,
    CSS,
    D,
    Diff,
    Fortran,
    Fortran77,
    GDScript,
    HTML,
    HTMLFull,
    IDL,
    IntelHex,
    Java,
    JavaScript,
    JSON,
    LaTeX,
    Lua,
    Makefile,
    Markdown,
    MASM,
    Matlab,
    NASM,
    Octave,
    Pascal,
    Perl,
    PHP,
    PO,
    PostScript,
    POV,
    Properties,
    Python2,
    Python3,
    Python3Extended,
    QML,
    QSS,
    QUI,
    Ruby,
    Spice,
    SQL,
    SRecord,
    TCL,
    TektronixHex,
    TeX,
    Verilog,
    VHDL,
    XML,
    YAML,
};


inline const QList<QString> extensions = {
    "All Extensions (*.*)",
    "Text Files (*.txt)",
    "ActionScript Files (*.as; *.mx)",
    "Active Server Pages Files (*.asp; *.aspx)",
    "AviSynth Files (*.avs; *.asvi)",
    "Bash/ Unix Shell Files (*.bash; *.sh; *.bsh; *.csh; *.bash_profile; *.bashrc; *.profile)",
    "Batch Files (*.bat; *.cmd; *.nt)",
    "BlitzBasic Files (*.bb)",
    "PureBasic Files (*.pb)",
    "FreeBasic Files (*.bas; *.bi)",
    "C Files (*.c; *.lex; *.i)",
    "C++ Files (*.cpp; *.cxx; *.cc; *.cp; *.c++; *.hpp; *.h; *.hxx; *.hh; *.hp; *.h++; *.ino; *.ipp; *.i++; *.ixx; "
    "*.ii)",
    "C# Files (*.cs)",
    "CMake Files (*.cmake; CMakeLists.txt)",
    "CoffeeScript Files (*.coffee; *.litcoffee)",
    "Cascading Style Sheets Files (*.css)",
    "D Files (*.d)",
    "Diff Files (*.diff; *.patch)",
    "Fortran Files (*.f; *.for; *.f90; *.f95; *.f2k; *.f23; *.fortran)",
    "Fortran 77 Files (*.f77)",
    "GDScript Files (*.gd)",
    "HTML Files (*.html; *.htm; *.shtml; *.shtm; *.mhtml; *.mhtm; *.xhtml; *.xht; *.hta)",
    "IDL Files (*.idl)",
    "Intel Hex Files (*.hex)",
    "Java Files (*.java)",
    "JavaScript Files (*.js; *.jsm; *.jsx; *.mjs)",
    "JSON Files (*.json)",
    "LaTeX Files (*.tex; *.sty; *.latex)",
    "Lua Files (*.lua)",
    "Makefile Files (*.mk; *.mak; *.make; *.makefile)",
    "Markdown Files (*.md; *.commonmark; *.markdown)",
    "MASM Assembly Files (*.asm; *.masm)",
    "Matlab Files (*.m; *.matlab)",
    "NASM Assembly Files (*.nasm)",
    "Octave Files (*.oct; *.octave)",
    "Pascal Files (*.pas; *.pp; *.p; *.inc; *.lpr)",
    "Perl Files (*.pl; *.pm; *.plx; *.t)",
    "PHP Files (*.php; *.php3; *.php4; *.php5; *.phps; *.phpt; *.phtml; *.phtm)",
    "PO/ GNU/GetText Files (*.po)",
    "PostScript Files (*.ps)",
    "POV-Ray Files (*.pov; *.povray)",
    "Properties Files (*.properties; *.conf; *.cfg; *.gitattributes; *.gitconfig; *.gitmodules; *.editorconfig)",
    "Python 2 Files (*.py2)",
    "Python 3 Files (*.py; *.pyw; *.py3; *.pyx; *.pyd; *.pyi; *.spec; *.egg; *.egg-info; *.dist-info; *.whl)",
    "Qt Modeling Language Files (*.qml)",
    "Qt Style Sheets Files (*.qss)",
    "Qt User Interface Files (*.qs; *.cw)",
    "Ruby Files (*.ruby; *.rb; *.rbw; *.rbx; *.gem)",
    "Spice Files (*.spice; *.scp; *.out)",
    "Structured Query Language Files (*.sql)",
    "S-Record Hex Files (*.srec; *.mot)",
    "Tool Command Language Files (*.tcl)",
    "Tektronix Hex Files (*.tek)",
    "TeX Files (*.tex)",
    "Verilog Files (*.v; *.sv; *.vh; *.svh)",
    "VHSIC Hardware Description Language Files (*.vhdl; *.vhd)",
    "X-tended Markup Language Files (*.xml; *.qrc; *.rcc; *.xaml; *.xsl; *.xslt; *.xsd; *.xul; *.kml; *.svg; *.mxml; "
    "*.wsdl; *.xlf; *.xliff; *.xbl; *.sxbl; *.sitemap; *.gml; *.gpx; *.plist; *.vcproj; *.vcxproj; *.csproj; "
    "*.csxproj; *.vbproj; *.vbxproj; *.ui; *.rc)",
    "YAML Files (*.yaml)",
};

inline const QMap<Languages, QString> defaultNameFilter = {
    {None, "All Extensions (*.*)"},
    {ActionScript, "ActionScript Files (*.as; *.mx)"},
    {ASP, "Active Server Pages Files (*.asp; *.aspx)"},
    {AviSynth, "AviSynth Files (*.avs; *.asvi)"},
    {Bash, "Bash/ Unix Shell Files (*.bash; *.sh; *.bsh; *.csh; *.bash_profile; *.bashrc; *.profile)"},
    {Batch, "Batch Files (*.bat; *.cmd; *.nt)"},
    {BlitzBasic, "BlitzBasic Files (*.bb)"},
    {PureBasic, "PureBasic Files (*.pb)"},
    {FreeBasic, "FreeBasic Files (*.bas; *.bi)"},
    {C, "C Files (*.c; *.lex; *.i)"},
    {CPP, "C++ Files (*.cpp; *.cxx; *.cc; *.cp; *.c++; *.hpp; *.h; *.hxx; *.hh; *.hp; *.h++; *.ino; *.ipp; *.i++; "
     "*.ixx; *.ii)"},
    {CS, "C# Files (*.cs)"},
    {CMake, "CMake Files (*.cmake; CMakeLists.txt)"},
    {CoffeeScript, "CoffeeScript Files (*.coffee; *.litcoffee)"},
    {CSS, "Cascading Style Sheets Files (*.css)"},
    {D, "D Files (*.d)"},
    {Diff, "Diff Files (*.diff; *.patch)"},
    {Fortran, "Fortran Files (*.f; *.for; *.f90; *.f95; *.f2k; *.f23; *.fortran)"},
    {Fortran77, "Fortran 77 Files (*.f77)"},
    {GDScript, "GDScript Files (*.gd)"},
    {HTML, "HTML Files (*.html; *.htm; *.shtml; *.shtm; *.mhtml; *.mhtm; *.xhtml; *.xht; *.hta)"},
    {IDL, "IDL Files (*.idl)"},
    {IntelHex, "Intel Hex Files (*.hex)"},
    {Java, "Java Files (*.java)"},
    {JavaScript, "JavaScript Files (*.js; *.jsm; *.jsx; *.mjs)"},
    {JSON, "JSON Files (*.json)"},
    {LaTeX, "LaTeX Files (*.tex; *.sty; *.latex)"},
    {Lua, "Lua Files (*.lua)"},
    {Makefile, "Makefile Files (*.mk; *.mak; *.make; *.makefile)"},
    {Markdown, "Markdown Files (*.md; *.commonmark; *.markdown)"},
    {MASM, "MASM Assembly Files (*.asm; *.masm)"},
    {Matlab, "Matlab Files (*.m; *.matlab)"},
    {NASM, "NASM Assembly Files (*.nasm)"},
    {Octave, "Octave Files (*.oct; *.octave)"},
    {Pascal, "Pascal Files (*.pas; *.pp; *.p; *.inc; *.lpr)"},
    {Perl, "Perl Files (*.pl; *.pm; *.plx; *.t)"},
    {PHP, "PHP Files (*.php; *.php3; *.php4; *.php5; *.phps; *.phpt; *.phtml; *.phtm)"},
    {PO, "PO/ GNU/GetText Files (*.po)"},
    {PostScript, "PostScript Files (*.ps)"},
    {POV, "POV-Ray Files (*.pov; *.povray)"},
    {Properties, "Properties Files (*.properties; *.conf; *.cfg; *.gitattributes; *.gitconfig; *.gitmodules; "
     "*.editorconfig)"},
    {Python2, "Python 2 Files (*.py2)"},
    {Python3, "Python 3 Files (*.py; *.pyw; *.py3; *.pyx; *.pyd; *.pyi; *.spec; *.egg; *.egg-info; *.dist-info; "
     "*.whl)"},
    {QML, "Qt Modeling Language Files (*.qml)"},
    {QSS, "Qt Style Sheets Files (*.qss)"},
    {QUI, "Qt User Interface Files (*.qs; *.cw)"},
    {Ruby, "Ruby Files (*.ruby; *.rb; *.rbw; *.rbx; *.gem)"},
    {Spice, "Spice Files (*.spice; *.scp; *.out)"},
    {SQL, "Structured Query Language Files (*.sql)"},
    {SRecord, "S-Record Hex Files (*.srec; *.mot)"},
    {TCL, "Tool Command Language Files (*.tcl)"},
    {TektronixHex, "Tektronix Hex Files (*.tek)"},
    {TeX, "TeX Files (*.tex)"},
    {Verilog, "Verilog Files (*.v; *.sv; *.vh; *.svh)"},
    {VHDL, "VHSIC Hardware Description Language Files (*.vhdl; *.vhd)"},
    {XML,     "X-tended Markup Language Files (*.xml; *.qrc; *.rcc; *.xaml; *.xsl; *.xslt; *.xsd; *.xul; *.kml; *.svg; "
     "*.mxml; *.wsdl; *.xlf; *.xliff; *.xbl; *.sxbl; *.sitemap; *.gml; *.gpx; *.plist; *.vcproj; *.vcxproj; *.csproj; "
     "*.csxproj; *.vbproj; *.vbxproj; *.ui; *.rc)"},
    {YAML, "YAML Files (*.yaml)"}
};

inline const QMap<QString, Languages> extensionToLanguages = {
    {"as", ActionScript},
    {"mx", ActionScript},
    {"asp", ASP},
    {"aspx", ASP},
    {"avs", AviSynth},
    {"avsi", AviSynth},
    {"bash", Bash},
    {"sh", Bash},
    {"bsh", Bash},
    {"csh", Bash},
    {"bash_profile", Bash},
    {"bashrc", Bash},
    {"profile", Bash},
    {"bat", Batch},
    {"cmd", Batch},
    {"nt", Batch},
    {"bb", BlitzBasic},
    {"pb", PureBasic},
    {"bas", FreeBasic},
    {"bi", FreeBasic},
    {"c", C},
    {"lex", C},
    {"i", C},
    {"cpp", CPP},
    {"cxx", CPP},
    {"cc", CPP},
    {"cp", CPP},
    {"c++", CPP},
    {"hpp", CPP},
    {"h", CPP},
    {"hxx", CPP},
    {"hh", CPP},
    {"hp", CPP},
    {"h++", CPP},
    {"ino", CPP},
    {"i++", CPP},
    {"ii", CPP},
    {"cs", CS},
    {"cmake", CMake},
    {"coffee", CoffeeScript},
    {"litcoffee", CoffeeScript},
    {"css", CSS},
    {"d", D},
    {"diff", Diff},
    {"patch", Diff},
    {"f", Fortran},
    {"for", Fortran},
    {"f90", Fortran},
    {"f95", Fortran},
    {"f2k", Fortran},
    {"f23", Fortran},
    {"fortran", Fortran},
    {"f77", Fortran77},
    {"gd", GDScript},
    {"html", HTMLFull},
    {"htm", HTMLFull},
    {"shtml", HTMLFull},
    {"shtm", HTMLFull},
    {"mhtml", HTMLFull},
    {"mhtm", HTMLFull},
    {"xhtml", HTMLFull},
    {"xht", HTMLFull},
    {"hta", HTMLFull},
    {"idl", IDL},
    {"hex", IntelHex},
    {"java", Java},
    {"js", JavaScript},
    {"jsm", JavaScript},
    {"jsx", JavaScript},
    {"mjs", JavaScript},
    {"json", JSON},
    {"sty", LaTeX},
    {"latex", LaTeX},
    {"lua", Lua},
    {"mk", Makefile},
    {"mak", Makefile},
    {"make", Makefile},
    {"makefile", Makefile},
    {"md", Markdown},
    {"commonmark", Markdown},
    {"markdown", Markdown},
    {"asm", MASM},
    {"masm", MASM},
    {"m", Matlab},
    {"matlab", Matlab},
    {"nasm", NASM},
    {"oct", Octave},
    {"pas", Pascal},
    {"pp", Pascal},
    {"p", Pascal},
    {"inc", Pascal},
    {"lpr", Pascal},
    {"pl", Perl},
    {"pm", Perl},
    {"plx", Perl},
    {"t", Perl},
    {"php", PHP},
    {"php3", PHP},
    {"php4", PHP},
    {"php5", PHP},
    {"phpt", PHP},
    {"phtml", PHP},
    {"phtm", PHP},
    {"po", PO},
    {"ps", PostScript},
    {"pov", POV},
    {"povray", POV},
    {"properties", Properties},
    {"conf", Properties},
    {"cfg", Properties},
    {"gitattributes", Properties},
    {"gitconfig", Properties},
    {"gitmodules", Properties},
    {"editorconfig", Properties},
    {"py2", Python2},
    {"py", Python3Extended},
    {"pyw", Python3Extended},
    {"pyx", Python3Extended},
    {"pyd", Python3Extended},
    {"pyi", Python3Extended},
    {"spec", Python3Extended},
    {"egg", Python3Extended},
    {"egg-info", Python3Extended},
    {"dist-info", Python3Extended},
    {"whl", Python3Extended},
    {"qml", QML},
    {"qss", QSS},
    {"ui", QUI},
    {"cw", QUI},
    {"ruby", Ruby},
    {"rb", Ruby},
    {"rbw", Ruby},
    {"rbx", Ruby},
    {"gem", Ruby},
    {"spice", Spice},
    {"scp", Spice},
    {"out", Spice},
    {"sql", SQL},
    {"srec", SRecord},
    {"mot", SRecord},
    {"tcl", TCL},
    {"tek", TektronixHex},
    {"tex", TeX},
    {"v", Verilog},
    {"sv", Verilog},
    {"vh", Verilog},
    {"svh", Verilog},
    {"vhdl", VHDL},
    {"vhd", VHDL},
    {"xml", XML},
    {"qrc", XML},
    {"rcc", XML},
    {"xaml", XML},
    {"xsl", XML},
    {"xslt", XML},
    {"xsd", XML},
    {"xul", XML},
    {"kml", XML},
    {"svg", XML},
    {"mxml", XML},
    {"wsdl", XML},
    {"xlf", XML},
    {"xliff", XML},
    {"xbl", XML},
    {"sxbl", XML},
    {"sitemap", XML},
    {"gml", XML},
    {"gpx", XML},
    {"plist", XML},
    {"vcproj", XML},
    {"vcxproj", XML},
    {"csproj", XML},
    {"csxproj", XML},
    {"ui", XML},
    {"rc", XML},
    {"yaml", YAML},
};

inline const char *fileErrorReason(QFile::FileError code)
{
    switch (code)
    {
    case QFile::FileError::ReadError:
        return "The file could not be read.\nError code: 0x0000F002";
    case QFile::FileError::WriteError:
        return "The file could not be written.\nError code: 0x0000F003";
    case QFile::FileError::FatalError:
        return "The file action could not proceed because of a critical error.\nError code: 0x0000F004";
    case QFile::FileError::ResourceError:
        return "The computer is out of resource (too many open files or out of memory, etc.)\nError code: 0x0000F005";
    case QFile::FileError::OpenError:
        return "The file could not be opened.\nError code: 0x0000F006";
    case QFile::FileError::AbortError:
        return "The file operation was aborted due to a specific reason.\nError code: 0x0000F007";
    case QFile::FileError::TimeOutError:
        return "The file was too long to response, i.e. a timeout error.\nError code: 0x0000F008";
    case QFile::FileError::UnspecifiedError:
        return "An unknown error occurred.\nError code: 0x0000F009";
    case QFile::FileError::RemoveError:
        return "The file could not be removed.\nError code: 0x0000F00A";
    case QFile::FileError::RenameError:
        return "The fild could not be renamed.\nError code: 0x0000F00B";
    case QFile::FileError::PositionError:
        return "The position in the file could not be changed.\nError code: 0x0000F00C";
    case QFile::FileError::ResizeError:
        return "The file could not be resized.\nError code: 0x0000F00D";
    case QFile::FileError::PermissionsError:
        return "The file could not be accessed.\nError code: 0x0000F00E";
    case QFile::FileError::CopyError:
        return "The file could not be copied.\nError code: 0x0000F00F";
    default:
        return "";
    }
}

#endif // TPGLOBALS_HPP
