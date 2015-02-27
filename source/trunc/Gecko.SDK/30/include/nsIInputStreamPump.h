/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIInputStreamPump.idl
 */

#ifndef __gen_nsIInputStreamPump_h__
#define __gen_nsIInputStreamPump_h__


#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIStreamListener; /* forward declaration */


/* starting interface:    nsIInputStreamPump */
#define NS_IINPUTSTREAMPUMP_IID_STR "400f5468-97e7-4d2b-9c65-a82aecc7ae82"

#define NS_IINPUTSTREAMPUMP_IID \
  {0x400f5468, 0x97e7, 0x4d2b, \
    { 0x9c, 0x65, 0xa8, 0x2a, 0xec, 0xc7, 0xae, 0x82 }}

class NS_NO_VTABLE nsIInputStreamPump : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTSTREAMPUMP_IID)

  /* void init (in nsIInputStream aStream, in long long aStreamPos, in long long aStreamLen, in unsigned long aSegmentSize, in unsigned long aSegmentCount, in boolean aCloseWhenDone); */
  NS_IMETHOD Init(nsIInputStream *aStream, int64_t aStreamPos, int64_t aStreamLen, uint32_t aSegmentSize, uint32_t aSegmentCount, bool aCloseWhenDone) = 0;

  /* void asyncRead (in nsIStreamListener aListener, in nsISupports aListenerContext); */
  NS_IMETHOD AsyncRead(nsIStreamListener *aListener, nsISupports *aListenerContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputStreamPump, NS_IINPUTSTREAMPUMP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTSTREAMPUMP \
  NS_IMETHOD Init(nsIInputStream *aStream, int64_t aStreamPos, int64_t aStreamLen, uint32_t aSegmentSize, uint32_t aSegmentCount, bool aCloseWhenDone); \
  NS_IMETHOD AsyncRead(nsIStreamListener *aListener, nsISupports *aListenerContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTSTREAMPUMP(_to) \
  NS_IMETHOD Init(nsIInputStream *aStream, int64_t aStreamPos, int64_t aStreamLen, uint32_t aSegmentSize, uint32_t aSegmentCount, bool aCloseWhenDone) { return _to Init(aStream, aStreamPos, aStreamLen, aSegmentSize, aSegmentCount, aCloseWhenDone); } \
  NS_IMETHOD AsyncRead(nsIStreamListener *aListener, nsISupports *aListenerContext) { return _to AsyncRead(aListener, aListenerContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTSTREAMPUMP(_to) \
  NS_IMETHOD Init(nsIInputStream *aStream, int64_t aStreamPos, int64_t aStreamLen, uint32_t aSegmentSize, uint32_t aSegmentCount, bool aCloseWhenDone) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aStream, aStreamPos, aStreamLen, aSegmentSize, aSegmentCount, aCloseWhenDone); } \
  NS_IMETHOD AsyncRead(nsIStreamListener *aListener, nsISupports *aListenerContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncRead(aListener, aListenerContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputStreamPump : public nsIInputStreamPump
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTSTREAMPUMP

  nsInputStreamPump();

private:
  ~nsInputStreamPump();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInputStreamPump, nsIInputStreamPump)

nsInputStreamPump::nsInputStreamPump()
{
  /* member initializers and constructor code */
}

nsInputStreamPump::~nsInputStreamPump()
{
  /* destructor code */
}

/* void init (in nsIInputStream aStream, in long long aStreamPos, in long long aStreamLen, in unsigned long aSegmentSize, in unsigned long aSegmentCount, in boolean aCloseWhenDone); */
NS_IMETHODIMP nsInputStreamPump::Init(nsIInputStream *aStream, int64_t aStreamPos, int64_t aStreamLen, uint32_t aSegmentSize, uint32_t aSegmentCount, bool aCloseWhenDone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncRead (in nsIStreamListener aListener, in nsISupports aListenerContext); */
NS_IMETHODIMP nsInputStreamPump::AsyncRead(nsIStreamListener *aListener, nsISupports *aListenerContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInputStreamPump_h__ */
