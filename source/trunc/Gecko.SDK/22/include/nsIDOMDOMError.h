/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/base/nsIDOMDOMError.idl
 */

#ifndef __gen_nsIDOMDOMError_h__
#define __gen_nsIDOMDOMError_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDOMError */
#define NS_IDOMDOMERROR_IID_STR "e4e28307-d409-4cf7-93cd-6ea8e889f87a"

#define NS_IDOMDOMERROR_IID \
  {0xe4e28307, 0xd409, 0x4cf7, \
    { 0x93, 0xcd, 0x6e, 0xa8, 0xe8, 0x89, 0xf8, 0x7a }}

class NS_NO_VTABLE nsIDOMDOMError : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMERROR_IID)

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMError, NS_IDOMDOMERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMERROR \
  NS_IMETHOD GetName(nsAString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMERROR(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMERROR(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMError : public nsIDOMDOMError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMERROR

  nsDOMDOMError();

private:
  ~nsDOMDOMError();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMError, nsIDOMDOMError)

nsDOMDOMError::nsDOMDOMError()
{
  /* member initializers and constructor code */
}

nsDOMDOMError::~nsDOMDOMError()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMDOMError::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMError_h__ */
