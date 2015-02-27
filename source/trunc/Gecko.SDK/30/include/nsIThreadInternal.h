/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIThreadInternal.idl
 */

#ifndef __gen_nsIThreadInternal_h__
#define __gen_nsIThreadInternal_h__


#ifndef __gen_nsIThread_h__
#include "nsIThread.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRunnable; /* forward declaration */

class nsIThreadObserver; /* forward declaration */


/* starting interface:    nsIThreadInternal */
#define NS_ITHREADINTERNAL_IID_STR "b24c5af3-43c2-4d17-be14-94d6648a305f"

#define NS_ITHREADINTERNAL_IID \
  {0xb24c5af3, 0x43c2, 0x4d17, \
    { 0xbe, 0x14, 0x94, 0xd6, 0x64, 0x8a, 0x30, 0x5f }}

class NS_NO_VTABLE nsIThreadInternal : public nsIThread {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADINTERNAL_IID)

  /* attribute nsIThreadObserver observer; */
  NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver) = 0;
  NS_IMETHOD SetObserver(nsIThreadObserver *aObserver) = 0;

  /* readonly attribute unsigned long recursionDepth; */
  NS_IMETHOD GetRecursionDepth(uint32_t *aRecursionDepth) = 0;

  /* void addObserver (in nsIThreadObserver observer); */
  NS_IMETHOD AddObserver(nsIThreadObserver *observer) = 0;

  /* void removeObserver (in nsIThreadObserver observer); */
  NS_IMETHOD RemoveObserver(nsIThreadObserver *observer) = 0;

  /* [noscript] nsIEventTarget pushEventQueue (); */
  NS_IMETHOD PushEventQueue(nsIEventTarget * *_retval) = 0;

  /* [noscript] void popEventQueue (in nsIEventTarget aInnermostTarget); */
  NS_IMETHOD PopEventQueue(nsIEventTarget *aInnermostTarget) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadInternal, NS_ITHREADINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADINTERNAL \
  NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver); \
  NS_IMETHOD SetObserver(nsIThreadObserver *aObserver); \
  NS_IMETHOD GetRecursionDepth(uint32_t *aRecursionDepth); \
  NS_IMETHOD AddObserver(nsIThreadObserver *observer); \
  NS_IMETHOD RemoveObserver(nsIThreadObserver *observer); \
  NS_IMETHOD PushEventQueue(nsIEventTarget * *_retval); \
  NS_IMETHOD PopEventQueue(nsIEventTarget *aInnermostTarget); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADINTERNAL(_to) \
  NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver) { return _to GetObserver(aObserver); } \
  NS_IMETHOD SetObserver(nsIThreadObserver *aObserver) { return _to SetObserver(aObserver); } \
  NS_IMETHOD GetRecursionDepth(uint32_t *aRecursionDepth) { return _to GetRecursionDepth(aRecursionDepth); } \
  NS_IMETHOD AddObserver(nsIThreadObserver *observer) { return _to AddObserver(observer); } \
  NS_IMETHOD RemoveObserver(nsIThreadObserver *observer) { return _to RemoveObserver(observer); } \
  NS_IMETHOD PushEventQueue(nsIEventTarget * *_retval) { return _to PushEventQueue(_retval); } \
  NS_IMETHOD PopEventQueue(nsIEventTarget *aInnermostTarget) { return _to PopEventQueue(aInnermostTarget); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADINTERNAL(_to) \
  NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObserver(aObserver); } \
  NS_IMETHOD SetObserver(nsIThreadObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetObserver(aObserver); } \
  NS_IMETHOD GetRecursionDepth(uint32_t *aRecursionDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRecursionDepth(aRecursionDepth); } \
  NS_IMETHOD AddObserver(nsIThreadObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(observer); } \
  NS_IMETHOD RemoveObserver(nsIThreadObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(observer); } \
  NS_IMETHOD PushEventQueue(nsIEventTarget * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PushEventQueue(_retval); } \
  NS_IMETHOD PopEventQueue(nsIEventTarget *aInnermostTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->PopEventQueue(aInnermostTarget); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadInternal : public nsIThreadInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADINTERNAL

  nsThreadInternal();

private:
  ~nsThreadInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadInternal, nsIThreadInternal)

