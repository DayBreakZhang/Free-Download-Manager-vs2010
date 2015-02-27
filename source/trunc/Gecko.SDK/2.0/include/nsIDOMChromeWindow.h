/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/base/nsIDOMChromeWindow.idl
 */

#ifndef __gen_nsIDOMChromeWindow_h__
#define __gen_nsIDOMChromeWindow_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIBrowserDOMWindow; /* forward declaration */

class nsIDOMElement; /* forward declaration */

class nsIDOMEvent; /* forward declaration */

class nsIChromeFrameMessageManager; /* forward declaration */


/* starting interface:    nsIDOMChromeWindow */
#define NS_IDOMCHROMEWINDOW_IID_STR "ec38cbaf-372f-4874-bc7a-dbf1f0b3d755"

#define NS_IDOMCHROMEWINDOW_IID \
  {0xec38cbaf, 0x372f, 0x4874, \
    { 0xbc, 0x7a, 0xdb, 0xf1, 0xf0, 0xb3, 0xd7, 0x55 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMChromeWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMCHROMEWINDOW_IID)

  enum { STATE_MAXIMIZED = 1U };

  enum { STATE_MINIMIZED = 2U };

  enum { STATE_NORMAL = 3U };

  enum { STATE_FULLSCREEN = 4U };

  /* readonly attribute unsigned short windowState; */
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(PRUint16 *aWindowState) = 0;

  /**
   * browserDOMWindow provides access to yet another layer of
   * utility functions implemented by chrome script. It will be null
   * for DOMWindows not corresponding to browsers.
   */
  /* attribute nsIBrowserDOMWindow browserDOMWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow **aBrowserDOMWindow) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow *aBrowserDOMWindow) = 0;

  /* void getAttention (); */
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void) = 0;

  /* void getAttentionWithCycleCount (in long aCycleCount); */
  NS_SCRIPTABLE NS_IMETHOD GetAttentionWithCycleCount(PRInt32 aCycleCount) = 0;

  /* void setCursor (in DOMString cursor); */
  NS_SCRIPTABLE NS_IMETHOD SetCursor(const nsAString & cursor) = 0;

  /* void maximize (); */
  NS_SCRIPTABLE NS_IMETHOD Maximize(void) = 0;

  /* void minimize (); */
  NS_SCRIPTABLE NS_IMETHOD Minimize(void) = 0;

  /* void restore (); */
  NS_SCRIPTABLE NS_IMETHOD Restore(void) = 0;

  /**
   * Notify a default button is loaded on a dialog or a wizard.
   * defaultButton is the default button.
   */
  /* void notifyDefaultButtonLoaded (in nsIDOMElement defaultButton); */
  NS_SCRIPTABLE NS_IMETHOD NotifyDefaultButtonLoaded(nsIDOMElement *defaultButton) = 0;

  /* readonly attribute nsIChromeFrameMessageManager messageManager; */
  NS_SCRIPTABLE NS_IMETHOD GetMessageManager(nsIChromeFrameMessageManager **aMessageManager) = 0;

  /**
   * On some operating systems, we must allow the window manager to
   * handle window dragging. This function tells the window manager to
   * start dragging the window. This function will fail unless called
   * while the left mouse button is held down, callers must check this.
   *
   * Returns NS_ERROR_NOT_IMPLEMENTED (and thus throws in JS) if the OS
   * doesn't support this.
   */
  /* void beginWindowMove (in nsIDOMEvent mouseDownEvent); */
  NS_SCRIPTABLE NS_IMETHOD BeginWindowMove(nsIDOMEvent *mouseDownEvent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMChromeWindow, NS_IDOMCHROMEWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMCHROMEWINDOW \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(PRUint16 *aWindowState); \
  NS_SCRIPTABLE NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow **aBrowserDOMWindow); \
  NS_SCRIPTABLE NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow *aBrowserDOMWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void); \
  NS_SCRIPTABLE NS_IMETHOD GetAttentionWithCycleCount(PRInt32 aCycleCount); \
  NS_SCRIPTABLE NS_IMETHOD SetCursor(const nsAString & cursor); \
  NS_SCRIPTABLE NS_IMETHOD Maximize(void); \
  NS_SCRIPTABLE NS_IMETHOD Minimize(void); \
  NS_SCRIPTABLE NS_IMETHOD Restore(void); \
  NS_SCRIPTABLE NS_IMETHOD NotifyDefaultButtonLoaded(nsIDOMElement *defaultButton); \
  NS_SCRIPTABLE NS_IMETHOD GetMessageManager(nsIChromeFrameMessageManager **aMessageManager); \
  NS_SCRIPTABLE NS_IMETHOD BeginWindowMove(nsIDOMEvent *mouseDownEvent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMCHROMEWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(PRUint16 *aWindowState) { return _to GetWindowState(aWindowState); } \
  NS_SCRIPTABLE NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow **aBrowserDOMWindow) { return _to GetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow *aBrowserDOMWindow) { return _to SetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void) { return _to GetAttention(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttentionWithCycleCount(PRInt32 aCycleCount) { return _to GetAttentionWithCycleCount(aCycleCount); } \
  NS_SCRIPTABLE NS_IMETHOD SetCursor(const nsAString & cursor) { return _to SetCursor(cursor); } \
  NS_SCRIPTABLE NS_IMETHOD Maximize(void) { return _to Maximize(); } \
  NS_SCRIPTABLE NS_IMETHOD Minimize(void) { return _to Minimize(); } \
  NS_SCRIPTABLE NS_IMETHOD Restore(void) { return _to Restore(); } \
  NS_SCRIPTABLE NS_IMETHOD NotifyDefaultButtonLoaded(nsIDOMElement *defaultButton) { return _to NotifyDefaultButtonLoaded(defaultButton); } \
  NS_SCRIPTABLE NS_IMETHOD GetMessageManager(nsIChromeFrameMessageManager **aMessageManager) { return _to GetMessageManager(aMessageManager); } \
  NS_SCRIPTABLE NS_IMETHOD BeginWindowMove(nsIDOMEvent *mouseDownEvent) { return _to BeginWindowMove(mouseDownEvent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMCHROMEWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(PRUint16 *aWindowState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowState(aWindowState); } \
  NS_SCRIPTABLE NS_IMETHOD GetBrowserDOMWindow(nsIBrowserDOMWindow **aBrowserDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_SCRIPTABLE NS_IMETHOD SetBrowserDOMWindow(nsIBrowserDOMWindow *aBrowserDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBrowserDOMWindow(aBrowserDOMWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttention(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttention(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAttentionWithCycleCount(PRInt32 aCycleCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttentionWithCycleCount(aCycleCount); } \
  NS_SCRIPTABLE NS_IMETHOD SetCursor(const nsAString & cursor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCursor(cursor); } \
  NS_SCRIPTABLE NS_IMETHOD Maximize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Maximize(); } \
  NS_SCRIPTABLE NS_IMETHOD Minimize(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Minimize(); } \
  NS_SCRIPTABLE NS_IMETHOD Restore(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Restore(); } \
  NS_SCRIPTABLE NS_IMETHOD NotifyDefaultButtonLoaded(nsIDOMElement *defaultButton) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDefaultButtonLoaded(defaultButton); } \
  NS_SCRIPTABLE NS_IMETHOD GetMessageManager(nsIChromeFrameMessageManager **aMessageManager) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageManager(aMessageManager); } \
  NS_SCRIPTABLE NS_IMETHOD BeginWindowMove(nsIDOMEvent *mouseDownEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginWindowMove(mouseDownEvent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMChromeWindow : public nsIDOMChromeWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMCHROMEWINDOW

  nsDOMChromeWindow();

private:
  ~nsDOMChromeWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMChromeWindow, nsIDOMChromeWindow)

nsDOMChromeWindow::nsDOMChromeWindow()
{
  /* member initializers and constructor code */
}

nsDOMChromeWindow::~nsDOMChromeWindow()
{
  /* destructor code */
}

/* readonly attribute unsigned short windowState; */
NS_IMETHODIMP nsDOMChromeWindow::GetWindowState(PRUint16 *aWindowState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIBrowserDOMWindow browserDOMWindow; */
NS_IMETHODIMP nsDOMChromeWindow::GetBrowserDOMWindow(nsIBrowserDOMWindow **aBrowserDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMChromeWindow::SetBrowserDOMWindow(nsIBrowserDOMWindow *aBrowserDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAttention (); */
NS_IMETHODIMP nsDOMChromeWindow::GetAttention()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAttentionWithCycleCount (in long aCycleCount); */
NS_IMETHODIMP nsDOMChromeWindow::GetAttentionWithCycleCount(PRInt32 aCycleCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCursor (in DOMString cursor); */
NS_IMETHODIMP nsDOMChromeWindow::SetCursor(const nsAString & cursor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void maximize (); */
NS_IMETHODIMP nsDOMChromeWindow::Maximize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void minimize (); */
NS_IMETHODIMP nsDOMChromeWindow::Minimize()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restore (); */
NS_IMETHODIMP nsDOMChromeWindow::Restore()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDefaultButtonLoaded (in nsIDOMElement defaultButton); */
NS_IMETHODIMP nsDOMChromeWindow::NotifyDefaultButtonLoaded(nsIDOMElement *defaultButton)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIChromeFrameMessageManager messageManager; */
NS_IMETHODIMP nsDOMChromeWindow::GetMessageManager(nsIChromeFrameMessageManager **aMessageManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginWindowMove (in nsIDOMEvent mouseDownEvent); */
NS_IMETHODIMP nsDOMChromeWindow::BeginWindowMove(nsIDOMEvent *mouseDownEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMChromeWindow_h__ */
