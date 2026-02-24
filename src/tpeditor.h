#ifndef TPEDITOR_H
#define TPEDITOR_H

#include <Qsci/qsciscintilla.h>

#include <Lexers/TpGeneralLexer>
#include <TpGlobals>

TP_NAMESPACE

class TpBookmarkView;
class TpFindContainer;
class TpMainWindow;
class TpTabSplitter;
class TpTabWidget;

class QSCINTILLA_EXPORT TpEditor : public QsciScintilla
{
    Q_OBJECT

    DEF_PROP(WrapVisualFlag, startFlag);
    DEF_PROP(WrapVisualFlag, endFlag);
    DEF_PROP(int, autoCompletionStyle);
    DEF_PROP(bool, lineNumbers);
    DEF_PROP(bool, autoInsertBrackets);
    DEF_PROP(bool, autoBrace);
    DEF_PROP(bool, autoSelectionWrap);
    DEF_PROP(bool, autoDelete);

    friend class TpMainWindow;
    friend class TpMenuBar;
    friend class TpOpenAssistant;
    friend class TpSaveAssistant;
    friend class TpSessionThread;
    friend class TpTabSplitter;
    friend class TpTabWidget;

public:
    TpEditor(TpTabWidget *parent);
    ~TpEditor();

public:
    const QString &content() const;
    const QString &filePath() const;
    unsigned int untitled() const;

    void setStartFlag(WrapVisualFlag startFlag);
    WrapVisualFlag startFlag() const;
    void setEndFlag(WrapVisualFlag endFlag);
    WrapVisualFlag endFlag() const;
    void setLineNumbers(bool lineNumbers);
    bool lineNumbers() const;
    void setAutoCompletionStyle(int style);
    int autoCompletionStyle() const;

    int currentLine() const;
    void setCurrentLine(int line);
    QChar charAt(int position) const;
    QString eolChar() const;
    QList<QString> physicalLines() const;
    QList<QString> physicalLinesWithEol() const;
    void selectionLineRange(int &first, int &last);

    Languages currentLexer() const;
    bool setCurrentLexer(Languages currentLexer);
    int getLength() const;
    int getPosition() const;
    void setCurrentPosition(int position);
    void setCurrentPosition(int line, int index);

    int findIndicator() const;
    int findIndicatorStart(int position) const;
    int findIndicatorEnd(int position) const;
    int incrementalIndicator() const;
    int bookmarkMarker() const;

    DEF_PROP_FUNC(bool, autoInsertBrackets, AutoInsertBrackets);
    DEF_PROP_FUNC(bool, autoBrace, AutoBrace);
    DEF_PROP_FUNC(bool, autoSelectionWrap, AutoSelectionWrap);
    DEF_PROP_FUNC(bool, autoDelete, AutoDelete);

    QMap<QString, QVariant> toMap(QMap<QString, QVariant> additionalInfo = {});
    QString fromMap(QMap<QString, QVariant> map);

    void adjustAppearance();
    void adjustMargins();

    TpMainWindow *ultimateParent() const;

    QByteArray textAsBytes(const QString &text) const;
    QString bytesAsText(const QByteArray &bytes) const;

    TpEditor *cloneEditor(TpTabWidget *parent);

signals:
    void fileNameChanged(const QString &path, const QString &name);
    void checkBoxChecked(bool isChecked);
    void positionChanged(int position, int line, int index);
    void returnPressed();
    void punctuation();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void adjustBookmarks();
    bool toSelectionWrap(QKeyEvent *event);
    bool toSmartBackspace(QKeyEvent *event);
    bool toSmartDelete(QKeyEvent *event);
    bool toAutoIndentOnEnter(QKeyEvent *event);

private slots:
    void onCursorPositionChanged(int line, int index);
    void onMarginClicked(int margin, int line, Qt::KeyboardModifiers modifiers);
    void onBookmarkViewDoubleClicked(int line);
    void onCustomContextMenuRequested(const QPoint &point);

private:
    TpTabWidget *m_parent;
    QString m_content;
    QString m_filePath;
    unsigned int m_untitled;

    const QHash<int, QChar> m_bracketMap = {
        {Qt::Key::Key_BraceRight, '}'},
        {Qt::Key::Key_BracketRight, ']'},
        {Qt::Key::Key_ParenRight, ')'},
        {Qt::Key::Key_QuoteDbl, '"'},
        {Qt::Key::Key_Apostrophe, '\''}
    };

    const QHash<int, QChar> m_leftBracketMap = {
        {Qt::Key::Key_BraceLeft, '}'},
        {Qt::Key::Key_BracketLeft, ']'},
        {Qt::Key::Key_ParenLeft, ')'},
        {Qt::Key::Key_QuoteDbl, '"'},
        {Qt::Key::Key_Apostrophe, '\''}
    };

    const QHash<QChar, QChar> m_openToClose = {
        {'(', ')'},
        {'[', ']'},
        {'{', '}'},
        {'"', '"'},
        {'\'', '\''}
    };

    const QHash<QChar, QChar> m_closeToOpen = {
        {')', '('},
        {']', '['},
        {'}', '{'},
        {'"', '"'},
        {'\'', '\''}
    };

    // const QMap<QString, QVariant> m_config;

    int m_findIndicator;
    TpFindContainer *m_findContainer;

    int m_incrementalIndicator;

    int m_bookmarkMarker;
    TpBookmarkView *m_bookmarkView;

    QMap<Languages, TpGeneralLexer*> m_lexers;
};

TP_END_NAMESPACE

#endif // TPEDITOR_H
