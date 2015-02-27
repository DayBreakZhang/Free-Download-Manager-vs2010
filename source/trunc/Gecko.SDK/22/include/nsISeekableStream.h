/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsISeekableStream.idl
 */

#ifndef __gen_nsISeekableStream_h__
#define __gen_nsISeekableStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISeekableStream */
#define NS_ISEEKABLESTREAM_IID_STR "8429d350-1040-4661-8b71-f2a6ba455980"

#define NS_ISEEKABLESTREAM_IID \
  {0x8429d350, 0x1040, 0x4661, \
    { 0x8b, 0x71, 0xf2, 0xa6, 0xba, 0x45, 0x59, 0x80 }}

class NS_NO_VTABLE nsISeekableStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISEEKABLESTREAM_IID)

  enum {
    NS_SEEK_SET = 0,
    NS_SEEK_CUR = 1,
    NS_SEEK_END = 2
  };

  /* void seek (in long whence, in long long offset); */
  NS_IMETHOD Seek(int32_t whence, int64_t offset) = 0;

  /* long long tell (); */
  NS_IMETHOD Tell(int64_t *_retval) = 0;

  /* void setEOF (); */
  NS_IMETHOD SetEOF(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISeekableStream, NS_ISEEKABLESTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISEEKABLESTREAM \
  NS_IMETHOD Seek(int32_t whence, int64_t offset); \
  NS_IMETHOD Tell(int64_t *_retval); \
  NS_IMETHOD SetEOF(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISEEKABLESTREAM(_to) \
  NS_IMETHOD Seek(int32_t whence, int64_t offset) { return _to Seek(whence, offset); } \
  NS_IMETHOD Tell(int64_t *_retval) { return _to Tell(_retval); } \
  NS_IMETHOD SetEOF(void) { return _to SetEOF(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISEEKABLESTREAM(_to) \
  NS_IMETHOD Seek(int32_t whence, int64_t offset) { return !_to ? NS_ERROR_NULL_POINTER : _to->Seek(whence, offset); } \
  NS_IMETHOD Tell(int64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Tell(_retval); } \
  NS_IMETHOD SetEOF(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEOF(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSeekableStream : public nsISeekableStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISEEKABLESTREAM

  nsSeekableStream();

private:
  ~nsSeekableStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSeekableStream, nsISeekableStream)

nsSeekableStream::nsSeekableStream()
{
  /* member initializers and constructor code */
}

nsSeekableStream::~nsSeekableStream()
{
  /* destructor code */
}

/* void seek (in long whence, in long long offset); */
NS_IMETHODIMP nsSeekableStream::Seek(int32_t whence, int64_t offset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long long tell (); */
NS_IMETHODIMP nsSeekableStream::Tell(int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setEOF (); */
NS_IMETHODIMP nsSeekableStream::SetEOF()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISeekableStream_h__ */
