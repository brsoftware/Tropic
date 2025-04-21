#include <Lexers/TpLexerPascal>

TP_NAMESPACE

TpLexerPascal::TpLexerPascal(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true),
    m_foldCompact(true),
    m_foldPreprocessor(true),
    m_smartHighlight(true)
{}

TpLexerPascal::~TpLexerPascal()
{}

const char *TpLexerPascal::language() const
{
    return "Pascal";
}

const char *TpLexerPascal::lexer() const
{
    return "pascal";
}

QStringList TpLexerPascal::autoCompletionWordSeparators() const
{
    QStringList wordList;

    wordList << "." << "^";

    return wordList;
}

const char *TpLexerPascal::blockEnd(int *style) const
{
    if (style)
        *style = Operator;

    return "end";
}

const char *TpLexerPascal::blockStart(int *style) const
{
    if (style)
        *style = Operator;

    return "begin";
}

const char *TpLexerPascal::blockStartKeyword(int *style) const
{
    if (style)
        *style = Keyword;

    return "case class do else for then private protected public published repeat try while type";
}

int TpLexerPascal::braceStyle() const
{
    return Operator;
}

QColor TpLexerPascal::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Pascal/Color/Universal", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Pascal/Color/Identifier", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Pascal/Color/Comment", QColor);
    case CommentParenthesis:
        return GET_SETTINGS("Lexer/Pascal/Color/CommentParenthesis", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/Pascal/Color/CommentLine", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Pascal/Color/PreProcessor", QColor);
    case PreProcessorParenthesis:
        return GET_SETTINGS("Lexer/Pascal/Color/PreProcessorParenthesis", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Pascal/Color/Number", QColor);
    case HexNumber:
        return GET_SETTINGS("Lexer/Pascal/Color/HexNumber", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Pascal/Color/Keyword", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Pascal/Color/SingleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Pascal/Color/UnclosedString", QColor);
    case Character:
        return GET_SETTINGS("Lexer/Pascal/Color/Character", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Pascal/Color/Operator", QColor);
    case Asm:
        return GET_SETTINGS("Lexer/Pascal/Color/Asm", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerPascal::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Pascal/Fill/Universal", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/Pascal/Fill/Identifier", bool);
    case Comment:
        return GET_SETTINGS("Lexer/Pascal/Fill/Comment", bool);
    case CommentParenthesis:
        return GET_SETTINGS("Lexer/Pascal/Fill/CommentParenthesis", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/Pascal/Fill/CommentLine", bool);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Pascal/Fill/PreProcessor", bool);
    case PreProcessorParenthesis:
        return GET_SETTINGS("Lexer/Pascal/Fill/PreProcessorParenthesis", bool);
    case Number:
        return GET_SETTINGS("Lexer/Pascal/Fill/Number", bool);
    case HexNumber:
        return GET_SETTINGS("Lexer/Pascal/Fill/HexNumber", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/Pascal/Fill/Keyword", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Pascal/Fill/SingleQuotedString", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Pascal/Fill/UnclosedString", bool);
    case Character:
        return GET_SETTINGS("Lexer/Pascal/Fill/Character", bool);
    case Operator:
        return GET_SETTINGS("Lexer/Pascal/Fill/Operator", bool);
    case Asm:
        return GET_SETTINGS("Lexer/Pascal/Fill/Asm", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerPascal::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Pascal/Font/Universal", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/Pascal/Font/Identifier", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/Pascal/Font/Comment", QFont);
    case CommentParenthesis:
        return GET_SETTINGS("Lexer/Pascal/Font/CommentParenthesis", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/Pascal/Font/CommentLine", QFont);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Pascal/Font/PreProcessor", QFont);
    case PreProcessorParenthesis:
        return GET_SETTINGS("Lexer/Pascal/Font/PreProcessorParenthesis", QFont);
    case Number:
        return GET_SETTINGS("Lexer/Pascal/Font/Number", QFont);
    case HexNumber:
        return GET_SETTINGS("Lexer/Pascal/Font/HexNumber", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/Pascal/Font/Keyword", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Pascal/Font/SingleQuotedString", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Pascal/Font/UnclosedString", QFont);
    case Character:
        return GET_SETTINGS("Lexer/Pascal/Font/Character", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/Pascal/Font/Operator", QFont);
    case Asm:
        return GET_SETTINGS("Lexer/Pascal/Font/Asm", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerPascal::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Pascal/BgColor/Universal", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/Pascal/BgColor/Identifier", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/Pascal/BgColor/Comment", QColor);
    case CommentParenthesis:
        return GET_SETTINGS("Lexer/Pascal/BgColor/CommentParenthesis", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/Pascal/BgColor/CommentLine", QColor);
    case PreProcessor:
        return GET_SETTINGS("Lexer/Pascal/BgColor/PreProcessor", QColor);
    case PreProcessorParenthesis:
        return GET_SETTINGS("Lexer/Pascal/BgColor/PreProcessorParenthesis", QColor);
    case Number:
        return GET_SETTINGS("Lexer/Pascal/BgColor/Number", QColor);
    case HexNumber:
        return GET_SETTINGS("Lexer/Pascal/BgColor/HexNumber", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/Pascal/BgColor/Keyword", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/Pascal/BgColor/SingleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/Pascal/BgColor/UnclosedString", QColor);
    case Character:
        return GET_SETTINGS("Lexer/Pascal/BgColor/Character", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/Pascal/BgColor/Operator", QColor);
    case Asm:
        return GET_SETTINGS("Lexer/Pascal/BgColor/Asm", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerPascal::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerPascalKeyword1;
    default:
        return 0;
    }
}

QString TpLexerPascal::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Identifier:
        return tr("Identifier");
    case Comment:
        return tr("'{ ... }' style comment");
    case CommentParenthesis:
        return tr("'(* ... *)' style comment");
    case CommentLine:
        return tr("Line comment");
    case PreProcessor:
        return tr("'{$ ... }' style pre-processor block");
    case PreProcessorParenthesis:
        return tr("'(*$ ... *)' style pre-processor block");
    case Number:
        return tr("Number");
    case HexNumber:
        return tr("Hexadecimal number");
    case Keyword:
        return tr("Keyword");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case UnclosedString:
        return tr("Unclosed string");
    case Character:
        return tr("Character");
    case Operator:
        return tr("Operator");
    case Asm:
        return tr("Inline asm");
    }

    return QString();
}

void TpLexerPascal::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
    setLexerProperty(PropFoldPreprocessor, m_foldPreprocessor);
    setLexerProperty(PropSmartHighlight, m_smartHighlight);
}

void TpLexerPascal::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    case PropFoldComments: {
        m_foldComments = value.toBool();
        emit propertyChanged("fold.comment", (m_foldComments ? "1" : "0"));
        break;
    }
    case PropFoldPreprocessor: {
        m_foldPreprocessor = value.toBool();
        emit propertyChanged("fold.preprocessor", (m_foldPreprocessor ? "1" : "0"));
        break;
    }
    case PropSmartHighlight: {
        m_smartHighlight = value.toBool();
        emit propertyChanged("lexer.pascal.smart.highlighting", (m_smartHighlight ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerPascal::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldComments:
        return m_foldComments;
    case PropFoldPreprocessor:
        return m_foldPreprocessor;
    case PropSmartHighlight:
        return m_smartHighlight;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerPascal::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_foldPreprocessor = GET_SETTINGS_WITH(prefix + "foldpreprocessor", bool, true);
    m_smartHighlight = GET_SETTINGS_WITH(prefix + "smarthighlight", bool, true);

    return true;
}

bool TpLexerPascal::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "foldpreprocessor", m_foldPreprocessor);
    SET_SETTINGS(prefix + "smarthighlight", m_smartHighlight);

    return true;
}

TP_END_NAMESPACE
