/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMBlobEvent.idl
 */

#ifndef __gen_nsIDOMBlobEvent_h__
#define __gen_nsIDOMBlobEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMBlob; /* forward declaration */


/* starting interface:    nsIDOMBlobEvent */
#define NS_IDOMBLOBEVENT_IID_STR "84293ee0-68f5-11e2-9906-cf63ba8c6e43"

#define NS_IDOMBLOBEVENT_IID \
  {0x84293ee0, 0x68f5, 0x11e2, \
    { 0x99, 0x06, 0xcf, 0x63, 0xba, 0x8c, 0x6e, 0x43 }}

class NS_NO_VTABLE nsIDOMBlobEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMBLOBEVENT_IID)

  /* readonly attribute nsIDOMBlob data; */
  NS_IMETHOD GetData(nsIDOMBlob * *aData) = 0;

  /* [noscript] void initBlobEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in nsIDOMBlob aData); */
  NS_IMETHOD InitBlobEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMBlob *aData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMBlobEvent, NS_IDOMBLOBEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMBLOBEVENT \
  NS_IMETHOD GetData(nsIDOMBlob * *aData); \
  NS_IMETHOD InitBlobEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMBlob *aData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMBLOBEVENT(_to) \
  NS_IMETHOD GetData(nsIDOMBlob * *aData) { return _to GetData(aData); } \
  NS_IMETHOD InitBlobEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMBlob *aData) { return _to InitBlobEvent(aType, aCanBubble, aCancelable, aData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMBLOBEVENT(_to) \
  NS_IMETHOD GetData(nsIDOMBlob * *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD InitBlobEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMBlob *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitBlobEvent(aType, aCanBubble, aCancelable, aData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMBlobEvent : public nsIDOMBlobEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMBLOBEVENT

  nsDOMBlobEvent();

private:
  ~nsDOMBlobEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMBlobEvent, nsIDOMBlobEvent)

nsDOMBlobEvent::nsDOMBlobEvent()
{
  /* member initializers and constructor code */
}

nsDOMBlobEvent::~nsDOMBlobEvent()
{
  /* destructor code */
}

/* readonly attribute nsIDOMBlob data; */
NS_IMETHODIMP nsDOMBlobEvent::GetData(nsIDOMBlob * *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initBlobEvent (in DOMString aType, in boolean aCanBubble, in boolean aCancelable, in nsIDOMBlob aData); */
NS_IMETHODIMP nsDOMBlobEvent::InitBlobEvent(const nsAString & aType, bool aCanBubble, bool aCancelable, nsIDOMBlob *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMBlobEvent_h__ */
