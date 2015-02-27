/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISHistoryInternal.idl
 */

#ifndef __gen_nsISHistoryInternal_h__
#define __gen_nsISHistoryInternal_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIBFCacheEntry; /* forward declaration */

class nsISHEntry; /* forward declaration */

class nsISHistoryListener; /* forward declaration */

class nsISHTransaction; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIURI; /* forward declaration */

#define NS_SHISTORY_INTERNAL_CID \
{ 0x9c47c121, 0x1c6e, 0x4d8f, \
  { 0xb9, 0x04, 0x3a, 0xc9, 0x68, 0x11, 0x6e, 0x88 } }
#define NS_SHISTORY_INTERNAL_CONTRACTID "@mozilla.org/browser/shistory-internal;1"
#include "nsTArrayForwardDeclare.h"

/* starting interface:    nsISHistoryInternal */
#define NS_ISHISTORYINTERNAL_IID_STR "f9348014-0239-11e2-b029-3d38e719eb2d"

#define NS_ISHISTORYINTERNAL_IID \
  {0xf9348014, 0x0239, 0x11e2, \
    { 0xb0, 0x29, 0x3d, 0x38, 0xe7, 0x19, 0xeb, 0x2d }}

class NS_NO_VTABLE nsISHistoryInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISHISTORYINTERNAL_IID)

  /* void addEntry (in nsISHEntry aEntry, in boolean aPersist); */
  NS_IMETHOD AddEntry(nsISHEntry *aEntry, bool aPersist) = 0;

  /* readonly attribute nsISHTransaction rootTransaction; */
  NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction) = 0;

  /* attribute nsIDocShell rootDocShell; */
  NS_IMETHOD GetRootDocShell(nsIDocShell * *aRootDocShell) = 0;
  NS_IMETHOD SetRootDocShell(nsIDocShell *aRootDocShell) = 0;

  /* void updateIndex (); */
  NS_IMETHOD UpdateIndex(void) = 0;

  /* void replaceEntry (in long aIndex, in nsISHEntry aReplaceEntry); */
  NS_IMETHOD ReplaceEntry(int32_t aIndex, nsISHEntry *aReplaceEntry) = 0;

  /* boolean notifyOnHistoryReload (in nsIURI aReloadURI, in unsigned long aReloadFlags); */
  NS_IMETHOD NotifyOnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval) = 0;

  /* void evictOutOfRangeContentViewers (in long aIndex); */
  NS_IMETHOD EvictOutOfRangeContentViewers(int32_t aIndex) = 0;

  /* void evictExpiredContentViewerForEntry (in nsIBFCacheEntry aEntry); */
  NS_IMETHOD EvictExpiredContentViewerForEntry(nsIBFCacheEntry *aEntry) = 0;

  /* void evictAllContentViewers (); */
  NS_IMETHOD EvictAllContentViewers(void) = 0;

  /* [noscript,notxpcom] void RemoveEntries (in nsDocshellIDArray aIDs, in long aStartIndex); */
  NS_IMETHOD_(void) RemoveEntries(nsTArray<uint64_t> & aIDs, int32_t aStartIndex) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISHistoryInternal, NS_ISHISTORYINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISHISTORYINTERNAL \
  NS_IMETHOD AddEntry(nsISHEntry *aEntry, bool aPersist); \
  NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction); \
  NS_IMETHOD GetRootDocShell(nsIDocShell * *aRootDocShell); \
  NS_IMETHOD SetRootDocShell(nsIDocShell *aRootDocShell); \
  NS_IMETHOD UpdateIndex(void); \
  NS_IMETHOD ReplaceEntry(int32_t aIndex, nsISHEntry *aReplaceEntry); \
  NS_IMETHOD NotifyOnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval); \
  NS_IMETHOD EvictOutOfRangeContentViewers(int32_t aIndex); \
  NS_IMETHOD EvictExpiredContentViewerForEntry(nsIBFCacheEntry *aEntry); \
  NS_IMETHOD EvictAllContentViewers(void); \
  NS_IMETHOD_(void) RemoveEntries(nsTArray<uint64_t> & aIDs, int32_t aStartIndex); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISHISTORYINTERNAL(_to) \
  NS_IMETHOD AddEntry(nsISHEntry *aEntry, bool aPersist) { return _to AddEntry(aEntry, aPersist); } \
  NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction) { return _to GetRootTransaction(aRootTransaction); } \
  NS_IMETHOD GetRootDocShell(nsIDocShell * *aRootDocShell) { return _to GetRootDocShell(aRootDocShell); } \
  NS_IMETHOD SetRootDocShell(nsIDocShell *aRootDocShell) { return _to SetRootDocShell(aRootDocShell); } \
  NS_IMETHOD UpdateIndex(void) { return _to UpdateIndex(); } \
  NS_IMETHOD ReplaceEntry(int32_t aIndex, nsISHEntry *aReplaceEntry) { return _to ReplaceEntry(aIndex, aReplaceEntry); } \
  NS_IMETHOD NotifyOnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval) { return _to NotifyOnHistoryReload(aReloadURI, aReloadFlags, _retval); } \
  NS_IMETHOD EvictOutOfRangeContentViewers(int32_t aIndex) { return _to EvictOutOfRangeContentViewers(aIndex); } \
  NS_IMETHOD EvictExpiredContentViewerForEntry(nsIBFCacheEntry *aEntry) { return _to EvictExpiredContentViewerForEntry(aEntry); } \
  NS_IMETHOD EvictAllContentViewers(void) { return _to EvictAllContentViewers(); } \
  NS_IMETHOD_(void) RemoveEntries(nsTArray<uint64_t> & aIDs, int32_t aStartIndex) { return _to RemoveEntries(aIDs, aStartIndex); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISHISTORYINTERNAL(_to) \
  NS_IMETHOD AddEntry(nsISHEntry *aEntry, bool aPersist) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEntry(aEntry, aPersist); } \
  NS_IMETHOD GetRootTransaction(nsISHTransaction * *aRootTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootTransaction(aRootTransaction); } \
  NS_IMETHOD GetRootDocShell(nsIDocShell * *aRootDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootDocShell(aRootDocShell); } \
  NS_IMETHOD SetRootDocShell(nsIDocShell *aRootDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRootDocShell(aRootDocShell); } \
  NS_IMETHOD UpdateIndex(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateIndex(); } \
  NS_IMETHOD ReplaceEntry(int32_t aIndex, nsISHEntry *aReplaceEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceEntry(aIndex, aReplaceEntry); } \
  NS_IMETHOD NotifyOnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyOnHistoryReload(aReloadURI, aReloadFlags, _retval); } \
  NS_IMETHOD EvictOutOfRangeContentViewers(int32_t aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictOutOfRangeContentViewers(aIndex); } \
  NS_IMETHOD EvictExpiredContentViewerForEntry(nsIBFCacheEntry *aEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictExpiredContentViewerForEntry(aEntry); } \
  NS_IMETHOD EvictAllContentViewers(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EvictAllContentViewers(); } \
  NS_IMETHOD_(void) RemoveEntries(nsTArray<uint64_t> & aIDs, int32_t aStartIndex); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSHistoryInternal : public nsISHistoryInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISHISTORYINTERNAL

  nsSHistoryInternal();

