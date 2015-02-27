/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsIContentPrefService.idl
 */

#ifndef __gen_nsIContentPrefService_h__
#define __gen_nsIContentPrefService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIPropertyBag2; /* forward declaration */

class nsIContentURIGrouper; /* forward declaration */

class nsILoadContext; /* forward declaration */

class mozIStorageConnection; /* forward declaration */


/* starting interface:    nsIContentPrefObserver */
#define NS_ICONTENTPREFOBSERVER_IID_STR "746c7a02-f6c1-4869-b434-7c8b86e60e61"

#define NS_ICONTENTPREFOBSERVER_IID \
  {0x746c7a02, 0xf6c1, 0x4869, \
    { 0xb4, 0x34, 0x7c, 0x8b, 0x86, 0xe6, 0x0e, 0x61 }}

class NS_NO_VTABLE nsIContentPrefObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFOBSERVER_IID)

  /* void onContentPrefSet (in AString aGroup, in AString aName, in nsIVariant aValue); */
  NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue) = 0;

  /* void onContentPrefRemoved (in AString aGroup, in AString aName); */
  NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefObserver, NS_ICONTENTPREFOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFOBSERVER \
  NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue); \
  NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFOBSERVER(_to) \
  NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue) { return _to OnContentPrefSet(aGroup, aName, aValue); } \
  NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName) { return _to OnContentPrefRemoved(aGroup, aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFOBSERVER(_to) \
  NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContentPrefSet(aGroup, aName, aValue); } \
  NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContentPrefRemoved(aGroup, aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPrefObserver : public nsIContentPrefObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPREFOBSERVER

  nsContentPrefObserver();

private:
  ~nsContentPrefObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPrefObserver, nsIContentPrefObserver)

nsContentPrefObserver::nsContentPrefObserver()
{
  /* member initializers and constructor code */
}

nsContentPrefObserver::~nsContentPrefObserver()
{
  /* destructor code */
}

/* void onContentPrefSet (in AString aGroup, in AString aName, in nsIVariant aValue); */
NS_IMETHODIMP nsContentPrefObserver::OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onContentPrefRemoved (in AString aGroup, in AString aName); */
NS_IMETHODIMP nsContentPrefObserver::OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPrefCallback */
#define NS_ICONTENTPREFCALLBACK_IID_STR "c1b3d6df-5373-4606-8494-8bcf14a7fc62"

#define NS_ICONTENTPREFCALLBACK_IID \
  {0xc1b3d6df, 0x5373, 0x4606, \
    { 0x84, 0x94, 0x8b, 0xcf, 0x14, 0xa7, 0xfc, 0x62 }}

class NS_NO_VTABLE nsIContentPrefCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFCALLBACK_IID)

  /* void onResult (in nsIVariant aResult); */
  NS_IMETHOD OnResult(nsIVariant *aResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefCallback, NS_ICONTENTPREFCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFCALLBACK \
  NS_IMETHOD OnResult(nsIVariant *aResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFCALLBACK(_to) \
  NS_IMETHOD OnResult(nsIVariant *aResult) { return _to OnResult(aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFCALLBACK(_to) \
  NS_IMETHOD OnResult(nsIVariant *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnResult(aResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPrefCallback : public nsIContentPrefCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPREFCALLBACK

  nsContentPrefCallback();

private:
  ~nsContentPrefCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPrefCallback, nsIContentPrefCallback)

nsContentPrefCallback::nsContentPrefCallback()
{
  /* member initializers and constructor code */
}

nsContentPrefCallback::~nsContentPrefCallback()
{
  /* destructor code */
}

/* void onResult (in nsIVariant aResult); */
NS_IMETHODIMP nsContentPrefCallback::OnResult(nsIVariant *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPrefService */
#define NS_ICONTENTPREFSERVICE_IID_STR "e3f772f3-023f-4b32-b074-36cf0fd5d414"

#define NS_ICONTENTPREFSERVICE_IID \
  {0xe3f772f3, 0x023f, 0x4b32, \
    { 0xb0, 0x74, 0x36, 0xcf, 0x0f, 0xd5, 0xd4, 0x14 }}

class NS_NO_VTABLE nsIContentPrefService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFSERVICE_IID)

  /* nsIVariant getPref (in nsIVariant aGroup, in AString aName, in nsILoadContext aPrivacyContext, [optional] in nsIContentPrefCallback aCallback); */
  NS_IMETHOD GetPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aPrivacyContext, nsIContentPrefCallback *aCallback, nsIVariant * *_retval) = 0;

  /* void setPref (in nsIVariant aGroup, in AString aName, in nsIVariant aValue, in nsILoadContext aPrivacyContext); */
  NS_IMETHOD SetPref(nsIVariant *aGroup, const nsAString & aName, nsIVariant *aValue, nsILoadContext *aPrivacyContext) = 0;

  /* boolean hasPref (in nsIVariant aGroup, in AString aName, in nsILoadContext aContext); */
  NS_IMETHOD HasPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext, bool *_retval) = 0;

  /* boolean hasCachedPref (in nsIVariant aGroup, in AString aName, in nsILoadContext aContext); */
  NS_IMETHOD HasCachedPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext, bool *_retval) = 0;

  /* void removePref (in nsIVariant aGroup, in AString aName, in nsILoadContext aContext); */
  NS_IMETHOD RemovePref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext) = 0;

  /* void removeGroupedPrefs (in nsILoadContext aContext); */
  NS_IMETHOD RemoveGroupedPrefs(nsILoadContext *aContext) = 0;

  /* void removePrefsByName (in AString aName, in nsILoadContext aContext); */
  NS_IMETHOD RemovePrefsByName(const nsAString & aName, nsILoadContext *aContext) = 0;

  /* nsIPropertyBag2 getPrefs (in nsIVariant aGroup, in nsILoadContext aContext); */
  NS_IMETHOD GetPrefs(nsIVariant *aGroup, nsILoadContext *aContext, nsIPropertyBag2 * *_retval) = 0;

  /* nsIPropertyBag2 getPrefsByName (in AString aName, in nsILoadContext aContext); */
  NS_IMETHOD GetPrefsByName(const nsAString & aName, nsILoadContext *aContext, nsIPropertyBag2 * *_retval) = 0;

  /* void addObserver (in AString aName, in nsIContentPrefObserver aObserver); */
  NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) = 0;

  /* void removeObserver (in AString aName, in nsIContentPrefObserver aObserver); */
  NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) = 0;

  /* readonly attribute nsIContentURIGrouper grouper; */
  NS_IMETHOD GetGrouper(nsIContentURIGrouper * *aGrouper) = 0;

  /* readonly attribute mozIStorageConnection DBConnection; */
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefService, NS_ICONTENTPREFSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFSERVICE \
  NS_IMETHOD GetPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aPrivacyContext, nsIContentPrefCallback *aCallback, nsIVariant * *_retval); \
  NS_IMETHOD SetPref(nsIVariant *aGroup, const nsAString & aName, nsIVariant *aValue, nsILoadContext *aPrivacyContext); \
  NS_IMETHOD HasPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext, bool *_retval); \
  NS_IMETHOD HasCachedPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext, bool *_retval); \
  NS_IMETHOD RemovePref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext); \
  NS_IMETHOD RemoveGroupedPrefs(nsILoadContext *aContext); \
  NS_IMETHOD RemovePrefsByName(const nsAString & aName, nsILoadContext *aContext); \
  NS_IMETHOD GetPrefs(nsIVariant *aGroup, nsILoadContext *aContext, nsIPropertyBag2 * *_retval); \
  NS_IMETHOD GetPrefsByName(const nsAString & aName, nsILoadContext *aContext, nsIPropertyBag2 * *_retval); \
  NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver); \
  NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver); \
  NS_IMETHOD GetGrouper(nsIContentURIGrouper * *aGrouper); \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFSERVICE(_to) \
  NS_IMETHOD GetPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aPrivacyContext, nsIContentPrefCallback *aCallback, nsIVariant * *_retval) { return _to GetPref(aGroup, aName, aPrivacyContext, aCallback, _retval); } \
  NS_IMETHOD SetPref(nsIVariant *aGroup, const nsAString & aName, nsIVariant *aValue, nsILoadContext *aPrivacyContext) { return _to SetPref(aGroup, aName, aValue, aPrivacyContext); } \
  NS_IMETHOD HasPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext, bool *_retval) { return _to HasPref(aGroup, aName, aContext, _retval); } \
  NS_IMETHOD HasCachedPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext, bool *_retval) { return _to HasCachedPref(aGroup, aName, aContext, _retval); } \
  NS_IMETHOD RemovePref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext) { return _to RemovePref(aGroup, aName, aContext); } \
  NS_IMETHOD RemoveGroupedPrefs(nsILoadContext *aContext) { return _to RemoveGroupedPrefs(aContext); } \
  NS_IMETHOD RemovePrefsByName(const nsAString & aName, nsILoadContext *aContext) { return _to RemovePrefsByName(aName, aContext); } \
  NS_IMETHOD GetPrefs(nsIVariant *aGroup, nsILoadContext *aContext, nsIPropertyBag2 * *_retval) { return _to GetPrefs(aGroup, aContext, _retval); } \
  NS_IMETHOD GetPrefsByName(const nsAString & aName, nsILoadContext *aContext, nsIPropertyBag2 * *_retval) { return _to GetPrefsByName(aName, aContext, _retval); } \
  NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return _to AddObserver(aName, aObserver); } \
  NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return _to RemoveObserver(aName, aObserver); } \
  NS_IMETHOD GetGrouper(nsIContentURIGrouper * *aGrouper) { return _to GetGrouper(aGrouper); } \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return _to GetDBConnection(aDBConnection); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFSERVICE(_to) \
  NS_IMETHOD GetPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aPrivacyContext, nsIContentPrefCallback *aCallback, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPref(aGroup, aName, aPrivacyContext, aCallback, _retval); } \
  NS_IMETHOD SetPref(nsIVariant *aGroup, const nsAString & aName, nsIVariant *aValue, nsILoadContext *aPrivacyContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPref(aGroup, aName, aValue, aPrivacyContext); } \
  NS_IMETHOD HasPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPref(aGroup, aName, aContext, _retval); } \
  NS_IMETHOD HasCachedPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasCachedPref(aGroup, aName, aContext, _retval); } \
  NS_IMETHOD RemovePref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePref(aGroup, aName, aContext); } \
  NS_IMETHOD RemoveGroupedPrefs(nsILoadContext *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveGroupedPrefs(aContext); } \
  NS_IMETHOD RemovePrefsByName(const nsAString & aName, nsILoadContext *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePrefsByName(aName, aContext); } \
  NS_IMETHOD GetPrefs(nsIVariant *aGroup, nsILoadContext *aContext, nsIPropertyBag2 * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefs(aGroup, aContext, _retval); } \
  NS_IMETHOD GetPrefsByName(const nsAString & aName, nsILoadContext *aContext, nsIPropertyBag2 * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefsByName(aName, aContext, _retval); } \
  NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aName, aObserver); } \
  NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aName, aObserver); } \
  NS_IMETHOD GetGrouper(nsIContentURIGrouper * *aGrouper) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGrouper(aGrouper); } \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBConnection(aDBConnection); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPrefService : public nsIContentPrefService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPREFSERVICE

  nsContentPrefService();

