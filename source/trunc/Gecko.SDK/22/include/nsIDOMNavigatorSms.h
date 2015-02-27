/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mobilemessage/interfaces/nsIDOMNavigatorSms.idl
 */

#ifndef __gen_nsIDOMNavigatorSms_h__
#define __gen_nsIDOMNavigatorSms_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozSmsManager; /* forward declaration */


/* starting interface:    nsIDOMMozNavigatorSms */
#define NS_IDOMMOZNAVIGATORSMS_IID_STR "7752e51c-68ba-48c7-9fb6-32e5fbdb4599"

#define NS_IDOMMOZNAVIGATORSMS_IID \
  {0x7752e51c, 0x68ba, 0x48c7, \
    { 0x9f, 0xb6, 0x32, 0xe5, 0xfb, 0xdb, 0x45, 0x99 }}

class NS_NO_VTABLE nsIDOMMozNavigatorSms : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZNAVIGATORSMS_IID)

  /* readonly attribute nsIDOMMozSmsManager mozSms; */
  NS_IMETHOD GetMozSms(nsIDOMMozSmsManager * *aMozSms) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozNavigatorSms, NS_IDOMMOZNAVIGATORSMS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZNAVIGATORSMS \
  NS_IMETHOD GetMozSms(nsIDOMMozSmsManager * *aMozSms); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZNAVIGATORSMS(_to) \
  NS_IMETHOD GetMozSms(nsIDOMMozSmsManager * *aMozSms) { return _to GetMozSms(aMozSms); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZNAVIGATORSMS(_to) \
  NS_IMETHOD GetMozSms(nsIDOMMozSmsManager * *aMozSms) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozSms(aMozSms); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozNavigatorSms : public nsIDOMMozNavigatorSms
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZNAVIGATORSMS

  nsDOMMozNavigatorSms();

private:
  ~nsDOMMozNavigatorSms();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozNavigatorSms, nsIDOMMozNavigatorSms)

nsDOMMozNavigatorSms::nsDOMMozNavigatorSms()
{
  /* member initializers and constructor code */
}

nsDOMMozNavigatorSms::~nsDOMMozNavigatorSms()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMozSmsManager mozSms; */
NS_IMETHODIMP nsDOMMozNavigatorSms::GetMozSms(nsIDOMMozSmsManager * *aMozSms)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorSms_h__ */
