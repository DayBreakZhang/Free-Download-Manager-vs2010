/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMessageManager.idl
 */

#ifndef __gen_nsIMessageManager_h__
#define __gen_nsIMessageManager_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDocShell; /* forward declaration */

class nsIContent; /* forward declaration */

class nsIPrincipal; /* forward declaration */


/* starting interface:    nsIMessageListener */
#define NS_IMESSAGELISTENER_IID_STR "2b44eb57-a9c6-4773-9a1e-fe0818739a4c"

#define NS_IMESSAGELISTENER_IID \
  {0x2b44eb57, 0xa9c6, 0x4773, \
    { 0x9a, 0x1e, 0xfe, 0x08, 0x18, 0x73, 0x9a, 0x4c }}

class NS_NO_VTABLE nsIMessageListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMESSAGELISTENER_IID)

  /* void receiveMessage (); */
  NS_IMETHOD ReceiveMessage(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMessageListener, NS_IMESSAGELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMESSAGELISTENER \
  NS_IMETHOD ReceiveMessage(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMESSAGELISTENER(_to) \
  NS_IMETHOD ReceiveMessage(void) { return _to ReceiveMessage(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMESSAGELISTENER(_to) \
  NS_IMETHOD ReceiveMessage(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReceiveMessage(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMessageListener : public nsIMessageListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMESSAGELISTENER

  nsMessageListener();

private:
  ~nsMessageListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMessageListener, nsIMessageListener)

nsMessageListener::nsMessageListener()
{
  /* member initializers and constructor code */
}

nsMessageListener::~nsMessageListener()
{
  /* destructor code */
}

/* void receiveMessage (); */
NS_IMETHODIMP nsMessageListener::ReceiveMessage()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMessageListenerManager */
#define NS_IMESSAGELISTENERMANAGER_IID_STR "aae827bd-acf1-45fe-a556-ea545d4c0804"

#define NS_IMESSAGELISTENERMANAGER_IID \
  {0xaae827bd, 0xacf1, 0x45fe, \
    { 0xa5, 0x56, 0xea, 0x54, 0x5d, 0x4c, 0x08, 0x04 }}

class NS_NO_VTABLE nsIMessageListenerManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMESSAGELISTENERMANAGER_IID)

  /* void addMessageListener (in AString messageName, in nsIMessageListener listener); */
  NS_IMETHOD AddMessageListener(const nsAString & messageName, nsIMessageListener *listener) = 0;

  /* void removeMessageListener (in AString messageName, in nsIMessageListener listener); */
  NS_IMETHOD RemoveMessageListener(const nsAString & messageName, nsIMessageListener *listener) = 0;

  /* void addWeakMessageListener (in AString messageName, in nsIMessageListener listener); */
  NS_IMETHOD AddWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) = 0;

  /* void removeWeakMessageListener (in AString messageName, in nsIMessageListener listener); */
  NS_IMETHOD RemoveWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) = 0;

  /* [notxpcom] boolean markForCC (); */
  NS_IMETHOD_(bool) MarkForCC(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMessageListenerManager, NS_IMESSAGELISTENERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMESSAGELISTENERMANAGER \
  NS_IMETHOD AddMessageListener(const nsAString & messageName, nsIMessageListener *listener); \
  NS_IMETHOD RemoveMessageListener(const nsAString & messageName, nsIMessageListener *listener); \
  NS_IMETHOD AddWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener); \
  NS_IMETHOD RemoveWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener); \
  NS_IMETHOD_(bool) MarkForCC(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMESSAGELISTENERMANAGER(_to) \
  NS_IMETHOD AddMessageListener(const nsAString & messageName, nsIMessageListener *listener) { return _to AddMessageListener(messageName, listener); } \
  NS_IMETHOD RemoveMessageListener(const nsAString & messageName, nsIMessageListener *listener) { return _to RemoveMessageListener(messageName, listener); } \
  NS_IMETHOD AddWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) { return _to AddWeakMessageListener(messageName, listener); } \
  NS_IMETHOD RemoveWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) { return _to RemoveWeakMessageListener(messageName, listener); } \
  NS_IMETHOD_(bool) MarkForCC(void) { return _to MarkForCC(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMESSAGELISTENERMANAGER(_to) \
  NS_IMETHOD AddMessageListener(const nsAString & messageName, nsIMessageListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddMessageListener(messageName, listener); } \
  NS_IMETHOD RemoveMessageListener(const nsAString & messageName, nsIMessageListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveMessageListener(messageName, listener); } \
  NS_IMETHOD AddWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWeakMessageListener(messageName, listener); } \
  NS_IMETHOD RemoveWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWeakMessageListener(messageName, listener); } \
  NS_IMETHOD_(bool) MarkForCC(void); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMessageListenerManager : public nsIMessageListenerManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMESSAGELISTENERMANAGER

  nsMessageListenerManager();

