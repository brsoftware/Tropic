#include <Lexers/TpFamilyHexLexer>

TP_NAMESPACE

TpFamilyHexLexer::TpFamilyHexLexer(QObject *parent)
    : TpGeneralLexer(parent)
{}

TpFamilyHexLexer::~TpFamilyHexLexer()
{}

const char *TpFamilyHexLexer::language() const
{
    return "Hex (abstract)";
}

const char *TpFamilyHexLexer::lexer() const
{
    return "ihex";
}

QColor TpFamilyHexLexer::defaultColor(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Color/Universal", QColor);
    case RecordStart:
        return GET_SETTINGS("Editor/Color/Keyword", QColor);
    case RecordType:
        return GET_SETTINGS("Editor/Color/Type", QColor);
    case UnknownRecordType:
        return GET_SETTINGS("Editor/Color/Error", QColor);
    case ByteCount:
        return GET_SETTINGS("Editor/Color/Number", QColor);
    case IncorrectByteCount:
        return GET_SETTINGS("Editor/Color/Warning", QColor);
    case NoAddress:
        return GET_SETTINGS("Editor/Color/WeakWarning", QColor);
    case DataAddress:
        return GET_SETTINGS("Editor/Color/DoubleQuotedString", QColor);
    case RecordCount:
        return GET_SETTINGS("Editor/Color/SingleQuotedString", QColor);
    case StartAddress:
        return GET_SETTINGS("Editor/Color/RawString", QColor);
    case ExtendedAddress:
        return GET_SETTINGS("Editor/Color/HashQuotedString", QColor);
    case OddData:
        return GET_SETTINGS("Editor/Color/CommentDoc", QColor);
    case EvenData:
        return GET_SETTINGS("Editor/Color/CommentDocKeyword", QColor);
    case UnknownData:
        return GET_SETTINGS("Editor/Color/Error", QColor);
    case Checksum:
        return GET_SETTINGS("Editor/Color/UUID", QColor);
    case IncorrectChecksum:
        return GET_SETTINGS("Editor/Color/Warning", QColor);
    case TrailingGarbage:
        return GET_SETTINGS("Editor/Color/Comment", QColor);
    }

    return TpGeneralLexer::defaultColor(style);
}

bool TpFamilyHexLexer::defaultEolFill(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Fill/Universal", bool);
    case RecordStart:
        return GET_SETTINGS("Editor/Fill/Keyword", bool);
    case RecordType:
        return GET_SETTINGS("Editor/Fill/Type", bool);
    case UnknownRecordType:
        return GET_SETTINGS("Editor/Fill/Error", bool);
    case ByteCount:
        return GET_SETTINGS("Editor/Fill/Number", bool);
    case IncorrectByteCount:
        return GET_SETTINGS("Editor/Fill/Warning", bool);
    case NoAddress:
        return GET_SETTINGS("Editor/Fill/WeakWarning", bool);
    case DataAddress:
        return GET_SETTINGS("Editor/Fill/DoubleQuotedString", bool);
    case RecordCount:
        return GET_SETTINGS("Editor/Fill/SingleQuotedString", bool);
    case StartAddress:
        return GET_SETTINGS("Editor/Fill/RawString", bool);
    case ExtendedAddress:
        return GET_SETTINGS("Editor/Fill/HashQuotedString", bool);
    case OddData:
        return GET_SETTINGS("Editor/Fill/CommentDoc", bool);
    case EvenData:
        return GET_SETTINGS("Editor/Fill/CommentDocKeyword", bool);
    case UnknownData:
        return GET_SETTINGS("Editor/Fill/Error", bool);
    case Checksum:
        return GET_SETTINGS("Editor/Fill/UUID", bool);
    case IncorrectChecksum:
        return GET_SETTINGS("Editor/Fill/Warning", bool);
    case TrailingGarbage:
        return GET_SETTINGS("Editor/Fill/Comment", bool);
    }

    return TpGeneralLexer::defaultEolFill(style);
}

