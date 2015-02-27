/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLStyleElement.idl
 */

#ifndef __gen_nsIDOMHTMLStyleElement_h__
#define __gen_nsIDOMHTMLStyleElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLStyleElement */
#define NS_IDOMHTMLSTYLEELEMENT_IID_STR "fa326d22-8739-4eef-a80e-6449bde605d2"

#define NS_IDOMHTMLSTYLEELEMENT_IID \
  {0xfa326d22, 0x8739, 0x4eef, \
    { 0xa8, 0x0e, 0x64, 0x49, 0xbd, 0xe6, 0x05, 0xd2 }}

class NS_NO_VTABLE nsIDOMHTMLStyleElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLSTYLEELEMENT_IID)

  /* [binaryname(MozDisabled)] attribute boolean disabled; */
  NS_IMETHOD GetMozDisabled(bool *aDisabled) = 0;
  NS_IMETHOD SetMozDisabled(bool aDisabled) = 0;

  /* attribute DOMString media; */
  NS_IMETHOD GetMedia(nsAString & aMedia) = 0;
  NS_IMETHOD SetMedia(const nsAString & aMedia) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute boolean scoped; */
  NS_IMETHOD GetScoped(bool *aScoped) = 0;
  NS_IMETHOD SetScoped(bool aScoped) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLStyleElement, NS_IDOMHTMLSTYLEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLSTYLEELEMENT \
  NS_IMETHOD GetMozDisabled(bool *aDisabled); \
  NS_IMETHOD SetMozDisabled(bool aDisabled); \
  NS_IMETHOD GetMedia(nsAString & aMedia); \
  NS_IMETHOD SetMedia(const nsAString & aMedia); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetScoped(bool *aScoped); \
  NS_IMETHOD SetScoped(bool aScoped); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLSTYLEELEMENT(_to) \
  NS_IMETHOD GetMozDisabled(bool *aDisabled) { return _to GetMozDisabled(aDisabled); } \
  NS_IMETHOD SetMozDisabled(bool aDisabled) { return _to SetMozDisabled(aDisabled); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) { return _to GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) { return _to SetMedia(aMedia); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetScoped(bool *aScoped) { return _to GetScoped(aScoped); } \
  NS_IMETHOD SetScoped(bool aScoped) { return _to SetScoped(aScoped); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLSTYLEELEMENT(_to) \
  NS_IMETHOD GetMozDisabled(bool *aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozDisabled(aDisabled); } \
  NS_IMETHOD SetMozDisabled(bool aDisabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozDisabled(aDisabled); } \
  NS_IMETHOD GetMedia(nsAString & aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMedia(aMedia); } \
  NS_IMETHOD SetMedia(const nsAString & aMedia) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMedia(aMedia); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetScoped(bool *aScoped) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScoped(aScoped); } \
  NS_IMETHOD SetScoped(bool aScoped) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScoped(aScoped); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLStyleElement : public nsIDOMHTMLStyleElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLSTYLEELEMENT

  nsDOMHTMLStyleElement();

private:
  ~nsDOMHTMLStyleElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLStyleElement, nsIDOMHTMLStyleElement)

nsDOMHTMLStyleElement::nsDOMHTMLStyleElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLStyleElement::~nsDOMHTMLStyleElement()
{
  /* destructor code */
}

/* [binaryname(MozDisabled)] attribute boolean disabled; */
NS_IMETHODIMP nsDOMHTMLStyleElement::GetMozDisabled(bool *aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLStyleElement::SetMozDisabled(bool aDisabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString media; */
NS_IMETHODIMP nsDOMHTMLStyleElement::GetMedia(nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLStyleElement::SetMedia(const nsAString & aMedia)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLStyleElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLStyleElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean scoped; */
NS_IMETHODIMP nsDOMHTMLStyleElement::GetScoped(bool *aScoped)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLStyleElement::SetScoped(bool aScoped)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLStyleElement_h__ */
