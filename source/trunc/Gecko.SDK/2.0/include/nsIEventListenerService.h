/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/content/events/public/nsIEventListenerService.idl
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

/**
 * An instance of this interface describes how an event listener
 * was added to an event target.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIEventListenerInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEVENTLISTENERINFO_IID)

  /**
   * The type of the event for which the listener was added.
   */
  /* readonly attribute AString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute boolean capturing; */
  NS_SCRIPTABLE NS_IMETHOD GetCapturing(PRBool *aCapturing) = 0;

  /* readonly attribute boolean allowsUntrusted; */
  NS_SCRIPTABLE NS_IMETHOD GetAllowsUntrusted(PRBool *aAllowsUntrusted) = 0;

  /* readonly attribute boolean inSystemEventGroup; */
  NS_SCRIPTABLE NS_IMETHOD GetInSystemEventGroup(PRBool *aInSystemEventGroup) = 0;

  /**
   * Tries to serialize event listener to a string.
   * Returns null if serialization isn't possible
   * (for example with C++ listeners).
   */
  /* AString toSource (); */
  NS_SCRIPTABLE NS_IMETHOD ToSource(nsAString & _retval NS_OUTPARAM) = 0;

  /**
   * If jsdIDebuggerService is active and the listener is implemented in JS,
   * this returns the listener as a jsdIValue. Otherwise null.
   */
  /* nsISupports getDebugObject (); */
  NS_SCRIPTABLE NS_IMETHOD GetDebugObject(nsISupports **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEventListenerInfo, NS_IEVENTLISTENERINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEVENTLISTENERINFO \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetCapturing(PRBool *aCapturing); \
  NS_SCRIPTABLE NS_IMETHOD GetAllowsUntrusted(PRBool *aAllowsUntrusted); \
  NS_SCRIPTABLE NS_IMETHOD GetInSystemEventGroup(PRBool *aInSystemEventGroup); \
  NS_SCRIPTABLE NS_IMETHOD ToSource(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetDebugObject(nsISupports **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEVENTLISTENERINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetCapturing(PRBool *aCapturing) { return _to GetCapturing(aCapturing); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowsUntrusted(PRBool *aAllowsUntrusted) { return _to GetAllowsUntrusted(aAllowsUntrusted); } \
  NS_SCRIPTABLE NS_IMETHOD GetInSystemEventGroup(PRBool *aInSystemEventGroup) { return _to GetInSystemEventGroup(aInSystemEventGroup); } \
  NS_SCRIPTABLE NS_IMETHOD ToSource(nsAString & _retval NS_OUTPARAM) { return _to ToSource(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDebugObject(nsISupports **_retval NS_OUTPARAM) { return _to GetDebugObject(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEVENTLISTENERINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetCapturing(PRBool *aCapturing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCapturing(aCapturing); } \
  NS_SCRIPTABLE NS_IMETHOD GetAllowsUntrusted(PRBool *aAllowsUntrusted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowsUntrusted(aAllowsUntrusted); } \
  NS_SCRIPTABLE NS_IMETHOD GetInSystemEventGroup(PRBool *aInSystemEventGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInSystemEventGroup(aInSystemEventGroup); } \
  NS_SCRIPTABLE NS_IMETHOD ToSource(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToSource(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetDebugObject(nsISupports **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDebugObject(_retval); } 

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
NS_IMETHODIMP nsEventListenerInfo::GetCapturing(PRBool *aCapturing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean allowsUntrusted; */
NS_IMETHODIMP nsEventListenerInfo::GetAllowsUntrusted(PRBool *aAllowsUntrusted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean inSystemEventGroup; */
NS_IMETHODIMP nsEventListenerInfo::GetInSystemEventGroup(PRBool *aInSystemEventGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString toSource (); */
NS_IMETHODIMP nsEventListenerInfo::ToSource(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getDebugObject (); */
NS_IMETHODIMP nsEventListenerInfo::GetDebugObject(nsISupports **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIEventListenerService */
#define NS_IEVENTLISTENERSERVICE_IID_STR "7be78bb6-33f7-4f31-b3f3-97eefaff2762"

#define NS_IEVENTLISTENERSERVICE_IID \
  {0x7be78bb6, 0x33f7, 0x4f31, \
    { 0xb3, 0xf3, 0x97, 0xee, 0xfa, 0xff, 0x27, 0x62 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIEventListenerService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEVENTLISTENERSERVICE_IID)

  /**
   * Returns an array of nsIEventListenerInfo objects.
   * If aEventTarget doesn't have any listeners, this returns null.
   */
  /* void getListenerInfoFor (in nsIDOMEventTarget aEventTarget, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIEventListenerInfo aOutArray); */
  NS_SCRIPTABLE NS_IMETHOD GetListenerInfoFor(nsIDOMEventTarget *aEventTarget, PRUint32 *aCount NS_OUTPARAM, nsIEventListenerInfo ***aOutArray NS_OUTPARAM) = 0;

  /**
   * Returns an array of event targets.
   * aEventTarget will be at index 0.
   * The objects are the ones that would be used as DOMEvent.currentTarget while
   * dispatching an event to aEventTarget
   * @note Some events, especially 'load', may actually have a shorter
   *       event target chain than what this methods returns.
  */
  /* void getEventTargetChainFor (in nsIDOMEventTarget aEventTarget, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIDOMEventTarget aOutArray); */
  NS_SCRIPTABLE NS_IMETHOD GetEventTargetChainFor(nsIDOMEventTarget *aEventTarget, PRUint32 *aCount NS_OUTPARAM, nsIDOMEventTarget ***aOutArray NS_OUTPARAM) = 0;

  /**
   * Returns system event group.
   */
  /* readonly attribute nsIDOMEventGroup systemEventGroup; */
  NS_SCRIPTABLE NS_IMETHOD GetSystemEventGroup(nsIDOMEventGroup **aSystemEventGroup) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEventListenerService, NS_IEVENTLISTENERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEVENTLISTENERSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetListenerInfoFor(nsIDOMEventTarget *aEventTarget, PRUint32 *aCount NS_OUTPARAM, nsIEventListenerInfo ***aOutArray NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEventTargetChainFor(nsIDOMEventTarget *aEventTarget, PRUint32 *aCount NS_OUTPARAM, nsIDOMEventTarget ***aOutArray NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSystemEventGroup(nsIDOMEventGroup **aSystemEventGroup); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEVENTLISTENERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetListenerInfoFor(nsIDOMEventTarget *aEventTarget, PRUint32 *aCount NS_OUTPARAM, nsIEventListenerInfo ***aOutArray NS_OUTPARAM) { return _to GetListenerInfoFor(aEventTarget, aCount, aOutArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetEventTargetChainFor(nsIDOMEventTarget *aEventTarget, PRUint32 *aCount NS_OUTPARAM, nsIDOMEventTarget ***aOutArray NS_OUTPARAM) { return _to GetEventTargetChainFor(aEventTarget, aCount, aOutArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetSystemEventGroup(nsIDOMEventGroup **aSystemEventGroup) { return _to GetSystemEventGroup(aSystemEventGroup); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEVENTLISTENERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetListenerInfoFor(nsIDOMEventTarget *aEventTarget, PRUint32 *aCount NS_OUTPARAM, nsIEventListenerInfo ***aOutArray NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListenerInfoFor(aEventTarget, aCount, aOutArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetEventTargetChainFor(nsIDOMEventTarget *aEventTarget, PRUint32 *aCount NS_OUTPARAM, nsIDOMEventTarget ***aOutArray NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventTargetChainFor(aEventTarget, aCount, aOutArray); } \
  NS_SCRIPTABLE NS_IMETHOD GetSystemEventGroup(nsIDOMEventGroup **aSystemEventGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSystemEventGroup(aSystemEventGroup); } 

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
NS_IMETHODIMP nsEventListenerService::GetListenerInfoFor(nsIDOMEventTarget *aEventTarget, PRUint32 *aCount NS_OUTPARAM, nsIEventListenerInfo ***aOutArray NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getEventTargetChainFor (in nsIDOMEventTarget aEventTarget, [optional] out unsigned long aCount, [array, size_is (aCount), retval] out nsIDOMEventTarget aOutArray); */
NS_IMETHODIMP nsEventListenerService::GetEventTargetChainFor(nsIDOMEventTarget *aEventTarget, PRUint32 *aCount NS_OUTPARAM, nsIDOMEventTarget ***aOutArray NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEventGroup systemEventGroup; */
NS_IMETHODIMP nsEventListenerService::GetSystemEventGroup(nsIDOMEventGroup **aSystemEventGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEventListenerService_h__ */
