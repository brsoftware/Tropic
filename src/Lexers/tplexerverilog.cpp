#include <Lexers/TpLexerVerilog>

TP_NAMESPACE

TpLexerVerilog::TpLexerVerilog(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldAtElse(true),
    m_foldComments(true),
    m_foldCompact(true),
    m_foldPreprocessor(true),
    m_foldAtModule(true)
{}

TpLexerVerilog::~TpLexerVerilog()
{}

const char *TpLexerVerilog::language() const
{
    return "Verilog";
}

const char *TpLexerVerilog::lexer() const
{
    return "verilog";
}

const char *TpLexerVerilog::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_$";
}

int TpLexerVerilog::braceStyle() const
{
    return Operator;
}

QColor TpLexerVerilog::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Verilog/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Verilog/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/Verilog/Color/CommentLine", QColor);
    case CommentBang:
        return GET_SETTINGS("Lexer/Verilog/Color/CommentBang", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Verilog/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Verilog/Color/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/Verilog/Color/String", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/Verilog/Color/KeywordSet2", QColor);
    case SystemTask:
        return GET_SETTINGS("Lexer/Verilog/Color/SystemTask", QColor);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Verilog/Color/Preprocessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Verilog/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Verilog/Color/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Verilog/Color/UnclosedString", QColor);
    case UserKeywordSet:
        return GET_SETTINGS("Lexer/Verilog/Color/UserKeywordSet", QColor);
    case CommentKeyword:
        return GET_SETTINGS("Lexer/Verilog/Color/CommentKeyword", QColor);
    case DeclareInputPort:
        return GET_SETTINGS("Lexer/Verilog/Color/DeclareInputPort", QColor);
    case DeclareOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Color/DeclareOutputPort", QColor);
    case DeclareInputOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Color/DeclareInputOutputPort", QColor);
    case PortConnection:
        return GET_SETTINGS("Lexer/Verilog/Color/PortConnection", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveCommentLine", QColor);
    case InactiveCommentBang:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveCommentBang", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveKeyword", QColor);
    case InactiveString:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveString", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveKeywordSet2", QColor);
    case InactiveSystemTask:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveSystemTask", QColor);
    case InactivePreprocessor:
        return GET_SETTINGS("Lexer/Verilog/Color/InactivePreprocessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveUnclosedString", QColor);
    case InactiveUserKeywordSet:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveUserKeywordSet", QColor);
    case InactiveCommentKeyword:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveCommentKeyword", QColor);
    case InactiveDeclareInputPort:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveDeclareInputPort", QColor);
    case InactiveDeclareOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveDeclareOutputPort", QColor);
    case InactiveDeclareInputOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Color/InactiveDeclareInputOutputPort", QColor);
    case InactivePortConnection:
        return GET_SETTINGS("Lexer/Verilog/Color/InactivePortConnection", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerVerilog::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Verilog/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Verilog/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/Verilog/Fill/CommentLine", bool);
    case CommentBang:
        return GET_SETTINGS("Lexer/Verilog/Fill/CommentBang", bool);
    case Number:
        return GET_SETTINGS("Lexer/Verilog/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Verilog/Fill/Keyword", bool);
    case String:
        return GET_SETTINGS("Lexer/Verilog/Fill/String", bool);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/Verilog/Fill/KeywordSet2", bool);
    case SystemTask:
        return GET_SETTINGS("Lexer/Verilog/Fill/SystemTask", bool);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Verilog/Fill/Preprocessor", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Verilog/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Verilog/Fill/Identifier", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Verilog/Fill/UnclosedString", bool);
    case UserKeywordSet:
        return GET_SETTINGS("Lexer/Verilog/Fill/UserKeywordSet", bool);
    case CommentKeyword:
        return GET_SETTINGS("Lexer/Verilog/Fill/CommentKeyword", bool);
    case DeclareInputPort:
        return GET_SETTINGS("Lexer/Verilog/Fill/DeclareInputPort", bool);
    case DeclareOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Fill/DeclareOutputPort", bool);
    case DeclareInputOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Fill/DeclareInputOutputPort", bool);
    case PortConnection:
        return GET_SETTINGS("Lexer/Verilog/Fill/PortConnection", bool);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveDefault", bool);
    case InactiveComment:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveComment", bool);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveCommentLine", bool);
    case InactiveCommentBang:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveCommentBang", bool);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveNumber", bool);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveKeyword", bool);
    case InactiveString:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveString", bool);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveKeywordSet2", bool);
    case InactiveSystemTask:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveSystemTask", bool);
    case InactivePreprocessor:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactivePreprocessor", bool);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveOperator", bool);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveIdentifier", bool);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveUnclosedString", bool);
    case InactiveUserKeywordSet:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveUserKeywordSet", bool);
    case InactiveCommentKeyword:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveCommentKeyword", bool);
    case InactiveDeclareInputPort:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveDeclareInputPort", bool);
    case InactiveDeclareOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveDeclareOutputPort", bool);
    case InactiveDeclareInputOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactiveDeclareInputOutputPort", bool);
    case InactivePortConnection:
        return GET_SETTINGS("Lexer/Verilog/Fill/InactivePortConnection", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerVerilog::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Verilog/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Verilog/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/Verilog/Font/CommentLine", QFont);
    case CommentBang:
        return GET_SETTINGS("Lexer/Verilog/Font/CommentBang", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Verilog/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Verilog/Font/Keyword", QFont);
    case String:
        return GET_SETTINGS("Lexer/Verilog/Font/String", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/Verilog/Font/KeywordSet2", QFont);
    case SystemTask:
        return GET_SETTINGS("Lexer/Verilog/Font/SystemTask", QFont);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Verilog/Font/Preprocessor", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Verilog/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Verilog/Font/Identifier", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Verilog/Font/UnclosedString", QFont);
    case UserKeywordSet:
        return GET_SETTINGS("Lexer/Verilog/Font/UserKeywordSet", QFont);
    case CommentKeyword:
        return GET_SETTINGS("Lexer/Verilog/Font/CommentKeyword", QFont);
    case DeclareInputPort:
        return GET_SETTINGS("Lexer/Verilog/Font/DeclareInputPort", QFont);
    case DeclareOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Font/DeclareOutputPort", QFont);
    case DeclareInputOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Font/DeclareInputOutputPort", QFont);
    case PortConnection:
        return GET_SETTINGS("Lexer/Verilog/Font/PortConnection", QFont);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveDefault", QFont);
    case InactiveComment:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveComment", QFont);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveCommentLine", QFont);
    case InactiveCommentBang:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveCommentBang", QFont);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveNumber", QFont);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveKeyword", QFont);
    case InactiveString:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveString", QFont);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveKeywordSet2", QFont);
    case InactiveSystemTask:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveSystemTask", QFont);
    case InactivePreprocessor:
        return GET_SETTINGS("Lexer/Verilog/Font/InactivePreprocessor", QFont);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveOperator", QFont);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveIdentifier", QFont);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveUnclosedString", QFont);
    case InactiveUserKeywordSet:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveUserKeywordSet", QFont);
    case InactiveCommentKeyword:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveCommentKeyword", QFont);
    case InactiveDeclareInputPort:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveDeclareInputPort", QFont);
    case InactiveDeclareOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveDeclareOutputPort", QFont);
    case InactiveDeclareInputOutputPort:
        return GET_SETTINGS("Lexer/Verilog/Font/InactiveDeclareInputOutputPort", QFont);
    case InactivePortConnection:
        return GET_SETTINGS("Lexer/Verilog/Font/InactivePortConnection", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerVerilog::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Verilog/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Verilog/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/Verilog/BgColor/CommentLine", QColor);
    case CommentBang:
        return GET_SETTINGS("Lexer/Verilog/BgColor/CommentBang", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Verilog/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Verilog/BgColor/Keyword", QColor);
    case String:
        return GET_SETTINGS("Lexer/Verilog/BgColor/String", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Lexer/Verilog/BgColor/KeywordSet2", QColor);
    case SystemTask:
        return GET_SETTINGS("Lexer/Verilog/BgColor/SystemTask", QColor);
    case Preprocessor:
        return GET_SETTINGS("Lexer/Verilog/BgColor/Preprocessor", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Verilog/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Verilog/BgColor/Identifier", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Verilog/BgColor/UnclosedString", QColor);
    case UserKeywordSet:
        return GET_SETTINGS("Lexer/Verilog/BgColor/UserKeywordSet", QColor);
    case CommentKeyword:
        return GET_SETTINGS("Lexer/Verilog/BgColor/CommentKeyword", QColor);
    case DeclareInputPort:
        return GET_SETTINGS("Lexer/Verilog/BgColor/DeclareInputPort", QColor);
    case DeclareOutputPort:
        return GET_SETTINGS("Lexer/Verilog/BgColor/DeclareOutputPort", QColor);
    case DeclareInputOutputPort:
        return GET_SETTINGS("Lexer/Verilog/BgColor/DeclareInputOutputPort", QColor);
    case PortConnection:
        return GET_SETTINGS("Lexer/Verilog/BgColor/PortConnection", QColor);
    case InactiveDefault:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveDefault", QColor);
    case InactiveComment:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveComment", QColor);
    case InactiveCommentLine:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveCommentLine", QColor);
    case InactiveCommentBang:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveCommentBang", QColor);
    case InactiveNumber:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveNumber", QColor);
    case InactiveKeyword:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveKeyword", QColor);
    case InactiveString:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveString", QColor);
    case InactiveKeywordSet2:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveKeywordSet2", QColor);
    case InactiveSystemTask:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveSystemTask", QColor);
    case InactivePreprocessor:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactivePreprocessor", QColor);
    case InactiveOperator:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveOperator", QColor);
    case InactiveIdentifier:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveIdentifier", QColor);
    case InactiveUnclosedString:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveUnclosedString", QColor);
    case InactiveUserKeywordSet:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveUserKeywordSet", QColor);
    case InactiveCommentKeyword:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveCommentKeyword", QColor);
    case InactiveDeclareInputPort:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveDeclareInputPort", QColor);
    case InactiveDeclareOutputPort:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveDeclareOutputPort", QColor);
    case InactiveDeclareInputOutputPort:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactiveDeclareInputOutputPort", QColor);
    case InactivePortConnection:
        return GET_SETTINGS("Lexer/Verilog/BgColor/InactivePortConnection", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerVerilog::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerVerilogKeyword1;
    case 3:
        return lexerVerilogKeyword3;
    default:
        return 0;
    }
}

QString TpLexerVerilog::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case InactiveDefault:
        return tr("Inactive default");
    case Comment:
        return tr("Comment");
    case InactiveComment:
        return tr("Inactive comment");
    case CommentLine:
        return tr("Line comment");
    case InactiveCommentLine:
        return tr("Inactive line comment");
    case CommentBang:
        return tr("Bang comment");
    case InactiveCommentBang:
        return tr("Inactive bang comment");
    case Number:
        return tr("Number");
    case InactiveNumber:
        return tr("Inactive number");
    case Keyword:
        return tr("Primary keywords and identifiers");
    case InactiveKeyword:
        return tr("Inactive primary keywords and identifiers");
    case String:
        return tr("String");
    case InactiveString:
        return tr("Inactive string");
    case KeywordSet2:
        return tr("Secondary keywords and identifiers");
    case InactiveKeywordSet2:
        return tr("Inactive secondary keywords and identifiers");
    case SystemTask:
        return tr("System task");
    case InactiveSystemTask:
        return tr("Inactive system task");
    case Preprocessor:
        return tr("Preprocessor block");
    case InactivePreprocessor:
        return tr("Inactive preprocessor block");
    case Operator:
        return tr("Operator");
    case InactiveOperator:
        return tr("Inactive operator");
    case Identifier:
        return tr("Identifier");
    case InactiveIdentifier:
        return tr("Inactive identifier");
    case UnclosedString:
        return tr("Unclosed string");
    case InactiveUnclosedString:
        return tr("Inactive unclosed string");
    case UserKeywordSet:
        return tr("User defined tasks and identifiers");
    case InactiveUserKeywordSet:
        return tr("Inactive user defined tasks and identifiers");
    case CommentKeyword:
        return tr("Keyword comment");
    case InactiveCommentKeyword:
        return tr("Inactive keyword comment");
    case DeclareInputPort:
        return tr("Input port declaration");
    case InactiveDeclareInputPort:
        return tr("Inactive input port declaration");
    case DeclareOutputPort:
        return tr("Output port declaration");
    case InactiveDeclareOutputPort:
        return tr("Inactive output port declaration");
    case DeclareInputOutputPort:
        return tr("Input/output port declaration");
    case InactiveDeclareInputOutputPort:
        return tr("Inactive input/output port declaration");
    case PortConnection:
        return tr("Port connection");
    case InactivePortConnection:
        return tr("Inactive port connection");
    }

    return QString();
}

