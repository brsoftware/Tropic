#include <Lexers/TpLexerTektronixHex>

TP_NAMESPACE

TpLexerTektronixHex::TpLexerTektronixHex(QObject *parent)
    : TpFamilyHexLexer(parent)
{}

const char *TpLexerTektronixHex::language() const
{
    return "Tektronix Hex";
}

const char *TpLexerTektronixHex::lexer() const
{
    return "tehex";
}

QColor TpLexerTektronixHex::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TektronixHex/Color/Universal", QColor);
    case RecordStart:
        return GET_SETTINGS("Lexer/TektronixHex/Color/RecordStart", QColor);
    case RecordType:
        return GET_SETTINGS("Lexer/TektronixHex/Color/RecordType", QColor);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/TektronixHex/Color/UnknownRecordType", QColor);
    case ByteCount:
        return GET_SETTINGS("Lexer/TektronixHex/Color/ByteCount", QColor);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/TektronixHex/Color/IncorrectByteCount", QColor);
    case NoAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Color/NoAddress", QColor);
    case DataAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Color/DataAddress", QColor);
    case RecordCount:
        return GET_SETTINGS("Lexer/TektronixHex/Color/RecordCount", QColor);
    case StartAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Color/StartAddress", QColor);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Color/ExtendedAddress", QColor);
    case OddData:
        return GET_SETTINGS("Lexer/TektronixHex/Color/OddData", QColor);
    case EvenData:
        return GET_SETTINGS("Lexer/TektronixHex/Color/EvenData", QColor);
    case UnknownData:
        return GET_SETTINGS("Lexer/TektronixHex/Color/UnknownData", QColor);
    case Checksum:
        return GET_SETTINGS("Lexer/TektronixHex/Color/Checksum", QColor);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/TektronixHex/Color/IncorrectChecksum", QColor);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/TektronixHex/Color/TrailingGarbage", QColor);
    }

    return TpFamilyHexLexer::defaultColor(style);
}

bool TpLexerTektronixHex::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/Universal", bool);
    case RecordStart:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/RecordStart", bool);
    case RecordType:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/RecordType", bool);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/UnknownRecordType", bool);
    case ByteCount:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/ByteCount", bool);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/IncorrectByteCount", bool);
    case NoAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/NoAddress", bool);
    case DataAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/DataAddress", bool);
    case RecordCount:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/RecordCount", bool);
    case StartAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/StartAddress", bool);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/ExtendedAddress", bool);
    case OddData:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/OddData", bool);
    case EvenData:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/EvenData", bool);
    case UnknownData:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/UnknownData", bool);
    case Checksum:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/Checksum", bool);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/IncorrectChecksum", bool);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/TektronixHex/Fill/TrailingGarbage", bool);
    }

    return TpFamilyHexLexer::defaultEolFill(style);
}

QFont TpLexerTektronixHex::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TektronixHex/Font/Universal", QFont);
    case RecordStart:
        return GET_SETTINGS("Lexer/TektronixHex/Font/RecordStart", QFont);
    case RecordType:
        return GET_SETTINGS("Lexer/TektronixHex/Font/RecordType", QFont);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/TektronixHex/Font/UnknownRecordType", QFont);
    case ByteCount:
        return GET_SETTINGS("Lexer/TektronixHex/Font/ByteCount", QFont);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/TektronixHex/Font/IncorrectByteCount", QFont);
    case NoAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Font/NoAddress", QFont);
    case DataAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Font/DataAddress", QFont);
    case RecordCount:
        return GET_SETTINGS("Lexer/TektronixHex/Font/RecordCount", QFont);
    case StartAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Font/StartAddress", QFont);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/TektronixHex/Font/ExtendedAddress", QFont);
    case OddData:
        return GET_SETTINGS("Lexer/TektronixHex/Font/OddData", QFont);
    case EvenData:
        return GET_SETTINGS("Lexer/TektronixHex/Font/EvenData", QFont);
    case UnknownData:
        return GET_SETTINGS("Lexer/TektronixHex/Font/UnknownData", QFont);
    case Checksum:
        return GET_SETTINGS("Lexer/TektronixHex/Font/Checksum", QFont);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/TektronixHex/Font/IncorrectChecksum", QFont);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/TektronixHex/Font/TrailingGarbage", QFont);
    }

    return TpFamilyHexLexer::defaultFont(style);
}

QColor TpLexerTektronixHex::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/Universal", QColor);
    case RecordStart:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/RecordStart", QColor);
    case RecordType:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/RecordType", QColor);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/UnknownRecordType", QColor);
    case ByteCount:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/ByteCount", QColor);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/IncorrectByteCount", QColor);
    case NoAddress:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/NoAddress", QColor);
    case DataAddress:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/DataAddress", QColor);
    case RecordCount:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/RecordCount", QColor);
    case StartAddress:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/StartAddress", QColor);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/ExtendedAddress", QColor);
    case OddData:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/OddData", QColor);
    case EvenData:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/EvenData", QColor);
    case UnknownData:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/UnknownData", QColor);
    case Checksum:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/Checksum", QColor);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/IncorrectChecksum", QColor);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/TektronixHex/BgColor/TrailingGarbage", QColor);
    }

    return TpFamilyHexLexer::defaultPaper(style);
}

TP_END_NAMESPACE
