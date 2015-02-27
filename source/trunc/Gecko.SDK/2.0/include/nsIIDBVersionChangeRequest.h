/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/indexedDB/nsIIDBVersionChangeRequest.idl
 */

#ifndef __gen_nsIIDBVersionChangeRequest_h__
#define __gen_nsIIDBVersionChangeRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */


/* starting interface:    nsIIDBVersionChangeRequest */
#define NS_IIDBVERSIONCHANGEREQUEST_IID_STR "aeaabb0d-594a-4c58-ac5e-68ef3bff927d"

#define NS_IIDBVERSIONCHANGEREQUEST_IID \
  {0xaeaabb0d, 0x594a, 0x4c58, \
    { 0xac, 0x5e, 0x68, 0xef, 0x3b, 0xff, 0x92, 0x7d }}

/**
 * IDBReqeust interface.  See
 * http://dev.w3.org/2006/webapi/WebSimpleDB/#idl-def-IDBRequest for more
 * information.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBVersionChangeRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBVERSIONCHANGEREQUEST_IID)

  /* attribute nsIDOMEventListener onblocked; */
  NS_SCRIPTABLE NS_IMETHOD GetOnblocked(nsIDOMEventListener **aOnblocked) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnblocked(nsIDOMEventListener *aOnblocked) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBVersionChangeRequest, NS_IIDBVERSIONCHANGEREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBVERSIONCHANGEREQUEST \
  NS_SCRIPTABLE NS_IMETHOD GetOnblocked(nsIDOMEventListener **aOnblocked); \
  NS_SCRIPTABLE NS_IMETHOD SetOnblocked(nsIDOMEventListener *aOnblocked); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBVERSIONCHANGEREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOnblocked(nsIDOMEventListener **aOnblocked) { return _to GetOnblocked(aOnblocked); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnblocked(nsIDOMEventListener *aOnblocked) { return _to SetOnblocked(aOnblocked); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBVERSIONCHANGEREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOnblocked(nsIDOMEventListener **aOnblocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnblocked(aOnblocked); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnblocked(nsIDOMEventListener *aOnblocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnblocked(aOnblocked); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBVersionChangeRequest : public nsIIDBVersionChangeRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBVERSIONCHANGEREQUEST

  nsIDBVersionChangeRequest();

private:
  ~nsIDBVersionChangeRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBVersionChangeRequest, nsIIDBVersionChangeRequest)

nsIDBVersionChangeRequest::nsIDBVersionChangeRequest()
{
  /* member initializers and constructor code */
}

nsIDBVersionChangeRequest::~nsIDBVersionChangeRequest()
{
  /* destructor code */
}

/* attribute nsIDOMEventListener onblocked; */
NS_IMETHODIMP nsIDBVersionChangeRequest::GetOnblocked(nsIDOMEventListener **aOnblocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBVersionChangeRequest::SetOnblocked(nsIDOMEventListener *aOnblocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBVersionChangeRequest_h__ */
