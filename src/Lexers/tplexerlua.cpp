#include <Lexers/TpLexerLua>

TP_NAMESPACE

TpLexerLua::TpLexerLua(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldCompact(true)
{}

TpLexerLua::~TpLexerLua()
{}

const char *TpLexerLua::language() const
{
    return "Lua";
}

const char *TpLexerLua::lexer() const
{
    return "lua";
}

QStringList TpLexerLua::autoCompletionWordSeparators() const
{
    QStringList wordList;

    wordList << ":" << ".";

    return wordList;
}

const char *TpLexerLua::blockStart(int *style) const
{
    if (style)
        *style = Operator;

    return "";
}

int TpLexerLua::braceStyle() const
{
    return Operator;
}

QColor TpLexerLua::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Lua/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Lua/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/Lua/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Lua/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Lua/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Lua/Color/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/Lua/Color/String", QColor);
    case Character:
        return GET_SETTINGS("Lexer/Lua/Color/Character", QColor);
    case LiteralString:
        return GET_SETTINGS("Lexer/Lua/Color/LiteralString", QColor);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Lua/Color/Preprocessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Lua/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Lua/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Lua/Color/UnclosedString", QColor);
    case BasicFunctions:
        return GET_SETTINGS("Lexer/Lua/Color/BasicFunctions", QColor);
    case StringTableMathsFunctions:
        return GET_SETTINGS("Lexer/Lua/Color/StringTableMathsFunction", QColor);
    case CoroutinesIOSystemFacilities:
        return GET_SETTINGS("Lexer/Lua/Color/CoroutinesIOSystemFacilities", QColor);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/Lua/Color/KeywordSet5", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/Lua/Color/KeywordSet6", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/Lua/Color/KeywordSet7", QColor);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/Lua/Color/KeywordSet8", QColor);
    case Label:
        return GET_SETTINGS("Lexer/Lua/Color/Label", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerLua::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Lua/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Lua/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/Lua/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Lua/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/Lua/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Lua/Fill/Keyword", bool);
    case String:
        return GET_SETTINGS("Lexer/Lua/Fill/String", bool);
    case Character:
        return GET_SETTINGS("Lexer/Lua/Fill/Character", bool);
    case LiteralString:
        return GET_SETTINGS("Lexer/Lua/Fill/LiteralString", bool);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Lua/Fill/Preprocessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Lua/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Lua/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Lua/Fill/UnclosedString", bool);
    case BasicFunctions:
        return GET_SETTINGS("Lexer/Lua/Fill/BasicFunctions", bool);
    case StringTableMathsFunctions:
        return GET_SETTINGS("Lexer/Lua/Fill/StringTableMathsFunction", bool);
    case CoroutinesIOSystemFacilities:
        return GET_SETTINGS("Lexer/Lua/Fill/CoroutinesIOSystemFacilities", bool);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/Lua/Fill/KeywordSet5", bool);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/Lua/Fill/KeywordSet6", bool);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/Lua/Fill/KeywordSet7", bool);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/Lua/Fill/KeywordSet8", bool);
    case Label:
        return GET_SETTINGS("Lexer/Lua/Fill/Label", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerLua::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Lua/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Lua/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/Lua/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Lua/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Lua/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Lua/Font/Keyword", QFont);
    case String:
        return GET_SETTINGS("Lexer/Lua/Font/String", QFont);
    case Character:
        return GET_SETTINGS("Lexer/Lua/Font/Character", QFont);
    case LiteralString:
        return GET_SETTINGS("Lexer/Lua/Font/LiteralString", QFont);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Lua/Font/Preprocessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Lua/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Lua/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Lua/Font/UnclosedString", QFont);
    case BasicFunctions:
        return GET_SETTINGS("Lexer/Lua/Font/BasicFunctions", QFont);
    case StringTableMathsFunctions:
        return GET_SETTINGS("Lexer/Lua/Font/StringTableMathsFunction", QFont);
    case CoroutinesIOSystemFacilities:
        return GET_SETTINGS("Lexer/Lua/Font/CoroutinesIOSystemFacilities", QFont);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/Lua/Font/KeywordSet5", QFont);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/Lua/Font/KeywordSet6", QFont);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/Lua/Font/KeywordSet7", QFont);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/Lua/Font/KeywordSet8", QFont);
    case Label:
        return GET_SETTINGS("Lexer/Lua/Font/Label", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerLua::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Lua/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Lua/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/Lua/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/Lua/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Lua/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Lua/BgColor/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/Lua/BgColor/String", QColor);
    case Character:
        return GET_SETTINGS("Lexer/Lua/BgColor/Character", QColor);
    case LiteralString:
        return GET_SETTINGS("Lexer/Lua/BgColor/LiteralString", QColor);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Lua/BgColor/Preprocessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Lua/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Lua/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Lua/BgColor/UnclosedString", QColor);
    case BasicFunctions:
        return GET_SETTINGS("Lexer/Lua/BgColor/BasicFunctions", QColor);
    case StringTableMathsFunctions:
        return GET_SETTINGS("Lexer/Lua/BgColor/StringTableMathsFunction", QColor);
    case CoroutinesIOSystemFacilities:
        return GET_SETTINGS("Lexer/Lua/BgColor/CoroutinesIOSystemFacilities", QColor);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/Lua/BgColor/KeywordSet5", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/Lua/BgColor/KeywordSet6", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/Lua/BgColor/KeywordSet7", QColor);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/Lua/BgColor/KeywordSet8", QColor);
    case Label:
        return GET_SETTINGS("Lexer/Lua/BgColor/Label", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerLua::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerLuaKeyword1;
    case 2:
        return lexerLuaKeyword2;
    case 3:
        return lexerLuaKeyword3;
    case 4:
        return lexerLuaKeyword4;
    default:
        return 0;
    }
}

QString TpLexerLua::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case CommentLine:
        return tr("Line comment");
    case CommentDoc:
       return tr("Javadoc style comment");
    case Number:
        return tr("Number");
    case Keyword:
        return tr("Keyword");
    case String:
        return tr("String");
    case Character:
        return tr("Character");
    case LiteralString:
        return tr("Literal string");
    case Preprocessor:
        return tr("Preprocessor");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case UnclosedString:
        return tr("Unclosed string");
    case BasicFunctions:
        return tr("Basic functions");
    case StringTableMathsFunctions:
        return tr("String, table and maths functions");
    case CoroutinesIOSystemFacilities:
        return tr("Coroutines, i/o and system facilities");
    case KeywordSet5:
        return tr("User defined 1");
    case KeywordSet6:
        return tr("User defined 2");
    case KeywordSet7:
        return tr("User defined 3");
    case KeywordSet8:
        return tr("User defined 4");
    case Label:
        return tr("Label");
    }

    return QString();
}

void TpLexerLua::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
}

void TpLexerLua::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerLua::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldCompact:
        return m_foldCompact;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerLua::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);

    return true;
}

bool TpLexerLua::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);

    return true;
}

TP_END_NAMESPACE
