/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsIMultiplexInputStream.idl
 */

#ifndef __gen_nsIMultiplexInputStream_h__
#define __gen_nsIMultiplexInputStream_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMultiplexInputStream */
#define NS_IMULTIPLEXINPUTSTREAM_IID_STR "a076fd12-1dd1-11b2-b19a-d53b5dffaade"

#define NS_IMULTIPLEXINPUTSTREAM_IID \
  {0xa076fd12, 0x1dd1, 0x11b2, \
    { 0xb1, 0x9a, 0xd5, 0x3b, 0x5d, 0xff, 0xaa, 0xde }}

class NS_NO_VTABLE nsIMultiplexInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMULTIPLEXINPUTSTREAM_IID)

  /* readonly attribute unsigned long count; */
  NS_IMETHOD GetCount(uint32_t *aCount) = 0;

  /* void appendStream (in nsIInputStream stream); */
  NS_IMETHOD AppendStream(nsIInputStream *stream) = 0;

  /* void insertStream (in nsIInputStream stream, in unsigned long index); */
  NS_IMETHOD InsertStream(nsIInputStream *stream, uint32_t index) = 0;

  /* void removeStream (in unsigned long index); */
  NS_IMETHOD RemoveStream(uint32_t index) = 0;

  /* nsIInputStream getStream (in unsigned long index); */
  NS_IMETHOD GetStream(uint32_t index, nsIInputStream * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMultiplexInputStream, NS_IMULTIPLEXINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMULTIPLEXINPUTSTREAM \
  NS_IMETHOD GetCount(uint32_t *aCount); \
  NS_IMETHOD AppendStream(nsIInputStream *stream); \
  NS_IMETHOD InsertStream(nsIInputStream *stream, uint32_t index); \
  NS_IMETHOD RemoveStream(uint32_t index); \
  NS_IMETHOD GetStream(uint32_t index, nsIInputStream * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMULTIPLEXINPUTSTREAM(_to) \
  NS_IMETHOD GetCount(uint32_t *aCount) { return _to GetCount(aCount); } \
  NS_IMETHOD AppendStream(nsIInputStream *stream) { return _to AppendStream(stream); } \
  NS_IMETHOD InsertStream(nsIInputStream *stream, uint32_t index) { return _to InsertStream(stream, index); } \
  NS_IMETHOD RemoveStream(uint32_t index) { return _to RemoveStream(index); } \
  NS_IMETHOD GetStream(uint32_t index, nsIInputStream * *_retval) { return _to GetStream(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMULTIPLEXINPUTSTREAM(_to) \
  NS_IMETHOD GetCount(uint32_t *aCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCount(aCount); } \
  NS_IMETHOD AppendStream(nsIInputStream *stream) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendStream(stream); } \
  NS_IMETHOD InsertStream(nsIInputStream *stream, uint32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertStream(stream, index); } \
  NS_IMETHOD RemoveStream(uint32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveStream(index); } \
  NS_IMETHOD GetStream(uint32_t index, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStream(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMultiplexInputStream : public nsIMultiplexInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMULTIPLEXINPUTSTREAM

  nsMultiplexInputStream();

private:
  ~nsMultiplexInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMultiplexInputStream, nsIMultiplexInputStream)

nsMultiplexInputStream::nsMultiplexInputStream()
{
  /* member initializers and constructor code */
}

nsMultiplexInputStream::~nsMultiplexInputStream()
{
  /* destructor code */
}

/* readonly attribute unsigned long count; */
NS_IMETHODIMP nsMultiplexInputStream::GetCount(uint32_t *aCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void appendStream (in nsIInputStream stream); */
NS_IMETHODIMP nsMultiplexInputStream::AppendStream(nsIInputStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertStream (in nsIInputStream stream, in unsigned long index); */
NS_IMETHODIMP nsMultiplexInputStream::InsertStream(nsIInputStream *stream, uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeStream (in unsigned long index); */
NS_IMETHODIMP nsMultiplexInputStream::RemoveStream(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream getStream (in unsigned long index); */
NS_IMETHODIMP nsMultiplexInputStream::GetStream(uint32_t index, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMultiplexInputStream_h__ */
