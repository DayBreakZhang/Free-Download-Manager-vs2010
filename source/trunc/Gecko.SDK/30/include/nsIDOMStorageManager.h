/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMStorageManager.idl
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
#define NS_IDOMSTORAGEMANAGER_IID_STR "8096f9ea-fa61-4960-b5d7-fb30ac42c8d8"

#define NS_IDOMSTORAGEMANAGER_IID \
  {0x8096f9ea, 0xfa61, 0x4960, \
    { 0xb5, 0xd7, 0xfb, 0x30, 0xac, 0x42, 0xc8, 0xd8 }}

class NS_NO_VTABLE nsIDOMStorageManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEMANAGER_IID)

  /* void precacheStorage (in nsIPrincipal aPrincipal); */
  NS_IMETHOD PrecacheStorage(nsIPrincipal *aPrincipal) = 0;

  /* nsIDOMStorage createStorage (in nsIPrincipal aPrincipal, in DOMString aDocumentURI, [optional] in bool aPrivate); */
  NS_IMETHOD CreateStorage(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval) = 0;

  /* nsIDOMStorage getStorage (in nsIPrincipal aPrincipal, [optional] in bool aPrivate); */
  NS_IMETHOD GetStorage(nsIPrincipal *aPrincipal, bool aPrivate, nsIDOMStorage * *_retval) = 0;

  /* void cloneStorage (in nsIDOMStorage aStorageToCloneFrom); */
  NS_IMETHOD CloneStorage(nsIDOMStorage *aStorageToCloneFrom) = 0;

  /* bool checkStorage (in nsIPrincipal aPrincipal, in nsIDOMStorage aStorage); */
  NS_IMETHOD CheckStorage(nsIPrincipal *aPrincipal, nsIDOMStorage *aStorage, bool *_retval) = 0;

  /* nsIDOMStorage getLocalStorageForPrincipal (in nsIPrincipal aPrincipal, in DOMString aDocumentURI, [optional] in bool aPrivate); */
  NS_IMETHOD GetLocalStorageForPrincipal(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageManager, NS_IDOMSTORAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEMANAGER \
  NS_IMETHOD PrecacheStorage(nsIPrincipal *aPrincipal); \
  NS_IMETHOD CreateStorage(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval); \
  NS_IMETHOD GetStorage(nsIPrincipal *aPrincipal, bool aPrivate, nsIDOMStorage * *_retval); \
  NS_IMETHOD CloneStorage(nsIDOMStorage *aStorageToCloneFrom); \
  NS_IMETHOD CheckStorage(nsIPrincipal *aPrincipal, nsIDOMStorage *aStorage, bool *_retval); \
  NS_IMETHOD GetLocalStorageForPrincipal(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEMANAGER(_to) \
  NS_IMETHOD PrecacheStorage(nsIPrincipal *aPrincipal) { return _to PrecacheStorage(aPrincipal); } \
  NS_IMETHOD CreateStorage(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval) { return _to CreateStorage(aPrincipal, aDocumentURI, aPrivate, _retval); } \
  NS_IMETHOD GetStorage(nsIPrincipal *aPrincipal, bool aPrivate, nsIDOMStorage * *_retval) { return _to GetStorage(aPrincipal, aPrivate, _retval); } \
  NS_IMETHOD CloneStorage(nsIDOMStorage *aStorageToCloneFrom) { return _to CloneStorage(aStorageToCloneFrom); } \
  NS_IMETHOD CheckStorage(nsIPrincipal *aPrincipal, nsIDOMStorage *aStorage, bool *_retval) { return _to CheckStorage(aPrincipal, aStorage, _retval); } \
  NS_IMETHOD GetLocalStorageForPrincipal(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval) { return _to GetLocalStorageForPrincipal(aPrincipal, aDocumentURI, aPrivate, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEMANAGER(_to) \
  NS_IMETHOD PrecacheStorage(nsIPrincipal *aPrincipal) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrecacheStorage(aPrincipal); } \
  NS_IMETHOD CreateStorage(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateStorage(aPrincipal, aDocumentURI, aPrivate, _retval); } \
  NS_IMETHOD GetStorage(nsIPrincipal *aPrincipal, bool aPrivate, nsIDOMStorage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorage(aPrincipal, aPrivate, _retval); } \
  NS_IMETHOD CloneStorage(nsIDOMStorage *aStorageToCloneFrom) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloneStorage(aStorageToCloneFrom); } \
  NS_IMETHOD CheckStorage(nsIPrincipal *aPrincipal, nsIDOMStorage *aStorage, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckStorage(aPrincipal, aStorage, _retval); } \
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

/* void precacheStorage (in nsIPrincipal aPrincipal); */
NS_IMETHODIMP nsDOMStorageManager::PrecacheStorage(nsIPrincipal *aPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMStorage createStorage (in nsIPrincipal aPrincipal, in DOMString aDocumentURI, [optional] in bool aPrivate); */
NS_IMETHODIMP nsDOMStorageManager::CreateStorage(nsIPrincipal *aPrincipal, const nsAString & aDocumentURI, bool aPrivate, nsIDOMStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMStorage getStorage (in nsIPrincipal aPrincipal, [optional] in bool aPrivate); */
NS_IMETHODIMP nsDOMStorageManager::GetStorage(nsIPrincipal *aPrincipal, bool aPrivate, nsIDOMStorage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cloneStorage (in nsIDOMStorage aStorageToCloneFrom); */
NS_IMETHODIMP nsDOMStorageManager::CloneStorage(nsIDOMStorage *aStorageToCloneFrom)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool checkStorage (in nsIPrincipal aPrincipal, in nsIDOMStorage aStorage); */
NS_IMETHODIMP nsDOMStorageManager::CheckStorage(nsIPrincipal *aPrincipal, nsIDOMStorage *aStorage, bool *_retval)
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
