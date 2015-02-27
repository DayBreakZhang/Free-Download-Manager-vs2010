/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIContentViewerFile.idl
 */

#ifndef __gen_nsIContentViewerFile_h__
#define __gen_nsIContentViewerFile_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIPrintSettings; /* forward declaration */

class nsIWebProgressListener; /* forward declaration */

#include <stdio.h>

/* starting interface:    nsIContentViewerFile */
#define NS_ICONTENTVIEWERFILE_IID_STR "564a3276-6228-401e-9b5c-d82cb382a60f"

#define NS_ICONTENTVIEWERFILE_IID \
  {0x564a3276, 0x6228, 0x401e, \
    { 0x9b, 0x5c, 0xd8, 0x2c, 0xb3, 0x82, 0xa6, 0x0f }}

class NS_NO_VTABLE nsIContentViewerFile : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTVIEWERFILE_IID)

  /* readonly attribute boolean printable; */
  NS_IMETHOD GetPrintable(bool *aPrintable) = 0;

  /* [noscript] void print (in boolean aSilent, in FILE aDebugFile, in nsIPrintSettings aPrintSettings); */
  NS_IMETHOD Print(bool aSilent, FILE *aDebugFile, nsIPrintSettings *aPrintSettings) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentViewerFile, NS_ICONTENTVIEWERFILE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTVIEWERFILE \
  NS_IMETHOD GetPrintable(bool *aPrintable); \
  NS_IMETHOD Print(bool aSilent, FILE *aDebugFile, nsIPrintSettings *aPrintSettings); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTVIEWERFILE(_to) \
  NS_IMETHOD GetPrintable(bool *aPrintable) { return _to GetPrintable(aPrintable); } \
  NS_IMETHOD Print(bool aSilent, FILE *aDebugFile, nsIPrintSettings *aPrintSettings) { return _to Print(aSilent, aDebugFile, aPrintSettings); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTVIEWERFILE(_to) \
  NS_IMETHOD GetPrintable(bool *aPrintable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPrintable(aPrintable); } \
  NS_IMETHOD Print(bool aSilent, FILE *aDebugFile, nsIPrintSettings *aPrintSettings) { return !_to ? NS_ERROR_NULL_POINTER : _to->Print(aSilent, aDebugFile, aPrintSettings); } 

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

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentViewerFile_h__ */
