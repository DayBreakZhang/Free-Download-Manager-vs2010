/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/time/nsIDOMNavigatorTime.idl
 */

#ifndef __gen_nsIDOMNavigatorTime_h__
#define __gen_nsIDOMNavigatorTime_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozTimeManager; /* forward declaration */


/* starting interface:    nsIDOMMozNavigatorTime */
#define NS_IDOMMOZNAVIGATORTIME_IID_STR "befc186d-c249-4acb-8e70-8080f7b45e5c"

#define NS_IDOMMOZNAVIGATORTIME_IID \
  {0xbefc186d, 0xc249, 0x4acb, \
    { 0x8e, 0x70, 0x80, 0x80, 0xf7, 0xb4, 0x5e, 0x5c }}

class NS_NO_VTABLE nsIDOMMozNavigatorTime : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZNAVIGATORTIME_IID)

  /* readonly attribute nsIDOMMozTimeManager mozTime; */
  NS_IMETHOD GetMozTime(nsIDOMMozTimeManager * *aMozTime) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozNavigatorTime, NS_IDOMMOZNAVIGATORTIME_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZNAVIGATORTIME \
  NS_IMETHOD GetMozTime(nsIDOMMozTimeManager * *aMozTime); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZNAVIGATORTIME(_to) \
  NS_IMETHOD GetMozTime(nsIDOMMozTimeManager * *aMozTime) { return _to GetMozTime(aMozTime); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZNAVIGATORTIME(_to) \
  NS_IMETHOD GetMozTime(nsIDOMMozTimeManager * *aMozTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozTime(aMozTime); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozNavigatorTime : public nsIDOMMozNavigatorTime
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZNAVIGATORTIME

  nsDOMMozNavigatorTime();

private:
  ~nsDOMMozNavigatorTime();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozNavigatorTime, nsIDOMMozNavigatorTime)

nsDOMMozNavigatorTime::nsDOMMozNavigatorTime()
{
  /* member initializers and constructor code */
}

nsDOMMozNavigatorTime::~nsDOMMozNavigatorTime()
{
  /* destructor code */
}

/* readonly attribute nsIDOMMozTimeManager mozTime; */
NS_IMETHODIMP nsDOMMozNavigatorTime::GetMozTime(nsIDOMMozTimeManager * *aMozTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNavigatorTime_h__ */
