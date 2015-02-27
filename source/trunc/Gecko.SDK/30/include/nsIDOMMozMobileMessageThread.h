/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMozMobileMessageThread.idl
 */

#ifndef __gen_nsIDOMMozMobileMessageThread_h__
#define __gen_nsIDOMMozMobileMessageThread_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozMobileMessageThread */
#define NS_IDOMMOZMOBILEMESSAGETHREAD_IID_STR "525ad3a6-59a9-11e3-bdc3-836486cb58be"

#define NS_IDOMMOZMOBILEMESSAGETHREAD_IID \
  {0x525ad3a6, 0x59a9, 0x11e3, \
    { 0xbd, 0xc3, 0x83, 0x64, 0x86, 0xcb, 0x58, 0xbe }}

class NS_NO_VTABLE nsIDOMMozMobileMessageThread : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZMOBILEMESSAGETHREAD_IID)

  /* readonly attribute unsigned long long id; */
  NS_IMETHOD GetId(uint64_t *aId) = 0;

  /* readonly attribute DOMString lastMessageSubject; */
  NS_IMETHOD GetLastMessageSubject(nsAString & aLastMessageSubject) = 0;

  /* readonly attribute DOMString body; */
  NS_IMETHOD GetBody(nsAString & aBody) = 0;

  /* readonly attribute unsigned long long unreadCount; */
  NS_IMETHOD GetUnreadCount(uint64_t *aUnreadCount) = 0;

  /* [implicit_jscontext] readonly attribute jsval participants; */
  NS_IMETHOD GetParticipants(JSContext* cx, JS::MutableHandleValue aParticipants) = 0;

  /* readonly attribute DOMTimeStamp timestamp; */
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) = 0;

  /* readonly attribute DOMString lastMessageType; */
  NS_IMETHOD GetLastMessageType(nsAString & aLastMessageType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozMobileMessageThread, NS_IDOMMOZMOBILEMESSAGETHREAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZMOBILEMESSAGETHREAD \
  NS_IMETHOD GetId(uint64_t *aId); \
  NS_IMETHOD GetLastMessageSubject(nsAString & aLastMessageSubject); \
  NS_IMETHOD GetBody(nsAString & aBody); \
  NS_IMETHOD GetUnreadCount(uint64_t *aUnreadCount); \
  NS_IMETHOD GetParticipants(JSContext* cx, JS::MutableHandleValue aParticipants); \
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp); \
  NS_IMETHOD GetLastMessageType(nsAString & aLastMessageType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZMOBILEMESSAGETHREAD(_to) \
  NS_IMETHOD GetId(uint64_t *aId) { return _to GetId(aId); } \
  NS_IMETHOD GetLastMessageSubject(nsAString & aLastMessageSubject) { return _to GetLastMessageSubject(aLastMessageSubject); } \
  NS_IMETHOD GetBody(nsAString & aBody) { return _to GetBody(aBody); } \
  NS_IMETHOD GetUnreadCount(uint64_t *aUnreadCount) { return _to GetUnreadCount(aUnreadCount); } \
  NS_IMETHOD GetParticipants(JSContext* cx, JS::MutableHandleValue aParticipants) { return _to GetParticipants(cx, aParticipants); } \
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) { return _to GetTimestamp(aTimestamp); } \
  NS_IMETHOD GetLastMessageType(nsAString & aLastMessageType) { return _to GetLastMessageType(aLastMessageType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZMOBILEMESSAGETHREAD(_to) \
  NS_IMETHOD GetId(uint64_t *aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetLastMessageSubject(nsAString & aLastMessageSubject) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastMessageSubject(aLastMessageSubject); } \
  NS_IMETHOD GetBody(nsAString & aBody) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBody(aBody); } \
  NS_IMETHOD GetUnreadCount(uint64_t *aUnreadCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnreadCount(aUnreadCount); } \
  NS_IMETHOD GetParticipants(JSContext* cx, JS::MutableHandleValue aParticipants) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParticipants(cx, aParticipants); } \
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimestamp(aTimestamp); } \
  NS_IMETHOD GetLastMessageType(nsAString & aLastMessageType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastMessageType(aLastMessageType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozMobileMessageThread : public nsIDOMMozMobileMessageThread
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZMOBILEMESSAGETHREAD

  nsDOMMozMobileMessageThread();

private:
  ~nsDOMMozMobileMessageThread();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozMobileMessageThread, nsIDOMMozMobileMessageThread)

nsDOMMozMobileMessageThread::nsDOMMozMobileMessageThread()
{
  /* member initializers and constructor code */
}

nsDOMMozMobileMessageThread::~nsDOMMozMobileMessageThread()
{
  /* destructor code */
}

/* readonly attribute unsigned long long id; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetId(uint64_t *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastMessageSubject; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetLastMessageSubject(nsAString & aLastMessageSubject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString body; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetBody(nsAString & aBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long unreadCount; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetUnreadCount(uint64_t *aUnreadCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval participants; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetParticipants(JSContext* cx, JS::MutableHandleValue aParticipants)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMTimeStamp timestamp; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetTimestamp(DOMTimeStamp *aTimestamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastMessageType; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetLastMessageType(nsAString & aLastMessageType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozMobileMessageThread_h__ */
