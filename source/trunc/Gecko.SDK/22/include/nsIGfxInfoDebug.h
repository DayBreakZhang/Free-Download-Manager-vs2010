/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsIGfxInfoDebug.idl
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
#define NS_IGFXINFODEBUG_IID_STR "ca7b0bc7-c67c-4b79-8270-ed7ba002af08"

#define NS_IGFXINFODEBUG_IID \
  {0xca7b0bc7, 0xc67c, 0x4b79, \
    { 0x82, 0x70, 0xed, 0x7b, 0xa0, 0x02, 0xaf, 0x08 }}

class NS_NO_VTABLE nsIGfxInfoDebug : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IGFXINFODEBUG_IID)

  /* void spoofVendorID (in DOMString aVendorID); */
  NS_IMETHOD SpoofVendorID(const nsAString & aVendorID) = 0;

  /* void spoofDeviceID (in DOMString aDeviceID); */
  NS_IMETHOD SpoofDeviceID(const nsAString & aDeviceID) = 0;

  /* void spoofDriverVersion (in DOMString aDriverVersion); */
  NS_IMETHOD SpoofDriverVersion(const nsAString & aDriverVersion) = 0;

  /* void spoofOSVersion (in unsigned long aVersion); */
  NS_IMETHOD SpoofOSVersion(uint32_t aVersion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIGfxInfoDebug, NS_IGFXINFODEBUG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIGFXINFODEBUG \
  NS_IMETHOD SpoofVendorID(const nsAString & aVendorID); \
  NS_IMETHOD SpoofDeviceID(const nsAString & aDeviceID); \
  NS_IMETHOD SpoofDriverVersion(const nsAString & aDriverVersion); \
  NS_IMETHOD SpoofOSVersion(uint32_t aVersion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIGFXINFODEBUG(_to) \
  NS_IMETHOD SpoofVendorID(const nsAString & aVendorID) { return _to SpoofVendorID(aVendorID); } \
  NS_IMETHOD SpoofDeviceID(const nsAString & aDeviceID) { return _to SpoofDeviceID(aDeviceID); } \
  NS_IMETHOD SpoofDriverVersion(const nsAString & aDriverVersion) { return _to SpoofDriverVersion(aDriverVersion); } \
  NS_IMETHOD SpoofOSVersion(uint32_t aVersion) { return _to SpoofOSVersion(aVersion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIGFXINFODEBUG(_to) \
  NS_IMETHOD SpoofVendorID(const nsAString & aVendorID) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpoofVendorID(aVendorID); } \
  NS_IMETHOD SpoofDeviceID(const nsAString & aDeviceID) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpoofDeviceID(aDeviceID); } \
  NS_IMETHOD SpoofDriverVersion(const nsAString & aDriverVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpoofDriverVersion(aDriverVersion); } \
  NS_IMETHOD SpoofOSVersion(uint32_t aVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SpoofOSVersion(aVersion); } 

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

/* void spoofVendorID (in DOMString aVendorID); */
NS_IMETHODIMP nsGfxInfoDebug::SpoofVendorID(const nsAString & aVendorID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void spoofDeviceID (in DOMString aDeviceID); */
NS_IMETHODIMP nsGfxInfoDebug::SpoofDeviceID(const nsAString & aDeviceID)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void spoofDriverVersion (in DOMString aDriverVersion); */
NS_IMETHODIMP nsGfxInfoDebug::SpoofDriverVersion(const nsAString & aDriverVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void spoofOSVersion (in unsigned long aVersion); */
NS_IMETHODIMP nsGfxInfoDebug::SpoofOSVersion(uint32_t aVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIGfxInfoDebug_h__ */
