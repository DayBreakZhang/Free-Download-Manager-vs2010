/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIRDFDataSource.idl
 */

#ifndef __gen_nsIRDFDataSource_h__
#define __gen_nsIRDFDataSource_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISupportsArray_h__
#include "nsISupportsArray.h"
#endif

#ifndef __gen_nsIRDFResource_h__
#include "nsIRDFResource.h"
#endif

#ifndef __gen_nsIRDFNode_h__
#include "nsIRDFNode.h"
#endif

#ifndef __gen_nsISimpleEnumerator_h__
#include "nsISimpleEnumerator.h"
#endif

#ifndef __gen_nsIRDFObserver_h__
#include "nsIRDFObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRDFDataSource */
#define NS_IRDFDATASOURCE_IID_STR "0f78da58-8321-11d2-8eac-00805f29f370"

#define NS_IRDFDATASOURCE_IID \
  {0x0f78da58, 0x8321, 0x11d2, \
    { 0x8e, 0xac, 0x00, 0x80, 0x5f, 0x29, 0xf3, 0x70 }}

class NS_NO_VTABLE nsIRDFDataSource : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IRDFDATASOURCE_IID)

  /* readonly attribute string URI; */
  NS_IMETHOD GetURI(char * *aURI) = 0;

  /* nsIRDFResource GetSource (in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
  NS_IMETHOD GetSource(nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, nsIRDFResource * *_retval) = 0;

  /* nsISimpleEnumerator GetSources (in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
  NS_IMETHOD GetSources(nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, nsISimpleEnumerator * *_retval) = 0;

  /* nsIRDFNode GetTarget (in nsIRDFResource aSource, in nsIRDFResource aProperty, in boolean aTruthValue); */
  NS_IMETHOD GetTarget(nsIRDFResource *aSource, nsIRDFResource *aProperty, bool aTruthValue, nsIRDFNode * *_retval) = 0;

  /* nsISimpleEnumerator GetTargets (in nsIRDFResource aSource, in nsIRDFResource aProperty, in boolean aTruthValue); */
  NS_IMETHOD GetTargets(nsIRDFResource *aSource, nsIRDFResource *aProperty, bool aTruthValue, nsISimpleEnumerator * *_retval) = 0;

  /* void Assert (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
  NS_IMETHOD Assert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue) = 0;

  /* void Unassert (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
  NS_IMETHOD Unassert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) = 0;

  /* void Change (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aOldTarget, in nsIRDFNode aNewTarget); */
  NS_IMETHOD Change(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget) = 0;

  /* void Move (in nsIRDFResource aOldSource, in nsIRDFResource aNewSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
  NS_IMETHOD Move(nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) = 0;

  /* boolean HasAssertion (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
  NS_IMETHOD HasAssertion(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, bool *_retval) = 0;

  /* void AddObserver (in nsIRDFObserver aObserver); */
  NS_IMETHOD AddObserver(nsIRDFObserver *aObserver) = 0;

  /* void RemoveObserver (in nsIRDFObserver aObserver); */
  NS_IMETHOD RemoveObserver(nsIRDFObserver *aObserver) = 0;

  /* nsISimpleEnumerator ArcLabelsIn (in nsIRDFNode aNode); */
  NS_IMETHOD ArcLabelsIn(nsIRDFNode *aNode, nsISimpleEnumerator * *_retval) = 0;

  /* nsISimpleEnumerator ArcLabelsOut (in nsIRDFResource aSource); */
  NS_IMETHOD ArcLabelsOut(nsIRDFResource *aSource, nsISimpleEnumerator * *_retval) = 0;

  /* nsISimpleEnumerator GetAllResources (); */
  NS_IMETHOD GetAllResources(nsISimpleEnumerator * *_retval) = 0;

  /* boolean IsCommandEnabled (in nsISupportsArray aSources, in nsIRDFResource aCommand, in nsISupportsArray aArguments); */
  NS_IMETHOD IsCommandEnabled(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments, bool *_retval) = 0;

  /* void DoCommand (in nsISupportsArray aSources, in nsIRDFResource aCommand, in nsISupportsArray aArguments); */
  NS_IMETHOD DoCommand(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments) = 0;

  /* nsISimpleEnumerator GetAllCmds (in nsIRDFResource aSource); */
  NS_IMETHOD GetAllCmds(nsIRDFResource *aSource, nsISimpleEnumerator * *_retval) = 0;

  /* boolean hasArcIn (in nsIRDFNode aNode, in nsIRDFResource aArc); */
  NS_IMETHOD HasArcIn(nsIRDFNode *aNode, nsIRDFResource *aArc, bool *_retval) = 0;

  /* boolean hasArcOut (in nsIRDFResource aSource, in nsIRDFResource aArc); */
  NS_IMETHOD HasArcOut(nsIRDFResource *aSource, nsIRDFResource *aArc, bool *_retval) = 0;

  /* void beginUpdateBatch (); */
  NS_IMETHOD BeginUpdateBatch(void) = 0;

  /* void endUpdateBatch (); */
  NS_IMETHOD EndUpdateBatch(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRDFDataSource, NS_IRDFDATASOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIRDFDATASOURCE \
  NS_IMETHOD GetURI(char * *aURI); \
  NS_IMETHOD GetSource(nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, nsIRDFResource * *_retval); \
  NS_IMETHOD GetSources(nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD GetTarget(nsIRDFResource *aSource, nsIRDFResource *aProperty, bool aTruthValue, nsIRDFNode * *_retval); \
  NS_IMETHOD GetTargets(nsIRDFResource *aSource, nsIRDFResource *aProperty, bool aTruthValue, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD Assert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue); \
  NS_IMETHOD Unassert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget); \
  NS_IMETHOD Change(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget); \
  NS_IMETHOD Move(nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget); \
  NS_IMETHOD HasAssertion(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, bool *_retval); \
  NS_IMETHOD AddObserver(nsIRDFObserver *aObserver); \
  NS_IMETHOD RemoveObserver(nsIRDFObserver *aObserver); \
  NS_IMETHOD ArcLabelsIn(nsIRDFNode *aNode, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD ArcLabelsOut(nsIRDFResource *aSource, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD GetAllResources(nsISimpleEnumerator * *_retval); \
  NS_IMETHOD IsCommandEnabled(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments, bool *_retval); \
  NS_IMETHOD DoCommand(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments); \
  NS_IMETHOD GetAllCmds(nsIRDFResource *aSource, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD HasArcIn(nsIRDFNode *aNode, nsIRDFResource *aArc, bool *_retval); \
  NS_IMETHOD HasArcOut(nsIRDFResource *aSource, nsIRDFResource *aArc, bool *_retval); \
  NS_IMETHOD BeginUpdateBatch(void); \
  NS_IMETHOD EndUpdateBatch(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIRDFDATASOURCE(_to) \
  NS_IMETHOD GetURI(char * *aURI) { return _to GetURI(aURI); } \
  NS_IMETHOD GetSource(nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, nsIRDFResource * *_retval) { return _to GetSource(aProperty, aTarget, aTruthValue, _retval); } \
  NS_IMETHOD GetSources(nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, nsISimpleEnumerator * *_retval) { return _to GetSources(aProperty, aTarget, aTruthValue, _retval); } \
  NS_IMETHOD GetTarget(nsIRDFResource *aSource, nsIRDFResource *aProperty, bool aTruthValue, nsIRDFNode * *_retval) { return _to GetTarget(aSource, aProperty, aTruthValue, _retval); } \
  NS_IMETHOD GetTargets(nsIRDFResource *aSource, nsIRDFResource *aProperty, bool aTruthValue, nsISimpleEnumerator * *_retval) { return _to GetTargets(aSource, aProperty, aTruthValue, _retval); } \
  NS_IMETHOD Assert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue) { return _to Assert(aSource, aProperty, aTarget, aTruthValue); } \
  NS_IMETHOD Unassert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return _to Unassert(aSource, aProperty, aTarget); } \
  NS_IMETHOD Change(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget) { return _to Change(aSource, aProperty, aOldTarget, aNewTarget); } \
  NS_IMETHOD Move(nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return _to Move(aOldSource, aNewSource, aProperty, aTarget); } \
  NS_IMETHOD HasAssertion(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, bool *_retval) { return _to HasAssertion(aSource, aProperty, aTarget, aTruthValue, _retval); } \
  NS_IMETHOD AddObserver(nsIRDFObserver *aObserver) { return _to AddObserver(aObserver); } \
  NS_IMETHOD RemoveObserver(nsIRDFObserver *aObserver) { return _to RemoveObserver(aObserver); } \
  NS_IMETHOD ArcLabelsIn(nsIRDFNode *aNode, nsISimpleEnumerator * *_retval) { return _to ArcLabelsIn(aNode, _retval); } \
  NS_IMETHOD ArcLabelsOut(nsIRDFResource *aSource, nsISimpleEnumerator * *_retval) { return _to ArcLabelsOut(aSource, _retval); } \
  NS_IMETHOD GetAllResources(nsISimpleEnumerator * *_retval) { return _to GetAllResources(_retval); } \
  NS_IMETHOD IsCommandEnabled(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments, bool *_retval) { return _to IsCommandEnabled(aSources, aCommand, aArguments, _retval); } \
  NS_IMETHOD DoCommand(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments) { return _to DoCommand(aSources, aCommand, aArguments); } \
  NS_IMETHOD GetAllCmds(nsIRDFResource *aSource, nsISimpleEnumerator * *_retval) { return _to GetAllCmds(aSource, _retval); } \
  NS_IMETHOD HasArcIn(nsIRDFNode *aNode, nsIRDFResource *aArc, bool *_retval) { return _to HasArcIn(aNode, aArc, _retval); } \
  NS_IMETHOD HasArcOut(nsIRDFResource *aSource, nsIRDFResource *aArc, bool *_retval) { return _to HasArcOut(aSource, aArc, _retval); } \
  NS_IMETHOD BeginUpdateBatch(void) { return _to BeginUpdateBatch(); } \
  NS_IMETHOD EndUpdateBatch(void) { return _to EndUpdateBatch(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIRDFDATASOURCE(_to) \
  NS_IMETHOD GetURI(char * *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_IMETHOD GetSource(nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, nsIRDFResource * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aProperty, aTarget, aTruthValue, _retval); } \
  NS_IMETHOD GetSources(nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSources(aProperty, aTarget, aTruthValue, _retval); } \
  NS_IMETHOD GetTarget(nsIRDFResource *aSource, nsIRDFResource *aProperty, bool aTruthValue, nsIRDFNode * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aSource, aProperty, aTruthValue, _retval); } \
  NS_IMETHOD GetTargets(nsIRDFResource *aSource, nsIRDFResource *aProperty, bool aTruthValue, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargets(aSource, aProperty, aTruthValue, _retval); } \
  NS_IMETHOD Assert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->Assert(aSource, aProperty, aTarget, aTruthValue); } \
  NS_IMETHOD Unassert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->Unassert(aSource, aProperty, aTarget); } \
  NS_IMETHOD Change(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->Change(aSource, aProperty, aOldTarget, aNewTarget); } \
  NS_IMETHOD Move(nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->Move(aOldSource, aNewSource, aProperty, aTarget); } \
  NS_IMETHOD HasAssertion(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasAssertion(aSource, aProperty, aTarget, aTruthValue, _retval); } \
  NS_IMETHOD AddObserver(nsIRDFObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver); } \
  NS_IMETHOD RemoveObserver(nsIRDFObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_IMETHOD ArcLabelsIn(nsIRDFNode *aNode, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ArcLabelsIn(aNode, _retval); } \
  NS_IMETHOD ArcLabelsOut(nsIRDFResource *aSource, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ArcLabelsOut(aSource, _retval); } \
  NS_IMETHOD GetAllResources(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllResources(_retval); } \
  NS_IMETHOD IsCommandEnabled(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCommandEnabled(aSources, aCommand, aArguments, _retval); } \
  NS_IMETHOD DoCommand(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoCommand(aSources, aCommand, aArguments); } \
  NS_IMETHOD GetAllCmds(nsIRDFResource *aSource, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllCmds(aSource, _retval); } \
  NS_IMETHOD HasArcIn(nsIRDFNode *aNode, nsIRDFResource *aArc, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasArcIn(aNode, aArc, _retval); } \
  NS_IMETHOD HasArcOut(nsIRDFResource *aSource, nsIRDFResource *aArc, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasArcOut(aSource, aArc, _retval); } \
  NS_IMETHOD BeginUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->BeginUpdateBatch(); } \
  NS_IMETHOD EndUpdateBatch(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndUpdateBatch(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRDFDataSource : public nsIRDFDataSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIRDFDATASOURCE

  nsRDFDataSource();

private:
  ~nsRDFDataSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRDFDataSource, nsIRDFDataSource)

nsRDFDataSource::nsRDFDataSource()
{
  /* member initializers and constructor code */
}

nsRDFDataSource::~nsRDFDataSource()
{
  /* destructor code */
}

/* readonly attribute string URI; */
NS_IMETHODIMP nsRDFDataSource::GetURI(char * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFResource GetSource (in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::GetSource(nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, nsIRDFResource * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetSources (in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::GetSources(nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIRDFNode GetTarget (in nsIRDFResource aSource, in nsIRDFResource aProperty, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::GetTarget(nsIRDFResource *aSource, nsIRDFResource *aProperty, bool aTruthValue, nsIRDFNode * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetTargets (in nsIRDFResource aSource, in nsIRDFResource aProperty, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::GetTargets(nsIRDFResource *aSource, nsIRDFResource *aProperty, bool aTruthValue, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Assert (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::Assert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Unassert (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
NS_IMETHODIMP nsRDFDataSource::Unassert(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Change (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aOldTarget, in nsIRDFNode aNewTarget); */
NS_IMETHODIMP nsRDFDataSource::Change(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aOldTarget, nsIRDFNode *aNewTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void Move (in nsIRDFResource aOldSource, in nsIRDFResource aNewSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget); */
NS_IMETHODIMP nsRDFDataSource::Move(nsIRDFResource *aOldSource, nsIRDFResource *aNewSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean HasAssertion (in nsIRDFResource aSource, in nsIRDFResource aProperty, in nsIRDFNode aTarget, in boolean aTruthValue); */
NS_IMETHODIMP nsRDFDataSource::HasAssertion(nsIRDFResource *aSource, nsIRDFResource *aProperty, nsIRDFNode *aTarget, bool aTruthValue, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void AddObserver (in nsIRDFObserver aObserver); */
NS_IMETHODIMP nsRDFDataSource::AddObserver(nsIRDFObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void RemoveObserver (in nsIRDFObserver aObserver); */
NS_IMETHODIMP nsRDFDataSource::RemoveObserver(nsIRDFObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator ArcLabelsIn (in nsIRDFNode aNode); */
NS_IMETHODIMP nsRDFDataSource::ArcLabelsIn(nsIRDFNode *aNode, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator ArcLabelsOut (in nsIRDFResource aSource); */
NS_IMETHODIMP nsRDFDataSource::ArcLabelsOut(nsIRDFResource *aSource, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetAllResources (); */
NS_IMETHODIMP nsRDFDataSource::GetAllResources(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean IsCommandEnabled (in nsISupportsArray aSources, in nsIRDFResource aCommand, in nsISupportsArray aArguments); */
NS_IMETHODIMP nsRDFDataSource::IsCommandEnabled(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void DoCommand (in nsISupportsArray aSources, in nsIRDFResource aCommand, in nsISupportsArray aArguments); */
NS_IMETHODIMP nsRDFDataSource::DoCommand(nsISupportsArray *aSources, nsIRDFResource *aCommand, nsISupportsArray *aArguments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator GetAllCmds (in nsIRDFResource aSource); */
NS_IMETHODIMP nsRDFDataSource::GetAllCmds(nsIRDFResource *aSource, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasArcIn (in nsIRDFNode aNode, in nsIRDFResource aArc); */
NS_IMETHODIMP nsRDFDataSource::HasArcIn(nsIRDFNode *aNode, nsIRDFResource *aArc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasArcOut (in nsIRDFResource aSource, in nsIRDFResource aArc); */
NS_IMETHODIMP nsRDFDataSource::HasArcOut(nsIRDFResource *aSource, nsIRDFResource *aArc, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void beginUpdateBatch (); */
NS_IMETHODIMP nsRDFDataSource::BeginUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endUpdateBatch (); */
NS_IMETHODIMP nsRDFDataSource::EndUpdateBatch()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRDFDataSource_h__ */
