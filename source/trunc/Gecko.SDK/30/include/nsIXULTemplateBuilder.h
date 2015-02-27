/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXULTemplateBuilder.idl
 */

#ifndef __gen_nsIXULTemplateBuilder_h__
#define __gen_nsIXULTemplateBuilder_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAtom; /* forward declaration */

class nsIContent; /* forward declaration */

class nsIXULBuilderListener; /* forward declaration */

class nsIXULTemplateResult; /* forward declaration */

class nsIXULTemplateRuleFilter; /* forward declaration */

class nsIXULTemplateQueryProcessor; /* forward declaration */

class nsIRDFResource; /* forward declaration */

class nsIRDFCompositeDataSource; /* forward declaration */

class nsIDOMDataTransfer; /* forward declaration */


/* starting interface:    nsIXULTemplateBuilder */
#define NS_IXULTEMPLATEBUILDER_IID_STR "a583b676-5b02-4f9c-a0c9-cb850cb99818"

#define NS_IXULTEMPLATEBUILDER_IID \
  {0xa583b676, 0x5b02, 0x4f9c, \
    { 0xa0, 0xc9, 0xcb, 0x85, 0x0c, 0xb9, 0x98, 0x18 }}

class NS_NO_VTABLE nsIXULTemplateBuilder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULTEMPLATEBUILDER_IID)

  /* readonly attribute nsIDOMElement root; */
  NS_IMETHOD GetRoot(nsIDOMElement * *aRoot) = 0;

  /* attribute nsISupports datasource; */
  NS_IMETHOD GetDatasource(nsISupports * *aDatasource) = 0;
  NS_IMETHOD SetDatasource(nsISupports *aDatasource) = 0;

  /* readonly attribute nsIRDFCompositeDataSource database; */
  NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase) = 0;

  /* readonly attribute nsIXULTemplateResult rootResult; */
  NS_IMETHOD GetRootResult(nsIXULTemplateResult * *aRootResult) = 0;

  /* [noscript] readonly attribute nsIXULTemplateQueryProcessor queryProcessor; */
  NS_IMETHOD GetQueryProcessor(nsIXULTemplateQueryProcessor * *aQueryProcessor) = 0;

  /* void rebuild (); */
  NS_IMETHOD Rebuild(void) = 0;

  /* void refresh (); */
  NS_IMETHOD Refresh(void) = 0;

  /* void addResult (in nsIXULTemplateResult aResult, in nsIDOMNode aQueryNode); */
  NS_IMETHOD AddResult(nsIXULTemplateResult *aResult, nsIDOMNode *aQueryNode) = 0;

  /* void removeResult (in nsIXULTemplateResult aResult); */
  NS_IMETHOD RemoveResult(nsIXULTemplateResult *aResult) = 0;

  /* void replaceResult (in nsIXULTemplateResult aOldResult, in nsIXULTemplateResult aNewResult, in nsIDOMNode aQueryNode); */
  NS_IMETHOD ReplaceResult(nsIXULTemplateResult *aOldResult, nsIXULTemplateResult *aNewResult, nsIDOMNode *aQueryNode) = 0;

  /* void resultBindingChanged (in nsIXULTemplateResult aResult); */
  NS_IMETHOD ResultBindingChanged(nsIXULTemplateResult *aResult) = 0;

  /* nsIXULTemplateResult getResultForId (in AString aId); */
  NS_IMETHOD GetResultForId(const nsAString & aId, nsIXULTemplateResult * *_retval) = 0;

  /* nsIXULTemplateResult getResultForContent (in nsIDOMElement aElement); */
  NS_IMETHOD GetResultForContent(nsIDOMElement *aElement, nsIXULTemplateResult * *_retval) = 0;

  /* boolean hasGeneratedContent (in nsIRDFResource aNode, in nsIAtom aTag); */
  NS_IMETHOD HasGeneratedContent(nsIRDFResource *aNode, nsIAtom *aTag, bool *_retval) = 0;

  /* void addRuleFilter (in nsIDOMNode aRule, in nsIXULTemplateRuleFilter aFilter); */
  NS_IMETHOD AddRuleFilter(nsIDOMNode *aRule, nsIXULTemplateRuleFilter *aFilter) = 0;

  /* [noscript] void init (in nsIContent aElement); */
  NS_IMETHOD Init(nsIContent *aElement) = 0;

  /* [noscript] void createContents (in nsIContent aElement, in boolean aForceCreation); */
  NS_IMETHOD CreateContents(nsIContent *aElement, bool aForceCreation) = 0;

  /* void addListener (in nsIXULBuilderListener aListener); */
  NS_IMETHOD AddListener(nsIXULBuilderListener *aListener) = 0;

  /* void removeListener (in nsIXULBuilderListener aListener); */
  NS_IMETHOD RemoveListener(nsIXULBuilderListener *aListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULTemplateBuilder, NS_IXULTEMPLATEBUILDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULTEMPLATEBUILDER \
  NS_IMETHOD GetRoot(nsIDOMElement * *aRoot); \
  NS_IMETHOD GetDatasource(nsISupports * *aDatasource); \
  NS_IMETHOD SetDatasource(nsISupports *aDatasource); \
  NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase); \
  NS_IMETHOD GetRootResult(nsIXULTemplateResult * *aRootResult); \
  NS_IMETHOD GetQueryProcessor(nsIXULTemplateQueryProcessor * *aQueryProcessor); \
  NS_IMETHOD Rebuild(void); \
  NS_IMETHOD Refresh(void); \
  NS_IMETHOD AddResult(nsIXULTemplateResult *aResult, nsIDOMNode *aQueryNode); \
  NS_IMETHOD RemoveResult(nsIXULTemplateResult *aResult); \
  NS_IMETHOD ReplaceResult(nsIXULTemplateResult *aOldResult, nsIXULTemplateResult *aNewResult, nsIDOMNode *aQueryNode); \
  NS_IMETHOD ResultBindingChanged(nsIXULTemplateResult *aResult); \
  NS_IMETHOD GetResultForId(const nsAString & aId, nsIXULTemplateResult * *_retval); \
  NS_IMETHOD GetResultForContent(nsIDOMElement *aElement, nsIXULTemplateResult * *_retval); \
  NS_IMETHOD HasGeneratedContent(nsIRDFResource *aNode, nsIAtom *aTag, bool *_retval); \
  NS_IMETHOD AddRuleFilter(nsIDOMNode *aRule, nsIXULTemplateRuleFilter *aFilter); \
  NS_IMETHOD Init(nsIContent *aElement); \
  NS_IMETHOD CreateContents(nsIContent *aElement, bool aForceCreation); \
  NS_IMETHOD AddListener(nsIXULBuilderListener *aListener); \
  NS_IMETHOD RemoveListener(nsIXULBuilderListener *aListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULTEMPLATEBUILDER(_to) \
  NS_IMETHOD GetRoot(nsIDOMElement * *aRoot) { return _to GetRoot(aRoot); } \
  NS_IMETHOD GetDatasource(nsISupports * *aDatasource) { return _to GetDatasource(aDatasource); } \
  NS_IMETHOD SetDatasource(nsISupports *aDatasource) { return _to SetDatasource(aDatasource); } \
  NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase) { return _to GetDatabase(aDatabase); } \
  NS_IMETHOD GetRootResult(nsIXULTemplateResult * *aRootResult) { return _to GetRootResult(aRootResult); } \
  NS_IMETHOD GetQueryProcessor(nsIXULTemplateQueryProcessor * *aQueryProcessor) { return _to GetQueryProcessor(aQueryProcessor); } \
  NS_IMETHOD Rebuild(void) { return _to Rebuild(); } \
  NS_IMETHOD Refresh(void) { return _to Refresh(); } \
  NS_IMETHOD AddResult(nsIXULTemplateResult *aResult, nsIDOMNode *aQueryNode) { return _to AddResult(aResult, aQueryNode); } \
  NS_IMETHOD RemoveResult(nsIXULTemplateResult *aResult) { return _to RemoveResult(aResult); } \
  NS_IMETHOD ReplaceResult(nsIXULTemplateResult *aOldResult, nsIXULTemplateResult *aNewResult, nsIDOMNode *aQueryNode) { return _to ReplaceResult(aOldResult, aNewResult, aQueryNode); } \
  NS_IMETHOD ResultBindingChanged(nsIXULTemplateResult *aResult) { return _to ResultBindingChanged(aResult); } \
  NS_IMETHOD GetResultForId(const nsAString & aId, nsIXULTemplateResult * *_retval) { return _to GetResultForId(aId, _retval); } \
  NS_IMETHOD GetResultForContent(nsIDOMElement *aElement, nsIXULTemplateResult * *_retval) { return _to GetResultForContent(aElement, _retval); } \
  NS_IMETHOD HasGeneratedContent(nsIRDFResource *aNode, nsIAtom *aTag, bool *_retval) { return _to HasGeneratedContent(aNode, aTag, _retval); } \
  NS_IMETHOD AddRuleFilter(nsIDOMNode *aRule, nsIXULTemplateRuleFilter *aFilter) { return _to AddRuleFilter(aRule, aFilter); } \
  NS_IMETHOD Init(nsIContent *aElement) { return _to Init(aElement); } \
  NS_IMETHOD CreateContents(nsIContent *aElement, bool aForceCreation) { return _to CreateContents(aElement, aForceCreation); } \
  NS_IMETHOD AddListener(nsIXULBuilderListener *aListener) { return _to AddListener(aListener); } \
  NS_IMETHOD RemoveListener(nsIXULBuilderListener *aListener) { return _to RemoveListener(aListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULTEMPLATEBUILDER(_to) \
  NS_IMETHOD GetRoot(nsIDOMElement * *aRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRoot(aRoot); } \
  NS_IMETHOD GetDatasource(nsISupports * *aDatasource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatasource(aDatasource); } \
  NS_IMETHOD SetDatasource(nsISupports *aDatasource) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDatasource(aDatasource); } \
  NS_IMETHOD GetDatabase(nsIRDFCompositeDataSource * *aDatabase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatabase(aDatabase); } \
  NS_IMETHOD GetRootResult(nsIXULTemplateResult * *aRootResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRootResult(aRootResult); } \
  NS_IMETHOD GetQueryProcessor(nsIXULTemplateQueryProcessor * *aQueryProcessor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetQueryProcessor(aQueryProcessor); } \
  NS_IMETHOD Rebuild(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Rebuild(); } \
  NS_IMETHOD Refresh(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Refresh(); } \
  NS_IMETHOD AddResult(nsIXULTemplateResult *aResult, nsIDOMNode *aQueryNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddResult(aResult, aQueryNode); } \
  NS_IMETHOD RemoveResult(nsIXULTemplateResult *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveResult(aResult); } \
  NS_IMETHOD ReplaceResult(nsIXULTemplateResult *aOldResult, nsIXULTemplateResult *aNewResult, nsIDOMNode *aQueryNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceResult(aOldResult, aNewResult, aQueryNode); } \
  NS_IMETHOD ResultBindingChanged(nsIXULTemplateResult *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResultBindingChanged(aResult); } \
  NS_IMETHOD GetResultForId(const nsAString & aId, nsIXULTemplateResult * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultForId(aId, _retval); } \
  NS_IMETHOD GetResultForContent(nsIDOMElement *aElement, nsIXULTemplateResult * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResultForContent(aElement, _retval); } \
  NS_IMETHOD HasGeneratedContent(nsIRDFResource *aNode, nsIAtom *aTag, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasGeneratedContent(aNode, aTag, _retval); } \
  NS_IMETHOD AddRuleFilter(nsIDOMNode *aRule, nsIXULTemplateRuleFilter *aFilter) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddRuleFilter(aRule, aFilter); } \
  NS_IMETHOD Init(nsIContent *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aElement); } \
  NS_IMETHOD CreateContents(nsIContent *aElement, bool aForceCreation) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateContents(aElement, aForceCreation); } \
  NS_IMETHOD AddListener(nsIXULBuilderListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aListener); } \
  NS_IMETHOD RemoveListener(nsIXULBuilderListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULTemplateBuilder : public nsIXULTemplateBuilder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULTEMPLATEBUILDER

  nsXULTemplateBuilder();

private:
  ~nsXULTemplateBuilder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULTemplateBuilder, nsIXULTemplateBuilder)

