/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLBodyElement.idl
 */

#ifndef __gen_nsIDOMHTMLBodyElement_h__
#define __gen_nsIDOMHTMLBodyElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jspubtd.h"

/* starting interface:    nsIDOMHTMLBodyElement */
#define NS_IDOMHTMLBODYELEMENT_IID_STR "4df676f2-7da1-4b88-843c-67d6c3f151df"

#define NS_IDOMHTMLBODYELEMENT_IID \
  {0x4df676f2, 0x7da1, 0x4b88, \
    { 0x84, 0x3c, 0x67, 0xd6, 0xc3, 0xf1, 0x51, 0xdf }}

class NS_NO_VTABLE nsIDOMHTMLBodyElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLBODYELEMENT_IID)

  /* attribute DOMString aLink; */
  NS_IMETHOD GetALink(nsAString & aALink) = 0;
  NS_IMETHOD SetALink(const nsAString & aALink) = 0;

  /* attribute DOMString background; */
  NS_IMETHOD GetBackground(nsAString & aBackground) = 0;
  NS_IMETHOD SetBackground(const nsAString & aBackground) = 0;

  /* attribute DOMString bgColor; */
  NS_IMETHOD GetBgColor(nsAString & aBgColor) = 0;
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) = 0;

  /* attribute DOMString link; */
  NS_IMETHOD GetLink(nsAString & aLink) = 0;
  NS_IMETHOD SetLink(const nsAString & aLink) = 0;

  /* attribute DOMString text; */
  NS_IMETHOD GetText(nsAString & aText) = 0;
  NS_IMETHOD SetText(const nsAString & aText) = 0;

  /* attribute DOMString vLink; */
  NS_IMETHOD GetVLink(nsAString & aVLink) = 0;
  NS_IMETHOD SetVLink(const nsAString & aVLink) = 0;

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

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLBodyElement, NS_IDOMHTMLBODYELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLBODYELEMENT \
  NS_IMETHOD GetALink(nsAString & aALink); \
  NS_IMETHOD SetALink(const nsAString & aALink); \
  NS_IMETHOD GetBackground(nsAString & aBackground); \
  NS_IMETHOD SetBackground(const nsAString & aBackground); \
  NS_IMETHOD GetBgColor(nsAString & aBgColor); \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor); \
  NS_IMETHOD GetLink(nsAString & aLink); \
  NS_IMETHOD SetLink(const nsAString & aLink); \
  NS_IMETHOD GetText(nsAString & aText); \
  NS_IMETHOD SetText(const nsAString & aText); \
  NS_IMETHOD GetVLink(nsAString & aVLink); \
  NS_IMETHOD SetVLink(const nsAString & aVLink); \
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
#define NS_FORWARD_NSIDOMHTMLBODYELEMENT(_to) \
  NS_IMETHOD GetALink(nsAString & aALink) { return _to GetALink(aALink); } \
  NS_IMETHOD SetALink(const nsAString & aALink) { return _to SetALink(aALink); } \
  NS_IMETHOD GetBackground(nsAString & aBackground) { return _to GetBackground(aBackground); } \
  NS_IMETHOD SetBackground(const nsAString & aBackground) { return _to SetBackground(aBackground); } \
  NS_IMETHOD GetBgColor(nsAString & aBgColor) { return _to GetBgColor(aBgColor); } \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) { return _to SetBgColor(aBgColor); } \
  NS_IMETHOD GetLink(nsAString & aLink) { return _to GetLink(aLink); } \
  NS_IMETHOD SetLink(const nsAString & aLink) { return _to SetLink(aLink); } \
  NS_IMETHOD GetText(nsAString & aText) { return _to GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) { return _to SetText(aText); } \
  NS_IMETHOD GetVLink(nsAString & aVLink) { return _to GetVLink(aVLink); } \
  NS_IMETHOD SetVLink(const nsAString & aVLink) { return _to SetVLink(aVLink); } \
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
#define NS_FORWARD_SAFE_NSIDOMHTMLBODYELEMENT(_to) \
  NS_IMETHOD GetALink(nsAString & aALink) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetALink(aALink); } \
  NS_IMETHOD SetALink(const nsAString & aALink) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetALink(aALink); } \
  NS_IMETHOD GetBackground(nsAString & aBackground) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBackground(aBackground); } \
  NS_IMETHOD SetBackground(const nsAString & aBackground) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBackground(aBackground); } \
  NS_IMETHOD GetBgColor(nsAString & aBgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBgColor(aBgColor); } \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBgColor(aBgColor); } \
  NS_IMETHOD GetLink(nsAString & aLink) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLink(aLink); } \
  NS_IMETHOD SetLink(const nsAString & aLink) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLink(aLink); } \
  NS_IMETHOD GetText(nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetText(aText); } \
  NS_IMETHOD SetText(const nsAString & aText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetText(aText); } \
  NS_IMETHOD GetVLink(nsAString & aVLink) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVLink(aVLink); } \
  NS_IMETHOD SetVLink(const nsAString & aVLink) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVLink(aVLink); } \
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
class nsDOMHTMLBodyElement : public nsIDOMHTMLBodyElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLBODYELEMENT

  nsDOMHTMLBodyElement();

