/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDeviceSensors.idl
 */

#ifndef __gen_nsIDeviceSensors_h__
#define __gen_nsIDeviceSensors_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIDeviceSensorData */
#define NS_IDEVICESENSORDATA_IID_STR "1b406e32-cf42-471e-a470-6fd600bf4c7b"

#define NS_IDEVICESENSORDATA_IID \
  {0x1b406e32, 0xcf42, 0x471e, \
    { 0xa4, 0x70, 0x6f, 0xd6, 0x00, 0xbf, 0x4c, 0x7b }}

class NS_NO_VTABLE nsIDeviceSensorData : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDEVICESENSORDATA_IID)

  enum {
    TYPE_ORIENTATION = 0U,
    TYPE_ACCELERATION = 1U,
    TYPE_PROXIMITY = 2U,
    TYPE_LINEAR_ACCELERATION = 3U,
    TYPE_GYROSCOPE = 4U,
    TYPE_LIGHT = 5U
  };

  /* readonly attribute unsigned long type; */
  NS_IMETHOD GetType(uint32_t *aType) = 0;

  /* readonly attribute double x; */
  NS_IMETHOD GetX(double *aX) = 0;

  /* readonly attribute double y; */
  NS_IMETHOD GetY(double *aY) = 0;

  /* readonly attribute double z; */
  NS_IMETHOD GetZ(double *aZ) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDeviceSensorData, NS_IDEVICESENSORDATA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDEVICESENSORDATA \
  NS_IMETHOD GetType(uint32_t *aType); \
  NS_IMETHOD GetX(double *aX); \
  NS_IMETHOD GetY(double *aY); \
  NS_IMETHOD GetZ(double *aZ); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDEVICESENSORDATA(_to) \
  NS_IMETHOD GetType(uint32_t *aType) { return _to GetType(aType); } \
  NS_IMETHOD GetX(double *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(double *aY) { return _to GetY(aY); } \
  NS_IMETHOD GetZ(double *aZ) { return _to GetZ(aZ); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDEVICESENSORDATA(_to) \
  NS_IMETHOD GetType(uint32_t *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetX(double *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(double *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_IMETHOD GetZ(double *aZ) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZ(aZ); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDeviceSensorData : public nsIDeviceSensorData
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDEVICESENSORDATA

  nsDeviceSensorData();

private:
  ~nsDeviceSensorData();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDeviceSensorData, nsIDeviceSensorData)

nsDeviceSensorData::nsDeviceSensorData()
{
  /* member initializers and constructor code */
}

nsDeviceSensorData::~nsDeviceSensorData()
{
  /* destructor code */
}

/* readonly attribute unsigned long type; */
NS_IMETHODIMP nsDeviceSensorData::GetType(uint32_t *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double x; */
NS_IMETHODIMP nsDeviceSensorData::GetX(double *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double y; */
NS_IMETHODIMP nsDeviceSensorData::GetY(double *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute double z; */
NS_IMETHODIMP nsDeviceSensorData::GetZ(double *aZ)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDeviceSensors */
#define NS_IDEVICESENSORS_IID_STR "e46e47c7-55ff-44c4-abce-21b14ba07f86"

#define NS_IDEVICESENSORS_IID \
  {0xe46e47c7, 0x55ff, 0x44c4, \
    { 0xab, 0xce, 0x21, 0xb1, 0x4b, 0xa0, 0x7f, 0x86 }}

class NS_NO_VTABLE nsIDeviceSensors : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDEVICESENSORS_IID)

  /* bool hasWindowListener (in unsigned long aType, in nsIDOMWindow aWindow); */
  NS_IMETHOD HasWindowListener(uint32_t aType, nsIDOMWindow *aWindow, bool *_retval) = 0;

  /* [noscript] void addWindowListener (in unsigned long aType, in nsIDOMWindow aWindow); */
  NS_IMETHOD AddWindowListener(uint32_t aType, nsIDOMWindow *aWindow) = 0;

  /* [noscript] void removeWindowListener (in unsigned long aType, in nsIDOMWindow aWindow); */
  NS_IMETHOD RemoveWindowListener(uint32_t aType, nsIDOMWindow *aWindow) = 0;

  /* [noscript] void removeWindowAsListener (in nsIDOMWindow aWindow); */
  NS_IMETHOD RemoveWindowAsListener(nsIDOMWindow *aWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDeviceSensors, NS_IDEVICESENSORS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDEVICESENSORS \
  NS_IMETHOD HasWindowListener(uint32_t aType, nsIDOMWindow *aWindow, bool *_retval); \
  NS_IMETHOD AddWindowListener(uint32_t aType, nsIDOMWindow *aWindow); \
  NS_IMETHOD RemoveWindowListener(uint32_t aType, nsIDOMWindow *aWindow); \
  NS_IMETHOD RemoveWindowAsListener(nsIDOMWindow *aWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDEVICESENSORS(_to) \
  NS_IMETHOD HasWindowListener(uint32_t aType, nsIDOMWindow *aWindow, bool *_retval) { return _to HasWindowListener(aType, aWindow, _retval); } \
  NS_IMETHOD AddWindowListener(uint32_t aType, nsIDOMWindow *aWindow) { return _to AddWindowListener(aType, aWindow); } \
  NS_IMETHOD RemoveWindowListener(uint32_t aType, nsIDOMWindow *aWindow) { return _to RemoveWindowListener(aType, aWindow); } \
  NS_IMETHOD RemoveWindowAsListener(nsIDOMWindow *aWindow) { return _to RemoveWindowAsListener(aWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDEVICESENSORS(_to) \
  NS_IMETHOD HasWindowListener(uint32_t aType, nsIDOMWindow *aWindow, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasWindowListener(aType, aWindow, _retval); } \
  NS_IMETHOD AddWindowListener(uint32_t aType, nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddWindowListener(aType, aWindow); } \
  NS_IMETHOD RemoveWindowListener(uint32_t aType, nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWindowListener(aType, aWindow); } \
  NS_IMETHOD RemoveWindowAsListener(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveWindowAsListener(aWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDeviceSensors : public nsIDeviceSensors
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDEVICESENSORS

  nsDeviceSensors();

private:
  ~nsDeviceSensors();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDeviceSensors, nsIDeviceSensors)

nsDeviceSensors::nsDeviceSensors()
{
  /* member initializers and constructor code */
}

nsDeviceSensors::~nsDeviceSensors()
{
  /* destructor code */
}

/* bool hasWindowListener (in unsigned long aType, in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsDeviceSensors::HasWindowListener(uint32_t aType, nsIDOMWindow *aWindow, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void addWindowListener (in unsigned long aType, in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsDeviceSensors::AddWindowListener(uint32_t aType, nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void removeWindowListener (in unsigned long aType, in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsDeviceSensors::RemoveWindowListener(uint32_t aType, nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void removeWindowAsListener (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsDeviceSensors::RemoveWindowAsListener(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_DEVICE_SENSORS_CID \
{ 0xecba5203, 0x77da, 0x465a, \
{ 0x86, 0x5e, 0x78, 0xb7, 0xaf, 0x10, 0xd8, 0xf7 } }
#define NS_DEVICE_SENSORS_CONTRACTID "@mozilla.org/devicesensors;1"

#endif /* __gen_nsIDeviceSensors_h__ */
