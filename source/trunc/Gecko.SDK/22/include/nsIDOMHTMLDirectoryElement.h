/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLDirectoryElement.idl
 */

#ifndef __gen_nsIDOMHTMLDirectoryElement_h__
#define __gen_nsIDOMHTMLDirectoryElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLDirectoryElement */
#define NS_IDOMHTMLDIRECTORYELEMENT_IID_STR "15b161c4-f471-4681-9368-1114f5d7a129"

#define NS_IDOMHTMLDIRECTORYELEMENT_IID \
  {0x15b161c4, 0xf471, 0x4681, \
    { 0x93, 0x68, 0x11, 0x14, 0xf5, 0xd7, 0xa1, 0x29 }}

class NS_NO_VTABLE nsIDOMHTMLDirectoryElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLDIRECTORYELEMENT_IID)

  /* attribute boolean compact; */
  NS_IMETHOD GetCompact(bool *aCompact) = 0;
  NS_IMETHOD SetCompact(bool aCompact) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLDirectoryElement, NS_IDOMHTMLDIRECTORYELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLDIRECTORYELEMENT \
  NS_IMETHOD GetCompact(bool *aCompact); \
  NS_IMETHOD SetCompact(bool aCompact); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLDIRECTORYELEMENT(_to) \
  NS_IMETHOD GetCompact(bool *aCompact) { return _to GetCompact(aCompact); } \
  NS_IMETHOD SetCompact(bool aCompact) { return _to SetCompact(aCompact); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLDIRECTORYELEMENT(_to) \
  NS_IMETHOD GetCompact(bool *aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompact(aCompact); } \
  NS_IMETHOD SetCompact(bool aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompact(aCompact); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLDirectoryElement : public nsIDOMHTMLDirectoryElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLDIRECTORYELEMENT

  nsDOMHTMLDirectoryElement();

private:
  ~nsDOMHTMLDirectoryElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLDirectoryElement, nsIDOMHTMLDirectoryElement)

nsDOMHTMLDirectoryElement::nsDOMHTMLDirectoryElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLDirectoryElement::~nsDOMHTMLDirectoryElement()
{
  /* destructor code */
}

/* attribute boolean compact; */
NS_IMETHODIMP nsDOMHTMLDirectoryElement::GetCompact(bool *aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDirectoryElement::SetCompact(bool aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLDirectoryElement_h__ */
