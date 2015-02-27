/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMmsService.idl
 */

#ifndef __gen_nsIMmsService_h__
#define __gen_nsIMmsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMobileMessageCallback; /* forward declaration */

class nsIDOMBlob; /* forward declaration */

#define MMS_SERVICE_CID { 0x06d9124b, 0x80e0, 0x40ed, \
  { 0x98, 0x71, 0x4d, 0x23, 0x4a, 0x0f, 0xd4, 0x31 } }
#define MMS_SERVICE_CONTRACTID "@mozilla.org/mms/mmsservice;1"

/* starting interface:    nsIMmsService */
#define NS_IMMSSERVICE_IID_STR "543278b3-d926-4c65-84b8-b49ad7a17d21"

#define NS_IMMSSERVICE_IID \
  {0x543278b3, 0xd926, 0x4c65, \
    { 0x84, 0xb8, 0xb4, 0x9a, 0xd7, 0xa1, 0x7d, 0x21 }}

class NS_NO_VTABLE nsIMmsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMMSSERVICE_IID)

  /* readonly attribute unsigned long mmsDefaultServiceId; */
  NS_IMETHOD GetMmsDefaultServiceId(uint32_t *aMmsDefaultServiceId) = 0;

  /* void send (in unsigned long serviceId, in jsval parameters, in nsIMobileMessageCallback request); */
  NS_IMETHOD Send(uint32_t serviceId, JS::HandleValue parameters, nsIMobileMessageCallback *request) = 0;

  /* void retrieve (in long id, in nsIMobileMessageCallback request); */
  NS_IMETHOD Retrieve(int32_t id, nsIMobileMessageCallback *request) = 0;

  /* void sendReadReport (in DOMString messageID, in DOMString toAddress, in DOMString iccId); */
  NS_IMETHOD SendReadReport(const nsAString & messageID, const nsAString & toAddress, const nsAString & iccId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMmsService, NS_IMMSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMMSSERVICE \
  NS_IMETHOD GetMmsDefaultServiceId(uint32_t *aMmsDefaultServiceId); \
  NS_IMETHOD Send(uint32_t serviceId, JS::HandleValue parameters, nsIMobileMessageCallback *request); \
  NS_IMETHOD Retrieve(int32_t id, nsIMobileMessageCallback *request); \
  NS_IMETHOD SendReadReport(const nsAString & messageID, const nsAString & toAddress, const nsAString & iccId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMMSSERVICE(_to) \
  NS_IMETHOD GetMmsDefaultServiceId(uint32_t *aMmsDefaultServiceId) { return _to GetMmsDefaultServiceId(aMmsDefaultServiceId); } \
  NS_IMETHOD Send(uint32_t serviceId, JS::HandleValue parameters, nsIMobileMessageCallback *request) { return _to Send(serviceId, parameters, request); } \
  NS_IMETHOD Retrieve(int32_t id, nsIMobileMessageCallback *request) { return _to Retrieve(id, request); } \
  NS_IMETHOD SendReadReport(const nsAString & messageID, const nsAString & toAddress, const nsAString & iccId) { return _to SendReadReport(messageID, toAddress, iccId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMMSSERVICE(_to) \
  NS_IMETHOD GetMmsDefaultServiceId(uint32_t *aMmsDefaultServiceId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMmsDefaultServiceId(aMmsDefaultServiceId); } \
  NS_IMETHOD Send(uint32_t serviceId, JS::HandleValue parameters, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(serviceId, parameters, request); } \
  NS_IMETHOD Retrieve(int32_t id, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Retrieve(id, request); } \
  NS_IMETHOD SendReadReport(const nsAString & messageID, const nsAString & toAddress, const nsAString & iccId) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendReadReport(messageID, toAddress, iccId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMmsService : public nsIMmsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMMSSERVICE

  nsMmsService();

private:
  ~nsMmsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMmsService, nsIMmsService)

nsMmsService::nsMmsService()
{
  /* member initializers and constructor code */
}

nsMmsService::~nsMmsService()
{
  /* destructor code */
}

/* readonly attribute unsigned long mmsDefaultServiceId; */
NS_IMETHODIMP nsMmsService::GetMmsDefaultServiceId(uint32_t *aMmsDefaultServiceId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void send (in unsigned long serviceId, in jsval parameters, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMmsService::Send(uint32_t serviceId, JS::HandleValue parameters, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void retrieve (in long id, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMmsService::Retrieve(int32_t id, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendReadReport (in DOMString messageID, in DOMString toAddress, in DOMString iccId); */
NS_IMETHODIMP nsMmsService::SendReadReport(const nsAString & messageID, const nsAString & toAddress, const nsAString & iccId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMmsService_h__ */
