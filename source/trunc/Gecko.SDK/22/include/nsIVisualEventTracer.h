/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/base/nsIVisualEventTracer.idl
 */

#ifndef __gen_nsIVisualEventTracer_h__
#define __gen_nsIVisualEventTracer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVisualEventTracerLog; /* forward declaration */


/* starting interface:    nsIVisualEventTracer */
#define NS_IVISUALEVENTTRACER_IID_STR "d51f7867-42f3-4029-8c4e-c00676253a8e"

#define NS_IVISUALEVENTTRACER_IID \
  {0xd51f7867, 0x42f3, 0x4029, \
    { 0x8c, 0x4e, 0xc0, 0x06, 0x76, 0x25, 0x3a, 0x8e }}

class NS_NO_VTABLE nsIVisualEventTracer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVISUALEVENTTRACER_IID)

  /* void start (in unsigned long minBacklogSeconds); */
  NS_IMETHOD Start(uint32_t minBacklogSeconds) = 0;

  /* void stop (); */
  NS_IMETHOD Stop(void) = 0;

  /* nsIVisualEventTracerLog snapshot (); */
  NS_IMETHOD Snapshot(nsIVisualEventTracerLog * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVisualEventTracer, NS_IVISUALEVENTTRACER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVISUALEVENTTRACER \
  NS_IMETHOD Start(uint32_t minBacklogSeconds); \
  NS_IMETHOD Stop(void); \
  NS_IMETHOD Snapshot(nsIVisualEventTracerLog * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVISUALEVENTTRACER(_to) \
  NS_IMETHOD Start(uint32_t minBacklogSeconds) { return _to Start(minBacklogSeconds); } \
  NS_IMETHOD Stop(void) { return _to Stop(); } \
  NS_IMETHOD Snapshot(nsIVisualEventTracerLog * *_retval) { return _to Snapshot(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVISUALEVENTTRACER(_to) \
  NS_IMETHOD Start(uint32_t minBacklogSeconds) { return !_to ? NS_ERROR_NULL_POINTER : _to->Start(minBacklogSeconds); } \
  NS_IMETHOD Stop(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Stop(); } \
  NS_IMETHOD Snapshot(nsIVisualEventTracerLog * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Snapshot(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsVisualEventTracer : public nsIVisualEventTracer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIVISUALEVENTTRACER

  nsVisualEventTracer();

private:
  ~nsVisualEventTracer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsVisualEventTracer, nsIVisualEventTracer)

nsVisualEventTracer::nsVisualEventTracer()
{
  /* member initializers and constructor code */
}

nsVisualEventTracer::~nsVisualEventTracer()
{
  /* destructor code */
}

/* void start (in unsigned long minBacklogSeconds); */
NS_IMETHODIMP nsVisualEventTracer::Start(uint32_t minBacklogSeconds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stop (); */
NS_IMETHODIMP nsVisualEventTracer::Stop()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVisualEventTracerLog snapshot (); */
NS_IMETHODIMP nsVisualEventTracer::Snapshot(nsIVisualEventTracerLog * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIVisualEventTracerLog */
#define NS_IVISUALEVENTTRACERLOG_IID_STR "52ec8962-f67c-4f49-a9d6-89b8ebda2649"

#define NS_IVISUALEVENTTRACERLOG_IID \
  {0x52ec8962, 0xf67c, 0x4f49, \
    { 0xa9, 0xd6, 0x89, 0xb8, 0xeb, 0xda, 0x26, 0x49 }}

class NS_NO_VTABLE nsIVisualEventTracerLog : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVISUALEVENTTRACERLOG_IID)

  /* readonly attribute ACString JSONString; */
  NS_IMETHOD GetJSONString(nsACString & aJSONString) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVisualEventTracerLog, NS_IVISUALEVENTTRACERLOG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVISUALEVENTTRACERLOG \
  NS_IMETHOD GetJSONString(nsACString & aJSONString); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVISUALEVENTTRACERLOG(_to) \
  NS_IMETHOD GetJSONString(nsACString & aJSONString) { return _to GetJSONString(aJSONString); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVISUALEVENTTRACERLOG(_to) \
  NS_IMETHOD GetJSONString(nsACString & aJSONString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSONString(aJSONString); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsVisualEventTracerLog : public nsIVisualEventTracerLog
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIVISUALEVENTTRACERLOG

  nsVisualEventTracerLog();

private:
  ~nsVisualEventTracerLog();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsVisualEventTracerLog, nsIVisualEventTracerLog)

nsVisualEventTracerLog::nsVisualEventTracerLog()
{
  /* member initializers and constructor code */
}

nsVisualEventTracerLog::~nsVisualEventTracerLog()
{
  /* destructor code */
}

/* readonly attribute ACString JSONString; */
NS_IMETHODIMP nsVisualEventTracerLog::GetJSONString(nsACString & aJSONString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIVisualEventTracer_h__ */
