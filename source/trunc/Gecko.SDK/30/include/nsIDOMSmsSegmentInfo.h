/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMSmsSegmentInfo.idl
 */

#ifndef __gen_nsIDOMSmsSegmentInfo_h__
#define __gen_nsIDOMSmsSegmentInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozSmsSegmentInfo */
#define NS_IDOMMOZSMSSEGMENTINFO_IID_STR "57ac3989-531e-4928-998b-53fde81a05a6"

#define NS_IDOMMOZSMSSEGMENTINFO_IID \
  {0x57ac3989, 0x531e, 0x4928, \
    { 0x99, 0x8b, 0x53, 0xfd, 0xe8, 0x1a, 0x05, 0xa6 }}

class NS_NO_VTABLE nsIDOMMozSmsSegmentInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZSMSSEGMENTINFO_IID)

  /* readonly attribute long segments; */
  NS_IMETHOD GetSegments(int32_t *aSegments) = 0;

  /* readonly attribute long charsPerSegment; */
  NS_IMETHOD GetCharsPerSegment(int32_t *aCharsPerSegment) = 0;

  /* readonly attribute long charsAvailableInLastSegment; */
  NS_IMETHOD GetCharsAvailableInLastSegment(int32_t *aCharsAvailableInLastSegment) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozSmsSegmentInfo, NS_IDOMMOZSMSSEGMENTINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZSMSSEGMENTINFO \
  NS_IMETHOD GetSegments(int32_t *aSegments); \
  NS_IMETHOD GetCharsPerSegment(int32_t *aCharsPerSegment); \
  NS_IMETHOD GetCharsAvailableInLastSegment(int32_t *aCharsAvailableInLastSegment); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZSMSSEGMENTINFO(_to) \
  NS_IMETHOD GetSegments(int32_t *aSegments) { return _to GetSegments(aSegments); } \
  NS_IMETHOD GetCharsPerSegment(int32_t *aCharsPerSegment) { return _to GetCharsPerSegment(aCharsPerSegment); } \
  NS_IMETHOD GetCharsAvailableInLastSegment(int32_t *aCharsAvailableInLastSegment) { return _to GetCharsAvailableInLastSegment(aCharsAvailableInLastSegment); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZSMSSEGMENTINFO(_to) \
  NS_IMETHOD GetSegments(int32_t *aSegments) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSegments(aSegments); } \
  NS_IMETHOD GetCharsPerSegment(int32_t *aCharsPerSegment) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsPerSegment(aCharsPerSegment); } \
  NS_IMETHOD GetCharsAvailableInLastSegment(int32_t *aCharsAvailableInLastSegment) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharsAvailableInLastSegment(aCharsAvailableInLastSegment); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozSmsSegmentInfo : public nsIDOMMozSmsSegmentInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZSMSSEGMENTINFO

  nsDOMMozSmsSegmentInfo();

private:
  ~nsDOMMozSmsSegmentInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozSmsSegmentInfo, nsIDOMMozSmsSegmentInfo)

nsDOMMozSmsSegmentInfo::nsDOMMozSmsSegmentInfo()
{
  /* member initializers and constructor code */
}

nsDOMMozSmsSegmentInfo::~nsDOMMozSmsSegmentInfo()
{
  /* destructor code */
}

/* readonly attribute long segments; */
NS_IMETHODIMP nsDOMMozSmsSegmentInfo::GetSegments(int32_t *aSegments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long charsPerSegment; */
NS_IMETHODIMP nsDOMMozSmsSegmentInfo::GetCharsPerSegment(int32_t *aCharsPerSegment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long charsAvailableInLastSegment; */
NS_IMETHODIMP nsDOMMozSmsSegmentInfo::GetCharsAvailableInLastSegment(int32_t *aCharsAvailableInLastSegment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSmsSegmentInfo_h__ */
