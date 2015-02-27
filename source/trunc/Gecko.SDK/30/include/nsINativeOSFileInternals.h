/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsINativeOSFileInternals.idl
 */

#ifndef __gen_nsINativeOSFileInternals_h__
#define __gen_nsINativeOSFileInternals_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINativeOSFileResult */
#define NS_INATIVEOSFILERESULT_IID_STR "08b4cf29-3d65-4e79-b522-a694c322ed07"

#define NS_INATIVEOSFILERESULT_IID \
  {0x08b4cf29, 0x3d65, 0x4e79, \
    { 0xb5, 0x22, 0xa6, 0x94, 0xc3, 0x22, 0xed, 0x07 }}

class NS_NO_VTABLE nsINativeOSFileResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INATIVEOSFILERESULT_IID)

  /* [implicit_jscontext] readonly attribute jsval result; */
  NS_IMETHOD GetResult(JSContext* cx, JS::MutableHandleValue aResult) = 0;

  /* readonly attribute double dispatchDurationMS; */
  NS_IMETHOD GetDispatchDurationMS(double *aDispatchDurationMS) = 0;

  /* readonly attribute double executionDurationMS; */
  NS_IMETHOD GetExecutionDurationMS(double *aExecutionDurationMS) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINativeOSFileResult, NS_INATIVEOSFILERESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINATIVEOSFILERESULT \
  NS_IMETHOD GetResult(JSContext* cx, JS::MutableHandleValue aResult); \
  NS_IMETHOD GetDispatchDurationMS(double *aDispatchDurationMS); \
  NS_IMETHOD GetExecutionDurationMS(double *aExecutionDurationMS); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINATIVEOSFILERESULT(_to) \
  NS_IMETHOD GetResult(JSContext* cx, JS::MutableHandleValue aResult) { return _to GetResult(cx, aResult); } \
  NS_IMETHOD GetDispatchDurationMS(double *aDispatchDurationMS) { return _to GetDispatchDurationMS(aDispatchDurationMS); } \
  NS_IMETHOD GetExecutionDurationMS(double *aExecutionDurationMS) { return _to GetExecutionDurationMS(aExecutionDurationMS); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINATIVEOSFILERESULT(_to) \
  NS_IMETHOD GetResult(JSContext* cx, JS::MutableHandleValue aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(cx, aResult); } \
  NS_IMETHOD GetDispatchDurationMS(double *aDispatchDurationMS) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDispatchDurationMS(aDispatchDurationMS); } \
  NS_IMETHOD GetExecutionDurationMS(double *aExecutionDurationMS) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExecutionDurationMS(aExecutionDurationMS); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNativeOSFileResult : public nsINativeOSFileResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINATIVEOSFILERESULT

  nsNativeOSFileResult();

private:
  ~nsNativeOSFileResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNativeOSFileResult, nsINativeOSFileResult)

nsNativeOSFileResult::nsNativeOSFileResult()
{
  /* member initializers and constructor code */
}

nsNativeOSFileResult::~nsNativeOSFileResult()
{
  /* destructor code */
}

