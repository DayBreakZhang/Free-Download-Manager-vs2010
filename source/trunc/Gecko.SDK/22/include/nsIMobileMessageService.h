/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mobilemessage/interfaces/nsIMobileMessageService.idl
 */

#ifndef __gen_nsIMobileMessageService_h__
#define __gen_nsIMobileMessageService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozSmsMessage; /* forward declaration */

class nsIDOMMozMmsMessage; /* forward declaration */

class nsIDOMMozSmsSegmentInfo; /* forward declaration */

#define MOBILE_MESSAGE_SERVICE_CID { 0x829c1dd6, 0x0466, 0x4591, { 0x83, 0x6f, 0xb8, 0xf6, 0xfd, 0x1f, 0x7b, 0xa5 } }
#define MOBILE_MESSAGE_SERVICE_CONTRACTID "@mozilla.org/mobilemessage/mobilemessageservice;1"

/* starting interface:    nsIMobileMessageService */
#define NS_IMOBILEMESSAGESERVICE_IID_STR "4cbc9594-84c3-11e2-a274-ebada93fa6cd"

#define NS_IMOBILEMESSAGESERVICE_IID \
  {0x4cbc9594, 0x84c3, 0x11e2, \
    { 0xa2, 0x74, 0xeb, 0xad, 0xa9, 0x3f, 0xa6, 0xcd }}

