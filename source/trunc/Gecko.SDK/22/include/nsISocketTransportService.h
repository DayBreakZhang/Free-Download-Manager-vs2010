/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsISocketTransportService.idl
 */

#ifndef __gen_nsISocketTransportService_h__
#define __gen_nsISocketTransportService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISocketTransport; /* forward declaration */

class nsIProxyInfo; /* forward declaration */

class nsIRunnable; /* forward declaration */

class nsASocketHandler;
struct PRFileDesc;

/* starting interface:    nsISocketTransportService */
#define NS_ISOCKETTRANSPORTSERVICE_IID_STR "185b3a5d-8729-436d-9693-7bdccb9c2216"

#define NS_ISOCKETTRANSPORTSERVICE_IID \
  {0x185b3a5d, 0x8729, 0x436d, \
    { 0x96, 0x93, 0x7b, 0xdc, 0xcb, 0x9c, 0x22, 0x16 }}

class NS_NO_VTABLE nsISocketTransportService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISOCKETTRANSPORTSERVICE_IID)

  /* nsISocketTransport createTransport ([array, size_is (aTypeCount)] in string aSocketTypes, in unsigned long aTypeCount, in AUTF8String aHost, in long aPort, in nsIProxyInfo aProxyInfo); */
  NS_IMETHOD CreateTransport(const char * *aSocketTypes, uint32_t aTypeCount, const nsACString & aHost, int32_t aPort, nsIProxyInfo *aProxyInfo, nsISocketTransport * *_retval) = 0;

  /* [noscript] void attachSocket (in PRFileDescPtr aFd, in nsASocketHandlerPtr aHandler); */
  NS_IMETHOD AttachSocket(PRFileDesc *aFd, nsASocketHandler *aHandler) = 0;

  /* [noscript] void notifyWhenCanAttachSocket (in nsIRunnable aEvent); */
  NS_IMETHOD NotifyWhenCanAttachSocket(nsIRunnable *aEvent) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISocketTransportService, NS_ISOCKETTRANSPORTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISOCKETTRANSPORTSERVICE \
  NS_IMETHOD CreateTransport(const char * *aSocketTypes, uint32_t aTypeCount, const nsACString & aHost, int32_t aPort, nsIProxyInfo *aProxyInfo, nsISocketTransport * *_retval); \
  NS_IMETHOD AttachSocket(PRFileDesc *aFd, nsASocketHandler *aHandler); \
  NS_IMETHOD NotifyWhenCanAttachSocket(nsIRunnable *aEvent); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISOCKETTRANSPORTSERVICE(_to) \
  NS_IMETHOD CreateTransport(const char * *aSocketTypes, uint32_t aTypeCount, const nsACString & aHost, int32_t aPort, nsIProxyInfo *aProxyInfo, nsISocketTransport * *_retval) { return _to CreateTransport(aSocketTypes, aTypeCount, aHost, aPort, aProxyInfo, _retval); } \
  NS_IMETHOD AttachSocket(PRFileDesc *aFd, nsASocketHandler *aHandler) { return _to AttachSocket(aFd, aHandler); } \
  NS_IMETHOD NotifyWhenCanAttachSocket(nsIRunnable *aEvent) { return _to NotifyWhenCanAttachSocket(aEvent); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISOCKETTRANSPORTSERVICE(_to) \
  NS_IMETHOD CreateTransport(const char * *aSocketTypes, uint32_t aTypeCount, const nsACString & aHost, int32_t aPort, nsIProxyInfo *aProxyInfo, nsISocketTransport * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTransport(aSocketTypes, aTypeCount, aHost, aPort, aProxyInfo, _retval); } \
  NS_IMETHOD AttachSocket(PRFileDesc *aFd, nsASocketHandler *aHandler) { return !_to ? NS_ERROR_NULL_POINTER : _to->AttachSocket(aFd, aHandler); } \
  NS_IMETHOD NotifyWhenCanAttachSocket(nsIRunnable *aEvent) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyWhenCanAttachSocket(aEvent); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSocketTransportService : public nsISocketTransportService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISOCKETTRANSPORTSERVICE

  nsSocketTransportService();

private:
  ~nsSocketTransportService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSocketTransportService, nsISocketTransportService)

nsSocketTransportService::nsSocketTransportService()
{
  /* member initializers and constructor code */
}

nsSocketTransportService::~nsSocketTransportService()
{
  /* destructor code */
}

/* nsISocketTransport createTransport ([array, size_is (aTypeCount)] in string aSocketTypes, in unsigned long aTypeCount, in AUTF8String aHost, in long aPort, in nsIProxyInfo aProxyInfo); */
NS_IMETHODIMP nsSocketTransportService::CreateTransport(const char * *aSocketTypes, uint32_t aTypeCount, const nsACString & aHost, int32_t aPort, nsIProxyInfo *aProxyInfo, nsISocketTransport * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void attachSocket (in PRFileDescPtr aFd, in nsASocketHandlerPtr aHandler); */
NS_IMETHODIMP nsSocketTransportService::AttachSocket(PRFileDesc *aFd, nsASocketHandler *aHandler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void notifyWhenCanAttachSocket (in nsIRunnable aEvent); */
NS_IMETHODIMP nsSocketTransportService::NotifyWhenCanAttachSocket(nsIRunnable *aEvent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISocketTransportService_h__ */
