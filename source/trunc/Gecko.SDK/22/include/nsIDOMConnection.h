/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/network/interfaces/nsIDOMConnection.idl
 */

#ifndef __gen_nsIDOMConnection_h__
#define __gen_nsIDOMConnection_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */


/* starting interface:    nsIDOMMozConnection */
#define NS_IDOMMOZCONNECTION_IID_STR "a0eb16f3-5fa2-4cbd-bf7a-4ce7704b13ea"

#define NS_IDOMMOZCONNECTION_IID \
  {0xa0eb16f3, 0x5fa2, 0x4cbd, \
    { 0xbf, 0x7a, 0x4c, 0xe7, 0x70, 0x4b, 0x13, 0xea }}

class NS_NO_VTABLE nsIDOMMozConnection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZCONNECTION_IID)

  /* readonly attribute double bandwidth; */
  NS_IMETHOD GetBandwidth(double *aBandwidth) = 0;

  /* readonly attribute boolean metered; */
  NS_IMETHOD GetMetered(bool *aMetered) = 0;

  /* [implicit_jscontext] attribute jsval onchange; */
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange) = 0;
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozConnection, NS_IDOMMOZCONNECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZCONNECTION \
  NS_IMETHOD GetBandwidth(double *aBandwidth); \
  NS_IMETHOD GetMetered(bool *aMetered); \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange); \
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZCONNECTION(_to) \
  NS_IMETHOD GetBandwidth(double *aBandwidth) { return _to GetBandwidth(aBandwidth); } \
  NS_IMETHOD GetMetered(bool *aMetered) { return _to GetMetered(aMetered); } \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange) { return _to GetOnchange(cx, aOnchange); } \
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange) { return _to SetOnchange(cx, aOnchange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZCONNECTION(_to) \
  NS_IMETHOD GetBandwidth(double *aBandwidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBandwidth(aBandwidth); } \
  NS_IMETHOD GetMetered(bool *aMetered) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMetered(aMetered); } \
  NS_IMETHOD GetOnchange(JSContext* cx, JS::Value *aOnchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchange(cx, aOnchange); } \
  NS_IMETHOD SetOnchange(JSContext* cx, const JS::Value & aOnchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchange(cx, aOnchange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozConnection : public nsIDOMMozConnection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZCONNECTION

  nsDOMMozConnection();

private:
  ~nsDOMMozConnection();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozConnection, nsIDOMMozConnection)

nsDOMMozConnection::nsDOMMozConnection()
{
  /* member initializers and constructor code */
}

nsDOMMozConnection::~nsDOMMozConnection()
{
  /* destructor code */
}

/* readonly attribute double bandwidth; */
NS_IMETHODIMP nsDOMMozConnection::GetBandwidth(double *aBandwidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean metered; */
NS_IMETHODIMP nsDOMMozConnection::GetMetered(bool *aMetered)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onchange; */
NS_IMETHODIMP nsDOMMozConnection::GetOnchange(JSContext* cx, JS::Value *aOnchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozConnection::SetOnchange(JSContext* cx, const JS::Value & aOnchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMConnection_h__ */
