/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mobilemessage/interfaces/nsISmsService.idl
 */

#ifndef __gen_nsISmsService_h__
#define __gen_nsISmsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozSmsMessage; /* forward declaration */

class nsIDOMMozSmsSegmentInfo; /* forward declaration */

class nsIMobileMessageCallback; /* forward declaration */

#define SMS_SERVICE_CID { 0xbada3cb8, 0xa568, 0x4dff, { 0xb5, 0x43, 0x52, 0xbb, 0xb3, 0x14, 0x31, 0x21 } }
#define SMS_SERVICE_CONTRACTID "@mozilla.org/sms/smsservice;1"

/* starting interface:    nsISmsService */
#define NS_ISMSSERVICE_IID_STR "c4b2ed2a-8714-11e2-bd2b-13f1a0759342"

#define NS_ISMSSERVICE_IID \
  {0xc4b2ed2a, 0x8714, 0x11e2, \
    { 0xbd, 0x2b, 0x13, 0xf1, 0xa0, 0x75, 0x93, 0x42 }}

class NS_NO_VTABLE nsISmsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISMSSERVICE_IID)

  /* boolean hasSupport (); */
  NS_IMETHOD HasSupport(bool *_retval) = 0;

  /* nsIDOMMozSmsSegmentInfo getSegmentInfoForText (in DOMString text); */
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) = 0;

  /* void send (in DOMString number, in DOMString message, in nsIMobileMessageCallback request); */
  NS_IMETHOD Send(const nsAString & number, const nsAString & message, nsIMobileMessageCallback *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISmsService, NS_ISMSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISMSSERVICE \
  NS_IMETHOD HasSupport(bool *_retval); \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval); \
  NS_IMETHOD Send(const nsAString & number, const nsAString & message, nsIMobileMessageCallback *request); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISMSSERVICE(_to) \
  NS_IMETHOD HasSupport(bool *_retval) { return _to HasSupport(_retval); } \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) { return _to GetSegmentInfoForText(text, _retval); } \
  NS_IMETHOD Send(const nsAString & number, const nsAString & message, nsIMobileMessageCallback *request) { return _to Send(number, message, request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISMSSERVICE(_to) \
  NS_IMETHOD HasSupport(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasSupport(_retval); } \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSegmentInfoForText(text, _retval); } \
  NS_IMETHOD Send(const nsAString & number, const nsAString & message, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(number, message, request); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSmsService : public nsISmsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISMSSERVICE

  nsSmsService();

private:
  ~nsSmsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSmsService, nsISmsService)

nsSmsService::nsSmsService()
{
  /* member initializers and constructor code */
}

nsSmsService::~nsSmsService()
{
  /* destructor code */
}

/* boolean hasSupport (); */
NS_IMETHODIMP nsSmsService::HasSupport(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMozSmsSegmentInfo getSegmentInfoForText (in DOMString text); */
NS_IMETHODIMP nsSmsService::GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void send (in DOMString number, in DOMString message, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsSmsService::Send(const nsAString & number, const nsAString & message, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISmsService_h__ */
