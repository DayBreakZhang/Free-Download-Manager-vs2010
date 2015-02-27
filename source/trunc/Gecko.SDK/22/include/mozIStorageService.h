/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/storage/public/mozIStorageService.idl
 */

#ifndef __gen_mozIStorageService_h__
#define __gen_mozIStorageService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class mozIStorageConnection; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIFileURL; /* forward declaration */


/* starting interface:    mozIStorageService */
#define MOZISTORAGESERVICE_IID_STR "12bfad34-cca3-40fb-8736-d8bf9db61a27"

#define MOZISTORAGESERVICE_IID \
  {0x12bfad34, 0xcca3, 0x40fb, \
    { 0x87, 0x36, 0xd8, 0xbf, 0x9d, 0xb6, 0x1a, 0x27 }}

class NS_NO_VTABLE mozIStorageService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZISTORAGESERVICE_IID)

  /* mozIStorageConnection openSpecialDatabase (in string aStorageKey); */
  NS_IMETHOD OpenSpecialDatabase(const char * aStorageKey, mozIStorageConnection * *_retval) = 0;

  /* mozIStorageConnection openDatabase (in nsIFile aDatabaseFile); */
  NS_IMETHOD OpenDatabase(nsIFile *aDatabaseFile, mozIStorageConnection * *_retval) = 0;

  /* mozIStorageConnection openUnsharedDatabase (in nsIFile aDatabaseFile); */
  NS_IMETHOD OpenUnsharedDatabase(nsIFile *aDatabaseFile, mozIStorageConnection * *_retval) = 0;

  /* mozIStorageConnection openDatabaseWithFileURL (in nsIFileURL aFileURL); */
  NS_IMETHOD OpenDatabaseWithFileURL(nsIFileURL *aFileURL, mozIStorageConnection * *_retval) = 0;

  /* nsIFile backupDatabaseFile (in nsIFile aDBFile, in AString aBackupFileName, [optional] in nsIFile aBackupParentDirectory); */
  NS_IMETHOD BackupDatabaseFile(nsIFile *aDBFile, const nsAString & aBackupFileName, nsIFile *aBackupParentDirectory, nsIFile * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIStorageService, MOZISTORAGESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZISTORAGESERVICE \
  NS_IMETHOD OpenSpecialDatabase(const char * aStorageKey, mozIStorageConnection * *_retval); \
  NS_IMETHOD OpenDatabase(nsIFile *aDatabaseFile, mozIStorageConnection * *_retval); \
  NS_IMETHOD OpenUnsharedDatabase(nsIFile *aDatabaseFile, mozIStorageConnection * *_retval); \
  NS_IMETHOD OpenDatabaseWithFileURL(nsIFileURL *aFileURL, mozIStorageConnection * *_retval); \
  NS_IMETHOD BackupDatabaseFile(nsIFile *aDBFile, const nsAString & aBackupFileName, nsIFile *aBackupParentDirectory, nsIFile * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZISTORAGESERVICE(_to) \
  NS_IMETHOD OpenSpecialDatabase(const char * aStorageKey, mozIStorageConnection * *_retval) { return _to OpenSpecialDatabase(aStorageKey, _retval); } \
  NS_IMETHOD OpenDatabase(nsIFile *aDatabaseFile, mozIStorageConnection * *_retval) { return _to OpenDatabase(aDatabaseFile, _retval); } \
  NS_IMETHOD OpenUnsharedDatabase(nsIFile *aDatabaseFile, mozIStorageConnection * *_retval) { return _to OpenUnsharedDatabase(aDatabaseFile, _retval); } \
  NS_IMETHOD OpenDatabaseWithFileURL(nsIFileURL *aFileURL, mozIStorageConnection * *_retval) { return _to OpenDatabaseWithFileURL(aFileURL, _retval); } \
  NS_IMETHOD BackupDatabaseFile(nsIFile *aDBFile, const nsAString & aBackupFileName, nsIFile *aBackupParentDirectory, nsIFile * *_retval) { return _to BackupDatabaseFile(aDBFile, aBackupFileName, aBackupParentDirectory, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZISTORAGESERVICE(_to) \
  NS_IMETHOD OpenSpecialDatabase(const char * aStorageKey, mozIStorageConnection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenSpecialDatabase(aStorageKey, _retval); } \
  NS_IMETHOD OpenDatabase(nsIFile *aDatabaseFile, mozIStorageConnection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDatabase(aDatabaseFile, _retval); } \
  NS_IMETHOD OpenUnsharedDatabase(nsIFile *aDatabaseFile, mozIStorageConnection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenUnsharedDatabase(aDatabaseFile, _retval); } \
  NS_IMETHOD OpenDatabaseWithFileURL(nsIFileURL *aFileURL, mozIStorageConnection * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenDatabaseWithFileURL(aFileURL, _retval); } \
  NS_IMETHOD BackupDatabaseFile(nsIFile *aDBFile, const nsAString & aBackupFileName, nsIFile *aBackupParentDirectory, nsIFile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->BackupDatabaseFile(aDBFile, aBackupFileName, aBackupParentDirectory, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIStorageService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZISTORAGESERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIStorageService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* mozIStorageConnection openSpecialDatabase (in string aStorageKey); */
NS_IMETHODIMP _MYCLASS_::OpenSpecialDatabase(const char * aStorageKey, mozIStorageConnection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageConnection openDatabase (in nsIFile aDatabaseFile); */
NS_IMETHODIMP _MYCLASS_::OpenDatabase(nsIFile *aDatabaseFile, mozIStorageConnection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageConnection openUnsharedDatabase (in nsIFile aDatabaseFile); */
NS_IMETHODIMP _MYCLASS_::OpenUnsharedDatabase(nsIFile *aDatabaseFile, mozIStorageConnection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* mozIStorageConnection openDatabaseWithFileURL (in nsIFileURL aFileURL); */
NS_IMETHODIMP _MYCLASS_::OpenDatabaseWithFileURL(nsIFileURL *aFileURL, mozIStorageConnection * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile backupDatabaseFile (in nsIFile aDBFile, in AString aBackupFileName, [optional] in nsIFile aBackupParentDirectory); */
NS_IMETHODIMP _MYCLASS_::BackupDatabaseFile(nsIFile *aDBFile, const nsAString & aBackupFileName, nsIFile *aBackupParentDirectory, nsIFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define MOZ_STORAGE_MEMORY_STORAGE_KEY    "memory"
#define MOZ_STORAGE_PROFILE_STORAGE_KEY   "profile"

#endif /* __gen_mozIStorageService_h__ */
