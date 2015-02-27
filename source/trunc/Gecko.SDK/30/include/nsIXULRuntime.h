/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXULRuntime.idl
 */

#ifndef __gen_nsIXULRuntime_h__
#define __gen_nsIXULRuntime_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

namespace mozilla {
// Simple C++ getter for nsIXULRuntime::browserTabsRemote
bool BrowserTabsRemote();
}

/* starting interface:    nsIXULRuntime */
#define NS_IXULRUNTIME_IID_STR "ef6df588-f0bf-4e38-949e-9de838c228ea"

#define NS_IXULRUNTIME_IID \
  {0xef6df588, 0xf0bf, 0x4e38, \
    { 0x94, 0x9e, 0x9d, 0xe8, 0x38, 0xc2, 0x28, 0xea }}

class NS_NO_VTABLE nsIXULRuntime : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULRUNTIME_IID)

  /* readonly attribute boolean inSafeMode; */
  NS_IMETHOD GetInSafeMode(bool *aInSafeMode) = 0;

  /* attribute boolean logConsoleErrors; */
  NS_IMETHOD GetLogConsoleErrors(bool *aLogConsoleErrors) = 0;
  NS_IMETHOD SetLogConsoleErrors(bool aLogConsoleErrors) = 0;

  /* readonly attribute AUTF8String OS; */
  NS_IMETHOD GetOS(nsACString & aOS) = 0;

  /* readonly attribute AUTF8String XPCOMABI; */
  NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI) = 0;

  /* readonly attribute AUTF8String widgetToolkit; */
  NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit) = 0;

  enum {
    PROCESS_TYPE_DEFAULT = 0U,
    PROCESS_TYPE_PLUGIN = 1U,
    PROCESS_TYPE_CONTENT = 2U,
    PROCESS_TYPE_IPDLUNITTEST = 3U
  };

  /* readonly attribute unsigned long processType; */
  NS_IMETHOD GetProcessType(uint32_t *aProcessType) = 0;

  /* readonly attribute boolean browserTabsRemote; */
  NS_IMETHOD GetBrowserTabsRemote(bool *aBrowserTabsRemote) = 0;

  /* void invalidateCachesOnRestart (); */
  NS_IMETHOD InvalidateCachesOnRestart(void) = 0;

  /* void ensureContentProcess (); */
  NS_IMETHOD EnsureContentProcess(void) = 0;

  /* readonly attribute PRTime replacedLockTime; */
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime) = 0;

  /* readonly attribute DOMString lastRunCrashID; */
  NS_IMETHOD GetLastRunCrashID(nsAString & aLastRunCrashID) = 0;

  /* readonly attribute boolean isReleaseBuild; */
  NS_IMETHOD GetIsReleaseBuild(bool *aIsReleaseBuild) = 0;

  /* readonly attribute boolean isOfficialBranding; */
  NS_IMETHOD GetIsOfficialBranding(bool *aIsOfficialBranding) = 0;

  /* readonly attribute AUTF8String defaultUpdateChannel; */
  NS_IMETHOD GetDefaultUpdateChannel(nsACString & aDefaultUpdateChannel) = 0;

  /* readonly attribute AUTF8String distributionID; */
  NS_IMETHOD GetDistributionID(nsACString & aDistributionID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULRuntime, NS_IXULRUNTIME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULRUNTIME \
  NS_IMETHOD GetInSafeMode(bool *aInSafeMode); \
  NS_IMETHOD GetLogConsoleErrors(bool *aLogConsoleErrors); \
  NS_IMETHOD SetLogConsoleErrors(bool aLogConsoleErrors); \
  NS_IMETHOD GetOS(nsACString & aOS); \
  NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI); \
  NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit); \
  NS_IMETHOD GetProcessType(uint32_t *aProcessType); \
  NS_IMETHOD GetBrowserTabsRemote(bool *aBrowserTabsRemote); \
  NS_IMETHOD InvalidateCachesOnRestart(void); \
  NS_IMETHOD EnsureContentProcess(void); \
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime); \
  NS_IMETHOD GetLastRunCrashID(nsAString & aLastRunCrashID); \
  NS_IMETHOD GetIsReleaseBuild(bool *aIsReleaseBuild); \
  NS_IMETHOD GetIsOfficialBranding(bool *aIsOfficialBranding); \
  NS_IMETHOD GetDefaultUpdateChannel(nsACString & aDefaultUpdateChannel); \
  NS_IMETHOD GetDistributionID(nsACString & aDistributionID); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULRUNTIME(_to) \
  NS_IMETHOD GetInSafeMode(bool *aInSafeMode) { return _to GetInSafeMode(aInSafeMode); } \
  NS_IMETHOD GetLogConsoleErrors(bool *aLogConsoleErrors) { return _to GetLogConsoleErrors(aLogConsoleErrors); } \
  NS_IMETHOD SetLogConsoleErrors(bool aLogConsoleErrors) { return _to SetLogConsoleErrors(aLogConsoleErrors); } \
  NS_IMETHOD GetOS(nsACString & aOS) { return _to GetOS(aOS); } \
  NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI) { return _to GetXPCOMABI(aXPCOMABI); } \
  NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit) { return _to GetWidgetToolkit(aWidgetToolkit); } \
  NS_IMETHOD GetProcessType(uint32_t *aProcessType) { return _to GetProcessType(aProcessType); } \
  NS_IMETHOD GetBrowserTabsRemote(bool *aBrowserTabsRemote) { return _to GetBrowserTabsRemote(aBrowserTabsRemote); } \
  NS_IMETHOD InvalidateCachesOnRestart(void) { return _to InvalidateCachesOnRestart(); } \
  NS_IMETHOD EnsureContentProcess(void) { return _to EnsureContentProcess(); } \
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime) { return _to GetReplacedLockTime(aReplacedLockTime); } \
  NS_IMETHOD GetLastRunCrashID(nsAString & aLastRunCrashID) { return _to GetLastRunCrashID(aLastRunCrashID); } \
  NS_IMETHOD GetIsReleaseBuild(bool *aIsReleaseBuild) { return _to GetIsReleaseBuild(aIsReleaseBuild); } \
  NS_IMETHOD GetIsOfficialBranding(bool *aIsOfficialBranding) { return _to GetIsOfficialBranding(aIsOfficialBranding); } \
  NS_IMETHOD GetDefaultUpdateChannel(nsACString & aDefaultUpdateChannel) { return _to GetDefaultUpdateChannel(aDefaultUpdateChannel); } \
  NS_IMETHOD GetDistributionID(nsACString & aDistributionID) { return _to GetDistributionID(aDistributionID); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULRUNTIME(_to) \
  NS_IMETHOD GetInSafeMode(bool *aInSafeMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInSafeMode(aInSafeMode); } \
  NS_IMETHOD GetLogConsoleErrors(bool *aLogConsoleErrors) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLogConsoleErrors(aLogConsoleErrors); } \
  NS_IMETHOD SetLogConsoleErrors(bool aLogConsoleErrors) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLogConsoleErrors(aLogConsoleErrors); } \
  NS_IMETHOD GetOS(nsACString & aOS) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOS(aOS); } \
  NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXPCOMABI(aXPCOMABI); } \
  NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidgetToolkit(aWidgetToolkit); } \
  NS_IMETHOD GetProcessType(uint32_t *aProcessType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProcessType(aProcessType); } \
  NS_IMETHOD GetBrowserTabsRemote(bool *aBrowserTabsRemote) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBrowserTabsRemote(aBrowserTabsRemote); } \
  NS_IMETHOD InvalidateCachesOnRestart(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateCachesOnRestart(); } \
  NS_IMETHOD EnsureContentProcess(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureContentProcess(); } \
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReplacedLockTime(aReplacedLockTime); } \
  NS_IMETHOD GetLastRunCrashID(nsAString & aLastRunCrashID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastRunCrashID(aLastRunCrashID); } \
  NS_IMETHOD GetIsReleaseBuild(bool *aIsReleaseBuild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsReleaseBuild(aIsReleaseBuild); } \
  NS_IMETHOD GetIsOfficialBranding(bool *aIsOfficialBranding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsOfficialBranding(aIsOfficialBranding); } \
  NS_IMETHOD GetDefaultUpdateChannel(nsACString & aDefaultUpdateChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultUpdateChannel(aDefaultUpdateChannel); } \
  NS_IMETHOD GetDistributionID(nsACString & aDistributionID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDistributionID(aDistributionID); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULRuntime : public nsIXULRuntime
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULRUNTIME

  nsXULRuntime();

private:
  ~nsXULRuntime();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULRuntime, nsIXULRuntime)

