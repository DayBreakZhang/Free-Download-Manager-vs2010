/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAnnotationService.idl
 */

#ifndef __gen_nsIAnnotationService_h__
#define __gen_nsIAnnotationService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */

class mozIAnnotatedResult; /* forward declaration */


/* starting interface:    nsIAnnotationObserver */
#define NS_IANNOTATIONOBSERVER_IID_STR "63fe98e0-6889-4c2c-ac9f-703e4bc25027"

#define NS_IANNOTATIONOBSERVER_IID \
  {0x63fe98e0, 0x6889, 0x4c2c, \
    { 0xac, 0x9f, 0x70, 0x3e, 0x4b, 0xc2, 0x50, 0x27 }}

class NS_NO_VTABLE nsIAnnotationObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IANNOTATIONOBSERVER_IID)

  /* void onPageAnnotationSet (in nsIURI aPage, in AUTF8String aName); */
  NS_IMETHOD OnPageAnnotationSet(nsIURI *aPage, const nsACString & aName) = 0;

  /* void onItemAnnotationSet (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD OnItemAnnotationSet(int64_t aItemId, const nsACString & aName) = 0;

  /* void onPageAnnotationRemoved (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD OnPageAnnotationRemoved(nsIURI *aURI, const nsACString & aName) = 0;

  /* void onItemAnnotationRemoved (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD OnItemAnnotationRemoved(int64_t aItemId, const nsACString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAnnotationObserver, NS_IANNOTATIONOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIANNOTATIONOBSERVER \
  NS_IMETHOD OnPageAnnotationSet(nsIURI *aPage, const nsACString & aName); \
  NS_IMETHOD OnItemAnnotationSet(int64_t aItemId, const nsACString & aName); \
  NS_IMETHOD OnPageAnnotationRemoved(nsIURI *aURI, const nsACString & aName); \
  NS_IMETHOD OnItemAnnotationRemoved(int64_t aItemId, const nsACString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIANNOTATIONOBSERVER(_to) \
  NS_IMETHOD OnPageAnnotationSet(nsIURI *aPage, const nsACString & aName) { return _to OnPageAnnotationSet(aPage, aName); } \
  NS_IMETHOD OnItemAnnotationSet(int64_t aItemId, const nsACString & aName) { return _to OnItemAnnotationSet(aItemId, aName); } \
  NS_IMETHOD OnPageAnnotationRemoved(nsIURI *aURI, const nsACString & aName) { return _to OnPageAnnotationRemoved(aURI, aName); } \
  NS_IMETHOD OnItemAnnotationRemoved(int64_t aItemId, const nsACString & aName) { return _to OnItemAnnotationRemoved(aItemId, aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIANNOTATIONOBSERVER(_to) \
  NS_IMETHOD OnPageAnnotationSet(nsIURI *aPage, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPageAnnotationSet(aPage, aName); } \
  NS_IMETHOD OnItemAnnotationSet(int64_t aItemId, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemAnnotationSet(aItemId, aName); } \
  NS_IMETHOD OnPageAnnotationRemoved(nsIURI *aURI, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPageAnnotationRemoved(aURI, aName); } \
  NS_IMETHOD OnItemAnnotationRemoved(int64_t aItemId, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnItemAnnotationRemoved(aItemId, aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAnnotationObserver : public nsIAnnotationObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIANNOTATIONOBSERVER

  nsAnnotationObserver();

private:
  ~nsAnnotationObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAnnotationObserver, nsIAnnotationObserver)

nsAnnotationObserver::nsAnnotationObserver()
{
  /* member initializers and constructor code */
}

nsAnnotationObserver::~nsAnnotationObserver()
{
  /* destructor code */
}

/* void onPageAnnotationSet (in nsIURI aPage, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationObserver::OnPageAnnotationSet(nsIURI *aPage, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemAnnotationSet (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationObserver::OnItemAnnotationSet(int64_t aItemId, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPageAnnotationRemoved (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationObserver::OnPageAnnotationRemoved(nsIURI *aURI, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onItemAnnotationRemoved (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationObserver::OnItemAnnotationRemoved(int64_t aItemId, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAnnotationService */
#define NS_IANNOTATIONSERVICE_IID_STR "d4cdaab1-8eec-47a8-b420-ad7cb333056a"

#define NS_IANNOTATIONSERVICE_IID \
  {0xd4cdaab1, 0x8eec, 0x47a8, \
    { 0xb4, 0x20, 0xad, 0x7c, 0xb3, 0x33, 0x05, 0x6a }}

