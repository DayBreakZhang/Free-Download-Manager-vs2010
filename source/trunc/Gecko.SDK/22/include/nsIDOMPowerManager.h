/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/power/nsIDOMPowerManager.idl
 */

#ifndef __gen_nsIDOMPowerManager_h__
#define __gen_nsIDOMPowerManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozWakeLockListener; /* forward declaration */


/* starting interface:    nsIDOMMozPowerManager */
#define NS_IDOMMOZPOWERMANAGER_IID_STR "7b181fef-2757-4198-89a0-8c426b8439ea"

#define NS_IDOMMOZPOWERMANAGER_IID \
  {0x7b181fef, 0x2757, 0x4198, \
    { 0x89, 0xa0, 0x8c, 0x42, 0x6b, 0x84, 0x39, 0xea }}

class NS_NO_VTABLE nsIDOMMozPowerManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZPOWERMANAGER_IID)

  /* void powerOff (); */
  NS_IMETHOD PowerOff(void) = 0;

  /* void reboot (); */
  NS_IMETHOD Reboot(void) = 0;

  /* void factoryReset (); */
  NS_IMETHOD FactoryReset(void) = 0;

  /* void addWakeLockListener (in nsIDOMMozWakeLockListener aListener); */
  NS_IMETHOD AddWakeLockListener(nsIDOMMozWakeLockListener *aListener) = 0;

  /* void removeWakeLockListener (in nsIDOMMozWakeLockListener aListener); */
  NS_IMETHOD RemoveWakeLockListener(nsIDOMMozWakeLockListener *aListener) = 0;

  /* DOMString getWakeLockState (in DOMString aTopic); */
  NS_IMETHOD GetWakeLockState(const nsAString & aTopic, nsAString & _retval) = 0;

  /* attribute boolean screenEnabled; */
  NS_IMETHOD GetScreenEnabled(bool *aScreenEnabled) = 0;
  NS_IMETHOD SetScreenEnabled(bool aScreenEnabled) = 0;

  /* attribute double screenBrightness; */
  NS_IMETHOD GetScreenBrightness(double *aScreenBrightness) = 0;
  NS_IMETHOD SetScreenBrightness(double aScreenBrightness) = 0;

  /* attribute boolean cpuSleepAllowed; */
  NS_IMETHOD GetCpuSleepAllowed(bool *aCpuSleepAllowed) = 0;
  NS_IMETHOD SetCpuSleepAllowed(bool aCpuSleepAllowed) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozPowerManager, NS_IDOMMOZPOWERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZPOWERMANAGER \
  NS_IMETHOD PowerOff(void); \
  NS_IMETHOD Reboot(void); \
  NS_IMETHOD FactoryReset(void); \
  NS_IMETHOD AddWakeLockListener(nsIDOMMozWakeLockListener *aListener); \
  NS_IMETHOD RemoveWakeLockListener(nsIDOMMozWakeLockListener *aListener); \
  NS_IMETHOD GetWakeLockState(const nsAString & aTopic, nsAString & _retval); \
  NS_IMETHOD GetScreenEnabled(bool *aScreenEnabled); \
  NS_IMETHOD SetScreenEnabled(bool aScreenEnabled); \
  NS_IMETHOD GetScreenBrightness(double *aScreenBrightness); \
  NS_IMETHOD SetScreenBrightness(double aScreenBrightness); \
  NS_IMETHOD GetCpuSleepAllowed(bool *aCpuSleepAllowed); \
  NS_IMETHOD SetCpuSleepAllowed(bool aCpuSleepAllowed); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZPOWERMANAGER(_to) \
  NS_IMETHOD PowerOff(void) { return _to PowerOff(); } \
  NS_IMETHOD Reboot(void) { return _to Reboot(); } \
  NS_IMETHOD FactoryReset(void) { return _to FactoryReset(); } \
  NS_IMETHOD AddWakeLockListener(nsIDOMMozWakeLockListener *aListener) { return _to AddWakeLockListener(aListener); } \
  NS_IMETHOD RemoveWakeLockListener(nsIDOMMozWakeLockListener *aListener) { return _to RemoveWakeLockListener(aListener); } \
  NS_IMETHOD GetWakeLockState(const nsAString & aTopic, nsAString & _retval) { return _to GetWakeLockState(aTopic, _retval); } \
  NS_IMETHOD GetScreenEnabled(bool *aScreenEnabled) { return _to GetScreenEnabled(aScreenEnabled); } \
  NS_IMETHOD SetScreenEnabled(bool aScreenEnabled) { return _to SetScreenEnabled(aScreenEnabled); } \
  NS_IMETHOD GetScreenBrightness(double *aScreenBrightness) { return _to GetScreenBrightness(aScreenBrightness); } \
  NS_IMETHOD SetScreenBrightness(double aScreenBrightness) { return _to SetScreenBrightness(aScreenBrightness); } \
  NS_IMETHOD GetCpuSleepAllowed(bool *aCpuSleepAllowed) { return _to GetCpuSleepAllowed(aCpuSleepAllowed); } \
  NS_IMETHOD SetCpuSleepAllowed(bool aCpuSleepAllowed) { return _to SetCpuSleepAllowed(aCpuSleepAllowed); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZPOWERMANAGER(_to) \
  NS_IMETHOD PowerOff(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PowerOff(); } \
  NS_IMETHOD Reboot(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reboot(); } \
  NS_IMETHOD FactoryReset(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->FactoryReset(); } \
  NS_IMETHOD AddWakeLockListener(nsIDOMMozWakeLockListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWakeLockListener(aListener); } \
  NS_IMETHOD RemoveWakeLockListener(nsIDOMMozWakeLockListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWakeLockListener(aListener); } \
  NS_IMETHOD GetWakeLockState(const nsAString & aTopic, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWakeLockState(aTopic, _retval); } \
  NS_IMETHOD GetScreenEnabled(bool *aScreenEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenEnabled(aScreenEnabled); } \
  NS_IMETHOD SetScreenEnabled(bool aScreenEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScreenEnabled(aScreenEnabled); } \
  NS_IMETHOD GetScreenBrightness(double *aScreenBrightness) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenBrightness(aScreenBrightness); } \
  NS_IMETHOD SetScreenBrightness(double aScreenBrightness) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetScreenBrightness(aScreenBrightness); } \
  NS_IMETHOD GetCpuSleepAllowed(bool *aCpuSleepAllowed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCpuSleepAllowed(aCpuSleepAllowed); } \
  NS_IMETHOD SetCpuSleepAllowed(bool aCpuSleepAllowed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCpuSleepAllowed(aCpuSleepAllowed); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozPowerManager : public nsIDOMMozPowerManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZPOWERMANAGER

  nsDOMMozPowerManager();

private:
  ~nsDOMMozPowerManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozPowerManager, nsIDOMMozPowerManager)

