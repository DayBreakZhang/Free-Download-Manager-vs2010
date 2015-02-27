/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/xul/templates/public/nsIXULTemplateQueryProcessor.idl
 */

#ifndef __gen_nsIXULTemplateQueryProcessor_h__
#define __gen_nsIXULTemplateQueryProcessor_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAtom; /* forward declaration */

class nsIArray; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */

class nsIXULTemplateResult; /* forward declaration */

class nsIXULTemplateRuleFilter; /* forward declaration */

class nsIXULTemplateBuilder; /* forward declaration */


/* starting interface:    nsIXULTemplateQueryProcessor */
#define NS_IXULTEMPLATEQUERYPROCESSOR_IID_STR "c257573f-444f-468a-ba27-de979dc55fe4"

#define NS_IXULTEMPLATEQUERYPROCESSOR_IID \
  {0xc257573f, 0x444f, 0x468a, \
    { 0xba, 0x27, 0xde, 0x97, 0x9d, 0xc5, 0x5f, 0xe4 }}

class NS_NO_VTABLE nsIXULTemplateQueryProcessor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULTEMPLATEQUERYPROCESSOR_IID)

  /* nsISupports getDatasource (in nsIArray aDataSources, in nsIDOMNode aRootNode, in boolean aIsTrusted, in nsIXULTemplateBuilder aBuilder, out boolean aShouldDelayBuilding); */
  NS_IMETHOD GetDatasource(nsIArray *aDataSources, nsIDOMNode *aRootNode, bool aIsTrusted, nsIXULTemplateBuilder *aBuilder, bool *aShouldDelayBuilding, nsISupports * *_retval) = 0;

  /* void initializeForBuilding (in nsISupports aDatasource, in nsIXULTemplateBuilder aBuilder, in nsIDOMNode aRootNode); */
  NS_IMETHOD InitializeForBuilding(nsISupports *aDatasource, nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aRootNode) = 0;

  /* void done (); */
  NS_IMETHOD Done(void) = 0;

  /* nsISupports compileQuery (in nsIXULTemplateBuilder aBuilder, in nsIDOMNode aQuery, in nsIAtom aRefVariable, in nsIAtom aMemberVariable); */
  NS_IMETHOD CompileQuery(nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aQuery, nsIAtom *aRefVariable, nsIAtom *aMemberVariable, nsISupports * *_retval) = 0;

  /* nsISimpleEnumerator generateResults (in nsISupports aDatasource, in nsIXULTemplateResult aRef, in nsISupports aQuery); */
  NS_IMETHOD GenerateResults(nsISupports *aDatasource, nsIXULTemplateResult *aRef, nsISupports *aQuery, nsISimpleEnumerator * *_retval) = 0;

  /* void addBinding (in nsIDOMNode aRuleNode, in nsIAtom aVar, in nsIAtom aRef, in AString aExpr); */
  NS_IMETHOD AddBinding(nsIDOMNode *aRuleNode, nsIAtom *aVar, nsIAtom *aRef, const nsAString & aExpr) = 0;

  /* nsIXULTemplateResult translateRef (in nsISupports aDatasource, in AString aRefString); */
  NS_IMETHOD TranslateRef(nsISupports *aDatasource, const nsAString & aRefString, nsIXULTemplateResult * *_retval) = 0;

  /* int32_t compareResults (in nsIXULTemplateResult aLeft, in nsIXULTemplateResult aRight, in nsIAtom aVar, in unsigned long aSortHints); */
  NS_IMETHOD CompareResults(nsIXULTemplateResult *aLeft, nsIXULTemplateResult *aRight, nsIAtom *aVar, uint32_t aSortHints, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULTemplateQueryProcessor, NS_IXULTEMPLATEQUERYPROCESSOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULTEMPLATEQUERYPROCESSOR \
  NS_IMETHOD GetDatasource(nsIArray *aDataSources, nsIDOMNode *aRootNode, bool aIsTrusted, nsIXULTemplateBuilder *aBuilder, bool *aShouldDelayBuilding, nsISupports * *_retval); \
  NS_IMETHOD InitializeForBuilding(nsISupports *aDatasource, nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aRootNode); \
  NS_IMETHOD Done(void); \
  NS_IMETHOD CompileQuery(nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aQuery, nsIAtom *aRefVariable, nsIAtom *aMemberVariable, nsISupports * *_retval); \
  NS_IMETHOD GenerateResults(nsISupports *aDatasource, nsIXULTemplateResult *aRef, nsISupports *aQuery, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD AddBinding(nsIDOMNode *aRuleNode, nsIAtom *aVar, nsIAtom *aRef, const nsAString & aExpr); \
  NS_IMETHOD TranslateRef(nsISupports *aDatasource, const nsAString & aRefString, nsIXULTemplateResult * *_retval); \
  NS_IMETHOD CompareResults(nsIXULTemplateResult *aLeft, nsIXULTemplateResult *aRight, nsIAtom *aVar, uint32_t aSortHints, int32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULTEMPLATEQUERYPROCESSOR(_to) \
  NS_IMETHOD GetDatasource(nsIArray *aDataSources, nsIDOMNode *aRootNode, bool aIsTrusted, nsIXULTemplateBuilder *aBuilder, bool *aShouldDelayBuilding, nsISupports * *_retval) { return _to GetDatasource(aDataSources, aRootNode, aIsTrusted, aBuilder, aShouldDelayBuilding, _retval); } \
  NS_IMETHOD InitializeForBuilding(nsISupports *aDatasource, nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aRootNode) { return _to InitializeForBuilding(aDatasource, aBuilder, aRootNode); } \
  NS_IMETHOD Done(void) { return _to Done(); } \
  NS_IMETHOD CompileQuery(nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aQuery, nsIAtom *aRefVariable, nsIAtom *aMemberVariable, nsISupports * *_retval) { return _to CompileQuery(aBuilder, aQuery, aRefVariable, aMemberVariable, _retval); } \
  NS_IMETHOD GenerateResults(nsISupports *aDatasource, nsIXULTemplateResult *aRef, nsISupports *aQuery, nsISimpleEnumerator * *_retval) { return _to GenerateResults(aDatasource, aRef, aQuery, _retval); } \
  NS_IMETHOD AddBinding(nsIDOMNode *aRuleNode, nsIAtom *aVar, nsIAtom *aRef, const nsAString & aExpr) { return _to AddBinding(aRuleNode, aVar, aRef, aExpr); } \
  NS_IMETHOD TranslateRef(nsISupports *aDatasource, const nsAString & aRefString, nsIXULTemplateResult * *_retval) { return _to TranslateRef(aDatasource, aRefString, _retval); } \
  NS_IMETHOD CompareResults(nsIXULTemplateResult *aLeft, nsIXULTemplateResult *aRight, nsIAtom *aVar, uint32_t aSortHints, int32_t *_retval) { return _to CompareResults(aLeft, aRight, aVar, aSortHints, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULTEMPLATEQUERYPROCESSOR(_to) \
  NS_IMETHOD GetDatasource(nsIArray *aDataSources, nsIDOMNode *aRootNode, bool aIsTrusted, nsIXULTemplateBuilder *aBuilder, bool *aShouldDelayBuilding, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDatasource(aDataSources, aRootNode, aIsTrusted, aBuilder, aShouldDelayBuilding, _retval); } \
  NS_IMETHOD InitializeForBuilding(nsISupports *aDatasource, nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aRootNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitializeForBuilding(aDatasource, aBuilder, aRootNode); } \
  NS_IMETHOD Done(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Done(); } \
  NS_IMETHOD CompileQuery(nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aQuery, nsIAtom *aRefVariable, nsIAtom *aMemberVariable, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompileQuery(aBuilder, aQuery, aRefVariable, aMemberVariable, _retval); } \
  NS_IMETHOD GenerateResults(nsISupports *aDatasource, nsIXULTemplateResult *aRef, nsISupports *aQuery, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GenerateResults(aDatasource, aRef, aQuery, _retval); } \
  NS_IMETHOD AddBinding(nsIDOMNode *aRuleNode, nsIAtom *aVar, nsIAtom *aRef, const nsAString & aExpr) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddBinding(aRuleNode, aVar, aRef, aExpr); } \
  NS_IMETHOD TranslateRef(nsISupports *aDatasource, const nsAString & aRefString, nsIXULTemplateResult * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->TranslateRef(aDatasource, aRefString, _retval); } \
  NS_IMETHOD CompareResults(nsIXULTemplateResult *aLeft, nsIXULTemplateResult *aRight, nsIAtom *aVar, uint32_t aSortHints, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompareResults(aLeft, aRight, aVar, aSortHints, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULTemplateQueryProcessor : public nsIXULTemplateQueryProcessor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULTEMPLATEQUERYPROCESSOR

  nsXULTemplateQueryProcessor();

private:
  ~nsXULTemplateQueryProcessor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULTemplateQueryProcessor, nsIXULTemplateQueryProcessor)

nsXULTemplateQueryProcessor::nsXULTemplateQueryProcessor()
{
  /* member initializers and constructor code */
}

nsXULTemplateQueryProcessor::~nsXULTemplateQueryProcessor()
{
  /* destructor code */
}

/* nsISupports getDatasource (in nsIArray aDataSources, in nsIDOMNode aRootNode, in boolean aIsTrusted, in nsIXULTemplateBuilder aBuilder, out boolean aShouldDelayBuilding); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::GetDatasource(nsIArray *aDataSources, nsIDOMNode *aRootNode, bool aIsTrusted, nsIXULTemplateBuilder *aBuilder, bool *aShouldDelayBuilding, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initializeForBuilding (in nsISupports aDatasource, in nsIXULTemplateBuilder aBuilder, in nsIDOMNode aRootNode); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::InitializeForBuilding(nsISupports *aDatasource, nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aRootNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void done (); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::Done()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports compileQuery (in nsIXULTemplateBuilder aBuilder, in nsIDOMNode aQuery, in nsIAtom aRefVariable, in nsIAtom aMemberVariable); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::CompileQuery(nsIXULTemplateBuilder *aBuilder, nsIDOMNode *aQuery, nsIAtom *aRefVariable, nsIAtom *aMemberVariable, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator generateResults (in nsISupports aDatasource, in nsIXULTemplateResult aRef, in nsISupports aQuery); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::GenerateResults(nsISupports *aDatasource, nsIXULTemplateResult *aRef, nsISupports *aQuery, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addBinding (in nsIDOMNode aRuleNode, in nsIAtom aVar, in nsIAtom aRef, in AString aExpr); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::AddBinding(nsIDOMNode *aRuleNode, nsIAtom *aVar, nsIAtom *aRef, const nsAString & aExpr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIXULTemplateResult translateRef (in nsISupports aDatasource, in AString aRefString); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::TranslateRef(nsISupports *aDatasource, const nsAString & aRefString, nsIXULTemplateResult * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* int32_t compareResults (in nsIXULTemplateResult aLeft, in nsIXULTemplateResult aRight, in nsIAtom aVar, in unsigned long aSortHints); */
NS_IMETHODIMP nsXULTemplateQueryProcessor::CompareResults(nsIXULTemplateResult *aLeft, nsIXULTemplateResult *aRight, nsIAtom *aVar, uint32_t aSortHints, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULTemplateQueryProcessor_h__ */
