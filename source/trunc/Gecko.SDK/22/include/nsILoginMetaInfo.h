/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/passwordmgr/nsILoginMetaInfo.idl
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

class NS_NO_VTABLE nsILoginMetaInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOGINMETAINFO_IID)

  /* attribute AString guid; */
  NS_IMETHOD GetGuid(nsAString & aGuid) = 0;
  NS_IMETHOD SetGuid(const nsAString & aGuid) = 0;

  /* attribute unsigned long long timeCreated; */
  NS_IMETHOD GetTimeCreated(uint64_t *aTimeCreated) = 0;
  NS_IMETHOD SetTimeCreated(uint64_t aTimeCreated) = 0;

  /* attribute unsigned long long timeLastUsed; */
  NS_IMETHOD GetTimeLastUsed(uint64_t *aTimeLastUsed) = 0;
  NS_IMETHOD SetTimeLastUsed(uint64_t aTimeLastUsed) = 0;

  /* attribute unsigned long long timePasswordChanged; */
  NS_IMETHOD GetTimePasswordChanged(uint64_t *aTimePasswordChanged) = 0;
  NS_IMETHOD SetTimePasswordChanged(uint64_t aTimePasswordChanged) = 0;

  /* attribute unsigned long timesUsed; */
  NS_IMETHOD GetTimesUsed(uint32_t *aTimesUsed) = 0;
  NS_IMETHOD SetTimesUsed(uint32_t aTimesUsed) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoginMetaInfo, NS_ILOGINMETAINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOGINMETAINFO \
  NS_IMETHOD GetGuid(nsAString & aGuid); \
  NS_IMETHOD SetGuid(const nsAString & aGuid); \
  NS_IMETHOD GetTimeCreated(uint64_t *aTimeCreated); \
  NS_IMETHOD SetTimeCreated(uint64_t aTimeCreated); \
  NS_IMETHOD GetTimeLastUsed(uint64_t *aTimeLastUsed); \
  NS_IMETHOD SetTimeLastUsed(uint64_t aTimeLastUsed); \
  NS_IMETHOD GetTimePasswordChanged(uint64_t *aTimePasswordChanged); \
  NS_IMETHOD SetTimePasswordChanged(uint64_t aTimePasswordChanged); \
  NS_IMETHOD GetTimesUsed(uint32_t *aTimesUsed); \
  NS_IMETHOD SetTimesUsed(uint32_t aTimesUsed); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOGINMETAINFO(_to) \
  NS_IMETHOD GetGuid(nsAString & aGuid) { return _to GetGuid(aGuid); } \
  NS_IMETHOD SetGuid(const nsAString & aGuid) { return _to SetGuid(aGuid); } \
  NS_IMETHOD GetTimeCreated(uint64_t *aTimeCreated) { return _to GetTimeCreated(aTimeCreated); } \
  NS_IMETHOD SetTimeCreated(uint64_t aTimeCreated) { return _to SetTimeCreated(aTimeCreated); } \
  NS_IMETHOD GetTimeLastUsed(uint64_t *aTimeLastUsed) { return _to GetTimeLastUsed(aTimeLastUsed); } \
  NS_IMETHOD SetTimeLastUsed(uint64_t aTimeLastUsed) { return _to SetTimeLastUsed(aTimeLastUsed); } \
  NS_IMETHOD GetTimePasswordChanged(uint64_t *aTimePasswordChanged) { return _to GetTimePasswordChanged(aTimePasswordChanged); } \
  NS_IMETHOD SetTimePasswordChanged(uint64_t aTimePasswordChanged) { return _to SetTimePasswordChanged(aTimePasswordChanged); } \
  NS_IMETHOD GetTimesUsed(uint32_t *aTimesUsed) { return _to GetTimesUsed(aTimesUsed); } \
  NS_IMETHOD SetTimesUsed(uint32_t aTimesUsed) { return _to SetTimesUsed(aTimesUsed); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOGINMETAINFO(_to) \
  NS_IMETHOD GetGuid(nsAString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGuid(aGuid); } \
  NS_IMETHOD SetGuid(const nsAString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGuid(aGuid); } \
  NS_IMETHOD GetTimeCreated(uint64_t *aTimeCreated) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeCreated(aTimeCreated); } \
  NS_IMETHOD SetTimeCreated(uint64_t aTimeCreated) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeCreated(aTimeCreated); } \
  NS_IMETHOD GetTimeLastUsed(uint64_t *aTimeLastUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeLastUsed(aTimeLastUsed); } \
  NS_IMETHOD SetTimeLastUsed(uint64_t aTimeLastUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeLastUsed(aTimeLastUsed); } \
  NS_IMETHOD GetTimePasswordChanged(uint64_t *aTimePasswordChanged) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimePasswordChanged(aTimePasswordChanged); } \
  NS_IMETHOD SetTimePasswordChanged(uint64_t aTimePasswordChanged) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimePasswordChanged(aTimePasswordChanged); } \
  NS_IMETHOD GetTimesUsed(uint32_t *aTimesUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimesUsed(aTimesUsed); } \
  NS_IMETHOD SetTimesUsed(uint32_t aTimesUsed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimesUsed(aTimesUsed); } 

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
NS_IMETHODIMP nsLoginMetaInfo::GetTimeCreated(uint64_t *aTimeCreated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginMetaInfo::SetTimeCreated(uint64_t aTimeCreated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long long timeLastUsed; */
NS_IMETHODIMP nsLoginMetaInfo::GetTimeLastUsed(uint64_t *aTimeLastUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginMetaInfo::SetTimeLastUsed(uint64_t aTimeLastUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long long timePasswordChanged; */
NS_IMETHODIMP nsLoginMetaInfo::GetTimePasswordChanged(uint64_t *aTimePasswordChanged)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginMetaInfo::SetTimePasswordChanged(uint64_t aTimePasswordChanged)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long timesUsed; */
NS_IMETHODIMP nsLoginMetaInfo::GetTimesUsed(uint32_t *aTimesUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsLoginMetaInfo::SetTimesUsed(uint32_t aTimesUsed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoginMetaInfo_h__ */
