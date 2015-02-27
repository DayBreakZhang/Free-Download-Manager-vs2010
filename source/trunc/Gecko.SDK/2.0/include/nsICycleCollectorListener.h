/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/xpcom/base/nsICycleCollectorListener.idl
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

/* starting interface:    nsICycleCollectorListener */
#define NS_ICYCLECOLLECTORLISTENER_IID_STR "194b749a-4ceb-4dd1-928d-d30b5f14c23e"

#define NS_ICYCLECOLLECTORLISTENER_IID \
  {0x194b749a, 0x4ceb, 0x4dd1, \
    { 0x92, 0x8d, 0xd3, 0x0b, 0x5f, 0x14, 0xc2, 0x3e }}

/**
 * Interface to pass to the cycle collector to get information about the CC
 * graph while it's being built. The order of calls will be call to begin();
 * then for every node in the graph a call to noteObject() and calls to
 * noteEdge() for every edge starting at that node; then a call to
 * beginDescriptions(); then for every black node in the CC graph a call to
 * either describeRefcountedObject() or to describeGCedObject(); and then a
 * call to end(). If begin() returns an error none of the other functions will
 * be called.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICycleCollectorListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICYCLECOLLECTORLISTENER_IID)

  /* void begin (); */
  NS_SCRIPTABLE NS_IMETHOD Begin(void) = 0;

  /* void noteObject (in unsigned long long aAddress, in string aObjectDescription); */
  NS_SCRIPTABLE NS_IMETHOD NoteObject(PRUint64 aAddress, const char *aObjectDescription) = 0;

  /* void noteEdge (in unsigned long long aFromAddress, in unsigned long long aToAddress, in string aEdgeName); */
  NS_SCRIPTABLE NS_IMETHOD NoteEdge(PRUint64 aFromAddress, PRUint64 aToAddress, const char *aEdgeName) = 0;

  /* void beginDescriptions (); */
  NS_SCRIPTABLE NS_IMETHOD BeginDescriptions(void) = 0;

  /* void describeRefcountedObject (in unsigned long long aAddress, in unsigned long aKnownEdges, in unsigned long aTotalEdges); */
  NS_SCRIPTABLE NS_IMETHOD DescribeRefcountedObject(PRUint64 aAddress, PRUint32 aKnownEdges, PRUint32 aTotalEdges) = 0;

  /* void describeGCedObject (in unsigned long long aAddress, in boolean aMarked); */
  NS_SCRIPTABLE NS_IMETHOD DescribeGCedObject(PRUint64 aAddress, PRBool aMarked) = 0;

  /* void end (); */
  NS_SCRIPTABLE NS_IMETHOD End(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICycleCollectorListener, NS_ICYCLECOLLECTORLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICYCLECOLLECTORLISTENER \
  NS_SCRIPTABLE NS_IMETHOD Begin(void); \
  NS_SCRIPTABLE NS_IMETHOD NoteObject(PRUint64 aAddress, const char *aObjectDescription); \
  NS_SCRIPTABLE NS_IMETHOD NoteEdge(PRUint64 aFromAddress, PRUint64 aToAddress, const char *aEdgeName); \
  NS_SCRIPTABLE NS_IMETHOD BeginDescriptions(void); \
  NS_SCRIPTABLE NS_IMETHOD DescribeRefcountedObject(PRUint64 aAddress, PRUint32 aKnownEdges, PRUint32 aTotalEdges); \
  NS_SCRIPTABLE NS_IMETHOD DescribeGCedObject(PRUint64 aAddress, PRBool aMarked); \
  NS_SCRIPTABLE NS_IMETHOD End(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICYCLECOLLECTORLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Begin(void) { return _to Begin(); } \
  NS_SCRIPTABLE NS_IMETHOD NoteObject(PRUint64 aAddress, const char *aObjectDescription) { return _to NoteObject(aAddress, aObjectDescription); } \
  NS_SCRIPTABLE NS_IMETHOD NoteEdge(PRUint64 aFromAddress, PRUint64 aToAddress, const char *aEdgeName) { return _to NoteEdge(aFromAddress, aToAddress, aEdgeName); } \
  NS_SCRIPTABLE NS_IMETHOD BeginDescriptions(void) { return _to BeginDescriptions(); } \
  NS_SCRIPTABLE NS_IMETHOD DescribeRefcountedObject(PRUint64 aAddress, PRUint32 aKnownEdges, PRUint32 aTotalEdges) { return _to DescribeRefcountedObject(aAddress, aKnownEdges, aTotalEdges); } \
  NS_SCRIPTABLE NS_IMETHOD DescribeGCedObject(PRUint64 aAddress, PRBool aMarked) { return _to DescribeGCedObject(aAddress, aMarked); } \
  NS_SCRIPTABLE NS_IMETHOD End(void) { return _to End(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICYCLECOLLECTORLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Begin(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Begin(); } \
  NS_SCRIPTABLE NS_IMETHOD NoteObject(PRUint64 aAddress, const char *aObjectDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteObject(aAddress, aObjectDescription); } \
  NS_SCRIPTABLE NS_IMETHOD NoteEdge(PRUint64 aFromAddress, PRUint64 aToAddress, const char *aEdgeName) { return !_to ? NS_ERROR_NULL_POINTER : _to->NoteEdge(aFromAddress, aToAddress, aEdgeName); } \
  NS_SCRIPTABLE NS_IMETHOD BeginDescriptions(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginDescriptions(); } \
  NS_SCRIPTABLE NS_IMETHOD DescribeRefcountedObject(PRUint64 aAddress, PRUint32 aKnownEdges, PRUint32 aTotalEdges) { return !_to ? NS_ERROR_NULL_POINTER : _to->DescribeRefcountedObject(aAddress, aKnownEdges, aTotalEdges); } \
  NS_SCRIPTABLE NS_IMETHOD DescribeGCedObject(PRUint64 aAddress, PRBool aMarked) { return !_to ? NS_ERROR_NULL_POINTER : _to->DescribeGCedObject(aAddress, aMarked); } \
  NS_SCRIPTABLE NS_IMETHOD End(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->End(); } 

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

/* void begin (); */
NS_IMETHODIMP nsCycleCollectorListener::Begin()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void noteObject (in unsigned long long aAddress, in string aObjectDescription); */
NS_IMETHODIMP nsCycleCollectorListener::NoteObject(PRUint64 aAddress, const char *aObjectDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void noteEdge (in unsigned long long aFromAddress, in unsigned long long aToAddress, in string aEdgeName); */
NS_IMETHODIMP nsCycleCollectorListener::NoteEdge(PRUint64 aFromAddress, PRUint64 aToAddress, const char *aEdgeName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginDescriptions (); */
NS_IMETHODIMP nsCycleCollectorListener::BeginDescriptions()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void describeRefcountedObject (in unsigned long long aAddress, in unsigned long aKnownEdges, in unsigned long aTotalEdges); */
NS_IMETHODIMP nsCycleCollectorListener::DescribeRefcountedObject(PRUint64 aAddress, PRUint32 aKnownEdges, PRUint32 aTotalEdges)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void describeGCedObject (in unsigned long long aAddress, in boolean aMarked); */
NS_IMETHODIMP nsCycleCollectorListener::DescribeGCedObject(PRUint64 aAddress, PRBool aMarked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void end (); */
NS_IMETHODIMP nsCycleCollectorListener::End()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICycleCollectorListener_h__ */
