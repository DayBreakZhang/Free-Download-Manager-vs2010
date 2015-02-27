/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/js/jetpack/nsIJetpackService.idl
 */

#ifndef __gen_nsIJetpackService_h__
#define __gen_nsIJetpackService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIJetpack; /* forward declaration */


/* starting interface:    nsIJetpackService */
#define NS_IJETPACKSERVICE_IID_STR "2e097e3e-225f-42a3-87a8-c5c22659fef0"

#define NS_IJETPACKSERVICE_IID \
  {0x2e097e3e, 0x225f, 0x42a3, \
    { 0x87, 0xa8, 0xc5, 0xc2, 0x26, 0x59, 0xfe, 0xf0 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIJetpackService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJETPACKSERVICE_IID)

  /* nsIJetpack createJetpack (); */
  NS_SCRIPTABLE NS_IMETHOD CreateJetpack(nsIJetpack **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJetpackService, NS_IJETPACKSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJETPACKSERVICE \
  NS_SCRIPTABLE NS_IMETHOD CreateJetpack(nsIJetpack **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJETPACKSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateJetpack(nsIJetpack **_retval NS_OUTPARAM) { return _to CreateJetpack(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJETPACKSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateJetpack(nsIJetpack **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateJetpack(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJetpackService : public nsIJetpackService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJETPACKSERVICE

  nsJetpackService();

private:
  ~nsJetpackService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJetpackService, nsIJetpackService)

nsJetpackService::nsJetpackService()
{
  /* member initializers and constructor code */
}

nsJetpackService::~nsJetpackService()
{
  /* destructor code */
}

/* nsIJetpack createJetpack (); */
NS_IMETHODIMP nsJetpackService::CreateJetpack(nsIJetpack **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJetpackService_h__ */
