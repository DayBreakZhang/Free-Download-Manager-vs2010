/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/power/nsIDOMWakeLock.idl
 */

#ifndef __gen_nsIDOMWakeLock_h__
#define __gen_nsIDOMWakeLock_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozWakeLock */
#define NS_IDOMMOZWAKELOCK_IID_STR "2e61eed1-5983-4562-8f26-fd361ab4a00d"

#define NS_IDOMMOZWAKELOCK_IID \
  {0x2e61eed1, 0x5983, 0x4562, \
    { 0x8f, 0x26, 0xfd, 0x36, 0x1a, 0xb4, 0xa0, 0x0d }}

class NS_NO_VTABLE nsIDOMMozWakeLock : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZWAKELOCK_IID)

  /* readonly attribute DOMString topic; */
  NS_IMETHOD GetTopic(nsAString & aTopic) = 0;

  /* void unlock (); */
  NS_IMETHOD Unlock(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozWakeLock, NS_IDOMMOZWAKELOCK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZWAKELOCK \
  NS_IMETHOD GetTopic(nsAString & aTopic); \
  NS_IMETHOD Unlock(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZWAKELOCK(_to) \
  NS_IMETHOD GetTopic(nsAString & aTopic) { return _to GetTopic(aTopic); } \
  NS_IMETHOD Unlock(void) { return _to Unlock(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZWAKELOCK(_to) \
  NS_IMETHOD GetTopic(nsAString & aTopic) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTopic(aTopic); } \
  NS_IMETHOD Unlock(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unlock(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozWakeLock : public nsIDOMMozWakeLock
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZWAKELOCK

  nsDOMMozWakeLock();

private:
  ~nsDOMMozWakeLock();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozWakeLock, nsIDOMMozWakeLock)

nsDOMMozWakeLock::nsDOMMozWakeLock()
{
  /* member initializers and constructor code */
}

nsDOMMozWakeLock::~nsDOMMozWakeLock()
{
  /* destructor code */
}

/* readonly attribute DOMString topic; */
NS_IMETHODIMP nsDOMMozWakeLock::GetTopic(nsAString & aTopic)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlock (); */
NS_IMETHODIMP nsDOMMozWakeLock::Unlock()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWakeLock_h__ */
