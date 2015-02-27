/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/components/places/public/nsPIPlacesHistoryListenersNotifier.idl
 */

#ifndef __gen_nsPIPlacesHistoryListenersNotifier_h__
#define __gen_nsPIPlacesHistoryListenersNotifier_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsPIPlacesHistoryListenersNotifier */
#define NS_PIPLACESHISTORYLISTENERSNOTIFIER_IID_STR "b96adaff-e02c-48da-a379-8af5d10e09af"

#define NS_PIPLACESHISTORYLISTENERSNOTIFIER_IID \
  {0xb96adaff, 0xe02c, 0x48da, \
    { 0xa3, 0x79, 0x8a, 0xf5, 0xd1, 0x0e, 0x09, 0xaf }}

/**
 * This is a private interface used by Places components to notify history
 * listeners about important notifications.  These should not be used by any
 * code that is not part of core.
 *
 * @note See also: nsINavHistoryObserver
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsPIPlacesHistoryListenersNotifier : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIPLACESHISTORYLISTENERSNOTIFIER_IID)

  /**
   * Calls onDeleteVisits and onDeleteURI notifications on registered listeners
   * with the history service.
   *
   * @param aURI
   *        The nsIURI object representing the URI of the page being expired.
   * @param aVisitTime
   *        The time, in microseconds, that the page being expired was visited.
   * @param aWholeEntry
   *        Indicates if this is the last visit for this URI.
   */
  /* void notifyOnPageExpired (in nsIURI aURI, in PRTime aVisitTime, in boolean aWholeEntry); */
  NS_SCRIPTABLE NS_IMETHOD NotifyOnPageExpired(nsIURI *aURI, PRTime aVisitTime, PRBool aWholeEntry) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIPlacesHistoryListenersNotifier, NS_PIPLACESHISTORYLISTENERSNOTIFIER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIPLACESHISTORYLISTENERSNOTIFIER \
  NS_SCRIPTABLE NS_IMETHOD NotifyOnPageExpired(nsIURI *aURI, PRTime aVisitTime, PRBool aWholeEntry); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIPLACESHISTORYLISTENERSNOTIFIER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifyOnPageExpired(nsIURI *aURI, PRTime aVisitTime, PRBool aWholeEntry) { return _to NotifyOnPageExpired(aURI, aVisitTime, aWholeEntry); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIPLACESHISTORYLISTENERSNOTIFIER(_to) \
  NS_SCRIPTABLE NS_IMETHOD NotifyOnPageExpired(nsIURI *aURI, PRTime aVisitTime, PRBool aWholeEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyOnPageExpired(aURI, aVisitTime, aWholeEntry); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIPlacesHistoryListenersNotifier
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIPLACESHISTORYLISTENERSNOTIFIER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIPlacesHistoryListenersNotifier)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void notifyOnPageExpired (in nsIURI aURI, in PRTime aVisitTime, in boolean aWholeEntry); */
NS_IMETHODIMP _MYCLASS_::NotifyOnPageExpired(nsIURI *aURI, PRTime aVisitTime, PRBool aWholeEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIPlacesHistoryListenersNotifier_h__ */
