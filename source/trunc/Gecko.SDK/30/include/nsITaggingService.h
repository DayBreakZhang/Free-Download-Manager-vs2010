/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITaggingService.idl
 */

#ifndef __gen_nsITaggingService_h__
#define __gen_nsITaggingService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIVariant; /* forward declaration */


/* starting interface:    nsITaggingService */
#define NS_ITAGGINGSERVICE_IID_STR "f816b4df-f733-4dbd-964d-8bfc92a475b2"

#define NS_ITAGGINGSERVICE_IID \
  {0xf816b4df, 0xf733, 0x4dbd, \
    { 0x96, 0x4d, 0x8b, 0xfc, 0x92, 0xa4, 0x75, 0xb2 }}

class NS_NO_VTABLE nsITaggingService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITAGGINGSERVICE_IID)

  /* void tagURI (in nsIURI aURI, in nsIVariant aTags); */
  NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags) = 0;

  /* void untagURI (in nsIURI aURI, in nsIVariant aTags); */
  NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags) = 0;

  /* nsIVariant getURIsForTag (in AString aTag); */
  NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant * *_retval) = 0;

  /* void getTagsForURI (in nsIURI aURI, [optional] out unsigned long length, [array, size_is (length), retval] out wstring aTags); */
  NS_IMETHOD GetTagsForURI(nsIURI *aURI, uint32_t *length, char16_t * **aTags) = 0;

  /* readonly attribute nsIVariant allTags; */
  NS_IMETHOD GetAllTags(nsIVariant * *aAllTags) = 0;

  /* readonly attribute boolean hasTags; */
  NS_IMETHOD GetHasTags(bool *aHasTags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaggingService, NS_ITAGGINGSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITAGGINGSERVICE \
  NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags); \
  NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags); \
  NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant * *_retval); \
  NS_IMETHOD GetTagsForURI(nsIURI *aURI, uint32_t *length, char16_t * **aTags); \
  NS_IMETHOD GetAllTags(nsIVariant * *aAllTags); \
  NS_IMETHOD GetHasTags(bool *aHasTags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITAGGINGSERVICE(_to) \
  NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags) { return _to TagURI(aURI, aTags); } \
  NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags) { return _to UntagURI(aURI, aTags); } \
  NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant * *_retval) { return _to GetURIsForTag(aTag, _retval); } \
  NS_IMETHOD GetTagsForURI(nsIURI *aURI, uint32_t *length, char16_t * **aTags) { return _to GetTagsForURI(aURI, length, aTags); } \
  NS_IMETHOD GetAllTags(nsIVariant * *aAllTags) { return _to GetAllTags(aAllTags); } \
  NS_IMETHOD GetHasTags(bool *aHasTags) { return _to GetHasTags(aHasTags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITAGGINGSERVICE(_to) \
  NS_IMETHOD TagURI(nsIURI *aURI, nsIVariant *aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->TagURI(aURI, aTags); } \
  NS_IMETHOD UntagURI(nsIURI *aURI, nsIVariant *aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->UntagURI(aURI, aTags); } \
  NS_IMETHOD GetURIsForTag(const nsAString & aTag, nsIVariant * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURIsForTag(aTag, _retval); } \
  NS_IMETHOD GetTagsForURI(nsIURI *aURI, uint32_t *length, char16_t * **aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTagsForURI(aURI, length, aTags); } \
  NS_IMETHOD GetAllTags(nsIVariant * *aAllTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllTags(aAllTags); } \
  NS_IMETHOD GetHasTags(bool *aHasTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasTags(aHasTags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaggingService : public nsITaggingService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITAGGINGSERVICE

  nsTaggingService();

private:
  ~nsTaggingService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTaggingService, nsITaggingService)

nsTaggingService::nsTaggingService()
{
  /* member initializers and constructor code */
}

nsTaggingService::~nsTaggingService()
{
  /* destructor code */
}

/* void tagURI (in nsIURI aURI, in nsIVariant aTags); */
NS_IMETHODIMP nsTaggingService::TagURI(nsIURI *aURI, nsIVariant *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void untagURI (in nsIURI aURI, in nsIVariant aTags); */
NS_IMETHODIMP nsTaggingService::UntagURI(nsIURI *aURI, nsIVariant *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant getURIsForTag (in AString aTag); */
NS_IMETHODIMP nsTaggingService::GetURIsForTag(const nsAString & aTag, nsIVariant * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTagsForURI (in nsIURI aURI, [optional] out unsigned long length, [array, size_is (length), retval] out wstring aTags); */
NS_IMETHODIMP nsTaggingService::GetTagsForURI(nsIURI *aURI, uint32_t *length, char16_t * **aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant allTags; */
NS_IMETHODIMP nsTaggingService::GetAllTags(nsIVariant * *aAllTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean hasTags; */
NS_IMETHODIMP nsTaggingService::GetHasTags(bool *aHasTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define TAGGING_SERVICE_CID "@mozilla.org/browser/tagging-service;1"

#endif /* __gen_nsITaggingService_h__ */
