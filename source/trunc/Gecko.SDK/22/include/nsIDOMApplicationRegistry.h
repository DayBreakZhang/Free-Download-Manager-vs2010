/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/apps/nsIDOMApplicationRegistry.idl
 */

#ifndef __gen_nsIDOMApplicationRegistry_h__
#define __gen_nsIDOMApplicationRegistry_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMRequest; /* forward declaration */

class nsIDOMDOMError; /* forward declaration */


/* starting interface:    mozIDOMApplication */
#define MOZIDOMAPPLICATION_IID_STR "d89870fe-5ba3-11e2-a5d2-cfa1d3f6e5f4"

#define MOZIDOMAPPLICATION_IID \
  {0xd89870fe, 0x5ba3, 0x11e2, \
    { 0xa5, 0xd2, 0xcf, 0xa1, 0xd3, 0xf6, 0xe5, 0xf4 }}

class NS_NO_VTABLE mozIDOMApplication : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIDOMAPPLICATION_IID)

  /* readonly attribute jsval manifest; */
  NS_IMETHOD GetManifest(JS::Value *aManifest) = 0;

  /* readonly attribute jsval updateManifest; */
  NS_IMETHOD GetUpdateManifest(JS::Value *aUpdateManifest) = 0;

  /* readonly attribute DOMString manifestURL; */
  NS_IMETHOD GetManifestURL(nsAString & aManifestURL) = 0;

  /* readonly attribute jsval receipts; */
  NS_IMETHOD GetReceipts(JS::Value *aReceipts) = 0;

  /* readonly attribute DOMString origin; */
  NS_IMETHOD GetOrigin(nsAString & aOrigin) = 0;

  /* readonly attribute DOMString installOrigin; */
  NS_IMETHOD GetInstallOrigin(nsAString & aInstallOrigin) = 0;

  /* readonly attribute unsigned long long installTime; */
  NS_IMETHOD GetInstallTime(uint64_t *aInstallTime) = 0;

  /* readonly attribute boolean removable; */
  NS_IMETHOD GetRemovable(bool *aRemovable) = 0;

  /* readonly attribute double progress; */
  NS_IMETHOD GetProgress(double *aProgress) = 0;

  /* readonly attribute DOMString installState; */
  NS_IMETHOD GetInstallState(nsAString & aInstallState) = 0;

  /* attribute nsIDOMEventListener onprogress; */
  NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) = 0;
  NS_IMETHOD SetOnprogress(nsIDOMEventListener *aOnprogress) = 0;

  /* readonly attribute unsigned long long lastUpdateCheck; */
  NS_IMETHOD GetLastUpdateCheck(uint64_t *aLastUpdateCheck) = 0;

  /* readonly attribute unsigned long long updateTime; */
  NS_IMETHOD GetUpdateTime(uint64_t *aUpdateTime) = 0;

  /* nsIDOMDOMRequest checkForUpdate (); */
  NS_IMETHOD CheckForUpdate(nsIDOMDOMRequest * *_retval) = 0;

  /* readonly attribute boolean downloadAvailable; */
  NS_IMETHOD GetDownloadAvailable(bool *aDownloadAvailable) = 0;

  /* readonly attribute boolean downloading; */
  NS_IMETHOD GetDownloading(bool *aDownloading) = 0;

  /* readonly attribute boolean readyToApplyDownload; */
  NS_IMETHOD GetReadyToApplyDownload(bool *aReadyToApplyDownload) = 0;

  /* readonly attribute long downloadSize; */
  NS_IMETHOD GetDownloadSize(int32_t *aDownloadSize) = 0;

  /* readonly attribute nsIDOMDOMError downloadError; */
  NS_IMETHOD GetDownloadError(nsIDOMDOMError * *aDownloadError) = 0;

  /* attribute nsIDOMEventListener ondownloadsuccess; */
  NS_IMETHOD GetOndownloadsuccess(nsIDOMEventListener * *aOndownloadsuccess) = 0;
  NS_IMETHOD SetOndownloadsuccess(nsIDOMEventListener *aOndownloadsuccess) = 0;

  /* attribute nsIDOMEventListener ondownloaderror; */
  NS_IMETHOD GetOndownloaderror(nsIDOMEventListener * *aOndownloaderror) = 0;
  NS_IMETHOD SetOndownloaderror(nsIDOMEventListener *aOndownloaderror) = 0;

  /* attribute nsIDOMEventListener ondownloadavailable; */
  NS_IMETHOD GetOndownloadavailable(nsIDOMEventListener * *aOndownloadavailable) = 0;
  NS_IMETHOD SetOndownloadavailable(nsIDOMEventListener *aOndownloadavailable) = 0;

  /* attribute nsIDOMEventListener ondownloadapplied; */
  NS_IMETHOD GetOndownloadapplied(nsIDOMEventListener * *aOndownloadapplied) = 0;
  NS_IMETHOD SetOndownloadapplied(nsIDOMEventListener *aOndownloadapplied) = 0;

  /* void download (); */
  NS_IMETHOD Download(void) = 0;

  /* void cancelDownload (); */
  NS_IMETHOD CancelDownload(void) = 0;

  /* nsIDOMDOMRequest launch ([optional] in DOMString startPoint); */
  NS_IMETHOD Launch(const nsAString & startPoint, nsIDOMDOMRequest * *_retval) = 0;

  /* void clearBrowserData (); */
  NS_IMETHOD ClearBrowserData(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIDOMApplication, MOZIDOMAPPLICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIDOMAPPLICATION \
  NS_IMETHOD GetManifest(JS::Value *aManifest); \
  NS_IMETHOD GetUpdateManifest(JS::Value *aUpdateManifest); \
  NS_IMETHOD GetManifestURL(nsAString & aManifestURL); \
  NS_IMETHOD GetReceipts(JS::Value *aReceipts); \
  NS_IMETHOD GetOrigin(nsAString & aOrigin); \
  NS_IMETHOD GetInstallOrigin(nsAString & aInstallOrigin); \
  NS_IMETHOD GetInstallTime(uint64_t *aInstallTime); \
  NS_IMETHOD GetRemovable(bool *aRemovable); \
  NS_IMETHOD GetProgress(double *aProgress); \
  NS_IMETHOD GetInstallState(nsAString & aInstallState); \
  NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress); \
  NS_IMETHOD SetOnprogress(nsIDOMEventListener *aOnprogress); \
  NS_IMETHOD GetLastUpdateCheck(uint64_t *aLastUpdateCheck); \
  NS_IMETHOD GetUpdateTime(uint64_t *aUpdateTime); \
  NS_IMETHOD CheckForUpdate(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetDownloadAvailable(bool *aDownloadAvailable); \
  NS_IMETHOD GetDownloading(bool *aDownloading); \
  NS_IMETHOD GetReadyToApplyDownload(bool *aReadyToApplyDownload); \
  NS_IMETHOD GetDownloadSize(int32_t *aDownloadSize); \
  NS_IMETHOD GetDownloadError(nsIDOMDOMError * *aDownloadError); \
  NS_IMETHOD GetOndownloadsuccess(nsIDOMEventListener * *aOndownloadsuccess); \
  NS_IMETHOD SetOndownloadsuccess(nsIDOMEventListener *aOndownloadsuccess); \
  NS_IMETHOD GetOndownloaderror(nsIDOMEventListener * *aOndownloaderror); \
  NS_IMETHOD SetOndownloaderror(nsIDOMEventListener *aOndownloaderror); \
  NS_IMETHOD GetOndownloadavailable(nsIDOMEventListener * *aOndownloadavailable); \
  NS_IMETHOD SetOndownloadavailable(nsIDOMEventListener *aOndownloadavailable); \
  NS_IMETHOD GetOndownloadapplied(nsIDOMEventListener * *aOndownloadapplied); \
  NS_IMETHOD SetOndownloadapplied(nsIDOMEventListener *aOndownloadapplied); \
  NS_IMETHOD Download(void); \
  NS_IMETHOD CancelDownload(void); \
  NS_IMETHOD Launch(const nsAString & startPoint, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD ClearBrowserData(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIDOMAPPLICATION(_to) \
  NS_IMETHOD GetManifest(JS::Value *aManifest) { return _to GetManifest(aManifest); } \
  NS_IMETHOD GetUpdateManifest(JS::Value *aUpdateManifest) { return _to GetUpdateManifest(aUpdateManifest); } \
  NS_IMETHOD GetManifestURL(nsAString & aManifestURL) { return _to GetManifestURL(aManifestURL); } \
  NS_IMETHOD GetReceipts(JS::Value *aReceipts) { return _to GetReceipts(aReceipts); } \
  NS_IMETHOD GetOrigin(nsAString & aOrigin) { return _to GetOrigin(aOrigin); } \
  NS_IMETHOD GetInstallOrigin(nsAString & aInstallOrigin) { return _to GetInstallOrigin(aInstallOrigin); } \
  NS_IMETHOD GetInstallTime(uint64_t *aInstallTime) { return _to GetInstallTime(aInstallTime); } \
  NS_IMETHOD GetRemovable(bool *aRemovable) { return _to GetRemovable(aRemovable); } \
  NS_IMETHOD GetProgress(double *aProgress) { return _to GetProgress(aProgress); } \
  NS_IMETHOD GetInstallState(nsAString & aInstallState) { return _to GetInstallState(aInstallState); } \
  NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) { return _to GetOnprogress(aOnprogress); } \
  NS_IMETHOD SetOnprogress(nsIDOMEventListener *aOnprogress) { return _to SetOnprogress(aOnprogress); } \
  NS_IMETHOD GetLastUpdateCheck(uint64_t *aLastUpdateCheck) { return _to GetLastUpdateCheck(aLastUpdateCheck); } \
  NS_IMETHOD GetUpdateTime(uint64_t *aUpdateTime) { return _to GetUpdateTime(aUpdateTime); } \
  NS_IMETHOD CheckForUpdate(nsIDOMDOMRequest * *_retval) { return _to CheckForUpdate(_retval); } \
  NS_IMETHOD GetDownloadAvailable(bool *aDownloadAvailable) { return _to GetDownloadAvailable(aDownloadAvailable); } \
  NS_IMETHOD GetDownloading(bool *aDownloading) { return _to GetDownloading(aDownloading); } \
  NS_IMETHOD GetReadyToApplyDownload(bool *aReadyToApplyDownload) { return _to GetReadyToApplyDownload(aReadyToApplyDownload); } \
  NS_IMETHOD GetDownloadSize(int32_t *aDownloadSize) { return _to GetDownloadSize(aDownloadSize); } \
  NS_IMETHOD GetDownloadError(nsIDOMDOMError * *aDownloadError) { return _to GetDownloadError(aDownloadError); } \
  NS_IMETHOD GetOndownloadsuccess(nsIDOMEventListener * *aOndownloadsuccess) { return _to GetOndownloadsuccess(aOndownloadsuccess); } \
  NS_IMETHOD SetOndownloadsuccess(nsIDOMEventListener *aOndownloadsuccess) { return _to SetOndownloadsuccess(aOndownloadsuccess); } \
  NS_IMETHOD GetOndownloaderror(nsIDOMEventListener * *aOndownloaderror) { return _to GetOndownloaderror(aOndownloaderror); } \
  NS_IMETHOD SetOndownloaderror(nsIDOMEventListener *aOndownloaderror) { return _to SetOndownloaderror(aOndownloaderror); } \
  NS_IMETHOD GetOndownloadavailable(nsIDOMEventListener * *aOndownloadavailable) { return _to GetOndownloadavailable(aOndownloadavailable); } \
  NS_IMETHOD SetOndownloadavailable(nsIDOMEventListener *aOndownloadavailable) { return _to SetOndownloadavailable(aOndownloadavailable); } \
  NS_IMETHOD GetOndownloadapplied(nsIDOMEventListener * *aOndownloadapplied) { return _to GetOndownloadapplied(aOndownloadapplied); } \
  NS_IMETHOD SetOndownloadapplied(nsIDOMEventListener *aOndownloadapplied) { return _to SetOndownloadapplied(aOndownloadapplied); } \
  NS_IMETHOD Download(void) { return _to Download(); } \
  NS_IMETHOD CancelDownload(void) { return _to CancelDownload(); } \
  NS_IMETHOD Launch(const nsAString & startPoint, nsIDOMDOMRequest * *_retval) { return _to Launch(startPoint, _retval); } \
  NS_IMETHOD ClearBrowserData(void) { return _to ClearBrowserData(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIDOMAPPLICATION(_to) \
  NS_IMETHOD GetManifest(JS::Value *aManifest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifest(aManifest); } \
  NS_IMETHOD GetUpdateManifest(JS::Value *aUpdateManifest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateManifest(aUpdateManifest); } \
  NS_IMETHOD GetManifestURL(nsAString & aManifestURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestURL(aManifestURL); } \
  NS_IMETHOD GetReceipts(JS::Value *aReceipts) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReceipts(aReceipts); } \
  NS_IMETHOD GetOrigin(nsAString & aOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrigin(aOrigin); } \
  NS_IMETHOD GetInstallOrigin(nsAString & aInstallOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstallOrigin(aInstallOrigin); } \
  NS_IMETHOD GetInstallTime(uint64_t *aInstallTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstallTime(aInstallTime); } \
  NS_IMETHOD GetRemovable(bool *aRemovable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemovable(aRemovable); } \
  NS_IMETHOD GetProgress(double *aProgress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProgress(aProgress); } \
  NS_IMETHOD GetInstallState(nsAString & aInstallState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstallState(aInstallState); } \
  NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnprogress(aOnprogress); } \
  NS_IMETHOD SetOnprogress(nsIDOMEventListener *aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnprogress(aOnprogress); } \
  NS_IMETHOD GetLastUpdateCheck(uint64_t *aLastUpdateCheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastUpdateCheck(aLastUpdateCheck); } \
  NS_IMETHOD GetUpdateTime(uint64_t *aUpdateTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUpdateTime(aUpdateTime); } \
  NS_IMETHOD CheckForUpdate(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForUpdate(_retval); } \
  NS_IMETHOD GetDownloadAvailable(bool *aDownloadAvailable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownloadAvailable(aDownloadAvailable); } \
  NS_IMETHOD GetDownloading(bool *aDownloading) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownloading(aDownloading); } \
  NS_IMETHOD GetReadyToApplyDownload(bool *aReadyToApplyDownload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyToApplyDownload(aReadyToApplyDownload); } \
  NS_IMETHOD GetDownloadSize(int32_t *aDownloadSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownloadSize(aDownloadSize); } \
  NS_IMETHOD GetDownloadError(nsIDOMDOMError * *aDownloadError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownloadError(aDownloadError); } \
  NS_IMETHOD GetOndownloadsuccess(nsIDOMEventListener * *aOndownloadsuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndownloadsuccess(aOndownloadsuccess); } \
  NS_IMETHOD SetOndownloadsuccess(nsIDOMEventListener *aOndownloadsuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndownloadsuccess(aOndownloadsuccess); } \
  NS_IMETHOD GetOndownloaderror(nsIDOMEventListener * *aOndownloaderror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndownloaderror(aOndownloaderror); } \
  NS_IMETHOD SetOndownloaderror(nsIDOMEventListener *aOndownloaderror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndownloaderror(aOndownloaderror); } \
  NS_IMETHOD GetOndownloadavailable(nsIDOMEventListener * *aOndownloadavailable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndownloadavailable(aOndownloadavailable); } \
  NS_IMETHOD SetOndownloadavailable(nsIDOMEventListener *aOndownloadavailable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndownloadavailable(aOndownloadavailable); } \
  NS_IMETHOD GetOndownloadapplied(nsIDOMEventListener * *aOndownloadapplied) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndownloadapplied(aOndownloadapplied); } \
  NS_IMETHOD SetOndownloadapplied(nsIDOMEventListener *aOndownloadapplied) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndownloadapplied(aOndownloadapplied); } \
  NS_IMETHOD Download(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Download(); } \
  NS_IMETHOD CancelDownload(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelDownload(); } \
  NS_IMETHOD Launch(const nsAString & startPoint, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Launch(startPoint, _retval); } \
  NS_IMETHOD ClearBrowserData(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearBrowserData(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIDOMApplication
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIDOMAPPLICATION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIDOMApplication)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute jsval manifest; */
NS_IMETHODIMP _MYCLASS_::GetManifest(JS::Value *aManifest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval updateManifest; */
NS_IMETHODIMP _MYCLASS_::GetUpdateManifest(JS::Value *aUpdateManifest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString manifestURL; */
NS_IMETHODIMP _MYCLASS_::GetManifestURL(nsAString & aManifestURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval receipts; */
NS_IMETHODIMP _MYCLASS_::GetReceipts(JS::Value *aReceipts)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString origin; */
NS_IMETHODIMP _MYCLASS_::GetOrigin(nsAString & aOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString installOrigin; */
NS_IMETHODIMP _MYCLASS_::GetInstallOrigin(nsAString & aInstallOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long installTime; */
NS_IMETHODIMP _MYCLASS_::GetInstallTime(uint64_t *aInstallTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean removable; */
NS_IMETHODIMP _MYCLASS_::GetRemovable(bool *aRemovable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double progress; */
NS_IMETHODIMP _MYCLASS_::GetProgress(double *aProgress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString installState; */
NS_IMETHODIMP _MYCLASS_::GetInstallState(nsAString & aInstallState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onprogress; */
NS_IMETHODIMP _MYCLASS_::GetOnprogress(nsIDOMEventListener * *aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOnprogress(nsIDOMEventListener *aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long lastUpdateCheck; */
NS_IMETHODIMP _MYCLASS_::GetLastUpdateCheck(uint64_t *aLastUpdateCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long updateTime; */
NS_IMETHODIMP _MYCLASS_::GetUpdateTime(uint64_t *aUpdateTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest checkForUpdate (); */
NS_IMETHODIMP _MYCLASS_::CheckForUpdate(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean downloadAvailable; */
NS_IMETHODIMP _MYCLASS_::GetDownloadAvailable(bool *aDownloadAvailable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean downloading; */
NS_IMETHODIMP _MYCLASS_::GetDownloading(bool *aDownloading)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean readyToApplyDownload; */
NS_IMETHODIMP _MYCLASS_::GetReadyToApplyDownload(bool *aReadyToApplyDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long downloadSize; */
NS_IMETHODIMP _MYCLASS_::GetDownloadSize(int32_t *aDownloadSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMError downloadError; */
NS_IMETHODIMP _MYCLASS_::GetDownloadError(nsIDOMDOMError * *aDownloadError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener ondownloadsuccess; */
NS_IMETHODIMP _MYCLASS_::GetOndownloadsuccess(nsIDOMEventListener * *aOndownloadsuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOndownloadsuccess(nsIDOMEventListener *aOndownloadsuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener ondownloaderror; */
NS_IMETHODIMP _MYCLASS_::GetOndownloaderror(nsIDOMEventListener * *aOndownloaderror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOndownloaderror(nsIDOMEventListener *aOndownloaderror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener ondownloadavailable; */
NS_IMETHODIMP _MYCLASS_::GetOndownloadavailable(nsIDOMEventListener * *aOndownloadavailable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOndownloadavailable(nsIDOMEventListener *aOndownloadavailable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener ondownloadapplied; */
NS_IMETHODIMP _MYCLASS_::GetOndownloadapplied(nsIDOMEventListener * *aOndownloadapplied)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOndownloadapplied(nsIDOMEventListener *aOndownloadapplied)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void download (); */
NS_IMETHODIMP _MYCLASS_::Download()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelDownload (); */
NS_IMETHODIMP _MYCLASS_::CancelDownload()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest launch ([optional] in DOMString startPoint); */
NS_IMETHODIMP _MYCLASS_::Launch(const nsAString & startPoint, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearBrowserData (); */
NS_IMETHODIMP _MYCLASS_::ClearBrowserData()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIDOMApplicationMgmt */
#define MOZIDOMAPPLICATIONMGMT_IID_STR "cf742022-5ba3-11e2-868f-03310341b006"

#define MOZIDOMAPPLICATIONMGMT_IID \
  {0xcf742022, 0x5ba3, 0x11e2, \
    { 0x86, 0x8f, 0x03, 0x31, 0x03, 0x41, 0xb0, 0x06 }}

class NS_NO_VTABLE mozIDOMApplicationMgmt : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIDOMAPPLICATIONMGMT_IID)

  /* nsIDOMDOMRequest getAll (); */
  NS_IMETHOD GetAll(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest getNotInstalled (); */
  NS_IMETHOD GetNotInstalled(nsIDOMDOMRequest * *_retval) = 0;

  /* attribute nsIDOMEventListener oninstall; */
  NS_IMETHOD GetOninstall(nsIDOMEventListener * *aOninstall) = 0;
  NS_IMETHOD SetOninstall(nsIDOMEventListener *aOninstall) = 0;

  /* attribute nsIDOMEventListener onuninstall; */
  NS_IMETHOD GetOnuninstall(nsIDOMEventListener * *aOnuninstall) = 0;
  NS_IMETHOD SetOnuninstall(nsIDOMEventListener *aOnuninstall) = 0;

  /* void applyDownload (in mozIDOMApplication app); */
  NS_IMETHOD ApplyDownload(mozIDOMApplication *app) = 0;

  /* nsIDOMDOMRequest uninstall (in mozIDOMApplication app); */
  NS_IMETHOD Uninstall(mozIDOMApplication *app, nsIDOMDOMRequest * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIDOMApplicationMgmt, MOZIDOMAPPLICATIONMGMT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIDOMAPPLICATIONMGMT \
  NS_IMETHOD GetAll(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetNotInstalled(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetOninstall(nsIDOMEventListener * *aOninstall); \
  NS_IMETHOD SetOninstall(nsIDOMEventListener *aOninstall); \
  NS_IMETHOD GetOnuninstall(nsIDOMEventListener * *aOnuninstall); \
  NS_IMETHOD SetOnuninstall(nsIDOMEventListener *aOnuninstall); \
  NS_IMETHOD ApplyDownload(mozIDOMApplication *app); \
  NS_IMETHOD Uninstall(mozIDOMApplication *app, nsIDOMDOMRequest * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIDOMAPPLICATIONMGMT(_to) \
  NS_IMETHOD GetAll(nsIDOMDOMRequest * *_retval) { return _to GetAll(_retval); } \
  NS_IMETHOD GetNotInstalled(nsIDOMDOMRequest * *_retval) { return _to GetNotInstalled(_retval); } \
  NS_IMETHOD GetOninstall(nsIDOMEventListener * *aOninstall) { return _to GetOninstall(aOninstall); } \
  NS_IMETHOD SetOninstall(nsIDOMEventListener *aOninstall) { return _to SetOninstall(aOninstall); } \
  NS_IMETHOD GetOnuninstall(nsIDOMEventListener * *aOnuninstall) { return _to GetOnuninstall(aOnuninstall); } \
  NS_IMETHOD SetOnuninstall(nsIDOMEventListener *aOnuninstall) { return _to SetOnuninstall(aOnuninstall); } \
  NS_IMETHOD ApplyDownload(mozIDOMApplication *app) { return _to ApplyDownload(app); } \
  NS_IMETHOD Uninstall(mozIDOMApplication *app, nsIDOMDOMRequest * *_retval) { return _to Uninstall(app, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIDOMAPPLICATIONMGMT(_to) \
  NS_IMETHOD GetAll(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAll(_retval); } \
  NS_IMETHOD GetNotInstalled(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotInstalled(_retval); } \
  NS_IMETHOD GetOninstall(nsIDOMEventListener * *aOninstall) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOninstall(aOninstall); } \
  NS_IMETHOD SetOninstall(nsIDOMEventListener *aOninstall) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOninstall(aOninstall); } \
  NS_IMETHOD GetOnuninstall(nsIDOMEventListener * *aOnuninstall) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnuninstall(aOnuninstall); } \
  NS_IMETHOD SetOnuninstall(nsIDOMEventListener *aOnuninstall) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnuninstall(aOnuninstall); } \
  NS_IMETHOD ApplyDownload(mozIDOMApplication *app) { return !_to ? NS_ERROR_NULL_POINTER : _to->ApplyDownload(app); } \
  NS_IMETHOD Uninstall(mozIDOMApplication *app, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Uninstall(app, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIDOMApplicationMgmt
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIDOMAPPLICATIONMGMT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIDOMApplicationMgmt)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* nsIDOMDOMRequest getAll (); */
NS_IMETHODIMP _MYCLASS_::GetAll(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getNotInstalled (); */
NS_IMETHODIMP _MYCLASS_::GetNotInstalled(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener oninstall; */
NS_IMETHODIMP _MYCLASS_::GetOninstall(nsIDOMEventListener * *aOninstall)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOninstall(nsIDOMEventListener *aOninstall)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onuninstall; */
NS_IMETHODIMP _MYCLASS_::GetOnuninstall(nsIDOMEventListener * *aOnuninstall)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetOnuninstall(nsIDOMEventListener *aOnuninstall)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void applyDownload (in mozIDOMApplication app); */
NS_IMETHODIMP _MYCLASS_::ApplyDownload(mozIDOMApplication *app)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest uninstall (in mozIDOMApplication app); */
NS_IMETHODIMP _MYCLASS_::Uninstall(mozIDOMApplication *app, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIDOMApplicationRegistry */
#define MOZIDOMAPPLICATIONREGISTRY_IID_STR "abfc6c15-8b92-4b9a-b892-52e6ae76f379"

#define MOZIDOMAPPLICATIONREGISTRY_IID \
  {0xabfc6c15, 0x8b92, 0x4b9a, \
    { 0xb8, 0x92, 0x52, 0xe6, 0xae, 0x76, 0xf3, 0x79 }}

class NS_NO_VTABLE mozIDOMApplicationRegistry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIDOMAPPLICATIONREGISTRY_IID)

  /* nsIDOMDOMRequest install (in DOMString manifestUrl, [optional] in jsval parameters); */
  NS_IMETHOD Install(const nsAString & manifestUrl, const JS::Value & parameters, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest getSelf (); */
  NS_IMETHOD GetSelf(nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest checkInstalled (in DOMString manifestUrl); */
  NS_IMETHOD CheckInstalled(const nsAString & manifestUrl, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest getInstalled (); */
  NS_IMETHOD GetInstalled(nsIDOMDOMRequest * *_retval) = 0;

  /* readonly attribute mozIDOMApplicationMgmt mgmt; */
  NS_IMETHOD GetMgmt(mozIDOMApplicationMgmt * *aMgmt) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIDOMApplicationRegistry, MOZIDOMAPPLICATIONREGISTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIDOMAPPLICATIONREGISTRY \
  NS_IMETHOD Install(const nsAString & manifestUrl, const JS::Value & parameters, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetSelf(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD CheckInstalled(const nsAString & manifestUrl, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetInstalled(nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetMgmt(mozIDOMApplicationMgmt * *aMgmt); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIDOMAPPLICATIONREGISTRY(_to) \
  NS_IMETHOD Install(const nsAString & manifestUrl, const JS::Value & parameters, nsIDOMDOMRequest * *_retval) { return _to Install(manifestUrl, parameters, _retval); } \
  NS_IMETHOD GetSelf(nsIDOMDOMRequest * *_retval) { return _to GetSelf(_retval); } \
  NS_IMETHOD CheckInstalled(const nsAString & manifestUrl, nsIDOMDOMRequest * *_retval) { return _to CheckInstalled(manifestUrl, _retval); } \
  NS_IMETHOD GetInstalled(nsIDOMDOMRequest * *_retval) { return _to GetInstalled(_retval); } \
  NS_IMETHOD GetMgmt(mozIDOMApplicationMgmt * *aMgmt) { return _to GetMgmt(aMgmt); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIDOMAPPLICATIONREGISTRY(_to) \
  NS_IMETHOD Install(const nsAString & manifestUrl, const JS::Value & parameters, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Install(manifestUrl, parameters, _retval); } \
  NS_IMETHOD GetSelf(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelf(_retval); } \
  NS_IMETHOD CheckInstalled(const nsAString & manifestUrl, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckInstalled(manifestUrl, _retval); } \
  NS_IMETHOD GetInstalled(nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInstalled(_retval); } \
  NS_IMETHOD GetMgmt(mozIDOMApplicationMgmt * *aMgmt) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMgmt(aMgmt); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIDOMApplicationRegistry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIDOMAPPLICATIONREGISTRY

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIDOMApplicationRegistry)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* nsIDOMDOMRequest install (in DOMString manifestUrl, [optional] in jsval parameters); */
NS_IMETHODIMP _MYCLASS_::Install(const nsAString & manifestUrl, const JS::Value & parameters, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getSelf (); */
NS_IMETHODIMP _MYCLASS_::GetSelf(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest checkInstalled (in DOMString manifestUrl); */
NS_IMETHODIMP _MYCLASS_::CheckInstalled(const nsAString & manifestUrl, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest getInstalled (); */
NS_IMETHODIMP _MYCLASS_::GetInstalled(nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIDOMApplicationMgmt mgmt; */
NS_IMETHODIMP _MYCLASS_::GetMgmt(mozIDOMApplicationMgmt * *aMgmt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMApplicationRegistry_h__ */
