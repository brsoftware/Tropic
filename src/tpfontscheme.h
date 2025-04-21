#ifndef TPFONTSCHEME_H
#define TPFONTSCHEME_H

#include <TpGlobals>

TP_NAMESPACE

typedef struct TpFontScheme
{
    TpFontScheme()
    {
        QFont font;
        font.setFamily("Consolas");
        font.setPointSize(12);
        font.setStyleHint(QFont::StyleHint::Monospace);

        // font400 == font

        QFont font500 = font;
        font500.setWeight(QFont::Weight::Medium);

        QFont font600 = font;
        font600.setWeight(QFont::Weight::DemiBold);

        QFont fontBold = font;
        fontBold.setWeight(QFont::Weight::Bold);

        QFont font800 = font;
        font800.setWeight(QFont::Weight::ExtraBold);

        QFont font900 = font;
        font900.setWeight(QFont::Weight::Black);

        QFont fontItalic = font;
        fontItalic.setItalic(true);

        QFont fontStroke = font;
        fontStroke.setStrikeOut(true);

        Default = font;
        Comment = fontItalic;
        CommentLine = fontItalic;
        CommentDoc = fontItalic;
        Number = font;
        Keyword = fontItalic;
        DoubleQuotedString = font;
        SingleQuotedString = font;
        UUID = font;
        PreProcessor = font;
        Operator = font;
        Identifier = font;
        UnclosedString = font;
        VerbatimString = font;
        Regex = font;
        CommentLineDoc = font;
        KeywordSet2 = font;
        CommentDocKeyword = font;
        CommentDocKeywordError = font;
        GlobalClass = font;
        RawString = font;
        TripleQuotedVerbatimString = font;
        HashQuotedString = font;
        PreProcessorComment = font;
        PreProcessorCommentLineDoc = font;
        UserLiteral = font;
        TaskMarker = font;
        EscapeSequence = font;
        InactiveDefault = font;
        InactiveComment = font;
        InactiveCommentLine = font;
        InactiveCommentDoc = font;
        InactiveNumber = font;
        InactiveKeyword = font;
        InactiveDoubleQuotedString = font;
        InactiveSingleQuotedString = font;
        InactiveUUID = font;
        InactivePreProcessor = font;
        InactiveOperator = font;
        InactiveIdentifier = font;
        InactiveUnclosedString = font;
        InactiveVerbatimString = font;
        InactiveRegex = font;
        InactiveCommentLineDoc = font;
        InactiveKeywordSet2 = font;
        InactiveCommentDocKeyword = font;
        InactiveCommentDocKeywordError = font;
        InactiveGlobalClass = font;
        InactiveRawString = font;
        InactiveTripleQuotedVerbatimString = font;
        InactiveHashQuotedString = font;
        InactivePreProcessorComment = font;
        InactivePreProcessorCommentLineDoc = font;
        InactiveUserLiteral = font;
        InactiveTaskMarker = font;
        InactiveEscapeSequence = font;
        Error = font;
        Type = font;
        PrimitiveType = font;
        Warning = font;
        WeakWarning = font;

        StrongEmphasis = fontBold;
        Emphasis = fontItalic;
        Header1 = font900;
        Header2 = font800;
        Header3 = fontBold;
        Header4 = font600;
        Header5 = font500;
        Header6 = font;
        StrikeOut = fontStroke;
    }

    QFont Default;
    QFont Comment;
    QFont CommentLine;
    QFont CommentDoc;
    QFont Number;
    QFont Keyword;
    QFont DoubleQuotedString;
    QFont SingleQuotedString;
    QFont UUID;
    QFont PreProcessor;
    QFont Operator;
    QFont Identifier;
    QFont UnclosedString;
    QFont VerbatimString;
    QFont Regex;
    QFont CommentLineDoc;
    QFont KeywordSet2;
    QFont CommentDocKeyword;
    QFont CommentDocKeywordError;
    QFont GlobalClass;
    QFont RawString;
    QFont TripleQuotedVerbatimString;
    QFont HashQuotedString;
    QFont PreProcessorComment;
    QFont PreProcessorCommentLineDoc;
    QFont UserLiteral;
    QFont TaskMarker;
    QFont EscapeSequence;
    QFont InactiveDefault;
    QFont InactiveComment;
    QFont InactiveCommentLine;
    QFont InactiveCommentDoc;
    QFont InactiveNumber;
    QFont InactiveKeyword;
    QFont InactiveDoubleQuotedString;
    QFont InactiveSingleQuotedString;
    QFont InactiveUUID;
    QFont InactivePreProcessor;
    QFont InactiveOperator;
    QFont InactiveIdentifier;
    QFont InactiveUnclosedString;
    QFont InactiveVerbatimString;
    QFont InactiveRegex;
    QFont InactiveCommentLineDoc;
    QFont InactiveKeywordSet2;
    QFont InactiveCommentDocKeyword;
    QFont InactiveCommentDocKeywordError;
    QFont InactiveGlobalClass;
    QFont InactiveRawString;
    QFont InactiveTripleQuotedVerbatimString;
    QFont InactiveHashQuotedString;
    QFont InactivePreProcessorComment;
    QFont InactivePreProcessorCommentLineDoc;
    QFont InactiveUserLiteral;
    QFont InactiveTaskMarker;
    QFont InactiveEscapeSequence;
    QFont Error;
    QFont Type;
    QFont PrimitiveType;
    QFont Warning;
    QFont WeakWarning;

    // Markdown only.
    QFont StrongEmphasis;
    QFont Emphasis;
    QFont Header1;
    QFont Header2;
    QFont Header3;
    QFont Header4;
    QFont Header5;
    QFont Header6;
    QFont StrikeOut;
} TpFontScheme;

inline TpFontScheme *defaultFontScheme = new TpFontScheme();

TP_END_NAMESPACE

#endif // TPFONTSCHEME_H
