/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/security/manager/ssl/public/nsIX509Cert3.idl
 */

#ifndef __gen_nsIX509Cert3_h__
#define __gen_nsIX509Cert3_h__


#ifndef __gen_nsIX509Cert2_h__
#include "nsIX509Cert2.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICertVerificationListener; /* forward declaration */


/* starting interface:    nsIX509Cert3 */
#define NS_IX509CERT3_IID_STR "399004d8-b8c7-4eb9-8362-d99f4c0161fd"

#define NS_IX509CERT3_IID \
  {0x399004d8, 0xb8c7, 0x4eb9, \
    { 0x83, 0x62, 0xd9, 0x9f, 0x4c, 0x01, 0x61, 0xfd }}

class NS_NO_VTABLE nsIX509Cert3 : public nsIX509Cert2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IX509CERT3_IID)

  enum {
    CMS_CHAIN_MODE_CertOnly = 1U,
    CMS_CHAIN_MODE_CertChain = 2U,
    CMS_CHAIN_MODE_CertChainWithRoot = 3U
  };

  /* void requestUsagesArrayAsync (in nsICertVerificationListener cvl); */
  NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl) = 0;

  /* void exportAsCMS (in unsigned long chainMode, out unsigned long length, [array, size_is (length), retval] out octet data); */
  NS_IMETHOD ExportAsCMS(uint32_t chainMode, uint32_t *length, uint8_t **data) = 0;

  /* readonly attribute boolean isSelfSigned; */
  NS_IMETHOD GetIsSelfSigned(bool *aIsSelfSigned) = 0;

  /* void getAllTokenNames (out unsigned long length, [array, size_is (length), retval] out wstring tokenNames); */
  NS_IMETHOD GetAllTokenNames(uint32_t *length, PRUnichar * **tokenNames) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIX509Cert3, NS_IX509CERT3_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIX509CERT3 \
  NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl); \
  NS_IMETHOD ExportAsCMS(uint32_t chainMode, uint32_t *length, uint8_t **data); \
  NS_IMETHOD GetIsSelfSigned(bool *aIsSelfSigned); \
  NS_IMETHOD GetAllTokenNames(uint32_t *length, PRUnichar * **tokenNames); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIX509CERT3(_to) \
  NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl) { return _to RequestUsagesArrayAsync(cvl); } \
  NS_IMETHOD ExportAsCMS(uint32_t chainMode, uint32_t *length, uint8_t **data) { return _to ExportAsCMS(chainMode, length, data); } \
  NS_IMETHOD GetIsSelfSigned(bool *aIsSelfSigned) { return _to GetIsSelfSigned(aIsSelfSigned); } \
  NS_IMETHOD GetAllTokenNames(uint32_t *length, PRUnichar * **tokenNames) { return _to GetAllTokenNames(length, tokenNames); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIX509CERT3(_to) \
  NS_IMETHOD RequestUsagesArrayAsync(nsICertVerificationListener *cvl) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestUsagesArrayAsync(cvl); } \
  NS_IMETHOD ExportAsCMS(uint32_t chainMode, uint32_t *length, uint8_t **data) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExportAsCMS(chainMode, length, data); } \
  NS_IMETHOD GetIsSelfSigned(bool *aIsSelfSigned) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSelfSigned(aIsSelfSigned); } \
  NS_IMETHOD GetAllTokenNames(uint32_t *length, PRUnichar * **tokenNames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllTokenNames(length, tokenNames); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsX509Cert3 : public nsIX509Cert3
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIX509CERT3

  nsX509Cert3();

private:
  ~nsX509Cert3();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsX509Cert3, nsIX509Cert3)

nsX509Cert3::nsX509Cert3()
{
  /* member initializers and constructor code */
}

nsX509Cert3::~nsX509Cert3()
{
  /* destructor code */
}

