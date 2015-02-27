/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICookieManager.idl
 */

#ifndef __gen_nsICookieManager_h__
#define __gen_nsICookieManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsICookieManager */
#define NS_ICOOKIEMANAGER_IID_STR "aaab6710-0f2c-11d5-a53b-0010a401eb10"

#define NS_ICOOKIEMANAGER_IID \
  {0xaaab6710, 0x0f2c, 0x11d5, \
    { 0xa5, 0x3b, 0x00, 0x10, 0xa4, 0x01, 0xeb, 0x10 }}

class NS_NO_VTABLE nsICookieManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOOKIEMANAGER_IID)

  /* void removeAll (); */
  NS_IMETHOD RemoveAll(void) = 0;

  /* readonly attribute nsISimpleEnumerator enumerator; */
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) = 0;

  /* void remove (in AUTF8String aHost, in ACString aName, in AUTF8String aPath, in boolean aBlocked); */
  NS_IMETHOD Remove(const nsACString & aHost, const nsACString & aName, const nsACString & aPath, bool aBlocked) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICookieManager, NS_ICOOKIEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOOKIEMANAGER \
  NS_IMETHOD RemoveAll(void); \
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator); \
  NS_IMETHOD Remove(const nsACString & aHost, const nsACString & aName, const nsACString & aPath, bool aBlocked); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOOKIEMANAGER(_to) \
  NS_IMETHOD RemoveAll(void) { return _to RemoveAll(); } \
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) { return _to GetEnumerator(aEnumerator); } \
  NS_IMETHOD Remove(const nsACString & aHost, const nsACString & aName, const nsACString & aPath, bool aBlocked) { return _to Remove(aHost, aName, aPath, aBlocked); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOOKIEMANAGER(_to) \
  NS_IMETHOD RemoveAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveAll(); } \
  NS_IMETHOD GetEnumerator(nsISimpleEnumerator * *aEnumerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnumerator(aEnumerator); } \
  NS_IMETHOD Remove(const nsACString & aHost, const nsACString & aName, const nsACString & aPath, bool aBlocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(aHost, aName, aPath, aBlocked); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCookieManager : public nsICookieManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOOKIEMANAGER

  nsCookieManager();

private:
  ~nsCookieManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCookieManager, nsICookieManager)

nsCookieManager::nsCookieManager()
{
  /* member initializers and constructor code */
}

nsCookieManager::~nsCookieManager()
{
  /* destructor code */
}

/* void removeAll (); */
NS_IMETHODIMP nsCookieManager::RemoveAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator enumerator; */
NS_IMETHODIMP nsCookieManager::GetEnumerator(nsISimpleEnumerator * *aEnumerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in AUTF8String aHost, in ACString aName, in AUTF8String aPath, in boolean aBlocked); */
NS_IMETHODIMP nsCookieManager::Remove(const nsACString & aHost, const nsACString & aName, const nsACString & aPath, bool aBlocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICookieManager_h__ */
