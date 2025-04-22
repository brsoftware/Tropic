#include <Lexers/TpGeneralLexer>

#include <TpEditor>

TP_NAMESPACE

TpGeneralLexer::TpGeneralLexer(QObject *parent)
    : QsciLexer(parent)
{}

int TpGeneralLexer::autoIndentStyle() const
{
    // DEF_SETTINGS;

    // if (GET_SETTINGS("Tools/Autoindentation/Style/Auto", bool))
    //     return TpEditor::AiMaintain;

    // return qobject_cast<TpEditor*>(parent())->autoCompletionStyle();

    TpEditor *editor = qobject_cast<TpEditor*>(parent());

    if (editor)
    {
        return editor->autoCompletionStyle();
    }

    return TpEditor::AiMaintain;
}

int TpGeneralLexer::blockLookback() const
{
    return 3;
}

QColor TpGeneralLexer::defaultColor(int style) const
{
    DEF_SETTINGS;
    return GET_SETTINGS("Editor/Color/Universal", QColor);
}

bool TpGeneralLexer::defaultEolFill(int style) const
{
    DEF_SETTINGS;
    return GET_SETTINGS("Editor/Fill/Universal", bool);
}

QFont TpGeneralLexer::defaultFont(int style) const
{
    DEF_SETTINGS;
    return GET_SETTINGS("Editor/Font/Universal", QFont);
}

QColor TpGeneralLexer::defaultPaper(int style) const
{
    DEF_SETTINGS;
    return GET_SETTINGS("Editor/BgColor/Universal", QColor);
}

void TpGeneralLexer::setLexerProperty(int, QVariant)
{}

QVariant TpGeneralLexer::lexerProperty(int) const
{
    return 0;
}

QByteArray TpGeneralLexer::textAsBytes(const QString &text) const
{
    if (TpEditor *editor = qobject_cast<TpEditor*>(parent()))
        return editor->textAsBytes(text);
    else
        return QByteArray();
}

QString TpGeneralLexer::bytesAsText(const QByteArray &text) const
{
    if (TpEditor *editor = qobject_cast<TpEditor*>(parent()))
        return editor->bytesAsText(text);
    else
        return QByteArray();
}

TP_END_NAMESPACE
