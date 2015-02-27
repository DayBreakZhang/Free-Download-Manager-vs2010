/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsITransferable.idl
 */

#ifndef __gen_nsITransferable_h__
#define __gen_nsITransferable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISupportsArray_h__
#include "nsISupportsArray.h"
#endif

#ifndef __gen_nsIFormatConverter_h__
#include "nsIFormatConverter.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

// these probably shouldn't live here, but in some central repository shared
// by the entire app.
#define kTextMime                   "text/plain"
#define kUnicodeMime                "text/unicode"
#define kMozTextInternal          "text/x-moz-text-internal"  // text data which isn't suppoed to be parsed by other apps.
#define kHTMLMime                   "text/html"
#define kAOLMailMime                "AOLMAIL"
#define kPNGImageMime               "image/png"
#define kJPEGImageMime              "image/jpeg"
#define kJPGImageMime               "image/jpg"
#define kGIFImageMime               "image/gif"
#define kFileMime                   "application/x-moz-file"
#define kURLMime                    "text/x-moz-url"        // data contains url\ntitle
#define kURLDataMime                "text/x-moz-url-data"   // data contains url only
#define kURLDescriptionMime         "text/x-moz-url-desc"   // data contains description
#define kURLPrivateMime             "text/x-moz-url-priv"   // same as kURLDataMime but for private uses
#define kNativeImageMime            "application/x-moz-nativeimage"
#define kNativeHTMLMime             "application/x-moz-nativehtml"
// These are used to indicate the context for a fragment of HTML source, such
// that some parent structure and style can be preserved. kHTMLContext
// contains the serialized ancestor elements, whereas kHTMLInfo are numbers
// identifying where in the context the fragment was from.
#define kHTMLContext   "text/_moz_htmlcontext"
#define kHTMLInfo      "text/_moz_htmlinfo"
// the source URL for a file promise
#define kFilePromiseURLMime         "application/x-moz-file-promise-url"
// the destination filename for a file promise
#define kFilePromiseDestFilename    "application/x-moz-file-promise-dest-filename"
// a dataless flavor used to interact with the OS during file drags
#define kFilePromiseMime            "application/x-moz-file-promise"
// a synthetic flavor, put into the transferable once we know the destination directory of a file drag
#define kFilePromiseDirectoryMime   "application/x-moz-file-promise-dir"
class nsITransferable; /* forward declaration */

class nsILoadContext; /* forward declaration */


/* starting interface:    nsIFlavorDataProvider */
#define NS_IFLAVORDATAPROVIDER_IID_STR "7e225e5f-711c-11d7-9fae-000393636592"

#define NS_IFLAVORDATAPROVIDER_IID \
  {0x7e225e5f, 0x711c, 0x11d7, \
    { 0x9f, 0xae, 0x00, 0x03, 0x93, 0x63, 0x65, 0x92 }}

class NS_NO_VTABLE nsIFlavorDataProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFLAVORDATAPROVIDER_IID)

  /* void getFlavorData (in nsITransferable aTransferable, in string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
  NS_IMETHOD GetFlavorData(nsITransferable *aTransferable, const char * aFlavor, nsISupports * *aData, uint32_t *aDataLen) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFlavorDataProvider, NS_IFLAVORDATAPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFLAVORDATAPROVIDER \
  NS_IMETHOD GetFlavorData(nsITransferable *aTransferable, const char * aFlavor, nsISupports * *aData, uint32_t *aDataLen); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFLAVORDATAPROVIDER(_to) \
  NS_IMETHOD GetFlavorData(nsITransferable *aTransferable, const char * aFlavor, nsISupports * *aData, uint32_t *aDataLen) { return _to GetFlavorData(aTransferable, aFlavor, aData, aDataLen); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFLAVORDATAPROVIDER(_to) \
  NS_IMETHOD GetFlavorData(nsITransferable *aTransferable, const char * aFlavor, nsISupports * *aData, uint32_t *aDataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlavorData(aTransferable, aFlavor, aData, aDataLen); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFlavorDataProvider : public nsIFlavorDataProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFLAVORDATAPROVIDER

  nsFlavorDataProvider();

private:
  ~nsFlavorDataProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFlavorDataProvider, nsIFlavorDataProvider)

nsFlavorDataProvider::nsFlavorDataProvider()
{
  /* member initializers and constructor code */
}

nsFlavorDataProvider::~nsFlavorDataProvider()
{
  /* destructor code */
}

/* void getFlavorData (in nsITransferable aTransferable, in string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
NS_IMETHODIMP nsFlavorDataProvider::GetFlavorData(nsITransferable *aTransferable, const char * aFlavor, nsISupports * *aData, uint32_t *aDataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITransferable */
#define NS_ITRANSFERABLE_IID_STR "5a611a60-e5b5-11e1-aff1-0800200c9a66"

