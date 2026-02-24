#include <Utilities/TpDelegateTypeChecker>

TP_NAMESPACE

TpDelegateTypeChecker::TpDelegateTypeChecker()
{
    regexBool.setPattern("^(true)|(false)$");
    regexBool.setPatternOptions(QRegularExpression::PatternOption::CaseInsensitiveOption);
    Q_ASSERT(regexBool.isValid());

    regexByteArray.setPattern(R"RX(^[\x00-\xff]*$)RX");
    Q_ASSERT(regexByteArray.isValid());

    regexChar.setPattern("^.$");
    Q_ASSERT(regexChar.isValid());

    regexColor.setPattern(R"RX(^\(([0-9]*),([0-9]*),([0-9]*),([0-9]*)\)$)RX");
    Q_ASSERT(regexColor.isValid());

    regexDouble.setPattern("");
    Q_ASSERT(regexDouble.isValid());

    regexPoint.setPattern(R"RX(^\((-?[0-9]*),(-?[0-9]*)\)$)RX");
    Q_ASSERT(regexPoint.isValid());

    regexRect.setPattern(R"RX(^\((-?[0-9]*),(-?[0-9]*),(-?[0-9]*),(-?[0-9]*)\)$)RX");
    Q_ASSERT(regexRect.isValid());

    regexSignedInt.setPattern("^-?[0-9]*$");
    Q_ASSERT(regexSignedInt.isValid());

    regexSize = regexPoint;

    regexUnsignedInt.setPattern("^[0-9]+$");
    Q_ASSERT(regexUnsignedInt.isValid());

    const QString datePattern = "([0-9]{,4})-([0-9]{,2})-([0-9]{,2})";
    regexDate.setPattern('^' + datePattern + '$');
    Q_ASSERT(regexDate.isValid());

    const QString timePattern = "([0-9]{,2}):([0-9]{,2}):([0-9]{,2})";
    regexTime.setPattern('^' + timePattern + '$');
    Q_ASSERT(regexTime.isValid());

    regexDateTime.setPattern('^' + datePattern + 'T' + timePattern + '$');
    Q_ASSERT(regexDateTime.isValid());
}

TP_END_NAMESPACE
