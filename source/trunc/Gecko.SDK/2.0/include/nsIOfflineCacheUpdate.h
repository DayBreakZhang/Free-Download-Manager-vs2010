/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/uriloader/prefetch/nsIOfflineCacheUpdate.idl
 */

#ifndef __gen_nsIOfflineCacheUpdate_h__
#define __gen_nsIOfflineCacheUpdate_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIDOMDocument; /* forward declaration */

class nsIDOMLoadStatus; /* forward declaration */

class nsIOfflineCacheUpdate; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIPrefBranch; /* forward declaration */

class nsIApplicationCache; /* forward declaration */


/* starting interface:    nsIOfflineCacheUpdateObserver */
#define NS_IOFFLINECACHEUPDATEOBSERVER_IID_STR "47360d57-8ef4-4a5d-8865-1a27a739ad1a"

#define NS_IOFFLINECACHEUPDATEOBSERVER_IID \
  {0x47360d57, 0x8ef4, 0x4a5d, \
    { 0x88, 0x65, 0x1a, 0x27, 0xa7, 0x39, 0xad, 0x1a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIOfflineCacheUpdateObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOFFLINECACHEUPDATEOBSERVER_IID)

  enum { STATE_ERROR = 1U };

  enum { STATE_CHECKING = 2U };

  enum { STATE_NOUPDATE = 3U };

  enum { STATE_OBSOLETE = 4U };

  enum { STATE_DOWNLOADING = 5U };

  enum { STATE_ITEMSTARTED = 6U };

  enum { STATE_ITEMCOMPLETED = 7U };

  enum { STATE_FINISHED = 10U };

  /**
   * aUpdate has changed its state.
   *
   * @param aUpdate
   *        The nsIOfflineCacheUpdate being processed.
   * @param event
   *        See enumeration above
   */
  /* void updateStateChanged (in nsIOfflineCacheUpdate aUpdate, in PRUint32 state); */
  NS_SCRIPTABLE NS_IMETHOD UpdateStateChanged(nsIOfflineCacheUpdate *aUpdate, PRUint32 state) = 0;

  /**
   * Informs the observer about an application being available to associate.
   *
   * @param applicationCache
   *        The application cache instance that has been created or found by the 
   *        update to associate with
   */
  /* void applicationCacheAvailable (in nsIApplicationCache applicationCache); */
  NS_SCRIPTABLE NS_IMETHOD ApplicationCacheAvailable(nsIApplicationCache *applicationCache) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOfflineCacheUpdateObserver, NS_IOFFLINECACHEUPDATEOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOFFLINECACHEUPDATEOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD UpdateStateChanged(nsIOfflineCacheUpdate *aUpdate, PRUint32 state); \
  NS_SCRIPTABLE NS_IMETHOD ApplicationCacheAvailable(nsIApplicationCache *applicationCache); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOFFLINECACHEUPDATEOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD UpdateStateChanged(nsIOfflineCacheUpdate *aUpdate, PRUint32 state) { return _to UpdateStateChanged(aUpdate, state); } \
  NS_SCRIPTABLE NS_IMETHOD ApplicationCacheAvailable(nsIApplicationCache *applicationCache) { return _to ApplicationCacheAvailable(applicationCache); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOFFLINECACHEUPDATEOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD UpdateStateChanged(nsIOfflineCacheUpdate *aUpdate, PRUint32 state) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateStateChanged(aUpdate, state); } \
  NS_SCRIPTABLE NS_IMETHOD ApplicationCacheAvailable(nsIApplicationCache *applicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplicationCacheAvailable(applicationCache); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOfflineCacheUpdateObserver : public nsIOfflineCacheUpdateObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOFFLINECACHEUPDATEOBSERVER

  nsOfflineCacheUpdateObserver();

private:
  ~nsOfflineCacheUpdateObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOfflineCacheUpdateObserver, nsIOfflineCacheUpdateObserver)

nsOfflineCacheUpdateObserver::nsOfflineCacheUpdateObserver()
{
  /* member initializers and constructor code */
}

nsOfflineCacheUpdateObserver::~nsOfflineCacheUpdateObserver()
{
  /* destructor code */
}

/* void updateStateChanged (in nsIOfflineCacheUpdate aUpdate, in PRUint32 state); */
NS_IMETHODIMP nsOfflineCacheUpdateObserver::UpdateStateChanged(nsIOfflineCacheUpdate *aUpdate, PRUint32 state)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void applicationCacheAvailable (in nsIApplicationCache applicationCache); */
NS_IMETHODIMP nsOfflineCacheUpdateObserver::ApplicationCacheAvailable(nsIApplicationCache *applicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIOfflineCacheUpdate */
#define NS_IOFFLINECACHEUPDATE_IID_STR "24605d81-8cf9-4021-8575-7f39aacbf31a"

#define NS_IOFFLINECACHEUPDATE_IID \
  {0x24605d81, 0x8cf9, 0x4021, \
    { 0x85, 0x75, 0x7f, 0x39, 0xaa, 0xcb, 0xf3, 0x1a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIOfflineCacheUpdate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOFFLINECACHEUPDATE_IID)

  /**
 * An nsIOfflineCacheUpdate is used to update an application's offline
 * resources.
 *
 * It can be used to perform partial or complete updates.
 *
 * Each update object maintains a list of nsIDOMLoadStatus items for the
 * resources it is updating.  The list of these items will be available
 * after the object is scheduled.
 *
 * One update object will be updating at a time.  The active object will
 * load its items one by one, sending itemCompleted() to any registered
 * observers.
 */
/**
   * Fetch the status of the running update.  This will return a value
   * defined in nsIDOMOfflineResourceList.
   */
  /* readonly attribute unsigned short status; */
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint16 *aStatus) = 0;

  /**
   * TRUE if the update is being used to add specific resources.
   * FALSE if the complete cache update process is happening.
   */
  /* readonly attribute boolean partial; */
  NS_SCRIPTABLE NS_IMETHOD GetPartial(PRBool *aPartial) = 0;

  /**
   * TRUE if this is an upgrade attempt, FALSE if it is a new cache
   * attempt.
   */
  /* readonly attribute boolean isUpgrade; */
  NS_SCRIPTABLE NS_IMETHOD GetIsUpgrade(PRBool *aIsUpgrade) = 0;

  /**
   * The domain being updated, and the domain that will own any URIs added
   * with this update.
   */
  /* readonly attribute ACString updateDomain; */
  NS_SCRIPTABLE NS_IMETHOD GetUpdateDomain(nsACString & aUpdateDomain) = 0;

  /**
   * The manifest for the offline application being updated.
   */
  /* readonly attribute nsIURI manifestURI; */
  NS_SCRIPTABLE NS_IMETHOD GetManifestURI(nsIURI **aManifestURI) = 0;

  /**
   * TRUE if the cache update completed successfully.
   */
  /* readonly attribute boolean succeeded; */
  NS_SCRIPTABLE NS_IMETHOD GetSucceeded(PRBool *aSucceeded) = 0;

  /**
   * Initialize the update.
   *
   * @param aManifestURI
   *        The manifest URI to be checked.
   * @param aDocumentURI
   *        The page that is requesting the update.
   */
  /* void init (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMDocument aDocument); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument) = 0;

  /**
   * Initialize the update for partial processing. 
   *
   * @param aManifestURI
   *        The manifest URI of the related cache.
   * @param aClientID
   *        Client  ID of the cache to store resource to. This ClientID
   *        must be ID of cache in the cache group identified by
   *        the manifest URI passed in the first parameter.
   * @param aDocumentURI
   *        The page that is requesting the update. May be null 
   *        when this information is unknown.
   */
  /* void initPartial (in nsIURI aManifestURI, in ACString aClientID, in nsIURI aDocumentURI); */
  NS_SCRIPTABLE NS_IMETHOD InitPartial(nsIURI *aManifestURI, const nsACString & aClientID, nsIURI *aDocumentURI) = 0;

  /**
   * Add a dynamic URI to the offline cache as part of the update.
   *
   * @param aURI
   *        The URI to add.
   */
  /* void addDynamicURI (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD AddDynamicURI(nsIURI *aURI) = 0;

  /**
   * Add the update to the offline update queue.  An offline-cache-update-added
   * event will be sent to the observer service.
   */
  /* void schedule (); */
  NS_SCRIPTABLE NS_IMETHOD Schedule(void) = 0;

  /**
   * Observe loads that are added to the update.
   *
   * @param aObserver
   *        object that notifications will be sent to.
   * @param aHoldWeak
   *        TRUE if you want the update to hold a weak reference to the
   *        observer, FALSE for a strong reference.
   */
  /* void addObserver (in nsIOfflineCacheUpdateObserver aObserver, in boolean aHoldWeak); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIOfflineCacheUpdateObserver *aObserver, PRBool aHoldWeak) = 0;

  /**
   * Remove an observer from the update.
   *
   * @param aObserver
   *        the observer to remove.
   */
  /* void removeObserver (in nsIOfflineCacheUpdateObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIOfflineCacheUpdateObserver *aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOfflineCacheUpdate, NS_IOFFLINECACHEUPDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOFFLINECACHEUPDATE \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint16 *aStatus); \
  NS_SCRIPTABLE NS_IMETHOD GetPartial(PRBool *aPartial); \
  NS_SCRIPTABLE NS_IMETHOD GetIsUpgrade(PRBool *aIsUpgrade); \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateDomain(nsACString & aUpdateDomain); \
  NS_SCRIPTABLE NS_IMETHOD GetManifestURI(nsIURI **aManifestURI); \
  NS_SCRIPTABLE NS_IMETHOD GetSucceeded(PRBool *aSucceeded); \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument); \
  NS_SCRIPTABLE NS_IMETHOD InitPartial(nsIURI *aManifestURI, const nsACString & aClientID, nsIURI *aDocumentURI); \
  NS_SCRIPTABLE NS_IMETHOD AddDynamicURI(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD Schedule(void); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIOfflineCacheUpdateObserver *aObserver, PRBool aHoldWeak); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIOfflineCacheUpdateObserver *aObserver); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOFFLINECACHEUPDATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint16 *aStatus) { return _to GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetPartial(PRBool *aPartial) { return _to GetPartial(aPartial); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsUpgrade(PRBool *aIsUpgrade) { return _to GetIsUpgrade(aIsUpgrade); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateDomain(nsACString & aUpdateDomain) { return _to GetUpdateDomain(aUpdateDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetManifestURI(nsIURI **aManifestURI) { return _to GetManifestURI(aManifestURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetSucceeded(PRBool *aSucceeded) { return _to GetSucceeded(aSucceeded); } \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument) { return _to Init(aManifestURI, aDocumentURI, aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD InitPartial(nsIURI *aManifestURI, const nsACString & aClientID, nsIURI *aDocumentURI) { return _to InitPartial(aManifestURI, aClientID, aDocumentURI); } \
  NS_SCRIPTABLE NS_IMETHOD AddDynamicURI(nsIURI *aURI) { return _to AddDynamicURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD Schedule(void) { return _to Schedule(); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIOfflineCacheUpdateObserver *aObserver, PRBool aHoldWeak) { return _to AddObserver(aObserver, aHoldWeak); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIOfflineCacheUpdateObserver *aObserver) { return _to RemoveObserver(aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOFFLINECACHEUPDATE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStatus(PRUint16 *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_SCRIPTABLE NS_IMETHOD GetPartial(PRBool *aPartial) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPartial(aPartial); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsUpgrade(PRBool *aIsUpgrade) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsUpgrade(aIsUpgrade); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdateDomain(nsACString & aUpdateDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateDomain(aUpdateDomain); } \
  NS_SCRIPTABLE NS_IMETHOD GetManifestURI(nsIURI **aManifestURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestURI(aManifestURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetSucceeded(PRBool *aSucceeded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSucceeded(aSucceeded); } \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aManifestURI, aDocumentURI, aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD InitPartial(nsIURI *aManifestURI, const nsACString & aClientID, nsIURI *aDocumentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPartial(aManifestURI, aClientID, aDocumentURI); } \
  NS_SCRIPTABLE NS_IMETHOD AddDynamicURI(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDynamicURI(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD Schedule(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Schedule(); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(nsIOfflineCacheUpdateObserver *aObserver, PRBool aHoldWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver, aHoldWeak); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(nsIOfflineCacheUpdateObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOfflineCacheUpdate : public nsIOfflineCacheUpdate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOFFLINECACHEUPDATE

  nsOfflineCacheUpdate();

private:
  ~nsOfflineCacheUpdate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOfflineCacheUpdate, nsIOfflineCacheUpdate)

nsOfflineCacheUpdate::nsOfflineCacheUpdate()
{
  /* member initializers and constructor code */
}

nsOfflineCacheUpdate::~nsOfflineCacheUpdate()
{
  /* destructor code */
}

/* readonly attribute unsigned short status; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetStatus(PRUint16 *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean partial; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetPartial(PRBool *aPartial)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isUpgrade; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetIsUpgrade(PRBool *aIsUpgrade)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString updateDomain; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetUpdateDomain(nsACString & aUpdateDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI manifestURI; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetManifestURI(nsIURI **aManifestURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean succeeded; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetSucceeded(PRBool *aSucceeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMDocument aDocument); */
NS_IMETHODIMP nsOfflineCacheUpdate::Init(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPartial (in nsIURI aManifestURI, in ACString aClientID, in nsIURI aDocumentURI); */
NS_IMETHODIMP nsOfflineCacheUpdate::InitPartial(nsIURI *aManifestURI, const nsACString & aClientID, nsIURI *aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDynamicURI (in nsIURI aURI); */
NS_IMETHODIMP nsOfflineCacheUpdate::AddDynamicURI(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void schedule (); */
NS_IMETHODIMP nsOfflineCacheUpdate::Schedule()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsIOfflineCacheUpdateObserver aObserver, in boolean aHoldWeak); */
NS_IMETHODIMP nsOfflineCacheUpdate::AddObserver(nsIOfflineCacheUpdateObserver *aObserver, PRBool aHoldWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIOfflineCacheUpdateObserver aObserver); */
NS_IMETHODIMP nsOfflineCacheUpdate::RemoveObserver(nsIOfflineCacheUpdateObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIOfflineCacheUpdateService */
#define NS_IOFFLINECACHEUPDATESERVICE_IID_STR "6fd2030f-7b00-4102-a0e3-d73078821eb1"

#define NS_IOFFLINECACHEUPDATESERVICE_IID \
  {0x6fd2030f, 0x7b00, 0x4102, \
    { 0xa0, 0xe3, 0xd7, 0x30, 0x78, 0x82, 0x1e, 0xb1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIOfflineCacheUpdateService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOFFLINECACHEUPDATESERVICE_IID)

  /**
     * Constants for the offline-app permission.
     *
     * XXX: This isn't a great place for this, but it's really the only
     * private offline-app-related interface
     */
/**
     * Allow the domain to use offline APIs, and don't warn about excessive
     * usage.
     */
  enum { ALLOW_NO_WARN = 3U };

  /**
     * Access to the list of cache updates that have been scheduled.
     */
  /* readonly attribute unsigned long numUpdates; */
  NS_SCRIPTABLE NS_IMETHOD GetNumUpdates(PRUint32 *aNumUpdates) = 0;

  /* nsIOfflineCacheUpdate getUpdate (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD GetUpdate(PRUint32 index, nsIOfflineCacheUpdate **_retval NS_OUTPARAM) = 0;

  /**
     * Schedule a cache update for a given offline manifest.  If an
     * existing update is scheduled or running, that update will be returned.
     * Otherwise a new update will be scheduled.
     */
  /* nsIOfflineCacheUpdate scheduleUpdate (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD ScheduleUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMWindow *aWindow, nsIOfflineCacheUpdate **_retval NS_OUTPARAM) = 0;

  /**
     * Schedule a cache update for a manifest when the document finishes
     * loading.
     */
  /* void scheduleOnDocumentStop (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMDocument aDocument); */
  NS_SCRIPTABLE NS_IMETHOD ScheduleOnDocumentStop(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument) = 0;

  /**
     * Checks whether a principal should have access to the offline
     * cache.
     * @param aPrincipal
     *        The principal to check.
     * @param aPrefBranch
     *        The pref branch to use to check the
     *        offline-apps.allow_by_default pref.  If not specified,
     *        the pref service will be used.
     */
  /* boolean offlineAppAllowed (in nsIPrincipal aPrincipal, in nsIPrefBranch aPrefBranch); */
  NS_SCRIPTABLE NS_IMETHOD OfflineAppAllowed(nsIPrincipal *aPrincipal, nsIPrefBranch *aPrefBranch, PRBool *_retval NS_OUTPARAM) = 0;

  /**
     * Checks whether a document at the given URI should have access
     * to the offline cache.
     * @param aURI
     *        The URI to check
     * @param aPrefBranch
     *        The pref branch to use to check the
     *        offline-apps.allow_by_default pref.  If not specified,
     *        the pref service will be used.
     */
  /* boolean offlineAppAllowedForURI (in nsIURI aURI, in nsIPrefBranch aPrefBranch); */
  NS_SCRIPTABLE NS_IMETHOD OfflineAppAllowedForURI(nsIURI *aURI, nsIPrefBranch *aPrefBranch, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOfflineCacheUpdateService, NS_IOFFLINECACHEUPDATESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOFFLINECACHEUPDATESERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetNumUpdates(PRUint32 *aNumUpdates); \
  NS_SCRIPTABLE NS_IMETHOD GetUpdate(PRUint32 index, nsIOfflineCacheUpdate **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ScheduleUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMWindow *aWindow, nsIOfflineCacheUpdate **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ScheduleOnDocumentStop(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument); \
  NS_SCRIPTABLE NS_IMETHOD OfflineAppAllowed(nsIPrincipal *aPrincipal, nsIPrefBranch *aPrefBranch, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD OfflineAppAllowedForURI(nsIURI *aURI, nsIPrefBranch *aPrefBranch, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOFFLINECACHEUPDATESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumUpdates(PRUint32 *aNumUpdates) { return _to GetNumUpdates(aNumUpdates); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdate(PRUint32 index, nsIOfflineCacheUpdate **_retval NS_OUTPARAM) { return _to GetUpdate(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScheduleUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMWindow *aWindow, nsIOfflineCacheUpdate **_retval NS_OUTPARAM) { return _to ScheduleUpdate(aManifestURI, aDocumentURI, aWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScheduleOnDocumentStop(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument) { return _to ScheduleOnDocumentStop(aManifestURI, aDocumentURI, aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD OfflineAppAllowed(nsIPrincipal *aPrincipal, nsIPrefBranch *aPrefBranch, PRBool *_retval NS_OUTPARAM) { return _to OfflineAppAllowed(aPrincipal, aPrefBranch, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OfflineAppAllowedForURI(nsIURI *aURI, nsIPrefBranch *aPrefBranch, PRBool *_retval NS_OUTPARAM) { return _to OfflineAppAllowedForURI(aURI, aPrefBranch, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOFFLINECACHEUPDATESERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNumUpdates(PRUint32 *aNumUpdates) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumUpdates(aNumUpdates); } \
  NS_SCRIPTABLE NS_IMETHOD GetUpdate(PRUint32 index, nsIOfflineCacheUpdate **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdate(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScheduleUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMWindow *aWindow, nsIOfflineCacheUpdate **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScheduleUpdate(aManifestURI, aDocumentURI, aWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScheduleOnDocumentStop(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScheduleOnDocumentStop(aManifestURI, aDocumentURI, aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD OfflineAppAllowed(nsIPrincipal *aPrincipal, nsIPrefBranch *aPrefBranch, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OfflineAppAllowed(aPrincipal, aPrefBranch, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD OfflineAppAllowedForURI(nsIURI *aURI, nsIPrefBranch *aPrefBranch, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->OfflineAppAllowedForURI(aURI, aPrefBranch, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOfflineCacheUpdateService : public nsIOfflineCacheUpdateService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOFFLINECACHEUPDATESERVICE

  nsOfflineCacheUpdateService();

private:
  ~nsOfflineCacheUpdateService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOfflineCacheUpdateService, nsIOfflineCacheUpdateService)

nsOfflineCacheUpdateService::nsOfflineCacheUpdateService()
{
  /* member initializers and constructor code */
}

nsOfflineCacheUpdateService::~nsOfflineCacheUpdateService()
{
  /* destructor code */
}

/* readonly attribute unsigned long numUpdates; */
NS_IMETHODIMP nsOfflineCacheUpdateService::GetNumUpdates(PRUint32 *aNumUpdates)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOfflineCacheUpdate getUpdate (in unsigned long index); */
NS_IMETHODIMP nsOfflineCacheUpdateService::GetUpdate(PRUint32 index, nsIOfflineCacheUpdate **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOfflineCacheUpdate scheduleUpdate (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsOfflineCacheUpdateService::ScheduleUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMWindow *aWindow, nsIOfflineCacheUpdate **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scheduleOnDocumentStop (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMDocument aDocument); */
NS_IMETHODIMP nsOfflineCacheUpdateService::ScheduleOnDocumentStop(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean offlineAppAllowed (in nsIPrincipal aPrincipal, in nsIPrefBranch aPrefBranch); */
NS_IMETHODIMP nsOfflineCacheUpdateService::OfflineAppAllowed(nsIPrincipal *aPrincipal, nsIPrefBranch *aPrefBranch, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean offlineAppAllowedForURI (in nsIURI aURI, in nsIPrefBranch aPrefBranch); */
NS_IMETHODIMP nsOfflineCacheUpdateService::OfflineAppAllowedForURI(nsIURI *aURI, nsIPrefBranch *aPrefBranch, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIOfflineCacheUpdate_h__ */
