#include <Lexers/TpLexerPostScript>

TP_NAMESPACE

TpLexerPostScript::TpLexerPostScript(QObject *parent)
    : TpGeneralLexer(parent),
    m_tokenize(true),
    m_level(PSThirdLevel),
    m_foldCompact(true),
    m_foldAtElse(true)
{}

TpLexerPostScript::~TpLexerPostScript()
{}

const char *TpLexerPostScript::language() const
{
    return "PostScript";
}

const char *TpLexerPostScript::lexer() const
{
    return "ps";
}

int TpLexerPostScript::braceStyle() const
{
    return ProcedureParenthesis;
}

QColor TpLexerPostScript::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PostScript/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/PostScript/Color/Comment", QColor);
    case DSCComment:
        return GET_SETTINGS("Lexer/PostScript/Color/DSCComment", QColor);
    case DSCCommentValue:
        return GET_SETTINGS("Lexer/PostScript/Color/DSCCommentValue", QColor);
    case Number:
        return GET_SETTINGS("Lexer/PostScript/Color/Number", QColor);
    case Name:
        return GET_SETTINGS("Lexer/PostScript/Color/Name", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/PostScript/Color/Keyword", QColor);
    case Literal:
        return GET_SETTINGS("Lexer/PostScript/Color/Literal", QColor);
    case ImmediateEvalLiteral:
        return GET_SETTINGS("Lexer/PostScript/Color/ImmediateEvalLiteral", QColor);
    case ArrayParenthesis:
        return GET_SETTINGS("Lexer/PostScript/Color/ArrayParenthesis", QColor);
    case DictionaryParenthesis:
        return GET_SETTINGS("Lexer/PostScript/Color/DictionaryParenthesis", QColor);
    case ProcedureParenthesis:
        return GET_SETTINGS("Lexer/PostScript/Color/ProcedureParenthesis", QColor);
    case Text:
        return GET_SETTINGS("Lexer/PostScript/Color/Text", QColor);
    case HexString:
        return GET_SETTINGS("Lexer/PostScript/Color/HexString", QColor);
    case Base85String:
        return GET_SETTINGS("Lexer/PostScript/Color/Base85String", QColor);
    case BadStringCharacter:
        return GET_SETTINGS("Lexer/PostScript/Color/BadStringCharacter", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerPostScript::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PostScript/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/PostScript/Fill/Comment", bool);
    case DSCComment:
        return GET_SETTINGS("Lexer/PostScript/Fill/DSCComment", bool);
    case DSCCommentValue:
        return GET_SETTINGS("Lexer/PostScript/Fill/DSCCommentValue", bool);
    case Number:
        return GET_SETTINGS("Lexer/PostScript/Fill/Number", bool);
    case Name:
        return GET_SETTINGS("Lexer/PostScript/Fill/Name", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/PostScript/Fill/Keyword", bool);
    case Literal:
        return GET_SETTINGS("Lexer/PostScript/Fill/Literal", bool);
    case ImmediateEvalLiteral:
        return GET_SETTINGS("Lexer/PostScript/Fill/ImmediateEvalLiteral", bool);
    case ArrayParenthesis:
        return GET_SETTINGS("Lexer/PostScript/Fill/ArrayParenthesis", bool);
    case DictionaryParenthesis:
        return GET_SETTINGS("Lexer/PostScript/Fill/DictionaryParenthesis", bool);
    case ProcedureParenthesis:
        return GET_SETTINGS("Lexer/PostScript/Fill/ProcedureParenthesis", bool);
    case Text:
        return GET_SETTINGS("Lexer/PostScript/Fill/Text", bool);
    case HexString:
        return GET_SETTINGS("Lexer/PostScript/Fill/HexString", bool);
    case Base85String:
        return GET_SETTINGS("Lexer/PostScript/Fill/Base85String", bool);
    case BadStringCharacter:
        return GET_SETTINGS("Lexer/PostScript/Fill/BadStringCharacter", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerPostScript::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PostScript/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/PostScript/Font/Comment", QFont);
    case DSCComment:
        return GET_SETTINGS("Lexer/PostScript/Font/DSCComment", QFont);
    case DSCCommentValue:
        return GET_SETTINGS("Lexer/PostScript/Font/DSCCommentValue", QFont);
    case Number:
        return GET_SETTINGS("Lexer/PostScript/Font/Number", QFont);
    case Name:
        return GET_SETTINGS("Lexer/PostScript/Font/Name", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/PostScript/Font/Keyword", QFont);
    case Literal:
        return GET_SETTINGS("Lexer/PostScript/Font/Literal", QFont);
    case ImmediateEvalLiteral:
        return GET_SETTINGS("Lexer/PostScript/Font/ImmediateEvalLiteral", QFont);
    case ArrayParenthesis:
        return GET_SETTINGS("Lexer/PostScript/Font/ArrayParenthesis", QFont);
    case DictionaryParenthesis:
        return GET_SETTINGS("Lexer/PostScript/Font/DictionaryParenthesis", QFont);
    case ProcedureParenthesis:
        return GET_SETTINGS("Lexer/PostScript/Font/ProcedureParenthesis", QFont);
    case Text:
        return GET_SETTINGS("Lexer/PostScript/Font/Text", QFont);
    case HexString:
        return GET_SETTINGS("Lexer/PostScript/Font/HexString", QFont);
    case Base85String:
        return GET_SETTINGS("Lexer/PostScript/Font/Base85String", QFont);
    case BadStringCharacter:
        return GET_SETTINGS("Lexer/PostScript/Font/BadStringCharacter", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerPostScript::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PostScript/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/PostScript/BgColor/Comment", QColor);
    case DSCComment:
        return GET_SETTINGS("Lexer/PostScript/BgColor/DSCComment", QColor);
    case DSCCommentValue:
        return GET_SETTINGS("Lexer/PostScript/BgColor/DSCCommentValue", QColor);
    case Number:
        return GET_SETTINGS("Lexer/PostScript/BgColor/Number", QColor);
    case Name:
        return GET_SETTINGS("Lexer/PostScript/BgColor/Name", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/PostScript/BgColor/Keyword", QColor);
    case Literal:
        return GET_SETTINGS("Lexer/PostScript/BgColor/Literal", QColor);
    case ImmediateEvalLiteral:
        return GET_SETTINGS("Lexer/PostScript/BgColor/ImmediateEvalLiteral", QColor);
    case ArrayParenthesis:
        return GET_SETTINGS("Lexer/PostScript/BgColor/ArrayParenthesis", QColor);
    case DictionaryParenthesis:
        return GET_SETTINGS("Lexer/PostScript/BgColor/DictionaryParenthesis", QColor);
    case ProcedureParenthesis:
        return GET_SETTINGS("Lexer/PostScript/BgColor/ProcedureParenthesis", QColor);
    case Text:
        return GET_SETTINGS("Lexer/PostScript/BgColor/Text", QColor);
    case HexString:
        return GET_SETTINGS("Lexer/PostScript/BgColor/HexString", QColor);
    case Base85String:
        return GET_SETTINGS("Lexer/PostScript/BgColor/Base85String", QColor);
    case BadStringCharacter:
        return GET_SETTINGS("Lexer/PostScript/BgColor/BadStringCharacter", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerPostScript::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerPostScriptKeyword1;
    case 2:
        return lexerPostScriptKeyword2;
    case 3:
        return lexerPostScriptKeyword3;
    case 4:
        return lexerPostScriptKeyword4;
    default:
        return 0;
    }
}

QString TpLexerPostScript::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case DSCComment:
        return tr("DSC comment");
    case DSCCommentValue:
        return tr("DSC comment value");
    case Number:
        return tr("Number");
    case Name:
        return tr("Name");
    case Keyword:
        return tr("Keyword");
    case Literal:
        return tr("Literal");
    case ImmediateEvalLiteral:
        return tr("Immediately evaluated literal");
    case ArrayParenthesis:
        return tr("Array parenthesis");
    case DictionaryParenthesis:
        return tr("Dictionary parenthesis");
    case ProcedureParenthesis:
        return tr("Procedure parenthesis");
    case Text:
        return tr("Text");
    case HexString:
        return tr("Hexadecimal string");
    case Base85String:
        return tr("Base85 string");
    case BadStringCharacter:
        return tr("Bad string character");
    }

    return QString();
}

void TpLexerPostScript::refreshProperties()
{
    setLexerProperty(PropTokenize, m_tokenize);
    setLexerProperty(PropLevel, m_level);
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldAtElse, m_foldAtElse);
}

void TpLexerPostScript::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropTokenize: {
        m_tokenize = value.toBool();
        emit propertyChanged("ps.tokenize", (m_tokenize ? "1" : "0"));
        break;
    }
    case PropLevel: {
        m_level = value.toInt();
        emit propertyChanged("ps.level", textAsBytes(QString::number(m_level)).constData());
        break;
    }
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
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

QVariant TpLexerPostScript::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropTokenize:
        return m_tokenize;
    case PropLevel:
        return m_level;
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldAtElse:
        return m_foldAtElse;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerPostScript::readProperties(QSettings &settings, const QString &prefix)
{
    m_tokenize = GET_SETTINGS_WITH(prefix + "tokenize", bool, true);
    m_level = GET_SETTINGS_WITH(prefix + "level", int, PSThirdLevel);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldAtElse = GET_SETTINGS_WITH(prefix + "foldatelse", bool, true);

    return true;
}

bool TpLexerPostScript::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "tokenize", m_tokenize);
    SET_SETTINGS(prefix + "level", m_level);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldatelse", m_foldAtElse);

    return true;
}

TP_END_NAMESPACE
