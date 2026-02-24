#ifndef TPCASEENGINE_H
#define TPCASEENGINE_H

#include <TpGlobals>

TP_NAMESPACE

class TpEditor;

class TpCaseEngine
{
    Q_GADGET

public:
    enum Case
    {
        Upper,
        Lower,
        Title,
        Sentence,
        Invert,
        Random,
    };
    Q_ENUM(Case)

public:
    static void convertCase(TpEditor *editor, Case textCase);

private:
    static void modify(TpEditor *editor, const QString &text, int l1, int i1, int l2, int i2);

private:
    TpCaseEngine() = delete;
    TpCaseEngine(const TpCaseEngine&) = delete;
    TpCaseEngine(TpCaseEngine&&) = delete;
};

TP_END_NAMESPACE

#endif // TPCASEENGINE_H
