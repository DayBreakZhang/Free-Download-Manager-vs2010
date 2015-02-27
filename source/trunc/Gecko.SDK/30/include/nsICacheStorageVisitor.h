/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICacheStorageVisitor.idl
 */

#ifndef __gen_nsICacheStorageVisitor_h__
#define __gen_nsICacheStorageVisitor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICacheEntry; /* forward declaration */


/* starting interface:    nsICacheStorageVisitor */
#define NS_ICACHESTORAGEVISITOR_IID_STR "692dda47-3b21-4d0d-853a-f4d27cc324d0"

#define NS_ICACHESTORAGEVISITOR_IID \
  {0x692dda47, 0x3b21, 0x4d0d, \
    { 0x85, 0x3a, 0xf4, 0xd2, 0x7c, 0xc3, 0x24, 0xd0 }}

class NS_NO_VTABLE nsICacheStorageVisitor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHESTORAGEVISITOR_IID)

  /* void onCacheStorageInfo (in uint32_t aEntryCount, in uint64_t aConsumption); */
  NS_IMETHOD OnCacheStorageInfo(uint32_t aEntryCount, uint64_t aConsumption) = 0;

  /* void onCacheEntryInfo (in nsICacheEntry aEntry); */
  NS_IMETHOD OnCacheEntryInfo(nsICacheEntry *aEntry) = 0;

  /* void onCacheEntryVisitCompleted (); */
  NS_IMETHOD OnCacheEntryVisitCompleted(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheStorageVisitor, NS_ICACHESTORAGEVISITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHESTORAGEVISITOR \
  NS_IMETHOD OnCacheStorageInfo(uint32_t aEntryCount, uint64_t aConsumption); \
  NS_IMETHOD OnCacheEntryInfo(nsICacheEntry *aEntry); \
  NS_IMETHOD OnCacheEntryVisitCompleted(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHESTORAGEVISITOR(_to) \
  NS_IMETHOD OnCacheStorageInfo(uint32_t aEntryCount, uint64_t aConsumption) { return _to OnCacheStorageInfo(aEntryCount, aConsumption); } \
  NS_IMETHOD OnCacheEntryInfo(nsICacheEntry *aEntry) { return _to OnCacheEntryInfo(aEntry); } \
  NS_IMETHOD OnCacheEntryVisitCompleted(void) { return _to OnCacheEntryVisitCompleted(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHESTORAGEVISITOR(_to) \
  NS_IMETHOD OnCacheStorageInfo(uint32_t aEntryCount, uint64_t aConsumption) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheStorageInfo(aEntryCount, aConsumption); } \
  NS_IMETHOD OnCacheEntryInfo(nsICacheEntry *aEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheEntryInfo(aEntry); } \
  NS_IMETHOD OnCacheEntryVisitCompleted(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheEntryVisitCompleted(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheStorageVisitor : public nsICacheStorageVisitor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHESTORAGEVISITOR

  nsCacheStorageVisitor();

private:
  ~nsCacheStorageVisitor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheStorageVisitor, nsICacheStorageVisitor)

nsCacheStorageVisitor::nsCacheStorageVisitor()
{
  /* member initializers and constructor code */
}

nsCacheStorageVisitor::~nsCacheStorageVisitor()
{
  /* destructor code */
}

/* void onCacheStorageInfo (in uint32_t aEntryCount, in uint64_t aConsumption); */
NS_IMETHODIMP nsCacheStorageVisitor::OnCacheStorageInfo(uint32_t aEntryCount, uint64_t aConsumption)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCacheEntryInfo (in nsICacheEntry aEntry); */
NS_IMETHODIMP nsCacheStorageVisitor::OnCacheEntryInfo(nsICacheEntry *aEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCacheEntryVisitCompleted (); */
NS_IMETHODIMP nsCacheStorageVisitor::OnCacheEntryVisitCompleted()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheStorageVisitor_h__ */
