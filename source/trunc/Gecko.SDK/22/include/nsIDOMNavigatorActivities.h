/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/activities/interfaces/nsIDOMNavigatorActivities.idl
 */

#ifndef __gen_nsIDOMNavigatorActivities_h__
#define __gen_nsIDOMNavigatorActivities_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozActivityHandlerDescription; /* forward declaration */

class nsIDOMDOMRequest; /* forward declaration */


/* starting interface:    nsIDOMMozNavigatorActivities */
#define NS_IDOMMOZNAVIGATORACTIVITIES_IID_STR "e7cb7d2f-11d2-4783-a8b0-bddabb4a5c03"

#define NS_IDOMMOZNAVIGATORACTIVITIES_IID \
  {0xe7cb7d2f, 0x11d2, 0x4783, \
    { 0xa8, 0xb0, 0xbd, 0xda, 0xbb, 0x4a, 0x5c, 0x03 }}

class NS_NO_VTABLE nsIDOMMozNavigatorActivities : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZNAVIGATORACTIVITIES_IID)

  /* nsIDOMDOMRequest mozRegisterActivityHandler (in nsIDOMMozActivityHandlerDescription description); */
  NS_IMETHOD MozRegisterActivityHandler(nsIDOMMozActivityHandlerDescription *description, nsIDOMDOMRequest * *_retval) = 0;

  /* void mozUnregisterActivityHandler (in nsIDOMMozActivityHandlerDescription description); */
  NS_IMETHOD MozUnregisterActivityHandler(nsIDOMMozActivityHandlerDescription *description) = 0;

  /* bool mozIsActivityHandlerRegistered (in nsIDOMMozActivityHandlerDescription description); */
  NS_IMETHOD MozIsActivityHandlerRegistered(nsIDOMMozActivityHandlerDescription *description, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozNavigatorActivities, NS_IDOMMOZNAVIGATORACTIVITIES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZNAVIGATORACTIVITIES \
  NS_IMETHOD MozRegisterActivityHandler(nsIDOMMozActivityHandlerDescription *description, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD MozUnregisterActivityHandler(nsIDOMMozActivityHandlerDescription *description); \
  NS_IMETHOD MozIsActivityHandlerRegistered(nsIDOMMozActivityHandlerDescription *description, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZNAVIGATORACTIVITIES(_to) \
  NS_IMETHOD MozRegisterActivityHandler(nsIDOMMozActivityHandlerDescription *description, nsIDOMDOMRequest * *_retval) { return _to MozRegisterActivityHandler(description, _retval); } \
  NS_IMETHOD MozUnregisterActivityHandler(nsIDOMMozActivityHandlerDescription *description) { return _to MozUnregisterActivityHandler(description); } \
  NS_IMETHOD MozIsActivityHandlerRegistered(nsIDOMMozActivityHandlerDescription *description, bool *_retval) { return _to MozIsActivityHandlerRegistered(description, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZNAVIGATORACTIVITIES(_to) \
  NS_IMETHOD MozRegisterActivityHandler(nsIDOMMozActivityHandlerDescription *description, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRegisterActivityHandler(description, _retval); } \
  NS_IMETHOD MozUnregisterActivityHandler(nsIDOMMozActivityHandlerDescription *description) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozUnregisterActivityHandler(description); } \
  NS_IMETHOD MozIsActivityHandlerRegistered(nsIDOMMozActivityHandlerDescription *description, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozIsActivityHandlerRegistered(description, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozNavigatorActivities : public nsIDOMMozNavigatorActivities
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZNAVIGATORACTIVITIES

  nsDOMMozNavigatorActivities();

private:
  ~nsDOMMozNavigatorActivities();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozNavigatorActivities, nsIDOMMozNavigatorActivities)

nsDOMMozNavigatorActivities::nsDOMMozNavigatorActivities()
{
  /* member initializers and constructor code */
}

nsDOMMozNavigatorActivities::~nsDOMMozNavigatorActivities()
{
  /* destructor code */
}

/* nsIDOMDOMRequest mozRegisterActivityHandler (in nsIDOMMozActivityHandlerDescription description); */
NS_IMETHODIMP nsDOMMozNavigatorActivities::MozRegisterActivityHandler(nsIDOMMozActivityHandlerDescription *description, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozUnregisterActivityHandler (in nsIDOMMozActivityHandlerDescription description); */
NS_IMETHODIMP nsDOMMozNavigatorActivities::MozUnregisterActivityHandler(nsIDOMMozActivityHandlerDescription *description)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool mozIsActivityHandlerRegistered (in nsIDOMMozActivityHandlerDescription description); */
NS_IMETHODIMP nsDOMMozNavigatorActivities::MozIsActivityHandlerRegistered(nsIDOMMozActivityHandlerDescription *description, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorActivities_h__ */
