/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIVisualEventTracer.idl
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
#define NS_IVISUALEVENTTRACER_IID_STR "713ee3ca-95e0-4085-8616-f6d64a9508ad"

#define NS_IVISUALEVENTTRACER_IID \
  {0x713ee3ca, 0x95e0, 0x4085, \
    { 0x86, 0x16, 0xf6, 0xd6, 0x4a, 0x95, 0x08, 0xad }}

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
#define NS_IVISUALEVENTTRACERLOG_IID_STR "8ec6e36d-6cba-400b-bcd6-454679f5f75a"

#define NS_IVISUALEVENTTRACERLOG_IID \
  {0x8ec6e36d, 0x6cba, 0x400b, \
    { 0xbc, 0xd6, 0x45, 0x46, 0x79, 0xf5, 0xf7, 0x5a }}

class NS_NO_VTABLE nsIVisualEventTracerLog : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IVISUALEVENTTRACERLOG_IID)

  /* readonly attribute ACString JSONString; */
  NS_IMETHOD GetJSONString(nsACString & aJSONString) = 0;

  /* void writeToProfilingFile (); */
  NS_IMETHOD WriteToProfilingFile(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIVisualEventTracerLog, NS_IVISUALEVENTTRACERLOG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIVISUALEVENTTRACERLOG \
  NS_IMETHOD GetJSONString(nsACString & aJSONString); \
  NS_IMETHOD WriteToProfilingFile(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIVISUALEVENTTRACERLOG(_to) \
  NS_IMETHOD GetJSONString(nsACString & aJSONString) { return _to GetJSONString(aJSONString); } \
  NS_IMETHOD WriteToProfilingFile(void) { return _to WriteToProfilingFile(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIVISUALEVENTTRACERLOG(_to) \
  NS_IMETHOD GetJSONString(nsACString & aJSONString) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSONString(aJSONString); } \
  NS_IMETHOD WriteToProfilingFile(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->WriteToProfilingFile(); } 

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

/* void writeToProfilingFile (); */
NS_IMETHODIMP nsVisualEventTracerLog::WriteToProfilingFile()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIVisualEventTracer_h__ */
