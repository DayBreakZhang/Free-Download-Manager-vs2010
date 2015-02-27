/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBrowserDOMWindow.idl
 */

#ifndef __gen_nsIBrowserDOMWindow_h__
#define __gen_nsIBrowserDOMWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIFrameLoaderOwner; /* forward declaration */


/* starting interface:    nsIBrowserDOMWindow */
#define NS_IBROWSERDOMWINDOW_IID_STR "e420bd32-b8c4-4b47-8cca-09e0bddbb0c3"

#define NS_IBROWSERDOMWINDOW_IID \
  {0xe420bd32, 0xb8c4, 0x4b47, \
    { 0x8c, 0xca, 0x09, 0xe0, 0xbd, 0xdb, 0xb0, 0xc3 }}

class NS_NO_VTABLE nsIBrowserDOMWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERDOMWINDOW_IID)

  enum {
    OPEN_DEFAULTWINDOW = 0,
    OPEN_CURRENTWINDOW = 1,
    OPEN_NEWWINDOW = 2,
    OPEN_NEWTAB = 3,
    OPEN_SWITCHTAB = 4,
    OPEN_EXTERNAL = 1,
    OPEN_NEW = 2
  };

  /* nsIDOMWindow openURI (in nsIURI aURI, in nsIDOMWindow aOpener, in short aWhere, in short aContext); */
  NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIDOMWindow * *_retval) = 0;

  /* nsIFrameLoaderOwner openURIInFrame (in nsIURI aURI, in nsIDOMWindow aOpener, in short aWhere, in short aContext); */
  NS_IMETHOD OpenURIInFrame(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIFrameLoaderOwner * *_retval) = 0;

  /* boolean isTabContentWindow (in nsIDOMWindow aWindow); */
  NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, bool *_retval) = 0;

  /* readonly attribute jsval contentWindow; */
  NS_IMETHOD GetContentWindow(JS::MutableHandleValue aContentWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserDOMWindow, NS_IBROWSERDOMWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERDOMWINDOW \
  NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIDOMWindow * *_retval); \
  NS_IMETHOD OpenURIInFrame(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIFrameLoaderOwner * *_retval); \
  NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, bool *_retval); \
  NS_IMETHOD GetContentWindow(JS::MutableHandleValue aContentWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERDOMWINDOW(_to) \
  NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIDOMWindow * *_retval) { return _to OpenURI(aURI, aOpener, aWhere, aContext, _retval); } \
  NS_IMETHOD OpenURIInFrame(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIFrameLoaderOwner * *_retval) { return _to OpenURIInFrame(aURI, aOpener, aWhere, aContext, _retval); } \
  NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, bool *_retval) { return _to IsTabContentWindow(aWindow, _retval); } \
  NS_IMETHOD GetContentWindow(JS::MutableHandleValue aContentWindow) { return _to GetContentWindow(aContentWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERDOMWINDOW(_to) \
  NS_IMETHOD OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenURI(aURI, aOpener, aWhere, aContext, _retval); } \
  NS_IMETHOD OpenURIInFrame(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIFrameLoaderOwner * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenURIInFrame(aURI, aOpener, aWhere, aContext, _retval); } \
  NS_IMETHOD IsTabContentWindow(nsIDOMWindow *aWindow, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsTabContentWindow(aWindow, _retval); } \
  NS_IMETHOD GetContentWindow(JS::MutableHandleValue aContentWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentWindow(aContentWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserDOMWindow : public nsIBrowserDOMWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERDOMWINDOW

  nsBrowserDOMWindow();

private:
  ~nsBrowserDOMWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserDOMWindow, nsIBrowserDOMWindow)

nsBrowserDOMWindow::nsBrowserDOMWindow()
{
  /* member initializers and constructor code */
}

nsBrowserDOMWindow::~nsBrowserDOMWindow()
{
  /* destructor code */
}

/* nsIDOMWindow openURI (in nsIURI aURI, in nsIDOMWindow aOpener, in short aWhere, in short aContext); */
NS_IMETHODIMP nsBrowserDOMWindow::OpenURI(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFrameLoaderOwner openURIInFrame (in nsIURI aURI, in nsIDOMWindow aOpener, in short aWhere, in short aContext); */
NS_IMETHODIMP nsBrowserDOMWindow::OpenURIInFrame(nsIURI *aURI, nsIDOMWindow *aOpener, int16_t aWhere, int16_t aContext, nsIFrameLoaderOwner * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isTabContentWindow (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsBrowserDOMWindow::IsTabContentWindow(nsIDOMWindow *aWindow, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval contentWindow; */
NS_IMETHODIMP nsBrowserDOMWindow::GetContentWindow(JS::MutableHandleValue aContentWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserDOMWindow_h__ */
