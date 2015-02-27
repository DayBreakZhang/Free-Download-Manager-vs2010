/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMProgressEvent.idl
 */

#ifndef __gen_nsIDOMProgressEvent_h__
#define __gen_nsIDOMProgressEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMProgressEvent */
#define NS_IDOMPROGRESSEVENT_IID_STR "e0682338-4c3f-4d3a-9487-d7492ea76335"

#define NS_IDOMPROGRESSEVENT_IID \
  {0xe0682338, 0x4c3f, 0x4d3a, \
    { 0x94, 0x87, 0xd7, 0x49, 0x2e, 0xa7, 0x63, 0x35 }}

class NS_NO_VTABLE nsIDOMProgressEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPROGRESSEVENT_IID)

  /* readonly attribute boolean lengthComputable; */
  NS_IMETHOD GetLengthComputable(bool *aLengthComputable) = 0;

  /* readonly attribute unsigned long long loaded; */
  NS_IMETHOD GetLoaded(uint64_t *aLoaded) = 0;

  /* readonly attribute unsigned long long total; */
  NS_IMETHOD GetTotal(uint64_t *aTotal) = 0;

  /* [noscript] void initProgressEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in boolean lengthComputableArg, in unsigned long long loadedArg, in unsigned long long totalArg); */
  NS_IMETHOD InitProgressEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, bool lengthComputableArg, uint64_t loadedArg, uint64_t totalArg) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMProgressEvent, NS_IDOMPROGRESSEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPROGRESSEVENT \
  NS_IMETHOD GetLengthComputable(bool *aLengthComputable); \
  NS_IMETHOD GetLoaded(uint64_t *aLoaded); \
  NS_IMETHOD GetTotal(uint64_t *aTotal); \
  NS_IMETHOD InitProgressEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, bool lengthComputableArg, uint64_t loadedArg, uint64_t totalArg); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPROGRESSEVENT(_to) \
  NS_IMETHOD GetLengthComputable(bool *aLengthComputable) { return _to GetLengthComputable(aLengthComputable); } \
  NS_IMETHOD GetLoaded(uint64_t *aLoaded) { return _to GetLoaded(aLoaded); } \
  NS_IMETHOD GetTotal(uint64_t *aTotal) { return _to GetTotal(aTotal); } \
  NS_IMETHOD InitProgressEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, bool lengthComputableArg, uint64_t loadedArg, uint64_t totalArg) { return _to InitProgressEvent(typeArg, canBubbleArg, cancelableArg, lengthComputableArg, loadedArg, totalArg); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPROGRESSEVENT(_to) \
  NS_IMETHOD GetLengthComputable(bool *aLengthComputable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLengthComputable(aLengthComputable); } \
  NS_IMETHOD GetLoaded(uint64_t *aLoaded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoaded(aLoaded); } \
  NS_IMETHOD GetTotal(uint64_t *aTotal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotal(aTotal); } \
  NS_IMETHOD InitProgressEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, bool lengthComputableArg, uint64_t loadedArg, uint64_t totalArg) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitProgressEvent(typeArg, canBubbleArg, cancelableArg, lengthComputableArg, loadedArg, totalArg); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMProgressEvent : public nsIDOMProgressEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPROGRESSEVENT

  nsDOMProgressEvent();

private:
  ~nsDOMProgressEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMProgressEvent, nsIDOMProgressEvent)

nsDOMProgressEvent::nsDOMProgressEvent()
{
  /* member initializers and constructor code */
}

nsDOMProgressEvent::~nsDOMProgressEvent()
{
  /* destructor code */
}

/* readonly attribute boolean lengthComputable; */
NS_IMETHODIMP nsDOMProgressEvent::GetLengthComputable(bool *aLengthComputable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long loaded; */
NS_IMETHODIMP nsDOMProgressEvent::GetLoaded(uint64_t *aLoaded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long total; */
NS_IMETHODIMP nsDOMProgressEvent::GetTotal(uint64_t *aTotal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initProgressEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean cancelableArg, in boolean lengthComputableArg, in unsigned long long loadedArg, in unsigned long long totalArg); */
NS_IMETHODIMP nsDOMProgressEvent::InitProgressEvent(const nsAString & typeArg, bool canBubbleArg, bool cancelableArg, bool lengthComputableArg, uint64_t loadedArg, uint64_t totalArg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMProgressEvent_h__ */
