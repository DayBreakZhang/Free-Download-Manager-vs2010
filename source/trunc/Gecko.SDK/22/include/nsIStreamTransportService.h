/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIStreamTransportService.idl
 */

#ifndef __gen_nsIStreamTransportService_h__
#define __gen_nsIStreamTransportService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsITransport; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIOutputStream; /* forward declaration */


/* starting interface:    nsIStreamTransportService */
#define NS_ISTREAMTRANSPORTSERVICE_IID_STR "5e0adf7d-9785-45c3-a193-04f25a75da8f"

#define NS_ISTREAMTRANSPORTSERVICE_IID \
  {0x5e0adf7d, 0x9785, 0x45c3, \
    { 0xa1, 0x93, 0x04, 0xf2, 0x5a, 0x75, 0xda, 0x8f }}

class NS_NO_VTABLE nsIStreamTransportService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMTRANSPORTSERVICE_IID)

  /* nsITransport createInputTransport (in nsIInputStream aStream, in long long aStartOffset, in long long aReadLimit, in boolean aCloseWhenDone); */
  NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, int64_t aStartOffset, int64_t aReadLimit, bool aCloseWhenDone, nsITransport * *_retval) = 0;

  /* nsITransport createOutputTransport (in nsIOutputStream aStream, in long long aStartOffset, in long long aWriteLimit, in boolean aCloseWhenDone); */
  NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, int64_t aStartOffset, int64_t aWriteLimit, bool aCloseWhenDone, nsITransport * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamTransportService, NS_ISTREAMTRANSPORTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMTRANSPORTSERVICE \
  NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, int64_t aStartOffset, int64_t aReadLimit, bool aCloseWhenDone, nsITransport * *_retval); \
  NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, int64_t aStartOffset, int64_t aWriteLimit, bool aCloseWhenDone, nsITransport * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMTRANSPORTSERVICE(_to) \
  NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, int64_t aStartOffset, int64_t aReadLimit, bool aCloseWhenDone, nsITransport * *_retval) { return _to CreateInputTransport(aStream, aStartOffset, aReadLimit, aCloseWhenDone, _retval); } \
  NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, int64_t aStartOffset, int64_t aWriteLimit, bool aCloseWhenDone, nsITransport * *_retval) { return _to CreateOutputTransport(aStream, aStartOffset, aWriteLimit, aCloseWhenDone, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMTRANSPORTSERVICE(_to) \
  NS_IMETHOD CreateInputTransport(nsIInputStream *aStream, int64_t aStartOffset, int64_t aReadLimit, bool aCloseWhenDone, nsITransport * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateInputTransport(aStream, aStartOffset, aReadLimit, aCloseWhenDone, _retval); } \
  NS_IMETHOD CreateOutputTransport(nsIOutputStream *aStream, int64_t aStartOffset, int64_t aWriteLimit, bool aCloseWhenDone, nsITransport * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateOutputTransport(aStream, aStartOffset, aWriteLimit, aCloseWhenDone, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamTransportService : public nsIStreamTransportService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMTRANSPORTSERVICE

  nsStreamTransportService();

private:
  ~nsStreamTransportService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamTransportService, nsIStreamTransportService)

nsStreamTransportService::nsStreamTransportService()
{
  /* member initializers and constructor code */
}

nsStreamTransportService::~nsStreamTransportService()
{
  /* destructor code */
}

/* nsITransport createInputTransport (in nsIInputStream aStream, in long long aStartOffset, in long long aReadLimit, in boolean aCloseWhenDone); */
NS_IMETHODIMP nsStreamTransportService::CreateInputTransport(nsIInputStream *aStream, int64_t aStartOffset, int64_t aReadLimit, bool aCloseWhenDone, nsITransport * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsITransport createOutputTransport (in nsIOutputStream aStream, in long long aStartOffset, in long long aWriteLimit, in boolean aCloseWhenDone); */
NS_IMETHODIMP nsStreamTransportService::CreateOutputTransport(nsIOutputStream *aStream, int64_t aStartOffset, int64_t aWriteLimit, bool aCloseWhenDone, nsITransport * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamTransportService_h__ */
