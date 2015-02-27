/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/uriloader/prefetch/nsIOfflineCacheUpdate.idl
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

class nsIFile; /* forward declaration */

class nsIObserver; /* forward declaration */


/* starting interface:    nsIOfflineCacheUpdateObserver */
#define NS_IOFFLINECACHEUPDATEOBSERVER_IID_STR "47360d57-8ef4-4a5d-8865-1a27a739ad1a"

#define NS_IOFFLINECACHEUPDATEOBSERVER_IID \
  {0x47360d57, 0x8ef4, 0x4a5d, \
    { 0x88, 0x65, 0x1a, 0x27, 0xa7, 0x39, 0xad, 0x1a }}

class NS_NO_VTABLE nsIOfflineCacheUpdateObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOFFLINECACHEUPDATEOBSERVER_IID)

  enum {
    STATE_ERROR = 1U,
    STATE_CHECKING = 2U,
    STATE_NOUPDATE = 3U,
    STATE_OBSOLETE = 4U,
    STATE_DOWNLOADING = 5U,
    STATE_ITEMSTARTED = 6U,
    STATE_ITEMCOMPLETED = 7U,
    STATE_ITEMPROGRESS = 8U,
    STATE_FINISHED = 10U
  };

  /* void updateStateChanged (in nsIOfflineCacheUpdate aUpdate, in uint32_t state); */
  NS_IMETHOD UpdateStateChanged(nsIOfflineCacheUpdate *aUpdate, uint32_t state) = 0;

  /* void applicationCacheAvailable (in nsIApplicationCache applicationCache); */
  NS_IMETHOD ApplicationCacheAvailable(nsIApplicationCache *applicationCache) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOfflineCacheUpdateObserver, NS_IOFFLINECACHEUPDATEOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOFFLINECACHEUPDATEOBSERVER \
  NS_IMETHOD UpdateStateChanged(nsIOfflineCacheUpdate *aUpdate, uint32_t state); \
  NS_IMETHOD ApplicationCacheAvailable(nsIApplicationCache *applicationCache); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOFFLINECACHEUPDATEOBSERVER(_to) \
  NS_IMETHOD UpdateStateChanged(nsIOfflineCacheUpdate *aUpdate, uint32_t state) { return _to UpdateStateChanged(aUpdate, state); } \
  NS_IMETHOD ApplicationCacheAvailable(nsIApplicationCache *applicationCache) { return _to ApplicationCacheAvailable(applicationCache); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOFFLINECACHEUPDATEOBSERVER(_to) \
  NS_IMETHOD UpdateStateChanged(nsIOfflineCacheUpdate *aUpdate, uint32_t state) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateStateChanged(aUpdate, state); } \
  NS_IMETHOD ApplicationCacheAvailable(nsIApplicationCache *applicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplicationCacheAvailable(applicationCache); } 

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

/* void updateStateChanged (in nsIOfflineCacheUpdate aUpdate, in uint32_t state); */
NS_IMETHODIMP nsOfflineCacheUpdateObserver::UpdateStateChanged(nsIOfflineCacheUpdate *aUpdate, uint32_t state)
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
#define NS_IOFFLINECACHEUPDATE_IID_STR "a4503a53-6ab8-4b50-b01e-1c4f393fc980"

#define NS_IOFFLINECACHEUPDATE_IID \
  {0xa4503a53, 0x6ab8, 0x4b50, \
    { 0xb0, 0x1e, 0x1c, 0x4f, 0x39, 0x3f, 0xc9, 0x80 }}

