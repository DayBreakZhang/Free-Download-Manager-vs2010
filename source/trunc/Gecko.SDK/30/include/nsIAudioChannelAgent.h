/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAudioChannelAgent.idl
 */

#ifndef __gen_nsIAudioChannelAgent_h__
#define __gen_nsIAudioChannelAgent_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIAudioChannelAgentCallback */
#define NS_IAUDIOCHANNELAGENTCALLBACK_IID_STR "194b55d9-39c0-45c6-b8ef-b8049f978ea5"

#define NS_IAUDIOCHANNELAGENTCALLBACK_IID \
  {0x194b55d9, 0x39c0, 0x45c6, \
    { 0xb8, 0xef, 0xb8, 0x04, 0x9f, 0x97, 0x8e, 0xa5 }}

class NS_NO_VTABLE nsIAudioChannelAgentCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUDIOCHANNELAGENTCALLBACK_IID)

  /* void canPlayChanged (in long canPlay); */
  NS_IMETHOD CanPlayChanged(int32_t canPlay) = 0;

  /* void windowVolumeChanged (); */
  NS_IMETHOD WindowVolumeChanged(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAudioChannelAgentCallback, NS_IAUDIOCHANNELAGENTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUDIOCHANNELAGENTCALLBACK \
  NS_IMETHOD CanPlayChanged(int32_t canPlay); \
  NS_IMETHOD WindowVolumeChanged(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUDIOCHANNELAGENTCALLBACK(_to) \
  NS_IMETHOD CanPlayChanged(int32_t canPlay) { return _to CanPlayChanged(canPlay); } \
  NS_IMETHOD WindowVolumeChanged(void) { return _to WindowVolumeChanged(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUDIOCHANNELAGENTCALLBACK(_to) \
  NS_IMETHOD CanPlayChanged(int32_t canPlay) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPlayChanged(canPlay); } \
  NS_IMETHOD WindowVolumeChanged(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->WindowVolumeChanged(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAudioChannelAgentCallback : public nsIAudioChannelAgentCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUDIOCHANNELAGENTCALLBACK

  nsAudioChannelAgentCallback();

private:
  ~nsAudioChannelAgentCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAudioChannelAgentCallback, nsIAudioChannelAgentCallback)

nsAudioChannelAgentCallback::nsAudioChannelAgentCallback()
{
  /* member initializers and constructor code */
}

nsAudioChannelAgentCallback::~nsAudioChannelAgentCallback()
{
  /* destructor code */
}

/* void canPlayChanged (in long canPlay); */
NS_IMETHODIMP nsAudioChannelAgentCallback::CanPlayChanged(int32_t canPlay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void windowVolumeChanged (); */
NS_IMETHODIMP nsAudioChannelAgentCallback::WindowVolumeChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAudioChannelAgent */
#define NS_IAUDIOCHANNELAGENT_IID_STR "2b0222a5-8f7b-49d2-9ab8-cd01b744b23e"

#define NS_IAUDIOCHANNELAGENT_IID \
  {0x2b0222a5, 0x8f7b, 0x49d2, \
    { 0x9a, 0xb8, 0xcd, 0x01, 0xb7, 0x44, 0xb2, 0x3e }}

class NS_NO_VTABLE nsIAudioChannelAgent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUDIOCHANNELAGENT_IID)

  enum {
    AUDIO_AGENT_CHANNEL_NORMAL = 0,
    AUDIO_AGENT_CHANNEL_CONTENT = 1,
    AUDIO_AGENT_CHANNEL_NOTIFICATION = 2,
    AUDIO_AGENT_CHANNEL_ALARM = 3,
    AUDIO_AGENT_CHANNEL_TELEPHONY = 4,
    AUDIO_AGENT_CHANNEL_RINGER = 5,
    AUDIO_AGENT_CHANNEL_PUBLICNOTIFICATION = 6,
    AUDIO_AGENT_CHANNEL_ERROR = 1000,
    AUDIO_AGENT_STATE_NORMAL = 0,
    AUDIO_AGENT_STATE_MUTED = 1,
    AUDIO_AGENT_STATE_FADED = 2
  };

  /* readonly attribute long audioChannelType; */
  NS_IMETHOD GetAudioChannelType(int32_t *aAudioChannelType) = 0;

  /* void init (in nsIDOMWindow window, in long channelType, in nsIAudioChannelAgentCallback callback); */
  NS_IMETHOD Init(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback) = 0;

  /* void initWithWeakCallback (in nsIDOMWindow window, in long channelType, in nsIAudioChannelAgentCallback callback); */
  NS_IMETHOD InitWithWeakCallback(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback) = 0;

  /* void initWithVideo (in nsIDOMWindow window, in long channelType, in nsIAudioChannelAgentCallback callback, in boolean weak); */
  NS_IMETHOD InitWithVideo(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback, bool weak) = 0;

  /* long startPlaying (); */
  NS_IMETHOD StartPlaying(int32_t *_retval) = 0;

  /* void stopPlaying (); */
  NS_IMETHOD StopPlaying(void) = 0;

  /* void setVisibilityState (in boolean visible); */
  NS_IMETHOD SetVisibilityState(bool visible) = 0;

  /* readonly attribute float windowVolume; */
  NS_IMETHOD GetWindowVolume(float *aWindowVolume) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAudioChannelAgent, NS_IAUDIOCHANNELAGENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUDIOCHANNELAGENT \
  NS_IMETHOD GetAudioChannelType(int32_t *aAudioChannelType); \
  NS_IMETHOD Init(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback); \
  NS_IMETHOD InitWithWeakCallback(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback); \
  NS_IMETHOD InitWithVideo(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback, bool weak); \
  NS_IMETHOD StartPlaying(int32_t *_retval); \
  NS_IMETHOD StopPlaying(void); \
  NS_IMETHOD SetVisibilityState(bool visible); \
  NS_IMETHOD GetWindowVolume(float *aWindowVolume); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUDIOCHANNELAGENT(_to) \
  NS_IMETHOD GetAudioChannelType(int32_t *aAudioChannelType) { return _to GetAudioChannelType(aAudioChannelType); } \
  NS_IMETHOD Init(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback) { return _to Init(window, channelType, callback); } \
  NS_IMETHOD InitWithWeakCallback(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback) { return _to InitWithWeakCallback(window, channelType, callback); } \
  NS_IMETHOD InitWithVideo(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback, bool weak) { return _to InitWithVideo(window, channelType, callback, weak); } \
  NS_IMETHOD StartPlaying(int32_t *_retval) { return _to StartPlaying(_retval); } \
  NS_IMETHOD StopPlaying(void) { return _to StopPlaying(); } \
  NS_IMETHOD SetVisibilityState(bool visible) { return _to SetVisibilityState(visible); } \
  NS_IMETHOD GetWindowVolume(float *aWindowVolume) { return _to GetWindowVolume(aWindowVolume); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUDIOCHANNELAGENT(_to) \
  NS_IMETHOD GetAudioChannelType(int32_t *aAudioChannelType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAudioChannelType(aAudioChannelType); } \
  NS_IMETHOD Init(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(window, channelType, callback); } \
  NS_IMETHOD InitWithWeakCallback(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithWeakCallback(window, channelType, callback); } \
  NS_IMETHOD InitWithVideo(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback, bool weak) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithVideo(window, channelType, callback, weak); } \
  NS_IMETHOD StartPlaying(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartPlaying(_retval); } \
  NS_IMETHOD StopPlaying(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopPlaying(); } \
  NS_IMETHOD SetVisibilityState(bool visible) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVisibilityState(visible); } \
  NS_IMETHOD GetWindowVolume(float *aWindowVolume) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowVolume(aWindowVolume); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAudioChannelAgent : public nsIAudioChannelAgent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUDIOCHANNELAGENT

  nsAudioChannelAgent();

private:
  ~nsAudioChannelAgent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAudioChannelAgent, nsIAudioChannelAgent)

nsAudioChannelAgent::nsAudioChannelAgent()
{
  /* member initializers and constructor code */
}

nsAudioChannelAgent::~nsAudioChannelAgent()
{
  /* destructor code */
}

/* readonly attribute long audioChannelType; */
NS_IMETHODIMP nsAudioChannelAgent::GetAudioChannelType(int32_t *aAudioChannelType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in nsIDOMWindow window, in long channelType, in nsIAudioChannelAgentCallback callback); */
NS_IMETHODIMP nsAudioChannelAgent::Init(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithWeakCallback (in nsIDOMWindow window, in long channelType, in nsIAudioChannelAgentCallback callback); */
NS_IMETHODIMP nsAudioChannelAgent::InitWithWeakCallback(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initWithVideo (in nsIDOMWindow window, in long channelType, in nsIAudioChannelAgentCallback callback, in boolean weak); */
NS_IMETHODIMP nsAudioChannelAgent::InitWithVideo(nsIDOMWindow *window, int32_t channelType, nsIAudioChannelAgentCallback *callback, bool weak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long startPlaying (); */
NS_IMETHODIMP nsAudioChannelAgent::StartPlaying(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopPlaying (); */
NS_IMETHODIMP nsAudioChannelAgent::StopPlaying()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setVisibilityState (in boolean visible); */
NS_IMETHODIMP nsAudioChannelAgent::SetVisibilityState(bool visible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float windowVolume; */
NS_IMETHODIMP nsAudioChannelAgent::GetWindowVolume(float *aWindowVolume)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAudioChannelAgent_h__ */
