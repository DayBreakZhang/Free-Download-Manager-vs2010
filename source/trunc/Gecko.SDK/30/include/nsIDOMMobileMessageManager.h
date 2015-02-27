/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMobileMessageManager.idl
 */

#ifndef __gen_nsIDOMMobileMessageManager_h__
#define __gen_nsIDOMMobileMessageManager_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */

class nsIDOMMozSmsFilter; /* forward declaration */

class nsIDOMMozSmsSegmentInfo; /* forward declaration */

class nsIDOMDOMCursor; /* forward declaration */

class nsIDOMDOMRequest; /* forward declaration */

class nsIDOMBlob; /* forward declaration */


/* starting interface:    nsIDOMMozMobileMessageManager */
#define NS_IDOMMOZMOBILEMESSAGEMANAGER_IID_STR "8ec8247d-3f5f-41af-9c72-9dc857e3be81"

#define NS_IDOMMOZMOBILEMESSAGEMANAGER_IID \
  {0x8ec8247d, 0x3f5f, 0x41af, \
    { 0x9c, 0x72, 0x9d, 0xc8, 0x57, 0xe3, 0xbe, 0x81 }}

class NS_NO_VTABLE nsIDOMMozMobileMessageManager : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZMOBILEMESSAGEMANAGER_IID)

  /* nsIDOMDOMRequest getSegmentInfoForText (in DOMString text); */
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMDOMRequest * *_retval) = 0;

  /* [implicit_jscontext,optional_argc] jsval send (in jsval number, in DOMString message, [optional] in jsval sendParameters); */
  NS_IMETHOD Send(JS::HandleValue number, const nsAString & message, JS::HandleValue sendParameters, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) = 0;

  /* [implicit_jscontext,optional_argc] nsIDOMDOMRequest sendMMS (in jsval parameters, [optional] in jsval sendParameters); */
  NS_IMETHOD SendMMS(JS::HandleValue parameters, JS::HandleValue sendParameters, JSContext* cx, uint8_t _argc, nsIDOMDOMRequest * *_retval) = 0;

  /* [binaryname(GetMessageMoz)] nsIDOMDOMRequest getMessage (in long id); */
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval) = 0;

  /* [implicit_jscontext] nsIDOMDOMRequest delete (in jsval param); */
  NS_IMETHOD Delete(JS::HandleValue param, JSContext* cx, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMCursor getMessages (in nsIDOMMozSmsFilter filter, in boolean reverse); */
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval) = 0;

  /* nsIDOMDOMRequest markMessageRead (in long id, in boolean value, [optional] in boolean aSendReadReport); */
  NS_IMETHOD MarkMessageRead(int32_t id, bool value, bool aSendReadReport, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMCursor getThreads (); */
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval) = 0;

  /* nsIDOMDOMRequest retrieveMMS (in long id); */
  NS_IMETHOD RetrieveMMS(int32_t id, nsIDOMDOMRequest * *_retval) = 0;

  /* [optional_argc] nsIDOMDOMRequest getSmscAddress ([optional] in unsigned long serviceId); */
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, uint8_t _argc, nsIDOMDOMRequest * *_retval) = 0;

  /* [implicit_jscontext] attribute jsval onreceived; */
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::MutableHandleValue aOnreceived) = 0;
  NS_IMETHOD SetOnreceived(JSContext* cx, JS::HandleValue aOnreceived) = 0;

  /* [implicit_jscontext] attribute jsval onretrieving; */
  NS_IMETHOD GetOnretrieving(JSContext* cx, JS::MutableHandleValue aOnretrieving) = 0;
  NS_IMETHOD SetOnretrieving(JSContext* cx, JS::HandleValue aOnretrieving) = 0;

  /* [implicit_jscontext] attribute jsval onsending; */
  NS_IMETHOD GetOnsending(JSContext* cx, JS::MutableHandleValue aOnsending) = 0;
  NS_IMETHOD SetOnsending(JSContext* cx, JS::HandleValue aOnsending) = 0;

  /* [implicit_jscontext] attribute jsval onsent; */
  NS_IMETHOD GetOnsent(JSContext* cx, JS::MutableHandleValue aOnsent) = 0;
  NS_IMETHOD SetOnsent(JSContext* cx, JS::HandleValue aOnsent) = 0;

  /* [implicit_jscontext] attribute jsval onfailed; */
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::MutableHandleValue aOnfailed) = 0;
  NS_IMETHOD SetOnfailed(JSContext* cx, JS::HandleValue aOnfailed) = 0;

  /* [implicit_jscontext] attribute jsval ondeliverysuccess; */
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::MutableHandleValue aOndeliverysuccess) = 0;
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, JS::HandleValue aOndeliverysuccess) = 0;

  /* [implicit_jscontext] attribute jsval ondeliveryerror; */
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::MutableHandleValue aOndeliveryerror) = 0;
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, JS::HandleValue aOndeliveryerror) = 0;

  /* [implicit_jscontext] attribute jsval onreadsuccess; */
  NS_IMETHOD GetOnreadsuccess(JSContext* cx, JS::MutableHandleValue aOnreadsuccess) = 0;
  NS_IMETHOD SetOnreadsuccess(JSContext* cx, JS::HandleValue aOnreadsuccess) = 0;

  /* [implicit_jscontext] attribute jsval onreaderror; */
  NS_IMETHOD GetOnreaderror(JSContext* cx, JS::MutableHandleValue aOnreaderror) = 0;
  NS_IMETHOD SetOnreaderror(JSContext* cx, JS::HandleValue aOnreaderror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozMobileMessageManager, NS_IDOMMOZMOBILEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZMOBILEMESSAGEMANAGER \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Send(JS::HandleValue number, const nsAString & message, JS::HandleValue sendParameters, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval); \
  NS_IMETHOD SendMMS(JS::HandleValue parameters, JS::HandleValue sendParameters, JSContext* cx, uint8_t _argc, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Delete(JS::HandleValue param, JSContext* cx, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval); \
  NS_IMETHOD MarkMessageRead(int32_t id, bool value, bool aSendReadReport, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval); \
  NS_IMETHOD RetrieveMMS(int32_t id, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, uint8_t _argc, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::MutableHandleValue aOnreceived); \
  NS_IMETHOD SetOnreceived(JSContext* cx, JS::HandleValue aOnreceived); \
  NS_IMETHOD GetOnretrieving(JSContext* cx, JS::MutableHandleValue aOnretrieving); \
  NS_IMETHOD SetOnretrieving(JSContext* cx, JS::HandleValue aOnretrieving); \
  NS_IMETHOD GetOnsending(JSContext* cx, JS::MutableHandleValue aOnsending); \
  NS_IMETHOD SetOnsending(JSContext* cx, JS::HandleValue aOnsending); \
  NS_IMETHOD GetOnsent(JSContext* cx, JS::MutableHandleValue aOnsent); \
  NS_IMETHOD SetOnsent(JSContext* cx, JS::HandleValue aOnsent); \
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::MutableHandleValue aOnfailed); \
  NS_IMETHOD SetOnfailed(JSContext* cx, JS::HandleValue aOnfailed); \
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::MutableHandleValue aOndeliverysuccess); \
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, JS::HandleValue aOndeliverysuccess); \
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::MutableHandleValue aOndeliveryerror); \
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, JS::HandleValue aOndeliveryerror); \
  NS_IMETHOD GetOnreadsuccess(JSContext* cx, JS::MutableHandleValue aOnreadsuccess); \
  NS_IMETHOD SetOnreadsuccess(JSContext* cx, JS::HandleValue aOnreadsuccess); \
  NS_IMETHOD GetOnreaderror(JSContext* cx, JS::MutableHandleValue aOnreaderror); \
  NS_IMETHOD SetOnreaderror(JSContext* cx, JS::HandleValue aOnreaderror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZMOBILEMESSAGEMANAGER(_to) \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMDOMRequest * *_retval) { return _to GetSegmentInfoForText(text, _retval); } \
  NS_IMETHOD Send(JS::HandleValue number, const nsAString & message, JS::HandleValue sendParameters, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) { return _to Send(number, message, sendParameters, cx, _argc, _retval); } \
  NS_IMETHOD SendMMS(JS::HandleValue parameters, JS::HandleValue sendParameters, JSContext* cx, uint8_t _argc, nsIDOMDOMRequest * *_retval) { return _to SendMMS(parameters, sendParameters, cx, _argc, _retval); } \
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval) { return _to GetMessageMoz(id, _retval); } \
  NS_IMETHOD Delete(JS::HandleValue param, JSContext* cx, nsIDOMDOMRequest * *_retval) { return _to Delete(param, cx, _retval); } \
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval) { return _to GetMessages(filter, reverse, _retval); } \
  NS_IMETHOD MarkMessageRead(int32_t id, bool value, bool aSendReadReport, nsIDOMDOMRequest * *_retval) { return _to MarkMessageRead(id, value, aSendReadReport, _retval); } \
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval) { return _to GetThreads(_retval); } \
  NS_IMETHOD RetrieveMMS(int32_t id, nsIDOMDOMRequest * *_retval) { return _to RetrieveMMS(id, _retval); } \
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, uint8_t _argc, nsIDOMDOMRequest * *_retval) { return _to GetSmscAddress(serviceId, _argc, _retval); } \
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::MutableHandleValue aOnreceived) { return _to GetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD SetOnreceived(JSContext* cx, JS::HandleValue aOnreceived) { return _to SetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD GetOnretrieving(JSContext* cx, JS::MutableHandleValue aOnretrieving) { return _to GetOnretrieving(cx, aOnretrieving); } \
  NS_IMETHOD SetOnretrieving(JSContext* cx, JS::HandleValue aOnretrieving) { return _to SetOnretrieving(cx, aOnretrieving); } \
  NS_IMETHOD GetOnsending(JSContext* cx, JS::MutableHandleValue aOnsending) { return _to GetOnsending(cx, aOnsending); } \
  NS_IMETHOD SetOnsending(JSContext* cx, JS::HandleValue aOnsending) { return _to SetOnsending(cx, aOnsending); } \
  NS_IMETHOD GetOnsent(JSContext* cx, JS::MutableHandleValue aOnsent) { return _to GetOnsent(cx, aOnsent); } \
  NS_IMETHOD SetOnsent(JSContext* cx, JS::HandleValue aOnsent) { return _to SetOnsent(cx, aOnsent); } \
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::MutableHandleValue aOnfailed) { return _to GetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD SetOnfailed(JSContext* cx, JS::HandleValue aOnfailed) { return _to SetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::MutableHandleValue aOndeliverysuccess) { return _to GetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, JS::HandleValue aOndeliverysuccess) { return _to SetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::MutableHandleValue aOndeliveryerror) { return _to GetOndeliveryerror(cx, aOndeliveryerror); } \
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, JS::HandleValue aOndeliveryerror) { return _to SetOndeliveryerror(cx, aOndeliveryerror); } \
  NS_IMETHOD GetOnreadsuccess(JSContext* cx, JS::MutableHandleValue aOnreadsuccess) { return _to GetOnreadsuccess(cx, aOnreadsuccess); } \
  NS_IMETHOD SetOnreadsuccess(JSContext* cx, JS::HandleValue aOnreadsuccess) { return _to SetOnreadsuccess(cx, aOnreadsuccess); } \
  NS_IMETHOD GetOnreaderror(JSContext* cx, JS::MutableHandleValue aOnreaderror) { return _to GetOnreaderror(cx, aOnreaderror); } \
  NS_IMETHOD SetOnreaderror(JSContext* cx, JS::HandleValue aOnreaderror) { return _to SetOnreaderror(cx, aOnreaderror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZMOBILEMESSAGEMANAGER(_to) \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSegmentInfoForText(text, _retval); } \
  NS_IMETHOD Send(JS::HandleValue number, const nsAString & message, JS::HandleValue sendParameters, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(number, message, sendParameters, cx, _argc, _retval); } \
  NS_IMETHOD SendMMS(JS::HandleValue parameters, JS::HandleValue sendParameters, JSContext* cx, uint8_t _argc, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMMS(parameters, sendParameters, cx, _argc, _retval); } \
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(id, _retval); } \
  NS_IMETHOD Delete(JS::HandleValue param, JSContext* cx, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(param, cx, _retval); } \
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessages(filter, reverse, _retval); } \
  NS_IMETHOD MarkMessageRead(int32_t id, bool value, bool aSendReadReport, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkMessageRead(id, value, aSendReadReport, _retval); } \
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreads(_retval); } \
  NS_IMETHOD RetrieveMMS(int32_t id, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RetrieveMMS(id, _retval); } \
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, uint8_t _argc, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSmscAddress(serviceId, _argc, _retval); } \
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::MutableHandleValue aOnreceived) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD SetOnreceived(JSContext* cx, JS::HandleValue aOnreceived) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD GetOnretrieving(JSContext* cx, JS::MutableHandleValue aOnretrieving) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnretrieving(cx, aOnretrieving); } \
  NS_IMETHOD SetOnretrieving(JSContext* cx, JS::HandleValue aOnretrieving) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnretrieving(cx, aOnretrieving); } \
  NS_IMETHOD GetOnsending(JSContext* cx, JS::MutableHandleValue aOnsending) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsending(cx, aOnsending); } \
  NS_IMETHOD SetOnsending(JSContext* cx, JS::HandleValue aOnsending) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsending(cx, aOnsending); } \
  NS_IMETHOD GetOnsent(JSContext* cx, JS::MutableHandleValue aOnsent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsent(cx, aOnsent); } \
  NS_IMETHOD SetOnsent(JSContext* cx, JS::HandleValue aOnsent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsent(cx, aOnsent); } \
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::MutableHandleValue aOnfailed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD SetOnfailed(JSContext* cx, JS::HandleValue aOnfailed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::MutableHandleValue aOndeliverysuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, JS::HandleValue aOndeliverysuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::MutableHandleValue aOndeliveryerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndeliveryerror(cx, aOndeliveryerror); } \
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, JS::HandleValue aOndeliveryerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndeliveryerror(cx, aOndeliveryerror); } \
  NS_IMETHOD GetOnreadsuccess(JSContext* cx, JS::MutableHandleValue aOnreadsuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnreadsuccess(cx, aOnreadsuccess); } \
  NS_IMETHOD SetOnreadsuccess(JSContext* cx, JS::HandleValue aOnreadsuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnreadsuccess(cx, aOnreadsuccess); } \
  NS_IMETHOD GetOnreaderror(JSContext* cx, JS::MutableHandleValue aOnreaderror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnreaderror(cx, aOnreaderror); } \
  NS_IMETHOD SetOnreaderror(JSContext* cx, JS::HandleValue aOnreaderror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnreaderror(cx, aOnreaderror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozMobileMessageManager : public nsIDOMMozMobileMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZMOBILEMESSAGEMANAGER

  nsDOMMozMobileMessageManager();

private:
  ~nsDOMMozMobileMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozMobileMessageManager, nsIDOMMozMobileMessageManager)

nsDOMMozMobileMessageManager::nsDOMMozMobileMessageManager()
{
  /* member initializers and constructor code */
}

nsDOMMozMobileMessageManager::~nsDOMMozMobileMessageManager()
{
  /* destructor code */
}

/* nsIDOMDOMRequest getSegmentInfoForText (in DOMString text); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetSegmentInfoForText(const nsAString & text, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] jsval send (in jsval number, in DOMString message, [optional] in jsval sendParameters); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::Send(JS::HandleValue number, const nsAString & message, JS::HandleValue sendParameters, JSContext* cx, uint8_t _argc, JS::MutableHandleValue _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext,optional_argc] nsIDOMDOMRequest sendMMS (in jsval parameters, [optional] in jsval sendParameters); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::SendMMS(JS::HandleValue parameters, JS::HandleValue sendParameters, JSContext* cx, uint8_t _argc, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(GetMessageMoz)] nsIDOMDOMRequest getMessage (in long id); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIDOMDOMRequest delete (in jsval param); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::Delete(JS::HandleValue param, JSContext* cx, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMCursor getMessages (in nsIDOMMozSmsFilter filter, in boolean reverse); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest markMessageRead (in long id, in boolean value, [optional] in boolean aSendReadReport); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::MarkMessageRead(int32_t id, bool value, bool aSendReadReport, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMCursor getThreads (); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetThreads(nsIDOMDOMCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest retrieveMMS (in long id); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::RetrieveMMS(int32_t id, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIDOMDOMRequest getSmscAddress ([optional] in unsigned long serviceId); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetSmscAddress(uint32_t serviceId, uint8_t _argc, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onreceived; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnreceived(JSContext* cx, JS::MutableHandleValue aOnreceived)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnreceived(JSContext* cx, JS::HandleValue aOnreceived)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onretrieving; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnretrieving(JSContext* cx, JS::MutableHandleValue aOnretrieving)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnretrieving(JSContext* cx, JS::HandleValue aOnretrieving)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsending; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnsending(JSContext* cx, JS::MutableHandleValue aOnsending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnsending(JSContext* cx, JS::HandleValue aOnsending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsent; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnsent(JSContext* cx, JS::MutableHandleValue aOnsent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnsent(JSContext* cx, JS::HandleValue aOnsent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onfailed; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnfailed(JSContext* cx, JS::MutableHandleValue aOnfailed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnfailed(JSContext* cx, JS::HandleValue aOnfailed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondeliverysuccess; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOndeliverysuccess(JSContext* cx, JS::MutableHandleValue aOndeliverysuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOndeliverysuccess(JSContext* cx, JS::HandleValue aOndeliverysuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondeliveryerror; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOndeliveryerror(JSContext* cx, JS::MutableHandleValue aOndeliveryerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOndeliveryerror(JSContext* cx, JS::HandleValue aOndeliveryerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onreadsuccess; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnreadsuccess(JSContext* cx, JS::MutableHandleValue aOnreadsuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnreadsuccess(JSContext* cx, JS::HandleValue aOnreadsuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onreaderror; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnreaderror(JSContext* cx, JS::MutableHandleValue aOnreaderror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnreaderror(JSContext* cx, JS::HandleValue aOnreaderror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMobileMessageManager_h__ */
