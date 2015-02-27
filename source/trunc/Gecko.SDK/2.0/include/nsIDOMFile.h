/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/content/base/public/nsIDOMFile.idl
 */

#ifndef __gen_nsIDOMFile_h__
#define __gen_nsIDOMFile_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMFileError; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIDOMBlob; /* forward declaration */


/* starting interface:    nsIDOMBlob */
#define NS_IDOMBLOB_IID_STR "5822776a-049c-4de7-adb6-dd9efc39d082"

#define NS_IDOMBLOB_IID \
  {0x5822776a, 0x049c, 0x4de7, \
    { 0xad, 0xb6, 0xdd, 0x9e, 0xfc, 0x39, 0xd0, 0x82 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMBlob : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMBLOB_IID)

  /* readonly attribute unsigned long long size; */
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint64 *aSize) = 0;

  /* readonly attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;

  /* nsIDOMBlob slice (in unsigned long long start, in unsigned long long length, [optional] in DOMString contentType); */
  NS_SCRIPTABLE NS_IMETHOD Slice(PRUint64 start, PRUint64 length, const nsAString & contentType, nsIDOMBlob **_retval NS_OUTPARAM) = 0;

  /* [noscript] readonly attribute nsIInputStream internalStream; */
  NS_IMETHOD GetInternalStream(nsIInputStream **aInternalStream) = 0;

  /* [noscript] DOMString getInternalUrl (in nsIPrincipal principal); */
  NS_IMETHOD GetInternalUrl(nsIPrincipal *principal, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMBlob, NS_IDOMBLOB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMBLOB \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint64 *aSize); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD Slice(PRUint64 start, PRUint64 length, const nsAString & contentType, nsIDOMBlob **_retval NS_OUTPARAM); \
  NS_IMETHOD GetInternalStream(nsIInputStream **aInternalStream); \
  NS_IMETHOD GetInternalUrl(nsIPrincipal *principal, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMBLOB(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint64 *aSize) { return _to GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD Slice(PRUint64 start, PRUint64 length, const nsAString & contentType, nsIDOMBlob **_retval NS_OUTPARAM) { return _to Slice(start, length, contentType, _retval); } \
  NS_IMETHOD GetInternalStream(nsIInputStream **aInternalStream) { return _to GetInternalStream(aInternalStream); } \
  NS_IMETHOD GetInternalUrl(nsIPrincipal *principal, nsAString & _retval NS_OUTPARAM) { return _to GetInternalUrl(principal, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMBLOB(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetSize(PRUint64 *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD Slice(PRUint64 start, PRUint64 length, const nsAString & contentType, nsIDOMBlob **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Slice(start, length, contentType, _retval); } \
  NS_IMETHOD GetInternalStream(nsIInputStream **aInternalStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternalStream(aInternalStream); } \
  NS_IMETHOD GetInternalUrl(nsIPrincipal *principal, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternalUrl(principal, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMBlob : public nsIDOMBlob
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMBLOB

  nsDOMBlob();

private:
  ~nsDOMBlob();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMBlob, nsIDOMBlob)

nsDOMBlob::nsDOMBlob()
{
  /* member initializers and constructor code */
}

nsDOMBlob::~nsDOMBlob()
{
  /* destructor code */
}

/* readonly attribute unsigned long long size; */
NS_IMETHODIMP nsDOMBlob::GetSize(PRUint64 *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsDOMBlob::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMBlob slice (in unsigned long long start, in unsigned long long length, [optional] in DOMString contentType); */
NS_IMETHODIMP nsDOMBlob::Slice(PRUint64 start, PRUint64 length, const nsAString & contentType, nsIDOMBlob **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIInputStream internalStream; */
NS_IMETHODIMP nsDOMBlob::GetInternalStream(nsIInputStream **aInternalStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] DOMString getInternalUrl (in nsIPrincipal principal); */
NS_IMETHODIMP nsDOMBlob::GetInternalUrl(nsIPrincipal *principal, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMFile */
#define NS_IDOMFILE_IID_STR "ae1405b0-e411-481e-9606-b29ec7982687"

#define NS_IDOMFILE_IID \
  {0xae1405b0, 0xe411, 0x481e, \
    { 0x96, 0x06, 0xb2, 0x9e, 0xc7, 0x98, 0x26, 0x87 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMFile : public nsIDOMBlob {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFILE_IID)

  /* readonly attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString mozFullPath; */
  NS_SCRIPTABLE NS_IMETHOD GetMozFullPath(nsAString & aMozFullPath) = 0;

  /* [noscript] readonly attribute DOMString mozFullPathInternal; */
  NS_IMETHOD GetMozFullPathInternal(nsAString & aMozFullPathInternal) = 0;

  /* readonly attribute DOMString fileName; */
  NS_SCRIPTABLE NS_IMETHOD GetFileName(nsAString & aFileName) = 0;

  /* readonly attribute unsigned long long fileSize; */
  NS_SCRIPTABLE NS_IMETHOD GetFileSize(PRUint64 *aFileSize) = 0;

  /* DOMString getAsText (in DOMString encoding); */
  NS_SCRIPTABLE NS_IMETHOD GetAsText(const nsAString & encoding, nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString getAsDataURL (); */
  NS_SCRIPTABLE NS_IMETHOD GetAsDataURL(nsAString & _retval NS_OUTPARAM) = 0;

  /* DOMString getAsBinary (); */
  NS_SCRIPTABLE NS_IMETHOD GetAsBinary(nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFile, NS_IDOMFILE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFILE \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetMozFullPath(nsAString & aMozFullPath); \
  NS_IMETHOD GetMozFullPathInternal(nsAString & aMozFullPathInternal); \
  NS_SCRIPTABLE NS_IMETHOD GetFileName(nsAString & aFileName); \
  NS_SCRIPTABLE NS_IMETHOD GetFileSize(PRUint64 *aFileSize); \
  NS_SCRIPTABLE NS_IMETHOD GetAsText(const nsAString & encoding, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAsDataURL(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetAsBinary(nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFILE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozFullPath(nsAString & aMozFullPath) { return _to GetMozFullPath(aMozFullPath); } \
  NS_IMETHOD GetMozFullPathInternal(nsAString & aMozFullPathInternal) { return _to GetMozFullPathInternal(aMozFullPathInternal); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileName(nsAString & aFileName) { return _to GetFileName(aFileName); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileSize(PRUint64 *aFileSize) { return _to GetFileSize(aFileSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetAsText(const nsAString & encoding, nsAString & _retval NS_OUTPARAM) { return _to GetAsText(encoding, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAsDataURL(nsAString & _retval NS_OUTPARAM) { return _to GetAsDataURL(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAsBinary(nsAString & _retval NS_OUTPARAM) { return _to GetAsBinary(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFILE(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetMozFullPath(nsAString & aMozFullPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFullPath(aMozFullPath); } \
  NS_IMETHOD GetMozFullPathInternal(nsAString & aMozFullPathInternal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFullPathInternal(aMozFullPathInternal); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileName(nsAString & aFileName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileName(aFileName); } \
  NS_SCRIPTABLE NS_IMETHOD GetFileSize(PRUint64 *aFileSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFileSize(aFileSize); } \
  NS_SCRIPTABLE NS_IMETHOD GetAsText(const nsAString & encoding, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsText(encoding, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAsDataURL(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsDataURL(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetAsBinary(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAsBinary(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFile : public nsIDOMFile
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFILE

  nsDOMFile();

private:
  ~nsDOMFile();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMFile, nsIDOMFile)

nsDOMFile::nsDOMFile()
{
  /* member initializers and constructor code */
}

nsDOMFile::~nsDOMFile()
{
  /* destructor code */
}

/* readonly attribute DOMString name; */
NS_IMETHODIMP nsDOMFile::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString mozFullPath; */
NS_IMETHODIMP nsDOMFile::GetMozFullPath(nsAString & aMozFullPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute DOMString mozFullPathInternal; */
NS_IMETHODIMP nsDOMFile::GetMozFullPathInternal(nsAString & aMozFullPathInternal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString fileName; */
NS_IMETHODIMP nsDOMFile::GetFileName(nsAString & aFileName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long fileSize; */
NS_IMETHODIMP nsDOMFile::GetFileSize(PRUint64 *aFileSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getAsText (in DOMString encoding); */
NS_IMETHODIMP nsDOMFile::GetAsText(const nsAString & encoding, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getAsDataURL (); */
NS_IMETHODIMP nsDOMFile::GetAsDataURL(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString getAsBinary (); */
NS_IMETHODIMP nsDOMFile::GetAsBinary(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMFile_h__ */
