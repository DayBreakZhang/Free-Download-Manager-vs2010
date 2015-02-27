/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMSmsFilter.idl
 */

#ifndef __gen_nsIDOMSmsFilter_h__
#define __gen_nsIDOMSmsFilter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozSmsFilter */
#define NS_IDOMMOZSMSFILTER_IID_STR "17890b60-0367-45c6-9729-62e5bf349b2b"

#define NS_IDOMMOZSMSFILTER_IID \
  {0x17890b60, 0x0367, 0x45c6, \
    { 0x97, 0x29, 0x62, 0xe5, 0xbf, 0x34, 0x9b, 0x2b }}

class NS_NO_VTABLE nsIDOMMozSmsFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZSMSFILTER_IID)

  /* [implicit_jscontext] attribute jsval startDate; */
  NS_IMETHOD GetStartDate(JSContext* cx, JS::MutableHandleValue aStartDate) = 0;
  NS_IMETHOD SetStartDate(JSContext* cx, JS::HandleValue aStartDate) = 0;

  /* [implicit_jscontext] attribute jsval endDate; */
  NS_IMETHOD GetEndDate(JSContext* cx, JS::MutableHandleValue aEndDate) = 0;
  NS_IMETHOD SetEndDate(JSContext* cx, JS::HandleValue aEndDate) = 0;

  /* [implicit_jscontext] attribute jsval numbers; */
  NS_IMETHOD GetNumbers(JSContext* cx, JS::MutableHandleValue aNumbers) = 0;
  NS_IMETHOD SetNumbers(JSContext* cx, JS::HandleValue aNumbers) = 0;

  /* [Null(Empty)] attribute DOMString delivery; */
  NS_IMETHOD GetDelivery(nsAString & aDelivery) = 0;
  NS_IMETHOD SetDelivery(const nsAString & aDelivery) = 0;

  /* [implicit_jscontext] attribute jsval read; */
  NS_IMETHOD GetRead(JSContext* cx, JS::MutableHandleValue aRead) = 0;
  NS_IMETHOD SetRead(JSContext* cx, JS::HandleValue aRead) = 0;

  /* [implicit_jscontext] attribute jsval threadId; */
  NS_IMETHOD GetThreadId(JSContext* cx, JS::MutableHandleValue aThreadId) = 0;
  NS_IMETHOD SetThreadId(JSContext* cx, JS::HandleValue aThreadId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozSmsFilter, NS_IDOMMOZSMSFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZSMSFILTER \
  NS_IMETHOD GetStartDate(JSContext* cx, JS::MutableHandleValue aStartDate); \
  NS_IMETHOD SetStartDate(JSContext* cx, JS::HandleValue aStartDate); \
  NS_IMETHOD GetEndDate(JSContext* cx, JS::MutableHandleValue aEndDate); \
  NS_IMETHOD SetEndDate(JSContext* cx, JS::HandleValue aEndDate); \
  NS_IMETHOD GetNumbers(JSContext* cx, JS::MutableHandleValue aNumbers); \
  NS_IMETHOD SetNumbers(JSContext* cx, JS::HandleValue aNumbers); \
  NS_IMETHOD GetDelivery(nsAString & aDelivery); \
  NS_IMETHOD SetDelivery(const nsAString & aDelivery); \
  NS_IMETHOD GetRead(JSContext* cx, JS::MutableHandleValue aRead); \
  NS_IMETHOD SetRead(JSContext* cx, JS::HandleValue aRead); \
  NS_IMETHOD GetThreadId(JSContext* cx, JS::MutableHandleValue aThreadId); \
  NS_IMETHOD SetThreadId(JSContext* cx, JS::HandleValue aThreadId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZSMSFILTER(_to) \
  NS_IMETHOD GetStartDate(JSContext* cx, JS::MutableHandleValue aStartDate) { return _to GetStartDate(cx, aStartDate); } \
  NS_IMETHOD SetStartDate(JSContext* cx, JS::HandleValue aStartDate) { return _to SetStartDate(cx, aStartDate); } \
  NS_IMETHOD GetEndDate(JSContext* cx, JS::MutableHandleValue aEndDate) { return _to GetEndDate(cx, aEndDate); } \
  NS_IMETHOD SetEndDate(JSContext* cx, JS::HandleValue aEndDate) { return _to SetEndDate(cx, aEndDate); } \
  NS_IMETHOD GetNumbers(JSContext* cx, JS::MutableHandleValue aNumbers) { return _to GetNumbers(cx, aNumbers); } \
  NS_IMETHOD SetNumbers(JSContext* cx, JS::HandleValue aNumbers) { return _to SetNumbers(cx, aNumbers); } \
  NS_IMETHOD GetDelivery(nsAString & aDelivery) { return _to GetDelivery(aDelivery); } \
  NS_IMETHOD SetDelivery(const nsAString & aDelivery) { return _to SetDelivery(aDelivery); } \
  NS_IMETHOD GetRead(JSContext* cx, JS::MutableHandleValue aRead) { return _to GetRead(cx, aRead); } \
  NS_IMETHOD SetRead(JSContext* cx, JS::HandleValue aRead) { return _to SetRead(cx, aRead); } \
  NS_IMETHOD GetThreadId(JSContext* cx, JS::MutableHandleValue aThreadId) { return _to GetThreadId(cx, aThreadId); } \
  NS_IMETHOD SetThreadId(JSContext* cx, JS::HandleValue aThreadId) { return _to SetThreadId(cx, aThreadId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZSMSFILTER(_to) \
  NS_IMETHOD GetStartDate(JSContext* cx, JS::MutableHandleValue aStartDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartDate(cx, aStartDate); } \
  NS_IMETHOD SetStartDate(JSContext* cx, JS::HandleValue aStartDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartDate(cx, aStartDate); } \
  NS_IMETHOD GetEndDate(JSContext* cx, JS::MutableHandleValue aEndDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndDate(cx, aEndDate); } \
  NS_IMETHOD SetEndDate(JSContext* cx, JS::HandleValue aEndDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndDate(cx, aEndDate); } \
  NS_IMETHOD GetNumbers(JSContext* cx, JS::MutableHandleValue aNumbers) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumbers(cx, aNumbers); } \
  NS_IMETHOD SetNumbers(JSContext* cx, JS::HandleValue aNumbers) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNumbers(cx, aNumbers); } \
  NS_IMETHOD GetDelivery(nsAString & aDelivery) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelivery(aDelivery); } \
  NS_IMETHOD SetDelivery(const nsAString & aDelivery) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDelivery(aDelivery); } \
  NS_IMETHOD GetRead(JSContext* cx, JS::MutableHandleValue aRead) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRead(cx, aRead); } \
  NS_IMETHOD SetRead(JSContext* cx, JS::HandleValue aRead) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRead(cx, aRead); } \
  NS_IMETHOD GetThreadId(JSContext* cx, JS::MutableHandleValue aThreadId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreadId(cx, aThreadId); } \
  NS_IMETHOD SetThreadId(JSContext* cx, JS::HandleValue aThreadId) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetThreadId(cx, aThreadId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozSmsFilter : public nsIDOMMozSmsFilter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZSMSFILTER

  nsDOMMozSmsFilter();

private:
  ~nsDOMMozSmsFilter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozSmsFilter, nsIDOMMozSmsFilter)

