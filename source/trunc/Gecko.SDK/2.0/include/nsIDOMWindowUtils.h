/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/base/nsIDOMWindowUtils.idl
 */

#ifndef __gen_nsIDOMWindowUtils_h__
#define __gen_nsIDOMWindowUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsColor.h"
#include "nsRect.h"
#include "gfxContext.h"
class nsICycleCollectorListener; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMNodeList; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMHTMLCanvasElement; /* forward declaration */

class nsIDOMEvent; /* forward declaration */

class nsITransferable; /* forward declaration */

class nsIQueryContentEventResult; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIDOMWindowUtils */
#define NS_IDOMWINDOWUTILS_IID_STR "85fa978a-fc91-4513-9f11-8911e671577f"

#define NS_IDOMWINDOWUTILS_IID \
  {0x85fa978a, 0xfc91, 0x4513, \
    { 0x9f, 0x11, 0x89, 0x11, 0xe6, 0x71, 0x57, 0x7f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMWindowUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOWUTILS_IID)

  /**
   * Image animation mode of the window. When this attribute's value
   * is changed, the implementation should set all images in the window
   * to the given value. That is, when set to kDontAnimMode, all images
   * will stop animating. The attribute's value must be one of the
   * animationMode values from imgIContainer.
   * @note Images may individually override the window's setting after
   *       the window's mode is set. Therefore images given different modes
   *       since the last setting of the window's mode may behave
   *       out of line with the window's overall mode.
   * @note The attribute's value is the window's overall mode. It may
   *       for example continue to report kDontAnimMode after all images
   *       have subsequently been individually animated.
   * @note Only images immediately in this window are affected;
   *       this is not recursive to subwindows.
   * @see imgIContainer
   */
  /* attribute unsigned short imageAnimationMode; */
  NS_SCRIPTABLE NS_IMETHOD GetImageAnimationMode(PRUint16 *aImageAnimationMode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetImageAnimationMode(PRUint16 aImageAnimationMode) = 0;

  /**
   * Whether the charset of the window's current document has been forced by
   * the user.
   * Cannot be accessed from unprivileged context (not content-accessible)
   */
  /* readonly attribute boolean docCharsetIsForced; */
  NS_SCRIPTABLE NS_IMETHOD GetDocCharsetIsForced(PRBool *aDocCharsetIsForced) = 0;

  /**
   * Get current cursor type from this window
   * @return the current value of nsCursor
   */
  /* short getCursorType (); */
  NS_SCRIPTABLE NS_IMETHOD GetCursorType(PRInt16 *_retval NS_OUTPARAM) = 0;

  /**
   * Function to get metadata associated with the window's current document
   * @param aName the name of the metadata.  This should be all lowercase.
   * @return the value of the metadata, or the empty string if it's not set
   *
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   */
  /* AString getDocumentMetadata (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Force an immediate redraw of this window.  The parameter specifies
   * the number of times to redraw, and the return value is the length,
   * in milliseconds, that the redraws took.  If aCount is not specified
   * or is 0, it is taken to be 1.
   */
  /* unsigned long redraw ([optional] in unsigned long aCount); */
  NS_SCRIPTABLE NS_IMETHOD Redraw(PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Set the CSS viewport to be |widthPx| x |heightPx| in units of CSS
   * pixels, regardless of the size of the enclosing widget/view.
   * This will trigger reflow.
   *
   * The caller of this method must have UniversalXPConnect
   * privileges.
   */
  /* void setCSSViewport (in float aWidthPx, in float aHeightPx); */
  NS_SCRIPTABLE NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx) = 0;

  /**
   * Set the "displayport" to be <xPx, yPx, widthPx, heightPx> in
   * units of CSS pixels, regardless of the size of the enclosing
   * widget/view.  This will *not* trigger reflow.
   *
   * <x, y> is relative to the top-left of the CSS viewport.  This
   * means that the pixels rendered to the displayport take scrolling
   * into account, for example.
   *
   * The displayport will be used as the window's visible region for
   * the purposes of invalidation and painting.  The displayport can
   * approximately be thought of as a "persistent" drawWindow()
   * (albeit with coordinates relative to the CSS viewport): the
   * bounds are remembered by the platform, and layer pixels are
   * retained and updated inside the viewport bounds.
   *
   * It's legal to set a displayport that extends beyond the CSS
   * viewport in any direction (left/right/top/bottom).
   * 
   * It's also legal to set a displayport that extends beyond the
   * document's bounds.  The value of the pixels rendered outside the
   * document bounds is not yet defined.
   *
   * The caller of this method must have UniversalXPConnect
   * privileges.
   */
  /* void setDisplayPort (in float aXPx, in float aYPx, in float aWidthPx, in float aHeightPx); */
  NS_SCRIPTABLE NS_IMETHOD SetDisplayPort(float aXPx, float aYPx, float aWidthPx, float aHeightPx) = 0;

  /**
   * Get/set the resolution at which rescalable web content is drawn.
   * Currently this is only (some) thebes content.
   *
   * Setting a new resolution does *not* trigger reflow.  This API is
   * entirely separate from textZoom and fullZoom; a resolution scale
   * can be applied together with both textZoom and fullZoom.
   *
   * The effect of is API for gfx code to allocate more or fewer
   * pixels for rescalable content by a factor of |resolution| in
   * either or both dimensions.  setResolution() together with
   * setDisplayport() can be used to implement a non-reflowing
   * scale-zoom in concert with another entity that can draw with a
   * scale.  For example, to scale a content |window| inside a
   * <browser> by a factor of 2.0
   *
   *   window.setDisplayport(x, y, oldW / 2.0, oldH / 2.0);
   *   window.setResolution(2.0, 2.0);
   *   // elsewhere
   *   browser.setViewportScale(2.0, 2.0);
   *
   * The caller of this method must have UniversalXPConnect
   * privileges.
   */
  /* void setResolution (in float aXResolution, in float aYResolution); */
  NS_SCRIPTABLE NS_IMETHOD SetResolution(float aXResolution, float aYResolution) = 0;

  /** Synthesize a mouse event. The event types supported are:
   *    mousedown, mouseup, mousemove, mouseover, mouseout, contextmenu
   *
   * Events are sent in coordinates offset by aX and aY from the window.
   *
   * Note that additional events may be fired as a result of this call. For
   * instance, typically a click event will be fired as a result of a
   * mousedown and mouseup in sequence.
   *
   * Normally at this level of events, the mouseover and mouseout events are
   * only fired when the window is entered or exited. For inter-element
   * mouseover and mouseout events, a movemove event fired on the new element
   * should be sufficient to generate the correct over and out events as well.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * The event is dispatched via the toplevel window, so it could go to any
   * window under the toplevel window, in some cases it could never reach this
   * window at all.
   *
   * @param aType event type
   * @param aX x offset in CSS pixels
   * @param aY y offset in CSS pixels
   * @param aButton button to synthesize
   * @param aClickCount number of clicks that have been performed
   * @param aModifiers modifiers pressed, using constants defined in nsIDOMNSEvent
   * @param aIgnoreRootScrollFrame whether the event should ignore viewport bounds
   *                           during dispatch
   */
  /* void sendMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
  NS_SCRIPTABLE NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame) = 0;

  /** The same as sendMouseEvent but ensures that the event is dispatched to
   *  this DOM window or one of its children.
   */
  /* void sendMouseEventToWindow (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
  NS_SCRIPTABLE NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame) = 0;

  /** Synthesize a mouse scroll event for a window. The event types supported
   *  are: 
   *    DOMMouseScroll
   *    MozMousePixelScroll
   *
   * Events are sent in coordinates offset by aX and aY from the window.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * @param aType event type
   * @param aX x offset in CSS pixels
   * @param aY y offset in CSS pixels
   * @param aButton button to synthesize
   * @param aScrollFlags flag bits --- see nsMouseScrollFlags in nsGUIEvent.h
   * @param aDelta the direction and amount to scroll (in lines or pixels,
   * depending on the event type)
   * @param aModifiers modifiers pressed, using constants defined in nsIDOMNSEvent
   */
  /* void sendMouseScrollEvent (in AString aType, in float aX, in float aY, in long aButton, in long aScrollFlags, in long aDelta, in long aModifiers); */
  NS_SCRIPTABLE NS_IMETHOD SendMouseScrollEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aScrollFlags, PRInt32 aDelta, PRInt32 aModifiers) = 0;

  /**
   * Synthesize a key event to the window. The event types supported are:
   *   keydown, keyup, keypress
   *
   * Key events generally end up being sent to the focused node.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * @param aType event type
   * @param aKeyCode key code
   * @param aCharCode character code
   * @param aModifiers modifiers pressed, using constants defined in nsIDOMNSEvent
   * @param aPreventDefault if true, preventDefault() the event before dispatch
   *
   * @return false if the event had preventDefault() called on it,
   *               true otherwise.  In other words, true if and only if the
   *               default action was taken.
   */
  /* boolean sendKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in boolean aPreventDefault); */
  NS_SCRIPTABLE NS_IMETHOD SendKeyEvent(const nsAString & aType, PRInt32 aKeyCode, PRInt32 aCharCode, PRInt32 aModifiers, PRBool aPreventDefault, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * See nsIWidget::SynthesizeNativeKeyEvent
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   */
  /* void sendNativeKeyEvent (in long aNativeKeyboardLayout, in long aNativeKeyCode, in long aModifierFlags, in AString aCharacters, in AString aUnmodifiedCharacters); */
  NS_SCRIPTABLE NS_IMETHOD SendNativeKeyEvent(PRInt32 aNativeKeyboardLayout, PRInt32 aNativeKeyCode, PRInt32 aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters) = 0;

  /**
   * See nsIWidget::SynthesizeNativeMouseEvent
   *
   * Will be called on the widget that contains aElement.
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   */
  /* void sendNativeMouseEvent (in long aScreenX, in long aScreenY, in long aNativeMessage, in long aModifierFlags, in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD SendNativeMouseEvent(PRInt32 aScreenX, PRInt32 aScreenY, PRInt32 aNativeMessage, PRInt32 aModifierFlags, nsIDOMElement *aElement) = 0;

  /**
   * See nsIWidget::ActivateNativeMenuItemAt
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   */
  /* void activateNativeMenuItemAt (in AString indexString); */
  NS_SCRIPTABLE NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) = 0;

  /**
   * See nsIWidget::ForceUpdateNativeMenuAt
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   */
  /* void forceUpdateNativeMenuAt (in AString indexString); */
  NS_SCRIPTABLE NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) = 0;

  /**
   * Focus the element aElement. The element should be in the same document
   * that the window is displaying. Pass null to blur the element, if any,
   * that currently has focus, and focus the document.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * @param aElement the element to focus
   *
   * Do not use this method. Just use element.focus if available or
   * nsIFocusManager::SetFocus instead.
   *
   */
  /* void focus (in nsIDOMElement aElement); */
  NS_SCRIPTABLE NS_IMETHOD Focus(nsIDOMElement *aElement) = 0;

  /**
   * Force a garbage collection followed by a cycle collection.
   *
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges in non-debug builds. Available to all callers in debug builds.
   *
   * @param aListener listener that receives information about the CC graph
   *                  (see @mozilla.org/cycle-collector-logger;1 for a logger
   *                   component)
   */
  /* void garbageCollect ([optional] in nsICycleCollectorListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener) = 0;

  /**
   * Force processing of any queued paints
   */
  /* void processUpdates (); */
  NS_SCRIPTABLE NS_IMETHOD ProcessUpdates(void) = 0;

  /** Synthesize a simple gesture event for a window. The event types
   *  supported are: MozSwipeGesture, MozMagnifyGestureStart,
   *  MozMagnifyGestureUpdate, MozMagnifyGesture, MozRotateGestureStart,
   *  MozRotateGestureUpdate, MozRotateGesture, MozPressTapGesture, and
   *  MozTapGesture.
   *
   * Cannot be accessed from unprivileged context (not
   * content-accessible) Will throw a DOM security error if called
   * without UniversalXPConnect privileges.
   *
   * @param aType event type
   * @param aX x offset in CSS pixels
   * @param aY y offset in CSS pixels
   * @param aDirection direction, using constants defined in nsIDOMSimpleGestureEvent
   * @param aDelta  amount of magnification or rotation for magnify and rotation events
   * @param aModifiers modifiers pressed, using constants defined in nsIDOMNSEvent
   */
  /* void sendSimpleGestureEvent (in AString aType, in float aX, in float aY, in unsigned long aDirection, in double aDelta, in long aModifiers); */
  NS_SCRIPTABLE NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, PRUint32 aDirection, double aDelta, PRInt32 aModifiers) = 0;

  /**
   * Retrieve the element at point aX, aY in the window's document.
   *
   * @param aIgnoreRootScrollFrame whether or not to ignore the root scroll
   *        frame when retrieving the element. If false, this method returns
   *        null for coordinates outside of the viewport.
   * @param aFlushLayout flushes layout if true. Otherwise, no flush occurs.
   */
  /* nsIDOMElement elementFromPoint (in float aX, in float aY, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(float aX, float aY, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /**
   * Retrieve all nodes that intersect a rect in the window's document.
   *
   * @param aX x reference for the rectangle in CSS pixels
   * @param aY y reference for the rectangle in CSS pixels
   * @param aTopSize How much to expand up the rectangle
   * @param aRightSize How much to expand right the rectangle
   * @param aBottomSize How much to expand down the rectangle
   * @param aLeftSize How much to expand left the rectangle
   * @param aIgnoreRootScrollFrame whether or not to ignore the root scroll
   *        frame when retrieving the element. If false, this method returns
   *        null for coordinates outside of the viewport.
   * @param aFlushLayout flushes layout if true. Otherwise, no flush occurs.
   */
  /* nsIDOMNodeList nodesFromRect (in float aX, in float aY, in float aTopSize, in float aRightSize, in float aBottomSize, in float aLeftSize, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
  NS_SCRIPTABLE NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMNodeList **_retval NS_OUTPARAM) = 0;

  /**
   * Compare the two canvases, returning the number of differing pixels and
   * the maximum difference in a channel.  This will throw an error if
   * the dimensions of the two canvases are different.
   *
   * This method requires UniversalXPConnect privileges.
   */
  /* PRUint32 compareCanvases (in nsIDOMHTMLCanvasElement aCanvas1, in nsIDOMHTMLCanvasElement aCanvas2, out unsigned long aMaxDifference); */
  NS_SCRIPTABLE NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, PRUint32 *aMaxDifference NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Returns true if a MozAfterPaint event has been queued but not yet
   * fired.
   */
  /* readonly attribute boolean isMozAfterPaintPending; */
  NS_SCRIPTABLE NS_IMETHOD GetIsMozAfterPaintPending(PRBool *aIsMozAfterPaintPending) = 0;

  /**
   * Suppresses/unsuppresses user initiated event handling in window's document
   * and subdocuments.
   *
   * @throw NS_ERROR_DOM_SECURITY_ERR if called without UniversalXPConnect
   *        privileges and NS_ERROR_FAILURE if window doesn't have a document.
   */
  /* void suppressEventHandling (in boolean aSuppress); */
  NS_SCRIPTABLE NS_IMETHOD SuppressEventHandling(PRBool aSuppress) = 0;

  /* void clearMozAfterPaintEvents (); */
  NS_SCRIPTABLE NS_IMETHOD ClearMozAfterPaintEvents(void) = 0;

  /**
   * Disable or enable non synthetic test mouse events on *all* windows.
   *
   * Cannot be accessed from unprivileged context (not content-accessible).
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * @param aDisable  If true, disable all non synthetic test mouse events
   *               on all windows.  Otherwise, enable them.
   */
  /* void disableNonTestMouseEvents (in boolean aDisable); */
  NS_SCRIPTABLE NS_IMETHOD DisableNonTestMouseEvents(PRBool aDisable) = 0;

  /**
   * Returns the scroll position of the window's currently loaded document.
   *
   * @param aFlushLayout flushes layout if true. Otherwise, no flush occurs.
   * @see nsIDOMWindow::scrollX/Y
   */
  /* void getScrollXY (in boolean aFlushLayout, out long aScrollX, out long aScrollY); */
  NS_SCRIPTABLE NS_IMETHOD GetScrollXY(PRBool aFlushLayout, PRInt32 *aScrollX NS_OUTPARAM, PRInt32 *aScrollY NS_OUTPARAM) = 0;

  /**
   * Get IME open state. TRUE means 'Open', otherwise, 'Close'.
   * This property works only when IMEEnabled is IME_STATUS_ENABLED.
   */
  /* readonly attribute boolean IMEIsOpen; */
  NS_SCRIPTABLE NS_IMETHOD GetIMEIsOpen(PRBool *aIMEIsOpen) = 0;

  /**
   * WARNING: These values must be same as nsIWidget's values.
   */
