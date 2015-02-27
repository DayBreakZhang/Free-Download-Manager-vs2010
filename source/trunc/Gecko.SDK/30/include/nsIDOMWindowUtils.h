/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMWindowUtils.idl
 */

#ifndef __gen_nsIDOMWindowUtils_h__
#define __gen_nsIDOMWindowUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsColor.h"
class gfxContext;
class nsRect;
typedef uint64_t  nsViewID;

class nsICycleCollectorListener; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMNodeList; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMHTMLCanvasElement; /* forward declaration */

class nsIDOMEvent; /* forward declaration */

class nsITransferable; /* forward declaration */

class nsIQueryContentEventResult; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIDOMBlob; /* forward declaration */

class nsIDOMFile; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIDOMTouch; /* forward declaration */

class nsIDOMClientRect; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMEventTarget; /* forward declaration */

class nsIRunnable; /* forward declaration */

class nsICompositionStringSynthesizer; /* forward declaration */


/* starting interface:    nsIDOMWindowUtils */
#define NS_IDOMWINDOWUTILS_IID_STR "f3148b3e-6db8-4a49-aa5c-de726449054d"

#define NS_IDOMWINDOWUTILS_IID \
  {0xf3148b3e, 0x6db8, 0x4a49, \
    { 0xaa, 0x5c, 0xde, 0x72, 0x64, 0x49, 0x05, 0x4d }}

