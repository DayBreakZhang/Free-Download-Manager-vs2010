/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mobilemessage/interfaces/nsIMobileMessageDatabaseService.idl
 */

#ifndef __gen_nsIMobileMessageDatabaseService_h__
#define __gen_nsIMobileMessageDatabaseService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define MOBILE_MESSAGE_DATABASE_SERVICE_CID \
{ 0x0d84b9c2, 0x8f76, 0x4ba4,    \
{ 0xa5, 0xcd, 0xdb, 0xfb, 0x01, 0xdf, 0xda, 0x99 } }
#define MOBILE_MESSAGE_DATABASE_SERVICE_CONTRACTID "@mozilla.org/mobilemessage/mobilemessagedatabaseservice;1"
class nsIDOMMozSmsFilter; /* forward declaration */

class nsIMobileMessageCallback; /* forward declaration */


/* starting interface:    nsIMobileMessageDatabaseService */
#define NS_IMOBILEMESSAGEDATABASESERVICE_IID_STR "4000064a-86d2-11e2-b4a6-ef0f30bd1e59"

#define NS_IMOBILEMESSAGEDATABASESERVICE_IID \
  {0x4000064a, 0x86d2, 0x11e2, \
    { 0xb4, 0xa6, 0xef, 0x0f, 0x30, 0xbd, 0x1e, 0x59 }}

class NS_NO_VTABLE nsIMobileMessageDatabaseService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILEMESSAGEDATABASESERVICE_IID)

  /* [binaryname(GetMessageMoz)] void getMessage (in long messageId, in nsIMobileMessageCallback request); */
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsIMobileMessageCallback *request) = 0;

  /* void deleteMessage (in long messageId, in nsIMobileMessageCallback request); */
  NS_IMETHOD DeleteMessage(int32_t messageId, nsIMobileMessageCallback *request) = 0;

  /* void createMessageList (in nsIDOMMozSmsFilter filter, in boolean reverse, in nsIMobileMessageCallback request); */
  NS_IMETHOD CreateMessageList(nsIDOMMozSmsFilter *filter, bool reverse, nsIMobileMessageCallback *request) = 0;

  /* void getNextMessageInList (in long listId, in nsIMobileMessageCallback request); */
  NS_IMETHOD GetNextMessageInList(int32_t listId, nsIMobileMessageCallback *request) = 0;

  /* void clearMessageList (in long listId); */
  NS_IMETHOD ClearMessageList(int32_t listId) = 0;

  /* void markMessageRead (in long messageId, in boolean value, in nsIMobileMessageCallback request); */
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, nsIMobileMessageCallback *request) = 0;

  /* void getThreadList (in nsIMobileMessageCallback request); */
  NS_IMETHOD GetThreadList(nsIMobileMessageCallback *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileMessageDatabaseService, NS_IMOBILEMESSAGEDATABASESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILEMESSAGEDATABASESERVICE \
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsIMobileMessageCallback *request); \
  NS_IMETHOD DeleteMessage(int32_t messageId, nsIMobileMessageCallback *request); \
  NS_IMETHOD CreateMessageList(nsIDOMMozSmsFilter *filter, bool reverse, nsIMobileMessageCallback *request); \
  NS_IMETHOD GetNextMessageInList(int32_t listId, nsIMobileMessageCallback *request); \
  NS_IMETHOD ClearMessageList(int32_t listId); \
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, nsIMobileMessageCallback *request); \
  NS_IMETHOD GetThreadList(nsIMobileMessageCallback *request); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILEMESSAGEDATABASESERVICE(_to) \
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsIMobileMessageCallback *request) { return _to GetMessageMoz(messageId, request); } \
  NS_IMETHOD DeleteMessage(int32_t messageId, nsIMobileMessageCallback *request) { return _to DeleteMessage(messageId, request); } \
  NS_IMETHOD CreateMessageList(nsIDOMMozSmsFilter *filter, bool reverse, nsIMobileMessageCallback *request) { return _to CreateMessageList(filter, reverse, request); } \
  NS_IMETHOD GetNextMessageInList(int32_t listId, nsIMobileMessageCallback *request) { return _to GetNextMessageInList(listId, request); } \
  NS_IMETHOD ClearMessageList(int32_t listId) { return _to ClearMessageList(listId); } \
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, nsIMobileMessageCallback *request) { return _to MarkMessageRead(messageId, value, request); } \
  NS_IMETHOD GetThreadList(nsIMobileMessageCallback *request) { return _to GetThreadList(request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILEMESSAGEDATABASESERVICE(_to) \
  NS_IMETHOD GetMessageMoz(int32_t messageId, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(messageId, request); } \
  NS_IMETHOD DeleteMessage(int32_t messageId, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteMessage(messageId, request); } \
  NS_IMETHOD CreateMessageList(nsIDOMMozSmsFilter *filter, bool reverse, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateMessageList(filter, reverse, request); } \
  NS_IMETHOD GetNextMessageInList(int32_t listId, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextMessageInList(listId, request); } \
  NS_IMETHOD ClearMessageList(int32_t listId) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearMessageList(listId); } \
  NS_IMETHOD MarkMessageRead(int32_t messageId, bool value, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkMessageRead(messageId, value, request); } \
  NS_IMETHOD GetThreadList(nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreadList(request); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileMessageDatabaseService : public nsIMobileMessageDatabaseService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILEMESSAGEDATABASESERVICE

  nsMobileMessageDatabaseService();

private:
  ~nsMobileMessageDatabaseService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMobileMessageDatabaseService, nsIMobileMessageDatabaseService)

nsMobileMessageDatabaseService::nsMobileMessageDatabaseService()
{
  /* member initializers and constructor code */
}

nsMobileMessageDatabaseService::~nsMobileMessageDatabaseService()
{
  /* destructor code */
}

/* [binaryname(GetMessageMoz)] void getMessage (in long messageId, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMobileMessageDatabaseService::GetMessageMoz(int32_t messageId, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteMessage (in long messageId, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMobileMessageDatabaseService::DeleteMessage(int32_t messageId, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void createMessageList (in nsIDOMMozSmsFilter filter, in boolean reverse, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMobileMessageDatabaseService::CreateMessageList(nsIDOMMozSmsFilter *filter, bool reverse, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getNextMessageInList (in long listId, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMobileMessageDatabaseService::GetNextMessageInList(int32_t listId, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearMessageList (in long listId); */
NS_IMETHODIMP nsMobileMessageDatabaseService::ClearMessageList(int32_t listId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void markMessageRead (in long messageId, in boolean value, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMobileMessageDatabaseService::MarkMessageRead(int32_t messageId, bool value, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getThreadList (in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMobileMessageDatabaseService::GetThreadList(nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileMessageDatabaseService_h__ */
