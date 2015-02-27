/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBufferedStreams.idl
 */

#ifndef __gen_nsIBufferedStreams_h__
#define __gen_nsIBufferedStreams_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

#ifndef __gen_nsIOutputStream_h__
#include "nsIOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIBufferedInputStream */
#define NS_IBUFFEREDINPUTSTREAM_IID_STR "616f5b48-da09-11d3-8cda-0060b0fc14a3"

#define NS_IBUFFEREDINPUTSTREAM_IID \
  {0x616f5b48, 0xda09, 0x11d3, \
    { 0x8c, 0xda, 0x00, 0x60, 0xb0, 0xfc, 0x14, 0xa3 }}

class NS_NO_VTABLE nsIBufferedInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBUFFEREDINPUTSTREAM_IID)

  /* void init (in nsIInputStream fillFromStream, in unsigned long bufferSize); */
  NS_IMETHOD Init(nsIInputStream *fillFromStream, uint32_t bufferSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBufferedInputStream, NS_IBUFFEREDINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBUFFEREDINPUTSTREAM \
  NS_IMETHOD Init(nsIInputStream *fillFromStream, uint32_t bufferSize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBUFFEREDINPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIInputStream *fillFromStream, uint32_t bufferSize) { return _to Init(fillFromStream, bufferSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBUFFEREDINPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIInputStream *fillFromStream, uint32_t bufferSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(fillFromStream, bufferSize); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBufferedInputStream : public nsIBufferedInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBUFFEREDINPUTSTREAM

  nsBufferedInputStream();

private:
  ~nsBufferedInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBufferedInputStream, nsIBufferedInputStream)

nsBufferedInputStream::nsBufferedInputStream()
{
  /* member initializers and constructor code */
}

nsBufferedInputStream::~nsBufferedInputStream()
{
  /* destructor code */
}

/* void init (in nsIInputStream fillFromStream, in unsigned long bufferSize); */
NS_IMETHODIMP nsBufferedInputStream::Init(nsIInputStream *fillFromStream, uint32_t bufferSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIBufferedOutputStream */
#define NS_IBUFFEREDOUTPUTSTREAM_IID_STR "6476378a-da09-11d3-8cda-0060b0fc14a3"

#define NS_IBUFFEREDOUTPUTSTREAM_IID \
  {0x6476378a, 0xda09, 0x11d3, \
    { 0x8c, 0xda, 0x00, 0x60, 0xb0, 0xfc, 0x14, 0xa3 }}

class NS_NO_VTABLE nsIBufferedOutputStream : public nsIOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBUFFEREDOUTPUTSTREAM_IID)

  /* void init (in nsIOutputStream sinkToStream, in unsigned long bufferSize); */
  NS_IMETHOD Init(nsIOutputStream *sinkToStream, uint32_t bufferSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBufferedOutputStream, NS_IBUFFEREDOUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBUFFEREDOUTPUTSTREAM \
  NS_IMETHOD Init(nsIOutputStream *sinkToStream, uint32_t bufferSize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBUFFEREDOUTPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIOutputStream *sinkToStream, uint32_t bufferSize) { return _to Init(sinkToStream, bufferSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBUFFEREDOUTPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIOutputStream *sinkToStream, uint32_t bufferSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(sinkToStream, bufferSize); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBufferedOutputStream : public nsIBufferedOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBUFFEREDOUTPUTSTREAM

  nsBufferedOutputStream();

private:
  ~nsBufferedOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBufferedOutputStream, nsIBufferedOutputStream)

nsBufferedOutputStream::nsBufferedOutputStream()
{
  /* member initializers and constructor code */
}

nsBufferedOutputStream::~nsBufferedOutputStream()
{
  /* destructor code */
}

/* void init (in nsIOutputStream sinkToStream, in unsigned long bufferSize); */
NS_IMETHODIMP nsBufferedOutputStream::Init(nsIOutputStream *sinkToStream, uint32_t bufferSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBufferedStreams_h__ */