class NS_NO_VTABLE nsIOfflineCacheUpdate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOFFLINECACHEUPDATE_IID)

  /* readonly attribute unsigned short status; */
  NS_IMETHOD GetStatus(uint16_t *aStatus) = 0;

  /* readonly attribute boolean partial; */
  NS_IMETHOD GetPartial(bool *aPartial) = 0;

  /* readonly attribute boolean isUpgrade; */
  NS_IMETHOD GetIsUpgrade(bool *aIsUpgrade) = 0;

  /* readonly attribute ACString updateDomain; */
  NS_IMETHOD GetUpdateDomain(nsACString & aUpdateDomain) = 0;

  /* readonly attribute nsIURI manifestURI; */
  NS_IMETHOD GetManifestURI(nsIURI * *aManifestURI) = 0;

  /* readonly attribute boolean succeeded; */
  NS_IMETHOD GetSucceeded(bool *aSucceeded) = 0;

  /* void init (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMDocument aDocument, [optional] in nsIFile aCustomProfileDir, [optional] in unsigned long aAppId, [optional] in boolean aInBrowser); */
  NS_IMETHOD Init(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument, nsIFile *aCustomProfileDir, uint32_t aAppId, bool aInBrowser) = 0;

  /* void initPartial (in nsIURI aManifestURI, in ACString aClientID, in nsIURI aDocumentURI); */
  NS_IMETHOD InitPartial(nsIURI *aManifestURI, const nsACString & aClientID, nsIURI *aDocumentURI) = 0;

  /* void initForUpdateCheck (in nsIURI aManifestURI, in unsigned long aAppID, in boolean aInBrowser, in nsIObserver aObserver); */
  NS_IMETHOD InitForUpdateCheck(nsIURI *aManifestURI, uint32_t aAppID, bool aInBrowser, nsIObserver *aObserver) = 0;

  /* void addDynamicURI (in nsIURI aURI); */
  NS_IMETHOD AddDynamicURI(nsIURI *aURI) = 0;

  /* void schedule (); */
  NS_IMETHOD Schedule(void) = 0;

  /* void addObserver (in nsIOfflineCacheUpdateObserver aObserver, in boolean aHoldWeak); */
  NS_IMETHOD AddObserver(nsIOfflineCacheUpdateObserver *aObserver, bool aHoldWeak) = 0;

  /* void removeObserver (in nsIOfflineCacheUpdateObserver aObserver); */
  NS_IMETHOD RemoveObserver(nsIOfflineCacheUpdateObserver *aObserver) = 0;

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

  /* readonly attribute uint64_t byteProgress; */
  NS_IMETHOD GetByteProgress(uint64_t *aByteProgress) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOfflineCacheUpdate, NS_IOFFLINECACHEUPDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOFFLINECACHEUPDATE \
  NS_IMETHOD GetStatus(uint16_t *aStatus); \
  NS_IMETHOD GetPartial(bool *aPartial); \
  NS_IMETHOD GetIsUpgrade(bool *aIsUpgrade); \
  NS_IMETHOD GetUpdateDomain(nsACString & aUpdateDomain); \
  NS_IMETHOD GetManifestURI(nsIURI * *aManifestURI); \
  NS_IMETHOD GetSucceeded(bool *aSucceeded); \
  NS_IMETHOD Init(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument, nsIFile *aCustomProfileDir, uint32_t aAppId, bool aInBrowser); \
  NS_IMETHOD InitPartial(nsIURI *aManifestURI, const nsACString & aClientID, nsIURI *aDocumentURI); \
  NS_IMETHOD InitForUpdateCheck(nsIURI *aManifestURI, uint32_t aAppID, bool aInBrowser, nsIObserver *aObserver); \
  NS_IMETHOD AddDynamicURI(nsIURI *aURI); \
  NS_IMETHOD Schedule(void); \
  NS_IMETHOD AddObserver(nsIOfflineCacheUpdateObserver *aObserver, bool aHoldWeak); \
  NS_IMETHOD RemoveObserver(nsIOfflineCacheUpdateObserver *aObserver); \
  NS_IMETHOD Cancel(void); \
  NS_IMETHOD GetByteProgress(uint64_t *aByteProgress); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOFFLINECACHEUPDATE(_to) \
  NS_IMETHOD GetStatus(uint16_t *aStatus) { return _to GetStatus(aStatus); } \
  NS_IMETHOD GetPartial(bool *aPartial) { return _to GetPartial(aPartial); } \
  NS_IMETHOD GetIsUpgrade(bool *aIsUpgrade) { return _to GetIsUpgrade(aIsUpgrade); } \
  NS_IMETHOD GetUpdateDomain(nsACString & aUpdateDomain) { return _to GetUpdateDomain(aUpdateDomain); } \
  NS_IMETHOD GetManifestURI(nsIURI * *aManifestURI) { return _to GetManifestURI(aManifestURI); } \
  NS_IMETHOD GetSucceeded(bool *aSucceeded) { return _to GetSucceeded(aSucceeded); } \
  NS_IMETHOD Init(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument, nsIFile *aCustomProfileDir, uint32_t aAppId, bool aInBrowser) { return _to Init(aManifestURI, aDocumentURI, aDocument, aCustomProfileDir, aAppId, aInBrowser); } \
  NS_IMETHOD InitPartial(nsIURI *aManifestURI, const nsACString & aClientID, nsIURI *aDocumentURI) { return _to InitPartial(aManifestURI, aClientID, aDocumentURI); } \
  NS_IMETHOD InitForUpdateCheck(nsIURI *aManifestURI, uint32_t aAppID, bool aInBrowser, nsIObserver *aObserver) { return _to InitForUpdateCheck(aManifestURI, aAppID, aInBrowser, aObserver); } \
  NS_IMETHOD AddDynamicURI(nsIURI *aURI) { return _to AddDynamicURI(aURI); } \
  NS_IMETHOD Schedule(void) { return _to Schedule(); } \
  NS_IMETHOD AddObserver(nsIOfflineCacheUpdateObserver *aObserver, bool aHoldWeak) { return _to AddObserver(aObserver, aHoldWeak); } \
  NS_IMETHOD RemoveObserver(nsIOfflineCacheUpdateObserver *aObserver) { return _to RemoveObserver(aObserver); } \
  NS_IMETHOD Cancel(void) { return _to Cancel(); } \
  NS_IMETHOD GetByteProgress(uint64_t *aByteProgress) { return _to GetByteProgress(aByteProgress); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOFFLINECACHEUPDATE(_to) \
  NS_IMETHOD GetStatus(uint16_t *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_IMETHOD GetPartial(bool *aPartial) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPartial(aPartial); } \
  NS_IMETHOD GetIsUpgrade(bool *aIsUpgrade) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsUpgrade(aIsUpgrade); } \
  NS_IMETHOD GetUpdateDomain(nsACString & aUpdateDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateDomain(aUpdateDomain); } \
  NS_IMETHOD GetManifestURI(nsIURI * *aManifestURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestURI(aManifestURI); } \
  NS_IMETHOD GetSucceeded(bool *aSucceeded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSucceeded(aSucceeded); } \
  NS_IMETHOD Init(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument, nsIFile *aCustomProfileDir, uint32_t aAppId, bool aInBrowser) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aManifestURI, aDocumentURI, aDocument, aCustomProfileDir, aAppId, aInBrowser); } \
  NS_IMETHOD InitPartial(nsIURI *aManifestURI, const nsACString & aClientID, nsIURI *aDocumentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPartial(aManifestURI, aClientID, aDocumentURI); } \
  NS_IMETHOD InitForUpdateCheck(nsIURI *aManifestURI, uint32_t aAppID, bool aInBrowser, nsIObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitForUpdateCheck(aManifestURI, aAppID, aInBrowser, aObserver); } \
  NS_IMETHOD AddDynamicURI(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDynamicURI(aURI); } \
  NS_IMETHOD Schedule(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Schedule(); } \
  NS_IMETHOD AddObserver(nsIOfflineCacheUpdateObserver *aObserver, bool aHoldWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver, aHoldWeak); } \
  NS_IMETHOD RemoveObserver(nsIOfflineCacheUpdateObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_IMETHOD Cancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } \
  NS_IMETHOD GetByteProgress(uint64_t *aByteProgress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetByteProgress(aByteProgress); } 

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
NS_IMETHODIMP nsOfflineCacheUpdate::GetStatus(uint16_t *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean partial; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetPartial(bool *aPartial)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isUpgrade; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetIsUpgrade(bool *aIsUpgrade)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString updateDomain; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetUpdateDomain(nsACString & aUpdateDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI manifestURI; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetManifestURI(nsIURI * *aManifestURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean succeeded; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetSucceeded(bool *aSucceeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMDocument aDocument, [optional] in nsIFile aCustomProfileDir, [optional] in unsigned long aAppId, [optional] in boolean aInBrowser); */
NS_IMETHODIMP nsOfflineCacheUpdate::Init(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument, nsIFile *aCustomProfileDir, uint32_t aAppId, bool aInBrowser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPartial (in nsIURI aManifestURI, in ACString aClientID, in nsIURI aDocumentURI); */
NS_IMETHODIMP nsOfflineCacheUpdate::InitPartial(nsIURI *aManifestURI, const nsACString & aClientID, nsIURI *aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initForUpdateCheck (in nsIURI aManifestURI, in unsigned long aAppID, in boolean aInBrowser, in nsIObserver aObserver); */
NS_IMETHODIMP nsOfflineCacheUpdate::InitForUpdateCheck(nsIURI *aManifestURI, uint32_t aAppID, bool aInBrowser, nsIObserver *aObserver)
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
NS_IMETHODIMP nsOfflineCacheUpdate::AddObserver(nsIOfflineCacheUpdateObserver *aObserver, bool aHoldWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIOfflineCacheUpdateObserver aObserver); */
NS_IMETHODIMP nsOfflineCacheUpdate::RemoveObserver(nsIOfflineCacheUpdateObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsOfflineCacheUpdate::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint64_t byteProgress; */
NS_IMETHODIMP nsOfflineCacheUpdate::GetByteProgress(uint64_t *aByteProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIOfflineCacheUpdateService */
#define NS_IOFFLINECACHEUPDATESERVICE_IID_STR "cf362a31-4166-4994-8443-b68704ecdcc0"

#define NS_IOFFLINECACHEUPDATESERVICE_IID \
  {0xcf362a31, 0x4166, 0x4994, \
    { 0x84, 0x43, 0xb6, 0x87, 0x04, 0xec, 0xdc, 0xc0 }}

class NS_NO_VTABLE nsIOfflineCacheUpdateService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOFFLINECACHEUPDATESERVICE_IID)

  enum {
    ALLOW_NO_WARN = 3U
  };

  /* readonly attribute unsigned long numUpdates; */
  NS_IMETHOD GetNumUpdates(uint32_t *aNumUpdates) = 0;

  /* nsIOfflineCacheUpdate getUpdate (in unsigned long index); */
  NS_IMETHOD GetUpdate(uint32_t index, nsIOfflineCacheUpdate * *_retval) = 0;

  /* nsIOfflineCacheUpdate scheduleUpdate (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMWindow aWindow); */
  NS_IMETHOD ScheduleUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMWindow *aWindow, nsIOfflineCacheUpdate * *_retval) = 0;

  /* nsIOfflineCacheUpdate scheduleCustomProfileUpdate (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIFile aProfileDir); */
  NS_IMETHOD ScheduleCustomProfileUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIFile *aProfileDir, nsIOfflineCacheUpdate * *_retval) = 0;

  /* nsIOfflineCacheUpdate scheduleAppUpdate (in nsIURI aManifestURI, in nsIURI aDocumentURI, in unsigned long aAppID, in boolean aInBrowser); */
  NS_IMETHOD ScheduleAppUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, uint32_t aAppID, bool aInBrowser, nsIOfflineCacheUpdate * *_retval) = 0;

  /* void scheduleOnDocumentStop (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMDocument aDocument); */
  NS_IMETHOD ScheduleOnDocumentStop(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument) = 0;

  /* void checkForUpdate (in nsIURI aManifestURI, in unsigned long aAppID, in boolean aInBrowser, in nsIObserver aObserver); */
  NS_IMETHOD CheckForUpdate(nsIURI *aManifestURI, uint32_t aAppID, bool aInBrowser, nsIObserver *aObserver) = 0;

  /* boolean offlineAppAllowed (in nsIPrincipal aPrincipal, in nsIPrefBranch aPrefBranch); */
  NS_IMETHOD OfflineAppAllowed(nsIPrincipal *aPrincipal, nsIPrefBranch *aPrefBranch, bool *_retval) = 0;

  /* boolean offlineAppAllowedForURI (in nsIURI aURI, in nsIPrefBranch aPrefBranch); */
  NS_IMETHOD OfflineAppAllowedForURI(nsIURI *aURI, nsIPrefBranch *aPrefBranch, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOfflineCacheUpdateService, NS_IOFFLINECACHEUPDATESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOFFLINECACHEUPDATESERVICE \
  NS_IMETHOD GetNumUpdates(uint32_t *aNumUpdates); \
  NS_IMETHOD GetUpdate(uint32_t index, nsIOfflineCacheUpdate * *_retval); \
  NS_IMETHOD ScheduleUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMWindow *aWindow, nsIOfflineCacheUpdate * *_retval); \
  NS_IMETHOD ScheduleCustomProfileUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIFile *aProfileDir, nsIOfflineCacheUpdate * *_retval); \
  NS_IMETHOD ScheduleAppUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, uint32_t aAppID, bool aInBrowser, nsIOfflineCacheUpdate * *_retval); \
  NS_IMETHOD ScheduleOnDocumentStop(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument); \
  NS_IMETHOD CheckForUpdate(nsIURI *aManifestURI, uint32_t aAppID, bool aInBrowser, nsIObserver *aObserver); \
  NS_IMETHOD OfflineAppAllowed(nsIPrincipal *aPrincipal, nsIPrefBranch *aPrefBranch, bool *_retval); \
  NS_IMETHOD OfflineAppAllowedForURI(nsIURI *aURI, nsIPrefBranch *aPrefBranch, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOFFLINECACHEUPDATESERVICE(_to) \
  NS_IMETHOD GetNumUpdates(uint32_t *aNumUpdates) { return _to GetNumUpdates(aNumUpdates); } \
  NS_IMETHOD GetUpdate(uint32_t index, nsIOfflineCacheUpdate * *_retval) { return _to GetUpdate(index, _retval); } \
  NS_IMETHOD ScheduleUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMWindow *aWindow, nsIOfflineCacheUpdate * *_retval) { return _to ScheduleUpdate(aManifestURI, aDocumentURI, aWindow, _retval); } \
  NS_IMETHOD ScheduleCustomProfileUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIFile *aProfileDir, nsIOfflineCacheUpdate * *_retval) { return _to ScheduleCustomProfileUpdate(aManifestURI, aDocumentURI, aProfileDir, _retval); } \
  NS_IMETHOD ScheduleAppUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, uint32_t aAppID, bool aInBrowser, nsIOfflineCacheUpdate * *_retval) { return _to ScheduleAppUpdate(aManifestURI, aDocumentURI, aAppID, aInBrowser, _retval); } \
  NS_IMETHOD ScheduleOnDocumentStop(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument) { return _to ScheduleOnDocumentStop(aManifestURI, aDocumentURI, aDocument); } \
  NS_IMETHOD CheckForUpdate(nsIURI *aManifestURI, uint32_t aAppID, bool aInBrowser, nsIObserver *aObserver) { return _to CheckForUpdate(aManifestURI, aAppID, aInBrowser, aObserver); } \
  NS_IMETHOD OfflineAppAllowed(nsIPrincipal *aPrincipal, nsIPrefBranch *aPrefBranch, bool *_retval) { return _to OfflineAppAllowed(aPrincipal, aPrefBranch, _retval); } \
  NS_IMETHOD OfflineAppAllowedForURI(nsIURI *aURI, nsIPrefBranch *aPrefBranch, bool *_retval) { return _to OfflineAppAllowedForURI(aURI, aPrefBranch, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOFFLINECACHEUPDATESERVICE(_to) \
  NS_IMETHOD GetNumUpdates(uint32_t *aNumUpdates) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumUpdates(aNumUpdates); } \
  NS_IMETHOD GetUpdate(uint32_t index, nsIOfflineCacheUpdate * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdate(index, _retval); } \
  NS_IMETHOD ScheduleUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMWindow *aWindow, nsIOfflineCacheUpdate * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScheduleUpdate(aManifestURI, aDocumentURI, aWindow, _retval); } \
  NS_IMETHOD ScheduleCustomProfileUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIFile *aProfileDir, nsIOfflineCacheUpdate * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScheduleCustomProfileUpdate(aManifestURI, aDocumentURI, aProfileDir, _retval); } \
  NS_IMETHOD ScheduleAppUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, uint32_t aAppID, bool aInBrowser, nsIOfflineCacheUpdate * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScheduleAppUpdate(aManifestURI, aDocumentURI, aAppID, aInBrowser, _retval); } \
  NS_IMETHOD ScheduleOnDocumentStop(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScheduleOnDocumentStop(aManifestURI, aDocumentURI, aDocument); } \
  NS_IMETHOD CheckForUpdate(nsIURI *aManifestURI, uint32_t aAppID, bool aInBrowser, nsIObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForUpdate(aManifestURI, aAppID, aInBrowser, aObserver); } \
  NS_IMETHOD OfflineAppAllowed(nsIPrincipal *aPrincipal, nsIPrefBranch *aPrefBranch, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OfflineAppAllowed(aPrincipal, aPrefBranch, _retval); } \
  NS_IMETHOD OfflineAppAllowedForURI(nsIURI *aURI, nsIPrefBranch *aPrefBranch, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OfflineAppAllowedForURI(aURI, aPrefBranch, _retval); } 

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
NS_IMETHODIMP nsOfflineCacheUpdateService::GetNumUpdates(uint32_t *aNumUpdates)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOfflineCacheUpdate getUpdate (in unsigned long index); */
NS_IMETHODIMP nsOfflineCacheUpdateService::GetUpdate(uint32_t index, nsIOfflineCacheUpdate * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOfflineCacheUpdate scheduleUpdate (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsOfflineCacheUpdateService::ScheduleUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMWindow *aWindow, nsIOfflineCacheUpdate * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOfflineCacheUpdate scheduleCustomProfileUpdate (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIFile aProfileDir); */
NS_IMETHODIMP nsOfflineCacheUpdateService::ScheduleCustomProfileUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIFile *aProfileDir, nsIOfflineCacheUpdate * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOfflineCacheUpdate scheduleAppUpdate (in nsIURI aManifestURI, in nsIURI aDocumentURI, in unsigned long aAppID, in boolean aInBrowser); */
NS_IMETHODIMP nsOfflineCacheUpdateService::ScheduleAppUpdate(nsIURI *aManifestURI, nsIURI *aDocumentURI, uint32_t aAppID, bool aInBrowser, nsIOfflineCacheUpdate * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scheduleOnDocumentStop (in nsIURI aManifestURI, in nsIURI aDocumentURI, in nsIDOMDocument aDocument); */
NS_IMETHODIMP nsOfflineCacheUpdateService::ScheduleOnDocumentStop(nsIURI *aManifestURI, nsIURI *aDocumentURI, nsIDOMDocument *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkForUpdate (in nsIURI aManifestURI, in unsigned long aAppID, in boolean aInBrowser, in nsIObserver aObserver); */
NS_IMETHODIMP nsOfflineCacheUpdateService::CheckForUpdate(nsIURI *aManifestURI, uint32_t aAppID, bool aInBrowser, nsIObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean offlineAppAllowed (in nsIPrincipal aPrincipal, in nsIPrefBranch aPrefBranch); */
NS_IMETHODIMP nsOfflineCacheUpdateService::OfflineAppAllowed(nsIPrincipal *aPrincipal, nsIPrefBranch *aPrefBranch, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean offlineAppAllowedForURI (in nsIURI aURI, in nsIPrefBranch aPrefBranch); */
NS_IMETHODIMP nsOfflineCacheUpdateService::OfflineAppAllowedForURI(nsIURI *aURI, nsIPrefBranch *aPrefBranch, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIOfflineCacheUpdate_h__ */
