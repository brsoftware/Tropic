#include <Lexers/TpLexerPO>

TP_NAMESPACE

TpLexerPO::TpLexerPO(QObject *parent)
    : TpGeneralLexer(parent),
    m_foldComments(true),
    m_foldCompact(true)
{}

TpLexerPO::~TpLexerPO()
{}

const char *TpLexerPO::language() const
{
    return "PO";
}

const char *TpLexerPO::lexer() const
{
    return "po";
}

QColor TpLexerPO::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PO/Color/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/PO/Color/Comment", QColor);
    case MessageId:
        return GET_SETTINGS("Lexer/PO/Color/MessageId", QColor);
    case MessageIdText:
        return GET_SETTINGS("Lexer/PO/Color/MessageIdText", QColor);
    case MessageString:
        return GET_SETTINGS("Lexer/PO/Color/MessageString", QColor);
    case MessageStringText:
        return GET_SETTINGS("Lexer/PO/Color/MessageStringText", QColor);
    case MessageContext:
        return GET_SETTINGS("Lexer/PO/Color/MessageContext", QColor);
    case MessageContextText:
        return GET_SETTINGS("Lexer/PO/Color/MessageContextText", QColor);
    case Fuzzy:
        return GET_SETTINGS("Lexer/PO/Color/Fuzzy", QColor);
    case ProgrammerComment:
        return GET_SETTINGS("Lexer/PO/Color/ProgrammerComment", QColor);
    case Reference:
        return GET_SETTINGS("Lexer/PO/Color/Reference", QColor);
    case Flags:
        return GET_SETTINGS("Lexer/PO/Color/Flags", QColor);
    case MessageIdTextEOL:
        return GET_SETTINGS("Lexer/PO/Color/MessageIDTextEOL", QColor);
    case MessageStringTextEOL:
        return GET_SETTINGS("Lexer/PO/Color/MessageStringTextEOL", QColor);
    case MessageContextTextEOL:
        return GET_SETTINGS("Lexer/PO/Color/MessageContextTextEOL", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerPO::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PO/Fill/Universal", bool);
    case Comment:
        return GET_SETTINGS("Lexer/PO/Fill/Comment", bool);
    case MessageId:
        return GET_SETTINGS("Lexer/PO/Fill/MessageId", bool);
    case MessageIdText:
        return GET_SETTINGS("Lexer/PO/Fill/MessageIdText", bool);
    case MessageString:
        return GET_SETTINGS("Lexer/PO/Fill/MessageString", bool);
    case MessageStringText:
        return GET_SETTINGS("Lexer/PO/Fill/MessageStringText", bool);
    case MessageContext:
        return GET_SETTINGS("Lexer/PO/Fill/MessageContext", bool);
    case MessageContextText:
        return GET_SETTINGS("Lexer/PO/Fill/MessageContextText", bool);
    case Fuzzy:
        return GET_SETTINGS("Lexer/PO/Fill/Fuzzy", bool);
    case ProgrammerComment:
        return GET_SETTINGS("Lexer/PO/Fill/ProgrammerComment", bool);
    case Reference:
        return GET_SETTINGS("Lexer/PO/Fill/Reference", bool);
    case Flags:
        return GET_SETTINGS("Lexer/PO/Fill/Flags", bool);
    case MessageIdTextEOL:
        return GET_SETTINGS("Lexer/PO/Fill/MessageIDTextEOL", bool);
    case MessageStringTextEOL:
        return GET_SETTINGS("Lexer/PO/Fill/MessageStringTextEOL", bool);
    case MessageContextTextEOL:
        return GET_SETTINGS("Lexer/PO/Fill/MessageContextTextEOL", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerPO::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PO/Font/Universal", QFont);
    case Comment:
        return GET_SETTINGS("Lexer/PO/Font/Comment", QFont);
    case MessageId:
        return GET_SETTINGS("Lexer/PO/Font/MessageId", QFont);
    case MessageIdText:
        return GET_SETTINGS("Lexer/PO/Font/MessageIdText", QFont);
    case MessageString:
        return GET_SETTINGS("Lexer/PO/Font/MessageString", QFont);
    case MessageStringText:
        return GET_SETTINGS("Lexer/PO/Font/MessageStringText", QFont);
    case MessageContext:
        return GET_SETTINGS("Lexer/PO/Font/MessageContext", QFont);
    case MessageContextText:
        return GET_SETTINGS("Lexer/PO/Font/MessageContextText", QFont);
    case Fuzzy:
        return GET_SETTINGS("Lexer/PO/Font/Fuzzy", QFont);
    case ProgrammerComment:
        return GET_SETTINGS("Lexer/PO/Font/ProgrammerComment", QFont);
    case Reference:
        return GET_SETTINGS("Lexer/PO/Font/Reference", QFont);
    case Flags:
        return GET_SETTINGS("Lexer/PO/Font/Flags", QFont);
    case MessageIdTextEOL:
        return GET_SETTINGS("Lexer/PO/Font/MessageIDTextEOL", QFont);
    case MessageStringTextEOL:
        return GET_SETTINGS("Lexer/PO/Font/MessageStringTextEOL", QFont);
    case MessageContextTextEOL:
        return GET_SETTINGS("Lexer/PO/Font/MessageContextTextEOL", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerPO::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/PO/BgColor/Universal", QColor);
    case Comment:
        return GET_SETTINGS("Lexer/PO/BgColor/Comment", QColor);
    case MessageId:
        return GET_SETTINGS("Lexer/PO/BgColor/MessageId", QColor);
    case MessageIdText:
        return GET_SETTINGS("Lexer/PO/BgColor/MessageIdText", QColor);
    case MessageString:
        return GET_SETTINGS("Lexer/PO/BgColor/MessageString", QColor);
    case MessageStringText:
        return GET_SETTINGS("Lexer/PO/BgColor/MessageStringText", QColor);
    case MessageContext:
        return GET_SETTINGS("Lexer/PO/BgColor/MessageContext", QColor);
    case MessageContextText:
        return GET_SETTINGS("Lexer/PO/BgColor/MessageContextText", QColor);
    case Fuzzy:
        return GET_SETTINGS("Lexer/PO/BgColor/Fuzzy", QColor);
    case ProgrammerComment:
        return GET_SETTINGS("Lexer/PO/BgColor/ProgrammerComment", QColor);
    case Reference:
        return GET_SETTINGS("Lexer/PO/BgColor/Reference", QColor);
    case Flags:
        return GET_SETTINGS("Lexer/PO/BgColor/Flags", QColor);
    case MessageIdTextEOL:
        return GET_SETTINGS("Lexer/PO/BgColor/MessageIDTextEOL", QColor);
    case MessageStringTextEOL:
        return GET_SETTINGS("Lexer/PO/BgColor/MessageStringTextEOL", QColor);
    case MessageContextTextEOL:
        return GET_SETTINGS("Lexer/PO/BgColor/MessageContextTextEOL", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

QString TpLexerPO::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Comment:
        return tr("Comment");
    case MessageId:
        return tr("Message identifier");
    case MessageIdText:
        return tr("Message identifier text");
    case MessageString:
        return tr("Message string");
    case MessageStringText:
        return tr("Message string text");
    case MessageContext:
        return tr("Message context");
    case MessageContextText:
        return tr("Message context text");
    case Fuzzy:
        return tr("Fuzzy flag");
    case ProgrammerComment:
        return tr("Programmer comment");
    case Reference:
        return tr("Reference");
    case Flags:
        return tr("Flags");
    case MessageIdTextEOL:
        return tr("Message identifier text end-of-line");
    case MessageStringTextEOL:
        return tr("Message string text end-of-line");
    case MessageContextTextEOL:
        return tr("Message context text end-of-line");
    }

    return QString();
}

void TpLexerPO::refreshProperties()
{
    setLexerProperty(PropFoldCompact, m_foldCompact);
    setLexerProperty(PropFoldComments, m_foldComments);
}

void TpLexerPO::setLexerProperty(int prop, QVariant value)
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
    default: {
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }
    }
}

QVariant TpLexerPO::lexerProperty(int prop) const
{
    switch (prop)
    {
    case PropFoldCompact:
        return m_foldCompact;
    case PropFoldComments:
        return m_foldComments;
    default:
        Q_ASSERT_X(false, Q_FUNC_INFO, qPrintable("Unknown property: " + QString::number(prop)));
        break;
    }

    return 0;
}

bool TpLexerPO::readProperties(QSettings &settings, const QString &prefix)
{
    m_foldCompact = GET_SETTINGS_WITH(prefix + "foldcompact", bool, true);
    m_foldComments = GET_SETTINGS_WITH(prefix + "foldcomments", bool, true);

    return true;
}

bool TpLexerPO::writeProperties(QSettings &settings, const QString &prefix) const
{
    SET_SETTINGS(prefix + "foldcompact", m_foldCompact);
    SET_SETTINGS(prefix + "foldcomments", m_foldComments);

    return true;
}

TP_END_NAMESPACE
