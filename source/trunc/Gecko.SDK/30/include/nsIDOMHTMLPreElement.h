/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLPreElement.idl
 */

#ifndef __gen_nsIDOMHTMLPreElement_h__
#define __gen_nsIDOMHTMLPreElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLPreElement */
#define NS_IDOMHTMLPREELEMENT_IID_STR "a2441b77-ad22-4275-b1dd-1b58c044fd04"

#define NS_IDOMHTMLPREELEMENT_IID \
  {0xa2441b77, 0xad22, 0x4275, \
    { 0xb1, 0xdd, 0x1b, 0x58, 0xc0, 0x44, 0xfd, 0x04 }}

class NS_NO_VTABLE nsIDOMHTMLPreElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLPREELEMENT_IID)

  /* attribute long width; */
  NS_IMETHOD GetWidth(int32_t *aWidth) = 0;
  NS_IMETHOD SetWidth(int32_t aWidth) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLPreElement, NS_IDOMHTMLPREELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLPREELEMENT \
  NS_IMETHOD GetWidth(int32_t *aWidth); \
  NS_IMETHOD SetWidth(int32_t aWidth); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLPREELEMENT(_to) \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(int32_t aWidth) { return _to SetWidth(aWidth); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLPREELEMENT(_to) \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(int32_t aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLPreElement : public nsIDOMHTMLPreElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLPREELEMENT

  nsDOMHTMLPreElement();

private:
  ~nsDOMHTMLPreElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLPreElement, nsIDOMHTMLPreElement)

nsDOMHTMLPreElement::nsDOMHTMLPreElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLPreElement::~nsDOMHTMLPreElement()
{
  /* destructor code */
}

/* attribute long width; */
NS_IMETHODIMP nsDOMHTMLPreElement::GetWidth(int32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLPreElement::SetWidth(int32_t aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLPreElement_h__ */
