/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICycleCollectorListener.idl
 */

#ifndef __gen_nsICycleCollectorListener_h__
#define __gen_nsICycleCollectorListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICycleCollectorHandler */
#define NS_ICYCLECOLLECTORHANDLER_IID_STR "39a8f80e-7eee-4141-b9ef-6e2a7d6e466d"

#define NS_ICYCLECOLLECTORHANDLER_IID \
  {0x39a8f80e, 0x7eee, 0x4141, \
    { 0xb9, 0xef, 0x6e, 0x2a, 0x7d, 0x6e, 0x46, 0x6d }}

class NS_NO_VTABLE nsICycleCollectorHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICYCLECOLLECTORHANDLER_IID)

  /* void noteRefCountedObject (in ACString aAddress, in unsigned long aRefCount, in ACString aObjectDescription); */
  NS_IMETHOD NoteRefCountedObject(const nsACString & aAddress, uint32_t aRefCount, const nsACString & aObjectDescription) = 0;

  /* void noteGCedObject (in ACString aAddress, in boolean aMarked, in ACString aObjectDescription, in ACString aCompartmentAddress); */
  NS_IMETHOD NoteGCedObject(const nsACString & aAddress, bool aMarked, const nsACString & aObjectDescription, const nsACString & aCompartmentAddress) = 0;

  /* void noteEdge (in ACString aFromAddress, in ACString aToAddress, in ACString aEdgeName); */
  NS_IMETHOD NoteEdge(const nsACString & aFromAddress, const nsACString & aToAddress, const nsACString & aEdgeName) = 0;

  /* void describeRoot (in ACString aAddress, in unsigned long aKnownEdges); */
  NS_IMETHOD DescribeRoot(const nsACString & aAddress, uint32_t aKnownEdges) = 0;

  /* void describeGarbage (in ACString aAddress); */
  NS_IMETHOD DescribeGarbage(const nsACString & aAddress) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICycleCollectorHandler, NS_ICYCLECOLLECTORHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICYCLECOLLECTORHANDLER \
  NS_IMETHOD NoteRefCountedObject(const nsACString & aAddress, uint32_t aRefCount, const nsACString & aObjectDescription); \
  NS_IMETHOD NoteGCedObject(const nsACString & aAddress, bool aMarked, const nsACString & aObjectDescription, const nsACString & aCompartmentAddress); \
  NS_IMETHOD NoteEdge(const nsACString & aFromAddress, const nsACString & aToAddress, const nsACString & aEdgeName); \
  NS_IMETHOD DescribeRoot(const nsACString & aAddress, uint32_t aKnownEdges); \
  NS_IMETHOD DescribeGarbage(const nsACString & aAddress); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICYCLECOLLECTORHANDLER(_to) \
  NS_IMETHOD NoteRefCountedObject(const nsACString & aAddress, uint32_t aRefCount, const nsACString & aObjectDescription) { return _to NoteRefCountedObject(aAddress, aRefCount, aObjectDescription); } \
  NS_IMETHOD NoteGCedObject(const nsACString & aAddress, bool aMarked, const nsACString & aObjectDescription, const nsACString & aCompartmentAddress) { return _to NoteGCedObject(aAddress, aMarked, aObjectDescription, aCompartmentAddress); } \
  NS_IMETHOD NoteEdge(const nsACString & aFromAddress, const nsACString & aToAddress, const nsACString & aEdgeName) { return _to NoteEdge(aFromAddress, aToAddress, aEdgeName); } \
  NS_IMETHOD DescribeRoot(const nsACString & aAddress, uint32_t aKnownEdges) { return _to DescribeRoot(aAddress, aKnownEdges); } \
  NS_IMETHOD DescribeGarbage(const nsACString & aAddress) { return _to DescribeGarbage(aAddress); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICYCLECOLLECTORHANDLER(_to) \
  NS_IMETHOD NoteRefCountedObject(const nsACString & aAddress, uint32_t aRefCount, const nsACString & aObjectDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteRefCountedObject(aAddress, aRefCount, aObjectDescription); } \
  NS_IMETHOD NoteGCedObject(const nsACString & aAddress, bool aMarked, const nsACString & aObjectDescription, const nsACString & aCompartmentAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteGCedObject(aAddress, aMarked, aObjectDescription, aCompartmentAddress); } \
  NS_IMETHOD NoteEdge(const nsACString & aFromAddress, const nsACString & aToAddress, const nsACString & aEdgeName) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteEdge(aFromAddress, aToAddress, aEdgeName); } \
  NS_IMETHOD DescribeRoot(const nsACString & aAddress, uint32_t aKnownEdges) { return !_to ? NS_ERROR_NULL_POINTER : _to->DescribeRoot(aAddress, aKnownEdges); } \
  NS_IMETHOD DescribeGarbage(const nsACString & aAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->DescribeGarbage(aAddress); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCycleCollectorHandler : public nsICycleCollectorHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICYCLECOLLECTORHANDLER

  nsCycleCollectorHandler();

private:
  ~nsCycleCollectorHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCycleCollectorHandler, nsICycleCollectorHandler)