class NS_NO_VTABLE nsIAnnotationService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IANNOTATIONSERVICE_IID)

  enum {
    EXPIRE_SESSION = 0U,
    EXPIRE_WEEKS = 2U,
    EXPIRE_MONTHS = 3U,
    EXPIRE_NEVER = 4U,
    EXPIRE_WITH_HISTORY = 5U,
    EXPIRE_DAYS = 6U,
    TYPE_INT32 = 1U,
    TYPE_DOUBLE = 2U,
    TYPE_STRING = 3U,
    TYPE_INT64 = 5U
  };

  /* void setPageAnnotation (in nsIURI aURI, in AUTF8String aName, in nsIVariant aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant *aValue, int32_t aFlags, uint16_t aExpiration) = 0;

  /* void setItemAnnotation (in long long aItemId, in AUTF8String aName, in nsIVariant aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetItemAnnotation(int64_t aItemId, const nsACString & aName, nsIVariant *aValue, int32_t aFlags, uint16_t aExpiration) = 0;

  /* [noscript] void setPageAnnotationString (in nsIURI aURI, in AUTF8String aName, in AString aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetPageAnnotationString(nsIURI *aURI, const nsACString & aName, const nsAString & aValue, int32_t aFlags, uint16_t aExpiration) = 0;

  /* [noscript] void setItemAnnotationString (in long long aItemId, in AUTF8String aName, in AString aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetItemAnnotationString(int64_t aItemId, const nsACString & aName, const nsAString & aValue, int32_t aFlags, uint16_t aExpiration) = 0;

  /* [noscript] void setPageAnnotationInt32 (in nsIURI aURI, in AUTF8String aName, in long aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, int32_t aValue, int32_t aFlags, uint16_t aExpiration) = 0;

  /* [noscript] void setItemAnnotationInt32 (in long long aItemId, in AUTF8String aName, in long aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetItemAnnotationInt32(int64_t aItemId, const nsACString & aName, int32_t aValue, int32_t aFlags, uint16_t aExpiration) = 0;

  /* [noscript] void setPageAnnotationInt64 (in nsIURI aURI, in AUTF8String aName, in long long aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, int64_t aValue, int32_t aFlags, uint16_t aExpiration) = 0;

  /* [noscript] void setItemAnnotationInt64 (in long long aItemId, in AUTF8String aName, in long long aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetItemAnnotationInt64(int64_t aItemId, const nsACString & aName, int64_t aValue, int32_t aFlags, uint16_t aExpiration) = 0;

  /* [noscript] void setPageAnnotationDouble (in nsIURI aURI, in AUTF8String aName, in double aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double aValue, int32_t aFlags, uint16_t aExpiration) = 0;

  /* [noscript] void setItemAnnotationDouble (in long long aItemId, in AUTF8String aName, in double aValue, in long aFlags, in unsigned short aExpiration); */
  NS_IMETHOD SetItemAnnotationDouble(int64_t aItemId, const nsACString & aName, double aValue, int32_t aFlags, uint16_t aExpiration) = 0;

  /* nsIVariant getPageAnnotation (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD GetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant * *_retval) = 0;

  /* nsIVariant getItemAnnotation (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD GetItemAnnotation(int64_t aItemId, const nsACString & aName, nsIVariant * *_retval) = 0;

  /* [noscript] AString getPageAnnotationString (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD GetPageAnnotationString(nsIURI *aURI, const nsACString & aName, nsAString & _retval) = 0;

  /* [noscript] AString getItemAnnotationString (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD GetItemAnnotationString(int64_t aItemId, const nsACString & aName, nsAString & _retval) = 0;

  /* [noscript] long getPageAnnotationInt32 (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD GetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, int32_t *_retval) = 0;

  /* [noscript] long getItemAnnotationInt32 (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD GetItemAnnotationInt32(int64_t aItemId, const nsACString & aName, int32_t *_retval) = 0;

  /* [noscript] long long getPageAnnotationInt64 (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD GetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, int64_t *_retval) = 0;

  /* [noscript] long long getItemAnnotationInt64 (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD GetItemAnnotationInt64(int64_t aItemId, const nsACString & aName, int64_t *_retval) = 0;

  /* [noscript] double getPageAnnotationDouble (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD GetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double *_retval) = 0;

  /* [noscript] double getItemAnnotationDouble (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD GetItemAnnotationDouble(int64_t aItemId, const nsACString & aName, double *_retval) = 0;

  /* void getPageAnnotationInfo (in nsIURI aURI, in AUTF8String aName, out int32_t aFlags, out unsigned short aExpiration, out unsigned short aType); */
  NS_IMETHOD GetPageAnnotationInfo(nsIURI *aURI, const nsACString & aName, int32_t *aFlags, uint16_t *aExpiration, uint16_t *aType) = 0;

  /* void getItemAnnotationInfo (in long long aItemId, in AUTF8String aName, out long aFlags, out unsigned short aExpiration, out unsigned short aType); */
  NS_IMETHOD GetItemAnnotationInfo(int64_t aItemId, const nsACString & aName, int32_t *aFlags, uint16_t *aExpiration, uint16_t *aType) = 0;

  /* uint16_t getPageAnnotationType (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD GetPageAnnotationType(nsIURI *aURI, const nsACString & aName, uint16_t *_retval) = 0;

  /* uint16_t getItemAnnotationType (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD GetItemAnnotationType(int64_t aItemId, const nsACString & aName, uint16_t *_retval) = 0;

  /* void getPagesWithAnnotation (in AUTF8String name, [optional] out unsigned long resultCount, [array, size_is (resultCount), retval] out nsIURI results); */
  NS_IMETHOD GetPagesWithAnnotation(const nsACString & name, uint32_t *resultCount, nsIURI * **results) = 0;

  /* void getItemsWithAnnotation (in AUTF8String name, [optional] out unsigned long resultCount, [array, size_is (resultCount), retval] out long long results); */
  NS_IMETHOD GetItemsWithAnnotation(const nsACString & name, uint32_t *resultCount, int64_t **results) = 0;

  /* void getAnnotationsWithName (in AUTF8String name, [optional] out unsigned long count, [array, size_is (count), retval] out mozIAnnotatedResult results); */
  NS_IMETHOD GetAnnotationsWithName(const nsACString & name, uint32_t *count, mozIAnnotatedResult * **results) = 0;

  /* void getPageAnnotationNames (in nsIURI aURI, [optional] out unsigned long count, [array, size_is (count), retval] out nsIVariant result); */
  NS_IMETHOD GetPageAnnotationNames(nsIURI *aURI, uint32_t *count, nsIVariant * **result) = 0;

  /* void getItemAnnotationNames (in long long aItemId, [optional] out unsigned long count, [array, size_is (count), retval] out nsIVariant result); */
  NS_IMETHOD GetItemAnnotationNames(int64_t aItemId, uint32_t *count, nsIVariant * **result) = 0;

  /* boolean pageHasAnnotation (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD PageHasAnnotation(nsIURI *aURI, const nsACString & aName, bool *_retval) = 0;

  /* boolean itemHasAnnotation (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD ItemHasAnnotation(int64_t aItemId, const nsACString & aName, bool *_retval) = 0;

  /* void removePageAnnotation (in nsIURI aURI, in AUTF8String aName); */
  NS_IMETHOD RemovePageAnnotation(nsIURI *aURI, const nsACString & aName) = 0;

  /* void removeItemAnnotation (in long long aItemId, in AUTF8String aName); */
  NS_IMETHOD RemoveItemAnnotation(int64_t aItemId, const nsACString & aName) = 0;

  /* void removePageAnnotations (in nsIURI aURI); */
  NS_IMETHOD RemovePageAnnotations(nsIURI *aURI) = 0;

  /* void removeItemAnnotations (in long long aItemId); */
  NS_IMETHOD RemoveItemAnnotations(int64_t aItemId) = 0;

  /* void copyPageAnnotations (in nsIURI aSourceURI, in nsIURI aDestURI, in boolean aOverwriteDest); */
  NS_IMETHOD CopyPageAnnotations(nsIURI *aSourceURI, nsIURI *aDestURI, bool aOverwriteDest) = 0;

  /* void copyItemAnnotations (in long long aSourceItemId, in long long aDestItemId, in boolean aOverwriteDest); */
  NS_IMETHOD CopyItemAnnotations(int64_t aSourceItemId, int64_t aDestItemId, bool aOverwriteDest) = 0;

  /* void addObserver (in nsIAnnotationObserver aObserver); */
  NS_IMETHOD AddObserver(nsIAnnotationObserver *aObserver) = 0;

  /* void removeObserver (in nsIAnnotationObserver aObserver); */
  NS_IMETHOD RemoveObserver(nsIAnnotationObserver *aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAnnotationService, NS_IANNOTATIONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIANNOTATIONSERVICE \
  NS_IMETHOD SetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant *aValue, int32_t aFlags, uint16_t aExpiration); \
  NS_IMETHOD SetItemAnnotation(int64_t aItemId, const nsACString & aName, nsIVariant *aValue, int32_t aFlags, uint16_t aExpiration); \
  NS_IMETHOD SetPageAnnotationString(nsIURI *aURI, const nsACString & aName, const nsAString & aValue, int32_t aFlags, uint16_t aExpiration); \
  NS_IMETHOD SetItemAnnotationString(int64_t aItemId, const nsACString & aName, const nsAString & aValue, int32_t aFlags, uint16_t aExpiration); \
  NS_IMETHOD SetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, int32_t aValue, int32_t aFlags, uint16_t aExpiration); \
  NS_IMETHOD SetItemAnnotationInt32(int64_t aItemId, const nsACString & aName, int32_t aValue, int32_t aFlags, uint16_t aExpiration); \
  NS_IMETHOD SetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, int64_t aValue, int32_t aFlags, uint16_t aExpiration); \
  NS_IMETHOD SetItemAnnotationInt64(int64_t aItemId, const nsACString & aName, int64_t aValue, int32_t aFlags, uint16_t aExpiration); \
  NS_IMETHOD SetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double aValue, int32_t aFlags, uint16_t aExpiration); \
  NS_IMETHOD SetItemAnnotationDouble(int64_t aItemId, const nsACString & aName, double aValue, int32_t aFlags, uint16_t aExpiration); \
  NS_IMETHOD GetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant * *_retval); \
  NS_IMETHOD GetItemAnnotation(int64_t aItemId, const nsACString & aName, nsIVariant * *_retval); \
  NS_IMETHOD GetPageAnnotationString(nsIURI *aURI, const nsACString & aName, nsAString & _retval); \
  NS_IMETHOD GetItemAnnotationString(int64_t aItemId, const nsACString & aName, nsAString & _retval); \
  NS_IMETHOD GetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, int32_t *_retval); \
  NS_IMETHOD GetItemAnnotationInt32(int64_t aItemId, const nsACString & aName, int32_t *_retval); \
  NS_IMETHOD GetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, int64_t *_retval); \
  NS_IMETHOD GetItemAnnotationInt64(int64_t aItemId, const nsACString & aName, int64_t *_retval); \
  NS_IMETHOD GetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double *_retval); \
  NS_IMETHOD GetItemAnnotationDouble(int64_t aItemId, const nsACString & aName, double *_retval); \
  NS_IMETHOD GetPageAnnotationInfo(nsIURI *aURI, const nsACString & aName, int32_t *aFlags, uint16_t *aExpiration, uint16_t *aType); \
  NS_IMETHOD GetItemAnnotationInfo(int64_t aItemId, const nsACString & aName, int32_t *aFlags, uint16_t *aExpiration, uint16_t *aType); \
  NS_IMETHOD GetPageAnnotationType(nsIURI *aURI, const nsACString & aName, uint16_t *_retval); \
  NS_IMETHOD GetItemAnnotationType(int64_t aItemId, const nsACString & aName, uint16_t *_retval); \
  NS_IMETHOD GetPagesWithAnnotation(const nsACString & name, uint32_t *resultCount, nsIURI * **results); \
  NS_IMETHOD GetItemsWithAnnotation(const nsACString & name, uint32_t *resultCount, int64_t **results); \
  NS_IMETHOD GetAnnotationsWithName(const nsACString & name, uint32_t *count, mozIAnnotatedResult * **results); \
  NS_IMETHOD GetPageAnnotationNames(nsIURI *aURI, uint32_t *count, nsIVariant * **result); \
  NS_IMETHOD GetItemAnnotationNames(int64_t aItemId, uint32_t *count, nsIVariant * **result); \
  NS_IMETHOD PageHasAnnotation(nsIURI *aURI, const nsACString & aName, bool *_retval); \
  NS_IMETHOD ItemHasAnnotation(int64_t aItemId, const nsACString & aName, bool *_retval); \
  NS_IMETHOD RemovePageAnnotation(nsIURI *aURI, const nsACString & aName); \
  NS_IMETHOD RemoveItemAnnotation(int64_t aItemId, const nsACString & aName); \
  NS_IMETHOD RemovePageAnnotations(nsIURI *aURI); \
  NS_IMETHOD RemoveItemAnnotations(int64_t aItemId); \
  NS_IMETHOD CopyPageAnnotations(nsIURI *aSourceURI, nsIURI *aDestURI, bool aOverwriteDest); \
  NS_IMETHOD CopyItemAnnotations(int64_t aSourceItemId, int64_t aDestItemId, bool aOverwriteDest); \
  NS_IMETHOD AddObserver(nsIAnnotationObserver *aObserver); \
  NS_IMETHOD RemoveObserver(nsIAnnotationObserver *aObserver); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIANNOTATIONSERVICE(_to) \
  NS_IMETHOD SetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant *aValue, int32_t aFlags, uint16_t aExpiration) { return _to SetPageAnnotation(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotation(int64_t aItemId, const nsACString & aName, nsIVariant *aValue, int32_t aFlags, uint16_t aExpiration) { return _to SetItemAnnotation(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationString(nsIURI *aURI, const nsACString & aName, const nsAString & aValue, int32_t aFlags, uint16_t aExpiration) { return _to SetPageAnnotationString(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationString(int64_t aItemId, const nsACString & aName, const nsAString & aValue, int32_t aFlags, uint16_t aExpiration) { return _to SetItemAnnotationString(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, int32_t aValue, int32_t aFlags, uint16_t aExpiration) { return _to SetPageAnnotationInt32(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationInt32(int64_t aItemId, const nsACString & aName, int32_t aValue, int32_t aFlags, uint16_t aExpiration) { return _to SetItemAnnotationInt32(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, int64_t aValue, int32_t aFlags, uint16_t aExpiration) { return _to SetPageAnnotationInt64(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationInt64(int64_t aItemId, const nsACString & aName, int64_t aValue, int32_t aFlags, uint16_t aExpiration) { return _to SetItemAnnotationInt64(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double aValue, int32_t aFlags, uint16_t aExpiration) { return _to SetPageAnnotationDouble(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationDouble(int64_t aItemId, const nsACString & aName, double aValue, int32_t aFlags, uint16_t aExpiration) { return _to SetItemAnnotationDouble(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD GetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant * *_retval) { return _to GetPageAnnotation(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotation(int64_t aItemId, const nsACString & aName, nsIVariant * *_retval) { return _to GetItemAnnotation(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationString(nsIURI *aURI, const nsACString & aName, nsAString & _retval) { return _to GetPageAnnotationString(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationString(int64_t aItemId, const nsACString & aName, nsAString & _retval) { return _to GetItemAnnotationString(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, int32_t *_retval) { return _to GetPageAnnotationInt32(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationInt32(int64_t aItemId, const nsACString & aName, int32_t *_retval) { return _to GetItemAnnotationInt32(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, int64_t *_retval) { return _to GetPageAnnotationInt64(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationInt64(int64_t aItemId, const nsACString & aName, int64_t *_retval) { return _to GetItemAnnotationInt64(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double *_retval) { return _to GetPageAnnotationDouble(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationDouble(int64_t aItemId, const nsACString & aName, double *_retval) { return _to GetItemAnnotationDouble(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationInfo(nsIURI *aURI, const nsACString & aName, int32_t *aFlags, uint16_t *aExpiration, uint16_t *aType) { return _to GetPageAnnotationInfo(aURI, aName, aFlags, aExpiration, aType); } \
  NS_IMETHOD GetItemAnnotationInfo(int64_t aItemId, const nsACString & aName, int32_t *aFlags, uint16_t *aExpiration, uint16_t *aType) { return _to GetItemAnnotationInfo(aItemId, aName, aFlags, aExpiration, aType); } \
  NS_IMETHOD GetPageAnnotationType(nsIURI *aURI, const nsACString & aName, uint16_t *_retval) { return _to GetPageAnnotationType(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationType(int64_t aItemId, const nsACString & aName, uint16_t *_retval) { return _to GetItemAnnotationType(aItemId, aName, _retval); } \
  NS_IMETHOD GetPagesWithAnnotation(const nsACString & name, uint32_t *resultCount, nsIURI * **results) { return _to GetPagesWithAnnotation(name, resultCount, results); } \
  NS_IMETHOD GetItemsWithAnnotation(const nsACString & name, uint32_t *resultCount, int64_t **results) { return _to GetItemsWithAnnotation(name, resultCount, results); } \
  NS_IMETHOD GetAnnotationsWithName(const nsACString & name, uint32_t *count, mozIAnnotatedResult * **results) { return _to GetAnnotationsWithName(name, count, results); } \
  NS_IMETHOD GetPageAnnotationNames(nsIURI *aURI, uint32_t *count, nsIVariant * **result) { return _to GetPageAnnotationNames(aURI, count, result); } \
  NS_IMETHOD GetItemAnnotationNames(int64_t aItemId, uint32_t *count, nsIVariant * **result) { return _to GetItemAnnotationNames(aItemId, count, result); } \
  NS_IMETHOD PageHasAnnotation(nsIURI *aURI, const nsACString & aName, bool *_retval) { return _to PageHasAnnotation(aURI, aName, _retval); } \
  NS_IMETHOD ItemHasAnnotation(int64_t aItemId, const nsACString & aName, bool *_retval) { return _to ItemHasAnnotation(aItemId, aName, _retval); } \
  NS_IMETHOD RemovePageAnnotation(nsIURI *aURI, const nsACString & aName) { return _to RemovePageAnnotation(aURI, aName); } \
  NS_IMETHOD RemoveItemAnnotation(int64_t aItemId, const nsACString & aName) { return _to RemoveItemAnnotation(aItemId, aName); } \
  NS_IMETHOD RemovePageAnnotations(nsIURI *aURI) { return _to RemovePageAnnotations(aURI); } \
  NS_IMETHOD RemoveItemAnnotations(int64_t aItemId) { return _to RemoveItemAnnotations(aItemId); } \
  NS_IMETHOD CopyPageAnnotations(nsIURI *aSourceURI, nsIURI *aDestURI, bool aOverwriteDest) { return _to CopyPageAnnotations(aSourceURI, aDestURI, aOverwriteDest); } \
  NS_IMETHOD CopyItemAnnotations(int64_t aSourceItemId, int64_t aDestItemId, bool aOverwriteDest) { return _to CopyItemAnnotations(aSourceItemId, aDestItemId, aOverwriteDest); } \
  NS_IMETHOD AddObserver(nsIAnnotationObserver *aObserver) { return _to AddObserver(aObserver); } \
  NS_IMETHOD RemoveObserver(nsIAnnotationObserver *aObserver) { return _to RemoveObserver(aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIANNOTATIONSERVICE(_to) \
  NS_IMETHOD SetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant *aValue, int32_t aFlags, uint16_t aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotation(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotation(int64_t aItemId, const nsACString & aName, nsIVariant *aValue, int32_t aFlags, uint16_t aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotation(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationString(nsIURI *aURI, const nsACString & aName, const nsAString & aValue, int32_t aFlags, uint16_t aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotationString(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationString(int64_t aItemId, const nsACString & aName, const nsAString & aValue, int32_t aFlags, uint16_t aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotationString(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, int32_t aValue, int32_t aFlags, uint16_t aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotationInt32(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationInt32(int64_t aItemId, const nsACString & aName, int32_t aValue, int32_t aFlags, uint16_t aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotationInt32(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, int64_t aValue, int32_t aFlags, uint16_t aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotationInt64(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationInt64(int64_t aItemId, const nsACString & aName, int64_t aValue, int32_t aFlags, uint16_t aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotationInt64(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double aValue, int32_t aFlags, uint16_t aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPageAnnotationDouble(aURI, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD SetItemAnnotationDouble(int64_t aItemId, const nsACString & aName, double aValue, int32_t aFlags, uint16_t aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItemAnnotationDouble(aItemId, aName, aValue, aFlags, aExpiration); } \
  NS_IMETHOD GetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotation(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotation(int64_t aItemId, const nsACString & aName, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotation(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationString(nsIURI *aURI, const nsACString & aName, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationString(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationString(int64_t aItemId, const nsACString & aName, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationString(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationInt32(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationInt32(int64_t aItemId, const nsACString & aName, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationInt32(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, int64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationInt64(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationInt64(int64_t aItemId, const nsACString & aName, int64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationInt64(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationDouble(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationDouble(int64_t aItemId, const nsACString & aName, double *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationDouble(aItemId, aName, _retval); } \
  NS_IMETHOD GetPageAnnotationInfo(nsIURI *aURI, const nsACString & aName, int32_t *aFlags, uint16_t *aExpiration, uint16_t *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationInfo(aURI, aName, aFlags, aExpiration, aType); } \
  NS_IMETHOD GetItemAnnotationInfo(int64_t aItemId, const nsACString & aName, int32_t *aFlags, uint16_t *aExpiration, uint16_t *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationInfo(aItemId, aName, aFlags, aExpiration, aType); } \
  NS_IMETHOD GetPageAnnotationType(nsIURI *aURI, const nsACString & aName, uint16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationType(aURI, aName, _retval); } \
  NS_IMETHOD GetItemAnnotationType(int64_t aItemId, const nsACString & aName, uint16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationType(aItemId, aName, _retval); } \
  NS_IMETHOD GetPagesWithAnnotation(const nsACString & name, uint32_t *resultCount, nsIURI * **results) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPagesWithAnnotation(name, resultCount, results); } \
  NS_IMETHOD GetItemsWithAnnotation(const nsACString & name, uint32_t *resultCount, int64_t **results) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemsWithAnnotation(name, resultCount, results); } \
  NS_IMETHOD GetAnnotationsWithName(const nsACString & name, uint32_t *count, mozIAnnotatedResult * **results) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotationsWithName(name, count, results); } \
  NS_IMETHOD GetPageAnnotationNames(nsIURI *aURI, uint32_t *count, nsIVariant * **result) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageAnnotationNames(aURI, count, result); } \
  NS_IMETHOD GetItemAnnotationNames(int64_t aItemId, uint32_t *count, nsIVariant * **result) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAnnotationNames(aItemId, count, result); } \
  NS_IMETHOD PageHasAnnotation(nsIURI *aURI, const nsACString & aName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PageHasAnnotation(aURI, aName, _retval); } \
  NS_IMETHOD ItemHasAnnotation(int64_t aItemId, const nsACString & aName, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ItemHasAnnotation(aItemId, aName, _retval); } \
  NS_IMETHOD RemovePageAnnotation(nsIURI *aURI, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePageAnnotation(aURI, aName); } \
  NS_IMETHOD RemoveItemAnnotation(int64_t aItemId, const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemAnnotation(aItemId, aName); } \
  NS_IMETHOD RemovePageAnnotations(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemovePageAnnotations(aURI); } \
  NS_IMETHOD RemoveItemAnnotations(int64_t aItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemAnnotations(aItemId); } \
  NS_IMETHOD CopyPageAnnotations(nsIURI *aSourceURI, nsIURI *aDestURI, bool aOverwriteDest) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyPageAnnotations(aSourceURI, aDestURI, aOverwriteDest); } \
  NS_IMETHOD CopyItemAnnotations(int64_t aSourceItemId, int64_t aDestItemId, bool aOverwriteDest) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyItemAnnotations(aSourceItemId, aDestItemId, aOverwriteDest); } \
  NS_IMETHOD AddObserver(nsIAnnotationObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver); } \
  NS_IMETHOD RemoveObserver(nsIAnnotationObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAnnotationService : public nsIAnnotationService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIANNOTATIONSERVICE

  nsAnnotationService();

private:
  ~nsAnnotationService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAnnotationService, nsIAnnotationService)

nsAnnotationService::nsAnnotationService()
{
  /* member initializers and constructor code */
}

nsAnnotationService::~nsAnnotationService()
{
  /* destructor code */
}

/* void setPageAnnotation (in nsIURI aURI, in AUTF8String aName, in nsIVariant aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant *aValue, int32_t aFlags, uint16_t aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setItemAnnotation (in long long aItemId, in AUTF8String aName, in nsIVariant aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotation(int64_t aItemId, const nsACString & aName, nsIVariant *aValue, int32_t aFlags, uint16_t aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setPageAnnotationString (in nsIURI aURI, in AUTF8String aName, in AString aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotationString(nsIURI *aURI, const nsACString & aName, const nsAString & aValue, int32_t aFlags, uint16_t aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setItemAnnotationString (in long long aItemId, in AUTF8String aName, in AString aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotationString(int64_t aItemId, const nsACString & aName, const nsAString & aValue, int32_t aFlags, uint16_t aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setPageAnnotationInt32 (in nsIURI aURI, in AUTF8String aName, in long aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, int32_t aValue, int32_t aFlags, uint16_t aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setItemAnnotationInt32 (in long long aItemId, in AUTF8String aName, in long aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotationInt32(int64_t aItemId, const nsACString & aName, int32_t aValue, int32_t aFlags, uint16_t aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setPageAnnotationInt64 (in nsIURI aURI, in AUTF8String aName, in long long aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, int64_t aValue, int32_t aFlags, uint16_t aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setItemAnnotationInt64 (in long long aItemId, in AUTF8String aName, in long long aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotationInt64(int64_t aItemId, const nsACString & aName, int64_t aValue, int32_t aFlags, uint16_t aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setPageAnnotationDouble (in nsIURI aURI, in AUTF8String aName, in double aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double aValue, int32_t aFlags, uint16_t aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setItemAnnotationDouble (in long long aItemId, in AUTF8String aName, in double aValue, in long aFlags, in unsigned short aExpiration); */
NS_IMETHODIMP nsAnnotationService::SetItemAnnotationDouble(int64_t aItemId, const nsACString & aName, double aValue, int32_t aFlags, uint16_t aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getPageAnnotation (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotation(nsIURI *aURI, const nsACString & aName, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getItemAnnotation (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotation(int64_t aItemId, const nsACString & aName, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AString getPageAnnotationString (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationString(nsIURI *aURI, const nsACString & aName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AString getItemAnnotationString (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationString(int64_t aItemId, const nsACString & aName, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long getPageAnnotationInt32 (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationInt32(nsIURI *aURI, const nsACString & aName, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long getItemAnnotationInt32 (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationInt32(int64_t aItemId, const nsACString & aName, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long long getPageAnnotationInt64 (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationInt64(nsIURI *aURI, const nsACString & aName, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] long long getItemAnnotationInt64 (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationInt64(int64_t aItemId, const nsACString & aName, int64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] double getPageAnnotationDouble (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationDouble(nsIURI *aURI, const nsACString & aName, double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] double getItemAnnotationDouble (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationDouble(int64_t aItemId, const nsACString & aName, double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPageAnnotationInfo (in nsIURI aURI, in AUTF8String aName, out int32_t aFlags, out unsigned short aExpiration, out unsigned short aType); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationInfo(nsIURI *aURI, const nsACString & aName, int32_t *aFlags, uint16_t *aExpiration, uint16_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getItemAnnotationInfo (in long long aItemId, in AUTF8String aName, out long aFlags, out unsigned short aExpiration, out unsigned short aType); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationInfo(int64_t aItemId, const nsACString & aName, int32_t *aFlags, uint16_t *aExpiration, uint16_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint16_t getPageAnnotationType (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationType(nsIURI *aURI, const nsACString & aName, uint16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* uint16_t getItemAnnotationType (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationType(int64_t aItemId, const nsACString & aName, uint16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPagesWithAnnotation (in AUTF8String name, [optional] out unsigned long resultCount, [array, size_is (resultCount), retval] out nsIURI results); */
NS_IMETHODIMP nsAnnotationService::GetPagesWithAnnotation(const nsACString & name, uint32_t *resultCount, nsIURI * **results)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getItemsWithAnnotation (in AUTF8String name, [optional] out unsigned long resultCount, [array, size_is (resultCount), retval] out long long results); */
NS_IMETHODIMP nsAnnotationService::GetItemsWithAnnotation(const nsACString & name, uint32_t *resultCount, int64_t **results)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAnnotationsWithName (in AUTF8String name, [optional] out unsigned long count, [array, size_is (count), retval] out mozIAnnotatedResult results); */
NS_IMETHODIMP nsAnnotationService::GetAnnotationsWithName(const nsACString & name, uint32_t *count, mozIAnnotatedResult * **results)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getPageAnnotationNames (in nsIURI aURI, [optional] out unsigned long count, [array, size_is (count), retval] out nsIVariant result); */
NS_IMETHODIMP nsAnnotationService::GetPageAnnotationNames(nsIURI *aURI, uint32_t *count, nsIVariant * **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getItemAnnotationNames (in long long aItemId, [optional] out unsigned long count, [array, size_is (count), retval] out nsIVariant result); */
NS_IMETHODIMP nsAnnotationService::GetItemAnnotationNames(int64_t aItemId, uint32_t *count, nsIVariant * **result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean pageHasAnnotation (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::PageHasAnnotation(nsIURI *aURI, const nsACString & aName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean itemHasAnnotation (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::ItemHasAnnotation(int64_t aItemId, const nsACString & aName, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePageAnnotation (in nsIURI aURI, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::RemovePageAnnotation(nsIURI *aURI, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItemAnnotation (in long long aItemId, in AUTF8String aName); */
NS_IMETHODIMP nsAnnotationService::RemoveItemAnnotation(int64_t aItemId, const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removePageAnnotations (in nsIURI aURI); */
NS_IMETHODIMP nsAnnotationService::RemovePageAnnotations(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeItemAnnotations (in long long aItemId); */
NS_IMETHODIMP nsAnnotationService::RemoveItemAnnotations(int64_t aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyPageAnnotations (in nsIURI aSourceURI, in nsIURI aDestURI, in boolean aOverwriteDest); */
NS_IMETHODIMP nsAnnotationService::CopyPageAnnotations(nsIURI *aSourceURI, nsIURI *aDestURI, bool aOverwriteDest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyItemAnnotations (in long long aSourceItemId, in long long aDestItemId, in boolean aOverwriteDest); */
NS_IMETHODIMP nsAnnotationService::CopyItemAnnotations(int64_t aSourceItemId, int64_t aDestItemId, bool aOverwriteDest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsIAnnotationObserver aObserver); */
NS_IMETHODIMP nsAnnotationService::AddObserver(nsIAnnotationObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIAnnotationObserver aObserver); */
NS_IMETHODIMP nsAnnotationService::RemoveObserver(nsIAnnotationObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    mozIAnnotatedResult */
#define MOZIANNOTATEDRESULT_IID_STR "81fd0188-db6a-492e-80b6-f6414913b396"

#define MOZIANNOTATEDRESULT_IID \
  {0x81fd0188, 0xdb6a, 0x492e, \
    { 0x80, 0xb6, 0xf6, 0x41, 0x49, 0x13, 0xb3, 0x96 }}

class NS_NO_VTABLE mozIAnnotatedResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIANNOTATEDRESULT_IID)

  /* readonly attribute AUTF8String guid; */
  NS_IMETHOD GetGuid(nsACString & aGuid) = 0;

  /* readonly attribute nsIURI uri; */
  NS_IMETHOD GetUri(nsIURI * *aUri) = 0;

  /* readonly attribute long long itemId; */
  NS_IMETHOD GetItemId(int64_t *aItemId) = 0;

  /* readonly attribute AUTF8String annotationName; */
  NS_IMETHOD GetAnnotationName(nsACString & aAnnotationName) = 0;

  /* readonly attribute nsIVariant annotationValue; */
  NS_IMETHOD GetAnnotationValue(nsIVariant * *aAnnotationValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIAnnotatedResult, MOZIANNOTATEDRESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIANNOTATEDRESULT \
  NS_IMETHOD GetGuid(nsACString & aGuid); \
  NS_IMETHOD GetUri(nsIURI * *aUri); \
  NS_IMETHOD GetItemId(int64_t *aItemId); \
  NS_IMETHOD GetAnnotationName(nsACString & aAnnotationName); \
  NS_IMETHOD GetAnnotationValue(nsIVariant * *aAnnotationValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIANNOTATEDRESULT(_to) \
  NS_IMETHOD GetGuid(nsACString & aGuid) { return _to GetGuid(aGuid); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return _to GetUri(aUri); } \
  NS_IMETHOD GetItemId(int64_t *aItemId) { return _to GetItemId(aItemId); } \
  NS_IMETHOD GetAnnotationName(nsACString & aAnnotationName) { return _to GetAnnotationName(aAnnotationName); } \
  NS_IMETHOD GetAnnotationValue(nsIVariant * *aAnnotationValue) { return _to GetAnnotationValue(aAnnotationValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIANNOTATEDRESULT(_to) \
  NS_IMETHOD GetGuid(nsACString & aGuid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGuid(aGuid); } \
  NS_IMETHOD GetUri(nsIURI * *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_IMETHOD GetItemId(int64_t *aItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemId(aItemId); } \
  NS_IMETHOD GetAnnotationName(nsACString & aAnnotationName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotationName(aAnnotationName); } \
  NS_IMETHOD GetAnnotationValue(nsIVariant * *aAnnotationValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotationValue(aAnnotationValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIAnnotatedResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIANNOTATEDRESULT

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIAnnotatedResult)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute AUTF8String guid; */
NS_IMETHODIMP _MYCLASS_::GetGuid(nsACString & aGuid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI uri; */
NS_IMETHODIMP _MYCLASS_::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long itemId; */
NS_IMETHODIMP _MYCLASS_::GetItemId(int64_t *aItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String annotationName; */
NS_IMETHODIMP _MYCLASS_::GetAnnotationName(nsACString & aAnnotationName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant annotationValue; */
NS_IMETHODIMP _MYCLASS_::GetAnnotationValue(nsIVariant * *aAnnotationValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAnnotationService_h__ */