/* void requestUsagesArrayAsync (in nsICertVerificationListener cvl); */
NS_IMETHODIMP nsX509Cert3::RequestUsagesArrayAsync(nsICertVerificationListener *cvl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void exportAsCMS (in unsigned long chainMode, out unsigned long length, [array, size_is (length), retval] out octet data); */
NS_IMETHODIMP nsX509Cert3::ExportAsCMS(uint32_t chainMode, uint32_t *length, uint8_t **data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSelfSigned; */
NS_IMETHODIMP nsX509Cert3::GetIsSelfSigned(bool *aIsSelfSigned)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAllTokenNames (out unsigned long length, [array, size_is (length), retval] out wstring tokenNames); */
NS_IMETHODIMP nsX509Cert3::GetAllTokenNames(uint32_t *length, PRUnichar * **tokenNames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICertVerificationResult */
#define NS_ICERTVERIFICATIONRESULT_IID_STR "2fd0a785-9f2d-4327-8871-8c3e0783891d"

#define NS_ICERTVERIFICATIONRESULT_IID \
  {0x2fd0a785, 0x9f2d, 0x4327, \
    { 0x88, 0x71, 0x8c, 0x3e, 0x07, 0x83, 0x89, 0x1d }}

class NS_NO_VTABLE nsICertVerificationResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTVERIFICATIONRESULT_IID)

  /* void getUsagesArrayResult (out uint32_t verified, out uint32_t count, [array, size_is (count)] out wstring usages); */
  NS_IMETHOD GetUsagesArrayResult(uint32_t *verified, uint32_t *count, PRUnichar * **usages) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertVerificationResult, NS_ICERTVERIFICATIONRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTVERIFICATIONRESULT \
  NS_IMETHOD GetUsagesArrayResult(uint32_t *verified, uint32_t *count, PRUnichar * **usages); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTVERIFICATIONRESULT(_to) \
  NS_IMETHOD GetUsagesArrayResult(uint32_t *verified, uint32_t *count, PRUnichar * **usages) { return _to GetUsagesArrayResult(verified, count, usages); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTVERIFICATIONRESULT(_to) \
  NS_IMETHOD GetUsagesArrayResult(uint32_t *verified, uint32_t *count, PRUnichar * **usages) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsagesArrayResult(verified, count, usages); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertVerificationResult : public nsICertVerificationResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTVERIFICATIONRESULT

  nsCertVerificationResult();

private:
  ~nsCertVerificationResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCertVerificationResult, nsICertVerificationResult)

nsCertVerificationResult::nsCertVerificationResult()
{
  /* member initializers and constructor code */
}

nsCertVerificationResult::~nsCertVerificationResult()
{
  /* destructor code */
}

/* void getUsagesArrayResult (out uint32_t verified, out uint32_t count, [array, size_is (count)] out wstring usages); */
NS_IMETHODIMP nsCertVerificationResult::GetUsagesArrayResult(uint32_t *verified, uint32_t *count, PRUnichar * **usages)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICertVerificationListener */
#define NS_ICERTVERIFICATIONLISTENER_IID_STR "6684bce9-50db-48e1-81b7-98102bf81357"

#define NS_ICERTVERIFICATIONLISTENER_IID \
  {0x6684bce9, 0x50db, 0x48e1, \
    { 0x81, 0xb7, 0x98, 0x10, 0x2b, 0xf8, 0x13, 0x57 }}

class NS_NO_VTABLE nsICertVerificationListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTVERIFICATIONLISTENER_IID)

  /* void notify (in nsIX509Cert3 verifiedCert, in nsICertVerificationResult result); */
  NS_IMETHOD Notify(nsIX509Cert3 *verifiedCert, nsICertVerificationResult *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertVerificationListener, NS_ICERTVERIFICATIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTVERIFICATIONLISTENER \
  NS_IMETHOD Notify(nsIX509Cert3 *verifiedCert, nsICertVerificationResult *result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTVERIFICATIONLISTENER(_to) \
  NS_IMETHOD Notify(nsIX509Cert3 *verifiedCert, nsICertVerificationResult *result) { return _to Notify(verifiedCert, result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTVERIFICATIONLISTENER(_to) \
  NS_IMETHOD Notify(nsIX509Cert3 *verifiedCert, nsICertVerificationResult *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->Notify(verifiedCert, result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertVerificationListener : public nsICertVerificationListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTVERIFICATIONLISTENER

  nsCertVerificationListener();

private:
  ~nsCertVerificationListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCertVerificationListener, nsICertVerificationListener)

nsCertVerificationListener::nsCertVerificationListener()
{
  /* member initializers and constructor code */
}

nsCertVerificationListener::~nsCertVerificationListener()
{
  /* destructor code */
}

/* void notify (in nsIX509Cert3 verifiedCert, in nsICertVerificationResult result); */
NS_IMETHODIMP nsCertVerificationListener::Notify(nsIX509Cert3 *verifiedCert, nsICertVerificationResult *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIX509Cert3_h__ */
