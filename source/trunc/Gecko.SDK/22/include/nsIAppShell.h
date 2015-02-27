/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsIAppShell.idl
 */

#ifndef __gen_nsIAppShell_h__
#define __gen_nsIAppShell_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRunnable; /* forward declaration */


/* starting interface:    nsIAppShell */
#define NS_IAPPSHELL_IID_STR "2d10ca53-f143-439a-bb2e-c1fbc71f6a05"

#define NS_IAPPSHELL_IID \
  {0x2d10ca53, 0xf143, 0x439a, \
    { 0xbb, 0x2e, 0xc1, 0xfb, 0xc7, 0x1f, 0x6a, 0x05 }}

class NS_NO_VTABLE nsIAppShell : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSHELL_IID)

  /* void run (); */
  NS_IMETHOD Run(void) = 0;

  /* void exit (); */
  NS_IMETHOD Exit(void) = 0;

  /* void favorPerformanceHint (in boolean favorPerfOverStarvation, in unsigned long starvationDelay); */
  NS_IMETHOD FavorPerformanceHint(bool favorPerfOverStarvation, uint32_t starvationDelay) = 0;

  /* void suspendNative (); */
  NS_IMETHOD SuspendNative(void) = 0;

  /* void resumeNative (); */
  NS_IMETHOD ResumeNative(void) = 0;

  /* readonly attribute unsigned long eventloopNestingLevel; */
  NS_IMETHOD GetEventloopNestingLevel(uint32_t *aEventloopNestingLevel) = 0;

  /* void runInStableState (in nsIRunnable runnable); */
  NS_IMETHOD RunInStableState(nsIRunnable *runnable) = 0;

  /* void runBeforeNextEvent (in nsIRunnable runnable); */
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppShell, NS_IAPPSHELL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSHELL \
  NS_IMETHOD Run(void); \
  NS_IMETHOD Exit(void); \
  NS_IMETHOD FavorPerformanceHint(bool favorPerfOverStarvation, uint32_t starvationDelay); \
  NS_IMETHOD SuspendNative(void); \
  NS_IMETHOD ResumeNative(void); \
  NS_IMETHOD GetEventloopNestingLevel(uint32_t *aEventloopNestingLevel); \
  NS_IMETHOD RunInStableState(nsIRunnable *runnable); \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSHELL(_to) \
  NS_IMETHOD Run(void) { return _to Run(); } \
  NS_IMETHOD Exit(void) { return _to Exit(); } \
  NS_IMETHOD FavorPerformanceHint(bool favorPerfOverStarvation, uint32_t starvationDelay) { return _to FavorPerformanceHint(favorPerfOverStarvation, starvationDelay); } \
  NS_IMETHOD SuspendNative(void) { return _to SuspendNative(); } \
  NS_IMETHOD ResumeNative(void) { return _to ResumeNative(); } \
  NS_IMETHOD GetEventloopNestingLevel(uint32_t *aEventloopNestingLevel) { return _to GetEventloopNestingLevel(aEventloopNestingLevel); } \
  NS_IMETHOD RunInStableState(nsIRunnable *runnable) { return _to RunInStableState(runnable); } \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) { return _to RunBeforeNextEvent(runnable); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSHELL(_to) \
  NS_IMETHOD Run(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Run(); } \
  NS_IMETHOD Exit(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Exit(); } \
  NS_IMETHOD FavorPerformanceHint(bool favorPerfOverStarvation, uint32_t starvationDelay) { return !_to ? NS_ERROR_NULL_POINTER : _to->FavorPerformanceHint(favorPerfOverStarvation, starvationDelay); } \
  NS_IMETHOD SuspendNative(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SuspendNative(); } \
  NS_IMETHOD ResumeNative(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeNative(); } \
  NS_IMETHOD GetEventloopNestingLevel(uint32_t *aEventloopNestingLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEventloopNestingLevel(aEventloopNestingLevel); } \
  NS_IMETHOD RunInStableState(nsIRunnable *runnable) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunInStableState(runnable); } \
  NS_IMETHOD RunBeforeNextEvent(nsIRunnable *runnable) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunBeforeNextEvent(runnable); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppShell : public nsIAppShell
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSHELL

  nsAppShell();

private:
  ~nsAppShell();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppShell, nsIAppShell)

nsAppShell::nsAppShell()
{
  /* member initializers and constructor code */
}

nsAppShell::~nsAppShell()
{
  /* destructor code */
}

/* void run (); */
NS_IMETHODIMP nsAppShell::Run()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exit (); */
NS_IMETHODIMP nsAppShell::Exit()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void favorPerformanceHint (in boolean favorPerfOverStarvation, in unsigned long starvationDelay); */
NS_IMETHODIMP nsAppShell::FavorPerformanceHint(bool favorPerfOverStarvation, uint32_t starvationDelay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspendNative (); */
NS_IMETHODIMP nsAppShell::SuspendNative()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeNative (); */
NS_IMETHODIMP nsAppShell::ResumeNative()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long eventloopNestingLevel; */
NS_IMETHODIMP nsAppShell::GetEventloopNestingLevel(uint32_t *aEventloopNestingLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runInStableState (in nsIRunnable runnable); */
NS_IMETHODIMP nsAppShell::RunInStableState(nsIRunnable *runnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runBeforeNextEvent (in nsIRunnable runnable); */
NS_IMETHODIMP nsAppShell::RunBeforeNextEvent(nsIRunnable *runnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAppShell_h__ */
