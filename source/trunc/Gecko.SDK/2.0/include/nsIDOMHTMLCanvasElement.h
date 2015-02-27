/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/html/nsIDOMHTMLCanvasElement.idl
 */

#ifndef __gen_nsIDOMHTMLCanvasElement_h__
#define __gen_nsIDOMHTMLCanvasElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
// for jsval
#include "jsapi.h"
class nsIDOMFile; /* forward declaration */


/* starting interface:    nsIDOMHTMLCanvasElement */
#define NS_IDOMHTMLCANVASELEMENT_IID_STR "53ad994a-3cd0-48fa-8ffb-7f3d8cd19c50"

#define NS_IDOMHTMLCANVASELEMENT_IID \
  {0x53ad994a, 0x3cd0, 0x48fa, \
    { 0x8f, 0xfb, 0x7f, 0x3d, 0x8c, 0xd1, 0x9c, 0x50 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLCanvasElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLCANVASELEMENT_IID)

  /* attribute long width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth) = 0;

  /* attribute long height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight) = 0;

  /* attribute boolean mozOpaque; */
  NS_SCRIPTABLE NS_IMETHOD GetMozOpaque(PRBool *aMozOpaque) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMozOpaque(PRBool aMozOpaque) = 0;

  /* nsISupports getContext (in DOMString contextId, [optional] in jsval contextOptions); */
  NS_SCRIPTABLE NS_IMETHOD GetContext(const nsAString & contextId, const jsval & contextOptions, nsISupports **_retval NS_OUTPARAM) = 0;

  /* [optional_argc] DOMString toDataURL ([optional] in DOMString type, [optional] in DOMString params); */
  NS_SCRIPTABLE NS_IMETHOD ToDataURL(const nsAString & type, const nsAString & params, PRUint8 _argc, nsAString & _retval NS_OUTPARAM) = 0;

  /* [noscript] DOMString toDataURLAs (in DOMString mimeType, in DOMString encoderOptions); */
  NS_IMETHOD ToDataURLAs(const nsAString & mimeType, const nsAString & encoderOptions, nsAString & _retval NS_OUTPARAM) = 0;

  /* [optional_argc] nsIDOMFile mozGetAsFile (in DOMString name, [optional] in DOMString type); */
  NS_SCRIPTABLE NS_IMETHOD MozGetAsFile(const nsAString & name, const nsAString & type, PRUint8 _argc, nsIDOMFile **_retval NS_OUTPARAM) = 0;

  /* nsISupports MozGetIPCContext (in DOMString contextId); */
  NS_SCRIPTABLE NS_IMETHOD MozGetIPCContext(const nsAString & contextId, nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLCanvasElement, NS_IDOMHTMLCANVASELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLCANVASELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight); \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetMozOpaque(PRBool *aMozOpaque); \
  NS_SCRIPTABLE NS_IMETHOD SetMozOpaque(PRBool aMozOpaque); \
  NS_SCRIPTABLE NS_IMETHOD GetContext(const nsAString & contextId, const jsval & contextOptions, nsISupports **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ToDataURL(const nsAString & type, const nsAString & params, PRUint8 _argc, nsAString & _retval NS_OUTPARAM); \
  NS_IMETHOD ToDataURLAs(const nsAString & mimeType, const nsAString & encoderOptions, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MozGetAsFile(const nsAString & name, const nsAString & type, PRUint8 _argc, nsIDOMFile **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MozGetIPCContext(const nsAString & contextId, nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLCANVASELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth) { return _to SetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight) { return _to SetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozOpaque(PRBool *aMozOpaque) { return _to GetMozOpaque(aMozOpaque); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozOpaque(PRBool aMozOpaque) { return _to SetMozOpaque(aMozOpaque); } \
  NS_SCRIPTABLE NS_IMETHOD GetContext(const nsAString & contextId, const jsval & contextOptions, nsISupports **_retval NS_OUTPARAM) { return _to GetContext(contextId, contextOptions, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ToDataURL(const nsAString & type, const nsAString & params, PRUint8 _argc, nsAString & _retval NS_OUTPARAM) { return _to ToDataURL(type, params, _argc, _retval); } \
  NS_IMETHOD ToDataURLAs(const nsAString & mimeType, const nsAString & encoderOptions, nsAString & _retval NS_OUTPARAM) { return _to ToDataURLAs(mimeType, encoderOptions, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozGetAsFile(const nsAString & name, const nsAString & type, PRUint8 _argc, nsIDOMFile **_retval NS_OUTPARAM) { return _to MozGetAsFile(name, type, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozGetIPCContext(const nsAString & contextId, nsISupports **_retval NS_OUTPARAM) { return _to MozGetIPCContext(contextId, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLCANVASELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(PRInt32 *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(PRInt32 aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(PRInt32 *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(PRInt32 aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozOpaque(PRBool *aMozOpaque) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozOpaque(aMozOpaque); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozOpaque(PRBool aMozOpaque) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozOpaque(aMozOpaque); } \
  NS_SCRIPTABLE NS_IMETHOD GetContext(const nsAString & contextId, const jsval & contextOptions, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContext(contextId, contextOptions, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ToDataURL(const nsAString & type, const nsAString & params, PRUint8 _argc, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToDataURL(type, params, _argc, _retval); } \
  NS_IMETHOD ToDataURLAs(const nsAString & mimeType, const nsAString & encoderOptions, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToDataURLAs(mimeType, encoderOptions, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozGetAsFile(const nsAString & name, const nsAString & type, PRUint8 _argc, nsIDOMFile **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetAsFile(name, type, _argc, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozGetIPCContext(const nsAString & contextId, nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetIPCContext(contextId, _retval); } 

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

/* attribute long width; */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetWidth(PRInt32 *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCanvasElement::SetWidth(PRInt32 aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long height; */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetHeight(PRInt32 *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCanvasElement::SetHeight(PRInt32 aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean mozOpaque; */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetMozOpaque(PRBool *aMozOpaque)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLCanvasElement::SetMozOpaque(PRBool aMozOpaque)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getContext (in DOMString contextId, [optional] in jsval contextOptions); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::GetContext(const nsAString & contextId, const jsval & contextOptions, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] DOMString toDataURL ([optional] in DOMString type, [optional] in DOMString params); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::ToDataURL(const nsAString & type, const nsAString & params, PRUint8 _argc, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] DOMString toDataURLAs (in DOMString mimeType, in DOMString encoderOptions); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::ToDataURLAs(const nsAString & mimeType, const nsAString & encoderOptions, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIDOMFile mozGetAsFile (in DOMString name, [optional] in DOMString type); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::MozGetAsFile(const nsAString & name, const nsAString & type, PRUint8 _argc, nsIDOMFile **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports MozGetIPCContext (in DOMString contextId); */
NS_IMETHODIMP nsDOMHTMLCanvasElement::MozGetIPCContext(const nsAString & contextId, nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLCanvasElement_h__ */
