/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITelephonyProvider.idl
 */

#ifndef __gen_nsITelephonyProvider_h__
#define __gen_nsITelephonyProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITelephonyListener */
#define NS_ITELEPHONYLISTENER_IID_STR "c25d3993-6481-4e12-acee-55e32f6e1454"

#define NS_ITELEPHONYLISTENER_IID \
  {0xc25d3993, 0x6481, 0x4e12, \
    { 0xac, 0xee, 0x55, 0xe3, 0x2f, 0x6e, 0x14, 0x54 }}

class NS_NO_VTABLE nsITelephonyListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITELEPHONYLISTENER_IID)

  /* void callStateChanged (in unsigned long clientId, in unsigned long callIndex, in unsigned short callState, in AString number, in boolean isActive, in boolean isOutgoing, in boolean isEmergency, in boolean isConference, in boolean isSwitchable, in boolean isMergeable); */
  NS_IMETHOD CallStateChanged(uint32_t clientId, uint32_t callIndex, uint16_t callState, const nsAString & number, bool isActive, bool isOutgoing, bool isEmergency, bool isConference, bool isSwitchable, bool isMergeable) = 0;

  /* void conferenceCallStateChanged (in unsigned short callState); */
  NS_IMETHOD ConferenceCallStateChanged(uint16_t callState) = 0;

  /* void enumerateCallStateComplete (); */
  NS_IMETHOD EnumerateCallStateComplete(void) = 0;

  /* void enumerateCallState (in unsigned long clientId, in unsigned long callIndex, in unsigned short callState, in AString number, in boolean isActive, in boolean isOutgoing, in boolean isEmergency, in boolean isConference, in boolean isSwitchable, in boolean isMergeable); */
  NS_IMETHOD EnumerateCallState(uint32_t clientId, uint32_t callIndex, uint16_t callState, const nsAString & number, bool isActive, bool isOutgoing, bool isEmergency, bool isConference, bool isSwitchable, bool isMergeable) = 0;

  /* void supplementaryServiceNotification (in unsigned long clientId, in long callIndex, in unsigned short notification); */
  NS_IMETHOD SupplementaryServiceNotification(uint32_t clientId, int32_t callIndex, uint16_t notification) = 0;

  /* void notifyError (in unsigned long clientId, in long callIndex, in AString error); */
  NS_IMETHOD NotifyError(uint32_t clientId, int32_t callIndex, const nsAString & error) = 0;

  /* void notifyCdmaCallWaiting (in unsigned long clientId, in AString number); */
  NS_IMETHOD NotifyCdmaCallWaiting(uint32_t clientId, const nsAString & number) = 0;

  /* void notifyConferenceError (in AString name, in AString message); */
  NS_IMETHOD NotifyConferenceError(const nsAString & name, const nsAString & message) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelephonyListener, NS_ITELEPHONYLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEPHONYLISTENER \
  NS_IMETHOD CallStateChanged(uint32_t clientId, uint32_t callIndex, uint16_t callState, const nsAString & number, bool isActive, bool isOutgoing, bool isEmergency, bool isConference, bool isSwitchable, bool isMergeable); \
  NS_IMETHOD ConferenceCallStateChanged(uint16_t callState); \
  NS_IMETHOD EnumerateCallStateComplete(void); \
  NS_IMETHOD EnumerateCallState(uint32_t clientId, uint32_t callIndex, uint16_t callState, const nsAString & number, bool isActive, bool isOutgoing, bool isEmergency, bool isConference, bool isSwitchable, bool isMergeable); \
  NS_IMETHOD SupplementaryServiceNotification(uint32_t clientId, int32_t callIndex, uint16_t notification); \
  NS_IMETHOD NotifyError(uint32_t clientId, int32_t callIndex, const nsAString & error); \
  NS_IMETHOD NotifyCdmaCallWaiting(uint32_t clientId, const nsAString & number); \
  NS_IMETHOD NotifyConferenceError(const nsAString & name, const nsAString & message); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEPHONYLISTENER(_to) \
  NS_IMETHOD CallStateChanged(uint32_t clientId, uint32_t callIndex, uint16_t callState, const nsAString & number, bool isActive, bool isOutgoing, bool isEmergency, bool isConference, bool isSwitchable, bool isMergeable) { return _to CallStateChanged(clientId, callIndex, callState, number, isActive, isOutgoing, isEmergency, isConference, isSwitchable, isMergeable); } \
  NS_IMETHOD ConferenceCallStateChanged(uint16_t callState) { return _to ConferenceCallStateChanged(callState); } \
  NS_IMETHOD EnumerateCallStateComplete(void) { return _to EnumerateCallStateComplete(); } \
  NS_IMETHOD EnumerateCallState(uint32_t clientId, uint32_t callIndex, uint16_t callState, const nsAString & number, bool isActive, bool isOutgoing, bool isEmergency, bool isConference, bool isSwitchable, bool isMergeable) { return _to EnumerateCallState(clientId, callIndex, callState, number, isActive, isOutgoing, isEmergency, isConference, isSwitchable, isMergeable); } \
  NS_IMETHOD SupplementaryServiceNotification(uint32_t clientId, int32_t callIndex, uint16_t notification) { return _to SupplementaryServiceNotification(clientId, callIndex, notification); } \
  NS_IMETHOD NotifyError(uint32_t clientId, int32_t callIndex, const nsAString & error) { return _to NotifyError(clientId, callIndex, error); } \
  NS_IMETHOD NotifyCdmaCallWaiting(uint32_t clientId, const nsAString & number) { return _to NotifyCdmaCallWaiting(clientId, number); } \
  NS_IMETHOD NotifyConferenceError(const nsAString & name, const nsAString & message) { return _to NotifyConferenceError(name, message); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEPHONYLISTENER(_to) \
  NS_IMETHOD CallStateChanged(uint32_t clientId, uint32_t callIndex, uint16_t callState, const nsAString & number, bool isActive, bool isOutgoing, bool isEmergency, bool isConference, bool isSwitchable, bool isMergeable) { return !_to ? NS_ERROR_NULL_POINTER : _to->CallStateChanged(clientId, callIndex, callState, number, isActive, isOutgoing, isEmergency, isConference, isSwitchable, isMergeable); } \
  NS_IMETHOD ConferenceCallStateChanged(uint16_t callState) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConferenceCallStateChanged(callState); } \
  NS_IMETHOD EnumerateCallStateComplete(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateCallStateComplete(); } \
  NS_IMETHOD EnumerateCallState(uint32_t clientId, uint32_t callIndex, uint16_t callState, const nsAString & number, bool isActive, bool isOutgoing, bool isEmergency, bool isConference, bool isSwitchable, bool isMergeable) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateCallState(clientId, callIndex, callState, number, isActive, isOutgoing, isEmergency, isConference, isSwitchable, isMergeable); } \
  NS_IMETHOD SupplementaryServiceNotification(uint32_t clientId, int32_t callIndex, uint16_t notification) { return !_to ? NS_ERROR_NULL_POINTER : _to->SupplementaryServiceNotification(clientId, callIndex, notification); } \
  NS_IMETHOD NotifyError(uint32_t clientId, int32_t callIndex, const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyError(clientId, callIndex, error); } \
  NS_IMETHOD NotifyCdmaCallWaiting(uint32_t clientId, const nsAString & number) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyCdmaCallWaiting(clientId, number); } \
  NS_IMETHOD NotifyConferenceError(const nsAString & name, const nsAString & message) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyConferenceError(name, message); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTelephonyListener : public nsITelephonyListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITELEPHONYLISTENER

  nsTelephonyListener();

