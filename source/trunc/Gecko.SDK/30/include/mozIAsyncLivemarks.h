/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIAsyncLivemarks.idl
 */

#ifndef __gen_mozIAsyncLivemarks_h__
#define __gen_mozIAsyncLivemarks_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class mozILivemarkCallback; /* forward declaration */

class mozILivemarkInfo; /* forward declaration */

class mozILivemark; /* forward declaration */

class nsINavHistoryResultObserver; /* forward declaration */


/* starting interface:    mozIAsyncLivemarks */
#define MOZIASYNCLIVEMARKS_IID_STR "5b48e5a2-f07a-4e64-a935-c722a3d60b65"

#define MOZIASYNCLIVEMARKS_IID \
  {0x5b48e5a2, 0xf07a, 0x4e64, \
    { 0xa9, 0x35, 0xc7, 0x22, 0xa3, 0xd6, 0x0b, 0x65 }}

class NS_NO_VTABLE mozIAsyncLivemarks : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIASYNCLIVEMARKS_IID)

  /* jsval addLivemark (in jsval aLivemarkInfo, [optional] in mozILivemarkCallback aCallback); */
  NS_IMETHOD AddLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval) = 0;

  /* jsval removeLivemark (in jsval aLivemarkInfo, [optional] in mozILivemarkCallback aCallback); */
  NS_IMETHOD RemoveLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval) = 0;

  /* jsval getLivemark (in jsval aLivemarkInfo, [optional] in mozILivemarkCallback aCallback); */
  NS_IMETHOD GetLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval) = 0;

  /* void reloadLivemarks ([optional] in boolean aForceUpdate); */
  NS_IMETHOD ReloadLivemarks(bool aForceUpdate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIAsyncLivemarks, MOZIASYNCLIVEMARKS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIASYNCLIVEMARKS \
  NS_IMETHOD AddLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval); \
  NS_IMETHOD RemoveLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval); \
  NS_IMETHOD GetLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval); \
  NS_IMETHOD ReloadLivemarks(bool aForceUpdate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIASYNCLIVEMARKS(_to) \
  NS_IMETHOD AddLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval) { return _to AddLivemark(aLivemarkInfo, aCallback, _retval); } \
  NS_IMETHOD RemoveLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval) { return _to RemoveLivemark(aLivemarkInfo, aCallback, _retval); } \
  NS_IMETHOD GetLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval) { return _to GetLivemark(aLivemarkInfo, aCallback, _retval); } \
  NS_IMETHOD ReloadLivemarks(bool aForceUpdate) { return _to ReloadLivemarks(aForceUpdate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIASYNCLIVEMARKS(_to) \
  NS_IMETHOD AddLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddLivemark(aLivemarkInfo, aCallback, _retval); } \
  NS_IMETHOD RemoveLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveLivemark(aLivemarkInfo, aCallback, _retval); } \
  NS_IMETHOD GetLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLivemark(aLivemarkInfo, aCallback, _retval); } \
  NS_IMETHOD ReloadLivemarks(bool aForceUpdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReloadLivemarks(aForceUpdate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIAsyncLivemarks
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIASYNCLIVEMARKS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIAsyncLivemarks)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* jsval addLivemark (in jsval aLivemarkInfo, [optional] in mozILivemarkCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::AddLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval removeLivemark (in jsval aLivemarkInfo, [optional] in mozILivemarkCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::RemoveLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval getLivemark (in jsval aLivemarkInfo, [optional] in mozILivemarkCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::GetLivemark(JS::HandleValue aLivemarkInfo, mozILivemarkCallback *aCallback, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reloadLivemarks ([optional] in boolean aForceUpdate); */
NS_IMETHODIMP _MYCLASS_::ReloadLivemarks(bool aForceUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozILivemarkCallback */
#define MOZILIVEMARKCALLBACK_IID_STR "62a426f9-39a6-42f0-ad48-b7404d48188f"

#define MOZILIVEMARKCALLBACK_IID \
  {0x62a426f9, 0x39a6, 0x42f0, \
    { 0xad, 0x48, 0xb7, 0x40, 0x4d, 0x48, 0x18, 0x8f }}

class NS_NO_VTABLE mozILivemarkCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZILIVEMARKCALLBACK_IID)

  /* void onCompletion (in nsresult aStatus, in mozILivemark aLivemark); */
  NS_IMETHOD OnCompletion(nsresult aStatus, mozILivemark *aLivemark) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozILivemarkCallback, MOZILIVEMARKCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZILIVEMARKCALLBACK \
  NS_IMETHOD OnCompletion(nsresult aStatus, mozILivemark *aLivemark); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZILIVEMARKCALLBACK(_to) \
  NS_IMETHOD OnCompletion(nsresult aStatus, mozILivemark *aLivemark) { return _to OnCompletion(aStatus, aLivemark); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZILIVEMARKCALLBACK(_to) \
  NS_IMETHOD OnCompletion(nsresult aStatus, mozILivemark *aLivemark) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCompletion(aStatus, aLivemark); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozILivemarkCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZILIVEMARKCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozILivemarkCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onCompletion (in nsresult aStatus, in mozILivemark aLivemark); */
NS_IMETHODIMP _MYCLASS_::OnCompletion(nsresult aStatus, mozILivemark *aLivemark)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozILivemarkInfo */
#define MOZILIVEMARKINFO_IID_STR "6e40d5b1-ce48-4458-8b68-6bee17d30ef3"

#define MOZILIVEMARKINFO_IID \
  {0x6e40d5b1, 0xce48, 0x4458, \
    { 0x8b, 0x68, 0x6b, 0xee, 0x17, 0xd3, 0x0e, 0xf3 }}

class NS_NO_VTABLE mozILivemarkInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZILIVEMARKINFO_IID)

  /* readonly attribute long long id; */
  NS_IMETHOD GetId(int64_t *aId) = 0;

  /* readonly attribute ACString guid; */
  NS_IMETHOD GetGuid(nsACString & aGuid) = 0;

  /* readonly attribute AString title; */
  NS_IMETHOD GetTitle(nsAString & aTitle) = 0;

  /* readonly attribute long long parentId; */
  NS_IMETHOD GetParentId(int64_t *aParentId) = 0;

  /* readonly attribute long index; */
  NS_IMETHOD GetIndex(int32_t *aIndex) = 0;

  /* readonly attribute PRTime lastModified; */
  NS_IMETHOD GetLastModified(PRTime *aLastModified) = 0;

  /* readonly attribute nsIURI feedURI; */
  NS_IMETHOD GetFeedURI(nsIURI * *aFeedURI) = 0;

  /* readonly attribute nsIURI siteURI; */
  NS_IMETHOD GetSiteURI(nsIURI * *aSiteURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozILivemarkInfo, MOZILIVEMARKINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZILIVEMARKINFO \
  NS_IMETHOD GetId(int64_t *aId); \
  NS_IMETHOD GetGuid(nsACString & aGuid); \
  NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_IMETHOD GetParentId(int64_t *aParentId); \
  NS_IMETHOD GetIndex(int32_t *aIndex); \
  NS_IMETHOD GetLastModified(PRTime *aLastModified); \
  NS_IMETHOD GetFeedURI(nsIURI * *aFeedURI); \
  NS_IMETHOD GetSiteURI(nsIURI * *aSiteURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZILIVEMARKINFO(_to) \
  NS_IMETHOD GetId(int64_t *aId) { return _to GetId(aId); } \
  NS_IMETHOD GetGuid(nsACString & aGuid) { return _to GetGuid(aGuid); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_IMETHOD GetParentId(int64_t *aParentId) { return _to GetParentId(aParentId); } \
  NS_IMETHOD GetIndex(int32_t *aIndex) { return _to GetIndex(aIndex); } \
  NS_IMETHOD GetLastModified(PRTime *aLastModified) { return _to GetLastModified(aLastModified); } \
  NS_IMETHOD GetFeedURI(nsIURI * *aFeedURI) { return _to GetFeedURI(aFeedURI); } \
  NS_IMETHOD GetSiteURI(nsIURI * *aSiteURI) { return _to GetSiteURI(aSiteURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZILIVEMARKINFO(_to) \
  NS_IMETHOD GetId(int64_t *aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetGuid(nsACString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGuid(aGuid); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD GetParentId(int64_t *aParentId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentId(aParentId); } \
  NS_IMETHOD GetIndex(int32_t *aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndex(aIndex); } \
  NS_IMETHOD GetLastModified(PRTime *aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_IMETHOD GetFeedURI(nsIURI * *aFeedURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFeedURI(aFeedURI); } \
  NS_IMETHOD GetSiteURI(nsIURI * *aSiteURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSiteURI(aSiteURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozILivemarkInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZILIVEMARKINFO

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozILivemarkInfo)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute long long id; */
NS_IMETHODIMP _MYCLASS_::GetId(int64_t *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString guid; */
NS_IMETHODIMP _MYCLASS_::GetGuid(nsACString & aGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString title; */
NS_IMETHODIMP _MYCLASS_::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long parentId; */
NS_IMETHODIMP _MYCLASS_::GetParentId(int64_t *aParentId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long index; */
NS_IMETHODIMP _MYCLASS_::GetIndex(int32_t *aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime lastModified; */
NS_IMETHODIMP _MYCLASS_::GetLastModified(PRTime *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI feedURI; */
NS_IMETHODIMP _MYCLASS_::GetFeedURI(nsIURI * *aFeedURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI siteURI; */
NS_IMETHODIMP _MYCLASS_::GetSiteURI(nsIURI * *aSiteURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozILivemark */
#define MOZILIVEMARK_IID_STR "9f6fdfae-db9a-4bd8-bde1-148758cf1b18"

#define MOZILIVEMARK_IID \
  {0x9f6fdfae, 0xdb9a, 0x4bd8, \
    { 0xbd, 0xe1, 0x14, 0x87, 0x58, 0xcf, 0x1b, 0x18 }}

class NS_NO_VTABLE mozILivemark : public mozILivemarkInfo {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZILIVEMARK_IID)

  enum {
    STATUS_READY = 0U,
    STATUS_LOADING = 1U,
    STATUS_FAILED = 2U
  };

  /* readonly attribute unsigned short status; */
  NS_IMETHOD GetStatus(uint16_t *aStatus) = 0;

  /* void reload ([optional] in boolean aForceUpdate); */
  NS_IMETHOD Reload(bool aForceUpdate) = 0;

  /* jsval getNodesForContainer (in jsval aContainerNode); */
  NS_IMETHOD GetNodesForContainer(JS::HandleValue aContainerNode, JS::MutableHandleValue _retval) = 0;

  /* void registerForUpdates (in jsval aContainerNode, in nsINavHistoryResultObserver aResultObserver); */
  NS_IMETHOD RegisterForUpdates(JS::HandleValue aContainerNode, nsINavHistoryResultObserver *aResultObserver) = 0;

  /* void unregisterForUpdates (in jsval aContainerNode); */
  NS_IMETHOD UnregisterForUpdates(JS::HandleValue aContainerNode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozILivemark, MOZILIVEMARK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZILIVEMARK \
  NS_IMETHOD GetStatus(uint16_t *aStatus); \
  NS_IMETHOD Reload(bool aForceUpdate); \
  NS_IMETHOD GetNodesForContainer(JS::HandleValue aContainerNode, JS::MutableHandleValue _retval); \
  NS_IMETHOD RegisterForUpdates(JS::HandleValue aContainerNode, nsINavHistoryResultObserver *aResultObserver); \
  NS_IMETHOD UnregisterForUpdates(JS::HandleValue aContainerNode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZILIVEMARK(_to) \
  NS_IMETHOD GetStatus(uint16_t *aStatus) { return _to GetStatus(aStatus); } \
  NS_IMETHOD Reload(bool aForceUpdate) { return _to Reload(aForceUpdate); } \
  NS_IMETHOD GetNodesForContainer(JS::HandleValue aContainerNode, JS::MutableHandleValue _retval) { return _to GetNodesForContainer(aContainerNode, _retval); } \
  NS_IMETHOD RegisterForUpdates(JS::HandleValue aContainerNode, nsINavHistoryResultObserver *aResultObserver) { return _to RegisterForUpdates(aContainerNode, aResultObserver); } \
  NS_IMETHOD UnregisterForUpdates(JS::HandleValue aContainerNode) { return _to UnregisterForUpdates(aContainerNode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZILIVEMARK(_to) \
  NS_IMETHOD GetStatus(uint16_t *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_IMETHOD Reload(bool aForceUpdate) { return !_to ? NS_ERROR_NULL_POINTER : _to->Reload(aForceUpdate); } \
  NS_IMETHOD GetNodesForContainer(JS::HandleValue aContainerNode, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNodesForContainer(aContainerNode, _retval); } \
  NS_IMETHOD RegisterForUpdates(JS::HandleValue aContainerNode, nsINavHistoryResultObserver *aResultObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterForUpdates(aContainerNode, aResultObserver); } \
  NS_IMETHOD UnregisterForUpdates(JS::HandleValue aContainerNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterForUpdates(aContainerNode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozILivemark
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZILIVEMARK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozILivemark)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute unsigned short status; */
NS_IMETHODIMP _MYCLASS_::GetStatus(uint16_t *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void reload ([optional] in boolean aForceUpdate); */
NS_IMETHODIMP _MYCLASS_::Reload(bool aForceUpdate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval getNodesForContainer (in jsval aContainerNode); */
NS_IMETHODIMP _MYCLASS_::GetNodesForContainer(JS::HandleValue aContainerNode, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerForUpdates (in jsval aContainerNode, in nsINavHistoryResultObserver aResultObserver); */
NS_IMETHODIMP _MYCLASS_::RegisterForUpdates(JS::HandleValue aContainerNode, nsINavHistoryResultObserver *aResultObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterForUpdates (in jsval aContainerNode); */
NS_IMETHODIMP _MYCLASS_::UnregisterForUpdates(JS::HandleValue aContainerNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIAsyncLivemarks_h__ */
