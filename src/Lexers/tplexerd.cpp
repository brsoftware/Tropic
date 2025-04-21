#include <Lexers/TpLexerD>

TP_NAMESPACE

TpLexerD::TpLexerD(QObject *parent)
    : TpGeneralLexer(parent),
    m_fold(true),
    m_foldSyntaxBased(true),
    m_foldComment(true),
    m_foldCommentMultiline(true),
    m_foldCommentExplicit(true),
    m_foldExplicitStart("//{"),
    m_foldExplicitEnd("//}"),
    m_foldExplicitAnywhere(false),
    m_foldCompact(true),
    m_foldAtElse(true)
{}

TpLexerD::~TpLexerD()
{}

const char *TpLexerD::language() const
{
    return "D";
}

const char *TpLexerD::lexer() const
{
    return "d";
}

QStringList TpLexerD::autoCompletionWordSeparators() const
{
    QStringList wordList;

    wordList << ".";

    return wordList;
}

const char *TpLexerD::blockEnd(int *style) const
{
    if (style)
        *style = Operator;

    return "}";
}

const char *TpLexerD::blockStart(int *style) const
{
    if (style)
        *style = Operator;

    return "{";
}

const char *TpLexerD::blockStartKeyword(int *style) const
{
    if (style)
        *style = Keyword;

    return "case catch class default do else finally for foreach foreach_reverse if private protected public struct "
           "try union while";
}

int TpLexerD::braceStyle() const
{
    return Operator;
}

const char *TpLexerD::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_#";
}

