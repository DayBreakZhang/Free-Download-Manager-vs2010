/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsITransport.idl
 */

#ifndef __gen_nsITransport_h__
#define __gen_nsITransport_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */

class nsITransportEventSink; /* forward declaration */

class nsIEventTarget; /* forward declaration */


/* starting interface:    nsITransport */
#define NS_ITRANSPORT_IID_STR "d8786c64-eb49-4a0b-b42c-0936a745fbe8"

#define NS_ITRANSPORT_IID \
  {0xd8786c64, 0xeb49, 0x4a0b, \
    { 0xb4, 0x2c, 0x09, 0x36, 0xa7, 0x45, 0xfb, 0xe8 }}

class NS_NO_VTABLE nsITransport : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSPORT_IID)

  enum {
    OPEN_BLOCKING = 1U,
    OPEN_UNBUFFERED = 2U
  };

  /* nsIInputStream openInputStream (in unsigned long aFlags, in unsigned long aSegmentSize, in unsigned long aSegmentCount); */
  NS_IMETHOD OpenInputStream(uint32_t aFlags, uint32_t aSegmentSize, uint32_t aSegmentCount, nsIInputStream * *_retval) = 0;

  /* nsIOutputStream openOutputStream (in unsigned long aFlags, in unsigned long aSegmentSize, in unsigned long aSegmentCount); */
  NS_IMETHOD OpenOutputStream(uint32_t aFlags, uint32_t aSegmentSize, uint32_t aSegmentCount, nsIOutputStream * *_retval) = 0;

  /* void close (in nsresult aReason); */
  NS_IMETHOD Close(nsresult aReason) = 0;

  /* void setEventSink (in nsITransportEventSink aSink, in nsIEventTarget aEventTarget); */
  NS_IMETHOD SetEventSink(nsITransportEventSink *aSink, nsIEventTarget *aEventTarget) = 0;

  enum {
    STATUS_READING = 2152398856U,
    STATUS_WRITING = 2152398857U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransport, NS_ITRANSPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSPORT \
  NS_IMETHOD OpenInputStream(uint32_t aFlags, uint32_t aSegmentSize, uint32_t aSegmentCount, nsIInputStream * *_retval); \
  NS_IMETHOD OpenOutputStream(uint32_t aFlags, uint32_t aSegmentSize, uint32_t aSegmentCount, nsIOutputStream * *_retval); \
  NS_IMETHOD Close(nsresult aReason); \
  NS_IMETHOD SetEventSink(nsITransportEventSink *aSink, nsIEventTarget *aEventTarget); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSPORT(_to) \
  NS_IMETHOD OpenInputStream(uint32_t aFlags, uint32_t aSegmentSize, uint32_t aSegmentCount, nsIInputStream * *_retval) { return _to OpenInputStream(aFlags, aSegmentSize, aSegmentCount, _retval); } \
  NS_IMETHOD OpenOutputStream(uint32_t aFlags, uint32_t aSegmentSize, uint32_t aSegmentCount, nsIOutputStream * *_retval) { return _to OpenOutputStream(aFlags, aSegmentSize, aSegmentCount, _retval); } \
  NS_IMETHOD Close(nsresult aReason) { return _to Close(aReason); } \
  NS_IMETHOD SetEventSink(nsITransportEventSink *aSink, nsIEventTarget *aEventTarget) { return _to SetEventSink(aSink, aEventTarget); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSPORT(_to) \
  NS_IMETHOD OpenInputStream(uint32_t aFlags, uint32_t aSegmentSize, uint32_t aSegmentCount, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenInputStream(aFlags, aSegmentSize, aSegmentCount, _retval); } \
  NS_IMETHOD OpenOutputStream(uint32_t aFlags, uint32_t aSegmentSize, uint32_t aSegmentCount, nsIOutputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenOutputStream(aFlags, aSegmentSize, aSegmentCount, _retval); } \
  NS_IMETHOD Close(nsresult aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(aReason); } \
  NS_IMETHOD SetEventSink(nsITransportEventSink *aSink, nsIEventTarget *aEventTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEventSink(aSink, aEventTarget); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransport : public nsITransport
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSPORT

  nsTransport();

private:
  ~nsTransport();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransport, nsITransport)

nsTransport::nsTransport()
{
  /* member initializers and constructor code */
}

nsTransport::~nsTransport()
{
  /* destructor code */
}

/* nsIInputStream openInputStream (in unsigned long aFlags, in unsigned long aSegmentSize, in unsigned long aSegmentCount); */
NS_IMETHODIMP nsTransport::OpenInputStream(uint32_t aFlags, uint32_t aSegmentSize, uint32_t aSegmentCount, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIOutputStream openOutputStream (in unsigned long aFlags, in unsigned long aSegmentSize, in unsigned long aSegmentCount); */
NS_IMETHODIMP nsTransport::OpenOutputStream(uint32_t aFlags, uint32_t aSegmentSize, uint32_t aSegmentCount, nsIOutputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (in nsresult aReason); */
NS_IMETHODIMP nsTransport::Close(nsresult aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setEventSink (in nsITransportEventSink aSink, in nsIEventTarget aEventTarget); */
NS_IMETHODIMP nsTransport::SetEventSink(nsITransportEventSink *aSink, nsIEventTarget *aEventTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITransportEventSink */
#define NS_ITRANSPORTEVENTSINK_IID_STR "eda4f520-67f7-484b-a691-8c3226a5b0a6"

#define NS_ITRANSPORTEVENTSINK_IID \
  {0xeda4f520, 0x67f7, 0x484b, \
    { 0xa6, 0x91, 0x8c, 0x32, 0x26, 0xa5, 0xb0, 0xa6 }}

class NS_NO_VTABLE nsITransportEventSink : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSPORTEVENTSINK_IID)

  /* void onTransportStatus (in nsITransport aTransport, in nsresult aStatus, in unsigned long long aProgress, in unsigned long long aProgressMax); */
  NS_IMETHOD OnTransportStatus(nsITransport *aTransport, nsresult aStatus, uint64_t aProgress, uint64_t aProgressMax) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransportEventSink, NS_ITRANSPORTEVENTSINK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSPORTEVENTSINK \
  NS_IMETHOD OnTransportStatus(nsITransport *aTransport, nsresult aStatus, uint64_t aProgress, uint64_t aProgressMax); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSPORTEVENTSINK(_to) \
  NS_IMETHOD OnTransportStatus(nsITransport *aTransport, nsresult aStatus, uint64_t aProgress, uint64_t aProgressMax) { return _to OnTransportStatus(aTransport, aStatus, aProgress, aProgressMax); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSPORTEVENTSINK(_to) \
  NS_IMETHOD OnTransportStatus(nsITransport *aTransport, nsresult aStatus, uint64_t aProgress, uint64_t aProgressMax) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTransportStatus(aTransport, aStatus, aProgress, aProgressMax); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransportEventSink : public nsITransportEventSink
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSPORTEVENTSINK

  nsTransportEventSink();

private:
  ~nsTransportEventSink();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransportEventSink, nsITransportEventSink)

nsTransportEventSink::nsTransportEventSink()
{
  /* member initializers and constructor code */
}

nsTransportEventSink::~nsTransportEventSink()
{
  /* destructor code */
}

/* void onTransportStatus (in nsITransport aTransport, in nsresult aStatus, in unsigned long long aProgress, in unsigned long long aProgressMax); */
NS_IMETHODIMP nsTransportEventSink::OnTransportStatus(nsITransport *aTransport, nsresult aStatus, uint64_t aProgress, uint64_t aProgressMax)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransport_h__ */
