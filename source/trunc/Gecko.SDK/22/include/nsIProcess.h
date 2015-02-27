/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/threads/nsIProcess.idl
 */

#ifndef __gen_nsIProcess_h__
#define __gen_nsIProcess_h__


#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIObserver; /* forward declaration */


/* starting interface:    nsIProcess */
#define NS_IPROCESS_IID_STR "609610de-9954-4a63-8a7c-346350a86403"

#define NS_IPROCESS_IID \
  {0x609610de, 0x9954, 0x4a63, \
    { 0x8a, 0x7c, 0x34, 0x63, 0x50, 0xa8, 0x64, 0x03 }}

class NS_NO_VTABLE nsIProcess : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROCESS_IID)

  /* void init (in nsIFile executable); */
  NS_IMETHOD Init(nsIFile *executable) = 0;

  /* void kill (); */
  NS_IMETHOD Kill(void) = 0;

  /* void run (in boolean blocking, [array, size_is (count)] in string args, in unsigned long count); */
  NS_IMETHOD Run(bool blocking, const char * *args, uint32_t count) = 0;

  /* void runAsync ([array, size_is (count)] in string args, in unsigned long count, [optional] in nsIObserver observer, [optional] in boolean holdWeak); */
  NS_IMETHOD RunAsync(const char * *args, uint32_t count, nsIObserver *observer, bool holdWeak) = 0;

  /* void runw (in boolean blocking, [array, size_is (count)] in wstring args, in unsigned long count); */
  NS_IMETHOD Runw(bool blocking, const PRUnichar * *args, uint32_t count) = 0;

  /* void runwAsync ([array, size_is (count)] in wstring args, in unsigned long count, [optional] in nsIObserver observer, [optional] in boolean holdWeak); */
  NS_IMETHOD RunwAsync(const PRUnichar * *args, uint32_t count, nsIObserver *observer, bool holdWeak) = 0;

  /* readonly attribute unsigned long pid; */
  NS_IMETHOD GetPid(uint32_t *aPid) = 0;

  /* readonly attribute long exitValue; */
  NS_IMETHOD GetExitValue(int32_t *aExitValue) = 0;

  /* readonly attribute boolean isRunning; */
  NS_IMETHOD GetIsRunning(bool *aIsRunning) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProcess, NS_IPROCESS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROCESS \
  NS_IMETHOD Init(nsIFile *executable); \
  NS_IMETHOD Kill(void); \
  NS_IMETHOD Run(bool blocking, const char * *args, uint32_t count); \
  NS_IMETHOD RunAsync(const char * *args, uint32_t count, nsIObserver *observer, bool holdWeak); \
  NS_IMETHOD Runw(bool blocking, const PRUnichar * *args, uint32_t count); \
  NS_IMETHOD RunwAsync(const PRUnichar * *args, uint32_t count, nsIObserver *observer, bool holdWeak); \
  NS_IMETHOD GetPid(uint32_t *aPid); \
  NS_IMETHOD GetExitValue(int32_t *aExitValue); \
  NS_IMETHOD GetIsRunning(bool *aIsRunning); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROCESS(_to) \
  NS_IMETHOD Init(nsIFile *executable) { return _to Init(executable); } \
  NS_IMETHOD Kill(void) { return _to Kill(); } \
  NS_IMETHOD Run(bool blocking, const char * *args, uint32_t count) { return _to Run(blocking, args, count); } \
  NS_IMETHOD RunAsync(const char * *args, uint32_t count, nsIObserver *observer, bool holdWeak) { return _to RunAsync(args, count, observer, holdWeak); } \
  NS_IMETHOD Runw(bool blocking, const PRUnichar * *args, uint32_t count) { return _to Runw(blocking, args, count); } \
  NS_IMETHOD RunwAsync(const PRUnichar * *args, uint32_t count, nsIObserver *observer, bool holdWeak) { return _to RunwAsync(args, count, observer, holdWeak); } \
  NS_IMETHOD GetPid(uint32_t *aPid) { return _to GetPid(aPid); } \
  NS_IMETHOD GetExitValue(int32_t *aExitValue) { return _to GetExitValue(aExitValue); } \
  NS_IMETHOD GetIsRunning(bool *aIsRunning) { return _to GetIsRunning(aIsRunning); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROCESS(_to) \
  NS_IMETHOD Init(nsIFile *executable) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(executable); } \
  NS_IMETHOD Kill(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Kill(); } \
  NS_IMETHOD Run(bool blocking, const char * *args, uint32_t count) { return !_to ? NS_ERROR_NULL_POINTER : _to->Run(blocking, args, count); } \
  NS_IMETHOD RunAsync(const char * *args, uint32_t count, nsIObserver *observer, bool holdWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunAsync(args, count, observer, holdWeak); } \
  NS_IMETHOD Runw(bool blocking, const PRUnichar * *args, uint32_t count) { return !_to ? NS_ERROR_NULL_POINTER : _to->Runw(blocking, args, count); } \
  NS_IMETHOD RunwAsync(const PRUnichar * *args, uint32_t count, nsIObserver *observer, bool holdWeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->RunwAsync(args, count, observer, holdWeak); } \
  NS_IMETHOD GetPid(uint32_t *aPid) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPid(aPid); } \
  NS_IMETHOD GetExitValue(int32_t *aExitValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExitValue(aExitValue); } \
  NS_IMETHOD GetIsRunning(bool *aIsRunning) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsRunning(aIsRunning); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProcess : public nsIProcess
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROCESS

  nsProcess();

private:
  ~nsProcess();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProcess, nsIProcess)

nsProcess::nsProcess()
{
  /* member initializers and constructor code */
}

nsProcess::~nsProcess()
{
  /* destructor code */
}

/* void init (in nsIFile executable); */
NS_IMETHODIMP nsProcess::Init(nsIFile *executable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void kill (); */
NS_IMETHODIMP nsProcess::Kill()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void run (in boolean blocking, [array, size_is (count)] in string args, in unsigned long count); */
NS_IMETHODIMP nsProcess::Run(bool blocking, const char * *args, uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runAsync ([array, size_is (count)] in string args, in unsigned long count, [optional] in nsIObserver observer, [optional] in boolean holdWeak); */
NS_IMETHODIMP nsProcess::RunAsync(const char * *args, uint32_t count, nsIObserver *observer, bool holdWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runw (in boolean blocking, [array, size_is (count)] in wstring args, in unsigned long count); */
NS_IMETHODIMP nsProcess::Runw(bool blocking, const PRUnichar * *args, uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void runwAsync ([array, size_is (count)] in wstring args, in unsigned long count, [optional] in nsIObserver observer, [optional] in boolean holdWeak); */
NS_IMETHODIMP nsProcess::RunwAsync(const PRUnichar * *args, uint32_t count, nsIObserver *observer, bool holdWeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long pid; */
NS_IMETHODIMP nsProcess::GetPid(uint32_t *aPid)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long exitValue; */
NS_IMETHODIMP nsProcess::GetExitValue(int32_t *aExitValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isRunning; */
NS_IMETHODIMP nsProcess::GetIsRunning(bool *aIsRunning)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_PROCESS_CONTRACTID "@mozilla.org/process/util;1"

#endif /* __gen_nsIProcess_h__ */
