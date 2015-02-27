/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsILoadContextInfo.idl
 */

#ifndef __gen_nsILoadContextInfo_h__
#define __gen_nsILoadContextInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsILoadContextInfo */
#define NS_ILOADCONTEXTINFO_IID_STR "1ea9cbdb-9df4-46a0-8c45-f4091aad9459"

#define NS_ILOADCONTEXTINFO_IID \
  {0x1ea9cbdb, 0x9df4, 0x46a0, \
    { 0x8c, 0x45, 0xf4, 0x09, 0x1a, 0xad, 0x94, 0x59 }}

class nsILoadContextInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILOADCONTEXTINFO_IID)

  /* readonly attribute boolean isPrivate; */
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) = 0;

  enum {
    NO_APP_ID = 0U,
    UNKNOWN_APP_ID = 4294967295U
  };

  /* readonly attribute uint32_t appId; */
  NS_IMETHOD GetAppId(uint32_t *aAppId) = 0;

  /* readonly attribute boolean isInBrowserElement; */
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) = 0;

  /* readonly attribute boolean isAnonymous; */
  NS_IMETHOD GetIsAnonymous(bool *aIsAnonymous) = 0;

   /**
   * De-XPCOMed getters
   */
  bool IsPrivate()
  {
    bool pb;
    GetIsPrivate(&pb);
    return pb;
  }
  uint32_t AppId()
  {
    uint32_t appId;
    GetAppId(&appId);
    return appId;
  }
  bool IsInBrowserElement()
  {
    bool ib;
    GetIsInBrowserElement(&ib);
    return ib;
  }
  bool IsAnonymous()
  {
    bool anon;
    GetIsAnonymous(&anon);
    return anon;
  }
};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsILoadContextInfo, NS_ILOADCONTEXTINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILOADCONTEXTINFO \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate); \
  NS_IMETHOD GetAppId(uint32_t *aAppId); \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement); \
  NS_IMETHOD GetIsAnonymous(bool *aIsAnonymous); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILOADCONTEXTINFO(_to) \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) { return _to GetIsPrivate(aIsPrivate); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) { return _to GetAppId(aAppId); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) { return _to GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetIsAnonymous(bool *aIsAnonymous) { return _to GetIsAnonymous(aIsAnonymous); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILOADCONTEXTINFO(_to) \
  NS_IMETHOD GetIsPrivate(bool *aIsPrivate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsPrivate(aIsPrivate); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppId(aAppId); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetIsAnonymous(bool *aIsAnonymous) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsAnonymous(aIsAnonymous); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsLoadContextInfo : public nsILoadContextInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILOADCONTEXTINFO

  nsLoadContextInfo();

private:
  ~nsLoadContextInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsLoadContextInfo, nsILoadContextInfo)

nsLoadContextInfo::nsLoadContextInfo()
{
  /* member initializers and constructor code */
}

nsLoadContextInfo::~nsLoadContextInfo()
{
  /* destructor code */
}

/* readonly attribute boolean isPrivate; */
NS_IMETHODIMP nsLoadContextInfo::GetIsPrivate(bool *aIsPrivate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t appId; */
NS_IMETHODIMP nsLoadContextInfo::GetAppId(uint32_t *aAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isInBrowserElement; */
NS_IMETHODIMP nsLoadContextInfo::GetIsInBrowserElement(bool *aIsInBrowserElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isAnonymous; */
NS_IMETHODIMP nsLoadContextInfo::GetIsAnonymous(bool *aIsAnonymous)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsILoadContextInfo_h__ */
