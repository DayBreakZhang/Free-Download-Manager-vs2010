/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLFrameSetElement.idl
 */

#ifndef __gen_nsIDOMHTMLFrameSetElement_h__
#define __gen_nsIDOMHTMLFrameSetElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"

/* starting interface:    nsIDOMHTMLFrameSetElement */
#define NS_IDOMHTMLFRAMESETELEMENT_IID_STR "e62b41c0-eaec-49bc-bf0c-be3a50b175d1"

#define NS_IDOMHTMLFRAMESETELEMENT_IID \
  {0xe62b41c0, 0xeaec, 0x49bc, \
    { 0xbf, 0x0c, 0xbe, 0x3a, 0x50, 0xb1, 0x75, 0xd1 }}

class NS_NO_VTABLE nsIDOMHTMLFrameSetElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLFRAMESETELEMENT_IID)

  /* attribute DOMString cols; */
  NS_IMETHOD GetCols(nsAString & aCols) = 0;
  NS_IMETHOD SetCols(const nsAString & aCols) = 0;

  /* attribute DOMString rows; */
  NS_IMETHOD GetRows(nsAString & aRows) = 0;
  NS_IMETHOD SetRows(const nsAString & aRows) = 0;

  /* [implicit_jscontext] attribute jsval onafterprint; */
  NS_IMETHOD GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint) = 0;
  NS_IMETHOD SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint) = 0;

  /* [implicit_jscontext] attribute jsval onbeforeprint; */
  NS_IMETHOD GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint) = 0;
  NS_IMETHOD SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint) = 0;

  /* [implicit_jscontext] attribute jsval onbeforeunload; */
  NS_IMETHOD GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload) = 0;
  NS_IMETHOD SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload) = 0;

  /* [implicit_jscontext] attribute jsval onhashchange; */
  NS_IMETHOD GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange) = 0;
  NS_IMETHOD SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange) = 0;

  /* [implicit_jscontext] attribute jsval onmessage; */
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::Value *aOnmessage) = 0;
  NS_IMETHOD SetOnmessage(JSContext* cx, const JS::Value & aOnmessage) = 0;

  /* [implicit_jscontext] attribute jsval onoffline; */
  NS_IMETHOD GetOnoffline(JSContext* cx, JS::Value *aOnoffline) = 0;
  NS_IMETHOD SetOnoffline(JSContext* cx, const JS::Value & aOnoffline) = 0;

  /* [implicit_jscontext] attribute jsval ononline; */
  NS_IMETHOD GetOnonline(JSContext* cx, JS::Value *aOnonline) = 0;
  NS_IMETHOD SetOnonline(JSContext* cx, const JS::Value & aOnonline) = 0;

  /* [implicit_jscontext] attribute jsval onpagehide; */
  NS_IMETHOD GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide) = 0;
  NS_IMETHOD SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide) = 0;

  /* [implicit_jscontext] attribute jsval onpageshow; */
  NS_IMETHOD GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow) = 0;
  NS_IMETHOD SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow) = 0;

  /* [implicit_jscontext] attribute jsval onpopstate; */
  NS_IMETHOD GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate) = 0;
  NS_IMETHOD SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate) = 0;

  /* [implicit_jscontext] attribute jsval onresize; */
  NS_IMETHOD GetOnresize(JSContext* cx, JS::Value *aOnresize) = 0;
  NS_IMETHOD SetOnresize(JSContext* cx, const JS::Value & aOnresize) = 0;

  /* [implicit_jscontext] attribute jsval onunload; */
  NS_IMETHOD GetOnunload(JSContext* cx, JS::Value *aOnunload) = 0;
  NS_IMETHOD SetOnunload(JSContext* cx, const JS::Value & aOnunload) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLFrameSetElement, NS_IDOMHTMLFRAMESETELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLFRAMESETELEMENT \
  NS_IMETHOD GetCols(nsAString & aCols); \
  NS_IMETHOD SetCols(const nsAString & aCols); \
  NS_IMETHOD GetRows(nsAString & aRows); \
  NS_IMETHOD SetRows(const nsAString & aRows); \
  NS_IMETHOD GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint); \
  NS_IMETHOD SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint); \
  NS_IMETHOD GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint); \
  NS_IMETHOD SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint); \
  NS_IMETHOD GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload); \
  NS_IMETHOD SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload); \
  NS_IMETHOD GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange); \
  NS_IMETHOD SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange); \
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::Value *aOnmessage); \
  NS_IMETHOD SetOnmessage(JSContext* cx, const JS::Value & aOnmessage); \
  NS_IMETHOD GetOnoffline(JSContext* cx, JS::Value *aOnoffline); \
  NS_IMETHOD SetOnoffline(JSContext* cx, const JS::Value & aOnoffline); \
  NS_IMETHOD GetOnonline(JSContext* cx, JS::Value *aOnonline); \
  NS_IMETHOD SetOnonline(JSContext* cx, const JS::Value & aOnonline); \
  NS_IMETHOD GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide); \
  NS_IMETHOD SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide); \
  NS_IMETHOD GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow); \
  NS_IMETHOD SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow); \
  NS_IMETHOD GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate); \
  NS_IMETHOD SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate); \
  NS_IMETHOD GetOnresize(JSContext* cx, JS::Value *aOnresize); \
  NS_IMETHOD SetOnresize(JSContext* cx, const JS::Value & aOnresize); \
  NS_IMETHOD GetOnunload(JSContext* cx, JS::Value *aOnunload); \
  NS_IMETHOD SetOnunload(JSContext* cx, const JS::Value & aOnunload); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLFRAMESETELEMENT(_to) \
  NS_IMETHOD GetCols(nsAString & aCols) { return _to GetCols(aCols); } \
  NS_IMETHOD SetCols(const nsAString & aCols) { return _to SetCols(aCols); } \
  NS_IMETHOD GetRows(nsAString & aRows) { return _to GetRows(aRows); } \
  NS_IMETHOD SetRows(const nsAString & aRows) { return _to SetRows(aRows); } \
  NS_IMETHOD GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint) { return _to GetOnafterprint(cx, aOnafterprint); } \
  NS_IMETHOD SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint) { return _to SetOnafterprint(cx, aOnafterprint); } \
  NS_IMETHOD GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint) { return _to GetOnbeforeprint(cx, aOnbeforeprint); } \
  NS_IMETHOD SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint) { return _to SetOnbeforeprint(cx, aOnbeforeprint); } \
  NS_IMETHOD GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload) { return _to GetOnbeforeunload(cx, aOnbeforeunload); } \
  NS_IMETHOD SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload) { return _to SetOnbeforeunload(cx, aOnbeforeunload); } \
  NS_IMETHOD GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange) { return _to GetOnhashchange(cx, aOnhashchange); } \
  NS_IMETHOD SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange) { return _to SetOnhashchange(cx, aOnhashchange); } \
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::Value *aOnmessage) { return _to GetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD SetOnmessage(JSContext* cx, const JS::Value & aOnmessage) { return _to SetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD GetOnoffline(JSContext* cx, JS::Value *aOnoffline) { return _to GetOnoffline(cx, aOnoffline); } \
  NS_IMETHOD SetOnoffline(JSContext* cx, const JS::Value & aOnoffline) { return _to SetOnoffline(cx, aOnoffline); } \
  NS_IMETHOD GetOnonline(JSContext* cx, JS::Value *aOnonline) { return _to GetOnonline(cx, aOnonline); } \
  NS_IMETHOD SetOnonline(JSContext* cx, const JS::Value & aOnonline) { return _to SetOnonline(cx, aOnonline); } \
  NS_IMETHOD GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide) { return _to GetOnpagehide(cx, aOnpagehide); } \
  NS_IMETHOD SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide) { return _to SetOnpagehide(cx, aOnpagehide); } \
  NS_IMETHOD GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow) { return _to GetOnpageshow(cx, aOnpageshow); } \
  NS_IMETHOD SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow) { return _to SetOnpageshow(cx, aOnpageshow); } \
  NS_IMETHOD GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate) { return _to GetOnpopstate(cx, aOnpopstate); } \
  NS_IMETHOD SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate) { return _to SetOnpopstate(cx, aOnpopstate); } \
  NS_IMETHOD GetOnresize(JSContext* cx, JS::Value *aOnresize) { return _to GetOnresize(cx, aOnresize); } \
  NS_IMETHOD SetOnresize(JSContext* cx, const JS::Value & aOnresize) { return _to SetOnresize(cx, aOnresize); } \
  NS_IMETHOD GetOnunload(JSContext* cx, JS::Value *aOnunload) { return _to GetOnunload(cx, aOnunload); } \
  NS_IMETHOD SetOnunload(JSContext* cx, const JS::Value & aOnunload) { return _to SetOnunload(cx, aOnunload); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLFRAMESETELEMENT(_to) \
  NS_IMETHOD GetCols(nsAString & aCols) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCols(aCols); } \
  NS_IMETHOD SetCols(const nsAString & aCols) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCols(aCols); } \
  NS_IMETHOD GetRows(nsAString & aRows) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRows(aRows); } \
  NS_IMETHOD SetRows(const nsAString & aRows) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRows(aRows); } \
  NS_IMETHOD GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnafterprint(cx, aOnafterprint); } \
  NS_IMETHOD SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnafterprint(cx, aOnafterprint); } \
  NS_IMETHOD GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnbeforeprint(cx, aOnbeforeprint); } \
  NS_IMETHOD SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnbeforeprint(cx, aOnbeforeprint); } \
  NS_IMETHOD GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnbeforeunload(cx, aOnbeforeunload); } \
  NS_IMETHOD SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnbeforeunload(cx, aOnbeforeunload); } \
  NS_IMETHOD GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnhashchange(cx, aOnhashchange); } \
  NS_IMETHOD SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnhashchange(cx, aOnhashchange); } \
  NS_IMETHOD GetOnmessage(JSContext* cx, JS::Value *aOnmessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD SetOnmessage(JSContext* cx, const JS::Value & aOnmessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnmessage(cx, aOnmessage); } \
  NS_IMETHOD GetOnoffline(JSContext* cx, JS::Value *aOnoffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnoffline(cx, aOnoffline); } \
  NS_IMETHOD SetOnoffline(JSContext* cx, const JS::Value & aOnoffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnoffline(cx, aOnoffline); } \
  NS_IMETHOD GetOnonline(JSContext* cx, JS::Value *aOnonline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnonline(cx, aOnonline); } \
  NS_IMETHOD SetOnonline(JSContext* cx, const JS::Value & aOnonline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnonline(cx, aOnonline); } \
  NS_IMETHOD GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpagehide(cx, aOnpagehide); } \
  NS_IMETHOD SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpagehide(cx, aOnpagehide); } \
  NS_IMETHOD GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpageshow(cx, aOnpageshow); } \
  NS_IMETHOD SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpageshow(cx, aOnpageshow); } \
  NS_IMETHOD GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnpopstate(cx, aOnpopstate); } \
  NS_IMETHOD SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnpopstate(cx, aOnpopstate); } \
  NS_IMETHOD GetOnresize(JSContext* cx, JS::Value *aOnresize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnresize(cx, aOnresize); } \
  NS_IMETHOD SetOnresize(JSContext* cx, const JS::Value & aOnresize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnresize(cx, aOnresize); } \
  NS_IMETHOD GetOnunload(JSContext* cx, JS::Value *aOnunload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnunload(cx, aOnunload); } \
  NS_IMETHOD SetOnunload(JSContext* cx, const JS::Value & aOnunload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnunload(cx, aOnunload); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLFrameSetElement : public nsIDOMHTMLFrameSetElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLFRAMESETELEMENT

  nsDOMHTMLFrameSetElement();

private:
  ~nsDOMHTMLFrameSetElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLFrameSetElement, nsIDOMHTMLFrameSetElement)