nsXULRuntime::nsXULRuntime()
{
  /* member initializers and constructor code */
}

nsXULRuntime::~nsXULRuntime()
{
  /* destructor code */
}

/* readonly attribute boolean inSafeMode; */
NS_IMETHODIMP nsXULRuntime::GetInSafeMode(bool *aInSafeMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean logConsoleErrors; */
NS_IMETHODIMP nsXULRuntime::GetLogConsoleErrors(bool *aLogConsoleErrors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULRuntime::SetLogConsoleErrors(bool aLogConsoleErrors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String OS; */
NS_IMETHODIMP nsXULRuntime::GetOS(nsACString & aOS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String XPCOMABI; */
NS_IMETHODIMP nsXULRuntime::GetXPCOMABI(nsACString & aXPCOMABI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String widgetToolkit; */
NS_IMETHODIMP nsXULRuntime::GetWidgetToolkit(nsACString & aWidgetToolkit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long processType; */
NS_IMETHODIMP nsXULRuntime::GetProcessType(uint32_t *aProcessType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean browserTabsRemote; */
NS_IMETHODIMP nsXULRuntime::GetBrowserTabsRemote(bool *aBrowserTabsRemote)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateCachesOnRestart (); */
NS_IMETHODIMP nsXULRuntime::InvalidateCachesOnRestart()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureContentProcess (); */
NS_IMETHODIMP nsXULRuntime::EnsureContentProcess()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime replacedLockTime; */
NS_IMETHODIMP nsXULRuntime::GetReplacedLockTime(PRTime *aReplacedLockTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastRunCrashID; */
NS_IMETHODIMP nsXULRuntime::GetLastRunCrashID(nsAString & aLastRunCrashID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isReleaseBuild; */
NS_IMETHODIMP nsXULRuntime::GetIsReleaseBuild(bool *aIsReleaseBuild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isOfficialBranding; */
NS_IMETHODIMP nsXULRuntime::GetIsOfficialBranding(bool *aIsOfficialBranding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String defaultUpdateChannel; */
NS_IMETHODIMP nsXULRuntime::GetDefaultUpdateChannel(nsACString & aDefaultUpdateChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String distributionID; */
NS_IMETHODIMP nsXULRuntime::GetDistributionID(nsACString & aDistributionID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULRuntime_h__ */
