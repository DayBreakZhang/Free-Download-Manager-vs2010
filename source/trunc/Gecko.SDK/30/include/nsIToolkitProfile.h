/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIToolkitProfile.idl
 */

#ifndef __gen_nsIToolkitProfile_h__
#define __gen_nsIToolkitProfile_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */

class nsIProfileUnlocker; /* forward declaration */


/* starting interface:    nsIProfileLock */
#define NS_IPROFILELOCK_IID_STR "7c58c703-d245-4864-8d75-9648ca4a6139"

#define NS_IPROFILELOCK_IID \
  {0x7c58c703, 0xd245, 0x4864, \
    { 0x8d, 0x75, 0x96, 0x48, 0xca, 0x4a, 0x61, 0x39 }}

class NS_NO_VTABLE nsIProfileLock : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROFILELOCK_IID)

  /* readonly attribute nsIFile directory; */
  NS_IMETHOD GetDirectory(nsIFile * *aDirectory) = 0;

  /* readonly attribute nsIFile localDirectory; */
  NS_IMETHOD GetLocalDirectory(nsIFile * *aLocalDirectory) = 0;

  /* readonly attribute PRTime replacedLockTime; */
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime) = 0;

  /* void unlock (); */
  NS_IMETHOD Unlock(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProfileLock, NS_IPROFILELOCK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROFILELOCK \
  NS_IMETHOD GetDirectory(nsIFile * *aDirectory); \
  NS_IMETHOD GetLocalDirectory(nsIFile * *aLocalDirectory); \
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime); \
  NS_IMETHOD Unlock(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROFILELOCK(_to) \
  NS_IMETHOD GetDirectory(nsIFile * *aDirectory) { return _to GetDirectory(aDirectory); } \
  NS_IMETHOD GetLocalDirectory(nsIFile * *aLocalDirectory) { return _to GetLocalDirectory(aLocalDirectory); } \
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime) { return _to GetReplacedLockTime(aReplacedLockTime); } \
  NS_IMETHOD Unlock(void) { return _to Unlock(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROFILELOCK(_to) \
  NS_IMETHOD GetDirectory(nsIFile * *aDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDirectory(aDirectory); } \
  NS_IMETHOD GetLocalDirectory(nsIFile * *aLocalDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalDirectory(aLocalDirectory); } \
  NS_IMETHOD GetReplacedLockTime(PRTime *aReplacedLockTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReplacedLockTime(aReplacedLockTime); } \
  NS_IMETHOD Unlock(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unlock(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProfileLock : public nsIProfileLock
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROFILELOCK

  nsProfileLock();

private:
  ~nsProfileLock();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProfileLock, nsIProfileLock)

nsProfileLock::nsProfileLock()
{
  /* member initializers and constructor code */
}

nsProfileLock::~nsProfileLock()
{
  /* destructor code */
}

/* readonly attribute nsIFile directory; */
NS_IMETHODIMP nsProfileLock::GetDirectory(nsIFile * *aDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile localDirectory; */
NS_IMETHODIMP nsProfileLock::GetLocalDirectory(nsIFile * *aLocalDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime replacedLockTime; */
NS_IMETHODIMP nsProfileLock::GetReplacedLockTime(PRTime *aReplacedLockTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unlock (); */
NS_IMETHODIMP nsProfileLock::Unlock()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIToolkitProfile */
#define NS_ITOOLKITPROFILE_IID_STR "7422b090-4a86-4407-972e-75468a625388"

#define NS_ITOOLKITPROFILE_IID \
  {0x7422b090, 0x4a86, 0x4407, \
    { 0x97, 0x2e, 0x75, 0x46, 0x8a, 0x62, 0x53, 0x88 }}

class NS_NO_VTABLE nsIToolkitProfile : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOOLKITPROFILE_IID)

  /* readonly attribute nsIFile rootDir; */
  NS_IMETHOD GetRootDir(nsIFile * *aRootDir) = 0;

  /* readonly attribute nsIFile localDir; */
  NS_IMETHOD GetLocalDir(nsIFile * *aLocalDir) = 0;

  /* attribute AUTF8String name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;
  NS_IMETHOD SetName(const nsACString & aName) = 0;

  /* void remove (in boolean removeFiles); */
  NS_IMETHOD Remove(bool removeFiles) = 0;

  /* nsIProfileLock lock (out nsIProfileUnlocker aUnlocker); */
  NS_IMETHOD Lock(nsIProfileUnlocker * *aUnlocker, nsIProfileLock * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIToolkitProfile, NS_ITOOLKITPROFILE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOOLKITPROFILE \
  NS_IMETHOD GetRootDir(nsIFile * *aRootDir); \
  NS_IMETHOD GetLocalDir(nsIFile * *aLocalDir); \
  NS_IMETHOD GetName(nsACString & aName); \
  NS_IMETHOD SetName(const nsACString & aName); \
  NS_IMETHOD Remove(bool removeFiles); \
  NS_IMETHOD Lock(nsIProfileUnlocker * *aUnlocker, nsIProfileLock * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOOLKITPROFILE(_to) \
  NS_IMETHOD GetRootDir(nsIFile * *aRootDir) { return _to GetRootDir(aRootDir); } \
  NS_IMETHOD GetLocalDir(nsIFile * *aLocalDir) { return _to GetLocalDir(aLocalDir); } \
  NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsACString & aName) { return _to SetName(aName); } \
  NS_IMETHOD Remove(bool removeFiles) { return _to Remove(removeFiles); } \
  NS_IMETHOD Lock(nsIProfileUnlocker * *aUnlocker, nsIProfileLock * *_retval) { return _to Lock(aUnlocker, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOOLKITPROFILE(_to) \
  NS_IMETHOD GetRootDir(nsIFile * *aRootDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootDir(aRootDir); } \
  NS_IMETHOD GetLocalDir(nsIFile * *aLocalDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalDir(aLocalDir); } \
  NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD Remove(bool removeFiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(removeFiles); } \
  NS_IMETHOD Lock(nsIProfileUnlocker * *aUnlocker, nsIProfileLock * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Lock(aUnlocker, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsToolkitProfile : public nsIToolkitProfile
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOOLKITPROFILE

  nsToolkitProfile();

private:
  ~nsToolkitProfile();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsToolkitProfile, nsIToolkitProfile)

nsToolkitProfile::nsToolkitProfile()
{
  /* member initializers and constructor code */
}

nsToolkitProfile::~nsToolkitProfile()
{
  /* destructor code */
}

/* readonly attribute nsIFile rootDir; */
NS_IMETHODIMP nsToolkitProfile::GetRootDir(nsIFile * *aRootDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile localDir; */
NS_IMETHODIMP nsToolkitProfile::GetLocalDir(nsIFile * *aLocalDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AUTF8String name; */
NS_IMETHODIMP nsToolkitProfile::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsToolkitProfile::SetName(const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in boolean removeFiles); */
NS_IMETHODIMP nsToolkitProfile::Remove(bool removeFiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIProfileLock lock (out nsIProfileUnlocker aUnlocker); */
NS_IMETHODIMP nsToolkitProfile::Lock(nsIProfileUnlocker * *aUnlocker, nsIProfileLock * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIToolkitProfile_h__ */
