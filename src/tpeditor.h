#ifndef TPEDITOR_H
#define TPEDITOR_H

#include <Qsci/qsciscintilla.h>

#include <Lexers/TpGeneralLexer>
#include <TpGlobals>

TP_NAMESPACE

class TpBookmarkView;
class TpFindContainer;
class TpMainWindow;
class TpTabWidget;

class QSCINTILLA_EXPORT TpEditor : public QsciScintilla
{
    Q_OBJECT

    DEF_PROP(WrapVisualFlag, startFlag);
    DEF_PROP(WrapVisualFlag, endFlag);
    DEF_PROP(int, autoCompletionStyle);
    DEF_PROP(bool, lineNumbers);

    friend class TpMainWindow;
    friend class TpMenuBar;
    friend class TpOpenAssistant;
    friend class TpSaveAssistant;
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
    DEF_PROP_FUNC(int, autoCompletionStyle, AutoCompletionStyle);

    int currentLine() const;
    void setCurrentLine(int line);

    Languages currentLexer() const;
    bool setCurrentLexer(Languages currentLexer);
    int getLength() const;
    int getPosition() const;

    int findIndicator() const;
    int findIndicatorStart(int position) const;
    int findIndicatorEnd(int position) const;
    int incrementalIndicator() const;
    int bookmarkMarker() const;

    QMap<QString, QVariant> toMap();
    QString fromMap(QMap<QString, QVariant> map);

    void adjustMargins();

    TpMainWindow *ultimateParent() const;

    QByteArray textAsBytes(const QString &text) const;
    QString bytesAsText(const QByteArray &bytes) const;

signals:
    void fileNameChanged(const QString &path, const QString &name);
    void checkBoxChecked(bool isChecked);
    void positionChanged(int position, int line, int index);
    void returnPressed();
    void punctuation();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    void adjustAppearance();
    void adjustBookmarks();

private slots:
    void onCursorPositionChanged(int line, int index);
    void onMarginClicked(int margin, int line, Qt::KeyboardModifiers modifiers);
    void onBookmarkViewDoubleClicked(int line);

private:
    TpTabWidget *m_parent;
    QString m_content;
    QString m_filePath;
    unsigned int m_untitled;

    bool m_bracketing;
    bool m_bracing;
    bool m_parenthesizing;
    bool m_apostrophing;
    bool m_stringing;

    int m_findIndicator;
    TpFindContainer *m_findContainer;

    int m_incrementalIndicator;

    int m_bookmarkMarker;
    TpBookmarkView *m_bookmarkView;

    QMap<Languages, TpGeneralLexer*> m_lexers;
};

TP_END_NAMESPACE

#endif // TPEDITOR_H
