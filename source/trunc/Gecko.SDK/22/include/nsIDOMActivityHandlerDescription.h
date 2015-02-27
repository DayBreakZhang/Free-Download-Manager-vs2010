/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/activities/interfaces/nsIDOMActivityHandlerDescription.idl
 */

#ifndef __gen_nsIDOMActivityHandlerDescription_h__
#define __gen_nsIDOMActivityHandlerDescription_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozActivityHandlerDescription */
#define NS_IDOMMOZACTIVITYHANDLERDESCRIPTION_IID_STR "1601d370-08d9-47b7-8802-d4291533b843"

#define NS_IDOMMOZACTIVITYHANDLERDESCRIPTION_IID \
  {0x1601d370, 0x08d9, 0x47b7, \
    { 0x88, 0x02, 0xd4, 0x29, 0x15, 0x33, 0xb8, 0x43 }}

class NS_NO_VTABLE nsIDOMMozActivityHandlerDescription : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZACTIVITYHANDLERDESCRIPTION_IID)

  /* attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute DOMString href; */
  NS_IMETHOD GetHref(nsAString & aHref) = 0;
  NS_IMETHOD SetHref(const nsAString & aHref) = 0;

  /* attribute DOMString disposition; */
  NS_IMETHOD GetDisposition(nsAString & aDisposition) = 0;
  NS_IMETHOD SetDisposition(const nsAString & aDisposition) = 0;

  /* attribute boolean returnValue; */
  NS_IMETHOD GetReturnValue(bool *aReturnValue) = 0;
  NS_IMETHOD SetReturnValue(bool aReturnValue) = 0;

  /* attribute jsval filters; */
  NS_IMETHOD GetFilters(JS::Value *aFilters) = 0;
  NS_IMETHOD SetFilters(const JS::Value & aFilters) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozActivityHandlerDescription, NS_IDOMMOZACTIVITYHANDLERDESCRIPTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZACTIVITYHANDLERDESCRIPTION \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD SetName(const nsAString & aName); \
  NS_IMETHOD GetHref(nsAString & aHref); \
  NS_IMETHOD SetHref(const nsAString & aHref); \
  NS_IMETHOD GetDisposition(nsAString & aDisposition); \
  NS_IMETHOD SetDisposition(const nsAString & aDisposition); \
  NS_IMETHOD GetReturnValue(bool *aReturnValue); \
  NS_IMETHOD SetReturnValue(bool aReturnValue); \
  NS_IMETHOD GetFilters(JS::Value *aFilters); \
  NS_IMETHOD SetFilters(const JS::Value & aFilters); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZACTIVITYHANDLERDESCRIPTION(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_IMETHOD GetHref(nsAString & aHref) { return _to GetHref(aHref); } \
  NS_IMETHOD SetHref(const nsAString & aHref) { return _to SetHref(aHref); } \
  NS_IMETHOD GetDisposition(nsAString & aDisposition) { return _to GetDisposition(aDisposition); } \
  NS_IMETHOD SetDisposition(const nsAString & aDisposition) { return _to SetDisposition(aDisposition); } \
  NS_IMETHOD GetReturnValue(bool *aReturnValue) { return _to GetReturnValue(aReturnValue); } \
  NS_IMETHOD SetReturnValue(bool aReturnValue) { return _to SetReturnValue(aReturnValue); } \
  NS_IMETHOD GetFilters(JS::Value *aFilters) { return _to GetFilters(aFilters); } \
  NS_IMETHOD SetFilters(const JS::Value & aFilters) { return _to SetFilters(aFilters); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZACTIVITYHANDLERDESCRIPTION(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetHref(nsAString & aHref) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHref(aHref); } \
  NS_IMETHOD SetHref(const nsAString & aHref) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHref(aHref); } \
  NS_IMETHOD GetDisposition(nsAString & aDisposition) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisposition(aDisposition); } \
  NS_IMETHOD SetDisposition(const nsAString & aDisposition) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisposition(aDisposition); } \
  NS_IMETHOD GetReturnValue(bool *aReturnValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReturnValue(aReturnValue); } \
  NS_IMETHOD SetReturnValue(bool aReturnValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReturnValue(aReturnValue); } \
  NS_IMETHOD GetFilters(JS::Value *aFilters) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilters(aFilters); } \
  NS_IMETHOD SetFilters(const JS::Value & aFilters) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilters(aFilters); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozActivityHandlerDescription : public nsIDOMMozActivityHandlerDescription
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZACTIVITYHANDLERDESCRIPTION

  nsDOMMozActivityHandlerDescription();

private:
  ~nsDOMMozActivityHandlerDescription();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozActivityHandlerDescription, nsIDOMMozActivityHandlerDescription)

nsDOMMozActivityHandlerDescription::nsDOMMozActivityHandlerDescription()
{
  /* member initializers and constructor code */
}

nsDOMMozActivityHandlerDescription::~nsDOMMozActivityHandlerDescription()
{
  /* destructor code */
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMMozActivityHandlerDescription::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozActivityHandlerDescription::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString href; */
NS_IMETHODIMP nsDOMMozActivityHandlerDescription::GetHref(nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozActivityHandlerDescription::SetHref(const nsAString & aHref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString disposition; */
NS_IMETHODIMP nsDOMMozActivityHandlerDescription::GetDisposition(nsAString & aDisposition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozActivityHandlerDescription::SetDisposition(const nsAString & aDisposition)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean returnValue; */
NS_IMETHODIMP nsDOMMozActivityHandlerDescription::GetReturnValue(bool *aReturnValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozActivityHandlerDescription::SetReturnValue(bool aReturnValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval filters; */
NS_IMETHODIMP nsDOMMozActivityHandlerDescription::GetFilters(JS::Value *aFilters)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozActivityHandlerDescription::SetFilters(const JS::Value & aFilters)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMActivityHandlerDescription_h__ */
