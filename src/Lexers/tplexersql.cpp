#include <Lexers/TpLexerSQL>

TP_NAMESPACE

TpLexerSQL::TpLexerSQL(QObject *parent)
    : TpGeneralLexer(parent),
    m_fold(true),
    m_foldAtElse(true),
    m_foldComments(true),
    m_foldCompact(true),
    m_foldOnlyBegin(false),
    m_backticksIdentifier(false),
    m_numbersignComment(true),
    m_backslashEscapes(true),
    m_allowDottedWord(false)
{}

TpLexerSQL::~TpLexerSQL()
{}

const char *TpLexerSQL::language() const
{
    return "SQL (MySQL)";
}

const char *TpLexerSQL::lexer() const
{
    return "sql";
}

int TpLexerSQL::braceStyle() const
{
    return Operator;
}

QColor TpLexerSQL::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/SQL/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/SQL/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/SQL/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/SQL/Color/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/SQL/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/SQL/Color/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/SQL/Color/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/SQL/Color/SingleQuotedString", QColor);
    case PlusKeyword:
        return GET_SETTINGS("Lexer/SQL/Color/PlusKeyword", QColor);
    case PlusPrompt:
        return GET_SETTINGS("Lexer/SQL/Color/PlusPrompt", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/SQL/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/SQL/Color/Identifier", QColor);
    case PlusComment:
        return GET_SETTINGS("Lexer/SQL/Color/PlusComment", QColor);
    case CommentLineHash:
        return GET_SETTINGS("Lexer/SQL/Color/CommentLineHash", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/SQL/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/SQL/Color/CommentDocKeywordError", QColor);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/SQL/Color/KeywordSet5", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/SQL/Color/KeywordSet6", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/SQL/Color/KeywordSet7", QColor);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/SQL/Color/KeywordSet8", QColor);
    case QuotedIdentifier:
        return GET_SETTINGS("Lexer/SQL/Color/QuotedIdentifier", QColor);
    case QuotedOperator:
        return GET_SETTINGS("Lexer/SQL/Color/QuotedOperator", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerSQL::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/SQL/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/SQL/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/SQL/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/SQL/Fill/CommentDoc", bool);
    case Number:
        return GET_SETTINGS("Lexer/SQL/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/SQL/Fill/Keyword", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/SQL/Fill/DoubleQuotedString", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/SQL/Fill/SingleQuotedString", bool);
    case PlusKeyword:
        return GET_SETTINGS("Lexer/SQL/Fill/PlusKeyword", bool);
    case PlusPrompt:
        return GET_SETTINGS("Lexer/SQL/Fill/PlusPrompt", bool);
    case Operator:
        return GET_SETTINGS("Lexer/SQL/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/SQL/Fill/Identifier", bool);
    case PlusComment:
        return GET_SETTINGS("Lexer/SQL/Fill/PlusComment", bool);
    case CommentLineHash:
        return GET_SETTINGS("Lexer/SQL/Fill/CommentLineHash", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/SQL/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/SQL/Fill/CommentDocKeywordError", bool);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/SQL/Fill/KeywordSet5", bool);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/SQL/Fill/KeywordSet6", bool);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/SQL/Fill/KeywordSet7", bool);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/SQL/Fill/KeywordSet8", bool);
    case QuotedIdentifier:
        return GET_SETTINGS("Lexer/SQL/Fill/QuotedIdentifier", bool);
    case QuotedOperator:
        return GET_SETTINGS("Lexer/SQL/Fill/QuotedOperator", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerSQL::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/SQL/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/SQL/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/SQL/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/SQL/Font/CommentDoc", QFont);
    case Number:
        return GET_SETTINGS("Lexer/SQL/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/SQL/Font/Keyword", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/SQL/Font/DoubleQuotedString", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/SQL/Font/SingleQuotedString", QFont);
    case PlusKeyword:
        return GET_SETTINGS("Lexer/SQL/Font/PlusKeyword", QFont);
    case PlusPrompt:
        return GET_SETTINGS("Lexer/SQL/Font/PlusPrompt", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/SQL/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/SQL/Font/Identifier", QFont);
    case PlusComment:
        return GET_SETTINGS("Lexer/SQL/Font/PlusComment", QFont);
    case CommentLineHash:
        return GET_SETTINGS("Lexer/SQL/Font/CommentLineHash", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/SQL/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/SQL/Font/CommentDocKeywordError", QFont);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/SQL/Font/KeywordSet5", QFont);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/SQL/Font/KeywordSet6", QFont);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/SQL/Font/KeywordSet7", QFont);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/SQL/Font/KeywordSet8", QFont);
    case QuotedIdentifier:
        return GET_SETTINGS("Lexer/SQL/Font/QuotedIdentifier", QFont);
    case QuotedOperator:
        return GET_SETTINGS("Lexer/SQL/Font/QuotedOperator", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerSQL::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/SQL/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/SQL/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/SQL/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/SQL/BgColor/CommentDoc", QColor);
    case Number:
        return GET_SETTINGS("Lexer/SQL/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/SQL/BgColor/Keyword", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Lexer/SQL/BgColor/DoubleQuotedString", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Lexer/SQL/BgColor/SingleQuotedString", QColor);
    case PlusKeyword:
        return GET_SETTINGS("Lexer/SQL/BgColor/PlusKeyword", QColor);
    case PlusPrompt:
        return GET_SETTINGS("Lexer/SQL/BgColor/PlusPrompt", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/SQL/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/SQL/BgColor/Identifier", QColor);
    case PlusComment:
        return GET_SETTINGS("Lexer/SQL/BgColor/PlusComment", QColor);
    case CommentLineHash:
        return GET_SETTINGS("Lexer/SQL/BgColor/CommentLineHash", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/SQL/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/SQL/BgColor/CommentDocKeywordError", QColor);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/SQL/BgColor/KeywordSet5", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/SQL/BgColor/KeywordSet6", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/SQL/BgColor/KeywordSet7", QColor);
    case KeywordSet8:
        return GET_SETTINGS("Lexer/SQL/BgColor/KeywordSet8", QColor);
    case QuotedIdentifier:
        return GET_SETTINGS("Lexer/SQL/BgColor/QuotedIdentifier", QColor);
    case QuotedOperator:
        return GET_SETTINGS("Lexer/SQL/BgColor/QuotedOperator", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerSQL::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerSQLKeyword1;
    case 3:
        return lexerGeneralDoxygen;
    case 4:
        return lexerSQLKeyword4;
    case 5:
        return lexerSQLKeyword5;
    default:
        return 0;
    }
}

QString TpLexerSQL::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case CommentLine:
        return tr("Comment line");
    case CommentDoc:
        return tr("JavaDoc style comment");
    case Number:
        return tr("Number");
    case Keyword:
        return tr("Keyword");
    case DoubleQuotedString:
        return tr("Double-quoted string");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case PlusKeyword:
        return tr("SQL*Plus keyword");
    case PlusPrompt:
        return tr("SQL*Plus prompt");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case PlusComment:
        return tr("SQL*Plus comment");
    case CommentLineHash:
        return tr("# comment line");
    case CommentDocKeyword:
        return tr("JavaDoc keyword");
    case CommentDocKeywordError:
        return tr("JavaDoc keyword error");
    case KeywordSet5:
        return tr("User defined 1");
    case KeywordSet6:
        return tr("User defined 2");
    case KeywordSet7:
        return tr("User defined 3");
    case KeywordSet8:
        return tr("User defined 4");
    case QuotedIdentifier:
        return tr("Quoted identifier");
    case QuotedOperator:
        return tr("Quoted operator");
    }

    return QString();
}

void TpLexerSQL::refreshProperties()
{
    setLexerProperty(PropFold, m_fold);
    setLexerProperty(PropFoldAtElse, m_foldAtElse);
    setLexerProperty(PropFoldComments, m_foldComments);
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldOnlyBegin, m_foldOnlyBegin);
    setLexerProperty(PropBackticksIdentifier, m_backticksIdentifier);
    setLexerProperty(PropNumbersignComment, m_numbersignComment);
    setLexerProperty(PropBackslashEscapes, m_backslashEscapes);
    setLexerProperty(PropAllowDottedWord, m_allowDottedWord);
}

