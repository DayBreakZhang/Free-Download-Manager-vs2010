/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXULAppInfo.idl
 */

#ifndef __gen_nsIXULAppInfo_h__
#define __gen_nsIXULAppInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIXULAppInfo */
#define NS_IXULAPPINFO_IID_STR "1518e7d2-022a-4dae-b02e-bbe7ffcf2145"

#define NS_IXULAPPINFO_IID \
  {0x1518e7d2, 0x022a, 0x4dae, \
    { 0xb0, 0x2e, 0xbb, 0xe7, 0xff, 0xcf, 0x21, 0x45 }}

class NS_NO_VTABLE nsIXULAppInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULAPPINFO_IID)

  /* readonly attribute ACString vendor; */
  NS_IMETHOD GetVendor(nsACString & aVendor) = 0;

  /* readonly attribute ACString name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute ACString ID; */
  NS_IMETHOD GetID(nsACString & aID) = 0;

  /* readonly attribute ACString version; */
  NS_IMETHOD GetVersion(nsACString & aVersion) = 0;

  /* readonly attribute ACString appBuildID; */
  NS_IMETHOD GetAppBuildID(nsACString & aAppBuildID) = 0;

  /* readonly attribute ACString platformVersion; */
  NS_IMETHOD GetPlatformVersion(nsACString & aPlatformVersion) = 0;

  /* readonly attribute ACString platformBuildID; */
  NS_IMETHOD GetPlatformBuildID(nsACString & aPlatformBuildID) = 0;

  /* readonly attribute ACString UAName; */
  NS_IMETHOD GetUAName(nsACString & aUAName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULAppInfo, NS_IXULAPPINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULAPPINFO \
  NS_IMETHOD GetVendor(nsACString & aVendor); \
  NS_IMETHOD GetName(nsACString & aName); \
  NS_IMETHOD GetID(nsACString & aID); \
  NS_IMETHOD GetVersion(nsACString & aVersion); \
  NS_IMETHOD GetAppBuildID(nsACString & aAppBuildID); \
  NS_IMETHOD GetPlatformVersion(nsACString & aPlatformVersion); \
  NS_IMETHOD GetPlatformBuildID(nsACString & aPlatformBuildID); \
  NS_IMETHOD GetUAName(nsACString & aUAName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULAPPINFO(_to) \
  NS_IMETHOD GetVendor(nsACString & aVendor) { return _to GetVendor(aVendor); } \
  NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetID(nsACString & aID) { return _to GetID(aID); } \
  NS_IMETHOD GetVersion(nsACString & aVersion) { return _to GetVersion(aVersion); } \
  NS_IMETHOD GetAppBuildID(nsACString & aAppBuildID) { return _to GetAppBuildID(aAppBuildID); } \
  NS_IMETHOD GetPlatformVersion(nsACString & aPlatformVersion) { return _to GetPlatformVersion(aPlatformVersion); } \
  NS_IMETHOD GetPlatformBuildID(nsACString & aPlatformBuildID) { return _to GetPlatformBuildID(aPlatformBuildID); } \
  NS_IMETHOD GetUAName(nsACString & aUAName) { return _to GetUAName(aUAName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULAPPINFO(_to) \
  NS_IMETHOD GetVendor(nsACString & aVendor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVendor(aVendor); } \
  NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetID(nsACString & aID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetID(aID); } \
  NS_IMETHOD GetVersion(nsACString & aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(aVersion); } \
  NS_IMETHOD GetAppBuildID(nsACString & aAppBuildID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppBuildID(aAppBuildID); } \
  NS_IMETHOD GetPlatformVersion(nsACString & aPlatformVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatformVersion(aPlatformVersion); } \
  NS_IMETHOD GetPlatformBuildID(nsACString & aPlatformBuildID) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatformBuildID(aPlatformBuildID); } \
  NS_IMETHOD GetUAName(nsACString & aUAName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUAName(aUAName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULAppInfo : public nsIXULAppInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULAPPINFO

  nsXULAppInfo();

private:
  ~nsXULAppInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULAppInfo, nsIXULAppInfo)

nsXULAppInfo::nsXULAppInfo()
{
  /* member initializers and constructor code */
}

nsXULAppInfo::~nsXULAppInfo()
{
  /* destructor code */
}

/* readonly attribute ACString vendor; */
NS_IMETHODIMP nsXULAppInfo::GetVendor(nsACString & aVendor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString name; */
NS_IMETHODIMP nsXULAppInfo::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString ID; */
NS_IMETHODIMP nsXULAppInfo::GetID(nsACString & aID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString version; */
NS_IMETHODIMP nsXULAppInfo::GetVersion(nsACString & aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString appBuildID; */
NS_IMETHODIMP nsXULAppInfo::GetAppBuildID(nsACString & aAppBuildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString platformVersion; */
NS_IMETHODIMP nsXULAppInfo::GetPlatformVersion(nsACString & aPlatformVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString platformBuildID; */
NS_IMETHODIMP nsXULAppInfo::GetPlatformBuildID(nsACString & aPlatformBuildID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString UAName; */
NS_IMETHODIMP nsXULAppInfo::GetUAName(nsACString & aUAName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULAppInfo_h__ */
