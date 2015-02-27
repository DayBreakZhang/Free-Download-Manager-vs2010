/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBFCacheEntry.idl
 */

#ifndef __gen_nsIBFCacheEntry_h__
#define __gen_nsIBFCacheEntry_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBFCacheEntry */
#define NS_IBFCACHEENTRY_IID_STR "a576060e-c7df-4d81-aa8c-5b52bd6ad25d"

#define NS_IBFCACHEENTRY_IID \
  {0xa576060e, 0xc7df, 0x4d81, \
    { 0xaa, 0x8c, 0x5b, 0x52, 0xbd, 0x6a, 0xd2, 0x5d }}

class NS_NO_VTABLE nsIBFCacheEntry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBFCACHEENTRY_IID)

  /* void RemoveFromBFCacheSync (); */
  NS_IMETHOD RemoveFromBFCacheSync(void) = 0;

  /* void RemoveFromBFCacheAsync (); */
  NS_IMETHOD RemoveFromBFCacheAsync(void) = 0;

  /* readonly attribute unsigned long long ID; */
  NS_IMETHOD GetID(uint64_t *aID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBFCacheEntry, NS_IBFCACHEENTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBFCACHEENTRY \
  NS_IMETHOD RemoveFromBFCacheSync(void); \
  NS_IMETHOD RemoveFromBFCacheAsync(void); \
  NS_IMETHOD GetID(uint64_t *aID); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBFCACHEENTRY(_to) \
  NS_IMETHOD RemoveFromBFCacheSync(void) { return _to RemoveFromBFCacheSync(); } \
  NS_IMETHOD RemoveFromBFCacheAsync(void) { return _to RemoveFromBFCacheAsync(); } \
  NS_IMETHOD GetID(uint64_t *aID) { return _to GetID(aID); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBFCACHEENTRY(_to) \
  NS_IMETHOD RemoveFromBFCacheSync(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFromBFCacheSync(); } \
  NS_IMETHOD RemoveFromBFCacheAsync(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveFromBFCacheAsync(); } \
  NS_IMETHOD GetID(uint64_t *aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetID(aID); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBFCacheEntry : public nsIBFCacheEntry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBFCACHEENTRY

  nsBFCacheEntry();

private:
  ~nsBFCacheEntry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBFCacheEntry, nsIBFCacheEntry)

nsBFCacheEntry::nsBFCacheEntry()
{
  /* member initializers and constructor code */
}

nsBFCacheEntry::~nsBFCacheEntry()
{
  /* destructor code */
}

/* void RemoveFromBFCacheSync (); */
NS_IMETHODIMP nsBFCacheEntry::RemoveFromBFCacheSync()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveFromBFCacheAsync (); */
NS_IMETHODIMP nsBFCacheEntry::RemoveFromBFCacheAsync()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long ID; */
NS_IMETHODIMP nsBFCacheEntry::GetID(uint64_t *aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBFCacheEntry_h__ */
