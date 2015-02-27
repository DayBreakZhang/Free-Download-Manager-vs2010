/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIThreadRetargetableStreamListener.idl
 */

#ifndef __gen_nsIThreadRetargetableStreamListener_h__
#define __gen_nsIThreadRetargetableStreamListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIThreadRetargetableStreamListener */
#define NS_ITHREADRETARGETABLESTREAMLISTENER_IID_STR "fb2304b8-f82f-4433-af68-d874a2ebbdc1"

#define NS_ITHREADRETARGETABLESTREAMLISTENER_IID \
  {0xfb2304b8, 0xf82f, 0x4433, \
    { 0xaf, 0x68, 0xd8, 0x74, 0xa2, 0xeb, 0xbd, 0xc1 }}

class NS_NO_VTABLE nsIThreadRetargetableStreamListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADRETARGETABLESTREAMLISTENER_IID)

  /* void checkListenerChain (); */
  NS_IMETHOD CheckListenerChain(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadRetargetableStreamListener, NS_ITHREADRETARGETABLESTREAMLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADRETARGETABLESTREAMLISTENER \
  NS_IMETHOD CheckListenerChain(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADRETARGETABLESTREAMLISTENER(_to) \
  NS_IMETHOD CheckListenerChain(void) { return _to CheckListenerChain(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADRETARGETABLESTREAMLISTENER(_to) \
  NS_IMETHOD CheckListenerChain(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckListenerChain(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadRetargetableStreamListener : public nsIThreadRetargetableStreamListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADRETARGETABLESTREAMLISTENER

  nsThreadRetargetableStreamListener();

private:
  ~nsThreadRetargetableStreamListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadRetargetableStreamListener, nsIThreadRetargetableStreamListener)

nsThreadRetargetableStreamListener::nsThreadRetargetableStreamListener()
{
  /* member initializers and constructor code */
}

nsThreadRetargetableStreamListener::~nsThreadRetargetableStreamListener()
{
  /* destructor code */
}

/* void checkListenerChain (); */
NS_IMETHODIMP nsThreadRetargetableStreamListener::CheckListenerChain()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIThreadRetargetableStreamListener_h__ */
