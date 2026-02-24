#ifndef TPFAMILYHEXLEXER_H
#define TPFAMILYHEXLEXER_H

#include <Lexers/TpGeneralLexer>

TP_NAMESPACE

class TpFamilyHexLexer : public TpGeneralLexer
{
    Q_OBJECT

public:
    enum
    {
        Default = 0,
        RecordStart = 1,
        RecordType = 2,
        UnknownRecordType = 3,
        ByteCount = 4,
        IncorrectByteCount = 5,
        NoAddress = 6,
        DataAddress = 7,
        RecordCount = 8,
        StartAddress = 9,
        ExtendedAddress = 11,
        OddData = 12,
        EvenData = 13,
        UnknownData = 14,
        Checksum = 16,
        IncorrectChecksum = 17,
        TrailingGarbage = 18,
    };

public:
    TpFamilyHexLexer(QObject *parent = nullptr);
    virtual ~TpFamilyHexLexer();

public:
    const char *language() const override;
    const char *lexer() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    QString description(int style) const override;
};

TP_END_NAMESPACE

#endif // TPFAMILYHEXLEXER_H
