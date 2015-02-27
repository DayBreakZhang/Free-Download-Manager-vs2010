/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/base/nsIFocusManager.idl
 */

#ifndef __gen_nsIFocusManager_h__
#define __gen_nsIFocusManager_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocument; /* forward declaration */

class nsIContent; /* forward declaration */


/* starting interface:    nsIFocusManager */
#define NS_IFOCUSMANAGER_IID_STR "5cb91200-53f6-4d35-989d-1d28ad80a0d4"

#define NS_IFOCUSMANAGER_IID \
  {0x5cb91200, 0x53f6, 0x4d35, \
    { 0x98, 0x9d, 0x1d, 0x28, 0xad, 0x80, 0xa0, 0xd4 }}

/**
 * The focus manager deals with all focus related behaviour. Only one element
 * in the entire application may have the focus at a time; this element
 * receives any keyboard events. While there is only one application-wide
 * focused element, each nsIDOMWindow maintains a reference to the element
 * that would be focused if the window was active.
 *
 * If the window's reference is to a frame element (iframe, browser,
 * editor), then the child window contains the element that is currently
 * focused. If the window's reference is to a root element, then the root is
 * focused. If a window's reference is null, then no element is focused, yet
 * the window is still focused.
 *
 * The blur event is fired on an element when it loses the application focus.
 * After this blur event, if the focus is moving away from a document, two
 * additional blur events are fired on the old document and window containing
 * the focus respectively.
 *
 * When a new document is focused, two focus events are fired on the new
 * document and window respectively. Then the focus event is fired on an
 * element when it gains the application focus.
 *
 * A special case is that the root element may be focused, yet does not
 * receive the element focus and blur events. Instead a focus outline may be
 * drawn around the document.
 *
 * Blur and focus events do not bubble as per the W3C DOM Events spec.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFocusManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFOCUSMANAGER_IID)

  /**
   * The most active (frontmost) window, or null if no window that is part of
   * the application is active. Setting the activeWindow raises it, and
   * focuses the current child window's current element, if any. Setting this
   * to null or to a non-top-level window throws an NS_ERROR_INVALID_ARG
   * exception.
   */
  /* attribute nsIDOMWindow activeWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetActiveWindow(nsIDOMWindow **aActiveWindow) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow) = 0;

  /**
   * The child window within the activeWindow that is focused. This will
   * always be activeWindow, a child window of activeWindow or null if no
   * child window is focused. Setting the focusedWindow changes the focused
   * window and raises the toplevel window it is in. If the current focus
   * within the new focusedWindow is a frame element, then the focusedWindow
   * will actually be set to the child window and the current element within
   * that set as the focused element. This process repeats downwards until a
   * non-frame element is found.
   */
  /* attribute nsIDOMWindow focusedWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetFocusedWindow(nsIDOMWindow **aFocusedWindow) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow) = 0;

  /**
   * The element that is currently focused. This will always be an element
   * within the document loaded in focusedWindow or null if no element in that
   * document is focused.
   */
  /* readonly attribute nsIDOMElement focusedElement; */
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElement(nsIDOMElement **aFocusedElement) = 0;

  /**
   * Returns the method that was used to focus the element in window. This
   * will either be 0, FLAG_BYMOUSE or FLAG_BYKEY. If window is null, then
   * the current focusedWindow will be used by default. This has the result
   * of retrieving the method that was used to focus the currently focused
   * element.
   */
  /* PRUint32 getLastFocusMethod (in nsIDOMWindow window); */
  NS_SCRIPTABLE NS_IMETHOD GetLastFocusMethod(nsIDOMWindow *window, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Changes the focused element reference within the window containing
   * aElement to aElement.
   */
  /* void setFocus (in nsIDOMElement aElement, in unsigned long aFlags); */
  NS_SCRIPTABLE NS_IMETHOD SetFocus(nsIDOMElement *aElement, PRUint32 aFlags) = 0;

  /**
   * Move the focus to another element. If aStartElement is specified, then
   * movement is done relative to aStartElement. If aStartElement is null,
   * then movement is done relative to the currently focused element. If no
   * element is focused, focus the first focusable element within the
   * document (or the last focusable element if aType is MOVEFOCUS_END). This
   * method is equivalent to setting the focusedElement to the new element.
   *
   * Specifying aStartElement and using MOVEFOCUS_LAST is not currently
   * implemented.
   *
   * If no element is found, and aType is either MOVEFOCUS_ROOT or
   * MOVEFOCUS_CARET, then the focus is cleared. If aType is any other value,
   * the focus is not changed.
   *
   * Returns the element that was focused.
   */
  /* nsIDOMElement moveFocus (in nsIDOMWindow aWindow, in nsIDOMElement aStartElement, in unsigned long aType, in unsigned long aFlags); */
  NS_SCRIPTABLE NS_IMETHOD MoveFocus(nsIDOMWindow *aWindow, nsIDOMElement *aStartElement, PRUint32 aType, PRUint32 aFlags, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /**
   * Clears the focused element within aWindow. If the current focusedWindow
   * is a descendant of aWindow, sets the current focusedWindow to aWindow.
   *
   * @throws NS_ERROR_INVALID_ARG if aWindow is null
   */
  /* void clearFocus (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD ClearFocus(nsIDOMWindow *aWindow) = 0;

  /**
   * Returns the currently focused element within aWindow. If aWindow is equal
   * to the current value of focusedWindow, then the returned element will be
   * the application-wide focused element (the value of focusedElement). The
   * return value will be null if no element is focused.
   *
   * If aDeep is true, then child frames are traversed and the return value
   * may be the element within a child descendant window that is focused. If
   * aDeep if false, then the return value will be the frame element if the
   * focus is in a child frame.
   *
   * aFocusedWindow will be set to the currently focused descendant window of
   * aWindow, or to aWindow if aDeep is false. This will be set even if no
   * element is focused.
   *
   * @throws NS_ERROR_INVALID_ARG if aWindow is null
   */
  /* nsIDOMElement getFocusedElementForWindow (in nsIDOMWindow aWindow, in PRBool aDeep, out nsIDOMWindow aFocusedWindow); */
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElementForWindow(nsIDOMWindow *aWindow, PRBool aDeep, nsIDOMWindow **aFocusedWindow NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) = 0;

  /**
   * Moves the selection caret within aWindow to the current focus.
   */
  /* void moveCaretToFocus (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD MoveCaretToFocus(nsIDOMWindow *aWindow) = 0;

  enum { FLAG_RAISE = 1U };

  /**
   * Do not scroll the element to focus into view
   */
  enum { FLAG_NOSCROLL = 2U };

  /**
   * If attempting to change focus in a window that is not focused, do not
   * switch focus to that window. Instead, just update the focus within that
   * window and leave the application focus as is. This flag will have no
   * effect if a child window is focused and an attempt is made to adjust the
   * focus in an ancestor, as the frame must be switched in this case.
   */
  enum { FLAG_NOSWITCHFRAME = 4U };

  /**
   * Focus is changing due to a mouse operation, for instance the mouse was
   * clicked on an element.
   */
  enum { FLAG_BYMOUSE = 4096U };

  /**
   * Focus is changing due to a key operation, for instance pressing the tab
   * key. This flag would normally be passed when MOVEFOCUS_FORWARD or
   * MOVEFOCUS_BACKWARD is used.
   */
  enum { FLAG_BYKEY = 8192U };

  /**
   * Focus is changing due to a call to MoveFocus. This flag will be implied
   * when MoveFocus is called except when one of the other mechanisms (mouse
   * or key) is specified, or when the type is MOVEFOCUS_ROOT or
   * MOVEFOCUS_CARET.
   */
  enum { FLAG_BYMOVEFOCUS = 16384U };

  /**
   * Always show the focus ring or other indicator of focus, regardless of
   * other state.
   */
  enum { FLAG_SHOWRING = 1048576U };

  /** move focus forward one element, used when pressing TAB */
  enum { MOVEFOCUS_FORWARD = 1U };

  /** move focus backward one element, used when pressing Shift+TAB */
  enum { MOVEFOCUS_BACKWARD = 2U };

  /** move focus forward to the next frame document, used when pressing F6 */
  enum { MOVEFOCUS_FORWARDDOC = 3U };

  /** move focus forward to the previous frame document, used when pressing Shift+F6 */
  enum { MOVEFOCUS_BACKWARDDOC = 4U };

  /** move focus to the first focusable element */
  enum { MOVEFOCUS_FIRST = 5U };

  /** move focus to the last focusable element */
  enum { MOVEFOCUS_LAST = 6U };

  /** move focus to the root element in the document */
  enum { MOVEFOCUS_ROOT = 7U };

  /** move focus to a link at the position of the caret. This is a special value used to
   *  focus links as the caret moves over them in caret browsing mode.
   */
  enum { MOVEFOCUS_CARET = 8U };

  /**
   * Called when a window has been raised.
   */
  /* [noscript] void windowRaised (in nsIDOMWindow aWindow); */
  NS_IMETHOD WindowRaised(nsIDOMWindow *aWindow) = 0;

  /**
   * Called when a window has been lowered.
   */
  /* [noscript] void windowLowered (in nsIDOMWindow aWindow); */
  NS_IMETHOD WindowLowered(nsIDOMWindow *aWindow) = 0;

  /**
   * Called when a new document in a window is shown.
   *
   * If aNeedsFocus is true, then focus events are expected to be fired on the
   * window if this window is in the focused window chain.
   */
  /* [noscript] void windowShown (in nsIDOMWindow aWindow, in PRBool aNeedsFocus); */
  NS_IMETHOD WindowShown(nsIDOMWindow *aWindow, PRBool aNeedsFocus) = 0;

  /**
   * Called when a document in a window has been hidden or otherwise can no
   * longer accept focus.
   */
  /* [noscript] void windowHidden (in nsIDOMWindow aWindow); */
  NS_IMETHOD WindowHidden(nsIDOMWindow *aWindow) = 0;

  /**
   * Fire any events that have been delayed due to synchronized actions.
   */
  /* [noscript] void fireDelayedEvents (in nsIDocument aDocument); */
  NS_IMETHOD FireDelayedEvents(nsIDocument *aDocument) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFocusManager, NS_IFOCUSMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFOCUSMANAGER \
  NS_SCRIPTABLE NS_IMETHOD GetActiveWindow(nsIDOMWindow **aActiveWindow); \
  NS_SCRIPTABLE NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedWindow(nsIDOMWindow **aFocusedWindow); \
  NS_SCRIPTABLE NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElement(nsIDOMElement **aFocusedElement); \
  NS_SCRIPTABLE NS_IMETHOD GetLastFocusMethod(nsIDOMWindow *window, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetFocus(nsIDOMElement *aElement, PRUint32 aFlags); \
  NS_SCRIPTABLE NS_IMETHOD MoveFocus(nsIDOMWindow *aWindow, nsIDOMElement *aStartElement, PRUint32 aType, PRUint32 aFlags, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ClearFocus(nsIDOMWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElementForWindow(nsIDOMWindow *aWindow, PRBool aDeep, nsIDOMWindow **aFocusedWindow NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MoveCaretToFocus(nsIDOMWindow *aWindow); \
  NS_IMETHOD WindowRaised(nsIDOMWindow *aWindow); \
  NS_IMETHOD WindowLowered(nsIDOMWindow *aWindow); \
  NS_IMETHOD WindowShown(nsIDOMWindow *aWindow, PRBool aNeedsFocus); \
  NS_IMETHOD WindowHidden(nsIDOMWindow *aWindow); \
  NS_IMETHOD FireDelayedEvents(nsIDocument *aDocument); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFOCUSMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetActiveWindow(nsIDOMWindow **aActiveWindow) { return _to GetActiveWindow(aActiveWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow) { return _to SetActiveWindow(aActiveWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedWindow(nsIDOMWindow **aFocusedWindow) { return _to GetFocusedWindow(aFocusedWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow) { return _to SetFocusedWindow(aFocusedWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElement(nsIDOMElement **aFocusedElement) { return _to GetFocusedElement(aFocusedElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastFocusMethod(nsIDOMWindow *window, PRUint32 *_retval NS_OUTPARAM) { return _to GetLastFocusMethod(window, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFocus(nsIDOMElement *aElement, PRUint32 aFlags) { return _to SetFocus(aElement, aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD MoveFocus(nsIDOMWindow *aWindow, nsIDOMElement *aStartElement, PRUint32 aType, PRUint32 aFlags, nsIDOMElement **_retval NS_OUTPARAM) { return _to MoveFocus(aWindow, aStartElement, aType, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ClearFocus(nsIDOMWindow *aWindow) { return _to ClearFocus(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElementForWindow(nsIDOMWindow *aWindow, PRBool aDeep, nsIDOMWindow **aFocusedWindow NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) { return _to GetFocusedElementForWindow(aWindow, aDeep, aFocusedWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MoveCaretToFocus(nsIDOMWindow *aWindow) { return _to MoveCaretToFocus(aWindow); } \
  NS_IMETHOD WindowRaised(nsIDOMWindow *aWindow) { return _to WindowRaised(aWindow); } \
  NS_IMETHOD WindowLowered(nsIDOMWindow *aWindow) { return _to WindowLowered(aWindow); } \
  NS_IMETHOD WindowShown(nsIDOMWindow *aWindow, PRBool aNeedsFocus) { return _to WindowShown(aWindow, aNeedsFocus); } \
  NS_IMETHOD WindowHidden(nsIDOMWindow *aWindow) { return _to WindowHidden(aWindow); } \
  NS_IMETHOD FireDelayedEvents(nsIDocument *aDocument) { return _to FireDelayedEvents(aDocument); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFOCUSMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetActiveWindow(nsIDOMWindow **aActiveWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveWindow(aActiveWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetActiveWindow(nsIDOMWindow *aActiveWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetActiveWindow(aActiveWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedWindow(nsIDOMWindow **aFocusedWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedWindow(aFocusedWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetFocusedWindow(nsIDOMWindow *aFocusedWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocusedWindow(aFocusedWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElement(nsIDOMElement **aFocusedElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedElement(aFocusedElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetLastFocusMethod(nsIDOMWindow *window, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastFocusMethod(window, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetFocus(nsIDOMElement *aElement, PRUint32 aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFocus(aElement, aFlags); } \
  NS_SCRIPTABLE NS_IMETHOD MoveFocus(nsIDOMWindow *aWindow, nsIDOMElement *aStartElement, PRUint32 aType, PRUint32 aFlags, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveFocus(aWindow, aStartElement, aType, aFlags, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ClearFocus(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearFocus(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetFocusedElementForWindow(nsIDOMWindow *aWindow, PRBool aDeep, nsIDOMWindow **aFocusedWindow NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFocusedElementForWindow(aWindow, aDeep, aFocusedWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MoveCaretToFocus(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveCaretToFocus(aWindow); } \
  NS_IMETHOD WindowRaised(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowRaised(aWindow); } \
  NS_IMETHOD WindowLowered(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowLowered(aWindow); } \
  NS_IMETHOD WindowShown(nsIDOMWindow *aWindow, PRBool aNeedsFocus) { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowShown(aWindow, aNeedsFocus); } \
  NS_IMETHOD WindowHidden(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowHidden(aWindow); } \
  NS_IMETHOD FireDelayedEvents(nsIDocument *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->FireDelayedEvents(aDocument); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFocusManager : public nsIFocusManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFOCUSMANAGER

  nsFocusManager();

private:
  ~nsFocusManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFocusManager, nsIFocusManager)

nsFocusManager::nsFocusManager()
{
  /* member initializers and constructor code */
}

nsFocusManager::~nsFocusManager()
{
  /* destructor code */
}

/* attribute nsIDOMWindow activeWindow; */
NS_IMETHODIMP nsFocusManager::GetActiveWindow(nsIDOMWindow **aActiveWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFocusManager::SetActiveWindow(nsIDOMWindow *aActiveWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMWindow focusedWindow; */
NS_IMETHODIMP nsFocusManager::GetFocusedWindow(nsIDOMWindow **aFocusedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFocusManager::SetFocusedWindow(nsIDOMWindow *aFocusedWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement focusedElement; */
NS_IMETHODIMP nsFocusManager::GetFocusedElement(nsIDOMElement **aFocusedElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* PRUint32 getLastFocusMethod (in nsIDOMWindow window); */
NS_IMETHODIMP nsFocusManager::GetLastFocusMethod(nsIDOMWindow *window, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setFocus (in nsIDOMElement aElement, in unsigned long aFlags); */
NS_IMETHODIMP nsFocusManager::SetFocus(nsIDOMElement *aElement, PRUint32 aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement moveFocus (in nsIDOMWindow aWindow, in nsIDOMElement aStartElement, in unsigned long aType, in unsigned long aFlags); */
NS_IMETHODIMP nsFocusManager::MoveFocus(nsIDOMWindow *aWindow, nsIDOMElement *aStartElement, PRUint32 aType, PRUint32 aFlags, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearFocus (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFocusManager::ClearFocus(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getFocusedElementForWindow (in nsIDOMWindow aWindow, in PRBool aDeep, out nsIDOMWindow aFocusedWindow); */
NS_IMETHODIMP nsFocusManager::GetFocusedElementForWindow(nsIDOMWindow *aWindow, PRBool aDeep, nsIDOMWindow **aFocusedWindow NS_OUTPARAM, nsIDOMElement **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveCaretToFocus (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFocusManager::MoveCaretToFocus(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void windowRaised (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFocusManager::WindowRaised(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void windowLowered (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFocusManager::WindowLowered(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void windowShown (in nsIDOMWindow aWindow, in PRBool aNeedsFocus); */
NS_IMETHODIMP nsFocusManager::WindowShown(nsIDOMWindow *aWindow, PRBool aNeedsFocus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void windowHidden (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsFocusManager::WindowHidden(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void fireDelayedEvents (in nsIDocument aDocument); */
NS_IMETHODIMP nsFocusManager::FireDelayedEvents(nsIDocument *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFocusManager_MOZILLA_2_0_BRANCH */
#define NS_IFOCUSMANAGER_MOZILLA_2_0_BRANCH_IID_STR "94a49833-0f6d-4d9b-b859-990546ad9b8d"

#define NS_IFOCUSMANAGER_MOZILLA_2_0_BRANCH_IID \
  {0x94a49833, 0x0f6d, 0x4d9b, \
    { 0xb8, 0x59, 0x99, 0x05, 0x46, 0xad, 0x9b, 0x8d }}

/**
 * This interface extends nsIFocusManager for the 2.0 branch
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIFocusManager_MOZILLA_2_0_BRANCH : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFOCUSMANAGER_MOZILLA_2_0_BRANCH_IID)

  /**
   * Indicate that a plugin wishes to take the focus. This is similar to a
   * normal focus except that the widget focus is not changed. Updating the
   * widget focus state is the responsibility of the caller.
   */
  /* [noscript] void focusPlugin (in nsIContent aPlugin); */
  NS_IMETHOD FocusPlugin(nsIContent *aPlugin) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFocusManager_MOZILLA_2_0_BRANCH, NS_IFOCUSMANAGER_MOZILLA_2_0_BRANCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFOCUSMANAGER_MOZILLA_2_0_BRANCH \
  NS_IMETHOD FocusPlugin(nsIContent *aPlugin); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFOCUSMANAGER_MOZILLA_2_0_BRANCH(_to) \
  NS_IMETHOD FocusPlugin(nsIContent *aPlugin) { return _to FocusPlugin(aPlugin); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFOCUSMANAGER_MOZILLA_2_0_BRANCH(_to) \
  NS_IMETHOD FocusPlugin(nsIContent *aPlugin) { return !_to ? NS_ERROR_NULL_POINTER : _to->FocusPlugin(aPlugin); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFocusManager_MOZILLA_2_0_BRANCH : public nsIFocusManager_MOZILLA_2_0_BRANCH
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFOCUSMANAGER_MOZILLA_2_0_BRANCH

  nsFocusManager_MOZILLA_2_0_BRANCH();

private:
  ~nsFocusManager_MOZILLA_2_0_BRANCH();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFocusManager_MOZILLA_2_0_BRANCH, nsIFocusManager_MOZILLA_2_0_BRANCH)

nsFocusManager_MOZILLA_2_0_BRANCH::nsFocusManager_MOZILLA_2_0_BRANCH()
{
  /* member initializers and constructor code */
}

nsFocusManager_MOZILLA_2_0_BRANCH::~nsFocusManager_MOZILLA_2_0_BRANCH()
{
  /* destructor code */
}

/* [noscript] void focusPlugin (in nsIContent aPlugin); */
NS_IMETHODIMP nsFocusManager_MOZILLA_2_0_BRANCH::FocusPlugin(nsIContent *aPlugin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFocusManager_h__ */
