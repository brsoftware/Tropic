#include <QRandomGenerator>

#include <Utilities/TpCaseEngine>
#include <TpEditor>

TP_NAMESPACE

void TpCaseEngine::convertCase(TpEditor *editor, TpCaseEngine::Case textCase)
{
    if (!editor)
        return;

    int l1, i1, l2, i2;
    if (!editor->hasSelectedText())
        editor->selectAll();
    editor->getSelection(&l1, &i1, &l2, &i2);
    const QString &original = editor->selectedText();

    QString text;

    switch (textCase)
    {
    case Upper:
        text = original.toUpper();
        break;
    case Lower:
        text = original.toLower();
        break;

    case Title: {
        QChar prev = ' ';

        for (const auto &c : std::as_const(original))
        {
            if (prev.isSpace() || prev.isPunct())
                text += c.toUpper();
            else
                text += c.toLower();
            prev = c;
        }

        break;
    }

    case Sentence: {
        bool capNext = true;

        for (const auto &c : std::as_const(original))
        {
            if (capNext && c.isLetter())
            {
                text += c.toUpper();
                capNext = false;
            }

            else
            {
                text += c.toLower();
            }

            if (c == '.' || c == '?' || c == '!' || c == '"' || c == '\'')
                capNext = true;
            else if (c.isSpace() && capNext)
                capNext = true;
        }

        break;
    }

    case Invert: {
        for (const auto &c : std::as_const(original))
        {
            if (c.isUpper())
                text += c.toLower();
            else if (c.isLower())
                text += c.toUpper();
            else
                text += c;
        }

        break;
    }

    case Random: {
        QRandomGenerator gen;

        for (const auto &c : std::as_const(original))
        {
            int g = gen.bounded(1, 3);
            text += (g == 1 ? c.toUpper() : c.toLower());
        }

        break;
    }
    }

    modify(editor, text, l1, i1, l2, i2);
}

void TpCaseEngine::modify(TpEditor *editor, const QString &text, int l1, int i1, int l2, int i2)
{
    if (!editor)
        return;

    editor->beginUndoAction();
    editor->setSelection(l1, i1, l2, i2);
    editor->removeSelectedText();
    editor->insert(text);
    editor->endUndoAction();
}

TP_END_NAMESPACE