#define NS_ITRANSFERABLE_IID \
  {0x5a611a60, 0xe5b5, 0x11e1, \
    { 0xaf, 0xf1, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsITransferable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITRANSFERABLE_IID)

  enum {
    kFlavorHasDataProvider = 0
  };

  /* void init (in nsILoadContext aContext); */
  NS_IMETHOD Init(nsILoadContext *aContext) = 0;

  /* nsISupportsArray flavorsTransferableCanExport (); */
  NS_IMETHOD FlavorsTransferableCanExport(nsISupportsArray * *_retval) = 0;

  /* void getTransferData (in string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
  NS_IMETHOD GetTransferData(const char * aFlavor, nsISupports * *aData, uint32_t *aDataLen) = 0;

  /* void getAnyTransferData (out string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
  NS_IMETHOD GetAnyTransferData(char * *aFlavor, nsISupports * *aData, uint32_t *aDataLen) = 0;

  /* boolean isLargeDataSet (); */
  NS_IMETHOD IsLargeDataSet(bool *_retval) = 0;

  /* nsISupportsArray flavorsTransferableCanImport (); */
  NS_IMETHOD FlavorsTransferableCanImport(nsISupportsArray * *_retval) = 0;

  /* void setTransferData (in string aFlavor, in nsISupports aData, in unsigned long aDataLen); */
  NS_IMETHOD SetTransferData(const char * aFlavor, nsISupports *aData, uint32_t aDataLen) = 0;

  /* void addDataFlavor (in string aDataFlavor); */
  NS_IMETHOD AddDataFlavor(const char * aDataFlavor) = 0;

  /* void removeDataFlavor (in string aDataFlavor); */
  NS_IMETHOD RemoveDataFlavor(const char * aDataFlavor) = 0;

  /* attribute nsIFormatConverter converter; */
  NS_IMETHOD GetConverter(nsIFormatConverter * *aConverter) = 0;
  NS_IMETHOD SetConverter(nsIFormatConverter *aConverter) = 0;

  /* [noscript] attribute boolean isPrivateData; */
  NS_IMETHOD GetIsPrivateData(bool *aIsPrivateData) = 0;
  NS_IMETHOD SetIsPrivateData(bool aIsPrivateData) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITransferable, NS_ITRANSFERABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITRANSFERABLE \
  NS_IMETHOD Init(nsILoadContext *aContext); \
  NS_IMETHOD FlavorsTransferableCanExport(nsISupportsArray * *_retval); \
  NS_IMETHOD GetTransferData(const char * aFlavor, nsISupports * *aData, uint32_t *aDataLen); \
  NS_IMETHOD GetAnyTransferData(char * *aFlavor, nsISupports * *aData, uint32_t *aDataLen); \
  NS_IMETHOD IsLargeDataSet(bool *_retval); \
  NS_IMETHOD FlavorsTransferableCanImport(nsISupportsArray * *_retval); \
  NS_IMETHOD SetTransferData(const char * aFlavor, nsISupports *aData, uint32_t aDataLen); \
  NS_IMETHOD AddDataFlavor(const char * aDataFlavor); \
  NS_IMETHOD RemoveDataFlavor(const char * aDataFlavor); \
  NS_IMETHOD GetConverter(nsIFormatConverter * *aConverter); \
  NS_IMETHOD SetConverter(nsIFormatConverter *aConverter); \
  NS_IMETHOD GetIsPrivateData(bool *aIsPrivateData); \
  NS_IMETHOD SetIsPrivateData(bool aIsPrivateData); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITRANSFERABLE(_to) \
  NS_IMETHOD Init(nsILoadContext *aContext) { return _to Init(aContext); } \
  NS_IMETHOD FlavorsTransferableCanExport(nsISupportsArray * *_retval) { return _to FlavorsTransferableCanExport(_retval); } \
  NS_IMETHOD GetTransferData(const char * aFlavor, nsISupports * *aData, uint32_t *aDataLen) { return _to GetTransferData(aFlavor, aData, aDataLen); } \
  NS_IMETHOD GetAnyTransferData(char * *aFlavor, nsISupports * *aData, uint32_t *aDataLen) { return _to GetAnyTransferData(aFlavor, aData, aDataLen); } \
  NS_IMETHOD IsLargeDataSet(bool *_retval) { return _to IsLargeDataSet(_retval); } \
  NS_IMETHOD FlavorsTransferableCanImport(nsISupportsArray * *_retval) { return _to FlavorsTransferableCanImport(_retval); } \
  NS_IMETHOD SetTransferData(const char * aFlavor, nsISupports *aData, uint32_t aDataLen) { return _to SetTransferData(aFlavor, aData, aDataLen); } \
  NS_IMETHOD AddDataFlavor(const char * aDataFlavor) { return _to AddDataFlavor(aDataFlavor); } \
  NS_IMETHOD RemoveDataFlavor(const char * aDataFlavor) { return _to RemoveDataFlavor(aDataFlavor); } \
  NS_IMETHOD GetConverter(nsIFormatConverter * *aConverter) { return _to GetConverter(aConverter); } \
  NS_IMETHOD SetConverter(nsIFormatConverter *aConverter) { return _to SetConverter(aConverter); } \
  NS_IMETHOD GetIsPrivateData(bool *aIsPrivateData) { return _to GetIsPrivateData(aIsPrivateData); } \
  NS_IMETHOD SetIsPrivateData(bool aIsPrivateData) { return _to SetIsPrivateData(aIsPrivateData); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITRANSFERABLE(_to) \
  NS_IMETHOD Init(nsILoadContext *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aContext); } \
  NS_IMETHOD FlavorsTransferableCanExport(nsISupportsArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FlavorsTransferableCanExport(_retval); } \
  NS_IMETHOD GetTransferData(const char * aFlavor, nsISupports * *aData, uint32_t *aDataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransferData(aFlavor, aData, aDataLen); } \
  NS_IMETHOD GetAnyTransferData(char * *aFlavor, nsISupports * *aData, uint32_t *aDataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnyTransferData(aFlavor, aData, aDataLen); } \
  NS_IMETHOD IsLargeDataSet(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsLargeDataSet(_retval); } \
  NS_IMETHOD FlavorsTransferableCanImport(nsISupportsArray * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FlavorsTransferableCanImport(_retval); } \
  NS_IMETHOD SetTransferData(const char * aFlavor, nsISupports *aData, uint32_t aDataLen) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTransferData(aFlavor, aData, aDataLen); } \
  NS_IMETHOD AddDataFlavor(const char * aDataFlavor) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddDataFlavor(aDataFlavor); } \
  NS_IMETHOD RemoveDataFlavor(const char * aDataFlavor) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveDataFlavor(aDataFlavor); } \
  NS_IMETHOD GetConverter(nsIFormatConverter * *aConverter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetConverter(aConverter); } \
  NS_IMETHOD SetConverter(nsIFormatConverter *aConverter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetConverter(aConverter); } \
  NS_IMETHOD GetIsPrivateData(bool *aIsPrivateData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsPrivateData(aIsPrivateData); } \
  NS_IMETHOD SetIsPrivateData(bool aIsPrivateData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetIsPrivateData(aIsPrivateData); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTransferable : public nsITransferable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITRANSFERABLE

  nsTransferable();

private:
  ~nsTransferable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTransferable, nsITransferable)

