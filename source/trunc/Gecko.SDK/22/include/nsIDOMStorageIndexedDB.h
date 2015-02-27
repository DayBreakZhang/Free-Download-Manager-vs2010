/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/storage/nsIDOMStorageIndexedDB.idl
 */

#ifndef __gen_nsIDOMStorageIndexedDB_h__
#define __gen_nsIDOMStorageIndexedDB_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMStorageIndexedDB */
#define NS_IDOMSTORAGEINDEXEDDB_IID_STR "f4deeef5-32d3-4048-bb56-883330fd8f35"

#define NS_IDOMSTORAGEINDEXEDDB_IID \
  {0xf4deeef5, 0x32d3, 0x4048, \
    { 0xbb, 0x56, 0x88, 0x33, 0x30, 0xfd, 0x8f, 0x35 }}

class NS_NO_VTABLE nsIDOMStorageIndexedDB : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEINDEXEDDB_IID)

  /* readonly attribute nsISupports indexedDB; */
  NS_IMETHOD GetIndexedDB(nsISupports * *aIndexedDB) = 0;

  /* readonly attribute nsISupports mozIndexedDB; */
  NS_IMETHOD GetMozIndexedDB(nsISupports * *aMozIndexedDB) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageIndexedDB, NS_IDOMSTORAGEINDEXEDDB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEINDEXEDDB \
  NS_IMETHOD GetIndexedDB(nsISupports * *aIndexedDB); \
  NS_IMETHOD GetMozIndexedDB(nsISupports * *aMozIndexedDB); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEINDEXEDDB(_to) \
  NS_IMETHOD GetIndexedDB(nsISupports * *aIndexedDB) { return _to GetIndexedDB(aIndexedDB); } \
  NS_IMETHOD GetMozIndexedDB(nsISupports * *aMozIndexedDB) { return _to GetMozIndexedDB(aMozIndexedDB); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEINDEXEDDB(_to) \
  NS_IMETHOD GetIndexedDB(nsISupports * *aIndexedDB) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexedDB(aIndexedDB); } \
  NS_IMETHOD GetMozIndexedDB(nsISupports * *aMozIndexedDB) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozIndexedDB(aMozIndexedDB); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMStorageIndexedDB : public nsIDOMStorageIndexedDB
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSTORAGEINDEXEDDB

  nsDOMStorageIndexedDB();

private:
  ~nsDOMStorageIndexedDB();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMStorageIndexedDB, nsIDOMStorageIndexedDB)

nsDOMStorageIndexedDB::nsDOMStorageIndexedDB()
{
  /* member initializers and constructor code */
}

nsDOMStorageIndexedDB::~nsDOMStorageIndexedDB()
{
  /* destructor code */
}

/* readonly attribute nsISupports indexedDB; */
NS_IMETHODIMP nsDOMStorageIndexedDB::GetIndexedDB(nsISupports * *aIndexedDB)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports mozIndexedDB; */
NS_IMETHODIMP nsDOMStorageIndexedDB::GetMozIndexedDB(nsISupports * *aMozIndexedDB)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageIndexedDB_h__ */
