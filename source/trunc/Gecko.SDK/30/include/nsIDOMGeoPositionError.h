/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMGeoPositionError.idl
 */

#ifndef __gen_nsIDOMGeoPositionError_h__
#define __gen_nsIDOMGeoPositionError_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef GetMessage
#undef GetMessage
#endif

/* starting interface:    nsIDOMGeoPositionError */
#define NS_IDOMGEOPOSITIONERROR_IID_STR "85255cc3-07ba-49fd-bc9b-18d2963daf7f"

#define NS_IDOMGEOPOSITIONERROR_IID \
  {0x85255cc3, 0x07ba, 0x49fd, \
    { 0xbc, 0x9b, 0x18, 0xd2, 0x96, 0x3d, 0xaf, 0x7f }}

class NS_NO_VTABLE nsIDOMGeoPositionError : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOPOSITIONERROR_IID)

  enum {
    PERMISSION_DENIED = 1U,
    POSITION_UNAVAILABLE = 2U,
    TIMEOUT = 3U
  };

  /* readonly attribute short code; */
  NS_IMETHOD GetCode(int16_t *aCode) = 0;

  /* readonly attribute AString message; */
  NS_IMETHOD GetMessage(nsAString & aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoPositionError, NS_IDOMGEOPOSITIONERROR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOPOSITIONERROR \
  NS_IMETHOD GetCode(int16_t *aCode); \
  NS_IMETHOD GetMessage(nsAString & aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOPOSITIONERROR(_to) \
  NS_IMETHOD GetCode(int16_t *aCode) { return _to GetCode(aCode); } \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return _to GetMessage(aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOPOSITIONERROR(_to) \
  NS_IMETHOD GetCode(int16_t *aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } \
  NS_IMETHOD GetMessage(nsAString & aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoPositionError : public nsIDOMGeoPositionError
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOPOSITIONERROR

  nsDOMGeoPositionError();

private:
  ~nsDOMGeoPositionError();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoPositionError, nsIDOMGeoPositionError)

nsDOMGeoPositionError::nsDOMGeoPositionError()
{
  /* member initializers and constructor code */
}

nsDOMGeoPositionError::~nsDOMGeoPositionError()
{
  /* destructor code */
}

/* readonly attribute short code; */
NS_IMETHODIMP nsDOMGeoPositionError::GetCode(int16_t *aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString message; */
NS_IMETHODIMP nsDOMGeoPositionError::GetMessage(nsAString & aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoPositionError_h__ */
