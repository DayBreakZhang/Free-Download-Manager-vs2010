/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMemoryInfoDumper.idl
 */

#ifndef __gen_nsIMemoryInfoDumper_h__
#define __gen_nsIMemoryInfoDumper_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIFinishDumpingCallback */
#define NS_IFINISHDUMPINGCALLBACK_IID_STR "2dea18fc-fbfa-4bf7-ad45-0efaf5495f5e"

#define NS_IFINISHDUMPINGCALLBACK_IID \
  {0x2dea18fc, 0xfbfa, 0x4bf7, \
    { 0xad, 0x45, 0x0e, 0xfa, 0xf5, 0x49, 0x5f, 0x5e }}

class NS_NO_VTABLE nsIFinishDumpingCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFINISHDUMPINGCALLBACK_IID)

  /* void callback (in nsISupports data); */
  NS_IMETHOD Callback(nsISupports *data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFinishDumpingCallback, NS_IFINISHDUMPINGCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFINISHDUMPINGCALLBACK \
  NS_IMETHOD Callback(nsISupports *data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFINISHDUMPINGCALLBACK(_to) \
  NS_IMETHOD Callback(nsISupports *data) { return _to Callback(data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFINISHDUMPINGCALLBACK(_to) \
  NS_IMETHOD Callback(nsISupports *data) { return !_to ? NS_ERROR_NULL_POINTER : _to->Callback(data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFinishDumpingCallback : public nsIFinishDumpingCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFINISHDUMPINGCALLBACK

  nsFinishDumpingCallback();

private:
  ~nsFinishDumpingCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFinishDumpingCallback, nsIFinishDumpingCallback)

nsFinishDumpingCallback::nsFinishDumpingCallback()
{
  /* member initializers and constructor code */
}

nsFinishDumpingCallback::~nsFinishDumpingCallback()
{
  /* destructor code */
}

/* void callback (in nsISupports data); */
NS_IMETHODIMP nsFinishDumpingCallback::Callback(nsISupports *data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMemoryInfoDumper */
#define NS_IMEMORYINFODUMPER_IID_STR "815bf31b-f5bd-425d-85c3-4657a7a91dad"

#define NS_IMEMORYINFODUMPER_IID \
  {0x815bf31b, 0xf5bd, 0x425d, \
    { 0x85, 0xc3, 0x46, 0x57, 0xa7, 0xa9, 0x1d, 0xad }}

class NS_NO_VTABLE nsIMemoryInfoDumper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYINFODUMPER_IID)

  /* void dumpMemoryReportsToNamedFile (in AString aFilename, in nsIFinishDumpingCallback aFinishDumping, in nsISupports aFinishDumpingData); */
  NS_IMETHOD DumpMemoryReportsToNamedFile(const nsAString & aFilename, nsIFinishDumpingCallback *aFinishDumping, nsISupports *aFinishDumpingData) = 0;

  /* void dumpMemoryInfoToTempDir (in AString aIdentifier, in bool aMinimizeMemoryUsage); */
  NS_IMETHOD DumpMemoryInfoToTempDir(const nsAString & aIdentifier, bool aMinimizeMemoryUsage) = 0;

  /* void dumpGCAndCCLogsToFile (in AString aIdentifier, in bool aDumpAllTraces, in bool aDumpChildProcesses, out AString aGCLogPath, out AString aCCLogPath); */
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpAllTraces, bool aDumpChildProcesses, nsAString & aGCLogPath, nsAString & aCCLogPath) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryInfoDumper, NS_IMEMORYINFODUMPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYINFODUMPER \
  NS_IMETHOD DumpMemoryReportsToNamedFile(const nsAString & aFilename, nsIFinishDumpingCallback *aFinishDumping, nsISupports *aFinishDumpingData); \
  NS_IMETHOD DumpMemoryInfoToTempDir(const nsAString & aIdentifier, bool aMinimizeMemoryUsage); \
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpAllTraces, bool aDumpChildProcesses, nsAString & aGCLogPath, nsAString & aCCLogPath); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYINFODUMPER(_to) \
  NS_IMETHOD DumpMemoryReportsToNamedFile(const nsAString & aFilename, nsIFinishDumpingCallback *aFinishDumping, nsISupports *aFinishDumpingData) { return _to DumpMemoryReportsToNamedFile(aFilename, aFinishDumping, aFinishDumpingData); } \
  NS_IMETHOD DumpMemoryInfoToTempDir(const nsAString & aIdentifier, bool aMinimizeMemoryUsage) { return _to DumpMemoryInfoToTempDir(aIdentifier, aMinimizeMemoryUsage); } \
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpAllTraces, bool aDumpChildProcesses, nsAString & aGCLogPath, nsAString & aCCLogPath) { return _to DumpGCAndCCLogsToFile(aIdentifier, aDumpAllTraces, aDumpChildProcesses, aGCLogPath, aCCLogPath); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYINFODUMPER(_to) \
  NS_IMETHOD DumpMemoryReportsToNamedFile(const nsAString & aFilename, nsIFinishDumpingCallback *aFinishDumping, nsISupports *aFinishDumpingData) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpMemoryReportsToNamedFile(aFilename, aFinishDumping, aFinishDumpingData); } \
  NS_IMETHOD DumpMemoryInfoToTempDir(const nsAString & aIdentifier, bool aMinimizeMemoryUsage) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpMemoryInfoToTempDir(aIdentifier, aMinimizeMemoryUsage); } \
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpAllTraces, bool aDumpChildProcesses, nsAString & aGCLogPath, nsAString & aCCLogPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpGCAndCCLogsToFile(aIdentifier, aDumpAllTraces, aDumpChildProcesses, aGCLogPath, aCCLogPath); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMemoryInfoDumper : public nsIMemoryInfoDumper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEMORYINFODUMPER

  nsMemoryInfoDumper();

private:
  ~nsMemoryInfoDumper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMemoryInfoDumper, nsIMemoryInfoDumper)

nsMemoryInfoDumper::nsMemoryInfoDumper()
{
  /* member initializers and constructor code */
}

nsMemoryInfoDumper::~nsMemoryInfoDumper()
{
  /* destructor code */
}

/* void dumpMemoryReportsToNamedFile (in AString aFilename, in nsIFinishDumpingCallback aFinishDumping, in nsISupports aFinishDumpingData); */
NS_IMETHODIMP nsMemoryInfoDumper::DumpMemoryReportsToNamedFile(const nsAString & aFilename, nsIFinishDumpingCallback *aFinishDumping, nsISupports *aFinishDumpingData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpMemoryInfoToTempDir (in AString aIdentifier, in bool aMinimizeMemoryUsage); */
NS_IMETHODIMP nsMemoryInfoDumper::DumpMemoryInfoToTempDir(const nsAString & aIdentifier, bool aMinimizeMemoryUsage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpGCAndCCLogsToFile (in AString aIdentifier, in bool aDumpAllTraces, in bool aDumpChildProcesses, out AString aGCLogPath, out AString aCCLogPath); */
NS_IMETHODIMP nsMemoryInfoDumper::DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpAllTraces, bool aDumpChildProcesses, nsAString & aGCLogPath, nsAString & aCCLogPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMemoryInfoDumper_h__ */
