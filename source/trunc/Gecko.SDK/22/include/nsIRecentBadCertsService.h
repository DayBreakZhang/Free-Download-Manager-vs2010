/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/security/manager/ssl/public/nsIRecentBadCertsService.idl
 */

#ifndef __gen_nsIRecentBadCertsService_h__
#define __gen_nsIRecentBadCertsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIX509Cert; /* forward declaration */

class nsISSLStatus; /* forward declaration */

#define NS_RECENTBADCERTS_CONTRACTID "@mozilla.org/security/recentbadcerts;1"

/* starting interface:    nsIRecentBadCerts */
#define NS_IRECENTBADCERTS_IID_STR "0fed7784-d152-44d6-95a7-67a59024de0f"

#define NS_IRECENTBADCERTS_IID \
  {0x0fed7784, 0xd152, 0x44d6, \
    { 0x95, 0xa7, 0x67, 0xa5, 0x90, 0x24, 0xde, 0x0f }}

class NS_NO_VTABLE nsIRecentBadCerts : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRECENTBADCERTS_IID)

  /* nsISSLStatus getRecentBadCert (in AString aHostNameWithPort); */
  NS_IMETHOD GetRecentBadCert(const nsAString & aHostNameWithPort, nsISSLStatus * *_retval) = 0;

  /* void addBadCert (in AString aHostNameWithPort, in nsISSLStatus aStatus); */
  NS_IMETHOD AddBadCert(const nsAString & aHostNameWithPort, nsISSLStatus *aStatus) = 0;

  /* void resetStoredCerts (); */
  NS_IMETHOD ResetStoredCerts(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRecentBadCerts, NS_IRECENTBADCERTS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRECENTBADCERTS \
  NS_IMETHOD GetRecentBadCert(const nsAString & aHostNameWithPort, nsISSLStatus * *_retval); \
  NS_IMETHOD AddBadCert(const nsAString & aHostNameWithPort, nsISSLStatus *aStatus); \
  NS_IMETHOD ResetStoredCerts(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRECENTBADCERTS(_to) \
  NS_IMETHOD GetRecentBadCert(const nsAString & aHostNameWithPort, nsISSLStatus * *_retval) { return _to GetRecentBadCert(aHostNameWithPort, _retval); } \
  NS_IMETHOD AddBadCert(const nsAString & aHostNameWithPort, nsISSLStatus *aStatus) { return _to AddBadCert(aHostNameWithPort, aStatus); } \
  NS_IMETHOD ResetStoredCerts(void) { return _to ResetStoredCerts(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRECENTBADCERTS(_to) \
  NS_IMETHOD GetRecentBadCert(const nsAString & aHostNameWithPort, nsISSLStatus * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRecentBadCert(aHostNameWithPort, _retval); } \
  NS_IMETHOD AddBadCert(const nsAString & aHostNameWithPort, nsISSLStatus *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddBadCert(aHostNameWithPort, aStatus); } \
  NS_IMETHOD ResetStoredCerts(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetStoredCerts(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRecentBadCerts : public nsIRecentBadCerts
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRECENTBADCERTS

  nsRecentBadCerts();

private:
  ~nsRecentBadCerts();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRecentBadCerts, nsIRecentBadCerts)

nsRecentBadCerts::nsRecentBadCerts()
{
  /* member initializers and constructor code */
}

nsRecentBadCerts::~nsRecentBadCerts()
{
  /* destructor code */
}

/* nsISSLStatus getRecentBadCert (in AString aHostNameWithPort); */
NS_IMETHODIMP nsRecentBadCerts::GetRecentBadCert(const nsAString & aHostNameWithPort, nsISSLStatus * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addBadCert (in AString aHostNameWithPort, in nsISSLStatus aStatus); */
NS_IMETHODIMP nsRecentBadCerts::AddBadCert(const nsAString & aHostNameWithPort, nsISSLStatus *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetStoredCerts (); */
NS_IMETHODIMP nsRecentBadCerts::ResetStoredCerts()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRecentBadCertsService_h__ */
