/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mobilemessage/interfaces/nsIDOMSmsFilter.idl
 */

#ifndef __gen_nsIDOMSmsFilter_h__
#define __gen_nsIDOMSmsFilter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozSmsFilter */
#define NS_IDOMMOZSMSFILTER_IID_STR "ce055c33-553d-4b0e-9bd8-91d93a057c90"

#define NS_IDOMMOZSMSFILTER_IID \
  {0xce055c33, 0x553d, 0x4b0e, \
    { 0x9b, 0xd8, 0x91, 0xd9, 0x3a, 0x05, 0x7c, 0x90 }}

class NS_NO_VTABLE nsIDOMMozSmsFilter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZSMSFILTER_IID)

  /* [implicit_jscontext] attribute jsval startDate; */
  NS_IMETHOD GetStartDate(JSContext* cx, JS::Value *aStartDate) = 0;
  NS_IMETHOD SetStartDate(JSContext* cx, const JS::Value & aStartDate) = 0;

  /* [implicit_jscontext] attribute jsval endDate; */
  NS_IMETHOD GetEndDate(JSContext* cx, JS::Value *aEndDate) = 0;
  NS_IMETHOD SetEndDate(JSContext* cx, const JS::Value & aEndDate) = 0;

  /* [implicit_jscontext] attribute jsval numbers; */
  NS_IMETHOD GetNumbers(JSContext* cx, JS::Value *aNumbers) = 0;
  NS_IMETHOD SetNumbers(JSContext* cx, const JS::Value & aNumbers) = 0;

  /* [Null(Empty)] attribute DOMString delivery; */
  NS_IMETHOD GetDelivery(nsAString & aDelivery) = 0;
  NS_IMETHOD SetDelivery(const nsAString & aDelivery) = 0;

  /* [implicit_jscontext] attribute jsval read; */
  NS_IMETHOD GetRead(JSContext* cx, JS::Value *aRead) = 0;
  NS_IMETHOD SetRead(JSContext* cx, const JS::Value & aRead) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozSmsFilter, NS_IDOMMOZSMSFILTER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZSMSFILTER \
  NS_IMETHOD GetStartDate(JSContext* cx, JS::Value *aStartDate); \
  NS_IMETHOD SetStartDate(JSContext* cx, const JS::Value & aStartDate); \
  NS_IMETHOD GetEndDate(JSContext* cx, JS::Value *aEndDate); \
  NS_IMETHOD SetEndDate(JSContext* cx, const JS::Value & aEndDate); \
  NS_IMETHOD GetNumbers(JSContext* cx, JS::Value *aNumbers); \
  NS_IMETHOD SetNumbers(JSContext* cx, const JS::Value & aNumbers); \
  NS_IMETHOD GetDelivery(nsAString & aDelivery); \
  NS_IMETHOD SetDelivery(const nsAString & aDelivery); \
  NS_IMETHOD GetRead(JSContext* cx, JS::Value *aRead); \
  NS_IMETHOD SetRead(JSContext* cx, const JS::Value & aRead); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZSMSFILTER(_to) \
  NS_IMETHOD GetStartDate(JSContext* cx, JS::Value *aStartDate) { return _to GetStartDate(cx, aStartDate); } \
  NS_IMETHOD SetStartDate(JSContext* cx, const JS::Value & aStartDate) { return _to SetStartDate(cx, aStartDate); } \
  NS_IMETHOD GetEndDate(JSContext* cx, JS::Value *aEndDate) { return _to GetEndDate(cx, aEndDate); } \
  NS_IMETHOD SetEndDate(JSContext* cx, const JS::Value & aEndDate) { return _to SetEndDate(cx, aEndDate); } \
  NS_IMETHOD GetNumbers(JSContext* cx, JS::Value *aNumbers) { return _to GetNumbers(cx, aNumbers); } \
  NS_IMETHOD SetNumbers(JSContext* cx, const JS::Value & aNumbers) { return _to SetNumbers(cx, aNumbers); } \
  NS_IMETHOD GetDelivery(nsAString & aDelivery) { return _to GetDelivery(aDelivery); } \
  NS_IMETHOD SetDelivery(const nsAString & aDelivery) { return _to SetDelivery(aDelivery); } \
  NS_IMETHOD GetRead(JSContext* cx, JS::Value *aRead) { return _to GetRead(cx, aRead); } \
  NS_IMETHOD SetRead(JSContext* cx, const JS::Value & aRead) { return _to SetRead(cx, aRead); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZSMSFILTER(_to) \
  NS_IMETHOD GetStartDate(JSContext* cx, JS::Value *aStartDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartDate(cx, aStartDate); } \
  NS_IMETHOD SetStartDate(JSContext* cx, const JS::Value & aStartDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStartDate(cx, aStartDate); } \
  NS_IMETHOD GetEndDate(JSContext* cx, JS::Value *aEndDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndDate(cx, aEndDate); } \
  NS_IMETHOD SetEndDate(JSContext* cx, const JS::Value & aEndDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEndDate(cx, aEndDate); } \
  NS_IMETHOD GetNumbers(JSContext* cx, JS::Value *aNumbers) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumbers(cx, aNumbers); } \
  NS_IMETHOD SetNumbers(JSContext* cx, const JS::Value & aNumbers) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNumbers(cx, aNumbers); } \
  NS_IMETHOD GetDelivery(nsAString & aDelivery) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelivery(aDelivery); } \
  NS_IMETHOD SetDelivery(const nsAString & aDelivery) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDelivery(aDelivery); } \
  NS_IMETHOD GetRead(JSContext* cx, JS::Value *aRead) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRead(cx, aRead); } \
  NS_IMETHOD SetRead(JSContext* cx, const JS::Value & aRead) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRead(cx, aRead); } 

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
NS_IMETHODIMP nsDOMMozSmsFilter::GetStartDate(JSContext* cx, JS::Value *aStartDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsFilter::SetStartDate(JSContext* cx, const JS::Value & aStartDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval endDate; */
NS_IMETHODIMP nsDOMMozSmsFilter::GetEndDate(JSContext* cx, JS::Value *aEndDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsFilter::SetEndDate(JSContext* cx, const JS::Value & aEndDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval numbers; */
NS_IMETHODIMP nsDOMMozSmsFilter::GetNumbers(JSContext* cx, JS::Value *aNumbers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsFilter::SetNumbers(JSContext* cx, const JS::Value & aNumbers)
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
NS_IMETHODIMP nsDOMMozSmsFilter::GetRead(JSContext* cx, JS::Value *aRead)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozSmsFilter::SetRead(JSContext* cx, const JS::Value & aRead)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSmsFilter_h__ */
