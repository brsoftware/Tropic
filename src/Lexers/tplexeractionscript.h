#ifndef TPLEXERACTIONSCRIPT_H
#define TPLEXERACTIONSCRIPT_H

#include <Lexers/TpFamilyCLexer>

TP_NAMESPACE

inline const char *lexerActionScriptKeyword1 =
"add and break continue delete do else eq for function ge gt if ifFrameLoaded in le lt ne new not on onClipEvent or "
"return tellTarget this typeof var void while with abstract boolean byte case catch char class const debugger default "
"double enum export extends final finally float goto implements import instanceof int interface native package private "
"protected public short static super switch synchronized throws transient try volatile";

inline const char *lexerActionScriptKeyword5 =
"Object AbstractMessage AbstractTarget Accessibility AccessibilityProperties ActionScriptVersion AddChild "
"AdvancedDataGridBaseSelectionData AdvancedDataGridEventReason AdvancedDataGridHeaderInfo "
"AdvancedDataGridRendererDescription AdvancedDataGridRendererProvider AntiAliasType ApplicationDomain arguments Array "
"ArrayUtil AsyncResponder Automation AutomationID AutomationIDPart AverageAggregator AxisLabel AxisLabelSet Back "
"Base64Decoder Base64Encoder BaseListData BindingUtils BitmapData BitmapDataChannel BitmapFill BitmapFilter "
"BitmapFilterQuality BitmapFilterType BlendMode Boolean Bounce BoundedValue BoxDirection BrowserManager "
"ButtonLabelPlacement ByteArray Capabilities CapsStyle CartesianCanvasValue ChangeWatcher ChartState Circular Class "
"ClassFactory Clipboard ClipboardFormats ClipboardTransferMode CollectionEventKind ColorTransform ColorUtil "
"ComponentDescriptor CompressionAlgorithm Concurrency ContainerCreationPolicy ContainerLayout ContextMenuBuiltInItems "
"CountAggregator CreditCardValidatorCardType CSMSettings Cubic CuePointManager CurrencyValidatorAlignSymbol "
"CursorBookmark CursorManager CursorManagerPriority DataDescription DataGridEventReason Date DateBase "
"DateChooserEventDetail DateRangeUtilities DefaultDataDescriptor DeferredInstanceFromClass "
"DeferredInstanceFromFunction DescribeTypeCache Dictionary DisplacementMapFilterMode DragManager DragSource "
"EdgeMetrics EffectTargetFilter Elastic EncryptedLocalStore Endian Error Event EventDispatcher EventPhase "
"EventPriority Exponential ExternalInterface FileFilter FileMode FileSystemEnumerationMode FileSystemSizeDisplayMode "
"FlexPrintJob FlexPrintJobScaleType FlexVersion FocusDirection FocusManager Font FontStyle FontType Formatter "
"FormItemDirection FrameLabel Function GradientType Graphics GraphicsUtil GridFitType Grouping GroupingField "
"HaloColors HaloDefaults HistoryManager HitData HTMLHistoryItem HTMLHost HTMLPDFCapability HTMLWindowCreateOptions "
"ID3Info ImageSnapshot IMEConversionMode InstanceCache int InterpolationMethod ItemResponder JointStyle JPEGEncoder "
"Keyboard KeyLocation LegendData Linear LineScaleMode LineSeriesSegment ListBaseSeekPending ListBaseSelectionData "
"ListEventReason ListRowInfo LoaderConfig LoaderContext LoaderUtil Locale Log LogEventLevel Math Matrix MaxAggregator "
"MessagePerformanceUtils MinAggregator ModuleManager Mouse Namespace NameUtil NativeDragActions NativeDragManager "
"NativeDragOptions NativeWindowDisplayState NativeWindowInitOptions NativeWindowResize NativeWindowSystemChrome "
"NativeWindowType NotificationType Number NumberBase NumberBaseRoundType ObjectEncoding ObjectUtil OLAPAxisPosition "
"OLAPCell OLAPDataGridRendererProvider OLAPQuery OLAPQueryAxis OLAPResult OLAPResultAxis OLAPSchema OLAPSet OLAPTrace "
"OLAPTuple PixelSnapping PNGEncoder Point PopUpManager PopUpManagerChildList PrintJobOptions PrintJobOrientation "
"ProgressBarDirection ProgressBarLabelPlacement ProgressBarMode PropertyChangeEventKind PropertyChanges Proxy QName "
"Quadratic QualifiedResourceManager Quartic Quintic Rectangle RectangularDropShadow RegExp RemoveChild RenderData "
"ResourceBundle ResourceManager Responder Responder RevocationCheckSettings Sample Scene SchemaTypeRegistry "
"ScrollBarDirection ScrollEventDetail ScrollEventDirection ScrollPolicy Security SecurityDomain SecurityPanel "
"ServerConfig SetProperty SetStyle SHA256 SharedObjectFlushStatus SignatureStatus SignerTrustSettings SimpleXMLDecoder "
"SimpleXMLEncoder Sine SliderDirection SliderEventClickTarget SOAPHeader SortInfo SoundLoaderContext SoundMixer "
"SoundTransform SpreadMethod SQLCollationType SQLColumnNameStyle SQLColumnSchema SQLErrorOperation SQLMode SQLResult "
"SQLSchema SQLSchemaResult SQLTransactionLockType StackFrame StageAlign StageDisplayState StageQuality StageScaleMode "
"String StringUtil StyleManager StyleProxy SubscriptionInfo SumAggregator SummaryField SummaryObject SummaryRow "
"SWFVersion SwitchSymbolFormatter System TextColorType TextDisplayMode TextFieldAutomationHelper TextFieldAutoSize "
"TextFieldType TextFormat TextFormatAlign TextLineMetrics TextRange TextRenderer TextSnapshot TileBaseDirection "
"TileDirection Transform Transition UIComponentCachePolicy UIDUtil uint UITextFieldAutomationImpl Updater "
"URLLoaderDataFormat URLRequest URLRequestDefaults URLRequestHeader URLRequestMethod URLUtil URLVariables "
"ValidationResult WSDLBinding XML XMLList XMLNode XMLNodeType XMLUtil ZipCodeValidatorDomainType";

class TpLexerActionScript : public TpFamilyCLexer
{
    Q_OBJECT

public:
    TpLexerActionScript(QObject *parent = nullptr);

public:
    const char *language() const override;
    QStringList autoCompletionWordSeparators() const override;

    QColor defaultColor(int style) const override;
    bool defaultEolFill(int style) const override;
    QFont defaultFont(int style) const override;
    QColor defaultPaper(int style) const override;

    const char *keywords(int set) const override;
};

TP_END_NAMESPACE

#endif // TPLEXERACTIONSCRIPT_H
