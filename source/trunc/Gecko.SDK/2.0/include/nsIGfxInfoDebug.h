/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/widget/public/nsIGfxInfoDebug.idl
 */

#ifndef __gen_nsIGfxInfoDebug_h__
#define __gen_nsIGfxInfoDebug_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIGfxInfoDebug */
#define NS_IGFXINFODEBUG_IID_STR "0c19c88a-9ef1-4bb4-b0a2-86ab768e8bd6"

#define NS_IGFXINFODEBUG_IID \
  {0x0c19c88a, 0x9ef1, 0x4bb4, \
    { 0xb0, 0xa2, 0x86, 0xab, 0x76, 0x8e, 0x8b, 0xd6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIGfxInfoDebug : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGFXINFODEBUG_IID)

  /* void spoofVendorID (in unsigned long aVendorID); */
  NS_SCRIPTABLE NS_IMETHOD SpoofVendorID(PRUint32 aVendorID) = 0;

  /* void spoofDeviceID (in unsigned long aDeviceID); */
  NS_SCRIPTABLE NS_IMETHOD SpoofDeviceID(PRUint32 aDeviceID) = 0;

  /* void spoofDriverVersion (in DOMString aDriverVersion); */
  NS_SCRIPTABLE NS_IMETHOD SpoofDriverVersion(const nsAString & aDriverVersion) = 0;

  /* void spoofOSVersion (in unsigned long aVersion); */
  NS_SCRIPTABLE NS_IMETHOD SpoofOSVersion(PRUint32 aVersion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGfxInfoDebug, NS_IGFXINFODEBUG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGFXINFODEBUG \
  NS_SCRIPTABLE NS_IMETHOD SpoofVendorID(PRUint32 aVendorID); \
  NS_SCRIPTABLE NS_IMETHOD SpoofDeviceID(PRUint32 aDeviceID); \
  NS_SCRIPTABLE NS_IMETHOD SpoofDriverVersion(const nsAString & aDriverVersion); \
  NS_SCRIPTABLE NS_IMETHOD SpoofOSVersion(PRUint32 aVersion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGFXINFODEBUG(_to) \
  NS_SCRIPTABLE NS_IMETHOD SpoofVendorID(PRUint32 aVendorID) { return _to SpoofVendorID(aVendorID); } \
  NS_SCRIPTABLE NS_IMETHOD SpoofDeviceID(PRUint32 aDeviceID) { return _to SpoofDeviceID(aDeviceID); } \
  NS_SCRIPTABLE NS_IMETHOD SpoofDriverVersion(const nsAString & aDriverVersion) { return _to SpoofDriverVersion(aDriverVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SpoofOSVersion(PRUint32 aVersion) { return _to SpoofOSVersion(aVersion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGFXINFODEBUG(_to) \
  NS_SCRIPTABLE NS_IMETHOD SpoofVendorID(PRUint32 aVendorID) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpoofVendorID(aVendorID); } \
  NS_SCRIPTABLE NS_IMETHOD SpoofDeviceID(PRUint32 aDeviceID) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpoofDeviceID(aDeviceID); } \
  NS_SCRIPTABLE NS_IMETHOD SpoofDriverVersion(const nsAString & aDriverVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpoofDriverVersion(aDriverVersion); } \
  NS_SCRIPTABLE NS_IMETHOD SpoofOSVersion(PRUint32 aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpoofOSVersion(aVersion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsGfxInfoDebug : public nsIGfxInfoDebug
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIGFXINFODEBUG

  nsGfxInfoDebug();

private:
  ~nsGfxInfoDebug();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsGfxInfoDebug, nsIGfxInfoDebug)

nsGfxInfoDebug::nsGfxInfoDebug()
{
  /* member initializers and constructor code */
}

nsGfxInfoDebug::~nsGfxInfoDebug()
{
  /* destructor code */
}

/* void spoofVendorID (in unsigned long aVendorID); */
NS_IMETHODIMP nsGfxInfoDebug::SpoofVendorID(PRUint32 aVendorID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void spoofDeviceID (in unsigned long aDeviceID); */
NS_IMETHODIMP nsGfxInfoDebug::SpoofDeviceID(PRUint32 aDeviceID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void spoofDriverVersion (in DOMString aDriverVersion); */
NS_IMETHODIMP nsGfxInfoDebug::SpoofDriverVersion(const nsAString & aDriverVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void spoofOSVersion (in unsigned long aVersion); */
NS_IMETHODIMP nsGfxInfoDebug::SpoofOSVersion(PRUint32 aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGfxInfoDebug_h__ */
