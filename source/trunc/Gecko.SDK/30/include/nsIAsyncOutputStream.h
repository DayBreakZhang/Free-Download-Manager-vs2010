/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAsyncOutputStream.idl
 */

#ifndef __gen_nsIAsyncOutputStream_h__
#define __gen_nsIAsyncOutputStream_h__


#ifndef __gen_nsIOutputStream_h__
#include "nsIOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIOutputStreamCallback; /* forward declaration */

class nsIEventTarget; /* forward declaration */


/* starting interface:    nsIAsyncOutputStream */
#define NS_IASYNCOUTPUTSTREAM_IID_STR "beb632d3-d77a-4e90-9134-f9ece69e8200"

#define NS_IASYNCOUTPUTSTREAM_IID \
  {0xbeb632d3, 0xd77a, 0x4e90, \
    { 0x91, 0x34, 0xf9, 0xec, 0xe6, 0x9e, 0x82, 0x00 }}

class NS_NO_VTABLE nsIAsyncOutputStream : public nsIOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IASYNCOUTPUTSTREAM_IID)

  /* void closeWithStatus (in nsresult reason); */
  NS_IMETHOD CloseWithStatus(nsresult reason) = 0;

  /* void asyncWait (in nsIOutputStreamCallback aCallback, in unsigned long aFlags, in unsigned long aRequestedCount, in nsIEventTarget aEventTarget); */
  NS_IMETHOD AsyncWait(nsIOutputStreamCallback *aCallback, uint32_t aFlags, uint32_t aRequestedCount, nsIEventTarget *aEventTarget) = 0;

  enum {
    WAIT_CLOSURE_ONLY = 1U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAsyncOutputStream, NS_IASYNCOUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIASYNCOUTPUTSTREAM \
  NS_IMETHOD CloseWithStatus(nsresult reason); \
  NS_IMETHOD AsyncWait(nsIOutputStreamCallback *aCallback, uint32_t aFlags, uint32_t aRequestedCount, nsIEventTarget *aEventTarget); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIASYNCOUTPUTSTREAM(_to) \
  NS_IMETHOD CloseWithStatus(nsresult reason) { return _to CloseWithStatus(reason); } \
  NS_IMETHOD AsyncWait(nsIOutputStreamCallback *aCallback, uint32_t aFlags, uint32_t aRequestedCount, nsIEventTarget *aEventTarget) { return _to AsyncWait(aCallback, aFlags, aRequestedCount, aEventTarget); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIASYNCOUTPUTSTREAM(_to) \
  NS_IMETHOD CloseWithStatus(nsresult reason) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseWithStatus(reason); } \
  NS_IMETHOD AsyncWait(nsIOutputStreamCallback *aCallback, uint32_t aFlags, uint32_t aRequestedCount, nsIEventTarget *aEventTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncWait(aCallback, aFlags, aRequestedCount, aEventTarget); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAsyncOutputStream : public nsIAsyncOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIASYNCOUTPUTSTREAM

  nsAsyncOutputStream();

private:
  ~nsAsyncOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAsyncOutputStream, nsIAsyncOutputStream)

nsAsyncOutputStream::nsAsyncOutputStream()
{
  /* member initializers and constructor code */
}

nsAsyncOutputStream::~nsAsyncOutputStream()
{
  /* destructor code */
}

/* void closeWithStatus (in nsresult reason); */
NS_IMETHODIMP nsAsyncOutputStream::CloseWithStatus(nsresult reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncWait (in nsIOutputStreamCallback aCallback, in unsigned long aFlags, in unsigned long aRequestedCount, in nsIEventTarget aEventTarget); */
NS_IMETHODIMP nsAsyncOutputStream::AsyncWait(nsIOutputStreamCallback *aCallback, uint32_t aFlags, uint32_t aRequestedCount, nsIEventTarget *aEventTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIOutputStreamCallback */
#define NS_IOUTPUTSTREAMCALLBACK_IID_STR "40dbcdff-9053-42c5-a57c-3ec910d0f148"

#define NS_IOUTPUTSTREAMCALLBACK_IID \
  {0x40dbcdff, 0x9053, 0x42c5, \
    { 0xa5, 0x7c, 0x3e, 0xc9, 0x10, 0xd0, 0xf1, 0x48 }}

class NS_NO_VTABLE nsIOutputStreamCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOUTPUTSTREAMCALLBACK_IID)

  /* void onOutputStreamReady (in nsIAsyncOutputStream aStream); */
  NS_IMETHOD OnOutputStreamReady(nsIAsyncOutputStream *aStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOutputStreamCallback, NS_IOUTPUTSTREAMCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOUTPUTSTREAMCALLBACK \
  NS_IMETHOD OnOutputStreamReady(nsIAsyncOutputStream *aStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOUTPUTSTREAMCALLBACK(_to) \
  NS_IMETHOD OnOutputStreamReady(nsIAsyncOutputStream *aStream) { return _to OnOutputStreamReady(aStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOUTPUTSTREAMCALLBACK(_to) \
  NS_IMETHOD OnOutputStreamReady(nsIAsyncOutputStream *aStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnOutputStreamReady(aStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOutputStreamCallback : public nsIOutputStreamCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOUTPUTSTREAMCALLBACK

  nsOutputStreamCallback();

private:
  ~nsOutputStreamCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOutputStreamCallback, nsIOutputStreamCallback)

nsOutputStreamCallback::nsOutputStreamCallback()
{
  /* member initializers and constructor code */
}

nsOutputStreamCallback::~nsOutputStreamCallback()
{
  /* destructor code */
}

/* void onOutputStreamReady (in nsIAsyncOutputStream aStream); */
NS_IMETHODIMP nsOutputStreamCallback::OnOutputStreamReady(nsIAsyncOutputStream *aStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAsyncOutputStream_h__ */