nsDOMMozPowerManager::nsDOMMozPowerManager()
{
  /* member initializers and constructor code */
}

nsDOMMozPowerManager::~nsDOMMozPowerManager()
{
  /* destructor code */
}

/* void powerOff (); */
NS_IMETHODIMP nsDOMMozPowerManager::PowerOff()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reboot (); */
NS_IMETHODIMP nsDOMMozPowerManager::Reboot()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void factoryReset (); */
NS_IMETHODIMP nsDOMMozPowerManager::FactoryReset()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addWakeLockListener (in nsIDOMMozWakeLockListener aListener); */
NS_IMETHODIMP nsDOMMozPowerManager::AddWakeLockListener(nsIDOMMozWakeLockListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWakeLockListener (in nsIDOMMozWakeLockListener aListener); */
NS_IMETHODIMP nsDOMMozPowerManager::RemoveWakeLockListener(nsIDOMMozWakeLockListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getWakeLockState (in DOMString aTopic); */
NS_IMETHODIMP nsDOMMozPowerManager::GetWakeLockState(const nsAString & aTopic, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean screenEnabled; */
NS_IMETHODIMP nsDOMMozPowerManager::GetScreenEnabled(bool *aScreenEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozPowerManager::SetScreenEnabled(bool aScreenEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double screenBrightness; */
NS_IMETHODIMP nsDOMMozPowerManager::GetScreenBrightness(double *aScreenBrightness)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozPowerManager::SetScreenBrightness(double aScreenBrightness)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean cpuSleepAllowed; */
NS_IMETHODIMP nsDOMMozPowerManager::GetCpuSleepAllowed(bool *aCpuSleepAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozPowerManager::SetCpuSleepAllowed(bool aCpuSleepAllowed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPowerManager_h__ */
