/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/base/nsIContentPrefService.idl
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

class mozIStorageConnection; /* forward declaration */


/* starting interface:    nsIContentPrefObserver */
#define NS_ICONTENTPREFOBSERVER_IID_STR "746c7a02-f6c1-4869-b434-7c8b86e60e61"

#define NS_ICONTENTPREFOBSERVER_IID \
  {0x746c7a02, 0xf6c1, 0x4869, \
    { 0xb4, 0x34, 0x7c, 0x8b, 0x86, 0xe6, 0x0e, 0x61 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentPrefObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFOBSERVER_IID)

  /**
   * Called when a content pref is set to a different value.
   * 
   * @param    aGroup      the group to which the pref belongs, or null
   *                       if it's a global pref (applies to all sites)
   * @param    aName       the name of the pref that was set
   * @param    aValue      the new value of the pref
   */
  /* void onContentPrefSet (in AString aGroup, in AString aName, in nsIVariant aValue); */
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue) = 0;

  /**
   * Called when a content pref is removed.
   * 
   * @param    aGroup      the group to which the pref belongs, or null
   *                       if it's a global pref (applies to all sites)
   * @param    aName       the name of the pref that was removed
   */
  /* void onContentPrefRemoved (in AString aGroup, in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefObserver, NS_ICONTENTPREFOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue); \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue) { return _to OnContentPrefSet(aGroup, aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName) { return _to OnContentPrefRemoved(aGroup, aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefSet(const nsAString & aGroup, const nsAString & aName, nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContentPrefSet(aGroup, aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD OnContentPrefRemoved(const nsAString & aGroup, const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnContentPrefRemoved(aGroup, aName); } 

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

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentPrefCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFCALLBACK_IID)

  /* void onResult (in nsIVariant aResult); */
  NS_SCRIPTABLE NS_IMETHOD OnResult(nsIVariant *aResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefCallback, NS_ICONTENTPREFCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD OnResult(nsIVariant *aResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnResult(nsIVariant *aResult) { return _to OnResult(aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnResult(nsIVariant *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnResult(aResult); } 

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
#define NS_ICONTENTPREFSERVICE_IID_STR "36715960-de39-457b-9d02-b800d5d3079b"

#define NS_ICONTENTPREFSERVICE_IID \
  {0x36715960, 0xde39, 0x457b, \
    { 0x9d, 0x02, 0xb8, 0x00, 0xd5, 0xd3, 0x07, 0x9b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentPrefService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFSERVICE_IID)

  /**
   * Get a pref.
   *
   * Besides the regular string, integer, boolean, etc. values, this method
   * may return null (nsIDataType::VTYPE_EMPTY), which means the pref is set
   * to NULL in the database, as well as undefined (nsIDataType::VTYPE_VOID),
   * which means there is no record for this pref in the database.
   *
   * This method can be called from content processes in electrolysis builds.
   * We have a whitelist of values that can be read in such a way.
   *
   * @param    aGroup      the group for which to get the pref, as an nsIURI
   *                       from which the hostname will be used, a string
   *                       (typically in the format of a hostname), or null 
   *                       to get the global pref (applies to all sites)
   * @param    aName       the name of the pref to get
   * @param    aCallback   an optional nsIContentPrefCallback to receive the
   *                       result. If desired, JavaScript callers can instead
   *                       provide a function to call upon completion
   *
   * @returns  the value of the pref
   * @throws   NS_ERROR_ILLEGAL_VALUE if aGroup is not a string, nsIURI, or null
   * @throws   NS_ERROR_ILLEGAL_VALUE if aName is null or an empty string
   */
  /* nsIVariant getPref (in nsIVariant aGroup, in AString aName, [optional] in nsIContentPrefCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD GetPref(nsIVariant *aGroup, const nsAString & aName, nsIContentPrefCallback *aCallback, nsIVariant **_retval NS_OUTPARAM) = 0;

  /**
   * Set a pref.
   *
   * This method can be called from content processes in electrolysis builds.
   * We have a whitelist of values that can be set in such a way.
   *
   * @param    aGroup      the group for which to set the pref, as an nsIURI
   *                       from which the hostname will be used, a string
   *                       (typically in the format of a hostname), or null
   *                       to set the global pref (applies to all sites)
   * @param    aName       the name of the pref to set
   * @param    aValue      the new value of the pref
   * @throws   NS_ERROR_ILLEGAL_VALUE if aGroup is not a string, nsIURI, or null
   * @throws   NS_ERROR_ILLEGAL_VALUE if aName is null or an empty string
   */
  /* void setPref (in nsIVariant aGroup, in AString aName, in nsIVariant aValue); */
  NS_SCRIPTABLE NS_IMETHOD SetPref(nsIVariant *aGroup, const nsAString & aName, nsIVariant *aValue) = 0;

  /**
   * Check whether or not a pref exists.
   *
   * @param    aGroup      the group for which to check for the pref, as an nsIURI
   *                       from which the hostname will be used, a string
   *                       (typically in the format of a hostname), or null
   *                       to check for the global pref (applies to all sites)
   * @param    aName       the name of the pref to check for
   * @throws   NS_ERROR_ILLEGAL_VALUE if aGroup is not a string, nsIURI, or null
   * @throws   NS_ERROR_ILLEGAL_VALUE if aName is null or an empty string
   */
  /* boolean hasPref (in nsIVariant aGroup, in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD HasPref(nsIVariant *aGroup, const nsAString & aName, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Remove a pref.
   *
   * @param    aGroup      the group for which to remove the pref, as an nsIURI
   *                       from which the hostname will be used, a string
   *                       (typically in the format of a hostname), or null
   *                       to remove the global pref (applies to all sites) 
   * @param    aName       the name of the pref to remove
   * @throws   NS_ERROR_ILLEGAL_VALUE if aGroup is not a string, nsIURI, or null
   * @throws   NS_ERROR_ILLEGAL_VALUE if aName is null or an empty string
   */
  /* void removePref (in nsIVariant aGroup, in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD RemovePref(nsIVariant *aGroup, const nsAString & aName) = 0;

  /**
   * Remove all grouped prefs.  Useful for removing references to the sites
   * the user has visited when the user clears their private data.
   */
  /* void removeGroupedPrefs (); */
  NS_SCRIPTABLE NS_IMETHOD RemoveGroupedPrefs(void) = 0;

  /**
   * Remove all prefs with the given name.
   *
   * @param    aName        the setting name for which to remove prefs
   * @throws   NS_ERROR_ILLEGAL_VALUE if aName is null or an empty string
   */
  /* void removePrefsByName (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD RemovePrefsByName(const nsAString & aName) = 0;

  /**
   * Get the prefs that apply to the given site.
   *
   * @param    aGroup      the group for which to retrieve prefs, as an nsIURI
   *                       from which the hostname will be used, a string
   *                       (typically in the format of a hostname), or null
   *                       to get the global prefs (apply to all sites) 
   * 
   * @returns  a property bag of prefs
   * @throws   NS_ERROR_ILLEGAL_VALUE if aGroup is not a string, nsIURI, or null
   */
  /* nsIPropertyBag2 getPrefs (in nsIVariant aGroup); */
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(nsIVariant *aGroup, nsIPropertyBag2 **_retval NS_OUTPARAM) = 0;

  /**
   * Get the prefs with the given name.
   *
   * @param    aName        the setting name for which to retrieve prefs
   * 
   * @returns  a property bag of prefs
   * @throws   NS_ERROR_ILLEGAL_VALUE if aName is null or an empty string
   */
  /* nsIPropertyBag2 getPrefsByName (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD GetPrefsByName(const nsAString & aName, nsIPropertyBag2 **_retval NS_OUTPARAM) = 0;

  /**
   * Add an observer.
   * 
   * @param    aName       the setting to observe, or null to add
   *                       a generic observer that observes all settings
   * @param    aObserver   the observer to add
   */
  /* void addObserver (in AString aName, in nsIContentPrefObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) = 0;

  /**
   * Remove an observer.
   *
   * @param    aName       the setting being observed, or null to remove
   *                       a generic observer that observes all settings
   * @param    aObserver   the observer to remove
   */
  /* void removeObserver (in AString aName, in nsIContentPrefObserver aObserver); */
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) = 0;

  /**
   * The component that the service uses to determine the groups to which
   * URIs belong.  By default this is the "hostname grouper", which groups
   * URIs by full hostname (a.k.a. site).
   */
  /* readonly attribute nsIContentURIGrouper grouper; */
  NS_SCRIPTABLE NS_IMETHOD GetGrouper(nsIContentURIGrouper **aGrouper) = 0;

  /**
   * The database connection to the content preferences database.
   * Useful for accessing and manipulating preferences in ways that are caller-
   * specific or for which there is not yet a generic method, although generic
   * functionality useful to multiple callers should generally be added to this
   * unfrozen interface.  Also useful for testing the database creation
   * and migration code.
   */
  /* readonly attribute mozIStorageConnection DBConnection; */
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection **aDBConnection) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefService, NS_ICONTENTPREFSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFSERVICE \
  NS_SCRIPTABLE NS_IMETHOD GetPref(nsIVariant *aGroup, const nsAString & aName, nsIContentPrefCallback *aCallback, nsIVariant **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetPref(nsIVariant *aGroup, const nsAString & aName, nsIVariant *aValue); \
  NS_SCRIPTABLE NS_IMETHOD HasPref(nsIVariant *aGroup, const nsAString & aName, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemovePref(nsIVariant *aGroup, const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD RemoveGroupedPrefs(void); \
  NS_SCRIPTABLE NS_IMETHOD RemovePrefsByName(const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(nsIVariant *aGroup, nsIPropertyBag2 **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetPrefsByName(const nsAString & aName, nsIPropertyBag2 **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver); \
  NS_SCRIPTABLE NS_IMETHOD GetGrouper(nsIContentURIGrouper **aGrouper); \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection **aDBConnection); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPref(nsIVariant *aGroup, const nsAString & aName, nsIContentPrefCallback *aCallback, nsIVariant **_retval NS_OUTPARAM) { return _to GetPref(aGroup, aName, aCallback, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetPref(nsIVariant *aGroup, const nsAString & aName, nsIVariant *aValue) { return _to SetPref(aGroup, aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD HasPref(nsIVariant *aGroup, const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return _to HasPref(aGroup, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePref(nsIVariant *aGroup, const nsAString & aName) { return _to RemovePref(aGroup, aName); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveGroupedPrefs(void) { return _to RemoveGroupedPrefs(); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePrefsByName(const nsAString & aName) { return _to RemovePrefsByName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(nsIVariant *aGroup, nsIPropertyBag2 **_retval NS_OUTPARAM) { return _to GetPrefs(aGroup, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefsByName(const nsAString & aName, nsIPropertyBag2 **_retval NS_OUTPARAM) { return _to GetPrefsByName(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return _to AddObserver(aName, aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return _to RemoveObserver(aName, aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetGrouper(nsIContentURIGrouper **aGrouper) { return _to GetGrouper(aGrouper); } \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection **aDBConnection) { return _to GetDBConnection(aDBConnection); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPref(nsIVariant *aGroup, const nsAString & aName, nsIContentPrefCallback *aCallback, nsIVariant **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPref(aGroup, aName, aCallback, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetPref(nsIVariant *aGroup, const nsAString & aName, nsIVariant *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPref(aGroup, aName, aValue); } \
  NS_SCRIPTABLE NS_IMETHOD HasPref(nsIVariant *aGroup, const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPref(aGroup, aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePref(nsIVariant *aGroup, const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePref(aGroup, aName); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveGroupedPrefs(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveGroupedPrefs(); } \
  NS_SCRIPTABLE NS_IMETHOD RemovePrefsByName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePrefsByName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefs(nsIVariant *aGroup, nsIPropertyBag2 **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefs(aGroup, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetPrefsByName(const nsAString & aName, nsIPropertyBag2 **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrefsByName(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aName, aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveObserver(const nsAString & aName, nsIContentPrefObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aName, aObserver); } \
  NS_SCRIPTABLE NS_IMETHOD GetGrouper(nsIContentURIGrouper **aGrouper) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGrouper(aGrouper); } \
  NS_SCRIPTABLE NS_IMETHOD GetDBConnection(mozIStorageConnection **aDBConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBConnection(aDBConnection); } 

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

/* nsIVariant getPref (in nsIVariant aGroup, in AString aName, [optional] in nsIContentPrefCallback aCallback); */
NS_IMETHODIMP nsContentPrefService::GetPref(nsIVariant *aGroup, const nsAString & aName, nsIContentPrefCallback *aCallback, nsIVariant **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPref (in nsIVariant aGroup, in AString aName, in nsIVariant aValue); */
NS_IMETHODIMP nsContentPrefService::SetPref(nsIVariant *aGroup, const nsAString & aName, nsIVariant *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasPref (in nsIVariant aGroup, in AString aName); */
NS_IMETHODIMP nsContentPrefService::HasPref(nsIVariant *aGroup, const nsAString & aName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePref (in nsIVariant aGroup, in AString aName); */
NS_IMETHODIMP nsContentPrefService::RemovePref(nsIVariant *aGroup, const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeGroupedPrefs (); */
NS_IMETHODIMP nsContentPrefService::RemoveGroupedPrefs()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePrefsByName (in AString aName); */
NS_IMETHODIMP nsContentPrefService::RemovePrefsByName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPropertyBag2 getPrefs (in nsIVariant aGroup); */
NS_IMETHODIMP nsContentPrefService::GetPrefs(nsIVariant *aGroup, nsIPropertyBag2 **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIPropertyBag2 getPrefsByName (in AString aName); */
NS_IMETHODIMP nsContentPrefService::GetPrefsByName(const nsAString & aName, nsIPropertyBag2 **_retval NS_OUTPARAM)
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
NS_IMETHODIMP nsContentPrefService::GetGrouper(nsIContentURIGrouper **aGrouper)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageConnection DBConnection; */
NS_IMETHODIMP nsContentPrefService::GetDBConnection(mozIStorageConnection **aDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPrefService_MOZILLA_2_0 */
#define NS_ICONTENTPREFSERVICE_MOZILLA_2_0_IID_STR "126f07cb-edfe-497e-87dd-ba906506b287"

#define NS_ICONTENTPREFSERVICE_MOZILLA_2_0_IID \
  {0x126f07cb, 0xedfe, 0x497e, \
    { 0x87, 0xdd, 0xba, 0x90, 0x65, 0x06, 0xb2, 0x87 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIContentPrefService_MOZILLA_2_0 : public nsIContentPrefService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFSERVICE_MOZILLA_2_0_IID)

  /**
   * Check whether or not the value of a pref (or its non-existance) is cached.
   *
   * @param    aGroup      the group for which to check for the pref, as an nsIURI
   *                       from which the hostname will be used, a string
   *                       (typically in the format of a hostname), or null
   *                       to check for the global pref (applies to all sites)
   * @param    aName       the name of the pref to check for
   * @throws   NS_ERROR_ILLEGAL_VALUE if aGroup is not a string, nsIURI, or null
   * @throws   NS_ERROR_ILLEGAL_VALUE if aName is null or an empty string
   */
  /* boolean hasCachedPref (in nsIVariant aGroup, in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD HasCachedPref(nsIVariant *aGroup, const nsAString & aName, PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefService_MOZILLA_2_0, NS_ICONTENTPREFSERVICE_MOZILLA_2_0_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFSERVICE_MOZILLA_2_0 \
  NS_SCRIPTABLE NS_IMETHOD HasCachedPref(nsIVariant *aGroup, const nsAString & aName, PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFSERVICE_MOZILLA_2_0(_to) \
  NS_SCRIPTABLE NS_IMETHOD HasCachedPref(nsIVariant *aGroup, const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return _to HasCachedPref(aGroup, aName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFSERVICE_MOZILLA_2_0(_to) \
  NS_SCRIPTABLE NS_IMETHOD HasCachedPref(nsIVariant *aGroup, const nsAString & aName, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasCachedPref(aGroup, aName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPrefService_MOZILLA_2_0 : public nsIContentPrefService_MOZILLA_2_0
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPREFSERVICE_MOZILLA_2_0

  nsContentPrefService_MOZILLA_2_0();

private:
  ~nsContentPrefService_MOZILLA_2_0();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPrefService_MOZILLA_2_0, nsIContentPrefService_MOZILLA_2_0)

nsContentPrefService_MOZILLA_2_0::nsContentPrefService_MOZILLA_2_0()
{
  /* member initializers and constructor code */
}

nsContentPrefService_MOZILLA_2_0::~nsContentPrefService_MOZILLA_2_0()
{
  /* destructor code */
}

/* boolean hasCachedPref (in nsIVariant aGroup, in AString aName); */
NS_IMETHODIMP nsContentPrefService_MOZILLA_2_0::HasCachedPref(nsIVariant *aGroup, const nsAString & aName, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// The contractID for the generic implementation built in to xpcom.
#define NS_CONTENT_PREF_SERVICE_CONTRACTID "@mozilla.org/content-pref/service;1"

#endif /* __gen_nsIContentPrefService_h__ */
