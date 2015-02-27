/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/system/nsIOSFileConstantsService.idl
 */

#ifndef __gen_nsIOSFileConstantsService_h__
#define __gen_nsIOSFileConstantsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIOSFileConstantsService */
#define NS_IOSFILECONSTANTSSERVICE_IID_STR "d6dd239f-34d6-4b34-baa1-f69ab4a20bc4"

#define NS_IOSFILECONSTANTSSERVICE_IID \
  {0xd6dd239f, 0x34d6, 0x4b34, \
    { 0xba, 0xa1, 0xf6, 0x9a, 0xb4, 0xa2, 0x0b, 0xc4 }}

class NS_NO_VTABLE nsIOSFileConstantsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IOSFILECONSTANTSSERVICE_IID)

  /* [implicit_jscontext] void init (); */
  NS_IMETHOD Init(JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIOSFileConstantsService, NS_IOSFILECONSTANTSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIOSFILECONSTANTSSERVICE \
  NS_IMETHOD Init(JSContext* cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIOSFILECONSTANTSSERVICE(_to) \
  NS_IMETHOD Init(JSContext* cx) { return _to Init(cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIOSFILECONSTANTSSERVICE(_to) \
  NS_IMETHOD Init(JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsOSFileConstantsService : public nsIOSFileConstantsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIOSFILECONSTANTSSERVICE

  nsOSFileConstantsService();

private:
  ~nsOSFileConstantsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsOSFileConstantsService, nsIOSFileConstantsService)

nsOSFileConstantsService::nsOSFileConstantsService()
{
  /* member initializers and constructor code */
}

nsOSFileConstantsService::~nsOSFileConstantsService()
{
  /* destructor code */
}

/* [implicit_jscontext] void init (); */
NS_IMETHODIMP nsOSFileConstantsService::Init(JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


// {4BBE1B96-8956-457F-A03F-9C27435F2AFA}
#define OSFILECONSTANTSSERVICE_CID {0x4BBE1B96,0x8956,0x457F,{0xA0,0x3F,0x9C,0x27,0x43,0x5F,0x2A,0xFA}}
#define OSFILECONSTANTSSERVICE_CONTRACTID "@mozilla.org/net/osfileconstantsservice;1"

#endif /* __gen_nsIOSFileConstantsService_h__ */
