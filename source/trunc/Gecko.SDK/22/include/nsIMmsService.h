/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mms/interfaces/nsIMmsService.idl
 */

#ifndef __gen_nsIMmsService_h__
#define __gen_nsIMmsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMobileMessageCallback; /* forward declaration */

class nsIDOMBlob; /* forward declaration */

#define RIL_MMSSERVICE_CONTRACTID "@mozilla.org/mms/rilmmsservice;1"

/* starting interface:    nsIMmsService */
#define NS_IMMSSERVICE_IID_STR "3ec33286-8559-11e2-9f38-e76b58650568"

#define NS_IMMSSERVICE_IID \
  {0x3ec33286, 0x8559, 0x11e2, \
    { 0x9f, 0x38, 0xe7, 0x6b, 0x58, 0x65, 0x05, 0x68 }}

class NS_NO_VTABLE nsIMmsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMMSSERVICE_IID)

  /* void send (in jsval parameters, in nsIMobileMessageCallback request); */
  NS_IMETHOD Send(const JS::Value & parameters, nsIMobileMessageCallback *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMmsService, NS_IMMSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMMSSERVICE \
  NS_IMETHOD Send(const JS::Value & parameters, nsIMobileMessageCallback *request); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMMSSERVICE(_to) \
  NS_IMETHOD Send(const JS::Value & parameters, nsIMobileMessageCallback *request) { return _to Send(parameters, request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMMSSERVICE(_to) \
  NS_IMETHOD Send(const JS::Value & parameters, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(parameters, request); } 

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

/* void send (in jsval parameters, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMmsService::Send(const JS::Value & parameters, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMmsService_h__ */
