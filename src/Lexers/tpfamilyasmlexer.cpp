#include <Lexers/TpFamilyASMLexer>

TP_NAMESPACE

TpFamilyASMLexer::TpFamilyASMLexer(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true),
    m_foldCompact(true),
    m_commentDelimiter('~'),
    m_foldSyntaxBased(true)
{}

TpFamilyASMLexer::~TpFamilyASMLexer()
{}

const char *TpFamilyASMLexer::language() const
{
    return "Assembly";
}

const char *TpFamilyASMLexer::lexer() const
{
    return "asm";
}

QColor TpFamilyASMLexer::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Editor/Color/Comment", QColor);
    case Number:
        return GET_SETTINGS("Editor/Color/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Color/DoubleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Editor/Color/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/Color/Identifier", QColor);
    case CPUInstruction:
        return GET_SETTINGS("Editor/Color/Keyword", QColor);
    case FPUInstruction:
        return GET_SETTINGS("Editor/Color/KeywordSet2", QColor);
    case Register:
        return GET_SETTINGS("Editor/Color/Number", QColor);
    case Directive:
        return GET_SETTINGS("Editor/Color/Type", QColor);
    case DirectiveOperand:
        return GET_SETTINGS("Editor/Color/Regex", QColor);
    case BlockComment:
        return GET_SETTINGS("Editor/Color/CommentDoc", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Color/SingleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Editor/Color/UnclosedString", QColor);
    case ExtendedInstruction:
        return GET_SETTINGS("Editor/Color/PreProcessor", QColor);
    case CommentDirective:
        return GET_SETTINGS("Editor/Color/CommentDocKeyword", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpFamilyASMLexer::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Editor/Fill/Comment", bool);
    case Number:
        return GET_SETTINGS("Editor/Fill/Number", bool);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Fill/DoubleQuotedString", bool);
    case Operator:
        return GET_SETTINGS("Editor/Fill/Operator", bool);
    case Identifier:
        return GET_SETTINGS("Editor/Fill/Identifier", bool);
    case CPUInstruction:
        return GET_SETTINGS("Editor/Fill/Keyword", bool);
    case FPUInstruction:
        return GET_SETTINGS("Editor/Fill/KeywordSet2", bool);
    case Register:
        return GET_SETTINGS("Editor/Fill/Number", bool);
    case Directive:
        return GET_SETTINGS("Editor/Fill/Type", bool);
    case DirectiveOperand:
        return GET_SETTINGS("Editor/Fill/Regex", bool);
    case BlockComment:
        return GET_SETTINGS("Editor/Fill/CommentDoc", bool);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Fill/SingleQuotedString", bool);
    case UnclosedString:
        return GET_SETTINGS("Editor/Fill/UnclosedString", bool);
    case ExtendedInstruction:
        return GET_SETTINGS("Editor/Fill/PreProcessor", bool);
    case CommentDirective:
        return GET_SETTINGS("Editor/Fill/CommentDocKeyword", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpFamilyASMLexer::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Editor/Font/Comment", QFont);
    case Number:
        return GET_SETTINGS("Editor/Font/Number", QFont);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/Font/DoubleQuotedString", QFont);
    case Operator:
        return GET_SETTINGS("Editor/Font/Operator", QFont);
    case Identifier:
        return GET_SETTINGS("Editor/Font/Identifier", QFont);
    case CPUInstruction:
        return GET_SETTINGS("Editor/Font/Keyword", QFont);
    case FPUInstruction:
        return GET_SETTINGS("Editor/Font/KeywordSet2", QFont);
    case Register:
        return GET_SETTINGS("Editor/Font/Number", QFont);
    case Directive:
        return GET_SETTINGS("Editor/Font/Type", QFont);
    case DirectiveOperand:
        return GET_SETTINGS("Editor/Font/Regex", QFont);
    case BlockComment:
        return GET_SETTINGS("Editor/Font/CommentDoc", QFont);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/Font/SingleQuotedString", QFont);
    case UnclosedString:
        return GET_SETTINGS("Editor/Font/UnclosedString", QFont);
    case ExtendedInstruction:
        return GET_SETTINGS("Editor/Font/PreProcessor", QFont);
    case CommentDirective:
        return GET_SETTINGS("Editor/Font/CommentDocKeyword", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpFamilyASMLexer::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Editor/BgColor/Comment", QColor);
    case Number:
        return GET_SETTINGS("Editor/BgColor/Number", QColor);
    case DoubleQuotedString:
        return GET_SETTINGS("Editor/BgColor/DoubleQuotedString", QColor);
    case Operator:
        return GET_SETTINGS("Editor/BgColor/Operator", QColor);
    case Identifier:
        return GET_SETTINGS("Editor/BgColor/Identifier", QColor);
    case CPUInstruction:
        return GET_SETTINGS("Editor/BgColor/Keyword", QColor);
    case FPUInstruction:
        return GET_SETTINGS("Editor/BgColor/KeywordSet2", QColor);
    case Register:
        return GET_SETTINGS("Editor/BgColor/Number", QColor);
    case Directive:
        return GET_SETTINGS("Editor/BgColor/Type", QColor);
    case DirectiveOperand:
        return GET_SETTINGS("Editor/BgColor/Regex", QColor);
    case BlockComment:
        return GET_SETTINGS("Editor/BgColor/CommentDoc", QColor);
    case SingleQuotedString:
        return GET_SETTINGS("Editor/BgColor/SingleQuotedString", QColor);
    case UnclosedString:
        return GET_SETTINGS("Editor/BgColor/UnclosedString", QColor);
    case ExtendedInstruction:
        return GET_SETTINGS("Editor/BgColor/PreProcessor", QColor);
    case CommentDirective:
        return GET_SETTINGS("Editor/BgColor/CommentDocKeyword", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

const char *TpFamilyASMLexer::keywords(int set) const
{
    switch (set)
    {
    case 1:
        return lexerAsmKeyword1;
    case 2:
        return lexerAsmKeyword2;
    case 3:
        return lexerAsmKeyword3;
    case 4:
        return lexerAsmKeyword4;
    case 5:
        return lexerAsmKeyword5;
    case 6:
        return lexerAsmKeyword6;
    default:
        return 0;
    }
}

QString TpFamilyASMLexer::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case Number:
        return tr("Number");
    case DoubleQuotedString:
        return tr("Double-quoted string");
    case Operator:
        return tr("Operator");
    case Identifier:
        return tr("Identifier");
    case CPUInstruction:
        return tr("CPU instruction");
    case FPUInstruction:
        return tr("FPU instruction");
    case Register:
        return tr("Register");
    case Directive:
        return tr("Directive");
    case DirectiveOperand:
        return tr("Directive operand");
    case BlockComment:
        return tr("Block comment");
    case SingleQuotedString:
        return tr("Single-quoted string");
    case UnclosedString:
        return tr("Unclosed string");
    case ExtendedInstruction:
        return tr("Extended instruction");
    case CommentDirective:
        return tr("Comment directive");
    }

    return QString();
}

void TpFamilyASMLexer::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
    setLexerProperty(PropCommentDelimiter, m_commentDelimiter);
    setLexerProperty(PropFoldSyntaxBased, m_foldSyntaxBased);
}

void TpFamilyASMLexer::setLexerProperty(int prop, QVariant value)
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
        emit propertyChanged("fold.asm.comment.multiline", (m_foldComments ? "1" : "0"));
        break;
    }
    case PropCommentDelimiter: {
        m_commentDelimiter = value.toChar();
        emit propertyChanged("lexer.asm.comment.delimiter", textAsBytes(m_commentDelimiter).constData());
        break;
    }
    case PropFoldSyntaxBased: {
        m_foldSyntaxBased = value.toBool();
        emit propertyChanged("fold.asm.syntax.based", (m_foldSyntaxBased ? "1" : "0"));
        break;
    }
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpFamilyASMLexer::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldComments:
        return m_foldComments;
    case PropCommentDelimiter:
        return m_commentDelimiter;
    case PropFoldSyntaxBased:
        return m_foldSyntaxBased;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpFamilyASMLexer::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);
    m_commentDelimiter = GET_SETTINGS_WITH(prefix + "commentdelimiter", QChar, '~');
    m_foldSyntaxBased = GET_SETTINGS_WITH(prefix + "foldsyntaxbased", bool, true);

    return true;
}

bool TpFamilyASMLexer::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);
    SET_SETTINGS(prefix + "commentdelimiter", m_commentDelimiter);
    SET_SETTINGS(prefix + "foldsyntaxbased", m_foldSyntaxBased);

    return true;
}

TP_END_NAMESPACE
