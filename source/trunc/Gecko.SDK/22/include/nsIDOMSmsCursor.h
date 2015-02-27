/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mobilemessage/interfaces/nsIDOMSmsCursor.idl
 */

#ifndef __gen_nsIDOMSmsCursor_h__
#define __gen_nsIDOMSmsCursor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozSmsFilter; /* forward declaration */

class nsIDOMMozSmsMessage; /* forward declaration */


/* starting interface:    nsIDOMMozSmsCursor */
#define NS_IDOMMOZSMSCURSOR_IID_STR "77b41d7e-ccb1-4480-8322-2af7bc437a3c"

#define NS_IDOMMOZSMSCURSOR_IID \
  {0x77b41d7e, 0xccb1, 0x4480, \
    { 0x83, 0x22, 0x2a, 0xf7, 0xbc, 0x43, 0x7a, 0x3c }}

class NS_NO_VTABLE nsIDOMMozSmsCursor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZSMSCURSOR_IID)

  /* readonly attribute nsIDOMMozSmsMessage message; */
  NS_IMETHOD GetMessage(nsIDOMMozSmsMessage * *aMessage) = 0;

  /* void continue (); */
  NS_IMETHOD Continue(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozSmsCursor, NS_IDOMMOZSMSCURSOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZSMSCURSOR \
  NS_IMETHOD GetMessage(nsIDOMMozSmsMessage * *aMessage); \
  NS_IMETHOD Continue(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZSMSCURSOR(_to) \
  NS_IMETHOD GetMessage(nsIDOMMozSmsMessage * *aMessage) { return _to GetMessage(aMessage); } \
  NS_IMETHOD Continue(void) { return _to Continue(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZSMSCURSOR(_to) \
  NS_IMETHOD GetMessage(nsIDOMMozSmsMessage * *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessage(aMessage); } \
  NS_IMETHOD Continue(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Continue(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozSmsCursor : public nsIDOMMozSmsCursor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZSMSCURSOR

  nsDOMMozSmsCursor();

private:
  ~nsDOMMozSmsCursor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozSmsCursor, nsIDOMMozSmsCursor)

nsDOMMozSmsCursor::nsDOMMozSmsCursor()
{
  /* member initializers and constructor code */
}

nsDOMMozSmsCursor::~nsDOMMozSmsCursor()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMozSmsMessage message; */
NS_IMETHODIMP nsDOMMozSmsCursor::GetMessage(nsIDOMMozSmsMessage * *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void continue (); */
NS_IMETHODIMP nsDOMMozSmsCursor::Continue()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSmsCursor_h__ */
