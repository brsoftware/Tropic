#include <Lexers/TpLexerTCL>

TP_NAMESPACE

TpLexerTCL::TpLexerTCL(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true)
{}

TpLexerTCL::~TpLexerTCL()
{}

const char *TpLexerTCL::language() const
{
    return "TCL";
}

const char *TpLexerTCL::lexer() const
{
    return "tcl";
}

int TpLexerTCL::braceStyle() const
{
    return Operator;
}

QColor TpLexerTCL::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TCL/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/TCL/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/TCL/Color/CommentLine", QColor);
    case Number:
        return GET_SETTINGS("Lexer/TCL/Color/Number", QColor);
    case QuotedKeyword:
        return GET_SETTINGS("Lexer/TCL/Color/QuotedKeyword", QColor);
    case QuotedString:
        return GET_SETTINGS("Lexer/TCL/Color/QuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/TCL/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/TCL/Color/Identifier", QColor);
    case Substitution:
        return GET_SETTINGS("Lexer/TCL/Color/Substitution", QColor);
    case SubstitutionBrace:
        return GET_SETTINGS("Lexer/TCL/Color/SubstitutionBrace", QColor);
    case Modifier:
        return GET_SETTINGS("Lexer/TCL/Color/Modifier", QColor);
    case ExpandKeyword:
        return GET_SETTINGS("Lexer/TCL/Color/ExpandKeyword", QColor);
    case TCLKeyword:
        return GET_SETTINGS("Lexer/TCL/Color/TCLKeyword", QColor);
    case TkKeyword:
        return GET_SETTINGS("Lexer/TCL/Color/TkKeyword", QColor);
    case ITCLKeyword:
        return GET_SETTINGS("Lexer/TCL/Color/ITCLKeyword", QColor);
    case TkCommand:
        return GET_SETTINGS("Lexer/TCL/Color/TkCommand", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/TCL/Color/KeywordSet6", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/TCL/Color/KeywordSet7", QColor);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/TCL/Color/KeywordSet8", QColor);
    case KeywordSet9:
        return GET_SETTINGS("Lexer/TCL/Color/KeywordSet9", QColor);
    case CommentBox:
        return GET_SETTINGS("Lexer/TCL/Color/CommentBox", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/TCL/Color/CommentBlock", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerTCL::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TCL/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/TCL/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/TCL/Fill/CommentLine", bool);
    case Number:
        return GET_SETTINGS("Lexer/TCL/Fill/Number", bool);
    case QuotedKeyword:
        return GET_SETTINGS("Lexer/TCL/Fill/QuotedKeyword", bool);
    case QuotedString:
        return GET_SETTINGS("Lexer/TCL/Fill/QuotedString", bool);
    case Operator:
        return GET_SETTINGS("Lexer/TCL/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/TCL/Fill/Identifier", bool);
    case Substitution:
        return GET_SETTINGS("Lexer/TCL/Fill/Substitution", bool);
    case SubstitutionBrace:
        return GET_SETTINGS("Lexer/TCL/Fill/SubstitutionBrace", bool);
    case Modifier:
        return GET_SETTINGS("Lexer/TCL/Fill/Modifier", bool);
    case ExpandKeyword:
        return GET_SETTINGS("Lexer/TCL/Fill/ExpandKeyword", bool);
    case TCLKeyword:
        return GET_SETTINGS("Lexer/TCL/Fill/TCLKeyword", bool);
    case TkKeyword:
        return GET_SETTINGS("Lexer/TCL/Fill/TkKeyword", bool);
    case ITCLKeyword:
        return GET_SETTINGS("Lexer/TCL/Fill/ITCLKeyword", bool);
    case TkCommand:
        return GET_SETTINGS("Lexer/TCL/Fill/TkCommand", bool);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/TCL/Fill/KeywordSet6", bool);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/TCL/Fill/KeywordSet7", bool);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/TCL/Fill/KeywordSet8", bool);
    case KeywordSet9:
        return GET_SETTINGS("Lexer/TCL/Fill/KeywordSet9", bool);
    case CommentBox:
        return GET_SETTINGS("Lexer/TCL/Fill/CommentBox", bool);
    case CommentBlock:
        return GET_SETTINGS("Lexer/TCL/Fill/CommentBlock", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerTCL::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TCL/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/TCL/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/TCL/Font/CommentLine", QFont);
    case Number:
        return GET_SETTINGS("Lexer/TCL/Font/Number", QFont);
    case QuotedKeyword:
        return GET_SETTINGS("Lexer/TCL/Font/QuotedKeyword", QFont);
    case QuotedString:
        return GET_SETTINGS("Lexer/TCL/Font/QuotedString", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/TCL/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/TCL/Font/Identifier", QFont);
    case Substitution:
        return GET_SETTINGS("Lexer/TCL/Font/Substitution", QFont);
    case SubstitutionBrace:
        return GET_SETTINGS("Lexer/TCL/Font/SubstitutionBrace", QFont);
    case Modifier:
        return GET_SETTINGS("Lexer/TCL/Font/Modifier", QFont);
    case ExpandKeyword:
        return GET_SETTINGS("Lexer/TCL/Font/ExpandKeyword", QFont);
    case TCLKeyword:
        return GET_SETTINGS("Lexer/TCL/Font/TCLKeyword", QFont);
    case TkKeyword:
        return GET_SETTINGS("Lexer/TCL/Font/TkKeyword", QFont);
    case ITCLKeyword:
        return GET_SETTINGS("Lexer/TCL/Font/ITCLKeyword", QFont);
    case TkCommand:
        return GET_SETTINGS("Lexer/TCL/Font/TkCommand", QFont);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/TCL/Font/KeywordSet6", QFont);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/TCL/Font/KeywordSet7", QFont);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/TCL/Font/KeywordSet8", QFont);
    case KeywordSet9:
        return GET_SETTINGS("Lexer/TCL/Font/KeywordSet9", QFont);
    case CommentBox:
        return GET_SETTINGS("Lexer/TCL/Font/CommentBox", QFont);
    case CommentBlock:
        return GET_SETTINGS("Lexer/TCL/Font/CommentBlock", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerTCL::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TCL/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/TCL/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/TCL/BgColor/CommentLine", QColor);
    case Number:
        return GET_SETTINGS("Lexer/TCL/BgColor/Number", QColor);
    case QuotedKeyword:
        return GET_SETTINGS("Lexer/TCL/BgColor/QuotedKeyword", QColor);
    case QuotedString:
        return GET_SETTINGS("Lexer/TCL/BgColor/QuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/TCL/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/TCL/BgColor/Identifier", QColor);
    case Substitution:
        return GET_SETTINGS("Lexer/TCL/BgColor/Substitution", QColor);
    case SubstitutionBrace:
        return GET_SETTINGS("Lexer/TCL/BgColor/SubstitutionBrace", QColor);
    case Modifier:
        return GET_SETTINGS("Lexer/TCL/BgColor/Modifier", QColor);
    case ExpandKeyword:
        return GET_SETTINGS("Lexer/TCL/BgColor/ExpandKeyword", QColor);
    case TCLKeyword:
        return GET_SETTINGS("Lexer/TCL/BgColor/TCLKeyword", QColor);
    case TkKeyword:
        return GET_SETTINGS("Lexer/TCL/BgColor/TkKeyword", QColor);
    case ITCLKeyword:
        return GET_SETTINGS("Lexer/TCL/BgColor/ITCLKeyword", QColor);
    case TkCommand:
        return GET_SETTINGS("Lexer/TCL/BgColor/TkCommand", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/TCL/BgColor/KeywordSet6", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/TCL/BgColor/KeywordSet7", QColor);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/TCL/BgColor/KeywordSet8", QColor);
    case KeywordSet9:
        return GET_SETTINGS("Lexer/TCL/BgColor/KeywordSet9", QColor);
    case CommentBox:
        return GET_SETTINGS("Lexer/TCL/BgColor/CommentBox", QColor);
    case CommentBlock:
        return GET_SETTINGS("Lexer/TCL/BgColor/CommentBlock", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerTCL::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerTCLKeyword1;
    case 2:
        return lexerTCLKeyword2;
    case 3:
        return lexerTCLKeyword3;
    case 4:
        return lexerTCLKeyword4;
    case 5:
        return lexerTCLKeyword5;
    default:
        return 0;
    }
}

QString TpLexerTCL::description(int style) const
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
    case QuotedKeyword:
        return tr("Quoted keyword");
    case QuotedString:
        return tr("Quoted string");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case Substitution:
        return tr("Substitution");
    case SubstitutionBrace:
        return tr("Brace substitution");
    case Modifier:
        return tr("Modifier");
    case ExpandKeyword:
        return tr("Expand keyword");
    case TCLKeyword:
        return tr("TCL keyword");
    case TkKeyword:
        return tr("Tk keyword");
    case ITCLKeyword:
        return tr("iTCL keyword");
    case TkCommand:
        return tr("Tk command");
    case KeywordSet6:
        return tr("User defined 1");
    case KeywordSet7:
        return tr("User defined 2");
    case KeywordSet8:
        return tr("User defined 3");
    case KeywordSet9:
        return tr("User defined 4");
    case CommentBox:
        return tr("Comment box");
    case CommentBlock:
        return tr("Comment block");
    }

    return QString();
}

void TpLexerTCL::refreshProperties()
{
    setLexerProperty(PropFoldComments, m_foldComments);
}

void TpLexerTCL::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFoldComments: {
        m_foldComments = value.toBool();
        emit propertyChanged("fold.comment", (m_foldComments ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerTCL::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldComments:
        return m_foldComments;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerTCL::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);

    return true;
}

bool TpLexerTCL::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);

    return true;
}

TP_END_NAMESPACE