void TpLexerSQL::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFold: {
        m_fold = value.toBool();
        emit propertyChanged("fold", (m_fold ? "1" : "0"));
        break;
    }
    case PropFoldAtElse: {
        m_foldAtElse = value.toBool();
        emit propertyChanged("fold.sql.at.else", (m_foldAtElse ? "1" : "0"));
        break;
    }
    case PropFoldComments: {
        m_foldComments = value.toBool();
        emit propertyChanged("fold.comment", (m_foldComments ? "1" : "0"));
        break;
    }
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    case PropFoldOnlyBegin: {
        m_foldOnlyBegin = value.toBool();
        emit propertyChanged("fold.sql.only.begin", (m_foldOnlyBegin ? "1" : "0"));
        break;
    }
    case PropBackticksIdentifier: {
        m_backticksIdentifier = value.toBool();
        emit propertyChanged("lexer.sql.backticks.identifier", (m_backticksIdentifier ? "1" : "0"));
        break;
    }
    case PropNumbersignComment: {
        m_numbersignComment = value.toBool();
        emit propertyChanged("lexer.sql.numbersign.comment", (m_numbersignComment ? "1" : "0"));
        break;
    }
    case PropBackslashEscapes: {
        m_backslashEscapes = value.toBool();
        emit propertyChanged("sql.backslash.escape", (m_backslashEscapes ? "1" : "0"));
        break;
    }
    case PropAllowDottedWord: {
        m_allowDottedWord = value.toBool();
        emit propertyChanged("lexer.sql.allow.dotted.word", (m_allowDottedWord ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerSQL::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFold:
        return m_fold;
    case PropFoldAtElse:
        return m_foldAtElse;
    case PropFoldComments:
        return m_foldComments;
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldOnlyBegin:
        return m_foldOnlyBegin;
    case PropBackticksIdentifier:
        return m_backticksIdentifier;
    case PropNumbersignComment:
        return m_numbersignComment;
    case PropBackslashEscapes:
        return m_backslashEscapes;
    case PropAllowDottedWord:
        return m_allowDottedWord;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerSQL::readProperties(QSettings &settings, const QString &prefix)
{
    m_fold = GET_SETTINGS_WITH(prefix + "fold", bool, true);
    m_foldAtElse = GET_SETTINGS_WITH(prefix + "foldatelse", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldOnlyBegin = GET_SETTINGS_WITH(prefix + "foldonlybegin", bool, false);
    m_backticksIdentifier = GET_SETTINGS_WITH(prefix + "backticksidentifier", bool, false);
    m_numbersignComment = GET_SETTINGS_WITH(prefix + "numbersigncomment", bool, true);
    m_backslashEscapes = GET_SETTINGS_WITH(prefix + "backslashescapes", bool, true);
    m_allowDottedWord = GET_SETTINGS_WITH(prefix + "allowdottedword", bool, false);

    return true;
}

bool TpLexerSQL::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "fold", m_fold);
    SET_SETTINGS(prefix + "foldatelse", m_foldAtElse);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldonlybegin", m_foldOnlyBegin);
    SET_SETTINGS(prefix + "backticksidentifier", m_backticksIdentifier);
    SET_SETTINGS(prefix + "numbersigncomment", m_numbersignComment);
    SET_SETTINGS(prefix + "backslashescapes", m_backslashEscapes);
    SET_SETTINGS(prefix + "allowdottedword", m_allowDottedWord);

    return true;
}

TP_END_NAMESPACE
