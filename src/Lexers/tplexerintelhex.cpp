#include <Lexers/TpLexerIntelHex>

TP_NAMESPACE

TpLexerIntelHex::TpLexerIntelHex(QObject *parent)
    : TpFamilyHexLexer(parent)
{}

const char *TpLexerIntelHex::language() const
{
    return "Intel Hex";
}

QColor TpLexerIntelHex::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/IntelHex/Color/Universal", QColor);
    case RecordStart:
        return GET_SETTINGS("Lexer/IntelHex/Color/RecordStart", QColor);
    case RecordType:
        return GET_SETTINGS("Lexer/IntelHex/Color/RecordType", QColor);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/IntelHex/Color/UnknownRecordType", QColor);
    case ByteCount:
        return GET_SETTINGS("Lexer/IntelHex/Color/ByteCount", QColor);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/IntelHex/Color/IncorrectByteCount", QColor);
    case NoAddress:
        return GET_SETTINGS("Lexer/IntelHex/Color/NoAddress", QColor);
    case DataAddress:
        return GET_SETTINGS("Lexer/IntelHex/Color/DataAddress", QColor);
    case RecordCount:
        return GET_SETTINGS("Lexer/IntelHex/Color/RecordCount", QColor);
    case StartAddress:
        return GET_SETTINGS("Lexer/IntelHex/Color/StartAddress", QColor);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/IntelHex/Color/ExtendedAddress", QColor);
    case OddData:
        return GET_SETTINGS("Lexer/IntelHex/Color/OddData", QColor);
    case EvenData:
        return GET_SETTINGS("Lexer/IntelHex/Color/EvenData", QColor);
    case UnknownData:
        return GET_SETTINGS("Lexer/IntelHex/Color/UnknownData", QColor);
    case Checksum:
        return GET_SETTINGS("Lexer/IntelHex/Color/Checksum", QColor);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/IntelHex/Color/IncorrectChecksum", QColor);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/IntelHex/Color/TrailingGarbage", QColor);
    }

    return TpFamilyHexLexer::defaultColor(style);
}

bool TpLexerIntelHex::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/IntelHex/Fill/Universal", bool);
    case RecordStart:
        return GET_SETTINGS("Lexer/IntelHex/Fill/RecordStart", bool);
    case RecordType:
        return GET_SETTINGS("Lexer/IntelHex/Fill/RecordType", bool);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/IntelHex/Fill/UnknownRecordType", bool);
    case ByteCount:
        return GET_SETTINGS("Lexer/IntelHex/Fill/ByteCount", bool);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/IntelHex/Fill/IncorrectByteCount", bool);
    case NoAddress:
        return GET_SETTINGS("Lexer/IntelHex/Fill/NoAddress", bool);
    case DataAddress:
        return GET_SETTINGS("Lexer/IntelHex/Fill/DataAddress", bool);
    case RecordCount:
        return GET_SETTINGS("Lexer/IntelHex/Fill/RecordCount", bool);
    case StartAddress:
        return GET_SETTINGS("Lexer/IntelHex/Fill/StartAddress", bool);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/IntelHex/Fill/ExtendedAddress", bool);
    case OddData:
        return GET_SETTINGS("Lexer/IntelHex/Fill/OddData", bool);
    case EvenData:
        return GET_SETTINGS("Lexer/IntelHex/Fill/EvenData", bool);
    case UnknownData:
        return GET_SETTINGS("Lexer/IntelHex/Fill/UnknownData", bool);
    case Checksum:
        return GET_SETTINGS("Lexer/IntelHex/Fill/Checksum", bool);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/IntelHex/Fill/IncorrectChecksum", bool);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/IntelHex/Fill/TrailingGarbage", bool);
    }

    return TpFamilyHexLexer::defaultEolFill(style);
}

QFont TpLexerIntelHex::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/IntelHex/Font/Universal", QFont);
    case RecordStart:
        return GET_SETTINGS("Lexer/IntelHex/Font/RecordStart", QFont);
    case RecordType:
        return GET_SETTINGS("Lexer/IntelHex/Font/RecordType", QFont);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/IntelHex/Font/UnknownRecordType", QFont);
    case ByteCount:
        return GET_SETTINGS("Lexer/IntelHex/Font/ByteCount", QFont);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/IntelHex/Font/IncorrectByteCount", QFont);
    case NoAddress:
        return GET_SETTINGS("Lexer/IntelHex/Font/NoAddress", QFont);
    case DataAddress:
        return GET_SETTINGS("Lexer/IntelHex/Font/DataAddress", QFont);
    case RecordCount:
        return GET_SETTINGS("Lexer/IntelHex/Font/RecordCount", QFont);
    case StartAddress:
        return GET_SETTINGS("Lexer/IntelHex/Font/StartAddress", QFont);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/IntelHex/Font/ExtendedAddress", QFont);
    case OddData:
        return GET_SETTINGS("Lexer/IntelHex/Font/OddData", QFont);
    case EvenData:
        return GET_SETTINGS("Lexer/IntelHex/Font/EvenData", QFont);
    case UnknownData:
        return GET_SETTINGS("Lexer/IntelHex/Font/UnknownData", QFont);
    case Checksum:
        return GET_SETTINGS("Lexer/IntelHex/Font/Checksum", QFont);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/IntelHex/Font/IncorrectChecksum", QFont);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/IntelHex/Font/TrailingGarbage", QFont);
    }

    return TpFamilyHexLexer::defaultFont(style);
}

QColor TpLexerIntelHex::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/Universal", QColor);
    case RecordStart:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/RecordStart", QColor);
    case RecordType:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/RecordType", QColor);
    case UnknownRecordType:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/UnknownRecordType", QColor);
    case ByteCount:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/ByteCount", QColor);
    case IncorrectByteCount:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/IncorrectByteCount", QColor);
    case NoAddress:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/NoAddress", QColor);
    case DataAddress:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/DataAddress", QColor);
    case RecordCount:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/RecordCount", QColor);
    case StartAddress:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/StartAddress", QColor);
    case ExtendedAddress:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/ExtendedAddress", QColor);
    case OddData:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/OddData", QColor);
    case EvenData:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/EvenData", QColor);
    case UnknownData:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/UnknownData", QColor);
    case Checksum:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/Checksum", QColor);
    case IncorrectChecksum:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/IncorrectChecksum", QColor);
    case TrailingGarbage:
        return GET_SETTINGS("Lexer/IntelHex/BgColor/TrailingGarbage", QColor);
    }

    return TpFamilyHexLexer::defaultPaper(style);
}

TP_END_NAMESPACE
