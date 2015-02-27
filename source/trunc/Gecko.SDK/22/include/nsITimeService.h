/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/time/nsITimeService.idl
 */

#ifndef __gen_nsITimeService_h__
#define __gen_nsITimeService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_TIMESERVICE_CID { 0x80d6f9cc, 0xf16d, 0x40c3, { 0xa5, 0x2e, 0xc4, 0xe6, 0x56, 0xe3, 0x65, 0xb4 } }
#define TIMESERVICE_CONTRACTID "@mozilla.org/time/timeservice;1"

/* starting interface:    nsITimeService */
#define NS_ITIMESERVICE_IID_STR "1fc7fde2-0090-11e2-bdd6-0fea4b9f41f8"

#define NS_ITIMESERVICE_IID \
  {0x1fc7fde2, 0x0090, 0x11e2, \
    { 0xbd, 0xd6, 0x0f, 0xea, 0x4b, 0x9f, 0x41, 0xf8 }}

class NS_NO_VTABLE nsITimeService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITIMESERVICE_IID)

  /* void set (in int64_t aTimeInMS); */
  NS_IMETHOD Set(int64_t aTimeInMS) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITimeService, NS_ITIMESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITIMESERVICE \
  NS_IMETHOD Set(int64_t aTimeInMS); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITIMESERVICE(_to) \
  NS_IMETHOD Set(int64_t aTimeInMS) { return _to Set(aTimeInMS); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITIMESERVICE(_to) \
  NS_IMETHOD Set(int64_t aTimeInMS) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(aTimeInMS); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTimeService : public nsITimeService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITIMESERVICE

  nsTimeService();

private:
  ~nsTimeService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTimeService, nsITimeService)

nsTimeService::nsTimeService()
{
  /* member initializers and constructor code */
}

nsTimeService::~nsTimeService()
{
  /* destructor code */
}

/* void set (in int64_t aTimeInMS); */
NS_IMETHODIMP nsTimeService::Set(int64_t aTimeInMS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITimeService_h__ */
