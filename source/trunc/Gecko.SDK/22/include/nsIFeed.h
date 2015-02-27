/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/feeds/nsIFeed.idl
 */

#ifndef __gen_nsIFeed_h__
#define __gen_nsIFeed_h__


#ifndef __gen_nsIFeedContainer_h__
#include "nsIFeedContainer.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIArray; /* forward declaration */

class nsIFeedGenerator; /* forward declaration */


/* starting interface:    nsIFeed */
#define NS_IFEED_IID_STR "3b8aae33-80e2-4efa-99c8-a6c5b99f76ea"

#define NS_IFEED_IID \
  {0x3b8aae33, 0x80e2, 0x4efa, \
    { 0x99, 0xc8, 0xa6, 0xc5, 0xb9, 0x9f, 0x76, 0xea }}

class NS_NO_VTABLE nsIFeed : public nsIFeedContainer {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFEED_IID)

  /* attribute nsIFeedTextConstruct subtitle; */
  NS_IMETHOD GetSubtitle(nsIFeedTextConstruct * *aSubtitle) = 0;
  NS_IMETHOD SetSubtitle(nsIFeedTextConstruct *aSubtitle) = 0;

  enum {
    TYPE_FEED = 0U,
    TYPE_AUDIO = 1U,
    TYPE_IMAGE = 2U,
    TYPE_VIDEO = 4U
  };

  /* readonly attribute unsigned long type; */
  NS_IMETHOD GetType(uint32_t *aType) = 0;

  /* attribute long enclosureCount; */
  NS_IMETHOD GetEnclosureCount(int32_t *aEnclosureCount) = 0;
  NS_IMETHOD SetEnclosureCount(int32_t aEnclosureCount) = 0;

  /* attribute nsIArray items; */
  NS_IMETHOD GetItems(nsIArray * *aItems) = 0;
  NS_IMETHOD SetItems(nsIArray *aItems) = 0;

  /* attribute nsIWritablePropertyBag2 cloud; */
  NS_IMETHOD GetCloud(nsIWritablePropertyBag2 * *aCloud) = 0;
  NS_IMETHOD SetCloud(nsIWritablePropertyBag2 *aCloud) = 0;

  /* attribute nsIFeedGenerator generator; */
  NS_IMETHOD GetGenerator(nsIFeedGenerator * *aGenerator) = 0;
  NS_IMETHOD SetGenerator(nsIFeedGenerator *aGenerator) = 0;

  /* attribute nsIWritablePropertyBag2 image; */
  NS_IMETHOD GetImage(nsIWritablePropertyBag2 * *aImage) = 0;
  NS_IMETHOD SetImage(nsIWritablePropertyBag2 *aImage) = 0;

  /* attribute nsIWritablePropertyBag2 textInput; */
  NS_IMETHOD GetTextInput(nsIWritablePropertyBag2 * *aTextInput) = 0;
  NS_IMETHOD SetTextInput(nsIWritablePropertyBag2 *aTextInput) = 0;

  /* attribute nsIArray skipDays; */
  NS_IMETHOD GetSkipDays(nsIArray * *aSkipDays) = 0;
  NS_IMETHOD SetSkipDays(nsIArray *aSkipDays) = 0;

  /* attribute nsIArray skipHours; */
  NS_IMETHOD GetSkipHours(nsIArray * *aSkipHours) = 0;
  NS_IMETHOD SetSkipHours(nsIArray *aSkipHours) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFeed, NS_IFEED_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFEED \
  NS_IMETHOD GetSubtitle(nsIFeedTextConstruct * *aSubtitle); \
  NS_IMETHOD SetSubtitle(nsIFeedTextConstruct *aSubtitle); \
  NS_IMETHOD GetType(uint32_t *aType); \
  NS_IMETHOD GetEnclosureCount(int32_t *aEnclosureCount); \
  NS_IMETHOD SetEnclosureCount(int32_t aEnclosureCount); \
  NS_IMETHOD GetItems(nsIArray * *aItems); \
  NS_IMETHOD SetItems(nsIArray *aItems); \
  NS_IMETHOD GetCloud(nsIWritablePropertyBag2 * *aCloud); \
  NS_IMETHOD SetCloud(nsIWritablePropertyBag2 *aCloud); \
  NS_IMETHOD GetGenerator(nsIFeedGenerator * *aGenerator); \
  NS_IMETHOD SetGenerator(nsIFeedGenerator *aGenerator); \
  NS_IMETHOD GetImage(nsIWritablePropertyBag2 * *aImage); \
  NS_IMETHOD SetImage(nsIWritablePropertyBag2 *aImage); \
  NS_IMETHOD GetTextInput(nsIWritablePropertyBag2 * *aTextInput); \
  NS_IMETHOD SetTextInput(nsIWritablePropertyBag2 *aTextInput); \
  NS_IMETHOD GetSkipDays(nsIArray * *aSkipDays); \
  NS_IMETHOD SetSkipDays(nsIArray *aSkipDays); \
  NS_IMETHOD GetSkipHours(nsIArray * *aSkipHours); \
  NS_IMETHOD SetSkipHours(nsIArray *aSkipHours); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFEED(_to) \
  NS_IMETHOD GetSubtitle(nsIFeedTextConstruct * *aSubtitle) { return _to GetSubtitle(aSubtitle); } \
  NS_IMETHOD SetSubtitle(nsIFeedTextConstruct *aSubtitle) { return _to SetSubtitle(aSubtitle); } \
  NS_IMETHOD GetType(uint32_t *aType) { return _to GetType(aType); } \
  NS_IMETHOD GetEnclosureCount(int32_t *aEnclosureCount) { return _to GetEnclosureCount(aEnclosureCount); } \
  NS_IMETHOD SetEnclosureCount(int32_t aEnclosureCount) { return _to SetEnclosureCount(aEnclosureCount); } \
  NS_IMETHOD GetItems(nsIArray * *aItems) { return _to GetItems(aItems); } \
  NS_IMETHOD SetItems(nsIArray *aItems) { return _to SetItems(aItems); } \
  NS_IMETHOD GetCloud(nsIWritablePropertyBag2 * *aCloud) { return _to GetCloud(aCloud); } \
  NS_IMETHOD SetCloud(nsIWritablePropertyBag2 *aCloud) { return _to SetCloud(aCloud); } \
  NS_IMETHOD GetGenerator(nsIFeedGenerator * *aGenerator) { return _to GetGenerator(aGenerator); } \
  NS_IMETHOD SetGenerator(nsIFeedGenerator *aGenerator) { return _to SetGenerator(aGenerator); } \
  NS_IMETHOD GetImage(nsIWritablePropertyBag2 * *aImage) { return _to GetImage(aImage); } \
  NS_IMETHOD SetImage(nsIWritablePropertyBag2 *aImage) { return _to SetImage(aImage); } \
  NS_IMETHOD GetTextInput(nsIWritablePropertyBag2 * *aTextInput) { return _to GetTextInput(aTextInput); } \
  NS_IMETHOD SetTextInput(nsIWritablePropertyBag2 *aTextInput) { return _to SetTextInput(aTextInput); } \
  NS_IMETHOD GetSkipDays(nsIArray * *aSkipDays) { return _to GetSkipDays(aSkipDays); } \
  NS_IMETHOD SetSkipDays(nsIArray *aSkipDays) { return _to SetSkipDays(aSkipDays); } \
  NS_IMETHOD GetSkipHours(nsIArray * *aSkipHours) { return _to GetSkipHours(aSkipHours); } \
  NS_IMETHOD SetSkipHours(nsIArray *aSkipHours) { return _to SetSkipHours(aSkipHours); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFEED(_to) \
  NS_IMETHOD GetSubtitle(nsIFeedTextConstruct * *aSubtitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubtitle(aSubtitle); } \
  NS_IMETHOD SetSubtitle(nsIFeedTextConstruct *aSubtitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSubtitle(aSubtitle); } \
  NS_IMETHOD GetType(uint32_t *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetEnclosureCount(int32_t *aEnclosureCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnclosureCount(aEnclosureCount); } \
  NS_IMETHOD SetEnclosureCount(int32_t aEnclosureCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEnclosureCount(aEnclosureCount); } \
  NS_IMETHOD GetItems(nsIArray * *aItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItems(aItems); } \
  NS_IMETHOD SetItems(nsIArray *aItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetItems(aItems); } \
  NS_IMETHOD GetCloud(nsIWritablePropertyBag2 * *aCloud) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCloud(aCloud); } \
  NS_IMETHOD SetCloud(nsIWritablePropertyBag2 *aCloud) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCloud(aCloud); } \
  NS_IMETHOD GetGenerator(nsIFeedGenerator * *aGenerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGenerator(aGenerator); } \
  NS_IMETHOD SetGenerator(nsIFeedGenerator *aGenerator) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGenerator(aGenerator); } \
  NS_IMETHOD GetImage(nsIWritablePropertyBag2 * *aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImage(aImage); } \
  NS_IMETHOD SetImage(nsIWritablePropertyBag2 *aImage) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImage(aImage); } \
  NS_IMETHOD GetTextInput(nsIWritablePropertyBag2 * *aTextInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTextInput(aTextInput); } \
  NS_IMETHOD SetTextInput(nsIWritablePropertyBag2 *aTextInput) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTextInput(aTextInput); } \
  NS_IMETHOD GetSkipDays(nsIArray * *aSkipDays) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSkipDays(aSkipDays); } \
  NS_IMETHOD SetSkipDays(nsIArray *aSkipDays) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSkipDays(aSkipDays); } \
  NS_IMETHOD GetSkipHours(nsIArray * *aSkipHours) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSkipHours(aSkipHours); } \
  NS_IMETHOD SetSkipHours(nsIArray *aSkipHours) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSkipHours(aSkipHours); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFeed : public nsIFeed
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFEED

  nsFeed();

