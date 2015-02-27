/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUrlClassifierStreamUpdater.idl
 */

#ifndef __gen_nsIUrlClassifierStreamUpdater_h__
#define __gen_nsIUrlClassifierStreamUpdater_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIUrlClassifierDBService_h__
#include "nsIUrlClassifierDBService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIUrlClassifierStreamUpdater */
#define NS_IURLCLASSIFIERSTREAMUPDATER_IID_STR "79e6b710-ce68-4639-ac6b-7d293af424a1"

#define NS_IURLCLASSIFIERSTREAMUPDATER_IID \
  {0x79e6b710, 0xce68, 0x4639, \
    { 0xac, 0x6b, 0x7d, 0x29, 0x3a, 0xf4, 0x24, 0xa1 }}

class NS_NO_VTABLE nsIUrlClassifierStreamUpdater : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURLCLASSIFIERSTREAMUPDATER_IID)

  /* attribute ACString updateUrl; */
  NS_IMETHOD GetUpdateUrl(nsACString & aUpdateUrl) = 0;
  NS_IMETHOD SetUpdateUrl(const nsACString & aUpdateUrl) = 0;

  /* boolean downloadUpdates (in ACString aRequestTables, in ACString aRequestBody, in nsIUrlClassifierCallback aSuccessCallback, in nsIUrlClassifierCallback aUpdateErrorCallback, in nsIUrlClassifierCallback aDownloadErrorCallback); */
  NS_IMETHOD DownloadUpdates(const nsACString & aRequestTables, const nsACString & aRequestBody, nsIUrlClassifierCallback *aSuccessCallback, nsIUrlClassifierCallback *aUpdateErrorCallback, nsIUrlClassifierCallback *aDownloadErrorCallback, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUrlClassifierStreamUpdater, NS_IURLCLASSIFIERSTREAMUPDATER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURLCLASSIFIERSTREAMUPDATER \
  NS_IMETHOD GetUpdateUrl(nsACString & aUpdateUrl); \
  NS_IMETHOD SetUpdateUrl(const nsACString & aUpdateUrl); \
  NS_IMETHOD DownloadUpdates(const nsACString & aRequestTables, const nsACString & aRequestBody, nsIUrlClassifierCallback *aSuccessCallback, nsIUrlClassifierCallback *aUpdateErrorCallback, nsIUrlClassifierCallback *aDownloadErrorCallback, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURLCLASSIFIERSTREAMUPDATER(_to) \
  NS_IMETHOD GetUpdateUrl(nsACString & aUpdateUrl) { return _to GetUpdateUrl(aUpdateUrl); } \
  NS_IMETHOD SetUpdateUrl(const nsACString & aUpdateUrl) { return _to SetUpdateUrl(aUpdateUrl); } \
  NS_IMETHOD DownloadUpdates(const nsACString & aRequestTables, const nsACString & aRequestBody, nsIUrlClassifierCallback *aSuccessCallback, nsIUrlClassifierCallback *aUpdateErrorCallback, nsIUrlClassifierCallback *aDownloadErrorCallback, bool *_retval) { return _to DownloadUpdates(aRequestTables, aRequestBody, aSuccessCallback, aUpdateErrorCallback, aDownloadErrorCallback, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURLCLASSIFIERSTREAMUPDATER(_to) \
  NS_IMETHOD GetUpdateUrl(nsACString & aUpdateUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateUrl(aUpdateUrl); } \
  NS_IMETHOD SetUpdateUrl(const nsACString & aUpdateUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUpdateUrl(aUpdateUrl); } \
  NS_IMETHOD DownloadUpdates(const nsACString & aRequestTables, const nsACString & aRequestBody, nsIUrlClassifierCallback *aSuccessCallback, nsIUrlClassifierCallback *aUpdateErrorCallback, nsIUrlClassifierCallback *aDownloadErrorCallback, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->DownloadUpdates(aRequestTables, aRequestBody, aSuccessCallback, aUpdateErrorCallback, aDownloadErrorCallback, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUrlClassifierStreamUpdater : public nsIUrlClassifierStreamUpdater
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURLCLASSIFIERSTREAMUPDATER

  nsUrlClassifierStreamUpdater();

private:
  ~nsUrlClassifierStreamUpdater();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUrlClassifierStreamUpdater, nsIUrlClassifierStreamUpdater)

nsUrlClassifierStreamUpdater::nsUrlClassifierStreamUpdater()
{
  /* member initializers and constructor code */
}

nsUrlClassifierStreamUpdater::~nsUrlClassifierStreamUpdater()
{
  /* destructor code */
}

/* attribute ACString updateUrl; */
NS_IMETHODIMP nsUrlClassifierStreamUpdater::GetUpdateUrl(nsACString & aUpdateUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsUrlClassifierStreamUpdater::SetUpdateUrl(const nsACString & aUpdateUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean downloadUpdates (in ACString aRequestTables, in ACString aRequestBody, in nsIUrlClassifierCallback aSuccessCallback, in nsIUrlClassifierCallback aUpdateErrorCallback, in nsIUrlClassifierCallback aDownloadErrorCallback); */
NS_IMETHODIMP nsUrlClassifierStreamUpdater::DownloadUpdates(const nsACString & aRequestTables, const nsACString & aRequestBody, nsIUrlClassifierCallback *aSuccessCallback, nsIUrlClassifierCallback *aUpdateErrorCallback, nsIUrlClassifierCallback *aDownloadErrorCallback, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUrlClassifierStreamUpdater_h__ */
