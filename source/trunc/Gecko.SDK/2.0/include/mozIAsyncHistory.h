/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/components/places/public/mozIAsyncHistory.idl
 */

#ifndef __gen_mozIAsyncHistory_h__
#define __gen_mozIAsyncHistory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */

#include "jsapi.h"

/* starting interface:    mozIVisitInfo */
#define MOZIVISITINFO_IID_STR "1a3b1260-4bdb-45d0-a306-dc377dd9baa4"

#define MOZIVISITINFO_IID \
  {0x1a3b1260, 0x4bdb, 0x45d0, \
    { 0xa3, 0x06, 0xdc, 0x37, 0x7d, 0xd9, 0xba, 0xa4 }}

/**
 * @status EXPERIMENTAL
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIVisitInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIVISITINFO_IID)

  /**
   * The machine-local (internal) id of the visit.
   */
  /* readonly attribute long long visitId; */
  NS_SCRIPTABLE NS_IMETHOD GetVisitId(PRInt64 *aVisitId) = 0;

  /**
   * The time the visit occurred.
   */
  /* readonly attribute PRTime visitDate; */
  NS_SCRIPTABLE NS_IMETHOD GetVisitDate(PRTime *aVisitDate) = 0;

  /**
   * The transition type used to get to this visit.  One of the TRANSITION_TYPE
   * constants on nsINavHistory.
   *
   * @see nsINavHistory.idl
   */
  /* readonly attribute unsigned long transitionType; */
  NS_SCRIPTABLE NS_IMETHOD GetTransitionType(PRUint32 *aTransitionType) = 0;

  /**
   * The referring URI of this visit.  This may be null.
   */
  /* readonly attribute nsIURI referrerURI; */
  NS_SCRIPTABLE NS_IMETHOD GetReferrerURI(nsIURI **aReferrerURI) = 0;

  /**
   * The sessionId of this visit.
   *
   * @see nsINavHistory.idl
   */
  /* readonly attribute long long sessionId; */
  NS_SCRIPTABLE NS_IMETHOD GetSessionId(PRInt64 *aSessionId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIVisitInfo, MOZIVISITINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIVISITINFO \
  NS_SCRIPTABLE NS_IMETHOD GetVisitId(PRInt64 *aVisitId); \
  NS_SCRIPTABLE NS_IMETHOD GetVisitDate(PRTime *aVisitDate); \
  NS_SCRIPTABLE NS_IMETHOD GetTransitionType(PRUint32 *aTransitionType); \
  NS_SCRIPTABLE NS_IMETHOD GetReferrerURI(nsIURI **aReferrerURI); \
  NS_SCRIPTABLE NS_IMETHOD GetSessionId(PRInt64 *aSessionId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIVISITINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVisitId(PRInt64 *aVisitId) { return _to GetVisitId(aVisitId); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisitDate(PRTime *aVisitDate) { return _to GetVisitDate(aVisitDate); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransitionType(PRUint32 *aTransitionType) { return _to GetTransitionType(aTransitionType); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrerURI(nsIURI **aReferrerURI) { return _to GetReferrerURI(aReferrerURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetSessionId(PRInt64 *aSessionId) { return _to GetSessionId(aSessionId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIVISITINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetVisitId(PRInt64 *aVisitId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisitId(aVisitId); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisitDate(PRTime *aVisitDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisitDate(aVisitDate); } \
  NS_SCRIPTABLE NS_IMETHOD GetTransitionType(PRUint32 *aTransitionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransitionType(aTransitionType); } \
  NS_SCRIPTABLE NS_IMETHOD GetReferrerURI(nsIURI **aReferrerURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReferrerURI(aReferrerURI); } \
  NS_SCRIPTABLE NS_IMETHOD GetSessionId(PRInt64 *aSessionId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionId(aSessionId); } 

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
NS_IMETHODIMP _MYCLASS_::GetVisitId(PRInt64 *aVisitId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime visitDate; */
NS_IMETHODIMP _MYCLASS_::GetVisitDate(PRTime *aVisitDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long transitionType; */
NS_IMETHODIMP _MYCLASS_::GetTransitionType(PRUint32 *aTransitionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI referrerURI; */
NS_IMETHODIMP _MYCLASS_::GetReferrerURI(nsIURI **aReferrerURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long sessionId; */
NS_IMETHODIMP _MYCLASS_::GetSessionId(PRInt64 *aSessionId)
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

/**
 * @status EXPERIMENTAL
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIPlaceInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIPLACEINFO_IID)

  /**
   * The machine-local (internal) id of the place.
   */
  /* readonly attribute long long placeId; */
  NS_SCRIPTABLE NS_IMETHOD GetPlaceId(PRInt64 *aPlaceId) = 0;

  /**
   * The globally unique id of the place.
   */
  /* readonly attribute ACString guid; */
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsACString & aGuid) = 0;

  /**
   * The URI of the place.
   */
  /* readonly attribute nsIURI uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) = 0;

  /**
   * The title associated with the place.
   */
  /* readonly attribute AString title; */
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) = 0;

  /**
   * The frecency of the place.
   */
  /* readonly attribute long long frecency; */
  NS_SCRIPTABLE NS_IMETHOD GetFrecency(PRInt64 *aFrecency) = 0;

  /**
   * An array of mozIVisitInfo objects for the place.
   */
  /* [implicit_jscontext] readonly attribute jsval visits; */
  NS_SCRIPTABLE NS_IMETHOD GetVisits(JSContext *cx, jsval *aVisits) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIPlaceInfo, MOZIPLACEINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIPLACEINFO \
  NS_SCRIPTABLE NS_IMETHOD GetPlaceId(PRInt64 *aPlaceId); \
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsACString & aGuid); \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri); \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetFrecency(PRInt64 *aFrecency); \
  NS_SCRIPTABLE NS_IMETHOD GetVisits(JSContext *cx, jsval *aVisits); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIPLACEINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPlaceId(PRInt64 *aPlaceId) { return _to GetPlaceId(aPlaceId); } \
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsACString & aGuid) { return _to GetGuid(aGuid); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) { return _to GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetFrecency(PRInt64 *aFrecency) { return _to GetFrecency(aFrecency); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisits(JSContext *cx, jsval *aVisits) { return _to GetVisits(cx, aVisits); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIPLACEINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetPlaceId(PRInt64 *aPlaceId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlaceId(aPlaceId); } \
  NS_SCRIPTABLE NS_IMETHOD GetGuid(nsACString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGuid(aGuid); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI **aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetFrecency(PRInt64 *aFrecency) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrecency(aFrecency); } \
  NS_SCRIPTABLE NS_IMETHOD GetVisits(JSContext *cx, jsval *aVisits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVisits(cx, aVisits); } 

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
NS_IMETHODIMP _MYCLASS_::GetPlaceId(PRInt64 *aPlaceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString guid; */
NS_IMETHODIMP _MYCLASS_::GetGuid(nsACString & aGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI uri; */
NS_IMETHODIMP _MYCLASS_::GetUri(nsIURI **aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString title; */
NS_IMETHODIMP _MYCLASS_::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long frecency; */
NS_IMETHODIMP _MYCLASS_::GetFrecency(PRInt64 *aFrecency)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval visits; */
NS_IMETHODIMP _MYCLASS_::GetVisits(JSContext *cx, jsval *aVisits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIVisitInfoCallback */
#define MOZIVISITINFOCALLBACK_IID_STR "3b97ca3c-5ea8-424f-b429-797477c52302"

#define MOZIVISITINFOCALLBACK_IID \
  {0x3b97ca3c, 0x5ea8, 0x424f, \
    { 0xb4, 0x29, 0x79, 0x74, 0x77, 0xc5, 0x23, 0x02 }}

/**
 * @status EXPERIMENTAL
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIVisitInfoCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIVISITINFOCALLBACK_IID)

  /**
   * Called for each visit added, title change, or guid change when passed to
   * mozIAsyncHistory::updatePlaces.
   *
   * @param aResultCode
   *        nsresult of the change indicating success or failure reason.
   * @param aPlaceInfo
   *        The information that was being entered into the database.
   */
  /* void onComplete (in nsresult aResultCode, in mozIPlaceInfo aPlaceInfo); */
  NS_SCRIPTABLE NS_IMETHOD OnComplete(nsresult aResultCode, mozIPlaceInfo *aPlaceInfo) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIVisitInfoCallback, MOZIVISITINFOCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIVISITINFOCALLBACK \
  NS_SCRIPTABLE NS_IMETHOD OnComplete(nsresult aResultCode, mozIPlaceInfo *aPlaceInfo); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIVISITINFOCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnComplete(nsresult aResultCode, mozIPlaceInfo *aPlaceInfo) { return _to OnComplete(aResultCode, aPlaceInfo); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIVISITINFOCALLBACK(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnComplete(nsresult aResultCode, mozIPlaceInfo *aPlaceInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnComplete(aResultCode, aPlaceInfo); } 

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

/* void onComplete (in nsresult aResultCode, in mozIPlaceInfo aPlaceInfo); */
NS_IMETHODIMP _MYCLASS_::OnComplete(nsresult aResultCode, mozIPlaceInfo *aPlaceInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIAsyncHistory */
#define MOZIASYNCHISTORY_IID_STR "f79ca67c-7e57-4511-a400-ea31001c762f"

#define MOZIASYNCHISTORY_IID \
  {0xf79ca67c, 0x7e57, 0x4511, \
    { 0xa4, 0x00, 0xea, 0x31, 0x00, 0x1c, 0x76, 0x2f }}

/**
 * @status EXPERIMENTAL
 */
class NS_NO_VTABLE NS_SCRIPTABLE mozIAsyncHistory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIASYNCHISTORY_IID)

  /**
   * Adds a set of visits for one or more mozIPlaceInfo objects, and updates
   * each mozIPlaceInfo's title or guid.
   *
   * @param aPlaceInfo
   *        The mozIPlaceInfo object[s] containing the information to store or
   *        update.  This can be a single object, or an array of objects.
   * @param [optional] aCallback
   *        Callback to be notified for each visit addition, title change, or
   *        guid change.  If more than one operation is done for a given visit,
   *        only one callback will be given (i.e. title change and add visit).
   *
   * @throws NS_ERROR_INVALID_ARG
   *         - Passing in NULL for aPlaceInfo.
   *         - Not providing at least one valid guid, or uri for all
   *           mozIPlaceInfo object[s].
   *         - Not providing an array or nothing for the visits property of
   *           mozIPlaceInfo.
   *         - Not providing a visitDate and transitionType for each
   *           mozIVisitInfo.
   *         - Providing an invalid transitionType for a mozIVisitInfo.
   */
  /* [implicit_jscontext] void updatePlaces (in jsval aPlaceInfo, [optional] in mozIVisitInfoCallback aCallback); */
  NS_SCRIPTABLE NS_IMETHOD UpdatePlaces(const jsval & aPlaceInfo, mozIVisitInfoCallback *aCallback, JSContext *cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIAsyncHistory, MOZIASYNCHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIASYNCHISTORY \
  NS_SCRIPTABLE NS_IMETHOD UpdatePlaces(const jsval & aPlaceInfo, mozIVisitInfoCallback *aCallback, JSContext *cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIASYNCHISTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD UpdatePlaces(const jsval & aPlaceInfo, mozIVisitInfoCallback *aCallback, JSContext *cx) { return _to UpdatePlaces(aPlaceInfo, aCallback, cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIASYNCHISTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD UpdatePlaces(const jsval & aPlaceInfo, mozIVisitInfoCallback *aCallback, JSContext *cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdatePlaces(aPlaceInfo, aCallback, cx); } 

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

/* [implicit_jscontext] void updatePlaces (in jsval aPlaceInfo, [optional] in mozIVisitInfoCallback aCallback); */
NS_IMETHODIMP _MYCLASS_::UpdatePlaces(const jsval & aPlaceInfo, mozIVisitInfoCallback *aCallback, JSContext *cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_mozIAsyncHistory_h__ */
