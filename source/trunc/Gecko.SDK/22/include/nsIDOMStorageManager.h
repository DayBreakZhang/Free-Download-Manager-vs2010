/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/storage/nsIDOMStorageManager.idl
 */

#ifndef __gen_nsIDOMStorageManager_h__
#define __gen_nsIDOMStorageManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMStorage; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIDOMStorageManager */
#define NS_IDOMSTORAGEMANAGER_IID_STR "b16b207c-d883-43f5-a27e-548e7f2f5c20"

#define NS_IDOMSTORAGEMANAGER_IID \
  {0xb16b207c, 0xd883, 0x43f5, \
    { 0xa2, 0x7e, 0x54, 0x8e, 0x7f, 0x2f, 0x5c, 0x20 }}

class NS_NO_VTABLE nsIDOMStorageManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEMANAGER_IID)

  /* long getUsage (in AString aOwnerDomain); */
  NS_IMETHOD GetUsage(const nsAString & aOwnerDomain, int32_t *_retval) = 0;

  /* nsIDOMStorage getLocalStorageForPrincipal (in nsIPrincipal aPrincipal, in DOMString aDocumentURI, [optional] in bool aPrivate); */
  NS_IMETHOD GetLocalStorageForPrincipal(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageManager, NS_IDOMSTORAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEMANAGER \
  NS_IMETHOD GetUsage(const nsAString & aOwnerDomain, int32_t *_retval); \
  NS_IMETHOD GetLocalStorageForPrincipal(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEMANAGER(_to) \
  NS_IMETHOD GetUsage(const nsAString & aOwnerDomain, int32_t *_retval) { return _to GetUsage(aOwnerDomain, _retval); } \
  NS_IMETHOD GetLocalStorageForPrincipal(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval) { return _to GetLocalStorageForPrincipal(aPrincipal, aDocumentURI, aPrivate, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEMANAGER(_to) \
  NS_IMETHOD GetUsage(const nsAString & aOwnerDomain, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsage(aOwnerDomain, _retval); } \
  NS_IMETHOD GetLocalStorageForPrincipal(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalStorageForPrincipal(aPrincipal, aDocumentURI, aPrivate, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageManager : public nsIDOMStorageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGEMANAGER

  nsDOMStorageManager();

private:
  ~nsDOMStorageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageManager, nsIDOMStorageManager)

nsDOMStorageManager::nsDOMStorageManager()
{
  /* member initializers and constructor code */
}

nsDOMStorageManager::~nsDOMStorageManager()
{
  /* destructor code */
}

/* long getUsage (in AString aOwnerDomain); */
NS_IMETHODIMP nsDOMStorageManager::GetUsage(const nsAString & aOwnerDomain, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMStorage getLocalStorageForPrincipal (in nsIPrincipal aPrincipal, in DOMString aDocumentURI, [optional] in bool aPrivate); */
NS_IMETHODIMP nsDOMStorageManager::GetLocalStorageForPrincipal(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageManager_h__ */
