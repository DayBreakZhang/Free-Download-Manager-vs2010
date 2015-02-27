/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/url-classifier/nsIUrlListManager.idl
 */

#ifndef __gen_nsIUrlListManager_h__
#define __gen_nsIUrlListManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIUrlListManagerCallback */
#define NS_IURLLISTMANAGERCALLBACK_IID_STR "fa4caf12-d057-4e7e-81e9-ce066ceee90b"

#define NS_IURLLISTMANAGERCALLBACK_IID \
  {0xfa4caf12, 0xd057, 0x4e7e, \
    { 0x81, 0xe9, 0xce, 0x06, 0x6c, 0xee, 0xe9, 0x0b }}

class NS_NO_VTABLE nsIUrlListManagerCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLLISTMANAGERCALLBACK_IID)

  /* void handleEvent (in ACString value); */
  NS_IMETHOD HandleEvent(const nsACString & value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlListManagerCallback, NS_IURLLISTMANAGERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLLISTMANAGERCALLBACK \
  NS_IMETHOD HandleEvent(const nsACString & value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLLISTMANAGERCALLBACK(_to) \
  NS_IMETHOD HandleEvent(const nsACString & value) { return _to HandleEvent(value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLLISTMANAGERCALLBACK(_to) \
  NS_IMETHOD HandleEvent(const nsACString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlListManagerCallback : public nsIUrlListManagerCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLLISTMANAGERCALLBACK

  nsUrlListManagerCallback();

private:
  ~nsUrlListManagerCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlListManagerCallback, nsIUrlListManagerCallback)

nsUrlListManagerCallback::nsUrlListManagerCallback()
{
  /* member initializers and constructor code */
}

nsUrlListManagerCallback::~nsUrlListManagerCallback()
{
  /* destructor code */
}

/* void handleEvent (in ACString value); */
NS_IMETHODIMP nsUrlListManagerCallback::HandleEvent(const nsACString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUrlListManager */
#define NS_IURLLISTMANAGER_IID_STR "5b4645b6-f9ca-4cb1-a821-2bdb3c3902f8"

#define NS_IURLLISTMANAGER_IID \
  {0x5b4645b6, 0xf9ca, 0x4cb1, \
    { 0xa8, 0x21, 0x2b, 0xdb, 0x3c, 0x39, 0x02, 0xf8 }}

class NS_NO_VTABLE nsIUrlListManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLLISTMANAGER_IID)

  /* void setUpdateUrl (in ACString url); */
  NS_IMETHOD SetUpdateUrl(const nsACString & url) = 0;

  /* void setKeyUrl (in ACString url); */
  NS_IMETHOD SetKeyUrl(const nsACString & url) = 0;

  /* void setGethashUrl (in ACString url); */
  NS_IMETHOD SetGethashUrl(const nsACString & url) = 0;

  /* boolean registerTable (in ACString tableName, in boolean requireMac); */
  NS_IMETHOD RegisterTable(const nsACString & tableName, bool requireMac, bool *_retval) = 0;

  /* void enableUpdate (in ACString tableName); */
  NS_IMETHOD EnableUpdate(const nsACString & tableName) = 0;

  /* void disableUpdate (in ACString tableName); */
  NS_IMETHOD DisableUpdate(const nsACString & tableName) = 0;

  /* void safeLookup (in nsIPrincipal key, in nsIUrlListManagerCallback cb); */
  NS_IMETHOD SafeLookup(nsIPrincipal *key, nsIUrlListManagerCallback *cb) = 0;

  /* void checkForUpdates (); */
  NS_IMETHOD CheckForUpdates(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlListManager, NS_IURLLISTMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLLISTMANAGER \
  NS_IMETHOD SetUpdateUrl(const nsACString & url); \
  NS_IMETHOD SetKeyUrl(const nsACString & url); \
  NS_IMETHOD SetGethashUrl(const nsACString & url); \
  NS_IMETHOD RegisterTable(const nsACString & tableName, bool requireMac, bool *_retval); \
  NS_IMETHOD EnableUpdate(const nsACString & tableName); \
  NS_IMETHOD DisableUpdate(const nsACString & tableName); \
  NS_IMETHOD SafeLookup(nsIPrincipal *key, nsIUrlListManagerCallback *cb); \
  NS_IMETHOD CheckForUpdates(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLLISTMANAGER(_to) \
  NS_IMETHOD SetUpdateUrl(const nsACString & url) { return _to SetUpdateUrl(url); } \
  NS_IMETHOD SetKeyUrl(const nsACString & url) { return _to SetKeyUrl(url); } \
  NS_IMETHOD SetGethashUrl(const nsACString & url) { return _to SetGethashUrl(url); } \
  NS_IMETHOD RegisterTable(const nsACString & tableName, bool requireMac, bool *_retval) { return _to RegisterTable(tableName, requireMac, _retval); } \
  NS_IMETHOD EnableUpdate(const nsACString & tableName) { return _to EnableUpdate(tableName); } \
  NS_IMETHOD DisableUpdate(const nsACString & tableName) { return _to DisableUpdate(tableName); } \
  NS_IMETHOD SafeLookup(nsIPrincipal *key, nsIUrlListManagerCallback *cb) { return _to SafeLookup(key, cb); } \
  NS_IMETHOD CheckForUpdates(void) { return _to CheckForUpdates(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLLISTMANAGER(_to) \
  NS_IMETHOD SetUpdateUrl(const nsACString & url) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUpdateUrl(url); } \
  NS_IMETHOD SetKeyUrl(const nsACString & url) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKeyUrl(url); } \
  NS_IMETHOD SetGethashUrl(const nsACString & url) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGethashUrl(url); } \
  NS_IMETHOD RegisterTable(const nsACString & tableName, bool requireMac, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterTable(tableName, requireMac, _retval); } \
  NS_IMETHOD EnableUpdate(const nsACString & tableName) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableUpdate(tableName); } \
  NS_IMETHOD DisableUpdate(const nsACString & tableName) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableUpdate(tableName); } \
  NS_IMETHOD SafeLookup(nsIPrincipal *key, nsIUrlListManagerCallback *cb) { return !_to ? NS_ERROR_NULL_POINTER : _to->SafeLookup(key, cb); } \
  NS_IMETHOD CheckForUpdates(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForUpdates(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlListManager : public nsIUrlListManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLLISTMANAGER

  nsUrlListManager();

private:
  ~nsUrlListManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlListManager, nsIUrlListManager)

nsUrlListManager::nsUrlListManager()
{
  /* member initializers and constructor code */
}

nsUrlListManager::~nsUrlListManager()
{
  /* destructor code */
}

/* void setUpdateUrl (in ACString url); */
NS_IMETHODIMP nsUrlListManager::SetUpdateUrl(const nsACString & url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setKeyUrl (in ACString url); */
NS_IMETHODIMP nsUrlListManager::SetKeyUrl(const nsACString & url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setGethashUrl (in ACString url); */
NS_IMETHODIMP nsUrlListManager::SetGethashUrl(const nsACString & url)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean registerTable (in ACString tableName, in boolean requireMac); */
NS_IMETHODIMP nsUrlListManager::RegisterTable(const nsACString & tableName, bool requireMac, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableUpdate (in ACString tableName); */
NS_IMETHODIMP nsUrlListManager::EnableUpdate(const nsACString & tableName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableUpdate (in ACString tableName); */
NS_IMETHODIMP nsUrlListManager::DisableUpdate(const nsACString & tableName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void safeLookup (in nsIPrincipal key, in nsIUrlListManagerCallback cb); */
NS_IMETHODIMP nsUrlListManager::SafeLookup(nsIPrincipal *key, nsIUrlListManagerCallback *cb)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkForUpdates (); */
NS_IMETHODIMP nsUrlListManager::CheckForUpdates()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUrlListManager_h__ */
