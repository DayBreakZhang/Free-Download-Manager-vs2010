/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/html/nsIDOMHTMLMediaElement.idl
 */

#ifndef __gen_nsIDOMHTMLMediaElement_h__
#define __gen_nsIDOMHTMLMediaElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

#ifndef __gen_nsIDOMMediaError_h__
#include "nsIDOMMediaError.h"
#endif

#ifndef __gen_nsIDOMTimeRanges_h__
#include "nsIDOMTimeRanges.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#ifdef GetCurrentTime
#undef GetCurrentTime
#endif

/* starting interface:    nsIDOMHTMLMediaElement */
#define NS_IDOMHTMLMEDIAELEMENT_IID_STR "91f65f50-74ea-40ea-8e26-652290738730"

#define NS_IDOMHTMLMEDIAELEMENT_IID \
  {0x91f65f50, 0x74ea, 0x40ea, \
    { 0x8e, 0x26, 0x65, 0x22, 0x90, 0x73, 0x87, 0x30 }}

/**
 * The nsIDOMHTMLMediaElement interface is an interface to be implemented by the HTML
 * <audio> and <video> elements.
 *
 * For more information on this interface, please see
 * http://www.whatwg.org/specs/web-apps/current-work/#htmlmediaelement
 *
 * @status UNDER_DEVELOPMENT
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLMediaElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLMEDIAELEMENT_IID)

  /* readonly attribute nsIDOMMediaError error; */
  NS_SCRIPTABLE NS_IMETHOD GetError(nsIDOMMediaError **aError) = 0;

  /* attribute DOMString src; */
  NS_SCRIPTABLE NS_IMETHOD GetSrc(nsAString & aSrc) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSrc(const nsAString & aSrc) = 0;

  /* readonly attribute DOMString currentSrc; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentSrc(nsAString & aCurrentSrc) = 0;

  enum { NETWORK_EMPTY = 0U };

  enum { NETWORK_IDLE = 1U };

  enum { NETWORK_LOADING = 2U };

  enum { NETWORK_NO_SOURCE = 3U };

  /* readonly attribute unsigned short networkState; */
  NS_SCRIPTABLE NS_IMETHOD GetNetworkState(PRUint16 *aNetworkState) = 0;

  /* attribute DOMString preload; */
  NS_SCRIPTABLE NS_IMETHOD GetPreload(nsAString & aPreload) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetPreload(const nsAString & aPreload) = 0;

  /* readonly attribute nsIDOMTimeRanges buffered; */
  NS_SCRIPTABLE NS_IMETHOD GetBuffered(nsIDOMTimeRanges **aBuffered) = 0;

  /* void load (); */
  NS_SCRIPTABLE NS_IMETHOD Load(void) = 0;

  /* DOMString canPlayType (in DOMString type); */
  NS_SCRIPTABLE NS_IMETHOD CanPlayType(const nsAString & type, nsAString & _retval NS_OUTPARAM) = 0;

  enum { HAVE_NOTHING = 0U };

  enum { HAVE_METADATA = 1U };

  enum { HAVE_CURRENT_DATA = 2U };

  enum { HAVE_FUTURE_DATA = 3U };

  enum { HAVE_ENOUGH_DATA = 4U };

  /* readonly attribute unsigned short readyState; */
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) = 0;

  /* readonly attribute boolean seeking; */
  NS_SCRIPTABLE NS_IMETHOD GetSeeking(PRBool *aSeeking) = 0;

  /* attribute double currentTime; */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentTime(double *aCurrentTime) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCurrentTime(double aCurrentTime) = 0;

  /* readonly attribute double duration; */
  NS_SCRIPTABLE NS_IMETHOD GetDuration(double *aDuration) = 0;

  /* readonly attribute boolean paused; */
  NS_SCRIPTABLE NS_IMETHOD GetPaused(PRBool *aPaused) = 0;

  /* readonly attribute boolean ended; */
  NS_SCRIPTABLE NS_IMETHOD GetEnded(PRBool *aEnded) = 0;

  /* readonly attribute boolean mozAutoplayEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetMozAutoplayEnabled(PRBool *aMozAutoplayEnabled) = 0;

  /* attribute boolean autoplay; */
  NS_SCRIPTABLE NS_IMETHOD GetAutoplay(PRBool *aAutoplay) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAutoplay(PRBool aAutoplay) = 0;

  /* void play (); */
  NS_SCRIPTABLE NS_IMETHOD Play(void) = 0;

  /* void pause (); */
  NS_SCRIPTABLE NS_IMETHOD Pause(void) = 0;

  /* attribute boolean controls; */
  NS_SCRIPTABLE NS_IMETHOD GetControls(PRBool *aControls) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetControls(PRBool aControls) = 0;

  /* attribute double volume; */
  NS_SCRIPTABLE NS_IMETHOD GetVolume(double *aVolume) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetVolume(double aVolume) = 0;

  /* attribute boolean muted; */
  NS_SCRIPTABLE NS_IMETHOD GetMuted(PRBool *aMuted) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMuted(PRBool aMuted) = 0;

  /* readonly attribute unsigned long mozChannels; */
  NS_SCRIPTABLE NS_IMETHOD GetMozChannels(PRUint32 *aMozChannels) = 0;

  /* readonly attribute unsigned long mozSampleRate; */
  NS_SCRIPTABLE NS_IMETHOD GetMozSampleRate(PRUint32 *aMozSampleRate) = 0;

  /* attribute unsigned long mozFrameBufferLength; */
  NS_SCRIPTABLE NS_IMETHOD GetMozFrameBufferLength(PRUint32 *aMozFrameBufferLength) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetMozFrameBufferLength(PRUint32 aMozFrameBufferLength) = 0;

  /* void mozLoadFrom (in nsIDOMHTMLMediaElement other); */
  NS_SCRIPTABLE NS_IMETHOD MozLoadFrom(nsIDOMHTMLMediaElement *other) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLMediaElement, NS_IDOMHTMLMEDIAELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLMEDIAELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetError(nsIDOMMediaError **aError); \
  NS_SCRIPTABLE NS_IMETHOD GetSrc(nsAString & aSrc); \
  NS_SCRIPTABLE NS_IMETHOD SetSrc(const nsAString & aSrc); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentSrc(nsAString & aCurrentSrc); \
  NS_SCRIPTABLE NS_IMETHOD GetNetworkState(PRUint16 *aNetworkState); \
  NS_SCRIPTABLE NS_IMETHOD GetPreload(nsAString & aPreload); \
  NS_SCRIPTABLE NS_IMETHOD SetPreload(const nsAString & aPreload); \
  NS_SCRIPTABLE NS_IMETHOD GetBuffered(nsIDOMTimeRanges **aBuffered); \
  NS_SCRIPTABLE NS_IMETHOD Load(void); \
  NS_SCRIPTABLE NS_IMETHOD CanPlayType(const nsAString & type, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState); \
  NS_SCRIPTABLE NS_IMETHOD GetSeeking(PRBool *aSeeking); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentTime(double *aCurrentTime); \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentTime(double aCurrentTime); \
  NS_SCRIPTABLE NS_IMETHOD GetDuration(double *aDuration); \
  NS_SCRIPTABLE NS_IMETHOD GetPaused(PRBool *aPaused); \
  NS_SCRIPTABLE NS_IMETHOD GetEnded(PRBool *aEnded); \
  NS_SCRIPTABLE NS_IMETHOD GetMozAutoplayEnabled(PRBool *aMozAutoplayEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetAutoplay(PRBool *aAutoplay); \
  NS_SCRIPTABLE NS_IMETHOD SetAutoplay(PRBool aAutoplay); \
  NS_SCRIPTABLE NS_IMETHOD Play(void); \
  NS_SCRIPTABLE NS_IMETHOD Pause(void); \
  NS_SCRIPTABLE NS_IMETHOD GetControls(PRBool *aControls); \
  NS_SCRIPTABLE NS_IMETHOD SetControls(PRBool aControls); \
  NS_SCRIPTABLE NS_IMETHOD GetVolume(double *aVolume); \
  NS_SCRIPTABLE NS_IMETHOD SetVolume(double aVolume); \
  NS_SCRIPTABLE NS_IMETHOD GetMuted(PRBool *aMuted); \
  NS_SCRIPTABLE NS_IMETHOD SetMuted(PRBool aMuted); \
  NS_SCRIPTABLE NS_IMETHOD GetMozChannels(PRUint32 *aMozChannels); \
  NS_SCRIPTABLE NS_IMETHOD GetMozSampleRate(PRUint32 *aMozSampleRate); \
  NS_SCRIPTABLE NS_IMETHOD GetMozFrameBufferLength(PRUint32 *aMozFrameBufferLength); \
  NS_SCRIPTABLE NS_IMETHOD SetMozFrameBufferLength(PRUint32 aMozFrameBufferLength); \
  NS_SCRIPTABLE NS_IMETHOD MozLoadFrom(nsIDOMHTMLMediaElement *other); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLMEDIAELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetError(nsIDOMMediaError **aError) { return _to GetError(aError); } \
  NS_SCRIPTABLE NS_IMETHOD GetSrc(nsAString & aSrc) { return _to GetSrc(aSrc); } \
  NS_SCRIPTABLE NS_IMETHOD SetSrc(const nsAString & aSrc) { return _to SetSrc(aSrc); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentSrc(nsAString & aCurrentSrc) { return _to GetCurrentSrc(aCurrentSrc); } \
  NS_SCRIPTABLE NS_IMETHOD GetNetworkState(PRUint16 *aNetworkState) { return _to GetNetworkState(aNetworkState); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreload(nsAString & aPreload) { return _to GetPreload(aPreload); } \
  NS_SCRIPTABLE NS_IMETHOD SetPreload(const nsAString & aPreload) { return _to SetPreload(aPreload); } \
  NS_SCRIPTABLE NS_IMETHOD GetBuffered(nsIDOMTimeRanges **aBuffered) { return _to GetBuffered(aBuffered); } \
  NS_SCRIPTABLE NS_IMETHOD Load(void) { return _to Load(); } \
  NS_SCRIPTABLE NS_IMETHOD CanPlayType(const nsAString & type, nsAString & _retval NS_OUTPARAM) { return _to CanPlayType(type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD GetSeeking(PRBool *aSeeking) { return _to GetSeeking(aSeeking); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentTime(double *aCurrentTime) { return _to GetCurrentTime(aCurrentTime); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentTime(double aCurrentTime) { return _to SetCurrentTime(aCurrentTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetDuration(double *aDuration) { return _to GetDuration(aDuration); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaused(PRBool *aPaused) { return _to GetPaused(aPaused); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnded(PRBool *aEnded) { return _to GetEnded(aEnded); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozAutoplayEnabled(PRBool *aMozAutoplayEnabled) { return _to GetMozAutoplayEnabled(aMozAutoplayEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoplay(PRBool *aAutoplay) { return _to GetAutoplay(aAutoplay); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutoplay(PRBool aAutoplay) { return _to SetAutoplay(aAutoplay); } \
  NS_SCRIPTABLE NS_IMETHOD Play(void) { return _to Play(); } \
  NS_SCRIPTABLE NS_IMETHOD Pause(void) { return _to Pause(); } \
  NS_SCRIPTABLE NS_IMETHOD GetControls(PRBool *aControls) { return _to GetControls(aControls); } \
  NS_SCRIPTABLE NS_IMETHOD SetControls(PRBool aControls) { return _to SetControls(aControls); } \
  NS_SCRIPTABLE NS_IMETHOD GetVolume(double *aVolume) { return _to GetVolume(aVolume); } \
  NS_SCRIPTABLE NS_IMETHOD SetVolume(double aVolume) { return _to SetVolume(aVolume); } \
  NS_SCRIPTABLE NS_IMETHOD GetMuted(PRBool *aMuted) { return _to GetMuted(aMuted); } \
  NS_SCRIPTABLE NS_IMETHOD SetMuted(PRBool aMuted) { return _to SetMuted(aMuted); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozChannels(PRUint32 *aMozChannels) { return _to GetMozChannels(aMozChannels); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozSampleRate(PRUint32 *aMozSampleRate) { return _to GetMozSampleRate(aMozSampleRate); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozFrameBufferLength(PRUint32 *aMozFrameBufferLength) { return _to GetMozFrameBufferLength(aMozFrameBufferLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozFrameBufferLength(PRUint32 aMozFrameBufferLength) { return _to SetMozFrameBufferLength(aMozFrameBufferLength); } \
  NS_SCRIPTABLE NS_IMETHOD MozLoadFrom(nsIDOMHTMLMediaElement *other) { return _to MozLoadFrom(other); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLMEDIAELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetError(nsIDOMMediaError **aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(aError); } \
  NS_SCRIPTABLE NS_IMETHOD GetSrc(nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrc(aSrc); } \
  NS_SCRIPTABLE NS_IMETHOD SetSrc(const nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrc(aSrc); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentSrc(nsAString & aCurrentSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentSrc(aCurrentSrc); } \
  NS_SCRIPTABLE NS_IMETHOD GetNetworkState(PRUint16 *aNetworkState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetworkState(aNetworkState); } \
  NS_SCRIPTABLE NS_IMETHOD GetPreload(nsAString & aPreload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreload(aPreload); } \
  NS_SCRIPTABLE NS_IMETHOD SetPreload(const nsAString & aPreload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreload(aPreload); } \
  NS_SCRIPTABLE NS_IMETHOD GetBuffered(nsIDOMTimeRanges **aBuffered) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuffered(aBuffered); } \
  NS_SCRIPTABLE NS_IMETHOD Load(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Load(); } \
  NS_SCRIPTABLE NS_IMETHOD CanPlayType(const nsAString & type, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPlayType(type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD GetSeeking(PRBool *aSeeking) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSeeking(aSeeking); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentTime(double *aCurrentTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentTime(aCurrentTime); } \
  NS_SCRIPTABLE NS_IMETHOD SetCurrentTime(double aCurrentTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentTime(aCurrentTime); } \
  NS_SCRIPTABLE NS_IMETHOD GetDuration(double *aDuration) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDuration(aDuration); } \
  NS_SCRIPTABLE NS_IMETHOD GetPaused(PRBool *aPaused) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaused(aPaused); } \
  NS_SCRIPTABLE NS_IMETHOD GetEnded(PRBool *aEnded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnded(aEnded); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozAutoplayEnabled(PRBool *aMozAutoplayEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozAutoplayEnabled(aMozAutoplayEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoplay(PRBool *aAutoplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoplay(aAutoplay); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutoplay(PRBool aAutoplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutoplay(aAutoplay); } \
  NS_SCRIPTABLE NS_IMETHOD Play(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Play(); } \
  NS_SCRIPTABLE NS_IMETHOD Pause(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Pause(); } \
  NS_SCRIPTABLE NS_IMETHOD GetControls(PRBool *aControls) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControls(aControls); } \
  NS_SCRIPTABLE NS_IMETHOD SetControls(PRBool aControls) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetControls(aControls); } \
  NS_SCRIPTABLE NS_IMETHOD GetVolume(double *aVolume) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVolume(aVolume); } \
  NS_SCRIPTABLE NS_IMETHOD SetVolume(double aVolume) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVolume(aVolume); } \
  NS_SCRIPTABLE NS_IMETHOD GetMuted(PRBool *aMuted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMuted(aMuted); } \
  NS_SCRIPTABLE NS_IMETHOD SetMuted(PRBool aMuted) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMuted(aMuted); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozChannels(PRUint32 *aMozChannels) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozChannels(aMozChannels); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozSampleRate(PRUint32 *aMozSampleRate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozSampleRate(aMozSampleRate); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozFrameBufferLength(PRUint32 *aMozFrameBufferLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFrameBufferLength(aMozFrameBufferLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetMozFrameBufferLength(PRUint32 aMozFrameBufferLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozFrameBufferLength(aMozFrameBufferLength); } \
  NS_SCRIPTABLE NS_IMETHOD MozLoadFrom(nsIDOMHTMLMediaElement *other) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozLoadFrom(other); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLMediaElement : public nsIDOMHTMLMediaElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLMEDIAELEMENT

  nsDOMHTMLMediaElement();

private:
  ~nsDOMHTMLMediaElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLMediaElement, nsIDOMHTMLMediaElement)

nsDOMHTMLMediaElement::nsDOMHTMLMediaElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLMediaElement::~nsDOMHTMLMediaElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMediaError error; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetError(nsIDOMMediaError **aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString src; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetSrc(nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetSrc(const nsAString & aSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString currentSrc; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetCurrentSrc(nsAString & aCurrentSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short networkState; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetNetworkState(PRUint16 *aNetworkState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString preload; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetPreload(nsAString & aPreload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetPreload(const nsAString & aPreload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMTimeRanges buffered; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetBuffered(nsIDOMTimeRanges **aBuffered)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void load (); */
NS_IMETHODIMP nsDOMHTMLMediaElement::Load()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString canPlayType (in DOMString type); */
NS_IMETHODIMP nsDOMHTMLMediaElement::CanPlayType(const nsAString & type, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short readyState; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetReadyState(PRUint16 *aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean seeking; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetSeeking(PRBool *aSeeking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double currentTime; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetCurrentTime(double *aCurrentTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetCurrentTime(double aCurrentTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double duration; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetDuration(double *aDuration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean paused; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetPaused(PRBool *aPaused)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ended; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetEnded(PRBool *aEnded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozAutoplayEnabled; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozAutoplayEnabled(PRBool *aMozAutoplayEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean autoplay; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetAutoplay(PRBool *aAutoplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetAutoplay(PRBool aAutoplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void play (); */
NS_IMETHODIMP nsDOMHTMLMediaElement::Play()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pause (); */
NS_IMETHODIMP nsDOMHTMLMediaElement::Pause()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean controls; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetControls(PRBool *aControls)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetControls(PRBool aControls)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double volume; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetVolume(double *aVolume)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetVolume(double aVolume)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean muted; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMuted(PRBool *aMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetMuted(PRBool aMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozChannels; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozChannels(PRUint32 *aMozChannels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozSampleRate; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozSampleRate(PRUint32 *aMozSampleRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long mozFrameBufferLength; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozFrameBufferLength(PRUint32 *aMozFrameBufferLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetMozFrameBufferLength(PRUint32 aMozFrameBufferLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozLoadFrom (in nsIDOMHTMLMediaElement other); */
NS_IMETHODIMP nsDOMHTMLMediaElement::MozLoadFrom(nsIDOMHTMLMediaElement *other)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLMediaElement_h__ */
