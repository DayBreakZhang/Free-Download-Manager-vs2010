/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITimedChannel.idl
 */

#ifndef __gen_nsITimedChannel_h__
#define __gen_nsITimedChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
namespace mozilla {
class TimeStamp;
}

/* starting interface:    nsITimedChannel */
#define NS_ITIMEDCHANNEL_IID_STR "c259b593-a9bf-4d08-8149-ef89e1977dc4"

#define NS_ITIMEDCHANNEL_IID \
  {0xc259b593, 0xa9bf, 0x4d08, \
    { 0x81, 0x49, 0xef, 0x89, 0xe1, 0x97, 0x7d, 0xc4 }}

class NS_NO_VTABLE nsITimedChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITIMEDCHANNEL_IID)

  /* attribute boolean timingEnabled; */
  NS_IMETHOD GetTimingEnabled(bool *aTimingEnabled) = 0;
  NS_IMETHOD SetTimingEnabled(bool aTimingEnabled) = 0;

  /* [noscript] readonly attribute TimeStamp channelCreation; */
  NS_IMETHOD GetChannelCreation(mozilla::TimeStamp *aChannelCreation) = 0;

  /* [noscript] readonly attribute TimeStamp asyncOpen; */
  NS_IMETHOD GetAsyncOpen(mozilla::TimeStamp *aAsyncOpen) = 0;

  /* [noscript] readonly attribute TimeStamp domainLookupStart; */
  NS_IMETHOD GetDomainLookupStart(mozilla::TimeStamp *aDomainLookupStart) = 0;

  /* [noscript] readonly attribute TimeStamp domainLookupEnd; */
  NS_IMETHOD GetDomainLookupEnd(mozilla::TimeStamp *aDomainLookupEnd) = 0;

  /* [noscript] readonly attribute TimeStamp connectStart; */
  NS_IMETHOD GetConnectStart(mozilla::TimeStamp *aConnectStart) = 0;

  /* [noscript] readonly attribute TimeStamp connectEnd; */
  NS_IMETHOD GetConnectEnd(mozilla::TimeStamp *aConnectEnd) = 0;

  /* [noscript] readonly attribute TimeStamp requestStart; */
  NS_IMETHOD GetRequestStart(mozilla::TimeStamp *aRequestStart) = 0;

  /* [noscript] readonly attribute TimeStamp responseStart; */
  NS_IMETHOD GetResponseStart(mozilla::TimeStamp *aResponseStart) = 0;

  /* [noscript] readonly attribute TimeStamp responseEnd; */
  NS_IMETHOD GetResponseEnd(mozilla::TimeStamp *aResponseEnd) = 0;

  /* [noscript] readonly attribute TimeStamp cacheReadStart; */
  NS_IMETHOD GetCacheReadStart(mozilla::TimeStamp *aCacheReadStart) = 0;

  /* [noscript] readonly attribute TimeStamp cacheReadEnd; */
  NS_IMETHOD GetCacheReadEnd(mozilla::TimeStamp *aCacheReadEnd) = 0;

  /* readonly attribute PRTime channelCreationTime; */
  NS_IMETHOD GetChannelCreationTime(PRTime *aChannelCreationTime) = 0;

  /* readonly attribute PRTime asyncOpenTime; */
  NS_IMETHOD GetAsyncOpenTime(PRTime *aAsyncOpenTime) = 0;

  /* readonly attribute PRTime domainLookupStartTime; */
  NS_IMETHOD GetDomainLookupStartTime(PRTime *aDomainLookupStartTime) = 0;

  /* readonly attribute PRTime domainLookupEndTime; */
  NS_IMETHOD GetDomainLookupEndTime(PRTime *aDomainLookupEndTime) = 0;

  /* readonly attribute PRTime connectStartTime; */
  NS_IMETHOD GetConnectStartTime(PRTime *aConnectStartTime) = 0;

  /* readonly attribute PRTime connectEndTime; */
  NS_IMETHOD GetConnectEndTime(PRTime *aConnectEndTime) = 0;

  /* readonly attribute PRTime requestStartTime; */
  NS_IMETHOD GetRequestStartTime(PRTime *aRequestStartTime) = 0;

  /* readonly attribute PRTime responseStartTime; */
  NS_IMETHOD GetResponseStartTime(PRTime *aResponseStartTime) = 0;

  /* readonly attribute PRTime responseEndTime; */
  NS_IMETHOD GetResponseEndTime(PRTime *aResponseEndTime) = 0;

  /* readonly attribute PRTime cacheReadStartTime; */
  NS_IMETHOD GetCacheReadStartTime(PRTime *aCacheReadStartTime) = 0;

  /* readonly attribute PRTime cacheReadEndTime; */
  NS_IMETHOD GetCacheReadEndTime(PRTime *aCacheReadEndTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITimedChannel, NS_ITIMEDCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITIMEDCHANNEL \
  NS_IMETHOD GetTimingEnabled(bool *aTimingEnabled); \
  NS_IMETHOD SetTimingEnabled(bool aTimingEnabled); \
  NS_IMETHOD GetChannelCreation(mozilla::TimeStamp *aChannelCreation); \
  NS_IMETHOD GetAsyncOpen(mozilla::TimeStamp *aAsyncOpen); \
  NS_IMETHOD GetDomainLookupStart(mozilla::TimeStamp *aDomainLookupStart); \
  NS_IMETHOD GetDomainLookupEnd(mozilla::TimeStamp *aDomainLookupEnd); \
  NS_IMETHOD GetConnectStart(mozilla::TimeStamp *aConnectStart); \
  NS_IMETHOD GetConnectEnd(mozilla::TimeStamp *aConnectEnd); \
  NS_IMETHOD GetRequestStart(mozilla::TimeStamp *aRequestStart); \
  NS_IMETHOD GetResponseStart(mozilla::TimeStamp *aResponseStart); \
  NS_IMETHOD GetResponseEnd(mozilla::TimeStamp *aResponseEnd); \
  NS_IMETHOD GetCacheReadStart(mozilla::TimeStamp *aCacheReadStart); \
  NS_IMETHOD GetCacheReadEnd(mozilla::TimeStamp *aCacheReadEnd); \
  NS_IMETHOD GetChannelCreationTime(PRTime *aChannelCreationTime); \
  NS_IMETHOD GetAsyncOpenTime(PRTime *aAsyncOpenTime); \
  NS_IMETHOD GetDomainLookupStartTime(PRTime *aDomainLookupStartTime); \
  NS_IMETHOD GetDomainLookupEndTime(PRTime *aDomainLookupEndTime); \
  NS_IMETHOD GetConnectStartTime(PRTime *aConnectStartTime); \
  NS_IMETHOD GetConnectEndTime(PRTime *aConnectEndTime); \
  NS_IMETHOD GetRequestStartTime(PRTime *aRequestStartTime); \
  NS_IMETHOD GetResponseStartTime(PRTime *aResponseStartTime); \
  NS_IMETHOD GetResponseEndTime(PRTime *aResponseEndTime); \
  NS_IMETHOD GetCacheReadStartTime(PRTime *aCacheReadStartTime); \
  NS_IMETHOD GetCacheReadEndTime(PRTime *aCacheReadEndTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITIMEDCHANNEL(_to) \
  NS_IMETHOD GetTimingEnabled(bool *aTimingEnabled) { return _to GetTimingEnabled(aTimingEnabled); } \
  NS_IMETHOD SetTimingEnabled(bool aTimingEnabled) { return _to SetTimingEnabled(aTimingEnabled); } \
  NS_IMETHOD GetChannelCreation(mozilla::TimeStamp *aChannelCreation) { return _to GetChannelCreation(aChannelCreation); } \
  NS_IMETHOD GetAsyncOpen(mozilla::TimeStamp *aAsyncOpen) { return _to GetAsyncOpen(aAsyncOpen); } \
  NS_IMETHOD GetDomainLookupStart(mozilla::TimeStamp *aDomainLookupStart) { return _to GetDomainLookupStart(aDomainLookupStart); } \
  NS_IMETHOD GetDomainLookupEnd(mozilla::TimeStamp *aDomainLookupEnd) { return _to GetDomainLookupEnd(aDomainLookupEnd); } \
  NS_IMETHOD GetConnectStart(mozilla::TimeStamp *aConnectStart) { return _to GetConnectStart(aConnectStart); } \
  NS_IMETHOD GetConnectEnd(mozilla::TimeStamp *aConnectEnd) { return _to GetConnectEnd(aConnectEnd); } \
  NS_IMETHOD GetRequestStart(mozilla::TimeStamp *aRequestStart) { return _to GetRequestStart(aRequestStart); } \
  NS_IMETHOD GetResponseStart(mozilla::TimeStamp *aResponseStart) { return _to GetResponseStart(aResponseStart); } \
  NS_IMETHOD GetResponseEnd(mozilla::TimeStamp *aResponseEnd) { return _to GetResponseEnd(aResponseEnd); } \
  NS_IMETHOD GetCacheReadStart(mozilla::TimeStamp *aCacheReadStart) { return _to GetCacheReadStart(aCacheReadStart); } \
  NS_IMETHOD GetCacheReadEnd(mozilla::TimeStamp *aCacheReadEnd) { return _to GetCacheReadEnd(aCacheReadEnd); } \
  NS_IMETHOD GetChannelCreationTime(PRTime *aChannelCreationTime) { return _to GetChannelCreationTime(aChannelCreationTime); } \
  NS_IMETHOD GetAsyncOpenTime(PRTime *aAsyncOpenTime) { return _to GetAsyncOpenTime(aAsyncOpenTime); } \
  NS_IMETHOD GetDomainLookupStartTime(PRTime *aDomainLookupStartTime) { return _to GetDomainLookupStartTime(aDomainLookupStartTime); } \
  NS_IMETHOD GetDomainLookupEndTime(PRTime *aDomainLookupEndTime) { return _to GetDomainLookupEndTime(aDomainLookupEndTime); } \
  NS_IMETHOD GetConnectStartTime(PRTime *aConnectStartTime) { return _to GetConnectStartTime(aConnectStartTime); } \
  NS_IMETHOD GetConnectEndTime(PRTime *aConnectEndTime) { return _to GetConnectEndTime(aConnectEndTime); } \
  NS_IMETHOD GetRequestStartTime(PRTime *aRequestStartTime) { return _to GetRequestStartTime(aRequestStartTime); } \
  NS_IMETHOD GetResponseStartTime(PRTime *aResponseStartTime) { return _to GetResponseStartTime(aResponseStartTime); } \
  NS_IMETHOD GetResponseEndTime(PRTime *aResponseEndTime) { return _to GetResponseEndTime(aResponseEndTime); } \
  NS_IMETHOD GetCacheReadStartTime(PRTime *aCacheReadStartTime) { return _to GetCacheReadStartTime(aCacheReadStartTime); } \
  NS_IMETHOD GetCacheReadEndTime(PRTime *aCacheReadEndTime) { return _to GetCacheReadEndTime(aCacheReadEndTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITIMEDCHANNEL(_to) \
  NS_IMETHOD GetTimingEnabled(bool *aTimingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimingEnabled(aTimingEnabled); } \
  NS_IMETHOD SetTimingEnabled(bool aTimingEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimingEnabled(aTimingEnabled); } \
  NS_IMETHOD GetChannelCreation(mozilla::TimeStamp *aChannelCreation) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelCreation(aChannelCreation); } \
  NS_IMETHOD GetAsyncOpen(mozilla::TimeStamp *aAsyncOpen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsyncOpen(aAsyncOpen); } \
  NS_IMETHOD GetDomainLookupStart(mozilla::TimeStamp *aDomainLookupStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainLookupStart(aDomainLookupStart); } \
  NS_IMETHOD GetDomainLookupEnd(mozilla::TimeStamp *aDomainLookupEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainLookupEnd(aDomainLookupEnd); } \
  NS_IMETHOD GetConnectStart(mozilla::TimeStamp *aConnectStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectStart(aConnectStart); } \
  NS_IMETHOD GetConnectEnd(mozilla::TimeStamp *aConnectEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectEnd(aConnectEnd); } \
  NS_IMETHOD GetRequestStart(mozilla::TimeStamp *aRequestStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestStart(aRequestStart); } \
  NS_IMETHOD GetResponseStart(mozilla::TimeStamp *aResponseStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseStart(aResponseStart); } \
  NS_IMETHOD GetResponseEnd(mozilla::TimeStamp *aResponseEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseEnd(aResponseEnd); } \
  NS_IMETHOD GetCacheReadStart(mozilla::TimeStamp *aCacheReadStart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheReadStart(aCacheReadStart); } \
  NS_IMETHOD GetCacheReadEnd(mozilla::TimeStamp *aCacheReadEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheReadEnd(aCacheReadEnd); } \
  NS_IMETHOD GetChannelCreationTime(PRTime *aChannelCreationTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelCreationTime(aChannelCreationTime); } \
  NS_IMETHOD GetAsyncOpenTime(PRTime *aAsyncOpenTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsyncOpenTime(aAsyncOpenTime); } \
  NS_IMETHOD GetDomainLookupStartTime(PRTime *aDomainLookupStartTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainLookupStartTime(aDomainLookupStartTime); } \
  NS_IMETHOD GetDomainLookupEndTime(PRTime *aDomainLookupEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomainLookupEndTime(aDomainLookupEndTime); } \
  NS_IMETHOD GetConnectStartTime(PRTime *aConnectStartTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectStartTime(aConnectStartTime); } \
  NS_IMETHOD GetConnectEndTime(PRTime *aConnectEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConnectEndTime(aConnectEndTime); } \
  NS_IMETHOD GetRequestStartTime(PRTime *aRequestStartTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestStartTime(aRequestStartTime); } \
  NS_IMETHOD GetResponseStartTime(PRTime *aResponseStartTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseStartTime(aResponseStartTime); } \
  NS_IMETHOD GetResponseEndTime(PRTime *aResponseEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseEndTime(aResponseEndTime); } \
  NS_IMETHOD GetCacheReadStartTime(PRTime *aCacheReadStartTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheReadStartTime(aCacheReadStartTime); } \
  NS_IMETHOD GetCacheReadEndTime(PRTime *aCacheReadEndTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCacheReadEndTime(aCacheReadEndTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTimedChannel : public nsITimedChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITIMEDCHANNEL

  nsTimedChannel();

private:
  ~nsTimedChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTimedChannel, nsITimedChannel)

nsTimedChannel::nsTimedChannel()
{
  /* member initializers and constructor code */
}

nsTimedChannel::~nsTimedChannel()
{
  /* destructor code */
}

/* attribute boolean timingEnabled; */
NS_IMETHODIMP nsTimedChannel::GetTimingEnabled(bool *aTimingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTimedChannel::SetTimingEnabled(bool aTimingEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp channelCreation; */
NS_IMETHODIMP nsTimedChannel::GetChannelCreation(mozilla::TimeStamp *aChannelCreation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp asyncOpen; */
NS_IMETHODIMP nsTimedChannel::GetAsyncOpen(mozilla::TimeStamp *aAsyncOpen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp domainLookupStart; */
NS_IMETHODIMP nsTimedChannel::GetDomainLookupStart(mozilla::TimeStamp *aDomainLookupStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp domainLookupEnd; */
NS_IMETHODIMP nsTimedChannel::GetDomainLookupEnd(mozilla::TimeStamp *aDomainLookupEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp connectStart; */
NS_IMETHODIMP nsTimedChannel::GetConnectStart(mozilla::TimeStamp *aConnectStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp connectEnd; */
NS_IMETHODIMP nsTimedChannel::GetConnectEnd(mozilla::TimeStamp *aConnectEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp requestStart; */
NS_IMETHODIMP nsTimedChannel::GetRequestStart(mozilla::TimeStamp *aRequestStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp responseStart; */
NS_IMETHODIMP nsTimedChannel::GetResponseStart(mozilla::TimeStamp *aResponseStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp responseEnd; */
NS_IMETHODIMP nsTimedChannel::GetResponseEnd(mozilla::TimeStamp *aResponseEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp cacheReadStart; */
NS_IMETHODIMP nsTimedChannel::GetCacheReadStart(mozilla::TimeStamp *aCacheReadStart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute TimeStamp cacheReadEnd; */
NS_IMETHODIMP nsTimedChannel::GetCacheReadEnd(mozilla::TimeStamp *aCacheReadEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime channelCreationTime; */
NS_IMETHODIMP nsTimedChannel::GetChannelCreationTime(PRTime *aChannelCreationTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime asyncOpenTime; */
NS_IMETHODIMP nsTimedChannel::GetAsyncOpenTime(PRTime *aAsyncOpenTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime domainLookupStartTime; */
NS_IMETHODIMP nsTimedChannel::GetDomainLookupStartTime(PRTime *aDomainLookupStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime domainLookupEndTime; */
NS_IMETHODIMP nsTimedChannel::GetDomainLookupEndTime(PRTime *aDomainLookupEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime connectStartTime; */
NS_IMETHODIMP nsTimedChannel::GetConnectStartTime(PRTime *aConnectStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime connectEndTime; */
NS_IMETHODIMP nsTimedChannel::GetConnectEndTime(PRTime *aConnectEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime requestStartTime; */
NS_IMETHODIMP nsTimedChannel::GetRequestStartTime(PRTime *aRequestStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime responseStartTime; */
NS_IMETHODIMP nsTimedChannel::GetResponseStartTime(PRTime *aResponseStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime responseEndTime; */
NS_IMETHODIMP nsTimedChannel::GetResponseEndTime(PRTime *aResponseEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime cacheReadStartTime; */
NS_IMETHODIMP nsTimedChannel::GetCacheReadStartTime(PRTime *aCacheReadStartTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime cacheReadEndTime; */
NS_IMETHODIMP nsTimedChannel::GetCacheReadEndTime(PRTime *aCacheReadEndTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITimedChannel_h__ */
