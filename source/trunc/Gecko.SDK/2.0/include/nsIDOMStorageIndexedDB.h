/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/storage/nsIDOMStorageIndexedDB.idl
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
class nsIIDBFactory; /* forward declaration */


/* starting interface:    nsIDOMStorageIndexedDB */
#define NS_IDOMSTORAGEINDEXEDDB_IID_STR "d20d48e4-0b94-40c7-a9c7-ba1d6ad44442"

#define NS_IDOMSTORAGEINDEXEDDB_IID \
  {0xd20d48e4, 0x0b94, 0x40c7, \
    { 0xa9, 0xc7, 0xba, 0x1d, 0x6a, 0xd4, 0x44, 0x42 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMStorageIndexedDB : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSTORAGEINDEXEDDB_IID)

  /**
   * Indexed Databases for the current browsing context.
   */
  /* readonly attribute nsIIDBFactory mozIndexedDB; */
  NS_SCRIPTABLE NS_IMETHOD GetMozIndexedDB(nsIIDBFactory **aMozIndexedDB) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMStorageIndexedDB, NS_IDOMSTORAGEINDEXEDDB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSTORAGEINDEXEDDB \
  NS_SCRIPTABLE NS_IMETHOD GetMozIndexedDB(nsIIDBFactory **aMozIndexedDB); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSTORAGEINDEXEDDB(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozIndexedDB(nsIIDBFactory **aMozIndexedDB) { return _to GetMozIndexedDB(aMozIndexedDB); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSTORAGEINDEXEDDB(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMozIndexedDB(nsIIDBFactory **aMozIndexedDB) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozIndexedDB(aMozIndexedDB); } 

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

/* readonly attribute nsIIDBFactory mozIndexedDB; */
NS_IMETHODIMP nsDOMStorageIndexedDB::GetMozIndexedDB(nsIIDBFactory **aMozIndexedDB)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMStorageIndexedDB_h__ */
