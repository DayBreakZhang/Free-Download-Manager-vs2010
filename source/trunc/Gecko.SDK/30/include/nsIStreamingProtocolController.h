/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStreamingProtocolController.idl
 */

#ifndef __gen_nsIStreamingProtocolController_h__
#define __gen_nsIStreamingProtocolController_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

#define MEDIASTREAM_FRAMETYPE_NORMAL          0x00000001
#define MEDIASTREAM_FRAMETYPE_DISCONTINUITY   0x00000002

/* starting interface:    nsIStreamingProtocolMetaData */
#define NS_ISTREAMINGPROTOCOLMETADATA_IID_STR "294adb30-856c-11e2-9e96-0800200c9a66"

#define NS_ISTREAMINGPROTOCOLMETADATA_IID \
  {0x294adb30, 0x856c, 0x11e2, \
    { 0x9e, 0x96, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIStreamingProtocolMetaData : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMINGPROTOCOLMETADATA_IID)

  /* attribute uint32_t frameType; */
  NS_IMETHOD GetFrameType(uint32_t *aFrameType) = 0;
  NS_IMETHOD SetFrameType(uint32_t aFrameType) = 0;

  /* attribute uint32_t totalTracks; */
  NS_IMETHOD GetTotalTracks(uint32_t *aTotalTracks) = 0;
  NS_IMETHOD SetTotalTracks(uint32_t aTotalTracks) = 0;

  /* attribute ACString mimeType; */
  NS_IMETHOD GetMimeType(nsACString & aMimeType) = 0;
  NS_IMETHOD SetMimeType(const nsACString & aMimeType) = 0;

  /* attribute unsigned long width; */
  NS_IMETHOD GetWidth(uint32_t *aWidth) = 0;
  NS_IMETHOD SetWidth(uint32_t aWidth) = 0;

  /* attribute unsigned long height; */
  NS_IMETHOD GetHeight(uint32_t *aHeight) = 0;
  NS_IMETHOD SetHeight(uint32_t aHeight) = 0;

  /* attribute unsigned long long duration; */
  NS_IMETHOD GetDuration(uint64_t *aDuration) = 0;
  NS_IMETHOD SetDuration(uint64_t aDuration) = 0;

  /* attribute unsigned long sampleRate; */
  NS_IMETHOD GetSampleRate(uint32_t *aSampleRate) = 0;
  NS_IMETHOD SetSampleRate(uint32_t aSampleRate) = 0;

  /* attribute unsigned long long timeStamp; */
  NS_IMETHOD GetTimeStamp(uint64_t *aTimeStamp) = 0;
  NS_IMETHOD SetTimeStamp(uint64_t aTimeStamp) = 0;

  /* attribute unsigned long channelCount; */
  NS_IMETHOD GetChannelCount(uint32_t *aChannelCount) = 0;
  NS_IMETHOD SetChannelCount(uint32_t aChannelCount) = 0;

  /* attribute ACString esdsData; */
  NS_IMETHOD GetEsdsData(nsACString & aEsdsData) = 0;
  NS_IMETHOD SetEsdsData(const nsACString & aEsdsData) = 0;

  /* attribute ACString avccData; */
  NS_IMETHOD GetAvccData(nsACString & aAvccData) = 0;
  NS_IMETHOD SetAvccData(const nsACString & aAvccData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamingProtocolMetaData, NS_ISTREAMINGPROTOCOLMETADATA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMINGPROTOCOLMETADATA \
  NS_IMETHOD GetFrameType(uint32_t *aFrameType); \
  NS_IMETHOD SetFrameType(uint32_t aFrameType); \
  NS_IMETHOD GetTotalTracks(uint32_t *aTotalTracks); \
  NS_IMETHOD SetTotalTracks(uint32_t aTotalTracks); \
  NS_IMETHOD GetMimeType(nsACString & aMimeType); \
  NS_IMETHOD SetMimeType(const nsACString & aMimeType); \
  NS_IMETHOD GetWidth(uint32_t *aWidth); \
  NS_IMETHOD SetWidth(uint32_t aWidth); \
  NS_IMETHOD GetHeight(uint32_t *aHeight); \
  NS_IMETHOD SetHeight(uint32_t aHeight); \
  NS_IMETHOD GetDuration(uint64_t *aDuration); \
  NS_IMETHOD SetDuration(uint64_t aDuration); \
  NS_IMETHOD GetSampleRate(uint32_t *aSampleRate); \
  NS_IMETHOD SetSampleRate(uint32_t aSampleRate); \
  NS_IMETHOD GetTimeStamp(uint64_t *aTimeStamp); \
  NS_IMETHOD SetTimeStamp(uint64_t aTimeStamp); \
  NS_IMETHOD GetChannelCount(uint32_t *aChannelCount); \
  NS_IMETHOD SetChannelCount(uint32_t aChannelCount); \
  NS_IMETHOD GetEsdsData(nsACString & aEsdsData); \
  NS_IMETHOD SetEsdsData(const nsACString & aEsdsData); \
  NS_IMETHOD GetAvccData(nsACString & aAvccData); \
  NS_IMETHOD SetAvccData(const nsACString & aAvccData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMINGPROTOCOLMETADATA(_to) \
  NS_IMETHOD GetFrameType(uint32_t *aFrameType) { return _to GetFrameType(aFrameType); } \
  NS_IMETHOD SetFrameType(uint32_t aFrameType) { return _to SetFrameType(aFrameType); } \
  NS_IMETHOD GetTotalTracks(uint32_t *aTotalTracks) { return _to GetTotalTracks(aTotalTracks); } \
  NS_IMETHOD SetTotalTracks(uint32_t aTotalTracks) { return _to SetTotalTracks(aTotalTracks); } \
  NS_IMETHOD GetMimeType(nsACString & aMimeType) { return _to GetMimeType(aMimeType); } \
  NS_IMETHOD SetMimeType(const nsACString & aMimeType) { return _to SetMimeType(aMimeType); } \
  NS_IMETHOD GetWidth(uint32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(uint32_t aWidth) { return _to SetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(uint32_t aHeight) { return _to SetHeight(aHeight); } \
  NS_IMETHOD GetDuration(uint64_t *aDuration) { return _to GetDuration(aDuration); } \
  NS_IMETHOD SetDuration(uint64_t aDuration) { return _to SetDuration(aDuration); } \
  NS_IMETHOD GetSampleRate(uint32_t *aSampleRate) { return _to GetSampleRate(aSampleRate); } \
  NS_IMETHOD SetSampleRate(uint32_t aSampleRate) { return _to SetSampleRate(aSampleRate); } \
  NS_IMETHOD GetTimeStamp(uint64_t *aTimeStamp) { return _to GetTimeStamp(aTimeStamp); } \
  NS_IMETHOD SetTimeStamp(uint64_t aTimeStamp) { return _to SetTimeStamp(aTimeStamp); } \
  NS_IMETHOD GetChannelCount(uint32_t *aChannelCount) { return _to GetChannelCount(aChannelCount); } \
  NS_IMETHOD SetChannelCount(uint32_t aChannelCount) { return _to SetChannelCount(aChannelCount); } \
  NS_IMETHOD GetEsdsData(nsACString & aEsdsData) { return _to GetEsdsData(aEsdsData); } \
  NS_IMETHOD SetEsdsData(const nsACString & aEsdsData) { return _to SetEsdsData(aEsdsData); } \
  NS_IMETHOD GetAvccData(nsACString & aAvccData) { return _to GetAvccData(aAvccData); } \
  NS_IMETHOD SetAvccData(const nsACString & aAvccData) { return _to SetAvccData(aAvccData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMINGPROTOCOLMETADATA(_to) \
  NS_IMETHOD GetFrameType(uint32_t *aFrameType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFrameType(aFrameType); } \
  NS_IMETHOD SetFrameType(uint32_t aFrameType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFrameType(aFrameType); } \
  NS_IMETHOD GetTotalTracks(uint32_t *aTotalTracks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalTracks(aTotalTracks); } \
  NS_IMETHOD SetTotalTracks(uint32_t aTotalTracks) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTotalTracks(aTotalTracks); } \
  NS_IMETHOD GetMimeType(nsACString & aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMimeType(aMimeType); } \
  NS_IMETHOD SetMimeType(const nsACString & aMimeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMimeType(aMimeType); } \
  NS_IMETHOD GetWidth(uint32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD SetWidth(uint32_t aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_IMETHOD GetHeight(uint32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD SetHeight(uint32_t aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_IMETHOD GetDuration(uint64_t *aDuration) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDuration(aDuration); } \
  NS_IMETHOD SetDuration(uint64_t aDuration) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDuration(aDuration); } \
  NS_IMETHOD GetSampleRate(uint32_t *aSampleRate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSampleRate(aSampleRate); } \
  NS_IMETHOD SetSampleRate(uint32_t aSampleRate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSampleRate(aSampleRate); } \
  NS_IMETHOD GetTimeStamp(uint64_t *aTimeStamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimeStamp(aTimeStamp); } \
  NS_IMETHOD SetTimeStamp(uint64_t aTimeStamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTimeStamp(aTimeStamp); } \
  NS_IMETHOD GetChannelCount(uint32_t *aChannelCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelCount(aChannelCount); } \
  NS_IMETHOD SetChannelCount(uint32_t aChannelCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChannelCount(aChannelCount); } \
  NS_IMETHOD GetEsdsData(nsACString & aEsdsData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEsdsData(aEsdsData); } \
  NS_IMETHOD SetEsdsData(const nsACString & aEsdsData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEsdsData(aEsdsData); } \
  NS_IMETHOD GetAvccData(nsACString & aAvccData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAvccData(aAvccData); } \
  NS_IMETHOD SetAvccData(const nsACString & aAvccData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAvccData(aAvccData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamingProtocolMetaData : public nsIStreamingProtocolMetaData
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMINGPROTOCOLMETADATA

  nsStreamingProtocolMetaData();

private:
  ~nsStreamingProtocolMetaData();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamingProtocolMetaData, nsIStreamingProtocolMetaData)

nsStreamingProtocolMetaData::nsStreamingProtocolMetaData()
{
  /* member initializers and constructor code */
}

nsStreamingProtocolMetaData::~nsStreamingProtocolMetaData()
{
  /* destructor code */
}

/* attribute uint32_t frameType; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetFrameType(uint32_t *aFrameType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetFrameType(uint32_t aFrameType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute uint32_t totalTracks; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetTotalTracks(uint32_t *aTotalTracks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetTotalTracks(uint32_t aTotalTracks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString mimeType; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetMimeType(nsACString & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetMimeType(const nsACString & aMimeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long width; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetWidth(uint32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetWidth(uint32_t aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long height; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetHeight(uint32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetHeight(uint32_t aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long long duration; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetDuration(uint64_t *aDuration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetDuration(uint64_t aDuration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long sampleRate; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetSampleRate(uint32_t *aSampleRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetSampleRate(uint32_t aSampleRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long long timeStamp; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetTimeStamp(uint64_t *aTimeStamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetTimeStamp(uint64_t aTimeStamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long channelCount; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetChannelCount(uint32_t *aChannelCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetChannelCount(uint32_t aChannelCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString esdsData; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetEsdsData(nsACString & aEsdsData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetEsdsData(const nsACString & aEsdsData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString avccData; */
NS_IMETHODIMP nsStreamingProtocolMetaData::GetAvccData(nsACString & aAvccData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsStreamingProtocolMetaData::SetAvccData(const nsACString & aAvccData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStreamingProtocolListener */
#define NS_ISTREAMINGPROTOCOLLISTENER_IID_STR "c4f6b660-892e-11e2-9e96-0800200c9a66"

#define NS_ISTREAMINGPROTOCOLLISTENER_IID \
  {0xc4f6b660, 0x892e, 0x11e2, \
    { 0x9e, 0x96, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIStreamingProtocolListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMINGPROTOCOLLISTENER_IID)

  /* void onMediaDataAvailable (in uint8_t index, in ACString data, in uint32_t length, in uint32_t offset, in nsIStreamingProtocolMetaData meta); */
  NS_IMETHOD OnMediaDataAvailable(uint8_t index, const nsACString & data, uint32_t length, uint32_t offset, nsIStreamingProtocolMetaData *meta) = 0;

  /* void onConnected (in uint8_t index, in nsIStreamingProtocolMetaData meta); */
  NS_IMETHOD OnConnected(uint8_t index, nsIStreamingProtocolMetaData *meta) = 0;

  /* void onDisconnected (in uint8_t index, in nsresult reason); */
  NS_IMETHOD OnDisconnected(uint8_t index, nsresult reason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamingProtocolListener, NS_ISTREAMINGPROTOCOLLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMINGPROTOCOLLISTENER \
  NS_IMETHOD OnMediaDataAvailable(uint8_t index, const nsACString & data, uint32_t length, uint32_t offset, nsIStreamingProtocolMetaData *meta); \
  NS_IMETHOD OnConnected(uint8_t index, nsIStreamingProtocolMetaData *meta); \
  NS_IMETHOD OnDisconnected(uint8_t index, nsresult reason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMINGPROTOCOLLISTENER(_to) \
  NS_IMETHOD OnMediaDataAvailable(uint8_t index, const nsACString & data, uint32_t length, uint32_t offset, nsIStreamingProtocolMetaData *meta) { return _to OnMediaDataAvailable(index, data, length, offset, meta); } \
  NS_IMETHOD OnConnected(uint8_t index, nsIStreamingProtocolMetaData *meta) { return _to OnConnected(index, meta); } \
  NS_IMETHOD OnDisconnected(uint8_t index, nsresult reason) { return _to OnDisconnected(index, reason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMINGPROTOCOLLISTENER(_to) \
  NS_IMETHOD OnMediaDataAvailable(uint8_t index, const nsACString & data, uint32_t length, uint32_t offset, nsIStreamingProtocolMetaData *meta) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnMediaDataAvailable(index, data, length, offset, meta); } \
  NS_IMETHOD OnConnected(uint8_t index, nsIStreamingProtocolMetaData *meta) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnConnected(index, meta); } \
  NS_IMETHOD OnDisconnected(uint8_t index, nsresult reason) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDisconnected(index, reason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamingProtocolListener : public nsIStreamingProtocolListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMINGPROTOCOLLISTENER

  nsStreamingProtocolListener();

private:
  ~nsStreamingProtocolListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamingProtocolListener, nsIStreamingProtocolListener)

nsStreamingProtocolListener::nsStreamingProtocolListener()
{
  /* member initializers and constructor code */
}

nsStreamingProtocolListener::~nsStreamingProtocolListener()
{
  /* destructor code */
}

/* void onMediaDataAvailable (in uint8_t index, in ACString data, in uint32_t length, in uint32_t offset, in nsIStreamingProtocolMetaData meta); */
NS_IMETHODIMP nsStreamingProtocolListener::OnMediaDataAvailable(uint8_t index, const nsACString & data, uint32_t length, uint32_t offset, nsIStreamingProtocolMetaData *meta)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onConnected (in uint8_t index, in nsIStreamingProtocolMetaData meta); */
NS_IMETHODIMP nsStreamingProtocolListener::OnConnected(uint8_t index, nsIStreamingProtocolMetaData *meta)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDisconnected (in uint8_t index, in nsresult reason); */
NS_IMETHODIMP nsStreamingProtocolListener::OnDisconnected(uint8_t index, nsresult reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIStreamingProtocolController */
#define NS_ISTREAMINGPROTOCOLCONTROLLER_IID_STR "a9bdd4b0-8559-11e2-9e96-0800200c9a66"

#define NS_ISTREAMINGPROTOCOLCONTROLLER_IID \
  {0xa9bdd4b0, 0x8559, 0x11e2, \
    { 0x9e, 0x96, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIStreamingProtocolController : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMINGPROTOCOLCONTROLLER_IID)

  /* void init (in nsIURI aUri); */
  NS_IMETHOD Init(nsIURI *aUri) = 0;

  /* void asyncOpen (in nsIStreamingProtocolListener aListener); */
  NS_IMETHOD AsyncOpen(nsIStreamingProtocolListener *aListener) = 0;

  /* nsIStreamingProtocolMetaData getTrackMetaData (in octet index); */
  NS_IMETHOD GetTrackMetaData(uint8_t index, nsIStreamingProtocolMetaData * *_retval) = 0;

  /* void play (); */
  NS_IMETHOD Play(void) = 0;

  /* void pause (); */
  NS_IMETHOD Pause(void) = 0;

  /* void resume (); */
  NS_IMETHOD Resume(void) = 0;

  /* void suspend (); */
  NS_IMETHOD Suspend(void) = 0;

  /* void seek (in unsigned long long seekTimeUs); */
  NS_IMETHOD Seek(uint64_t seekTimeUs) = 0;

  /* void stop (); */
  NS_IMETHOD Stop(void) = 0;

  /* readonly attribute octet totalTracks; */
  NS_IMETHOD GetTotalTracks(uint8_t *aTotalTracks) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamingProtocolController, NS_ISTREAMINGPROTOCOLCONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMINGPROTOCOLCONTROLLER \
  NS_IMETHOD Init(nsIURI *aUri); \
  NS_IMETHOD AsyncOpen(nsIStreamingProtocolListener *aListener); \
  NS_IMETHOD GetTrackMetaData(uint8_t index, nsIStreamingProtocolMetaData * *_retval); \
  NS_IMETHOD Play(void); \
  NS_IMETHOD Pause(void); \
  NS_IMETHOD Resume(void); \
  NS_IMETHOD Suspend(void); \
  NS_IMETHOD Seek(uint64_t seekTimeUs); \
  NS_IMETHOD Stop(void); \
  NS_IMETHOD GetTotalTracks(uint8_t *aTotalTracks); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMINGPROTOCOLCONTROLLER(_to) \
  NS_IMETHOD Init(nsIURI *aUri) { return _to Init(aUri); } \
  NS_IMETHOD AsyncOpen(nsIStreamingProtocolListener *aListener) { return _to AsyncOpen(aListener); } \
  NS_IMETHOD GetTrackMetaData(uint8_t index, nsIStreamingProtocolMetaData * *_retval) { return _to GetTrackMetaData(index, _retval); } \
  NS_IMETHOD Play(void) { return _to Play(); } \
  NS_IMETHOD Pause(void) { return _to Pause(); } \
  NS_IMETHOD Resume(void) { return _to Resume(); } \
  NS_IMETHOD Suspend(void) { return _to Suspend(); } \
  NS_IMETHOD Seek(uint64_t seekTimeUs) { return _to Seek(seekTimeUs); } \
  NS_IMETHOD Stop(void) { return _to Stop(); } \
  NS_IMETHOD GetTotalTracks(uint8_t *aTotalTracks) { return _to GetTotalTracks(aTotalTracks); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMINGPROTOCOLCONTROLLER(_to) \
  NS_IMETHOD Init(nsIURI *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aUri); } \
  NS_IMETHOD AsyncOpen(nsIStreamingProtocolListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncOpen(aListener); } \
  NS_IMETHOD GetTrackMetaData(uint8_t index, nsIStreamingProtocolMetaData * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTrackMetaData(index, _retval); } \
  NS_IMETHOD Play(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Play(); } \
  NS_IMETHOD Pause(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Pause(); } \
  NS_IMETHOD Resume(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Resume(); } \
  NS_IMETHOD Suspend(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Suspend(); } \
  NS_IMETHOD Seek(uint64_t seekTimeUs) { return !_to ? NS_ERROR_NULL_POINTER : _to->Seek(seekTimeUs); } \
  NS_IMETHOD Stop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_IMETHOD GetTotalTracks(uint8_t *aTotalTracks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTotalTracks(aTotalTracks); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamingProtocolController : public nsIStreamingProtocolController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMINGPROTOCOLCONTROLLER

  nsStreamingProtocolController();

private:
  ~nsStreamingProtocolController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamingProtocolController, nsIStreamingProtocolController)

nsStreamingProtocolController::nsStreamingProtocolController()
{
  /* member initializers and constructor code */
}

nsStreamingProtocolController::~nsStreamingProtocolController()
{
  /* destructor code */
}

/* void init (in nsIURI aUri); */
NS_IMETHODIMP nsStreamingProtocolController::Init(nsIURI *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncOpen (in nsIStreamingProtocolListener aListener); */
NS_IMETHODIMP nsStreamingProtocolController::AsyncOpen(nsIStreamingProtocolListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIStreamingProtocolMetaData getTrackMetaData (in octet index); */
NS_IMETHODIMP nsStreamingProtocolController::GetTrackMetaData(uint8_t index, nsIStreamingProtocolMetaData * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void play (); */
NS_IMETHODIMP nsStreamingProtocolController::Play()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pause (); */
NS_IMETHODIMP nsStreamingProtocolController::Pause()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resume (); */
NS_IMETHODIMP nsStreamingProtocolController::Resume()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void suspend (); */
NS_IMETHODIMP nsStreamingProtocolController::Suspend()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void seek (in unsigned long long seekTimeUs); */
NS_IMETHODIMP nsStreamingProtocolController::Seek(uint64_t seekTimeUs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (); */
NS_IMETHODIMP nsStreamingProtocolController::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute octet totalTracks; */
NS_IMETHODIMP nsStreamingProtocolController::GetTotalTracks(uint8_t *aTotalTracks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamingProtocolController_h__ */
