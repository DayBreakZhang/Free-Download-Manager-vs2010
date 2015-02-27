/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/profile/nsIToolkitProfileService.idl
 */

#ifndef __gen_nsIToolkitProfileService_h__
#define __gen_nsIToolkitProfileService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIToolkitProfile; /* forward declaration */

class nsIProfileLock; /* forward declaration */


/* starting interface:    nsIToolkitProfileService */
#define NS_ITOOLKITPROFILESERVICE_IID_STR "b619f83d-8317-473c-b342-67905993fdc7"

#define NS_ITOOLKITPROFILESERVICE_IID \
  {0xb619f83d, 0x8317, 0x473c, \
    { 0xb3, 0x42, 0x67, 0x90, 0x59, 0x93, 0xfd, 0xc7 }}

class NS_NO_VTABLE nsIToolkitProfileService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOOLKITPROFILESERVICE_IID)

  /* attribute boolean startWithLastProfile; */
  NS_IMETHOD GetStartWithLastProfile(bool *aStartWithLastProfile) = 0;
  NS_IMETHOD SetStartWithLastProfile(bool aStartWithLastProfile) = 0;

  /* attribute boolean startOffline; */
  NS_IMETHOD GetStartOffline(bool *aStartOffline) = 0;
  NS_IMETHOD SetStartOffline(bool aStartOffline) = 0;

  /* readonly attribute nsISimpleEnumerator profiles; */
  NS_IMETHOD GetProfiles(nsISimpleEnumerator * *aProfiles) = 0;

  /* attribute nsIToolkitProfile selectedProfile; */
  NS_IMETHOD GetSelectedProfile(nsIToolkitProfile * *aSelectedProfile) = 0;
  NS_IMETHOD SetSelectedProfile(nsIToolkitProfile *aSelectedProfile) = 0;

  /* nsIToolkitProfile getProfileByName (in AUTF8String aName); */
  NS_IMETHOD GetProfileByName(const nsACString & aName, nsIToolkitProfile * *_retval) = 0;

  /* nsIProfileLock lockProfilePath (in nsIFile aDirectory, in nsIFile aTempDirectory); */
  NS_IMETHOD LockProfilePath(nsIFile *aDirectory, nsIFile *aTempDirectory, nsIProfileLock * *_retval) = 0;

  /* nsIToolkitProfile createProfile (in nsIFile aRootDir, in nsIFile aTempDir, in AUTF8String aName); */
  NS_IMETHOD CreateProfile(nsIFile *aRootDir, nsIFile *aTempDir, const nsACString & aName, nsIToolkitProfile * *_retval) = 0;

  /* nsIToolkitProfile createDefaultProfileForApp (in AUTF8String aProfileName, in AUTF8String aAppName, in AUTF8String aVendorName, [optional] in nsIFile aProfileDefaultsDir); */
  NS_IMETHOD CreateDefaultProfileForApp(const nsACString & aProfileName, const nsACString & aAppName, const nsACString & aVendorName, nsIFile *aProfileDefaultsDir, nsIToolkitProfile * *_retval) = 0;

  /* readonly attribute unsigned long profileCount; */
  NS_IMETHOD GetProfileCount(uint32_t *aProfileCount) = 0;

  /* void flush (); */
  NS_IMETHOD Flush(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIToolkitProfileService, NS_ITOOLKITPROFILESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOOLKITPROFILESERVICE \
  NS_IMETHOD GetStartWithLastProfile(bool *aStartWithLastProfile); \
  NS_IMETHOD SetStartWithLastProfile(bool aStartWithLastProfile); \
  NS_IMETHOD GetStartOffline(bool *aStartOffline); \
  NS_IMETHOD SetStartOffline(bool aStartOffline); \
  NS_IMETHOD GetProfiles(nsISimpleEnumerator * *aProfiles); \
  NS_IMETHOD GetSelectedProfile(nsIToolkitProfile * *aSelectedProfile); \
  NS_IMETHOD SetSelectedProfile(nsIToolkitProfile *aSelectedProfile); \
  NS_IMETHOD GetProfileByName(const nsACString & aName, nsIToolkitProfile * *_retval); \
  NS_IMETHOD LockProfilePath(nsIFile *aDirectory, nsIFile *aTempDirectory, nsIProfileLock * *_retval); \
  NS_IMETHOD CreateProfile(nsIFile *aRootDir, nsIFile *aTempDir, const nsACString & aName, nsIToolkitProfile * *_retval); \
  NS_IMETHOD CreateDefaultProfileForApp(const nsACString & aProfileName, const nsACString & aAppName, const nsACString & aVendorName, nsIFile *aProfileDefaultsDir, nsIToolkitProfile * *_retval); \
  NS_IMETHOD GetProfileCount(uint32_t *aProfileCount); \
  NS_IMETHOD Flush(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOOLKITPROFILESERVICE(_to) \
  NS_IMETHOD GetStartWithLastProfile(bool *aStartWithLastProfile) { return _to GetStartWithLastProfile(aStartWithLastProfile); } \
  NS_IMETHOD SetStartWithLastProfile(bool aStartWithLastProfile) { return _to SetStartWithLastProfile(aStartWithLastProfile); } \
  NS_IMETHOD GetStartOffline(bool *aStartOffline) { return _to GetStartOffline(aStartOffline); } \
  NS_IMETHOD SetStartOffline(bool aStartOffline) { return _to SetStartOffline(aStartOffline); } \
  NS_IMETHOD GetProfiles(nsISimpleEnumerator * *aProfiles) { return _to GetProfiles(aProfiles); } \
  NS_IMETHOD GetSelectedProfile(nsIToolkitProfile * *aSelectedProfile) { return _to GetSelectedProfile(aSelectedProfile); } \
  NS_IMETHOD SetSelectedProfile(nsIToolkitProfile *aSelectedProfile) { return _to SetSelectedProfile(aSelectedProfile); } \
  NS_IMETHOD GetProfileByName(const nsACString & aName, nsIToolkitProfile * *_retval) { return _to GetProfileByName(aName, _retval); } \
  NS_IMETHOD LockProfilePath(nsIFile *aDirectory, nsIFile *aTempDirectory, nsIProfileLock * *_retval) { return _to LockProfilePath(aDirectory, aTempDirectory, _retval); } \
  NS_IMETHOD CreateProfile(nsIFile *aRootDir, nsIFile *aTempDir, const nsACString & aName, nsIToolkitProfile * *_retval) { return _to CreateProfile(aRootDir, aTempDir, aName, _retval); } \
  NS_IMETHOD CreateDefaultProfileForApp(const nsACString & aProfileName, const nsACString & aAppName, const nsACString & aVendorName, nsIFile *aProfileDefaultsDir, nsIToolkitProfile * *_retval) { return _to CreateDefaultProfileForApp(aProfileName, aAppName, aVendorName, aProfileDefaultsDir, _retval); } \
  NS_IMETHOD GetProfileCount(uint32_t *aProfileCount) { return _to GetProfileCount(aProfileCount); } \
  NS_IMETHOD Flush(void) { return _to Flush(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOOLKITPROFILESERVICE(_to) \
  NS_IMETHOD GetStartWithLastProfile(bool *aStartWithLastProfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartWithLastProfile(aStartWithLastProfile); } \
  NS_IMETHOD SetStartWithLastProfile(bool aStartWithLastProfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartWithLastProfile(aStartWithLastProfile); } \
  NS_IMETHOD GetStartOffline(bool *aStartOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartOffline(aStartOffline); } \
  NS_IMETHOD SetStartOffline(bool aStartOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartOffline(aStartOffline); } \
  NS_IMETHOD GetProfiles(nsISimpleEnumerator * *aProfiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfiles(aProfiles); } \
  NS_IMETHOD GetSelectedProfile(nsIToolkitProfile * *aSelectedProfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedProfile(aSelectedProfile); } \
  NS_IMETHOD SetSelectedProfile(nsIToolkitProfile *aSelectedProfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedProfile(aSelectedProfile); } \
  NS_IMETHOD GetProfileByName(const nsACString & aName, nsIToolkitProfile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileByName(aName, _retval); } \
  NS_IMETHOD LockProfilePath(nsIFile *aDirectory, nsIFile *aTempDirectory, nsIProfileLock * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->LockProfilePath(aDirectory, aTempDirectory, _retval); } \
  NS_IMETHOD CreateProfile(nsIFile *aRootDir, nsIFile *aTempDir, const nsACString & aName, nsIToolkitProfile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateProfile(aRootDir, aTempDir, aName, _retval); } \
  NS_IMETHOD CreateDefaultProfileForApp(const nsACString & aProfileName, const nsACString & aAppName, const nsACString & aVendorName, nsIFile *aProfileDefaultsDir, nsIToolkitProfile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateDefaultProfileForApp(aProfileName, aAppName, aVendorName, aProfileDefaultsDir, _retval); } \
  NS_IMETHOD GetProfileCount(uint32_t *aProfileCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProfileCount(aProfileCount); } \
  NS_IMETHOD Flush(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Flush(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsToolkitProfileService : public nsIToolkitProfileService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOOLKITPROFILESERVICE

  nsToolkitProfileService();

private:
  ~nsToolkitProfileService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsToolkitProfileService, nsIToolkitProfileService)

nsToolkitProfileService::nsToolkitProfileService()
{
  /* member initializers and constructor code */
}

nsToolkitProfileService::~nsToolkitProfileService()
{
  /* destructor code */
}

/* attribute boolean startWithLastProfile; */
NS_IMETHODIMP nsToolkitProfileService::GetStartWithLastProfile(bool *aStartWithLastProfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsToolkitProfileService::SetStartWithLastProfile(bool aStartWithLastProfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean startOffline; */
NS_IMETHODIMP nsToolkitProfileService::GetStartOffline(bool *aStartOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsToolkitProfileService::SetStartOffline(bool aStartOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISimpleEnumerator profiles; */
NS_IMETHODIMP nsToolkitProfileService::GetProfiles(nsISimpleEnumerator * *aProfiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIToolkitProfile selectedProfile; */
NS_IMETHODIMP nsToolkitProfileService::GetSelectedProfile(nsIToolkitProfile * *aSelectedProfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsToolkitProfileService::SetSelectedProfile(nsIToolkitProfile *aSelectedProfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIToolkitProfile getProfileByName (in AUTF8String aName); */
NS_IMETHODIMP nsToolkitProfileService::GetProfileByName(const nsACString & aName, nsIToolkitProfile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIProfileLock lockProfilePath (in nsIFile aDirectory, in nsIFile aTempDirectory); */
NS_IMETHODIMP nsToolkitProfileService::LockProfilePath(nsIFile *aDirectory, nsIFile *aTempDirectory, nsIProfileLock * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIToolkitProfile createProfile (in nsIFile aRootDir, in nsIFile aTempDir, in AUTF8String aName); */
NS_IMETHODIMP nsToolkitProfileService::CreateProfile(nsIFile *aRootDir, nsIFile *aTempDir, const nsACString & aName, nsIToolkitProfile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIToolkitProfile createDefaultProfileForApp (in AUTF8String aProfileName, in AUTF8String aAppName, in AUTF8String aVendorName, [optional] in nsIFile aProfileDefaultsDir); */
NS_IMETHODIMP nsToolkitProfileService::CreateDefaultProfileForApp(const nsACString & aProfileName, const nsACString & aAppName, const nsACString & aVendorName, nsIFile *aProfileDefaultsDir, nsIToolkitProfile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long profileCount; */
NS_IMETHODIMP nsToolkitProfileService::GetProfileCount(uint32_t *aProfileCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void flush (); */
NS_IMETHODIMP nsToolkitProfileService::Flush()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_PROFILESERVICE_CONTRACTID "@mozilla.org/toolkit/profile-service;1"

#endif /* __gen_nsIToolkitProfileService_h__ */
