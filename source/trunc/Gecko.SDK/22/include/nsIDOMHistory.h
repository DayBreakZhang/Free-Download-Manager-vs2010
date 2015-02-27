/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/base/nsIDOMHistory.idl
 */

#ifndef __gen_nsIDOMHistory_h__
#define __gen_nsIDOMHistory_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
struct JSContext;
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMHistory */
#define NS_IDOMHISTORY_IID_STR "d5a3006b-dd6b-4ba3-81be-6559f8889e60"

#define NS_IDOMHISTORY_IID \
  {0xd5a3006b, 0xdd6b, 0x4ba3, \
    { 0x81, 0xbe, 0x65, 0x59, 0xf8, 0x88, 0x9e, 0x60 }}

class NS_NO_VTABLE nsIDOMHistory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHISTORY_IID)

  /* readonly attribute long length; */
  NS_IMETHOD GetLength(int32_t *aLength) = 0;

  /* readonly attribute DOMString current; */
  NS_IMETHOD GetCurrent(nsAString & aCurrent) = 0;

  /* readonly attribute DOMString previous; */
  NS_IMETHOD GetPrevious(nsAString & aPrevious) = 0;

  /* readonly attribute DOMString next; */
  NS_IMETHOD GetNext(nsAString & aNext) = 0;

  /* void back (); */
  NS_IMETHOD Back(void) = 0;

  /* void forward (); */
  NS_IMETHOD Forward(void) = 0;

  /* void go ([optional] in long aDelta); */
  NS_IMETHOD Go(int32_t aDelta) = 0;

  /* DOMString item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) = 0;

  /* [implicit_jscontext] void pushState (in nsIVariant aData, in DOMString aTitle, [optional] in DOMString aURL); */
  NS_IMETHOD PushState(nsIVariant *aData, const nsAString & aTitle, const nsAString & aURL, JSContext* cx) = 0;

  /* [implicit_jscontext] void replaceState (in nsIVariant aData, in DOMString aTitle, [optional] in DOMString aURL); */
  NS_IMETHOD ReplaceState(nsIVariant *aData, const nsAString & aTitle, const nsAString & aURL, JSContext* cx) = 0;

  /* readonly attribute nsIVariant state; */
  NS_IMETHOD GetState(nsIVariant * *aState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHistory, NS_IDOMHISTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHISTORY \
  NS_IMETHOD GetLength(int32_t *aLength); \
  NS_IMETHOD GetCurrent(nsAString & aCurrent); \
  NS_IMETHOD GetPrevious(nsAString & aPrevious); \
  NS_IMETHOD GetNext(nsAString & aNext); \
  NS_IMETHOD Back(void); \
  NS_IMETHOD Forward(void); \
  NS_IMETHOD Go(int32_t aDelta); \
  NS_IMETHOD Item(uint32_t index, nsAString & _retval); \
  NS_IMETHOD PushState(nsIVariant *aData, const nsAString & aTitle, const nsAString & aURL, JSContext* cx); \
  NS_IMETHOD ReplaceState(nsIVariant *aData, const nsAString & aTitle, const nsAString & aURL, JSContext* cx); \
  NS_IMETHOD GetState(nsIVariant * *aState); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHISTORY(_to) \
  NS_IMETHOD GetLength(int32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD GetCurrent(nsAString & aCurrent) { return _to GetCurrent(aCurrent); } \
  NS_IMETHOD GetPrevious(nsAString & aPrevious) { return _to GetPrevious(aPrevious); } \
  NS_IMETHOD GetNext(nsAString & aNext) { return _to GetNext(aNext); } \
  NS_IMETHOD Back(void) { return _to Back(); } \
  NS_IMETHOD Forward(void) { return _to Forward(); } \
  NS_IMETHOD Go(int32_t aDelta) { return _to Go(aDelta); } \
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) { return _to Item(index, _retval); } \
  NS_IMETHOD PushState(nsIVariant *aData, const nsAString & aTitle, const nsAString & aURL, JSContext* cx) { return _to PushState(aData, aTitle, aURL, cx); } \
  NS_IMETHOD ReplaceState(nsIVariant *aData, const nsAString & aTitle, const nsAString & aURL, JSContext* cx) { return _to ReplaceState(aData, aTitle, aURL, cx); } \
  NS_IMETHOD GetState(nsIVariant * *aState) { return _to GetState(aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHISTORY(_to) \
  NS_IMETHOD GetLength(int32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD GetCurrent(nsAString & aCurrent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrent(aCurrent); } \
  NS_IMETHOD GetPrevious(nsAString & aPrevious) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrevious(aPrevious); } \
  NS_IMETHOD GetNext(nsAString & aNext) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNext(aNext); } \
  NS_IMETHOD Back(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Back(); } \
  NS_IMETHOD Forward(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Forward(); } \
  NS_IMETHOD Go(int32_t aDelta) { return !_to ? NS_ERROR_NULL_POINTER : _to->Go(aDelta); } \
  NS_IMETHOD Item(uint32_t index, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD PushState(nsIVariant *aData, const nsAString & aTitle, const nsAString & aURL, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->PushState(aData, aTitle, aURL, cx); } \
  NS_IMETHOD ReplaceState(nsIVariant *aData, const nsAString & aTitle, const nsAString & aURL, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceState(aData, aTitle, aURL, cx); } \
  NS_IMETHOD GetState(nsIVariant * *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHistory : public nsIDOMHistory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHISTORY

  nsDOMHistory();

private:
  ~nsDOMHistory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHistory, nsIDOMHistory)

nsDOMHistory::nsDOMHistory()
{
  /* member initializers and constructor code */
}

nsDOMHistory::~nsDOMHistory()
{
  /* destructor code */
}

/* readonly attribute long length; */
NS_IMETHODIMP nsDOMHistory::GetLength(int32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString current; */
NS_IMETHODIMP nsDOMHistory::GetCurrent(nsAString & aCurrent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString previous; */
NS_IMETHODIMP nsDOMHistory::GetPrevious(nsAString & aPrevious)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString next; */
NS_IMETHODIMP nsDOMHistory::GetNext(nsAString & aNext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void back (); */
NS_IMETHODIMP nsDOMHistory::Back()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forward (); */
NS_IMETHODIMP nsDOMHistory::Forward()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void go ([optional] in long aDelta); */
NS_IMETHODIMP nsDOMHistory::Go(int32_t aDelta)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString item (in unsigned long index); */
NS_IMETHODIMP nsDOMHistory::Item(uint32_t index, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void pushState (in nsIVariant aData, in DOMString aTitle, [optional] in DOMString aURL); */
NS_IMETHODIMP nsDOMHistory::PushState(nsIVariant *aData, const nsAString & aTitle, const nsAString & aURL, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void replaceState (in nsIVariant aData, in DOMString aTitle, [optional] in DOMString aURL); */
NS_IMETHODIMP nsDOMHistory::ReplaceState(nsIVariant *aData, const nsAString & aTitle, const nsAString & aURL, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant state; */
NS_IMETHODIMP nsDOMHistory::GetState(nsIVariant * *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHistory_h__ */
