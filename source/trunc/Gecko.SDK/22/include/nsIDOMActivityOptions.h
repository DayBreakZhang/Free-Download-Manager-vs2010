/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/activities/interfaces/nsIDOMActivityOptions.idl
 */

#ifndef __gen_nsIDOMActivityOptions_h__
#define __gen_nsIDOMActivityOptions_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozActivityOptions */
#define NS_IDOMMOZACTIVITYOPTIONS_IID_STR "f5bf5e9b-f53f-470f-b560-0d6f4c1c98ad"

#define NS_IDOMMOZACTIVITYOPTIONS_IID \
  {0xf5bf5e9b, 0xf53f, 0x470f, \
    { 0xb5, 0x60, 0x0d, 0x6f, 0x4c, 0x1c, 0x98, 0xad }}

class NS_NO_VTABLE nsIDOMMozActivityOptions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZACTIVITYOPTIONS_IID)

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute jsval data; */
  NS_IMETHOD GetData(JS::Value *aData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozActivityOptions, NS_IDOMMOZACTIVITYOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZACTIVITYOPTIONS \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetData(JS::Value *aData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZACTIVITYOPTIONS(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetData(JS::Value *aData) { return _to GetData(aData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZACTIVITYOPTIONS(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetData(JS::Value *aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozActivityOptions : public nsIDOMMozActivityOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZACTIVITYOPTIONS

  nsDOMMozActivityOptions();

private:
  ~nsDOMMozActivityOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozActivityOptions, nsIDOMMozActivityOptions)

nsDOMMozActivityOptions::nsDOMMozActivityOptions()
{
  /* member initializers and constructor code */
}

nsDOMMozActivityOptions::~nsDOMMozActivityOptions()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMMozActivityOptions::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute jsval data; */
NS_IMETHODIMP nsDOMMozActivityOptions::GetData(JS::Value *aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMActivityOptions_h__ */
