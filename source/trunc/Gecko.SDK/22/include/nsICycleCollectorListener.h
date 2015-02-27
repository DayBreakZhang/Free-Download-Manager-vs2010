/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/base/nsICycleCollectorListener.idl
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
#define NS_ICYCLECOLLECTORHANDLER_IID_STR "0ef15f15-7783-4991-af68-4976d7ec2267"

#define NS_ICYCLECOLLECTORHANDLER_IID \
  {0x0ef15f15, 0x7783, 0x4991, \
    { 0xaf, 0x68, 0x49, 0x76, 0xd7, 0xec, 0x22, 0x67 }}

class NS_NO_VTABLE nsICycleCollectorHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICYCLECOLLECTORHANDLER_IID)

  /* void noteRefCountedObject (in ACString aAddress, in unsigned long aRefCount, in ACString aObjectDescription); */
  NS_IMETHOD NoteRefCountedObject(const nsACString & aAddress, uint32_t aRefCount, const nsACString & aObjectDescription) = 0;

  /* void noteGCedObject (in ACString aAddress, in boolean aMarked, in ACString aObjectDescription); */
  NS_IMETHOD NoteGCedObject(const nsACString & aAddress, bool aMarked, const nsACString & aObjectDescription) = 0;

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
  NS_IMETHOD NoteGCedObject(const nsACString & aAddress, bool aMarked, const nsACString & aObjectDescription); \
  NS_IMETHOD NoteEdge(const nsACString & aFromAddress, const nsACString & aToAddress, const nsACString & aEdgeName); \
  NS_IMETHOD DescribeRoot(const nsACString & aAddress, uint32_t aKnownEdges); \
  NS_IMETHOD DescribeGarbage(const nsACString & aAddress); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICYCLECOLLECTORHANDLER(_to) \
  NS_IMETHOD NoteRefCountedObject(const nsACString & aAddress, uint32_t aRefCount, const nsACString & aObjectDescription) { return _to NoteRefCountedObject(aAddress, aRefCount, aObjectDescription); } \
  NS_IMETHOD NoteGCedObject(const nsACString & aAddress, bool aMarked, const nsACString & aObjectDescription) { return _to NoteGCedObject(aAddress, aMarked, aObjectDescription); } \
  NS_IMETHOD NoteEdge(const nsACString & aFromAddress, const nsACString & aToAddress, const nsACString & aEdgeName) { return _to NoteEdge(aFromAddress, aToAddress, aEdgeName); } \
  NS_IMETHOD DescribeRoot(const nsACString & aAddress, uint32_t aKnownEdges) { return _to DescribeRoot(aAddress, aKnownEdges); } \
  NS_IMETHOD DescribeGarbage(const nsACString & aAddress) { return _to DescribeGarbage(aAddress); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICYCLECOLLECTORHANDLER(_to) \
  NS_IMETHOD NoteRefCountedObject(const nsACString & aAddress, uint32_t aRefCount, const nsACString & aObjectDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteRefCountedObject(aAddress, aRefCount, aObjectDescription); } \
  NS_IMETHOD NoteGCedObject(const nsACString & aAddress, bool aMarked, const nsACString & aObjectDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteGCedObject(aAddress, aMarked, aObjectDescription); } \
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

/* void noteGCedObject (in ACString aAddress, in boolean aMarked, in ACString aObjectDescription); */
NS_IMETHODIMP nsCycleCollectorHandler::NoteGCedObject(const nsACString & aAddress, bool aMarked, const nsACString & aObjectDescription)
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
#define NS_ICYCLECOLLECTORLISTENER_IID_STR "4282249c-7f80-4093-b620-96c573ad683e"

#define NS_ICYCLECOLLECTORLISTENER_IID \
  {0x4282249c, 0x7f80, 0x4093, \
    { 0xb6, 0x20, 0x96, 0xc5, 0x73, 0xad, 0x68, 0x3e }}

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

  /* void begin (); */
  NS_IMETHOD Begin(void) = 0;

  /* void noteRefCountedObject (in unsigned long long aAddress, in unsigned long aRefCount, in string aObjectDescription); */
  NS_IMETHOD NoteRefCountedObject(uint64_t aAddress, uint32_t aRefCount, const char * aObjectDescription) = 0;

  /* void noteGCedObject (in unsigned long long aAddress, in boolean aMarked, in string aObjectDescription); */
  NS_IMETHOD NoteGCedObject(uint64_t aAddress, bool aMarked, const char * aObjectDescription) = 0;

  /* void noteEdge (in unsigned long long aToAddress, in string aEdgeName); */
  NS_IMETHOD NoteEdge(uint64_t aToAddress, const char * aEdgeName) = 0;

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
  NS_IMETHOD Begin(void); \
  NS_IMETHOD NoteRefCountedObject(uint64_t aAddress, uint32_t aRefCount, const char * aObjectDescription); \
  NS_IMETHOD NoteGCedObject(uint64_t aAddress, bool aMarked, const char * aObjectDescription); \
  NS_IMETHOD NoteEdge(uint64_t aToAddress, const char * aEdgeName); \
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
  NS_IMETHOD Begin(void) { return _to Begin(); } \
  NS_IMETHOD NoteRefCountedObject(uint64_t aAddress, uint32_t aRefCount, const char * aObjectDescription) { return _to NoteRefCountedObject(aAddress, aRefCount, aObjectDescription); } \
  NS_IMETHOD NoteGCedObject(uint64_t aAddress, bool aMarked, const char * aObjectDescription) { return _to NoteGCedObject(aAddress, aMarked, aObjectDescription); } \
  NS_IMETHOD NoteEdge(uint64_t aToAddress, const char * aEdgeName) { return _to NoteEdge(aToAddress, aEdgeName); } \
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
  NS_IMETHOD Begin(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Begin(); } \
  NS_IMETHOD NoteRefCountedObject(uint64_t aAddress, uint32_t aRefCount, const char * aObjectDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteRefCountedObject(aAddress, aRefCount, aObjectDescription); } \
  NS_IMETHOD NoteGCedObject(uint64_t aAddress, bool aMarked, const char * aObjectDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteGCedObject(aAddress, aMarked, aObjectDescription); } \
  NS_IMETHOD NoteEdge(uint64_t aToAddress, const char * aEdgeName) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteEdge(aToAddress, aEdgeName); } \
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

/* void noteGCedObject (in unsigned long long aAddress, in boolean aMarked, in string aObjectDescription); */
NS_IMETHODIMP nsCycleCollectorListener::NoteGCedObject(uint64_t aAddress, bool aMarked, const char * aObjectDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void noteEdge (in unsigned long long aToAddress, in string aEdgeName); */
NS_IMETHODIMP nsCycleCollectorListener::NoteEdge(uint64_t aToAddress, const char * aEdgeName)
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