private:
  ~nsDOMHTMLBodyElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLBodyElement, nsIDOMHTMLBodyElement)

nsDOMHTMLBodyElement::nsDOMHTMLBodyElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLBodyElement::~nsDOMHTMLBodyElement()
{
  /* destructor code */
}

/* attribute DOMString aLink; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetALink(nsAString & aALink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetALink(const nsAString & aALink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString background; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetBackground(nsAString & aBackground)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetBackground(const nsAString & aBackground)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString bgColor; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetBgColor(nsAString & aBgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetBgColor(const nsAString & aBgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString link; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetLink(nsAString & aLink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetLink(const nsAString & aLink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString text; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetText(nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetText(const nsAString & aText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString vLink; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetVLink(nsAString & aVLink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetVLink(const nsAString & aVLink)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onafterprint; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnafterprint(JSContext* cx, JS::Value *aOnafterprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnafterprint(JSContext* cx, const JS::Value & aOnafterprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onbeforeprint; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnbeforeprint(JSContext* cx, JS::Value *aOnbeforeprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnbeforeprint(JSContext* cx, const JS::Value & aOnbeforeprint)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onbeforeunload; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnbeforeunload(JSContext* cx, JS::Value *aOnbeforeunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnbeforeunload(JSContext* cx, const JS::Value & aOnbeforeunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onhashchange; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnhashchange(JSContext* cx, JS::Value *aOnhashchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnhashchange(JSContext* cx, const JS::Value & aOnhashchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onmessage; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnmessage(JSContext* cx, JS::Value *aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnmessage(JSContext* cx, const JS::Value & aOnmessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onoffline; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnoffline(JSContext* cx, JS::Value *aOnoffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnoffline(JSContext* cx, const JS::Value & aOnoffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ononline; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnonline(JSContext* cx, JS::Value *aOnonline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnonline(JSContext* cx, const JS::Value & aOnonline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpagehide; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnpagehide(JSContext* cx, JS::Value *aOnpagehide)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnpagehide(JSContext* cx, const JS::Value & aOnpagehide)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpageshow; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnpageshow(JSContext* cx, JS::Value *aOnpageshow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnpageshow(JSContext* cx, const JS::Value & aOnpageshow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onpopstate; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnpopstate(JSContext* cx, JS::Value *aOnpopstate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnpopstate(JSContext* cx, const JS::Value & aOnpopstate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onresize; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnresize(JSContext* cx, JS::Value *aOnresize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnresize(JSContext* cx, const JS::Value & aOnresize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onunload; */
NS_IMETHODIMP nsDOMHTMLBodyElement::GetOnunload(JSContext* cx, JS::Value *aOnunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLBodyElement::SetOnunload(JSContext* cx, const JS::Value & aOnunload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLBodyElement_h__ */
