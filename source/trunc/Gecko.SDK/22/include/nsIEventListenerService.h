/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/events/public/nsIEventListenerService.idl
 */

#ifndef __gen_nsIEventListenerService_h__
#define __gen_nsIEventListenerService_h__


#ifndef __gen_nsIDOMEventListener_h__
#include "nsIDOMEventListener.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventTarget; /* forward declaration */


/* starting interface:    nsIEventListenerInfo */
#define NS_IEVENTLISTENERINFO_IID_STR "cbc2ea6e-4043-4435-ba8f-64cbf6638622"

#define NS_IEVENTLISTENERINFO_IID \
  {0xcbc2ea6e, 0x4043, 0x4435, \
    { 0xba, 0x8f, 0x64, 0xcb, 0xf6, 0x63, 0x86, 0x22 }}

class NS_NO_VTABLE nsIEventListenerInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEVENTLISTENERINFO_IID)

  /* readonly attribute AString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute boolean capturing; */
  NS_IMETHOD GetCapturing(bool *aCapturing) = 0;

  /* readonly attribute boolean allowsUntrusted; */
  NS_IMETHOD GetAllowsUntrusted(bool *aAllowsUntrusted) = 0;

  /* readonly attribute boolean inSystemEventGroup; */
  NS_IMETHOD GetInSystemEventGroup(bool *aInSystemEventGroup) = 0;

  /* AString toSource (); */
  NS_IMETHOD ToSource(nsAString & _retval) = 0;

  /* nsISupports getDebugObject (); */
  NS_IMETHOD GetDebugObject(nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEventListenerInfo, NS_IEVENTLISTENERINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEVENTLISTENERINFO \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetCapturing(bool *aCapturing); \
  NS_IMETHOD GetAllowsUntrusted(bool *aAllowsUntrusted); \
  NS_IMETHOD GetInSystemEventGroup(bool *aInSystemEventGroup); \
  NS_IMETHOD ToSource(nsAString & _retval); \
  NS_IMETHOD GetDebugObject(nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEVENTLISTENERINFO(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetCapturing(bool *aCapturing) { return _to GetCapturing(aCapturing); } \
  NS_IMETHOD GetAllowsUntrusted(bool *aAllowsUntrusted) { return _to GetAllowsUntrusted(aAllowsUntrusted); } \
  NS_IMETHOD GetInSystemEventGroup(bool *aInSystemEventGroup) { return _to GetInSystemEventGroup(aInSystemEventGroup); } \
  NS_IMETHOD ToSource(nsAString & _retval) { return _to ToSource(_retval); } \
  NS_IMETHOD GetDebugObject(nsISupports * *_retval) { return _to GetDebugObject(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEVENTLISTENERINFO(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetCapturing(bool *aCapturing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCapturing(aCapturing); } \
  NS_IMETHOD GetAllowsUntrusted(bool *aAllowsUntrusted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsUntrusted(aAllowsUntrusted); } \
  NS_IMETHOD GetInSystemEventGroup(bool *aInSystemEventGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInSystemEventGroup(aInSystemEventGroup); } \
  NS_IMETHOD ToSource(nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToSource(_retval); } \
  NS_IMETHOD GetDebugObject(nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDebugObject(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEventListenerInfo : public nsIEventListenerInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEVENTLISTENERINFO

  nsEventListenerInfo();

private:
  ~nsEventListenerInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEventListenerInfo, nsIEventListenerInfo)

nsEventListenerInfo::nsEventListenerInfo()
{
  /* member initializers and constructor code */
}

nsEventListenerInfo::~nsEventListenerInfo()
{
  /* destructor code */
}

/* readonly attribute AString type; */
NS_IMETHODIMP nsEventListenerInfo::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean capturing; */
NS_IMETHODIMP nsEventListenerInfo::GetCapturing(bool *aCapturing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean allowsUntrusted; */
NS_IMETHODIMP nsEventListenerInfo::GetAllowsUntrusted(bool *aAllowsUntrusted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean inSystemEventGroup; */
NS_IMETHODIMP nsEventListenerInfo::GetInSystemEventGroup(bool *aInSystemEventGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString toSource (); */
NS_IMETHODIMP nsEventListenerInfo::ToSource(nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getDebugObject (); */
NS_IMETHODIMP nsEventListenerInfo::GetDebugObject(nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIEventListenerService */
#define NS_IEVENTLISTENERSERVICE_IID_STR "f6964bfb-dabe-4cab-9733-be0ee2bf8171"

#define NS_IEVENTLISTENERSERVICE_IID \
  {0xf6964bfb, 0xdabe, 0x4cab, \
    { 0x97, 0x33, 0xbe, 0x0e, 0xe2, 0xbf, 0x81, 0x71 }}

class NS_NO_VTABLE nsIEventListenerService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEVENTLISTENERSERVICE_IID)

  /* void getListenerInfoFor (in nsIDOMEventTarget aEventTarget, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIEventListenerInfo aOutArray); */
  NS_IMETHOD GetListenerInfoFor(nsIDOMEventTarget *aEventTarget, uint32_t *aCount, nsIEventListenerInfo * **aOutArray) = 0;

  /* void getEventTargetChainFor (in nsIDOMEventTarget aEventTarget, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIDOMEventTarget aOutArray); */
  NS_IMETHOD GetEventTargetChainFor(nsIDOMEventTarget *aEventTarget, uint32_t *aCount, nsIDOMEventTarget * **aOutArray) = 0;

  /* boolean hasListenersFor (in nsIDOMEventTarget aEventTarget, in DOMString aType); */
  NS_IMETHOD HasListenersFor(nsIDOMEventTarget *aEventTarget, const nsAString & aType, bool *_retval) = 0;

  /* void addSystemEventListener (in nsIDOMEventTarget target, in DOMString type, in nsIDOMEventListener listener, in boolean useCapture); */
  NS_IMETHOD AddSystemEventListener(nsIDOMEventTarget *target, const nsAString & type, nsIDOMEventListener *listener, bool useCapture) = 0;

  /* void removeSystemEventListener (in nsIDOMEventTarget target, in DOMString type, in nsIDOMEventListener listener, in boolean useCapture); */
  NS_IMETHOD RemoveSystemEventListener(nsIDOMEventTarget *target, const nsAString & type, nsIDOMEventListener *listener, bool useCapture) = 0;

  /* void addListenerForAllEvents (in nsIDOMEventTarget target, in nsIDOMEventListener listener, [optional] in boolean aUseCapture, [optional] in boolean aWantsUntrusted, [optional] in boolean aSystemEventGroup); */
  NS_IMETHOD AddListenerForAllEvents(nsIDOMEventTarget *target, nsIDOMEventListener *listener, bool aUseCapture, bool aWantsUntrusted, bool aSystemEventGroup) = 0;

  /* void removeListenerForAllEvents (in nsIDOMEventTarget target, in nsIDOMEventListener listener, [optional] in boolean aUseCapture, [optional] in boolean aSystemEventGroup); */
  NS_IMETHOD RemoveListenerForAllEvents(nsIDOMEventTarget *target, nsIDOMEventListener *listener, bool aUseCapture, bool aSystemEventGroup) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEventListenerService, NS_IEVENTLISTENERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEVENTLISTENERSERVICE \
  NS_IMETHOD GetListenerInfoFor(nsIDOMEventTarget *aEventTarget, uint32_t *aCount, nsIEventListenerInfo * **aOutArray); \
  NS_IMETHOD GetEventTargetChainFor(nsIDOMEventTarget *aEventTarget, uint32_t *aCount, nsIDOMEventTarget * **aOutArray); \
  NS_IMETHOD HasListenersFor(nsIDOMEventTarget *aEventTarget, const nsAString & aType, bool *_retval); \
  NS_IMETHOD AddSystemEventListener(nsIDOMEventTarget *target, const nsAString & type, nsIDOMEventListener *listener, bool useCapture); \
  NS_IMETHOD RemoveSystemEventListener(nsIDOMEventTarget *target, const nsAString & type, nsIDOMEventListener *listener, bool useCapture); \
  NS_IMETHOD AddListenerForAllEvents(nsIDOMEventTarget *target, nsIDOMEventListener *listener, bool aUseCapture, bool aWantsUntrusted, bool aSystemEventGroup); \
  NS_IMETHOD RemoveListenerForAllEvents(nsIDOMEventTarget *target, nsIDOMEventListener *listener, bool aUseCapture, bool aSystemEventGroup); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEVENTLISTENERSERVICE(_to) \
  NS_IMETHOD GetListenerInfoFor(nsIDOMEventTarget *aEventTarget, uint32_t *aCount, nsIEventListenerInfo * **aOutArray) { return _to GetListenerInfoFor(aEventTarget, aCount, aOutArray); } \
  NS_IMETHOD GetEventTargetChainFor(nsIDOMEventTarget *aEventTarget, uint32_t *aCount, nsIDOMEventTarget * **aOutArray) { return _to GetEventTargetChainFor(aEventTarget, aCount, aOutArray); } \
  NS_IMETHOD HasListenersFor(nsIDOMEventTarget *aEventTarget, const nsAString & aType, bool *_retval) { return _to HasListenersFor(aEventTarget, aType, _retval); } \
  NS_IMETHOD AddSystemEventListener(nsIDOMEventTarget *target, const nsAString & type, nsIDOMEventListener *listener, bool useCapture) { return _to AddSystemEventListener(target, type, listener, useCapture); } \
  NS_IMETHOD RemoveSystemEventListener(nsIDOMEventTarget *target, const nsAString & type, nsIDOMEventListener *listener, bool useCapture) { return _to RemoveSystemEventListener(target, type, listener, useCapture); } \
  NS_IMETHOD AddListenerForAllEvents(nsIDOMEventTarget *target, nsIDOMEventListener *listener, bool aUseCapture, bool aWantsUntrusted, bool aSystemEventGroup) { return _to AddListenerForAllEvents(target, listener, aUseCapture, aWantsUntrusted, aSystemEventGroup); } \
  NS_IMETHOD RemoveListenerForAllEvents(nsIDOMEventTarget *target, nsIDOMEventListener *listener, bool aUseCapture, bool aSystemEventGroup) { return _to RemoveListenerForAllEvents(target, listener, aUseCapture, aSystemEventGroup); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEVENTLISTENERSERVICE(_to) \
  NS_IMETHOD GetListenerInfoFor(nsIDOMEventTarget *aEventTarget, uint32_t *aCount, nsIEventListenerInfo * **aOutArray) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListenerInfoFor(aEventTarget, aCount, aOutArray); } \
  NS_IMETHOD GetEventTargetChainFor(nsIDOMEventTarget *aEventTarget, uint32_t *aCount, nsIDOMEventTarget * **aOutArray) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventTargetChainFor(aEventTarget, aCount, aOutArray); } \
  NS_IMETHOD HasListenersFor(nsIDOMEventTarget *aEventTarget, const nsAString & aType, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasListenersFor(aEventTarget, aType, _retval); } \
  NS_IMETHOD AddSystemEventListener(nsIDOMEventTarget *target, const nsAString & type, nsIDOMEventListener *listener, bool useCapture) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSystemEventListener(target, type, listener, useCapture); } \
  NS_IMETHOD RemoveSystemEventListener(nsIDOMEventTarget *target, const nsAString & type, nsIDOMEventListener *listener, bool useCapture) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSystemEventListener(target, type, listener, useCapture); } \
  NS_IMETHOD AddListenerForAllEvents(nsIDOMEventTarget *target, nsIDOMEventListener *listener, bool aUseCapture, bool aWantsUntrusted, bool aSystemEventGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListenerForAllEvents(target, listener, aUseCapture, aWantsUntrusted, aSystemEventGroup); } \
  NS_IMETHOD RemoveListenerForAllEvents(nsIDOMEventTarget *target, nsIDOMEventListener *listener, bool aUseCapture, bool aSystemEventGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListenerForAllEvents(target, listener, aUseCapture, aSystemEventGroup); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEventListenerService : public nsIEventListenerService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEVENTLISTENERSERVICE

  nsEventListenerService();

private:
  ~nsEventListenerService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEventListenerService, nsIEventListenerService)

nsEventListenerService::nsEventListenerService()
{
  /* member initializers and constructor code */
}

nsEventListenerService::~nsEventListenerService()
{
  /* destructor code */
}

/* void getListenerInfoFor (in nsIDOMEventTarget aEventTarget, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIEventListenerInfo aOutArray); */
NS_IMETHODIMP nsEventListenerService::GetListenerInfoFor(nsIDOMEventTarget *aEventTarget, uint32_t *aCount, nsIEventListenerInfo * **aOutArray)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getEventTargetChainFor (in nsIDOMEventTarget aEventTarget, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIDOMEventTarget aOutArray); */
NS_IMETHODIMP nsEventListenerService::GetEventTargetChainFor(nsIDOMEventTarget *aEventTarget, uint32_t *aCount, nsIDOMEventTarget * **aOutArray)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasListenersFor (in nsIDOMEventTarget aEventTarget, in DOMString aType); */
NS_IMETHODIMP nsEventListenerService::HasListenersFor(nsIDOMEventTarget *aEventTarget, const nsAString & aType, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSystemEventListener (in nsIDOMEventTarget target, in DOMString type, in nsIDOMEventListener listener, in boolean useCapture); */
NS_IMETHODIMP nsEventListenerService::AddSystemEventListener(nsIDOMEventTarget *target, const nsAString & type, nsIDOMEventListener *listener, bool useCapture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSystemEventListener (in nsIDOMEventTarget target, in DOMString type, in nsIDOMEventListener listener, in boolean useCapture); */
NS_IMETHODIMP nsEventListenerService::RemoveSystemEventListener(nsIDOMEventTarget *target, const nsAString & type, nsIDOMEventListener *listener, bool useCapture)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addListenerForAllEvents (in nsIDOMEventTarget target, in nsIDOMEventListener listener, [optional] in boolean aUseCapture, [optional] in boolean aWantsUntrusted, [optional] in boolean aSystemEventGroup); */
NS_IMETHODIMP nsEventListenerService::AddListenerForAllEvents(nsIDOMEventTarget *target, nsIDOMEventListener *listener, bool aUseCapture, bool aWantsUntrusted, bool aSystemEventGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListenerForAllEvents (in nsIDOMEventTarget target, in nsIDOMEventListener listener, [optional] in boolean aUseCapture, [optional] in boolean aSystemEventGroup); */
NS_IMETHODIMP nsEventListenerService::RemoveListenerForAllEvents(nsIDOMEventTarget *target, nsIDOMEventListener *listener, bool aUseCapture, bool aSystemEventGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEventListenerService_h__ */
