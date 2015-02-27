/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrintSettingsWin.idl
 */

#ifndef __gen_nsIPrintSettingsWin_h__
#define __gen_nsIPrintSettingsWin_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "windows.h"

/* starting interface:    nsIPrintSettingsWin */
#define NS_IPRINTSETTINGSWIN_IID_STR "f13b225d-473e-4372-b11f-b6dff9fe0c5b"

#define NS_IPRINTSETTINGSWIN_IID \
  {0xf13b225d, 0x473e, 0x4372, \
    { 0xb1, 0x1f, 0xb6, 0xdf, 0xf9, 0xfe, 0x0c, 0x5b }}

class NS_NO_VTABLE nsIPrintSettingsWin : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTSETTINGSWIN_IID)

  /* [noscript] attribute wstring deviceName; */
  NS_IMETHOD GetDeviceName(char16_t * *aDeviceName) = 0;
  NS_IMETHOD SetDeviceName(const char16_t * aDeviceName) = 0;

  /* [noscript] attribute wstring driverName; */
  NS_IMETHOD GetDriverName(char16_t * *aDriverName) = 0;
  NS_IMETHOD SetDriverName(const char16_t * aDriverName) = 0;

  /* [noscript] attribute nsDevMode devMode; */
  NS_IMETHOD GetDevMode(DEVMODEW **aDevMode) = 0;
  NS_IMETHOD SetDevMode(DEVMODEW *aDevMode) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintSettingsWin, NS_IPRINTSETTINGSWIN_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTSETTINGSWIN \
  NS_IMETHOD GetDeviceName(char16_t * *aDeviceName); \
  NS_IMETHOD SetDeviceName(const char16_t * aDeviceName); \
  NS_IMETHOD GetDriverName(char16_t * *aDriverName); \
  NS_IMETHOD SetDriverName(const char16_t * aDriverName); \
  NS_IMETHOD GetDevMode(DEVMODEW **aDevMode); \
  NS_IMETHOD SetDevMode(DEVMODEW *aDevMode); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTSETTINGSWIN(_to) \
  NS_IMETHOD GetDeviceName(char16_t * *aDeviceName) { return _to GetDeviceName(aDeviceName); } \
  NS_IMETHOD SetDeviceName(const char16_t * aDeviceName) { return _to SetDeviceName(aDeviceName); } \
  NS_IMETHOD GetDriverName(char16_t * *aDriverName) { return _to GetDriverName(aDriverName); } \
  NS_IMETHOD SetDriverName(const char16_t * aDriverName) { return _to SetDriverName(aDriverName); } \
  NS_IMETHOD GetDevMode(DEVMODEW **aDevMode) { return _to GetDevMode(aDevMode); } \
  NS_IMETHOD SetDevMode(DEVMODEW *aDevMode) { return _to SetDevMode(aDevMode); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTSETTINGSWIN(_to) \
  NS_IMETHOD GetDeviceName(char16_t * *aDeviceName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeviceName(aDeviceName); } \
  NS_IMETHOD SetDeviceName(const char16_t * aDeviceName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDeviceName(aDeviceName); } \
  NS_IMETHOD GetDriverName(char16_t * *aDriverName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDriverName(aDriverName); } \
  NS_IMETHOD SetDriverName(const char16_t * aDriverName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDriverName(aDriverName); } \
  NS_IMETHOD GetDevMode(DEVMODEW **aDevMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDevMode(aDevMode); } \
  NS_IMETHOD SetDevMode(DEVMODEW *aDevMode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDevMode(aDevMode); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintSettingsWin : public nsIPrintSettingsWin
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTSETTINGSWIN

  nsPrintSettingsWin();

private:
  ~nsPrintSettingsWin();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintSettingsWin, nsIPrintSettingsWin)

nsPrintSettingsWin::nsPrintSettingsWin()
{
  /* member initializers and constructor code */
}

nsPrintSettingsWin::~nsPrintSettingsWin()
{
  /* destructor code */
}

/* [noscript] attribute wstring deviceName; */
NS_IMETHODIMP nsPrintSettingsWin::GetDeviceName(char16_t * *aDeviceName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettingsWin::SetDeviceName(const char16_t * aDeviceName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute wstring driverName; */
NS_IMETHODIMP nsPrintSettingsWin::GetDriverName(char16_t * *aDriverName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettingsWin::SetDriverName(const char16_t * aDriverName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsDevMode devMode; */
NS_IMETHODIMP nsPrintSettingsWin::GetDevMode(DEVMODEW **aDevMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrintSettingsWin::SetDevMode(DEVMODEW *aDevMode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintSettingsWin_h__ */
