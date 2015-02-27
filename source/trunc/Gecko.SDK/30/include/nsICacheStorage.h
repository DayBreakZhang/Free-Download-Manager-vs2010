/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICacheStorage.idl
 */

#ifndef __gen_nsICacheStorage_h__
#define __gen_nsICacheStorage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsICacheEntryOpenCallback; /* forward declaration */

class nsICacheEntryDoomCallback; /* forward declaration */

class nsICacheStorageVisitor; /* forward declaration */


/* starting interface:    nsICacheStorage */
#define NS_ICACHESTORAGE_IID_STR "d983ba0c-433f-4017-abc1-93af737c82e4"

#define NS_ICACHESTORAGE_IID \
  {0xd983ba0c, 0x433f, 0x4017, \
    { 0xab, 0xc1, 0x93, 0xaf, 0x73, 0x7c, 0x82, 0xe4 }}

class NS_NO_VTABLE nsICacheStorage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHESTORAGE_IID)

  enum {
    OPEN_NORMALLY = 0U,
    OPEN_TRUNCATE = 1U,
    OPEN_READONLY = 2U,
    OPEN_PRIORITY = 4U,
    OPEN_BYPASS_IF_BUSY = 8U,
    CHECK_MULTITHREADED = 16U
  };

  /* void asyncOpenURI (in nsIURI aURI, in ACString aIdExtension, in uint32_t aFlags, in nsICacheEntryOpenCallback aCallback); */
  NS_IMETHOD AsyncOpenURI(nsIURI *aURI, const nsACString & aIdExtension, uint32_t aFlags, nsICacheEntryOpenCallback *aCallback) = 0;

  /* void asyncDoomURI (in nsIURI aURI, in ACString aIdExtension, in nsICacheEntryDoomCallback aCallback); */
  NS_IMETHOD AsyncDoomURI(nsIURI *aURI, const nsACString & aIdExtension, nsICacheEntryDoomCallback *aCallback) = 0;

  /* void asyncEvictStorage (in nsICacheEntryDoomCallback aCallback); */
  NS_IMETHOD AsyncEvictStorage(nsICacheEntryDoomCallback *aCallback) = 0;

  /* void asyncVisitStorage (in nsICacheStorageVisitor aVisitor, in boolean aVisitEntries); */
  NS_IMETHOD AsyncVisitStorage(nsICacheStorageVisitor *aVisitor, bool aVisitEntries) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheStorage, NS_ICACHESTORAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHESTORAGE \
  NS_IMETHOD AsyncOpenURI(nsIURI *aURI, const nsACString & aIdExtension, uint32_t aFlags, nsICacheEntryOpenCallback *aCallback); \
  NS_IMETHOD AsyncDoomURI(nsIURI *aURI, const nsACString & aIdExtension, nsICacheEntryDoomCallback *aCallback); \
  NS_IMETHOD AsyncEvictStorage(nsICacheEntryDoomCallback *aCallback); \
  NS_IMETHOD AsyncVisitStorage(nsICacheStorageVisitor *aVisitor, bool aVisitEntries); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHESTORAGE(_to) \
  NS_IMETHOD AsyncOpenURI(nsIURI *aURI, const nsACString & aIdExtension, uint32_t aFlags, nsICacheEntryOpenCallback *aCallback) { return _to AsyncOpenURI(aURI, aIdExtension, aFlags, aCallback); } \
  NS_IMETHOD AsyncDoomURI(nsIURI *aURI, const nsACString & aIdExtension, nsICacheEntryDoomCallback *aCallback) { return _to AsyncDoomURI(aURI, aIdExtension, aCallback); } \
  NS_IMETHOD AsyncEvictStorage(nsICacheEntryDoomCallback *aCallback) { return _to AsyncEvictStorage(aCallback); } \
  NS_IMETHOD AsyncVisitStorage(nsICacheStorageVisitor *aVisitor, bool aVisitEntries) { return _to AsyncVisitStorage(aVisitor, aVisitEntries); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHESTORAGE(_to) \
  NS_IMETHOD AsyncOpenURI(nsIURI *aURI, const nsACString & aIdExtension, uint32_t aFlags, nsICacheEntryOpenCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncOpenURI(aURI, aIdExtension, aFlags, aCallback); } \
  NS_IMETHOD AsyncDoomURI(nsIURI *aURI, const nsACString & aIdExtension, nsICacheEntryDoomCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncDoomURI(aURI, aIdExtension, aCallback); } \
  NS_IMETHOD AsyncEvictStorage(nsICacheEntryDoomCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncEvictStorage(aCallback); } \
  NS_IMETHOD AsyncVisitStorage(nsICacheStorageVisitor *aVisitor, bool aVisitEntries) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncVisitStorage(aVisitor, aVisitEntries); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheStorage : public nsICacheStorage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHESTORAGE

  nsCacheStorage();

private:
  ~nsCacheStorage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheStorage, nsICacheStorage)

nsCacheStorage::nsCacheStorage()
{
  /* member initializers and constructor code */
}

nsCacheStorage::~nsCacheStorage()
{
  /* destructor code */
}

/* void asyncOpenURI (in nsIURI aURI, in ACString aIdExtension, in uint32_t aFlags, in nsICacheEntryOpenCallback aCallback); */
NS_IMETHODIMP nsCacheStorage::AsyncOpenURI(nsIURI *aURI, const nsACString & aIdExtension, uint32_t aFlags, nsICacheEntryOpenCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncDoomURI (in nsIURI aURI, in ACString aIdExtension, in nsICacheEntryDoomCallback aCallback); */
NS_IMETHODIMP nsCacheStorage::AsyncDoomURI(nsIURI *aURI, const nsACString & aIdExtension, nsICacheEntryDoomCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncEvictStorage (in nsICacheEntryDoomCallback aCallback); */
NS_IMETHODIMP nsCacheStorage::AsyncEvictStorage(nsICacheEntryDoomCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncVisitStorage (in nsICacheStorageVisitor aVisitor, in boolean aVisitEntries); */
NS_IMETHODIMP nsCacheStorage::AsyncVisitStorage(nsICacheStorageVisitor *aVisitor, bool aVisitEntries)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheStorage_h__ */
