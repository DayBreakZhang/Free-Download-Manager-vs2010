/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/mozapps/update/nsIUpdateTimerManager.idl
 */

#ifndef __gen_nsIUpdateTimerManager_h__
#define __gen_nsIUpdateTimerManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITimerCallback; /* forward declaration */


/* starting interface:    nsIUpdateTimerManager */
#define NS_IUPDATETIMERMANAGER_IID_STR "0765c92c-6145-4253-9db4-594d8023087e"

#define NS_IUPDATETIMERMANAGER_IID \
  {0x0765c92c, 0x6145, 0x4253, \
    { 0x9d, 0xb4, 0x59, 0x4d, 0x80, 0x23, 0x08, 0x7e }}

/**
 * An interface describing a global application service that allows long
 * duration (e.g. 1-7 or more days, weeks or months) timers to be registered
 * and then fired.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIUpdateTimerManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUPDATETIMERMANAGER_IID)

  /**
   * Register an interval with the timer manager. The timer manager
   * periodically checks to see if the interval has expired and if it has
   * calls the specified callback. This is persistent across application
   * restarts and can handle intervals of long durations.
   * @param   id
   *          An id that identifies the interval, used for persistence
   * @param   callback
   *          A nsITimerCallback object that is notified when the interval
   *          expires
   * @param   interval
   *          The length of time, in seconds, of the interval
   *
   * Note: to avoid having to instantiate a component to call registerTimer
   * the component can intead register an update-timer category with comma
   * separated values as a single string representing the timer as follows.
   *
   * _xpcom_categories: [{ category: "update-timer",
   *                       value: "contractID," +
   *                              "method," +
   *                              "id," +
   *                              "preference," +
   *                              "interval" }],
   * the values are as follows
   *   contractID : the contract ID for the component.
   *   method     : the method used to instantiate the interface. This should be
   *                either getService or createInstance depending on your
   *                component.
   *   id         : the id that identifies the interval, used for persistence.
   *   preference : the preference to for timer interval. This value can be
   *                optional by specifying an empty string for the value.
   *   interval   : the default interval in seconds for the timer.
   */
  /* void registerTimer (in AString id, in nsITimerCallback callback, in unsigned long interval); */
  NS_SCRIPTABLE NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, PRUint32 interval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUpdateTimerManager, NS_IUPDATETIMERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUPDATETIMERMANAGER \
  NS_SCRIPTABLE NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, PRUint32 interval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUPDATETIMERMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, PRUint32 interval) { return _to RegisterTimer(id, callback, interval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUPDATETIMERMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD RegisterTimer(const nsAString & id, nsITimerCallback *callback, PRUint32 interval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterTimer(id, callback, interval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUpdateTimerManager : public nsIUpdateTimerManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUPDATETIMERMANAGER

  nsUpdateTimerManager();

private:
  ~nsUpdateTimerManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUpdateTimerManager, nsIUpdateTimerManager)

nsUpdateTimerManager::nsUpdateTimerManager()
{
  /* member initializers and constructor code */
}

nsUpdateTimerManager::~nsUpdateTimerManager()
{
  /* destructor code */
}

/* void registerTimer (in AString id, in nsITimerCallback callback, in unsigned long interval); */
NS_IMETHODIMP nsUpdateTimerManager::RegisterTimer(const nsAString & id, nsITimerCallback *callback, PRUint32 interval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUpdateTimerManager_h__ */