class NS_NO_VTABLE nsIDOMWindowUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOWUTILS_IID)

  /* attribute unsigned short imageAnimationMode; */
  NS_IMETHOD GetImageAnimationMode(uint16_t *aImageAnimationMode) = 0;
  NS_IMETHOD SetImageAnimationMode(uint16_t aImageAnimationMode) = 0;

  /* readonly attribute boolean docCharsetIsForced; */
  NS_IMETHOD GetDocCharsetIsForced(bool *aDocCharsetIsForced) = 0;

  /* short getCursorType (); */
  NS_IMETHOD GetCursorType(int16_t *_retval) = 0;

  /* AString getDocumentMetadata (in AString aName); */
  NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval) = 0;

  /* unsigned long redraw ([optional] in unsigned long aCount); */
  NS_IMETHOD Redraw(uint32_t aCount, uint32_t *_retval) = 0;

  /* void setCSSViewport (in float aWidthPx, in float aHeightPx); */
  NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx) = 0;

  /* void getViewportInfo (in uint32_t aDisplayWidth, in uint32_t aDisplayHeight, out double aDefaultZoom, out boolean aAllowZoom, out double aMinZoom, out double aMaxZoom, out uint32_t aWidth, out uint32_t aHeight, out boolean aAutoSize); */
  NS_IMETHOD GetViewportInfo(uint32_t aDisplayWidth, uint32_t aDisplayHeight, double *aDefaultZoom, bool *aAllowZoom, double *aMinZoom, double *aMaxZoom, uint32_t *aWidth, uint32_t *aHeight, bool *aAutoSize) = 0;

  /* void setDisplayPortForElement (in float aXPx, in float aYPx, in float aWidthPx, in float aHeightPx, in nsIDOMElement aElement, in uint32_t aPriority); */
  NS_IMETHOD SetDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement, uint32_t aPriority) = 0;

  /* void setDisplayPortMarginsForElement (in float aLeftMargin, in float aTopMargin, in float aRightMargin, in float aBottomMargin, in uint32_t aAlignment, in nsIDOMElement aElement, in uint32_t aPriority); */
  NS_IMETHOD SetDisplayPortMarginsForElement(float aLeftMargin, float aTopMargin, float aRightMargin, float aBottomMargin, uint32_t aAlignment, nsIDOMElement *aElement, uint32_t aPriority) = 0;

  /* void setDisplayPortBaseForElement (in int32_t aX, in int32_t aY, in int32_t aWidth, in int32_t aHeight, in nsIDOMElement aElement); */
  NS_IMETHOD SetDisplayPortBaseForElement(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, nsIDOMElement *aElement) = 0;

  /* void setCriticalDisplayPortForElement (in float aXPx, in float aYPx, in float aWidthPx, in float aHeightPx, in nsIDOMElement aElement); */
  NS_IMETHOD SetCriticalDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement) = 0;

  /* void setResolution (in float aXResolution, in float aYResolution); */
  NS_IMETHOD SetResolution(float aXResolution, float aYResolution) = 0;

  /* void getResolution (out float aXResolution, out float aYResolution); */
  NS_IMETHOD GetResolution(float *aXResolution, float *aYResolution) = 0;

  /* attribute boolean isFirstPaint; */
  NS_IMETHOD GetIsFirstPaint(bool *aIsFirstPaint) = 0;
  NS_IMETHOD SetIsFirstPaint(bool aIsFirstPaint) = 0;

  /* void getPresShellId (out uint32_t aPresShellId); */
  NS_IMETHOD GetPresShellId(uint32_t *aPresShellId) = 0;

  enum {
    MODIFIER_ALT = 1,
    MODIFIER_CONTROL = 2,
    MODIFIER_SHIFT = 4,
    MODIFIER_META = 8,
    MODIFIER_ALTGRAPH = 16,
    MODIFIER_CAPSLOCK = 32,
    MODIFIER_FN = 64,
    MODIFIER_NUMLOCK = 128,
    MODIFIER_SCROLLLOCK = 256,
    MODIFIER_SYMBOLLOCK = 512,
    MODIFIER_OS = 1024
  };

  /* [optional_argc] boolean sendMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in boolean aIsSynthesized); */
  NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc, bool *_retval) = 0;

  /* [optional_argc] boolean sendPointerEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in long aPointerId, [optional] in long aWidth, [optional] in long aHeight, [optional] in long tiltX, [optional] in long tiltY, [optional] in boolean aIsPrimary, [optional] in boolean aIsSynthesized); */
  NS_IMETHOD SendPointerEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t tiltX, int32_t tiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc, bool *_retval) = 0;

  /* boolean sendTouchEvent (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
  NS_IMETHOD SendTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) = 0;

  /* [optional_argc] void sendMouseEventToWindow (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in boolean aIsSynthesized); */
  NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc) = 0;

  /* boolean sendTouchEventToWindow (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
  NS_IMETHOD SendTouchEventToWindow(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) = 0;

  enum {
    WHEEL_EVENT_CAUSED_BY_PIXEL_ONLY_DEVICE = 1U,
    WHEEL_EVENT_CAUSED_BY_MOMENTUM = 2U,
    WHEEL_EVENT_CUSTOMIZED_BY_USER_PREFS = 4U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_X_ZERO = 16U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_X_POSITIVE = 32U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_X_NEGATIVE = 64U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_Y_ZERO = 256U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_Y_POSITIVE = 512U,
    WHEEL_EVENT_EXPECTED_OVERFLOW_DELTA_Y_NEGATIVE = 1024U
  };

  /* void sendWheelEvent (in float aX, in float aY, in double aDeltaX, in double aDeltaY, in double aDeltaZ, in unsigned long aDeltaMode, in long aModifiers, in long aLineOrPageDeltaX, in long aLineOrPageDeltaY, in unsigned long aOptions); */
  NS_IMETHOD SendWheelEvent(float aX, float aY, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aDeltaMode, int32_t aModifiers, int32_t aLineOrPageDeltaX, int32_t aLineOrPageDeltaY, uint32_t aOptions) = 0;

  enum {
    KEY_FLAG_PREVENT_DEFAULT = 1U,
    KEY_FLAG_LOCATION_STANDARD = 16U,
    KEY_FLAG_LOCATION_LEFT = 32U,
    KEY_FLAG_LOCATION_RIGHT = 64U,
    KEY_FLAG_LOCATION_NUMPAD = 128U,
    KEY_FLAG_LOCATION_MOBILE = 256U,
    KEY_FLAG_LOCATION_JOYSTICK = 512U
  };

  /* boolean sendKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in unsigned long aAdditionalFlags); */
  NS_IMETHOD SendKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, uint32_t aAdditionalFlags, bool *_retval) = 0;

  /* void sendNativeKeyEvent (in long aNativeKeyboardLayout, in long aNativeKeyCode, in long aModifierFlags, in AString aCharacters, in AString aUnmodifiedCharacters); */
  NS_IMETHOD SendNativeKeyEvent(int32_t aNativeKeyboardLayout, int32_t aNativeKeyCode, int32_t aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters) = 0;

  /* void sendNativeMouseEvent (in long aScreenX, in long aScreenY, in long aNativeMessage, in long aModifierFlags, in nsIDOMElement aElement); */
  NS_IMETHOD SendNativeMouseEvent(int32_t aScreenX, int32_t aScreenY, int32_t aNativeMessage, int32_t aModifierFlags, nsIDOMElement *aElement) = 0;

  enum {
    MOUSESCROLL_PREFER_WIDGET_AT_POINT = 1U,
    MOUSESCROLL_WIN_SCROLL_LPARAM_NOT_NULL = 65536U
  };

  /* void sendNativeMouseScrollEvent (in long aScreenX, in long aScreenY, in unsigned long aNativeMessage, in double aDeltaX, in double aDeltaY, in double aDeltaZ, in unsigned long aModifierFlags, in unsigned long aAdditionalFlags, in nsIDOMElement aElement); */
  NS_IMETHOD SendNativeMouseScrollEvent(int32_t aScreenX, int32_t aScreenY, uint32_t aNativeMessage, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aModifierFlags, uint32_t aAdditionalFlags, nsIDOMElement *aElement) = 0;

  enum {
    TOUCH_HOVER = 1,
    TOUCH_CONTACT = 2,
    TOUCH_REMOVE = 4,
    TOUCH_CANCEL = 8
  };

  /* void sendNativeTouchPoint (in unsigned long aPointerId, in unsigned long aTouchState, in long aScreenX, in long aScreenY, in double aPressure, in unsigned long aOrientation); */
  NS_IMETHOD SendNativeTouchPoint(uint32_t aPointerId, uint32_t aTouchState, int32_t aScreenX, int32_t aScreenY, double aPressure, uint32_t aOrientation) = 0;

  /* void sendNativeTouchTap (in long aScreenX, in long aScreenY, in boolean aLongTap); */
  NS_IMETHOD SendNativeTouchTap(int32_t aScreenX, int32_t aScreenY, bool aLongTap) = 0;

  /* void clearNativeTouchSequence (); */
  NS_IMETHOD ClearNativeTouchSequence(void) = 0;

  /* void activateNativeMenuItemAt (in AString indexString); */
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) = 0;

  /* void forceUpdateNativeMenuAt (in AString indexString); */
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) = 0;

  /* void focus (in nsIDOMElement aElement); */
  NS_IMETHOD Focus(nsIDOMElement *aElement) = 0;

  /* void garbageCollect ([optional] in nsICycleCollectorListener aListener, [optional] in long aExtraForgetSkippableCalls); */
  NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) = 0;

  /* void cycleCollect ([optional] in nsICycleCollectorListener aListener, [optional] in long aExtraForgetSkippableCalls); */
  NS_IMETHOD CycleCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) = 0;

  /* void sendSimpleGestureEvent (in AString aType, in float aX, in float aY, in unsigned long aDirection, in double aDelta, in long aModifiers, [optional] in unsigned long aClickCount); */
  NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, uint32_t aDirection, double aDelta, int32_t aModifiers, uint32_t aClickCount) = 0;

  /* nsIDOMElement elementFromPoint (in float aX, in float aY, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
  NS_IMETHOD ElementFromPoint(float aX, float aY, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMElement * *_retval) = 0;

  /* nsIDOMNodeList nodesFromRect (in float aX, in float aY, in float aTopSize, in float aRightSize, in float aBottomSize, in float aLeftSize, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
  NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMNodeList * *_retval) = 0;

  /* uint32_t compareCanvases (in nsIDOMHTMLCanvasElement aCanvas1, in nsIDOMHTMLCanvasElement aCanvas2, out unsigned long aMaxDifference); */
  NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, uint32_t *aMaxDifference, uint32_t *_retval) = 0;

  /* readonly attribute boolean isMozAfterPaintPending; */
  NS_IMETHOD GetIsMozAfterPaintPending(bool *aIsMozAfterPaintPending) = 0;

  /* void suppressEventHandling (in boolean aSuppress); */
  NS_IMETHOD SuppressEventHandling(bool aSuppress) = 0;

  /* void clearMozAfterPaintEvents (); */
  NS_IMETHOD ClearMozAfterPaintEvents(void) = 0;

  /* void disableNonTestMouseEvents (in boolean aDisable); */
  NS_IMETHOD DisableNonTestMouseEvents(bool aDisable) = 0;

  /* void getScrollXY (in boolean aFlushLayout, out long aScrollX, out long aScrollY); */
  NS_IMETHOD GetScrollXY(bool aFlushLayout, int32_t *aScrollX, int32_t *aScrollY) = 0;

  /* void getScrollXYFloat (in boolean aFlushLayout, out float aScrollX, out float aScrollY); */
  NS_IMETHOD GetScrollXYFloat(bool aFlushLayout, float *aScrollX, float *aScrollY) = 0;

  /* void getScrollbarSize (in boolean aFlushLayout, out long aWidth, out long aHeight); */
  NS_IMETHOD GetScrollbarSize(bool aFlushLayout, int32_t *aWidth, int32_t *aHeight) = 0;

  /* nsIDOMClientRect getBoundsWithoutFlushing (in nsIDOMElement aElement); */
  NS_IMETHOD GetBoundsWithoutFlushing(nsIDOMElement *aElement, nsIDOMClientRect * *_retval) = 0;

  /* nsIDOMClientRect getRootBounds (); */
  NS_IMETHOD GetRootBounds(nsIDOMClientRect * *_retval) = 0;

  /* readonly attribute boolean IMEIsOpen; */
  NS_IMETHOD GetIMEIsOpen(bool *aIMEIsOpen) = 0;

  enum {
    IME_STATUS_DISABLED = 0U,
    IME_STATUS_ENABLED = 1U,
    IME_STATUS_PASSWORD = 2U,
    IME_STATUS_PLUGIN = 3U
  };

  /* readonly attribute unsigned long IMEStatus; */
  NS_IMETHOD GetIMEStatus(uint32_t *aIMEStatus) = 0;

  /* readonly attribute float screenPixelsPerCSSPixel; */
  NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel) = 0;

  /* readonly attribute float fullZoom; */
  NS_IMETHOD GetFullZoom(float *aFullZoom) = 0;

  /* boolean dispatchDOMEventViaPresShell (in nsIDOMNode aTarget, in nsIDOMEvent aEvent, in boolean aTrusted); */
  NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, bool aTrusted, bool *_retval) = 0;

  /* boolean dispatchEventToChromeOnly (in nsIDOMEventTarget aTarget, in nsIDOMEvent aEvent); */
  NS_IMETHOD DispatchEventToChromeOnly(nsIDOMEventTarget *aTarget, nsIDOMEvent *aEvent, bool *_retval) = 0;

  /* [implicit_jscontext] string getClassName (in jsval aObject); */
  NS_IMETHOD GetClassName(JS::HandleValue aObject, JSContext* cx, char * *_retval) = 0;

  /* void sendContentCommandEvent (in AString aType, [optional] in nsITransferable aTransferable); */
  NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable) = 0;

  /* void sendCompositionEvent (in AString aType, in AString aData, in AString aLocale); */
  NS_IMETHOD SendCompositionEvent(const nsAString & aType, const nsAString & aData, const nsAString & aLocale) = 0;

  /* nsICompositionStringSynthesizer createCompositionStringSynthesizer (); */
  NS_IMETHOD CreateCompositionStringSynthesizer(nsICompositionStringSynthesizer * *_retval) = 0;

  /* nsIQueryContentEventResult sendQueryContentEvent (in unsigned long aType, in unsigned long aOffset, in unsigned long aLength, in long aX, in long aY); */
  NS_IMETHOD SendQueryContentEvent(uint32_t aType, uint32_t aOffset, uint32_t aLength, int32_t aX, int32_t aY, nsIQueryContentEventResult * *_retval) = 0;

  enum {
    QUERY_SELECTED_TEXT = 3200U,
    QUERY_TEXT_CONTENT = 3201U,
    QUERY_CARET_RECT = 3203U,
    QUERY_TEXT_RECT = 3204U,
    QUERY_EDITOR_RECT = 3205U,
    QUERY_CHARACTER_AT_POINT = 3208U
  };

  /* void remoteFrameFullscreenChanged (in nsIDOMElement aFrameElement, in AString aNewOrigin); */
  NS_IMETHOD RemoteFrameFullscreenChanged(nsIDOMElement *aFrameElement, const nsAString & aNewOrigin) = 0;

  /* void remoteFrameFullscreenReverted (); */
  NS_IMETHOD RemoteFrameFullscreenReverted(void) = 0;

  /* void exitFullscreen (); */
  NS_IMETHOD ExitFullscreen(void) = 0;

  /* boolean sendSelectionSetEvent (in unsigned long aOffset, in unsigned long aLength, in boolean aReverse); */
  NS_IMETHOD SendSelectionSetEvent(uint32_t aOffset, uint32_t aLength, bool aReverse, bool *_retval) = 0;

  enum {
    SELECT_CHARACTER = 0U,
    SELECT_CLUSTER = 1U,
    SELECT_WORD = 2U,
    SELECT_LINE = 3U,
    SELECT_BEGINLINE = 4U,
    SELECT_ENDLINE = 5U,
    SELECT_PARAGRAPH = 6U,
    SELECT_WORDNOSPACE = 7U
  };

  /* boolean selectAtPoint (in float aX, in float aY, in unsigned long aSelectBehavior); */
  NS_IMETHOD SelectAtPoint(float aX, float aY, uint32_t aSelectBehavior, bool *_retval) = 0;

  /* AString getVisitedDependentComputedStyle (in nsIDOMElement aElement, in AString aPseudoElement, in AString aPropertyName); */
  NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval) = 0;

  /* [implicit_jscontext] jsval getParent (in jsval obj); */
  NS_IMETHOD GetParent(JS::HandleValue obj, JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* readonly attribute unsigned long long outerWindowID; */
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) = 0;

  /* readonly attribute unsigned long long currentInnerWindowID; */
  NS_IMETHOD GetCurrentInnerWindowID(uint64_t *aCurrentInnerWindowID) = 0;

  /* void enterModalState (); */
  NS_IMETHOD EnterModalState(void) = 0;

  /* void leaveModalState (); */
  NS_IMETHOD LeaveModalState(void) = 0;

  /* [noscript] boolean isInModalState (); */
  NS_IMETHOD IsInModalState(bool *_retval) = 0;

  /* void suspendTimeouts (); */
  NS_IMETHOD SuspendTimeouts(void) = 0;

  /* void resumeTimeouts (); */
  NS_IMETHOD ResumeTimeouts(void) = 0;

  /* readonly attribute AString layerManagerType; */
  NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType) = 0;

  /* readonly attribute boolean layerManagerRemote; */
  NS_IMETHOD GetLayerManagerRemote(bool *aLayerManagerRemote) = 0;

  /* void startFrameTimeRecording ([retval] out unsigned long startIndex); */
  NS_IMETHOD StartFrameTimeRecording(uint32_t *startIndex) = 0;

  /* void stopFrameTimeRecording (in unsigned long startIndex, [optional] out unsigned long frameCount, [array, size_is (frameCount), retval] out float frameIntervals); */
  NS_IMETHOD StopFrameTimeRecording(uint32_t startIndex, uint32_t *frameCount, float **frameIntervals) = 0;

  /* void beginTabSwitch (); */
  NS_IMETHOD BeginTabSwitch(void) = 0;

  /* readonly attribute float displayDPI; */
  NS_IMETHOD GetDisplayDPI(float *aDisplayDPI) = 0;

  /* nsIDOMWindow getOuterWindowWithId (in unsigned long long aOuterWindowID); */
  NS_IMETHOD GetOuterWindowWithId(uint64_t aOuterWindowID, nsIDOMWindow * *_retval) = 0;

  /* readonly attribute nsIDOMElement containerElement; */
  NS_IMETHOD GetContainerElement(nsIDOMElement * *aContainerElement) = 0;

  /* [noscript] void RenderDocument (in nsConstRect aRect, in uint32_t aFlags, in nscolor aBackgroundColor, in gfxContext aThebesContext); */
  NS_IMETHOD RenderDocument(const nsRect & aRect, uint32_t aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext) = 0;

  /* void advanceTimeAndRefresh (in long long aMilliseconds); */
  NS_IMETHOD AdvanceTimeAndRefresh(int64_t aMilliseconds) = 0;

  /* void restoreNormalRefresh (); */
  NS_IMETHOD RestoreNormalRefresh(void) = 0;

  /* readonly attribute bool isTestControllingRefreshes; */
  NS_IMETHOD GetIsTestControllingRefreshes(bool *aIsTestControllingRefreshes) = 0;

  /* void setAsyncScrollOffset (in nsIDOMNode aNode, in int32_t aX, in int32_t aY); */
  NS_IMETHOD SetAsyncScrollOffset(nsIDOMNode *aNode, int32_t aX, int32_t aY) = 0;

  /* double computeAnimationDistance (in nsIDOMElement element, in AString property, in AString value1, in AString value2); */
  NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval) = 0;

  /* nsIDOMFile wrapDOMFile (in nsIFile aFile); */
  NS_IMETHOD WrapDOMFile(nsIFile *aFile, nsIDOMFile * *_retval) = 0;

  /* readonly attribute string focusedInputType; */
  NS_IMETHOD GetFocusedInputType(char * *aFocusedInputType) = 0;

  /* nsIDOMElement findElementWithViewId (in nsViewID aId); */
  NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement * *_retval) = 0;

  /* nsViewID getViewId (in nsIDOMElement aElement); */
  NS_IMETHOD GetViewId(nsIDOMElement *aElement, nsViewID *_retval) = 0;

  /* boolean leafLayersPartitionWindow (); */
  NS_IMETHOD LeafLayersPartitionWindow(bool *_retval) = 0;

  /* readonly attribute boolean mayHaveTouchEventListeners; */
  NS_IMETHOD GetMayHaveTouchEventListeners(bool *aMayHaveTouchEventListeners) = 0;

  /* boolean checkAndClearPaintedState (in nsIDOMElement aElement); */
  NS_IMETHOD CheckAndClearPaintedState(nsIDOMElement *aElement, bool *_retval) = 0;

  /* [implicit_jscontext,optional_argc] nsIDOMFile getFile (in DOMString aName, [optional] in jsval aBlobParts, [optional] in jsval aParameters); */
  NS_IMETHOD GetFile(const nsAString & aName, JS::HandleValue aBlobParts, JS::HandleValue aParameters, JSContext* cx, uint8_t _argc, nsIDOMFile * *_retval) = 0;

  /* [implicit_jscontext,optional_argc] nsIDOMBlob getBlob ([optional] in jsval aBlobParts, [optional] in jsval aParameters); */
  NS_IMETHOD GetBlob(JS::HandleValue aBlobParts, JS::HandleValue aParameters, JSContext* cx, uint8_t _argc, nsIDOMBlob * *_retval) = 0;

  /* [implicit_jscontext] long long getFileId (in jsval aFile); */
  NS_IMETHOD GetFileId(JS::HandleValue aFile, JSContext* cx, int64_t *_retval) = 0;

  /* [implicit_jscontext] boolean getFileReferences (in AString aDatabaseName, in long long aId, [optional] in jsval aOptions, [optional] out long aRefCnt, [optional] out long aDBRefCnt, [optional] out long aSliceRefCnt); */
  NS_IMETHOD GetFileReferences(const nsAString & aDatabaseName, int64_t aId, JS::HandleValue aOptions, int32_t *aRefCnt, int32_t *aDBRefCnt, int32_t *aSliceRefCnt, JSContext* cx, bool *_retval) = 0;

  /* [implicit_jscontext] boolean isIncrementalGCEnabled (); */
  NS_IMETHOD IsIncrementalGCEnabled(JSContext* cx, bool *_retval) = 0;

  /* [implicit_jscontext] void startPCCountProfiling (); */
  NS_IMETHOD StartPCCountProfiling(JSContext* cx) = 0;

  /* [implicit_jscontext] void stopPCCountProfiling (); */
  NS_IMETHOD StopPCCountProfiling(JSContext* cx) = 0;

  /* [implicit_jscontext] void purgePCCounts (); */
  NS_IMETHOD PurgePCCounts(JSContext* cx) = 0;

  /* [implicit_jscontext] long getPCCountScriptCount (); */
  NS_IMETHOD GetPCCountScriptCount(JSContext* cx, int32_t *_retval) = 0;

  /* [implicit_jscontext] AString getPCCountScriptSummary (in long script); */
  NS_IMETHOD GetPCCountScriptSummary(int32_t script, JSContext* cx, nsAString & _retval) = 0;

  /* [implicit_jscontext] AString getPCCountScriptContents (in long script); */
  NS_IMETHOD GetPCCountScriptContents(int32_t script, JSContext* cx, nsAString & _retval) = 0;

  /* readonly attribute boolean paintingSuppressed; */
  NS_IMETHOD GetPaintingSuppressed(bool *aPaintingSuppressed) = 0;

  /* [implicit_jscontext] readonly attribute jsval plugins; */
  NS_IMETHOD GetPlugins(JSContext* cx, JS::MutableHandleValue aPlugins) = 0;

  /* void setScrollPositionClampingScrollPortSize (in float aWidth, in float aHeight); */
  NS_IMETHOD SetScrollPositionClampingScrollPortSize(float aWidth, float aHeight) = 0;

  /* void setContentDocumentFixedPositionMargins (in float aTop, in float aRight, in float aBottom, in float aLeft); */
  NS_IMETHOD SetContentDocumentFixedPositionMargins(float aTop, float aRight, float aBottom, float aLeft) = 0;

  /* void disableDialogs (); */
  NS_IMETHOD DisableDialogs(void) = 0;

  /* void enableDialogs (); */
  NS_IMETHOD EnableDialogs(void) = 0;

  /* bool areDialogsEnabled (); */
  NS_IMETHOD AreDialogsEnabled(bool *_retval) = 0;

  enum {
    AGENT_SHEET = 0U,
    USER_SHEET = 1U,
    AUTHOR_SHEET = 2U
  };

  /* void loadSheet (in nsIURI sheetURI, in unsigned long type); */
  NS_IMETHOD LoadSheet(nsIURI *sheetURI, uint32_t type) = 0;

  /* void removeSheet (in nsIURI sheetURI, in unsigned long type); */
  NS_IMETHOD RemoveSheet(nsIURI *sheetURI, uint32_t type) = 0;

  /* readonly attribute boolean isHandlingUserInput; */
  NS_IMETHOD GetIsHandlingUserInput(bool *aIsHandlingUserInput) = 0;

  /* void allowScriptsToClose (); */
  NS_IMETHOD AllowScriptsToClose(void) = 0;

  /* readonly attribute boolean isParentWindowMainWidgetVisible; */
  NS_IMETHOD GetIsParentWindowMainWidgetVisible(bool *aIsParentWindowMainWidgetVisible) = 0;

  /* boolean isNodeDisabledForEvents (in nsIDOMNode aNode); */
  NS_IMETHOD IsNodeDisabledForEvents(nsIDOMNode *aNode, bool *_retval) = 0;

  /* attribute boolean paintFlashing; */
  NS_IMETHOD GetPaintFlashing(bool *aPaintFlashing) = 0;
  NS_IMETHOD SetPaintFlashing(bool aPaintFlashing) = 0;

  /* void runInStableState (in nsIRunnable runnable); */
  NS_IMETHOD RunInStableState(nsIRunnable *runnable) = 0;

  /* void runBeforeNextEvent (in nsIRunnable runnable); */
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) = 0;

  /* AString getOMTAStyle (in nsIDOMElement aElement, in AString aProperty); */
  NS_IMETHOD GetOMTAStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval) = 0;

  /* AString getOMTAOrComputedStyle (in nsIDOMElement aElement, in AString aProperty); */
  NS_IMETHOD GetOMTAOrComputedStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval) = 0;

  /* attribute boolean audioMuted; */
  NS_IMETHOD GetAudioMuted(bool *aAudioMuted) = 0;
  NS_IMETHOD SetAudioMuted(bool aAudioMuted) = 0;

  /* attribute float audioVolume; */
  NS_IMETHOD GetAudioVolume(float *aAudioVolume) = 0;
  NS_IMETHOD SetAudioVolume(float aAudioVolume) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindowUtils, NS_IDOMWINDOWUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOWUTILS \
  NS_IMETHOD GetImageAnimationMode(uint16_t *aImageAnimationMode); \
  NS_IMETHOD SetImageAnimationMode(uint16_t aImageAnimationMode); \
  NS_IMETHOD GetDocCharsetIsForced(bool *aDocCharsetIsForced); \
  NS_IMETHOD GetCursorType(int16_t *_retval); \
  NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval); \
  NS_IMETHOD Redraw(uint32_t aCount, uint32_t *_retval); \
  NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx); \
  NS_IMETHOD GetViewportInfo(uint32_t aDisplayWidth, uint32_t aDisplayHeight, double *aDefaultZoom, bool *aAllowZoom, double *aMinZoom, double *aMaxZoom, uint32_t *aWidth, uint32_t *aHeight, bool *aAutoSize); \
  NS_IMETHOD SetDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement, uint32_t aPriority); \
  NS_IMETHOD SetDisplayPortMarginsForElement(float aLeftMargin, float aTopMargin, float aRightMargin, float aBottomMargin, uint32_t aAlignment, nsIDOMElement *aElement, uint32_t aPriority); \
  NS_IMETHOD SetDisplayPortBaseForElement(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, nsIDOMElement *aElement); \
  NS_IMETHOD SetCriticalDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement); \
  NS_IMETHOD SetResolution(float aXResolution, float aYResolution); \
  NS_IMETHOD GetResolution(float *aXResolution, float *aYResolution); \
  NS_IMETHOD GetIsFirstPaint(bool *aIsFirstPaint); \
  NS_IMETHOD SetIsFirstPaint(bool aIsFirstPaint); \
  NS_IMETHOD GetPresShellId(uint32_t *aPresShellId); \
  NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc, bool *_retval); \
  NS_IMETHOD SendPointerEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t tiltX, int32_t tiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc, bool *_retval); \
  NS_IMETHOD SendTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval); \
  NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc); \
  NS_IMETHOD SendTouchEventToWindow(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval); \
  NS_IMETHOD SendWheelEvent(float aX, float aY, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aDeltaMode, int32_t aModifiers, int32_t aLineOrPageDeltaX, int32_t aLineOrPageDeltaY, uint32_t aOptions); \
  NS_IMETHOD SendKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, uint32_t aAdditionalFlags, bool *_retval); \
  NS_IMETHOD SendNativeKeyEvent(int32_t aNativeKeyboardLayout, int32_t aNativeKeyCode, int32_t aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters); \
  NS_IMETHOD SendNativeMouseEvent(int32_t aScreenX, int32_t aScreenY, int32_t aNativeMessage, int32_t aModifierFlags, nsIDOMElement *aElement); \
  NS_IMETHOD SendNativeMouseScrollEvent(int32_t aScreenX, int32_t aScreenY, uint32_t aNativeMessage, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aModifierFlags, uint32_t aAdditionalFlags, nsIDOMElement *aElement); \
  NS_IMETHOD SendNativeTouchPoint(uint32_t aPointerId, uint32_t aTouchState, int32_t aScreenX, int32_t aScreenY, double aPressure, uint32_t aOrientation); \
  NS_IMETHOD SendNativeTouchTap(int32_t aScreenX, int32_t aScreenY, bool aLongTap); \
  NS_IMETHOD ClearNativeTouchSequence(void); \
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString); \
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString); \
  NS_IMETHOD Focus(nsIDOMElement *aElement); \
  NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls); \
  NS_IMETHOD CycleCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls); \
  NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, uint32_t aDirection, double aDelta, int32_t aModifiers, uint32_t aClickCount); \
  NS_IMETHOD ElementFromPoint(float aX, float aY, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMElement * *_retval); \
  NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMNodeList * *_retval); \
  NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, uint32_t *aMaxDifference, uint32_t *_retval); \
  NS_IMETHOD GetIsMozAfterPaintPending(bool *aIsMozAfterPaintPending); \
  NS_IMETHOD SuppressEventHandling(bool aSuppress); \
  NS_IMETHOD ClearMozAfterPaintEvents(void); \
  NS_IMETHOD DisableNonTestMouseEvents(bool aDisable); \
  NS_IMETHOD GetScrollXY(bool aFlushLayout, int32_t *aScrollX, int32_t *aScrollY); \
  NS_IMETHOD GetScrollXYFloat(bool aFlushLayout, float *aScrollX, float *aScrollY); \
  NS_IMETHOD GetScrollbarSize(bool aFlushLayout, int32_t *aWidth, int32_t *aHeight); \
  NS_IMETHOD GetBoundsWithoutFlushing(nsIDOMElement *aElement, nsIDOMClientRect * *_retval); \
  NS_IMETHOD GetRootBounds(nsIDOMClientRect * *_retval); \
  NS_IMETHOD GetIMEIsOpen(bool *aIMEIsOpen); \
  NS_IMETHOD GetIMEStatus(uint32_t *aIMEStatus); \
  NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel); \
  NS_IMETHOD GetFullZoom(float *aFullZoom); \
  NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, bool aTrusted, bool *_retval); \
  NS_IMETHOD DispatchEventToChromeOnly(nsIDOMEventTarget *aTarget, nsIDOMEvent *aEvent, bool *_retval); \
  NS_IMETHOD GetClassName(JS::HandleValue aObject, JSContext* cx, char * *_retval); \
  NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable); \
  NS_IMETHOD SendCompositionEvent(const nsAString & aType, const nsAString & aData, const nsAString & aLocale); \
  NS_IMETHOD CreateCompositionStringSynthesizer(nsICompositionStringSynthesizer * *_retval); \
  NS_IMETHOD SendQueryContentEvent(uint32_t aType, uint32_t aOffset, uint32_t aLength, int32_t aX, int32_t aY, nsIQueryContentEventResult * *_retval); \
  NS_IMETHOD RemoteFrameFullscreenChanged(nsIDOMElement *aFrameElement, const nsAString & aNewOrigin); \
  NS_IMETHOD RemoteFrameFullscreenReverted(void); \
  NS_IMETHOD ExitFullscreen(void); \
  NS_IMETHOD SendSelectionSetEvent(uint32_t aOffset, uint32_t aLength, bool aReverse, bool *_retval); \
  NS_IMETHOD SelectAtPoint(float aX, float aY, uint32_t aSelectBehavior, bool *_retval); \
  NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval); \
  NS_IMETHOD GetParent(JS::HandleValue obj, JSContext* cx, JS::MutableHandleValue _retval); \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID); \
  NS_IMETHOD GetCurrentInnerWindowID(uint64_t *aCurrentInnerWindowID); \
  NS_IMETHOD EnterModalState(void); \
  NS_IMETHOD LeaveModalState(void); \
  NS_IMETHOD IsInModalState(bool *_retval); \
  NS_IMETHOD SuspendTimeouts(void); \
  NS_IMETHOD ResumeTimeouts(void); \
  NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType); \
  NS_IMETHOD GetLayerManagerRemote(bool *aLayerManagerRemote); \
  NS_IMETHOD StartFrameTimeRecording(uint32_t *startIndex); \
  NS_IMETHOD StopFrameTimeRecording(uint32_t startIndex, uint32_t *frameCount, float **frameIntervals); \
  NS_IMETHOD BeginTabSwitch(void); \
  NS_IMETHOD GetDisplayDPI(float *aDisplayDPI); \
  NS_IMETHOD GetOuterWindowWithId(uint64_t aOuterWindowID, nsIDOMWindow * *_retval); \
  NS_IMETHOD GetContainerElement(nsIDOMElement * *aContainerElement); \
  NS_IMETHOD RenderDocument(const nsRect & aRect, uint32_t aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext); \
  NS_IMETHOD AdvanceTimeAndRefresh(int64_t aMilliseconds); \
  NS_IMETHOD RestoreNormalRefresh(void); \
  NS_IMETHOD GetIsTestControllingRefreshes(bool *aIsTestControllingRefreshes); \
  NS_IMETHOD SetAsyncScrollOffset(nsIDOMNode *aNode, int32_t aX, int32_t aY); \
  NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval); \
  NS_IMETHOD WrapDOMFile(nsIFile *aFile, nsIDOMFile * *_retval); \
  NS_IMETHOD GetFocusedInputType(char * *aFocusedInputType); \
  NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement * *_retval); \
  NS_IMETHOD GetViewId(nsIDOMElement *aElement, nsViewID *_retval); \
  NS_IMETHOD LeafLayersPartitionWindow(bool *_retval); \
  NS_IMETHOD GetMayHaveTouchEventListeners(bool *aMayHaveTouchEventListeners); \
  NS_IMETHOD CheckAndClearPaintedState(nsIDOMElement *aElement, bool *_retval); \
  NS_IMETHOD GetFile(const nsAString & aName, JS::HandleValue aBlobParts, JS::HandleValue aParameters, JSContext* cx, uint8_t _argc, nsIDOMFile * *_retval); \
  NS_IMETHOD GetBlob(JS::HandleValue aBlobParts, JS::HandleValue aParameters, JSContext* cx, uint8_t _argc, nsIDOMBlob * *_retval); \
  NS_IMETHOD GetFileId(JS::HandleValue aFile, JSContext* cx, int64_t *_retval); \
  NS_IMETHOD GetFileReferences(const nsAString & aDatabaseName, int64_t aId, JS::HandleValue aOptions, int32_t *aRefCnt, int32_t *aDBRefCnt, int32_t *aSliceRefCnt, JSContext* cx, bool *_retval); \
  NS_IMETHOD IsIncrementalGCEnabled(JSContext* cx, bool *_retval); \
  NS_IMETHOD StartPCCountProfiling(JSContext* cx); \
  NS_IMETHOD StopPCCountProfiling(JSContext* cx); \
  NS_IMETHOD PurgePCCounts(JSContext* cx); \
  NS_IMETHOD GetPCCountScriptCount(JSContext* cx, int32_t *_retval); \
  NS_IMETHOD GetPCCountScriptSummary(int32_t script, JSContext* cx, nsAString & _retval); \
  NS_IMETHOD GetPCCountScriptContents(int32_t script, JSContext* cx, nsAString & _retval); \
  NS_IMETHOD GetPaintingSuppressed(bool *aPaintingSuppressed); \
  NS_IMETHOD GetPlugins(JSContext* cx, JS::MutableHandleValue aPlugins); \
  NS_IMETHOD SetScrollPositionClampingScrollPortSize(float aWidth, float aHeight); \
  NS_IMETHOD SetContentDocumentFixedPositionMargins(float aTop, float aRight, float aBottom, float aLeft); \
  NS_IMETHOD DisableDialogs(void); \
  NS_IMETHOD EnableDialogs(void); \
  NS_IMETHOD AreDialogsEnabled(bool *_retval); \
  NS_IMETHOD LoadSheet(nsIURI *sheetURI, uint32_t type); \
  NS_IMETHOD RemoveSheet(nsIURI *sheetURI, uint32_t type); \
  NS_IMETHOD GetIsHandlingUserInput(bool *aIsHandlingUserInput); \
  NS_IMETHOD AllowScriptsToClose(void); \
  NS_IMETHOD GetIsParentWindowMainWidgetVisible(bool *aIsParentWindowMainWidgetVisible); \
  NS_IMETHOD IsNodeDisabledForEvents(nsIDOMNode *aNode, bool *_retval); \
  NS_IMETHOD GetPaintFlashing(bool *aPaintFlashing); \
  NS_IMETHOD SetPaintFlashing(bool aPaintFlashing); \
  NS_IMETHOD RunInStableState(nsIRunnable *runnable); \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable); \
  NS_IMETHOD GetOMTAStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval); \
  NS_IMETHOD GetOMTAOrComputedStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval); \
  NS_IMETHOD GetAudioMuted(bool *aAudioMuted); \
  NS_IMETHOD SetAudioMuted(bool aAudioMuted); \
  NS_IMETHOD GetAudioVolume(float *aAudioVolume); \
  NS_IMETHOD SetAudioVolume(float aAudioVolume); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOWUTILS(_to) \
  NS_IMETHOD GetImageAnimationMode(uint16_t *aImageAnimationMode) { return _to GetImageAnimationMode(aImageAnimationMode); } \
  NS_IMETHOD SetImageAnimationMode(uint16_t aImageAnimationMode) { return _to SetImageAnimationMode(aImageAnimationMode); } \
  NS_IMETHOD GetDocCharsetIsForced(bool *aDocCharsetIsForced) { return _to GetDocCharsetIsForced(aDocCharsetIsForced); } \
  NS_IMETHOD GetCursorType(int16_t *_retval) { return _to GetCursorType(_retval); } \
  NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval) { return _to GetDocumentMetadata(aName, _retval); } \
  NS_IMETHOD Redraw(uint32_t aCount, uint32_t *_retval) { return _to Redraw(aCount, _retval); } \
  NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx) { return _to SetCSSViewport(aWidthPx, aHeightPx); } \
  NS_IMETHOD GetViewportInfo(uint32_t aDisplayWidth, uint32_t aDisplayHeight, double *aDefaultZoom, bool *aAllowZoom, double *aMinZoom, double *aMaxZoom, uint32_t *aWidth, uint32_t *aHeight, bool *aAutoSize) { return _to GetViewportInfo(aDisplayWidth, aDisplayHeight, aDefaultZoom, aAllowZoom, aMinZoom, aMaxZoom, aWidth, aHeight, aAutoSize); } \
  NS_IMETHOD SetDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement, uint32_t aPriority) { return _to SetDisplayPortForElement(aXPx, aYPx, aWidthPx, aHeightPx, aElement, aPriority); } \
  NS_IMETHOD SetDisplayPortMarginsForElement(float aLeftMargin, float aTopMargin, float aRightMargin, float aBottomMargin, uint32_t aAlignment, nsIDOMElement *aElement, uint32_t aPriority) { return _to SetDisplayPortMarginsForElement(aLeftMargin, aTopMargin, aRightMargin, aBottomMargin, aAlignment, aElement, aPriority); } \
  NS_IMETHOD SetDisplayPortBaseForElement(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, nsIDOMElement *aElement) { return _to SetDisplayPortBaseForElement(aX, aY, aWidth, aHeight, aElement); } \
  NS_IMETHOD SetCriticalDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement) { return _to SetCriticalDisplayPortForElement(aXPx, aYPx, aWidthPx, aHeightPx, aElement); } \
  NS_IMETHOD SetResolution(float aXResolution, float aYResolution) { return _to SetResolution(aXResolution, aYResolution); } \
  NS_IMETHOD GetResolution(float *aXResolution, float *aYResolution) { return _to GetResolution(aXResolution, aYResolution); } \
  NS_IMETHOD GetIsFirstPaint(bool *aIsFirstPaint) { return _to GetIsFirstPaint(aIsFirstPaint); } \
  NS_IMETHOD SetIsFirstPaint(bool aIsFirstPaint) { return _to SetIsFirstPaint(aIsFirstPaint); } \
  NS_IMETHOD GetPresShellId(uint32_t *aPresShellId) { return _to GetPresShellId(aPresShellId); } \
  NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc, bool *_retval) { return _to SendMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aIsSynthesized, _argc, _retval); } \
  NS_IMETHOD SendPointerEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t tiltX, int32_t tiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc, bool *_retval) { return _to SendPointerEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aPointerId, aWidth, aHeight, tiltX, tiltY, aIsPrimary, aIsSynthesized, _argc, _retval); } \
  NS_IMETHOD SendTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) { return _to SendTouchEvent(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers, aIgnoreRootScrollFrame, _retval); } \
  NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc) { return _to SendMouseEventToWindow(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aIsSynthesized, _argc); } \
  NS_IMETHOD SendTouchEventToWindow(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) { return _to SendTouchEventToWindow(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers, aIgnoreRootScrollFrame, _retval); } \
  NS_IMETHOD SendWheelEvent(float aX, float aY, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aDeltaMode, int32_t aModifiers, int32_t aLineOrPageDeltaX, int32_t aLineOrPageDeltaY, uint32_t aOptions) { return _to SendWheelEvent(aX, aY, aDeltaX, aDeltaY, aDeltaZ, aDeltaMode, aModifiers, aLineOrPageDeltaX, aLineOrPageDeltaY, aOptions); } \
  NS_IMETHOD SendKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, uint32_t aAdditionalFlags, bool *_retval) { return _to SendKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aAdditionalFlags, _retval); } \
  NS_IMETHOD SendNativeKeyEvent(int32_t aNativeKeyboardLayout, int32_t aNativeKeyCode, int32_t aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters) { return _to SendNativeKeyEvent(aNativeKeyboardLayout, aNativeKeyCode, aModifierFlags, aCharacters, aUnmodifiedCharacters); } \
  NS_IMETHOD SendNativeMouseEvent(int32_t aScreenX, int32_t aScreenY, int32_t aNativeMessage, int32_t aModifierFlags, nsIDOMElement *aElement) { return _to SendNativeMouseEvent(aScreenX, aScreenY, aNativeMessage, aModifierFlags, aElement); } \
  NS_IMETHOD SendNativeMouseScrollEvent(int32_t aScreenX, int32_t aScreenY, uint32_t aNativeMessage, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aModifierFlags, uint32_t aAdditionalFlags, nsIDOMElement *aElement) { return _to SendNativeMouseScrollEvent(aScreenX, aScreenY, aNativeMessage, aDeltaX, aDeltaY, aDeltaZ, aModifierFlags, aAdditionalFlags, aElement); } \
  NS_IMETHOD SendNativeTouchPoint(uint32_t aPointerId, uint32_t aTouchState, int32_t aScreenX, int32_t aScreenY, double aPressure, uint32_t aOrientation) { return _to SendNativeTouchPoint(aPointerId, aTouchState, aScreenX, aScreenY, aPressure, aOrientation); } \
  NS_IMETHOD SendNativeTouchTap(int32_t aScreenX, int32_t aScreenY, bool aLongTap) { return _to SendNativeTouchTap(aScreenX, aScreenY, aLongTap); } \
  NS_IMETHOD ClearNativeTouchSequence(void) { return _to ClearNativeTouchSequence(); } \
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) { return _to ActivateNativeMenuItemAt(indexString); } \
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) { return _to ForceUpdateNativeMenuAt(indexString); } \
  NS_IMETHOD Focus(nsIDOMElement *aElement) { return _to Focus(aElement); } \
  NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) { return _to GarbageCollect(aListener, aExtraForgetSkippableCalls); } \
  NS_IMETHOD CycleCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) { return _to CycleCollect(aListener, aExtraForgetSkippableCalls); } \
  NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, uint32_t aDirection, double aDelta, int32_t aModifiers, uint32_t aClickCount) { return _to SendSimpleGestureEvent(aType, aX, aY, aDirection, aDelta, aModifiers, aClickCount); } \
  NS_IMETHOD ElementFromPoint(float aX, float aY, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMElement * *_retval) { return _to ElementFromPoint(aX, aY, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMNodeList * *_retval) { return _to NodesFromRect(aX, aY, aTopSize, aRightSize, aBottomSize, aLeftSize, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, uint32_t *aMaxDifference, uint32_t *_retval) { return _to CompareCanvases(aCanvas1, aCanvas2, aMaxDifference, _retval); } \
  NS_IMETHOD GetIsMozAfterPaintPending(bool *aIsMozAfterPaintPending) { return _to GetIsMozAfterPaintPending(aIsMozAfterPaintPending); } \
  NS_IMETHOD SuppressEventHandling(bool aSuppress) { return _to SuppressEventHandling(aSuppress); } \
  NS_IMETHOD ClearMozAfterPaintEvents(void) { return _to ClearMozAfterPaintEvents(); } \
  NS_IMETHOD DisableNonTestMouseEvents(bool aDisable) { return _to DisableNonTestMouseEvents(aDisable); } \
  NS_IMETHOD GetScrollXY(bool aFlushLayout, int32_t *aScrollX, int32_t *aScrollY) { return _to GetScrollXY(aFlushLayout, aScrollX, aScrollY); } \
  NS_IMETHOD GetScrollXYFloat(bool aFlushLayout, float *aScrollX, float *aScrollY) { return _to GetScrollXYFloat(aFlushLayout, aScrollX, aScrollY); } \
  NS_IMETHOD GetScrollbarSize(bool aFlushLayout, int32_t *aWidth, int32_t *aHeight) { return _to GetScrollbarSize(aFlushLayout, aWidth, aHeight); } \
  NS_IMETHOD GetBoundsWithoutFlushing(nsIDOMElement *aElement, nsIDOMClientRect * *_retval) { return _to GetBoundsWithoutFlushing(aElement, _retval); } \
  NS_IMETHOD GetRootBounds(nsIDOMClientRect * *_retval) { return _to GetRootBounds(_retval); } \
  NS_IMETHOD GetIMEIsOpen(bool *aIMEIsOpen) { return _to GetIMEIsOpen(aIMEIsOpen); } \
  NS_IMETHOD GetIMEStatus(uint32_t *aIMEStatus) { return _to GetIMEStatus(aIMEStatus); } \
  NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel) { return _to GetScreenPixelsPerCSSPixel(aScreenPixelsPerCSSPixel); } \
  NS_IMETHOD GetFullZoom(float *aFullZoom) { return _to GetFullZoom(aFullZoom); } \
  NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, bool aTrusted, bool *_retval) { return _to DispatchDOMEventViaPresShell(aTarget, aEvent, aTrusted, _retval); } \
  NS_IMETHOD DispatchEventToChromeOnly(nsIDOMEventTarget *aTarget, nsIDOMEvent *aEvent, bool *_retval) { return _to DispatchEventToChromeOnly(aTarget, aEvent, _retval); } \
  NS_IMETHOD GetClassName(JS::HandleValue aObject, JSContext* cx, char * *_retval) { return _to GetClassName(aObject, cx, _retval); } \
  NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable) { return _to SendContentCommandEvent(aType, aTransferable); } \
  NS_IMETHOD SendCompositionEvent(const nsAString & aType, const nsAString & aData, const nsAString & aLocale) { return _to SendCompositionEvent(aType, aData, aLocale); } \
  NS_IMETHOD CreateCompositionStringSynthesizer(nsICompositionStringSynthesizer * *_retval) { return _to CreateCompositionStringSynthesizer(_retval); } \
  NS_IMETHOD SendQueryContentEvent(uint32_t aType, uint32_t aOffset, uint32_t aLength, int32_t aX, int32_t aY, nsIQueryContentEventResult * *_retval) { return _to SendQueryContentEvent(aType, aOffset, aLength, aX, aY, _retval); } \
  NS_IMETHOD RemoteFrameFullscreenChanged(nsIDOMElement *aFrameElement, const nsAString & aNewOrigin) { return _to RemoteFrameFullscreenChanged(aFrameElement, aNewOrigin); } \
  NS_IMETHOD RemoteFrameFullscreenReverted(void) { return _to RemoteFrameFullscreenReverted(); } \
  NS_IMETHOD ExitFullscreen(void) { return _to ExitFullscreen(); } \
  NS_IMETHOD SendSelectionSetEvent(uint32_t aOffset, uint32_t aLength, bool aReverse, bool *_retval) { return _to SendSelectionSetEvent(aOffset, aLength, aReverse, _retval); } \
  NS_IMETHOD SelectAtPoint(float aX, float aY, uint32_t aSelectBehavior, bool *_retval) { return _to SelectAtPoint(aX, aY, aSelectBehavior, _retval); } \
  NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval) { return _to GetVisitedDependentComputedStyle(aElement, aPseudoElement, aPropertyName, _retval); } \
  NS_IMETHOD GetParent(JS::HandleValue obj, JSContext* cx, JS::MutableHandleValue _retval) { return _to GetParent(obj, cx, _retval); } \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) { return _to GetOuterWindowID(aOuterWindowID); } \
  NS_IMETHOD GetCurrentInnerWindowID(uint64_t *aCurrentInnerWindowID) { return _to GetCurrentInnerWindowID(aCurrentInnerWindowID); } \
  NS_IMETHOD EnterModalState(void) { return _to EnterModalState(); } \
  NS_IMETHOD LeaveModalState(void) { return _to LeaveModalState(); } \
  NS_IMETHOD IsInModalState(bool *_retval) { return _to IsInModalState(_retval); } \
  NS_IMETHOD SuspendTimeouts(void) { return _to SuspendTimeouts(); } \
  NS_IMETHOD ResumeTimeouts(void) { return _to ResumeTimeouts(); } \
  NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType) { return _to GetLayerManagerType(aLayerManagerType); } \
  NS_IMETHOD GetLayerManagerRemote(bool *aLayerManagerRemote) { return _to GetLayerManagerRemote(aLayerManagerRemote); } \
  NS_IMETHOD StartFrameTimeRecording(uint32_t *startIndex) { return _to StartFrameTimeRecording(startIndex); } \
  NS_IMETHOD StopFrameTimeRecording(uint32_t startIndex, uint32_t *frameCount, float **frameIntervals) { return _to StopFrameTimeRecording(startIndex, frameCount, frameIntervals); } \
  NS_IMETHOD BeginTabSwitch(void) { return _to BeginTabSwitch(); } \
  NS_IMETHOD GetDisplayDPI(float *aDisplayDPI) { return _to GetDisplayDPI(aDisplayDPI); } \
  NS_IMETHOD GetOuterWindowWithId(uint64_t aOuterWindowID, nsIDOMWindow * *_retval) { return _to GetOuterWindowWithId(aOuterWindowID, _retval); } \
  NS_IMETHOD GetContainerElement(nsIDOMElement * *aContainerElement) { return _to GetContainerElement(aContainerElement); } \
  NS_IMETHOD RenderDocument(const nsRect & aRect, uint32_t aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext) { return _to RenderDocument(aRect, aFlags, aBackgroundColor, aThebesContext); } \
  NS_IMETHOD AdvanceTimeAndRefresh(int64_t aMilliseconds) { return _to AdvanceTimeAndRefresh(aMilliseconds); } \
  NS_IMETHOD RestoreNormalRefresh(void) { return _to RestoreNormalRefresh(); } \
  NS_IMETHOD GetIsTestControllingRefreshes(bool *aIsTestControllingRefreshes) { return _to GetIsTestControllingRefreshes(aIsTestControllingRefreshes); } \
  NS_IMETHOD SetAsyncScrollOffset(nsIDOMNode *aNode, int32_t aX, int32_t aY) { return _to SetAsyncScrollOffset(aNode, aX, aY); } \
  NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval) { return _to ComputeAnimationDistance(element, property, value1, value2, _retval); } \
  NS_IMETHOD WrapDOMFile(nsIFile *aFile, nsIDOMFile * *_retval) { return _to WrapDOMFile(aFile, _retval); } \
  NS_IMETHOD GetFocusedInputType(char * *aFocusedInputType) { return _to GetFocusedInputType(aFocusedInputType); } \
  NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement * *_retval) { return _to FindElementWithViewId(aId, _retval); } \
  NS_IMETHOD GetViewId(nsIDOMElement *aElement, nsViewID *_retval) { return _to GetViewId(aElement, _retval); } \
  NS_IMETHOD LeafLayersPartitionWindow(bool *_retval) { return _to LeafLayersPartitionWindow(_retval); } \
  NS_IMETHOD GetMayHaveTouchEventListeners(bool *aMayHaveTouchEventListeners) { return _to GetMayHaveTouchEventListeners(aMayHaveTouchEventListeners); } \
  NS_IMETHOD CheckAndClearPaintedState(nsIDOMElement *aElement, bool *_retval) { return _to CheckAndClearPaintedState(aElement, _retval); } \
  NS_IMETHOD GetFile(const nsAString & aName, JS::HandleValue aBlobParts, JS::HandleValue aParameters, JSContext* cx, uint8_t _argc, nsIDOMFile * *_retval) { return _to GetFile(aName, aBlobParts, aParameters, cx, _argc, _retval); } \
  NS_IMETHOD GetBlob(JS::HandleValue aBlobParts, JS::HandleValue aParameters, JSContext* cx, uint8_t _argc, nsIDOMBlob * *_retval) { return _to GetBlob(aBlobParts, aParameters, cx, _argc, _retval); } \
  NS_IMETHOD GetFileId(JS::HandleValue aFile, JSContext* cx, int64_t *_retval) { return _to GetFileId(aFile, cx, _retval); } \
  NS_IMETHOD GetFileReferences(const nsAString & aDatabaseName, int64_t aId, JS::HandleValue aOptions, int32_t *aRefCnt, int32_t *aDBRefCnt, int32_t *aSliceRefCnt, JSContext* cx, bool *_retval) { return _to GetFileReferences(aDatabaseName, aId, aOptions, aRefCnt, aDBRefCnt, aSliceRefCnt, cx, _retval); } \
  NS_IMETHOD IsIncrementalGCEnabled(JSContext* cx, bool *_retval) { return _to IsIncrementalGCEnabled(cx, _retval); } \
  NS_IMETHOD StartPCCountProfiling(JSContext* cx) { return _to StartPCCountProfiling(cx); } \
  NS_IMETHOD StopPCCountProfiling(JSContext* cx) { return _to StopPCCountProfiling(cx); } \
  NS_IMETHOD PurgePCCounts(JSContext* cx) { return _to PurgePCCounts(cx); } \
  NS_IMETHOD GetPCCountScriptCount(JSContext* cx, int32_t *_retval) { return _to GetPCCountScriptCount(cx, _retval); } \
  NS_IMETHOD GetPCCountScriptSummary(int32_t script, JSContext* cx, nsAString & _retval) { return _to GetPCCountScriptSummary(script, cx, _retval); } \
  NS_IMETHOD GetPCCountScriptContents(int32_t script, JSContext* cx, nsAString & _retval) { return _to GetPCCountScriptContents(script, cx, _retval); } \
  NS_IMETHOD GetPaintingSuppressed(bool *aPaintingSuppressed) { return _to GetPaintingSuppressed(aPaintingSuppressed); } \
  NS_IMETHOD GetPlugins(JSContext* cx, JS::MutableHandleValue aPlugins) { return _to GetPlugins(cx, aPlugins); } \
  NS_IMETHOD SetScrollPositionClampingScrollPortSize(float aWidth, float aHeight) { return _to SetScrollPositionClampingScrollPortSize(aWidth, aHeight); } \
  NS_IMETHOD SetContentDocumentFixedPositionMargins(float aTop, float aRight, float aBottom, float aLeft) { return _to SetContentDocumentFixedPositionMargins(aTop, aRight, aBottom, aLeft); } \
  NS_IMETHOD DisableDialogs(void) { return _to DisableDialogs(); } \
  NS_IMETHOD EnableDialogs(void) { return _to EnableDialogs(); } \
  NS_IMETHOD AreDialogsEnabled(bool *_retval) { return _to AreDialogsEnabled(_retval); } \
  NS_IMETHOD LoadSheet(nsIURI *sheetURI, uint32_t type) { return _to LoadSheet(sheetURI, type); } \
  NS_IMETHOD RemoveSheet(nsIURI *sheetURI, uint32_t type) { return _to RemoveSheet(sheetURI, type); } \
  NS_IMETHOD GetIsHandlingUserInput(bool *aIsHandlingUserInput) { return _to GetIsHandlingUserInput(aIsHandlingUserInput); } \
  NS_IMETHOD AllowScriptsToClose(void) { return _to AllowScriptsToClose(); } \
  NS_IMETHOD GetIsParentWindowMainWidgetVisible(bool *aIsParentWindowMainWidgetVisible) { return _to GetIsParentWindowMainWidgetVisible(aIsParentWindowMainWidgetVisible); } \
  NS_IMETHOD IsNodeDisabledForEvents(nsIDOMNode *aNode, bool *_retval) { return _to IsNodeDisabledForEvents(aNode, _retval); } \
  NS_IMETHOD GetPaintFlashing(bool *aPaintFlashing) { return _to GetPaintFlashing(aPaintFlashing); } \
  NS_IMETHOD SetPaintFlashing(bool aPaintFlashing) { return _to SetPaintFlashing(aPaintFlashing); } \
  NS_IMETHOD RunInStableState(nsIRunnable *runnable) { return _to RunInStableState(runnable); } \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) { return _to RunBeforeNextEvent(runnable); } \
  NS_IMETHOD GetOMTAStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval) { return _to GetOMTAStyle(aElement, aProperty, _retval); } \
  NS_IMETHOD GetOMTAOrComputedStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval) { return _to GetOMTAOrComputedStyle(aElement, aProperty, _retval); } \
  NS_IMETHOD GetAudioMuted(bool *aAudioMuted) { return _to GetAudioMuted(aAudioMuted); } \
  NS_IMETHOD SetAudioMuted(bool aAudioMuted) { return _to SetAudioMuted(aAudioMuted); } \
  NS_IMETHOD GetAudioVolume(float *aAudioVolume) { return _to GetAudioVolume(aAudioVolume); } \
  NS_IMETHOD SetAudioVolume(float aAudioVolume) { return _to SetAudioVolume(aAudioVolume); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOWUTILS(_to) \
  NS_IMETHOD GetImageAnimationMode(uint16_t *aImageAnimationMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageAnimationMode(aImageAnimationMode); } \
  NS_IMETHOD SetImageAnimationMode(uint16_t aImageAnimationMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImageAnimationMode(aImageAnimationMode); } \
  NS_IMETHOD GetDocCharsetIsForced(bool *aDocCharsetIsForced) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocCharsetIsForced(aDocCharsetIsForced); } \
  NS_IMETHOD GetCursorType(int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCursorType(_retval); } \
  NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentMetadata(aName, _retval); } \
  NS_IMETHOD Redraw(uint32_t aCount, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Redraw(aCount, _retval); } \
  NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCSSViewport(aWidthPx, aHeightPx); } \
  NS_IMETHOD GetViewportInfo(uint32_t aDisplayWidth, uint32_t aDisplayHeight, double *aDefaultZoom, bool *aAllowZoom, double *aMinZoom, double *aMaxZoom, uint32_t *aWidth, uint32_t *aHeight, bool *aAutoSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewportInfo(aDisplayWidth, aDisplayHeight, aDefaultZoom, aAllowZoom, aMinZoom, aMaxZoom, aWidth, aHeight, aAutoSize); } \
  NS_IMETHOD SetDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement, uint32_t aPriority) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayPortForElement(aXPx, aYPx, aWidthPx, aHeightPx, aElement, aPriority); } \
  NS_IMETHOD SetDisplayPortMarginsForElement(float aLeftMargin, float aTopMargin, float aRightMargin, float aBottomMargin, uint32_t aAlignment, nsIDOMElement *aElement, uint32_t aPriority) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayPortMarginsForElement(aLeftMargin, aTopMargin, aRightMargin, aBottomMargin, aAlignment, aElement, aPriority); } \
  NS_IMETHOD SetDisplayPortBaseForElement(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayPortBaseForElement(aX, aY, aWidth, aHeight, aElement); } \
  NS_IMETHOD SetCriticalDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCriticalDisplayPortForElement(aXPx, aYPx, aWidthPx, aHeightPx, aElement); } \
  NS_IMETHOD SetResolution(float aXResolution, float aYResolution) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResolution(aXResolution, aYResolution); } \
  NS_IMETHOD GetResolution(float *aXResolution, float *aYResolution) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResolution(aXResolution, aYResolution); } \
  NS_IMETHOD GetIsFirstPaint(bool *aIsFirstPaint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsFirstPaint(aIsFirstPaint); } \
  NS_IMETHOD SetIsFirstPaint(bool aIsFirstPaint) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsFirstPaint(aIsFirstPaint); } \
  NS_IMETHOD GetPresShellId(uint32_t *aPresShellId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPresShellId(aPresShellId); } \
  NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aIsSynthesized, _argc, _retval); } \
  NS_IMETHOD SendPointerEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t tiltX, int32_t tiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendPointerEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aPointerId, aWidth, aHeight, tiltX, tiltY, aIsPrimary, aIsSynthesized, _argc, _retval); } \
  NS_IMETHOD SendTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendTouchEvent(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers, aIgnoreRootScrollFrame, _retval); } \
  NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMouseEventToWindow(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame, aPressure, aInputSourceArg, aIsSynthesized, _argc); } \
  NS_IMETHOD SendTouchEventToWindow(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendTouchEventToWindow(aType, aIdentifiers, aXs, aYs, aRxs, aRys, aRotationAngles, aForces, count, aModifiers, aIgnoreRootScrollFrame, _retval); } \
  NS_IMETHOD SendWheelEvent(float aX, float aY, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aDeltaMode, int32_t aModifiers, int32_t aLineOrPageDeltaX, int32_t aLineOrPageDeltaY, uint32_t aOptions) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendWheelEvent(aX, aY, aDeltaX, aDeltaY, aDeltaZ, aDeltaMode, aModifiers, aLineOrPageDeltaX, aLineOrPageDeltaY, aOptions); } \
  NS_IMETHOD SendKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, uint32_t aAdditionalFlags, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aAdditionalFlags, _retval); } \
  NS_IMETHOD SendNativeKeyEvent(int32_t aNativeKeyboardLayout, int32_t aNativeKeyCode, int32_t aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeKeyEvent(aNativeKeyboardLayout, aNativeKeyCode, aModifierFlags, aCharacters, aUnmodifiedCharacters); } \
  NS_IMETHOD SendNativeMouseEvent(int32_t aScreenX, int32_t aScreenY, int32_t aNativeMessage, int32_t aModifierFlags, nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeMouseEvent(aScreenX, aScreenY, aNativeMessage, aModifierFlags, aElement); } \
  NS_IMETHOD SendNativeMouseScrollEvent(int32_t aScreenX, int32_t aScreenY, uint32_t aNativeMessage, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aModifierFlags, uint32_t aAdditionalFlags, nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeMouseScrollEvent(aScreenX, aScreenY, aNativeMessage, aDeltaX, aDeltaY, aDeltaZ, aModifierFlags, aAdditionalFlags, aElement); } \
  NS_IMETHOD SendNativeTouchPoint(uint32_t aPointerId, uint32_t aTouchState, int32_t aScreenX, int32_t aScreenY, double aPressure, uint32_t aOrientation) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeTouchPoint(aPointerId, aTouchState, aScreenX, aScreenY, aPressure, aOrientation); } \
  NS_IMETHOD SendNativeTouchTap(int32_t aScreenX, int32_t aScreenY, bool aLongTap) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeTouchTap(aScreenX, aScreenY, aLongTap); } \
  NS_IMETHOD ClearNativeTouchSequence(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearNativeTouchSequence(); } \
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateNativeMenuItemAt(indexString); } \
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceUpdateNativeMenuAt(indexString); } \
  NS_IMETHOD Focus(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(aElement); } \
  NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) { return !_to ? NS_ERROR_NULL_POINTER : _to->GarbageCollect(aListener, aExtraForgetSkippableCalls); } \
  NS_IMETHOD CycleCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls) { return !_to ? NS_ERROR_NULL_POINTER : _to->CycleCollect(aListener, aExtraForgetSkippableCalls); } \
  NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, uint32_t aDirection, double aDelta, int32_t aModifiers, uint32_t aClickCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSimpleGestureEvent(aType, aX, aY, aDirection, aDelta, aModifiers, aClickCount); } \
  NS_IMETHOD ElementFromPoint(float aX, float aY, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ElementFromPoint(aX, aY, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMNodeList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodesFromRect(aX, aY, aTopSize, aRightSize, aBottomSize, aLeftSize, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, uint32_t *aMaxDifference, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareCanvases(aCanvas1, aCanvas2, aMaxDifference, _retval); } \
  NS_IMETHOD GetIsMozAfterPaintPending(bool *aIsMozAfterPaintPending) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsMozAfterPaintPending(aIsMozAfterPaintPending); } \
  NS_IMETHOD SuppressEventHandling(bool aSuppress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SuppressEventHandling(aSuppress); } \
  NS_IMETHOD ClearMozAfterPaintEvents(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearMozAfterPaintEvents(); } \
  NS_IMETHOD DisableNonTestMouseEvents(bool aDisable) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableNonTestMouseEvents(aDisable); } \
  NS_IMETHOD GetScrollXY(bool aFlushLayout, int32_t *aScrollX, int32_t *aScrollY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollXY(aFlushLayout, aScrollX, aScrollY); } \
  NS_IMETHOD GetScrollXYFloat(bool aFlushLayout, float *aScrollX, float *aScrollY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollXYFloat(aFlushLayout, aScrollX, aScrollY); } \
  NS_IMETHOD GetScrollbarSize(bool aFlushLayout, int32_t *aWidth, int32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollbarSize(aFlushLayout, aWidth, aHeight); } \
  NS_IMETHOD GetBoundsWithoutFlushing(nsIDOMElement *aElement, nsIDOMClientRect * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBoundsWithoutFlushing(aElement, _retval); } \
  NS_IMETHOD GetRootBounds(nsIDOMClientRect * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootBounds(_retval); } \
  NS_IMETHOD GetIMEIsOpen(bool *aIMEIsOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIMEIsOpen(aIMEIsOpen); } \
  NS_IMETHOD GetIMEStatus(uint32_t *aIMEStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIMEStatus(aIMEStatus); } \
  NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenPixelsPerCSSPixel(aScreenPixelsPerCSSPixel); } \
  NS_IMETHOD GetFullZoom(float *aFullZoom) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFullZoom(aFullZoom); } \
  NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, bool aTrusted, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchDOMEventViaPresShell(aTarget, aEvent, aTrusted, _retval); } \
  NS_IMETHOD DispatchEventToChromeOnly(nsIDOMEventTarget *aTarget, nsIDOMEvent *aEvent, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchEventToChromeOnly(aTarget, aEvent, _retval); } \
  NS_IMETHOD GetClassName(JS::HandleValue aObject, JSContext* cx, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassName(aObject, cx, _retval); } \
  NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendContentCommandEvent(aType, aTransferable); } \
  NS_IMETHOD SendCompositionEvent(const nsAString & aType, const nsAString & aData, const nsAString & aLocale) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendCompositionEvent(aType, aData, aLocale); } \
  NS_IMETHOD CreateCompositionStringSynthesizer(nsICompositionStringSynthesizer * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateCompositionStringSynthesizer(_retval); } \
  NS_IMETHOD SendQueryContentEvent(uint32_t aType, uint32_t aOffset, uint32_t aLength, int32_t aX, int32_t aY, nsIQueryContentEventResult * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendQueryContentEvent(aType, aOffset, aLength, aX, aY, _retval); } \
  NS_IMETHOD RemoteFrameFullscreenChanged(nsIDOMElement *aFrameElement, const nsAString & aNewOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoteFrameFullscreenChanged(aFrameElement, aNewOrigin); } \
  NS_IMETHOD RemoteFrameFullscreenReverted(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoteFrameFullscreenReverted(); } \
  NS_IMETHOD ExitFullscreen(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExitFullscreen(); } \
  NS_IMETHOD SendSelectionSetEvent(uint32_t aOffset, uint32_t aLength, bool aReverse, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSelectionSetEvent(aOffset, aLength, aReverse, _retval); } \
  NS_IMETHOD SelectAtPoint(float aX, float aY, uint32_t aSelectBehavior, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAtPoint(aX, aY, aSelectBehavior, _retval); } \
  NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisitedDependentComputedStyle(aElement, aPseudoElement, aPropertyName, _retval); } \
  NS_IMETHOD GetParent(JS::HandleValue obj, JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(obj, cx, _retval); } \
  NS_IMETHOD GetOuterWindowID(uint64_t *aOuterWindowID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWindowID(aOuterWindowID); } \
  NS_IMETHOD GetCurrentInnerWindowID(uint64_t *aCurrentInnerWindowID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentInnerWindowID(aCurrentInnerWindowID); } \
  NS_IMETHOD EnterModalState(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnterModalState(); } \
  NS_IMETHOD LeaveModalState(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LeaveModalState(); } \
  NS_IMETHOD IsInModalState(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsInModalState(_retval); } \
  NS_IMETHOD SuspendTimeouts(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SuspendTimeouts(); } \
  NS_IMETHOD ResumeTimeouts(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeTimeouts(); } \
  NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayerManagerType(aLayerManagerType); } \
  NS_IMETHOD GetLayerManagerRemote(bool *aLayerManagerRemote) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayerManagerRemote(aLayerManagerRemote); } \
  NS_IMETHOD StartFrameTimeRecording(uint32_t *startIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartFrameTimeRecording(startIndex); } \
  NS_IMETHOD StopFrameTimeRecording(uint32_t startIndex, uint32_t *frameCount, float **frameIntervals) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopFrameTimeRecording(startIndex, frameCount, frameIntervals); } \
  NS_IMETHOD BeginTabSwitch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginTabSwitch(); } \
  NS_IMETHOD GetDisplayDPI(float *aDisplayDPI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayDPI(aDisplayDPI); } \
  NS_IMETHOD GetOuterWindowWithId(uint64_t aOuterWindowID, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWindowWithId(aOuterWindowID, _retval); } \
  NS_IMETHOD GetContainerElement(nsIDOMElement * *aContainerElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContainerElement(aContainerElement); } \
  NS_IMETHOD RenderDocument(const nsRect & aRect, uint32_t aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->RenderDocument(aRect, aFlags, aBackgroundColor, aThebesContext); } \
  NS_IMETHOD AdvanceTimeAndRefresh(int64_t aMilliseconds) { return !_to ? NS_ERROR_NULL_POINTER : _to->AdvanceTimeAndRefresh(aMilliseconds); } \
  NS_IMETHOD RestoreNormalRefresh(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreNormalRefresh(); } \
  NS_IMETHOD GetIsTestControllingRefreshes(bool *aIsTestControllingRefreshes) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTestControllingRefreshes(aIsTestControllingRefreshes); } \
  NS_IMETHOD SetAsyncScrollOffset(nsIDOMNode *aNode, int32_t aX, int32_t aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAsyncScrollOffset(aNode, aX, aY); } \
  NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ComputeAnimationDistance(element, property, value1, value2, _retval); } \
  NS_IMETHOD WrapDOMFile(nsIFile *aFile, nsIDOMFile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WrapDOMFile(aFile, _retval); } \
  NS_IMETHOD GetFocusedInputType(char * *aFocusedInputType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedInputType(aFocusedInputType); } \
  NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindElementWithViewId(aId, _retval); } \
  NS_IMETHOD GetViewId(nsIDOMElement *aElement, nsViewID *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetViewId(aElement, _retval); } \
  NS_IMETHOD LeafLayersPartitionWindow(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->LeafLayersPartitionWindow(_retval); } \
  NS_IMETHOD GetMayHaveTouchEventListeners(bool *aMayHaveTouchEventListeners) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMayHaveTouchEventListeners(aMayHaveTouchEventListeners); } \
  NS_IMETHOD CheckAndClearPaintedState(nsIDOMElement *aElement, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckAndClearPaintedState(aElement, _retval); } \
  NS_IMETHOD GetFile(const nsAString & aName, JS::HandleValue aBlobParts, JS::HandleValue aParameters, JSContext* cx, uint8_t _argc, nsIDOMFile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aName, aBlobParts, aParameters, cx, _argc, _retval); } \
  NS_IMETHOD GetBlob(JS::HandleValue aBlobParts, JS::HandleValue aParameters, JSContext* cx, uint8_t _argc, nsIDOMBlob * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBlob(aBlobParts, aParameters, cx, _argc, _retval); } \
  NS_IMETHOD GetFileId(JS::HandleValue aFile, JSContext* cx, int64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileId(aFile, cx, _retval); } \
  NS_IMETHOD GetFileReferences(const nsAString & aDatabaseName, int64_t aId, JS::HandleValue aOptions, int32_t *aRefCnt, int32_t *aDBRefCnt, int32_t *aSliceRefCnt, JSContext* cx, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileReferences(aDatabaseName, aId, aOptions, aRefCnt, aDBRefCnt, aSliceRefCnt, cx, _retval); } \
  NS_IMETHOD IsIncrementalGCEnabled(JSContext* cx, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsIncrementalGCEnabled(cx, _retval); } \
  NS_IMETHOD StartPCCountProfiling(JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartPCCountProfiling(cx); } \
  NS_IMETHOD StopPCCountProfiling(JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopPCCountProfiling(cx); } \
  NS_IMETHOD PurgePCCounts(JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->PurgePCCounts(cx); } \
  NS_IMETHOD GetPCCountScriptCount(JSContext* cx, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPCCountScriptCount(cx, _retval); } \
  NS_IMETHOD GetPCCountScriptSummary(int32_t script, JSContext* cx, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPCCountScriptSummary(script, cx, _retval); } \
  NS_IMETHOD GetPCCountScriptContents(int32_t script, JSContext* cx, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPCCountScriptContents(script, cx, _retval); } \
  NS_IMETHOD GetPaintingSuppressed(bool *aPaintingSuppressed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaintingSuppressed(aPaintingSuppressed); } \
  NS_IMETHOD GetPlugins(JSContext* cx, JS::MutableHandleValue aPlugins) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlugins(cx, aPlugins); } \
  NS_IMETHOD SetScrollPositionClampingScrollPortSize(float aWidth, float aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrollPositionClampingScrollPortSize(aWidth, aHeight); } \
  NS_IMETHOD SetContentDocumentFixedPositionMargins(float aTop, float aRight, float aBottom, float aLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentDocumentFixedPositionMargins(aTop, aRight, aBottom, aLeft); } \
  NS_IMETHOD DisableDialogs(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableDialogs(); } \
  NS_IMETHOD EnableDialogs(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableDialogs(); } \
  NS_IMETHOD AreDialogsEnabled(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AreDialogsEnabled(_retval); } \
  NS_IMETHOD LoadSheet(nsIURI *sheetURI, uint32_t type) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadSheet(sheetURI, type); } \
  NS_IMETHOD RemoveSheet(nsIURI *sheetURI, uint32_t type) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSheet(sheetURI, type); } \
  NS_IMETHOD GetIsHandlingUserInput(bool *aIsHandlingUserInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsHandlingUserInput(aIsHandlingUserInput); } \
  NS_IMETHOD AllowScriptsToClose(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AllowScriptsToClose(); } \
  NS_IMETHOD GetIsParentWindowMainWidgetVisible(bool *aIsParentWindowMainWidgetVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsParentWindowMainWidgetVisible(aIsParentWindowMainWidgetVisible); } \
  NS_IMETHOD IsNodeDisabledForEvents(nsIDOMNode *aNode, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsNodeDisabledForEvents(aNode, _retval); } \
  NS_IMETHOD GetPaintFlashing(bool *aPaintFlashing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaintFlashing(aPaintFlashing); } \
  NS_IMETHOD SetPaintFlashing(bool aPaintFlashing) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPaintFlashing(aPaintFlashing); } \
  NS_IMETHOD RunInStableState(nsIRunnable *runnable) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunInStableState(runnable); } \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunBeforeNextEvent(runnable); } \
  NS_IMETHOD GetOMTAStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOMTAStyle(aElement, aProperty, _retval); } \
  NS_IMETHOD GetOMTAOrComputedStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOMTAOrComputedStyle(aElement, aProperty, _retval); } \
  NS_IMETHOD GetAudioMuted(bool *aAudioMuted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAudioMuted(aAudioMuted); } \
  NS_IMETHOD SetAudioMuted(bool aAudioMuted) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAudioMuted(aAudioMuted); } \
  NS_IMETHOD GetAudioVolume(float *aAudioVolume) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAudioVolume(aAudioVolume); } \
  NS_IMETHOD SetAudioVolume(float aAudioVolume) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAudioVolume(aAudioVolume); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindowUtils : public nsIDOMWindowUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOWUTILS

  nsDOMWindowUtils();

