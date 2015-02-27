/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/xpcom/system/nsIXULRuntime.idl
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

/* starting interface:    nsIXULRuntime */
#define NS_IXULRUNTIME_IID_STR "7685dac8-3637-4660-a544-928c5ec0e714"

#define NS_IXULRUNTIME_IID \
  {0x7685dac8, 0x3637, 0x4660, \
    { 0xa5, 0x44, 0x92, 0x8c, 0x5e, 0xc0, 0xe7, 0x14 }}

/**
 * Provides information about the XUL runtime.
 * @status UNSTABLE - This interface is not frozen and will probably change in
 *                    future releases. If you need this functionality to be
 *                    stable/frozen, please contact Benjamin Smedberg.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIXULRuntime : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULRUNTIME_IID)

  /**
   * Whether the application was launched in safe mode.
   */
  /* readonly attribute boolean inSafeMode; */
  NS_SCRIPTABLE NS_IMETHOD GetInSafeMode(PRBool *aInSafeMode) = 0;

  /**
   * Whether to write console errors to a log file. If a component
   * encounters startup errors that might prevent the app from showing
   * proper UI, it should set this flag to "true".
   */
  /* attribute boolean logConsoleErrors; */
  NS_SCRIPTABLE NS_IMETHOD GetLogConsoleErrors(PRBool *aLogConsoleErrors) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLogConsoleErrors(PRBool aLogConsoleErrors) = 0;

  /**
   * A string tag identifying the current operating system. This is taken
   * from the OS_TARGET configure variable. It will always be available.
   */
  /* readonly attribute AUTF8String OS; */
  NS_SCRIPTABLE NS_IMETHOD GetOS(nsACString & aOS) = 0;

  /**
   * A string tag identifying the binary ABI of the current processor and
   * compiler vtable. This is taken from the TARGET_XPCOM_ABI configure
   * variable. It may not be available on all platforms, especially
   * unusual processor or compiler combinations.
   *
   * The result takes the form <processor>-<compilerABI>, for example:
   *   x86-msvc
   *   ppc-gcc3
   *
   * This value should almost always be used in combination with "OS".
   *
   * @throw NS_ERROR_NOT_AVAILABLE if not available.
   */
  /* readonly attribute AUTF8String XPCOMABI; */
  NS_SCRIPTABLE NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI) = 0;

  /**
   * A string tag identifying the target widget toolkit in use.
   * This is taken from the MOZ_WIDGET_TOOLKIT configure variable.
   */
  /* readonly attribute AUTF8String widgetToolkit; */
  NS_SCRIPTABLE NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit) = 0;

  /**
   * The legal values of processType.
   */
  enum { PROCESS_TYPE_DEFAULT = 0U };

  enum { PROCESS_TYPE_PLUGIN = 1U };

  enum { PROCESS_TYPE_CONTENT = 2U };

  enum { PROCESS_TYPE_JETPACK = 3U };

  enum { PROCESS_TYPE_IPDLUNITTEST = 4U };

  /**
   * The type of the caller's process.  Returns one of the values above.
   */
  /* readonly attribute unsigned long processType; */
  NS_SCRIPTABLE NS_IMETHOD GetProcessType(PRUint32 *aProcessType) = 0;

  /**
   * Signal the apprunner to invalidate caches on the next restart.
   * This will cause components to be autoregistered and all
   * fastload data to be re-created.
   */
  /* void invalidateCachesOnRestart (); */
  NS_SCRIPTABLE NS_IMETHOD InvalidateCachesOnRestart(void) = 0;

  /**
   * Starts a child process. This method is intented to pre-start a
   * content child process so that when it is actually needed, it is
   * ready to go.
   *
   * @throw NS_ERROR_NOT_AVAILABLE if not available.
   */
  /* void ensureContentProcess (); */
  NS_SCRIPTABLE NS_IMETHOD EnsureContentProcess(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULRuntime, NS_IXULRUNTIME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULRUNTIME \
  NS_SCRIPTABLE NS_IMETHOD GetInSafeMode(PRBool *aInSafeMode); \
  NS_SCRIPTABLE NS_IMETHOD GetLogConsoleErrors(PRBool *aLogConsoleErrors); \
  NS_SCRIPTABLE NS_IMETHOD SetLogConsoleErrors(PRBool aLogConsoleErrors); \
  NS_SCRIPTABLE NS_IMETHOD GetOS(nsACString & aOS); \
  NS_SCRIPTABLE NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI); \
  NS_SCRIPTABLE NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit); \
  NS_SCRIPTABLE NS_IMETHOD GetProcessType(PRUint32 *aProcessType); \
  NS_SCRIPTABLE NS_IMETHOD InvalidateCachesOnRestart(void); \
  NS_SCRIPTABLE NS_IMETHOD EnsureContentProcess(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULRUNTIME(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInSafeMode(PRBool *aInSafeMode) { return _to GetInSafeMode(aInSafeMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetLogConsoleErrors(PRBool *aLogConsoleErrors) { return _to GetLogConsoleErrors(aLogConsoleErrors); } \
  NS_SCRIPTABLE NS_IMETHOD SetLogConsoleErrors(PRBool aLogConsoleErrors) { return _to SetLogConsoleErrors(aLogConsoleErrors); } \
  NS_SCRIPTABLE NS_IMETHOD GetOS(nsACString & aOS) { return _to GetOS(aOS); } \
  NS_SCRIPTABLE NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI) { return _to GetXPCOMABI(aXPCOMABI); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit) { return _to GetWidgetToolkit(aWidgetToolkit); } \
  NS_SCRIPTABLE NS_IMETHOD GetProcessType(PRUint32 *aProcessType) { return _to GetProcessType(aProcessType); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateCachesOnRestart(void) { return _to InvalidateCachesOnRestart(); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureContentProcess(void) { return _to EnsureContentProcess(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULRUNTIME(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetInSafeMode(PRBool *aInSafeMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInSafeMode(aInSafeMode); } \
  NS_SCRIPTABLE NS_IMETHOD GetLogConsoleErrors(PRBool *aLogConsoleErrors) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLogConsoleErrors(aLogConsoleErrors); } \
  NS_SCRIPTABLE NS_IMETHOD SetLogConsoleErrors(PRBool aLogConsoleErrors) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLogConsoleErrors(aLogConsoleErrors); } \
  NS_SCRIPTABLE NS_IMETHOD GetOS(nsACString & aOS) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOS(aOS); } \
  NS_SCRIPTABLE NS_IMETHOD GetXPCOMABI(nsACString & aXPCOMABI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXPCOMABI(aXPCOMABI); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidgetToolkit(nsACString & aWidgetToolkit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidgetToolkit(aWidgetToolkit); } \
  NS_SCRIPTABLE NS_IMETHOD GetProcessType(PRUint32 *aProcessType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProcessType(aProcessType); } \
  NS_SCRIPTABLE NS_IMETHOD InvalidateCachesOnRestart(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateCachesOnRestart(); } \
  NS_SCRIPTABLE NS_IMETHOD EnsureContentProcess(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureContentProcess(); } 

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
NS_IMETHODIMP nsXULRuntime::GetInSafeMode(PRBool *aInSafeMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean logConsoleErrors; */
NS_IMETHODIMP nsXULRuntime::GetLogConsoleErrors(PRBool *aLogConsoleErrors)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULRuntime::SetLogConsoleErrors(PRBool aLogConsoleErrors)
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
NS_IMETHODIMP nsXULRuntime::GetProcessType(PRUint32 *aProcessType)
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

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULRuntime_h__ */
