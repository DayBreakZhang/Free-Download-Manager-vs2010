/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISmsService.idl
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
#define NS_ISMSSERVICE_IID_STR "cb7d7b60-01f1-4241-a0ae-2ff035c3fbe5"

#define NS_ISMSSERVICE_IID \
  {0xcb7d7b60, 0x01f1, 0x4241, \
    { 0xa0, 0xae, 0x2f, 0xf0, 0x35, 0xc3, 0xfb, 0xe5 }}

class NS_NO_VTABLE nsISmsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISMSSERVICE_IID)

  /* readonly attribute unsigned long smsDefaultServiceId; */
  NS_IMETHOD GetSmsDefaultServiceId(uint32_t *aSmsDefaultServiceId) = 0;

  /* void getSegmentInfoForText (in DOMString text, in nsIMobileMessageCallback request); */
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIMobileMessageCallback *request) = 0;

  /* void send (in unsigned long serviceId, in DOMString number, in DOMString message, in boolean silent, in nsIMobileMessageCallback request); */
  NS_IMETHOD Send(uint32_t serviceId, const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request) = 0;

  /* boolean isSilentNumber (in DOMString number); */
  NS_IMETHOD IsSilentNumber(const nsAString & number, bool *_retval) = 0;

  /* void addSilentNumber (in DOMString number); */
  NS_IMETHOD AddSilentNumber(const nsAString & number) = 0;

  /* void removeSilentNumber (in DOMString number); */
  NS_IMETHOD RemoveSilentNumber(const nsAString & number) = 0;

  /* void getSmscAddress (in unsigned long serviceId, in nsIMobileMessageCallback request); */
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, nsIMobileMessageCallback *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISmsService, NS_ISMSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISMSSERVICE \
  NS_IMETHOD GetSmsDefaultServiceId(uint32_t *aSmsDefaultServiceId); \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIMobileMessageCallback *request); \
  NS_IMETHOD Send(uint32_t serviceId, const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request); \
  NS_IMETHOD IsSilentNumber(const nsAString & number, bool *_retval); \
  NS_IMETHOD AddSilentNumber(const nsAString & number); \
  NS_IMETHOD RemoveSilentNumber(const nsAString & number); \
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, nsIMobileMessageCallback *request); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISMSSERVICE(_to) \
  NS_IMETHOD GetSmsDefaultServiceId(uint32_t *aSmsDefaultServiceId) { return _to GetSmsDefaultServiceId(aSmsDefaultServiceId); } \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIMobileMessageCallback *request) { return _to GetSegmentInfoForText(text, request); } \
  NS_IMETHOD Send(uint32_t serviceId, const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request) { return _to Send(serviceId, number, message, silent, request); } \
  NS_IMETHOD IsSilentNumber(const nsAString & number, bool *_retval) { return _to IsSilentNumber(number, _retval); } \
  NS_IMETHOD AddSilentNumber(const nsAString & number) { return _to AddSilentNumber(number); } \
  NS_IMETHOD RemoveSilentNumber(const nsAString & number) { return _to RemoveSilentNumber(number); } \
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, nsIMobileMessageCallback *request) { return _to GetSmscAddress(serviceId, request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISMSSERVICE(_to) \
  NS_IMETHOD GetSmsDefaultServiceId(uint32_t *aSmsDefaultServiceId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSmsDefaultServiceId(aSmsDefaultServiceId); } \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSegmentInfoForText(text, request); } \
  NS_IMETHOD Send(uint32_t serviceId, const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(serviceId, number, message, silent, request); } \
  NS_IMETHOD IsSilentNumber(const nsAString & number, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSilentNumber(number, _retval); } \
  NS_IMETHOD AddSilentNumber(const nsAString & number) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSilentNumber(number); } \
  NS_IMETHOD RemoveSilentNumber(const nsAString & number) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSilentNumber(number); } \
  NS_IMETHOD GetSmscAddress(uint32_t serviceId, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSmscAddress(serviceId, request); } 

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

/* readonly attribute unsigned long smsDefaultServiceId; */
NS_IMETHODIMP nsSmsService::GetSmsDefaultServiceId(uint32_t *aSmsDefaultServiceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSegmentInfoForText (in DOMString text, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsSmsService::GetSegmentInfoForText(const nsAString & text, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void send (in unsigned long serviceId, in DOMString number, in DOMString message, in boolean silent, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsSmsService::Send(uint32_t serviceId, const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSilentNumber (in DOMString number); */
NS_IMETHODIMP nsSmsService::IsSilentNumber(const nsAString & number, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSilentNumber (in DOMString number); */
NS_IMETHODIMP nsSmsService::AddSilentNumber(const nsAString & number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSilentNumber (in DOMString number); */
NS_IMETHODIMP nsSmsService::RemoveSilentNumber(const nsAString & number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getSmscAddress (in unsigned long serviceId, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsSmsService::GetSmscAddress(uint32_t serviceId, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISmsService_h__ */
