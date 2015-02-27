/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsINSSErrorsService.idl
 */

#ifndef __gen_nsINSSErrorsService_h__
#define __gen_nsINSSErrorsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINSSErrorsService */
#define NS_INSSERRORSSERVICE_IID_STR "3a5c7a0f-f5da-4a8b-a748-d7c5a528f33b"

#define NS_INSSERRORSSERVICE_IID \
  {0x3a5c7a0f, 0xf5da, 0x4a8b, \
    { 0xa7, 0x48, 0xd7, 0xc5, 0xa5, 0x28, 0xf3, 0x3b }}

class NS_NO_VTABLE nsINSSErrorsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INSSERRORSSERVICE_IID)

  /* boolean isNSSErrorCode (in int32_t aNSPRCode); */
  NS_IMETHOD IsNSSErrorCode(int32_t aNSPRCode, bool *_retval) = 0;

  /* nsresult getXPCOMFromNSSError (in int32_t aNSPRCode); */
  NS_IMETHOD GetXPCOMFromNSSError(int32_t aNSPRCode, nsresult *_retval) = 0;

  /* AString getErrorMessage (in nsresult aXPCOMErrorCode); */
  NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval) = 0;

  /* uint32_t getErrorClass (in nsresult aXPCOMErrorCode); */
  NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, uint32_t *_retval) = 0;

  enum {
    ERROR_CLASS_SSL_PROTOCOL = 1U,
    ERROR_CLASS_BAD_CERT = 2U,
    NSS_SEC_ERROR_BASE = -8192,
    NSS_SEC_ERROR_LIMIT = -7192,
    NSS_SSL_ERROR_BASE = -12288,
    NSS_SSL_ERROR_LIMIT = -11288
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINSSErrorsService, NS_INSSERRORSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINSSERRORSSERVICE \
  NS_IMETHOD IsNSSErrorCode(int32_t aNSPRCode, bool *_retval); \
  NS_IMETHOD GetXPCOMFromNSSError(int32_t aNSPRCode, nsresult *_retval); \
  NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval); \
  NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, uint32_t *_retval); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINSSERRORSSERVICE(_to) \
  NS_IMETHOD IsNSSErrorCode(int32_t aNSPRCode, bool *_retval) { return _to IsNSSErrorCode(aNSPRCode, _retval); } \
  NS_IMETHOD GetXPCOMFromNSSError(int32_t aNSPRCode, nsresult *_retval) { return _to GetXPCOMFromNSSError(aNSPRCode, _retval); } \
  NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval) { return _to GetErrorMessage(aXPCOMErrorCode, _retval); } \
  NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, uint32_t *_retval) { return _to GetErrorClass(aXPCOMErrorCode, _retval); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINSSERRORSSERVICE(_to) \
  NS_IMETHOD IsNSSErrorCode(int32_t aNSPRCode, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsNSSErrorCode(aNSPRCode, _retval); } \
  NS_IMETHOD GetXPCOMFromNSSError(int32_t aNSPRCode, nsresult *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXPCOMFromNSSError(aNSPRCode, _retval); } \
  NS_IMETHOD GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorMessage(aXPCOMErrorCode, _retval); } \
  NS_IMETHOD GetErrorClass(nsresult aXPCOMErrorCode, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetErrorClass(aXPCOMErrorCode, _retval); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNSSErrorsService : public nsINSSErrorsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINSSERRORSSERVICE

  nsNSSErrorsService();

private:
  ~nsNSSErrorsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNSSErrorsService, nsINSSErrorsService)

nsNSSErrorsService::nsNSSErrorsService()
{
  /* member initializers and constructor code */
}

nsNSSErrorsService::~nsNSSErrorsService()
{
  /* destructor code */
}

/* boolean isNSSErrorCode (in int32_t aNSPRCode); */
NS_IMETHODIMP nsNSSErrorsService::IsNSSErrorCode(int32_t aNSPRCode, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsresult getXPCOMFromNSSError (in int32_t aNSPRCode); */
NS_IMETHODIMP nsNSSErrorsService::GetXPCOMFromNSSError(int32_t aNSPRCode, nsresult *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getErrorMessage (in nsresult aXPCOMErrorCode); */
NS_IMETHODIMP nsNSSErrorsService::GetErrorMessage(nsresult aXPCOMErrorCode, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint32_t getErrorClass (in nsresult aXPCOMErrorCode); */
NS_IMETHODIMP nsNSSErrorsService::GetErrorClass(nsresult aXPCOMErrorCode, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINSSErrorsService_h__ */
