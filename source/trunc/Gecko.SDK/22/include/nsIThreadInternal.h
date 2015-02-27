/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/threads/nsIThreadInternal.idl
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
class nsIThreadObserver; /* forward declaration */

class nsIThreadEventFilter; /* forward declaration */


/* starting interface:    nsIThreadInternal */
#define NS_ITHREADINTERNAL_IID_STR "504e9e1f-70e1-4f33-a785-5840a4680414"

#define NS_ITHREADINTERNAL_IID \
  {0x504e9e1f, 0x70e1, 0x4f33, \
    { 0xa7, 0x85, 0x58, 0x40, 0xa4, 0x68, 0x04, 0x14 }}

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

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadInternal, NS_ITHREADINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADINTERNAL \
  NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver); \
  NS_IMETHOD SetObserver(nsIThreadObserver *aObserver); \
  NS_IMETHOD GetRecursionDepth(uint32_t *aRecursionDepth); \
  NS_IMETHOD AddObserver(nsIThreadObserver *observer); \
  NS_IMETHOD RemoveObserver(nsIThreadObserver *observer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADINTERNAL(_to) \
  NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver) { return _to GetObserver(aObserver); } \
  NS_IMETHOD SetObserver(nsIThreadObserver *aObserver) { return _to SetObserver(aObserver); } \
  NS_IMETHOD GetRecursionDepth(uint32_t *aRecursionDepth) { return _to GetRecursionDepth(aRecursionDepth); } \
  NS_IMETHOD AddObserver(nsIThreadObserver *observer) { return _to AddObserver(observer); } \
  NS_IMETHOD RemoveObserver(nsIThreadObserver *observer) { return _to RemoveObserver(observer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADINTERNAL(_to) \
  NS_IMETHOD GetObserver(nsIThreadObserver * *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObserver(aObserver); } \
  NS_IMETHOD SetObserver(nsIThreadObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetObserver(aObserver); } \
  NS_IMETHOD GetRecursionDepth(uint32_t *aRecursionDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRecursionDepth(aRecursionDepth); } \
  NS_IMETHOD AddObserver(nsIThreadObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(observer); } \
  NS_IMETHOD RemoveObserver(nsIThreadObserver *observer) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(observer); } 

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

/* End of implementation class template. */
#endif


/* starting interface:    nsIThreadObserver */
#define NS_ITHREADOBSERVER_IID_STR "81d0b509-f198-4417-8020-08eb4271491f"

#define NS_ITHREADOBSERVER_IID \
  {0x81d0b509, 0xf198, 0x4417, \
    { 0x80, 0x20, 0x08, 0xeb, 0x42, 0x71, 0x49, 0x1f }}

class NS_NO_VTABLE nsIThreadObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADOBSERVER_IID)

  /* void onDispatchedEvent (in nsIThreadInternal thread); */
  NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread) = 0;

  /* void onProcessNextEvent (in nsIThreadInternal thread, in boolean mayWait, in unsigned long recursionDepth); */
  NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, bool mayWait, uint32_t recursionDepth) = 0;

  /* void afterProcessNextEvent (in nsIThreadInternal thread, in unsigned long recursionDepth); */
  NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, uint32_t recursionDepth) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadObserver, NS_ITHREADOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADOBSERVER \
  NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread); \
  NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, bool mayWait, uint32_t recursionDepth); \
  NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, uint32_t recursionDepth); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADOBSERVER(_to) \
  NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread) { return _to OnDispatchedEvent(thread); } \
  NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, bool mayWait, uint32_t recursionDepth) { return _to OnProcessNextEvent(thread, mayWait, recursionDepth); } \
  NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, uint32_t recursionDepth) { return _to AfterProcessNextEvent(thread, recursionDepth); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADOBSERVER(_to) \
  NS_IMETHOD OnDispatchedEvent(nsIThreadInternal *thread) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDispatchedEvent(thread); } \
  NS_IMETHOD OnProcessNextEvent(nsIThreadInternal *thread, bool mayWait, uint32_t recursionDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProcessNextEvent(thread, mayWait, recursionDepth); } \
  NS_IMETHOD AfterProcessNextEvent(nsIThreadInternal *thread, uint32_t recursionDepth) { return !_to ? NS_ERROR_NULL_POINTER : _to->AfterProcessNextEvent(thread, recursionDepth); } 

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

/* void afterProcessNextEvent (in nsIThreadInternal thread, in unsigned long recursionDepth); */
NS_IMETHODIMP nsThreadObserver::AfterProcessNextEvent(nsIThreadInternal *thread, uint32_t recursionDepth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIThreadInternal_h__ */
