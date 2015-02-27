/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/geolocation/nsIDOMGeoPosition.idl
 */

#ifndef __gen_nsIDOMGeoPosition_h__
#define __gen_nsIDOMGeoPosition_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#ifndef __gen_nsIDOMGeoPositionCoords_h__
#include "nsIDOMGeoPositionCoords.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMGeoPosition */
#define NS_IDOMGEOPOSITION_IID_STR "dd9f7e81-0f74-4fb5-b361-37019bf60c3f"

#define NS_IDOMGEOPOSITION_IID \
  {0xdd9f7e81, 0x0f74, 0x4fb5, \
    { 0xb3, 0x61, 0x37, 0x01, 0x9b, 0xf6, 0x0c, 0x3f }}

class NS_NO_VTABLE nsIDOMGeoPosition : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOPOSITION_IID)

  /* readonly attribute DOMTimeStamp timestamp; */
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) = 0;

  /* readonly attribute nsIDOMGeoPositionCoords coords; */
  NS_IMETHOD GetCoords(nsIDOMGeoPositionCoords * *aCoords) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoPosition, NS_IDOMGEOPOSITION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOPOSITION \
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp); \
  NS_IMETHOD GetCoords(nsIDOMGeoPositionCoords * *aCoords); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOPOSITION(_to) \
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) { return _to GetTimestamp(aTimestamp); } \
  NS_IMETHOD GetCoords(nsIDOMGeoPositionCoords * *aCoords) { return _to GetCoords(aCoords); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOPOSITION(_to) \
  NS_IMETHOD GetTimestamp(DOMTimeStamp *aTimestamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimestamp(aTimestamp); } \
  NS_IMETHOD GetCoords(nsIDOMGeoPositionCoords * *aCoords) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCoords(aCoords); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoPosition : public nsIDOMGeoPosition
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOPOSITION

  nsDOMGeoPosition();

private:
  ~nsDOMGeoPosition();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoPosition, nsIDOMGeoPosition)

nsDOMGeoPosition::nsDOMGeoPosition()
{
  /* member initializers and constructor code */
}

nsDOMGeoPosition::~nsDOMGeoPosition()
{
  /* destructor code */
}

/* readonly attribute DOMTimeStamp timestamp; */
NS_IMETHODIMP nsDOMGeoPosition::GetTimestamp(DOMTimeStamp *aTimestamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMGeoPositionCoords coords; */
NS_IMETHODIMP nsDOMGeoPosition::GetCoords(nsIDOMGeoPositionCoords * *aCoords)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoPosition_h__ */
