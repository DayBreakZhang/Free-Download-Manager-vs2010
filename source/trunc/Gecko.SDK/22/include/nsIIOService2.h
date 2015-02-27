/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIIOService2.idl
 */

#ifndef __gen_nsIIOService2_h__
#define __gen_nsIIOService2_h__


#ifndef __gen_nsIIOService_h__
#include "nsIIOService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIOService2 */
#define NS_IIOSERVICE2_IID_STR "9a7dc724-0b5c-4b78-9722-1037074c02de"

#define NS_IIOSERVICE2_IID \
  {0x9a7dc724, 0x0b5c, 0x4b78, \
    { 0x97, 0x22, 0x10, 0x37, 0x07, 0x4c, 0x02, 0xde }}

class NS_NO_VTABLE nsIIOService2 : public nsIIOService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIOSERVICE2_IID)

  /* attribute boolean manageOfflineStatus; */
  NS_IMETHOD GetManageOfflineStatus(bool *aManageOfflineStatus) = 0;
  NS_IMETHOD SetManageOfflineStatus(bool aManageOfflineStatus) = 0;

  /* nsIChannel newChannelFromURIWithProxyFlags (in nsIURI aURI, in nsIURI aProxyURI, in unsigned long aProxyFlags); */
  NS_IMETHOD NewChannelFromURIWithProxyFlags(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIChannel * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIOService2, NS_IIOSERVICE2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIOSERVICE2 \
  NS_IMETHOD GetManageOfflineStatus(bool *aManageOfflineStatus); \
  NS_IMETHOD SetManageOfflineStatus(bool aManageOfflineStatus); \
  NS_IMETHOD NewChannelFromURIWithProxyFlags(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIChannel * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIOSERVICE2(_to) \
  NS_IMETHOD GetManageOfflineStatus(bool *aManageOfflineStatus) { return _to GetManageOfflineStatus(aManageOfflineStatus); } \
  NS_IMETHOD SetManageOfflineStatus(bool aManageOfflineStatus) { return _to SetManageOfflineStatus(aManageOfflineStatus); } \
  NS_IMETHOD NewChannelFromURIWithProxyFlags(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIChannel * *_retval) { return _to NewChannelFromURIWithProxyFlags(aURI, aProxyURI, aProxyFlags, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIOSERVICE2(_to) \
  NS_IMETHOD GetManageOfflineStatus(bool *aManageOfflineStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManageOfflineStatus(aManageOfflineStatus); } \
  NS_IMETHOD SetManageOfflineStatus(bool aManageOfflineStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetManageOfflineStatus(aManageOfflineStatus); } \
  NS_IMETHOD NewChannelFromURIWithProxyFlags(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIChannel * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannelFromURIWithProxyFlags(aURI, aProxyURI, aProxyFlags, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIOService2 : public nsIIOService2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIOSERVICE2

  nsIOService2();

private:
  ~nsIOService2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIOService2, nsIIOService2)

nsIOService2::nsIOService2()
{
  /* member initializers and constructor code */
}

nsIOService2::~nsIOService2()
{
  /* destructor code */
}

/* attribute boolean manageOfflineStatus; */
NS_IMETHODIMP nsIOService2::GetManageOfflineStatus(bool *aManageOfflineStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIOService2::SetManageOfflineStatus(bool aManageOfflineStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannelFromURIWithProxyFlags (in nsIURI aURI, in nsIURI aProxyURI, in unsigned long aProxyFlags); */
NS_IMETHODIMP nsIOService2::NewChannelFromURIWithProxyFlags(nsIURI *aURI, nsIURI *aProxyURI, uint32_t aProxyFlags, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIOService2_h__ */
