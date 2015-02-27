/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDownload.idl
 */

#ifndef __gen_nsIDownload_h__
#define __gen_nsIDownload_h__


#ifndef __gen_nsITransfer_h__
#include "nsITransfer.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIObserver; /* forward declaration */

class nsICancelable; /* forward declaration */

class nsIWebProgressListener; /* forward declaration */

class nsIMIMEInfo; /* forward declaration */


/* starting interface:    nsIDownload */
#define NS_IDOWNLOAD_IID_STR "b02be33b-d47c-4bd3-afd9-402a942426b0"

#define NS_IDOWNLOAD_IID \
  {0xb02be33b, 0xd47c, 0x4bd3, \
    { 0xaf, 0xd9, 0x40, 0x2a, 0x94, 0x24, 0x26, 0xb0 }}

class NS_NO_VTABLE nsIDownload : public nsITransfer {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOAD_IID)

  /* readonly attribute nsIFile targetFile; */
  NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile) = 0;

  /* readonly attribute long percentComplete; */
  NS_IMETHOD GetPercentComplete(int32_t *aPercentComplete) = 0;

  /* readonly attribute long long amountTransferred; */
  NS_IMETHOD GetAmountTransferred(int64_t *aAmountTransferred) = 0;

  /* readonly attribute long long size; */
  NS_IMETHOD GetSize(int64_t *aSize) = 0;

  /* readonly attribute nsIURI source; */
  NS_IMETHOD GetSource(nsIURI * *aSource) = 0;

  /* readonly attribute nsIURI target; */
  NS_IMETHOD GetTarget(nsIURI * *aTarget) = 0;

  /* readonly attribute nsICancelable cancelable; */
  NS_IMETHOD GetCancelable(nsICancelable * *aCancelable) = 0;

  /* readonly attribute AString displayName; */
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName) = 0;

  /* readonly attribute long long startTime; */
  NS_IMETHOD GetStartTime(int64_t *aStartTime) = 0;

  /* readonly attribute double speed; */
  NS_IMETHOD GetSpeed(double *aSpeed) = 0;

  /* readonly attribute nsIMIMEInfo MIMEInfo; */
  NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) = 0;

  /* readonly attribute unsigned long id; */
  NS_IMETHOD GetId(uint32_t *aId) = 0;

  /* readonly attribute ACString guid; */
  NS_IMETHOD GetGuid(nsACString & aGuid) = 0;

  /* readonly attribute short state; */
  NS_IMETHOD GetState(int16_t *aState) = 0;

  /* readonly attribute nsIURI referrer; */
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) = 0;

  /* readonly attribute boolean resumable; */
  NS_IMETHOD GetResumable(bool *aResumable) = 0;

  /* readonly attribute boolean isPrivate; */
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) = 0;

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

  /* void pause (); */
  NS_IMETHOD Pause(void) = 0;

  /* void resume (); */
  NS_IMETHOD Resume(void) = 0;

  /* void remove (); */
  NS_IMETHOD Remove(void) = 0;

  /* void retry (); */
  NS_IMETHOD Retry(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownload, NS_IDOWNLOAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOAD \
  NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile); \
  NS_IMETHOD GetPercentComplete(int32_t *aPercentComplete); \
  NS_IMETHOD GetAmountTransferred(int64_t *aAmountTransferred); \
  NS_IMETHOD GetSize(int64_t *aSize); \
  NS_IMETHOD GetSource(nsIURI * *aSource); \
  NS_IMETHOD GetTarget(nsIURI * *aTarget); \
  NS_IMETHOD GetCancelable(nsICancelable * *aCancelable); \
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName); \
  NS_IMETHOD GetStartTime(int64_t *aStartTime); \
  NS_IMETHOD GetSpeed(double *aSpeed); \
  NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo); \
  NS_IMETHOD GetId(uint32_t *aId); \
  NS_IMETHOD GetGuid(nsACString & aGuid); \
  NS_IMETHOD GetState(int16_t *aState); \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer); \
  NS_IMETHOD GetResumable(bool *aResumable); \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate); \
  NS_IMETHOD Cancel(void); \
  NS_IMETHOD Pause(void); \
  NS_IMETHOD Resume(void); \
  NS_IMETHOD Remove(void); \
  NS_IMETHOD Retry(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOAD(_to) \
  NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile) { return _to GetTargetFile(aTargetFile); } \
  NS_IMETHOD GetPercentComplete(int32_t *aPercentComplete) { return _to GetPercentComplete(aPercentComplete); } \
  NS_IMETHOD GetAmountTransferred(int64_t *aAmountTransferred) { return _to GetAmountTransferred(aAmountTransferred); } \
  NS_IMETHOD GetSize(int64_t *aSize) { return _to GetSize(aSize); } \
  NS_IMETHOD GetSource(nsIURI * *aSource) { return _to GetSource(aSource); } \
  NS_IMETHOD GetTarget(nsIURI * *aTarget) { return _to GetTarget(aTarget); } \
  NS_IMETHOD GetCancelable(nsICancelable * *aCancelable) { return _to GetCancelable(aCancelable); } \
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName) { return _to GetDisplayName(aDisplayName); } \
  NS_IMETHOD GetStartTime(int64_t *aStartTime) { return _to GetStartTime(aStartTime); } \
  NS_IMETHOD GetSpeed(double *aSpeed) { return _to GetSpeed(aSpeed); } \
  NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) { return _to GetMIMEInfo(aMIMEInfo); } \
  NS_IMETHOD GetId(uint32_t *aId) { return _to GetId(aId); } \
  NS_IMETHOD GetGuid(nsACString & aGuid) { return _to GetGuid(aGuid); } \
  NS_IMETHOD GetState(int16_t *aState) { return _to GetState(aState); } \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) { return _to GetReferrer(aReferrer); } \
  NS_IMETHOD GetResumable(bool *aResumable) { return _to GetResumable(aResumable); } \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) { return _to GetIsPrivate(aIsPrivate); } \
  NS_IMETHOD Cancel(void) { return _to Cancel(); } \
  NS_IMETHOD Pause(void) { return _to Pause(); } \
  NS_IMETHOD Resume(void) { return _to Resume(); } \
  NS_IMETHOD Remove(void) { return _to Remove(); } \
  NS_IMETHOD Retry(void) { return _to Retry(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOAD(_to) \
  NS_IMETHOD GetTargetFile(nsIFile * *aTargetFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetFile(aTargetFile); } \
  NS_IMETHOD GetPercentComplete(int32_t *aPercentComplete) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPercentComplete(aPercentComplete); } \
  NS_IMETHOD GetAmountTransferred(int64_t *aAmountTransferred) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAmountTransferred(aAmountTransferred); } \
  NS_IMETHOD GetSize(int64_t *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_IMETHOD GetSource(nsIURI * *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_IMETHOD GetTarget(nsIURI * *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD GetCancelable(nsICancelable * *aCancelable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCancelable(aCancelable); } \
  NS_IMETHOD GetDisplayName(nsAString & aDisplayName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplayName(aDisplayName); } \
  NS_IMETHOD GetStartTime(int64_t *aStartTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartTime(aStartTime); } \
  NS_IMETHOD GetSpeed(double *aSpeed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpeed(aSpeed); } \
  NS_IMETHOD GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMIMEInfo(aMIMEInfo); } \
  NS_IMETHOD GetId(uint32_t *aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetGuid(nsACString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGuid(aGuid); } \
  NS_IMETHOD GetState(int16_t *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_IMETHOD GetReferrer(nsIURI * *aReferrer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrer(aReferrer); } \
  NS_IMETHOD GetResumable(bool *aResumable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResumable(aResumable); } \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsPrivate(aIsPrivate); } \
  NS_IMETHOD Cancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } \
  NS_IMETHOD Pause(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Pause(); } \
  NS_IMETHOD Resume(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Resume(); } \
  NS_IMETHOD Remove(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(); } \
  NS_IMETHOD Retry(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Retry(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownload : public nsIDownload
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOAD

  nsDownload();

private:
  ~nsDownload();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownload, nsIDownload)

nsDownload::nsDownload()
{
  /* member initializers and constructor code */
}

nsDownload::~nsDownload()
{
  /* destructor code */
}

/* readonly attribute nsIFile targetFile; */
NS_IMETHODIMP nsDownload::GetTargetFile(nsIFile * *aTargetFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long percentComplete; */
NS_IMETHODIMP nsDownload::GetPercentComplete(int32_t *aPercentComplete)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long amountTransferred; */
NS_IMETHODIMP nsDownload::GetAmountTransferred(int64_t *aAmountTransferred)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long size; */
NS_IMETHODIMP nsDownload::GetSize(int64_t *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI source; */
NS_IMETHODIMP nsDownload::GetSource(nsIURI * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI target; */
NS_IMETHODIMP nsDownload::GetTarget(nsIURI * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsICancelable cancelable; */
NS_IMETHODIMP nsDownload::GetCancelable(nsICancelable * *aCancelable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString displayName; */
NS_IMETHODIMP nsDownload::GetDisplayName(nsAString & aDisplayName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long startTime; */
NS_IMETHODIMP nsDownload::GetStartTime(int64_t *aStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double speed; */
NS_IMETHODIMP nsDownload::GetSpeed(double *aSpeed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIMIMEInfo MIMEInfo; */
NS_IMETHODIMP nsDownload::GetMIMEInfo(nsIMIMEInfo * *aMIMEInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long id; */
NS_IMETHODIMP nsDownload::GetId(uint32_t *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString guid; */
NS_IMETHODIMP nsDownload::GetGuid(nsACString & aGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute short state; */
NS_IMETHODIMP nsDownload::GetState(int16_t *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI referrer; */
NS_IMETHODIMP nsDownload::GetReferrer(nsIURI * *aReferrer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean resumable; */
NS_IMETHODIMP nsDownload::GetResumable(bool *aResumable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isPrivate; */
NS_IMETHODIMP nsDownload::GetIsPrivate(bool *aIsPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancel (); */
NS_IMETHODIMP nsDownload::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pause (); */
NS_IMETHODIMP nsDownload::Pause()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resume (); */
NS_IMETHODIMP nsDownload::Resume()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (); */
NS_IMETHODIMP nsDownload::Remove()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void retry (); */
NS_IMETHODIMP nsDownload::Retry()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {b02be33b-d47c-4bd3-afd9-402a942426b0}
#define NS_DOWNLOAD_CID \
  { 0xb02be33b, 0xd47c, 0x4bd3, { 0xaf, 0xd9, 0x40, 0x2a, 0x94, 0x24, 0x26, 0xb0 } }

#endif /* __gen_nsIDownload_h__ */
