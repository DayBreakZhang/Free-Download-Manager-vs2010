/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDownloadManager.idl
 */

#ifndef __gen_nsIDownloadManager_h__
#define __gen_nsIDownloadManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIDownload; /* forward declaration */

class nsICancelable; /* forward declaration */

class nsIMIMEInfo; /* forward declaration */

class nsIDownloadProgressListener; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class mozIStorageConnection; /* forward declaration */


/* starting interface:    nsIDownloadManagerResult */
#define NS_IDOWNLOADMANAGERRESULT_IID_STR "0c07ffeb-791b-49f3-ae38-2c331fd55a52"

#define NS_IDOWNLOADMANAGERRESULT_IID \
  {0x0c07ffeb, 0x791b, 0x49f3, \
    { 0xae, 0x38, 0x2c, 0x33, 0x1f, 0xd5, 0x5a, 0x52 }}

class NS_NO_VTABLE nsIDownloadManagerResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOADMANAGERRESULT_IID)

  /* void handleResult (in nsresult aStatus, in nsIDownload aDownload); */
  NS_IMETHOD HandleResult(nsresult aStatus, nsIDownload *aDownload) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownloadManagerResult, NS_IDOWNLOADMANAGERRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOADMANAGERRESULT \
  NS_IMETHOD HandleResult(nsresult aStatus, nsIDownload *aDownload); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOADMANAGERRESULT(_to) \
  NS_IMETHOD HandleResult(nsresult aStatus, nsIDownload *aDownload) { return _to HandleResult(aStatus, aDownload); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOADMANAGERRESULT(_to) \
  NS_IMETHOD HandleResult(nsresult aStatus, nsIDownload *aDownload) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleResult(aStatus, aDownload); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownloadManagerResult : public nsIDownloadManagerResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOADMANAGERRESULT

  nsDownloadManagerResult();

private:
  ~nsDownloadManagerResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownloadManagerResult, nsIDownloadManagerResult)

nsDownloadManagerResult::nsDownloadManagerResult()
{
  /* member initializers and constructor code */
}

nsDownloadManagerResult::~nsDownloadManagerResult()
{
  /* destructor code */
}

