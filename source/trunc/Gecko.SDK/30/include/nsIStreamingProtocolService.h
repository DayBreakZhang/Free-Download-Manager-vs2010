/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStreamingProtocolService.idl
 */

#ifndef __gen_nsIStreamingProtocolService_h__
#define __gen_nsIStreamingProtocolService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIStreamingProtocolController; /* forward declaration */

class nsIChannel; /* forward declaration */

#define NS_MEDIASTREAMCONTROLLERSERVICE_CID                                   \
  { 0x94838530, 0x8627, 0x11e2,                                               \
    {                                                                         \
      0x9e, 0x96, 0x08, 0x00,                                                 \
      0x20, 0x0c, 0x9a, 0x66                                                  \
    }                                                                         \
  }
#define MEDIASTREAMCONTROLLERSERVICE_CONTRACTID                               \
  "@mozilla.org/mediastream/mediastreamcontrollerservice;1"

/* starting interface:    nsIStreamingProtocolControllerService */
#define NS_ISTREAMINGPROTOCOLCONTROLLERSERVICE_IID_STR "94838530-8627-11e2-9e96-0800200c9a66"

#define NS_ISTREAMINGPROTOCOLCONTROLLERSERVICE_IID \
  {0x94838530, 0x8627, 0x11e2, \
    { 0x9e, 0x96, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIStreamingProtocolControllerService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMINGPROTOCOLCONTROLLERSERVICE_IID)

  /* nsIStreamingProtocolController create (in nsIChannel channel); */
  NS_IMETHOD Create(nsIChannel *channel, nsIStreamingProtocolController * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamingProtocolControllerService, NS_ISTREAMINGPROTOCOLCONTROLLERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMINGPROTOCOLCONTROLLERSERVICE \
  NS_IMETHOD Create(nsIChannel *channel, nsIStreamingProtocolController * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMINGPROTOCOLCONTROLLERSERVICE(_to) \
  NS_IMETHOD Create(nsIChannel *channel, nsIStreamingProtocolController * *_retval) { return _to Create(channel, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMINGPROTOCOLCONTROLLERSERVICE(_to) \
  NS_IMETHOD Create(nsIChannel *channel, nsIStreamingProtocolController * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Create(channel, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamingProtocolControllerService : public nsIStreamingProtocolControllerService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMINGPROTOCOLCONTROLLERSERVICE

  nsStreamingProtocolControllerService();

private:
  ~nsStreamingProtocolControllerService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamingProtocolControllerService, nsIStreamingProtocolControllerService)

nsStreamingProtocolControllerService::nsStreamingProtocolControllerService()
{
  /* member initializers and constructor code */
}

nsStreamingProtocolControllerService::~nsStreamingProtocolControllerService()
{
  /* destructor code */
}

/* nsIStreamingProtocolController create (in nsIChannel channel); */
NS_IMETHODIMP nsStreamingProtocolControllerService::Create(nsIChannel *channel, nsIStreamingProtocolController * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStreamingProtocolService_h__ */
