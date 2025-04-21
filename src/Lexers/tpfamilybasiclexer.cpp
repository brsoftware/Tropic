#include <Lexers/TpFamilyBasicLexer>

TP_NAMESPACE

TpFamilyBasicLexer::TpFamilyBasicLexer(QObject *parent)
    : TpGeneralLexer(parent),
    m_mode(PureBasic),
    m_fold(true),
    m_foldSyntaxBased(true),
    m_foldCommentExplicit(true),
    m_foldExplicitStart(""),
    m_foldExplicitEnd(""),
    m_foldExplicitAnywhere(false),
    m_foldCompact(true)
{}

TpFamilyBasicLexer::~TpFamilyBasicLexer()
{}

const char *TpFamilyBasicLexer::language() const
{
    return "Basic";
}

const char *TpFamilyBasicLexer::lexer() const
{
    switch (m_mode)
    {
    case BlitzBasic:
        return "blitzbasic";
    case FreeBasic:
        return "freebasic";
    case PureBasic:
    default:
        return "purebasic";
    }
}

QStringList TpFamilyBasicLexer::autoCompletionWordSeparators() const
{
    QStringList wordList;
    wordList << ".";
    return wordList;
}

const char *TpFamilyBasicLexer::blockStartKeyword(int *style) const
{
    if (style)
        *style = Keyword;

    switch (m_mode)
    {
    case BlitzBasic:
        return "function type";
    case FreeBasic:
        return "function sub enum type union property destructor constructor";
    case PureBasic:
    default:
        return "procedure enumeration interface structure";
    }
}

const char *TpFamilyBasicLexer::wordCharacters() const
{
    return "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
}

