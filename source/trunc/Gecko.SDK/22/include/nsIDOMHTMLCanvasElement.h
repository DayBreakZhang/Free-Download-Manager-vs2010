/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLCanvasElement.idl
 */

#ifndef __gen_nsIDOMHTMLCanvasElement_h__
#define __gen_nsIDOMHTMLCanvasElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// for jsval
#include "jsapi.h"
class nsIDOMBlob; /* forward declaration */

class nsIDOMFile; /* forward declaration */

class nsIVariant; /* forward declaration */

class nsIInputStreamCallback; /* forward declaration */


/* starting interface:    nsIDOMMozCanvasPrintState */
#define NS_IDOMMOZCANVASPRINTSTATE_IID_STR "8d5fb8a0-7782-11e1-b0c4-0800200c9a67"

#define NS_IDOMMOZCANVASPRINTSTATE_IID \
  {0x8d5fb8a0, 0x7782, 0x11e1, \
    { 0xb0, 0xc4, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x67 }}

class NS_NO_VTABLE nsIDOMMozCanvasPrintState : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZCANVASPRINTSTATE_IID)

  /* readonly attribute nsISupports context; */
  NS_IMETHOD GetContext(nsISupports * *aContext) = 0;

  /* void done (); */
  NS_IMETHOD Done(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozCanvasPrintState, NS_IDOMMOZCANVASPRINTSTATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZCANVASPRINTSTATE \
  NS_IMETHOD GetContext(nsISupports * *aContext); \
  NS_IMETHOD Done(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZCANVASPRINTSTATE(_to) \
  NS_IMETHOD GetContext(nsISupports * *aContext) { return _to GetContext(aContext); } \
  NS_IMETHOD Done(void) { return _to Done(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZCANVASPRINTSTATE(_to) \
  NS_IMETHOD GetContext(nsISupports * *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContext(aContext); } \
  NS_IMETHOD Done(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Done(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozCanvasPrintState : public nsIDOMMozCanvasPrintState
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZCANVASPRINTSTATE

  nsDOMMozCanvasPrintState();

private:
  ~nsDOMMozCanvasPrintState();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozCanvasPrintState, nsIDOMMozCanvasPrintState)

nsDOMMozCanvasPrintState::nsDOMMozCanvasPrintState()
{
  /* member initializers and constructor code */
}

nsDOMMozCanvasPrintState::~nsDOMMozCanvasPrintState()
{
  /* destructor code */
}

/* readonly attribute nsISupports context; */
NS_IMETHODIMP nsDOMMozCanvasPrintState::GetContext(nsISupports * *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void done (); */
NS_IMETHODIMP nsDOMMozCanvasPrintState::Done()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPrintCallback */
#define NS_IPRINTCALLBACK_IID_STR "8d5fb8a0-7782-11e1-b0c4-0800200c9a66"

#define NS_IPRINTCALLBACK_IID \
  {0x8d5fb8a0, 0x7782, 0x11e1, \
    { 0xb0, 0xc4, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIPrintCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTCALLBACK_IID)

  /* void render (in nsIDOMMozCanvasPrintState ctx); */
  NS_IMETHOD Render(nsIDOMMozCanvasPrintState *ctx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintCallback, NS_IPRINTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTCALLBACK \
  NS_IMETHOD Render(nsIDOMMozCanvasPrintState *ctx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTCALLBACK(_to) \
  NS_IMETHOD Render(nsIDOMMozCanvasPrintState *ctx) { return _to Render(ctx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTCALLBACK(_to) \
  NS_IMETHOD Render(nsIDOMMozCanvasPrintState *ctx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Render(ctx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintCallback : public nsIPrintCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTCALLBACK

  nsPrintCallback();

private:
  ~nsPrintCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintCallback, nsIPrintCallback)

nsPrintCallback::nsPrintCallback()
{
  /* member initializers and constructor code */
}

nsPrintCallback::~nsPrintCallback()
{
  /* destructor code */
}

/* void render (in nsIDOMMozCanvasPrintState ctx); */
NS_IMETHODIMP nsPrintCallback::Render(nsIDOMMozCanvasPrintState *ctx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFileCallback */
#define NS_IFILECALLBACK_IID_STR "6e9ffb59-2067-4aef-a51c-65e65a3e0d81"

#define NS_IFILECALLBACK_IID \
  {0x6e9ffb59, 0x2067, 0x4aef, \
    { 0xa5, 0x1c, 0x65, 0xe6, 0x5a, 0x3e, 0x0d, 0x81 }}

class NS_NO_VTABLE nsIFileCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILECALLBACK_IID)

  /* void receive (in nsIDOMBlob file); */
  NS_IMETHOD Receive(nsIDOMBlob *file) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFileCallback, NS_IFILECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILECALLBACK \
  NS_IMETHOD Receive(nsIDOMBlob *file); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILECALLBACK(_to) \
  NS_IMETHOD Receive(nsIDOMBlob *file) { return _to Receive(file); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILECALLBACK(_to) \
  NS_IMETHOD Receive(nsIDOMBlob *file) { return !_to ? NS_ERROR_NULL_POINTER : _to->Receive(file); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFileCallback : public nsIFileCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILECALLBACK

  nsFileCallback();

private:
  ~nsFileCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFileCallback, nsIFileCallback)

nsFileCallback::nsFileCallback()
{
  /* member initializers and constructor code */
}

nsFileCallback::~nsFileCallback()
{
  /* destructor code */
}

/* void receive (in nsIDOMBlob file); */
NS_IMETHODIMP nsFileCallback::Receive(nsIDOMBlob *file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMHTMLCanvasElement */
#define NS_IDOMHTMLCANVASELEMENT_IID_STR "1cfacc53-ab73-4ceb-9f5f-22387dcd1aae"

#define NS_IDOMHTMLCANVASELEMENT_IID \
  {0x1cfacc53, 0xab73, 0x4ceb, \
    { 0x9f, 0x5f, 0x22, 0x38, 0x7d, 0xcd, 0x1a, 0xae }}

class NS_NO_VTABLE nsIDOMHTMLCanvasElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLCANVASELEMENT_IID)

  /* attribute unsigned long width; */
  NS_IMETHOD GetWidth(uint32_t *aWidth) = 0;
  NS_IMETHOD SetWidth(uint32_t aWidth) = 0;

  /* attribute unsigned long height; */
  NS_IMETHOD GetHeight(uint32_t *aHeight) = 0;
  NS_IMETHOD SetHeight(uint32_t aHeight) = 0;

  /* attribute boolean mozOpaque; */
  NS_IMETHOD GetMozOpaque(bool *aMozOpaque) = 0;
  NS_IMETHOD SetMozOpaque(bool aMozOpaque) = 0;

  /* nsISupports getContext (in DOMString contextId, [optional] in jsval contextOptions); */
  NS_IMETHOD GetContext(const nsAString & contextId, const JS::Value & contextOptions, nsISupports * *_retval) = 0;

  /* [optional_argc] DOMString toDataURL ([optional] in DOMString type, [optional] in nsIVariant params); */
  NS_IMETHOD ToDataURL(const nsAString & type, nsIVariant *params, uint8_t _argc, nsAString & _retval) = 0;

  /* [optional_argc] nsIDOMFile mozGetAsFile (in DOMString name, [optional] in DOMString type); */
  NS_IMETHOD MozGetAsFile(const nsAString & name, const nsAString & type, uint8_t _argc, nsIDOMFile * *_retval) = 0;

  /* [optional_argc] void toBlob (in nsIFileCallback callback, [optional] in DOMString type, [optional] in nsIVariant params); */
  NS_IMETHOD ToBlob(nsIFileCallback *callback, const nsAString & type, nsIVariant *params, uint8_t _argc) = 0;

  /* nsISupports MozGetIPCContext (in DOMString contextId); */
  NS_IMETHOD MozGetIPCContext(const nsAString & contextId, nsISupports * *_retval) = 0;

  /* void mozFetchAsStream (in nsIInputStreamCallback callback, [optional] in DOMString type); */
  NS_IMETHOD MozFetchAsStream(nsIInputStreamCallback *callback, const nsAString & type) = 0;

  /* attribute nsIPrintCallback mozPrintCallback; */
  NS_IMETHOD GetMozPrintCallback(nsIPrintCallback * *aMozPrintCallback) = 0;
  NS_IMETHOD SetMozPrintCallback(nsIPrintCallback *aMozPrintCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLCanvasElement, NS_IDOMHTMLCANVASELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLCANVASELEMENT \
  NS_IMETHOD GetWidth(uint32_t *aWidth); \
  NS_IMETHOD SetWidth(uint32_t aWidth); \
  NS_IMETHOD GetHeight(uint32_t *aHeight); \
  NS_IMETHOD SetHeight(uint32_t aHeight); \
  NS_IMETHOD GetMozOpaque(bool *aMozOpaque); \
  NS_IMETHOD SetMozOpaque(bool aMozOpaque); \
  NS_IMETHOD GetContext(const nsAString & contextId, const JS::Value & contextOptions, nsISupports * *_retval); \
  NS_IMETHOD ToDataURL(const nsAString & type, nsIVariant *params, uint8_t _argc, nsAString & _retval); \
  NS_IMETHOD MozGetAsFile(const nsAString & name, const nsAString & type, uint8_t _argc, nsIDOMFile * *_retval); \
  NS_IMETHOD ToBlob(nsIFileCallback *callback, const nsAString & type, nsIVariant *params, uint8_t _argc); \
  NS_IMETHOD MozGetIPCContext(const nsAString & contextId, nsISupports * *_retval); \
  NS_IMETHOD MozFetchAsStream(nsIInputStreamCallback *callback, const nsAString & type); \
  NS_IMETHOD GetMozPrintCallback(nsIPrintCallback * *aMozPrintCallback); \
  NS_IMETHOD SetMozPrintCallback(nsIPrintCallback *aMozPrintCallback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLCANVASELEMENT(_to) \
  NS_IMETHOD GetWidth(uint32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(uint32_t aWidth) { return _to SetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(uint32_t aHeight) { return _to SetHeight(aHeight); } \
  NS_IMETHOD GetMozOpaque(bool *aMozOpaque) { return _to GetMozOpaque(aMozOpaque); } \
  NS_IMETHOD SetMozOpaque(bool aMozOpaque) { return _to SetMozOpaque(aMozOpaque); } \
  NS_IMETHOD GetContext(const nsAString & contextId, const JS::Value & contextOptions, nsISupports * *_retval) { return _to GetContext(contextId, contextOptions, _retval); } \
  NS_IMETHOD ToDataURL(const nsAString & type, nsIVariant *params, uint8_t _argc, nsAString & _retval) { return _to ToDataURL(type, params, _argc, _retval); } \
  NS_IMETHOD MozGetAsFile(const nsAString & name, const nsAString & type, uint8_t _argc, nsIDOMFile * *_retval) { return _to MozGetAsFile(name, type, _argc, _retval); } \
  NS_IMETHOD ToBlob(nsIFileCallback *callback, const nsAString & type, nsIVariant *params, uint8_t _argc) { return _to ToBlob(callback, type, params, _argc); } \
  NS_IMETHOD MozGetIPCContext(const nsAString & contextId, nsISupports * *_retval) { return _to MozGetIPCContext(contextId, _retval); } \
  NS_IMETHOD MozFetchAsStream(nsIInputStreamCallback *callback, const nsAString & type) { return _to MozFetchAsStream(callback, type); } \
  NS_IMETHOD GetMozPrintCallback(nsIPrintCallback * *aMozPrintCallback) { return _to GetMozPrintCallback(aMozPrintCallback); } \
  NS_IMETHOD SetMozPrintCallback(nsIPrintCallback *aMozPrintCallback) { return _to SetMozPrintCallback(aMozPrintCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLCANVASELEMENT(_to) \
  NS_IMETHOD GetWidth(uint32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(uint32_t aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(uint32_t aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_IMETHOD GetMozOpaque(bool *aMozOpaque) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozOpaque(aMozOpaque); } \
  NS_IMETHOD SetMozOpaque(bool aMozOpaque) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozOpaque(aMozOpaque); } \
  NS_IMETHOD GetContext(const nsAString & contextId, const JS::Value & contextOptions, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContext(contextId, contextOptions, _retval); } \
  NS_IMETHOD ToDataURL(const nsAString & type, nsIVariant *params, uint8_t _argc, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToDataURL(type, params, _argc, _retval); } \
  NS_IMETHOD MozGetAsFile(const nsAString & name, const nsAString & type, uint8_t _argc, nsIDOMFile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetAsFile(name, type, _argc, _retval); } \
  NS_IMETHOD ToBlob(nsIFileCallback *callback, const nsAString & type, nsIVariant *params, uint8_t _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToBlob(callback, type, params, _argc); } \
  NS_IMETHOD MozGetIPCContext(const nsAString & contextId, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetIPCContext(contextId, _retval); } \
  NS_IMETHOD MozFetchAsStream(nsIInputStreamCallback *callback, const nsAString & type) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozFetchAsStream(callback, type); } \
  NS_IMETHOD GetMozPrintCallback(nsIPrintCallback * *aMozPrintCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozPrintCallback(aMozPrintCallback); } \
  NS_IMETHOD SetMozPrintCallback(nsIPrintCallback *aMozPrintCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozPrintCallback(aMozPrintCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLCanvasElement : public nsIDOMHTMLCanvasElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLCANVASELEMENT

  nsDOMHTMLCanvasElement();

private:
  ~nsDOMHTMLCanvasElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLCanvasElement, nsIDOMHTMLCanvasElement)

nsDOMHTMLCanvasElement::nsDOMHTMLCanvasElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLCanvasElement::~nsDOMHTMLCanvasElement()
{
  /* destructor code */
}

/* attribute unsigned long width; */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetWidth(uint32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCanvasElement::SetWidth(uint32_t aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long height; */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetHeight(uint32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCanvasElement::SetHeight(uint32_t aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean mozOpaque; */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetMozOpaque(bool *aMozOpaque)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCanvasElement::SetMozOpaque(bool aMozOpaque)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getContext (in DOMString contextId, [optional] in jsval contextOptions); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetContext(const nsAString & contextId, const JS::Value & contextOptions, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] DOMString toDataURL ([optional] in DOMString type, [optional] in nsIVariant params); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::ToDataURL(const nsAString & type, nsIVariant *params, uint8_t _argc, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIDOMFile mozGetAsFile (in DOMString name, [optional] in DOMString type); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::MozGetAsFile(const nsAString & name, const nsAString & type, uint8_t _argc, nsIDOMFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] void toBlob (in nsIFileCallback callback, [optional] in DOMString type, [optional] in nsIVariant params); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::ToBlob(nsIFileCallback *callback, const nsAString & type, nsIVariant *params, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports MozGetIPCContext (in DOMString contextId); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::MozGetIPCContext(const nsAString & contextId, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozFetchAsStream (in nsIInputStreamCallback callback, [optional] in DOMString type); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::MozFetchAsStream(nsIInputStreamCallback *callback, const nsAString & type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIPrintCallback mozPrintCallback; */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetMozPrintCallback(nsIPrintCallback * *aMozPrintCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCanvasElement::SetMozPrintCallback(nsIPrintCallback *aMozPrintCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLCanvasElement_h__ */
