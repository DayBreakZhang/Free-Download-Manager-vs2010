/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/geolocation/nsIDOMGeoPositionAddress.idl
 */

#ifndef __gen_nsIDOMGeoPositionAddress_h__
#define __gen_nsIDOMGeoPositionAddress_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMGeoPositionAddress */
#define NS_IDOMGEOPOSITIONADDRESS_IID_STR "0df49c5c-9845-42f9-a76c-62e09c110986"

#define NS_IDOMGEOPOSITIONADDRESS_IID \
  {0x0df49c5c, 0x9845, 0x42f9, \
    { 0xa7, 0x6c, 0x62, 0xe0, 0x9c, 0x11, 0x09, 0x86 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMGeoPositionAddress : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOPOSITIONADDRESS_IID)

  /* readonly attribute DOMString streetNumber; */
  NS_SCRIPTABLE NS_IMETHOD GetStreetNumber(nsAString & aStreetNumber) = 0;

  /* readonly attribute DOMString street; */
  NS_SCRIPTABLE NS_IMETHOD GetStreet(nsAString & aStreet) = 0;

  /* readonly attribute DOMString premises; */
  NS_SCRIPTABLE NS_IMETHOD GetPremises(nsAString & aPremises) = 0;

  /* readonly attribute DOMString city; */
  NS_SCRIPTABLE NS_IMETHOD GetCity(nsAString & aCity) = 0;

  /* readonly attribute DOMString county; */
  NS_SCRIPTABLE NS_IMETHOD GetCounty(nsAString & aCounty) = 0;

  /* readonly attribute DOMString region; */
  NS_SCRIPTABLE NS_IMETHOD GetRegion(nsAString & aRegion) = 0;

  /* readonly attribute DOMString country; */
  NS_SCRIPTABLE NS_IMETHOD GetCountry(nsAString & aCountry) = 0;

  /* readonly attribute DOMString countryCode; */
  NS_SCRIPTABLE NS_IMETHOD GetCountryCode(nsAString & aCountryCode) = 0;

  /* readonly attribute DOMString postalCode; */
  NS_SCRIPTABLE NS_IMETHOD GetPostalCode(nsAString & aPostalCode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoPositionAddress, NS_IDOMGEOPOSITIONADDRESS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOPOSITIONADDRESS \
  NS_SCRIPTABLE NS_IMETHOD GetStreetNumber(nsAString & aStreetNumber); \
  NS_SCRIPTABLE NS_IMETHOD GetStreet(nsAString & aStreet); \
  NS_SCRIPTABLE NS_IMETHOD GetPremises(nsAString & aPremises); \
  NS_SCRIPTABLE NS_IMETHOD GetCity(nsAString & aCity); \
  NS_SCRIPTABLE NS_IMETHOD GetCounty(nsAString & aCounty); \
  NS_SCRIPTABLE NS_IMETHOD GetRegion(nsAString & aRegion); \
  NS_SCRIPTABLE NS_IMETHOD GetCountry(nsAString & aCountry); \
  NS_SCRIPTABLE NS_IMETHOD GetCountryCode(nsAString & aCountryCode); \
  NS_SCRIPTABLE NS_IMETHOD GetPostalCode(nsAString & aPostalCode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOPOSITIONADDRESS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStreetNumber(nsAString & aStreetNumber) { return _to GetStreetNumber(aStreetNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetStreet(nsAString & aStreet) { return _to GetStreet(aStreet); } \
  NS_SCRIPTABLE NS_IMETHOD GetPremises(nsAString & aPremises) { return _to GetPremises(aPremises); } \
  NS_SCRIPTABLE NS_IMETHOD GetCity(nsAString & aCity) { return _to GetCity(aCity); } \
  NS_SCRIPTABLE NS_IMETHOD GetCounty(nsAString & aCounty) { return _to GetCounty(aCounty); } \
  NS_SCRIPTABLE NS_IMETHOD GetRegion(nsAString & aRegion) { return _to GetRegion(aRegion); } \
  NS_SCRIPTABLE NS_IMETHOD GetCountry(nsAString & aCountry) { return _to GetCountry(aCountry); } \
  NS_SCRIPTABLE NS_IMETHOD GetCountryCode(nsAString & aCountryCode) { return _to GetCountryCode(aCountryCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPostalCode(nsAString & aPostalCode) { return _to GetPostalCode(aPostalCode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOPOSITIONADDRESS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetStreetNumber(nsAString & aStreetNumber) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStreetNumber(aStreetNumber); } \
  NS_SCRIPTABLE NS_IMETHOD GetStreet(nsAString & aStreet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStreet(aStreet); } \
  NS_SCRIPTABLE NS_IMETHOD GetPremises(nsAString & aPremises) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPremises(aPremises); } \
  NS_SCRIPTABLE NS_IMETHOD GetCity(nsAString & aCity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCity(aCity); } \
  NS_SCRIPTABLE NS_IMETHOD GetCounty(nsAString & aCounty) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCounty(aCounty); } \
  NS_SCRIPTABLE NS_IMETHOD GetRegion(nsAString & aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRegion(aRegion); } \
  NS_SCRIPTABLE NS_IMETHOD GetCountry(nsAString & aCountry) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCountry(aCountry); } \
  NS_SCRIPTABLE NS_IMETHOD GetCountryCode(nsAString & aCountryCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCountryCode(aCountryCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetPostalCode(nsAString & aPostalCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPostalCode(aPostalCode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoPositionAddress : public nsIDOMGeoPositionAddress
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOPOSITIONADDRESS

  nsDOMGeoPositionAddress();

private:
  ~nsDOMGeoPositionAddress();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoPositionAddress, nsIDOMGeoPositionAddress)

nsDOMGeoPositionAddress::nsDOMGeoPositionAddress()
{
  /* member initializers and constructor code */
}

nsDOMGeoPositionAddress::~nsDOMGeoPositionAddress()
{
  /* destructor code */
}

/* readonly attribute DOMString streetNumber; */
NS_IMETHODIMP nsDOMGeoPositionAddress::GetStreetNumber(nsAString & aStreetNumber)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString street; */
NS_IMETHODIMP nsDOMGeoPositionAddress::GetStreet(nsAString & aStreet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString premises; */
NS_IMETHODIMP nsDOMGeoPositionAddress::GetPremises(nsAString & aPremises)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString city; */
NS_IMETHODIMP nsDOMGeoPositionAddress::GetCity(nsAString & aCity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString county; */
NS_IMETHODIMP nsDOMGeoPositionAddress::GetCounty(nsAString & aCounty)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString region; */
NS_IMETHODIMP nsDOMGeoPositionAddress::GetRegion(nsAString & aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString country; */
NS_IMETHODIMP nsDOMGeoPositionAddress::GetCountry(nsAString & aCountry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString countryCode; */
NS_IMETHODIMP nsDOMGeoPositionAddress::GetCountryCode(nsAString & aCountryCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString postalCode; */
NS_IMETHODIMP nsDOMGeoPositionAddress::GetPostalCode(nsAString & aPostalCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoPositionAddress_h__ */