private:
  ~nsDOMWindowUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWindowUtils, nsIDOMWindowUtils)

nsDOMWindowUtils::nsDOMWindowUtils()
{
  /* member initializers and constructor code */
}

nsDOMWindowUtils::~nsDOMWindowUtils()
{
  /* destructor code */
}

/* attribute unsigned short imageAnimationMode; */
NS_IMETHODIMP nsDOMWindowUtils::GetImageAnimationMode(uint16_t *aImageAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetImageAnimationMode(uint16_t aImageAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean docCharsetIsForced; */
NS_IMETHODIMP nsDOMWindowUtils::GetDocCharsetIsForced(bool *aDocCharsetIsForced)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short getCursorType (); */
NS_IMETHODIMP nsDOMWindowUtils::GetCursorType(int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getDocumentMetadata (in AString aName); */
NS_IMETHODIMP nsDOMWindowUtils::GetDocumentMetadata(const nsAString & aName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long redraw ([optional] in unsigned long aCount); */
NS_IMETHODIMP nsDOMWindowUtils::Redraw(uint32_t aCount, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCSSViewport (in float aWidthPx, in float aHeightPx); */
NS_IMETHODIMP nsDOMWindowUtils::SetCSSViewport(float aWidthPx, float aHeightPx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getViewportInfo (in uint32_t aDisplayWidth, in uint32_t aDisplayHeight, out double aDefaultZoom, out boolean aAllowZoom, out double aMinZoom, out double aMaxZoom, out uint32_t aWidth, out uint32_t aHeight, out boolean aAutoSize); */
NS_IMETHODIMP nsDOMWindowUtils::GetViewportInfo(uint32_t aDisplayWidth, uint32_t aDisplayHeight, double *aDefaultZoom, bool *aAllowZoom, double *aMinZoom, double *aMaxZoom, uint32_t *aWidth, uint32_t *aHeight, bool *aAutoSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDisplayPortForElement (in float aXPx, in float aYPx, in float aWidthPx, in float aHeightPx, in nsIDOMElement aElement, in uint32_t aPriority); */
NS_IMETHODIMP nsDOMWindowUtils::SetDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement, uint32_t aPriority)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDisplayPortMarginsForElement (in float aLeftMargin, in float aTopMargin, in float aRightMargin, in float aBottomMargin, in uint32_t aAlignment, in nsIDOMElement aElement, in uint32_t aPriority); */
NS_IMETHODIMP nsDOMWindowUtils::SetDisplayPortMarginsForElement(float aLeftMargin, float aTopMargin, float aRightMargin, float aBottomMargin, uint32_t aAlignment, nsIDOMElement *aElement, uint32_t aPriority)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDisplayPortBaseForElement (in int32_t aX, in int32_t aY, in int32_t aWidth, in int32_t aHeight, in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::SetDisplayPortBaseForElement(int32_t aX, int32_t aY, int32_t aWidth, int32_t aHeight, nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCriticalDisplayPortForElement (in float aXPx, in float aYPx, in float aWidthPx, in float aHeightPx, in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::SetCriticalDisplayPortForElement(float aXPx, float aYPx, float aWidthPx, float aHeightPx, nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setResolution (in float aXResolution, in float aYResolution); */
NS_IMETHODIMP nsDOMWindowUtils::SetResolution(float aXResolution, float aYResolution)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getResolution (out float aXResolution, out float aYResolution); */
NS_IMETHODIMP nsDOMWindowUtils::GetResolution(float *aXResolution, float *aYResolution)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean isFirstPaint; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsFirstPaint(bool *aIsFirstPaint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetIsFirstPaint(bool aIsFirstPaint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPresShellId (out uint32_t aPresShellId); */
NS_IMETHODIMP nsDOMWindowUtils::GetPresShellId(uint32_t *aPresShellId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean sendMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in boolean aIsSynthesized); */
NS_IMETHODIMP nsDOMWindowUtils::SendMouseEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] boolean sendPointerEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in long aPointerId, [optional] in long aWidth, [optional] in long aHeight, [optional] in long tiltX, [optional] in long tiltY, [optional] in boolean aIsPrimary, [optional] in boolean aIsSynthesized); */
NS_IMETHODIMP nsDOMWindowUtils::SendPointerEvent(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, int32_t aPointerId, int32_t aWidth, int32_t aHeight, int32_t tiltX, int32_t tiltY, bool aIsPrimary, bool aIsSynthesized, uint8_t _argc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendTouchEvent (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
NS_IMETHODIMP nsDOMWindowUtils::SendTouchEvent(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] void sendMouseEventToWindow (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame, [optional] in float aPressure, [optional] in unsigned short aInputSourceArg, [optional] in boolean aIsSynthesized); */
NS_IMETHODIMP nsDOMWindowUtils::SendMouseEventToWindow(const nsAString & aType, float aX, float aY, int32_t aButton, int32_t aClickCount, int32_t aModifiers, bool aIgnoreRootScrollFrame, float aPressure, uint16_t aInputSourceArg, bool aIsSynthesized, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendTouchEventToWindow (in AString aType, [array, size_is (count)] in uint32_t aIdentifiers, [array, size_is (count)] in int32_t aXs, [array, size_is (count)] in int32_t aYs, [array, size_is (count)] in uint32_t aRxs, [array, size_is (count)] in uint32_t aRys, [array, size_is (count)] in float aRotationAngles, [array, size_is (count)] in float aForces, in uint32_t count, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
NS_IMETHODIMP nsDOMWindowUtils::SendTouchEventToWindow(const nsAString & aType, uint32_t *aIdentifiers, int32_t *aXs, int32_t *aYs, uint32_t *aRxs, uint32_t *aRys, float *aRotationAngles, float *aForces, uint32_t count, int32_t aModifiers, bool aIgnoreRootScrollFrame, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendWheelEvent (in float aX, in float aY, in double aDeltaX, in double aDeltaY, in double aDeltaZ, in unsigned long aDeltaMode, in long aModifiers, in long aLineOrPageDeltaX, in long aLineOrPageDeltaY, in unsigned long aOptions); */
NS_IMETHODIMP nsDOMWindowUtils::SendWheelEvent(float aX, float aY, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aDeltaMode, int32_t aModifiers, int32_t aLineOrPageDeltaX, int32_t aLineOrPageDeltaY, uint32_t aOptions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in unsigned long aAdditionalFlags); */
NS_IMETHODIMP nsDOMWindowUtils::SendKeyEvent(const nsAString & aType, int32_t aKeyCode, int32_t aCharCode, int32_t aModifiers, uint32_t aAdditionalFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeKeyEvent (in long aNativeKeyboardLayout, in long aNativeKeyCode, in long aModifierFlags, in AString aCharacters, in AString aUnmodifiedCharacters); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeKeyEvent(int32_t aNativeKeyboardLayout, int32_t aNativeKeyCode, int32_t aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeMouseEvent (in long aScreenX, in long aScreenY, in long aNativeMessage, in long aModifierFlags, in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeMouseEvent(int32_t aScreenX, int32_t aScreenY, int32_t aNativeMessage, int32_t aModifierFlags, nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeMouseScrollEvent (in long aScreenX, in long aScreenY, in unsigned long aNativeMessage, in double aDeltaX, in double aDeltaY, in double aDeltaZ, in unsigned long aModifierFlags, in unsigned long aAdditionalFlags, in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeMouseScrollEvent(int32_t aScreenX, int32_t aScreenY, uint32_t aNativeMessage, double aDeltaX, double aDeltaY, double aDeltaZ, uint32_t aModifierFlags, uint32_t aAdditionalFlags, nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeTouchPoint (in unsigned long aPointerId, in unsigned long aTouchState, in long aScreenX, in long aScreenY, in double aPressure, in unsigned long aOrientation); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeTouchPoint(uint32_t aPointerId, uint32_t aTouchState, int32_t aScreenX, int32_t aScreenY, double aPressure, uint32_t aOrientation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeTouchTap (in long aScreenX, in long aScreenY, in boolean aLongTap); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeTouchTap(int32_t aScreenX, int32_t aScreenY, bool aLongTap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearNativeTouchSequence (); */
NS_IMETHODIMP nsDOMWindowUtils::ClearNativeTouchSequence()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activateNativeMenuItemAt (in AString indexString); */
NS_IMETHODIMP nsDOMWindowUtils::ActivateNativeMenuItemAt(const nsAString & indexString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceUpdateNativeMenuAt (in AString indexString); */
NS_IMETHODIMP nsDOMWindowUtils::ForceUpdateNativeMenuAt(const nsAString & indexString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::Focus(nsIDOMElement *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void garbageCollect ([optional] in nsICycleCollectorListener aListener, [optional] in long aExtraForgetSkippableCalls); */
NS_IMETHODIMP nsDOMWindowUtils::GarbageCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cycleCollect ([optional] in nsICycleCollectorListener aListener, [optional] in long aExtraForgetSkippableCalls); */
NS_IMETHODIMP nsDOMWindowUtils::CycleCollect(nsICycleCollectorListener *aListener, int32_t aExtraForgetSkippableCalls)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendSimpleGestureEvent (in AString aType, in float aX, in float aY, in unsigned long aDirection, in double aDelta, in long aModifiers, [optional] in unsigned long aClickCount); */
NS_IMETHODIMP nsDOMWindowUtils::SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, uint32_t aDirection, double aDelta, int32_t aModifiers, uint32_t aClickCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement elementFromPoint (in float aX, in float aY, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
NS_IMETHODIMP nsDOMWindowUtils::ElementFromPoint(float aX, float aY, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList nodesFromRect (in float aX, in float aY, in float aTopSize, in float aRightSize, in float aBottomSize, in float aLeftSize, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
NS_IMETHODIMP nsDOMWindowUtils::NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, bool aIgnoreRootScrollFrame, bool aFlushLayout, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t compareCanvases (in nsIDOMHTMLCanvasElement aCanvas1, in nsIDOMHTMLCanvasElement aCanvas2, out unsigned long aMaxDifference); */
NS_IMETHODIMP nsDOMWindowUtils::CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, uint32_t *aMaxDifference, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isMozAfterPaintPending; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsMozAfterPaintPending(bool *aIsMozAfterPaintPending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suppressEventHandling (in boolean aSuppress); */
NS_IMETHODIMP nsDOMWindowUtils::SuppressEventHandling(bool aSuppress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearMozAfterPaintEvents (); */
NS_IMETHODIMP nsDOMWindowUtils::ClearMozAfterPaintEvents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableNonTestMouseEvents (in boolean aDisable); */
NS_IMETHODIMP nsDOMWindowUtils::DisableNonTestMouseEvents(bool aDisable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollXY (in boolean aFlushLayout, out long aScrollX, out long aScrollY); */
NS_IMETHODIMP nsDOMWindowUtils::GetScrollXY(bool aFlushLayout, int32_t *aScrollX, int32_t *aScrollY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollXYFloat (in boolean aFlushLayout, out float aScrollX, out float aScrollY); */
NS_IMETHODIMP nsDOMWindowUtils::GetScrollXYFloat(bool aFlushLayout, float *aScrollX, float *aScrollY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollbarSize (in boolean aFlushLayout, out long aWidth, out long aHeight); */
NS_IMETHODIMP nsDOMWindowUtils::GetScrollbarSize(bool aFlushLayout, int32_t *aWidth, int32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRect getBoundsWithoutFlushing (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::GetBoundsWithoutFlushing(nsIDOMElement *aElement, nsIDOMClientRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMClientRect getRootBounds (); */
NS_IMETHODIMP nsDOMWindowUtils::GetRootBounds(nsIDOMClientRect * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean IMEIsOpen; */
NS_IMETHODIMP nsDOMWindowUtils::GetIMEIsOpen(bool *aIMEIsOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long IMEStatus; */
NS_IMETHODIMP nsDOMWindowUtils::GetIMEStatus(uint32_t *aIMEStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float screenPixelsPerCSSPixel; */
NS_IMETHODIMP nsDOMWindowUtils::GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float fullZoom; */
NS_IMETHODIMP nsDOMWindowUtils::GetFullZoom(float *aFullZoom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean dispatchDOMEventViaPresShell (in nsIDOMNode aTarget, in nsIDOMEvent aEvent, in boolean aTrusted); */
NS_IMETHODIMP nsDOMWindowUtils::DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, bool aTrusted, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean dispatchEventToChromeOnly (in nsIDOMEventTarget aTarget, in nsIDOMEvent aEvent); */
NS_IMETHODIMP nsDOMWindowUtils::DispatchEventToChromeOnly(nsIDOMEventTarget *aTarget, nsIDOMEvent *aEvent, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] string getClassName (in jsval aObject); */
NS_IMETHODIMP nsDOMWindowUtils::GetClassName(JS::HandleValue aObject, JSContext* cx, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendContentCommandEvent (in AString aType, [optional] in nsITransferable aTransferable); */
NS_IMETHODIMP nsDOMWindowUtils::SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendCompositionEvent (in AString aType, in AString aData, in AString aLocale); */
NS_IMETHODIMP nsDOMWindowUtils::SendCompositionEvent(const nsAString & aType, const nsAString & aData, const nsAString & aLocale)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICompositionStringSynthesizer createCompositionStringSynthesizer (); */
NS_IMETHODIMP nsDOMWindowUtils::CreateCompositionStringSynthesizer(nsICompositionStringSynthesizer * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIQueryContentEventResult sendQueryContentEvent (in unsigned long aType, in unsigned long aOffset, in unsigned long aLength, in long aX, in long aY); */
NS_IMETHODIMP nsDOMWindowUtils::SendQueryContentEvent(uint32_t aType, uint32_t aOffset, uint32_t aLength, int32_t aX, int32_t aY, nsIQueryContentEventResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remoteFrameFullscreenChanged (in nsIDOMElement aFrameElement, in AString aNewOrigin); */
NS_IMETHODIMP nsDOMWindowUtils::RemoteFrameFullscreenChanged(nsIDOMElement *aFrameElement, const nsAString & aNewOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remoteFrameFullscreenReverted (); */
NS_IMETHODIMP nsDOMWindowUtils::RemoteFrameFullscreenReverted()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exitFullscreen (); */
NS_IMETHODIMP nsDOMWindowUtils::ExitFullscreen()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendSelectionSetEvent (in unsigned long aOffset, in unsigned long aLength, in boolean aReverse); */
NS_IMETHODIMP nsDOMWindowUtils::SendSelectionSetEvent(uint32_t aOffset, uint32_t aLength, bool aReverse, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean selectAtPoint (in float aX, in float aY, in unsigned long aSelectBehavior); */
NS_IMETHODIMP nsDOMWindowUtils::SelectAtPoint(float aX, float aY, uint32_t aSelectBehavior, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getVisitedDependentComputedStyle (in nsIDOMElement aElement, in AString aPseudoElement, in AString aPropertyName); */
NS_IMETHODIMP nsDOMWindowUtils::GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getParent (in jsval obj); */
NS_IMETHODIMP nsDOMWindowUtils::GetParent(JS::HandleValue obj, JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long outerWindowID; */
NS_IMETHODIMP nsDOMWindowUtils::GetOuterWindowID(uint64_t *aOuterWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long currentInnerWindowID; */
NS_IMETHODIMP nsDOMWindowUtils::GetCurrentInnerWindowID(uint64_t *aCurrentInnerWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enterModalState (); */
NS_IMETHODIMP nsDOMWindowUtils::EnterModalState()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void leaveModalState (); */
NS_IMETHODIMP nsDOMWindowUtils::LeaveModalState()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean isInModalState (); */
NS_IMETHODIMP nsDOMWindowUtils::IsInModalState(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspendTimeouts (); */
NS_IMETHODIMP nsDOMWindowUtils::SuspendTimeouts()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeTimeouts (); */
NS_IMETHODIMP nsDOMWindowUtils::ResumeTimeouts()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString layerManagerType; */
NS_IMETHODIMP nsDOMWindowUtils::GetLayerManagerType(nsAString & aLayerManagerType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean layerManagerRemote; */
NS_IMETHODIMP nsDOMWindowUtils::GetLayerManagerRemote(bool *aLayerManagerRemote)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startFrameTimeRecording ([retval] out unsigned long startIndex); */
NS_IMETHODIMP nsDOMWindowUtils::StartFrameTimeRecording(uint32_t *startIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopFrameTimeRecording (in unsigned long startIndex, [optional] out unsigned long frameCount, [array, size_is (frameCount), retval] out float frameIntervals); */
NS_IMETHODIMP nsDOMWindowUtils::StopFrameTimeRecording(uint32_t startIndex, uint32_t *frameCount, float **frameIntervals)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginTabSwitch (); */
NS_IMETHODIMP nsDOMWindowUtils::BeginTabSwitch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float displayDPI; */
NS_IMETHODIMP nsDOMWindowUtils::GetDisplayDPI(float *aDisplayDPI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow getOuterWindowWithId (in unsigned long long aOuterWindowID); */
NS_IMETHODIMP nsDOMWindowUtils::GetOuterWindowWithId(uint64_t aOuterWindowID, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement containerElement; */
NS_IMETHODIMP nsDOMWindowUtils::GetContainerElement(nsIDOMElement * *aContainerElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void RenderDocument (in nsConstRect aRect, in uint32_t aFlags, in nscolor aBackgroundColor, in gfxContext aThebesContext); */
NS_IMETHODIMP nsDOMWindowUtils::RenderDocument(const nsRect & aRect, uint32_t aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void advanceTimeAndRefresh (in long long aMilliseconds); */
NS_IMETHODIMP nsDOMWindowUtils::AdvanceTimeAndRefresh(int64_t aMilliseconds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreNormalRefresh (); */
NS_IMETHODIMP nsDOMWindowUtils::RestoreNormalRefresh()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute bool isTestControllingRefreshes; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsTestControllingRefreshes(bool *aIsTestControllingRefreshes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setAsyncScrollOffset (in nsIDOMNode aNode, in int32_t aX, in int32_t aY); */
NS_IMETHODIMP nsDOMWindowUtils::SetAsyncScrollOffset(nsIDOMNode *aNode, int32_t aX, int32_t aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double computeAnimationDistance (in nsIDOMElement element, in AString property, in AString value1, in AString value2); */
NS_IMETHODIMP nsDOMWindowUtils::ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMFile wrapDOMFile (in nsIFile aFile); */
NS_IMETHODIMP nsDOMWindowUtils::WrapDOMFile(nsIFile *aFile, nsIDOMFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string focusedInputType; */
NS_IMETHODIMP nsDOMWindowUtils::GetFocusedInputType(char * *aFocusedInputType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement findElementWithViewId (in nsViewID aId); */
NS_IMETHODIMP nsDOMWindowUtils::FindElementWithViewId(nsViewID aId, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsViewID getViewId (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::GetViewId(nsIDOMElement *aElement, nsViewID *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean leafLayersPartitionWindow (); */
NS_IMETHODIMP nsDOMWindowUtils::LeafLayersPartitionWindow(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mayHaveTouchEventListeners; */
NS_IMETHODIMP nsDOMWindowUtils::GetMayHaveTouchEventListeners(bool *aMayHaveTouchEventListeners)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkAndClearPaintedState (in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::CheckAndClearPaintedState(nsIDOMElement *aElement, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIDOMFile getFile (in DOMString aName, [optional] in jsval aBlobParts, [optional] in jsval aParameters); */
NS_IMETHODIMP nsDOMWindowUtils::GetFile(const nsAString & aName, JS::HandleValue aBlobParts, JS::HandleValue aParameters, JSContext* cx, uint8_t _argc, nsIDOMFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIDOMBlob getBlob ([optional] in jsval aBlobParts, [optional] in jsval aParameters); */
NS_IMETHODIMP nsDOMWindowUtils::GetBlob(JS::HandleValue aBlobParts, JS::HandleValue aParameters, JSContext* cx, uint8_t _argc, nsIDOMBlob * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] long long getFileId (in jsval aFile); */
NS_IMETHODIMP nsDOMWindowUtils::GetFileId(JS::HandleValue aFile, JSContext* cx, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] boolean getFileReferences (in AString aDatabaseName, in long long aId, [optional] in jsval aOptions, [optional] out long aRefCnt, [optional] out long aDBRefCnt, [optional] out long aSliceRefCnt); */
NS_IMETHODIMP nsDOMWindowUtils::GetFileReferences(const nsAString & aDatabaseName, int64_t aId, JS::HandleValue aOptions, int32_t *aRefCnt, int32_t *aDBRefCnt, int32_t *aSliceRefCnt, JSContext* cx, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] boolean isIncrementalGCEnabled (); */
NS_IMETHODIMP nsDOMWindowUtils::IsIncrementalGCEnabled(JSContext* cx, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void startPCCountProfiling (); */
NS_IMETHODIMP nsDOMWindowUtils::StartPCCountProfiling(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void stopPCCountProfiling (); */
NS_IMETHODIMP nsDOMWindowUtils::StopPCCountProfiling(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void purgePCCounts (); */
NS_IMETHODIMP nsDOMWindowUtils::PurgePCCounts(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] long getPCCountScriptCount (); */
NS_IMETHODIMP nsDOMWindowUtils::GetPCCountScriptCount(JSContext* cx, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] AString getPCCountScriptSummary (in long script); */
NS_IMETHODIMP nsDOMWindowUtils::GetPCCountScriptSummary(int32_t script, JSContext* cx, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] AString getPCCountScriptContents (in long script); */
NS_IMETHODIMP nsDOMWindowUtils::GetPCCountScriptContents(int32_t script, JSContext* cx, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean paintingSuppressed; */
NS_IMETHODIMP nsDOMWindowUtils::GetPaintingSuppressed(bool *aPaintingSuppressed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval plugins; */
NS_IMETHODIMP nsDOMWindowUtils::GetPlugins(JSContext* cx, JS::MutableHandleValue aPlugins)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setScrollPositionClampingScrollPortSize (in float aWidth, in float aHeight); */
NS_IMETHODIMP nsDOMWindowUtils::SetScrollPositionClampingScrollPortSize(float aWidth, float aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setContentDocumentFixedPositionMargins (in float aTop, in float aRight, in float aBottom, in float aLeft); */
NS_IMETHODIMP nsDOMWindowUtils::SetContentDocumentFixedPositionMargins(float aTop, float aRight, float aBottom, float aLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableDialogs (); */
NS_IMETHODIMP nsDOMWindowUtils::DisableDialogs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableDialogs (); */
NS_IMETHODIMP nsDOMWindowUtils::EnableDialogs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool areDialogsEnabled (); */
NS_IMETHODIMP nsDOMWindowUtils::AreDialogsEnabled(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadSheet (in nsIURI sheetURI, in unsigned long type); */
NS_IMETHODIMP nsDOMWindowUtils::LoadSheet(nsIURI *sheetURI, uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSheet (in nsIURI sheetURI, in unsigned long type); */
NS_IMETHODIMP nsDOMWindowUtils::RemoveSheet(nsIURI *sheetURI, uint32_t type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isHandlingUserInput; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsHandlingUserInput(bool *aIsHandlingUserInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void allowScriptsToClose (); */
NS_IMETHODIMP nsDOMWindowUtils::AllowScriptsToClose()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isParentWindowMainWidgetVisible; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsParentWindowMainWidgetVisible(bool *aIsParentWindowMainWidgetVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isNodeDisabledForEvents (in nsIDOMNode aNode); */
NS_IMETHODIMP nsDOMWindowUtils::IsNodeDisabledForEvents(nsIDOMNode *aNode, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean paintFlashing; */
NS_IMETHODIMP nsDOMWindowUtils::GetPaintFlashing(bool *aPaintFlashing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetPaintFlashing(bool aPaintFlashing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runInStableState (in nsIRunnable runnable); */
NS_IMETHODIMP nsDOMWindowUtils::RunInStableState(nsIRunnable *runnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runBeforeNextEvent (in nsIRunnable runnable); */
NS_IMETHODIMP nsDOMWindowUtils::RunBeforeNextEvent(nsIRunnable *runnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getOMTAStyle (in nsIDOMElement aElement, in AString aProperty); */
NS_IMETHODIMP nsDOMWindowUtils::GetOMTAStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getOMTAOrComputedStyle (in nsIDOMElement aElement, in AString aProperty); */
NS_IMETHODIMP nsDOMWindowUtils::GetOMTAOrComputedStyle(nsIDOMElement *aElement, const nsAString & aProperty, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean audioMuted; */
NS_IMETHODIMP nsDOMWindowUtils::GetAudioMuted(bool *aAudioMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetAudioMuted(bool aAudioMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute float audioVolume; */
NS_IMETHODIMP nsDOMWindowUtils::GetAudioVolume(float *aAudioVolume)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetAudioVolume(float aAudioVolume)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWindowUtils_h__ */
