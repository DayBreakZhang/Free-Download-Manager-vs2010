/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/media/nsIDOMRTCPeerConnection.idl
 */

#ifndef __gen_nsIDOMRTCPeerConnection_h__
#define __gen_nsIDOMRTCPeerConnection_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIDOMMediaStream_h__
#include "nsIDOMMediaStream.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDataChannel; /* forward declaration */


/* starting interface:    RTCPeerConnectionCallback */
#define RTCPEERCONNECTIONCALLBACK_IID_STR "eb9c563c-3b09-4565-9317-eca96ae0c538"

#define RTCPEERCONNECTIONCALLBACK_IID \
  {0xeb9c563c, 0x3b09, 0x4565, \
    { 0x93, 0x17, 0xec, 0xa9, 0x6a, 0xe0, 0xc5, 0x38 }}

class NS_NO_VTABLE RTCPeerConnectionCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(RTCPEERCONNECTIONCALLBACK_IID)

  /* void onCallback (in jsval value); */
  NS_IMETHOD OnCallback(const JS::Value & value) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(RTCPeerConnectionCallback, RTCPEERCONNECTIONCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_RTCPEERCONNECTIONCALLBACK \
  NS_IMETHOD OnCallback(const JS::Value & value); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_RTCPEERCONNECTIONCALLBACK(_to) \
  NS_IMETHOD OnCallback(const JS::Value & value) { return _to OnCallback(value); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_RTCPEERCONNECTIONCALLBACK(_to) \
  NS_IMETHOD OnCallback(const JS::Value & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCallback(value); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public RTCPeerConnectionCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_RTCPEERCONNECTIONCALLBACK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, RTCPeerConnectionCallback)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onCallback (in jsval value); */
NS_IMETHODIMP _MYCLASS_::OnCallback(const JS::Value & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    RTCPeerConnectionCallbackVoid */
#define RTCPEERCONNECTIONCALLBACKVOID_IID_STR "55546efd-287b-4460-8283-0592875b890f"

#define RTCPEERCONNECTIONCALLBACKVOID_IID \
  {0x55546efd, 0x287b, 0x4460, \
    { 0x82, 0x83, 0x05, 0x92, 0x87, 0x5b, 0x89, 0x0f }}

class NS_NO_VTABLE RTCPeerConnectionCallbackVoid : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(RTCPEERCONNECTIONCALLBACKVOID_IID)

  /* void onCallback (); */
  NS_IMETHOD OnCallback(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(RTCPeerConnectionCallbackVoid, RTCPEERCONNECTIONCALLBACKVOID_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_RTCPEERCONNECTIONCALLBACKVOID \
  NS_IMETHOD OnCallback(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_RTCPEERCONNECTIONCALLBACKVOID(_to) \
  NS_IMETHOD OnCallback(void) { return _to OnCallback(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_RTCPEERCONNECTIONCALLBACKVOID(_to) \
  NS_IMETHOD OnCallback(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCallback(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public RTCPeerConnectionCallbackVoid
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_RTCPEERCONNECTIONCALLBACKVOID

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, RTCPeerConnectionCallbackVoid)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void onCallback (); */
NS_IMETHODIMP _MYCLASS_::OnCallback()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMRTCSessionDescription */
#define NS_IDOMRTCSESSIONDESCRIPTION_IID_STR "05d7375e-b024-4951-a570-c6642105ad35"

#define NS_IDOMRTCSESSIONDESCRIPTION_IID \
  {0x05d7375e, 0xb024, 0x4951, \
    { 0xa5, 0x70, 0xc6, 0x64, 0x21, 0x05, 0xad, 0x35 }}

class NS_NO_VTABLE nsIDOMRTCSessionDescription : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMRTCSESSIONDESCRIPTION_IID)

  /* attribute DOMString sdp; */
  NS_IMETHOD GetSdp(nsAString & aSdp) = 0;
  NS_IMETHOD SetSdp(const nsAString & aSdp) = 0;

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMRTCSessionDescription, NS_IDOMRTCSESSIONDESCRIPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMRTCSESSIONDESCRIPTION \
  NS_IMETHOD GetSdp(nsAString & aSdp); \
  NS_IMETHOD SetSdp(const nsAString & aSdp); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMRTCSESSIONDESCRIPTION(_to) \
  NS_IMETHOD GetSdp(nsAString & aSdp) { return _to GetSdp(aSdp); } \
  NS_IMETHOD SetSdp(const nsAString & aSdp) { return _to SetSdp(aSdp); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMRTCSESSIONDESCRIPTION(_to) \
  NS_IMETHOD GetSdp(nsAString & aSdp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSdp(aSdp); } \
  NS_IMETHOD SetSdp(const nsAString & aSdp) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSdp(aSdp); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMRTCSessionDescription : public nsIDOMRTCSessionDescription
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMRTCSESSIONDESCRIPTION

  nsDOMRTCSessionDescription();

private:
  ~nsDOMRTCSessionDescription();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMRTCSessionDescription, nsIDOMRTCSessionDescription)

nsDOMRTCSessionDescription::nsDOMRTCSessionDescription()
{
  /* member initializers and constructor code */
}

nsDOMRTCSessionDescription::~nsDOMRTCSessionDescription()
{
  /* destructor code */
}

/* attribute DOMString sdp; */
NS_IMETHODIMP nsDOMRTCSessionDescription::GetSdp(nsAString & aSdp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCSessionDescription::SetSdp(const nsAString & aSdp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMRTCSessionDescription::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCSessionDescription::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMRTCIceCandidate */
#define NS_IDOMRTCICECANDIDATE_IID_STR "df176474-e20a-4f42-a85b-b0414d634cf0"

#define NS_IDOMRTCICECANDIDATE_IID \
  {0xdf176474, 0xe20a, 0x4f42, \
    { 0xa8, 0x5b, 0xb0, 0x41, 0x4d, 0x63, 0x4c, 0xf0 }}

class NS_NO_VTABLE nsIDOMRTCIceCandidate : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMRTCICECANDIDATE_IID)

  /* attribute DOMString candidate; */
  NS_IMETHOD GetCandidate(nsAString & aCandidate) = 0;
  NS_IMETHOD SetCandidate(const nsAString & aCandidate) = 0;

  /* attribute DOMString sdpMid; */
  NS_IMETHOD GetSdpMid(nsAString & aSdpMid) = 0;
  NS_IMETHOD SetSdpMid(const nsAString & aSdpMid) = 0;

  /* attribute unsigned short sdpMLineIndex; */
  NS_IMETHOD GetSdpMLineIndex(uint16_t *aSdpMLineIndex) = 0;
  NS_IMETHOD SetSdpMLineIndex(uint16_t aSdpMLineIndex) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMRTCIceCandidate, NS_IDOMRTCICECANDIDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMRTCICECANDIDATE \
  NS_IMETHOD GetCandidate(nsAString & aCandidate); \
  NS_IMETHOD SetCandidate(const nsAString & aCandidate); \
  NS_IMETHOD GetSdpMid(nsAString & aSdpMid); \
  NS_IMETHOD SetSdpMid(const nsAString & aSdpMid); \
  NS_IMETHOD GetSdpMLineIndex(uint16_t *aSdpMLineIndex); \
  NS_IMETHOD SetSdpMLineIndex(uint16_t aSdpMLineIndex); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMRTCICECANDIDATE(_to) \
  NS_IMETHOD GetCandidate(nsAString & aCandidate) { return _to GetCandidate(aCandidate); } \
  NS_IMETHOD SetCandidate(const nsAString & aCandidate) { return _to SetCandidate(aCandidate); } \
  NS_IMETHOD GetSdpMid(nsAString & aSdpMid) { return _to GetSdpMid(aSdpMid); } \
  NS_IMETHOD SetSdpMid(const nsAString & aSdpMid) { return _to SetSdpMid(aSdpMid); } \
  NS_IMETHOD GetSdpMLineIndex(uint16_t *aSdpMLineIndex) { return _to GetSdpMLineIndex(aSdpMLineIndex); } \
  NS_IMETHOD SetSdpMLineIndex(uint16_t aSdpMLineIndex) { return _to SetSdpMLineIndex(aSdpMLineIndex); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMRTCICECANDIDATE(_to) \
  NS_IMETHOD GetCandidate(nsAString & aCandidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCandidate(aCandidate); } \
  NS_IMETHOD SetCandidate(const nsAString & aCandidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCandidate(aCandidate); } \
  NS_IMETHOD GetSdpMid(nsAString & aSdpMid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSdpMid(aSdpMid); } \
  NS_IMETHOD SetSdpMid(const nsAString & aSdpMid) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSdpMid(aSdpMid); } \
  NS_IMETHOD GetSdpMLineIndex(uint16_t *aSdpMLineIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSdpMLineIndex(aSdpMLineIndex); } \
  NS_IMETHOD SetSdpMLineIndex(uint16_t aSdpMLineIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSdpMLineIndex(aSdpMLineIndex); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMRTCIceCandidate : public nsIDOMRTCIceCandidate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMRTCICECANDIDATE

  nsDOMRTCIceCandidate();

private:
  ~nsDOMRTCIceCandidate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMRTCIceCandidate, nsIDOMRTCIceCandidate)

nsDOMRTCIceCandidate::nsDOMRTCIceCandidate()
{
  /* member initializers and constructor code */
}

nsDOMRTCIceCandidate::~nsDOMRTCIceCandidate()
{
  /* destructor code */
}

/* attribute DOMString candidate; */
NS_IMETHODIMP nsDOMRTCIceCandidate::GetCandidate(nsAString & aCandidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCIceCandidate::SetCandidate(const nsAString & aCandidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString sdpMid; */
NS_IMETHODIMP nsDOMRTCIceCandidate::GetSdpMid(nsAString & aSdpMid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCIceCandidate::SetSdpMid(const nsAString & aSdpMid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned short sdpMLineIndex; */
NS_IMETHODIMP nsDOMRTCIceCandidate::GetSdpMLineIndex(uint16_t *aSdpMLineIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCIceCandidate::SetSdpMLineIndex(uint16_t aSdpMLineIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMRTCPeerConnection */
#define NS_IDOMRTCPEERCONNECTION_IID_STR "474074ab-11f9-4933-a200-8ea1a5f84e4c"

#define NS_IDOMRTCPEERCONNECTION_IID \
  {0x474074ab, 0x11f9, 0x4933, \
    { 0xa2, 0x00, 0x8e, 0xa1, 0xa5, 0xf8, 0x4e, 0x4c }}

class NS_NO_VTABLE nsIDOMRTCPeerConnection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMRTCPEERCONNECTION_IID)

  /* void createOffer (in RTCPeerConnectionCallback successCallback, [optional] in RTCPeerConnectionCallback failureCallback, [optional] in jsval constraints); */
  NS_IMETHOD CreateOffer(RTCPeerConnectionCallback *successCallback, RTCPeerConnectionCallback *failureCallback, const JS::Value & constraints) = 0;

  /* void createAnswer (in RTCPeerConnectionCallback successCallback, [optional] in RTCPeerConnectionCallback failureCallback, [optional] in jsval constraints, [optional] in bool createProvisionalAnswer); */
  NS_IMETHOD CreateAnswer(RTCPeerConnectionCallback *successCallback, RTCPeerConnectionCallback *failureCallback, const JS::Value & constraints, bool createProvisionalAnswer) = 0;

  /* void setLocalDescription (in nsIDOMRTCSessionDescription desc, [optional] in RTCPeerConnectionCallbackVoid successCallback, [optional] in RTCPeerConnectionCallback failureCallback); */
  NS_IMETHOD SetLocalDescription(nsIDOMRTCSessionDescription *desc, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback) = 0;

  /* void setRemoteDescription (in nsIDOMRTCSessionDescription desc, [optional] in RTCPeerConnectionCallbackVoid successCallback, [optional] in RTCPeerConnectionCallback failureCallback); */
  NS_IMETHOD SetRemoteDescription(nsIDOMRTCSessionDescription *desc, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback) = 0;

  /* void updateIce ([optional] in jsval configuration, [optional] in jsval constraints, [optional] in bool restart); */
  NS_IMETHOD UpdateIce(const JS::Value & configuration, const JS::Value & constraints, bool restart) = 0;

  /* void addIceCandidate (in nsIDOMRTCIceCandidate candidate, [optional] in RTCPeerConnectionCallbackVoid successCallback, [optional] in RTCPeerConnectionCallback failureCallback); */
  NS_IMETHOD AddIceCandidate(nsIDOMRTCIceCandidate *candidate, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback) = 0;

  /* void addStream (in nsIDOMMediaStream stream, [optional] in jsval constraints); */
  NS_IMETHOD AddStream(nsIDOMMediaStream *stream, const JS::Value & constraints) = 0;

  /* void removeStream (in nsIDOMMediaStream stream); */
  NS_IMETHOD RemoveStream(nsIDOMMediaStream *stream) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* readonly attribute DOMString iceState; */
  NS_IMETHOD GetIceState(nsAString & aIceState) = 0;

  /* readonly attribute DOMString iceGatheringState; */
  NS_IMETHOD GetIceGatheringState(nsAString & aIceGatheringState) = 0;

  /* readonly attribute DOMString readyState; */
  NS_IMETHOD GetReadyState(nsAString & aReadyState) = 0;

  /* readonly attribute jsval localDescription; */
  NS_IMETHOD GetLocalDescription(JS::Value *aLocalDescription) = 0;

  /* readonly attribute jsval remoteDescription; */
  NS_IMETHOD GetRemoteDescription(JS::Value *aRemoteDescription) = 0;

  /* readonly attribute jsval localStreams; */
  NS_IMETHOD GetLocalStreams(JS::Value *aLocalStreams) = 0;

  /* readonly attribute jsval remoteStreams; */
  NS_IMETHOD GetRemoteStreams(JS::Value *aRemoteStreams) = 0;

  /* attribute RTCPeerConnectionCallback onaddstream; */
  NS_IMETHOD GetOnaddstream(RTCPeerConnectionCallback * *aOnaddstream) = 0;
  NS_IMETHOD SetOnaddstream(RTCPeerConnectionCallback *aOnaddstream) = 0;

  /* attribute RTCPeerConnectionCallback onopen; */
  NS_IMETHOD GetOnopen(RTCPeerConnectionCallback * *aOnopen) = 0;
  NS_IMETHOD SetOnopen(RTCPeerConnectionCallback *aOnopen) = 0;

  /* attribute RTCPeerConnectionCallback onremovestream; */
  NS_IMETHOD GetOnremovestream(RTCPeerConnectionCallback * *aOnremovestream) = 0;
  NS_IMETHOD SetOnremovestream(RTCPeerConnectionCallback *aOnremovestream) = 0;

  /* attribute RTCPeerConnectionCallback onicecandidate; */
  NS_IMETHOD GetOnicecandidate(RTCPeerConnectionCallback * *aOnicecandidate) = 0;
  NS_IMETHOD SetOnicecandidate(RTCPeerConnectionCallback *aOnicecandidate) = 0;

  /* attribute RTCPeerConnectionCallback onstatechange; */
  NS_IMETHOD GetOnstatechange(RTCPeerConnectionCallback * *aOnstatechange) = 0;
  NS_IMETHOD SetOnstatechange(RTCPeerConnectionCallback *aOnstatechange) = 0;

  /* attribute RTCPeerConnectionCallback ongatheringchange; */
  NS_IMETHOD GetOngatheringchange(RTCPeerConnectionCallback * *aOngatheringchange) = 0;
  NS_IMETHOD SetOngatheringchange(RTCPeerConnectionCallback *aOngatheringchange) = 0;

  /* attribute RTCPeerConnectionCallback onicechange; */
  NS_IMETHOD GetOnicechange(RTCPeerConnectionCallback * *aOnicechange) = 0;
  NS_IMETHOD SetOnicechange(RTCPeerConnectionCallback *aOnicechange) = 0;

  /* nsIDOMDataChannel createDataChannel ([optional] in ACString label, [optional] in jsval options); */
  NS_IMETHOD CreateDataChannel(const nsACString & label, const JS::Value & options, nsIDOMDataChannel * *_retval) = 0;

  /* void connectDataConnection (in unsigned short localport, in unsigned short remoteport, [optional] in unsigned short numstreams); */
  NS_IMETHOD ConnectDataConnection(uint16_t localport, uint16_t remoteport, uint16_t numstreams) = 0;

  /* attribute RTCPeerConnectionCallback ondatachannel; */
  NS_IMETHOD GetOndatachannel(RTCPeerConnectionCallback * *aOndatachannel) = 0;
  NS_IMETHOD SetOndatachannel(RTCPeerConnectionCallback *aOndatachannel) = 0;

  /* attribute RTCPeerConnectionCallbackVoid onconnection; */
  NS_IMETHOD GetOnconnection(RTCPeerConnectionCallbackVoid * *aOnconnection) = 0;
  NS_IMETHOD SetOnconnection(RTCPeerConnectionCallbackVoid *aOnconnection) = 0;

  /* attribute RTCPeerConnectionCallbackVoid onclosedconnection; */
  NS_IMETHOD GetOnclosedconnection(RTCPeerConnectionCallbackVoid * *aOnclosedconnection) = 0;
  NS_IMETHOD SetOnclosedconnection(RTCPeerConnectionCallbackVoid *aOnclosedconnection) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMRTCPeerConnection, NS_IDOMRTCPEERCONNECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMRTCPEERCONNECTION \
  NS_IMETHOD CreateOffer(RTCPeerConnectionCallback *successCallback, RTCPeerConnectionCallback *failureCallback, const JS::Value & constraints); \
  NS_IMETHOD CreateAnswer(RTCPeerConnectionCallback *successCallback, RTCPeerConnectionCallback *failureCallback, const JS::Value & constraints, bool createProvisionalAnswer); \
  NS_IMETHOD SetLocalDescription(nsIDOMRTCSessionDescription *desc, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback); \
  NS_IMETHOD SetRemoteDescription(nsIDOMRTCSessionDescription *desc, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback); \
  NS_IMETHOD UpdateIce(const JS::Value & configuration, const JS::Value & constraints, bool restart); \
  NS_IMETHOD AddIceCandidate(nsIDOMRTCIceCandidate *candidate, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback); \
  NS_IMETHOD AddStream(nsIDOMMediaStream *stream, const JS::Value & constraints); \
  NS_IMETHOD RemoveStream(nsIDOMMediaStream *stream); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD GetIceState(nsAString & aIceState); \
  NS_IMETHOD GetIceGatheringState(nsAString & aIceGatheringState); \
  NS_IMETHOD GetReadyState(nsAString & aReadyState); \
  NS_IMETHOD GetLocalDescription(JS::Value *aLocalDescription); \
  NS_IMETHOD GetRemoteDescription(JS::Value *aRemoteDescription); \
  NS_IMETHOD GetLocalStreams(JS::Value *aLocalStreams); \
  NS_IMETHOD GetRemoteStreams(JS::Value *aRemoteStreams); \
  NS_IMETHOD GetOnaddstream(RTCPeerConnectionCallback * *aOnaddstream); \
  NS_IMETHOD SetOnaddstream(RTCPeerConnectionCallback *aOnaddstream); \
  NS_IMETHOD GetOnopen(RTCPeerConnectionCallback * *aOnopen); \
  NS_IMETHOD SetOnopen(RTCPeerConnectionCallback *aOnopen); \
  NS_IMETHOD GetOnremovestream(RTCPeerConnectionCallback * *aOnremovestream); \
  NS_IMETHOD SetOnremovestream(RTCPeerConnectionCallback *aOnremovestream); \
  NS_IMETHOD GetOnicecandidate(RTCPeerConnectionCallback * *aOnicecandidate); \
  NS_IMETHOD SetOnicecandidate(RTCPeerConnectionCallback *aOnicecandidate); \
  NS_IMETHOD GetOnstatechange(RTCPeerConnectionCallback * *aOnstatechange); \
  NS_IMETHOD SetOnstatechange(RTCPeerConnectionCallback *aOnstatechange); \
  NS_IMETHOD GetOngatheringchange(RTCPeerConnectionCallback * *aOngatheringchange); \
  NS_IMETHOD SetOngatheringchange(RTCPeerConnectionCallback *aOngatheringchange); \
  NS_IMETHOD GetOnicechange(RTCPeerConnectionCallback * *aOnicechange); \
  NS_IMETHOD SetOnicechange(RTCPeerConnectionCallback *aOnicechange); \
  NS_IMETHOD CreateDataChannel(const nsACString & label, const JS::Value & options, nsIDOMDataChannel * *_retval); \
  NS_IMETHOD ConnectDataConnection(uint16_t localport, uint16_t remoteport, uint16_t numstreams); \
  NS_IMETHOD GetOndatachannel(RTCPeerConnectionCallback * *aOndatachannel); \
  NS_IMETHOD SetOndatachannel(RTCPeerConnectionCallback *aOndatachannel); \
  NS_IMETHOD GetOnconnection(RTCPeerConnectionCallbackVoid * *aOnconnection); \
  NS_IMETHOD SetOnconnection(RTCPeerConnectionCallbackVoid *aOnconnection); \
  NS_IMETHOD GetOnclosedconnection(RTCPeerConnectionCallbackVoid * *aOnclosedconnection); \
  NS_IMETHOD SetOnclosedconnection(RTCPeerConnectionCallbackVoid *aOnclosedconnection); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMRTCPEERCONNECTION(_to) \
  NS_IMETHOD CreateOffer(RTCPeerConnectionCallback *successCallback, RTCPeerConnectionCallback *failureCallback, const JS::Value & constraints) { return _to CreateOffer(successCallback, failureCallback, constraints); } \
  NS_IMETHOD CreateAnswer(RTCPeerConnectionCallback *successCallback, RTCPeerConnectionCallback *failureCallback, const JS::Value & constraints, bool createProvisionalAnswer) { return _to CreateAnswer(successCallback, failureCallback, constraints, createProvisionalAnswer); } \
  NS_IMETHOD SetLocalDescription(nsIDOMRTCSessionDescription *desc, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback) { return _to SetLocalDescription(desc, successCallback, failureCallback); } \
  NS_IMETHOD SetRemoteDescription(nsIDOMRTCSessionDescription *desc, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback) { return _to SetRemoteDescription(desc, successCallback, failureCallback); } \
  NS_IMETHOD UpdateIce(const JS::Value & configuration, const JS::Value & constraints, bool restart) { return _to UpdateIce(configuration, constraints, restart); } \
  NS_IMETHOD AddIceCandidate(nsIDOMRTCIceCandidate *candidate, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback) { return _to AddIceCandidate(candidate, successCallback, failureCallback); } \
  NS_IMETHOD AddStream(nsIDOMMediaStream *stream, const JS::Value & constraints) { return _to AddStream(stream, constraints); } \
  NS_IMETHOD RemoveStream(nsIDOMMediaStream *stream) { return _to RemoveStream(stream); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD GetIceState(nsAString & aIceState) { return _to GetIceState(aIceState); } \
  NS_IMETHOD GetIceGatheringState(nsAString & aIceGatheringState) { return _to GetIceGatheringState(aIceGatheringState); } \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetLocalDescription(JS::Value *aLocalDescription) { return _to GetLocalDescription(aLocalDescription); } \
  NS_IMETHOD GetRemoteDescription(JS::Value *aRemoteDescription) { return _to GetRemoteDescription(aRemoteDescription); } \
  NS_IMETHOD GetLocalStreams(JS::Value *aLocalStreams) { return _to GetLocalStreams(aLocalStreams); } \
  NS_IMETHOD GetRemoteStreams(JS::Value *aRemoteStreams) { return _to GetRemoteStreams(aRemoteStreams); } \
  NS_IMETHOD GetOnaddstream(RTCPeerConnectionCallback * *aOnaddstream) { return _to GetOnaddstream(aOnaddstream); } \
  NS_IMETHOD SetOnaddstream(RTCPeerConnectionCallback *aOnaddstream) { return _to SetOnaddstream(aOnaddstream); } \
  NS_IMETHOD GetOnopen(RTCPeerConnectionCallback * *aOnopen) { return _to GetOnopen(aOnopen); } \
  NS_IMETHOD SetOnopen(RTCPeerConnectionCallback *aOnopen) { return _to SetOnopen(aOnopen); } \
  NS_IMETHOD GetOnremovestream(RTCPeerConnectionCallback * *aOnremovestream) { return _to GetOnremovestream(aOnremovestream); } \
  NS_IMETHOD SetOnremovestream(RTCPeerConnectionCallback *aOnremovestream) { return _to SetOnremovestream(aOnremovestream); } \
  NS_IMETHOD GetOnicecandidate(RTCPeerConnectionCallback * *aOnicecandidate) { return _to GetOnicecandidate(aOnicecandidate); } \
  NS_IMETHOD SetOnicecandidate(RTCPeerConnectionCallback *aOnicecandidate) { return _to SetOnicecandidate(aOnicecandidate); } \
  NS_IMETHOD GetOnstatechange(RTCPeerConnectionCallback * *aOnstatechange) { return _to GetOnstatechange(aOnstatechange); } \
  NS_IMETHOD SetOnstatechange(RTCPeerConnectionCallback *aOnstatechange) { return _to SetOnstatechange(aOnstatechange); } \
  NS_IMETHOD GetOngatheringchange(RTCPeerConnectionCallback * *aOngatheringchange) { return _to GetOngatheringchange(aOngatheringchange); } \
  NS_IMETHOD SetOngatheringchange(RTCPeerConnectionCallback *aOngatheringchange) { return _to SetOngatheringchange(aOngatheringchange); } \
  NS_IMETHOD GetOnicechange(RTCPeerConnectionCallback * *aOnicechange) { return _to GetOnicechange(aOnicechange); } \
  NS_IMETHOD SetOnicechange(RTCPeerConnectionCallback *aOnicechange) { return _to SetOnicechange(aOnicechange); } \
  NS_IMETHOD CreateDataChannel(const nsACString & label, const JS::Value & options, nsIDOMDataChannel * *_retval) { return _to CreateDataChannel(label, options, _retval); } \
  NS_IMETHOD ConnectDataConnection(uint16_t localport, uint16_t remoteport, uint16_t numstreams) { return _to ConnectDataConnection(localport, remoteport, numstreams); } \
  NS_IMETHOD GetOndatachannel(RTCPeerConnectionCallback * *aOndatachannel) { return _to GetOndatachannel(aOndatachannel); } \
  NS_IMETHOD SetOndatachannel(RTCPeerConnectionCallback *aOndatachannel) { return _to SetOndatachannel(aOndatachannel); } \
  NS_IMETHOD GetOnconnection(RTCPeerConnectionCallbackVoid * *aOnconnection) { return _to GetOnconnection(aOnconnection); } \
  NS_IMETHOD SetOnconnection(RTCPeerConnectionCallbackVoid *aOnconnection) { return _to SetOnconnection(aOnconnection); } \
  NS_IMETHOD GetOnclosedconnection(RTCPeerConnectionCallbackVoid * *aOnclosedconnection) { return _to GetOnclosedconnection(aOnclosedconnection); } \
  NS_IMETHOD SetOnclosedconnection(RTCPeerConnectionCallbackVoid *aOnclosedconnection) { return _to SetOnclosedconnection(aOnclosedconnection); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMRTCPEERCONNECTION(_to) \
  NS_IMETHOD CreateOffer(RTCPeerConnectionCallback *successCallback, RTCPeerConnectionCallback *failureCallback, const JS::Value & constraints) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateOffer(successCallback, failureCallback, constraints); } \
  NS_IMETHOD CreateAnswer(RTCPeerConnectionCallback *successCallback, RTCPeerConnectionCallback *failureCallback, const JS::Value & constraints, bool createProvisionalAnswer) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateAnswer(successCallback, failureCallback, constraints, createProvisionalAnswer); } \
  NS_IMETHOD SetLocalDescription(nsIDOMRTCSessionDescription *desc, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLocalDescription(desc, successCallback, failureCallback); } \
  NS_IMETHOD SetRemoteDescription(nsIDOMRTCSessionDescription *desc, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRemoteDescription(desc, successCallback, failureCallback); } \
  NS_IMETHOD UpdateIce(const JS::Value & configuration, const JS::Value & constraints, bool restart) { return !_to ? NS_ERROR_NULL_POINTER : _to->UpdateIce(configuration, constraints, restart); } \
  NS_IMETHOD AddIceCandidate(nsIDOMRTCIceCandidate *candidate, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddIceCandidate(candidate, successCallback, failureCallback); } \
  NS_IMETHOD AddStream(nsIDOMMediaStream *stream, const JS::Value & constraints) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddStream(stream, constraints); } \
  NS_IMETHOD RemoveStream(nsIDOMMediaStream *stream) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveStream(stream); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD GetIceState(nsAString & aIceState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIceState(aIceState); } \
  NS_IMETHOD GetIceGatheringState(nsAString & aIceGatheringState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIceGatheringState(aIceGatheringState); } \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetLocalDescription(JS::Value *aLocalDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalDescription(aLocalDescription); } \
  NS_IMETHOD GetRemoteDescription(JS::Value *aRemoteDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemoteDescription(aRemoteDescription); } \
  NS_IMETHOD GetLocalStreams(JS::Value *aLocalStreams) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalStreams(aLocalStreams); } \
  NS_IMETHOD GetRemoteStreams(JS::Value *aRemoteStreams) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemoteStreams(aRemoteStreams); } \
  NS_IMETHOD GetOnaddstream(RTCPeerConnectionCallback * *aOnaddstream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnaddstream(aOnaddstream); } \
  NS_IMETHOD SetOnaddstream(RTCPeerConnectionCallback *aOnaddstream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnaddstream(aOnaddstream); } \
  NS_IMETHOD GetOnopen(RTCPeerConnectionCallback * *aOnopen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnopen(aOnopen); } \
  NS_IMETHOD SetOnopen(RTCPeerConnectionCallback *aOnopen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnopen(aOnopen); } \
  NS_IMETHOD GetOnremovestream(RTCPeerConnectionCallback * *aOnremovestream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnremovestream(aOnremovestream); } \
  NS_IMETHOD SetOnremovestream(RTCPeerConnectionCallback *aOnremovestream) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnremovestream(aOnremovestream); } \
  NS_IMETHOD GetOnicecandidate(RTCPeerConnectionCallback * *aOnicecandidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnicecandidate(aOnicecandidate); } \
  NS_IMETHOD SetOnicecandidate(RTCPeerConnectionCallback *aOnicecandidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnicecandidate(aOnicecandidate); } \
  NS_IMETHOD GetOnstatechange(RTCPeerConnectionCallback * *aOnstatechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnstatechange(aOnstatechange); } \
  NS_IMETHOD SetOnstatechange(RTCPeerConnectionCallback *aOnstatechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnstatechange(aOnstatechange); } \
  NS_IMETHOD GetOngatheringchange(RTCPeerConnectionCallback * *aOngatheringchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOngatheringchange(aOngatheringchange); } \
  NS_IMETHOD SetOngatheringchange(RTCPeerConnectionCallback *aOngatheringchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOngatheringchange(aOngatheringchange); } \
  NS_IMETHOD GetOnicechange(RTCPeerConnectionCallback * *aOnicechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnicechange(aOnicechange); } \
  NS_IMETHOD SetOnicechange(RTCPeerConnectionCallback *aOnicechange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnicechange(aOnicechange); } \
  NS_IMETHOD CreateDataChannel(const nsACString & label, const JS::Value & options, nsIDOMDataChannel * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateDataChannel(label, options, _retval); } \
  NS_IMETHOD ConnectDataConnection(uint16_t localport, uint16_t remoteport, uint16_t numstreams) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConnectDataConnection(localport, remoteport, numstreams); } \
  NS_IMETHOD GetOndatachannel(RTCPeerConnectionCallback * *aOndatachannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndatachannel(aOndatachannel); } \
  NS_IMETHOD SetOndatachannel(RTCPeerConnectionCallback *aOndatachannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndatachannel(aOndatachannel); } \
  NS_IMETHOD GetOnconnection(RTCPeerConnectionCallbackVoid * *aOnconnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnconnection(aOnconnection); } \
  NS_IMETHOD SetOnconnection(RTCPeerConnectionCallbackVoid *aOnconnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnconnection(aOnconnection); } \
  NS_IMETHOD GetOnclosedconnection(RTCPeerConnectionCallbackVoid * *aOnclosedconnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnclosedconnection(aOnclosedconnection); } \
  NS_IMETHOD SetOnclosedconnection(RTCPeerConnectionCallbackVoid *aOnclosedconnection) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnclosedconnection(aOnclosedconnection); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMRTCPeerConnection : public nsIDOMRTCPeerConnection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMRTCPEERCONNECTION

  nsDOMRTCPeerConnection();

private:
  ~nsDOMRTCPeerConnection();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMRTCPeerConnection, nsIDOMRTCPeerConnection)

nsDOMRTCPeerConnection::nsDOMRTCPeerConnection()
{
  /* member initializers and constructor code */
}

nsDOMRTCPeerConnection::~nsDOMRTCPeerConnection()
{
  /* destructor code */
}

/* void createOffer (in RTCPeerConnectionCallback successCallback, [optional] in RTCPeerConnectionCallback failureCallback, [optional] in jsval constraints); */
NS_IMETHODIMP nsDOMRTCPeerConnection::CreateOffer(RTCPeerConnectionCallback *successCallback, RTCPeerConnectionCallback *failureCallback, const JS::Value & constraints)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createAnswer (in RTCPeerConnectionCallback successCallback, [optional] in RTCPeerConnectionCallback failureCallback, [optional] in jsval constraints, [optional] in bool createProvisionalAnswer); */
NS_IMETHODIMP nsDOMRTCPeerConnection::CreateAnswer(RTCPeerConnectionCallback *successCallback, RTCPeerConnectionCallback *failureCallback, const JS::Value & constraints, bool createProvisionalAnswer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setLocalDescription (in nsIDOMRTCSessionDescription desc, [optional] in RTCPeerConnectionCallbackVoid successCallback, [optional] in RTCPeerConnectionCallback failureCallback); */
NS_IMETHODIMP nsDOMRTCPeerConnection::SetLocalDescription(nsIDOMRTCSessionDescription *desc, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setRemoteDescription (in nsIDOMRTCSessionDescription desc, [optional] in RTCPeerConnectionCallbackVoid successCallback, [optional] in RTCPeerConnectionCallback failureCallback); */
NS_IMETHODIMP nsDOMRTCPeerConnection::SetRemoteDescription(nsIDOMRTCSessionDescription *desc, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void updateIce ([optional] in jsval configuration, [optional] in jsval constraints, [optional] in bool restart); */
NS_IMETHODIMP nsDOMRTCPeerConnection::UpdateIce(const JS::Value & configuration, const JS::Value & constraints, bool restart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addIceCandidate (in nsIDOMRTCIceCandidate candidate, [optional] in RTCPeerConnectionCallbackVoid successCallback, [optional] in RTCPeerConnectionCallback failureCallback); */
NS_IMETHODIMP nsDOMRTCPeerConnection::AddIceCandidate(nsIDOMRTCIceCandidate *candidate, RTCPeerConnectionCallbackVoid *successCallback, RTCPeerConnectionCallback *failureCallback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addStream (in nsIDOMMediaStream stream, [optional] in jsval constraints); */
NS_IMETHODIMP nsDOMRTCPeerConnection::AddStream(nsIDOMMediaStream *stream, const JS::Value & constraints)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeStream (in nsIDOMMediaStream stream); */
NS_IMETHODIMP nsDOMRTCPeerConnection::RemoveStream(nsIDOMMediaStream *stream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsDOMRTCPeerConnection::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString iceState; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetIceState(nsAString & aIceState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString iceGatheringState; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetIceGatheringState(nsAString & aIceGatheringState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString readyState; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetReadyState(nsAString & aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval localDescription; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetLocalDescription(JS::Value *aLocalDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval remoteDescription; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetRemoteDescription(JS::Value *aRemoteDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval localStreams; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetLocalStreams(JS::Value *aLocalStreams)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval remoteStreams; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetRemoteStreams(JS::Value *aRemoteStreams)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute RTCPeerConnectionCallback onaddstream; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetOnaddstream(RTCPeerConnectionCallback * *aOnaddstream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCPeerConnection::SetOnaddstream(RTCPeerConnectionCallback *aOnaddstream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute RTCPeerConnectionCallback onopen; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetOnopen(RTCPeerConnectionCallback * *aOnopen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCPeerConnection::SetOnopen(RTCPeerConnectionCallback *aOnopen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute RTCPeerConnectionCallback onremovestream; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetOnremovestream(RTCPeerConnectionCallback * *aOnremovestream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCPeerConnection::SetOnremovestream(RTCPeerConnectionCallback *aOnremovestream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute RTCPeerConnectionCallback onicecandidate; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetOnicecandidate(RTCPeerConnectionCallback * *aOnicecandidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCPeerConnection::SetOnicecandidate(RTCPeerConnectionCallback *aOnicecandidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute RTCPeerConnectionCallback onstatechange; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetOnstatechange(RTCPeerConnectionCallback * *aOnstatechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCPeerConnection::SetOnstatechange(RTCPeerConnectionCallback *aOnstatechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute RTCPeerConnectionCallback ongatheringchange; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetOngatheringchange(RTCPeerConnectionCallback * *aOngatheringchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCPeerConnection::SetOngatheringchange(RTCPeerConnectionCallback *aOngatheringchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute RTCPeerConnectionCallback onicechange; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetOnicechange(RTCPeerConnectionCallback * *aOnicechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCPeerConnection::SetOnicechange(RTCPeerConnectionCallback *aOnicechange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDataChannel createDataChannel ([optional] in ACString label, [optional] in jsval options); */
NS_IMETHODIMP nsDOMRTCPeerConnection::CreateDataChannel(const nsACString & label, const JS::Value & options, nsIDOMDataChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void connectDataConnection (in unsigned short localport, in unsigned short remoteport, [optional] in unsigned short numstreams); */
NS_IMETHODIMP nsDOMRTCPeerConnection::ConnectDataConnection(uint16_t localport, uint16_t remoteport, uint16_t numstreams)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute RTCPeerConnectionCallback ondatachannel; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetOndatachannel(RTCPeerConnectionCallback * *aOndatachannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCPeerConnection::SetOndatachannel(RTCPeerConnectionCallback *aOndatachannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute RTCPeerConnectionCallbackVoid onconnection; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetOnconnection(RTCPeerConnectionCallbackVoid * *aOnconnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCPeerConnection::SetOnconnection(RTCPeerConnectionCallbackVoid *aOnconnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute RTCPeerConnectionCallbackVoid onclosedconnection; */
NS_IMETHODIMP nsDOMRTCPeerConnection::GetOnclosedconnection(RTCPeerConnectionCallbackVoid * *aOnclosedconnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMRTCPeerConnection::SetOnclosedconnection(RTCPeerConnectionCallbackVoid *aOnclosedconnection)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMRTCPeerConnection_h__ */