void TpLexerVerilog::refreshProperties()
{
    setLexerProperty(PropFoldAtElse, m_foldAtElse);
    setLexerProperty(PropFoldComments, m_foldComments);
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldPreprocessor, m_foldPreprocessor);
    setLexerProperty(PropFoldAtModule, m_foldAtModule);
}

void TpLexerVerilog::setLexerProperty(int prop, QVariant value)
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
    case PropFoldPreprocessor: {
        m_foldPreprocessor = value.toBool();
        emit propertyChanged("fold.preprocessor", (m_foldPreprocessor ? "1" : "0"));
        break;
    }
    case PropFoldAtModule: {
        m_foldAtModule = value.toBool();
        emit propertyChanged("fold.verilog.flags", (m_foldAtModule ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerVerilog::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldAtElse:
        return m_foldAtElse;
    case PropFoldComments:
        return m_foldComments;
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldPreprocessor:
        return m_foldPreprocessor;
    case PropFoldAtModule:
        return m_foldAtModule;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerVerilog::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldAtElse = GET_SETTINGS_WITH(prefix + "foldatelse", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldPreprocessor = GET_SETTINGS_WITH(prefix + "foldpreprocessor", bool, true);
    m_foldAtModule = GET_SETTINGS_WITH(prefix + "foldatmodule", bool, true);

    return true;
}

bool TpLexerVerilog::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldatelse", m_foldAtElse);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldpreprocessor", m_foldPreprocessor);
    SET_SETTINGS(prefix + "foldatmodule", m_foldAtModule);

    return true;
}

TP_END_NAMESPACE
