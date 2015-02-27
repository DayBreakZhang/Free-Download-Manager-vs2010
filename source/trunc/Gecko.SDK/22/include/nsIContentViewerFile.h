/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/docshell/base/nsIContentViewerFile.idl
 */

#ifndef __gen_nsIContentViewerFile_h__
#define __gen_nsIContentViewerFile_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPrintSettings_h__
#include "nsIPrintSettings.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIWebProgressListener; /* forward declaration */

#include <stdio.h>

/* starting interface:    nsIContentViewerFile */
#define NS_ICONTENTVIEWERFILE_IID_STR "1b373597-6132-49f7-940e-6ff62fca5d35"

#define NS_ICONTENTVIEWERFILE_IID \
  {0x1b373597, 0x6132, 0x49f7, \
    { 0x94, 0x0e, 0x6f, 0xf6, 0x2f, 0xca, 0x5d, 0x35 }}

class NS_NO_VTABLE nsIContentViewerFile : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEWERFILE_IID)

  /* readonly attribute boolean printable; */
  NS_IMETHOD GetPrintable(bool *aPrintable) = 0;

  /* [noscript] void print (in boolean aSilent, in FILE aDebugFile, in nsIPrintSettings aPrintSettings); */
  NS_IMETHOD Print(bool aSilent, FILE *aDebugFile, nsIPrintSettings *aPrintSettings) = 0;

  /* [noscript] void printWithParent (in nsIDOMWindow aParentWin, in nsIPrintSettings aThePrintSettings, in nsIWebProgressListener aWPListener); */
  NS_IMETHOD PrintWithParent(nsIDOMWindow *aParentWin, nsIPrintSettings *aThePrintSettings, nsIWebProgressListener *aWPListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentViewerFile, NS_ICONTENTVIEWERFILE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEWERFILE \
  NS_IMETHOD GetPrintable(bool *aPrintable); \
  NS_IMETHOD Print(bool aSilent, FILE *aDebugFile, nsIPrintSettings *aPrintSettings); \
  NS_IMETHOD PrintWithParent(nsIDOMWindow *aParentWin, nsIPrintSettings *aThePrintSettings, nsIWebProgressListener *aWPListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEWERFILE(_to) \
  NS_IMETHOD GetPrintable(bool *aPrintable) { return _to GetPrintable(aPrintable); } \
  NS_IMETHOD Print(bool aSilent, FILE *aDebugFile, nsIPrintSettings *aPrintSettings) { return _to Print(aSilent, aDebugFile, aPrintSettings); } \
  NS_IMETHOD PrintWithParent(nsIDOMWindow *aParentWin, nsIPrintSettings *aThePrintSettings, nsIWebProgressListener *aWPListener) { return _to PrintWithParent(aParentWin, aThePrintSettings, aWPListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEWERFILE(_to) \
  NS_IMETHOD GetPrintable(bool *aPrintable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintable(aPrintable); } \
  NS_IMETHOD Print(bool aSilent, FILE *aDebugFile, nsIPrintSettings *aPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->Print(aSilent, aDebugFile, aPrintSettings); } \
  NS_IMETHOD PrintWithParent(nsIDOMWindow *aParentWin, nsIPrintSettings *aThePrintSettings, nsIWebProgressListener *aWPListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrintWithParent(aParentWin, aThePrintSettings, aWPListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentViewerFile : public nsIContentViewerFile
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTVIEWERFILE

  nsContentViewerFile();

private:
  ~nsContentViewerFile();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentViewerFile, nsIContentViewerFile)

nsContentViewerFile::nsContentViewerFile()
{
  /* member initializers and constructor code */
}

nsContentViewerFile::~nsContentViewerFile()
{
  /* destructor code */
}

/* readonly attribute boolean printable; */
NS_IMETHODIMP nsContentViewerFile::GetPrintable(bool *aPrintable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void print (in boolean aSilent, in FILE aDebugFile, in nsIPrintSettings aPrintSettings); */
NS_IMETHODIMP nsContentViewerFile::Print(bool aSilent, FILE *aDebugFile, nsIPrintSettings *aPrintSettings)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void printWithParent (in nsIDOMWindow aParentWin, in nsIPrintSettings aThePrintSettings, in nsIWebProgressListener aWPListener); */
NS_IMETHODIMP nsContentViewerFile::PrintWithParent(nsIDOMWindow *aParentWin, nsIPrintSettings *aThePrintSettings, nsIWebProgressListener *aWPListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentViewerFile_h__ */
