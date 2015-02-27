/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProtocolProxyService2.idl
 */

#ifndef __gen_nsIProtocolProxyService2_h__
#define __gen_nsIProtocolProxyService2_h__


#ifndef __gen_nsIProtocolProxyService_h__
#include "nsIProtocolProxyService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIProtocolProxyService2 */
#define NS_IPROTOCOLPROXYSERVICE2_IID_STR "bb52e571-4a0e-4363-83d0-52034910dd14"

#define NS_IPROTOCOLPROXYSERVICE2_IID \
  {0xbb52e571, 0x4a0e, 0x4363, \
    { 0x83, 0xd0, 0x52, 0x03, 0x49, 0x10, 0xdd, 0x14 }}

class NS_NO_VTABLE nsIProtocolProxyService2 : public nsIProtocolProxyService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTOCOLPROXYSERVICE2_IID)

  /* void reloadPAC (); */
  NS_IMETHOD ReloadPAC(void) = 0;

  /* nsIProxyInfo deprecatedBlockingResolve (in nsIURI aURI, in unsigned long aFlags); */
  NS_IMETHOD DeprecatedBlockingResolve(nsIURI *aURI, uint32_t aFlags, nsIProxyInfo * *_retval) = 0;

  /* nsICancelable asyncResolve2 (in nsIURI aURI, in unsigned long aFlags, in nsIProtocolProxyCallback aCallback); */
  NS_IMETHOD AsyncResolve2(nsIURI *aURI, uint32_t aFlags, nsIProtocolProxyCallback *aCallback, nsICancelable * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtocolProxyService2, NS_IPROTOCOLPROXYSERVICE2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTOCOLPROXYSERVICE2 \
  NS_IMETHOD ReloadPAC(void); \
  NS_IMETHOD DeprecatedBlockingResolve(nsIURI *aURI, uint32_t aFlags, nsIProxyInfo * *_retval); \
  NS_IMETHOD AsyncResolve2(nsIURI *aURI, uint32_t aFlags, nsIProtocolProxyCallback *aCallback, nsICancelable * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTOCOLPROXYSERVICE2(_to) \
  NS_IMETHOD ReloadPAC(void) { return _to ReloadPAC(); } \
  NS_IMETHOD DeprecatedBlockingResolve(nsIURI *aURI, uint32_t aFlags, nsIProxyInfo * *_retval) { return _to DeprecatedBlockingResolve(aURI, aFlags, _retval); } \
  NS_IMETHOD AsyncResolve2(nsIURI *aURI, uint32_t aFlags, nsIProtocolProxyCallback *aCallback, nsICancelable * *_retval) { return _to AsyncResolve2(aURI, aFlags, aCallback, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTOCOLPROXYSERVICE2(_to) \
  NS_IMETHOD ReloadPAC(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadPAC(); } \
  NS_IMETHOD DeprecatedBlockingResolve(nsIURI *aURI, uint32_t aFlags, nsIProxyInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeprecatedBlockingResolve(aURI, aFlags, _retval); } \
  NS_IMETHOD AsyncResolve2(nsIURI *aURI, uint32_t aFlags, nsIProtocolProxyCallback *aCallback, nsICancelable * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncResolve2(aURI, aFlags, aCallback, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtocolProxyService2 : public nsIProtocolProxyService2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTOCOLPROXYSERVICE2

  nsProtocolProxyService2();

private:
  ~nsProtocolProxyService2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProtocolProxyService2, nsIProtocolProxyService2)

nsProtocolProxyService2::nsProtocolProxyService2()
{
  /* member initializers and constructor code */
}

nsProtocolProxyService2::~nsProtocolProxyService2()
{
  /* destructor code */
}

/* void reloadPAC (); */
NS_IMETHODIMP nsProtocolProxyService2::ReloadPAC()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIProxyInfo deprecatedBlockingResolve (in nsIURI aURI, in unsigned long aFlags); */
NS_IMETHODIMP nsProtocolProxyService2::DeprecatedBlockingResolve(nsIURI *aURI, uint32_t aFlags, nsIProxyInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICancelable asyncResolve2 (in nsIURI aURI, in unsigned long aFlags, in nsIProtocolProxyCallback aCallback); */
NS_IMETHODIMP nsProtocolProxyService2::AsyncResolve2(nsIURI *aURI, uint32_t aFlags, nsIProtocolProxyCallback *aCallback, nsICancelable * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProtocolProxyService2_h__ */
