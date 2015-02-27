/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRefreshURI.idl
 */

#ifndef __gen_nsIRefreshURI_h__
#define __gen_nsIRefreshURI_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIRefreshURI */
#define NS_IREFRESHURI_IID_STR "a5e61a3c-51bd-45be-ac0c-e87b71860656"

#define NS_IREFRESHURI_IID \
  {0xa5e61a3c, 0x51bd, 0x45be, \
    { 0xac, 0x0c, 0xe8, 0x7b, 0x71, 0x86, 0x06, 0x56 }}

class NS_NO_VTABLE nsIRefreshURI : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IREFRESHURI_IID)

  /* void refreshURI (in nsIURI aURI, in long aMillis, in boolean aRepeat, in boolean aMetaRefresh); */
  NS_IMETHOD RefreshURI(nsIURI *aURI, int32_t aMillis, bool aRepeat, bool aMetaRefresh) = 0;

  /* void forceRefreshURI (in nsIURI aURI, in long aMillis, in boolean aMetaRefresh); */
  NS_IMETHOD ForceRefreshURI(nsIURI *aURI, int32_t aMillis, bool aMetaRefresh) = 0;

  /* void setupRefreshURI (in nsIChannel aChannel); */
  NS_IMETHOD SetupRefreshURI(nsIChannel *aChannel) = 0;

  /* void setupRefreshURIFromHeader (in nsIURI aBaseURI, in nsIPrincipal principal, in ACString aHeader); */
  NS_IMETHOD SetupRefreshURIFromHeader(nsIURI *aBaseURI, nsIPrincipal *principal, const nsACString & aHeader) = 0;

  /* void cancelRefreshURITimers (); */
  NS_IMETHOD CancelRefreshURITimers(void) = 0;

  /* readonly attribute boolean refreshPending; */
  NS_IMETHOD GetRefreshPending(bool *aRefreshPending) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRefreshURI, NS_IREFRESHURI_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIREFRESHURI \
  NS_IMETHOD RefreshURI(nsIURI *aURI, int32_t aMillis, bool aRepeat, bool aMetaRefresh); \
  NS_IMETHOD ForceRefreshURI(nsIURI *aURI, int32_t aMillis, bool aMetaRefresh); \
  NS_IMETHOD SetupRefreshURI(nsIChannel *aChannel); \
  NS_IMETHOD SetupRefreshURIFromHeader(nsIURI *aBaseURI, nsIPrincipal *principal, const nsACString & aHeader); \
  NS_IMETHOD CancelRefreshURITimers(void); \
  NS_IMETHOD GetRefreshPending(bool *aRefreshPending); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIREFRESHURI(_to) \
  NS_IMETHOD RefreshURI(nsIURI *aURI, int32_t aMillis, bool aRepeat, bool aMetaRefresh) { return _to RefreshURI(aURI, aMillis, aRepeat, aMetaRefresh); } \
  NS_IMETHOD ForceRefreshURI(nsIURI *aURI, int32_t aMillis, bool aMetaRefresh) { return _to ForceRefreshURI(aURI, aMillis, aMetaRefresh); } \
  NS_IMETHOD SetupRefreshURI(nsIChannel *aChannel) { return _to SetupRefreshURI(aChannel); } \
  NS_IMETHOD SetupRefreshURIFromHeader(nsIURI *aBaseURI, nsIPrincipal *principal, const nsACString & aHeader) { return _to SetupRefreshURIFromHeader(aBaseURI, principal, aHeader); } \
  NS_IMETHOD CancelRefreshURITimers(void) { return _to CancelRefreshURITimers(); } \
  NS_IMETHOD GetRefreshPending(bool *aRefreshPending) { return _to GetRefreshPending(aRefreshPending); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIREFRESHURI(_to) \
  NS_IMETHOD RefreshURI(nsIURI *aURI, int32_t aMillis, bool aRepeat, bool aMetaRefresh) { return !_to ? NS_ERROR_NULL_POINTER : _to->RefreshURI(aURI, aMillis, aRepeat, aMetaRefresh); } \
  NS_IMETHOD ForceRefreshURI(nsIURI *aURI, int32_t aMillis, bool aMetaRefresh) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceRefreshURI(aURI, aMillis, aMetaRefresh); } \
  NS_IMETHOD SetupRefreshURI(nsIChannel *aChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetupRefreshURI(aChannel); } \
  NS_IMETHOD SetupRefreshURIFromHeader(nsIURI *aBaseURI, nsIPrincipal *principal, const nsACString & aHeader) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetupRefreshURIFromHeader(aBaseURI, principal, aHeader); } \
  NS_IMETHOD CancelRefreshURITimers(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelRefreshURITimers(); } \
  NS_IMETHOD GetRefreshPending(bool *aRefreshPending) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRefreshPending(aRefreshPending); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRefreshURI : public nsIRefreshURI
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIREFRESHURI

  nsRefreshURI();

private:
  ~nsRefreshURI();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRefreshURI, nsIRefreshURI)

nsRefreshURI::nsRefreshURI()
{
  /* member initializers and constructor code */
}

nsRefreshURI::~nsRefreshURI()
{
  /* destructor code */
}

/* void refreshURI (in nsIURI aURI, in long aMillis, in boolean aRepeat, in boolean aMetaRefresh); */
NS_IMETHODIMP nsRefreshURI::RefreshURI(nsIURI *aURI, int32_t aMillis, bool aRepeat, bool aMetaRefresh)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceRefreshURI (in nsIURI aURI, in long aMillis, in boolean aMetaRefresh); */
NS_IMETHODIMP nsRefreshURI::ForceRefreshURI(nsIURI *aURI, int32_t aMillis, bool aMetaRefresh)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setupRefreshURI (in nsIChannel aChannel); */
NS_IMETHODIMP nsRefreshURI::SetupRefreshURI(nsIChannel *aChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setupRefreshURIFromHeader (in nsIURI aBaseURI, in nsIPrincipal principal, in ACString aHeader); */
NS_IMETHODIMP nsRefreshURI::SetupRefreshURIFromHeader(nsIURI *aBaseURI, nsIPrincipal *principal, const nsACString & aHeader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelRefreshURITimers (); */
NS_IMETHODIMP nsRefreshURI::CancelRefreshURITimers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean refreshPending; */
NS_IMETHODIMP nsRefreshURI::GetRefreshPending(bool *aRefreshPending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRefreshURI_h__ */
