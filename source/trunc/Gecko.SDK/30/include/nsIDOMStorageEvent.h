/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMStorageEvent.idl
 */

#ifndef __gen_nsIDOMStorageEvent_h__
#define __gen_nsIDOMStorageEvent_h__


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
class nsIDOMStorage; /* forward declaration */


/* starting interface:    nsIDOMStorageEvent */
#define NS_IDOMSTORAGEEVENT_IID_STR "85f04275-4679-4e89-b43f-142bbbab1e89"

#define NS_IDOMSTORAGEEVENT_IID \
  {0x85f04275, 0x4679, 0x4e89, \
    { 0xb4, 0x3f, 0x14, 0x2b, 0xbb, 0xab, 0x1e, 0x89 }}

class NS_NO_VTABLE nsIDOMStorageEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEEVENT_IID)

  /* readonly attribute DOMString key; */
  NS_IMETHOD GetKey(nsAString & aKey) = 0;

  /* readonly attribute DOMString oldValue; */
  NS_IMETHOD GetOldValue(nsAString & aOldValue) = 0;

  /* readonly attribute DOMString newValue; */
  NS_IMETHOD GetNewValue(nsAString & aNewValue) = 0;

  /* readonly attribute DOMString url; */
  NS_IMETHOD GetUrl(nsAString & aUrl) = 0;

  /* readonly attribute nsIDOMStorage storageArea; */
  NS_IMETHOD GetStorageArea(nsIDOMStorage * *aStorageArea) = 0;

  /* void initStorageEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString keyArg, in DOMString oldValueArg, in DOMString newValueArg, in DOMString urlArg, in nsIDOMStorage storageAreaArg); */
  NS_IMETHOD InitStorageEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & keyArg, const nsAString & oldValueArg, const nsAString & newValueArg, const nsAString & urlArg, nsIDOMStorage *storageAreaArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageEvent, NS_IDOMSTORAGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEEVENT \
  NS_IMETHOD GetKey(nsAString & aKey); \
  NS_IMETHOD GetOldValue(nsAString & aOldValue); \
  NS_IMETHOD GetNewValue(nsAString & aNewValue); \
  NS_IMETHOD GetUrl(nsAString & aUrl); \
  NS_IMETHOD GetStorageArea(nsIDOMStorage * *aStorageArea); \
  NS_IMETHOD InitStorageEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & keyArg, const nsAString & oldValueArg, const nsAString & newValueArg, const nsAString & urlArg, nsIDOMStorage *storageAreaArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEEVENT(_to) \
  NS_IMETHOD GetKey(nsAString & aKey) { return _to GetKey(aKey); } \
  NS_IMETHOD GetOldValue(nsAString & aOldValue) { return _to GetOldValue(aOldValue); } \
  NS_IMETHOD GetNewValue(nsAString & aNewValue) { return _to GetNewValue(aNewValue); } \
  NS_IMETHOD GetUrl(nsAString & aUrl) { return _to GetUrl(aUrl); } \
  NS_IMETHOD GetStorageArea(nsIDOMStorage * *aStorageArea) { return _to GetStorageArea(aStorageArea); } \
  NS_IMETHOD InitStorageEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & keyArg, const nsAString & oldValueArg, const nsAString & newValueArg, const nsAString & urlArg, nsIDOMStorage *storageAreaArg) { return _to InitStorageEvent(typeArg, canBubbleArg, cancelableArg, keyArg, oldValueArg, newValueArg, urlArg, storageAreaArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEEVENT(_to) \
  NS_IMETHOD GetKey(nsAString & aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(aKey); } \
  NS_IMETHOD GetOldValue(nsAString & aOldValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOldValue(aOldValue); } \
  NS_IMETHOD GetNewValue(nsAString & aNewValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewValue(aNewValue); } \
  NS_IMETHOD GetUrl(nsAString & aUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUrl(aUrl); } \
  NS_IMETHOD GetStorageArea(nsIDOMStorage * *aStorageArea) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorageArea(aStorageArea); } \
  NS_IMETHOD InitStorageEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & keyArg, const nsAString & oldValueArg, const nsAString & newValueArg, const nsAString & urlArg, nsIDOMStorage *storageAreaArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitStorageEvent(typeArg, canBubbleArg, cancelableArg, keyArg, oldValueArg, newValueArg, urlArg, storageAreaArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageEvent : public nsIDOMStorageEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGEEVENT

  nsDOMStorageEvent();

private:
  ~nsDOMStorageEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageEvent, nsIDOMStorageEvent)

nsDOMStorageEvent::nsDOMStorageEvent()
{
  /* member initializers and constructor code */
}

nsDOMStorageEvent::~nsDOMStorageEvent()
{
  /* destructor code */
}

/* readonly attribute DOMString key; */
NS_IMETHODIMP nsDOMStorageEvent::GetKey(nsAString & aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString oldValue; */
NS_IMETHODIMP nsDOMStorageEvent::GetOldValue(nsAString & aOldValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString newValue; */
NS_IMETHODIMP nsDOMStorageEvent::GetNewValue(nsAString & aNewValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString url; */
NS_IMETHODIMP nsDOMStorageEvent::GetUrl(nsAString & aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMStorage storageArea; */
NS_IMETHODIMP nsDOMStorageEvent::GetStorageArea(nsIDOMStorage * *aStorageArea)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initStorageEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in DOMString keyArg, in DOMString oldValueArg, in DOMString newValueArg, in DOMString urlArg, in nsIDOMStorage storageAreaArg); */
NS_IMETHODIMP nsDOMStorageEvent::InitStorageEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, const nsAString & keyArg, const nsAString & oldValueArg, const nsAString & newValueArg, const nsAString & urlArg, nsIDOMStorage *storageAreaArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageEvent_h__ */
