/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/base/nsIMemoryReporter.idl
 */

#ifndef __gen_nsIMemoryReporter_h__
#define __gen_nsIMemoryReporter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISimpleEnumerator; /* forward declaration */

class nsIRunnable; /* forward declaration */

class nsICancelableRunnable; /* forward declaration */


/* starting interface:    nsIMemoryReporter */
#define NS_IMEMORYREPORTER_IID_STR "b2c39f65-1799-4b92-a806-ab3cf6af3cfa"

#define NS_IMEMORYREPORTER_IID \
  {0xb2c39f65, 0x1799, 0x4b92, \
    { 0xa8, 0x06, 0xab, 0x3c, 0xf6, 0xaf, 0x3c, 0xfa }}

class NS_NO_VTABLE nsIMemoryReporter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYREPORTER_IID)

  /* readonly attribute ACString process; */
  NS_IMETHOD GetProcess(nsACString & aProcess) = 0;

  /* readonly attribute AUTF8String path; */
  NS_IMETHOD GetPath(nsACString & aPath) = 0;

  enum {
    KIND_NONHEAP = 0,
    KIND_HEAP = 1,
    KIND_OTHER = 2
  };

  /* readonly attribute int32_t kind; */
  NS_IMETHOD GetKind(int32_t *aKind) = 0;

  enum {
    UNITS_BYTES = 0,
    UNITS_COUNT = 1,
    UNITS_COUNT_CUMULATIVE = 2,
    UNITS_PERCENTAGE = 3
  };

  /* readonly attribute int32_t units; */
  NS_IMETHOD GetUnits(int32_t *aUnits) = 0;

  /* readonly attribute int64_t amount; */
  NS_IMETHOD GetAmount(int64_t *aAmount) = 0;

  /* readonly attribute AUTF8String description; */
  NS_IMETHOD GetDescription(nsACString & aDescription) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryReporter, NS_IMEMORYREPORTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYREPORTER \
  NS_IMETHOD GetProcess(nsACString & aProcess); \
  NS_IMETHOD GetPath(nsACString & aPath); \
  NS_IMETHOD GetKind(int32_t *aKind); \
  NS_IMETHOD GetUnits(int32_t *aUnits); \
  NS_IMETHOD GetAmount(int64_t *aAmount); \
  NS_IMETHOD GetDescription(nsACString & aDescription); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYREPORTER(_to) \
  NS_IMETHOD GetProcess(nsACString & aProcess) { return _to GetProcess(aProcess); } \
  NS_IMETHOD GetPath(nsACString & aPath) { return _to GetPath(aPath); } \
  NS_IMETHOD GetKind(int32_t *aKind) { return _to GetKind(aKind); } \
  NS_IMETHOD GetUnits(int32_t *aUnits) { return _to GetUnits(aUnits); } \
  NS_IMETHOD GetAmount(int64_t *aAmount) { return _to GetAmount(aAmount); } \
  NS_IMETHOD GetDescription(nsACString & aDescription) { return _to GetDescription(aDescription); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYREPORTER(_to) \
  NS_IMETHOD GetProcess(nsACString & aProcess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProcess(aProcess); } \
  NS_IMETHOD GetPath(nsACString & aPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPath(aPath); } \
  NS_IMETHOD GetKind(int32_t *aKind) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKind(aKind); } \
  NS_IMETHOD GetUnits(int32_t *aUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnits(aUnits); } \
  NS_IMETHOD GetAmount(int64_t *aAmount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAmount(aAmount); } \
  NS_IMETHOD GetDescription(nsACString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMemoryReporter : public nsIMemoryReporter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEMORYREPORTER

  nsMemoryReporter();

private:
  ~nsMemoryReporter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMemoryReporter, nsIMemoryReporter)

nsMemoryReporter::nsMemoryReporter()
{
  /* member initializers and constructor code */
}

nsMemoryReporter::~nsMemoryReporter()
{
  /* destructor code */
}

