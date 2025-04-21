#include <Lexers/TpLexerVHDL>

TP_NAMESPACE

TpLexerVHDL::TpLexerVHDL(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true),
    m_foldCompact(true),
    m_foldAtElse(true),
    m_foldAtBegin(true),
    m_foldAtParenthesis(true)
{}

TpLexerVHDL::~TpLexerVHDL()
{}

const char *TpLexerVHDL::language() const
{
    return "VHDL";
}

const char *TpLexerVHDL::lexer() const
{
    return "vhdl";
}

int TpLexerVHDL::braceStyle() const
{
    return Attribute;
}

QColor TpLexerVHDL::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/VHDL/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/VHDL/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/VHDL/Color/CommentLine", QColor);
    case Number:
        return GET_SETTINGS("Lexer/VHDL/Color/Number", QColor);
    case String:
        return GET_SETTINGS("Lexer/VHDL/Color/String", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/VHDL/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/VHDL/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/VHDL/Color/UnclosedString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/VHDL/Color/Keyword", QColor);
    case StandardOperator:
        return GET_SETTINGS("Lexer/VHDL/Color/StandardOperator", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/VHDL/Color/Attribute", QColor);
    case StandardFunction:
        return GET_SETTINGS("Lexer/VHDL/Color/StandardFunction", QColor);
    case StandardPackage:
        return GET_SETTINGS("Lexer/VHDL/Color/StandardPackage", QColor);
    case StandardType:
        return GET_SETTINGS("Lexer/VHDL/Color/StandardType", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/VHDL/Color/KeywordSet7", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/VHDL/Color/CommentBlock", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerVHDL::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/VHDL/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/VHDL/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/VHDL/Fill/CommentLine", bool);
    case Number:
        return GET_SETTINGS("Lexer/VHDL/Fill/Number", bool);
    case String:
        return GET_SETTINGS("Lexer/VHDL/Fill/String", bool);
    case Operator:
        return GET_SETTINGS("Lexer/VHDL/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/VHDL/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/VHDL/Fill/UnclosedString", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/VHDL/Fill/Keyword", bool);
    case StandardOperator:
        return GET_SETTINGS("Lexer/VHDL/Fill/StandardOperator", bool);
    case Attribute:
        return GET_SETTINGS("Lexer/VHDL/Fill/Attribute", bool);
    case StandardFunction:
        return GET_SETTINGS("Lexer/VHDL/Fill/StandardFunction", bool);
    case StandardPackage:
        return GET_SETTINGS("Lexer/VHDL/Fill/StandardPackage", bool);
    case StandardType:
        return GET_SETTINGS("Lexer/VHDL/Fill/StandardType", bool);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/VHDL/Fill/KeywordSet7", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/VHDL/Fill/CommentBlock", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerVHDL::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/VHDL/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/VHDL/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/VHDL/Font/CommentLine", QFont);
    case Number:
        return GET_SETTINGS("Lexer/VHDL/Font/Number", QFont);
    case String:
        return GET_SETTINGS("Lexer/VHDL/Font/String", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/VHDL/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/VHDL/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/VHDL/Font/UnclosedString", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/VHDL/Font/Keyword", QFont);
    case StandardOperator:
        return GET_SETTINGS("Lexer/VHDL/Font/StandardOperator", QFont);
    case Attribute:
        return GET_SETTINGS("Lexer/VHDL/Font/Attribute", QFont);
    case StandardFunction:
        return GET_SETTINGS("Lexer/VHDL/Font/StandardFunction", QFont);
    case StandardPackage:
        return GET_SETTINGS("Lexer/VHDL/Font/StandardPackage", QFont);
    case StandardType:
        return GET_SETTINGS("Lexer/VHDL/Font/StandardType", QFont);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/VHDL/Font/KeywordSet7", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/VHDL/Font/CommentBlock", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerVHDL::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/VHDL/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/VHDL/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/VHDL/BgColor/CommentLine", QColor);
    case Number:
        return GET_SETTINGS("Lexer/VHDL/BgColor/Number", QColor);
    case String:
        return GET_SETTINGS("Lexer/VHDL/BgColor/String", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/VHDL/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/VHDL/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/VHDL/BgColor/UnclosedString", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/VHDL/BgColor/Keyword", QColor);
    case StandardOperator:
        return GET_SETTINGS("Lexer/VHDL/BgColor/StandardOperator", QColor);
    case Attribute:
        return GET_SETTINGS("Lexer/VHDL/BgColor/Attribute", QColor);
    case StandardFunction:
        return GET_SETTINGS("Lexer/VHDL/BgColor/StandardFunction", QColor);
    case StandardPackage:
        return GET_SETTINGS("Lexer/VHDL/BgColor/StandardPackage", QColor);
    case StandardType:
        return GET_SETTINGS("Lexer/VHDL/BgColor/StandardType", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/VHDL/BgColor/KeywordSet7", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/VHDL/BgColor/CommentBlock", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerVHDL::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerVHDLKeyword1;
    case 2:
        return lexerVHDLKeyword2;
    case 3:
        return lexerVHDLKeyword3;
    case 4:
        return lexerVHDLKeyword4;
    case 5:
        return lexerVHDLKeyword5;
    case 6:
        return lexerVHDLKeyword6;
    default:
        return 0;
    }
}

QString TpLexerVHDL::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case CommentLine:
        return tr("Comment line");
    case Number:
        return tr("Number");
    case String:
        return tr("String");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case UnclosedString:
        return tr("Unclosed string");
    case Keyword:
        return tr("Keyword");
    case StandardOperator:
        return tr("Standard operator");
    case Attribute:
        return tr("Attribute");
    case StandardFunction:
        return tr("Standard function");
    case StandardPackage:
        return tr("Standard package");
    case StandardType:
        return tr("Standard type");
    case KeywordSet7:
        return tr("User defined");
    case CommentBlock:
        return tr("Comment block");
    }

    return QString();
}

void TpLexerVHDL::refreshProperties()
{
    setLexerProperty(PropFoldAtElse, m_foldAtElse);
    setLexerProperty(PropFoldComments, m_foldComments);
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldAtBegin, m_foldAtBegin);
    setLexerProperty(PropFoldAtParenthesis, m_foldAtParenthesis);
}

