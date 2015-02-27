/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMHTMLMediaElement.idl
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

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMediaStream; /* forward declaration */

#ifdef GetCurrentTime
#undef GetCurrentTime
#endif

/* starting interface:    nsIDOMHTMLMediaElement */
#define NS_IDOMHTMLMEDIAELEMENT_IID_STR "d83d38f3-68b9-4ea2-8748-1cc738d74333"

#define NS_IDOMHTMLMEDIAELEMENT_IID \
  {0xd83d38f3, 0x68b9, 0x4ea2, \
    { 0x87, 0x48, 0x1c, 0xc7, 0x38, 0xd7, 0x43, 0x33 }}

class NS_NO_VTABLE nsIDOMHTMLMediaElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLMEDIAELEMENT_IID)

  /* readonly attribute nsIDOMMediaError error; */
  NS_IMETHOD GetError(nsIDOMMediaError * *aError) = 0;

  /* attribute DOMString src; */
  NS_IMETHOD GetSrc(nsAString & aSrc) = 0;
  NS_IMETHOD SetSrc(const nsAString & aSrc) = 0;

  /* attribute nsIDOMMediaStream mozSrcObject; */
  NS_IMETHOD GetMozSrcObject(nsIDOMMediaStream * *aMozSrcObject) = 0;
  NS_IMETHOD SetMozSrcObject(nsIDOMMediaStream *aMozSrcObject) = 0;

  /* readonly attribute DOMString currentSrc; */
  NS_IMETHOD GetCurrentSrc(nsAString & aCurrentSrc) = 0;

  /* attribute DOMString crossOrigin; */
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) = 0;
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) = 0;

  enum {
    NETWORK_EMPTY = 0U,
    NETWORK_IDLE = 1U,
    NETWORK_LOADING = 2U,
    NETWORK_NO_SOURCE = 3U
  };

  /* readonly attribute unsigned short networkState; */
  NS_IMETHOD GetNetworkState(uint16_t *aNetworkState) = 0;

  /* attribute DOMString preload; */
  NS_IMETHOD GetPreload(nsAString & aPreload) = 0;
  NS_IMETHOD SetPreload(const nsAString & aPreload) = 0;

  /* readonly attribute nsIDOMTimeRanges buffered; */
  NS_IMETHOD GetBuffered(nsIDOMTimeRanges * *aBuffered) = 0;

  /* void load (); */
  NS_IMETHOD Load(void) = 0;

  /* DOMString canPlayType (in DOMString type); */
  NS_IMETHOD CanPlayType(const nsAString & type, nsAString & _retval) = 0;

  enum {
    HAVE_NOTHING = 0U,
    HAVE_METADATA = 1U,
    HAVE_CURRENT_DATA = 2U,
    HAVE_FUTURE_DATA = 3U,
    HAVE_ENOUGH_DATA = 4U
  };

  /* readonly attribute unsigned short readyState; */
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) = 0;

  /* readonly attribute boolean seeking; */
  NS_IMETHOD GetSeeking(bool *aSeeking) = 0;

  /* attribute double currentTime; */
  NS_IMETHOD GetCurrentTime(double *aCurrentTime) = 0;
  NS_IMETHOD SetCurrentTime(double aCurrentTime) = 0;

  /* readonly attribute double duration; */
  NS_IMETHOD GetDuration(double *aDuration) = 0;

  /* readonly attribute boolean paused; */
  NS_IMETHOD GetPaused(bool *aPaused) = 0;

  /* attribute double defaultPlaybackRate; */
  NS_IMETHOD GetDefaultPlaybackRate(double *aDefaultPlaybackRate) = 0;
  NS_IMETHOD SetDefaultPlaybackRate(double aDefaultPlaybackRate) = 0;

  /* attribute double playbackRate; */
  NS_IMETHOD GetPlaybackRate(double *aPlaybackRate) = 0;
  NS_IMETHOD SetPlaybackRate(double aPlaybackRate) = 0;

  /* attribute boolean mozPreservesPitch; */
  NS_IMETHOD GetMozPreservesPitch(bool *aMozPreservesPitch) = 0;
  NS_IMETHOD SetMozPreservesPitch(bool aMozPreservesPitch) = 0;

  /* readonly attribute nsIDOMTimeRanges played; */
  NS_IMETHOD GetPlayed(nsIDOMTimeRanges * *aPlayed) = 0;

  /* readonly attribute nsIDOMTimeRanges seekable; */
  NS_IMETHOD GetSeekable(nsIDOMTimeRanges * *aSeekable) = 0;

  /* readonly attribute boolean ended; */
  NS_IMETHOD GetEnded(bool *aEnded) = 0;

  /* readonly attribute boolean mozAutoplayEnabled; */
  NS_IMETHOD GetMozAutoplayEnabled(bool *aMozAutoplayEnabled) = 0;

  /* attribute boolean autoplay; */
  NS_IMETHOD GetAutoplay(bool *aAutoplay) = 0;
  NS_IMETHOD SetAutoplay(bool aAutoplay) = 0;

  /* attribute boolean loop; */
  NS_IMETHOD GetLoop(bool *aLoop) = 0;
  NS_IMETHOD SetLoop(bool aLoop) = 0;

  /* void play (); */
  NS_IMETHOD Play(void) = 0;

  /* void pause (); */
  NS_IMETHOD Pause(void) = 0;

  /* attribute boolean controls; */
  NS_IMETHOD GetControls(bool *aControls) = 0;
  NS_IMETHOD SetControls(bool aControls) = 0;

  /* attribute double volume; */
  NS_IMETHOD GetVolume(double *aVolume) = 0;
  NS_IMETHOD SetVolume(double aVolume) = 0;

  /* attribute boolean muted; */
  NS_IMETHOD GetMuted(bool *aMuted) = 0;
  NS_IMETHOD SetMuted(bool aMuted) = 0;

  /* attribute boolean defaultMuted; */
  NS_IMETHOD GetDefaultMuted(bool *aDefaultMuted) = 0;
  NS_IMETHOD SetDefaultMuted(bool aDefaultMuted) = 0;

  /* nsIDOMMediaStream mozCaptureStream (); */
  NS_IMETHOD MozCaptureStream(nsIDOMMediaStream * *_retval) = 0;

  /* nsIDOMMediaStream mozCaptureStreamUntilEnded (); */
  NS_IMETHOD MozCaptureStreamUntilEnded(nsIDOMMediaStream * *_retval) = 0;

  /* readonly attribute boolean mozAudioCaptured; */
  NS_IMETHOD GetMozAudioCaptured(bool *aMozAudioCaptured) = 0;

  /* readonly attribute unsigned long mozChannels; */
  NS_IMETHOD GetMozChannels(uint32_t *aMozChannels) = 0;

  /* readonly attribute unsigned long mozSampleRate; */
  NS_IMETHOD GetMozSampleRate(uint32_t *aMozSampleRate) = 0;

  /* attribute unsigned long mozFrameBufferLength; */
  NS_IMETHOD GetMozFrameBufferLength(uint32_t *aMozFrameBufferLength) = 0;
  NS_IMETHOD SetMozFrameBufferLength(uint32_t aMozFrameBufferLength) = 0;

  /* [implicit_jscontext] jsval mozGetMetadata (); */
  NS_IMETHOD MozGetMetadata(JSContext* cx, JS::MutableHandleValue _retval) = 0;

  /* readonly attribute double mozFragmentEnd; */
  NS_IMETHOD GetMozFragmentEnd(double *aMozFragmentEnd) = 0;

  /* attribute DOMString mozAudioChannelType; */
  NS_IMETHOD GetMozAudioChannelType(nsAString & aMozAudioChannelType) = 0;
  NS_IMETHOD SetMozAudioChannelType(const nsAString & aMozAudioChannelType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLMediaElement, NS_IDOMHTMLMEDIAELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLMEDIAELEMENT \
  NS_IMETHOD GetError(nsIDOMMediaError * *aError); \
  NS_IMETHOD GetSrc(nsAString & aSrc); \
  NS_IMETHOD SetSrc(const nsAString & aSrc); \
  NS_IMETHOD GetMozSrcObject(nsIDOMMediaStream * *aMozSrcObject); \
  NS_IMETHOD SetMozSrcObject(nsIDOMMediaStream *aMozSrcObject); \
  NS_IMETHOD GetCurrentSrc(nsAString & aCurrentSrc); \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin); \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin); \
  NS_IMETHOD GetNetworkState(uint16_t *aNetworkState); \
  NS_IMETHOD GetPreload(nsAString & aPreload); \
  NS_IMETHOD SetPreload(const nsAString & aPreload); \
  NS_IMETHOD GetBuffered(nsIDOMTimeRanges * *aBuffered); \
  NS_IMETHOD Load(void); \
  NS_IMETHOD CanPlayType(const nsAString & type, nsAString & _retval); \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState); \
  NS_IMETHOD GetSeeking(bool *aSeeking); \
  NS_IMETHOD GetCurrentTime(double *aCurrentTime); \
  NS_IMETHOD SetCurrentTime(double aCurrentTime); \
  NS_IMETHOD GetDuration(double *aDuration); \
  NS_IMETHOD GetPaused(bool *aPaused); \
  NS_IMETHOD GetDefaultPlaybackRate(double *aDefaultPlaybackRate); \
  NS_IMETHOD SetDefaultPlaybackRate(double aDefaultPlaybackRate); \
  NS_IMETHOD GetPlaybackRate(double *aPlaybackRate); \
  NS_IMETHOD SetPlaybackRate(double aPlaybackRate); \
  NS_IMETHOD GetMozPreservesPitch(bool *aMozPreservesPitch); \
  NS_IMETHOD SetMozPreservesPitch(bool aMozPreservesPitch); \
  NS_IMETHOD GetPlayed(nsIDOMTimeRanges * *aPlayed); \
  NS_IMETHOD GetSeekable(nsIDOMTimeRanges * *aSeekable); \
  NS_IMETHOD GetEnded(bool *aEnded); \
  NS_IMETHOD GetMozAutoplayEnabled(bool *aMozAutoplayEnabled); \
  NS_IMETHOD GetAutoplay(bool *aAutoplay); \
  NS_IMETHOD SetAutoplay(bool aAutoplay); \
  NS_IMETHOD GetLoop(bool *aLoop); \
  NS_IMETHOD SetLoop(bool aLoop); \
  NS_IMETHOD Play(void); \
  NS_IMETHOD Pause(void); \
  NS_IMETHOD GetControls(bool *aControls); \
  NS_IMETHOD SetControls(bool aControls); \
  NS_IMETHOD GetVolume(double *aVolume); \
  NS_IMETHOD SetVolume(double aVolume); \
  NS_IMETHOD GetMuted(bool *aMuted); \
  NS_IMETHOD SetMuted(bool aMuted); \
  NS_IMETHOD GetDefaultMuted(bool *aDefaultMuted); \
  NS_IMETHOD SetDefaultMuted(bool aDefaultMuted); \
  NS_IMETHOD MozCaptureStream(nsIDOMMediaStream * *_retval); \
  NS_IMETHOD MozCaptureStreamUntilEnded(nsIDOMMediaStream * *_retval); \
  NS_IMETHOD GetMozAudioCaptured(bool *aMozAudioCaptured); \
  NS_IMETHOD GetMozChannels(uint32_t *aMozChannels); \
  NS_IMETHOD GetMozSampleRate(uint32_t *aMozSampleRate); \
  NS_IMETHOD GetMozFrameBufferLength(uint32_t *aMozFrameBufferLength); \
  NS_IMETHOD SetMozFrameBufferLength(uint32_t aMozFrameBufferLength); \
  NS_IMETHOD MozGetMetadata(JSContext* cx, JS::MutableHandleValue _retval); \
  NS_IMETHOD GetMozFragmentEnd(double *aMozFragmentEnd); \
  NS_IMETHOD GetMozAudioChannelType(nsAString & aMozAudioChannelType); \
  NS_IMETHOD SetMozAudioChannelType(const nsAString & aMozAudioChannelType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLMEDIAELEMENT(_to) \
  NS_IMETHOD GetError(nsIDOMMediaError * *aError) { return _to GetError(aError); } \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return _to GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return _to SetSrc(aSrc); } \
  NS_IMETHOD GetMozSrcObject(nsIDOMMediaStream * *aMozSrcObject) { return _to GetMozSrcObject(aMozSrcObject); } \
  NS_IMETHOD SetMozSrcObject(nsIDOMMediaStream *aMozSrcObject) { return _to SetMozSrcObject(aMozSrcObject); } \
  NS_IMETHOD GetCurrentSrc(nsAString & aCurrentSrc) { return _to GetCurrentSrc(aCurrentSrc); } \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) { return _to GetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) { return _to SetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD GetNetworkState(uint16_t *aNetworkState) { return _to GetNetworkState(aNetworkState); } \
  NS_IMETHOD GetPreload(nsAString & aPreload) { return _to GetPreload(aPreload); } \
  NS_IMETHOD SetPreload(const nsAString & aPreload) { return _to SetPreload(aPreload); } \
  NS_IMETHOD GetBuffered(nsIDOMTimeRanges * *aBuffered) { return _to GetBuffered(aBuffered); } \
  NS_IMETHOD Load(void) { return _to Load(); } \
  NS_IMETHOD CanPlayType(const nsAString & type, nsAString & _retval) { return _to CanPlayType(type, _retval); } \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetSeeking(bool *aSeeking) { return _to GetSeeking(aSeeking); } \
  NS_IMETHOD GetCurrentTime(double *aCurrentTime) { return _to GetCurrentTime(aCurrentTime); } \
  NS_IMETHOD SetCurrentTime(double aCurrentTime) { return _to SetCurrentTime(aCurrentTime); } \
  NS_IMETHOD GetDuration(double *aDuration) { return _to GetDuration(aDuration); } \
  NS_IMETHOD GetPaused(bool *aPaused) { return _to GetPaused(aPaused); } \
  NS_IMETHOD GetDefaultPlaybackRate(double *aDefaultPlaybackRate) { return _to GetDefaultPlaybackRate(aDefaultPlaybackRate); } \
  NS_IMETHOD SetDefaultPlaybackRate(double aDefaultPlaybackRate) { return _to SetDefaultPlaybackRate(aDefaultPlaybackRate); } \
  NS_IMETHOD GetPlaybackRate(double *aPlaybackRate) { return _to GetPlaybackRate(aPlaybackRate); } \
  NS_IMETHOD SetPlaybackRate(double aPlaybackRate) { return _to SetPlaybackRate(aPlaybackRate); } \
  NS_IMETHOD GetMozPreservesPitch(bool *aMozPreservesPitch) { return _to GetMozPreservesPitch(aMozPreservesPitch); } \
  NS_IMETHOD SetMozPreservesPitch(bool aMozPreservesPitch) { return _to SetMozPreservesPitch(aMozPreservesPitch); } \
  NS_IMETHOD GetPlayed(nsIDOMTimeRanges * *aPlayed) { return _to GetPlayed(aPlayed); } \
  NS_IMETHOD GetSeekable(nsIDOMTimeRanges * *aSeekable) { return _to GetSeekable(aSeekable); } \
  NS_IMETHOD GetEnded(bool *aEnded) { return _to GetEnded(aEnded); } \
  NS_IMETHOD GetMozAutoplayEnabled(bool *aMozAutoplayEnabled) { return _to GetMozAutoplayEnabled(aMozAutoplayEnabled); } \
  NS_IMETHOD GetAutoplay(bool *aAutoplay) { return _to GetAutoplay(aAutoplay); } \
  NS_IMETHOD SetAutoplay(bool aAutoplay) { return _to SetAutoplay(aAutoplay); } \
  NS_IMETHOD GetLoop(bool *aLoop) { return _to GetLoop(aLoop); } \
  NS_IMETHOD SetLoop(bool aLoop) { return _to SetLoop(aLoop); } \
  NS_IMETHOD Play(void) { return _to Play(); } \
  NS_IMETHOD Pause(void) { return _to Pause(); } \
  NS_IMETHOD GetControls(bool *aControls) { return _to GetControls(aControls); } \
  NS_IMETHOD SetControls(bool aControls) { return _to SetControls(aControls); } \
  NS_IMETHOD GetVolume(double *aVolume) { return _to GetVolume(aVolume); } \
  NS_IMETHOD SetVolume(double aVolume) { return _to SetVolume(aVolume); } \
  NS_IMETHOD GetMuted(bool *aMuted) { return _to GetMuted(aMuted); } \
  NS_IMETHOD SetMuted(bool aMuted) { return _to SetMuted(aMuted); } \
  NS_IMETHOD GetDefaultMuted(bool *aDefaultMuted) { return _to GetDefaultMuted(aDefaultMuted); } \
  NS_IMETHOD SetDefaultMuted(bool aDefaultMuted) { return _to SetDefaultMuted(aDefaultMuted); } \
  NS_IMETHOD MozCaptureStream(nsIDOMMediaStream * *_retval) { return _to MozCaptureStream(_retval); } \
  NS_IMETHOD MozCaptureStreamUntilEnded(nsIDOMMediaStream * *_retval) { return _to MozCaptureStreamUntilEnded(_retval); } \
  NS_IMETHOD GetMozAudioCaptured(bool *aMozAudioCaptured) { return _to GetMozAudioCaptured(aMozAudioCaptured); } \
  NS_IMETHOD GetMozChannels(uint32_t *aMozChannels) { return _to GetMozChannels(aMozChannels); } \
  NS_IMETHOD GetMozSampleRate(uint32_t *aMozSampleRate) { return _to GetMozSampleRate(aMozSampleRate); } \
  NS_IMETHOD GetMozFrameBufferLength(uint32_t *aMozFrameBufferLength) { return _to GetMozFrameBufferLength(aMozFrameBufferLength); } \
  NS_IMETHOD SetMozFrameBufferLength(uint32_t aMozFrameBufferLength) { return _to SetMozFrameBufferLength(aMozFrameBufferLength); } \
  NS_IMETHOD MozGetMetadata(JSContext* cx, JS::MutableHandleValue _retval) { return _to MozGetMetadata(cx, _retval); } \
  NS_IMETHOD GetMozFragmentEnd(double *aMozFragmentEnd) { return _to GetMozFragmentEnd(aMozFragmentEnd); } \
  NS_IMETHOD GetMozAudioChannelType(nsAString & aMozAudioChannelType) { return _to GetMozAudioChannelType(aMozAudioChannelType); } \
  NS_IMETHOD SetMozAudioChannelType(const nsAString & aMozAudioChannelType) { return _to SetMozAudioChannelType(aMozAudioChannelType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLMEDIAELEMENT(_to) \
  NS_IMETHOD GetError(nsIDOMMediaError * *aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(aError); } \
  NS_IMETHOD GetSrc(nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSrc(aSrc); } \
  NS_IMETHOD SetSrc(const nsAString & aSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSrc(aSrc); } \
  NS_IMETHOD GetMozSrcObject(nsIDOMMediaStream * *aMozSrcObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozSrcObject(aMozSrcObject); } \
  NS_IMETHOD SetMozSrcObject(nsIDOMMediaStream *aMozSrcObject) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozSrcObject(aMozSrcObject); } \
  NS_IMETHOD GetCurrentSrc(nsAString & aCurrentSrc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentSrc(aCurrentSrc); } \
  NS_IMETHOD GetCrossOrigin(nsAString & aCrossOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD SetCrossOrigin(const nsAString & aCrossOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCrossOrigin(aCrossOrigin); } \
  NS_IMETHOD GetNetworkState(uint16_t *aNetworkState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNetworkState(aNetworkState); } \
  NS_IMETHOD GetPreload(nsAString & aPreload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreload(aPreload); } \
  NS_IMETHOD SetPreload(const nsAString & aPreload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPreload(aPreload); } \
  NS_IMETHOD GetBuffered(nsIDOMTimeRanges * *aBuffered) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuffered(aBuffered); } \
  NS_IMETHOD Load(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Load(); } \
  NS_IMETHOD CanPlayType(const nsAString & type, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPlayType(type, _retval); } \
  NS_IMETHOD GetReadyState(uint16_t *aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetSeeking(bool *aSeeking) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSeeking(aSeeking); } \
  NS_IMETHOD GetCurrentTime(double *aCurrentTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentTime(aCurrentTime); } \
  NS_IMETHOD SetCurrentTime(double aCurrentTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCurrentTime(aCurrentTime); } \
  NS_IMETHOD GetDuration(double *aDuration) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDuration(aDuration); } \
  NS_IMETHOD GetPaused(bool *aPaused) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPaused(aPaused); } \
  NS_IMETHOD GetDefaultPlaybackRate(double *aDefaultPlaybackRate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultPlaybackRate(aDefaultPlaybackRate); } \
  NS_IMETHOD SetDefaultPlaybackRate(double aDefaultPlaybackRate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultPlaybackRate(aDefaultPlaybackRate); } \
  NS_IMETHOD GetPlaybackRate(double *aPlaybackRate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlaybackRate(aPlaybackRate); } \
  NS_IMETHOD SetPlaybackRate(double aPlaybackRate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPlaybackRate(aPlaybackRate); } \
  NS_IMETHOD GetMozPreservesPitch(bool *aMozPreservesPitch) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozPreservesPitch(aMozPreservesPitch); } \
  NS_IMETHOD SetMozPreservesPitch(bool aMozPreservesPitch) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozPreservesPitch(aMozPreservesPitch); } \
  NS_IMETHOD GetPlayed(nsIDOMTimeRanges * *aPlayed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlayed(aPlayed); } \
  NS_IMETHOD GetSeekable(nsIDOMTimeRanges * *aSeekable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSeekable(aSeekable); } \
  NS_IMETHOD GetEnded(bool *aEnded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEnded(aEnded); } \
  NS_IMETHOD GetMozAutoplayEnabled(bool *aMozAutoplayEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozAutoplayEnabled(aMozAutoplayEnabled); } \
  NS_IMETHOD GetAutoplay(bool *aAutoplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoplay(aAutoplay); } \
  NS_IMETHOD SetAutoplay(bool aAutoplay) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutoplay(aAutoplay); } \
  NS_IMETHOD GetLoop(bool *aLoop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoop(aLoop); } \
  NS_IMETHOD SetLoop(bool aLoop) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoop(aLoop); } \
  NS_IMETHOD Play(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Play(); } \
  NS_IMETHOD Pause(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Pause(); } \
  NS_IMETHOD GetControls(bool *aControls) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetControls(aControls); } \
  NS_IMETHOD SetControls(bool aControls) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetControls(aControls); } \
  NS_IMETHOD GetVolume(double *aVolume) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVolume(aVolume); } \
  NS_IMETHOD SetVolume(double aVolume) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVolume(aVolume); } \
  NS_IMETHOD GetMuted(bool *aMuted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMuted(aMuted); } \
  NS_IMETHOD SetMuted(bool aMuted) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMuted(aMuted); } \
  NS_IMETHOD GetDefaultMuted(bool *aDefaultMuted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultMuted(aDefaultMuted); } \
  NS_IMETHOD SetDefaultMuted(bool aDefaultMuted) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDefaultMuted(aDefaultMuted); } \
  NS_IMETHOD MozCaptureStream(nsIDOMMediaStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozCaptureStream(_retval); } \
  NS_IMETHOD MozCaptureStreamUntilEnded(nsIDOMMediaStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozCaptureStreamUntilEnded(_retval); } \
  NS_IMETHOD GetMozAudioCaptured(bool *aMozAudioCaptured) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozAudioCaptured(aMozAudioCaptured); } \
  NS_IMETHOD GetMozChannels(uint32_t *aMozChannels) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozChannels(aMozChannels); } \
  NS_IMETHOD GetMozSampleRate(uint32_t *aMozSampleRate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozSampleRate(aMozSampleRate); } \
  NS_IMETHOD GetMozFrameBufferLength(uint32_t *aMozFrameBufferLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFrameBufferLength(aMozFrameBufferLength); } \
  NS_IMETHOD SetMozFrameBufferLength(uint32_t aMozFrameBufferLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozFrameBufferLength(aMozFrameBufferLength); } \
  NS_IMETHOD MozGetMetadata(JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozGetMetadata(cx, _retval); } \
  NS_IMETHOD GetMozFragmentEnd(double *aMozFragmentEnd) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFragmentEnd(aMozFragmentEnd); } \
  NS_IMETHOD GetMozAudioChannelType(nsAString & aMozAudioChannelType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozAudioChannelType(aMozAudioChannelType); } \
  NS_IMETHOD SetMozAudioChannelType(const nsAString & aMozAudioChannelType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMozAudioChannelType(aMozAudioChannelType); } 

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
NS_IMETHODIMP nsDOMHTMLMediaElement::GetError(nsIDOMMediaError * *aError)
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

