/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPowerManagerService.idl
 */

#ifndef __gen_nsIPowerManagerService_h__
#define __gen_nsIPowerManagerService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_POWERMANAGERSERVICE_CID { 0x18c2e238, 0x3a0a, 0x4153, {0x89, 0xfc, 0x16, 0x6b, 0x3b, 0x14, 0x65, 0xa1 } }
#define POWERMANAGERSERVICE_CONTRACTID "@mozilla.org/power/powermanagerservice;1"
class nsIDOMMozWakeLockListener; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIPowerManagerService */
#define NS_IPOWERMANAGERSERVICE_IID_STR "a232e826-07bd-11e2-8a8f-236186ff1a14"

#define NS_IPOWERMANAGERSERVICE_IID \
  {0xa232e826, 0x07bd, 0x11e2, \
    { 0x8a, 0x8f, 0x23, 0x61, 0x86, 0xff, 0x1a, 0x14 }}

class NS_NO_VTABLE nsIPowerManagerService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPOWERMANAGERSERVICE_IID)

  /* void powerOff (); */
  NS_IMETHOD PowerOff(void) = 0;

  /* void reboot (); */
  NS_IMETHOD Reboot(void) = 0;

  /* void restart (); */
  NS_IMETHOD Restart(void) = 0;

  /* void addWakeLockListener (in nsIDOMMozWakeLockListener aListener); */
  NS_IMETHOD AddWakeLockListener(nsIDOMMozWakeLockListener *aListener) = 0;

  /* void removeWakeLockListener (in nsIDOMMozWakeLockListener aListener); */
  NS_IMETHOD RemoveWakeLockListener(nsIDOMMozWakeLockListener *aListener) = 0;

  /* DOMString getWakeLockState (in DOMString aTopic); */
  NS_IMETHOD GetWakeLockState(const nsAString & aTopic, nsAString & _retval) = 0;

  /* nsISupports newWakeLock (in DOMString aTopic, [optional] in nsIDOMWindow aWindow); */
  NS_IMETHOD NewWakeLock(const nsAString & aTopic, nsIDOMWindow *aWindow, nsISupports * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPowerManagerService, NS_IPOWERMANAGERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPOWERMANAGERSERVICE \
  NS_IMETHOD PowerOff(void); \
  NS_IMETHOD Reboot(void); \
  NS_IMETHOD Restart(void); \
  NS_IMETHOD AddWakeLockListener(nsIDOMMozWakeLockListener *aListener); \
  NS_IMETHOD RemoveWakeLockListener(nsIDOMMozWakeLockListener *aListener); \
  NS_IMETHOD GetWakeLockState(const nsAString & aTopic, nsAString & _retval); \
  NS_IMETHOD NewWakeLock(const nsAString & aTopic, nsIDOMWindow *aWindow, nsISupports * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPOWERMANAGERSERVICE(_to) \
  NS_IMETHOD PowerOff(void) { return _to PowerOff(); } \
  NS_IMETHOD Reboot(void) { return _to Reboot(); } \
  NS_IMETHOD Restart(void) { return _to Restart(); } \
  NS_IMETHOD AddWakeLockListener(nsIDOMMozWakeLockListener *aListener) { return _to AddWakeLockListener(aListener); } \
  NS_IMETHOD RemoveWakeLockListener(nsIDOMMozWakeLockListener *aListener) { return _to RemoveWakeLockListener(aListener); } \
  NS_IMETHOD GetWakeLockState(const nsAString & aTopic, nsAString & _retval) { return _to GetWakeLockState(aTopic, _retval); } \
  NS_IMETHOD NewWakeLock(const nsAString & aTopic, nsIDOMWindow *aWindow, nsISupports * *_retval) { return _to NewWakeLock(aTopic, aWindow, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPOWERMANAGERSERVICE(_to) \
  NS_IMETHOD PowerOff(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PowerOff(); } \
  NS_IMETHOD Reboot(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reboot(); } \
  NS_IMETHOD Restart(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Restart(); } \
  NS_IMETHOD AddWakeLockListener(nsIDOMMozWakeLockListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWakeLockListener(aListener); } \
  NS_IMETHOD RemoveWakeLockListener(nsIDOMMozWakeLockListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWakeLockListener(aListener); } \
  NS_IMETHOD GetWakeLockState(const nsAString & aTopic, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWakeLockState(aTopic, _retval); } \
  NS_IMETHOD NewWakeLock(const nsAString & aTopic, nsIDOMWindow *aWindow, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewWakeLock(aTopic, aWindow, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPowerManagerService : public nsIPowerManagerService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPOWERMANAGERSERVICE

  nsPowerManagerService();

private:
  ~nsPowerManagerService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPowerManagerService, nsIPowerManagerService)

nsPowerManagerService::nsPowerManagerService()
{
  /* member initializers and constructor code */
}

nsPowerManagerService::~nsPowerManagerService()
{
  /* destructor code */
}

/* void powerOff (); */
NS_IMETHODIMP nsPowerManagerService::PowerOff()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reboot (); */
NS_IMETHODIMP nsPowerManagerService::Reboot()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restart (); */
NS_IMETHODIMP nsPowerManagerService::Restart()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addWakeLockListener (in nsIDOMMozWakeLockListener aListener); */
NS_IMETHODIMP nsPowerManagerService::AddWakeLockListener(nsIDOMMozWakeLockListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWakeLockListener (in nsIDOMMozWakeLockListener aListener); */
NS_IMETHODIMP nsPowerManagerService::RemoveWakeLockListener(nsIDOMMozWakeLockListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getWakeLockState (in DOMString aTopic); */
NS_IMETHODIMP nsPowerManagerService::GetWakeLockState(const nsAString & aTopic, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports newWakeLock (in DOMString aTopic, [optional] in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsPowerManagerService::NewWakeLock(const nsAString & aTopic, nsIDOMWindow *aWindow, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPowerManagerService_h__ */