class NS_NO_VTABLE nsIMobileMessageService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILEMESSAGESERVICE_IID)

  /* [implicit_jscontext] nsIDOMMozSmsMessage createSmsMessage (in long id, in DOMString delivery, in DOMString deliveryStatus, in DOMString sender, in DOMString receiver, in DOMString body, in DOMString messageClass, in jsval timestamp, in bool read); */
  NS_IMETHOD CreateSmsMessage(int32_t id, const nsAString & delivery, const nsAString & deliveryStatus, const nsAString & sender, const nsAString & receiver, const nsAString & body, const nsAString & messageClass, const JS::Value & timestamp, bool read, JSContext* cx, nsIDOMMozSmsMessage * *_retval) = 0;

  /* [implicit_jscontext] nsIDOMMozMmsMessage createMmsMessage (in long id, in DOMString delivery, in jsval deliveryStatus, in DOMString sender, in jsval receivers, in jsval timestamp, in boolean read, in DOMString subject, in DOMString smil, in jsval attachments); */
  NS_IMETHOD CreateMmsMessage(int32_t id, const nsAString & delivery, const JS::Value & deliveryStatus, const nsAString & sender, const JS::Value & receivers, const JS::Value & timestamp, bool read, const nsAString & subject, const nsAString & smil, const JS::Value & attachments, JSContext* cx, nsIDOMMozMmsMessage * *_retval) = 0;

  /* nsIDOMMozSmsSegmentInfo createSmsSegmentInfo (in long segments, in long charsPerSegment, in long charsAvailableInLastSegment); */
  NS_IMETHOD CreateSmsSegmentInfo(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment, nsIDOMMozSmsSegmentInfo * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileMessageService, NS_IMOBILEMESSAGESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILEMESSAGESERVICE \
  NS_IMETHOD CreateSmsMessage(int32_t id, const nsAString & delivery, const nsAString & deliveryStatus, const nsAString & sender, const nsAString & receiver, const nsAString & body, const nsAString & messageClass, const JS::Value & timestamp, bool read, JSContext* cx, nsIDOMMozSmsMessage * *_retval); \
  NS_IMETHOD CreateMmsMessage(int32_t id, const nsAString & delivery, const JS::Value & deliveryStatus, const nsAString & sender, const JS::Value & receivers, const JS::Value & timestamp, bool read, const nsAString & subject, const nsAString & smil, const JS::Value & attachments, JSContext* cx, nsIDOMMozMmsMessage * *_retval); \
  NS_IMETHOD CreateSmsSegmentInfo(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment, nsIDOMMozSmsSegmentInfo * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILEMESSAGESERVICE(_to) \
  NS_IMETHOD CreateSmsMessage(int32_t id, const nsAString & delivery, const nsAString & deliveryStatus, const nsAString & sender, const nsAString & receiver, const nsAString & body, const nsAString & messageClass, const JS::Value & timestamp, bool read, JSContext* cx, nsIDOMMozSmsMessage * *_retval) { return _to CreateSmsMessage(id, delivery, deliveryStatus, sender, receiver, body, messageClass, timestamp, read, cx, _retval); } \
  NS_IMETHOD CreateMmsMessage(int32_t id, const nsAString & delivery, const JS::Value & deliveryStatus, const nsAString & sender, const JS::Value & receivers, const JS::Value & timestamp, bool read, const nsAString & subject, const nsAString & smil, const JS::Value & attachments, JSContext* cx, nsIDOMMozMmsMessage * *_retval) { return _to CreateMmsMessage(id, delivery, deliveryStatus, sender, receivers, timestamp, read, subject, smil, attachments, cx, _retval); } \
  NS_IMETHOD CreateSmsSegmentInfo(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment, nsIDOMMozSmsSegmentInfo * *_retval) { return _to CreateSmsSegmentInfo(segments, charsPerSegment, charsAvailableInLastSegment, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILEMESSAGESERVICE(_to) \
  NS_IMETHOD CreateSmsMessage(int32_t id, const nsAString & delivery, const nsAString & deliveryStatus, const nsAString & sender, const nsAString & receiver, const nsAString & body, const nsAString & messageClass, const JS::Value & timestamp, bool read, JSContext* cx, nsIDOMMozSmsMessage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSmsMessage(id, delivery, deliveryStatus, sender, receiver, body, messageClass, timestamp, read, cx, _retval); } \
  NS_IMETHOD CreateMmsMessage(int32_t id, const nsAString & delivery, const JS::Value & deliveryStatus, const nsAString & sender, const JS::Value & receivers, const JS::Value & timestamp, bool read, const nsAString & subject, const nsAString & smil, const JS::Value & attachments, JSContext* cx, nsIDOMMozMmsMessage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateMmsMessage(id, delivery, deliveryStatus, sender, receivers, timestamp, read, subject, smil, attachments, cx, _retval); } \
  NS_IMETHOD CreateSmsSegmentInfo(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment, nsIDOMMozSmsSegmentInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSmsSegmentInfo(segments, charsPerSegment, charsAvailableInLastSegment, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileMessageService : public nsIMobileMessageService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILEMESSAGESERVICE

  nsMobileMessageService();

private:
  ~nsMobileMessageService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMobileMessageService, nsIMobileMessageService)

nsMobileMessageService::nsMobileMessageService()
{
  /* member initializers and constructor code */
}

nsMobileMessageService::~nsMobileMessageService()
{
  /* destructor code */
}

/* [implicit_jscontext] nsIDOMMozSmsMessage createSmsMessage (in long id, in DOMString delivery, in DOMString deliveryStatus, in DOMString sender, in DOMString receiver, in DOMString body, in DOMString messageClass, in jsval timestamp, in bool read); */
NS_IMETHODIMP nsMobileMessageService::CreateSmsMessage(int32_t id, const nsAString & delivery, const nsAString & deliveryStatus, const nsAString & sender, const nsAString & receiver, const nsAString & body, const nsAString & messageClass, const JS::Value & timestamp, bool read, JSContext* cx, nsIDOMMozSmsMessage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIDOMMozMmsMessage createMmsMessage (in long id, in DOMString delivery, in jsval deliveryStatus, in DOMString sender, in jsval receivers, in jsval timestamp, in boolean read, in DOMString subject, in DOMString smil, in jsval attachments); */
NS_IMETHODIMP nsMobileMessageService::CreateMmsMessage(int32_t id, const nsAString & delivery, const JS::Value & deliveryStatus, const nsAString & sender, const JS::Value & receivers, const JS::Value & timestamp, bool read, const nsAString & subject, const nsAString & smil, const JS::Value & attachments, JSContext* cx, nsIDOMMozMmsMessage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMozSmsSegmentInfo createSmsSegmentInfo (in long segments, in long charsPerSegment, in long charsAvailableInLastSegment); */
NS_IMETHODIMP nsMobileMessageService::CreateSmsSegmentInfo(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment, nsIDOMMozSmsSegmentInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileMessageService_h__ */