QColor TpFamilyBasicLexer::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Editor/Color/CommentLine", QColor);
    case Number:
        return GET_SETTINGS("Editor/Color/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Editor/Color/Keyword", QColor);
    case String:
        return GET_SETTINGS("Editor/Color/DoubleQuotedString", QColor);
    case PreProcessor:
        return GET_SETTINGS("Editor/Color/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Editor/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/Color/Identifier", QColor);
    case Date:
        return GET_SETTINGS("Editor/Color/UUID", QColor);
    case StringEol:
        return GET_SETTINGS("Editor/Color/Error", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Editor/Color/Keyword", QColor);
    case KeywordSet3:
        return GET_SETTINGS("Editor/Color/Keyword", QColor);
    case KeywordSet4:
        return GET_SETTINGS("Editor/Color/Keyword", QColor);
    case Constant:
        return GET_SETTINGS("Editor/Color/UserLiteral", QColor);
    case Asm:
        return GET_SETTINGS("Editor/Color/Regex", QColor);
    case Label:
        return GET_SETTINGS("Editor/Color/TaskMarker", QColor);
    case Error:
        return GET_SETTINGS("Editor/Color/Error", QColor);
    case HexNumber:
        return GET_SETTINGS("Editor/Color/HashQuotedString", QColor);
    case BinaryNumber:
        return GET_SETTINGS("Editor/Color/TripleQuotedVerbatimString", QColor);
    case CommentBlock:
        return GET_SETTINGS("Editor/Color/Comment", QColor);
    case DocLine:
        return GET_SETTINGS("Editor/Color/CommentLineDoc", QColor);
    case DocBlock:
        return GET_SETTINGS("Editor/Color/CommentDoc", QColor);
    case DocKeyword:
        return GET_SETTINGS("Editor/Color/CommentDocKeyword", QColor);
    default:
        return GET_SETTINGS("Editor/Color/Universal", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

QFont TpFamilyBasicLexer::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Editor/Font/CommentLine", QFont);
    case Number:
        return GET_SETTINGS("Editor/Font/Number", QFont);
    case Keyword:
        return GET_SETTINGS("Editor/Font/Keyword", QFont);
    case String:
        return GET_SETTINGS("Editor/Font/DoubleQuotedString", QFont);
    case PreProcessor:
        return GET_SETTINGS("Editor/Font/PreProcessor", QFont);
    case Operator:
        return GET_SETTINGS("Editor/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Editor/Font/Identifier", QFont);
    case Date:
        return GET_SETTINGS("Editor/Font/UUID", QFont);
    case StringEol:
        return GET_SETTINGS("Editor/Font/Error", QFont);
    case KeywordSet2:
        return GET_SETTINGS("Editor/Font/Keyword", QFont);
    case KeywordSet3:
        return GET_SETTINGS("Editor/Font/Keyword", QFont);
    case KeywordSet4:
        return GET_SETTINGS("Editor/Font/Keyword", QFont);
    case Constant:
        return GET_SETTINGS("Editor/Font/UserLiteral", QFont);
    case Asm:
        return GET_SETTINGS("Editor/Font/Regex", QFont);
    case Label:
        return GET_SETTINGS("Editor/Font/TaskMarker", QFont);
    case Error:
        return GET_SETTINGS("Editor/Font/Error", QFont);
    case HexNumber:
        return GET_SETTINGS("Editor/Font/HashQuotedString", QFont);
    case BinaryNumber:
        return GET_SETTINGS("Editor/Font/TripleQuotedVerbatimString", QFont);
    case CommentBlock:
        return GET_SETTINGS("Editor/Font/Comment", QFont);
    case DocLine:
        return GET_SETTINGS("Editor/Font/CommentLineDoc", QFont);
    case DocBlock:
        return GET_SETTINGS("Editor/Font/CommentDoc", QFont);
    case DocKeyword:
        return GET_SETTINGS("Editor/Font/CommentDocKeyword", QFont);
    default:
        return GET_SETTINGS("Editor/Font/Universal", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

bool TpFamilyBasicLexer::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Editor/Fill/CommentLine", bool);
    case Number:
        return GET_SETTINGS("Editor/Fill/Number", bool);
    case Keyword:
        return GET_SETTINGS("Editor/Fill/Keyword", bool);
    case String:
        return GET_SETTINGS("Editor/Fill/DoubleQuotedString", bool);
    case PreProcessor:
        return GET_SETTINGS("Editor/Fill/PreProcessor", bool);
    case Operator:
        return GET_SETTINGS("Editor/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Editor/Fill/Identifier", bool);
    case Date:
        return GET_SETTINGS("Editor/Fill/UUID", bool);
    case StringEol:
        return GET_SETTINGS("Editor/Fill/Error", bool);
    case KeywordSet2:
        return GET_SETTINGS("Editor/Fill/Keyword", bool);
    case KeywordSet3:
        return GET_SETTINGS("Editor/Fill/Keyword", bool);
    case KeywordSet4:
        return GET_SETTINGS("Editor/Fill/Keyword", bool);
    case Constant:
        return GET_SETTINGS("Editor/Fill/UserLiteral", bool);
    case Asm:
        return GET_SETTINGS("Editor/Fill/Regex", bool);
    case Label:
        return GET_SETTINGS("Editor/Fill/TaskMarker", bool);
    case Error:
        return GET_SETTINGS("Editor/Fill/Error", bool);
    case HexNumber:
        return GET_SETTINGS("Editor/Fill/HashQuotedString", bool);
    case BinaryNumber:
        return GET_SETTINGS("Editor/Fill/TripleQuotedVerbatimString", bool);
    case CommentBlock:
        return GET_SETTINGS("Editor/Fill/Comment", bool);
    case DocLine:
        return GET_SETTINGS("Editor/Fill/CommentLineDoc", bool);
    case DocBlock:
        return GET_SETTINGS("Editor/Fill/CommentDoc", bool);
    case DocKeyword:
        return GET_SETTINGS("Editor/Fill/CommentDocKeyword", bool);
    default:
        return GET_SETTINGS("Editor/Fill/Universal", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QColor TpFamilyBasicLexer::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    case Comment:
        return GET_SETTINGS("Editor/BgColor/CommentLine", QColor);
    case Number:
        return GET_SETTINGS("Editor/BgColor/Number", QColor);
    case Keyword:
        return GET_SETTINGS("Editor/BgColor/Keyword", QColor);
    case String:
        return GET_SETTINGS("Editor/BgColor/DoubleQuotedString", QColor);
    case PreProcessor:
        return GET_SETTINGS("Editor/BgColor/PreProcessor", QColor);
    case Operator:
        return GET_SETTINGS("Editor/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/BgColor/Identifier", QColor);
    case Date:
        return GET_SETTINGS("Editor/BgColor/UUID", QColor);
    case StringEol:
        return GET_SETTINGS("Editor/BgColor/Error", QColor);
    case KeywordSet2:
        return GET_SETTINGS("Editor/BgColor/Keyword", QColor);
    case KeywordSet3:
        return GET_SETTINGS("Editor/BgColor/Keyword", QColor);
    case KeywordSet4:
        return GET_SETTINGS("Editor/BgColor/Keyword", QColor);
    case Constant:
        return GET_SETTINGS("Editor/BgColor/UserLiteral", QColor);
    case Asm:
        return GET_SETTINGS("Editor/BgColor/Regex", QColor);
    case Label:
        return GET_SETTINGS("Editor/BgColor/TaskMarker", QColor);
    case Error:
        return GET_SETTINGS("Editor/BgColor/Error", QColor);
    case HexNumber:
        return GET_SETTINGS("Editor/BgColor/HashQuotedString", QColor);
    case BinaryNumber:
        return GET_SETTINGS("Editor/BgColor/TripleQuotedVerbatimString", QColor);
    case CommentBlock:
        return GET_SETTINGS("Editor/BgColor/Comment", QColor);
    case DocLine:
        return GET_SETTINGS("Editor/BgColor/CommentLineDoc", QColor);
    case DocBlock:
        return GET_SETTINGS("Editor/BgColor/CommentDoc", QColor);
    case DocKeyword:
        return GET_SETTINGS("Editor/BgColor/CommentDocKeyword", QColor);
    default:
        return GET_SETTINGS("Editor/BgColor/Universal", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpFamilyBasicLexer::keywords(int set) const
{
    switch (set)
    {
    default:
        return 0;
    }
}

QString TpFamilyBasicLexer::description(int set) const
{
    switch (set)
    {
    default:
        return "Default";
    case Comment:
        return "Comment";
    case Number:
        return "Number";
    case Keyword:
        return "Keyword";
    case String:
        return "String";
    case PreProcessor:
        return "Pre-processor";
    case Operator:
        return "Opreator";
    case Identifier:
        return "Identifier";
    case Date:
        return "Date";
    case StringEol:
        return "String end-of-line";
    case KeywordSet2:
        return "Keyword set 2";
    case KeywordSet3:
        return "Keyword set 3";
    case KeywordSet4:
        return "Keyword set 4";
    case Constant:
        return "Constant";
    case Asm:
        return "Assembly block";
    case Label:
        return "Label";
    case Error:
        return "Error";
    case HexNumber:
        return "Hexadecimal number";
    case BinaryNumber:
        return "Binary number";
    case CommentBlock:
        return "Comment block";
    case DocLine:
        return "Comment doc line";
    case DocBlock:
        return "Comment doc block";
    case DocKeyword:
        return "Comment doc keyword";
    }

    return QString();
}

void TpFamilyBasicLexer::refreshProperties()
{
    setLexerProperty(PropMode, m_mode);
    setLexerProperty(PropFold, m_fold);
    setLexerProperty(PropFoldSyntaxBased, m_foldSyntaxBased);
    setLexerProperty(PropFoldCommentExplicit, m_foldCommentExplicit);
    setLexerProperty(PropFoldExplicitStart, m_foldExplicitStart);
    setLexerProperty(PropFoldExplicitEnd, m_foldExplicitEnd);
    setLexerProperty(PropFoldExplicitAnywhere, m_foldExplicitAnywhere);
    setLexerProperty(PropFoldCompact, m_foldCompact);
}

void TpFamilyBasicLexer::setLexerProperty(int prop, QVariant value)
{
    switch (prop)
    {
    case PropMode: {
        bool ok = true;
        switch (value.toInt(&ok))
        {
        case BlitzBasic: case PureBasic: case FreeBasic:
            m_mode = value.toInt();
            break;
        default:
            Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Undefined property: " + QString::number(prop)));
            break;
        }
        if (!ok)
            Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + value.toString()));
        break;
    }
    case PropFold: {
        m_fold = value.toBool();
        emit propertyChanged("fold", (m_fold ? "1" : "0"));
        break;
    }
    case PropFoldSyntaxBased: {
        m_foldSyntaxBased = value.toBool();
        emit propertyChanged("fold.basic.syntax.based", (m_foldSyntaxBased ? "1" : "0"));
        break;
    }
    case PropFoldCommentExplicit: {
        m_foldCommentExplicit = value.toBool();
        emit propertyChanged("fold.basic.comment.explicit", (m_foldCommentExplicit ? "1" : "0"));
        break;
    }
    case PropFoldExplicitStart: {
        m_foldExplicitStart = value.toString();
        emit propertyChanged("fold.basic.explicit.start", textAsBytes(m_foldExplicitStart).constData());
        break;
    }
    case PropFoldExplicitEnd: {
        m_foldExplicitEnd = value.toString();
        emit propertyChanged("fold.basic.explicit.end", textAsBytes(m_foldExplicitEnd).constData());
        break;
    }
    case PropFoldExplicitAnywhere: {
        m_foldExplicitAnywhere = value.toBool();
        emit propertyChanged("fold.basic.explicit.anywhere", (m_foldExplicitAnywhere ? "1" : "0"));
        break;
    }
    case PropFoldCompact: {
        m_foldCompact = value.toBool();
        emit propertyChanged("fold.compact", (m_foldCompact ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + value.toString()));
        break;
    }
    }
}

QVariant TpFamilyBasicLexer::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropMode:
        return m_mode;
    case PropFold:
        return m_fold;
    case PropFoldSyntaxBased:
        return m_foldSyntaxBased;
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
    }

    return 0;
}

bool TpFamilyBasicLexer::readProperties(QSettings &settings, const QString &prefix)
{
    m_mode = GET_SETTINGS(prefix + "mode", int);
    m_fold = GET_SETTINGS(prefix + "fold", bool);
    m_foldSyntaxBased = GET_SETTINGS(prefix + "foldsyntaxbased", bool);
    m_foldCommentExplicit = GET_SETTINGS(prefix + "foldcommentexplicit", bool);
    m_foldExplicitStart = GET_SETTINGS(prefix + "foldexplicitstart", QString);
    m_foldExplicitEnd = GET_SETTINGS(prefix + "foldexplicitend", QString);
    m_foldExplicitAnywhere = GET_SETTINGS(prefix + "foldexplicitanywhere", bool);
    m_foldCompact = GET_SETTINGS(prefix + "foldcompact", bool);

    return true;
}

bool TpFamilyBasicLexer::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "mode", m_mode);
    SET_SETTINGS(prefix + "fold", m_fold);
    SET_SETTINGS(prefix + "foldsyntaxbased", m_foldSyntaxBased);
    SET_SETTINGS(prefix + "foldcommentexplicit", m_foldCommentExplicit);
    SET_SETTINGS(prefix + "foldexplicitstart", m_foldExplicitStart);
    SET_SETTINGS(prefix + "foldexplicitend", m_foldExplicitEnd);
    SET_SETTINGS(prefix + "foldexplicitanywhere", m_foldExplicitAnywhere);
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);

    return true;
}

TP_END_NAMESPACE
