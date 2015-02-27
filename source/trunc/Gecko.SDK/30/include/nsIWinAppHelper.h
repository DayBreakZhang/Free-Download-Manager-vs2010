/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWinAppHelper.idl
 */

#ifndef __gen_nsIWinAppHelper_h__
#define __gen_nsIWinAppHelper_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWinAppHelper */
#define NS_IWINAPPHELPER_IID_STR "dc263ca8-b257-47eb-b5b7-339d9e0b90f7"

#define NS_IWINAPPHELPER_IID \
  {0xdc263ca8, 0xb257, 0x47eb, \
    { 0xb5, 0xb7, 0x33, 0x9d, 0x9e, 0x0b, 0x90, 0xf7 }}

class NS_NO_VTABLE nsIWinAppHelper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWINAPPHELPER_IID)

  /* readonly attribute boolean userCanElevate; */
  NS_IMETHOD GetUserCanElevate(bool *aUserCanElevate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWinAppHelper, NS_IWINAPPHELPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWINAPPHELPER \
  NS_IMETHOD GetUserCanElevate(bool *aUserCanElevate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWINAPPHELPER(_to) \
  NS_IMETHOD GetUserCanElevate(bool *aUserCanElevate) { return _to GetUserCanElevate(aUserCanElevate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWINAPPHELPER(_to) \
  NS_IMETHOD GetUserCanElevate(bool *aUserCanElevate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserCanElevate(aUserCanElevate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWinAppHelper : public nsIWinAppHelper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWINAPPHELPER

  nsWinAppHelper();

private:
  ~nsWinAppHelper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWinAppHelper, nsIWinAppHelper)

nsWinAppHelper::nsWinAppHelper()
{
  /* member initializers and constructor code */
}

nsWinAppHelper::~nsWinAppHelper()
{
  /* destructor code */
}

/* readonly attribute boolean userCanElevate; */
NS_IMETHODIMP nsWinAppHelper::GetUserCanElevate(bool *aUserCanElevate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWinAppHelper_h__ */