private:
  ~nsFeed();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFeed, nsIFeed)

nsFeed::nsFeed()
{
  /* member initializers and constructor code */
}

nsFeed::~nsFeed()
{
  /* destructor code */
}

/* attribute nsIFeedTextConstruct subtitle; */
NS_IMETHODIMP nsFeed::GetSubtitle(nsIFeedTextConstruct * *aSubtitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetSubtitle(nsIFeedTextConstruct *aSubtitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long type; */
NS_IMETHODIMP nsFeed::GetType(uint32_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long enclosureCount; */
NS_IMETHODIMP nsFeed::GetEnclosureCount(int32_t *aEnclosureCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetEnclosureCount(int32_t aEnclosureCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIArray items; */
NS_IMETHODIMP nsFeed::GetItems(nsIArray * *aItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetItems(nsIArray *aItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWritablePropertyBag2 cloud; */
NS_IMETHODIMP nsFeed::GetCloud(nsIWritablePropertyBag2 * *aCloud)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetCloud(nsIWritablePropertyBag2 *aCloud)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFeedGenerator generator; */
NS_IMETHODIMP nsFeed::GetGenerator(nsIFeedGenerator * *aGenerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetGenerator(nsIFeedGenerator *aGenerator)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWritablePropertyBag2 image; */
NS_IMETHODIMP nsFeed::GetImage(nsIWritablePropertyBag2 * *aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetImage(nsIWritablePropertyBag2 *aImage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIWritablePropertyBag2 textInput; */
NS_IMETHODIMP nsFeed::GetTextInput(nsIWritablePropertyBag2 * *aTextInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetTextInput(nsIWritablePropertyBag2 *aTextInput)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIArray skipDays; */
NS_IMETHODIMP nsFeed::GetSkipDays(nsIArray * *aSkipDays)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetSkipDays(nsIArray *aSkipDays)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIArray skipHours; */
NS_IMETHODIMP nsFeed::GetSkipHours(nsIArray * *aSkipHours)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsFeed::SetSkipHours(nsIArray *aSkipHours)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFeed_h__ */