nsCycleCollectorHandler::nsCycleCollectorHandler()
{
  /* member initializers and constructor code */
}

nsCycleCollectorHandler::~nsCycleCollectorHandler()
{
  /* destructor code */
}

/* void noteRefCountedObject (in ACString aAddress, in unsigned long aRefCount, in ACString aObjectDescription); */
NS_IMETHODIMP nsCycleCollectorHandler::NoteRefCountedObject(const nsACString & aAddress, uint32_t aRefCount, const nsACString & aObjectDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void noteGCedObject (in ACString aAddress, in boolean aMarked, in ACString aObjectDescription, in ACString aCompartmentAddress); */
NS_IMETHODIMP nsCycleCollectorHandler::NoteGCedObject(const nsACString & aAddress, bool aMarked, const nsACString & aObjectDescription, const nsACString & aCompartmentAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void noteEdge (in ACString aFromAddress, in ACString aToAddress, in ACString aEdgeName); */
NS_IMETHODIMP nsCycleCollectorHandler::NoteEdge(const nsACString & aFromAddress, const nsACString & aToAddress, const nsACString & aEdgeName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void describeRoot (in ACString aAddress, in unsigned long aKnownEdges); */
NS_IMETHODIMP nsCycleCollectorHandler::DescribeRoot(const nsACString & aAddress, uint32_t aKnownEdges)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void describeGarbage (in ACString aAddress); */
NS_IMETHODIMP nsCycleCollectorHandler::DescribeGarbage(const nsACString & aAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsICycleCollectorListener */
#define NS_ICYCLECOLLECTORLISTENER_IID_STR "2d04dd00-abc4-11e3-a5e2-0800200c9a66"

#define NS_ICYCLECOLLECTORLISTENER_IID \
  {0x2d04dd00, 0xabc4, 0x11e3, \
    { 0xa5, 0xe2, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsICycleCollectorListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICYCLECOLLECTORLISTENER_IID)

  /* nsICycleCollectorListener allTraces (); */
  NS_IMETHOD AllTraces(nsICycleCollectorListener * *_retval) = 0;

  /* readonly attribute boolean wantAllTraces; */
  NS_IMETHOD GetWantAllTraces(bool *aWantAllTraces) = 0;

  /* attribute boolean disableLog; */
  NS_IMETHOD GetDisableLog(bool *aDisableLog) = 0;
  NS_IMETHOD SetDisableLog(bool aDisableLog) = 0;

  /* attribute boolean wantAfterProcessing; */
  NS_IMETHOD GetWantAfterProcessing(bool *aWantAfterProcessing) = 0;
  NS_IMETHOD SetWantAfterProcessing(bool aWantAfterProcessing) = 0;

  /* attribute AString filenameIdentifier; */
  NS_IMETHOD GetFilenameIdentifier(nsAString & aFilenameIdentifier) = 0;
  NS_IMETHOD SetFilenameIdentifier(const nsAString & aFilenameIdentifier) = 0;

  /* readonly attribute AString gcLogPath; */
  NS_IMETHOD GetGcLogPath(nsAString & aGcLogPath) = 0;

  /* readonly attribute AString ccLogPath; */
  NS_IMETHOD GetCcLogPath(nsAString & aCcLogPath) = 0;

  /* void begin (); */
  NS_IMETHOD Begin(void) = 0;

  /* void noteRefCountedObject (in unsigned long long aAddress, in unsigned long aRefCount, in string aObjectDescription); */
  NS_IMETHOD NoteRefCountedObject(uint64_t aAddress, uint32_t aRefCount, const char * aObjectDescription) = 0;

  /* void noteGCedObject (in unsigned long long aAddress, in boolean aMarked, in string aObjectDescription, in unsigned long long aCompartmentAddress); */
  NS_IMETHOD NoteGCedObject(uint64_t aAddress, bool aMarked, const char * aObjectDescription, uint64_t aCompartmentAddress) = 0;

  /* void noteEdge (in unsigned long long aToAddress, in string aEdgeName); */
  NS_IMETHOD NoteEdge(uint64_t aToAddress, const char * aEdgeName) = 0;

  /* void noteWeakMapEntry (in unsigned long long aMap, in unsigned long long aKey, in unsigned long long aKeyDelegate, in unsigned long long aValue); */
  NS_IMETHOD NoteWeakMapEntry(uint64_t aMap, uint64_t aKey, uint64_t aKeyDelegate, uint64_t aValue) = 0;

  /* void noteIncrementalRoot (in unsigned long long aAddress); */
  NS_IMETHOD NoteIncrementalRoot(uint64_t aAddress) = 0;

  /* void beginResults (); */
  NS_IMETHOD BeginResults(void) = 0;

  /* void describeRoot (in unsigned long long aAddress, in unsigned long aKnownEdges); */
  NS_IMETHOD DescribeRoot(uint64_t aAddress, uint32_t aKnownEdges) = 0;

  /* void describeGarbage (in unsigned long long aAddress); */
  NS_IMETHOD DescribeGarbage(uint64_t aAddress) = 0;

  /* void end (); */
  NS_IMETHOD End(void) = 0;

  /* boolean processNext (in nsICycleCollectorHandler aHandler); */
  NS_IMETHOD ProcessNext(nsICycleCollectorHandler *aHandler, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICycleCollectorListener, NS_ICYCLECOLLECTORLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICYCLECOLLECTORLISTENER \
  NS_IMETHOD AllTraces(nsICycleCollectorListener * *_retval); \
  NS_IMETHOD GetWantAllTraces(bool *aWantAllTraces); \
  NS_IMETHOD GetDisableLog(bool *aDisableLog); \
  NS_IMETHOD SetDisableLog(bool aDisableLog); \
  NS_IMETHOD GetWantAfterProcessing(bool *aWantAfterProcessing); \
  NS_IMETHOD SetWantAfterProcessing(bool aWantAfterProcessing); \
  NS_IMETHOD GetFilenameIdentifier(nsAString & aFilenameIdentifier); \
  NS_IMETHOD SetFilenameIdentifier(const nsAString & aFilenameIdentifier); \
  NS_IMETHOD GetGcLogPath(nsAString & aGcLogPath); \
  NS_IMETHOD GetCcLogPath(nsAString & aCcLogPath); \
  NS_IMETHOD Begin(void); \
  NS_IMETHOD NoteRefCountedObject(uint64_t aAddress, uint32_t aRefCount, const char * aObjectDescription); \
  NS_IMETHOD NoteGCedObject(uint64_t aAddress, bool aMarked, const char * aObjectDescription, uint64_t aCompartmentAddress); \
  NS_IMETHOD NoteEdge(uint64_t aToAddress, const char * aEdgeName); \
  NS_IMETHOD NoteWeakMapEntry(uint64_t aMap, uint64_t aKey, uint64_t aKeyDelegate, uint64_t aValue); \
  NS_IMETHOD NoteIncrementalRoot(uint64_t aAddress); \
  NS_IMETHOD BeginResults(void); \
  NS_IMETHOD DescribeRoot(uint64_t aAddress, uint32_t aKnownEdges); \
  NS_IMETHOD DescribeGarbage(uint64_t aAddress); \
  NS_IMETHOD End(void); \
  NS_IMETHOD ProcessNext(nsICycleCollectorHandler *aHandler, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICYCLECOLLECTORLISTENER(_to) \
  NS_IMETHOD AllTraces(nsICycleCollectorListener * *_retval) { return _to AllTraces(_retval); } \
  NS_IMETHOD GetWantAllTraces(bool *aWantAllTraces) { return _to GetWantAllTraces(aWantAllTraces); } \
  NS_IMETHOD GetDisableLog(bool *aDisableLog) { return _to GetDisableLog(aDisableLog); } \
  NS_IMETHOD SetDisableLog(bool aDisableLog) { return _to SetDisableLog(aDisableLog); } \
  NS_IMETHOD GetWantAfterProcessing(bool *aWantAfterProcessing) { return _to GetWantAfterProcessing(aWantAfterProcessing); } \
  NS_IMETHOD SetWantAfterProcessing(bool aWantAfterProcessing) { return _to SetWantAfterProcessing(aWantAfterProcessing); } \
  NS_IMETHOD GetFilenameIdentifier(nsAString & aFilenameIdentifier) { return _to GetFilenameIdentifier(aFilenameIdentifier); } \
  NS_IMETHOD SetFilenameIdentifier(const nsAString & aFilenameIdentifier) { return _to SetFilenameIdentifier(aFilenameIdentifier); } \
  NS_IMETHOD GetGcLogPath(nsAString & aGcLogPath) { return _to GetGcLogPath(aGcLogPath); } \
  NS_IMETHOD GetCcLogPath(nsAString & aCcLogPath) { return _to GetCcLogPath(aCcLogPath); } \
  NS_IMETHOD Begin(void) { return _to Begin(); } \
  NS_IMETHOD NoteRefCountedObject(uint64_t aAddress, uint32_t aRefCount, const char * aObjectDescription) { return _to NoteRefCountedObject(aAddress, aRefCount, aObjectDescription); } \
  NS_IMETHOD NoteGCedObject(uint64_t aAddress, bool aMarked, const char * aObjectDescription, uint64_t aCompartmentAddress) { return _to NoteGCedObject(aAddress, aMarked, aObjectDescription, aCompartmentAddress); } \
  NS_IMETHOD NoteEdge(uint64_t aToAddress, const char * aEdgeName) { return _to NoteEdge(aToAddress, aEdgeName); } \
  NS_IMETHOD NoteWeakMapEntry(uint64_t aMap, uint64_t aKey, uint64_t aKeyDelegate, uint64_t aValue) { return _to NoteWeakMapEntry(aMap, aKey, aKeyDelegate, aValue); } \
  NS_IMETHOD NoteIncrementalRoot(uint64_t aAddress) { return _to NoteIncrementalRoot(aAddress); } \
  NS_IMETHOD BeginResults(void) { return _to BeginResults(); } \
  NS_IMETHOD DescribeRoot(uint64_t aAddress, uint32_t aKnownEdges) { return _to DescribeRoot(aAddress, aKnownEdges); } \
  NS_IMETHOD DescribeGarbage(uint64_t aAddress) { return _to DescribeGarbage(aAddress); } \
  NS_IMETHOD End(void) { return _to End(); } \
  NS_IMETHOD ProcessNext(nsICycleCollectorHandler *aHandler, bool *_retval) { return _to ProcessNext(aHandler, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICYCLECOLLECTORLISTENER(_to) \
  NS_IMETHOD AllTraces(nsICycleCollectorListener * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AllTraces(_retval); } \
  NS_IMETHOD GetWantAllTraces(bool *aWantAllTraces) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWantAllTraces(aWantAllTraces); } \
  NS_IMETHOD GetDisableLog(bool *aDisableLog) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisableLog(aDisableLog); } \
  NS_IMETHOD SetDisableLog(bool aDisableLog) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisableLog(aDisableLog); } \
  NS_IMETHOD GetWantAfterProcessing(bool *aWantAfterProcessing) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWantAfterProcessing(aWantAfterProcessing); } \
  NS_IMETHOD SetWantAfterProcessing(bool aWantAfterProcessing) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWantAfterProcessing(aWantAfterProcessing); } \
  NS_IMETHOD GetFilenameIdentifier(nsAString & aFilenameIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilenameIdentifier(aFilenameIdentifier); } \
  NS_IMETHOD SetFilenameIdentifier(const nsAString & aFilenameIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilenameIdentifier(aFilenameIdentifier); } \
  NS_IMETHOD GetGcLogPath(nsAString & aGcLogPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGcLogPath(aGcLogPath); } \
  NS_IMETHOD GetCcLogPath(nsAString & aCcLogPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCcLogPath(aCcLogPath); } \
  NS_IMETHOD Begin(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Begin(); } \
  NS_IMETHOD NoteRefCountedObject(uint64_t aAddress, uint32_t aRefCount, const char * aObjectDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteRefCountedObject(aAddress, aRefCount, aObjectDescription); } \
  NS_IMETHOD NoteGCedObject(uint64_t aAddress, bool aMarked, const char * aObjectDescription, uint64_t aCompartmentAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteGCedObject(aAddress, aMarked, aObjectDescription, aCompartmentAddress); } \
  NS_IMETHOD NoteEdge(uint64_t aToAddress, const char * aEdgeName) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteEdge(aToAddress, aEdgeName); } \
  NS_IMETHOD NoteWeakMapEntry(uint64_t aMap, uint64_t aKey, uint64_t aKeyDelegate, uint64_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteWeakMapEntry(aMap, aKey, aKeyDelegate, aValue); } \
  NS_IMETHOD NoteIncrementalRoot(uint64_t aAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteIncrementalRoot(aAddress); } \
  NS_IMETHOD BeginResults(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginResults(); } \
  NS_IMETHOD DescribeRoot(uint64_t aAddress, uint32_t aKnownEdges) { return !_to ? NS_ERROR_NULL_POINTER : _to->DescribeRoot(aAddress, aKnownEdges); } \
  NS_IMETHOD DescribeGarbage(uint64_t aAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->DescribeGarbage(aAddress); } \
  NS_IMETHOD End(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->End(); } \
  NS_IMETHOD ProcessNext(nsICycleCollectorHandler *aHandler, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessNext(aHandler, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCycleCollectorListener : public nsICycleCollectorListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICYCLECOLLECTORLISTENER

  nsCycleCollectorListener();

private:
  ~nsCycleCollectorListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCycleCollectorListener, nsICycleCollectorListener)

nsCycleCollectorListener::nsCycleCollectorListener()
{
  /* member initializers and constructor code */
}

nsCycleCollectorListener::~nsCycleCollectorListener()
{
  /* destructor code */
}

/* nsICycleCollectorListener allTraces (); */
NS_IMETHODIMP nsCycleCollectorListener::AllTraces(nsICycleCollectorListener * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean wantAllTraces; */
NS_IMETHODIMP nsCycleCollectorListener::GetWantAllTraces(bool *aWantAllTraces)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean disableLog; */
NS_IMETHODIMP nsCycleCollectorListener::GetDisableLog(bool *aDisableLog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCycleCollectorListener::SetDisableLog(bool aDisableLog)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean wantAfterProcessing; */
NS_IMETHODIMP nsCycleCollectorListener::GetWantAfterProcessing(bool *aWantAfterProcessing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCycleCollectorListener::SetWantAfterProcessing(bool aWantAfterProcessing)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString filenameIdentifier; */
NS_IMETHODIMP nsCycleCollectorListener::GetFilenameIdentifier(nsAString & aFilenameIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsCycleCollectorListener::SetFilenameIdentifier(const nsAString & aFilenameIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString gcLogPath; */
NS_IMETHODIMP nsCycleCollectorListener::GetGcLogPath(nsAString & aGcLogPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString ccLogPath; */
NS_IMETHODIMP nsCycleCollectorListener::GetCcLogPath(nsAString & aCcLogPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void begin (); */
NS_IMETHODIMP nsCycleCollectorListener::Begin()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void noteRefCountedObject (in unsigned long long aAddress, in unsigned long aRefCount, in string aObjectDescription); */
NS_IMETHODIMP nsCycleCollectorListener::NoteRefCountedObject(uint64_t aAddress, uint32_t aRefCount, const char * aObjectDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void noteGCedObject (in unsigned long long aAddress, in boolean aMarked, in string aObjectDescription, in unsigned long long aCompartmentAddress); */
NS_IMETHODIMP nsCycleCollectorListener::NoteGCedObject(uint64_t aAddress, bool aMarked, const char * aObjectDescription, uint64_t aCompartmentAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void noteEdge (in unsigned long long aToAddress, in string aEdgeName); */
NS_IMETHODIMP nsCycleCollectorListener::NoteEdge(uint64_t aToAddress, const char * aEdgeName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void noteWeakMapEntry (in unsigned long long aMap, in unsigned long long aKey, in unsigned long long aKeyDelegate, in unsigned long long aValue); */
NS_IMETHODIMP nsCycleCollectorListener::NoteWeakMapEntry(uint64_t aMap, uint64_t aKey, uint64_t aKeyDelegate, uint64_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void noteIncrementalRoot (in unsigned long long aAddress); */
NS_IMETHODIMP nsCycleCollectorListener::NoteIncrementalRoot(uint64_t aAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginResults (); */
NS_IMETHODIMP nsCycleCollectorListener::BeginResults()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void describeRoot (in unsigned long long aAddress, in unsigned long aKnownEdges); */
NS_IMETHODIMP nsCycleCollectorListener::DescribeRoot(uint64_t aAddress, uint32_t aKnownEdges)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void describeGarbage (in unsigned long long aAddress); */
NS_IMETHODIMP nsCycleCollectorListener::DescribeGarbage(uint64_t aAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void end (); */
NS_IMETHODIMP nsCycleCollectorListener::End()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean processNext (in nsICycleCollectorHandler aHandler); */
NS_IMETHODIMP nsCycleCollectorListener::ProcessNext(nsICycleCollectorHandler *aHandler, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICycleCollectorListener_h__ */
