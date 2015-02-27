/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/xul/templates/public/nsIXULTemplateResult.idl
 */

#ifndef __gen_nsIXULTemplateResult_h__
#define __gen_nsIXULTemplateResult_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAtom; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsIRDFResource; /* forward declaration */


/* starting interface:    nsIXULTemplateResult */
#define NS_IXULTEMPLATERESULT_IID_STR "ebea0230-36fa-41b7-8e31-760806057965"

#define NS_IXULTEMPLATERESULT_IID \
  {0xebea0230, 0x36fa, 0x41b7, \
    { 0x8e, 0x31, 0x76, 0x08, 0x06, 0x05, 0x79, 0x65 }}

class NS_NO_VTABLE nsIXULTemplateResult : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULTEMPLATERESULT_IID)

  /* readonly attribute boolean isContainer; */
  NS_IMETHOD GetIsContainer(bool *aIsContainer) = 0;

  /* readonly attribute boolean isEmpty; */
  NS_IMETHOD GetIsEmpty(bool *aIsEmpty) = 0;

  /* readonly attribute boolean mayProcessChildren; */
  NS_IMETHOD GetMayProcessChildren(bool *aMayProcessChildren) = 0;

  /* readonly attribute AString id; */
  NS_IMETHOD GetId(nsAString & aId) = 0;

  /* readonly attribute nsIRDFResource resource; */
  NS_IMETHOD GetResource(nsIRDFResource * *aResource) = 0;

  /* readonly attribute AString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* AString getBindingFor (in nsIAtom aVar); */
  NS_IMETHOD GetBindingFor(nsIAtom *aVar, nsAString & _retval) = 0;

  /* nsISupports getBindingObjectFor (in nsIAtom aVar); */
  NS_IMETHOD GetBindingObjectFor(nsIAtom *aVar, nsISupports * *_retval) = 0;

  /* void ruleMatched (in nsISupports aQuery, in nsIDOMNode aRuleNode); */
  NS_IMETHOD RuleMatched(nsISupports *aQuery, nsIDOMNode *aRuleNode) = 0;

  /* void hasBeenRemoved (); */
  NS_IMETHOD HasBeenRemoved(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULTemplateResult, NS_IXULTEMPLATERESULT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULTEMPLATERESULT \
  NS_IMETHOD GetIsContainer(bool *aIsContainer); \
  NS_IMETHOD GetIsEmpty(bool *aIsEmpty); \
  NS_IMETHOD GetMayProcessChildren(bool *aMayProcessChildren); \
  NS_IMETHOD GetId(nsAString & aId); \
  NS_IMETHOD GetResource(nsIRDFResource * *aResource); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetBindingFor(nsIAtom *aVar, nsAString & _retval); \
  NS_IMETHOD GetBindingObjectFor(nsIAtom *aVar, nsISupports * *_retval); \
  NS_IMETHOD RuleMatched(nsISupports *aQuery, nsIDOMNode *aRuleNode); \
  NS_IMETHOD HasBeenRemoved(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULTEMPLATERESULT(_to) \
  NS_IMETHOD GetIsContainer(bool *aIsContainer) { return _to GetIsContainer(aIsContainer); } \
  NS_IMETHOD GetIsEmpty(bool *aIsEmpty) { return _to GetIsEmpty(aIsEmpty); } \
  NS_IMETHOD GetMayProcessChildren(bool *aMayProcessChildren) { return _to GetMayProcessChildren(aMayProcessChildren); } \
  NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_IMETHOD GetResource(nsIRDFResource * *aResource) { return _to GetResource(aResource); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetBindingFor(nsIAtom *aVar, nsAString & _retval) { return _to GetBindingFor(aVar, _retval); } \
  NS_IMETHOD GetBindingObjectFor(nsIAtom *aVar, nsISupports * *_retval) { return _to GetBindingObjectFor(aVar, _retval); } \
  NS_IMETHOD RuleMatched(nsISupports *aQuery, nsIDOMNode *aRuleNode) { return _to RuleMatched(aQuery, aRuleNode); } \
  NS_IMETHOD HasBeenRemoved(void) { return _to HasBeenRemoved(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULTEMPLATERESULT(_to) \
  NS_IMETHOD GetIsContainer(bool *aIsContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsContainer(aIsContainer); } \
  NS_IMETHOD GetIsEmpty(bool *aIsEmpty) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsEmpty(aIsEmpty); } \
  NS_IMETHOD GetMayProcessChildren(bool *aMayProcessChildren) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMayProcessChildren(aMayProcessChildren); } \
  NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetResource(nsIRDFResource * *aResource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResource(aResource); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetBindingFor(nsIAtom *aVar, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBindingFor(aVar, _retval); } \
  NS_IMETHOD GetBindingObjectFor(nsIAtom *aVar, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBindingObjectFor(aVar, _retval); } \
  NS_IMETHOD RuleMatched(nsISupports *aQuery, nsIDOMNode *aRuleNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->RuleMatched(aQuery, aRuleNode); } \
  NS_IMETHOD HasBeenRemoved(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasBeenRemoved(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULTemplateResult : public nsIXULTemplateResult
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULTEMPLATERESULT

  nsXULTemplateResult();

private:
  ~nsXULTemplateResult();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULTemplateResult, nsIXULTemplateResult)

nsXULTemplateResult::nsXULTemplateResult()
{
  /* member initializers and constructor code */
}

nsXULTemplateResult::~nsXULTemplateResult()
{
  /* destructor code */
}

/* readonly attribute boolean isContainer; */
NS_IMETHODIMP nsXULTemplateResult::GetIsContainer(bool *aIsContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isEmpty; */
NS_IMETHODIMP nsXULTemplateResult::GetIsEmpty(bool *aIsEmpty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean mayProcessChildren; */
NS_IMETHODIMP nsXULTemplateResult::GetMayProcessChildren(bool *aMayProcessChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString id; */
NS_IMETHODIMP nsXULTemplateResult::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIRDFResource resource; */
NS_IMETHODIMP nsXULTemplateResult::GetResource(nsIRDFResource * *aResource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString type; */
NS_IMETHODIMP nsXULTemplateResult::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getBindingFor (in nsIAtom aVar); */
NS_IMETHODIMP nsXULTemplateResult::GetBindingFor(nsIAtom *aVar, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getBindingObjectFor (in nsIAtom aVar); */
NS_IMETHODIMP nsXULTemplateResult::GetBindingObjectFor(nsIAtom *aVar, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ruleMatched (in nsISupports aQuery, in nsIDOMNode aRuleNode); */
NS_IMETHODIMP nsXULTemplateResult::RuleMatched(nsISupports *aQuery, nsIDOMNode *aRuleNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void hasBeenRemoved (); */
NS_IMETHODIMP nsXULTemplateResult::HasBeenRemoved()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULTemplateResult_h__ */
