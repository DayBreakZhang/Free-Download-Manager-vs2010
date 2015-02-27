/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\mozIAsyncHistory.idl
 */

#ifndef __gen_mozIAsyncHistory_h__
#define __gen_mozIAsyncHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    mozIVisitInfo */
#define MOZIVISITINFO_IID_STR "41e4ccc9-f0c8-4cd7-9753-7a38514b8488"

#define MOZIVISITINFO_IID \
  {0x41e4ccc9, 0xf0c8, 0x4cd7, \
    { 0x97, 0x53, 0x7a, 0x38, 0x51, 0x4b, 0x84, 0x88 }}

class NS_NO_VTABLE mozIVisitInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIVISITINFO_IID)

  /* readonly attribute long long visitId; */
  NS_IMETHOD GetVisitId(int64_t *aVisitId) = 0;

  /* readonly attribute PRTime visitDate; */
  NS_IMETHOD GetVisitDate(PRTime *aVisitDate) = 0;

  /* readonly attribute unsigned long transitionType; */
  NS_IMETHOD GetTransitionType(uint32_t *aTransitionType) = 0;

  /* readonly attribute nsIURI referrerURI; */
  NS_IMETHOD GetReferrerURI(nsIURI * *aReferrerURI) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIVisitInfo, MOZIVISITINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIVISITINFO \
  NS_IMETHOD GetVisitId(int64_t *aVisitId); \
  NS_IMETHOD GetVisitDate(PRTime *aVisitDate); \
  NS_IMETHOD GetTransitionType(uint32_t *aTransitionType); \
  NS_IMETHOD GetReferrerURI(nsIURI * *aReferrerURI); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIVISITINFO(_to) \
  NS_IMETHOD GetVisitId(int64_t *aVisitId) { return _to GetVisitId(aVisitId); } \
  NS_IMETHOD GetVisitDate(PRTime *aVisitDate) { return _to GetVisitDate(aVisitDate); } \
  NS_IMETHOD GetTransitionType(uint32_t *aTransitionType) { return _to GetTransitionType(aTransitionType); } \
  NS_IMETHOD GetReferrerURI(nsIURI * *aReferrerURI) { return _to GetReferrerURI(aReferrerURI); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIVISITINFO(_to) \
  NS_IMETHOD GetVisitId(int64_t *aVisitId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisitId(aVisitId); } \
  NS_IMETHOD GetVisitDate(PRTime *aVisitDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisitDate(aVisitDate); } \
  NS_IMETHOD GetTransitionType(uint32_t *aTransitionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransitionType(aTransitionType); } \
  NS_IMETHOD GetReferrerURI(nsIURI * *aReferrerURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrerURI(aReferrerURI); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIVisitInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIVISITINFO

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIVisitInfo)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute long long visitId; */
NS_IMETHODIMP _MYCLASS_::GetVisitId(int64_t *aVisitId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime visitDate; */
NS_IMETHODIMP _MYCLASS_::GetVisitDate(PRTime *aVisitDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long transitionType; */
NS_IMETHODIMP _MYCLASS_::GetTransitionType(uint32_t *aTransitionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI referrerURI; */
NS_IMETHODIMP _MYCLASS_::GetReferrerURI(nsIURI * *aReferrerURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIPlaceInfo */
#define MOZIPLACEINFO_IID_STR "ad83e137-c92a-4b7b-b67e-0a318811f91e"

#define MOZIPLACEINFO_IID \
  {0xad83e137, 0xc92a, 0x4b7b, \
    { 0xb6, 0x7e, 0x0a, 0x31, 0x88, 0x11, 0xf9, 0x1e }}

class NS_NO_VTABLE mozIPlaceInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIPLACEINFO_IID)

  /* readonly attribute long long placeId; */
  NS_IMETHOD GetPlaceId(int64_t *aPlaceId) = 0;

  /* readonly attribute ACString guid; */
  NS_IMETHOD GetGuid(nsACString & aGuid) = 0;

  /* readonly attribute nsIURI uri; */
  NS_IMETHOD GetUri(nsIURI * *aUri) = 0;

  /* readonly attribute AString title; */
  NS_IMETHOD GetTitle(nsAString & aTitle) = 0;

  /* readonly attribute long long frecency; */
  NS_IMETHOD GetFrecency(int64_t *aFrecency) = 0;

  /* [implicit_jscontext] readonly attribute jsval visits; */
  NS_IMETHOD GetVisits(JSContext* cx, JS::MutableHandleValue aVisits) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIPlaceInfo, MOZIPLACEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIPLACEINFO \
  NS_IMETHOD GetPlaceId(int64_t *aPlaceId); \
  NS_IMETHOD GetGuid(nsACString & aGuid); \
  NS_IMETHOD GetUri(nsIURI * *aUri); \
  NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_IMETHOD GetFrecency(int64_t *aFrecency); \
  NS_IMETHOD GetVisits(JSContext* cx, JS::MutableHandleValue aVisits); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIPLACEINFO(_to) \
  NS_IMETHOD GetPlaceId(int64_t *aPlaceId) { return _to GetPlaceId(aPlaceId); } \
  NS_IMETHOD GetGuid(nsACString & aGuid) { return _to GetGuid(aGuid); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return _to GetUri(aUri); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_IMETHOD GetFrecency(int64_t *aFrecency) { return _to GetFrecency(aFrecency); } \
  NS_IMETHOD GetVisits(JSContext* cx, JS::MutableHandleValue aVisits) { return _to GetVisits(cx, aVisits); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIPLACEINFO(_to) \
  NS_IMETHOD GetPlaceId(int64_t *aPlaceId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlaceId(aPlaceId); } \
  NS_IMETHOD GetGuid(nsACString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGuid(aGuid); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_IMETHOD GetFrecency(int64_t *aFrecency) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrecency(aFrecency); } \
  NS_IMETHOD GetVisits(JSContext* cx, JS::MutableHandleValue aVisits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisits(cx, aVisits); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIPlaceInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIPLACEINFO

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIPlaceInfo)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute long long placeId; */
NS_IMETHODIMP _MYCLASS_::GetPlaceId(int64_t *aPlaceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString guid; */
NS_IMETHODIMP _MYCLASS_::GetGuid(nsACString & aGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI uri; */
NS_IMETHODIMP _MYCLASS_::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString title; */
NS_IMETHODIMP _MYCLASS_::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long frecency; */
NS_IMETHODIMP _MYCLASS_::GetFrecency(int64_t *aFrecency)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval visits; */
NS_IMETHODIMP _MYCLASS_::GetVisits(JSContext* cx, JS::MutableHandleValue aVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIVisitInfoCallback */
#define MOZIVISITINFOCALLBACK_IID_STR "1f266877-2859-418b-a11b-ec3ae4f4f93d"

#define MOZIVISITINFOCALLBACK_IID \
  {0x1f266877, 0x2859, 0x418b, \
    { 0xa1, 0x1b, 0xec, 0x3a, 0xe4, 0xf4, 0xf9, 0x3d }}

class NS_NO_VTABLE mozIVisitInfoCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIVISITINFOCALLBACK_IID)

  /* void handleError (in nsresult aResultCode, in mozIPlaceInfo aPlaceInfo); */
  NS_IMETHOD HandleError(nsresult aResultCode, mozIPlaceInfo *aPlaceInfo) = 0;

  /* void handleResult (in mozIPlaceInfo aPlaceInfo); */
  NS_IMETHOD HandleResult(mozIPlaceInfo *aPlaceInfo) = 0;

  /* void handleCompletion (); */
  NS_IMETHOD HandleCompletion(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIVisitInfoCallback, MOZIVISITINFOCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIVISITINFOCALLBACK \
  NS_IMETHOD HandleError(nsresult aResultCode, mozIPlaceInfo *aPlaceInfo); \
  NS_IMETHOD HandleResult(mozIPlaceInfo *aPlaceInfo); \
  NS_IMETHOD HandleCompletion(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIVISITINFOCALLBACK(_to) \
  NS_IMETHOD HandleError(nsresult aResultCode, mozIPlaceInfo *aPlaceInfo) { return _to HandleError(aResultCode, aPlaceInfo); } \
  NS_IMETHOD HandleResult(mozIPlaceInfo *aPlaceInfo) { return _to HandleResult(aPlaceInfo); } \
  NS_IMETHOD HandleCompletion(void) { return _to HandleCompletion(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIVISITINFOCALLBACK(_to) \
  NS_IMETHOD HandleError(nsresult aResultCode, mozIPlaceInfo *aPlaceInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleError(aResultCode, aPlaceInfo); } \
  NS_IMETHOD HandleResult(mozIPlaceInfo *aPlaceInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleResult(aPlaceInfo); } \
  NS_IMETHOD HandleCompletion(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleCompletion(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIVisitInfoCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIVISITINFOCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIVisitInfoCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void handleError (in nsresult aResultCode, in mozIPlaceInfo aPlaceInfo); */
NS_IMETHODIMP _MYCLASS_::HandleError(nsresult aResultCode, mozIPlaceInfo *aPlaceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleResult (in mozIPlaceInfo aPlaceInfo); */
NS_IMETHODIMP _MYCLASS_::HandleResult(mozIPlaceInfo *aPlaceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void handleCompletion (); */
NS_IMETHODIMP _MYCLASS_::HandleCompletion()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIVisitedStatusCallback */
#define MOZIVISITEDSTATUSCALLBACK_IID_STR "994092bf-936f-449b-8dd6-0941e024360d"

#define MOZIVISITEDSTATUSCALLBACK_IID \
  {0x994092bf, 0x936f, 0x449b, \
    { 0x8d, 0xd6, 0x09, 0x41, 0xe0, 0x24, 0x36, 0x0d }}

class NS_NO_VTABLE mozIVisitedStatusCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIVISITEDSTATUSCALLBACK_IID)

  /* void isVisited (in nsIURI aURI, in boolean aVisitedStatus); */
  NS_IMETHOD IsVisited(nsIURI *aURI, bool aVisitedStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIVisitedStatusCallback, MOZIVISITEDSTATUSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIVISITEDSTATUSCALLBACK \
  NS_IMETHOD IsVisited(nsIURI *aURI, bool aVisitedStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIVISITEDSTATUSCALLBACK(_to) \
  NS_IMETHOD IsVisited(nsIURI *aURI, bool aVisitedStatus) { return _to IsVisited(aURI, aVisitedStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIVISITEDSTATUSCALLBACK(_to) \
  NS_IMETHOD IsVisited(nsIURI *aURI, bool aVisitedStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsVisited(aURI, aVisitedStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIVisitedStatusCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIVISITEDSTATUSCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIVisitedStatusCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void isVisited (in nsIURI aURI, in boolean aVisitedStatus); */
NS_IMETHODIMP _MYCLASS_::IsVisited(nsIURI *aURI, bool aVisitedStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIAsyncHistory */
#define MOZIASYNCHISTORY_IID_STR "1643efd2-a329-4733-a39d-17069c8d3b2d"

#define MOZIASYNCHISTORY_IID \
  {0x1643efd2, 0xa329, 0x4733, \
    { 0xa3, 0x9d, 0x17, 0x06, 0x9c, 0x8d, 0x3b, 0x2d }}

class NS_NO_VTABLE mozIAsyncHistory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIASYNCHISTORY_IID)

  /* [implicit_jscontext] void getPlacesInfo (in jsval aPlaceIdentifiers, in mozIVisitInfoCallback aCallback); */
  NS_IMETHOD GetPlacesInfo(JS::HandleValue aPlaceIdentifiers, mozIVisitInfoCallback *aCallback, JSContext* cx) = 0;

  /* [implicit_jscontext] void updatePlaces (in jsval aPlaceInfo, [optional] in mozIVisitInfoCallback aCallback); */
  NS_IMETHOD UpdatePlaces(JS::HandleValue aPlaceInfo, mozIVisitInfoCallback *aCallback, JSContext* cx) = 0;

  /* void isURIVisited (in nsIURI aURI, in mozIVisitedStatusCallback aCallback); */
  NS_IMETHOD IsURIVisited(nsIURI *aURI, mozIVisitedStatusCallback *aCallback) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIAsyncHistory, MOZIASYNCHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIASYNCHISTORY \
  NS_IMETHOD GetPlacesInfo(JS::HandleValue aPlaceIdentifiers, mozIVisitInfoCallback *aCallback, JSContext* cx); \
  NS_IMETHOD UpdatePlaces(JS::HandleValue aPlaceInfo, mozIVisitInfoCallback *aCallback, JSContext* cx); \
  NS_IMETHOD IsURIVisited(nsIURI *aURI, mozIVisitedStatusCallback *aCallback); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIASYNCHISTORY(_to) \
  NS_IMETHOD GetPlacesInfo(JS::HandleValue aPlaceIdentifiers, mozIVisitInfoCallback *aCallback, JSContext* cx) { return _to GetPlacesInfo(aPlaceIdentifiers, aCallback, cx); } \
  NS_IMETHOD UpdatePlaces(JS::HandleValue aPlaceInfo, mozIVisitInfoCallback *aCallback, JSContext* cx) { return _to UpdatePlaces(aPlaceInfo, aCallback, cx); } \
  NS_IMETHOD IsURIVisited(nsIURI *aURI, mozIVisitedStatusCallback *aCallback) { return _to IsURIVisited(aURI, aCallback); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIASYNCHISTORY(_to) \
  NS_IMETHOD GetPlacesInfo(JS::HandleValue aPlaceIdentifiers, mozIVisitInfoCallback *aCallback, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlacesInfo(aPlaceIdentifiers, aCallback, cx); } \
  NS_IMETHOD UpdatePlaces(JS::HandleValue aPlaceInfo, mozIVisitInfoCallback *aCallback, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdatePlaces(aPlaceInfo, aCallback, cx); } \
  NS_IMETHOD IsURIVisited(nsIURI *aURI, mozIVisitedStatusCallback *aCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsURIVisited(aURI, aCallback); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIAsyncHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIASYNCHISTORY

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIAsyncHistory)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* [implicit_jscontext] void getPlacesInfo (in jsval aPlaceIdentifiers, in mozIVisitInfoCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::GetPlacesInfo(JS::HandleValue aPlaceIdentifiers, mozIVisitInfoCallback *aCallback, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void updatePlaces (in jsval aPlaceInfo, [optional] in mozIVisitInfoCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::UpdatePlaces(JS::HandleValue aPlaceInfo, mozIVisitInfoCallback *aCallback, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void isURIVisited (in nsIURI aURI, in mozIVisitedStatusCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::IsURIVisited(nsIURI *aURI, mozIVisitedStatusCallback *aCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIAsyncHistory_h__ */
