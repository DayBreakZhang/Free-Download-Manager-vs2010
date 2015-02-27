/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIThreadPool.idl
 */

#ifndef __gen_nsIThreadPool_h__
#define __gen_nsIThreadPool_h__


#ifndef __gen_nsIEventTarget_h__
#include "nsIEventTarget.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIThreadPoolListener */
#define NS_ITHREADPOOLLISTENER_IID_STR "ef194cab-3f86-4b61-b132-e5e96a79e5d1"

#define NS_ITHREADPOOLLISTENER_IID \
  {0xef194cab, 0x3f86, 0x4b61, \
    { 0xb1, 0x32, 0xe5, 0xe9, 0x6a, 0x79, 0xe5, 0xd1 }}

class NS_NO_VTABLE nsIThreadPoolListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADPOOLLISTENER_IID)

  /* void onThreadCreated (); */
  NS_IMETHOD OnThreadCreated(void) = 0;

  /* void onThreadShuttingDown (); */
  NS_IMETHOD OnThreadShuttingDown(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadPoolListener, NS_ITHREADPOOLLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADPOOLLISTENER \
  NS_IMETHOD OnThreadCreated(void); \
  NS_IMETHOD OnThreadShuttingDown(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADPOOLLISTENER(_to) \
  NS_IMETHOD OnThreadCreated(void) { return _to OnThreadCreated(); } \
  NS_IMETHOD OnThreadShuttingDown(void) { return _to OnThreadShuttingDown(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADPOOLLISTENER(_to) \
  NS_IMETHOD OnThreadCreated(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnThreadCreated(); } \
  NS_IMETHOD OnThreadShuttingDown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnThreadShuttingDown(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadPoolListener : public nsIThreadPoolListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADPOOLLISTENER

  nsThreadPoolListener();

private:
  ~nsThreadPoolListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadPoolListener, nsIThreadPoolListener)

nsThreadPoolListener::nsThreadPoolListener()
{
  /* member initializers and constructor code */
}

nsThreadPoolListener::~nsThreadPoolListener()
{
  /* destructor code */
}

/* void onThreadCreated (); */
NS_IMETHODIMP nsThreadPoolListener::OnThreadCreated()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onThreadShuttingDown (); */
NS_IMETHODIMP nsThreadPoolListener::OnThreadShuttingDown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIThreadPool */
#define NS_ITHREADPOOL_IID_STR "53675068-cb3a-40e5-a026-1be5a97c9b23"

#define NS_ITHREADPOOL_IID \
  {0x53675068, 0xcb3a, 0x40e5, \
    { 0xa0, 0x26, 0x1b, 0xe5, 0xa9, 0x7c, 0x9b, 0x23 }}

class NS_NO_VTABLE nsIThreadPool : public nsIEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADPOOL_IID)

  /* void shutdown (); */
  NS_IMETHOD Shutdown(void) = 0;

  /* attribute unsigned long threadLimit; */
  NS_IMETHOD GetThreadLimit(uint32_t *aThreadLimit) = 0;
  NS_IMETHOD SetThreadLimit(uint32_t aThreadLimit) = 0;

  /* attribute unsigned long idleThreadLimit; */
  NS_IMETHOD GetIdleThreadLimit(uint32_t *aIdleThreadLimit) = 0;
  NS_IMETHOD SetIdleThreadLimit(uint32_t aIdleThreadLimit) = 0;

  /* attribute unsigned long idleThreadTimeout; */
  NS_IMETHOD GetIdleThreadTimeout(uint32_t *aIdleThreadTimeout) = 0;
  NS_IMETHOD SetIdleThreadTimeout(uint32_t aIdleThreadTimeout) = 0;

  /* attribute unsigned long threadStackSize; */
  NS_IMETHOD GetThreadStackSize(uint32_t *aThreadStackSize) = 0;
  NS_IMETHOD SetThreadStackSize(uint32_t aThreadStackSize) = 0;

  /* attribute nsIThreadPoolListener listener; */
  NS_IMETHOD GetListener(nsIThreadPoolListener * *aListener) = 0;
  NS_IMETHOD SetListener(nsIThreadPoolListener *aListener) = 0;

  /* void setName (in ACString aName); */
  NS_IMETHOD SetName(const nsACString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadPool, NS_ITHREADPOOL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADPOOL \
  NS_IMETHOD Shutdown(void); \
  NS_IMETHOD GetThreadLimit(uint32_t *aThreadLimit); \
  NS_IMETHOD SetThreadLimit(uint32_t aThreadLimit); \
  NS_IMETHOD GetIdleThreadLimit(uint32_t *aIdleThreadLimit); \
  NS_IMETHOD SetIdleThreadLimit(uint32_t aIdleThreadLimit); \
  NS_IMETHOD GetIdleThreadTimeout(uint32_t *aIdleThreadTimeout); \
  NS_IMETHOD SetIdleThreadTimeout(uint32_t aIdleThreadTimeout); \
  NS_IMETHOD GetThreadStackSize(uint32_t *aThreadStackSize); \
  NS_IMETHOD SetThreadStackSize(uint32_t aThreadStackSize); \
  NS_IMETHOD GetListener(nsIThreadPoolListener * *aListener); \
  NS_IMETHOD SetListener(nsIThreadPoolListener *aListener); \
  NS_IMETHOD SetName(const nsACString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADPOOL(_to) \
  NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_IMETHOD GetThreadLimit(uint32_t *aThreadLimit) { return _to GetThreadLimit(aThreadLimit); } \
  NS_IMETHOD SetThreadLimit(uint32_t aThreadLimit) { return _to SetThreadLimit(aThreadLimit); } \
  NS_IMETHOD GetIdleThreadLimit(uint32_t *aIdleThreadLimit) { return _to GetIdleThreadLimit(aIdleThreadLimit); } \
  NS_IMETHOD SetIdleThreadLimit(uint32_t aIdleThreadLimit) { return _to SetIdleThreadLimit(aIdleThreadLimit); } \
  NS_IMETHOD GetIdleThreadTimeout(uint32_t *aIdleThreadTimeout) { return _to GetIdleThreadTimeout(aIdleThreadTimeout); } \
  NS_IMETHOD SetIdleThreadTimeout(uint32_t aIdleThreadTimeout) { return _to SetIdleThreadTimeout(aIdleThreadTimeout); } \
  NS_IMETHOD GetThreadStackSize(uint32_t *aThreadStackSize) { return _to GetThreadStackSize(aThreadStackSize); } \
  NS_IMETHOD SetThreadStackSize(uint32_t aThreadStackSize) { return _to SetThreadStackSize(aThreadStackSize); } \
  NS_IMETHOD GetListener(nsIThreadPoolListener * *aListener) { return _to GetListener(aListener); } \
  NS_IMETHOD SetListener(nsIThreadPoolListener *aListener) { return _to SetListener(aListener); } \
  NS_IMETHOD SetName(const nsACString & aName) { return _to SetName(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADPOOL(_to) \
  NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } \
  NS_IMETHOD GetThreadLimit(uint32_t *aThreadLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreadLimit(aThreadLimit); } \
  NS_IMETHOD SetThreadLimit(uint32_t aThreadLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetThreadLimit(aThreadLimit); } \
  NS_IMETHOD GetIdleThreadLimit(uint32_t *aIdleThreadLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdleThreadLimit(aIdleThreadLimit); } \
  NS_IMETHOD SetIdleThreadLimit(uint32_t aIdleThreadLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIdleThreadLimit(aIdleThreadLimit); } \
  NS_IMETHOD GetIdleThreadTimeout(uint32_t *aIdleThreadTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdleThreadTimeout(aIdleThreadTimeout); } \
  NS_IMETHOD SetIdleThreadTimeout(uint32_t aIdleThreadTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIdleThreadTimeout(aIdleThreadTimeout); } \
  NS_IMETHOD GetThreadStackSize(uint32_t *aThreadStackSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreadStackSize(aThreadStackSize); } \
  NS_IMETHOD SetThreadStackSize(uint32_t aThreadStackSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetThreadStackSize(aThreadStackSize); } \
  NS_IMETHOD GetListener(nsIThreadPoolListener * *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetListener(aListener); } \
  NS_IMETHOD SetListener(nsIThreadPoolListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetListener(aListener); } \
  NS_IMETHOD SetName(const nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadPool : public nsIThreadPool
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADPOOL

  nsThreadPool();

private:
  ~nsThreadPool();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadPool, nsIThreadPool)

nsThreadPool::nsThreadPool()
{
  /* member initializers and constructor code */
}

nsThreadPool::~nsThreadPool()
{
  /* destructor code */
}

/* void shutdown (); */
NS_IMETHODIMP nsThreadPool::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long threadLimit; */
NS_IMETHODIMP nsThreadPool::GetThreadLimit(uint32_t *aThreadLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadPool::SetThreadLimit(uint32_t aThreadLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long idleThreadLimit; */
NS_IMETHODIMP nsThreadPool::GetIdleThreadLimit(uint32_t *aIdleThreadLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadPool::SetIdleThreadLimit(uint32_t aIdleThreadLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long idleThreadTimeout; */
NS_IMETHODIMP nsThreadPool::GetIdleThreadTimeout(uint32_t *aIdleThreadTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadPool::SetIdleThreadTimeout(uint32_t aIdleThreadTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long threadStackSize; */
NS_IMETHODIMP nsThreadPool::GetThreadStackSize(uint32_t *aThreadStackSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadPool::SetThreadStackSize(uint32_t aThreadStackSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIThreadPoolListener listener; */
NS_IMETHODIMP nsThreadPool::GetListener(nsIThreadPoolListener * *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsThreadPool::SetListener(nsIThreadPoolListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setName (in ACString aName); */
NS_IMETHODIMP nsThreadPool::SetName(const nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIThreadPool_h__ */