/* [implicit_jscontext] readonly attribute jsval result; */
NS_IMETHODIMP nsNativeOSFileResult::GetResult(JSContext* cx, JS::MutableHandleValue aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double dispatchDurationMS; */
NS_IMETHODIMP nsNativeOSFileResult::GetDispatchDurationMS(double *aDispatchDurationMS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double executionDurationMS; */
NS_IMETHODIMP nsNativeOSFileResult::GetExecutionDurationMS(double *aExecutionDurationMS)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINativeOSFileSuccessCallback */
#define NS_INATIVEOSFILESUCCESSCALLBACK_IID_STR "2c1922ca-ca1b-4099-8b61-ec23cff49412"

#define NS_INATIVEOSFILESUCCESSCALLBACK_IID \
  {0x2c1922ca, 0xca1b, 0x4099, \
    { 0x8b, 0x61, 0xec, 0x23, 0xcf, 0xf4, 0x94, 0x12 }}

class NS_NO_VTABLE nsINativeOSFileSuccessCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INATIVEOSFILESUCCESSCALLBACK_IID)

  /* void complete (in nsINativeOSFileResult result); */
  NS_IMETHOD Complete(nsINativeOSFileResult *result) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINativeOSFileSuccessCallback, NS_INATIVEOSFILESUCCESSCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINATIVEOSFILESUCCESSCALLBACK \
  NS_IMETHOD Complete(nsINativeOSFileResult *result); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINATIVEOSFILESUCCESSCALLBACK(_to) \
  NS_IMETHOD Complete(nsINativeOSFileResult *result) { return _to Complete(result); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINATIVEOSFILESUCCESSCALLBACK(_to) \
  NS_IMETHOD Complete(nsINativeOSFileResult *result) { return !_to ? NS_ERROR_NULL_POINTER : _to->Complete(result); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNativeOSFileSuccessCallback : public nsINativeOSFileSuccessCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINATIVEOSFILESUCCESSCALLBACK

  nsNativeOSFileSuccessCallback();

private:
  ~nsNativeOSFileSuccessCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNativeOSFileSuccessCallback, nsINativeOSFileSuccessCallback)

nsNativeOSFileSuccessCallback::nsNativeOSFileSuccessCallback()
{
  /* member initializers and constructor code */
}

nsNativeOSFileSuccessCallback::~nsNativeOSFileSuccessCallback()
{
  /* destructor code */
}

/* void complete (in nsINativeOSFileResult result); */
NS_IMETHODIMP nsNativeOSFileSuccessCallback::Complete(nsINativeOSFileResult *result)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINativeOSFileErrorCallback */
#define NS_INATIVEOSFILEERRORCALLBACK_IID_STR "f612e0fc-6736-4d24-aa50-fd661b3b40b6"

#define NS_INATIVEOSFILEERRORCALLBACK_IID \
  {0xf612e0fc, 0x6736, 0x4d24, \
    { 0xaa, 0x50, 0xfd, 0x66, 0x1b, 0x3b, 0x40, 0xb6 }}

class NS_NO_VTABLE nsINativeOSFileErrorCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INATIVEOSFILEERRORCALLBACK_IID)

  /* void complete (in ACString operation, in long OSstatus); */
  NS_IMETHOD Complete(const nsACString & operation, int32_t OSstatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINativeOSFileErrorCallback, NS_INATIVEOSFILEERRORCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINATIVEOSFILEERRORCALLBACK \
  NS_IMETHOD Complete(const nsACString & operation, int32_t OSstatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINATIVEOSFILEERRORCALLBACK(_to) \
  NS_IMETHOD Complete(const nsACString & operation, int32_t OSstatus) { return _to Complete(operation, OSstatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINATIVEOSFILEERRORCALLBACK(_to) \
  NS_IMETHOD Complete(const nsACString & operation, int32_t OSstatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->Complete(operation, OSstatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNativeOSFileErrorCallback : public nsINativeOSFileErrorCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINATIVEOSFILEERRORCALLBACK

  nsNativeOSFileErrorCallback();

private:
  ~nsNativeOSFileErrorCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNativeOSFileErrorCallback, nsINativeOSFileErrorCallback)

nsNativeOSFileErrorCallback::nsNativeOSFileErrorCallback()
{
  /* member initializers and constructor code */
}

nsNativeOSFileErrorCallback::~nsNativeOSFileErrorCallback()
{
  /* destructor code */
}

/* void complete (in ACString operation, in long OSstatus); */
NS_IMETHODIMP nsNativeOSFileErrorCallback::Complete(const nsACString & operation, int32_t OSstatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsINativeOSFileInternalsService */
#define NS_INATIVEOSFILEINTERNALSSERVICE_IID_STR "913362ad-1526-4623-9e6b-a2eb08afbbb9"

#define NS_INATIVEOSFILEINTERNALSSERVICE_IID \
  {0x913362ad, 0x1526, 0x4623, \
    { 0x9e, 0x6b, 0xa2, 0xeb, 0x08, 0xaf, 0xbb, 0xb9 }}

class NS_NO_VTABLE nsINativeOSFileInternalsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INATIVEOSFILEINTERNALSSERVICE_IID)

  /* [implicit_jscontext] void read (in AString path, in jsval options, in nsINativeOSFileSuccessCallback onSuccess, in nsINativeOSFileErrorCallback onError); */
  NS_IMETHOD Read(const nsAString & path, JS::HandleValue options, nsINativeOSFileSuccessCallback *onSuccess, nsINativeOSFileErrorCallback *onError, JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINativeOSFileInternalsService, NS_INATIVEOSFILEINTERNALSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINATIVEOSFILEINTERNALSSERVICE \
  NS_IMETHOD Read(const nsAString & path, JS::HandleValue options, nsINativeOSFileSuccessCallback *onSuccess, nsINativeOSFileErrorCallback *onError, JSContext* cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINATIVEOSFILEINTERNALSSERVICE(_to) \
  NS_IMETHOD Read(const nsAString & path, JS::HandleValue options, nsINativeOSFileSuccessCallback *onSuccess, nsINativeOSFileErrorCallback *onError, JSContext* cx) { return _to Read(path, options, onSuccess, onError, cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINATIVEOSFILEINTERNALSSERVICE(_to) \
  NS_IMETHOD Read(const nsAString & path, JS::HandleValue options, nsINativeOSFileSuccessCallback *onSuccess, nsINativeOSFileErrorCallback *onError, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->Read(path, options, onSuccess, onError, cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNativeOSFileInternalsService : public nsINativeOSFileInternalsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINATIVEOSFILEINTERNALSSERVICE

  nsNativeOSFileInternalsService();

private:
  ~nsNativeOSFileInternalsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNativeOSFileInternalsService, nsINativeOSFileInternalsService)

nsNativeOSFileInternalsService::nsNativeOSFileInternalsService()
{
  /* member initializers and constructor code */
}

nsNativeOSFileInternalsService::~nsNativeOSFileInternalsService()
{
  /* destructor code */
}

/* [implicit_jscontext] void read (in AString path, in jsval options, in nsINativeOSFileSuccessCallback onSuccess, in nsINativeOSFileErrorCallback onError); */
NS_IMETHODIMP nsNativeOSFileInternalsService::Read(const nsAString & path, JS::HandleValue options, nsINativeOSFileSuccessCallback *onSuccess, nsINativeOSFileErrorCallback *onError, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NATIVE_OSFILE_INTERNALS_SERVICE_CID {0x63A69303,0x8A64,0x45A9,{0x84, 0x8C, 0xD4, 0xE2, 0x79, 0x27, 0x94, 0xE6}}
#define NATIVE_OSFILE_INTERNALS_SERVICE_CONTRACTID "@mozilla.org/toolkit/osfile/native-internals;1"

#endif /* __gen_nsINativeOSFileInternals_h__ */
