#ifndef TPDELEGATETYPECHECKER_H
#define TPDELEGATETYPECHECKER_H

#include <QRegularExpression>

#include <TpGlobals>

TP_NAMESPACE

struct TpDelegateTypeChecker
{
    TpDelegateTypeChecker();

    QRegularExpression regexBool;
    QRegularExpression regexByteArray;
    QRegularExpression regexChar;
    QRegularExpression regexColor;
    QRegularExpression regexDate;
    QRegularExpression regexDateTime;
    QRegularExpression regexDouble;
    QRegularExpression regexPoint;
    QRegularExpression regexRect;
    QRegularExpression regexSignedInt;
    QRegularExpression regexSize;
    QRegularExpression regexTime;
    QRegularExpression regexUnsignedInt;
};

typedef QSharedPointer<TpDelegateTypeChecker> TpTypeCheckerPtr;

TP_END_NAMESPACE

#endif // TPDELEGATETYPECHECKER_H
