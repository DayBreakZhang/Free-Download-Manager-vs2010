/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/storage/nsIDOMStorageWindow.idl
 */

#ifndef __gen_nsIDOMStorageWindow_h__
#define __gen_nsIDOMStorageWindow_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMStorageObsolete; /* forward declaration */

class nsIDOMStorage; /* forward declaration */

class nsIDOMStorageList; /* forward declaration */

class nsIIDBFactory; /* forward declaration */


/* starting interface:    nsIDOMStorageWindow */
#define NS_IDOMSTORAGEWINDOW_IID_STR "b6f6efd8-1bdc-43af-b8ef-6685d6260931"

#define NS_IDOMSTORAGEWINDOW_IID \
  {0xb6f6efd8, 0x1bdc, 0x43af, \
    { 0xb8, 0xef, 0x66, 0x85, 0xd6, 0x26, 0x09, 0x31 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMStorageWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEWINDOW_IID)

  /**
   * Session storage for the current browsing context.
   */
  /* readonly attribute nsIDOMStorage sessionStorage; */
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage **aSessionStorage) = 0;

  /**
   * Global storage, accessible by domain.
   */
  /* readonly attribute nsIDOMStorageList globalStorage; */
  NS_SCRIPTABLE NS_IMETHOD GetGlobalStorage(nsIDOMStorageList **aGlobalStorage) = 0;

  /**
   * Local storage for the current browsing context.
   */
  /* readonly attribute nsIDOMStorage localStorage; */
  NS_SCRIPTABLE NS_IMETHOD GetLocalStorage(nsIDOMStorage **aLocalStorage) = 0;

  /**
   * Indexed Databases for the current browsing context.
   * NOTE: mozIndexedDB should be removed post-2.0. Bug 623316.
   */
  /* [noscript] readonly attribute nsIIDBFactory mozIndexedDB; */
  NS_IMETHOD GetMozIndexedDB(nsIIDBFactory **aMozIndexedDB) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageWindow, NS_IDOMSTORAGEWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEWINDOW \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage **aSessionStorage); \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalStorage(nsIDOMStorageList **aGlobalStorage); \
  NS_SCRIPTABLE NS_IMETHOD GetLocalStorage(nsIDOMStorage **aLocalStorage); \
  NS_IMETHOD GetMozIndexedDB(nsIIDBFactory **aMozIndexedDB); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage **aSessionStorage) { return _to GetSessionStorage(aSessionStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalStorage(nsIDOMStorageList **aGlobalStorage) { return _to GetGlobalStorage(aGlobalStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalStorage(nsIDOMStorage **aLocalStorage) { return _to GetLocalStorage(aLocalStorage); } \
  NS_IMETHOD GetMozIndexedDB(nsIIDBFactory **aMozIndexedDB) { return _to GetMozIndexedDB(aMozIndexedDB); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSessionStorage(nsIDOMStorage **aSessionStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionStorage(aSessionStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetGlobalStorage(nsIDOMStorageList **aGlobalStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobalStorage(aGlobalStorage); } \
  NS_SCRIPTABLE NS_IMETHOD GetLocalStorage(nsIDOMStorage **aLocalStorage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalStorage(aLocalStorage); } \
  NS_IMETHOD GetMozIndexedDB(nsIIDBFactory **aMozIndexedDB) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozIndexedDB(aMozIndexedDB); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageWindow : public nsIDOMStorageWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGEWINDOW

  nsDOMStorageWindow();

private:
  ~nsDOMStorageWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageWindow, nsIDOMStorageWindow)

nsDOMStorageWindow::nsDOMStorageWindow()
{
  /* member initializers and constructor code */
}

nsDOMStorageWindow::~nsDOMStorageWindow()
{
  /* destructor code */
}

/* readonly attribute nsIDOMStorage sessionStorage; */
NS_IMETHODIMP nsDOMStorageWindow::GetSessionStorage(nsIDOMStorage **aSessionStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMStorageList globalStorage; */
NS_IMETHODIMP nsDOMStorageWindow::GetGlobalStorage(nsIDOMStorageList **aGlobalStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMStorage localStorage; */
NS_IMETHODIMP nsDOMStorageWindow::GetLocalStorage(nsIDOMStorage **aLocalStorage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIIDBFactory mozIndexedDB; */
NS_IMETHODIMP nsDOMStorageWindow::GetMozIndexedDB(nsIIDBFactory **aMozIndexedDB)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageWindow_h__ */