nsXULTemplateBuilder::nsXULTemplateBuilder()
{
  /* member initializers and constructor code */
}

nsXULTemplateBuilder::~nsXULTemplateBuilder()
{
  /* destructor code */
}

/* readonly attribute nsIDOMElement root; */
NS_IMETHODIMP nsXULTemplateBuilder::GetRoot(nsIDOMElement * *aRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsISupports datasource; */
NS_IMETHODIMP nsXULTemplateBuilder::GetDatasource(nsISupports * *aDatasource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsXULTemplateBuilder::SetDatasource(nsISupports *aDatasource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRDFCompositeDataSource database; */
NS_IMETHODIMP nsXULTemplateBuilder::GetDatabase(nsIRDFCompositeDataSource * *aDatabase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXULTemplateResult rootResult; */
NS_IMETHODIMP nsXULTemplateBuilder::GetRootResult(nsIXULTemplateResult * *aRootResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIXULTemplateQueryProcessor queryProcessor; */
NS_IMETHODIMP nsXULTemplateBuilder::GetQueryProcessor(nsIXULTemplateQueryProcessor * *aQueryProcessor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void rebuild (); */
NS_IMETHODIMP nsXULTemplateBuilder::Rebuild()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void refresh (); */
NS_IMETHODIMP nsXULTemplateBuilder::Refresh()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addResult (in nsIXULTemplateResult aResult, in nsIDOMNode aQueryNode); */
NS_IMETHODIMP nsXULTemplateBuilder::AddResult(nsIXULTemplateResult *aResult, nsIDOMNode *aQueryNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeResult (in nsIXULTemplateResult aResult); */
NS_IMETHODIMP nsXULTemplateBuilder::RemoveResult(nsIXULTemplateResult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceResult (in nsIXULTemplateResult aOldResult, in nsIXULTemplateResult aNewResult, in nsIDOMNode aQueryNode); */
NS_IMETHODIMP nsXULTemplateBuilder::ReplaceResult(nsIXULTemplateResult *aOldResult, nsIXULTemplateResult *aNewResult, nsIDOMNode *aQueryNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resultBindingChanged (in nsIXULTemplateResult aResult); */
NS_IMETHODIMP nsXULTemplateBuilder::ResultBindingChanged(nsIXULTemplateResult *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXULTemplateResult getResultForId (in AString aId); */
NS_IMETHODIMP nsXULTemplateBuilder::GetResultForId(const nsAString & aId, nsIXULTemplateResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXULTemplateResult getResultForContent (in nsIDOMElement aElement); */
NS_IMETHODIMP nsXULTemplateBuilder::GetResultForContent(nsIDOMElement *aElement, nsIXULTemplateResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasGeneratedContent (in nsIRDFResource aNode, in nsIAtom aTag); */
NS_IMETHODIMP nsXULTemplateBuilder::HasGeneratedContent(nsIRDFResource *aNode, nsIAtom *aTag, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addRuleFilter (in nsIDOMNode aRule, in nsIXULTemplateRuleFilter aFilter); */
NS_IMETHODIMP nsXULTemplateBuilder::AddRuleFilter(nsIDOMNode *aRule, nsIXULTemplateRuleFilter *aFilter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void init (in nsIContent aElement); */
NS_IMETHODIMP nsXULTemplateBuilder::Init(nsIContent *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void createContents (in nsIContent aElement, in boolean aForceCreation); */
NS_IMETHODIMP nsXULTemplateBuilder::CreateContents(nsIContent *aElement, bool aForceCreation)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addListener (in nsIXULBuilderListener aListener); */
NS_IMETHODIMP nsXULTemplateBuilder::AddListener(nsIXULBuilderListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in nsIXULBuilderListener aListener); */
NS_IMETHODIMP nsXULTemplateBuilder::RemoveListener(nsIXULBuilderListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXULTreeBuilderObserver */
#define NS_IXULTREEBUILDEROBSERVER_IID_STR "57ced9a7-ec0b-4a0e-8aeb-5da32ebe951c"

#define NS_IXULTREEBUILDEROBSERVER_IID \
  {0x57ced9a7, 0xec0b, 0x4a0e, \
    { 0x8a, 0xeb, 0x5d, 0xa3, 0x2e, 0xbe, 0x95, 0x1c }}

class NS_NO_VTABLE nsIXULTreeBuilderObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULTREEBUILDEROBSERVER_IID)

  enum {
    DROP_BEFORE = -1,
    DROP_ON = 0,
    DROP_AFTER = 1
  };

  /* boolean canDrop (in long index, in long orientation, in nsIDOMDataTransfer dataTransfer); */
  NS_IMETHOD CanDrop(int32_t index, int32_t orientation, nsIDOMDataTransfer *dataTransfer, bool *_retval) = 0;

  /* void onDrop (in long row, in long orientation, in nsIDOMDataTransfer dataTransfer); */
  NS_IMETHOD OnDrop(int32_t row, int32_t orientation, nsIDOMDataTransfer *dataTransfer) = 0;

  /* void onToggleOpenState (in long index); */
  NS_IMETHOD OnToggleOpenState(int32_t index) = 0;

  /* void onCycleHeader (in wstring colID, in nsIDOMElement elt); */
  NS_IMETHOD OnCycleHeader(const char16_t * colID, nsIDOMElement *elt) = 0;

  /* void onCycleCell (in long row, in wstring colID); */
  NS_IMETHOD OnCycleCell(int32_t row, const char16_t * colID) = 0;

  /* void onSelectionChanged (); */
  NS_IMETHOD OnSelectionChanged(void) = 0;

  /* void onPerformAction (in wstring action); */
  NS_IMETHOD OnPerformAction(const char16_t * action) = 0;

  /* void onPerformActionOnRow (in wstring action, in long row); */
  NS_IMETHOD OnPerformActionOnRow(const char16_t * action, int32_t row) = 0;

  /* void onPerformActionOnCell (in wstring action, in long row, in wstring colID); */
  NS_IMETHOD OnPerformActionOnCell(const char16_t * action, int32_t row, const char16_t * colID) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULTreeBuilderObserver, NS_IXULTREEBUILDEROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULTREEBUILDEROBSERVER \
  NS_IMETHOD CanDrop(int32_t index, int32_t orientation, nsIDOMDataTransfer *dataTransfer, bool *_retval); \
  NS_IMETHOD OnDrop(int32_t row, int32_t orientation, nsIDOMDataTransfer *dataTransfer); \
  NS_IMETHOD OnToggleOpenState(int32_t index); \
  NS_IMETHOD OnCycleHeader(const char16_t * colID, nsIDOMElement *elt); \
  NS_IMETHOD OnCycleCell(int32_t row, const char16_t * colID); \
  NS_IMETHOD OnSelectionChanged(void); \
  NS_IMETHOD OnPerformAction(const char16_t * action); \
  NS_IMETHOD OnPerformActionOnRow(const char16_t * action, int32_t row); \
  NS_IMETHOD OnPerformActionOnCell(const char16_t * action, int32_t row, const char16_t * colID); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULTREEBUILDEROBSERVER(_to) \
  NS_IMETHOD CanDrop(int32_t index, int32_t orientation, nsIDOMDataTransfer *dataTransfer, bool *_retval) { return _to CanDrop(index, orientation, dataTransfer, _retval); } \
  NS_IMETHOD OnDrop(int32_t row, int32_t orientation, nsIDOMDataTransfer *dataTransfer) { return _to OnDrop(row, orientation, dataTransfer); } \
  NS_IMETHOD OnToggleOpenState(int32_t index) { return _to OnToggleOpenState(index); } \
  NS_IMETHOD OnCycleHeader(const char16_t * colID, nsIDOMElement *elt) { return _to OnCycleHeader(colID, elt); } \
  NS_IMETHOD OnCycleCell(int32_t row, const char16_t * colID) { return _to OnCycleCell(row, colID); } \
  NS_IMETHOD OnSelectionChanged(void) { return _to OnSelectionChanged(); } \
  NS_IMETHOD OnPerformAction(const char16_t * action) { return _to OnPerformAction(action); } \
  NS_IMETHOD OnPerformActionOnRow(const char16_t * action, int32_t row) { return _to OnPerformActionOnRow(action, row); } \
  NS_IMETHOD OnPerformActionOnCell(const char16_t * action, int32_t row, const char16_t * colID) { return _to OnPerformActionOnCell(action, row, colID); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULTREEBUILDEROBSERVER(_to) \
  NS_IMETHOD CanDrop(int32_t index, int32_t orientation, nsIDOMDataTransfer *dataTransfer, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanDrop(index, orientation, dataTransfer, _retval); } \
  NS_IMETHOD OnDrop(int32_t row, int32_t orientation, nsIDOMDataTransfer *dataTransfer) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnDrop(row, orientation, dataTransfer); } \
  NS_IMETHOD OnToggleOpenState(int32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnToggleOpenState(index); } \
  NS_IMETHOD OnCycleHeader(const char16_t * colID, nsIDOMElement *elt) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCycleHeader(colID, elt); } \
  NS_IMETHOD OnCycleCell(int32_t row, const char16_t * colID) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCycleCell(row, colID); } \
  NS_IMETHOD OnSelectionChanged(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnSelectionChanged(); } \
  NS_IMETHOD OnPerformAction(const char16_t * action) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPerformAction(action); } \
  NS_IMETHOD OnPerformActionOnRow(const char16_t * action, int32_t row) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPerformActionOnRow(action, row); } \
  NS_IMETHOD OnPerformActionOnCell(const char16_t * action, int32_t row, const char16_t * colID) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPerformActionOnCell(action, row, colID); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULTreeBuilderObserver : public nsIXULTreeBuilderObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULTREEBUILDEROBSERVER

  nsXULTreeBuilderObserver();

private:
  ~nsXULTreeBuilderObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULTreeBuilderObserver, nsIXULTreeBuilderObserver)

nsXULTreeBuilderObserver::nsXULTreeBuilderObserver()
{
  /* member initializers and constructor code */
}

nsXULTreeBuilderObserver::~nsXULTreeBuilderObserver()
{
  /* destructor code */
}

/* boolean canDrop (in long index, in long orientation, in nsIDOMDataTransfer dataTransfer); */
NS_IMETHODIMP nsXULTreeBuilderObserver::CanDrop(int32_t index, int32_t orientation, nsIDOMDataTransfer *dataTransfer, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onDrop (in long row, in long orientation, in nsIDOMDataTransfer dataTransfer); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnDrop(int32_t row, int32_t orientation, nsIDOMDataTransfer *dataTransfer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onToggleOpenState (in long index); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnToggleOpenState(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCycleHeader (in wstring colID, in nsIDOMElement elt); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnCycleHeader(const char16_t * colID, nsIDOMElement *elt)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCycleCell (in long row, in wstring colID); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnCycleCell(int32_t row, const char16_t * colID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onSelectionChanged (); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnSelectionChanged()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPerformAction (in wstring action); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnPerformAction(const char16_t * action)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPerformActionOnRow (in wstring action, in long row); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnPerformActionOnRow(const char16_t * action, int32_t row)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onPerformActionOnCell (in wstring action, in long row, in wstring colID); */
NS_IMETHODIMP nsXULTreeBuilderObserver::OnPerformActionOnCell(const char16_t * action, int32_t row, const char16_t * colID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIXULTreeBuilder */
#define NS_IXULTREEBUILDER_IID_STR "06b31b15-ebf5-4e74-a0e2-6bc0a18a3969"

#define NS_IXULTREEBUILDER_IID \
  {0x06b31b15, 0xebf5, 0x4e74, \
    { 0xa0, 0xe2, 0x6b, 0xc0, 0xa1, 0x8a, 0x39, 0x69 }}

class NS_NO_VTABLE nsIXULTreeBuilder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULTREEBUILDER_IID)

  /* nsIRDFResource getResourceAtIndex (in long aRowIndex); */
  NS_IMETHOD GetResourceAtIndex(int32_t aRowIndex, nsIRDFResource * *_retval) = 0;

  /* long getIndexOfResource (in nsIRDFResource resource); */
  NS_IMETHOD GetIndexOfResource(nsIRDFResource *resource, int32_t *_retval) = 0;

  /* void addObserver (in nsIXULTreeBuilderObserver aObserver); */
  NS_IMETHOD AddObserver(nsIXULTreeBuilderObserver *aObserver) = 0;

  /* void removeObserver (in nsIXULTreeBuilderObserver aObserver); */
  NS_IMETHOD RemoveObserver(nsIXULTreeBuilderObserver *aObserver) = 0;

  /* void sort (in nsIDOMElement aColumnElement); */
  NS_IMETHOD Sort(nsIDOMElement *aColumnElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULTreeBuilder, NS_IXULTREEBUILDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULTREEBUILDER \
  NS_IMETHOD GetResourceAtIndex(int32_t aRowIndex, nsIRDFResource * *_retval); \
  NS_IMETHOD GetIndexOfResource(nsIRDFResource *resource, int32_t *_retval); \
  NS_IMETHOD AddObserver(nsIXULTreeBuilderObserver *aObserver); \
  NS_IMETHOD RemoveObserver(nsIXULTreeBuilderObserver *aObserver); \
  NS_IMETHOD Sort(nsIDOMElement *aColumnElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULTREEBUILDER(_to) \
  NS_IMETHOD GetResourceAtIndex(int32_t aRowIndex, nsIRDFResource * *_retval) { return _to GetResourceAtIndex(aRowIndex, _retval); } \
  NS_IMETHOD GetIndexOfResource(nsIRDFResource *resource, int32_t *_retval) { return _to GetIndexOfResource(resource, _retval); } \
  NS_IMETHOD AddObserver(nsIXULTreeBuilderObserver *aObserver) { return _to AddObserver(aObserver); } \
  NS_IMETHOD RemoveObserver(nsIXULTreeBuilderObserver *aObserver) { return _to RemoveObserver(aObserver); } \
  NS_IMETHOD Sort(nsIDOMElement *aColumnElement) { return _to Sort(aColumnElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULTREEBUILDER(_to) \
  NS_IMETHOD GetResourceAtIndex(int32_t aRowIndex, nsIRDFResource * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResourceAtIndex(aRowIndex, _retval); } \
  NS_IMETHOD GetIndexOfResource(nsIRDFResource *resource, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfResource(resource, _retval); } \
  NS_IMETHOD AddObserver(nsIXULTreeBuilderObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddObserver(aObserver); } \
  NS_IMETHOD RemoveObserver(nsIXULTreeBuilderObserver *aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveObserver(aObserver); } \
  NS_IMETHOD Sort(nsIDOMElement *aColumnElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->Sort(aColumnElement); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULTreeBuilder : public nsIXULTreeBuilder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULTREEBUILDER

  nsXULTreeBuilder();

private:
  ~nsXULTreeBuilder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULTreeBuilder, nsIXULTreeBuilder)

nsXULTreeBuilder::nsXULTreeBuilder()
{
  /* member initializers and constructor code */
}

nsXULTreeBuilder::~nsXULTreeBuilder()
{
  /* destructor code */
}

/* nsIRDFResource getResourceAtIndex (in long aRowIndex); */
NS_IMETHODIMP nsXULTreeBuilder::GetResourceAtIndex(int32_t aRowIndex, nsIRDFResource * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfResource (in nsIRDFResource resource); */
NS_IMETHODIMP nsXULTreeBuilder::GetIndexOfResource(nsIRDFResource *resource, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addObserver (in nsIXULTreeBuilderObserver aObserver); */
NS_IMETHODIMP nsXULTreeBuilder::AddObserver(nsIXULTreeBuilderObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeObserver (in nsIXULTreeBuilderObserver aObserver); */
NS_IMETHODIMP nsXULTreeBuilder::RemoveObserver(nsIXULTreeBuilderObserver *aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sort (in nsIDOMElement aColumnElement); */
NS_IMETHODIMP nsXULTreeBuilder::Sort(nsIDOMElement *aColumnElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULTemplateBuilder_h__ */
