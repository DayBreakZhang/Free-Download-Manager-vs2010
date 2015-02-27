/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLFrameElement.idl
 */

#ifndef __gen_nsIDOMHTMLFrameElement_h__
#define __gen_nsIDOMHTMLFrameElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLFrameElement */
#define NS_IDOMHTMLFRAMEELEMENT_IID_STR "912423ad-00c2-4948-8f8e-4950169e516d"

#define NS_IDOMHTMLFRAMEELEMENT_IID \
  {0x912423ad, 0x00c2, 0x4948, \
    { 0x8f, 0x8e, 0x49, 0x50, 0x16, 0x9e, 0x51, 0x6d }}

class NS_NO_VTABLE nsIDOMHTMLFrameElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLFRAMEELEMENT_IID)

  /* attribute DOMString frameBorder; */
  NS_IMETHOD GetFrameBorder(nsAString & aFrameBorder) = 0;
  NS_IMETHOD SetFrameBorder(const nsAString & aFrameBorder) = 0;

  /* attribute DOMString longDesc; */
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc) = 0;
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc) = 0;

  /* attribute DOMString marginHeight; */
  NS_IMETHOD GetMarginHeight(nsAString & aMarginHeight) = 0;
  NS_IMETHOD SetMarginHeight(const nsAString & aMarginHeight) = 0;

  /* attribute DOMString marginWidth; */
  NS_IMETHOD GetMarginWidth(nsAString & aMarginWidth) = 0;
  NS_IMETHOD SetMarginWidth(const nsAString & aMarginWidth) = 0;

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute boolean noResize; */
  NS_IMETHOD GetNoResize(bool *aNoResize) = 0;
  NS_IMETHOD SetNoResize(bool aNoResize) = 0;

  /* attribute DOMString scrolling; */
  NS_IMETHOD GetScrolling(nsAString & aScrolling) = 0;
  NS_IMETHOD SetScrolling(const nsAString & aScrolling) = 0;

  /* attribute DOMString src; */
  NS_IMETHOD GetSrc(nsAString & aSrc) = 0;
  NS_IMETHOD SetSrc(const nsAString & aSrc) = 0;

  /* readonly attribute nsIDOMDocument contentDocument; */
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument) = 0;

  /* readonly attribute nsIDOMWindow contentWindow; */
  NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLFrameElement, NS_IDOMHTMLFRAMEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLFRAMEELEMENT \
  NS_IMETHOD GetFrameBorder(nsAString & aFrameBorder); \
  NS_IMETHOD SetFrameBorder(const nsAString & aFrameBorder); \
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc); \
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc); \
  NS_IMETHOD GetMarginHeight(nsAString & aMarginHeight); \
  NS_IMETHOD SetMarginHeight(const nsAString & aMarginHeight); \
  NS_IMETHOD GetMarginWidth(nsAString & aMarginWidth); \
  NS_IMETHOD SetMarginWidth(const nsAString & aMarginWidth); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD SetName(const nsAString & aName); \
  NS_IMETHOD GetNoResize(bool *aNoResize); \
  NS_IMETHOD SetNoResize(bool aNoResize); \
  NS_IMETHOD GetScrolling(nsAString & aScrolling); \
  NS_IMETHOD SetScrolling(const nsAString & aScrolling); \
  NS_IMETHOD GetSrc(nsAString & aSrc); \
  NS_IMETHOD SetSrc(const nsAString & aSrc); \
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument); \
  NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLFRAMEELEMENT(_to) \
  NS_IMETHOD GetFrameBorder(nsAString & aFrameBorder) { return _to GetFrameBorder(aFrameBorder); } \
  NS_IMETHOD SetFrameBorder(const nsAString & aFrameBorder) { return _to SetFrameBorder(aFrameBorder); } \
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc) { return _to GetLongDesc(aLongDesc); } \
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc) { return _to SetLongDesc(aLongDesc); } \
  NS_IMETHOD GetMarginHeight(nsAString & aMarginHeight) { return _to GetMarginHeight(aMarginHeight); } \
  NS_IMETHOD SetMarginHeight(const nsAString & aMarginHeight) { return _to SetMarginHeight(aMarginHeight); } \
  NS_IMETHOD GetMarginWidth(nsAString & aMarginWidth) { return _to GetMarginWidth(aMarginWidth); } \
  NS_IMETHOD SetMarginWidth(const nsAString & aMarginWidth) { return _to SetMarginWidth(aMarginWidth); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_IMETHOD GetNoResize(bool *aNoResize) { return _to GetNoResize(aNoResize); } \
  NS_IMETHOD SetNoResize(bool aNoResize) { return _to SetNoResize(aNoResize); } \
  NS_IMETHOD GetScrolling(nsAString & aScrolling) { return _to GetScrolling(aScrolling); } \
  NS_IMETHOD SetScrolling(const nsAString & aScrolling) { return _to SetScrolling(aScrolling); } \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return _to GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return _to SetSrc(aSrc); } \
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument) { return _to GetContentDocument(aContentDocument); } \
  NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow) { return _to GetContentWindow(aContentWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLFRAMEELEMENT(_to) \
  NS_IMETHOD GetFrameBorder(nsAString & aFrameBorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameBorder(aFrameBorder); } \
  NS_IMETHOD SetFrameBorder(const nsAString & aFrameBorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFrameBorder(aFrameBorder); } \
  NS_IMETHOD GetLongDesc(nsAString & aLongDesc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLongDesc(aLongDesc); } \
  NS_IMETHOD SetLongDesc(const nsAString & aLongDesc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLongDesc(aLongDesc); } \
  NS_IMETHOD GetMarginHeight(nsAString & aMarginHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginHeight(aMarginHeight); } \
  NS_IMETHOD SetMarginHeight(const nsAString & aMarginHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginHeight(aMarginHeight); } \
  NS_IMETHOD GetMarginWidth(nsAString & aMarginWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMarginWidth(aMarginWidth); } \
  NS_IMETHOD SetMarginWidth(const nsAString & aMarginWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMarginWidth(aMarginWidth); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetNoResize(bool *aNoResize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNoResize(aNoResize); } \
  NS_IMETHOD SetNoResize(bool aNoResize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNoResize(aNoResize); } \
  NS_IMETHOD GetScrolling(nsAString & aScrolling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScrolling(aScrolling); } \
  NS_IMETHOD SetScrolling(const nsAString & aScrolling) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScrolling(aScrolling); } \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrc(aSrc); } \
  NS_IMETHOD GetContentDocument(nsIDOMDocument * *aContentDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentDocument(aContentDocument); } \
  NS_IMETHOD GetContentWindow(nsIDOMWindow * *aContentWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentWindow(aContentWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLFrameElement : public nsIDOMHTMLFrameElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLFRAMEELEMENT

  nsDOMHTMLFrameElement();

private:
  ~nsDOMHTMLFrameElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLFrameElement, nsIDOMHTMLFrameElement)

nsDOMHTMLFrameElement::nsDOMHTMLFrameElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLFrameElement::~nsDOMHTMLFrameElement()
{
  /* destructor code */
}

/* attribute DOMString frameBorder; */
NS_IMETHODIMP nsDOMHTMLFrameElement::GetFrameBorder(nsAString & aFrameBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameElement::SetFrameBorder(const nsAString & aFrameBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString longDesc; */
NS_IMETHODIMP nsDOMHTMLFrameElement::GetLongDesc(nsAString & aLongDesc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameElement::SetLongDesc(const nsAString & aLongDesc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString marginHeight; */
NS_IMETHODIMP nsDOMHTMLFrameElement::GetMarginHeight(nsAString & aMarginHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameElement::SetMarginHeight(const nsAString & aMarginHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString marginWidth; */
NS_IMETHODIMP nsDOMHTMLFrameElement::GetMarginWidth(nsAString & aMarginWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameElement::SetMarginWidth(const nsAString & aMarginWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLFrameElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean noResize; */
NS_IMETHODIMP nsDOMHTMLFrameElement::GetNoResize(bool *aNoResize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameElement::SetNoResize(bool aNoResize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString scrolling; */
NS_IMETHODIMP nsDOMHTMLFrameElement::GetScrolling(nsAString & aScrolling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameElement::SetScrolling(const nsAString & aScrolling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString src; */
NS_IMETHODIMP nsDOMHTMLFrameElement::GetSrc(nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLFrameElement::SetSrc(const nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument contentDocument; */
NS_IMETHODIMP nsDOMHTMLFrameElement::GetContentDocument(nsIDOMDocument * *aContentDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow contentWindow; */
NS_IMETHODIMP nsDOMHTMLFrameElement::GetContentWindow(nsIDOMWindow * *aContentWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLFrameElement_h__ */
