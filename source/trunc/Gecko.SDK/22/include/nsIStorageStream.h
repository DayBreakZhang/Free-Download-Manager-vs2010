/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsIStorageStream.idl
 */

#ifndef __gen_nsIStorageStream_h__
#define __gen_nsIStorageStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMemory; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIStorageStream */
#define NS_ISTORAGESTREAM_IID_STR "604ad9d0-753e-11d3-90ca-34278643278f"

#define NS_ISTORAGESTREAM_IID \
  {0x604ad9d0, 0x753e, 0x11d3, \
    { 0x90, 0xca, 0x34, 0x27, 0x86, 0x43, 0x27, 0x8f }}

class NS_NO_VTABLE nsIStorageStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTORAGESTREAM_IID)

  /* void init (in uint32_t segmentSize, in uint32_t maxSize, in nsIMemory segmentAllocator); */
  NS_IMETHOD Init(uint32_t segmentSize, uint32_t maxSize, nsIMemory *segmentAllocator) = 0;

  /* nsIOutputStream getOutputStream (in int32_t startPosition); */
  NS_IMETHOD GetOutputStream(int32_t startPosition, nsIOutputStream * *_retval) = 0;

  /* nsIInputStream newInputStream (in int32_t startPosition); */
  NS_IMETHOD NewInputStream(int32_t startPosition, nsIInputStream * *_retval) = 0;

  /* attribute uint32_t length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;
  NS_IMETHOD SetLength(uint32_t aLength) = 0;

  /* readonly attribute boolean writeInProgress; */
  NS_IMETHOD GetWriteInProgress(bool *aWriteInProgress) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStorageStream, NS_ISTORAGESTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTORAGESTREAM \
  NS_IMETHOD Init(uint32_t segmentSize, uint32_t maxSize, nsIMemory *segmentAllocator); \
  NS_IMETHOD GetOutputStream(int32_t startPosition, nsIOutputStream * *_retval); \
  NS_IMETHOD NewInputStream(int32_t startPosition, nsIInputStream * *_retval); \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD SetLength(uint32_t aLength); \
  NS_IMETHOD GetWriteInProgress(bool *aWriteInProgress); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTORAGESTREAM(_to) \
  NS_IMETHOD Init(uint32_t segmentSize, uint32_t maxSize, nsIMemory *segmentAllocator) { return _to Init(segmentSize, maxSize, segmentAllocator); } \
  NS_IMETHOD GetOutputStream(int32_t startPosition, nsIOutputStream * *_retval) { return _to GetOutputStream(startPosition, _retval); } \
  NS_IMETHOD NewInputStream(int32_t startPosition, nsIInputStream * *_retval) { return _to NewInputStream(startPosition, _retval); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD SetLength(uint32_t aLength) { return _to SetLength(aLength); } \
  NS_IMETHOD GetWriteInProgress(bool *aWriteInProgress) { return _to GetWriteInProgress(aWriteInProgress); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTORAGESTREAM(_to) \
  NS_IMETHOD Init(uint32_t segmentSize, uint32_t maxSize, nsIMemory *segmentAllocator) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(segmentSize, maxSize, segmentAllocator); } \
  NS_IMETHOD GetOutputStream(int32_t startPosition, nsIOutputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOutputStream(startPosition, _retval); } \
  NS_IMETHOD NewInputStream(int32_t startPosition, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewInputStream(startPosition, _retval); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD SetLength(uint32_t aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLength(aLength); } \
  NS_IMETHOD GetWriteInProgress(bool *aWriteInProgress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWriteInProgress(aWriteInProgress); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStorageStream : public nsIStorageStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTORAGESTREAM

  nsStorageStream();

private:
  ~nsStorageStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStorageStream, nsIStorageStream)

nsStorageStream::nsStorageStream()
{
  /* member initializers and constructor code */
}

nsStorageStream::~nsStorageStream()
{
  /* destructor code */
}

/* void init (in uint32_t segmentSize, in uint32_t maxSize, in nsIMemory segmentAllocator); */
NS_IMETHODIMP nsStorageStream::Init(uint32_t segmentSize, uint32_t maxSize, nsIMemory *segmentAllocator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOutputStream getOutputStream (in int32_t startPosition); */
NS_IMETHODIMP nsStorageStream::GetOutputStream(int32_t startPosition, nsIOutputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream newInputStream (in int32_t startPosition); */
NS_IMETHODIMP nsStorageStream::NewInputStream(int32_t startPosition, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute uint32_t length; */
NS_IMETHODIMP nsStorageStream::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStorageStream::SetLength(uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean writeInProgress; */
NS_IMETHODIMP nsStorageStream::GetWriteInProgress(bool *aWriteInProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// Factory method
nsresult
NS_NewStorageStream(uint32_t segmentSize, uint32_t maxSize, nsIStorageStream **result);

#endif /* __gen_nsIStorageStream_h__ */
