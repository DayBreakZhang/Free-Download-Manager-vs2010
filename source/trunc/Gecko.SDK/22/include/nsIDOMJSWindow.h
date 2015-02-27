/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsIDOMJSWindow.idl
 */

#ifndef __gen_nsIDOMJSWindow_h__
#define __gen_nsIDOMJSWindow_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMJSWindow */
#define NS_IDOMJSWINDOW_IID_STR "6652c4d2-6b49-424b-aaf9-91f91006fab7"

#define NS_IDOMJSWINDOW_IID \
  {0x6652c4d2, 0x6b49, 0x424b, \
    { 0xaa, 0xf9, 0x91, 0xf9, 0x10, 0x06, 0xfa, 0xb7 }}

class NS_NO_VTABLE nsIDOMJSWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMJSWINDOW_IID)

  /* void dump (in DOMString str); */
  NS_IMETHOD Dump(const nsAString & str) = 0;

  /* long setTimeout (); */
  NS_IMETHOD SetTimeout(int32_t *_retval) = 0;

  /* long setInterval (); */
  NS_IMETHOD SetInterval(int32_t *_retval) = 0;

  /* void clearTimeout ([optional] in long handle); */
  NS_IMETHOD ClearTimeout(int32_t handle) = 0;

  /* void clearInterval ([optional] in long handle); */
  NS_IMETHOD ClearInterval(int32_t handle) = 0;

  /* void setResizable (in boolean resizable); */
  NS_IMETHOD SetResizable(bool resizable) = 0;

  /* void captureEvents (in long eventFlags); */
  NS_IMETHOD CaptureEvents(int32_t eventFlags) = 0;

  /* void releaseEvents (in long eventFlags); */
  NS_IMETHOD ReleaseEvents(int32_t eventFlags) = 0;

  /* void routeEvent (in nsIDOMEvent evt); */
  NS_IMETHOD RouteEvent(nsIDOMEvent *evt) = 0;

  /* void enableExternalCapture (); */
  NS_IMETHOD EnableExternalCapture(void) = 0;

  /* void disableExternalCapture (); */
  NS_IMETHOD DisableExternalCapture(void) = 0;

  /* [binaryname(OpenJS)] nsIDOMWindow open ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
  NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) = 0;

  /* nsIDOMWindow openDialog ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) = 0;

  /* readonly attribute nsIDOMWindow frames; */
  NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMJSWindow, NS_IDOMJSWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMJSWINDOW \
  NS_IMETHOD Dump(const nsAString & str); \
  NS_IMETHOD SetTimeout(int32_t *_retval); \
  NS_IMETHOD SetInterval(int32_t *_retval); \
  NS_IMETHOD ClearTimeout(int32_t handle); \
  NS_IMETHOD ClearInterval(int32_t handle); \
  NS_IMETHOD SetResizable(bool resizable); \
  NS_IMETHOD CaptureEvents(int32_t eventFlags); \
  NS_IMETHOD ReleaseEvents(int32_t eventFlags); \
  NS_IMETHOD RouteEvent(nsIDOMEvent *evt); \
  NS_IMETHOD EnableExternalCapture(void); \
  NS_IMETHOD DisableExternalCapture(void); \
  NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval); \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval); \
  NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMJSWINDOW(_to) \
  NS_IMETHOD Dump(const nsAString & str) { return _to Dump(str); } \
  NS_IMETHOD SetTimeout(int32_t *_retval) { return _to SetTimeout(_retval); } \
  NS_IMETHOD SetInterval(int32_t *_retval) { return _to SetInterval(_retval); } \
  NS_IMETHOD ClearTimeout(int32_t handle) { return _to ClearTimeout(handle); } \
  NS_IMETHOD ClearInterval(int32_t handle) { return _to ClearInterval(handle); } \
  NS_IMETHOD SetResizable(bool resizable) { return _to SetResizable(resizable); } \
  NS_IMETHOD CaptureEvents(int32_t eventFlags) { return _to CaptureEvents(eventFlags); } \
  NS_IMETHOD ReleaseEvents(int32_t eventFlags) { return _to ReleaseEvents(eventFlags); } \
  NS_IMETHOD RouteEvent(nsIDOMEvent *evt) { return _to RouteEvent(evt); } \
  NS_IMETHOD EnableExternalCapture(void) { return _to EnableExternalCapture(); } \
  NS_IMETHOD DisableExternalCapture(void) { return _to DisableExternalCapture(); } \
  NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) { return _to OpenJS(url, name, options, _retval); } \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) { return _to OpenDialog(url, name, options, _retval); } \
  NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames) { return _to GetFrames(aFrames); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMJSWINDOW(_to) \
  NS_IMETHOD Dump(const nsAString & str) { return !_to ? NS_ERROR_NULL_POINTER : _to->Dump(str); } \
  NS_IMETHOD SetTimeout(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeout(_retval); } \
  NS_IMETHOD SetInterval(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInterval(_retval); } \
  NS_IMETHOD ClearTimeout(int32_t handle) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearTimeout(handle); } \
  NS_IMETHOD ClearInterval(int32_t handle) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearInterval(handle); } \
  NS_IMETHOD SetResizable(bool resizable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetResizable(resizable); } \
  NS_IMETHOD CaptureEvents(int32_t eventFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->CaptureEvents(eventFlags); } \
  NS_IMETHOD ReleaseEvents(int32_t eventFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReleaseEvents(eventFlags); } \
  NS_IMETHOD RouteEvent(nsIDOMEvent *evt) { return !_to ? NS_ERROR_NULL_POINTER : _to->RouteEvent(evt); } \
  NS_IMETHOD EnableExternalCapture(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableExternalCapture(); } \
  NS_IMETHOD DisableExternalCapture(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableExternalCapture(); } \
  NS_IMETHOD OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenJS(url, name, options, _retval); } \
  NS_IMETHOD OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDialog(url, name, options, _retval); } \
  NS_IMETHOD GetFrames(nsIDOMWindow * *aFrames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrames(aFrames); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMJSWindow : public nsIDOMJSWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMJSWINDOW

  nsDOMJSWindow();

private:
  ~nsDOMJSWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMJSWindow, nsIDOMJSWindow)

