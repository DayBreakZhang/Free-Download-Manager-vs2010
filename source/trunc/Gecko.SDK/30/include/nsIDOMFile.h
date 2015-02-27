/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMFile.idl
 */

#ifndef __gen_nsIDOMFile_h__
#define __gen_nsIDOMFile_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "js/Value.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
namespace mozilla {
namespace dom {
namespace indexedDB {
class FileInfo;
class FileManager;
}
}
}
class nsIDOMFileError; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIPrincipal; /* forward declaration */

class nsIDOMBlob; /* forward declaration */


/* starting interface:    nsIDOMBlob */
#define NS_IDOMBLOB_IID_STR "b1723fac-4814-4429-82cb-dc54ba0d46d6"

#define NS_IDOMBLOB_IID \
  {0xb1723fac, 0x4814, 0x4429, \
    { 0x82, 0xcb, 0xdc, 0x54, 0xba, 0x0d, 0x46, 0xd6 }}

class NS_NO_VTABLE nsIDOMBlob : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMBLOB_IID)

  /* readonly attribute unsigned long long size; */
  NS_IMETHOD GetSize(uint64_t *aSize) = 0;

  /* readonly attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* [noscript] readonly attribute nsIInputStream internalStream; */
  NS_IMETHOD GetInternalStream(nsIInputStream * *aInternalStream) = 0;

  /* [noscript] DOMString getInternalUrl (in nsIPrincipal principal); */
  NS_IMETHOD GetInternalUrl(nsIPrincipal *principal, nsAString & _retval) = 0;

  /* [optional_argc] nsIDOMBlob slice ([optional] in long long start, [optional] in long long end, [optional] in DOMString contentType); */
  NS_IMETHOD Slice(int64_t start, int64_t end, const nsAString & contentType, uint8_t _argc, nsIDOMBlob * *_retval) = 0;

  /* [notxpcom] long long getFileId (); */
  NS_IMETHOD_(int64_t) GetFileId(void) = 0;

  /* [notxpcom] void addFileInfo (in FileInfo aFileInfo); */
  NS_IMETHOD_(void) AddFileInfo(mozilla::dom::indexedDB::FileInfo *aFileInfo) = 0;

  /* [notxpcom] FileInfo getFileInfo (in FileManager aFileManager); */
  NS_IMETHOD_(mozilla::dom::indexedDB::FileInfo *) GetFileInfo(mozilla::dom::indexedDB::FileManager *aFileManager) = 0;

  /* [notxpcom] bool isMemoryFile (); */
  NS_IMETHOD_(bool) IsMemoryFile(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMBlob, NS_IDOMBLOB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMBLOB \
  NS_IMETHOD GetSize(uint64_t *aSize); \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetInternalStream(nsIInputStream * *aInternalStream); \
  NS_IMETHOD GetInternalUrl(nsIPrincipal *principal, nsAString & _retval); \
  NS_IMETHOD Slice(int64_t start, int64_t end, const nsAString & contentType, uint8_t _argc, nsIDOMBlob * *_retval); \
  NS_IMETHOD_(int64_t) GetFileId(void); \
  NS_IMETHOD_(void) AddFileInfo(mozilla::dom::indexedDB::FileInfo *aFileInfo); \
  NS_IMETHOD_(mozilla::dom::indexedDB::FileInfo *) GetFileInfo(mozilla::dom::indexedDB::FileManager *aFileManager); \
  NS_IMETHOD_(bool) IsMemoryFile(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMBLOB(_to) \
  NS_IMETHOD GetSize(uint64_t *aSize) { return _to GetSize(aSize); } \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetInternalStream(nsIInputStream * *aInternalStream) { return _to GetInternalStream(aInternalStream); } \
  NS_IMETHOD GetInternalUrl(nsIPrincipal *principal, nsAString & _retval) { return _to GetInternalUrl(principal, _retval); } \
  NS_IMETHOD Slice(int64_t start, int64_t end, const nsAString & contentType, uint8_t _argc, nsIDOMBlob * *_retval) { return _to Slice(start, end, contentType, _argc, _retval); } \
  NS_IMETHOD_(int64_t) GetFileId(void) { return _to GetFileId(); } \
  NS_IMETHOD_(void) AddFileInfo(mozilla::dom::indexedDB::FileInfo *aFileInfo) { return _to AddFileInfo(aFileInfo); } \
  NS_IMETHOD_(mozilla::dom::indexedDB::FileInfo *) GetFileInfo(mozilla::dom::indexedDB::FileManager *aFileManager) { return _to GetFileInfo(aFileManager); } \
  NS_IMETHOD_(bool) IsMemoryFile(void) { return _to IsMemoryFile(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMBLOB(_to) \
  NS_IMETHOD GetSize(uint64_t *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetInternalStream(nsIInputStream * *aInternalStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternalStream(aInternalStream); } \
  NS_IMETHOD GetInternalUrl(nsIPrincipal *principal, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInternalUrl(principal, _retval); } \
  NS_IMETHOD Slice(int64_t start, int64_t end, const nsAString & contentType, uint8_t _argc, nsIDOMBlob * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Slice(start, end, contentType, _argc, _retval); } \
  NS_IMETHOD_(int64_t) GetFileId(void); \
  NS_IMETHOD_(void) AddFileInfo(mozilla::dom::indexedDB::FileInfo *aFileInfo); \
  NS_IMETHOD_(mozilla::dom::indexedDB::FileInfo *) GetFileInfo(mozilla::dom::indexedDB::FileManager *aFileManager); \
  NS_IMETHOD_(bool) IsMemoryFile(void); 

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
NS_IMETHODIMP nsDOMBlob::GetSize(uint64_t *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsDOMBlob::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIInputStream internalStream; */
NS_IMETHODIMP nsDOMBlob::GetInternalStream(nsIInputStream * *aInternalStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] DOMString getInternalUrl (in nsIPrincipal principal); */
NS_IMETHODIMP nsDOMBlob::GetInternalUrl(nsIPrincipal *principal, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] nsIDOMBlob slice ([optional] in long long start, [optional] in long long end, [optional] in DOMString contentType); */
NS_IMETHODIMP nsDOMBlob::Slice(int64_t start, int64_t end, const nsAString & contentType, uint8_t _argc, nsIDOMBlob * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] long long getFileId (); */
NS_IMETHODIMP_(int64_t) nsDOMBlob::GetFileId()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] void addFileInfo (in FileInfo aFileInfo); */
NS_IMETHODIMP_(void) nsDOMBlob::AddFileInfo(mozilla::dom::indexedDB::FileInfo *aFileInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] FileInfo getFileInfo (in FileManager aFileManager); */
NS_IMETHODIMP_(mozilla::dom::indexedDB::FileInfo *) nsDOMBlob::GetFileInfo(mozilla::dom::indexedDB::FileManager *aFileManager)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [notxpcom] bool isMemoryFile (); */
NS_IMETHODIMP_(bool) nsDOMBlob::IsMemoryFile()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMFile */
#define NS_IDOMFILE_IID_STR "4e7d1a8b-e2d5-4304-a753-4affb731660c"

#define NS_IDOMFILE_IID \
  {0x4e7d1a8b, 0xe2d5, 0x4304, \
    { 0xa7, 0x53, 0x4a, 0xff, 0xb7, 0x31, 0x66, 0x0c }}

class NS_NO_VTABLE nsIDOMFile : public nsIDOMBlob {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFILE_IID)

  /* readonly attribute DOMString name; */
  NS_IMETHOD GetName(nsAString & aName) = 0;

  /* readonly attribute DOMString path; */
  NS_IMETHOD GetPath(nsAString & aPath) = 0;

  /* [implicit_jscontext] readonly attribute jsval lastModifiedDate; */
  NS_IMETHOD GetLastModifiedDate(JSContext* cx, JS::MutableHandleValue aLastModifiedDate) = 0;

  /* readonly attribute DOMString mozFullPath; */
  NS_IMETHOD GetMozFullPath(nsAString & aMozFullPath) = 0;

  /* [noscript] readonly attribute DOMString mozFullPathInternal; */
  NS_IMETHOD GetMozFullPathInternal(nsAString & aMozFullPathInternal) = 0;

  /* [noscript] readonly attribute uint64_t mozLastModifiedDate; */
  NS_IMETHOD GetMozLastModifiedDate(uint64_t *aMozLastModifiedDate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFile, NS_IDOMFILE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFILE \
  NS_IMETHOD GetName(nsAString & aName); \
  NS_IMETHOD GetPath(nsAString & aPath); \
  NS_IMETHOD GetLastModifiedDate(JSContext* cx, JS::MutableHandleValue aLastModifiedDate); \
  NS_IMETHOD GetMozFullPath(nsAString & aMozFullPath); \
  NS_IMETHOD GetMozFullPathInternal(nsAString & aMozFullPathInternal); \
  NS_IMETHOD GetMozLastModifiedDate(uint64_t *aMozLastModifiedDate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFILE(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetPath(nsAString & aPath) { return _to GetPath(aPath); } \
  NS_IMETHOD GetLastModifiedDate(JSContext* cx, JS::MutableHandleValue aLastModifiedDate) { return _to GetLastModifiedDate(cx, aLastModifiedDate); } \
  NS_IMETHOD GetMozFullPath(nsAString & aMozFullPath) { return _to GetMozFullPath(aMozFullPath); } \
  NS_IMETHOD GetMozFullPathInternal(nsAString & aMozFullPathInternal) { return _to GetMozFullPathInternal(aMozFullPathInternal); } \
  NS_IMETHOD GetMozLastModifiedDate(uint64_t *aMozLastModifiedDate) { return _to GetMozLastModifiedDate(aMozLastModifiedDate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFILE(_to) \
  NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetPath(nsAString & aPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPath(aPath); } \
  NS_IMETHOD GetLastModifiedDate(JSContext* cx, JS::MutableHandleValue aLastModifiedDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModifiedDate(cx, aLastModifiedDate); } \
  NS_IMETHOD GetMozFullPath(nsAString & aMozFullPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFullPath(aMozFullPath); } \
  NS_IMETHOD GetMozFullPathInternal(nsAString & aMozFullPathInternal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozFullPathInternal(aMozFullPathInternal); } \
  NS_IMETHOD GetMozLastModifiedDate(uint64_t *aMozLastModifiedDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMozLastModifiedDate(aMozLastModifiedDate); } 

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

/* readonly attribute DOMString path; */
NS_IMETHODIMP nsDOMFile::GetPath(nsAString & aPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval lastModifiedDate; */
NS_IMETHODIMP nsDOMFile::GetLastModifiedDate(JSContext* cx, JS::MutableHandleValue aLastModifiedDate)
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

/* [noscript] readonly attribute uint64_t mozLastModifiedDate; */
NS_IMETHODIMP nsDOMFile::GetMozLastModifiedDate(uint64_t *aMozLastModifiedDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMFile_h__ */