private:
  ~nsMessageListenerManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMessageListenerManager, nsIMessageListenerManager)

nsMessageListenerManager::nsMessageListenerManager()
{
  /* member initializers and constructor code */
}

nsMessageListenerManager::~nsMessageListenerManager()
{
  /* destructor code */
}

/* void addMessageListener (in AString messageName, in nsIMessageListener listener); */
NS_IMETHODIMP nsMessageListenerManager::AddMessageListener(const nsAString & messageName, nsIMessageListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeMessageListener (in AString messageName, in nsIMessageListener listener); */
NS_IMETHODIMP nsMessageListenerManager::RemoveMessageListener(const nsAString & messageName, nsIMessageListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addWeakMessageListener (in AString messageName, in nsIMessageListener listener); */
NS_IMETHODIMP nsMessageListenerManager::AddWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWeakMessageListener (in AString messageName, in nsIMessageListener listener); */
NS_IMETHODIMP nsMessageListenerManager::RemoveWeakMessageListener(const nsAString & messageName, nsIMessageListener *listener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] boolean markForCC (); */
NS_IMETHODIMP_(bool) nsMessageListenerManager::MarkForCC()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMessageSender */
#define NS_IMESSAGESENDER_IID_STR "d6b0d851-43e6-426d-9f13-054bc0198175"

#define NS_IMESSAGESENDER_IID \
  {0xd6b0d851, 0x43e6, 0x426d, \
    { 0x9f, 0x13, 0x05, 0x4b, 0xc0, 0x19, 0x81, 0x75 }}

class NS_NO_VTABLE nsIMessageSender : public nsIMessageListenerManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMESSAGESENDER_IID)

  /* [implicit_jscontext,optional_argc] void sendAsyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
  NS_IMETHOD SendAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMessageSender, NS_IMESSAGESENDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMESSAGESENDER \
  NS_IMETHOD SendAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMESSAGESENDER(_to) \
  NS_IMETHOD SendAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc) { return _to SendAsyncMessage(messageName, obj, objects, principal, cx, _argc); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMESSAGESENDER(_to) \
  NS_IMETHOD SendAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendAsyncMessage(messageName, obj, objects, principal, cx, _argc); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMessageSender : public nsIMessageSender
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMESSAGESENDER

  nsMessageSender();

private:
  ~nsMessageSender();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMessageSender, nsIMessageSender)

nsMessageSender::nsMessageSender()
{
  /* member initializers and constructor code */
}

nsMessageSender::~nsMessageSender()
{
  /* destructor code */
}

/* [implicit_jscontext,optional_argc] void sendAsyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
NS_IMETHODIMP nsMessageSender::SendAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMessageBroadcaster */
#define NS_IMESSAGEBROADCASTER_IID_STR "d36346b9-5d3b-497d-9c28-ffbc3e4f6d0d"

#define NS_IMESSAGEBROADCASTER_IID \
  {0xd36346b9, 0x5d3b, 0x497d, \
    { 0x9c, 0x28, 0xff, 0xbc, 0x3e, 0x4f, 0x6d, 0x0d }}