nsThreadInternal::nsThreadInternal()
{
  /* member initializers and constructor code */
}

nsThreadInternal::~nsThreadInternal()
{
  /* destructor code */
}

/* attribute nsIThreadObserver observer; */
NS_IMETHODIMP nsThreadInternal::GetObserver(nsIThreadObserver * *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadInternal::SetObserver(nsIThreadObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long recursionDepth; */
NS_IMETHODIMP nsThreadInternal::GetRecursionDepth(uint32_t *aRecursionDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsIThreadObserver observer); */
NS_IMETHODIMP nsThreadInternal::AddObserver(nsIThreadObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIThreadObserver observer); */
NS_IMETHODIMP nsThreadInternal::RemoveObserver(nsIThreadObserver *observer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsIEventTarget pushEventQueue (); */
NS_IMETHODIMP nsThreadInternal::PushEventQueue(nsIEventTarget * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void popEventQueue (in nsIEventTarget aInnermostTarget); */
NS_IMETHODIMP nsThreadInternal::PopEventQueue(nsIEventTarget *aInnermostTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIThreadObserver */
#define NS_ITHREADOBSERVER_IID_STR "09b424c3-26b0-4128-9039-d66f85b02c63"

#define NS_ITHREADOBSERVER_IID \
  {0x09b424c3, 0x26b0, 0x4128, \
    { 0x90, 0x39, 0xd6, 0x6f, 0x85, 0xb0, 0x2c, 0x63 }}

class NS_NO_VTABLE nsIThreadObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADOBSERVER_IID)

  /* void onDispatchedEvent (in nsIThreadInternal thread); */
  NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread) = 0;

  /* void onProcessNextEvent (in nsIThreadInternal thread, in boolean mayWait, in unsigned long recursionDepth); */
  NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, bool mayWait, uint32_t recursionDepth) = 0;

  /* void afterProcessNextEvent (in nsIThreadInternal thread, in unsigned long recursionDepth, in bool eventWasProcessed); */
  NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, uint32_t recursionDepth, bool eventWasProcessed) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadObserver, NS_ITHREADOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADOBSERVER \
  NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread); \
  NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, bool mayWait, uint32_t recursionDepth); \
  NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, uint32_t recursionDepth, bool eventWasProcessed); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADOBSERVER(_to) \
  NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread) { return _to OnDispatchedEvent(thread); } \
  NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, bool mayWait, uint32_t recursionDepth) { return _to OnProcessNextEvent(thread, mayWait, recursionDepth); } \
  NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, uint32_t recursionDepth, bool eventWasProcessed) { return _to AfterProcessNextEvent(thread, recursionDepth, eventWasProcessed); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADOBSERVER(_to) \
  NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDispatchedEvent(thread); } \
  NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, bool mayWait, uint32_t recursionDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProcessNextEvent(thread, mayWait, recursionDepth); } \
  NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, uint32_t recursionDepth, bool eventWasProcessed) { return !_to ? NS_ERROR_NULL_POINTER : _to->AfterProcessNextEvent(thread, recursionDepth, eventWasProcessed); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadObserver : public nsIThreadObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADOBSERVER

  nsThreadObserver();

private:
  ~nsThreadObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadObserver, nsIThreadObserver)

nsThreadObserver::nsThreadObserver()
{
  /* member initializers and constructor code */
}

nsThreadObserver::~nsThreadObserver()
{
  /* destructor code */
}

/* void onDispatchedEvent (in nsIThreadInternal thread); */
NS_IMETHODIMP nsThreadObserver::OnDispatchedEvent(nsIThreadInternal *thread)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onProcessNextEvent (in nsIThreadInternal thread, in boolean mayWait, in unsigned long recursionDepth); */
NS_IMETHODIMP nsThreadObserver::OnProcessNextEvent(nsIThreadInternal *thread, bool mayWait, uint32_t recursionDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void afterProcessNextEvent (in nsIThreadInternal thread, in unsigned long recursionDepth, in bool eventWasProcessed); */
NS_IMETHODIMP nsThreadObserver::AfterProcessNextEvent(nsIThreadInternal *thread, uint32_t recursionDepth, bool eventWasProcessed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIThreadInternal_h__ */