private:
  ~nsTelephonyListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTelephonyListener, nsITelephonyListener)

nsTelephonyListener::nsTelephonyListener()
{
  /* member initializers and constructor code */
}

nsTelephonyListener::~nsTelephonyListener()
{
  /* destructor code */
}

/* void callStateChanged (in unsigned long clientId, in unsigned long callIndex, in unsigned short callState, in AString number, in boolean isActive, in boolean isOutgoing, in boolean isEmergency, in boolean isConference, in boolean isSwitchable, in boolean isMergeable); */
NS_IMETHODIMP nsTelephonyListener::CallStateChanged(uint32_t clientId, uint32_t callIndex, uint16_t callState, const nsAString & number, bool isActive, bool isOutgoing, bool isEmergency, bool isConference, bool isSwitchable, bool isMergeable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void conferenceCallStateChanged (in unsigned short callState); */
NS_IMETHODIMP nsTelephonyListener::ConferenceCallStateChanged(uint16_t callState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enumerateCallStateComplete (); */
NS_IMETHODIMP nsTelephonyListener::EnumerateCallStateComplete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enumerateCallState (in unsigned long clientId, in unsigned long callIndex, in unsigned short callState, in AString number, in boolean isActive, in boolean isOutgoing, in boolean isEmergency, in boolean isConference, in boolean isSwitchable, in boolean isMergeable); */
NS_IMETHODIMP nsTelephonyListener::EnumerateCallState(uint32_t clientId, uint32_t callIndex, uint16_t callState, const nsAString & number, bool isActive, bool isOutgoing, bool isEmergency, bool isConference, bool isSwitchable, bool isMergeable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void supplementaryServiceNotification (in unsigned long clientId, in long callIndex, in unsigned short notification); */
NS_IMETHODIMP nsTelephonyListener::SupplementaryServiceNotification(uint32_t clientId, int32_t callIndex, uint16_t notification)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyError (in unsigned long clientId, in long callIndex, in AString error); */
NS_IMETHODIMP nsTelephonyListener::NotifyError(uint32_t clientId, int32_t callIndex, const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyCdmaCallWaiting (in unsigned long clientId, in AString number); */
NS_IMETHODIMP nsTelephonyListener::NotifyCdmaCallWaiting(uint32_t clientId, const nsAString & number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyConferenceError (in AString name, in AString message); */
NS_IMETHODIMP nsTelephonyListener::NotifyConferenceError(const nsAString & name, const nsAString & message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITelephonyCallback */
#define NS_ITELEPHONYCALLBACK_IID_STR "c095aa82-aacb-4e53-a787-56a89c3f638e"

#define NS_ITELEPHONYCALLBACK_IID \
  {0xc095aa82, 0xaacb, 0x4e53, \
    { 0xa7, 0x87, 0x56, 0xa8, 0x9c, 0x3f, 0x63, 0x8e }}

class NS_NO_VTABLE nsITelephonyCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITELEPHONYCALLBACK_IID)

  /* void notifyDialError (in AString error); */
  NS_IMETHOD NotifyDialError(const nsAString & error) = 0;

  /* void notifyDialSuccess (); */
  NS_IMETHOD NotifyDialSuccess(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelephonyCallback, NS_ITELEPHONYCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEPHONYCALLBACK \
  NS_IMETHOD NotifyDialError(const nsAString & error); \
  NS_IMETHOD NotifyDialSuccess(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEPHONYCALLBACK(_to) \
  NS_IMETHOD NotifyDialError(const nsAString & error) { return _to NotifyDialError(error); } \
  NS_IMETHOD NotifyDialSuccess(void) { return _to NotifyDialSuccess(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEPHONYCALLBACK(_to) \
  NS_IMETHOD NotifyDialError(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDialError(error); } \
  NS_IMETHOD NotifyDialSuccess(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDialSuccess(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTelephonyCallback : public nsITelephonyCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITELEPHONYCALLBACK

  nsTelephonyCallback();

private:
  ~nsTelephonyCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTelephonyCallback, nsITelephonyCallback)

nsTelephonyCallback::nsTelephonyCallback()
{
  /* member initializers and constructor code */
}

nsTelephonyCallback::~nsTelephonyCallback()
{
  /* destructor code */
}

/* void notifyDialError (in AString error); */
NS_IMETHODIMP nsTelephonyCallback::NotifyDialError(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDialSuccess (); */
NS_IMETHODIMP nsTelephonyCallback::NotifyDialSuccess()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define TELEPHONY_PROVIDER_CID \
  { 0x9cf8aa52, 0x7c1c, 0x4cde, { 0x97, 0x4e, 0xed, 0x2a, 0xa0, 0xe7, 0x35, 0xfa } }
#define TELEPHONY_PROVIDER_CONTRACTID \
  "@mozilla.org/telephony/telephonyprovider;1"

/* starting interface:    nsITelephonyProvider */
#define NS_ITELEPHONYPROVIDER_IID_STR "b16ca98f-994f-4ae1-8c2d-e7b18e08d1f3"

#define NS_ITELEPHONYPROVIDER_IID \
  {0xb16ca98f, 0x994f, 0x4ae1, \
    { 0x8c, 0x2d, 0xe7, 0xb1, 0x8e, 0x08, 0xd1, 0xf3 }}

class NS_NO_VTABLE nsITelephonyProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITELEPHONYPROVIDER_IID)

  enum {
    CALL_STATE_UNKNOWN = 0U,
    CALL_STATE_DIALING = 1U,
    CALL_STATE_ALERTING = 2U,
    CALL_STATE_CONNECTING = 3U,
    CALL_STATE_CONNECTED = 4U,
    CALL_STATE_HOLDING = 5U,
    CALL_STATE_HELD = 6U,
    CALL_STATE_RESUMING = 7U,
    CALL_STATE_DISCONNECTING = 8U,
    CALL_STATE_DISCONNECTED = 9U,
    CALL_STATE_INCOMING = 10U,
    NOTIFICATION_REMOTE_HELD = 0U,
    NOTIFICATION_REMOTE_RESUMED = 1U
  };

  /* readonly attribute unsigned long defaultServiceId; */
  NS_IMETHOD GetDefaultServiceId(uint32_t *aDefaultServiceId) = 0;

  /* void registerListener (in nsITelephonyListener listener); */
  NS_IMETHOD RegisterListener(nsITelephonyListener *listener) = 0;

  /* void unregisterListener (in nsITelephonyListener listener); */
  NS_IMETHOD UnregisterListener(nsITelephonyListener *listener) = 0;

  /* void enumerateCalls (in nsITelephonyListener listener); */
  NS_IMETHOD EnumerateCalls(nsITelephonyListener *listener) = 0;

  /* void dial (in unsigned long clientId, in DOMString number, in boolean isEmergency, in nsITelephonyCallback callback); */
  NS_IMETHOD Dial(uint32_t clientId, const nsAString & number, bool isEmergency, nsITelephonyCallback *callback) = 0;

  /* void hangUp (in unsigned long clientId, in unsigned long callIndex); */
  NS_IMETHOD HangUp(uint32_t clientId, uint32_t callIndex) = 0;

  /* void startTone (in unsigned long clientId, in DOMString dtmfChar); */
  NS_IMETHOD StartTone(uint32_t clientId, const nsAString & dtmfChar) = 0;

  /* void stopTone (in unsigned long clientId); */
  NS_IMETHOD StopTone(uint32_t clientId) = 0;

  /* void answerCall (in unsigned long clientId, in unsigned long callIndex); */
  NS_IMETHOD AnswerCall(uint32_t clientId, uint32_t callIndex) = 0;

  /* void rejectCall (in unsigned long clientId, in unsigned long callIndex); */
  NS_IMETHOD RejectCall(uint32_t clientId, uint32_t callIndex) = 0;

  /* void holdCall (in unsigned long clientId, in unsigned long callIndex); */
  NS_IMETHOD HoldCall(uint32_t clientId, uint32_t callIndex) = 0;

  /* void resumeCall (in unsigned long clientId, in unsigned long callIndex); */
  NS_IMETHOD ResumeCall(uint32_t clientId, uint32_t callIndex) = 0;

  /* void conferenceCall (in unsigned long clientId); */
  NS_IMETHOD ConferenceCall(uint32_t clientId) = 0;

  /* void separateCall (in unsigned long clientId, in unsigned long callIndex); */
  NS_IMETHOD SeparateCall(uint32_t clientId, uint32_t callIndex) = 0;

  /* void holdConference (in unsigned long clientId); */
  NS_IMETHOD HoldConference(uint32_t clientId) = 0;

  /* void resumeConference (in unsigned long clientId); */
  NS_IMETHOD ResumeConference(uint32_t clientId) = 0;

  /* attribute bool microphoneMuted; */
  NS_IMETHOD GetMicrophoneMuted(bool *aMicrophoneMuted) = 0;
  NS_IMETHOD SetMicrophoneMuted(bool aMicrophoneMuted) = 0;

  /* attribute bool speakerEnabled; */
  NS_IMETHOD GetSpeakerEnabled(bool *aSpeakerEnabled) = 0;
  NS_IMETHOD SetSpeakerEnabled(bool aSpeakerEnabled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITelephonyProvider, NS_ITELEPHONYPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITELEPHONYPROVIDER \
  NS_IMETHOD GetDefaultServiceId(uint32_t *aDefaultServiceId); \
  NS_IMETHOD RegisterListener(nsITelephonyListener *listener); \
  NS_IMETHOD UnregisterListener(nsITelephonyListener *listener); \
  NS_IMETHOD EnumerateCalls(nsITelephonyListener *listener); \
  NS_IMETHOD Dial(uint32_t clientId, const nsAString & number, bool isEmergency, nsITelephonyCallback *callback); \
  NS_IMETHOD HangUp(uint32_t clientId, uint32_t callIndex); \
  NS_IMETHOD StartTone(uint32_t clientId, const nsAString & dtmfChar); \
  NS_IMETHOD StopTone(uint32_t clientId); \
  NS_IMETHOD AnswerCall(uint32_t clientId, uint32_t callIndex); \
  NS_IMETHOD RejectCall(uint32_t clientId, uint32_t callIndex); \
  NS_IMETHOD HoldCall(uint32_t clientId, uint32_t callIndex); \
  NS_IMETHOD ResumeCall(uint32_t clientId, uint32_t callIndex); \
  NS_IMETHOD ConferenceCall(uint32_t clientId); \
  NS_IMETHOD SeparateCall(uint32_t clientId, uint32_t callIndex); \
  NS_IMETHOD HoldConference(uint32_t clientId); \
  NS_IMETHOD ResumeConference(uint32_t clientId); \
  NS_IMETHOD GetMicrophoneMuted(bool *aMicrophoneMuted); \
  NS_IMETHOD SetMicrophoneMuted(bool aMicrophoneMuted); \
  NS_IMETHOD GetSpeakerEnabled(bool *aSpeakerEnabled); \
  NS_IMETHOD SetSpeakerEnabled(bool aSpeakerEnabled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITELEPHONYPROVIDER(_to) \
  NS_IMETHOD GetDefaultServiceId(uint32_t *aDefaultServiceId) { return _to GetDefaultServiceId(aDefaultServiceId); } \
  NS_IMETHOD RegisterListener(nsITelephonyListener *listener) { return _to RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsITelephonyListener *listener) { return _to UnregisterListener(listener); } \
  NS_IMETHOD EnumerateCalls(nsITelephonyListener *listener) { return _to EnumerateCalls(listener); } \
  NS_IMETHOD Dial(uint32_t clientId, const nsAString & number, bool isEmergency, nsITelephonyCallback *callback) { return _to Dial(clientId, number, isEmergency, callback); } \
  NS_IMETHOD HangUp(uint32_t clientId, uint32_t callIndex) { return _to HangUp(clientId, callIndex); } \
  NS_IMETHOD StartTone(uint32_t clientId, const nsAString & dtmfChar) { return _to StartTone(clientId, dtmfChar); } \
  NS_IMETHOD StopTone(uint32_t clientId) { return _to StopTone(clientId); } \
  NS_IMETHOD AnswerCall(uint32_t clientId, uint32_t callIndex) { return _to AnswerCall(clientId, callIndex); } \
  NS_IMETHOD RejectCall(uint32_t clientId, uint32_t callIndex) { return _to RejectCall(clientId, callIndex); } \
  NS_IMETHOD HoldCall(uint32_t clientId, uint32_t callIndex) { return _to HoldCall(clientId, callIndex); } \
  NS_IMETHOD ResumeCall(uint32_t clientId, uint32_t callIndex) { return _to ResumeCall(clientId, callIndex); } \
  NS_IMETHOD ConferenceCall(uint32_t clientId) { return _to ConferenceCall(clientId); } \
  NS_IMETHOD SeparateCall(uint32_t clientId, uint32_t callIndex) { return _to SeparateCall(clientId, callIndex); } \
  NS_IMETHOD HoldConference(uint32_t clientId) { return _to HoldConference(clientId); } \
  NS_IMETHOD ResumeConference(uint32_t clientId) { return _to ResumeConference(clientId); } \
  NS_IMETHOD GetMicrophoneMuted(bool *aMicrophoneMuted) { return _to GetMicrophoneMuted(aMicrophoneMuted); } \
  NS_IMETHOD SetMicrophoneMuted(bool aMicrophoneMuted) { return _to SetMicrophoneMuted(aMicrophoneMuted); } \
  NS_IMETHOD GetSpeakerEnabled(bool *aSpeakerEnabled) { return _to GetSpeakerEnabled(aSpeakerEnabled); } \
  NS_IMETHOD SetSpeakerEnabled(bool aSpeakerEnabled) { return _to SetSpeakerEnabled(aSpeakerEnabled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITELEPHONYPROVIDER(_to) \
  NS_IMETHOD GetDefaultServiceId(uint32_t *aDefaultServiceId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultServiceId(aDefaultServiceId); } \
  NS_IMETHOD RegisterListener(nsITelephonyListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterListener(listener); } \
  NS_IMETHOD UnregisterListener(nsITelephonyListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterListener(listener); } \
  NS_IMETHOD EnumerateCalls(nsITelephonyListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateCalls(listener); } \
  NS_IMETHOD Dial(uint32_t clientId, const nsAString & number, bool isEmergency, nsITelephonyCallback *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->Dial(clientId, number, isEmergency, callback); } \
  NS_IMETHOD HangUp(uint32_t clientId, uint32_t callIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->HangUp(clientId, callIndex); } \
  NS_IMETHOD StartTone(uint32_t clientId, const nsAString & dtmfChar) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartTone(clientId, dtmfChar); } \
  NS_IMETHOD StopTone(uint32_t clientId) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopTone(clientId); } \
  NS_IMETHOD AnswerCall(uint32_t clientId, uint32_t callIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->AnswerCall(clientId, callIndex); } \
  NS_IMETHOD RejectCall(uint32_t clientId, uint32_t callIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->RejectCall(clientId, callIndex); } \
  NS_IMETHOD HoldCall(uint32_t clientId, uint32_t callIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->HoldCall(clientId, callIndex); } \
  NS_IMETHOD ResumeCall(uint32_t clientId, uint32_t callIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeCall(clientId, callIndex); } \
  NS_IMETHOD ConferenceCall(uint32_t clientId) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConferenceCall(clientId); } \
  NS_IMETHOD SeparateCall(uint32_t clientId, uint32_t callIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SeparateCall(clientId, callIndex); } \
  NS_IMETHOD HoldConference(uint32_t clientId) { return !_to ? NS_ERROR_NULL_POINTER : _to->HoldConference(clientId); } \
  NS_IMETHOD ResumeConference(uint32_t clientId) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResumeConference(clientId); } \
  NS_IMETHOD GetMicrophoneMuted(bool *aMicrophoneMuted) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMicrophoneMuted(aMicrophoneMuted); } \
  NS_IMETHOD SetMicrophoneMuted(bool aMicrophoneMuted) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetMicrophoneMuted(aMicrophoneMuted); } \
  NS_IMETHOD GetSpeakerEnabled(bool *aSpeakerEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpeakerEnabled(aSpeakerEnabled); } \
  NS_IMETHOD SetSpeakerEnabled(bool aSpeakerEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpeakerEnabled(aSpeakerEnabled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTelephonyProvider : public nsITelephonyProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITELEPHONYPROVIDER

  nsTelephonyProvider();

private:
  ~nsTelephonyProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTelephonyProvider, nsITelephonyProvider)

nsTelephonyProvider::nsTelephonyProvider()
{
  /* member initializers and constructor code */
}

nsTelephonyProvider::~nsTelephonyProvider()
{
  /* destructor code */
}

/* readonly attribute unsigned long defaultServiceId; */
NS_IMETHODIMP nsTelephonyProvider::GetDefaultServiceId(uint32_t *aDefaultServiceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerListener (in nsITelephonyListener listener); */
NS_IMETHODIMP nsTelephonyProvider::RegisterListener(nsITelephonyListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterListener (in nsITelephonyListener listener); */
NS_IMETHODIMP nsTelephonyProvider::UnregisterListener(nsITelephonyListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enumerateCalls (in nsITelephonyListener listener); */
NS_IMETHODIMP nsTelephonyProvider::EnumerateCalls(nsITelephonyListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dial (in unsigned long clientId, in DOMString number, in boolean isEmergency, in nsITelephonyCallback callback); */
NS_IMETHODIMP nsTelephonyProvider::Dial(uint32_t clientId, const nsAString & number, bool isEmergency, nsITelephonyCallback *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hangUp (in unsigned long clientId, in unsigned long callIndex); */
NS_IMETHODIMP nsTelephonyProvider::HangUp(uint32_t clientId, uint32_t callIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startTone (in unsigned long clientId, in DOMString dtmfChar); */
NS_IMETHODIMP nsTelephonyProvider::StartTone(uint32_t clientId, const nsAString & dtmfChar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopTone (in unsigned long clientId); */
NS_IMETHODIMP nsTelephonyProvider::StopTone(uint32_t clientId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void answerCall (in unsigned long clientId, in unsigned long callIndex); */
NS_IMETHODIMP nsTelephonyProvider::AnswerCall(uint32_t clientId, uint32_t callIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rejectCall (in unsigned long clientId, in unsigned long callIndex); */
NS_IMETHODIMP nsTelephonyProvider::RejectCall(uint32_t clientId, uint32_t callIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void holdCall (in unsigned long clientId, in unsigned long callIndex); */
NS_IMETHODIMP nsTelephonyProvider::HoldCall(uint32_t clientId, uint32_t callIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeCall (in unsigned long clientId, in unsigned long callIndex); */
NS_IMETHODIMP nsTelephonyProvider::ResumeCall(uint32_t clientId, uint32_t callIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void conferenceCall (in unsigned long clientId); */
NS_IMETHODIMP nsTelephonyProvider::ConferenceCall(uint32_t clientId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void separateCall (in unsigned long clientId, in unsigned long callIndex); */
NS_IMETHODIMP nsTelephonyProvider::SeparateCall(uint32_t clientId, uint32_t callIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void holdConference (in unsigned long clientId); */
NS_IMETHODIMP nsTelephonyProvider::HoldConference(uint32_t clientId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resumeConference (in unsigned long clientId); */
NS_IMETHODIMP nsTelephonyProvider::ResumeConference(uint32_t clientId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute bool microphoneMuted; */
NS_IMETHODIMP nsTelephonyProvider::GetMicrophoneMuted(bool *aMicrophoneMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTelephonyProvider::SetMicrophoneMuted(bool aMicrophoneMuted)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute bool speakerEnabled; */
NS_IMETHODIMP nsTelephonyProvider::GetSpeakerEnabled(bool *aSpeakerEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTelephonyProvider::SetSpeakerEnabled(bool aSpeakerEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITelephonyProvider_h__ */