class NS_NO_VTABLE nsIMessageBroadcaster : public nsIMessageListenerManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMESSAGEBROADCASTER_IID)

  /* [implicit_jscontext,optional_argc] void broadcastAsyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects); */
  NS_IMETHOD BroadcastAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, JSContext* cx, uint8_t _argc) = 0;

  /* readonly attribute unsigned long childCount; */
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) = 0;

  /* nsIMessageListenerManager getChildAt (in unsigned long aIndex); */
  NS_IMETHOD GetChildAt(uint32_t aIndex, nsIMessageListenerManager * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMessageBroadcaster, NS_IMESSAGEBROADCASTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMESSAGEBROADCASTER \
  NS_IMETHOD BroadcastAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, JSContext* cx, uint8_t _argc); \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount); \
  NS_IMETHOD GetChildAt(uint32_t aIndex, nsIMessageListenerManager * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMESSAGEBROADCASTER(_to) \
  NS_IMETHOD BroadcastAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, JSContext* cx, uint8_t _argc) { return _to BroadcastAsyncMessage(messageName, obj, objects, cx, _argc); } \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) { return _to GetChildCount(aChildCount); } \
  NS_IMETHOD GetChildAt(uint32_t aIndex, nsIMessageListenerManager * *_retval) { return _to GetChildAt(aIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMESSAGEBROADCASTER(_to) \
  NS_IMETHOD BroadcastAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, JSContext* cx, uint8_t _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->BroadcastAsyncMessage(messageName, obj, objects, cx, _argc); } \
  NS_IMETHOD GetChildCount(uint32_t *aChildCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildCount(aChildCount); } \
  NS_IMETHOD GetChildAt(uint32_t aIndex, nsIMessageListenerManager * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildAt(aIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMessageBroadcaster : public nsIMessageBroadcaster
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMESSAGEBROADCASTER

  nsMessageBroadcaster();

private:
  ~nsMessageBroadcaster();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMessageBroadcaster, nsIMessageBroadcaster)

nsMessageBroadcaster::nsMessageBroadcaster()
{
  /* member initializers and constructor code */
}

nsMessageBroadcaster::~nsMessageBroadcaster()
{
  /* destructor code */
}

/* [implicit_jscontext,optional_argc] void broadcastAsyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects); */
NS_IMETHODIMP nsMessageBroadcaster::BroadcastAsyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, JSContext* cx, uint8_t _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long childCount; */
NS_IMETHODIMP nsMessageBroadcaster::GetChildCount(uint32_t *aChildCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMessageListenerManager getChildAt (in unsigned long aIndex); */
NS_IMETHODIMP nsMessageBroadcaster::GetChildAt(uint32_t aIndex, nsIMessageListenerManager * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsISyncMessageSender */
#define NS_ISYNCMESSAGESENDER_IID_STR "7fda0941-9dcc-448b-bd39-16373c5b4003"

#define NS_ISYNCMESSAGESENDER_IID \
  {0x7fda0941, 0x9dcc, 0x448b, \
    { 0xbd, 0x39, 0x16, 0x37, 0x3c, 0x5b, 0x40, 0x03 }}

class NS_NO_VTABLE nsISyncMessageSender : public nsIMessageSender {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISYNCMESSAGESENDER_IID)

  /* [implicit_jscontext,optional_argc] jsval sendSyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
  NS_IMETHOD SendSyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext,optional_argc] jsval sendRpcMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
  NS_IMETHOD SendRpcMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISyncMessageSender, NS_ISYNCMESSAGESENDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISYNCMESSAGESENDER \
  NS_IMETHOD SendSyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval); \
  NS_IMETHOD SendRpcMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISYNCMESSAGESENDER(_to) \
  NS_IMETHOD SendSyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) { return _to SendSyncMessage(messageName, obj, objects, principal, cx, _argc, _retval); } \
  NS_IMETHOD SendRpcMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) { return _to SendRpcMessage(messageName, obj, objects, principal, cx, _argc, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISYNCMESSAGESENDER(_to) \
  NS_IMETHOD SendSyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSyncMessage(messageName, obj, objects, principal, cx, _argc, _retval); } \
  NS_IMETHOD SendRpcMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendRpcMessage(messageName, obj, objects, principal, cx, _argc, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSyncMessageSender : public nsISyncMessageSender
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISYNCMESSAGESENDER

  nsSyncMessageSender();

private:
  ~nsSyncMessageSender();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSyncMessageSender, nsISyncMessageSender)

nsSyncMessageSender::nsSyncMessageSender()
{
  /* member initializers and constructor code */
}

nsSyncMessageSender::~nsSyncMessageSender()
{
  /* destructor code */
}

/* [implicit_jscontext,optional_argc] jsval sendSyncMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
NS_IMETHODIMP nsSyncMessageSender::SendSyncMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] jsval sendRpcMessage ([optional] in AString messageName, [optional] in jsval obj, [optional] in jsval objects, [optional] in nsIPrincipal principal); */
NS_IMETHODIMP nsSyncMessageSender::SendRpcMessage(const nsAString & messageName, JS::HandleValue obj, JS::HandleValue objects, nsIPrincipal *principal, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContentFrameMessageManager */
#define NS_ICONTENTFRAMEMESSAGEMANAGER_IID_STR "894ff2d4-39a3-4df8-9d76-8ee329975488"

#define NS_ICONTENTFRAMEMESSAGEMANAGER_IID \
  {0x894ff2d4, 0x39a3, 0x4df8, \
    { 0x9d, 0x76, 0x8e, 0xe3, 0x29, 0x97, 0x54, 0x88 }}

class NS_NO_VTABLE nsIContentFrameMessageManager : public nsISyncMessageSender {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTFRAMEMESSAGEMANAGER_IID)

  /* readonly attribute nsIDOMWindow content; */
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) = 0;

  /* readonly attribute nsIDocShell docShell; */
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) = 0;

  /* void dump (in DOMString aStr); */
  NS_IMETHOD Dump(const nsAString & aStr) = 0;

  /* void privateNoteIntentionalCrash (); */
  NS_IMETHOD PrivateNoteIntentionalCrash(void) = 0;

  /* DOMString atob (in DOMString aAsciiString); */
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) = 0;

  /* DOMString btoa (in DOMString aBase64Data); */
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentFrameMessageManager, NS_ICONTENTFRAMEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTFRAMEMESSAGEMANAGER \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent); \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell); \
  NS_IMETHOD Dump(const nsAString & aStr); \
  NS_IMETHOD PrivateNoteIntentionalCrash(void); \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval); \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) { return _to GetContent(aContent); } \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return _to GetDocShell(aDocShell); } \
  NS_IMETHOD Dump(const nsAString & aStr) { return _to Dump(aStr); } \
  NS_IMETHOD PrivateNoteIntentionalCrash(void) { return _to PrivateNoteIntentionalCrash(); } \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) { return _to Atob(aAsciiString, _retval); } \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) { return _to Btoa(aBase64Data, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_IMETHOD GetContent(nsIDOMWindow * *aContent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContent(aContent); } \
  NS_IMETHOD GetDocShell(nsIDocShell * *aDocShell) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocShell(aDocShell); } \
  NS_IMETHOD Dump(const nsAString & aStr) { return !_to ? NS_ERROR_NULL_POINTER : _to->Dump(aStr); } \
  NS_IMETHOD PrivateNoteIntentionalCrash(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrivateNoteIntentionalCrash(); } \
  NS_IMETHOD Atob(const nsAString & aAsciiString, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Atob(aAsciiString, _retval); } \
  NS_IMETHOD Btoa(const nsAString & aBase64Data, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Btoa(aBase64Data, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentFrameMessageManager : public nsIContentFrameMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTFRAMEMESSAGEMANAGER

  nsContentFrameMessageManager();

private:
  ~nsContentFrameMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentFrameMessageManager, nsIContentFrameMessageManager)

nsContentFrameMessageManager::nsContentFrameMessageManager()
{
  /* member initializers and constructor code */
}

nsContentFrameMessageManager::~nsContentFrameMessageManager()
{
  /* destructor code */
}

/* readonly attribute nsIDOMWindow content; */
NS_IMETHODIMP nsContentFrameMessageManager::GetContent(nsIDOMWindow * *aContent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDocShell docShell; */
NS_IMETHODIMP nsContentFrameMessageManager::GetDocShell(nsIDocShell * *aDocShell)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dump (in DOMString aStr); */
NS_IMETHODIMP nsContentFrameMessageManager::Dump(const nsAString & aStr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void privateNoteIntentionalCrash (); */
NS_IMETHODIMP nsContentFrameMessageManager::PrivateNoteIntentionalCrash()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString atob (in DOMString aAsciiString); */
NS_IMETHODIMP nsContentFrameMessageManager::Atob(const nsAString & aAsciiString, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString btoa (in DOMString aBase64Data); */
NS_IMETHODIMP nsContentFrameMessageManager::Btoa(const nsAString & aBase64Data, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIInProcessContentFrameMessageManager */
#define NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID_STR "a2325927-9c0c-437d-9215-749c79235031"

#define NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID \
  {0xa2325927, 0x9c0c, 0x437d, \
    { 0x92, 0x15, 0x74, 0x9c, 0x79, 0x23, 0x50, 0x31 }}

class NS_NO_VTABLE nsIInProcessContentFrameMessageManager : public nsIContentFrameMessageManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID)

  /* [notxpcom] nsIContent getOwnerContent (); */
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInProcessContentFrameMessageManager, NS_IINPROCESSCONTENTFRAMEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER \
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void) { return _to GetOwnerContent(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER(_to) \
  NS_IMETHOD_(nsIContent *) GetOwnerContent(void); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInProcessContentFrameMessageManager : public nsIInProcessContentFrameMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPROCESSCONTENTFRAMEMESSAGEMANAGER

  nsInProcessContentFrameMessageManager();

private:
  ~nsInProcessContentFrameMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInProcessContentFrameMessageManager, nsIInProcessContentFrameMessageManager)

nsInProcessContentFrameMessageManager::nsInProcessContentFrameMessageManager()
{
  /* member initializers and constructor code */
}

nsInProcessContentFrameMessageManager::~nsInProcessContentFrameMessageManager()
{
  /* destructor code */
}

/* [notxpcom] nsIContent getOwnerContent (); */
NS_IMETHODIMP_(nsIContent *) nsInProcessContentFrameMessageManager::GetOwnerContent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFrameScriptLoader */
#define NS_IFRAMESCRIPTLOADER_IID_STR "6fb78110-45ae-11e3-8f96-0800200c9a66"

#define NS_IFRAMESCRIPTLOADER_IID \
  {0x6fb78110, 0x45ae, 0x11e3, \
    { 0x8f, 0x96, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIFrameScriptLoader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMESCRIPTLOADER_IID)

  /* void loadFrameScript (in AString aURL, in boolean aAllowDelayedLoad, [optional] in boolean aRunInGlobalScope); */
  NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad, bool aRunInGlobalScope) = 0;

  /* void removeDelayedFrameScript (in AString aURL); */
  NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL) = 0;

  /* [implicit_jscontext] jsval getDelayedFrameScripts (); */
  NS_IMETHOD GetDelayedFrameScripts(JSContext* cx, JS::MutableHandleValue _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameScriptLoader, NS_IFRAMESCRIPTLOADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMESCRIPTLOADER \
  NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad, bool aRunInGlobalScope); \
  NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL); \
  NS_IMETHOD GetDelayedFrameScripts(JSContext* cx, JS::MutableHandleValue _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMESCRIPTLOADER(_to) \
  NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad, bool aRunInGlobalScope) { return _to LoadFrameScript(aURL, aAllowDelayedLoad, aRunInGlobalScope); } \
  NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL) { return _to RemoveDelayedFrameScript(aURL); } \
  NS_IMETHOD GetDelayedFrameScripts(JSContext* cx, JS::MutableHandleValue _retval) { return _to GetDelayedFrameScripts(cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMESCRIPTLOADER(_to) \
  NS_IMETHOD LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad, bool aRunInGlobalScope) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadFrameScript(aURL, aAllowDelayedLoad, aRunInGlobalScope); } \
  NS_IMETHOD RemoveDelayedFrameScript(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDelayedFrameScript(aURL); } \
  NS_IMETHOD GetDelayedFrameScripts(JSContext* cx, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelayedFrameScripts(cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameScriptLoader : public nsIFrameScriptLoader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMESCRIPTLOADER

  nsFrameScriptLoader();

private:
  ~nsFrameScriptLoader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFrameScriptLoader, nsIFrameScriptLoader)

nsFrameScriptLoader::nsFrameScriptLoader()
{
  /* member initializers and constructor code */
}

nsFrameScriptLoader::~nsFrameScriptLoader()
{
  /* destructor code */
}

/* void loadFrameScript (in AString aURL, in boolean aAllowDelayedLoad, [optional] in boolean aRunInGlobalScope); */
NS_IMETHODIMP nsFrameScriptLoader::LoadFrameScript(const nsAString & aURL, bool aAllowDelayedLoad, bool aRunInGlobalScope)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDelayedFrameScript (in AString aURL); */
NS_IMETHODIMP nsFrameScriptLoader::RemoveDelayedFrameScript(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] jsval getDelayedFrameScripts (); */
NS_IMETHODIMP nsFrameScriptLoader::GetDelayedFrameScripts(JSContext* cx, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIProcessChecker */
#define NS_IPROCESSCHECKER_IID_STR "ad57800b-ff21-4e2f-91d3-e68615ae8afe"

#define NS_IPROCESSCHECKER_IID \
  {0xad57800b, 0xff21, 0x4e2f, \
    { 0x91, 0xd3, 0xe6, 0x86, 0x15, 0xae, 0x8a, 0xfe }}

class NS_NO_VTABLE nsIProcessChecker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROCESSCHECKER_IID)

  /* boolean assertPermission (in DOMString aPermission); */
  NS_IMETHOD AssertPermission(const nsAString & aPermission, bool *_retval) = 0;

  /* boolean assertContainApp (in DOMString aManifestURL); */
  NS_IMETHOD AssertContainApp(const nsAString & aManifestURL, bool *_retval) = 0;

  /* boolean assertAppHasPermission (in DOMString aPermission); */
  NS_IMETHOD AssertAppHasPermission(const nsAString & aPermission, bool *_retval) = 0;

  /* boolean assertAppHasStatus (in unsigned short aStatus); */
  NS_IMETHOD AssertAppHasStatus(uint16_t aStatus, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProcessChecker, NS_IPROCESSCHECKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROCESSCHECKER \
  NS_IMETHOD AssertPermission(const nsAString & aPermission, bool *_retval); \
  NS_IMETHOD AssertContainApp(const nsAString & aManifestURL, bool *_retval); \
  NS_IMETHOD AssertAppHasPermission(const nsAString & aPermission, bool *_retval); \
  NS_IMETHOD AssertAppHasStatus(uint16_t aStatus, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROCESSCHECKER(_to) \
  NS_IMETHOD AssertPermission(const nsAString & aPermission, bool *_retval) { return _to AssertPermission(aPermission, _retval); } \
  NS_IMETHOD AssertContainApp(const nsAString & aManifestURL, bool *_retval) { return _to AssertContainApp(aManifestURL, _retval); } \
  NS_IMETHOD AssertAppHasPermission(const nsAString & aPermission, bool *_retval) { return _to AssertAppHasPermission(aPermission, _retval); } \
  NS_IMETHOD AssertAppHasStatus(uint16_t aStatus, bool *_retval) { return _to AssertAppHasStatus(aStatus, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROCESSCHECKER(_to) \
  NS_IMETHOD AssertPermission(const nsAString & aPermission, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AssertPermission(aPermission, _retval); } \
  NS_IMETHOD AssertContainApp(const nsAString & aManifestURL, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AssertContainApp(aManifestURL, _retval); } \
  NS_IMETHOD AssertAppHasPermission(const nsAString & aPermission, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AssertAppHasPermission(aPermission, _retval); } \
  NS_IMETHOD AssertAppHasStatus(uint16_t aStatus, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AssertAppHasStatus(aStatus, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProcessChecker : public nsIProcessChecker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROCESSCHECKER

  nsProcessChecker();

private:
  ~nsProcessChecker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProcessChecker, nsIProcessChecker)

nsProcessChecker::nsProcessChecker()
{
  /* member initializers and constructor code */
}

nsProcessChecker::~nsProcessChecker()
{
  /* destructor code */
}

/* boolean assertPermission (in DOMString aPermission); */
NS_IMETHODIMP nsProcessChecker::AssertPermission(const nsAString & aPermission, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean assertContainApp (in DOMString aManifestURL); */
NS_IMETHODIMP nsProcessChecker::AssertContainApp(const nsAString & aManifestURL, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean assertAppHasPermission (in DOMString aPermission); */
NS_IMETHODIMP nsProcessChecker::AssertAppHasPermission(const nsAString & aPermission, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean assertAppHasStatus (in unsigned short aStatus); */
NS_IMETHODIMP nsProcessChecker::AssertAppHasStatus(uint16_t aStatus, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMessageManager_h__ */
