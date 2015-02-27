/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMobileMessageCursorCallback.idl
 */

#ifndef __gen_nsIMobileMessageCursorCallback_h__
#define __gen_nsIMobileMessageCursorCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMobileMessageCursorCallback */
#define NS_IMOBILEMESSAGECURSORCALLBACK_IID_STR "8fd0dba2-032e-4190-a751-07cc3782e93e"

#define NS_IMOBILEMESSAGECURSORCALLBACK_IID \
  {0x8fd0dba2, 0x032e, 0x4190, \
    { 0xa7, 0x51, 0x07, 0xcc, 0x37, 0x82, 0xe9, 0x3e }}

class NS_NO_VTABLE nsIMobileMessageCursorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILEMESSAGECURSORCALLBACK_IID)

  /* void notifyCursorError (in long error); */
  NS_IMETHOD NotifyCursorError(int32_t error) = 0;

  /* void notifyCursorResult (in nsISupports result); */
  NS_IMETHOD NotifyCursorResult(nsISupports *result) = 0;

  /* void notifyCursorDone (); */
  NS_IMETHOD NotifyCursorDone(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileMessageCursorCallback, NS_IMOBILEMESSAGECURSORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILEMESSAGECURSORCALLBACK \
  NS_IMETHOD NotifyCursorError(int32_t error); \
  NS_IMETHOD NotifyCursorResult(nsISupports *result); \
  NS_IMETHOD NotifyCursorDone(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILEMESSAGECURSORCALLBACK(_to) \
  NS_IMETHOD NotifyCursorError(int32_t error) { return _to NotifyCursorError(error); } \
  NS_IMETHOD NotifyCursorResult(nsISupports *result) { return _to NotifyCursorResult(result); } \
  NS_IMETHOD NotifyCursorDone(void) { return _to NotifyCursorDone(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILEMESSAGECURSORCALLBACK(_to) \
  NS_IMETHOD NotifyCursorError(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCursorError(error); } \
  NS_IMETHOD NotifyCursorResult(nsISupports *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCursorResult(result); } \
  NS_IMETHOD NotifyCursorDone(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCursorDone(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileMessageCursorCallback : public nsIMobileMessageCursorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILEMESSAGECURSORCALLBACK

  nsMobileMessageCursorCallback();

private:
  ~nsMobileMessageCursorCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMobileMessageCursorCallback, nsIMobileMessageCursorCallback)

nsMobileMessageCursorCallback::nsMobileMessageCursorCallback()
{
  /* member initializers and constructor code */
}

nsMobileMessageCursorCallback::~nsMobileMessageCursorCallback()
{
  /* destructor code */
}

/* void notifyCursorError (in long error); */
NS_IMETHODIMP nsMobileMessageCursorCallback::NotifyCursorError(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyCursorResult (in nsISupports result); */
NS_IMETHODIMP nsMobileMessageCursorCallback::NotifyCursorResult(nsISupports *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyCursorDone (); */
NS_IMETHODIMP nsMobileMessageCursorCallback::NotifyCursorDone()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileMessageCursorCallback_h__ */
