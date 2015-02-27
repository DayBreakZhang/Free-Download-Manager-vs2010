/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/indexedDB/nsIIndexedDatabaseManager.idl
 */

#ifndef __gen_nsIIndexedDatabaseManager_h__
#define __gen_nsIIndexedDatabaseManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIIndexedDatabaseUsageCallback */
#define NS_IINDEXEDDATABASEUSAGECALLBACK_IID_STR "17675af5-0569-4f5b-987f-ff4bb60f73ee"

#define NS_IINDEXEDDATABASEUSAGECALLBACK_IID \
  {0x17675af5, 0x0569, 0x4f5b, \
    { 0x98, 0x7f, 0xff, 0x4b, 0xb6, 0x0f, 0x73, 0xee }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIIndexedDatabaseUsageCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINDEXEDDATABASEUSAGECALLBACK_IID)

  /**
   *
   */
  /* void onUsageResult (in nsIURI aURI, in unsigned long long aUsage); */
  NS_SCRIPTABLE NS_IMETHOD OnUsageResult(nsIURI *aURI, PRUint64 aUsage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIndexedDatabaseUsageCallback, NS_IINDEXEDDATABASEUSAGECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINDEXEDDATABASEUSAGECALLBACK \
  NS_SCRIPTABLE NS_IMETHOD OnUsageResult(nsIURI *aURI, PRUint64 aUsage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINDEXEDDATABASEUSAGECALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnUsageResult(nsIURI *aURI, PRUint64 aUsage) { return _to OnUsageResult(aURI, aUsage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINDEXEDDATABASEUSAGECALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnUsageResult(nsIURI *aURI, PRUint64 aUsage) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnUsageResult(aURI, aUsage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIndexedDatabaseUsageCallback : public nsIIndexedDatabaseUsageCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINDEXEDDATABASEUSAGECALLBACK

  nsIndexedDatabaseUsageCallback();

private:
  ~nsIndexedDatabaseUsageCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIndexedDatabaseUsageCallback, nsIIndexedDatabaseUsageCallback)

nsIndexedDatabaseUsageCallback::nsIndexedDatabaseUsageCallback()
{
  /* member initializers and constructor code */
}

nsIndexedDatabaseUsageCallback::~nsIndexedDatabaseUsageCallback()
{
  /* destructor code */
}

/* void onUsageResult (in nsIURI aURI, in unsigned long long aUsage); */
NS_IMETHODIMP nsIndexedDatabaseUsageCallback::OnUsageResult(nsIURI *aURI, PRUint64 aUsage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIIndexedDatabaseManager */
#define NS_IINDEXEDDATABASEMANAGER_IID_STR "415f5684-6c84-4a8b-b777-d01f5df778f2"

#define NS_IINDEXEDDATABASEMANAGER_IID \
  {0x415f5684, 0x6c84, 0x4a8b, \
    { 0xb7, 0x77, 0xd0, 0x1f, 0x5d, 0xf7, 0x78, 0xf2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIIndexedDatabaseManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINDEXEDDATABASEMANAGER_IID)

  /**
   * Schedules an asynchronous callback that will return the total amount of
   * disk space being used by databases for the given origin.
   *
   * @param aURI
   *        The URI whose usage is being queried.
   * @param aCallback
   *        The callback that will be called when the usage is available.
   */
  /* void getUsageForURI (in nsIURI aURI, in nsIIndexedDatabaseUsageCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD GetUsageForURI(nsIURI *aURI, nsIIndexedDatabaseUsageCallback *aCallback) = 0;

  /**
   * Cancels an asynchronous usage check initiated by a previous call to
   * getUsageForURI().
   *
   * @param aURI
   *        The URI whose usage is being queried.
   * @param aCallback
   *        The callback that will be called when the usage is available.
   */
  /* void cancelGetUsageForURI (in nsIURI aURI, in nsIIndexedDatabaseUsageCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD CancelGetUsageForURI(nsIURI *aURI, nsIIndexedDatabaseUsageCallback *aCallback) = 0;

  /**
   * Removes all databases stored for the given URI. The files may not be
   * deleted immediately depending on prohibitive concurrent operations.
   *
   * @param aURI
   *        The URI whose databases are to be cleared.
   */
  /* void clearDatabasesForURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD ClearDatabasesForURI(nsIURI *aURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIndexedDatabaseManager, NS_IINDEXEDDATABASEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINDEXEDDATABASEMANAGER \
  NS_SCRIPTABLE NS_IMETHOD GetUsageForURI(nsIURI *aURI, nsIIndexedDatabaseUsageCallback *aCallback); \
  NS_SCRIPTABLE NS_IMETHOD CancelGetUsageForURI(nsIURI *aURI, nsIIndexedDatabaseUsageCallback *aCallback); \
  NS_SCRIPTABLE NS_IMETHOD ClearDatabasesForURI(nsIURI *aURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINDEXEDDATABASEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUsageForURI(nsIURI *aURI, nsIIndexedDatabaseUsageCallback *aCallback) { return _to GetUsageForURI(aURI, aCallback); } \
  NS_SCRIPTABLE NS_IMETHOD CancelGetUsageForURI(nsIURI *aURI, nsIIndexedDatabaseUsageCallback *aCallback) { return _to CancelGetUsageForURI(aURI, aCallback); } \
  NS_SCRIPTABLE NS_IMETHOD ClearDatabasesForURI(nsIURI *aURI) { return _to ClearDatabasesForURI(aURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINDEXEDDATABASEMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUsageForURI(nsIURI *aURI, nsIIndexedDatabaseUsageCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsageForURI(aURI, aCallback); } \
  NS_SCRIPTABLE NS_IMETHOD CancelGetUsageForURI(nsIURI *aURI, nsIIndexedDatabaseUsageCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelGetUsageForURI(aURI, aCallback); } \
  NS_SCRIPTABLE NS_IMETHOD ClearDatabasesForURI(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearDatabasesForURI(aURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIndexedDatabaseManager : public nsIIndexedDatabaseManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINDEXEDDATABASEMANAGER

  nsIndexedDatabaseManager();

private:
  ~nsIndexedDatabaseManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIndexedDatabaseManager, nsIIndexedDatabaseManager)

nsIndexedDatabaseManager::nsIndexedDatabaseManager()
{
  /* member initializers and constructor code */
}

nsIndexedDatabaseManager::~nsIndexedDatabaseManager()
{
  /* destructor code */
}

/* void getUsageForURI (in nsIURI aURI, in nsIIndexedDatabaseUsageCallback aCallback); */
NS_IMETHODIMP nsIndexedDatabaseManager::GetUsageForURI(nsIURI *aURI, nsIIndexedDatabaseUsageCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelGetUsageForURI (in nsIURI aURI, in nsIIndexedDatabaseUsageCallback aCallback); */
NS_IMETHODIMP nsIndexedDatabaseManager::CancelGetUsageForURI(nsIURI *aURI, nsIIndexedDatabaseUsageCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearDatabasesForURI (in nsIURI aURI); */
NS_IMETHODIMP nsIndexedDatabaseManager::ClearDatabasesForURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIndexedDatabaseManager_h__ */
