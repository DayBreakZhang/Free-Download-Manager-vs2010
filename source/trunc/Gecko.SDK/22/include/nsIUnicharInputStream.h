/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsIUnicharInputStream.idl
 */

#ifndef __gen_nsIUnicharInputStream_h__
#define __gen_nsIUnicharInputStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUnicharInputStream; /* forward declaration */

class nsIInputStream; /* forward declaration */

/**
 * The signature of the writer function passed to ReadSegments. This
 * is the "consumer" of data that gets read from the stream's buffer.
 *
 * @param aInStream stream being read
 * @param aClosure opaque parameter passed to ReadSegments
 * @param aFromSegment pointer to memory owned by the input stream
 * @param aToOffset amount already read (since ReadSegments was called)
 * @param aCount length of fromSegment
 * @param aWriteCount number of bytes read
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
typedef NS_CALLBACK(nsWriteUnicharSegmentFun)(nsIUnicharInputStream *aInStream,
                                              void *aClosure,
                                              const PRUnichar *aFromSegment,
                                              uint32_t aToOffset,
                                              uint32_t aCount,
                                              uint32_t *aWriteCount);

/* starting interface:    nsIUnicharInputStream */
#define NS_IUNICHARINPUTSTREAM_IID_STR "d5e3bd80-6723-4b92-b0c9-22f6162fd94f"

#define NS_IUNICHARINPUTSTREAM_IID \
  {0xd5e3bd80, 0x6723, 0x4b92, \
    { 0xb0, 0xc9, 0x22, 0xf6, 0x16, 0x2f, 0xd9, 0x4f }}

class NS_NO_VTABLE nsIUnicharInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUNICHARINPUTSTREAM_IID)

  /* [noscript] unsigned long read ([array, size_is (aCount)] in PRUnichar aBuf, in unsigned long aCount); */
  NS_IMETHOD Read(PRUnichar *aBuf, uint32_t aCount, uint32_t *_retval) = 0;

  /* [noscript] unsigned long readSegments (in nsWriteUnicharSegmentFun aWriter, in voidPtr aClosure, in unsigned long aCount); */
  NS_IMETHOD ReadSegments(nsWriteUnicharSegmentFun aWriter, void *aClosure, uint32_t aCount, uint32_t *_retval) = 0;

  /* unsigned long readString (in unsigned long aCount, out AString aString); */
  NS_IMETHOD ReadString(uint32_t aCount, nsAString & aString, uint32_t *_retval) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUnicharInputStream, NS_IUNICHARINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUNICHARINPUTSTREAM \
  NS_IMETHOD Read(PRUnichar *aBuf, uint32_t aCount, uint32_t *_retval); \
  NS_IMETHOD ReadSegments(nsWriteUnicharSegmentFun aWriter, void *aClosure, uint32_t aCount, uint32_t *_retval); \
  NS_IMETHOD ReadString(uint32_t aCount, nsAString & aString, uint32_t *_retval); \
  NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUNICHARINPUTSTREAM(_to) \
  NS_IMETHOD Read(PRUnichar *aBuf, uint32_t aCount, uint32_t *_retval) { return _to Read(aBuf, aCount, _retval); } \
  NS_IMETHOD ReadSegments(nsWriteUnicharSegmentFun aWriter, void *aClosure, uint32_t aCount, uint32_t *_retval) { return _to ReadSegments(aWriter, aClosure, aCount, _retval); } \
  NS_IMETHOD ReadString(uint32_t aCount, nsAString & aString, uint32_t *_retval) { return _to ReadString(aCount, aString, _retval); } \
  NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUNICHARINPUTSTREAM(_to) \
  NS_IMETHOD Read(PRUnichar *aBuf, uint32_t aCount, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Read(aBuf, aCount, _retval); } \
  NS_IMETHOD ReadSegments(nsWriteUnicharSegmentFun aWriter, void *aClosure, uint32_t aCount, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadSegments(aWriter, aClosure, aCount, _retval); } \
  NS_IMETHOD ReadString(uint32_t aCount, nsAString & aString, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadString(aCount, aString, _retval); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUnicharInputStream : public nsIUnicharInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUNICHARINPUTSTREAM

  nsUnicharInputStream();

private:
  ~nsUnicharInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUnicharInputStream, nsIUnicharInputStream)

nsUnicharInputStream::nsUnicharInputStream()
{
  /* member initializers and constructor code */
}

nsUnicharInputStream::~nsUnicharInputStream()
{
  /* destructor code */
}

/* [noscript] unsigned long read ([array, size_is (aCount)] in PRUnichar aBuf, in unsigned long aCount); */
NS_IMETHODIMP nsUnicharInputStream::Read(PRUnichar *aBuf, uint32_t aCount, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] unsigned long readSegments (in nsWriteUnicharSegmentFun aWriter, in voidPtr aClosure, in unsigned long aCount); */
NS_IMETHODIMP nsUnicharInputStream::ReadSegments(nsWriteUnicharSegmentFun aWriter, void *aClosure, uint32_t aCount, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long readString (in unsigned long aCount, out AString aString); */
NS_IMETHODIMP nsUnicharInputStream::ReadString(uint32_t aCount, nsAString & aString, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsUnicharInputStream::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUnicharInputStream_h__ */