/* void handleResult (in nsresult aStatus, in nsIDownload aDownload); */
NS_IMETHODIMP nsDownloadManagerResult::HandleResult(nsresult aStatus, nsIDownload *aDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDownloadManager */
#define NS_IDOWNLOADMANAGER_IID_STR "b29aac15-7ec4-4ab3-a53b-08f78aed3b34"

#define NS_IDOWNLOADMANAGER_IID \
  {0xb29aac15, 0x7ec4, 0x4ab3, \
    { 0xa5, 0x3b, 0x08, 0xf7, 0x8a, 0xed, 0x3b, 0x34 }}

class NS_NO_VTABLE nsIDownloadManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOWNLOADMANAGER_IID)

  enum {
    DOWNLOAD_TYPE_DOWNLOAD = 0,
    DOWNLOAD_NOTSTARTED = -1,
    DOWNLOAD_DOWNLOADING = 0,
    DOWNLOAD_FINISHED = 1,
    DOWNLOAD_FAILED = 2,
    DOWNLOAD_CANCELED = 3,
    DOWNLOAD_PAUSED = 4,
    DOWNLOAD_QUEUED = 5,
    DOWNLOAD_BLOCKED_PARENTAL = 6,
    DOWNLOAD_SCANNING = 7,
    DOWNLOAD_DIRTY = 8,
    DOWNLOAD_BLOCKED_POLICY = 9
  };

  /* nsIDownload addDownload (in short aDownloadType, in nsIURI aSource, in nsIURI aTarget, in AString aDisplayName, in nsIMIMEInfo aMIMEInfo, in PRTime aStartTime, in nsIFile aTempFile, in nsICancelable aCancelable, in boolean aIsPrivate); */
  NS_IMETHOD AddDownload(int16_t aDownloadType, nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime aStartTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate, nsIDownload * *_retval) = 0;

  /* nsIDownload getDownload (in unsigned long aID); */
  NS_IMETHOD GetDownload(uint32_t aID, nsIDownload * *_retval) = 0;

  /* void getDownloadByGUID (in ACString aGUID, in nsIDownloadManagerResult aCallback); */
  NS_IMETHOD GetDownloadByGUID(const nsACString & aGUID, nsIDownloadManagerResult *aCallback) = 0;

  /* void cancelDownload (in unsigned long aID); */
  NS_IMETHOD CancelDownload(uint32_t aID) = 0;

  /* void removeDownload (in unsigned long aID); */
  NS_IMETHOD RemoveDownload(uint32_t aID) = 0;

  /* void removeDownloadsByTimeframe (in long long aBeginTime, in long long aEndTime); */
  NS_IMETHOD RemoveDownloadsByTimeframe(int64_t aBeginTime, int64_t aEndTime) = 0;

  /* void pauseDownload (in unsigned long aID); */
  NS_IMETHOD PauseDownload(uint32_t aID) = 0;

  /* void resumeDownload (in unsigned long aID); */
  NS_IMETHOD ResumeDownload(uint32_t aID) = 0;

  /* void retryDownload (in unsigned long aID); */
  NS_IMETHOD RetryDownload(uint32_t aID) = 0;

  /* readonly attribute mozIStorageConnection DBConnection; */
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) = 0;

  /* readonly attribute mozIStorageConnection privateDBConnection; */
  NS_IMETHOD GetPrivateDBConnection(mozIStorageConnection * *aPrivateDBConnection) = 0;

  /* readonly attribute boolean canCleanUp; */
  NS_IMETHOD GetCanCleanUp(bool *aCanCleanUp) = 0;

  /* readonly attribute boolean canCleanUpPrivate; */
  NS_IMETHOD GetCanCleanUpPrivate(bool *aCanCleanUpPrivate) = 0;

  /* void cleanUp (); */
  NS_IMETHOD CleanUp(void) = 0;

  /* void cleanUpPrivate (); */
  NS_IMETHOD CleanUpPrivate(void) = 0;

  /* readonly attribute long activeDownloadCount; */
  NS_IMETHOD GetActiveDownloadCount(int32_t *aActiveDownloadCount) = 0;

  /* readonly attribute long activePrivateDownloadCount; */
  NS_IMETHOD GetActivePrivateDownloadCount(int32_t *aActivePrivateDownloadCount) = 0;

  /* readonly attribute nsISimpleEnumerator activeDownloads; */
  NS_IMETHOD GetActiveDownloads(nsISimpleEnumerator * *aActiveDownloads) = 0;

  /* readonly attribute nsISimpleEnumerator activePrivateDownloads; */
  NS_IMETHOD GetActivePrivateDownloads(nsISimpleEnumerator * *aActivePrivateDownloads) = 0;

  /* void addListener (in nsIDownloadProgressListener aListener); */
  NS_IMETHOD AddListener(nsIDownloadProgressListener *aListener) = 0;

  /* void addPrivacyAwareListener (in nsIDownloadProgressListener aListener); */
  NS_IMETHOD AddPrivacyAwareListener(nsIDownloadProgressListener *aListener) = 0;

  /* void removeListener (in nsIDownloadProgressListener aListener); */
  NS_IMETHOD RemoveListener(nsIDownloadProgressListener *aListener) = 0;

  /* readonly attribute nsIFile defaultDownloadsDirectory; */
  NS_IMETHOD GetDefaultDownloadsDirectory(nsIFile * *aDefaultDownloadsDirectory) = 0;

  /* readonly attribute nsIFile userDownloadsDirectory; */
  NS_IMETHOD GetUserDownloadsDirectory(nsIFile * *aUserDownloadsDirectory) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDownloadManager, NS_IDOWNLOADMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOWNLOADMANAGER \
  NS_IMETHOD AddDownload(int16_t aDownloadType, nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime aStartTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate, nsIDownload * *_retval); \
  NS_IMETHOD GetDownload(uint32_t aID, nsIDownload * *_retval); \
  NS_IMETHOD GetDownloadByGUID(const nsACString & aGUID, nsIDownloadManagerResult *aCallback); \
  NS_IMETHOD CancelDownload(uint32_t aID); \
  NS_IMETHOD RemoveDownload(uint32_t aID); \
  NS_IMETHOD RemoveDownloadsByTimeframe(int64_t aBeginTime, int64_t aEndTime); \
  NS_IMETHOD PauseDownload(uint32_t aID); \
  NS_IMETHOD ResumeDownload(uint32_t aID); \
  NS_IMETHOD RetryDownload(uint32_t aID); \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection); \
  NS_IMETHOD GetPrivateDBConnection(mozIStorageConnection * *aPrivateDBConnection); \
  NS_IMETHOD GetCanCleanUp(bool *aCanCleanUp); \
  NS_IMETHOD GetCanCleanUpPrivate(bool *aCanCleanUpPrivate); \
  NS_IMETHOD CleanUp(void); \
  NS_IMETHOD CleanUpPrivate(void); \
  NS_IMETHOD GetActiveDownloadCount(int32_t *aActiveDownloadCount); \
  NS_IMETHOD GetActivePrivateDownloadCount(int32_t *aActivePrivateDownloadCount); \
  NS_IMETHOD GetActiveDownloads(nsISimpleEnumerator * *aActiveDownloads); \
  NS_IMETHOD GetActivePrivateDownloads(nsISimpleEnumerator * *aActivePrivateDownloads); \
  NS_IMETHOD AddListener(nsIDownloadProgressListener *aListener); \
  NS_IMETHOD AddPrivacyAwareListener(nsIDownloadProgressListener *aListener); \
  NS_IMETHOD RemoveListener(nsIDownloadProgressListener *aListener); \
  NS_IMETHOD GetDefaultDownloadsDirectory(nsIFile * *aDefaultDownloadsDirectory); \
  NS_IMETHOD GetUserDownloadsDirectory(nsIFile * *aUserDownloadsDirectory); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOWNLOADMANAGER(_to) \
  NS_IMETHOD AddDownload(int16_t aDownloadType, nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime aStartTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate, nsIDownload * *_retval) { return _to AddDownload(aDownloadType, aSource, aTarget, aDisplayName, aMIMEInfo, aStartTime, aTempFile, aCancelable, aIsPrivate, _retval); } \
  NS_IMETHOD GetDownload(uint32_t aID, nsIDownload * *_retval) { return _to GetDownload(aID, _retval); } \
  NS_IMETHOD GetDownloadByGUID(const nsACString & aGUID, nsIDownloadManagerResult *aCallback) { return _to GetDownloadByGUID(aGUID, aCallback); } \
  NS_IMETHOD CancelDownload(uint32_t aID) { return _to CancelDownload(aID); } \
  NS_IMETHOD RemoveDownload(uint32_t aID) { return _to RemoveDownload(aID); } \
  NS_IMETHOD RemoveDownloadsByTimeframe(int64_t aBeginTime, int64_t aEndTime) { return _to RemoveDownloadsByTimeframe(aBeginTime, aEndTime); } \
  NS_IMETHOD PauseDownload(uint32_t aID) { return _to PauseDownload(aID); } \
  NS_IMETHOD ResumeDownload(uint32_t aID) { return _to ResumeDownload(aID); } \
  NS_IMETHOD RetryDownload(uint32_t aID) { return _to RetryDownload(aID); } \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return _to GetDBConnection(aDBConnection); } \
  NS_IMETHOD GetPrivateDBConnection(mozIStorageConnection * *aPrivateDBConnection) { return _to GetPrivateDBConnection(aPrivateDBConnection); } \
  NS_IMETHOD GetCanCleanUp(bool *aCanCleanUp) { return _to GetCanCleanUp(aCanCleanUp); } \
  NS_IMETHOD GetCanCleanUpPrivate(bool *aCanCleanUpPrivate) { return _to GetCanCleanUpPrivate(aCanCleanUpPrivate); } \
  NS_IMETHOD CleanUp(void) { return _to CleanUp(); } \
  NS_IMETHOD CleanUpPrivate(void) { return _to CleanUpPrivate(); } \
  NS_IMETHOD GetActiveDownloadCount(int32_t *aActiveDownloadCount) { return _to GetActiveDownloadCount(aActiveDownloadCount); } \
  NS_IMETHOD GetActivePrivateDownloadCount(int32_t *aActivePrivateDownloadCount) { return _to GetActivePrivateDownloadCount(aActivePrivateDownloadCount); } \
  NS_IMETHOD GetActiveDownloads(nsISimpleEnumerator * *aActiveDownloads) { return _to GetActiveDownloads(aActiveDownloads); } \
  NS_IMETHOD GetActivePrivateDownloads(nsISimpleEnumerator * *aActivePrivateDownloads) { return _to GetActivePrivateDownloads(aActivePrivateDownloads); } \
  NS_IMETHOD AddListener(nsIDownloadProgressListener *aListener) { return _to AddListener(aListener); } \
  NS_IMETHOD AddPrivacyAwareListener(nsIDownloadProgressListener *aListener) { return _to AddPrivacyAwareListener(aListener); } \
  NS_IMETHOD RemoveListener(nsIDownloadProgressListener *aListener) { return _to RemoveListener(aListener); } \
  NS_IMETHOD GetDefaultDownloadsDirectory(nsIFile * *aDefaultDownloadsDirectory) { return _to GetDefaultDownloadsDirectory(aDefaultDownloadsDirectory); } \
  NS_IMETHOD GetUserDownloadsDirectory(nsIFile * *aUserDownloadsDirectory) { return _to GetUserDownloadsDirectory(aUserDownloadsDirectory); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOWNLOADMANAGER(_to) \
  NS_IMETHOD AddDownload(int16_t aDownloadType, nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime aStartTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate, nsIDownload * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDownload(aDownloadType, aSource, aTarget, aDisplayName, aMIMEInfo, aStartTime, aTempFile, aCancelable, aIsPrivate, _retval); } \
  NS_IMETHOD GetDownload(uint32_t aID, nsIDownload * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownload(aID, _retval); } \
  NS_IMETHOD GetDownloadByGUID(const nsACString & aGUID, nsIDownloadManagerResult *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDownloadByGUID(aGUID, aCallback); } \
  NS_IMETHOD CancelDownload(uint32_t aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelDownload(aID); } \
  NS_IMETHOD RemoveDownload(uint32_t aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDownload(aID); } \
  NS_IMETHOD RemoveDownloadsByTimeframe(int64_t aBeginTime, int64_t aEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDownloadsByTimeframe(aBeginTime, aEndTime); } \
  NS_IMETHOD PauseDownload(uint32_t aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->PauseDownload(aID); } \
  NS_IMETHOD ResumeDownload(uint32_t aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeDownload(aID); } \
  NS_IMETHOD RetryDownload(uint32_t aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->RetryDownload(aID); } \
  NS_IMETHOD GetDBConnection(mozIStorageConnection * *aDBConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDBConnection(aDBConnection); } \
  NS_IMETHOD GetPrivateDBConnection(mozIStorageConnection * *aPrivateDBConnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrivateDBConnection(aPrivateDBConnection); } \
  NS_IMETHOD GetCanCleanUp(bool *aCanCleanUp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanCleanUp(aCanCleanUp); } \
  NS_IMETHOD GetCanCleanUpPrivate(bool *aCanCleanUpPrivate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanCleanUpPrivate(aCanCleanUpPrivate); } \
  NS_IMETHOD CleanUp(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CleanUp(); } \
  NS_IMETHOD CleanUpPrivate(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CleanUpPrivate(); } \
  NS_IMETHOD GetActiveDownloadCount(int32_t *aActiveDownloadCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveDownloadCount(aActiveDownloadCount); } \
  NS_IMETHOD GetActivePrivateDownloadCount(int32_t *aActivePrivateDownloadCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActivePrivateDownloadCount(aActivePrivateDownloadCount); } \
  NS_IMETHOD GetActiveDownloads(nsISimpleEnumerator * *aActiveDownloads) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveDownloads(aActiveDownloads); } \
  NS_IMETHOD GetActivePrivateDownloads(nsISimpleEnumerator * *aActivePrivateDownloads) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActivePrivateDownloads(aActivePrivateDownloads); } \
  NS_IMETHOD AddListener(nsIDownloadProgressListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aListener); } \
  NS_IMETHOD AddPrivacyAwareListener(nsIDownloadProgressListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddPrivacyAwareListener(aListener); } \
  NS_IMETHOD RemoveListener(nsIDownloadProgressListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aListener); } \
  NS_IMETHOD GetDefaultDownloadsDirectory(nsIFile * *aDefaultDownloadsDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultDownloadsDirectory(aDefaultDownloadsDirectory); } \
  NS_IMETHOD GetUserDownloadsDirectory(nsIFile * *aUserDownloadsDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserDownloadsDirectory(aUserDownloadsDirectory); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDownloadManager : public nsIDownloadManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOWNLOADMANAGER

  nsDownloadManager();

private:
  ~nsDownloadManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDownloadManager, nsIDownloadManager)