nsDOMHTMLFrameSetElement::nsDOMHTMLFrameSetElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLFrameSetElement::~nsDOMHTMLFrameSetElement()
{
  /* destructor code */
}

/* attribute DOMString cols; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetCols(nsAString & aCols)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetCols(const nsAString & aCols)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString rows; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetRows(nsAString & aRows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetRows(const nsAString & aRows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onafterprint; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onbeforeprint; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onbeforeunload; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onhashchange; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmessage; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnmessage(JSContext* cx, JS::Value *aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnmessage(JSContext* cx, const JS::Value & aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onoffline; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnoffline(JSContext* cx, JS::Value *aOnoffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnoffline(JSContext* cx, const JS::Value & aOnoffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ononline; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnonline(JSContext* cx, JS::Value *aOnonline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnonline(JSContext* cx, const JS::Value & aOnonline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpagehide; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpageshow; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpopstate; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onresize; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnresize(JSContext* cx, JS::Value *aOnresize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnresize(JSContext* cx, const JS::Value & aOnresize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onunload; */
NS_IMETHODIMP nsDOMHTMLFrameSetElement::GetOnunload(JSContext* cx, JS::Value *aOnunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameSetElement::SetOnunload(JSContext* cx, const JS::Value & aOnunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLFrameSetElement_h__ */
