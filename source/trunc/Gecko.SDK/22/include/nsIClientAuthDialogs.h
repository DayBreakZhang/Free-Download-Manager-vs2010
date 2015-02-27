/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/security/manager/ssl/public/nsIClientAuthDialogs.idl
 */

#ifndef __gen_nsIClientAuthDialogs_h__
#define __gen_nsIClientAuthDialogs_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */


/* starting interface:    nsIClientAuthDialogs */
#define NS_ICLIENTAUTHDIALOGS_IID_STR "fa4c7520-1433-11d5-ba24-00108303b117"

#define NS_ICLIENTAUTHDIALOGS_IID \
  {0xfa4c7520, 0x1433, 0x11d5, \
    { 0xba, 0x24, 0x00, 0x10, 0x83, 0x03, 0xb1, 0x17 }}

class NS_NO_VTABLE nsIClientAuthDialogs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLIENTAUTHDIALOGS_IID)

  /* void ChooseCertificate (in nsIInterfaceRequestor ctx, in wstring cn, in wstring organization, in wstring issuer, [array, size_is (count)] in wstring certNickList, [array, size_is (count)] in wstring certDetailsList, in unsigned long count, out long selectedIndex, out boolean canceled); */
  NS_IMETHOD ChooseCertificate(nsIInterfaceRequestor *ctx, const PRUnichar * cn, const PRUnichar * organization, const PRUnichar * issuer, const PRUnichar * *certNickList, const PRUnichar * *certDetailsList, uint32_t count, int32_t *selectedIndex, bool *canceled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClientAuthDialogs, NS_ICLIENTAUTHDIALOGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLIENTAUTHDIALOGS \
  NS_IMETHOD ChooseCertificate(nsIInterfaceRequestor *ctx, const PRUnichar * cn, const PRUnichar * organization, const PRUnichar * issuer, const PRUnichar * *certNickList, const PRUnichar * *certDetailsList, uint32_t count, int32_t *selectedIndex, bool *canceled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLIENTAUTHDIALOGS(_to) \
  NS_IMETHOD ChooseCertificate(nsIInterfaceRequestor *ctx, const PRUnichar * cn, const PRUnichar * organization, const PRUnichar * issuer, const PRUnichar * *certNickList, const PRUnichar * *certDetailsList, uint32_t count, int32_t *selectedIndex, bool *canceled) { return _to ChooseCertificate(ctx, cn, organization, issuer, certNickList, certDetailsList, count, selectedIndex, canceled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLIENTAUTHDIALOGS(_to) \
  NS_IMETHOD ChooseCertificate(nsIInterfaceRequestor *ctx, const PRUnichar * cn, const PRUnichar * organization, const PRUnichar * issuer, const PRUnichar * *certNickList, const PRUnichar * *certDetailsList, uint32_t count, int32_t *selectedIndex, bool *canceled) { return !_to ? NS_ERROR_NULL_POINTER : _to->ChooseCertificate(ctx, cn, organization, issuer, certNickList, certDetailsList, count, selectedIndex, canceled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClientAuthDialogs : public nsIClientAuthDialogs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLIENTAUTHDIALOGS

  nsClientAuthDialogs();

private:
  ~nsClientAuthDialogs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClientAuthDialogs, nsIClientAuthDialogs)

nsClientAuthDialogs::nsClientAuthDialogs()
{
  /* member initializers and constructor code */
}

nsClientAuthDialogs::~nsClientAuthDialogs()
{
  /* destructor code */
}

/* void ChooseCertificate (in nsIInterfaceRequestor ctx, in wstring cn, in wstring organization, in wstring issuer, [array, size_is (count)] in wstring certNickList, [array, size_is (count)] in wstring certDetailsList, in unsigned long count, out long selectedIndex, out boolean canceled); */
NS_IMETHODIMP nsClientAuthDialogs::ChooseCertificate(nsIInterfaceRequestor *ctx, const PRUnichar * cn, const PRUnichar * organization, const PRUnichar * issuer, const PRUnichar * *certNickList, const PRUnichar * *certDetailsList, uint32_t count, int32_t *selectedIndex, bool *canceled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIClientAuthUserDecision */
#define NS_ICLIENTAUTHUSERDECISION_IID_STR "95c4373e-bdd4-4a63-b431-f5b000367721"

#define NS_ICLIENTAUTHUSERDECISION_IID \
  {0x95c4373e, 0xbdd4, 0x4a63, \
    { 0xb4, 0x31, 0xf5, 0xb0, 0x00, 0x36, 0x77, 0x21 }}

class NS_NO_VTABLE nsIClientAuthUserDecision : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLIENTAUTHUSERDECISION_IID)

  /* attribute boolean rememberClientAuthCertificate; */
  NS_IMETHOD GetRememberClientAuthCertificate(bool *aRememberClientAuthCertificate) = 0;
  NS_IMETHOD SetRememberClientAuthCertificate(bool aRememberClientAuthCertificate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClientAuthUserDecision, NS_ICLIENTAUTHUSERDECISION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLIENTAUTHUSERDECISION \
  NS_IMETHOD GetRememberClientAuthCertificate(bool *aRememberClientAuthCertificate); \
  NS_IMETHOD SetRememberClientAuthCertificate(bool aRememberClientAuthCertificate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLIENTAUTHUSERDECISION(_to) \
  NS_IMETHOD GetRememberClientAuthCertificate(bool *aRememberClientAuthCertificate) { return _to GetRememberClientAuthCertificate(aRememberClientAuthCertificate); } \
  NS_IMETHOD SetRememberClientAuthCertificate(bool aRememberClientAuthCertificate) { return _to SetRememberClientAuthCertificate(aRememberClientAuthCertificate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLIENTAUTHUSERDECISION(_to) \
  NS_IMETHOD GetRememberClientAuthCertificate(bool *aRememberClientAuthCertificate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRememberClientAuthCertificate(aRememberClientAuthCertificate); } \
  NS_IMETHOD SetRememberClientAuthCertificate(bool aRememberClientAuthCertificate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRememberClientAuthCertificate(aRememberClientAuthCertificate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClientAuthUserDecision : public nsIClientAuthUserDecision
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLIENTAUTHUSERDECISION

  nsClientAuthUserDecision();

private:
  ~nsClientAuthUserDecision();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClientAuthUserDecision, nsIClientAuthUserDecision)

nsClientAuthUserDecision::nsClientAuthUserDecision()
{
  /* member initializers and constructor code */
}

nsClientAuthUserDecision::~nsClientAuthUserDecision()
{
  /* destructor code */
}

/* attribute boolean rememberClientAuthCertificate; */
NS_IMETHODIMP nsClientAuthUserDecision::GetRememberClientAuthCertificate(bool *aRememberClientAuthCertificate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsClientAuthUserDecision::SetRememberClientAuthCertificate(bool aRememberClientAuthCertificate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CLIENTAUTHDIALOGS_CONTRACTID "@mozilla.org/nsClientAuthDialogs;1"

#endif /* __gen_nsIClientAuthDialogs_h__ */