private:
  ~nsContentPrefService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPrefService, nsIContentPrefService)

nsContentPrefService::nsContentPrefService()
{
  /* member initializers and constructor code */
}

nsContentPrefService::~nsContentPrefService()
{
  /* destructor code */
}

/* nsIVariant getPref (in nsIVariant aGroup, in AString aName, in nsILoadContext aPrivacyContext, [optional] in nsIContentPrefCallback aCallback); */
NS_IMETHODIMP nsContentPrefService::GetPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aPrivacyContext, nsIContentPrefCallback *aCallback, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPref (in nsIVariant aGroup, in AString aName, in nsIVariant aValue, in nsILoadContext aPrivacyContext); */
NS_IMETHODIMP nsContentPrefService::SetPref(nsIVariant *aGroup, const nsAString & aName, nsIVariant *aValue, nsILoadContext *aPrivacyContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasPref (in nsIVariant aGroup, in AString aName, in nsILoadContext aContext); */
NS_IMETHODIMP nsContentPrefService::HasPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasCachedPref (in nsIVariant aGroup, in AString aName, in nsILoadContext aContext); */
NS_IMETHODIMP nsContentPrefService::HasCachedPref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePref (in nsIVariant aGroup, in AString aName, in nsILoadContext aContext); */
NS_IMETHODIMP nsContentPrefService::RemovePref(nsIVariant *aGroup, const nsAString & aName, nsILoadContext *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeGroupedPrefs (in nsILoadContext aContext); */
NS_IMETHODIMP nsContentPrefService::RemoveGroupedPrefs(nsILoadContext *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePrefsByName (in AString aName, in nsILoadContext aContext); */
NS_IMETHODIMP nsContentPrefService::RemovePrefsByName(const nsAString & aName, nsILoadContext *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPropertyBag2 getPrefs (in nsIVariant aGroup, in nsILoadContext aContext); */
NS_IMETHODIMP nsContentPrefService::GetPrefs(nsIVariant *aGroup, nsILoadContext *aContext, nsIPropertyBag2 * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPropertyBag2 getPrefsByName (in AString aName, in nsILoadContext aContext); */
NS_IMETHODIMP nsContentPrefService::GetPrefsByName(const nsAString & aName, nsILoadContext *aContext, nsIPropertyBag2 * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in AString aName, in nsIContentPrefObserver aObserver); */
NS_IMETHODIMP nsContentPrefService::AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in AString aName, in nsIContentPrefObserver aObserver); */
NS_IMETHODIMP nsContentPrefService::RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIContentURIGrouper grouper; */
NS_IMETHODIMP nsContentPrefService::GetGrouper(nsIContentURIGrouper * *aGrouper)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageConnection DBConnection; */
NS_IMETHODIMP nsContentPrefService::GetDBConnection(mozIStorageConnection * *aDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// The contractID for the generic implementation built in to xpcom.
#define NS_CONTENT_PREF_SERVICE_CONTRACTID "@mozilla.org/content-pref/service;1"

#endif /* __gen_nsIContentPrefService_h__ */
