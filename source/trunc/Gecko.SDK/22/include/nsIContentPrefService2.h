/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsIContentPrefService2.idl
 */

#ifndef __gen_nsIContentPrefService2_h__
#define __gen_nsIContentPrefService2_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIContentPrefObserver; /* forward declaration */

class nsIContentPrefCallback2; /* forward declaration */

class nsILoadContext; /* forward declaration */

class nsIContentPref; /* forward declaration */


/* starting interface:    nsIContentPrefService2 */
#define NS_ICONTENTPREFSERVICE2_IID_STR "133608c7-f812-41ca-bc1c-62a4eb95e52a"

#define NS_ICONTENTPREFSERVICE2_IID \
  {0x133608c7, 0xf812, 0x41ca, \
    { 0xbc, 0x1c, 0x62, 0xa4, 0xeb, 0x95, 0xe5, 0x2a }}

class NS_NO_VTABLE nsIContentPrefService2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFSERVICE2_IID)

  /* void getByDomainAndName (in AString domain, in AString name, in nsILoadContext context, in nsIContentPrefCallback2 callback); */
  NS_IMETHOD GetByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void getBySubdomainAndName (in AString domain, in AString name, in nsILoadContext context, in nsIContentPrefCallback2 callback); */
  NS_IMETHOD GetBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void getGlobal (in AString name, in nsILoadContext context, in nsIContentPrefCallback2 callback); */
  NS_IMETHOD GetGlobal(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* nsIContentPref getCachedByDomainAndName (in AString domain, in AString name, in nsILoadContext context); */
  NS_IMETHOD GetCachedByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPref * *_retval) = 0;

  /* void getCachedBySubdomainAndName (in AString domain, in AString name, in nsILoadContext context, out unsigned long len, [array, size_is (len), retval] out nsIContentPref prefs); */
  NS_IMETHOD GetCachedBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, uint32_t *len, nsIContentPref * **prefs) = 0;

  /* nsIContentPref getCachedGlobal (in AString name, in nsILoadContext context); */
  NS_IMETHOD GetCachedGlobal(const nsAString & name, nsILoadContext *context, nsIContentPref * *_retval) = 0;

  /* void set (in AString domain, in AString name, in nsIVariant value, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
  NS_IMETHOD Set(const nsAString & domain, const nsAString & name, nsIVariant *value, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void setGlobal (in AString name, in nsIVariant value, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
  NS_IMETHOD SetGlobal(const nsAString & name, nsIVariant *value, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void removeByDomainAndName (in AString domain, in AString name, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
  NS_IMETHOD RemoveByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void removeBySubdomainAndName (in AString domain, in AString name, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
  NS_IMETHOD RemoveBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void removeGlobal (in AString name, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
  NS_IMETHOD RemoveGlobal(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void removeByDomain (in AString domain, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
  NS_IMETHOD RemoveByDomain(const nsAString & domain, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void removeBySubdomain (in AString domain, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
  NS_IMETHOD RemoveBySubdomain(const nsAString & domain, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void removeByName (in AString name, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
  NS_IMETHOD RemoveByName(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void removeAllDomains (in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
  NS_IMETHOD RemoveAllDomains(nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void removeAllGlobals (in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
  NS_IMETHOD RemoveAllGlobals(nsILoadContext *context, nsIContentPrefCallback2 *callback) = 0;

  /* void addObserverForName (in AString name, in nsIContentPrefObserver observer); */
  NS_IMETHOD AddObserverForName(const nsAString & name, nsIContentPrefObserver *observer) = 0;

  /* void removeObserverForName (in AString name, in nsIContentPrefObserver observer); */
  NS_IMETHOD RemoveObserverForName(const nsAString & name, nsIContentPrefObserver *observer) = 0;

  /* AString extractDomain (in AString str); */
  NS_IMETHOD ExtractDomain(const nsAString & str, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefService2, NS_ICONTENTPREFSERVICE2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFSERVICE2 \
  NS_IMETHOD GetByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD GetBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD GetGlobal(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD GetCachedByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPref * *_retval); \
  NS_IMETHOD GetCachedBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, uint32_t *len, nsIContentPref * **prefs); \
  NS_IMETHOD GetCachedGlobal(const nsAString & name, nsILoadContext *context, nsIContentPref * *_retval); \
  NS_IMETHOD Set(const nsAString & domain, const nsAString & name, nsIVariant *value, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD SetGlobal(const nsAString & name, nsIVariant *value, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD RemoveByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD RemoveBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD RemoveGlobal(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD RemoveByDomain(const nsAString & domain, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD RemoveBySubdomain(const nsAString & domain, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD RemoveByName(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD RemoveAllDomains(nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD RemoveAllGlobals(nsILoadContext *context, nsIContentPrefCallback2 *callback); \
  NS_IMETHOD AddObserverForName(const nsAString & name, nsIContentPrefObserver *observer); \
  NS_IMETHOD RemoveObserverForName(const nsAString & name, nsIContentPrefObserver *observer); \
  NS_IMETHOD ExtractDomain(const nsAString & str, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFSERVICE2(_to) \
  NS_IMETHOD GetByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to GetByDomainAndName(domain, name, context, callback); } \
  NS_IMETHOD GetBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to GetBySubdomainAndName(domain, name, context, callback); } \
  NS_IMETHOD GetGlobal(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to GetGlobal(name, context, callback); } \
  NS_IMETHOD GetCachedByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPref * *_retval) { return _to GetCachedByDomainAndName(domain, name, context, _retval); } \
  NS_IMETHOD GetCachedBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, uint32_t *len, nsIContentPref * **prefs) { return _to GetCachedBySubdomainAndName(domain, name, context, len, prefs); } \
  NS_IMETHOD GetCachedGlobal(const nsAString & name, nsILoadContext *context, nsIContentPref * *_retval) { return _to GetCachedGlobal(name, context, _retval); } \
  NS_IMETHOD Set(const nsAString & domain, const nsAString & name, nsIVariant *value, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to Set(domain, name, value, context, callback); } \
  NS_IMETHOD SetGlobal(const nsAString & name, nsIVariant *value, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to SetGlobal(name, value, context, callback); } \
  NS_IMETHOD RemoveByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to RemoveByDomainAndName(domain, name, context, callback); } \
  NS_IMETHOD RemoveBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to RemoveBySubdomainAndName(domain, name, context, callback); } \
  NS_IMETHOD RemoveGlobal(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to RemoveGlobal(name, context, callback); } \
  NS_IMETHOD RemoveByDomain(const nsAString & domain, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to RemoveByDomain(domain, context, callback); } \
  NS_IMETHOD RemoveBySubdomain(const nsAString & domain, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to RemoveBySubdomain(domain, context, callback); } \
  NS_IMETHOD RemoveByName(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to RemoveByName(name, context, callback); } \
  NS_IMETHOD RemoveAllDomains(nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to RemoveAllDomains(context, callback); } \
  NS_IMETHOD RemoveAllGlobals(nsILoadContext *context, nsIContentPrefCallback2 *callback) { return _to RemoveAllGlobals(context, callback); } \
  NS_IMETHOD AddObserverForName(const nsAString & name, nsIContentPrefObserver *observer) { return _to AddObserverForName(name, observer); } \
  NS_IMETHOD RemoveObserverForName(const nsAString & name, nsIContentPrefObserver *observer) { return _to RemoveObserverForName(name, observer); } \
  NS_IMETHOD ExtractDomain(const nsAString & str, nsAString & _retval) { return _to ExtractDomain(str, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFSERVICE2(_to) \
  NS_IMETHOD GetByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetByDomainAndName(domain, name, context, callback); } \
  NS_IMETHOD GetBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBySubdomainAndName(domain, name, context, callback); } \
  NS_IMETHOD GetGlobal(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobal(name, context, callback); } \
  NS_IMETHOD GetCachedByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPref * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedByDomainAndName(domain, name, context, _retval); } \
  NS_IMETHOD GetCachedBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, uint32_t *len, nsIContentPref * **prefs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedBySubdomainAndName(domain, name, context, len, prefs); } \
  NS_IMETHOD GetCachedGlobal(const nsAString & name, nsILoadContext *context, nsIContentPref * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCachedGlobal(name, context, _retval); } \
  NS_IMETHOD Set(const nsAString & domain, const nsAString & name, nsIVariant *value, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(domain, name, value, context, callback); } \
  NS_IMETHOD SetGlobal(const nsAString & name, nsIVariant *value, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGlobal(name, value, context, callback); } \
  NS_IMETHOD RemoveByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveByDomainAndName(domain, name, context, callback); } \
  NS_IMETHOD RemoveBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveBySubdomainAndName(domain, name, context, callback); } \
  NS_IMETHOD RemoveGlobal(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveGlobal(name, context, callback); } \
  NS_IMETHOD RemoveByDomain(const nsAString & domain, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveByDomain(domain, context, callback); } \
  NS_IMETHOD RemoveBySubdomain(const nsAString & domain, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveBySubdomain(domain, context, callback); } \
  NS_IMETHOD RemoveByName(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveByName(name, context, callback); } \
  NS_IMETHOD RemoveAllDomains(nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllDomains(context, callback); } \
  NS_IMETHOD RemoveAllGlobals(nsILoadContext *context, nsIContentPrefCallback2 *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAllGlobals(context, callback); } \
  NS_IMETHOD AddObserverForName(const nsAString & name, nsIContentPrefObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserverForName(name, observer); } \
  NS_IMETHOD RemoveObserverForName(const nsAString & name, nsIContentPrefObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserverForName(name, observer); } \
  NS_IMETHOD ExtractDomain(const nsAString & str, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtractDomain(str, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPrefService2 : public nsIContentPrefService2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPREFSERVICE2

  nsContentPrefService2();

private:
  ~nsContentPrefService2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPrefService2, nsIContentPrefService2)

nsContentPrefService2::nsContentPrefService2()
{
  /* member initializers and constructor code */
}

nsContentPrefService2::~nsContentPrefService2()
{
  /* destructor code */
}

/* void getByDomainAndName (in AString domain, in AString name, in nsILoadContext context, in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::GetByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getBySubdomainAndName (in AString domain, in AString name, in nsILoadContext context, in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::GetBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getGlobal (in AString name, in nsILoadContext context, in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::GetGlobal(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIContentPref getCachedByDomainAndName (in AString domain, in AString name, in nsILoadContext context); */
NS_IMETHODIMP nsContentPrefService2::GetCachedByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPref * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCachedBySubdomainAndName (in AString domain, in AString name, in nsILoadContext context, out unsigned long len, [array, size_is (len), retval] out nsIContentPref prefs); */
NS_IMETHODIMP nsContentPrefService2::GetCachedBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, uint32_t *len, nsIContentPref * **prefs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIContentPref getCachedGlobal (in AString name, in nsILoadContext context); */
NS_IMETHODIMP nsContentPrefService2::GetCachedGlobal(const nsAString & name, nsILoadContext *context, nsIContentPref * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void set (in AString domain, in AString name, in nsIVariant value, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::Set(const nsAString & domain, const nsAString & name, nsIVariant *value, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setGlobal (in AString name, in nsIVariant value, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::SetGlobal(const nsAString & name, nsIVariant *value, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeByDomainAndName (in AString domain, in AString name, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::RemoveByDomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeBySubdomainAndName (in AString domain, in AString name, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::RemoveBySubdomainAndName(const nsAString & domain, const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeGlobal (in AString name, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::RemoveGlobal(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeByDomain (in AString domain, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::RemoveByDomain(const nsAString & domain, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeBySubdomain (in AString domain, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::RemoveBySubdomain(const nsAString & domain, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeByName (in AString name, in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::RemoveByName(const nsAString & name, nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllDomains (in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::RemoveAllDomains(nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeAllGlobals (in nsILoadContext context, [optional] in nsIContentPrefCallback2 callback); */
NS_IMETHODIMP nsContentPrefService2::RemoveAllGlobals(nsILoadContext *context, nsIContentPrefCallback2 *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserverForName (in AString name, in nsIContentPrefObserver observer); */
NS_IMETHODIMP nsContentPrefService2::AddObserverForName(const nsAString & name, nsIContentPrefObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserverForName (in AString name, in nsIContentPrefObserver observer); */
NS_IMETHODIMP nsContentPrefService2::RemoveObserverForName(const nsAString & name, nsIContentPrefObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString extractDomain (in AString str); */
NS_IMETHODIMP nsContentPrefService2::ExtractDomain(const nsAString & str, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPrefCallback2 */
#define NS_ICONTENTPREFCALLBACK2_IID_STR "1a12cf41-79e8-4d0f-9899-2f7b27c5d9a1"

#define NS_ICONTENTPREFCALLBACK2_IID \
  {0x1a12cf41, 0x79e8, 0x4d0f, \
    { 0x98, 0x99, 0x2f, 0x7b, 0x27, 0xc5, 0xd9, 0xa1 }}

class NS_NO_VTABLE nsIContentPrefCallback2 : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREFCALLBACK2_IID)

  /* void handleResult (in nsIContentPref pref); */
  NS_IMETHOD HandleResult(nsIContentPref *pref) = 0;

  /* void handleError (in nsresult error); */
  NS_IMETHOD HandleError(nsresult error) = 0;

  /* void handleCompletion (in unsigned short reason); */
  NS_IMETHOD HandleCompletion(uint16_t reason) = 0;

  enum {
    COMPLETE_OK = 0U,
    COMPLETE_ERROR = 1U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPrefCallback2, NS_ICONTENTPREFCALLBACK2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREFCALLBACK2 \
  NS_IMETHOD HandleResult(nsIContentPref *pref); \
  NS_IMETHOD HandleError(nsresult error); \
  NS_IMETHOD HandleCompletion(uint16_t reason); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREFCALLBACK2(_to) \
  NS_IMETHOD HandleResult(nsIContentPref *pref) { return _to HandleResult(pref); } \
  NS_IMETHOD HandleError(nsresult error) { return _to HandleError(error); } \
  NS_IMETHOD HandleCompletion(uint16_t reason) { return _to HandleCompletion(reason); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREFCALLBACK2(_to) \
  NS_IMETHOD HandleResult(nsIContentPref *pref) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleResult(pref); } \
  NS_IMETHOD HandleError(nsresult error) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleError(error); } \
  NS_IMETHOD HandleCompletion(uint16_t reason) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleCompletion(reason); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPrefCallback2 : public nsIContentPrefCallback2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPREFCALLBACK2

  nsContentPrefCallback2();

private:
  ~nsContentPrefCallback2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPrefCallback2, nsIContentPrefCallback2)

nsContentPrefCallback2::nsContentPrefCallback2()
{
  /* member initializers and constructor code */
}

nsContentPrefCallback2::~nsContentPrefCallback2()
{
  /* destructor code */
}

/* void handleResult (in nsIContentPref pref); */
NS_IMETHODIMP nsContentPrefCallback2::HandleResult(nsIContentPref *pref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleError (in nsresult error); */
NS_IMETHODIMP nsContentPrefCallback2::HandleError(nsresult error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleCompletion (in unsigned short reason); */
NS_IMETHODIMP nsContentPrefCallback2::HandleCompletion(uint16_t reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentPref */
#define NS_ICONTENTPREF_IID_STR "9f24948d-24b5-4b1b-b554-7dbd58c1d792"

#define NS_ICONTENTPREF_IID \
  {0x9f24948d, 0x24b5, 0x4b1b, \
    { 0xb5, 0x54, 0x7d, 0xbd, 0x58, 0xc1, 0xd7, 0x92 }}

class NS_NO_VTABLE nsIContentPref : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPREF_IID)

  /* readonly attribute AString domain; */
  NS_IMETHOD GetDomain(nsAString & aDomain) = 0;

  /* readonly attribute AString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute nsIVariant value; */
  NS_IMETHOD GetValue(nsIVariant * *aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPref, NS_ICONTENTPREF_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPREF \
  NS_IMETHOD GetDomain(nsAString & aDomain); \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetValue(nsIVariant * *aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPREF(_to) \
  NS_IMETHOD GetDomain(nsAString & aDomain) { return _to GetDomain(aDomain); } \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetValue(nsIVariant * *aValue) { return _to GetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPREF(_to) \
  NS_IMETHOD GetDomain(nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetValue(nsIVariant * *aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPref : public nsIContentPref
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPREF

  nsContentPref();

private:
  ~nsContentPref();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPref, nsIContentPref)

nsContentPref::nsContentPref()
{
  /* member initializers and constructor code */
}

nsContentPref::~nsContentPref()
{
  /* destructor code */
}

/* readonly attribute AString domain; */
NS_IMETHODIMP nsContentPref::GetDomain(nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString name; */
NS_IMETHODIMP nsContentPref::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant value; */
NS_IMETHODIMP nsContentPref::GetValue(nsIVariant * *aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentPrefService2_h__ */
