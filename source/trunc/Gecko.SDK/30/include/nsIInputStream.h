/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInputStream.idl
 */

#ifndef __gen_nsIInputStream_h__
#define __gen_nsIInputStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

/**
 * The signature of the writer function passed to ReadSegments. This
 * is the "consumer" of data that gets read from the stream's buffer.
 *
 * @param aInStream stream being read
 * @param aClosure opaque parameter passed to ReadSegments
 * @param aFromSegment pointer to memory owned by the input stream.  This is
 *                     where the writer function should start consuming data.
 * @param aToOffset amount of data already consumed by this writer during this
 *                  ReadSegments call.  This is also the sum of the aWriteCount
 *                  returns from this writer over the previous invocations of
 *                  the writer by this ReadSegments call.
 * @param aCount Number of bytes available to be read starting at aFromSegment
 * @param [out] aWriteCount number of bytes read by this writer function call
 *
 * Implementers should return the following:
 *
 * @return NS_OK and (*aWriteCount > 0) if consumed some data
 * @return <any-error> if not interested in consuming any data
 *
 * Errors are never passed to the caller of ReadSegments.
 *
 * NOTE: returning NS_OK and (*aWriteCount = 0) has undefined behavior.
 */
typedef NS_CALLBACK(nsWriteSegmentFun)(nsIInputStream *aInStream,
                                       void *aClosure,
                                       const char *aFromSegment,
                                       uint32_t aToOffset,
                                       uint32_t aCount,
                                       uint32_t *aWriteCount);

/* starting interface:    nsIInputStream */
#define NS_IINPUTSTREAM_IID_STR "53cdbc97-c2d7-4e30-b2c3-45b2ee79db18"

#define NS_IINPUTSTREAM_IID \
  {0x53cdbc97, 0xc2d7, 0x4e30, \
    { 0xb2, 0xc3, 0x45, 0xb2, 0xee, 0x79, 0xdb, 0x18 }}

class NS_NO_VTABLE nsIInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTSTREAM_IID)

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* unsigned long long available (); */
  NS_IMETHOD Available(uint64_t *_retval) = 0;

  /* [noscript] unsigned long read (in charPtr aBuf, in unsigned long aCount); */
  NS_IMETHOD Read(char *aBuf, uint32_t aCount, uint32_t *_retval) = 0;

  /* [noscript] unsigned long readSegments (in nsWriteSegmentFun aWriter, in voidPtr aClosure, in unsigned long aCount); */
  NS_IMETHOD ReadSegments(nsWriteSegmentFun aWriter, void *aClosure, uint32_t aCount, uint32_t *_retval) = 0;

  /* boolean isNonBlocking (); */
  NS_IMETHOD IsNonBlocking(bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputStream, NS_IINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTSTREAM \
  NS_IMETHOD Close(void); \
  NS_IMETHOD Available(uint64_t *_retval); \
  NS_IMETHOD Read(char *aBuf, uint32_t aCount, uint32_t *_retval); \
  NS_IMETHOD ReadSegments(nsWriteSegmentFun aWriter, void *aClosure, uint32_t aCount, uint32_t *_retval); \
  NS_IMETHOD IsNonBlocking(bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTSTREAM(_to) \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD Available(uint64_t *_retval) { return _to Available(_retval); } \
  NS_IMETHOD Read(char *aBuf, uint32_t aCount, uint32_t *_retval) { return _to Read(aBuf, aCount, _retval); } \
  NS_IMETHOD ReadSegments(nsWriteSegmentFun aWriter, void *aClosure, uint32_t aCount, uint32_t *_retval) { return _to ReadSegments(aWriter, aClosure, aCount, _retval); } \
  NS_IMETHOD IsNonBlocking(bool *_retval) { return _to IsNonBlocking(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTSTREAM(_to) \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Available(uint64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Available(_retval); } \
  NS_IMETHOD Read(char *aBuf, uint32_t aCount, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Read(aBuf, aCount, _retval); } \
  NS_IMETHOD ReadSegments(nsWriteSegmentFun aWriter, void *aClosure, uint32_t aCount, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadSegments(aWriter, aClosure, aCount, _retval); } \
  NS_IMETHOD IsNonBlocking(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsNonBlocking(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputStream : public nsIInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTSTREAM

  nsInputStream();

private:
  ~nsInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInputStream, nsIInputStream)

nsInputStream::nsInputStream()
{
  /* member initializers and constructor code */
}

nsInputStream::~nsInputStream()
{
  /* destructor code */
}

/* void close (); */
NS_IMETHODIMP nsInputStream::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long long available (); */
NS_IMETHODIMP nsInputStream::Available(uint64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] unsigned long read (in charPtr aBuf, in unsigned long aCount); */
NS_IMETHODIMP nsInputStream::Read(char *aBuf, uint32_t aCount, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] unsigned long readSegments (in nsWriteSegmentFun aWriter, in voidPtr aClosure, in unsigned long aCount); */
NS_IMETHODIMP nsInputStream::ReadSegments(nsWriteSegmentFun aWriter, void *aClosure, uint32_t aCount, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isNonBlocking (); */
NS_IMETHODIMP nsInputStream::IsNonBlocking(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInputStream_h__ */
