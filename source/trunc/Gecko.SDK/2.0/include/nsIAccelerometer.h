/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/xpcom/system/nsIAccelerometer.idl
 */

#ifndef __gen_nsIAccelerometer_h__
#define __gen_nsIAccelerometer_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIAcceleration */
#define NS_IACCELERATION_IID_STR "1b406e32-cf42-471e-a470-6fd600bf4c7b"

#define NS_IACCELERATION_IID \
  {0x1b406e32, 0xcf42, 0x471e, \
    { 0xa4, 0x70, 0x6f, 0xd6, 0x00, 0xbf, 0x4c, 0x7b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAcceleration : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCELERATION_IID)

  /* readonly attribute double x; */
  NS_SCRIPTABLE NS_IMETHOD GetX(double *aX) = 0;

  /* readonly attribute double y; */
  NS_SCRIPTABLE NS_IMETHOD GetY(double *aY) = 0;

  /* readonly attribute double z; */
  NS_SCRIPTABLE NS_IMETHOD GetZ(double *aZ) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAcceleration, NS_IACCELERATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCELERATION \
  NS_SCRIPTABLE NS_IMETHOD GetX(double *aX); \
  NS_SCRIPTABLE NS_IMETHOD GetY(double *aY); \
  NS_SCRIPTABLE NS_IMETHOD GetZ(double *aZ); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCELERATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(double *aX) { return _to GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(double *aY) { return _to GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetZ(double *aZ) { return _to GetZ(aZ); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCELERATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX(double *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_SCRIPTABLE NS_IMETHOD GetY(double *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_SCRIPTABLE NS_IMETHOD GetZ(double *aZ) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZ(aZ); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAcceleration : public nsIAcceleration
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCELERATION

  nsAcceleration();

private:
  ~nsAcceleration();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAcceleration, nsIAcceleration)

nsAcceleration::nsAcceleration()
{
  /* member initializers and constructor code */
}

nsAcceleration::~nsAcceleration()
{
  /* destructor code */
}

/* readonly attribute double x; */
NS_IMETHODIMP nsAcceleration::GetX(double *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double y; */
NS_IMETHODIMP nsAcceleration::GetY(double *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double z; */
NS_IMETHODIMP nsAcceleration::GetZ(double *aZ)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccelerationListener */
#define NS_IACCELERATIONLISTENER_IID_STR "3386bed8-7393-4704-8ffc-1eb2c35432ff"

#define NS_IACCELERATIONLISTENER_IID \
  {0x3386bed8, 0x7393, 0x4704, \
    { 0x8f, 0xfc, 0x1e, 0xb2, 0xc3, 0x54, 0x32, 0xff }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccelerationListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCELERATIONLISTENER_IID)

  /* void onAccelerationChange (in nsIAcceleration aAcceleration); */
  NS_SCRIPTABLE NS_IMETHOD OnAccelerationChange(nsIAcceleration *aAcceleration) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccelerationListener, NS_IACCELERATIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCELERATIONLISTENER \
  NS_SCRIPTABLE NS_IMETHOD OnAccelerationChange(nsIAcceleration *aAcceleration); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCELERATIONLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnAccelerationChange(nsIAcceleration *aAcceleration) { return _to OnAccelerationChange(aAcceleration); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCELERATIONLISTENER(_to) \
  NS_SCRIPTABLE NS_IMETHOD OnAccelerationChange(nsIAcceleration *aAcceleration) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnAccelerationChange(aAcceleration); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccelerationListener : public nsIAccelerationListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCELERATIONLISTENER

  nsAccelerationListener();

private:
  ~nsAccelerationListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccelerationListener, nsIAccelerationListener)

nsAccelerationListener::nsAccelerationListener()
{
  /* member initializers and constructor code */
}

nsAccelerationListener::~nsAccelerationListener()
{
  /* destructor code */
}

/* void onAccelerationChange (in nsIAcceleration aAcceleration); */
NS_IMETHODIMP nsAccelerationListener::OnAccelerationChange(nsIAcceleration *aAcceleration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccelerometer */
#define NS_IACCELEROMETER_IID_STR "4b04e228-0b33-43fc-971f-af60cedb1c21"

#define NS_IACCELEROMETER_IID \
  {0x4b04e228, 0x0b33, 0x43fc, \
    { 0x97, 0x1f, 0xaf, 0x60, 0xce, 0xdb, 0x1c, 0x21 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAccelerometer : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCELEROMETER_IID)

  /* void addListener (in nsIAccelerationListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIAccelerationListener *aListener) = 0;

  /* void removeListener (in nsIAccelerationListener aListener); */
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIAccelerationListener *aListener) = 0;

  /* void addWindowListener (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD AddWindowListener(nsIDOMWindow *aWindow) = 0;

  /* void removeWindowListener (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD RemoveWindowListener(nsIDOMWindow *aWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccelerometer, NS_IACCELEROMETER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCELEROMETER \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIAccelerationListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIAccelerationListener *aListener); \
  NS_SCRIPTABLE NS_IMETHOD AddWindowListener(nsIDOMWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD RemoveWindowListener(nsIDOMWindow *aWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCELEROMETER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIAccelerationListener *aListener) { return _to AddListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIAccelerationListener *aListener) { return _to RemoveListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD AddWindowListener(nsIDOMWindow *aWindow) { return _to AddWindowListener(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveWindowListener(nsIDOMWindow *aWindow) { return _to RemoveWindowListener(aWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCELEROMETER(_to) \
  NS_SCRIPTABLE NS_IMETHOD AddListener(nsIAccelerationListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveListener(nsIAccelerationListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveListener(aListener); } \
  NS_SCRIPTABLE NS_IMETHOD AddWindowListener(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWindowListener(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveWindowListener(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWindowListener(aWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccelerometer : public nsIAccelerometer
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCELEROMETER

  nsAccelerometer();

private:
  ~nsAccelerometer();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccelerometer, nsIAccelerometer)

nsAccelerometer::nsAccelerometer()
{
  /* member initializers and constructor code */
}

nsAccelerometer::~nsAccelerometer()
{
  /* destructor code */
}

/* void addListener (in nsIAccelerationListener aListener); */
NS_IMETHODIMP nsAccelerometer::AddListener(nsIAccelerationListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeListener (in nsIAccelerationListener aListener); */
NS_IMETHODIMP nsAccelerometer::RemoveListener(nsIAccelerationListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addWindowListener (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsAccelerometer::AddWindowListener(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeWindowListener (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsAccelerometer::RemoveWindowListener(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAccelerometerUpdate */
#define NS_IACCELEROMETERUPDATE_IID_STR "22dd1d8a-51bf-406f-8b6d-d1919f8f1c7d"

#define NS_IACCELEROMETERUPDATE_IID \
  {0x22dd1d8a, 0x51bf, 0x406f, \
    { 0x8b, 0x6d, 0xd1, 0x91, 0x9f, 0x8f, 0x1c, 0x7d }}

class NS_NO_VTABLE nsIAccelerometerUpdate : public nsIAccelerometer {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCELEROMETERUPDATE_IID)

  /* void accelerationChanged (in double x, in double y, in double z); */
  NS_IMETHOD AccelerationChanged(double x, double y, double z) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccelerometerUpdate, NS_IACCELEROMETERUPDATE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCELEROMETERUPDATE \
  NS_IMETHOD AccelerationChanged(double x, double y, double z); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCELEROMETERUPDATE(_to) \
  NS_IMETHOD AccelerationChanged(double x, double y, double z) { return _to AccelerationChanged(x, y, z); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCELEROMETERUPDATE(_to) \
  NS_IMETHOD AccelerationChanged(double x, double y, double z) { return !_to ? NS_ERROR_NULL_POINTER : _to->AccelerationChanged(x, y, z); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccelerometerUpdate : public nsIAccelerometerUpdate
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCELEROMETERUPDATE

  nsAccelerometerUpdate();

private:
  ~nsAccelerometerUpdate();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccelerometerUpdate, nsIAccelerometerUpdate)

nsAccelerometerUpdate::nsAccelerometerUpdate()
{
  /* member initializers and constructor code */
}

nsAccelerometerUpdate::~nsAccelerometerUpdate()
{
  /* destructor code */
}

/* void accelerationChanged (in double x, in double y, in double z); */
NS_IMETHODIMP nsAccelerometerUpdate::AccelerationChanged(double x, double y, double z)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccelerometer_h__ */