QColor TpLexerD::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/D/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/D/Color/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/D/Color/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/D/Color/CommentDoc", QColor);
    case CommentNested:
        return GET_SETTINGS("Lexer/D/Color/CommentNested", QColor);
    case Number:
        return GET_SETTINGS("Lexer/D/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/D/Color/Keyword", QColor);
    case KeywordSecondary:
        return GET_SETTINGS("Lexer/D/Color/KeywordSecondary", QColor);
    case KeywordDoc:
        return GET_SETTINGS("Lexer/D/Color/KeywordDoc", QColor);
    case Typedefs:
        return GET_SETTINGS("Lexer/D/Color/Typedefs", QColor);
    case String:
        return GET_SETTINGS("Lexer/D/Color/String", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/D/Color/UnclosedString", QColor);
    case Character:
        return GET_SETTINGS("Lexer/D/Color/Character", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/D/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/D/Color/Identifier", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/D/Color/CommentLineDoc", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/D/Color/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/D/Color/CommentDocKeywordError", QColor);
    case BackquoteString:
        return GET_SETTINGS("Lexer/D/Color/BackquoteString", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/D/Color/RawString", QColor);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/D/Color/KeywordSet5", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/D/Color/KeywordSet6", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/D/Color/KeywordSet7", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerD::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/D/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/D/Fill/Comment", bool);
    case CommentLine:
        return GET_SETTINGS("Lexer/D/Fill/CommentLine", bool);
    case CommentDoc:
        return GET_SETTINGS("Lexer/D/Fill/CommentDoc", bool);
    case CommentNested:
        return GET_SETTINGS("Lexer/D/Fill/CommentNested", bool);
    case Number:
        return GET_SETTINGS("Lexer/D/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Lexer/D/Fill/Keyword", bool);
    case KeywordSecondary:
        return GET_SETTINGS("Lexer/D/Fill/KeywordSecondary", bool);
    case KeywordDoc:
        return GET_SETTINGS("Lexer/D/Fill/KeywordDoc", bool);
    case Typedefs:
        return GET_SETTINGS("Lexer/D/Fill/Typedefs", bool);
    case String:
        return GET_SETTINGS("Lexer/D/Fill/String", bool);
    case UnclosedString:
        return GET_SETTINGS("Lexer/D/Fill/UnclosedString", bool);
    case Character:
        return GET_SETTINGS("Lexer/D/Fill/Character", bool);
    case Operator:
        return GET_SETTINGS("Lexer/D/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Lexer/D/Fill/Identifier", bool);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/D/Fill/CommentLineDoc", bool);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/D/Fill/CommentDocKeyword", bool);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/D/Fill/CommentDocKeywordError", bool);
    case BackquoteString:
        return GET_SETTINGS("Lexer/D/Fill/BackquoteString", bool);
    case RawString:
        return GET_SETTINGS("Lexer/D/Fill/RawString", bool);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/D/Fill/KeywordSet5", bool);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/D/Fill/KeywordSet6", bool);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/D/Fill/KeywordSet7", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerD::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/D/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/D/Font/Comment", QFont);
    case CommentLine:
        return GET_SETTINGS("Lexer/D/Font/CommentLine", QFont);
    case CommentDoc:
        return GET_SETTINGS("Lexer/D/Font/CommentDoc", QFont);
    case CommentNested:
        return GET_SETTINGS("Lexer/D/Font/CommentNested", QFont);
    case Number:
        return GET_SETTINGS("Lexer/D/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Lexer/D/Font/Keyword", QFont);
    case KeywordSecondary:
        return GET_SETTINGS("Lexer/D/Font/KeywordSecondary", QFont);
    case KeywordDoc:
        return GET_SETTINGS("Lexer/D/Font/KeywordDoc", QFont);
    case Typedefs:
        return GET_SETTINGS("Lexer/D/Font/Typedefs", QFont);
    case String:
        return GET_SETTINGS("Lexer/D/Font/String", QFont);
    case UnclosedString:
        return GET_SETTINGS("Lexer/D/Font/UnclosedString", QFont);
    case Character:
        return GET_SETTINGS("Lexer/D/Font/Character", QFont);
    case Operator:
        return GET_SETTINGS("Lexer/D/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Lexer/D/Font/Identifier", QFont);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/D/Font/CommentLineDoc", QFont);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/D/Font/CommentDocKeyword", QFont);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/D/Font/CommentDocKeywordError", QFont);
    case BackquoteString:
        return GET_SETTINGS("Lexer/D/Font/BackquoteString", QFont);
    case RawString:
        return GET_SETTINGS("Lexer/D/Font/RawString", QFont);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/D/Font/KeywordSet5", QFont);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/D/Font/KeywordSet6", QFont);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/D/Font/KeywordSet7", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerD::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/D/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/D/BgColor/Comment", QColor);
    case CommentLine:
        return GET_SETTINGS("Lexer/D/BgColor/CommentLine", QColor);
    case CommentDoc:
        return GET_SETTINGS("Lexer/D/BgColor/CommentDoc", QColor);
    case CommentNested:
        return GET_SETTINGS("Lexer/D/BgColor/CommentNested", QColor);
    case Number:
        return GET_SETTINGS("Lexer/D/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Lexer/D/BgColor/Keyword", QColor);
    case KeywordSecondary:
        return GET_SETTINGS("Lexer/D/BgColor/KeywordSecondary", QColor);
    case KeywordDoc:
        return GET_SETTINGS("Lexer/D/BgColor/KeywordDoc", QColor);
    case Typedefs:
        return GET_SETTINGS("Lexer/D/BgColor/Typedefs", QColor);
    case String:
        return GET_SETTINGS("Lexer/D/BgColor/String", QColor);
    case UnclosedString:
        return GET_SETTINGS("Lexer/D/BgColor/UnclosedString", QColor);
    case Character:
        return GET_SETTINGS("Lexer/D/BgColor/Character", QColor);
    case Operator:
        return GET_SETTINGS("Lexer/D/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Lexer/D/BgColor/Identifier", QColor);
    case CommentLineDoc:
        return GET_SETTINGS("Lexer/D/BgColor/CommentLineDoc", QColor);
    case CommentDocKeyword:
        return GET_SETTINGS("Lexer/D/BgColor/CommentDocKeyword", QColor);
    case CommentDocKeywordError:
        return GET_SETTINGS("Lexer/D/BgColor/CommentDocKeywordError", QColor);
    case BackquoteString:
        return GET_SETTINGS("Lexer/D/BgColor/BackquoteString", QColor);
    case RawString:
        return GET_SETTINGS("Lexer/D/BgColor/RawString", QColor);
    case KeywordSet5:
        return GET_SETTINGS("Lexer/D/BgColor/KeywordSet5", QColor);
    case KeywordSet6:
        return GET_SETTINGS("Lexer/D/BgColor/KeywordSet6", QColor);
    case KeywordSet7:
        return GET_SETTINGS("Lexer/D/BgColor/KeywordSet7", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpLexerD::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerDKeyword1;
    case 3:
        return lexerGeneralDoxygen;
    default:
        return 0;
    }
}

QString TpLexerD::description(int style) const
{
    switch (style)
    {
    default:
        return tr("Default");
    case Comment:
        return tr("Block comment");
    case CommentLine:
        return tr("Line comment");
    case CommentDoc:
        return tr("DDoc style block comment");
    case CommentNested:
        return tr("Nesting comment");
    case Number:
        return tr("Number");
    case Keyword:
        return tr("Keyword");
    case KeywordSecondary:
        return tr("Secondary keyword");
    case KeywordDoc:
        return tr("Documentation keyword");
    case Typedefs:
        return tr("Type definition");
    case String:
        return tr("String");
    case UnclosedString:
        return tr("Unclosed string");
    case Character:
        return tr("Character");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case CommentLineDoc:
        return tr("DDoc style line comment");
    case CommentDocKeyword:
        return tr("DDoc keyword");
    case CommentDocKeywordError:
        return tr("DDoc keyword error");
    case BackquoteString:
        return tr("Backquoted string");
    case RawString:
        return tr("Raw string");
    case KeywordSet5:
        return tr("User defined 1");
    case KeywordSet6:
        return tr("User defined 2");
    case KeywordSet7:
        return tr("User defined 3");
    }

    return QString();
}

