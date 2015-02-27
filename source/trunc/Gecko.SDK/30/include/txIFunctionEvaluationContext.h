/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\txIFunctionEvaluationContext.idl
 */

#ifndef __gen_txIFunctionEvaluationContext_h__
#define __gen_txIFunctionEvaluationContext_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */

class txINodeSet; /* forward declaration */


/* starting interface:    txIFunctionEvaluationContext */
#define TXIFUNCTIONEVALUATIONCONTEXT_IID_STR "0ecbb00c-6a78-11d9-9791-000a95dc234c"

#define TXIFUNCTIONEVALUATIONCONTEXT_IID \
  {0x0ecbb00c, 0x6a78, 0x11d9, \
    { 0x97, 0x91, 0x00, 0x0a, 0x95, 0xdc, 0x23, 0x4c }}

class NS_NO_VTABLE txIFunctionEvaluationContext : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(TXIFUNCTIONEVALUATIONCONTEXT_IID)

  /* readonly attribute uint32_t position; */
  NS_IMETHOD GetPosition(uint32_t *aPosition) = 0;

  /* readonly attribute uint32_t size; */
  NS_IMETHOD GetSize(uint32_t *aSize) = 0;

  /* readonly attribute nsIDOMNode contextNode; */
  NS_IMETHOD GetContextNode(nsIDOMNode * *aContextNode) = 0;

  /* readonly attribute nsISupports state; */
  NS_IMETHOD GetState(nsISupports * *aState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(txIFunctionEvaluationContext, TXIFUNCTIONEVALUATIONCONTEXT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_TXIFUNCTIONEVALUATIONCONTEXT \
  NS_IMETHOD GetPosition(uint32_t *aPosition); \
  NS_IMETHOD GetSize(uint32_t *aSize); \
  NS_IMETHOD GetContextNode(nsIDOMNode * *aContextNode); \
  NS_IMETHOD GetState(nsISupports * *aState); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_TXIFUNCTIONEVALUATIONCONTEXT(_to) \
  NS_IMETHOD GetPosition(uint32_t *aPosition) { return _to GetPosition(aPosition); } \
  NS_IMETHOD GetSize(uint32_t *aSize) { return _to GetSize(aSize); } \
  NS_IMETHOD GetContextNode(nsIDOMNode * *aContextNode) { return _to GetContextNode(aContextNode); } \
  NS_IMETHOD GetState(nsISupports * *aState) { return _to GetState(aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_TXIFUNCTIONEVALUATIONCONTEXT(_to) \
  NS_IMETHOD GetPosition(uint32_t *aPosition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPosition(aPosition); } \
  NS_IMETHOD GetSize(uint32_t *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_IMETHOD GetContextNode(nsIDOMNode * *aContextNode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContextNode(aContextNode); } \
  NS_IMETHOD GetState(nsISupports * *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class txFunctionEvaluationContext : public txIFunctionEvaluationContext
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_TXIFUNCTIONEVALUATIONCONTEXT

  txFunctionEvaluationContext();

private:
  ~txFunctionEvaluationContext();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(txFunctionEvaluationContext, txIFunctionEvaluationContext)

txFunctionEvaluationContext::txFunctionEvaluationContext()
{
  /* member initializers and constructor code */
}

txFunctionEvaluationContext::~txFunctionEvaluationContext()
{
  /* destructor code */
}

/* readonly attribute uint32_t position; */
NS_IMETHODIMP txFunctionEvaluationContext::GetPosition(uint32_t *aPosition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t size; */
NS_IMETHODIMP txFunctionEvaluationContext::GetSize(uint32_t *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMNode contextNode; */
NS_IMETHODIMP txFunctionEvaluationContext::GetContextNode(nsIDOMNode * *aContextNode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports state; */
NS_IMETHODIMP txFunctionEvaluationContext::GetState(nsISupports * *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_txIFunctionEvaluationContext_h__ */
