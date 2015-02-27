/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsIPrintSettingsService.idl
 */

#ifndef __gen_nsIPrintSettingsService_h__
#define __gen_nsIPrintSettingsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIPrintSettings; /* forward declaration */


/* starting interface:    nsIPrintSettingsService */
#define NS_IPRINTSETTINGSSERVICE_IID_STR "841387c8-72e6-484b-9296-bf6eea80d58a"

#define NS_IPRINTSETTINGSSERVICE_IID \
  {0x841387c8, 0x72e6, 0x484b, \
    { 0x92, 0x96, 0xbf, 0x6e, 0xea, 0x80, 0xd5, 0x8a }}

class NS_NO_VTABLE nsIPrintSettingsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTSETTINGSSERVICE_IID)

  /* readonly attribute nsIPrintSettings globalPrintSettings; */
  NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings) = 0;

  /* readonly attribute nsIPrintSettings newPrintSettings; */
  NS_IMETHOD GetNewPrintSettings(nsIPrintSettings * *aNewPrintSettings) = 0;

  /* readonly attribute wstring defaultPrinterName; */
  NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName) = 0;

  /* void initPrintSettingsFromPrinter (in wstring aPrinterName, in nsIPrintSettings aPrintSettings); */
  NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar * aPrinterName, nsIPrintSettings *aPrintSettings) = 0;

  /* void initPrintSettingsFromPrefs (in nsIPrintSettings aPrintSettings, in boolean aUsePrinterNamePrefix, in unsigned long aFlags); */
  NS_IMETHOD InitPrintSettingsFromPrefs(nsIPrintSettings *aPrintSettings, bool aUsePrinterNamePrefix, uint32_t aFlags) = 0;

  /* void savePrintSettingsToPrefs (in nsIPrintSettings aPrintSettings, in boolean aUsePrinterNamePrefix, in unsigned long aFlags); */
  NS_IMETHOD SavePrintSettingsToPrefs(nsIPrintSettings *aPrintSettings, bool aUsePrinterNamePrefix, uint32_t aFlags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintSettingsService, NS_IPRINTSETTINGSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTSETTINGSSERVICE \
  NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings); \
  NS_IMETHOD GetNewPrintSettings(nsIPrintSettings * *aNewPrintSettings); \
  NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName); \
  NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar * aPrinterName, nsIPrintSettings *aPrintSettings); \
  NS_IMETHOD InitPrintSettingsFromPrefs(nsIPrintSettings *aPrintSettings, bool aUsePrinterNamePrefix, uint32_t aFlags); \
  NS_IMETHOD SavePrintSettingsToPrefs(nsIPrintSettings *aPrintSettings, bool aUsePrinterNamePrefix, uint32_t aFlags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTSETTINGSSERVICE(_to) \
  NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings) { return _to GetGlobalPrintSettings(aGlobalPrintSettings); } \
  NS_IMETHOD GetNewPrintSettings(nsIPrintSettings * *aNewPrintSettings) { return _to GetNewPrintSettings(aNewPrintSettings); } \
  NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName) { return _to GetDefaultPrinterName(aDefaultPrinterName); } \
  NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar * aPrinterName, nsIPrintSettings *aPrintSettings) { return _to InitPrintSettingsFromPrinter(aPrinterName, aPrintSettings); } \
  NS_IMETHOD InitPrintSettingsFromPrefs(nsIPrintSettings *aPrintSettings, bool aUsePrinterNamePrefix, uint32_t aFlags) { return _to InitPrintSettingsFromPrefs(aPrintSettings, aUsePrinterNamePrefix, aFlags); } \
  NS_IMETHOD SavePrintSettingsToPrefs(nsIPrintSettings *aPrintSettings, bool aUsePrinterNamePrefix, uint32_t aFlags) { return _to SavePrintSettingsToPrefs(aPrintSettings, aUsePrinterNamePrefix, aFlags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTSETTINGSSERVICE(_to) \
  NS_IMETHOD GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGlobalPrintSettings(aGlobalPrintSettings); } \
  NS_IMETHOD GetNewPrintSettings(nsIPrintSettings * *aNewPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewPrintSettings(aNewPrintSettings); } \
  NS_IMETHOD GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDefaultPrinterName(aDefaultPrinterName); } \
  NS_IMETHOD InitPrintSettingsFromPrinter(const PRUnichar * aPrinterName, nsIPrintSettings *aPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPrintSettingsFromPrinter(aPrinterName, aPrintSettings); } \
  NS_IMETHOD InitPrintSettingsFromPrefs(nsIPrintSettings *aPrintSettings, bool aUsePrinterNamePrefix, uint32_t aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitPrintSettingsFromPrefs(aPrintSettings, aUsePrinterNamePrefix, aFlags); } \
  NS_IMETHOD SavePrintSettingsToPrefs(nsIPrintSettings *aPrintSettings, bool aUsePrinterNamePrefix, uint32_t aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->SavePrintSettingsToPrefs(aPrintSettings, aUsePrinterNamePrefix, aFlags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintSettingsService : public nsIPrintSettingsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTSETTINGSSERVICE

  nsPrintSettingsService();

private:
  ~nsPrintSettingsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintSettingsService, nsIPrintSettingsService)

nsPrintSettingsService::nsPrintSettingsService()
{
  /* member initializers and constructor code */
}

nsPrintSettingsService::~nsPrintSettingsService()
{
  /* destructor code */
}

/* readonly attribute nsIPrintSettings globalPrintSettings; */
NS_IMETHODIMP nsPrintSettingsService::GetGlobalPrintSettings(nsIPrintSettings * *aGlobalPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIPrintSettings newPrintSettings; */
NS_IMETHODIMP nsPrintSettingsService::GetNewPrintSettings(nsIPrintSettings * *aNewPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute wstring defaultPrinterName; */
NS_IMETHODIMP nsPrintSettingsService::GetDefaultPrinterName(PRUnichar * *aDefaultPrinterName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPrintSettingsFromPrinter (in wstring aPrinterName, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsPrintSettingsService::InitPrintSettingsFromPrinter(const PRUnichar * aPrinterName, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void initPrintSettingsFromPrefs (in nsIPrintSettings aPrintSettings, in boolean aUsePrinterNamePrefix, in unsigned long aFlags); */
NS_IMETHODIMP nsPrintSettingsService::InitPrintSettingsFromPrefs(nsIPrintSettings *aPrintSettings, bool aUsePrinterNamePrefix, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void savePrintSettingsToPrefs (in nsIPrintSettings aPrintSettings, in boolean aUsePrinterNamePrefix, in unsigned long aFlags); */
NS_IMETHODIMP nsPrintSettingsService::SavePrintSettingsToPrefs(nsIPrintSettings *aPrintSettings, bool aUsePrinterNamePrefix, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// {841387C8-72E6-484b-9296-BF6EEA80D58A}
#define NS_PRINTSETTINGSSERVICE_IID \
 {0x841387c8, 0x72e6, 0x484b, { 0x92, 0x96, 0xbf, 0x6e, 0xea, 0x80, 0xd5, 0x8a}}

#endif /* __gen_nsIPrintSettingsService_h__ */