nsDownloadManager::nsDownloadManager()
{
  /* member initializers and constructor code */
}

nsDownloadManager::~nsDownloadManager()
{
  /* destructor code */
}

/* nsIDownload addDownload (in short aDownloadType, in nsIURI aSource, in nsIURI aTarget, in AString aDisplayName, in nsIMIMEInfo aMIMEInfo, in PRTime aStartTime, in nsIFile aTempFile, in nsICancelable aCancelable, in boolean aIsPrivate); */
NS_IMETHODIMP nsDownloadManager::AddDownload(int16_t aDownloadType, nsIURI *aSource, nsIURI *aTarget, const nsAString & aDisplayName, nsIMIMEInfo *aMIMEInfo, PRTime aStartTime, nsIFile *aTempFile, nsICancelable *aCancelable, bool aIsPrivate, nsIDownload * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDownload getDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::GetDownload(uint32_t aID, nsIDownload * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getDownloadByGUID (in ACString aGUID, in nsIDownloadManagerResult aCallback); */
NS_IMETHODIMP nsDownloadManager::GetDownloadByGUID(const nsACString & aGUID, nsIDownloadManagerResult *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::CancelDownload(uint32_t aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::RemoveDownload(uint32_t aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDownloadsByTimeframe (in long long aBeginTime, in long long aEndTime); */
NS_IMETHODIMP nsDownloadManager::RemoveDownloadsByTimeframe(int64_t aBeginTime, int64_t aEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pauseDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::PauseDownload(uint32_t aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::ResumeDownload(uint32_t aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void retryDownload (in unsigned long aID); */
NS_IMETHODIMP nsDownloadManager::RetryDownload(uint32_t aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageConnection DBConnection; */
NS_IMETHODIMP nsDownloadManager::GetDBConnection(mozIStorageConnection * *aDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute mozIStorageConnection privateDBConnection; */
NS_IMETHODIMP nsDownloadManager::GetPrivateDBConnection(mozIStorageConnection * *aPrivateDBConnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canCleanUp; */
NS_IMETHODIMP nsDownloadManager::GetCanCleanUp(bool *aCanCleanUp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canCleanUpPrivate; */
NS_IMETHODIMP nsDownloadManager::GetCanCleanUpPrivate(bool *aCanCleanUpPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cleanUp (); */
NS_IMETHODIMP nsDownloadManager::CleanUp()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cleanUpPrivate (); */
NS_IMETHODIMP nsDownloadManager::CleanUpPrivate()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long activeDownloadCount; */
NS_IMETHODIMP nsDownloadManager::GetActiveDownloadCount(int32_t *aActiveDownloadCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long activePrivateDownloadCount; */
NS_IMETHODIMP nsDownloadManager::GetActivePrivateDownloadCount(int32_t *aActivePrivateDownloadCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator activeDownloads; */
NS_IMETHODIMP nsDownloadManager::GetActiveDownloads(nsISimpleEnumerator * *aActiveDownloads)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator activePrivateDownloads; */
NS_IMETHODIMP nsDownloadManager::GetActivePrivateDownloads(nsISimpleEnumerator * *aActivePrivateDownloads)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addListener (in nsIDownloadProgressListener aListener); */
NS_IMETHODIMP nsDownloadManager::AddListener(nsIDownloadProgressListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addPrivacyAwareListener (in nsIDownloadProgressListener aListener); */
NS_IMETHODIMP nsDownloadManager::AddPrivacyAwareListener(nsIDownloadProgressListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in nsIDownloadProgressListener aListener); */
NS_IMETHODIMP nsDownloadManager::RemoveListener(nsIDownloadProgressListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile defaultDownloadsDirectory; */
NS_IMETHODIMP nsDownloadManager::GetDefaultDownloadsDirectory(nsIFile * *aDefaultDownloadsDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile userDownloadsDirectory; */
NS_IMETHODIMP nsDownloadManager::GetUserDownloadsDirectory(nsIFile * *aUserDownloadsDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDownloadManager_h__ */
