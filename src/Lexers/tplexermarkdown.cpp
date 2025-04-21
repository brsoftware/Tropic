#include <Lexers/TpLexerMarkdown>

TP_NAMESPACE

TpLexerMarkdown::TpLexerMarkdown(QObject *parent)
    : TpGeneralLexer(parent)
{}

TpLexerMarkdown::~TpLexerMarkdown()
{}

const char *TpLexerMarkdown::language() const
{
    return "Markdown";
}

const char *TpLexerMarkdown::lexer() const
{
    return "markdown";
}

QColor TpLexerMarkdown::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Markdown/Color/Universal", QColor);
    case Special:
        return GET_SETTINGS("Lexer/Markdown/Color/Special", QColor);
    case StrongEmphasisAsterisks:
        return GET_SETTINGS("Lexer/Markdown/Color/StrongEmphasisAsterisks", QColor);
    case StrongEmphasisUnderscores:
        return GET_SETTINGS("Lexer/Markdown/Color/StrongEmphasisUnderscores", QColor);
    case EmphasisAsterisks:
        return GET_SETTINGS("Lexer/Markdown/Color/EmphasisAsterisks", QColor);
    case EmphasisUnderscores:
        return GET_SETTINGS("Lexer/Markdown/Color/EmphasisUnderscores", QColor);
    case Header1:
        return GET_SETTINGS("Lexer/Markdown/Color/Header1", QColor);
    case Header2:
        return GET_SETTINGS("Lexer/Markdown/Color/Header2", QColor);
    case Header3:
        return GET_SETTINGS("Lexer/Markdown/Color/Header3", QColor);
    case Header4:
        return GET_SETTINGS("Lexer/Markdown/Color/Header4", QColor);
    case Header5:
        return GET_SETTINGS("Lexer/Markdown/Color/Header5", QColor);
    case Header6:
        return GET_SETTINGS("Lexer/Markdown/Color/Header6", QColor);
    case Prechar:
        return GET_SETTINGS("Lexer/Markdown/Color/Prechar", QColor);
    case UnorderedListItem:
        return GET_SETTINGS("Lexer/Markdown/Color/UnorderedListItem", QColor);
    case OrderedListItem:
        return GET_SETTINGS("Lexer/Markdown/Color/OrderedListItem", QColor);
    case BlockQuote:
        return GET_SETTINGS("Lexer/Markdown/Color/BlockQuote", QColor);
    case StrikeOut:
        return GET_SETTINGS("Lexer/Markdown/Color/StrikeOut", QColor);
    case HorizontalRule:
        return GET_SETTINGS("Lexer/Markdown/Color/HorizontalRule", QColor);
    case Link:
        return GET_SETTINGS("Lexer/Markdown/Color/Link", QColor);
    case CodeBackticks:
        return GET_SETTINGS("Lexer/Markdown/Color/CodeBackticks", QColor);
    case CodeDoubleBackticks:
        return GET_SETTINGS("Lexer/Markdown/Color/CodeDoubleBackticks", QColor);
    case CodeBlock:
        return GET_SETTINGS("Lexer/Markdown/Color/CodeBlock", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpLexerMarkdown::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Markdown/Fill/Universal", bool);
    case Special:
        return GET_SETTINGS("Lexer/Markdown/Fill/Special", bool);
    case StrongEmphasisAsterisks:
        return GET_SETTINGS("Lexer/Markdown/Fill/StrongEmphasisAsterisks", bool);
    case StrongEmphasisUnderscores:
        return GET_SETTINGS("Lexer/Markdown/Fill/StrongEmphasisUnderscores", bool);
    case EmphasisAsterisks:
        return GET_SETTINGS("Lexer/Markdown/Fill/EmphasisAsterisks", bool);
    case EmphasisUnderscores:
        return GET_SETTINGS("Lexer/Markdown/Fill/EmphasisUnderscores", bool);
    case Header1:
        return GET_SETTINGS("Lexer/Markdown/Fill/Header1", bool);
    case Header2:
        return GET_SETTINGS("Lexer/Markdown/Fill/Header2", bool);
    case Header3:
        return GET_SETTINGS("Lexer/Markdown/Fill/Header3", bool);
    case Header4:
        return GET_SETTINGS("Lexer/Markdown/Fill/Header4", bool);
    case Header5:
        return GET_SETTINGS("Lexer/Markdown/Fill/Header5", bool);
    case Header6:
        return GET_SETTINGS("Lexer/Markdown/Fill/Header6", bool);
    case Prechar:
        return GET_SETTINGS("Lexer/Markdown/Fill/Prechar", bool);
    case UnorderedListItem:
        return GET_SETTINGS("Lexer/Markdown/Fill/UnorderedListItem", bool);
    case OrderedListItem:
        return GET_SETTINGS("Lexer/Markdown/Fill/OrderedListItem", bool);
    case BlockQuote:
        return GET_SETTINGS("Lexer/Markdown/Fill/BlockQuote", bool);
    case StrikeOut:
        return GET_SETTINGS("Lexer/Markdown/Fill/StrikeOut", bool);
    case HorizontalRule:
        return GET_SETTINGS("Lexer/Markdown/Fill/HorizontalRule", bool);
    case Link:
        return GET_SETTINGS("Lexer/Markdown/Fill/Link", bool);
    case CodeBackticks:
        return GET_SETTINGS("Lexer/Markdown/Fill/CodeBackticks", bool);
    case CodeDoubleBackticks:
        return GET_SETTINGS("Lexer/Markdown/Fill/CodeDoubleBackticks", bool);
    case CodeBlock:
        return GET_SETTINGS("Lexer/Markdown/Fill/CodeBlock", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpLexerMarkdown::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Markdown/Font/Universal", QFont);
    case Special:
        return GET_SETTINGS("Lexer/Markdown/Font/Special", QFont);
    case StrongEmphasisAsterisks:
        return GET_SETTINGS("Lexer/Markdown/Font/StrongEmphasisAsterisks", QFont);
    case StrongEmphasisUnderscores:
        return GET_SETTINGS("Lexer/Markdown/Font/StrongEmphasisUnderscores", QFont);
    case EmphasisAsterisks:
        return GET_SETTINGS("Lexer/Markdown/Font/EmphasisAsterisks", QFont);
    case EmphasisUnderscores:
        return GET_SETTINGS("Lexer/Markdown/Font/EmphasisUnderscores", QFont);
    case Header1:
        return GET_SETTINGS("Lexer/Markdown/Font/Header1", QFont);
    case Header2:
        return GET_SETTINGS("Lexer/Markdown/Font/Header2", QFont);
    case Header3:
        return GET_SETTINGS("Lexer/Markdown/Font/Header3", QFont);
    case Header4:
        return GET_SETTINGS("Lexer/Markdown/Font/Header4", QFont);
    case Header5:
        return GET_SETTINGS("Lexer/Markdown/Font/Header5", QFont);
    case Header6:
        return GET_SETTINGS("Lexer/Markdown/Font/Header6", QFont);
    case Prechar:
        return GET_SETTINGS("Lexer/Markdown/Font/Prechar", QFont);
    case UnorderedListItem:
        return GET_SETTINGS("Lexer/Markdown/Font/UnorderedListItem", QFont);
    case OrderedListItem:
        return GET_SETTINGS("Lexer/Markdown/Font/OrderedListItem", QFont);
    case BlockQuote:
        return GET_SETTINGS("Lexer/Markdown/Font/BlockQuote", QFont);
    case StrikeOut:
        return GET_SETTINGS("Lexer/Markdown/Font/StrikeOut", QFont);
    case HorizontalRule:
        return GET_SETTINGS("Lexer/Markdown/Font/HorizontalRule", QFont);
    case Link:
        return GET_SETTINGS("Lexer/Markdown/Font/Link", QFont);
    case CodeBackticks:
        return GET_SETTINGS("Lexer/Markdown/Font/CodeBackticks", QFont);
    case CodeDoubleBackticks:
        return GET_SETTINGS("Lexer/Markdown/Font/CodeDoubleBackticks", QFont);
    case CodeBlock:
        return GET_SETTINGS("Lexer/Markdown/Font/CodeBlock", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpLexerMarkdown::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/Markdown/BgColor/Universal", QColor);
    case Special:
        return GET_SETTINGS("Lexer/Markdown/BgColor/Special", QColor);
    case StrongEmphasisAsterisks:
        return GET_SETTINGS("Lexer/Markdown/BgColor/StrongEmphasisAsterisks", QColor);
    case StrongEmphasisUnderscores:
        return GET_SETTINGS("Lexer/Markdown/BgColor/StrongEmphasisUnderscores", QColor);
    case EmphasisAsterisks:
        return GET_SETTINGS("Lexer/Markdown/BgColor/EmphasisAsterisks", QColor);
    case EmphasisUnderscores:
        return GET_SETTINGS("Lexer/Markdown/BgColor/EmphasisUnderscores", QColor);
    case Header1:
        return GET_SETTINGS("Lexer/Markdown/BgColor/Header1", QColor);
    case Header2:
        return GET_SETTINGS("Lexer/Markdown/BgColor/Header2", QColor);
    case Header3:
        return GET_SETTINGS("Lexer/Markdown/BgColor/Header3", QColor);
    case Header4:
        return GET_SETTINGS("Lexer/Markdown/BgColor/Header4", QColor);
    case Header5:
        return GET_SETTINGS("Lexer/Markdown/BgColor/Header5", QColor);
    case Header6:
        return GET_SETTINGS("Lexer/Markdown/BgColor/Header6", QColor);
    case Prechar:
        return GET_SETTINGS("Lexer/Markdown/BgColor/Prechar", QColor);
    case UnorderedListItem:
        return GET_SETTINGS("Lexer/Markdown/BgColor/UnorderedListItem", QColor);
    case OrderedListItem:
        return GET_SETTINGS("Lexer/Markdown/BgColor/OrderedListItem", QColor);
    case BlockQuote:
        return GET_SETTINGS("Lexer/Markdown/BgColor/BlockQuote", QColor);
    case StrikeOut:
        return GET_SETTINGS("Lexer/Markdown/BgColor/StrikeOut", QColor);
    case HorizontalRule:
        return GET_SETTINGS("Lexer/Markdown/BgColor/HorizontalRule", QColor);
    case Link:
        return GET_SETTINGS("Lexer/Markdown/BgColor/Link", QColor);
    case CodeBackticks:
        return GET_SETTINGS("Lexer/Markdown/BgColor/CodeBackticks", QColor);
    case CodeDoubleBackticks:
        return GET_SETTINGS("Lexer/Markdown/BgColor/CodeDoubleBackticks", QColor);
    case CodeBlock:
        return GET_SETTINGS("Lexer/Markdown/BgColor/CodeBlock", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

QString TpLexerMarkdown::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case Special:
        return tr("Special");
    case StrongEmphasisAsterisks:
        return tr("Strong emphasis using double asterisks");
    case StrongEmphasisUnderscores:
        return tr("Strong emphasis using double underscores");
    case EmphasisAsterisks:
        return tr("Emphasis using single asterisks");
    case EmphasisUnderscores:
        return tr("Emphasis using single underscores");
    case Header1:
        return tr("Level 1 header");
    case Header2:
        return tr("Level 2 header");
    case Header3:
        return tr("Level 3 header");
    case Header4:
        return tr("Level 4 header");
    case Header5:
        return tr("Level 5 header");
    case Header6:
        return tr("Level 6 header");
    case Prechar:
        return tr("Pre-char");
    case UnorderedListItem:
        return tr("Unordered list item");
    case OrderedListItem:
        return tr("Ordered list item");
    case BlockQuote:
        return tr("Block quote");
    case StrikeOut:
        return tr("Strike out");
    case HorizontalRule:
        return tr("Horizontal rule");
    case Link:
        return tr("Link");
    case CodeBackticks:
        return tr("Code between backticks");
    case CodeDoubleBackticks:
        return tr("Code between double backticks");
    case CodeBlock:
        return tr("Code block");
    }

    return QString();
}

TP_END_NAMESPACE
