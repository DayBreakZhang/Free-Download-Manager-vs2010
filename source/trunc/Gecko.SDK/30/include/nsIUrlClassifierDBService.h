/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUrlClassifierDBService.idl
 */

#ifndef __gen_nsIUrlClassifierDBService_h__
#define __gen_nsIUrlClassifierDBService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "Entries.h"
#include "LookupCache.h"
class nsUrlClassifierLookupResult;
class nsIUrlClassifierHashCompleter; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIUrlClassifierCallback */
#define NS_IURLCLASSIFIERCALLBACK_IID_STR "4ca27b6b-a674-4b3d-ab30-d21e2da2dffb"

#define NS_IURLCLASSIFIERCALLBACK_IID \
  {0x4ca27b6b, 0xa674, 0x4b3d, \
    { 0xab, 0x30, 0xd2, 0x1e, 0x2d, 0xa2, 0xdf, 0xfb }}

class NS_NO_VTABLE nsIUrlClassifierCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERCALLBACK_IID)

  /* void handleEvent (in ACString value); */
  NS_IMETHOD HandleEvent(const nsACString & value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierCallback, NS_IURLCLASSIFIERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERCALLBACK \
  NS_IMETHOD HandleEvent(const nsACString & value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERCALLBACK(_to) \
  NS_IMETHOD HandleEvent(const nsACString & value) { return _to HandleEvent(value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERCALLBACK(_to) \
  NS_IMETHOD HandleEvent(const nsACString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierCallback : public nsIUrlClassifierCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERCALLBACK

  nsUrlClassifierCallback();

private:
  ~nsUrlClassifierCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlClassifierCallback, nsIUrlClassifierCallback)

nsUrlClassifierCallback::nsUrlClassifierCallback()
{
  /* member initializers and constructor code */
}

nsUrlClassifierCallback::~nsUrlClassifierCallback()
{
  /* destructor code */
}

/* void handleEvent (in ACString value); */
NS_IMETHODIMP nsUrlClassifierCallback::HandleEvent(const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUrlClassifierUpdateObserver */
#define NS_IURLCLASSIFIERUPDATEOBSERVER_IID_STR "9fa11561-5816-4e1b-bcc9-b629ca05cce6"

#define NS_IURLCLASSIFIERUPDATEOBSERVER_IID \
  {0x9fa11561, 0x5816, 0x4e1b, \
    { 0xbc, 0xc9, 0xb6, 0x29, 0xca, 0x05, 0xcc, 0xe6 }}

class NS_NO_VTABLE nsIUrlClassifierUpdateObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERUPDATEOBSERVER_IID)

  /* void updateUrlRequested (in ACString url, in ACString table); */
  NS_IMETHOD UpdateUrlRequested(const nsACString & url, const nsACString & table) = 0;

  /* void streamFinished (in nsresult status, in unsigned long delay); */
  NS_IMETHOD StreamFinished(nsresult status, uint32_t delay) = 0;

  /* void updateError (in nsresult error); */
  NS_IMETHOD UpdateError(nsresult error) = 0;

  /* void updateSuccess (in unsigned long requestedTimeout); */
  NS_IMETHOD UpdateSuccess(uint32_t requestedTimeout) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierUpdateObserver, NS_IURLCLASSIFIERUPDATEOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERUPDATEOBSERVER \
  NS_IMETHOD UpdateUrlRequested(const nsACString & url, const nsACString & table); \
  NS_IMETHOD StreamFinished(nsresult status, uint32_t delay); \
  NS_IMETHOD UpdateError(nsresult error); \
  NS_IMETHOD UpdateSuccess(uint32_t requestedTimeout); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERUPDATEOBSERVER(_to) \
  NS_IMETHOD UpdateUrlRequested(const nsACString & url, const nsACString & table) { return _to UpdateUrlRequested(url, table); } \
  NS_IMETHOD StreamFinished(nsresult status, uint32_t delay) { return _to StreamFinished(status, delay); } \
  NS_IMETHOD UpdateError(nsresult error) { return _to UpdateError(error); } \
  NS_IMETHOD UpdateSuccess(uint32_t requestedTimeout) { return _to UpdateSuccess(requestedTimeout); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERUPDATEOBSERVER(_to) \
  NS_IMETHOD UpdateUrlRequested(const nsACString & url, const nsACString & table) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateUrlRequested(url, table); } \
  NS_IMETHOD StreamFinished(nsresult status, uint32_t delay) { return !_to ? NS_ERROR_NULL_POINTER : _to->StreamFinished(status, delay); } \
  NS_IMETHOD UpdateError(nsresult error) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateError(error); } \
  NS_IMETHOD UpdateSuccess(uint32_t requestedTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateSuccess(requestedTimeout); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierUpdateObserver : public nsIUrlClassifierUpdateObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERUPDATEOBSERVER

  nsUrlClassifierUpdateObserver();

private:
  ~nsUrlClassifierUpdateObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlClassifierUpdateObserver, nsIUrlClassifierUpdateObserver)

nsUrlClassifierUpdateObserver::nsUrlClassifierUpdateObserver()
{
  /* member initializers and constructor code */
}

nsUrlClassifierUpdateObserver::~nsUrlClassifierUpdateObserver()
{
  /* destructor code */
}

/* void updateUrlRequested (in ACString url, in ACString table); */
NS_IMETHODIMP nsUrlClassifierUpdateObserver::UpdateUrlRequested(const nsACString & url, const nsACString & table)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void streamFinished (in nsresult status, in unsigned long delay); */
NS_IMETHODIMP nsUrlClassifierUpdateObserver::StreamFinished(nsresult status, uint32_t delay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateError (in nsresult error); */
NS_IMETHODIMP nsUrlClassifierUpdateObserver::UpdateError(nsresult error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateSuccess (in unsigned long requestedTimeout); */
NS_IMETHODIMP nsUrlClassifierUpdateObserver::UpdateSuccess(uint32_t requestedTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUrlClassifierDBService */
#define NS_IURLCLASSIFIERDBSERVICE_IID_STR "3f9e61e5-01bd-45d0-8dd2-f1abcd20dbb7"

#define NS_IURLCLASSIFIERDBSERVICE_IID \
  {0x3f9e61e5, 0x01bd, 0x45d0, \
    { 0x8d, 0xd2, 0xf1, 0xab, 0xcd, 0x20, 0xdb, 0xb7 }}

class NS_NO_VTABLE nsIUrlClassifierDBService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERDBSERVICE_IID)

  /* void lookup (in nsIPrincipal principal, in ACString tables, in nsIUrlClassifierCallback c); */
  NS_IMETHOD Lookup(nsIPrincipal *principal, const nsACString & tables, nsIUrlClassifierCallback *c) = 0;

  /* void getTables (in nsIUrlClassifierCallback c); */
  NS_IMETHOD GetTables(nsIUrlClassifierCallback *c) = 0;

  /* void setHashCompleter (in ACString tableName, in nsIUrlClassifierHashCompleter completer); */
  NS_IMETHOD SetHashCompleter(const nsACString & tableName, nsIUrlClassifierHashCompleter *completer) = 0;

  /* void beginUpdate (in nsIUrlClassifierUpdateObserver updater, in ACString tables); */
  NS_IMETHOD BeginUpdate(nsIUrlClassifierUpdateObserver *updater, const nsACString & tables) = 0;

  /* void beginStream (in ACString table); */
  NS_IMETHOD BeginStream(const nsACString & table) = 0;

  /* void updateStream (in ACString updateChunk); */
  NS_IMETHOD UpdateStream(const nsACString & updateChunk) = 0;

  /* void finishStream (); */
  NS_IMETHOD FinishStream(void) = 0;

  /* void finishUpdate (); */
  NS_IMETHOD FinishUpdate(void) = 0;

  /* void cancelUpdate (); */
  NS_IMETHOD CancelUpdate(void) = 0;

  /* void resetDatabase (); */
  NS_IMETHOD ResetDatabase(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierDBService, NS_IURLCLASSIFIERDBSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERDBSERVICE \
  NS_IMETHOD Lookup(nsIPrincipal *principal, const nsACString & tables, nsIUrlClassifierCallback *c); \
  NS_IMETHOD GetTables(nsIUrlClassifierCallback *c); \
  NS_IMETHOD SetHashCompleter(const nsACString & tableName, nsIUrlClassifierHashCompleter *completer); \
  NS_IMETHOD BeginUpdate(nsIUrlClassifierUpdateObserver *updater, const nsACString & tables); \
  NS_IMETHOD BeginStream(const nsACString & table); \
  NS_IMETHOD UpdateStream(const nsACString & updateChunk); \
  NS_IMETHOD FinishStream(void); \
  NS_IMETHOD FinishUpdate(void); \
  NS_IMETHOD CancelUpdate(void); \
  NS_IMETHOD ResetDatabase(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERDBSERVICE(_to) \
  NS_IMETHOD Lookup(nsIPrincipal *principal, const nsACString & tables, nsIUrlClassifierCallback *c) { return _to Lookup(principal, tables, c); } \
  NS_IMETHOD GetTables(nsIUrlClassifierCallback *c) { return _to GetTables(c); } \
  NS_IMETHOD SetHashCompleter(const nsACString & tableName, nsIUrlClassifierHashCompleter *completer) { return _to SetHashCompleter(tableName, completer); } \
  NS_IMETHOD BeginUpdate(nsIUrlClassifierUpdateObserver *updater, const nsACString & tables) { return _to BeginUpdate(updater, tables); } \
  NS_IMETHOD BeginStream(const nsACString & table) { return _to BeginStream(table); } \
  NS_IMETHOD UpdateStream(const nsACString & updateChunk) { return _to UpdateStream(updateChunk); } \
  NS_IMETHOD FinishStream(void) { return _to FinishStream(); } \
  NS_IMETHOD FinishUpdate(void) { return _to FinishUpdate(); } \
  NS_IMETHOD CancelUpdate(void) { return _to CancelUpdate(); } \
  NS_IMETHOD ResetDatabase(void) { return _to ResetDatabase(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERDBSERVICE(_to) \
  NS_IMETHOD Lookup(nsIPrincipal *principal, const nsACString & tables, nsIUrlClassifierCallback *c) { return !_to ? NS_ERROR_NULL_POINTER : _to->Lookup(principal, tables, c); } \
  NS_IMETHOD GetTables(nsIUrlClassifierCallback *c) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTables(c); } \
  NS_IMETHOD SetHashCompleter(const nsACString & tableName, nsIUrlClassifierHashCompleter *completer) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHashCompleter(tableName, completer); } \
  NS_IMETHOD BeginUpdate(nsIUrlClassifierUpdateObserver *updater, const nsACString & tables) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginUpdate(updater, tables); } \
  NS_IMETHOD BeginStream(const nsACString & table) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginStream(table); } \
  NS_IMETHOD UpdateStream(const nsACString & updateChunk) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateStream(updateChunk); } \
  NS_IMETHOD FinishStream(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->FinishStream(); } \
  NS_IMETHOD FinishUpdate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->FinishUpdate(); } \
  NS_IMETHOD CancelUpdate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelUpdate(); } \
  NS_IMETHOD ResetDatabase(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetDatabase(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierDBService : public nsIUrlClassifierDBService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERDBSERVICE

  nsUrlClassifierDBService();

private:
  ~nsUrlClassifierDBService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlClassifierDBService, nsIUrlClassifierDBService)

nsUrlClassifierDBService::nsUrlClassifierDBService()
{
  /* member initializers and constructor code */
}

nsUrlClassifierDBService::~nsUrlClassifierDBService()
{
  /* destructor code */
}

/* void lookup (in nsIPrincipal principal, in ACString tables, in nsIUrlClassifierCallback c); */
NS_IMETHODIMP nsUrlClassifierDBService::Lookup(nsIPrincipal *principal, const nsACString & tables, nsIUrlClassifierCallback *c)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTables (in nsIUrlClassifierCallback c); */
NS_IMETHODIMP nsUrlClassifierDBService::GetTables(nsIUrlClassifierCallback *c)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setHashCompleter (in ACString tableName, in nsIUrlClassifierHashCompleter completer); */
NS_IMETHODIMP nsUrlClassifierDBService::SetHashCompleter(const nsACString & tableName, nsIUrlClassifierHashCompleter *completer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginUpdate (in nsIUrlClassifierUpdateObserver updater, in ACString tables); */
NS_IMETHODIMP nsUrlClassifierDBService::BeginUpdate(nsIUrlClassifierUpdateObserver *updater, const nsACString & tables)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginStream (in ACString table); */
NS_IMETHODIMP nsUrlClassifierDBService::BeginStream(const nsACString & table)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateStream (in ACString updateChunk); */
NS_IMETHODIMP nsUrlClassifierDBService::UpdateStream(const nsACString & updateChunk)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finishStream (); */
NS_IMETHODIMP nsUrlClassifierDBService::FinishStream()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void finishUpdate (); */
NS_IMETHODIMP nsUrlClassifierDBService::FinishUpdate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelUpdate (); */
NS_IMETHODIMP nsUrlClassifierDBService::CancelUpdate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetDatabase (); */
NS_IMETHODIMP nsUrlClassifierDBService::ResetDatabase()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUrlClassifierDBServiceWorker */
#define NS_IURLCLASSIFIERDBSERVICEWORKER_IID_STR "abcd7978-c304-4a7d-a44c-33c2ed5441e7"

#define NS_IURLCLASSIFIERDBSERVICEWORKER_IID \
  {0xabcd7978, 0xc304, 0x4a7d, \
    { 0xa4, 0x4c, 0x33, 0xc2, 0xed, 0x54, 0x41, 0xe7 }}

class NS_NO_VTABLE nsIUrlClassifierDBServiceWorker : public nsIUrlClassifierDBService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERDBSERVICEWORKER_IID)

  /* void closeDb (); */
  NS_IMETHOD CloseDb(void) = 0;

  /* [noscript] void cacheCompletions (in CacheCompletionArray completions); */
  NS_IMETHOD CacheCompletions(nsTArray<mozilla::safebrowsing::CacheResult> *completions) = 0;

  /* [noscript] void cacheMisses (in PrefixArray misses); */
  NS_IMETHOD CacheMisses(mozilla::safebrowsing::PrefixArray *misses) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierDBServiceWorker, NS_IURLCLASSIFIERDBSERVICEWORKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERDBSERVICEWORKER \
  NS_IMETHOD CloseDb(void); \
  NS_IMETHOD CacheCompletions(nsTArray<mozilla::safebrowsing::CacheResult> *completions); \
  NS_IMETHOD CacheMisses(mozilla::safebrowsing::PrefixArray *misses); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERDBSERVICEWORKER(_to) \
  NS_IMETHOD CloseDb(void) { return _to CloseDb(); } \
  NS_IMETHOD CacheCompletions(nsTArray<mozilla::safebrowsing::CacheResult> *completions) { return _to CacheCompletions(completions); } \
  NS_IMETHOD CacheMisses(mozilla::safebrowsing::PrefixArray *misses) { return _to CacheMisses(misses); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERDBSERVICEWORKER(_to) \
  NS_IMETHOD CloseDb(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseDb(); } \
  NS_IMETHOD CacheCompletions(nsTArray<mozilla::safebrowsing::CacheResult> *completions) { return !_to ? NS_ERROR_NULL_POINTER : _to->CacheCompletions(completions); } \
  NS_IMETHOD CacheMisses(mozilla::safebrowsing::PrefixArray *misses) { return !_to ? NS_ERROR_NULL_POINTER : _to->CacheMisses(misses); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierDBServiceWorker : public nsIUrlClassifierDBServiceWorker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERDBSERVICEWORKER

  nsUrlClassifierDBServiceWorker();

private:
  ~nsUrlClassifierDBServiceWorker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlClassifierDBServiceWorker, nsIUrlClassifierDBServiceWorker)

nsUrlClassifierDBServiceWorker::nsUrlClassifierDBServiceWorker()
{
  /* member initializers and constructor code */
}

nsUrlClassifierDBServiceWorker::~nsUrlClassifierDBServiceWorker()
{
  /* destructor code */
}

/* void closeDb (); */
NS_IMETHODIMP nsUrlClassifierDBServiceWorker::CloseDb()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void cacheCompletions (in CacheCompletionArray completions); */
NS_IMETHODIMP nsUrlClassifierDBServiceWorker::CacheCompletions(nsTArray<mozilla::safebrowsing::CacheResult> *completions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void cacheMisses (in PrefixArray misses); */
NS_IMETHODIMP nsUrlClassifierDBServiceWorker::CacheMisses(mozilla::safebrowsing::PrefixArray *misses)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUrlClassifierLookupCallback */
#define NS_IURLCLASSIFIERLOOKUPCALLBACK_IID_STR "b903dc8f-dff1-42fe-894b-36e7a59bb801"

#define NS_IURLCLASSIFIERLOOKUPCALLBACK_IID \
  {0xb903dc8f, 0xdff1, 0x42fe, \
    { 0x89, 0x4b, 0x36, 0xe7, 0xa5, 0x9b, 0xb8, 0x01 }}

class NS_NO_VTABLE nsIUrlClassifierLookupCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERLOOKUPCALLBACK_IID)

  /* void lookupComplete (in ResultArray results); */
  NS_IMETHOD LookupComplete(nsTArray<mozilla::safebrowsing::LookupResult> *results) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierLookupCallback, NS_IURLCLASSIFIERLOOKUPCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERLOOKUPCALLBACK \
  NS_IMETHOD LookupComplete(nsTArray<mozilla::safebrowsing::LookupResult> *results); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERLOOKUPCALLBACK(_to) \
  NS_IMETHOD LookupComplete(nsTArray<mozilla::safebrowsing::LookupResult> *results) { return _to LookupComplete(results); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERLOOKUPCALLBACK(_to) \
  NS_IMETHOD LookupComplete(nsTArray<mozilla::safebrowsing::LookupResult> *results) { return !_to ? NS_ERROR_NULL_POINTER : _to->LookupComplete(results); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierLookupCallback : public nsIUrlClassifierLookupCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERLOOKUPCALLBACK

  nsUrlClassifierLookupCallback();

private:
  ~nsUrlClassifierLookupCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlClassifierLookupCallback, nsIUrlClassifierLookupCallback)

nsUrlClassifierLookupCallback::nsUrlClassifierLookupCallback()
{
  /* member initializers and constructor code */
}

nsUrlClassifierLookupCallback::~nsUrlClassifierLookupCallback()
{
  /* destructor code */
}

/* void lookupComplete (in ResultArray results); */
NS_IMETHODIMP nsUrlClassifierLookupCallback::LookupComplete(nsTArray<mozilla::safebrowsing::LookupResult> *results)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUrlClassifierDBService_h__ */