nsTransferable::nsTransferable()
{
  /* member initializers and constructor code */
}

nsTransferable::~nsTransferable()
{
  /* destructor code */
}

/* void init (in nsILoadContext aContext); */
NS_IMETHODIMP nsTransferable::Init(nsILoadContext *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupportsArray flavorsTransferableCanExport (); */
NS_IMETHODIMP nsTransferable::FlavorsTransferableCanExport(nsISupportsArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getTransferData (in string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
NS_IMETHODIMP nsTransferable::GetTransferData(const char * aFlavor, nsISupports * *aData, uint32_t *aDataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getAnyTransferData (out string aFlavor, out nsISupports aData, out unsigned long aDataLen); */
NS_IMETHODIMP nsTransferable::GetAnyTransferData(char * *aFlavor, nsISupports * *aData, uint32_t *aDataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isLargeDataSet (); */
NS_IMETHODIMP nsTransferable::IsLargeDataSet(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupportsArray flavorsTransferableCanImport (); */
NS_IMETHODIMP nsTransferable::FlavorsTransferableCanImport(nsISupportsArray * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTransferData (in string aFlavor, in nsISupports aData, in unsigned long aDataLen); */
NS_IMETHODIMP nsTransferable::SetTransferData(const char * aFlavor, nsISupports *aData, uint32_t aDataLen)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addDataFlavor (in string aDataFlavor); */
NS_IMETHODIMP nsTransferable::AddDataFlavor(const char * aDataFlavor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeDataFlavor (in string aDataFlavor); */
NS_IMETHODIMP nsTransferable::RemoveDataFlavor(const char * aDataFlavor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIFormatConverter converter; */
NS_IMETHODIMP nsTransferable::GetConverter(nsIFormatConverter * *aConverter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTransferable::SetConverter(nsIFormatConverter *aConverter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute boolean isPrivateData; */
NS_IMETHODIMP nsTransferable::GetIsPrivateData(bool *aIsPrivateData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTransferable::SetIsPrivateData(bool aIsPrivateData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITransferable_h__ */
