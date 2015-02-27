/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMXULImageElement.idl
 */

#ifndef __gen_nsIDOMXULImageElement_h__
#define __gen_nsIDOMXULImageElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULImageElement */
#define NS_IDOMXULIMAGEELEMENT_IID_STR "d6f60061-263a-4e57-8986-6b0036ea488b"

#define NS_IDOMXULIMAGEELEMENT_IID \
  {0xd6f60061, 0x263a, 0x4e57, \
    { 0x89, 0x86, 0x6b, 0x00, 0x36, 0xea, 0x48, 0x8b }}

class NS_NO_VTABLE nsIDOMXULImageElement : public nsIDOMXULElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULIMAGEELEMENT_IID)

  /* attribute DOMString src; */
  NS_IMETHOD GetSrc(nsAString & aSrc) = 0;
  NS_IMETHOD SetSrc(const nsAString & aSrc) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULImageElement, NS_IDOMXULIMAGEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULIMAGEELEMENT \
  NS_IMETHOD GetSrc(nsAString & aSrc); \
  NS_IMETHOD SetSrc(const nsAString & aSrc); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULIMAGEELEMENT(_to) \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return _to GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return _to SetSrc(aSrc); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULIMAGEELEMENT(_to) \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrc(aSrc); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULImageElement : public nsIDOMXULImageElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULIMAGEELEMENT

  nsDOMXULImageElement();

private:
  ~nsDOMXULImageElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULImageElement, nsIDOMXULImageElement)

nsDOMXULImageElement::nsDOMXULImageElement()
{
  /* member initializers and constructor code */
}

nsDOMXULImageElement::~nsDOMXULImageElement()
{
  /* destructor code */
}

/* attribute DOMString src; */
NS_IMETHODIMP nsDOMXULImageElement::GetSrc(nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULImageElement::SetSrc(const nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULImageElement_h__ */