nsDOMMozSmsFilter::nsDOMMozSmsFilter()
{
  /* member initializers and constructor code */
}

nsDOMMozSmsFilter::~nsDOMMozSmsFilter()
{
  /* destructor code */
}

/* [implicit_jscontext] attribute jsval startDate; */
NS_IMETHODIMP nsDOMMozSmsFilter::GetStartDate(JSContext* cx, JS::MutableHandleValue aStartDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsFilter::SetStartDate(JSContext* cx, JS::HandleValue aStartDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval endDate; */
NS_IMETHODIMP nsDOMMozSmsFilter::GetEndDate(JSContext* cx, JS::MutableHandleValue aEndDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsFilter::SetEndDate(JSContext* cx, JS::HandleValue aEndDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval numbers; */
NS_IMETHODIMP nsDOMMozSmsFilter::GetNumbers(JSContext* cx, JS::MutableHandleValue aNumbers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsFilter::SetNumbers(JSContext* cx, JS::HandleValue aNumbers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [Null(Empty)] attribute DOMString delivery; */
NS_IMETHODIMP nsDOMMozSmsFilter::GetDelivery(nsAString & aDelivery)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsFilter::SetDelivery(const nsAString & aDelivery)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval read; */
NS_IMETHODIMP nsDOMMozSmsFilter::GetRead(JSContext* cx, JS::MutableHandleValue aRead)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsFilter::SetRead(JSContext* cx, JS::HandleValue aRead)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval threadId; */
NS_IMETHODIMP nsDOMMozSmsFilter::GetThreadId(JSContext* cx, JS::MutableHandleValue aThreadId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsFilter::SetThreadId(JSContext* cx, JS::HandleValue aThreadId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSmsFilter_h__ */
