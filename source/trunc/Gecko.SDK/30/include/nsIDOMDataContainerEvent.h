/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDataContainerEvent.idl
 */

#ifndef __gen_nsIDOMDataContainerEvent_h__
#define __gen_nsIDOMDataContainerEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

#ifndef __gen_nsIVariant_h__
#include "nsIVariant.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDataContainerEvent */
#define NS_IDOMDATACONTAINEREVENT_IID_STR "dc6b39da-87ff-4b6f-b065-b52602602e06"

#define NS_IDOMDATACONTAINEREVENT_IID \
  {0xdc6b39da, 0x87ff, 0x4b6f, \
    { 0xb0, 0x65, 0xb5, 0x26, 0x02, 0x60, 0x2e, 0x06 }}

class NS_NO_VTABLE nsIDOMDataContainerEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDATACONTAINEREVENT_IID)

  /* nsIVariant getData (in DOMString key); */
  NS_IMETHOD GetData(const nsAString & key, nsIVariant * *_retval) = 0;

  /* void setData (in DOMString key, in nsIVariant data); */
  NS_IMETHOD SetData(const nsAString & key, nsIVariant *data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDataContainerEvent, NS_IDOMDATACONTAINEREVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDATACONTAINEREVENT \
  NS_IMETHOD GetData(const nsAString & key, nsIVariant * *_retval); \
  NS_IMETHOD SetData(const nsAString & key, nsIVariant *data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDATACONTAINEREVENT(_to) \
  NS_IMETHOD GetData(const nsAString & key, nsIVariant * *_retval) { return _to GetData(key, _retval); } \
  NS_IMETHOD SetData(const nsAString & key, nsIVariant *data) { return _to SetData(key, data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDATACONTAINEREVENT(_to) \
  NS_IMETHOD GetData(const nsAString & key, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(key, _retval); } \
  NS_IMETHOD SetData(const nsAString & key, nsIVariant *data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(key, data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDataContainerEvent : public nsIDOMDataContainerEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDATACONTAINEREVENT

  nsDOMDataContainerEvent();

private:
  ~nsDOMDataContainerEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDataContainerEvent, nsIDOMDataContainerEvent)

nsDOMDataContainerEvent::nsDOMDataContainerEvent()
{
  /* member initializers and constructor code */
}

nsDOMDataContainerEvent::~nsDOMDataContainerEvent()
{
  /* destructor code */
}

/* nsIVariant getData (in DOMString key); */
NS_IMETHODIMP nsDOMDataContainerEvent::GetData(const nsAString & key, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setData (in DOMString key, in nsIVariant data); */
NS_IMETHODIMP nsDOMDataContainerEvent::SetData(const nsAString & key, nsIVariant *data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDataContainerEvent_h__ */