/**
   * DISABLED means users cannot use IME completely.
   * Note that this state is *not* same as |ime-mode: disabled;|.
   */
  enum { IME_STATUS_DISABLED = 0U };

  /**
   * ENABLED means users can use all functions of IME. This state is same as
   * |ime-mode: normal;|.
   */
  enum { IME_STATUS_ENABLED = 1U };

  /**
   * PASSWORD means users cannot use most functions of IME. But on GTK2,
   * users can use "Simple IM" which only supports dead key inputting.
   * The behavior is same as the behavior of the native password field.
   * This state is same as |ime-mode: disabled;|.
   */
  enum { IME_STATUS_PASSWORD = 2U };

  /**
   * PLUGIN means a plug-in has focus. At this time we should not touch to
   * controlling the IME state.
   */
  enum { IME_STATUS_PLUGIN = 3U };

  /**
   * Get IME status, see above IME_STATUS_* definitions.
   */
  /* readonly attribute unsigned long IMEStatus; */
  NS_SCRIPTABLE NS_IMETHOD GetIMEStatus(PRUint32 *aIMEStatus) = 0;

  /**
   * Get the number of screen pixels per CSS pixel.
   */
  /* readonly attribute float screenPixelsPerCSSPixel; */
  NS_SCRIPTABLE NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel) = 0;

  /**
   * Dispatches aEvent via the nsIPresShell object of the window's document.
   * The event is dispatched to aTarget, which should be an object
   * which implements nsIContent interface (#element, #text, etc).
   *
   * Cannot be accessed from unprivileged context (not
   * content-accessible) Will throw a DOM security error if called
   * without UniversalXPConnect privileges.
   *
   * @note Event handlers won't get aEvent as parameter, but a similar event.
   *       Also, aEvent should not be reused.
   */
  /* boolean dispatchDOMEventViaPresShell (in nsIDOMNode aTarget, in nsIDOMEvent aEvent, in boolean aTrusted); */
  NS_SCRIPTABLE NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, PRBool aTrusted, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Returns the real classname (possibly of the mostly-transparent security
   * wrapper) of aObj.
   */
  /* string getClassName (); */
  NS_SCRIPTABLE NS_IMETHOD GetClassName(char **_retval NS_OUTPARAM) = 0;

  /**
   * Generate a content command event.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * @param aType Type of command content event to send.  Can be one of "cut",
   *        "copy", "paste", "delete", "undo", "redo", or "pasteTransferable".
   * @param aTransferable an instance of nsITransferable when aType is
   *        "pasteTransferable"
   */
  /* void sendContentCommandEvent (in AString aType, [optional] in nsITransferable aTransferable); */
  NS_SCRIPTABLE NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable) = 0;

  /**
   * Synthesize a composition event to the window.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * @param aType The event type: "compositionstart" or "compositionend".
   */
  /* void sendCompositionEvent (in AString aType); */
  NS_SCRIPTABLE NS_IMETHOD SendCompositionEvent(const nsAString & aType) = 0;

  /**
   * Synthesize a text event to the window.
   *
   * Cannot be accessed from unprivileged context (not content-accessible)
   * Will throw a DOM security error if called without UniversalXPConnect
   * privileges.
   *
   * Currently, this method doesn't support 4 or more clauses composition
   * string.
   *
   * @param aCompositionString  composition string
   * @param a*ClauseLengh       the length of nth clause, set 0 when you
   *                            don't need second or third clause.
   * @param a*ClauseAttr        the attribute of nth clause, uese following
   *                            const values.
   * @param aCaretStart         the caret position in the composition string,
   *                            if you set negative value, this method don't
   *                            set the caret position to the event.
   * @param aCaretLength        the caret length, if this is one or more,
   *                            the caret will be wide caret, otherwise,
   *                            it's collapsed.
   *                            XXX nsEditor doesn't support wide caret yet.
   */
  enum { COMPOSITION_ATTR_RAWINPUT = 2U };

  enum { COMPOSITION_ATTR_SELECTEDRAWTEXT = 3U };

  enum { COMPOSITION_ATTR_CONVERTEDTEXT = 4U };

  enum { COMPOSITION_ATTR_SELECTEDCONVERTEDTEXT = 5U };

  /* void sendTextEvent (in AString aCompositionString, in long aFirstClauseLength, in unsigned long aFirstClauseAttr, in long aSecondClauseLength, in unsigned long aSecondClauseAttr, in long aThirdClauseLength, in unsigned long aThirdClauseAttr, in long aCaretStart, in long aCaretLength); */
  NS_SCRIPTABLE NS_IMETHOD SendTextEvent(const nsAString & aCompositionString, PRInt32 aFirstClauseLength, PRUint32 aFirstClauseAttr, PRInt32 aSecondClauseLength, PRUint32 aSecondClauseAttr, PRInt32 aThirdClauseLength, PRUint32 aThirdClauseAttr, PRInt32 aCaretStart, PRInt32 aCaretLength) = 0;

  /**
   * Synthesize a query content event.
   *
   * @param aType  On of the following const values.  And see also each comment
   *               for the other parameters and the result.
   */
  /* nsIQueryContentEventResult sendQueryContentEvent (in unsigned long aType, in unsigned long aOffset, in unsigned long aLength, in long aX, in long aY); */
  NS_SCRIPTABLE NS_IMETHOD SendQueryContentEvent(PRUint32 aType, PRUint32 aOffset, PRUint32 aLength, PRInt32 aX, PRInt32 aY, nsIQueryContentEventResult **_retval NS_OUTPARAM) = 0;

  /**
   * QUERY_SELECTED_TEXT queries the first selection range's information.
   *
   * @param aOffset   Not used.
   * @param aLength   Not used.
   * @param aX        Not used.
   * @param aY        Not used.
   *
   * @return offset, reversed and text properties of the result are available.
   */
  enum { QUERY_SELECTED_TEXT = 3200U };

  /**
   * QUERY_TEXT_CONTENT queries the text at the specified range.
   *
   * @param aOffset   The first character's offset.  0 is the first character.
   * @param aLength   The length of getting text.  If the aLength is too long,
   *                  the result text is shorter than this value.
   * @param aX        Not used.
   * @param aY        Not used.
   *
   * @return text property of the result is available.
   */
  enum { QUERY_TEXT_CONTENT = 3201U };

  /**
   * QUERY_CARET_RECT queries the (collapsed) caret rect of the offset.
   * If the actual caret is there at the specified offset, this returns the
   * actual caret rect.  Otherwise, this guesses the caret rect from the
   * metrics of the text.
   *
   * @param aOffset   The caret offset.  0 is the left side of the first
   *                  caracter in LTR text.
   * @param aLength   Not used.
   * @param aX        Not used.
   * @param aY        Not used.
   *
   * @return left, top, width and height properties of the result are available.
   *         The left and the top properties are offset in the client area of
   *         the DOM window.
   */
  enum { QUERY_CARET_RECT = 3203U };

  /**
   * QUERY_TEXT_RECT queries the specified text's rect.
   *
   * @param aOffset   The first character's offset.  0 is the first character.
   * @param aLength   The length of getting text.  If the aLength is too long,
   *                  the extra length is ignored.
   * @param aX        Not used.
   * @param aY        Not used.
   *
   * @return left, top, width and height properties of the result are available.
   *         The left and the top properties are offset in the client area of
   *         the DOM window.
   */
  enum { QUERY_TEXT_RECT = 3204U };

  /**
   * QUERY_TEXT_RECT queries the focused editor's rect.
   *
   * @param aOffset   Not used.
   * @param aLength   Not used.
   * @param aX        Not used.
   * @param aY        Not used.
   *
   * @return left, top, width and height properties of the result are available.
   */
  enum { QUERY_EDITOR_RECT = 3205U };

  /**
   * QUERY_CHARACTER_AT_POINT queries the character information at the
   * specified point.  The point is offset in the window.
   * NOTE: If there are some panels at the point, this method send the query
   * event to the panel's widget automatically.
   *
   * @param aOffset   Not used.
   * @param aLength   Not used.
   * @param aX        X offset in the widget.
   * @param aY        Y offset in the widget.
   *
   * @return offset, notFound, left, top, width and height properties of the
   *         result are available.
   */
  enum { QUERY_CHARACTER_AT_POINT = 3208U };

  /**
   * Synthesize a selection set event to the window.
   *
   * This sets the selection as the specified information.
   *
   * @param aOffset  The caret offset of the selection start.
   * @param aLength  The length of the selection.  If this is too long, the
   *                 extra length is ignored.
   * @param aReverse If true, the selection set from |aOffset + aLength| to
   *                 |aOffset|.  Otherwise, set from |aOffset| to
   *                 |aOffset + aLength|.
   * @return True, if succeeded.  Otherwise, false.
   */
  /* boolean sendSelectionSetEvent (in unsigned long aOffset, in unsigned long aLength, in boolean aReverse); */
  NS_SCRIPTABLE NS_IMETHOD SendSelectionSetEvent(PRUint32 aOffset, PRUint32 aLength, PRBool aReverse, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Perform the equivalent of:
   *   window.getComputedStyle(aElement, aPseudoElement).
   *     getPropertyValue(aPropertyName)
   * except that, when the link whose presence in history is allowed to
   * influence aElement's style is visited, get the value the property
   * would have if allowed all properties to change as a result of
   * :visited selectors (except for cases where getComputedStyle uses
   * data from the frame).
   *
   * This is easier to implement than adding our property restrictions
   * to this API, and is sufficient for the present testing
   * requirements (which are essentially testing 'color').
   */
  /* AString getVisitedDependentComputedStyle (in nsIDOMElement aElement, in AString aPseudoElement, in AString aPropertyName); */
  NS_SCRIPTABLE NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * Returns the parent of obj.
   *
   * @param obj The JavaScript object whose parent is to be gotten.
   * @return the parent.
   */
  /* void getParent (); */
  NS_SCRIPTABLE NS_IMETHOD GetParent(void) = 0;

  /**
   * Get the id of the outer window of this window.  This will never throw.
   */
  /* readonly attribute unsigned long long outerWindowID; */
  NS_SCRIPTABLE NS_IMETHOD GetOuterWindowID(PRUint64 *aOuterWindowID) = 0;

  /**
   * Get the id of the current inner window of this window.  If there
   * is no current inner window, throws NS_ERROR_NOT_AVAILABLE.
   */
  /* readonly attribute unsigned long long currentInnerWindowID; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentInnerWindowID(PRUint64 *aCurrentInnerWindowID) = 0;

  /**
   * Put the window into a state where scripts are frozen and events
   * suppressed, for use when the window has launched a modal prompt.
   */
  /* [noscript] void enterModalState (); */
  NS_IMETHOD EnterModalState(void) = 0;

  /**
   * Resume normal window state, where scripts can run and events are
   * delivered.
   */
  /* [noscript] void leaveModalState (); */
  NS_IMETHOD LeaveModalState(void) = 0;

  /**
   * Is the window is in a modal state? [See enterModalState()]
   */
  /* [noscript] boolean isInModalState (); */
  NS_IMETHOD IsInModalState(PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Suspend/resume timeouts on this window and its descendant windows.
   */
  /* void suspendTimeouts (); */
  NS_SCRIPTABLE NS_IMETHOD SuspendTimeouts(void) = 0;

  /* void resumeTimeouts (); */
  NS_SCRIPTABLE NS_IMETHOD ResumeTimeouts(void) = 0;

  /**
   * What type of layer manager the widget associated with this window is
   * using. "Basic" is unaccelerated; other types are accelerated. Throws an
   * error if there is no widget associated with this window.
   */
  /* readonly attribute AString layerManagerType; */
  NS_SCRIPTABLE NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType) = 0;

  /**
   * The DPI of the display
   */
  /* readonly attribute float displayDPI; */
  NS_SCRIPTABLE NS_IMETHOD GetDisplayDPI(float *aDisplayDPI) = 0;

  /**
   * Return the outer window with the given ID, if any.  Can return null.
   */
  /* nsIDOMWindow getOuterWindowWithId (in unsigned long long aOuterWindowID); */
  NS_SCRIPTABLE NS_IMETHOD GetOuterWindowWithId(PRUint64 aOuterWindowID, nsIDOMWindow **_retval NS_OUTPARAM) = 0;

  /* [noscript] void RenderDocument (in nsConstRect aRect, in PRUint32 aFlags, in nscolor aBackgroundColor, in gfxContext aThebesContext); */
  NS_IMETHOD RenderDocument(const nsRect & aRect, PRUint32 aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext) = 0;

  /**
   * Method for testing nsStyleAnimation::ComputeDistance.
   *
   * Returns the distance between the two values as reported by
   * nsStyleAnimation::ComputeDistance for the given element and
   * property.
   */
  /* double computeAnimationDistance (in nsIDOMElement element, in AString property, in AString value1, in AString value2); */
  NS_SCRIPTABLE NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindowUtils, NS_IDOMWINDOWUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOWUTILS \
  NS_SCRIPTABLE NS_IMETHOD GetImageAnimationMode(PRUint16 *aImageAnimationMode); \
  NS_SCRIPTABLE NS_IMETHOD SetImageAnimationMode(PRUint16 aImageAnimationMode); \
  NS_SCRIPTABLE NS_IMETHOD GetDocCharsetIsForced(PRBool *aDocCharsetIsForced); \
  NS_SCRIPTABLE NS_IMETHOD GetCursorType(PRInt16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Redraw(PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx); \
  NS_SCRIPTABLE NS_IMETHOD SetDisplayPort(float aXPx, float aYPx, float aWidthPx, float aHeightPx); \
  NS_SCRIPTABLE NS_IMETHOD SetResolution(float aXResolution, float aYResolution); \
  NS_SCRIPTABLE NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame); \
  NS_SCRIPTABLE NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame); \
  NS_SCRIPTABLE NS_IMETHOD SendMouseScrollEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aScrollFlags, PRInt32 aDelta, PRInt32 aModifiers); \
  NS_SCRIPTABLE NS_IMETHOD SendKeyEvent(const nsAString & aType, PRInt32 aKeyCode, PRInt32 aCharCode, PRInt32 aModifiers, PRBool aPreventDefault, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SendNativeKeyEvent(PRInt32 aNativeKeyboardLayout, PRInt32 aNativeKeyCode, PRInt32 aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters); \
  NS_SCRIPTABLE NS_IMETHOD SendNativeMouseEvent(PRInt32 aScreenX, PRInt32 aScreenY, PRInt32 aNativeMessage, PRInt32 aModifierFlags, nsIDOMElement *aElement); \
  NS_SCRIPTABLE NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString); \
  NS_SCRIPTABLE NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString); \
  NS_SCRIPTABLE NS_IMETHOD Focus(nsIDOMElement *aElement); \
  NS_SCRIPTABLE NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD ProcessUpdates(void); \
  NS_SCRIPTABLE NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, PRUint32 aDirection, double aDelta, PRInt32 aModifiers); \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(float aX, float aY, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMNodeList **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, PRUint32 *aMaxDifference NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIsMozAfterPaintPending(PRBool *aIsMozAfterPaintPending); \
  NS_SCRIPTABLE NS_IMETHOD SuppressEventHandling(PRBool aSuppress); \
  NS_SCRIPTABLE NS_IMETHOD ClearMozAfterPaintEvents(void); \
  NS_SCRIPTABLE NS_IMETHOD DisableNonTestMouseEvents(PRBool aDisable); \
  NS_SCRIPTABLE NS_IMETHOD GetScrollXY(PRBool aFlushLayout, PRInt32 *aScrollX NS_OUTPARAM, PRInt32 *aScrollY NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetIMEIsOpen(PRBool *aIMEIsOpen); \
  NS_SCRIPTABLE NS_IMETHOD GetIMEStatus(PRUint32 *aIMEStatus); \
  NS_SCRIPTABLE NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel); \
  NS_SCRIPTABLE NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, PRBool aTrusted, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetClassName(char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable); \
  NS_SCRIPTABLE NS_IMETHOD SendCompositionEvent(const nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SendTextEvent(const nsAString & aCompositionString, PRInt32 aFirstClauseLength, PRUint32 aFirstClauseAttr, PRInt32 aSecondClauseLength, PRUint32 aSecondClauseAttr, PRInt32 aThirdClauseLength, PRUint32 aThirdClauseAttr, PRInt32 aCaretStart, PRInt32 aCaretLength); \
  NS_SCRIPTABLE NS_IMETHOD SendQueryContentEvent(PRUint32 aType, PRUint32 aOffset, PRUint32 aLength, PRInt32 aX, PRInt32 aY, nsIQueryContentEventResult **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SendSelectionSetEvent(PRUint32 aOffset, PRUint32 aLength, PRBool aReverse, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetParent(void); \
  NS_SCRIPTABLE NS_IMETHOD GetOuterWindowID(PRUint64 *aOuterWindowID); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentInnerWindowID(PRUint64 *aCurrentInnerWindowID); \
  NS_IMETHOD EnterModalState(void); \
  NS_IMETHOD LeaveModalState(void); \
  NS_IMETHOD IsInModalState(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SuspendTimeouts(void); \
  NS_SCRIPTABLE NS_IMETHOD ResumeTimeouts(void); \
  NS_SCRIPTABLE NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType); \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayDPI(float *aDisplayDPI); \
  NS_SCRIPTABLE NS_IMETHOD GetOuterWindowWithId(PRUint64 aOuterWindowID, nsIDOMWindow **_retval NS_OUTPARAM); \
  NS_IMETHOD RenderDocument(const nsRect & aRect, PRUint32 aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext); \
  NS_SCRIPTABLE NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOWUTILS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImageAnimationMode(PRUint16 *aImageAnimationMode) { return _to GetImageAnimationMode(aImageAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetImageAnimationMode(PRUint16 aImageAnimationMode) { return _to SetImageAnimationMode(aImageAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocCharsetIsForced(PRBool *aDocCharsetIsForced) { return _to GetDocCharsetIsForced(aDocCharsetIsForced); } \
  NS_SCRIPTABLE NS_IMETHOD GetCursorType(PRInt16 *_retval NS_OUTPARAM) { return _to GetCursorType(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval NS_OUTPARAM) { return _to GetDocumentMetadata(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Redraw(PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) { return _to Redraw(aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx) { return _to SetCSSViewport(aWidthPx, aHeightPx); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisplayPort(float aXPx, float aYPx, float aWidthPx, float aHeightPx) { return _to SetDisplayPort(aXPx, aYPx, aWidthPx, aHeightPx); } \
  NS_SCRIPTABLE NS_IMETHOD SetResolution(float aXResolution, float aYResolution) { return _to SetResolution(aXResolution, aYResolution); } \
  NS_SCRIPTABLE NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame) { return _to SendMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame); } \
  NS_SCRIPTABLE NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame) { return _to SendMouseEventToWindow(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame); } \
  NS_SCRIPTABLE NS_IMETHOD SendMouseScrollEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aScrollFlags, PRInt32 aDelta, PRInt32 aModifiers) { return _to SendMouseScrollEvent(aType, aX, aY, aButton, aScrollFlags, aDelta, aModifiers); } \
  NS_SCRIPTABLE NS_IMETHOD SendKeyEvent(const nsAString & aType, PRInt32 aKeyCode, PRInt32 aCharCode, PRInt32 aModifiers, PRBool aPreventDefault, PRBool *_retval NS_OUTPARAM) { return _to SendKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aPreventDefault, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendNativeKeyEvent(PRInt32 aNativeKeyboardLayout, PRInt32 aNativeKeyCode, PRInt32 aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters) { return _to SendNativeKeyEvent(aNativeKeyboardLayout, aNativeKeyCode, aModifierFlags, aCharacters, aUnmodifiedCharacters); } \
  NS_SCRIPTABLE NS_IMETHOD SendNativeMouseEvent(PRInt32 aScreenX, PRInt32 aScreenY, PRInt32 aNativeMessage, PRInt32 aModifierFlags, nsIDOMElement *aElement) { return _to SendNativeMouseEvent(aScreenX, aScreenY, aNativeMessage, aModifierFlags, aElement); } \
  NS_SCRIPTABLE NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) { return _to ActivateNativeMenuItemAt(indexString); } \
  NS_SCRIPTABLE NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) { return _to ForceUpdateNativeMenuAt(indexString); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(nsIDOMElement *aElement) { return _to Focus(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener) { return _to GarbageCollect(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessUpdates(void) { return _to ProcessUpdates(); } \
  NS_SCRIPTABLE NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, PRUint32 aDirection, double aDelta, PRInt32 aModifiers) { return _to SendSimpleGestureEvent(aType, aX, aY, aDirection, aDelta, aModifiers); } \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(float aX, float aY, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMElement **_retval NS_OUTPARAM) { return _to ElementFromPoint(aX, aY, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMNodeList **_retval NS_OUTPARAM) { return _to NodesFromRect(aX, aY, aTopSize, aRightSize, aBottomSize, aLeftSize, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, PRUint32 *aMaxDifference NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return _to CompareCanvases(aCanvas1, aCanvas2, aMaxDifference, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsMozAfterPaintPending(PRBool *aIsMozAfterPaintPending) { return _to GetIsMozAfterPaintPending(aIsMozAfterPaintPending); } \
  NS_SCRIPTABLE NS_IMETHOD SuppressEventHandling(PRBool aSuppress) { return _to SuppressEventHandling(aSuppress); } \
  NS_SCRIPTABLE NS_IMETHOD ClearMozAfterPaintEvents(void) { return _to ClearMozAfterPaintEvents(); } \
  NS_SCRIPTABLE NS_IMETHOD DisableNonTestMouseEvents(PRBool aDisable) { return _to DisableNonTestMouseEvents(aDisable); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollXY(PRBool aFlushLayout, PRInt32 *aScrollX NS_OUTPARAM, PRInt32 *aScrollY NS_OUTPARAM) { return _to GetScrollXY(aFlushLayout, aScrollX, aScrollY); } \
  NS_SCRIPTABLE NS_IMETHOD GetIMEIsOpen(PRBool *aIMEIsOpen) { return _to GetIMEIsOpen(aIMEIsOpen); } \
  NS_SCRIPTABLE NS_IMETHOD GetIMEStatus(PRUint32 *aIMEStatus) { return _to GetIMEStatus(aIMEStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel) { return _to GetScreenPixelsPerCSSPixel(aScreenPixelsPerCSSPixel); } \
  NS_SCRIPTABLE NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, PRBool aTrusted, PRBool *_retval NS_OUTPARAM) { return _to DispatchDOMEventViaPresShell(aTarget, aEvent, aTrusted, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClassName(char **_retval NS_OUTPARAM) { return _to GetClassName(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable) { return _to SendContentCommandEvent(aType, aTransferable); } \
  NS_SCRIPTABLE NS_IMETHOD SendCompositionEvent(const nsAString & aType) { return _to SendCompositionEvent(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SendTextEvent(const nsAString & aCompositionString, PRInt32 aFirstClauseLength, PRUint32 aFirstClauseAttr, PRInt32 aSecondClauseLength, PRUint32 aSecondClauseAttr, PRInt32 aThirdClauseLength, PRUint32 aThirdClauseAttr, PRInt32 aCaretStart, PRInt32 aCaretLength) { return _to SendTextEvent(aCompositionString, aFirstClauseLength, aFirstClauseAttr, aSecondClauseLength, aSecondClauseAttr, aThirdClauseLength, aThirdClauseAttr, aCaretStart, aCaretLength); } \
  NS_SCRIPTABLE NS_IMETHOD SendQueryContentEvent(PRUint32 aType, PRUint32 aOffset, PRUint32 aLength, PRInt32 aX, PRInt32 aY, nsIQueryContentEventResult **_retval NS_OUTPARAM) { return _to SendQueryContentEvent(aType, aOffset, aLength, aX, aY, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendSelectionSetEvent(PRUint32 aOffset, PRUint32 aLength, PRBool aReverse, PRBool *_retval NS_OUTPARAM) { return _to SendSelectionSetEvent(aOffset, aLength, aReverse, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval NS_OUTPARAM) { return _to GetVisitedDependentComputedStyle(aElement, aPseudoElement, aPropertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParent(void) { return _to GetParent(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOuterWindowID(PRUint64 *aOuterWindowID) { return _to GetOuterWindowID(aOuterWindowID); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentInnerWindowID(PRUint64 *aCurrentInnerWindowID) { return _to GetCurrentInnerWindowID(aCurrentInnerWindowID); } \
  NS_IMETHOD EnterModalState(void) { return _to EnterModalState(); } \
  NS_IMETHOD LeaveModalState(void) { return _to LeaveModalState(); } \
  NS_IMETHOD IsInModalState(PRBool *_retval NS_OUTPARAM) { return _to IsInModalState(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SuspendTimeouts(void) { return _to SuspendTimeouts(); } \
  NS_SCRIPTABLE NS_IMETHOD ResumeTimeouts(void) { return _to ResumeTimeouts(); } \
  NS_SCRIPTABLE NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType) { return _to GetLayerManagerType(aLayerManagerType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayDPI(float *aDisplayDPI) { return _to GetDisplayDPI(aDisplayDPI); } \
  NS_SCRIPTABLE NS_IMETHOD GetOuterWindowWithId(PRUint64 aOuterWindowID, nsIDOMWindow **_retval NS_OUTPARAM) { return _to GetOuterWindowWithId(aOuterWindowID, _retval); } \
  NS_IMETHOD RenderDocument(const nsRect & aRect, PRUint32 aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext) { return _to RenderDocument(aRect, aFlags, aBackgroundColor, aThebesContext); } \
  NS_SCRIPTABLE NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval NS_OUTPARAM) { return _to ComputeAnimationDistance(element, property, value1, value2, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOWUTILS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetImageAnimationMode(PRUint16 *aImageAnimationMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImageAnimationMode(aImageAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD SetImageAnimationMode(PRUint16 aImageAnimationMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImageAnimationMode(aImageAnimationMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocCharsetIsForced(PRBool *aDocCharsetIsForced) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocCharsetIsForced(aDocCharsetIsForced); } \
  NS_SCRIPTABLE NS_IMETHOD GetCursorType(PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCursorType(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocumentMetadata(const nsAString & aName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentMetadata(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Redraw(PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Redraw(aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCSSViewport(float aWidthPx, float aHeightPx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCSSViewport(aWidthPx, aHeightPx); } \
  NS_SCRIPTABLE NS_IMETHOD SetDisplayPort(float aXPx, float aYPx, float aWidthPx, float aHeightPx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplayPort(aXPx, aYPx, aWidthPx, aHeightPx); } \
  NS_SCRIPTABLE NS_IMETHOD SetResolution(float aXResolution, float aYResolution) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResolution(aXResolution, aYResolution); } \
  NS_SCRIPTABLE NS_IMETHOD SendMouseEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMouseEvent(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame); } \
  NS_SCRIPTABLE NS_IMETHOD SendMouseEventToWindow(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMouseEventToWindow(aType, aX, aY, aButton, aClickCount, aModifiers, aIgnoreRootScrollFrame); } \
  NS_SCRIPTABLE NS_IMETHOD SendMouseScrollEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aScrollFlags, PRInt32 aDelta, PRInt32 aModifiers) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMouseScrollEvent(aType, aX, aY, aButton, aScrollFlags, aDelta, aModifiers); } \
  NS_SCRIPTABLE NS_IMETHOD SendKeyEvent(const nsAString & aType, PRInt32 aKeyCode, PRInt32 aCharCode, PRInt32 aModifiers, PRBool aPreventDefault, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendKeyEvent(aType, aKeyCode, aCharCode, aModifiers, aPreventDefault, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendNativeKeyEvent(PRInt32 aNativeKeyboardLayout, PRInt32 aNativeKeyCode, PRInt32 aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeKeyEvent(aNativeKeyboardLayout, aNativeKeyCode, aModifierFlags, aCharacters, aUnmodifiedCharacters); } \
  NS_SCRIPTABLE NS_IMETHOD SendNativeMouseEvent(PRInt32 aScreenX, PRInt32 aScreenY, PRInt32 aNativeMessage, PRInt32 aModifierFlags, nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendNativeMouseEvent(aScreenX, aScreenY, aNativeMessage, aModifierFlags, aElement); } \
  NS_SCRIPTABLE NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & indexString) { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateNativeMenuItemAt(indexString); } \
  NS_SCRIPTABLE NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & indexString) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceUpdateNativeMenuAt(indexString); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(nsIDOMElement *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(aElement); } \
  NS_SCRIPTABLE NS_IMETHOD GarbageCollect(nsICycleCollectorListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GarbageCollect(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessUpdates(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessUpdates(); } \
  NS_SCRIPTABLE NS_IMETHOD SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, PRUint32 aDirection, double aDelta, PRInt32 aModifiers) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSimpleGestureEvent(aType, aX, aY, aDirection, aDelta, aModifiers); } \
  NS_SCRIPTABLE NS_IMETHOD ElementFromPoint(float aX, float aY, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ElementFromPoint(aX, aY, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMNodeList **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NodesFromRect(aX, aY, aTopSize, aRightSize, aBottomSize, aLeftSize, aIgnoreRootScrollFrame, aFlushLayout, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, PRUint32 *aMaxDifference NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareCanvases(aCanvas1, aCanvas2, aMaxDifference, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsMozAfterPaintPending(PRBool *aIsMozAfterPaintPending) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsMozAfterPaintPending(aIsMozAfterPaintPending); } \
  NS_SCRIPTABLE NS_IMETHOD SuppressEventHandling(PRBool aSuppress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SuppressEventHandling(aSuppress); } \
  NS_SCRIPTABLE NS_IMETHOD ClearMozAfterPaintEvents(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearMozAfterPaintEvents(); } \
  NS_SCRIPTABLE NS_IMETHOD DisableNonTestMouseEvents(PRBool aDisable) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableNonTestMouseEvents(aDisable); } \
  NS_SCRIPTABLE NS_IMETHOD GetScrollXY(PRBool aFlushLayout, PRInt32 *aScrollX NS_OUTPARAM, PRInt32 *aScrollY NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrollXY(aFlushLayout, aScrollX, aScrollY); } \
  NS_SCRIPTABLE NS_IMETHOD GetIMEIsOpen(PRBool *aIMEIsOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIMEIsOpen(aIMEIsOpen); } \
  NS_SCRIPTABLE NS_IMETHOD GetIMEStatus(PRUint32 *aIMEStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIMEStatus(aIMEStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenPixelsPerCSSPixel(aScreenPixelsPerCSSPixel); } \
  NS_SCRIPTABLE NS_IMETHOD DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, PRBool aTrusted, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DispatchDOMEventViaPresShell(aTarget, aEvent, aTrusted, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClassName(char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassName(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendContentCommandEvent(aType, aTransferable); } \
  NS_SCRIPTABLE NS_IMETHOD SendCompositionEvent(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendCompositionEvent(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SendTextEvent(const nsAString & aCompositionString, PRInt32 aFirstClauseLength, PRUint32 aFirstClauseAttr, PRInt32 aSecondClauseLength, PRUint32 aSecondClauseAttr, PRInt32 aThirdClauseLength, PRUint32 aThirdClauseAttr, PRInt32 aCaretStart, PRInt32 aCaretLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendTextEvent(aCompositionString, aFirstClauseLength, aFirstClauseAttr, aSecondClauseLength, aSecondClauseAttr, aThirdClauseLength, aThirdClauseAttr, aCaretStart, aCaretLength); } \
  NS_SCRIPTABLE NS_IMETHOD SendQueryContentEvent(PRUint32 aType, PRUint32 aOffset, PRUint32 aLength, PRInt32 aX, PRInt32 aY, nsIQueryContentEventResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendQueryContentEvent(aType, aOffset, aLength, aX, aY, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SendSelectionSetEvent(PRUint32 aOffset, PRUint32 aLength, PRBool aReverse, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSelectionSetEvent(aOffset, aLength, aReverse, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisitedDependentComputedStyle(aElement, aPseudoElement, aPropertyName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetParent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(); } \
  NS_SCRIPTABLE NS_IMETHOD GetOuterWindowID(PRUint64 *aOuterWindowID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWindowID(aOuterWindowID); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentInnerWindowID(PRUint64 *aCurrentInnerWindowID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentInnerWindowID(aCurrentInnerWindowID); } \
  NS_IMETHOD EnterModalState(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnterModalState(); } \
  NS_IMETHOD LeaveModalState(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->LeaveModalState(); } \
  NS_IMETHOD IsInModalState(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsInModalState(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SuspendTimeouts(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SuspendTimeouts(); } \
  NS_SCRIPTABLE NS_IMETHOD ResumeTimeouts(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeTimeouts(); } \
  NS_SCRIPTABLE NS_IMETHOD GetLayerManagerType(nsAString & aLayerManagerType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLayerManagerType(aLayerManagerType); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplayDPI(float *aDisplayDPI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayDPI(aDisplayDPI); } \
  NS_SCRIPTABLE NS_IMETHOD GetOuterWindowWithId(PRUint64 aOuterWindowID, nsIDOMWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOuterWindowWithId(aOuterWindowID, _retval); } \
  NS_IMETHOD RenderDocument(const nsRect & aRect, PRUint32 aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->RenderDocument(aRect, aFlags, aBackgroundColor, aThebesContext); } \
  NS_SCRIPTABLE NS_IMETHOD ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ComputeAnimationDistance(element, property, value1, value2, _retval); } 

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
NS_IMETHODIMP nsDOMWindowUtils::GetImageAnimationMode(PRUint16 *aImageAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMWindowUtils::SetImageAnimationMode(PRUint16 aImageAnimationMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean docCharsetIsForced; */
NS_IMETHODIMP nsDOMWindowUtils::GetDocCharsetIsForced(PRBool *aDocCharsetIsForced)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short getCursorType (); */
NS_IMETHODIMP nsDOMWindowUtils::GetCursorType(PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getDocumentMetadata (in AString aName); */
NS_IMETHODIMP nsDOMWindowUtils::GetDocumentMetadata(const nsAString & aName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long redraw ([optional] in unsigned long aCount); */
NS_IMETHODIMP nsDOMWindowUtils::Redraw(PRUint32 aCount, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCSSViewport (in float aWidthPx, in float aHeightPx); */
NS_IMETHODIMP nsDOMWindowUtils::SetCSSViewport(float aWidthPx, float aHeightPx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setDisplayPort (in float aXPx, in float aYPx, in float aWidthPx, in float aHeightPx); */
NS_IMETHODIMP nsDOMWindowUtils::SetDisplayPort(float aXPx, float aYPx, float aWidthPx, float aHeightPx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setResolution (in float aXResolution, in float aYResolution); */
NS_IMETHODIMP nsDOMWindowUtils::SetResolution(float aXResolution, float aYResolution)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendMouseEvent (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
NS_IMETHODIMP nsDOMWindowUtils::SendMouseEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendMouseEventToWindow (in AString aType, in float aX, in float aY, in long aButton, in long aClickCount, in long aModifiers, [optional] in boolean aIgnoreRootScrollFrame); */
NS_IMETHODIMP nsDOMWindowUtils::SendMouseEventToWindow(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aClickCount, PRInt32 aModifiers, PRBool aIgnoreRootScrollFrame)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendMouseScrollEvent (in AString aType, in float aX, in float aY, in long aButton, in long aScrollFlags, in long aDelta, in long aModifiers); */
NS_IMETHODIMP nsDOMWindowUtils::SendMouseScrollEvent(const nsAString & aType, float aX, float aY, PRInt32 aButton, PRInt32 aScrollFlags, PRInt32 aDelta, PRInt32 aModifiers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendKeyEvent (in AString aType, in long aKeyCode, in long aCharCode, in long aModifiers, [optional] in boolean aPreventDefault); */
NS_IMETHODIMP nsDOMWindowUtils::SendKeyEvent(const nsAString & aType, PRInt32 aKeyCode, PRInt32 aCharCode, PRInt32 aModifiers, PRBool aPreventDefault, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeKeyEvent (in long aNativeKeyboardLayout, in long aNativeKeyCode, in long aModifierFlags, in AString aCharacters, in AString aUnmodifiedCharacters); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeKeyEvent(PRInt32 aNativeKeyboardLayout, PRInt32 aNativeKeyCode, PRInt32 aModifierFlags, const nsAString & aCharacters, const nsAString & aUnmodifiedCharacters)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendNativeMouseEvent (in long aScreenX, in long aScreenY, in long aNativeMessage, in long aModifierFlags, in nsIDOMElement aElement); */
NS_IMETHODIMP nsDOMWindowUtils::SendNativeMouseEvent(PRInt32 aScreenX, PRInt32 aScreenY, PRInt32 aNativeMessage, PRInt32 aModifierFlags, nsIDOMElement *aElement)
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

/* void garbageCollect ([optional] in nsICycleCollectorListener aListener); */
NS_IMETHODIMP nsDOMWindowUtils::GarbageCollect(nsICycleCollectorListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void processUpdates (); */
NS_IMETHODIMP nsDOMWindowUtils::ProcessUpdates()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendSimpleGestureEvent (in AString aType, in float aX, in float aY, in unsigned long aDirection, in double aDelta, in long aModifiers); */
NS_IMETHODIMP nsDOMWindowUtils::SendSimpleGestureEvent(const nsAString & aType, float aX, float aY, PRUint32 aDirection, double aDelta, PRInt32 aModifiers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement elementFromPoint (in float aX, in float aY, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
NS_IMETHODIMP nsDOMWindowUtils::ElementFromPoint(float aX, float aY, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList nodesFromRect (in float aX, in float aY, in float aTopSize, in float aRightSize, in float aBottomSize, in float aLeftSize, in boolean aIgnoreRootScrollFrame, in boolean aFlushLayout); */
NS_IMETHODIMP nsDOMWindowUtils::NodesFromRect(float aX, float aY, float aTopSize, float aRightSize, float aBottomSize, float aLeftSize, PRBool aIgnoreRootScrollFrame, PRBool aFlushLayout, nsIDOMNodeList **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint32 compareCanvases (in nsIDOMHTMLCanvasElement aCanvas1, in nsIDOMHTMLCanvasElement aCanvas2, out unsigned long aMaxDifference); */
NS_IMETHODIMP nsDOMWindowUtils::CompareCanvases(nsIDOMHTMLCanvasElement *aCanvas1, nsIDOMHTMLCanvasElement *aCanvas2, PRUint32 *aMaxDifference NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isMozAfterPaintPending; */
NS_IMETHODIMP nsDOMWindowUtils::GetIsMozAfterPaintPending(PRBool *aIsMozAfterPaintPending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suppressEventHandling (in boolean aSuppress); */
NS_IMETHODIMP nsDOMWindowUtils::SuppressEventHandling(PRBool aSuppress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearMozAfterPaintEvents (); */
NS_IMETHODIMP nsDOMWindowUtils::ClearMozAfterPaintEvents()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableNonTestMouseEvents (in boolean aDisable); */
NS_IMETHODIMP nsDOMWindowUtils::DisableNonTestMouseEvents(PRBool aDisable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getScrollXY (in boolean aFlushLayout, out long aScrollX, out long aScrollY); */
NS_IMETHODIMP nsDOMWindowUtils::GetScrollXY(PRBool aFlushLayout, PRInt32 *aScrollX NS_OUTPARAM, PRInt32 *aScrollY NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean IMEIsOpen; */
NS_IMETHODIMP nsDOMWindowUtils::GetIMEIsOpen(PRBool *aIMEIsOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long IMEStatus; */
NS_IMETHODIMP nsDOMWindowUtils::GetIMEStatus(PRUint32 *aIMEStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float screenPixelsPerCSSPixel; */
NS_IMETHODIMP nsDOMWindowUtils::GetScreenPixelsPerCSSPixel(float *aScreenPixelsPerCSSPixel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean dispatchDOMEventViaPresShell (in nsIDOMNode aTarget, in nsIDOMEvent aEvent, in boolean aTrusted); */
NS_IMETHODIMP nsDOMWindowUtils::DispatchDOMEventViaPresShell(nsIDOMNode *aTarget, nsIDOMEvent *aEvent, PRBool aTrusted, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string getClassName (); */
NS_IMETHODIMP nsDOMWindowUtils::GetClassName(char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendContentCommandEvent (in AString aType, [optional] in nsITransferable aTransferable); */
NS_IMETHODIMP nsDOMWindowUtils::SendContentCommandEvent(const nsAString & aType, nsITransferable *aTransferable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendCompositionEvent (in AString aType); */
NS_IMETHODIMP nsDOMWindowUtils::SendCompositionEvent(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendTextEvent (in AString aCompositionString, in long aFirstClauseLength, in unsigned long aFirstClauseAttr, in long aSecondClauseLength, in unsigned long aSecondClauseAttr, in long aThirdClauseLength, in unsigned long aThirdClauseAttr, in long aCaretStart, in long aCaretLength); */
NS_IMETHODIMP nsDOMWindowUtils::SendTextEvent(const nsAString & aCompositionString, PRInt32 aFirstClauseLength, PRUint32 aFirstClauseAttr, PRInt32 aSecondClauseLength, PRUint32 aSecondClauseAttr, PRInt32 aThirdClauseLength, PRUint32 aThirdClauseAttr, PRInt32 aCaretStart, PRInt32 aCaretLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIQueryContentEventResult sendQueryContentEvent (in unsigned long aType, in unsigned long aOffset, in unsigned long aLength, in long aX, in long aY); */
NS_IMETHODIMP nsDOMWindowUtils::SendQueryContentEvent(PRUint32 aType, PRUint32 aOffset, PRUint32 aLength, PRInt32 aX, PRInt32 aY, nsIQueryContentEventResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean sendSelectionSetEvent (in unsigned long aOffset, in unsigned long aLength, in boolean aReverse); */
NS_IMETHODIMP nsDOMWindowUtils::SendSelectionSetEvent(PRUint32 aOffset, PRUint32 aLength, PRBool aReverse, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getVisitedDependentComputedStyle (in nsIDOMElement aElement, in AString aPseudoElement, in AString aPropertyName); */
NS_IMETHODIMP nsDOMWindowUtils::GetVisitedDependentComputedStyle(nsIDOMElement *aElement, const nsAString & aPseudoElement, const nsAString & aPropertyName, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getParent (); */
NS_IMETHODIMP nsDOMWindowUtils::GetParent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long outerWindowID; */
NS_IMETHODIMP nsDOMWindowUtils::GetOuterWindowID(PRUint64 *aOuterWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long currentInnerWindowID; */
NS_IMETHODIMP nsDOMWindowUtils::GetCurrentInnerWindowID(PRUint64 *aCurrentInnerWindowID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void enterModalState (); */
NS_IMETHODIMP nsDOMWindowUtils::EnterModalState()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void leaveModalState (); */
NS_IMETHODIMP nsDOMWindowUtils::LeaveModalState()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] boolean isInModalState (); */
NS_IMETHODIMP nsDOMWindowUtils::IsInModalState(PRBool *_retval NS_OUTPARAM)
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

/* readonly attribute float displayDPI; */
NS_IMETHODIMP nsDOMWindowUtils::GetDisplayDPI(float *aDisplayDPI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow getOuterWindowWithId (in unsigned long long aOuterWindowID); */
NS_IMETHODIMP nsDOMWindowUtils::GetOuterWindowWithId(PRUint64 aOuterWindowID, nsIDOMWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void RenderDocument (in nsConstRect aRect, in PRUint32 aFlags, in nscolor aBackgroundColor, in gfxContext aThebesContext); */
NS_IMETHODIMP nsDOMWindowUtils::RenderDocument(const nsRect & aRect, PRUint32 aFlags, nscolor aBackgroundColor, gfxContext *aThebesContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* double computeAnimationDistance (in nsIDOMElement element, in AString property, in AString value1, in AString value2); */
NS_IMETHODIMP nsDOMWindowUtils::ComputeAnimationDistance(nsIDOMElement *element, const nsAString & property, const nsAString & value1, const nsAString & value2, double *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

typedef PRUint64  nsViewID;


/* starting interface:    nsIDOMWindowUtils_MOZILLA_2_0_BRANCH */
#define NS_IDOMWINDOWUTILS_MOZILLA_2_0_BRANCH_IID_STR "be2e28c8-64f8-4100-906d-8a451ddd6835"

#define NS_IDOMWINDOWUTILS_MOZILLA_2_0_BRANCH_IID \
  {0xbe2e28c8, 0x64f8, 0x4100, \
    { 0x90, 0x6d, 0x8a, 0x45, 0x1d, 0xdd, 0x68, 0x35 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMWindowUtils_MOZILLA_2_0_BRANCH : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOWUTILS_MOZILLA_2_0_BRANCH_IID)

  /**
   * Get the type of the currently focused html input, if any.
   */
  /* readonly attribute string focusedInputType; */
  NS_SCRIPTABLE NS_IMETHOD GetFocusedInputType(char **aFocusedInputType) = 0;

  /**
   * Given a view ID from the compositor process, retrieve the element
   * associated with a view. For scrollpanes for documents, the root
   * element of the document is returned.
   */
  /* nsIDOMElement findElementWithViewId (in nsViewID aId); */
  NS_SCRIPTABLE NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /**
   * Same as enterModalState, but returns the window associated with the
   * current JS context.
   */
  /* nsIDOMWindow enterModalStateWithWindow (); */
  NS_SCRIPTABLE NS_IMETHOD EnterModalStateWithWindow(nsIDOMWindow **_retval NS_OUTPARAM) = 0;

  /**
   * Same as leaveModalState, but takes a window associated with the active
   * context when enterModalStateWithWindow was called. The currently context
   * might be different at the moment (see bug 621764).
   */
  /* void leaveModalStateWithWindow (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD LeaveModalStateWithWindow(nsIDOMWindow *aWindow) = 0;

  /**
   * Checks the layer tree for this window and returns true
   * if all layers have transforms that are translations by integers,
   * no leaf layers overlap, and the union of the leaf layers is exactly
   * the bounds of the window. Always returns true in non-DEBUG builds.
   */
  /* boolean leafLayersPartitionWindow (); */
  NS_SCRIPTABLE NS_IMETHOD LeafLayersPartitionWindow(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindowUtils_MOZILLA_2_0_BRANCH, NS_IDOMWINDOWUTILS_MOZILLA_2_0_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOWUTILS_MOZILLA_2_0_BRANCH \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedInputType(char **aFocusedInputType); \
  NS_SCRIPTABLE NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD EnterModalStateWithWindow(nsIDOMWindow **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LeaveModalStateWithWindow(nsIDOMWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD LeafLayersPartitionWindow(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOWUTILS_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedInputType(char **aFocusedInputType) { return _to GetFocusedInputType(aFocusedInputType); } \
  NS_SCRIPTABLE NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement **_retval NS_OUTPARAM) { return _to FindElementWithViewId(aId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnterModalStateWithWindow(nsIDOMWindow **_retval NS_OUTPARAM) { return _to EnterModalStateWithWindow(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD LeaveModalStateWithWindow(nsIDOMWindow *aWindow) { return _to LeaveModalStateWithWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD LeafLayersPartitionWindow(PRBool *_retval NS_OUTPARAM) { return _to LeafLayersPartitionWindow(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOWUTILS_MOZILLA_2_0_BRANCH(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedInputType(char **aFocusedInputType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedInputType(aFocusedInputType); } \
  NS_SCRIPTABLE NS_IMETHOD FindElementWithViewId(nsViewID aId, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindElementWithViewId(aId, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD EnterModalStateWithWindow(nsIDOMWindow **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnterModalStateWithWindow(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD LeaveModalStateWithWindow(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->LeaveModalStateWithWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD LeafLayersPartitionWindow(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->LeafLayersPartitionWindow(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindowUtils_MOZILLA_2_0_BRANCH : public nsIDOMWindowUtils_MOZILLA_2_0_BRANCH
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOWUTILS_MOZILLA_2_0_BRANCH

  nsDOMWindowUtils_MOZILLA_2_0_BRANCH();

private:
  ~nsDOMWindowUtils_MOZILLA_2_0_BRANCH();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWindowUtils_MOZILLA_2_0_BRANCH, nsIDOMWindowUtils_MOZILLA_2_0_BRANCH)

nsDOMWindowUtils_MOZILLA_2_0_BRANCH::nsDOMWindowUtils_MOZILLA_2_0_BRANCH()
{
  /* member initializers and constructor code */
}

nsDOMWindowUtils_MOZILLA_2_0_BRANCH::~nsDOMWindowUtils_MOZILLA_2_0_BRANCH()
{
  /* destructor code */
}

/* readonly attribute string focusedInputType; */
NS_IMETHODIMP nsDOMWindowUtils_MOZILLA_2_0_BRANCH::GetFocusedInputType(char **aFocusedInputType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement findElementWithViewId (in nsViewID aId); */
NS_IMETHODIMP nsDOMWindowUtils_MOZILLA_2_0_BRANCH::FindElementWithViewId(nsViewID aId, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow enterModalStateWithWindow (); */
NS_IMETHODIMP nsDOMWindowUtils_MOZILLA_2_0_BRANCH::EnterModalStateWithWindow(nsIDOMWindow **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void leaveModalStateWithWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsDOMWindowUtils_MOZILLA_2_0_BRANCH::LeaveModalStateWithWindow(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean leafLayersPartitionWindow (); */
NS_IMETHODIMP nsDOMWindowUtils_MOZILLA_2_0_BRANCH::LeafLayersPartitionWindow(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWindowUtils_h__ */
