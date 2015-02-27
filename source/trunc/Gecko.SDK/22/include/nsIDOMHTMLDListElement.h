/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLDListElement.idl
 */

#ifndef __gen_nsIDOMHTMLDListElement_h__
#define __gen_nsIDOMHTMLDListElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLDListElement */
#define NS_IDOMHTMLDLISTELEMENT_IID_STR "e611c0c1-d5ea-4d25-b9e5-08d4cafd0151"

#define NS_IDOMHTMLDLISTELEMENT_IID \
  {0xe611c0c1, 0xd5ea, 0x4d25, \
    { 0xb9, 0xe5, 0x08, 0xd4, 0xca, 0xfd, 0x01, 0x51 }}

class NS_NO_VTABLE nsIDOMHTMLDListElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLDLISTELEMENT_IID)

  /* attribute boolean compact; */
  NS_IMETHOD GetCompact(bool *aCompact) = 0;
  NS_IMETHOD SetCompact(bool aCompact) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLDListElement, NS_IDOMHTMLDLISTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLDLISTELEMENT \
  NS_IMETHOD GetCompact(bool *aCompact); \
  NS_IMETHOD SetCompact(bool aCompact); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLDLISTELEMENT(_to) \
  NS_IMETHOD GetCompact(bool *aCompact) { return _to GetCompact(aCompact); } \
  NS_IMETHOD SetCompact(bool aCompact) { return _to SetCompact(aCompact); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLDLISTELEMENT(_to) \
  NS_IMETHOD GetCompact(bool *aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompact(aCompact); } \
  NS_IMETHOD SetCompact(bool aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompact(aCompact); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLDListElement : public nsIDOMHTMLDListElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLDLISTELEMENT

  nsDOMHTMLDListElement();

private:
  ~nsDOMHTMLDListElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLDListElement, nsIDOMHTMLDListElement)

nsDOMHTMLDListElement::nsDOMHTMLDListElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLDListElement::~nsDOMHTMLDListElement()
{
  /* destructor code */
}

/* attribute boolean compact; */
NS_IMETHODIMP nsDOMHTMLDListElement::GetCompact(bool *aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDListElement::SetCompact(bool aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLDListElement_h__ */
