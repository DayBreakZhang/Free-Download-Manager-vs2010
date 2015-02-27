/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMXULRelatedElement.idl
 */

#ifndef __gen_nsIDOMXULRelatedElement_h__
#define __gen_nsIDOMXULRelatedElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULRelatedElement */
#define NS_IDOMXULRELATEDELEMENT_IID_STR "9fbac05a-fb27-470d-8e5f-028b2dc54ad0"

#define NS_IDOMXULRELATEDELEMENT_IID \
  {0x9fbac05a, 0xfb27, 0x470d, \
    { 0x8e, 0x5f, 0x02, 0x8b, 0x2d, 0xc5, 0x4a, 0xd0 }}

class NS_NO_VTABLE nsIDOMXULRelatedElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULRELATEDELEMENT_IID)

  /* nsIDOMNode getRelatedElement (in nsIDOMNode aElement); */
  NS_IMETHOD GetRelatedElement(nsIDOMNode *aElement, nsIDOMNode * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULRelatedElement, NS_IDOMXULRELATEDELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULRELATEDELEMENT \
  NS_IMETHOD GetRelatedElement(nsIDOMNode *aElement, nsIDOMNode * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULRELATEDELEMENT(_to) \
  NS_IMETHOD GetRelatedElement(nsIDOMNode *aElement, nsIDOMNode * *_retval) { return _to GetRelatedElement(aElement, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULRELATEDELEMENT(_to) \
  NS_IMETHOD GetRelatedElement(nsIDOMNode *aElement, nsIDOMNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRelatedElement(aElement, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULRelatedElement : public nsIDOMXULRelatedElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULRELATEDELEMENT

  nsDOMXULRelatedElement();

private:
  ~nsDOMXULRelatedElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULRelatedElement, nsIDOMXULRelatedElement)

nsDOMXULRelatedElement::nsDOMXULRelatedElement()
{
  /* member initializers and constructor code */
}

nsDOMXULRelatedElement::~nsDOMXULRelatedElement()
{
  /* destructor code */
}

/* nsIDOMNode getRelatedElement (in nsIDOMNode aElement); */
NS_IMETHODIMP nsDOMXULRelatedElement::GetRelatedElement(nsIDOMNode *aElement, nsIDOMNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULRelatedElement_h__ */