private:
  ~nsSHistoryInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSHistoryInternal, nsISHistoryInternal)

nsSHistoryInternal::nsSHistoryInternal()
{
  /* member initializers and constructor code */
}

nsSHistoryInternal::~nsSHistoryInternal()
{
  /* destructor code */
}

/* void addEntry (in nsISHEntry aEntry, in boolean aPersist); */
NS_IMETHODIMP nsSHistoryInternal::AddEntry(nsISHEntry *aEntry, bool aPersist)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISHTransaction rootTransaction; */
NS_IMETHODIMP nsSHistoryInternal::GetRootTransaction(nsISHTransaction * *aRootTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDocShell rootDocShell; */
NS_IMETHODIMP nsSHistoryInternal::GetRootDocShell(nsIDocShell * *aRootDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSHistoryInternal::SetRootDocShell(nsIDocShell *aRootDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateIndex (); */
NS_IMETHODIMP nsSHistoryInternal::UpdateIndex()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceEntry (in long aIndex, in nsISHEntry aReplaceEntry); */
NS_IMETHODIMP nsSHistoryInternal::ReplaceEntry(int32_t aIndex, nsISHEntry *aReplaceEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean notifyOnHistoryReload (in nsIURI aReloadURI, in unsigned long aReloadFlags); */
NS_IMETHODIMP nsSHistoryInternal::NotifyOnHistoryReload(nsIURI *aReloadURI, uint32_t aReloadFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictOutOfRangeContentViewers (in long aIndex); */
NS_IMETHODIMP nsSHistoryInternal::EvictOutOfRangeContentViewers(int32_t aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictExpiredContentViewerForEntry (in nsIBFCacheEntry aEntry); */
NS_IMETHODIMP nsSHistoryInternal::EvictExpiredContentViewerForEntry(nsIBFCacheEntry *aEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void evictAllContentViewers (); */
NS_IMETHODIMP nsSHistoryInternal::EvictAllContentViewers()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void RemoveEntries (in nsDocshellIDArray aIDs, in long aStartIndex); */
NS_IMETHODIMP_(void) nsSHistoryInternal::RemoveEntries(nsTArray<uint64_t> & aIDs, int32_t aStartIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISHistoryInternal_h__ */
