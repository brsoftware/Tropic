#ifndef TPMESSAGECONFIRMCLOSE_H
#define TPMESSAGECONFIRMCLOSE_H

#include <QMessageBox>

#include <TpGlobals>

TP_NAMESPACE

inline const char *msgcc_InfoText =
"If you clicked 'Don't Save' or 'Discard', your document will be discarded forever and this cannot be undone.";

inline const char *msgcc_Text =
"Do you want to keep or discard your editted document?";

inline const char *msgcc_Title =
"Confirm Close";

class TpMessageConfirmClose : public QObject
{
    Q_OBJECT

    DEF_PROP(QWidget*, parent);

public:
    enum
    {
        Save,
        Discard,
        Cancel
    };

public:
    TpMessageConfirmClose(QWidget *parent);

public:
    int say();
};

TP_END_NAMESPACE

#endif // TPMESSAGECONFIRMCLOSE_H
