/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/devicestorage/nsIDOMDeviceStorageChangeEvent.idl
 */

#ifndef __gen_nsIDOMDeviceStorageChangeEvent_h__
#define __gen_nsIDOMDeviceStorageChangeEvent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDeviceStorageChangeEvent */
#define NS_IDOMDEVICESTORAGECHANGEEVENT_IID_STR "30eaf0b9-8f3f-49fe-818e-7b7d9fbf8f95"

#define NS_IDOMDEVICESTORAGECHANGEEVENT_IID \
  {0x30eaf0b9, 0x8f3f, 0x49fe, \
    { 0x81, 0x8e, 0x7b, 0x7d, 0x9f, 0xbf, 0x8f, 0x95 }}

class NS_NO_VTABLE nsIDOMDeviceStorageChangeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDEVICESTORAGECHANGEEVENT_IID)

  /* [noscript] void initDeviceStorageChangeEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString path, in DOMString reason); */
  NS_IMETHOD InitDeviceStorageChangeEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, const nsAString & path, const nsAString & reason) = 0;

  /* readonly attribute DOMString path; */
  NS_IMETHOD GetPath(nsAString & aPath) = 0;

  /* readonly attribute DOMString reason; */
  NS_IMETHOD GetReason(nsAString & aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDeviceStorageChangeEvent, NS_IDOMDEVICESTORAGECHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDEVICESTORAGECHANGEEVENT \
  NS_IMETHOD InitDeviceStorageChangeEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, const nsAString & path, const nsAString & reason); \
  NS_IMETHOD GetPath(nsAString & aPath); \
  NS_IMETHOD GetReason(nsAString & aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDEVICESTORAGECHANGEEVENT(_to) \
  NS_IMETHOD InitDeviceStorageChangeEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, const nsAString & path, const nsAString & reason) { return _to InitDeviceStorageChangeEvent(eventTypeArg, canBubbleArg, cancelableArg, path, reason); } \
  NS_IMETHOD GetPath(nsAString & aPath) { return _to GetPath(aPath); } \
  NS_IMETHOD GetReason(nsAString & aReason) { return _to GetReason(aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDEVICESTORAGECHANGEEVENT(_to) \
  NS_IMETHOD InitDeviceStorageChangeEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, const nsAString & path, const nsAString & reason) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDeviceStorageChangeEvent(eventTypeArg, canBubbleArg, cancelableArg, path, reason); } \
  NS_IMETHOD GetPath(nsAString & aPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPath(aPath); } \
  NS_IMETHOD GetReason(nsAString & aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReason(aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDeviceStorageChangeEvent : public nsIDOMDeviceStorageChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDEVICESTORAGECHANGEEVENT

  nsDOMDeviceStorageChangeEvent();

private:
  ~nsDOMDeviceStorageChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDeviceStorageChangeEvent, nsIDOMDeviceStorageChangeEvent)

nsDOMDeviceStorageChangeEvent::nsDOMDeviceStorageChangeEvent()
{
  /* member initializers and constructor code */
}

nsDOMDeviceStorageChangeEvent::~nsDOMDeviceStorageChangeEvent()
{
  /* destructor code */
}

/* [noscript] void initDeviceStorageChangeEvent (in DOMString eventTypeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString path, in DOMString reason); */
NS_IMETHODIMP nsDOMDeviceStorageChangeEvent::InitDeviceStorageChangeEvent(const nsAString & eventTypeArg, bool canBubbleArg, bool cancelableArg, const nsAString & path, const nsAString & reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString path; */
NS_IMETHODIMP nsDOMDeviceStorageChangeEvent::GetPath(nsAString & aPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString reason; */
NS_IMETHODIMP nsDOMDeviceStorageChangeEvent::GetReason(nsAString & aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDeviceStorageChangeEvent_h__ */
