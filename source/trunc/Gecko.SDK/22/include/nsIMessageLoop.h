/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/base/nsIMessageLoop.idl
 */

#ifndef __gen_nsIMessageLoop_h__
#define __gen_nsIMessageLoop_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRunnable; /* forward declaration */


/* starting interface:    nsIMessageLoop */
#define NS_IMESSAGELOOP_IID_STR "3e8c58e8-e52c-43e0-8e66-669ca788ff5f"

#define NS_IMESSAGELOOP_IID \
  {0x3e8c58e8, 0xe52c, 0x43e0, \
    { 0x8e, 0x66, 0x66, 0x9c, 0xa7, 0x88, 0xff, 0x5f }}

class NS_NO_VTABLE nsIMessageLoop : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMESSAGELOOP_IID)

  /* void postIdleTask (in nsIRunnable task, in uint32_t ensureRunsAfterMS); */
  NS_IMETHOD PostIdleTask(nsIRunnable *task, uint32_t ensureRunsAfterMS) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMessageLoop, NS_IMESSAGELOOP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMESSAGELOOP \
  NS_IMETHOD PostIdleTask(nsIRunnable *task, uint32_t ensureRunsAfterMS); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMESSAGELOOP(_to) \
  NS_IMETHOD PostIdleTask(nsIRunnable *task, uint32_t ensureRunsAfterMS) { return _to PostIdleTask(task, ensureRunsAfterMS); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMESSAGELOOP(_to) \
  NS_IMETHOD PostIdleTask(nsIRunnable *task, uint32_t ensureRunsAfterMS) { return !_to ? NS_ERROR_NULL_POINTER : _to->PostIdleTask(task, ensureRunsAfterMS); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMessageLoop : public nsIMessageLoop
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMESSAGELOOP

  nsMessageLoop();

private:
  ~nsMessageLoop();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMessageLoop, nsIMessageLoop)

nsMessageLoop::nsMessageLoop()
{
  /* member initializers and constructor code */
}

nsMessageLoop::~nsMessageLoop()
{
  /* destructor code */
}

/* void postIdleTask (in nsIRunnable task, in uint32_t ensureRunsAfterMS); */
NS_IMETHODIMP nsMessageLoop::PostIdleTask(nsIRunnable *task, uint32_t ensureRunsAfterMS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMessageLoop_h__ */
