/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFrameRequestCallback.idl
 */

#ifndef __gen_nsIFrameRequestCallback_h__
#define __gen_nsIFrameRequestCallback_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFrameRequestCallback */
#define NS_IFRAMEREQUESTCALLBACK_IID_STR "e8d887f0-2ed7-406f-9f1d-edeb2c54c0a2"

#define NS_IFRAMEREQUESTCALLBACK_IID \
  {0xe8d887f0, 0x2ed7, 0x406f, \
    { 0x9f, 0x1d, 0xed, 0xeb, 0x2c, 0x54, 0xc0, 0xa2 }}

class NS_NO_VTABLE nsIFrameRequestCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFRAMEREQUESTCALLBACK_IID)

  /* void sample (in DOMTimeStamp timeStamp); */
  NS_IMETHOD Sample(DOMTimeStamp timeStamp) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFrameRequestCallback, NS_IFRAMEREQUESTCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFRAMEREQUESTCALLBACK \
  NS_IMETHOD Sample(DOMTimeStamp timeStamp); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFRAMEREQUESTCALLBACK(_to) \
  NS_IMETHOD Sample(DOMTimeStamp timeStamp) { return _to Sample(timeStamp); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFRAMEREQUESTCALLBACK(_to) \
  NS_IMETHOD Sample(DOMTimeStamp timeStamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->Sample(timeStamp); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFrameRequestCallback : public nsIFrameRequestCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFRAMEREQUESTCALLBACK

  nsFrameRequestCallback();

private:
  ~nsFrameRequestCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFrameRequestCallback, nsIFrameRequestCallback)

nsFrameRequestCallback::nsFrameRequestCallback()
{
  /* member initializers and constructor code */
}

nsFrameRequestCallback::~nsFrameRequestCallback()
{
  /* destructor code */
}

/* void sample (in DOMTimeStamp timeStamp); */
NS_IMETHODIMP nsFrameRequestCallback::Sample(DOMTimeStamp timeStamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFrameRequestCallback_h__ */