nsDOMJSWindow::nsDOMJSWindow()
{
  /* member initializers and constructor code */
}

nsDOMJSWindow::~nsDOMJSWindow()
{
  /* destructor code */
}

/* void dump (in DOMString str); */
NS_IMETHODIMP nsDOMJSWindow::Dump(const nsAString & str)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long setTimeout (); */
NS_IMETHODIMP nsDOMJSWindow::SetTimeout(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long setInterval (); */
NS_IMETHODIMP nsDOMJSWindow::SetInterval(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearTimeout ([optional] in long handle); */
NS_IMETHODIMP nsDOMJSWindow::ClearTimeout(int32_t handle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearInterval ([optional] in long handle); */
NS_IMETHODIMP nsDOMJSWindow::ClearInterval(int32_t handle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setResizable (in boolean resizable); */
NS_IMETHODIMP nsDOMJSWindow::SetResizable(bool resizable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void captureEvents (in long eventFlags); */
NS_IMETHODIMP nsDOMJSWindow::CaptureEvents(int32_t eventFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void releaseEvents (in long eventFlags); */
NS_IMETHODIMP nsDOMJSWindow::ReleaseEvents(int32_t eventFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void routeEvent (in nsIDOMEvent evt); */
NS_IMETHODIMP nsDOMJSWindow::RouteEvent(nsIDOMEvent *evt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableExternalCapture (); */
NS_IMETHODIMP nsDOMJSWindow::EnableExternalCapture()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableExternalCapture (); */
NS_IMETHODIMP nsDOMJSWindow::DisableExternalCapture()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(OpenJS)] nsIDOMWindow open ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
NS_IMETHODIMP nsDOMJSWindow::OpenJS(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow openDialog ([optional] in DOMString url, [optional] in DOMString name, [optional] in DOMString options); */
NS_IMETHODIMP nsDOMJSWindow::OpenDialog(const nsAString & url, const nsAString & name, const nsAString & options, nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow frames; */
NS_IMETHODIMP nsDOMJSWindow::GetFrames(nsIDOMWindow * *aFrames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMJSWindow_h__ */