void TpLexerVHDL::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFoldAtElse: {
        m_foldAtElse = value.toBool();
        emit propertyChanged("fold.at.else", (m_foldAtElse ? "1" : "0"));
        break;
    }
    case PropFoldComments: {
        m_foldComments = value.toBool();
        emit propertyChanged("fold.comments", (m_foldComments ? "1" : "0"));
        break;
    }
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    case PropFoldAtBegin: {
        m_foldAtBegin = value.toBool();
        emit propertyChanged("fold.at.Begin", (m_foldAtBegin ? "1" : "0"));
        break;
    }
    case PropFoldAtParenthesis: {
        m_foldAtParenthesis = value.toBool();
        emit propertyChanged("fold.at.Parenthese", (m_foldAtParenthesis ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerVHDL::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldAtElse:
        return m_foldAtElse;
    case PropFoldComments:
        return m_foldComments;
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldAtBegin:
        return m_foldAtBegin;
    case PropFoldAtParenthesis:
        return m_foldAtParenthesis;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerVHDL::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldAtElse = GET_SETTINGS_WITH(prefix + "foldatelse", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldAtBegin = GET_SETTINGS_WITH(prefix + "foldatbegin", bool, true);
    m_foldAtParenthesis = GET_SETTINGS_WITH(prefix + "foldatparenthesis", bool, true);

    return true;
}

bool TpLexerVHDL::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldatelse", m_foldAtElse);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldatbegin", m_foldAtBegin);
    SET_SETTINGS(prefix + "foldatparenthesis", m_foldAtParenthesis);

    return true;
}

TP_END_NAMESPACE
