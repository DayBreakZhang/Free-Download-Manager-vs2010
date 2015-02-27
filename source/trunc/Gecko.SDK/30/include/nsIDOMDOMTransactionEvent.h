/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDOMTransactionEvent.idl
 */

#ifndef __gen_nsIDOMDOMTransactionEvent_h__
#define __gen_nsIDOMDOMTransactionEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMDOMTransactionEvent */
#define NS_IDOMDOMTRANSACTIONEVENT_IID_STR "f57f7c46-d420-4f32-a61b-0eb585d30ee1"

#define NS_IDOMDOMTRANSACTIONEVENT_IID \
  {0xf57f7c46, 0xd420, 0x4f32, \
    { 0xa6, 0x1b, 0x0e, 0xb5, 0x85, 0xd3, 0x0e, 0xe1 }}

class NS_NO_VTABLE nsIDOMDOMTransactionEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMTRANSACTIONEVENT_IID)

  /* readonly attribute nsIVariant transactions; */
  NS_IMETHOD GetTransactions(nsIVariant * *aTransactions) = 0;

  /* void initDOMTransactionEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean canCancelArg, in nsIVariant transactions); */
  NS_IMETHOD InitDOMTransactionEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, nsIVariant *transactions) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMTransactionEvent, NS_IDOMDOMTRANSACTIONEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMTRANSACTIONEVENT \
  NS_IMETHOD GetTransactions(nsIVariant * *aTransactions); \
  NS_IMETHOD InitDOMTransactionEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, nsIVariant *transactions); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMTRANSACTIONEVENT(_to) \
  NS_IMETHOD GetTransactions(nsIVariant * *aTransactions) { return _to GetTransactions(aTransactions); } \
  NS_IMETHOD InitDOMTransactionEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, nsIVariant *transactions) { return _to InitDOMTransactionEvent(typeArg, canBubbleArg, canCancelArg, transactions); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMTRANSACTIONEVENT(_to) \
  NS_IMETHOD GetTransactions(nsIVariant * *aTransactions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransactions(aTransactions); } \
  NS_IMETHOD InitDOMTransactionEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, nsIVariant *transactions) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitDOMTransactionEvent(typeArg, canBubbleArg, canCancelArg, transactions); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMTransactionEvent : public nsIDOMDOMTransactionEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMTRANSACTIONEVENT

  nsDOMDOMTransactionEvent();

private:
  ~nsDOMDOMTransactionEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMTransactionEvent, nsIDOMDOMTransactionEvent)

nsDOMDOMTransactionEvent::nsDOMDOMTransactionEvent()
{
  /* member initializers and constructor code */
}

nsDOMDOMTransactionEvent::~nsDOMDOMTransactionEvent()
{
  /* destructor code */
}

/* readonly attribute nsIVariant transactions; */
NS_IMETHODIMP nsDOMDOMTransactionEvent::GetTransactions(nsIVariant * *aTransactions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initDOMTransactionEvent (in DOMString typeArg, in boolean canBubbleArg, in boolean canCancelArg, in nsIVariant transactions); */
NS_IMETHODIMP nsDOMDOMTransactionEvent::InitDOMTransactionEvent(const nsAString & typeArg, bool canBubbleArg, bool canCancelArg, nsIVariant *transactions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMTransactionEvent_h__ */