/* readonly attribute ACString process; */
NS_IMETHODIMP nsMemoryReporter::GetProcess(nsACString & aProcess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String path; */
NS_IMETHODIMP nsMemoryReporter::GetPath(nsACString & aPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t kind; */
NS_IMETHODIMP nsMemoryReporter::GetKind(int32_t *aKind)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t units; */
NS_IMETHODIMP nsMemoryReporter::GetUnits(int32_t *aUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t amount; */
NS_IMETHODIMP nsMemoryReporter::GetAmount(int64_t *aAmount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String description; */
NS_IMETHODIMP nsMemoryReporter::GetDescription(nsACString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMemoryMultiReporterCallback */
#define NS_IMEMORYMULTIREPORTERCALLBACK_IID_STR "5b15f3fa-ba15-443c-8337-7770f5f0ce5d"

#define NS_IMEMORYMULTIREPORTERCALLBACK_IID \
  {0x5b15f3fa, 0xba15, 0x443c, \
    { 0x83, 0x37, 0x77, 0x70, 0xf5, 0xf0, 0xce, 0x5d }}

class NS_NO_VTABLE nsIMemoryMultiReporterCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYMULTIREPORTERCALLBACK_IID)

  /* void callback (in ACString process, in AUTF8String path, in int32_t kind, in int32_t units, in int64_t amount, in AUTF8String description, in nsISupports closure); */
  NS_IMETHOD Callback(const nsACString & process, const nsACString & path, int32_t kind, int32_t units, int64_t amount, const nsACString & description, nsISupports *closure) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryMultiReporterCallback, NS_IMEMORYMULTIREPORTERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYMULTIREPORTERCALLBACK \
  NS_IMETHOD Callback(const nsACString & process, const nsACString & path, int32_t kind, int32_t units, int64_t amount, const nsACString & description, nsISupports *closure); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYMULTIREPORTERCALLBACK(_to) \
  NS_IMETHOD Callback(const nsACString & process, const nsACString & path, int32_t kind, int32_t units, int64_t amount, const nsACString & description, nsISupports *closure) { return _to Callback(process, path, kind, units, amount, description, closure); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYMULTIREPORTERCALLBACK(_to) \
  NS_IMETHOD Callback(const nsACString & process, const nsACString & path, int32_t kind, int32_t units, int64_t amount, const nsACString & description, nsISupports *closure) { return !_to ? NS_ERROR_NULL_POINTER : _to->Callback(process, path, kind, units, amount, description, closure); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMemoryMultiReporterCallback : public nsIMemoryMultiReporterCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEMORYMULTIREPORTERCALLBACK

  nsMemoryMultiReporterCallback();

private:
  ~nsMemoryMultiReporterCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMemoryMultiReporterCallback, nsIMemoryMultiReporterCallback)

nsMemoryMultiReporterCallback::nsMemoryMultiReporterCallback()
{
  /* member initializers and constructor code */
}

nsMemoryMultiReporterCallback::~nsMemoryMultiReporterCallback()
{
  /* destructor code */
}

/* void callback (in ACString process, in AUTF8String path, in int32_t kind, in int32_t units, in int64_t amount, in AUTF8String description, in nsISupports closure); */
NS_IMETHODIMP nsMemoryMultiReporterCallback::Callback(const nsACString & process, const nsACString & path, int32_t kind, int32_t units, int64_t amount, const nsACString & description, nsISupports *closure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMemoryMultiReporter */
#define NS_IMEMORYMULTIREPORTER_IID_STR "61d498d5-b460-4398-a8ea-7f75208534b4"

#define NS_IMEMORYMULTIREPORTER_IID \
  {0x61d498d5, 0xb460, 0x4398, \
    { 0xa8, 0xea, 0x7f, 0x75, 0x20, 0x85, 0x34, 0xb4 }}

class NS_NO_VTABLE nsIMemoryMultiReporter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYMULTIREPORTER_IID)

  /* readonly attribute ACString name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* void collectReports (in nsIMemoryMultiReporterCallback callback, in nsISupports closure); */
  NS_IMETHOD CollectReports(nsIMemoryMultiReporterCallback *callback, nsISupports *closure) = 0;

  /* readonly attribute int64_t explicitNonHeap; */
  NS_IMETHOD GetExplicitNonHeap(int64_t *aExplicitNonHeap) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryMultiReporter, NS_IMEMORYMULTIREPORTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYMULTIREPORTER \
  NS_IMETHOD GetName(nsACString & aName); \
  NS_IMETHOD CollectReports(nsIMemoryMultiReporterCallback *callback, nsISupports *closure); \
  NS_IMETHOD GetExplicitNonHeap(int64_t *aExplicitNonHeap); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYMULTIREPORTER(_to) \
  NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_IMETHOD CollectReports(nsIMemoryMultiReporterCallback *callback, nsISupports *closure) { return _to CollectReports(callback, closure); } \
  NS_IMETHOD GetExplicitNonHeap(int64_t *aExplicitNonHeap) { return _to GetExplicitNonHeap(aExplicitNonHeap); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYMULTIREPORTER(_to) \
  NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD CollectReports(nsIMemoryMultiReporterCallback *callback, nsISupports *closure) { return !_to ? NS_ERROR_NULL_POINTER : _to->CollectReports(callback, closure); } \
  NS_IMETHOD GetExplicitNonHeap(int64_t *aExplicitNonHeap) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExplicitNonHeap(aExplicitNonHeap); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMemoryMultiReporter : public nsIMemoryMultiReporter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEMORYMULTIREPORTER

  nsMemoryMultiReporter();

private:
  ~nsMemoryMultiReporter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMemoryMultiReporter, nsIMemoryMultiReporter)

nsMemoryMultiReporter::nsMemoryMultiReporter()
{
  /* member initializers and constructor code */
}

nsMemoryMultiReporter::~nsMemoryMultiReporter()
{
  /* destructor code */
}

/* readonly attribute ACString name; */
NS_IMETHODIMP nsMemoryMultiReporter::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void collectReports (in nsIMemoryMultiReporterCallback callback, in nsISupports closure); */
NS_IMETHODIMP nsMemoryMultiReporter::CollectReports(nsIMemoryMultiReporterCallback *callback, nsISupports *closure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t explicitNonHeap; */
NS_IMETHODIMP nsMemoryMultiReporter::GetExplicitNonHeap(int64_t *aExplicitNonHeap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMemoryReporterManager */
#define NS_IMEMORYREPORTERMANAGER_IID_STR "0baaa958-3112-4952-b557-2a0c57eabb8f"

#define NS_IMEMORYREPORTERMANAGER_IID \
  {0x0baaa958, 0x3112, 0x4952, \
    { 0xb5, 0x57, 0x2a, 0x0c, 0x57, 0xea, 0xbb, 0x8f }}

class NS_NO_VTABLE nsIMemoryReporterManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYREPORTERMANAGER_IID)

  /* nsISimpleEnumerator enumerateReporters (); */
  NS_IMETHOD EnumerateReporters(nsISimpleEnumerator * *_retval) = 0;

  /* nsISimpleEnumerator enumerateMultiReporters (); */
  NS_IMETHOD EnumerateMultiReporters(nsISimpleEnumerator * *_retval) = 0;

  /* void registerReporter (in nsIMemoryReporter reporter); */
  NS_IMETHOD RegisterReporter(nsIMemoryReporter *reporter) = 0;

  /* void registerMultiReporter (in nsIMemoryMultiReporter reporter); */
  NS_IMETHOD RegisterMultiReporter(nsIMemoryMultiReporter *reporter) = 0;

  /* void unregisterReporter (in nsIMemoryReporter reporter); */
  NS_IMETHOD UnregisterReporter(nsIMemoryReporter *reporter) = 0;

  /* void unregisterMultiReporter (in nsIMemoryMultiReporter reporter); */
  NS_IMETHOD UnregisterMultiReporter(nsIMemoryMultiReporter *reporter) = 0;

  /* void init (); */
  NS_IMETHOD Init(void) = 0;

  /* readonly attribute int64_t resident; */
  NS_IMETHOD GetResident(int64_t *aResident) = 0;

  /* readonly attribute int64_t explicit; */
  NS_IMETHOD GetExplicit(int64_t *aExplicit) = 0;

  /* [infallible] readonly attribute boolean hasMozMallocUsableSize; */
  NS_IMETHOD GetHasMozMallocUsableSize(bool *aHasMozMallocUsableSize) = 0;
  inline bool GetHasMozMallocUsableSize()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetHasMozMallocUsableSize(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* nsICancelableRunnable minimizeMemoryUsage (in nsIRunnable callback); */
  NS_IMETHOD MinimizeMemoryUsage(nsIRunnable *callback, nsICancelableRunnable * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryReporterManager, NS_IMEMORYREPORTERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYREPORTERMANAGER \
  NS_IMETHOD EnumerateReporters(nsISimpleEnumerator * *_retval); \
  NS_IMETHOD EnumerateMultiReporters(nsISimpleEnumerator * *_retval); \
  NS_IMETHOD RegisterReporter(nsIMemoryReporter *reporter); \
  NS_IMETHOD RegisterMultiReporter(nsIMemoryMultiReporter *reporter); \
  NS_IMETHOD UnregisterReporter(nsIMemoryReporter *reporter); \
  NS_IMETHOD UnregisterMultiReporter(nsIMemoryMultiReporter *reporter); \
  NS_IMETHOD Init(void); \
  NS_IMETHOD GetResident(int64_t *aResident); \
  NS_IMETHOD GetExplicit(int64_t *aExplicit); \
  NS_IMETHOD GetHasMozMallocUsableSize(bool *aHasMozMallocUsableSize); \
  NS_IMETHOD MinimizeMemoryUsage(nsIRunnable *callback, nsICancelableRunnable * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYREPORTERMANAGER(_to) \
  NS_IMETHOD EnumerateReporters(nsISimpleEnumerator * *_retval) { return _to EnumerateReporters(_retval); } \
  NS_IMETHOD EnumerateMultiReporters(nsISimpleEnumerator * *_retval) { return _to EnumerateMultiReporters(_retval); } \
  NS_IMETHOD RegisterReporter(nsIMemoryReporter *reporter) { return _to RegisterReporter(reporter); } \
  NS_IMETHOD RegisterMultiReporter(nsIMemoryMultiReporter *reporter) { return _to RegisterMultiReporter(reporter); } \
  NS_IMETHOD UnregisterReporter(nsIMemoryReporter *reporter) { return _to UnregisterReporter(reporter); } \
  NS_IMETHOD UnregisterMultiReporter(nsIMemoryMultiReporter *reporter) { return _to UnregisterMultiReporter(reporter); } \
  NS_IMETHOD Init(void) { return _to Init(); } \
  NS_IMETHOD GetResident(int64_t *aResident) { return _to GetResident(aResident); } \
  NS_IMETHOD GetExplicit(int64_t *aExplicit) { return _to GetExplicit(aExplicit); } \
  NS_IMETHOD GetHasMozMallocUsableSize(bool *aHasMozMallocUsableSize) { return _to GetHasMozMallocUsableSize(aHasMozMallocUsableSize); } \
  NS_IMETHOD MinimizeMemoryUsage(nsIRunnable *callback, nsICancelableRunnable * *_retval) { return _to MinimizeMemoryUsage(callback, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYREPORTERMANAGER(_to) \
  NS_IMETHOD EnumerateReporters(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateReporters(_retval); } \
  NS_IMETHOD EnumerateMultiReporters(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateMultiReporters(_retval); } \
  NS_IMETHOD RegisterReporter(nsIMemoryReporter *reporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterReporter(reporter); } \
  NS_IMETHOD RegisterMultiReporter(nsIMemoryMultiReporter *reporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterMultiReporter(reporter); } \
  NS_IMETHOD UnregisterReporter(nsIMemoryReporter *reporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterReporter(reporter); } \
  NS_IMETHOD UnregisterMultiReporter(nsIMemoryMultiReporter *reporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterMultiReporter(reporter); } \
  NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_IMETHOD GetResident(int64_t *aResident) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResident(aResident); } \
  NS_IMETHOD GetExplicit(int64_t *aExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExplicit(aExplicit); } \
  NS_IMETHOD GetHasMozMallocUsableSize(bool *aHasMozMallocUsableSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasMozMallocUsableSize(aHasMozMallocUsableSize); } \
  NS_IMETHOD MinimizeMemoryUsage(nsIRunnable *callback, nsICancelableRunnable * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MinimizeMemoryUsage(callback, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMemoryReporterManager : public nsIMemoryReporterManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEMORYREPORTERMANAGER

  nsMemoryReporterManager();

private:
  ~nsMemoryReporterManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMemoryReporterManager, nsIMemoryReporterManager)

nsMemoryReporterManager::nsMemoryReporterManager()
{
  /* member initializers and constructor code */
}

nsMemoryReporterManager::~nsMemoryReporterManager()
{
  /* destructor code */
}

/* nsISimpleEnumerator enumerateReporters (); */
NS_IMETHODIMP nsMemoryReporterManager::EnumerateReporters(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator enumerateMultiReporters (); */
NS_IMETHODIMP nsMemoryReporterManager::EnumerateMultiReporters(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerReporter (in nsIMemoryReporter reporter); */
NS_IMETHODIMP nsMemoryReporterManager::RegisterReporter(nsIMemoryReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerMultiReporter (in nsIMemoryMultiReporter reporter); */
NS_IMETHODIMP nsMemoryReporterManager::RegisterMultiReporter(nsIMemoryMultiReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterReporter (in nsIMemoryReporter reporter); */
NS_IMETHODIMP nsMemoryReporterManager::UnregisterReporter(nsIMemoryReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterMultiReporter (in nsIMemoryMultiReporter reporter); */
NS_IMETHODIMP nsMemoryReporterManager::UnregisterMultiReporter(nsIMemoryMultiReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (); */
NS_IMETHODIMP nsMemoryReporterManager::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t resident; */
NS_IMETHODIMP nsMemoryReporterManager::GetResident(int64_t *aResident)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t explicit; */
NS_IMETHODIMP nsMemoryReporterManager::GetExplicit(int64_t *aExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean hasMozMallocUsableSize; */
NS_IMETHODIMP nsMemoryReporterManager::GetHasMozMallocUsableSize(bool *aHasMozMallocUsableSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICancelableRunnable minimizeMemoryUsage (in nsIRunnable callback); */
NS_IMETHODIMP nsMemoryReporterManager::MinimizeMemoryUsage(nsIRunnable *callback, nsICancelableRunnable * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#include "nsStringGlue.h"
// The NS_*MEMORY_REPORTER_IMPLEMENT* macros are the deprecated short-cut way
// of defining memory reporters.   You should instead subclass the
// MemoryReporterBase class below.
// Note that this defaults 'process' to "", which is usually what's desired.
#define NS_MEMORY_REPORTER_IMPLEMENT_HELPER(_classname, _path, _kind, _units, _amountFunction, _desc, _ts) \
    class MemoryReporter_##_classname MOZ_FINAL : public nsIMemoryReporter {                  \
    public:                                                                                   \
      NS_DECL_ISUPPORTS                                                                       \
      NS_IMETHOD GetProcess(nsACString &process) { process.Truncate(); return NS_OK; }        \
      NS_IMETHOD GetPath(nsACString &memoryPath) { memoryPath.AssignLiteral(_path); return NS_OK; }  \
      NS_IMETHOD GetKind(int *kind) { *kind = _kind; return NS_OK; }                          \
      NS_IMETHOD GetUnits(int *units) { *units = _units; return NS_OK; }                      \
      NS_IMETHOD GetAmount(int64_t *amount) { *amount = _amountFunction(); return NS_OK; }    \
      NS_IMETHOD GetDescription(nsACString &desc) { desc.AssignLiteral(_desc); return NS_OK; }       \
    };                                                                                        \
    NS_IMPL##_ts##ISUPPORTS1(MemoryReporter_##_classname, nsIMemoryReporter)
// The only difference between this and NS_MEMORY_REPORTER_IMPLEMENT_HELPER
// is that the function used to implement GetAmount is fallible.
#define NS_FALLIBLE_MEMORY_REPORTER_IMPLEMENT_HELPER(_classname, _path, _kind, _units, _amountFunction, _desc, _ts) \
    class MemoryReporter_##_classname MOZ_FINAL : public nsIMemoryReporter {                  \
    public:                                                                                   \
      NS_DECL_ISUPPORTS                                                                       \
      NS_IMETHOD GetProcess(nsACString &process) { process.Truncate(); return NS_OK; }        \
      NS_IMETHOD GetPath(nsACString &memoryPath) { memoryPath.AssignLiteral(_path); return NS_OK; }  \
      NS_IMETHOD GetKind(int32_t *kind) { *kind = _kind; return NS_OK; }                      \
      NS_IMETHOD GetUnits(int32_t *units) { *units = _units; return NS_OK; }                  \
      NS_IMETHOD GetAmount(int64_t *amount) { return _amountFunction(amount); }               \
      NS_IMETHOD GetDescription(nsACString &desc) { desc.AssignLiteral(_desc); return NS_OK; }\
    };                                                                                        \
    NS_IMPL##_ts##ISUPPORTS1(MemoryReporter_##_classname, nsIMemoryReporter)
#define NS_MEMORY_REPORTER_IMPLEMENT(_c, _p, _k, _u, _a, _d) \
        NS_MEMORY_REPORTER_IMPLEMENT_HELPER(_c, _p, _k, _u, _a, _d, _)
#define NS_THREADSAFE_MEMORY_REPORTER_IMPLEMENT(_c, _p, _k, _u, _a, _d) \
        NS_MEMORY_REPORTER_IMPLEMENT_HELPER(_c, _p, _k, _u, _a, _d, _THREADSAFE_)
#define NS_FALLIBLE_MEMORY_REPORTER_IMPLEMENT(_c, _p, _k, _u, _a, _d) \
        NS_FALLIBLE_MEMORY_REPORTER_IMPLEMENT_HELPER(_c, _p, _k, _u, _a, _d, _)
#define NS_FALLIBLE_THREADSAFE_MEMORY_REPORTER_IMPLEMENT(_c, _p, _k, _u, _a, _d) \
        NS_FALLIBLE_MEMORY_REPORTER_IMPLEMENT_HELPER(_c, _p, _k, _u, _a, _d, _THREADSAFE_)
#define NS_MEMORY_REPORTER_NAME(_classname)  MemoryReporter_##_classname
// Note that the memory reporters are held in an nsCOMArray, which means
// that individual reporters should be referenced with |nsIMemoryReporter *|
// instead of nsCOMPtr<nsIMemoryReporter>.
nsresult NS_RegisterMemoryReporter(nsIMemoryReporter *reporter);
nsresult NS_RegisterMemoryMultiReporter(nsIMemoryMultiReporter *reporter);
nsresult NS_UnregisterMemoryReporter(nsIMemoryReporter *reporter);
nsresult NS_UnregisterMemoryMultiReporter(nsIMemoryMultiReporter *reporter);
#if defined(MOZ_DMD)
namespace mozilla {
namespace dmd {
// This runs all the memory reporters but does nothing with the results;  i.e.
// it does the minimal amount of work possible for DMD to do its thing.
void RunReporters();
}
}
#endif  // defined(MOZ_DMD)
#if defined(MOZ_DMD)
#if !defined(MOZ_MEMORY)
#error "MOZ_DMD requires MOZ_MEMORY"
#endif
#include "DMD.h"
#define MOZ_REPORT(ptr)          mozilla::dmd::Report(ptr)
#define MOZ_REPORT_ON_ALLOC(ptr) mozilla::dmd::ReportOnAlloc(ptr)
#else
#define MOZ_REPORT(ptr)
#define MOZ_REPORT_ON_ALLOC(ptr)
#endif  // defined(MOZ_DMD)
// Functions generated via this macro should be used by all traversal-based
// memory reporters.  Such functions return |moz_malloc_size_of(ptr)|;  this
// will always be zero on some obscure platforms.
//
// You might be wondering why we have a macro that creates multiple functions
// that differ only in their name, instead of a single
// MemoryReporterMallocSizeOf function.  It's mostly to help with DMD
// integration, though it sometimes also helps with debugging and temporary ad
// hoc profiling.  The function name chosen doesn't matter greatly, but it's
// best to make it similar to the path used by the relevant memory
// reporter(s).
#define NS_MEMORY_REPORTER_MALLOC_SIZEOF_FUN(fn)                              \
  static size_t fn(const void *ptr)                                           \
  {                                                                           \
      MOZ_REPORT(ptr);                                                        \
      return moz_malloc_size_of(ptr);                                         \
  }
// Functions generated by the next two macros should be used by wrapping
// allocators that report heap blocks as soon as they are allocated and
// unreport them as soon as they are freed.  Such allocators are used in cases
// where we have third-party code that we cannot modify.  The two functions
// must always be used in tandem.
#define NS_MEMORY_REPORTER_MALLOC_SIZEOF_ON_ALLOC_FUN(fn)                     \
  static size_t fn(const void *ptr)                                           \
  {                                                                           \
      MOZ_REPORT_ON_ALLOC(ptr);                                               \
      return moz_malloc_size_of(ptr);                                         \
  }
#define NS_MEMORY_REPORTER_MALLOC_SIZEOF_ON_FREE_FUN(fn)                      \
  static size_t fn(const void *ptr)                                           \
  {                                                                           \
      return moz_malloc_size_of(ptr);                                         \
  }
namespace mozilla {
// The following base class reduces the amount of boilerplate code required for
// memory reporters.  You just need to provide the following.
// - The constant values: path, kind, units, and description.  They are passed
//   to the MemoryReporterBase constructor.
// - A (private) Amount() or (public) GetAmount() method.  It can use the 
//   MallocSizeOf method if necessary.  Use Amount() if the reporter is
//   infallible, and GetAmount() otherwise.  (If you fail to provide one or the
//   other, you'll get assertion failures when the memory reporter runs.)
//
// The class name of subclasses should match the path, minus the "explicit"
// (if present), and with "Reporter" at the end.  For example:
// - "explicit/dom/xyzzy"     --> DOMXyzzyReporter
// - "js-compartments/system" --> JSCompartmentsSystemReporter
//
class MemoryReporterBase : public nsIMemoryReporter
{
public:
  MemoryReporterBase(const char* aPath, int32_t aKind, int32_t aUnits,
                     const char* aDescription)
    : mPath(aPath)
    , mKind(aKind)
    , mUnits(aUnits)
    , mDescription(aDescription)
  {}
  virtual ~MemoryReporterBase() {}
  NS_DECL_ISUPPORTS
  NS_IMETHOD GetProcess(nsACString& aProcess)
  {
    aProcess.Truncate();
    return NS_OK;
  }
  NS_IMETHOD GetPath(nsACString& aPath)
  {
    aPath.Assign(mPath);
    return NS_OK;
  }
  NS_IMETHOD GetKind(int32_t* aKind)
  {
    *aKind = mKind;
    return NS_OK;
  }
  NS_IMETHOD GetUnits(int32_t* aUnits)
  {
    *aUnits = mUnits;
    return NS_OK;
  }
  NS_IMETHOD GetAmount(int64_t* aAmount)
  {
    *aAmount = Amount();
    return NS_OK;
  }
  NS_IMETHOD GetDescription(nsACString& aDescription)
  {
    aDescription.Assign(mDescription);
    return NS_OK;
  }
protected:
  virtual int64_t Amount()
  {
    // We only reach here if neither GetAmount() nor Amount() was overridden.
    MOZ_ASSERT(false);
    return 0;
  }
  NS_MEMORY_REPORTER_MALLOC_SIZEOF_FUN(MallocSizeOf)
  const nsCString mPath;
  const int32_t   mKind;
  const int32_t   mUnits;
  const nsCString mDescription;
};
} // namespace mozilla

#endif /* __gen_nsIMemoryReporter_h__ */