void TpLexerD::refreshProperties()
{
    setLexerProperty(PropFold, m_fold);
    setLexerProperty(PropFoldSyntaxBased, m_foldSyntaxBased);
    setLexerProperty(PropFoldComment, m_foldComment);
    setLexerProperty(PropFoldCommentMultiline, m_foldCommentMultiline);
    setLexerProperty(PropFoldCommentExplicit, m_foldCommentExplicit);
    setLexerProperty(PropFoldExplicitStart, m_foldExplicitStart);
    setLexerProperty(PropFoldExplicitEnd, m_foldExplicitEnd);
    setLexerProperty(PropFoldExplicitAnywhere, m_foldExplicitAnywhere);
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldAtElse, m_foldAtElse);
}

void TpLexerD::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropFold: {
        m_fold = value.toBool();
        emit propertyChanged("fold", (m_fold ? "1" : "0"));
        break;
    }
    case PropFoldSyntaxBased: {
        m_foldSyntaxBased = value.toBool();
        emit propertyChanged("fold.d.syntax.based", (m_foldSyntaxBased ? "1" : "0"));
        break;
    }
    case PropFoldComment: {
        m_foldComment = value.toBool();
        emit propertyChanged("fold.comment", (m_foldComment ? "1" : "0"));
        break;
    }
    case PropFoldCommentMultiline: {
        m_foldCommentMultiline = value.toBool();
        emit propertyChanged("fold.d.comment.multiline", (m_foldCommentMultiline ? "1" : "0"));
        break;
    }
    case PropFoldCommentExplicit: {
        m_foldCommentExplicit = value.toBool();
        emit propertyChanged("fold.d.comment.explicit", (m_foldCommentExplicit ? "1" : "0"));
        break;
    }
    case PropFoldExplicitStart: {
        m_foldExplicitStart = value.toString();
        emit propertyChanged("fold.d.explicit.start", textAsBytes(m_foldExplicitStart).constData());
        break;
    }
    case PropFoldExplicitEnd: {
        m_foldExplicitEnd = value.toString();
        emit propertyChanged("fold.d.explicit.end", textAsBytes(m_foldExplicitEnd).constData());
        break;
    }
    case PropFoldExplicitAnywhere: {
        m_foldExplicitAnywhere = value.toBool();
        emit propertyChanged("fold.d.explicit.anywhere", (m_foldExplicitAnywhere ? "1" : "0"));
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

QVariant TpLexerD::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFold:
        return m_fold;
    case PropFoldSyntaxBased:
        return m_foldSyntaxBased;
    case PropFoldComment:
        return m_foldComment;
    case PropFoldCommentMultiline:
        return m_foldCommentMultiline;
    case PropFoldCommentExplicit:
        return m_foldCommentExplicit;
    case PropFoldExplicitStart:
        return m_foldExplicitStart;
    case PropFoldExplicitEnd:
        return m_foldExplicitEnd;
    case PropFoldExplicitAnywhere:
        return m_foldExplicitAnywhere;
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

bool TpLexerD::readProperties(QSettings &settings, const QString &prefix)
{
    m_fold = GET_SETTINGS_WITH(prefix + "fold", bool, true);
    m_foldSyntaxBased = GET_SETTINGS_WITH(prefix + "foldsyntaxbased", bool, true);
    m_foldComment = GET_SETTINGS_WITH(prefix + "foldcomment", bool, true);
    m_foldCommentMultiline = GET_SETTINGS_WITH(prefix + "foldcommentmultiline", bool, true);
    m_foldCommentExplicit = GET_SETTINGS_WITH(prefix + "foldcommentexplicit", bool, true);
    m_foldExplicitStart = GET_SETTINGS_WITH(prefix + "foldexplicitstart", QString, "//{");
    m_foldExplicitEnd = GET_SETTINGS_WITH(prefix + "foldexplicitend", QString, "//}");
    m_foldExplicitAnywhere = GET_SETTINGS_WITH(prefix + "foldexplicitanywhere", bool, false);
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldAtElse = GET_SETTINGS_WITH(prefix + "foldatelse", bool, true);

    return true;
}

bool TpLexerD::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "fold", m_fold);
    SET_SETTINGS(prefix + "foldsyntaxbased", m_foldSyntaxBased);
    SET_SETTINGS(prefix + "foldcomment", m_foldComment);
    SET_SETTINGS(prefix + "foldcommentmultiline", m_foldCommentMultiline);
    SET_SETTINGS(prefix + "foldcommentexplicit", m_foldCommentExplicit);
    SET_SETTINGS(prefix + "foldexplicitstart", m_foldExplicitStart);
    SET_SETTINGS(prefix + "foldexplicitend", m_foldExplicitEnd);
    SET_SETTINGS(prefix + "foldexplicitanywhere", m_foldExplicitAnywhere);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldatelse", m_foldAtElse);

    return true;
}

TP_END_NAMESPACE
