/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIMemoryReporter.idl
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
class nsIDOMWindow; /* forward declaration */

class nsIRunnable; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIMemoryReporterCallback */
#define NS_IMEMORYREPORTERCALLBACK_IID_STR "3a61be3b-b93b-461a-a4f8-388214f558b1"

#define NS_IMEMORYREPORTERCALLBACK_IID \
  {0x3a61be3b, 0xb93b, 0x461a, \
    { 0xa4, 0xf8, 0x38, 0x82, 0x14, 0xf5, 0x58, 0xb1 }}

class NS_NO_VTABLE nsIMemoryReporterCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYREPORTERCALLBACK_IID)

  /* void callback (in ACString process, in AUTF8String path, in int32_t kind, in int32_t units, in int64_t amount, in AUTF8String description, in nsISupports data); */
  NS_IMETHOD Callback(const nsACString & process, const nsACString & path, int32_t kind, int32_t units, int64_t amount, const nsACString & description, nsISupports *data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryReporterCallback, NS_IMEMORYREPORTERCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYREPORTERCALLBACK \
  NS_IMETHOD Callback(const nsACString & process, const nsACString & path, int32_t kind, int32_t units, int64_t amount, const nsACString & description, nsISupports *data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYREPORTERCALLBACK(_to) \
  NS_IMETHOD Callback(const nsACString & process, const nsACString & path, int32_t kind, int32_t units, int64_t amount, const nsACString & description, nsISupports *data) { return _to Callback(process, path, kind, units, amount, description, data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYREPORTERCALLBACK(_to) \
  NS_IMETHOD Callback(const nsACString & process, const nsACString & path, int32_t kind, int32_t units, int64_t amount, const nsACString & description, nsISupports *data) { return !_to ? NS_ERROR_NULL_POINTER : _to->Callback(process, path, kind, units, amount, description, data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMemoryReporterCallback : public nsIMemoryReporterCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMEMORYREPORTERCALLBACK

  nsMemoryReporterCallback();

private:
  ~nsMemoryReporterCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMemoryReporterCallback, nsIMemoryReporterCallback)

nsMemoryReporterCallback::nsMemoryReporterCallback()
{
  /* member initializers and constructor code */
}

nsMemoryReporterCallback::~nsMemoryReporterCallback()
{
  /* destructor code */
}

/* void callback (in ACString process, in AUTF8String path, in int32_t kind, in int32_t units, in int64_t amount, in AUTF8String description, in nsISupports data); */
NS_IMETHODIMP nsMemoryReporterCallback::Callback(const nsACString & process, const nsACString & path, int32_t kind, int32_t units, int64_t amount, const nsACString & description, nsISupports *data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMemoryReporter */
#define NS_IMEMORYREPORTER_IID_STR "0884cd0f-5829-4381-979b-0f53904030ed"

#define NS_IMEMORYREPORTER_IID \
  {0x0884cd0f, 0x5829, 0x4381, \
    { 0x97, 0x9b, 0x0f, 0x53, 0x90, 0x40, 0x30, 0xed }}

class NS_NO_VTABLE nsIMemoryReporter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYREPORTER_IID)

  /* void collectReports (in nsIMemoryReporterCallback callback, in nsISupports data); */
  NS_IMETHOD CollectReports(nsIMemoryReporterCallback *callback, nsISupports *data) = 0;

  enum {
    KIND_NONHEAP = 0,
    KIND_HEAP = 1,
    KIND_OTHER = 2,
    UNITS_BYTES = 0,
    UNITS_COUNT = 1,
    UNITS_COUNT_CUMULATIVE = 2,
    UNITS_PERCENTAGE = 3
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryReporter, NS_IMEMORYREPORTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYREPORTER \
  NS_IMETHOD CollectReports(nsIMemoryReporterCallback *callback, nsISupports *data); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYREPORTER(_to) \
  NS_IMETHOD CollectReports(nsIMemoryReporterCallback *callback, nsISupports *data) { return _to CollectReports(callback, data); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYREPORTER(_to) \
  NS_IMETHOD CollectReports(nsIMemoryReporterCallback *callback, nsISupports *data) { return !_to ? NS_ERROR_NULL_POINTER : _to->CollectReports(callback, data); } \

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

/* void collectReports (in nsIMemoryReporterCallback callback, in nsISupports data); */
NS_IMETHODIMP nsMemoryReporter::CollectReports(nsIMemoryReporterCallback *callback, nsISupports *data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFinishReportingCallback */
#define NS_IFINISHREPORTINGCALLBACK_IID_STR "548b3909-c04d-4ca6-8466-b8bee3837457"

#define NS_IFINISHREPORTINGCALLBACK_IID \
  {0x548b3909, 0xc04d, 0x4ca6, \
    { 0x84, 0x66, 0xb8, 0xbe, 0xe3, 0x83, 0x74, 0x57 }}

class NS_NO_VTABLE nsIFinishReportingCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFINISHREPORTINGCALLBACK_IID)

  /* void callback (in nsISupports data); */
  NS_IMETHOD Callback(nsISupports *data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFinishReportingCallback, NS_IFINISHREPORTINGCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFINISHREPORTINGCALLBACK \
  NS_IMETHOD Callback(nsISupports *data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFINISHREPORTINGCALLBACK(_to) \
  NS_IMETHOD Callback(nsISupports *data) { return _to Callback(data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFINISHREPORTINGCALLBACK(_to) \
  NS_IMETHOD Callback(nsISupports *data) { return !_to ? NS_ERROR_NULL_POINTER : _to->Callback(data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFinishReportingCallback : public nsIFinishReportingCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFINISHREPORTINGCALLBACK

  nsFinishReportingCallback();

private:
  ~nsFinishReportingCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFinishReportingCallback, nsIFinishReportingCallback)

nsFinishReportingCallback::nsFinishReportingCallback()
{
  /* member initializers and constructor code */
}

nsFinishReportingCallback::~nsFinishReportingCallback()
{
  /* destructor code */
}

/* void callback (in nsISupports data); */
NS_IMETHODIMP nsFinishReportingCallback::Callback(nsISupports *data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIMemoryReporterManager */
#define NS_IMEMORYREPORTERMANAGER_IID_STR "b6e5ec8a-71d9-48db-8ae9-68b4c5bbf2c3"

#define NS_IMEMORYREPORTERMANAGER_IID \
  {0xb6e5ec8a, 0x71d9, 0x48db, \
    { 0x8a, 0xe9, 0x68, 0xb4, 0xc5, 0xbb, 0xf2, 0xc3 }}

class NS_NO_VTABLE nsIMemoryReporterManager : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMEMORYREPORTERMANAGER_IID)

  /* void init (); */
  NS_IMETHOD Init(void) = 0;

  /* void registerStrongReporter (in nsIMemoryReporter reporter); */
  NS_IMETHOD RegisterStrongReporter(nsIMemoryReporter *reporter) = 0;

  /* void registerWeakReporter (in nsIMemoryReporter reporter); */
  NS_IMETHOD RegisterWeakReporter(nsIMemoryReporter *reporter) = 0;

  /* void unregisterStrongReporter (in nsIMemoryReporter reporter); */
  NS_IMETHOD UnregisterStrongReporter(nsIMemoryReporter *reporter) = 0;

  /* void unregisterWeakReporter (in nsIMemoryReporter reporter); */
  NS_IMETHOD UnregisterWeakReporter(nsIMemoryReporter *reporter) = 0;

  /* void blockRegistrationAndHideExistingReporters (); */
  NS_IMETHOD BlockRegistrationAndHideExistingReporters(void) = 0;

  /* void unblockRegistrationAndRestoreOriginalReporters (); */
  NS_IMETHOD UnblockRegistrationAndRestoreOriginalReporters(void) = 0;

  /* void registerStrongReporterEvenIfBlocked (in nsIMemoryReporter aReporter); */
  NS_IMETHOD RegisterStrongReporterEvenIfBlocked(nsIMemoryReporter *aReporter) = 0;

  /* void getReports (in nsIMemoryReporterCallback handleReport, in nsISupports handleReportData, in nsIFinishReportingCallback finishReporting, in nsISupports finishReportingData); */
  NS_IMETHOD GetReports(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, nsIFinishReportingCallback *finishReporting, nsISupports *finishReportingData) = 0;

  /* [noscript] void getReportsExtended (in nsIMemoryReporterCallback handleReport, in nsISupports handleReportData, in nsIFinishReportingCallback finishReporting, in nsISupports finishReportingData, in boolean minimizeMemoryUsage, in AString DMDDumpIdent); */
  NS_IMETHOD GetReportsExtended(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, nsIFinishReportingCallback *finishReporting, nsISupports *finishReportingData, bool minimizeMemoryUsage, const nsAString & DMDDumpIdent) = 0;

  /* void getReportsForThisProcess (in nsIMemoryReporterCallback handleReport, in nsISupports handleReportData); */
  NS_IMETHOD GetReportsForThisProcess(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData) = 0;

  /* [noscript] void getReportsForThisProcessExtended (in nsIMemoryReporterCallback handleReport, in nsISupports handleReportData, in AString DMDDumpIdent); */
  NS_IMETHOD GetReportsForThisProcessExtended(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, const nsAString & DMDDumpIdent) = 0;

  /* readonly attribute int64_t explicit; */
  NS_IMETHOD GetExplicit(int64_t *aExplicit) = 0;

  /* readonly attribute int64_t vsize; */
  NS_IMETHOD GetVsize(int64_t *aVsize) = 0;

  /* readonly attribute int64_t vsizeMaxContiguous; */
  NS_IMETHOD GetVsizeMaxContiguous(int64_t *aVsizeMaxContiguous) = 0;

  /* readonly attribute int64_t resident; */
  NS_IMETHOD GetResident(int64_t *aResident) = 0;

  /* readonly attribute int64_t residentFast; */
  NS_IMETHOD GetResidentFast(int64_t *aResidentFast) = 0;

  /* readonly attribute int64_t heapAllocated; */
  NS_IMETHOD GetHeapAllocated(int64_t *aHeapAllocated) = 0;

  /* readonly attribute int64_t heapOverheadRatio; */
  NS_IMETHOD GetHeapOverheadRatio(int64_t *aHeapOverheadRatio) = 0;

  /* readonly attribute int64_t JSMainRuntimeGCHeap; */
  NS_IMETHOD GetJSMainRuntimeGCHeap(int64_t *aJSMainRuntimeGCHeap) = 0;

  /* readonly attribute int64_t JSMainRuntimeTemporaryPeak; */
  NS_IMETHOD GetJSMainRuntimeTemporaryPeak(int64_t *aJSMainRuntimeTemporaryPeak) = 0;

  /* readonly attribute int64_t JSMainRuntimeCompartmentsSystem; */
  NS_IMETHOD GetJSMainRuntimeCompartmentsSystem(int64_t *aJSMainRuntimeCompartmentsSystem) = 0;

  /* readonly attribute int64_t JSMainRuntimeCompartmentsUser; */
  NS_IMETHOD GetJSMainRuntimeCompartmentsUser(int64_t *aJSMainRuntimeCompartmentsUser) = 0;

  /* readonly attribute int64_t imagesContentUsedUncompressed; */
  NS_IMETHOD GetImagesContentUsedUncompressed(int64_t *aImagesContentUsedUncompressed) = 0;

  /* readonly attribute int64_t storageSQLite; */
  NS_IMETHOD GetStorageSQLite(int64_t *aStorageSQLite) = 0;

  /* readonly attribute int64_t lowMemoryEventsVirtual; */
  NS_IMETHOD GetLowMemoryEventsVirtual(int64_t *aLowMemoryEventsVirtual) = 0;

  /* readonly attribute int64_t lowMemoryEventsPhysical; */
  NS_IMETHOD GetLowMemoryEventsPhysical(int64_t *aLowMemoryEventsPhysical) = 0;

  /* readonly attribute int64_t ghostWindows; */
  NS_IMETHOD GetGhostWindows(int64_t *aGhostWindows) = 0;

  /* readonly attribute int64_t pageFaultsHard; */
  NS_IMETHOD GetPageFaultsHard(int64_t *aPageFaultsHard) = 0;

  /* [infallible] readonly attribute boolean hasMozMallocUsableSize; */
  NS_IMETHOD GetHasMozMallocUsableSize(bool *aHasMozMallocUsableSize) = 0;
  inline bool GetHasMozMallocUsableSize()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetHasMozMallocUsableSize(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* void minimizeMemoryUsage (in nsIRunnable callback); */
  NS_IMETHOD MinimizeMemoryUsage(nsIRunnable *callback) = 0;

  /* void sizeOfTab (in nsIDOMWindow window, out int64_t jsObjectsSize, out int64_t jsStringsSize, out int64_t jsOtherSize, out int64_t domSize, out int64_t styleSize, out int64_t otherSize, out int64_t totalSize, out double jsMilliseconds, out double nonJSMilliseconds); */
  NS_IMETHOD SizeOfTab(nsIDOMWindow *window, int64_t *jsObjectsSize, int64_t *jsStringsSize, int64_t *jsOtherSize, int64_t *domSize, int64_t *styleSize, int64_t *otherSize, int64_t *totalSize, double *jsMilliseconds, double *nonJSMilliseconds) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMemoryReporterManager, NS_IMEMORYREPORTERMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMEMORYREPORTERMANAGER \
  NS_IMETHOD Init(void); \
  NS_IMETHOD RegisterStrongReporter(nsIMemoryReporter *reporter); \
  NS_IMETHOD RegisterWeakReporter(nsIMemoryReporter *reporter); \
  NS_IMETHOD UnregisterStrongReporter(nsIMemoryReporter *reporter); \
  NS_IMETHOD UnregisterWeakReporter(nsIMemoryReporter *reporter); \
  NS_IMETHOD BlockRegistrationAndHideExistingReporters(void); \
  NS_IMETHOD UnblockRegistrationAndRestoreOriginalReporters(void); \
  NS_IMETHOD RegisterStrongReporterEvenIfBlocked(nsIMemoryReporter *aReporter); \
  NS_IMETHOD GetReports(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, nsIFinishReportingCallback *finishReporting, nsISupports *finishReportingData); \
  NS_IMETHOD GetReportsExtended(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, nsIFinishReportingCallback *finishReporting, nsISupports *finishReportingData, bool minimizeMemoryUsage, const nsAString & DMDDumpIdent); \
  NS_IMETHOD GetReportsForThisProcess(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData); \
  NS_IMETHOD GetReportsForThisProcessExtended(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, const nsAString & DMDDumpIdent); \
  NS_IMETHOD GetExplicit(int64_t *aExplicit); \
  NS_IMETHOD GetVsize(int64_t *aVsize); \
  NS_IMETHOD GetVsizeMaxContiguous(int64_t *aVsizeMaxContiguous); \
  NS_IMETHOD GetResident(int64_t *aResident); \
  NS_IMETHOD GetResidentFast(int64_t *aResidentFast); \
  NS_IMETHOD GetHeapAllocated(int64_t *aHeapAllocated); \
  NS_IMETHOD GetHeapOverheadRatio(int64_t *aHeapOverheadRatio); \
  NS_IMETHOD GetJSMainRuntimeGCHeap(int64_t *aJSMainRuntimeGCHeap); \
  NS_IMETHOD GetJSMainRuntimeTemporaryPeak(int64_t *aJSMainRuntimeTemporaryPeak); \
  NS_IMETHOD GetJSMainRuntimeCompartmentsSystem(int64_t *aJSMainRuntimeCompartmentsSystem); \
  NS_IMETHOD GetJSMainRuntimeCompartmentsUser(int64_t *aJSMainRuntimeCompartmentsUser); \
  NS_IMETHOD GetImagesContentUsedUncompressed(int64_t *aImagesContentUsedUncompressed); \
  NS_IMETHOD GetStorageSQLite(int64_t *aStorageSQLite); \
  NS_IMETHOD GetLowMemoryEventsVirtual(int64_t *aLowMemoryEventsVirtual); \
  NS_IMETHOD GetLowMemoryEventsPhysical(int64_t *aLowMemoryEventsPhysical); \
  NS_IMETHOD GetGhostWindows(int64_t *aGhostWindows); \
  NS_IMETHOD GetPageFaultsHard(int64_t *aPageFaultsHard); \
  NS_IMETHOD GetHasMozMallocUsableSize(bool *aHasMozMallocUsableSize); \
  NS_IMETHOD MinimizeMemoryUsage(nsIRunnable *callback); \
  NS_IMETHOD SizeOfTab(nsIDOMWindow *window, int64_t *jsObjectsSize, int64_t *jsStringsSize, int64_t *jsOtherSize, int64_t *domSize, int64_t *styleSize, int64_t *otherSize, int64_t *totalSize, double *jsMilliseconds, double *nonJSMilliseconds); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMEMORYREPORTERMANAGER(_to) \
  NS_IMETHOD Init(void) { return _to Init(); } \
  NS_IMETHOD RegisterStrongReporter(nsIMemoryReporter *reporter) { return _to RegisterStrongReporter(reporter); } \
  NS_IMETHOD RegisterWeakReporter(nsIMemoryReporter *reporter) { return _to RegisterWeakReporter(reporter); } \
  NS_IMETHOD UnregisterStrongReporter(nsIMemoryReporter *reporter) { return _to UnregisterStrongReporter(reporter); } \
  NS_IMETHOD UnregisterWeakReporter(nsIMemoryReporter *reporter) { return _to UnregisterWeakReporter(reporter); } \
  NS_IMETHOD BlockRegistrationAndHideExistingReporters(void) { return _to BlockRegistrationAndHideExistingReporters(); } \
  NS_IMETHOD UnblockRegistrationAndRestoreOriginalReporters(void) { return _to UnblockRegistrationAndRestoreOriginalReporters(); } \
  NS_IMETHOD RegisterStrongReporterEvenIfBlocked(nsIMemoryReporter *aReporter) { return _to RegisterStrongReporterEvenIfBlocked(aReporter); } \
  NS_IMETHOD GetReports(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, nsIFinishReportingCallback *finishReporting, nsISupports *finishReportingData) { return _to GetReports(handleReport, handleReportData, finishReporting, finishReportingData); } \
  NS_IMETHOD GetReportsExtended(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, nsIFinishReportingCallback *finishReporting, nsISupports *finishReportingData, bool minimizeMemoryUsage, const nsAString & DMDDumpIdent) { return _to GetReportsExtended(handleReport, handleReportData, finishReporting, finishReportingData, minimizeMemoryUsage, DMDDumpIdent); } \
  NS_IMETHOD GetReportsForThisProcess(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData) { return _to GetReportsForThisProcess(handleReport, handleReportData); } \
  NS_IMETHOD GetReportsForThisProcessExtended(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, const nsAString & DMDDumpIdent) { return _to GetReportsForThisProcessExtended(handleReport, handleReportData, DMDDumpIdent); } \
  NS_IMETHOD GetExplicit(int64_t *aExplicit) { return _to GetExplicit(aExplicit); } \
  NS_IMETHOD GetVsize(int64_t *aVsize) { return _to GetVsize(aVsize); } \
  NS_IMETHOD GetVsizeMaxContiguous(int64_t *aVsizeMaxContiguous) { return _to GetVsizeMaxContiguous(aVsizeMaxContiguous); } \
  NS_IMETHOD GetResident(int64_t *aResident) { return _to GetResident(aResident); } \
  NS_IMETHOD GetResidentFast(int64_t *aResidentFast) { return _to GetResidentFast(aResidentFast); } \
  NS_IMETHOD GetHeapAllocated(int64_t *aHeapAllocated) { return _to GetHeapAllocated(aHeapAllocated); } \
  NS_IMETHOD GetHeapOverheadRatio(int64_t *aHeapOverheadRatio) { return _to GetHeapOverheadRatio(aHeapOverheadRatio); } \
  NS_IMETHOD GetJSMainRuntimeGCHeap(int64_t *aJSMainRuntimeGCHeap) { return _to GetJSMainRuntimeGCHeap(aJSMainRuntimeGCHeap); } \
  NS_IMETHOD GetJSMainRuntimeTemporaryPeak(int64_t *aJSMainRuntimeTemporaryPeak) { return _to GetJSMainRuntimeTemporaryPeak(aJSMainRuntimeTemporaryPeak); } \
  NS_IMETHOD GetJSMainRuntimeCompartmentsSystem(int64_t *aJSMainRuntimeCompartmentsSystem) { return _to GetJSMainRuntimeCompartmentsSystem(aJSMainRuntimeCompartmentsSystem); } \
  NS_IMETHOD GetJSMainRuntimeCompartmentsUser(int64_t *aJSMainRuntimeCompartmentsUser) { return _to GetJSMainRuntimeCompartmentsUser(aJSMainRuntimeCompartmentsUser); } \
  NS_IMETHOD GetImagesContentUsedUncompressed(int64_t *aImagesContentUsedUncompressed) { return _to GetImagesContentUsedUncompressed(aImagesContentUsedUncompressed); } \
  NS_IMETHOD GetStorageSQLite(int64_t *aStorageSQLite) { return _to GetStorageSQLite(aStorageSQLite); } \
  NS_IMETHOD GetLowMemoryEventsVirtual(int64_t *aLowMemoryEventsVirtual) { return _to GetLowMemoryEventsVirtual(aLowMemoryEventsVirtual); } \
  NS_IMETHOD GetLowMemoryEventsPhysical(int64_t *aLowMemoryEventsPhysical) { return _to GetLowMemoryEventsPhysical(aLowMemoryEventsPhysical); } \
  NS_IMETHOD GetGhostWindows(int64_t *aGhostWindows) { return _to GetGhostWindows(aGhostWindows); } \
  NS_IMETHOD GetPageFaultsHard(int64_t *aPageFaultsHard) { return _to GetPageFaultsHard(aPageFaultsHard); } \
  NS_IMETHOD GetHasMozMallocUsableSize(bool *aHasMozMallocUsableSize) { return _to GetHasMozMallocUsableSize(aHasMozMallocUsableSize); } \
  NS_IMETHOD MinimizeMemoryUsage(nsIRunnable *callback) { return _to MinimizeMemoryUsage(callback); } \
  NS_IMETHOD SizeOfTab(nsIDOMWindow *window, int64_t *jsObjectsSize, int64_t *jsStringsSize, int64_t *jsOtherSize, int64_t *domSize, int64_t *styleSize, int64_t *otherSize, int64_t *totalSize, double *jsMilliseconds, double *nonJSMilliseconds) { return _to SizeOfTab(window, jsObjectsSize, jsStringsSize, jsOtherSize, domSize, styleSize, otherSize, totalSize, jsMilliseconds, nonJSMilliseconds); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMEMORYREPORTERMANAGER(_to) \
  NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_IMETHOD RegisterStrongReporter(nsIMemoryReporter *reporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterStrongReporter(reporter); } \
  NS_IMETHOD RegisterWeakReporter(nsIMemoryReporter *reporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterWeakReporter(reporter); } \
  NS_IMETHOD UnregisterStrongReporter(nsIMemoryReporter *reporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterStrongReporter(reporter); } \
  NS_IMETHOD UnregisterWeakReporter(nsIMemoryReporter *reporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterWeakReporter(reporter); } \
  NS_IMETHOD BlockRegistrationAndHideExistingReporters(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BlockRegistrationAndHideExistingReporters(); } \
  NS_IMETHOD UnblockRegistrationAndRestoreOriginalReporters(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnblockRegistrationAndRestoreOriginalReporters(); } \
  NS_IMETHOD RegisterStrongReporterEvenIfBlocked(nsIMemoryReporter *aReporter) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterStrongReporterEvenIfBlocked(aReporter); } \
  NS_IMETHOD GetReports(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, nsIFinishReportingCallback *finishReporting, nsISupports *finishReportingData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReports(handleReport, handleReportData, finishReporting, finishReportingData); } \
  NS_IMETHOD GetReportsExtended(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, nsIFinishReportingCallback *finishReporting, nsISupports *finishReportingData, bool minimizeMemoryUsage, const nsAString & DMDDumpIdent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReportsExtended(handleReport, handleReportData, finishReporting, finishReportingData, minimizeMemoryUsage, DMDDumpIdent); } \
  NS_IMETHOD GetReportsForThisProcess(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReportsForThisProcess(handleReport, handleReportData); } \
  NS_IMETHOD GetReportsForThisProcessExtended(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, const nsAString & DMDDumpIdent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReportsForThisProcessExtended(handleReport, handleReportData, DMDDumpIdent); } \
  NS_IMETHOD GetExplicit(int64_t *aExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExplicit(aExplicit); } \
  NS_IMETHOD GetVsize(int64_t *aVsize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVsize(aVsize); } \
  NS_IMETHOD GetVsizeMaxContiguous(int64_t *aVsizeMaxContiguous) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVsizeMaxContiguous(aVsizeMaxContiguous); } \
  NS_IMETHOD GetResident(int64_t *aResident) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResident(aResident); } \
  NS_IMETHOD GetResidentFast(int64_t *aResidentFast) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResidentFast(aResidentFast); } \
  NS_IMETHOD GetHeapAllocated(int64_t *aHeapAllocated) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeapAllocated(aHeapAllocated); } \
  NS_IMETHOD GetHeapOverheadRatio(int64_t *aHeapOverheadRatio) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeapOverheadRatio(aHeapOverheadRatio); } \
  NS_IMETHOD GetJSMainRuntimeGCHeap(int64_t *aJSMainRuntimeGCHeap) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSMainRuntimeGCHeap(aJSMainRuntimeGCHeap); } \
  NS_IMETHOD GetJSMainRuntimeTemporaryPeak(int64_t *aJSMainRuntimeTemporaryPeak) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSMainRuntimeTemporaryPeak(aJSMainRuntimeTemporaryPeak); } \
  NS_IMETHOD GetJSMainRuntimeCompartmentsSystem(int64_t *aJSMainRuntimeCompartmentsSystem) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSMainRuntimeCompartmentsSystem(aJSMainRuntimeCompartmentsSystem); } \
  NS_IMETHOD GetJSMainRuntimeCompartmentsUser(int64_t *aJSMainRuntimeCompartmentsUser) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJSMainRuntimeCompartmentsUser(aJSMainRuntimeCompartmentsUser); } \
  NS_IMETHOD GetImagesContentUsedUncompressed(int64_t *aImagesContentUsedUncompressed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImagesContentUsedUncompressed(aImagesContentUsedUncompressed); } \
  NS_IMETHOD GetStorageSQLite(int64_t *aStorageSQLite) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStorageSQLite(aStorageSQLite); } \
  NS_IMETHOD GetLowMemoryEventsVirtual(int64_t *aLowMemoryEventsVirtual) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLowMemoryEventsVirtual(aLowMemoryEventsVirtual); } \
  NS_IMETHOD GetLowMemoryEventsPhysical(int64_t *aLowMemoryEventsPhysical) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLowMemoryEventsPhysical(aLowMemoryEventsPhysical); } \
  NS_IMETHOD GetGhostWindows(int64_t *aGhostWindows) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGhostWindows(aGhostWindows); } \
  NS_IMETHOD GetPageFaultsHard(int64_t *aPageFaultsHard) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageFaultsHard(aPageFaultsHard); } \
  NS_IMETHOD GetHasMozMallocUsableSize(bool *aHasMozMallocUsableSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHasMozMallocUsableSize(aHasMozMallocUsableSize); } \
  NS_IMETHOD MinimizeMemoryUsage(nsIRunnable *callback) { return !_to ? NS_ERROR_NULL_POINTER : _to->MinimizeMemoryUsage(callback); } \
  NS_IMETHOD SizeOfTab(nsIDOMWindow *window, int64_t *jsObjectsSize, int64_t *jsStringsSize, int64_t *jsOtherSize, int64_t *domSize, int64_t *styleSize, int64_t *otherSize, int64_t *totalSize, double *jsMilliseconds, double *nonJSMilliseconds) { return !_to ? NS_ERROR_NULL_POINTER : _to->SizeOfTab(window, jsObjectsSize, jsStringsSize, jsOtherSize, domSize, styleSize, otherSize, totalSize, jsMilliseconds, nonJSMilliseconds); } 

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

