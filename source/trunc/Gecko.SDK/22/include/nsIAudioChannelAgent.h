/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/audiochannel/nsIAudioChannelAgent.idl
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

/* starting interface:    nsIAudioChannelAgentCallback */
#define NS_IAUDIOCHANNELAGENTCALLBACK_IID_STR "c7227506-5f8e-11e2-8bb3-10bf48d64bd4"

#define NS_IAUDIOCHANNELAGENTCALLBACK_IID \
  {0xc7227506, 0x5f8e, 0x11e2, \
    { 0x8b, 0xb3, 0x10, 0xbf, 0x48, 0xd6, 0x4b, 0xd4 }}

class NS_NO_VTABLE nsIAudioChannelAgentCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUDIOCHANNELAGENTCALLBACK_IID)

  /* void canPlayChanged (in boolean canPlay); */
  NS_IMETHOD CanPlayChanged(bool canPlay) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAudioChannelAgentCallback, NS_IAUDIOCHANNELAGENTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUDIOCHANNELAGENTCALLBACK \
  NS_IMETHOD CanPlayChanged(bool canPlay); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUDIOCHANNELAGENTCALLBACK(_to) \
  NS_IMETHOD CanPlayChanged(bool canPlay) { return _to CanPlayChanged(canPlay); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUDIOCHANNELAGENTCALLBACK(_to) \
  NS_IMETHOD CanPlayChanged(bool canPlay) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanPlayChanged(canPlay); } 

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

/* void canPlayChanged (in boolean canPlay); */
NS_IMETHODIMP nsAudioChannelAgentCallback::CanPlayChanged(bool canPlay)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAudioChannelAgent */
#define NS_IAUDIOCHANNELAGENT_IID_STR "4d01d4f0-3d16-11e2-a0db-10bf48d64bd4"

#define NS_IAUDIOCHANNELAGENT_IID \
  {0x4d01d4f0, 0x3d16, 0x11e2, \
    { 0xa0, 0xdb, 0x10, 0xbf, 0x48, 0xd6, 0x4b, 0xd4 }}

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
    AUDIO_AGENT_CHANNEL_ERROR = 1000
  };

  /* readonly attribute long audioChannelType; */
  NS_IMETHOD GetAudioChannelType(int32_t *aAudioChannelType) = 0;

  /* void init (in long channelType, in nsIAudioChannelAgentCallback callback); */
  NS_IMETHOD Init(int32_t channelType, nsIAudioChannelAgentCallback *callback) = 0;

  /* boolean startPlaying (); */
  NS_IMETHOD StartPlaying(bool *_retval) = 0;

  /* void stopPlaying (); */
  NS_IMETHOD StopPlaying(void) = 0;

  /* void setVisibilityState (in boolean visible); */
  NS_IMETHOD SetVisibilityState(bool visible) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAudioChannelAgent, NS_IAUDIOCHANNELAGENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUDIOCHANNELAGENT \
  NS_IMETHOD GetAudioChannelType(int32_t *aAudioChannelType); \
  NS_IMETHOD Init(int32_t channelType, nsIAudioChannelAgentCallback *callback); \
  NS_IMETHOD StartPlaying(bool *_retval); \
  NS_IMETHOD StopPlaying(void); \
  NS_IMETHOD SetVisibilityState(bool visible); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUDIOCHANNELAGENT(_to) \
  NS_IMETHOD GetAudioChannelType(int32_t *aAudioChannelType) { return _to GetAudioChannelType(aAudioChannelType); } \
  NS_IMETHOD Init(int32_t channelType, nsIAudioChannelAgentCallback *callback) { return _to Init(channelType, callback); } \
  NS_IMETHOD StartPlaying(bool *_retval) { return _to StartPlaying(_retval); } \
  NS_IMETHOD StopPlaying(void) { return _to StopPlaying(); } \
  NS_IMETHOD SetVisibilityState(bool visible) { return _to SetVisibilityState(visible); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUDIOCHANNELAGENT(_to) \
  NS_IMETHOD GetAudioChannelType(int32_t *aAudioChannelType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAudioChannelType(aAudioChannelType); } \
  NS_IMETHOD Init(int32_t channelType, nsIAudioChannelAgentCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(channelType, callback); } \
  NS_IMETHOD StartPlaying(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartPlaying(_retval); } \
  NS_IMETHOD StopPlaying(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopPlaying(); } \
  NS_IMETHOD SetVisibilityState(bool visible) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVisibilityState(visible); } 

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

/* void init (in long channelType, in nsIAudioChannelAgentCallback callback); */
NS_IMETHODIMP nsAudioChannelAgent::Init(int32_t channelType, nsIAudioChannelAgentCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean startPlaying (); */
NS_IMETHODIMP nsAudioChannelAgent::StartPlaying(bool *_retval)
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

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAudioChannelAgent_h__ */
