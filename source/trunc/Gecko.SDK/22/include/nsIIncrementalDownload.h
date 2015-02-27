/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIIncrementalDownload.idl
 */

#ifndef __gen_nsIIncrementalDownload_h__
#define __gen_nsIIncrementalDownload_h__


#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIRequestObserver; /* forward declaration */


/* starting interface:    nsIIncrementalDownload */
#define NS_IINCREMENTALDOWNLOAD_IID_STR "6687823f-56c4-461d-93a1-7f6cb7dfbfba"

#define NS_IINCREMENTALDOWNLOAD_IID \
  {0x6687823f, 0x56c4, 0x461d, \
    { 0x93, 0xa1, 0x7f, 0x6c, 0xb7, 0xdf, 0xbf, 0xba }}

class NS_NO_VTABLE nsIIncrementalDownload : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINCREMENTALDOWNLOAD_IID)

  /* void init (in nsIURI uri, in nsIFile destination, in long chunkSize, in long intervalInSeconds); */
  NS_IMETHOD Init(nsIURI *uri, nsIFile *destination, int32_t chunkSize, int32_t intervalInSeconds) = 0;

  /* readonly attribute nsIURI URI; */
  NS_IMETHOD GetURI(nsIURI * *aURI) = 0;

  /* readonly attribute nsIURI finalURI; */
  NS_IMETHOD GetFinalURI(nsIURI * *aFinalURI) = 0;

  /* readonly attribute nsIFile destination; */
  NS_IMETHOD GetDestination(nsIFile * *aDestination) = 0;

  /* readonly attribute long long totalSize; */
  NS_IMETHOD GetTotalSize(int64_t *aTotalSize) = 0;

  /* readonly attribute long long currentSize; */
  NS_IMETHOD GetCurrentSize(int64_t *aCurrentSize) = 0;

  /* void start (in nsIRequestObserver observer, in nsISupports ctxt); */
  NS_IMETHOD Start(nsIRequestObserver *observer, nsISupports *ctxt) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIncrementalDownload, NS_IINCREMENTALDOWNLOAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINCREMENTALDOWNLOAD \
  NS_IMETHOD Init(nsIURI *uri, nsIFile *destination, int32_t chunkSize, int32_t intervalInSeconds); \
  NS_IMETHOD GetURI(nsIURI * *aURI); \
  NS_IMETHOD GetFinalURI(nsIURI * *aFinalURI); \
  NS_IMETHOD GetDestination(nsIFile * *aDestination); \
  NS_IMETHOD GetTotalSize(int64_t *aTotalSize); \
  NS_IMETHOD GetCurrentSize(int64_t *aCurrentSize); \
  NS_IMETHOD Start(nsIRequestObserver *observer, nsISupports *ctxt); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINCREMENTALDOWNLOAD(_to) \
  NS_IMETHOD Init(nsIURI *uri, nsIFile *destination, int32_t chunkSize, int32_t intervalInSeconds) { return _to Init(uri, destination, chunkSize, intervalInSeconds); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return _to GetURI(aURI); } \
  NS_IMETHOD GetFinalURI(nsIURI * *aFinalURI) { return _to GetFinalURI(aFinalURI); } \
  NS_IMETHOD GetDestination(nsIFile * *aDestination) { return _to GetDestination(aDestination); } \
  NS_IMETHOD GetTotalSize(int64_t *aTotalSize) { return _to GetTotalSize(aTotalSize); } \
  NS_IMETHOD GetCurrentSize(int64_t *aCurrentSize) { return _to GetCurrentSize(aCurrentSize); } \
  NS_IMETHOD Start(nsIRequestObserver *observer, nsISupports *ctxt) { return _to Start(observer, ctxt); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINCREMENTALDOWNLOAD(_to) \
  NS_IMETHOD Init(nsIURI *uri, nsIFile *destination, int32_t chunkSize, int32_t intervalInSeconds) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(uri, destination, chunkSize, intervalInSeconds); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_IMETHOD GetFinalURI(nsIURI * *aFinalURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFinalURI(aFinalURI); } \
  NS_IMETHOD GetDestination(nsIFile * *aDestination) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDestination(aDestination); } \
  NS_IMETHOD GetTotalSize(int64_t *aTotalSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalSize(aTotalSize); } \
  NS_IMETHOD GetCurrentSize(int64_t *aCurrentSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentSize(aCurrentSize); } \
  NS_IMETHOD Start(nsIRequestObserver *observer, nsISupports *ctxt) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(observer, ctxt); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIncrementalDownload : public nsIIncrementalDownload
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINCREMENTALDOWNLOAD

  nsIncrementalDownload();

private:
  ~nsIncrementalDownload();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIncrementalDownload, nsIIncrementalDownload)

nsIncrementalDownload::nsIncrementalDownload()
{
  /* member initializers and constructor code */
}

nsIncrementalDownload::~nsIncrementalDownload()
{
  /* destructor code */
}

/* void init (in nsIURI uri, in nsIFile destination, in long chunkSize, in long intervalInSeconds); */
NS_IMETHODIMP nsIncrementalDownload::Init(nsIURI *uri, nsIFile *destination, int32_t chunkSize, int32_t intervalInSeconds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI URI; */
NS_IMETHODIMP nsIncrementalDownload::GetURI(nsIURI * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI finalURI; */
NS_IMETHODIMP nsIncrementalDownload::GetFinalURI(nsIURI * *aFinalURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile destination; */
NS_IMETHODIMP nsIncrementalDownload::GetDestination(nsIFile * *aDestination)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long totalSize; */
NS_IMETHODIMP nsIncrementalDownload::GetTotalSize(int64_t *aTotalSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long currentSize; */
NS_IMETHODIMP nsIncrementalDownload::GetCurrentSize(int64_t *aCurrentSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void start (in nsIRequestObserver observer, in nsISupports ctxt); */
NS_IMETHODIMP nsIncrementalDownload::Start(nsIRequestObserver *observer, nsISupports *ctxt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIncrementalDownload_h__ */
