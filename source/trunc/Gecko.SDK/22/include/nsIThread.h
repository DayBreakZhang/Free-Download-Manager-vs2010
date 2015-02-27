/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/threads/nsIThread.idl
 */

#ifndef __gen_nsIThread_h__
#define __gen_nsIThread_h__


#ifndef __gen_nsIEventTarget_h__
#include "nsIEventTarget.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIThread */
#define NS_ITHREAD_IID_STR "9c889946-a73a-4af3-ae9a-ea64f7d4e3ca"

#define NS_ITHREAD_IID \
  {0x9c889946, 0xa73a, 0x4af3, \
    { 0xae, 0x9a, 0xea, 0x64, 0xf7, 0xd4, 0xe3, 0xca }}

class NS_NO_VTABLE nsIThread : public nsIEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREAD_IID)

  /* [noscript] readonly attribute PRThread PRThread; */
  NS_IMETHOD GetPRThread(PRThread **aPRThread) = 0;

  /* void shutdown (); */
  NS_IMETHOD Shutdown(void) = 0;

  /* boolean hasPendingEvents (); */
  NS_IMETHOD HasPendingEvents(bool *_retval) = 0;

  /* boolean processNextEvent (in boolean mayWait); */
  NS_IMETHOD ProcessNextEvent(bool mayWait, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThread, NS_ITHREAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREAD \
  NS_IMETHOD GetPRThread(PRThread **aPRThread); \
  NS_IMETHOD Shutdown(void); \
  NS_IMETHOD HasPendingEvents(bool *_retval); \
  NS_IMETHOD ProcessNextEvent(bool mayWait, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREAD(_to) \
  NS_IMETHOD GetPRThread(PRThread **aPRThread) { return _to GetPRThread(aPRThread); } \
  NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_IMETHOD HasPendingEvents(bool *_retval) { return _to HasPendingEvents(_retval); } \
  NS_IMETHOD ProcessNextEvent(bool mayWait, bool *_retval) { return _to ProcessNextEvent(mayWait, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREAD(_to) \
  NS_IMETHOD GetPRThread(PRThread **aPRThread) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPRThread(aPRThread); } \
  NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } \
  NS_IMETHOD HasPendingEvents(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasPendingEvents(_retval); } \
  NS_IMETHOD ProcessNextEvent(bool mayWait, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessNextEvent(mayWait, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThread : public nsIThread
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREAD

  nsThread();

private:
  ~nsThread();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThread, nsIThread)

nsThread::nsThread()
{
  /* member initializers and constructor code */
}

nsThread::~nsThread()
{
  /* destructor code */
}

/* [noscript] readonly attribute PRThread PRThread; */
NS_IMETHODIMP nsThread::GetPRThread(PRThread **aPRThread)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shutdown (); */
NS_IMETHODIMP nsThread::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasPendingEvents (); */
NS_IMETHODIMP nsThread::HasPendingEvents(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean processNextEvent (in boolean mayWait); */
NS_IMETHODIMP nsThread::ProcessNextEvent(bool mayWait, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIThread_h__ */
