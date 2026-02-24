#include <Lexers/TpLexerSRecord>

TP_NAMESPACE

TpLexerSRecord::TpLexerSRecord(QObject *parent)
    : TpFamilyHexLexer(parent)
{}

const char *TpLexerSRecord::language() const
{
    return "S-Record";
}

const char *TpLexerSRecord::lexer() const
{
    return "srec";
}

QColor TpLexerSRecord::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/SRecord/Color/Universal", QColor);
    case RecordStart:
        return GET_SETTINGS("Lexer/SRecord/Color/RecordStart", QColor);
    case RecordType:
        return GET_SETTINGS("Lexer/SRecord/Color/RecordType", QColor);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/SRecord/Color/UnknownRecordType", QColor);
    case ByteCount:
        return GET_SETTINGS("Lexer/SRecord/Color/ByteCount", QColor);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/SRecord/Color/IncorrectByteCount", QColor);
    case NoAddress:
        return GET_SETTINGS("Lexer/SRecord/Color/NoAddress", QColor);
    case DataAddress:
        return GET_SETTINGS("Lexer/SRecord/Color/DataAddress", QColor);
    case RecordCount:
        return GET_SETTINGS("Lexer/SRecord/Color/RecordCount", QColor);
    case StartAddress:
        return GET_SETTINGS("Lexer/SRecord/Color/StartAddress", QColor);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/SRecord/Color/ExtendedAddress", QColor);
    case OddData:
        return GET_SETTINGS("Lexer/SRecord/Color/OddData", QColor);
    case EvenData:
        return GET_SETTINGS("Lexer/SRecord/Color/EvenData", QColor);
    case UnknownData:
        return GET_SETTINGS("Lexer/SRecord/Color/UnknownData", QColor);
    case Checksum:
        return GET_SETTINGS("Lexer/SRecord/Color/Checksum", QColor);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/SRecord/Color/IncorrectChecksum", QColor);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/SRecord/Color/TrailingGarbage", QColor);
    }

    return TpFamilyHexLexer::defaultColor(style);
}

bool TpLexerSRecord::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/SRecord/Fill/Universal", bool);
    case RecordStart:
        return GET_SETTINGS("Lexer/SRecord/Fill/RecordStart", bool);
    case RecordType:
        return GET_SETTINGS("Lexer/SRecord/Fill/RecordType", bool);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/SRecord/Fill/UnknownRecordType", bool);
    case ByteCount:
        return GET_SETTINGS("Lexer/SRecord/Fill/ByteCount", bool);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/SRecord/Fill/IncorrectByteCount", bool);
    case NoAddress:
        return GET_SETTINGS("Lexer/SRecord/Fill/NoAddress", bool);
    case DataAddress:
        return GET_SETTINGS("Lexer/SRecord/Fill/DataAddress", bool);
    case RecordCount:
        return GET_SETTINGS("Lexer/SRecord/Fill/RecordCount", bool);
    case StartAddress:
        return GET_SETTINGS("Lexer/SRecord/Fill/StartAddress", bool);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/SRecord/Fill/ExtendedAddress", bool);
    case OddData:
        return GET_SETTINGS("Lexer/SRecord/Fill/OddData", bool);
    case EvenData:
        return GET_SETTINGS("Lexer/SRecord/Fill/EvenData", bool);
    case UnknownData:
        return GET_SETTINGS("Lexer/SRecord/Fill/UnknownData", bool);
    case Checksum:
        return GET_SETTINGS("Lexer/SRecord/Fill/Checksum", bool);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/SRecord/Fill/IncorrectChecksum", bool);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/SRecord/Fill/TrailingGarbage", bool);
    }

    return TpFamilyHexLexer::defaultEolFill(style);
}

QFont TpLexerSRecord::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/SRecord/Font/Universal", QFont);
    case RecordStart:
        return GET_SETTINGS("Lexer/SRecord/Font/RecordStart", QFont);
    case RecordType:
        return GET_SETTINGS("Lexer/SRecord/Font/RecordType", QFont);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/SRecord/Font/UnknownRecordType", QFont);
    case ByteCount:
        return GET_SETTINGS("Lexer/SRecord/Font/ByteCount", QFont);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/SRecord/Font/IncorrectByteCount", QFont);
    case NoAddress:
        return GET_SETTINGS("Lexer/SRecord/Font/NoAddress", QFont);
    case DataAddress:
        return GET_SETTINGS("Lexer/SRecord/Font/DataAddress", QFont);
    case RecordCount:
        return GET_SETTINGS("Lexer/SRecord/Font/RecordCount", QFont);
    case StartAddress:
        return GET_SETTINGS("Lexer/SRecord/Font/StartAddress", QFont);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/SRecord/Font/ExtendedAddress", QFont);
    case OddData:
        return GET_SETTINGS("Lexer/SRecord/Font/OddData", QFont);
    case EvenData:
        return GET_SETTINGS("Lexer/SRecord/Font/EvenData", QFont);
    case UnknownData:
        return GET_SETTINGS("Lexer/SRecord/Font/UnknownData", QFont);
    case Checksum:
        return GET_SETTINGS("Lexer/SRecord/Font/Checksum", QFont);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/SRecord/Font/IncorrectChecksum", QFont);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/SRecord/Font/TrailingGarbage", QFont);
    }

    return TpFamilyHexLexer::defaultFont(style);
}

QColor TpLexerSRecord::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/SRecord/BgColor/Universal", QColor);
    case RecordStart:
        return GET_SETTINGS("Lexer/SRecord/BgColor/RecordStart", QColor);
    case RecordType:
        return GET_SETTINGS("Lexer/SRecord/BgColor/RecordType", QColor);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/SRecord/BgColor/UnknownRecordType", QColor);
    case ByteCount:
        return GET_SETTINGS("Lexer/SRecord/BgColor/ByteCount", QColor);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/SRecord/BgColor/IncorrectByteCount", QColor);
    case NoAddress:
        return GET_SETTINGS("Lexer/SRecord/BgColor/NoAddress", QColor);
    case DataAddress:
        return GET_SETTINGS("Lexer/SRecord/BgColor/DataAddress", QColor);
    case RecordCount:
        return GET_SETTINGS("Lexer/SRecord/BgColor/RecordCount", QColor);
    case StartAddress:
        return GET_SETTINGS("Lexer/SRecord/BgColor/StartAddress", QColor);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/SRecord/BgColor/ExtendedAddress", QColor);
    case OddData:
        return GET_SETTINGS("Lexer/SRecord/BgColor/OddData", QColor);
    case EvenData:
        return GET_SETTINGS("Lexer/SRecord/BgColor/EvenData", QColor);
    case UnknownData:
        return GET_SETTINGS("Lexer/SRecord/BgColor/UnknownData", QColor);
    case Checksum:
        return GET_SETTINGS("Lexer/SRecord/BgColor/Checksum", QColor);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/SRecord/BgColor/IncorrectChecksum", QColor);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/SRecord/BgColor/TrailingGarbage", QColor);
    }

    return TpFamilyHexLexer::defaultPaper(style);
}

TP_END_NAMESPACE
