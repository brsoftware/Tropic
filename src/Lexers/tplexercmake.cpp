#include <Lexers/TpLexerCMake>

TP_NAMESPACE

TpLexerCMake::TpLexerCMake(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldAtElse(true)
{}

TpLexerCMake::~TpLexerCMake()
{}

const char *TpLexerCMake::language() const
{
    return "CMake";
}

const char *TpLexerCMake::lexer() const
{
    return "cmake";
}

QColor TpLexerCMake::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CMake/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CMake/Color/Comment", QColor);
    case String:
        return GET_SETTINGS("Lexer/CMake/Color/String", QColor);
    case StringLeftQuote:
        return GET_SETTINGS("Lexer/CMake/Color/StringLeftQuote", QColor);
    case StringRightQuote:
        return GET_SETTINGS("Lexer/CMake/Color/StringRightQuote", QColor);
    case Function:
        return GET_SETTINGS("Lexer/CMake/Color/Function", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/CMake/Color/Variable", QColor);
    case Label:
        return GET_SETTINGS("Lexer/CMake/Color/Label", QColor);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/CMake/Color/KeywordSet3", QColor);
    case BlockWhile:
        return GET_SETTINGS("Lexer/CMake/Color/BlockWhilte", QColor);
    case BlockForeach:
        return GET_SETTINGS("Lexer/CMake/Color/BlockForeach", QColor);
    case BlockIf:
        return GET_SETTINGS("Lexer/CMake/Color/BlockIf", QColor);
    case BlockMacro:
        return GET_SETTINGS("Lexer/CMake/Color/BlockMacro", QColor);
    case StringVariable:
        return GET_SETTINGS("Lexer/CMake/Color/StringVariable", QColor);
    case Number:
        return GET_SETTINGS("Lexer/CMake/Color/Number", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerCMake::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CMake/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/CMake/Fill/Comment", bool);
    case String:
        return GET_SETTINGS("Lexer/CMake/Fill/String", bool);
    case StringLeftQuote:
        return GET_SETTINGS("Lexer/CMake/Fill/StringLeftQuote", bool);
    case StringRightQuote:
        return GET_SETTINGS("Lexer/CMake/Fill/StringRightQuote", bool);
    case Function:
        return GET_SETTINGS("Lexer/CMake/Fill/Function", bool);
    case Variable:
        return GET_SETTINGS("Lexer/CMake/Fill/Variable", bool);
    case Label:
        return GET_SETTINGS("Lexer/CMake/Fill/Label", bool);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/CMake/Fill/KeywordSet3", bool);
    case BlockWhile:
        return GET_SETTINGS("Lexer/CMake/Fill/BlockWhilte", bool);
    case BlockForeach:
        return GET_SETTINGS("Lexer/CMake/Fill/BlockForeach", bool);
    case BlockIf:
        return GET_SETTINGS("Lexer/CMake/Fill/BlockIf", bool);
    case BlockMacro:
        return GET_SETTINGS("Lexer/CMake/Fill/BlockMacro", bool);
    case StringVariable:
        return GET_SETTINGS("Lexer/CMake/Fill/StringVariable", bool);
    case Number:
        return GET_SETTINGS("Lexer/CMake/Fill/Number", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerCMake::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CMake/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/CMake/Font/Comment", QFont);
    case String:
        return GET_SETTINGS("Lexer/CMake/Font/String", QFont);
    case StringLeftQuote:
        return GET_SETTINGS("Lexer/CMake/Font/StringLeftQuote", QFont);
    case StringRightQuote:
        return GET_SETTINGS("Lexer/CMake/Font/StringRightQuote", QFont);
    case Function:
        return GET_SETTINGS("Lexer/CMake/Font/Function", QFont);
    case Variable:
        return GET_SETTINGS("Lexer/CMake/Font/Variable", QFont);
    case Label:
        return GET_SETTINGS("Lexer/CMake/Font/Label", QFont);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/CMake/Font/KeywordSet3", QFont);
    case BlockWhile:
        return GET_SETTINGS("Lexer/CMake/Font/BlockWhilte", QFont);
    case BlockForeach:
        return GET_SETTINGS("Lexer/CMake/Font/BlockForeach", QFont);
    case BlockIf:
        return GET_SETTINGS("Lexer/CMake/Font/BlockIf", QFont);
    case BlockMacro:
        return GET_SETTINGS("Lexer/CMake/Font/BlockMacro", QFont);
    case StringVariable:
        return GET_SETTINGS("Lexer/CMake/Font/StringVariable", QFont);
    case Number:
        return GET_SETTINGS("Lexer/CMake/Font/Number", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerCMake::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/CMake/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/CMake/BgColor/Comment", QColor);
    case String:
        return GET_SETTINGS("Lexer/CMake/BgColor/String", QColor);
    case StringLeftQuote:
        return GET_SETTINGS("Lexer/CMake/BgColor/StringLeftQuote", QColor);
    case StringRightQuote:
        return GET_SETTINGS("Lexer/CMake/BgColor/StringRightQuote", QColor);
    case Function:
        return GET_SETTINGS("Lexer/CMake/BgColor/Function", QColor);
    case Variable:
        return GET_SETTINGS("Lexer/CMake/BgColor/Variable", QColor);
    case Label:
        return GET_SETTINGS("Lexer/CMake/BgColor/Label", QColor);
    case KeywordSet3:
        return GET_SETTINGS("Lexer/CMake/BgColor/KeywordSet3", QColor);
    case BlockWhile:
        return GET_SETTINGS("Lexer/CMake/BgColor/BlockWhilte", QColor);
    case BlockForeach:
        return GET_SETTINGS("Lexer/CMake/BgColor/BlockForeach", QColor);
    case BlockIf:
        return GET_SETTINGS("Lexer/CMake/BgColor/BlockIf", QColor);
    case BlockMacro:
        return GET_SETTINGS("Lexer/CMake/BgColor/BlockMacro", QColor);
    case StringVariable:
        return GET_SETTINGS("Lexer/CMake/BgColor/StringVariable", QColor);
    case Number:
        return GET_SETTINGS("Lexer/CMake/BgColor/Number", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerCMake::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerCMakeKeyword1;
    case 2:
        return lexerCMakeKeyword2;
    default:
        return 0;
    }
}

QString TpLexerCMake::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case String:
        return tr("String");
    case StringLeftQuote:
        return tr("Left quoted string");
    case StringRightQuote:
        return tr("Right quoted string");
    case Function:
        return tr("Function");
    case Variable:
        return tr("Variable");
    case Label:
        return tr("Label");
    case KeywordSet3:
        return tr("User defined");
    case BlockWhile:
        return tr("WHILE block");
    case BlockForeach:
        return tr("FOREACH block");
    case BlockIf:
        return tr("IF block");
    case BlockMacro:
        return tr("MACRO block");
    case StringVariable:
        return tr("Variable within a string");
    case Number:
        return tr("Number");
    }

    return QString();
}

void TpLexerCMake::refreshProperties()
{
    setLexerProperty(PropFoldAtElse, m_foldAtElse);
}

void TpLexerCMake::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFoldAtElse: {
        m_foldAtElse = value.toBool();
        emit propertyChanged("fold.at.else", (m_foldAtElse ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerCMake::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldAtElse:
        return m_foldAtElse;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerCMake::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldAtElse = GET_SETTINGS_WITH(prefix + "foldatelse", bool, true);

    return true;
}

bool TpLexerCMake::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldatelse", m_foldAtElse);

    return true;
}

TP_END_NAMESPACE
