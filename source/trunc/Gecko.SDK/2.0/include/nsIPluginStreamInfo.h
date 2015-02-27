/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/modules/plugin/base/public/nsIPluginStreamInfo.idl
 */

#ifndef __gen_nsIPluginStreamInfo_h__
#define __gen_nsIPluginStreamInfo_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nspluginroot_h__
#include "nspluginroot.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "npapi.h"

/* starting interface:    nsIPluginStreamInfo */
#define NS_IPLUGINSTREAMINFO_IID_STR "a700845f-0e26-44ea-84f5-3be5381f98d5"

#define NS_IPLUGINSTREAMINFO_IID \
  {0xa700845f, 0x0e26, 0x44ea, \
    { 0x84, 0xf5, 0x3b, 0xe5, 0x38, 0x1f, 0x98, 0xd5 }}

class NS_NO_VTABLE nsIPluginStreamInfo : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPLUGINSTREAMINFO_IID)

  /* readonly attribute string contentType; */
  NS_IMETHOD GetContentType(char **aContentType) = 0;

  /* void isSeekable (out boolean aSeekable); */
  NS_IMETHOD IsSeekable(PRBool *aSeekable NS_OUTPARAM) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* readonly attribute unsigned long lastModified; */
  NS_IMETHOD GetLastModified(PRUint32 *aLastModified) = 0;

  /* void getURL (out constCharPtr aURL); */
  NS_IMETHOD GetURL(const char **aURL NS_OUTPARAM) = 0;

  /* void requestRead (in NPByteRangePtr aRangeList); */
  NS_IMETHOD RequestRead(NPByteRange *aRangeList) = 0;

  /* attribute long streamOffset; */
  NS_IMETHOD GetStreamOffset(PRInt32 *aStreamOffset) = 0;
  NS_IMETHOD SetStreamOffset(PRInt32 aStreamOffset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPluginStreamInfo, NS_IPLUGINSTREAMINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPLUGINSTREAMINFO \
  NS_IMETHOD GetContentType(char **aContentType); \
  NS_IMETHOD IsSeekable(PRBool *aSeekable NS_OUTPARAM); \
  NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_IMETHOD GetLastModified(PRUint32 *aLastModified); \
  NS_IMETHOD GetURL(const char **aURL NS_OUTPARAM); \
  NS_IMETHOD RequestRead(NPByteRange *aRangeList); \
  NS_IMETHOD GetStreamOffset(PRInt32 *aStreamOffset); \
  NS_IMETHOD SetStreamOffset(PRInt32 aStreamOffset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPLUGINSTREAMINFO(_to) \
  NS_IMETHOD GetContentType(char **aContentType) { return _to GetContentType(aContentType); } \
  NS_IMETHOD IsSeekable(PRBool *aSeekable NS_OUTPARAM) { return _to IsSeekable(aSeekable); } \
  NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD GetLastModified(PRUint32 *aLastModified) { return _to GetLastModified(aLastModified); } \
  NS_IMETHOD GetURL(const char **aURL NS_OUTPARAM) { return _to GetURL(aURL); } \
  NS_IMETHOD RequestRead(NPByteRange *aRangeList) { return _to RequestRead(aRangeList); } \
  NS_IMETHOD GetStreamOffset(PRInt32 *aStreamOffset) { return _to GetStreamOffset(aStreamOffset); } \
  NS_IMETHOD SetStreamOffset(PRInt32 aStreamOffset) { return _to SetStreamOffset(aStreamOffset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPLUGINSTREAMINFO(_to) \
  NS_IMETHOD GetContentType(char **aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentType(aContentType); } \
  NS_IMETHOD IsSeekable(PRBool *aSeekable NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSeekable(aSeekable); } \
  NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD GetLastModified(PRUint32 *aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } \
  NS_IMETHOD GetURL(const char **aURL NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURL(aURL); } \
  NS_IMETHOD RequestRead(NPByteRange *aRangeList) { return !_to ? NS_ERROR_NULL_POINTER : _to->RequestRead(aRangeList); } \
  NS_IMETHOD GetStreamOffset(PRInt32 *aStreamOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStreamOffset(aStreamOffset); } \
  NS_IMETHOD SetStreamOffset(PRInt32 aStreamOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStreamOffset(aStreamOffset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPluginStreamInfo : public nsIPluginStreamInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPLUGINSTREAMINFO

  nsPluginStreamInfo();

private:
  ~nsPluginStreamInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPluginStreamInfo, nsIPluginStreamInfo)

nsPluginStreamInfo::nsPluginStreamInfo()
{
  /* member initializers and constructor code */
}

nsPluginStreamInfo::~nsPluginStreamInfo()
{
  /* destructor code */
}

/* readonly attribute string contentType; */
NS_IMETHODIMP nsPluginStreamInfo::GetContentType(char **aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void isSeekable (out boolean aSeekable); */
NS_IMETHODIMP nsPluginStreamInfo::IsSeekable(PRBool *aSeekable NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsPluginStreamInfo::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long lastModified; */
NS_IMETHODIMP nsPluginStreamInfo::GetLastModified(PRUint32 *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getURL (out constCharPtr aURL); */
NS_IMETHODIMP nsPluginStreamInfo::GetURL(const char **aURL NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void requestRead (in NPByteRangePtr aRangeList); */
NS_IMETHODIMP nsPluginStreamInfo::RequestRead(NPByteRange *aRangeList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long streamOffset; */
NS_IMETHODIMP nsPluginStreamInfo::GetStreamOffset(PRInt32 *aStreamOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPluginStreamInfo::SetStreamOffset(PRInt32 aStreamOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPluginStreamInfo_h__ */
