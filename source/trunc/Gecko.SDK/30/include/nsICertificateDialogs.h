/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICertificateDialogs.idl
 */

#ifndef __gen_nsICertificateDialogs_h__
#define __gen_nsICertificateDialogs_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInterfaceRequestor; /* forward declaration */

class nsIX509Cert; /* forward declaration */


/* starting interface:    nsICertificateDialogs */
#define NS_ICERTIFICATEDIALOGS_IID_STR "da871dab-f69e-4173-ab26-99fcd47b0e85"

#define NS_ICERTIFICATEDIALOGS_IID \
  {0xda871dab, 0xf69e, 0x4173, \
    { 0xab, 0x26, 0x99, 0xfc, 0xd4, 0x7b, 0x0e, 0x85 }}

class NS_NO_VTABLE nsICertificateDialogs : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICERTIFICATEDIALOGS_IID)

  /* boolean confirmDownloadCACert (in nsIInterfaceRequestor ctx, in nsIX509Cert cert, out unsigned long trust); */
  NS_IMETHOD ConfirmDownloadCACert(nsIInterfaceRequestor *ctx, nsIX509Cert *cert, uint32_t *trust, bool *_retval) = 0;

  /* void notifyCACertExists (in nsIInterfaceRequestor ctx); */
  NS_IMETHOD NotifyCACertExists(nsIInterfaceRequestor *ctx) = 0;

  /* boolean setPKCS12FilePassword (in nsIInterfaceRequestor ctx, out AString password); */
  NS_IMETHOD SetPKCS12FilePassword(nsIInterfaceRequestor *ctx, nsAString & password, bool *_retval) = 0;

  /* boolean getPKCS12FilePassword (in nsIInterfaceRequestor ctx, out AString password); */
  NS_IMETHOD GetPKCS12FilePassword(nsIInterfaceRequestor *ctx, nsAString & password, bool *_retval) = 0;

  /* void viewCert (in nsIInterfaceRequestor ctx, in nsIX509Cert cert); */
  NS_IMETHOD ViewCert(nsIInterfaceRequestor *ctx, nsIX509Cert *cert) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICertificateDialogs, NS_ICERTIFICATEDIALOGS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICERTIFICATEDIALOGS \
  NS_IMETHOD ConfirmDownloadCACert(nsIInterfaceRequestor *ctx, nsIX509Cert *cert, uint32_t *trust, bool *_retval); \
  NS_IMETHOD NotifyCACertExists(nsIInterfaceRequestor *ctx); \
  NS_IMETHOD SetPKCS12FilePassword(nsIInterfaceRequestor *ctx, nsAString & password, bool *_retval); \
  NS_IMETHOD GetPKCS12FilePassword(nsIInterfaceRequestor *ctx, nsAString & password, bool *_retval); \
  NS_IMETHOD ViewCert(nsIInterfaceRequestor *ctx, nsIX509Cert *cert); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICERTIFICATEDIALOGS(_to) \
  NS_IMETHOD ConfirmDownloadCACert(nsIInterfaceRequestor *ctx, nsIX509Cert *cert, uint32_t *trust, bool *_retval) { return _to ConfirmDownloadCACert(ctx, cert, trust, _retval); } \
  NS_IMETHOD NotifyCACertExists(nsIInterfaceRequestor *ctx) { return _to NotifyCACertExists(ctx); } \
  NS_IMETHOD SetPKCS12FilePassword(nsIInterfaceRequestor *ctx, nsAString & password, bool *_retval) { return _to SetPKCS12FilePassword(ctx, password, _retval); } \
  NS_IMETHOD GetPKCS12FilePassword(nsIInterfaceRequestor *ctx, nsAString & password, bool *_retval) { return _to GetPKCS12FilePassword(ctx, password, _retval); } \
  NS_IMETHOD ViewCert(nsIInterfaceRequestor *ctx, nsIX509Cert *cert) { return _to ViewCert(ctx, cert); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICERTIFICATEDIALOGS(_to) \
  NS_IMETHOD ConfirmDownloadCACert(nsIInterfaceRequestor *ctx, nsIX509Cert *cert, uint32_t *trust, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConfirmDownloadCACert(ctx, cert, trust, _retval); } \
  NS_IMETHOD NotifyCACertExists(nsIInterfaceRequestor *ctx) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCACertExists(ctx); } \
  NS_IMETHOD SetPKCS12FilePassword(nsIInterfaceRequestor *ctx, nsAString & password, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPKCS12FilePassword(ctx, password, _retval); } \
  NS_IMETHOD GetPKCS12FilePassword(nsIInterfaceRequestor *ctx, nsAString & password, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPKCS12FilePassword(ctx, password, _retval); } \
  NS_IMETHOD ViewCert(nsIInterfaceRequestor *ctx, nsIX509Cert *cert) { return !_to ? NS_ERROR_NULL_POINTER : _to->ViewCert(ctx, cert); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCertificateDialogs : public nsICertificateDialogs
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICERTIFICATEDIALOGS

  nsCertificateDialogs();

private:
  ~nsCertificateDialogs();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCertificateDialogs, nsICertificateDialogs)

nsCertificateDialogs::nsCertificateDialogs()
{
  /* member initializers and constructor code */
}

nsCertificateDialogs::~nsCertificateDialogs()
{
  /* destructor code */
}

/* boolean confirmDownloadCACert (in nsIInterfaceRequestor ctx, in nsIX509Cert cert, out unsigned long trust); */
NS_IMETHODIMP nsCertificateDialogs::ConfirmDownloadCACert(nsIInterfaceRequestor *ctx, nsIX509Cert *cert, uint32_t *trust, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyCACertExists (in nsIInterfaceRequestor ctx); */
NS_IMETHODIMP nsCertificateDialogs::NotifyCACertExists(nsIInterfaceRequestor *ctx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean setPKCS12FilePassword (in nsIInterfaceRequestor ctx, out AString password); */
NS_IMETHODIMP nsCertificateDialogs::SetPKCS12FilePassword(nsIInterfaceRequestor *ctx, nsAString & password, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getPKCS12FilePassword (in nsIInterfaceRequestor ctx, out AString password); */
NS_IMETHODIMP nsCertificateDialogs::GetPKCS12FilePassword(nsIInterfaceRequestor *ctx, nsAString & password, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void viewCert (in nsIInterfaceRequestor ctx, in nsIX509Cert cert); */
NS_IMETHODIMP nsCertificateDialogs::ViewCert(nsIInterfaceRequestor *ctx, nsIX509Cert *cert)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_CERTIFICATEDIALOGS_CONTRACTID "@mozilla.org/nsCertificateDialogs;1"

#endif /* __gen_nsICertificateDialogs_h__ */