/* attribute nsIDOMMediaStream mozSrcObject; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozSrcObject(nsIDOMMediaStream * *aMozSrcObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetMozSrcObject(nsIDOMMediaStream *aMozSrcObject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString currentSrc; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetCurrentSrc(nsAString & aCurrentSrc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString crossOrigin; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetCrossOrigin(nsAString & aCrossOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetCrossOrigin(const nsAString & aCrossOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short networkState; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetNetworkState(uint16_t *aNetworkState)
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
NS_IMETHODIMP nsDOMHTMLMediaElement::GetBuffered(nsIDOMTimeRanges * *aBuffered)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void load (); */
NS_IMETHODIMP nsDOMHTMLMediaElement::Load()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString canPlayType (in DOMString type); */
NS_IMETHODIMP nsDOMHTMLMediaElement::CanPlayType(const nsAString & type, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short readyState; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetReadyState(uint16_t *aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean seeking; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetSeeking(bool *aSeeking)
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
NS_IMETHODIMP nsDOMHTMLMediaElement::GetPaused(bool *aPaused)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double defaultPlaybackRate; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetDefaultPlaybackRate(double *aDefaultPlaybackRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetDefaultPlaybackRate(double aDefaultPlaybackRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute double playbackRate; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetPlaybackRate(double *aPlaybackRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetPlaybackRate(double aPlaybackRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean mozPreservesPitch; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozPreservesPitch(bool *aMozPreservesPitch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetMozPreservesPitch(bool aMozPreservesPitch)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMTimeRanges played; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetPlayed(nsIDOMTimeRanges * *aPlayed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMTimeRanges seekable; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetSeekable(nsIDOMTimeRanges * *aSeekable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean ended; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetEnded(bool *aEnded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozAutoplayEnabled; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozAutoplayEnabled(bool *aMozAutoplayEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean autoplay; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetAutoplay(bool *aAutoplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetAutoplay(bool aAutoplay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean loop; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetLoop(bool *aLoop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetLoop(bool aLoop)
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
NS_IMETHODIMP nsDOMHTMLMediaElement::GetControls(bool *aControls)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetControls(bool aControls)
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
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMuted(bool *aMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetMuted(bool aMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean defaultMuted; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetDefaultMuted(bool *aDefaultMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetDefaultMuted(bool aDefaultMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMediaStream mozCaptureStream (); */
NS_IMETHODIMP nsDOMHTMLMediaElement::MozCaptureStream(nsIDOMMediaStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMediaStream mozCaptureStreamUntilEnded (); */
NS_IMETHODIMP nsDOMHTMLMediaElement::MozCaptureStreamUntilEnded(nsIDOMMediaStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mozAudioCaptured; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozAudioCaptured(bool *aMozAudioCaptured)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozChannels; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozChannels(uint32_t *aMozChannels)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long mozSampleRate; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozSampleRate(uint32_t *aMozSampleRate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long mozFrameBufferLength; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozFrameBufferLength(uint32_t *aMozFrameBufferLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetMozFrameBufferLength(uint32_t aMozFrameBufferLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval mozGetMetadata (); */
NS_IMETHODIMP nsDOMHTMLMediaElement::MozGetMetadata(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double mozFragmentEnd; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozFragmentEnd(double *aMozFragmentEnd)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString mozAudioChannelType; */
NS_IMETHODIMP nsDOMHTMLMediaElement::GetMozAudioChannelType(nsAString & aMozAudioChannelType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLMediaElement::SetMozAudioChannelType(const nsAString & aMozAudioChannelType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLMediaElement_h__ */
