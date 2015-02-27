/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/base/nsIMemoryInfoDumper.idl
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

/* starting interface:    nsIMemoryInfoDumper */
#define NS_IMEMORYINFODUMPER_IID_STR "ede09623-d793-4355-9682-b3adfe307126"

#define NS_IMEMORYINFODUMPER_IID \
  {0xede09623, 0xd793, 0x4355, \
    { 0x96, 0x82, 0xb3, 0xad, 0xfe, 0x30, 0x71, 0x26 }}

class NS_NO_VTABLE nsIMemoryInfoDumper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYINFODUMPER_IID)

  /* void dumpMemoryReportsToFile (in AString aIdentifier, in bool aMinimizeMemoryUsage, in bool aDumpChildProcesses); */
  NS_IMETHOD DumpMemoryReportsToFile(const nsAString & aIdentifier, bool aMinimizeMemoryUsage, bool aDumpChildProcesses) = 0;

  /* void dumpGCAndCCLogsToFile (in AString aIdentifier, in bool aDumpChildProcesses); */
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpChildProcesses) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryInfoDumper, NS_IMEMORYINFODUMPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYINFODUMPER \
  NS_IMETHOD DumpMemoryReportsToFile(const nsAString & aIdentifier, bool aMinimizeMemoryUsage, bool aDumpChildProcesses); \
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpChildProcesses); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYINFODUMPER(_to) \
  NS_IMETHOD DumpMemoryReportsToFile(const nsAString & aIdentifier, bool aMinimizeMemoryUsage, bool aDumpChildProcesses) { return _to DumpMemoryReportsToFile(aIdentifier, aMinimizeMemoryUsage, aDumpChildProcesses); } \
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpChildProcesses) { return _to DumpGCAndCCLogsToFile(aIdentifier, aDumpChildProcesses); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYINFODUMPER(_to) \
  NS_IMETHOD DumpMemoryReportsToFile(const nsAString & aIdentifier, bool aMinimizeMemoryUsage, bool aDumpChildProcesses) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpMemoryReportsToFile(aIdentifier, aMinimizeMemoryUsage, aDumpChildProcesses); } \
  NS_IMETHOD DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpChildProcesses) { return !_to ? NS_ERROR_NULL_POINTER : _to->DumpGCAndCCLogsToFile(aIdentifier, aDumpChildProcesses); } 

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

/* void dumpMemoryReportsToFile (in AString aIdentifier, in bool aMinimizeMemoryUsage, in bool aDumpChildProcesses); */
NS_IMETHODIMP nsMemoryInfoDumper::DumpMemoryReportsToFile(const nsAString & aIdentifier, bool aMinimizeMemoryUsage, bool aDumpChildProcesses)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dumpGCAndCCLogsToFile (in AString aIdentifier, in bool aDumpChildProcesses); */
NS_IMETHODIMP nsMemoryInfoDumper::DumpGCAndCCLogsToFile(const nsAString & aIdentifier, bool aDumpChildProcesses)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMemoryInfoDumper_h__ */