QFont TpFamilyHexLexer::defaultFont(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/Font/Universal", QFont);
    case RecordStart:
        return GET_SETTINGS("Editor/Font/Keyword", QFont);
    case RecordType:
        return GET_SETTINGS("Editor/Font/Type", QFont);
    case UnknownRecordType:
        return GET_SETTINGS("Editor/Font/Error", QFont);
    case ByteCount:
        return GET_SETTINGS("Editor/Font/Number", QFont);
    case IncorrectByteCount:
        return GET_SETTINGS("Editor/Font/Warning", QFont);
    case NoAddress:
        return GET_SETTINGS("Editor/Font/WeakWarning", QFont);
    case DataAddress:
        return GET_SETTINGS("Editor/Font/DoubleQuotedString", QFont);
    case RecordCount:
        return GET_SETTINGS("Editor/Font/SingleQuotedString", QFont);
    case StartAddress:
        return GET_SETTINGS("Editor/Font/RawString", QFont);
    case ExtendedAddress:
        return GET_SETTINGS("Editor/Font/HashQuotedString", QFont);
    case OddData:
        return GET_SETTINGS("Editor/Font/CommentDoc", QFont);
    case EvenData:
        return GET_SETTINGS("Editor/Font/CommentDocKeyword", QFont);
    case UnknownData:
        return GET_SETTINGS("Editor/Font/Error", QFont);
    case Checksum:
        return GET_SETTINGS("Editor/Font/UUID", QFont);
    case IncorrectChecksum:
        return GET_SETTINGS("Editor/Font/Warning", QFont);
    case TrailingGarbage:
        return GET_SETTINGS("Editor/Font/Comment", QFont);
    }

    return TpGeneralLexer::defaultFont(style);
}

QColor TpFamilyHexLexer::defaultPaper(int style) const
{
    DEF_SETTINGS;

    switch (style)
    {
    default:
        return GET_SETTINGS("Editor/BgColor/Universal", QColor);
    case RecordStart:
        return GET_SETTINGS("Editor/BgColor/Keyword", QColor);
    case RecordType:
        return GET_SETTINGS("Editor/BgColor/Type", QColor);
    case UnknownRecordType:
        return GET_SETTINGS("Editor/BgColor/Error", QColor);
    case ByteCount:
        return GET_SETTINGS("Editor/BgColor/Number", QColor);
    case IncorrectByteCount:
        return GET_SETTINGS("Editor/BgColor/Warning", QColor);
    case NoAddress:
        return GET_SETTINGS("Editor/BgColor/WeakWarning", QColor);
    case DataAddress:
        return GET_SETTINGS("Editor/BgColor/DoubleQuotedString", QColor);
    case RecordCount:
        return GET_SETTINGS("Editor/BgColor/SingleQuotedString", QColor);
    case StartAddress:
        return GET_SETTINGS("Editor/BgColor/RawString", QColor);
    case ExtendedAddress:
        return GET_SETTINGS("Editor/BgColor/HashQuotedString", QColor);
    case OddData:
        return GET_SETTINGS("Editor/BgColor/CommentDoc", QColor);
    case EvenData:
        return GET_SETTINGS("Editor/BgColor/CommentDocKeyword", QColor);
    case UnknownData:
        return GET_SETTINGS("Editor/BgColor/Error", QColor);
    case Checksum:
        return GET_SETTINGS("Editor/BgColor/UUID", QColor);
    case IncorrectChecksum:
        return GET_SETTINGS("Editor/BgColor/Warning", QColor);
    case TrailingGarbage:
        return GET_SETTINGS("Editor/BgColor/Comment", QColor);
    }

    return TpGeneralLexer::defaultPaper(style);
}

QString TpFamilyHexLexer::description(int style) const
{
    switch (style)
    {
    case Default:
        return tr("Default");
    case RecordStart:
        return tr("Record start");
    case RecordType:
        return tr("Record type");
    case UnknownRecordType:
        return tr("Unknown record type");
    case ByteCount:
        return tr("Byte count");
    case IncorrectByteCount:
        return tr("Incorrect byte count");
    case NoAddress:
        return tr("No address");
    case DataAddress:
        return tr("Data address");
    case RecordCount:
        return tr("Record count");
    case StartAddress:
        return tr("Start address");
    case ExtendedAddress:
        return tr("Extended address");
    case OddData:
        return tr("Odd data");
    case EvenData:
        return tr("Even data");
    case UnknownData:
        return tr("Unknown data");
    case Checksum:
        return tr("Checksum");
    case IncorrectChecksum:
        return tr("Incorrect checksum");
    case TrailingGarbage:
        return tr("Trailing garbage after a record");
   }

    return QString();
}

TP_END_NAMESPACE
