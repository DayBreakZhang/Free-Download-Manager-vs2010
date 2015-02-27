/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/components/passwordmgr/public/nsILoginMetaInfo.idl
 */

#ifndef __gen_nsILoginMetaInfo_h__
#define __gen_nsILoginMetaInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILoginMetaInfo */
#define NS_ILOGINMETAINFO_IID_STR "20d8eb40-c494-497f-b2a6-aaa32f807ebd"

#define NS_ILOGINMETAINFO_IID \
  {0x20d8eb40, 0xc494, 0x497f, \
    { 0xb2, 0xa6, 0xaa, 0xa3, 0x2f, 0x80, 0x7e, 0xbd }}

/**
 * An object containing metainfo for a login stored by the login manager.
 *
 * Code using login manager can generally ignore this interface. When adding
 * logins, default value will be created. When modifying logins, these
 * properties will be unchanged unless a change is explicitly requested [by
 * using modifyLogin() with a nsIPropertyBag]. When deleting a login or
 * comparing logins, these properties are ignored.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsILoginMetaInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMETAINFO_IID)

  /**
     * The GUID to uniquely identify the login. This can be any arbitrary
     * string, but a format as created by nsIUUIDGenerator is recommended.
     * For example, "{d4e1a1f6-5ea0-40ee-bff5-da57982f21cf}"
     *
     * addLogin will generate a random value unless a value is provided.
     *
     * addLogin and modifyLogin will throw if the GUID already exists.
     */
  /* attribute AString guid; */
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsAString & aGuid) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetGuid(const nsAString & aGuid) = 0;

  /**
     * The time, in Unix Epoch milliseconds, when the login was first created.
     */
  /* attribute unsigned long long timeCreated; */
  NS_SCRIPTABLE NS_IMETHOD GetTimeCreated(PRUint64 *aTimeCreated) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTimeCreated(PRUint64 aTimeCreated) = 0;

  /**
     * The time, in Unix Epoch milliseconds, when the login was last submitted
     * in a form or used to begin an HTTP auth session.
     */
  /* attribute unsigned long long timeLastUsed; */
  NS_SCRIPTABLE NS_IMETHOD GetTimeLastUsed(PRUint64 *aTimeLastUsed) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTimeLastUsed(PRUint64 aTimeLastUsed) = 0;

  /**
     * The time, in Unix Epoch milliseconds, when the login's password was
     * last modified.
     */
  /* attribute unsigned long long timePasswordChanged; */
  NS_SCRIPTABLE NS_IMETHOD GetTimePasswordChanged(PRUint64 *aTimePasswordChanged) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTimePasswordChanged(PRUint64 aTimePasswordChanged) = 0;

  /**
     * The number of times the login was submitted in a form or used to begin
     * an HTTP auth session.
     */
  /* attribute unsigned long timesUsed; */
  NS_SCRIPTABLE NS_IMETHOD GetTimesUsed(PRUint32 *aTimesUsed) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTimesUsed(PRUint32 aTimesUsed) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginMetaInfo, NS_ILOGINMETAINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMETAINFO \
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsAString & aGuid); \
  NS_SCRIPTABLE NS_IMETHOD SetGuid(const nsAString & aGuid); \
  NS_SCRIPTABLE NS_IMETHOD GetTimeCreated(PRUint64 *aTimeCreated); \
  NS_SCRIPTABLE NS_IMETHOD SetTimeCreated(PRUint64 aTimeCreated); \
  NS_SCRIPTABLE NS_IMETHOD GetTimeLastUsed(PRUint64 *aTimeLastUsed); \
  NS_SCRIPTABLE NS_IMETHOD SetTimeLastUsed(PRUint64 aTimeLastUsed); \
  NS_SCRIPTABLE NS_IMETHOD GetTimePasswordChanged(PRUint64 *aTimePasswordChanged); \
  NS_SCRIPTABLE NS_IMETHOD SetTimePasswordChanged(PRUint64 aTimePasswordChanged); \
  NS_SCRIPTABLE NS_IMETHOD GetTimesUsed(PRUint32 *aTimesUsed); \
  NS_SCRIPTABLE NS_IMETHOD SetTimesUsed(PRUint32 aTimesUsed); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMETAINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsAString & aGuid) { return _to GetGuid(aGuid); } \
  NS_SCRIPTABLE NS_IMETHOD SetGuid(const nsAString & aGuid) { return _to SetGuid(aGuid); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeCreated(PRUint64 *aTimeCreated) { return _to GetTimeCreated(aTimeCreated); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeCreated(PRUint64 aTimeCreated) { return _to SetTimeCreated(aTimeCreated); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeLastUsed(PRUint64 *aTimeLastUsed) { return _to GetTimeLastUsed(aTimeLastUsed); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeLastUsed(PRUint64 aTimeLastUsed) { return _to SetTimeLastUsed(aTimeLastUsed); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimePasswordChanged(PRUint64 *aTimePasswordChanged) { return _to GetTimePasswordChanged(aTimePasswordChanged); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimePasswordChanged(PRUint64 aTimePasswordChanged) { return _to SetTimePasswordChanged(aTimePasswordChanged); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimesUsed(PRUint32 *aTimesUsed) { return _to GetTimesUsed(aTimesUsed); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimesUsed(PRUint32 aTimesUsed) { return _to SetTimesUsed(aTimesUsed); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMETAINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsAString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGuid(aGuid); } \
  NS_SCRIPTABLE NS_IMETHOD SetGuid(const nsAString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGuid(aGuid); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeCreated(PRUint64 *aTimeCreated) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeCreated(aTimeCreated); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeCreated(PRUint64 aTimeCreated) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeCreated(aTimeCreated); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimeLastUsed(PRUint64 *aTimeLastUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeLastUsed(aTimeLastUsed); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimeLastUsed(PRUint64 aTimeLastUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeLastUsed(aTimeLastUsed); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimePasswordChanged(PRUint64 *aTimePasswordChanged) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimePasswordChanged(aTimePasswordChanged); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimePasswordChanged(PRUint64 aTimePasswordChanged) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimePasswordChanged(aTimePasswordChanged); } \
  NS_SCRIPTABLE NS_IMETHOD GetTimesUsed(PRUint32 *aTimesUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimesUsed(aTimesUsed); } \
  NS_SCRIPTABLE NS_IMETHOD SetTimesUsed(PRUint32 aTimesUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimesUsed(aTimesUsed); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoginMetaInfo : public nsILoginMetaInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOGINMETAINFO

  nsLoginMetaInfo();

private:
  ~nsLoginMetaInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoginMetaInfo, nsILoginMetaInfo)

nsLoginMetaInfo::nsLoginMetaInfo()
{
  /* member initializers and constructor code */
}

nsLoginMetaInfo::~nsLoginMetaInfo()
{
  /* destructor code */
}

/* attribute AString guid; */
NS_IMETHODIMP nsLoginMetaInfo::GetGuid(nsAString & aGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginMetaInfo::SetGuid(const nsAString & aGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long long timeCreated; */
NS_IMETHODIMP nsLoginMetaInfo::GetTimeCreated(PRUint64 *aTimeCreated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginMetaInfo::SetTimeCreated(PRUint64 aTimeCreated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long long timeLastUsed; */
NS_IMETHODIMP nsLoginMetaInfo::GetTimeLastUsed(PRUint64 *aTimeLastUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginMetaInfo::SetTimeLastUsed(PRUint64 aTimeLastUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long long timePasswordChanged; */
NS_IMETHODIMP nsLoginMetaInfo::GetTimePasswordChanged(PRUint64 *aTimePasswordChanged)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginMetaInfo::SetTimePasswordChanged(PRUint64 aTimePasswordChanged)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long timesUsed; */
NS_IMETHODIMP nsLoginMetaInfo::GetTimesUsed(PRUint32 *aTimesUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginMetaInfo::SetTimesUsed(PRUint32 aTimesUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoginMetaInfo_h__ */