/* void init (); */
NS_IMETHODIMP nsMemoryReporterManager::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerStrongReporter (in nsIMemoryReporter reporter); */
NS_IMETHODIMP nsMemoryReporterManager::RegisterStrongReporter(nsIMemoryReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerWeakReporter (in nsIMemoryReporter reporter); */
NS_IMETHODIMP nsMemoryReporterManager::RegisterWeakReporter(nsIMemoryReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterStrongReporter (in nsIMemoryReporter reporter); */
NS_IMETHODIMP nsMemoryReporterManager::UnregisterStrongReporter(nsIMemoryReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterWeakReporter (in nsIMemoryReporter reporter); */
NS_IMETHODIMP nsMemoryReporterManager::UnregisterWeakReporter(nsIMemoryReporter *reporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blockRegistrationAndHideExistingReporters (); */
NS_IMETHODIMP nsMemoryReporterManager::BlockRegistrationAndHideExistingReporters()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unblockRegistrationAndRestoreOriginalReporters (); */
NS_IMETHODIMP nsMemoryReporterManager::UnblockRegistrationAndRestoreOriginalReporters()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerStrongReporterEvenIfBlocked (in nsIMemoryReporter aReporter); */
NS_IMETHODIMP nsMemoryReporterManager::RegisterStrongReporterEvenIfBlocked(nsIMemoryReporter *aReporter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getReports (in nsIMemoryReporterCallback handleReport, in nsISupports handleReportData, in nsIFinishReportingCallback finishReporting, in nsISupports finishReportingData); */
NS_IMETHODIMP nsMemoryReporterManager::GetReports(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, nsIFinishReportingCallback *finishReporting, nsISupports *finishReportingData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getReportsExtended (in nsIMemoryReporterCallback handleReport, in nsISupports handleReportData, in nsIFinishReportingCallback finishReporting, in nsISupports finishReportingData, in boolean minimizeMemoryUsage, in AString DMDDumpIdent); */
NS_IMETHODIMP nsMemoryReporterManager::GetReportsExtended(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, nsIFinishReportingCallback *finishReporting, nsISupports *finishReportingData, bool minimizeMemoryUsage, const nsAString & DMDDumpIdent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getReportsForThisProcess (in nsIMemoryReporterCallback handleReport, in nsISupports handleReportData); */
NS_IMETHODIMP nsMemoryReporterManager::GetReportsForThisProcess(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getReportsForThisProcessExtended (in nsIMemoryReporterCallback handleReport, in nsISupports handleReportData, in AString DMDDumpIdent); */
NS_IMETHODIMP nsMemoryReporterManager::GetReportsForThisProcessExtended(nsIMemoryReporterCallback *handleReport, nsISupports *handleReportData, const nsAString & DMDDumpIdent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t explicit; */
NS_IMETHODIMP nsMemoryReporterManager::GetExplicit(int64_t *aExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t vsize; */
NS_IMETHODIMP nsMemoryReporterManager::GetVsize(int64_t *aVsize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t vsizeMaxContiguous; */
NS_IMETHODIMP nsMemoryReporterManager::GetVsizeMaxContiguous(int64_t *aVsizeMaxContiguous)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t resident; */
NS_IMETHODIMP nsMemoryReporterManager::GetResident(int64_t *aResident)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t residentFast; */
NS_IMETHODIMP nsMemoryReporterManager::GetResidentFast(int64_t *aResidentFast)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t heapAllocated; */
NS_IMETHODIMP nsMemoryReporterManager::GetHeapAllocated(int64_t *aHeapAllocated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t heapOverheadRatio; */
NS_IMETHODIMP nsMemoryReporterManager::GetHeapOverheadRatio(int64_t *aHeapOverheadRatio)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t JSMainRuntimeGCHeap; */
NS_IMETHODIMP nsMemoryReporterManager::GetJSMainRuntimeGCHeap(int64_t *aJSMainRuntimeGCHeap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t JSMainRuntimeTemporaryPeak; */
NS_IMETHODIMP nsMemoryReporterManager::GetJSMainRuntimeTemporaryPeak(int64_t *aJSMainRuntimeTemporaryPeak)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t JSMainRuntimeCompartmentsSystem; */
NS_IMETHODIMP nsMemoryReporterManager::GetJSMainRuntimeCompartmentsSystem(int64_t *aJSMainRuntimeCompartmentsSystem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t JSMainRuntimeCompartmentsUser; */
NS_IMETHODIMP nsMemoryReporterManager::GetJSMainRuntimeCompartmentsUser(int64_t *aJSMainRuntimeCompartmentsUser)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t imagesContentUsedUncompressed; */
NS_IMETHODIMP nsMemoryReporterManager::GetImagesContentUsedUncompressed(int64_t *aImagesContentUsedUncompressed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t storageSQLite; */
NS_IMETHODIMP nsMemoryReporterManager::GetStorageSQLite(int64_t *aStorageSQLite)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t lowMemoryEventsVirtual; */
NS_IMETHODIMP nsMemoryReporterManager::GetLowMemoryEventsVirtual(int64_t *aLowMemoryEventsVirtual)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t lowMemoryEventsPhysical; */
NS_IMETHODIMP nsMemoryReporterManager::GetLowMemoryEventsPhysical(int64_t *aLowMemoryEventsPhysical)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t ghostWindows; */
NS_IMETHODIMP nsMemoryReporterManager::GetGhostWindows(int64_t *aGhostWindows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int64_t pageFaultsHard; */
NS_IMETHODIMP nsMemoryReporterManager::GetPageFaultsHard(int64_t *aPageFaultsHard)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean hasMozMallocUsableSize; */
NS_IMETHODIMP nsMemoryReporterManager::GetHasMozMallocUsableSize(bool *aHasMozMallocUsableSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void minimizeMemoryUsage (in nsIRunnable callback); */
NS_IMETHODIMP nsMemoryReporterManager::MinimizeMemoryUsage(nsIRunnable *callback)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sizeOfTab (in nsIDOMWindow window, out int64_t jsObjectsSize, out int64_t jsStringsSize, out int64_t jsOtherSize, out int64_t domSize, out int64_t styleSize, out int64_t otherSize, out int64_t totalSize, out double jsMilliseconds, out double nonJSMilliseconds); */
NS_IMETHODIMP nsMemoryReporterManager::SizeOfTab(nsIDOMWindow *window, int64_t *jsObjectsSize, int64_t *jsStringsSize, int64_t *jsOtherSize, int64_t *domSize, int64_t *styleSize, int64_t *otherSize, int64_t *totalSize, double *jsMilliseconds, double *nonJSMilliseconds)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#include "js/TypeDecls.h"
#include "nsStringGlue.h"
#include "nsTArray.h"
#include "mozilla/Atomics.h"
class nsPIDOMWindow;
// nsIHandleReportCallback is a better name, but keep nsIMemoryReporterCallback
// around for backwards compatibility.
typedef nsIMemoryReporterCallback nsIHandleReportCallback;
namespace mozilla {
// Register a memory reporter.  The manager service will hold a strong
// reference to this reporter.
XPCOM_API(nsresult) RegisterStrongMemoryReporter(nsIMemoryReporter* aReporter);
// Register a memory reporter.  The manager service will hold a weak reference
// to this reporter.
XPCOM_API(nsresult) RegisterWeakMemoryReporter(nsIMemoryReporter* aReporter);
// Unregister a weak memory reporter.
XPCOM_API(nsresult) UnregisterWeakMemoryReporter(nsIMemoryReporter* aReporter);
// The memory reporter manager provides access to several distinguished
// amounts via attributes.  Some of these amounts are provided by Gecko
// components that cannot be accessed directly from XPCOM code.  So we provide
// the following functions for those components to be registered with the
// manager.
typedef int64_t (*InfallibleAmountFn)();
typedef nsresult (*FallibleAmountFn)(int64_t* aAmount);
#define DECL_REGISTER_DISTINGUISHED_AMOUNT(kind, name) \
    nsresult Register##name##DistinguishedAmount(kind##AmountFn aAmountFn);
#define DECL_UNREGISTER_DISTINGUISHED_AMOUNT(name) \
    nsresult Unregister##name##DistinguishedAmount();
DECL_REGISTER_DISTINGUISHED_AMOUNT(Infallible, JSMainRuntimeGCHeap)
DECL_REGISTER_DISTINGUISHED_AMOUNT(Infallible, JSMainRuntimeTemporaryPeak)
DECL_REGISTER_DISTINGUISHED_AMOUNT(Infallible, JSMainRuntimeCompartmentsSystem)
DECL_REGISTER_DISTINGUISHED_AMOUNT(Infallible, JSMainRuntimeCompartmentsUser)
DECL_REGISTER_DISTINGUISHED_AMOUNT(Infallible, ImagesContentUsedUncompressed)
DECL_REGISTER_DISTINGUISHED_AMOUNT(Infallible, StorageSQLite)
DECL_UNREGISTER_DISTINGUISHED_AMOUNT(StorageSQLite)
DECL_REGISTER_DISTINGUISHED_AMOUNT(Infallible, LowMemoryEventsVirtual)
DECL_REGISTER_DISTINGUISHED_AMOUNT(Infallible, LowMemoryEventsPhysical)
DECL_REGISTER_DISTINGUISHED_AMOUNT(Infallible, GhostWindows)
#undef DECL_REGISTER_DISTINGUISHED_AMOUNT
#undef DECL_UNREGISTER_DISTINGUISHED_AMOUNT
// Likewise for per-tab measurement.
typedef nsresult (*JSSizeOfTabFn)(JSObject* aObj,
                                  size_t* aJsObjectsSize,
                                  size_t* aJsStringSize,
                                  size_t* aJsPrivateSize,
                                  size_t* aJsOtherSize);
typedef nsresult (*NonJSSizeOfTabFn)(nsPIDOMWindow* aWindow,
                                     size_t* aDomSize,
                                     size_t* aStyleSize,
                                     size_t* aOtherSize);
nsresult RegisterJSSizeOfTab(JSSizeOfTabFn aSizeOfTabFn);
nsresult RegisterNonJSSizeOfTab(NonJSSizeOfTabFn aSizeOfTabFn);
}
#if defined(MOZ_DMD)
namespace mozilla {
namespace dmd {
// This runs all the memory reporters in the current process but does nothing
// with the results;  i.e. it does the minimal amount of work possible for DMD
// to do its thing.  It does nothing with child processes.
void RunReportersForThisProcess();
}
}
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
// that differ only in their name, instead of a single MallocSizeOf function.
// It's mostly to help with DMD integration, though it sometimes also helps
// with debugging and temporary ad hoc profiling.  The function name chosen
// doesn't matter greatly, but it's best to make it similar to the path used by
// the relevant memory reporter(s).
#define MOZ_DEFINE_MALLOC_SIZE_OF(fn)                                         \
  static size_t fn(const void* aPtr)                                          \
  {                                                                           \
      MOZ_REPORT(aPtr);                                                       \
      return moz_malloc_size_of(aPtr);                                        \
  }
// Functions generated by the next two macros should be used by wrapping
// allocators that report heap blocks as soon as they are allocated and
// unreport them as soon as they are freed.  Such allocators are used in cases
// where we have third-party code that we cannot modify.  The two functions
// must always be used in tandem.
#define MOZ_DEFINE_MALLOC_SIZE_OF_ON_ALLOC(fn)                                \
  static size_t fn(const void* aPtr)                                          \
  {                                                                           \
      MOZ_REPORT_ON_ALLOC(aPtr);                                              \
      return moz_malloc_size_of(aPtr);                                        \
  }
#define MOZ_DEFINE_MALLOC_SIZE_OF_ON_FREE(fn)                                 \
  static size_t fn(const void* aPtr)                                          \
  {                                                                           \
      return moz_malloc_size_of(aPtr);                                        \
  }
namespace mozilla {
// This CRTP class handles several details of wrapping allocators and should
// be preferred to manually counting with MOZ_DEFINE_MALLOC_SIZE_OF_ON_ALLOC
// and MOZ_DEFINE_MALLOC_SIZE_OF_ON_FREE.  The typical use is in a memory
// reporter for a particular third party library:
//
//   class MyMemoryReporter : public CountingAllocatorBase<MyMemoryReporter>
//   {
//     ...
//     NS_IMETHODIMP
//     CollectReports(nsIHandleReportCallback* aHandleReport, nsISupports* aData)
//     {
//        return MOZ_COLLECT_REPORTER(
//          "explicit/path/to/somewhere", KIND_HEAP, UNITS_BYTES,
//          MemoryAllocated(),
//          "A description of what we are reporting."
//     }
//   };
//
//   ...somewhere later in the code...
//   SetThirdPartyMemoryFunctions(MyMemoryReporter::CountingAlloc,
//                                MyMemoryReporter::CountingFree);
template<typename T>
class CountingAllocatorBase
{
public:
  CountingAllocatorBase()
  {
#ifdef DEBUG
    // There must be only one instance of this class, due to |sAmount| being
    // static.
    static bool hasRun = false;
    MOZ_ASSERT(!hasRun);
    hasRun = true;
#endif
  }
  static size_t
  MemoryAllocated()
  {
    return sAmount;
  }
  static void*
  CountingMalloc(size_t size)
  {
    void* p = malloc(size);
    sAmount += MallocSizeOfOnAlloc(p);
    return p;
  }
  static void*
  CountingCalloc(size_t nmemb, size_t size)
  {
    void* p = calloc(nmemb, size);
    sAmount += MallocSizeOfOnAlloc(p);
    return p;
  }
  static void*
  CountingRealloc(void* p, size_t size)
  {
    size_t oldsize = MallocSizeOfOnFree(p);
    void *pnew = realloc(p, size);
    if (pnew) {
      size_t newsize = MallocSizeOfOnAlloc(pnew);
      sAmount += newsize - oldsize;
    } else if (size == 0) {
      // We asked for a 0-sized (re)allocation of some existing pointer
      // and received NULL in return.  0-sized allocations are permitted
      // to either return NULL or to allocate a unique object per call (!).
      // For a malloc implementation that chooses the second strategy,
      // that allocation may fail (unlikely, but possible).
      //
      // Given a NULL return value and an allocation size of 0, then, we
      // don't know if that means the original pointer was freed or if
      // the allocation of the unique object failed.  If the original
      // pointer was freed, then we have nothing to do here.  If the
      // allocation of the unique object failed, the original pointer is
      // still valid and we ought to undo the decrement from above.
      // However, we have no way of knowing how the underlying realloc
      // implementation is behaving.  Assuming that the original pointer
      // was freed is the safest course of action.  We do, however, need
      // to note that we freed memory.
      sAmount -= oldsize;
    } else {
      // realloc failed.  The amount allocated hasn't changed.
    }
    return pnew;
  }
  static void
  CountingFree(void* p)
  {
    sAmount -= MallocSizeOfOnFree(p);
    free(p);
  }
private:
  // |sAmount| can be (implicitly) accessed by multiple threads, so it
  // must be thread-safe.
  static Atomic<size_t> sAmount;
  MOZ_DEFINE_MALLOC_SIZE_OF_ON_ALLOC(MallocSizeOfOnAlloc)
  MOZ_DEFINE_MALLOC_SIZE_OF_ON_FREE(MallocSizeOfOnFree)
};
}
// This macro assumes the presence of appropriate |aHandleReport| and |aData|
// variables.
#define MOZ_COLLECT_REPORT(path, kind, units, amount, description)            \
  aHandleReport->Callback(EmptyCString(), NS_LITERAL_CSTRING(path),           \
                          kind, units, amount,                                \
                          NS_LITERAL_CSTRING(description), aData)

#endif /* __gen_nsIMemoryReporter_h__ */
