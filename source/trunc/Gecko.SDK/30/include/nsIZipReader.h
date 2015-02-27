/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIZipReader.idl
 */

#ifndef __gen_nsIZipReader_h__
#define __gen_nsIZipReader_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUTF8StringEnumerator; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIFile; /* forward declaration */

class nsICertificatePrincipal; /* forward declaration */


/* starting interface:    nsIZipEntry */
#define NS_IZIPENTRY_IID_STR "fad6f72f-13d8-4e26-9173-53007a4afe71"

#define NS_IZIPENTRY_IID \
  {0xfad6f72f, 0x13d8, 0x4e26, \
    { 0x91, 0x73, 0x53, 0x00, 0x7a, 0x4a, 0xfe, 0x71 }}

class NS_NO_VTABLE nsIZipEntry : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPENTRY_IID)

  /* readonly attribute unsigned short compression; */
  NS_IMETHOD GetCompression(uint16_t *aCompression) = 0;

  /* readonly attribute unsigned long size; */
  NS_IMETHOD GetSize(uint32_t *aSize) = 0;

  /* readonly attribute unsigned long realSize; */
  NS_IMETHOD GetRealSize(uint32_t *aRealSize) = 0;

  /* readonly attribute unsigned long CRC32; */
  NS_IMETHOD GetCRC32(uint32_t *aCRC32) = 0;

  /* readonly attribute boolean isDirectory; */
  NS_IMETHOD GetIsDirectory(bool *aIsDirectory) = 0;

  /* readonly attribute PRTime lastModifiedTime; */
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) = 0;

  /* readonly attribute boolean isSynthetic; */
  NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic) = 0;

  /* readonly attribute unsigned long permissions; */
  NS_IMETHOD GetPermissions(uint32_t *aPermissions) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipEntry, NS_IZIPENTRY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPENTRY \
  NS_IMETHOD GetCompression(uint16_t *aCompression); \
  NS_IMETHOD GetSize(uint32_t *aSize); \
  NS_IMETHOD GetRealSize(uint32_t *aRealSize); \
  NS_IMETHOD GetCRC32(uint32_t *aCRC32); \
  NS_IMETHOD GetIsDirectory(bool *aIsDirectory); \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime); \
  NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic); \
  NS_IMETHOD GetPermissions(uint32_t *aPermissions); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPENTRY(_to) \
  NS_IMETHOD GetCompression(uint16_t *aCompression) { return _to GetCompression(aCompression); } \
  NS_IMETHOD GetSize(uint32_t *aSize) { return _to GetSize(aSize); } \
  NS_IMETHOD GetRealSize(uint32_t *aRealSize) { return _to GetRealSize(aRealSize); } \
  NS_IMETHOD GetCRC32(uint32_t *aCRC32) { return _to GetCRC32(aCRC32); } \
  NS_IMETHOD GetIsDirectory(bool *aIsDirectory) { return _to GetIsDirectory(aIsDirectory); } \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) { return _to GetLastModifiedTime(aLastModifiedTime); } \
  NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic) { return _to GetIsSynthetic(aIsSynthetic); } \
  NS_IMETHOD GetPermissions(uint32_t *aPermissions) { return _to GetPermissions(aPermissions); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPENTRY(_to) \
  NS_IMETHOD GetCompression(uint16_t *aCompression) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompression(aCompression); } \
  NS_IMETHOD GetSize(uint32_t *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_IMETHOD GetRealSize(uint32_t *aRealSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealSize(aRealSize); } \
  NS_IMETHOD GetCRC32(uint32_t *aCRC32) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCRC32(aCRC32); } \
  NS_IMETHOD GetIsDirectory(bool *aIsDirectory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDirectory(aIsDirectory); } \
  NS_IMETHOD GetLastModifiedTime(PRTime *aLastModifiedTime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModifiedTime(aLastModifiedTime); } \
  NS_IMETHOD GetIsSynthetic(bool *aIsSynthetic) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSynthetic(aIsSynthetic); } \
  NS_IMETHOD GetPermissions(uint32_t *aPermissions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPermissions(aPermissions); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipEntry : public nsIZipEntry
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPENTRY

  nsZipEntry();

private:
  ~nsZipEntry();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZipEntry, nsIZipEntry)

nsZipEntry::nsZipEntry()
{
  /* member initializers and constructor code */
}

nsZipEntry::~nsZipEntry()
{
  /* destructor code */
}

/* readonly attribute unsigned short compression; */
NS_IMETHODIMP nsZipEntry::GetCompression(uint16_t *aCompression)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long size; */
NS_IMETHODIMP nsZipEntry::GetSize(uint32_t *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long realSize; */
NS_IMETHODIMP nsZipEntry::GetRealSize(uint32_t *aRealSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long CRC32; */
NS_IMETHODIMP nsZipEntry::GetCRC32(uint32_t *aCRC32)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDirectory; */
NS_IMETHODIMP nsZipEntry::GetIsDirectory(bool *aIsDirectory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRTime lastModifiedTime; */
NS_IMETHODIMP nsZipEntry::GetLastModifiedTime(PRTime *aLastModifiedTime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSynthetic; */
NS_IMETHODIMP nsZipEntry::GetIsSynthetic(bool *aIsSynthetic)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long permissions; */
NS_IMETHODIMP nsZipEntry::GetPermissions(uint32_t *aPermissions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIZipReader */
#define NS_IZIPREADER_IID_STR "38d6d07a-8a58-4fe7-be8b-ef6472fa83ff"

#define NS_IZIPREADER_IID \
  {0x38d6d07a, 0x8a58, 0x4fe7, \
    { 0xbe, 0x8b, 0xef, 0x64, 0x72, 0xfa, 0x83, 0xff }}

class NS_NO_VTABLE nsIZipReader : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPREADER_IID)

  /* void open (in nsIFile zipFile); */
  NS_IMETHOD Open(nsIFile *zipFile) = 0;

  /* void openInner (in nsIZipReader zipReader, in AUTF8String zipEntry); */
  NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry) = 0;

  /* readonly attribute nsIFile file; */
  NS_IMETHOD GetFile(nsIFile * *aFile) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void test (in AUTF8String aEntryName); */
  NS_IMETHOD Test(const nsACString & aEntryName) = 0;

  /* void extract (in AUTF8String zipEntry, in nsIFile outFile); */
  NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile) = 0;

  /* nsIZipEntry getEntry (in AUTF8String zipEntry); */
  NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval) = 0;

  /* boolean hasEntry (in AUTF8String zipEntry); */
  NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval) = 0;

  /* nsIUTF8StringEnumerator findEntries (in AUTF8String aPattern); */
  NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval) = 0;

  /* nsIInputStream getInputStream (in AUTF8String zipEntry); */
  NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval) = 0;

  /* nsIInputStream getInputStreamWithSpec (in AUTF8String aJarSpec, in AUTF8String zipEntry); */
  NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval) = 0;

  /* nsICertificatePrincipal getCertificatePrincipal (in AUTF8String aEntryName); */
  NS_IMETHOD GetCertificatePrincipal(const nsACString & aEntryName, nsICertificatePrincipal * *_retval) = 0;

  /* readonly attribute uint32_t manifestEntriesCount; */
  NS_IMETHOD GetManifestEntriesCount(uint32_t *aManifestEntriesCount) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipReader, NS_IZIPREADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPREADER \
  NS_IMETHOD Open(nsIFile *zipFile); \
  NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry); \
  NS_IMETHOD GetFile(nsIFile * *aFile); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD Test(const nsACString & aEntryName); \
  NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile); \
  NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval); \
  NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval); \
  NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval); \
  NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval); \
  NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval); \
  NS_IMETHOD GetCertificatePrincipal(const nsACString & aEntryName, nsICertificatePrincipal * *_retval); \
  NS_IMETHOD GetManifestEntriesCount(uint32_t *aManifestEntriesCount); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPREADER(_to) \
  NS_IMETHOD Open(nsIFile *zipFile) { return _to Open(zipFile); } \
  NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry) { return _to OpenInner(zipReader, zipEntry); } \
  NS_IMETHOD GetFile(nsIFile * *aFile) { return _to GetFile(aFile); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD Test(const nsACString & aEntryName) { return _to Test(aEntryName); } \
  NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile) { return _to Extract(zipEntry, outFile); } \
  NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval) { return _to GetEntry(zipEntry, _retval); } \
  NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval) { return _to HasEntry(zipEntry, _retval); } \
  NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval) { return _to FindEntries(aPattern, _retval); } \
  NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval) { return _to GetInputStream(zipEntry, _retval); } \
  NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval) { return _to GetInputStreamWithSpec(aJarSpec, zipEntry, _retval); } \
  NS_IMETHOD GetCertificatePrincipal(const nsACString & aEntryName, nsICertificatePrincipal * *_retval) { return _to GetCertificatePrincipal(aEntryName, _retval); } \
  NS_IMETHOD GetManifestEntriesCount(uint32_t *aManifestEntriesCount) { return _to GetManifestEntriesCount(aManifestEntriesCount); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPREADER(_to) \
  NS_IMETHOD Open(nsIFile *zipFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(zipFile); } \
  NS_IMETHOD OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenInner(zipReader, zipEntry); } \
  NS_IMETHOD GetFile(nsIFile * *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aFile); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Test(const nsACString & aEntryName) { return !_to ? NS_ERROR_NULL_POINTER : _to->Test(aEntryName); } \
  NS_IMETHOD Extract(const nsACString & zipEntry, nsIFile *outFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->Extract(zipEntry, outFile); } \
  NS_IMETHOD GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntry(zipEntry, _retval); } \
  NS_IMETHOD HasEntry(const nsACString & zipEntry, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasEntry(zipEntry, _retval); } \
  NS_IMETHOD FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->FindEntries(aPattern, _retval); } \
  NS_IMETHOD GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStream(zipEntry, _retval); } \
  NS_IMETHOD GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInputStreamWithSpec(aJarSpec, zipEntry, _retval); } \
  NS_IMETHOD GetCertificatePrincipal(const nsACString & aEntryName, nsICertificatePrincipal * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCertificatePrincipal(aEntryName, _retval); } \
  NS_IMETHOD GetManifestEntriesCount(uint32_t *aManifestEntriesCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetManifestEntriesCount(aManifestEntriesCount); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipReader : public nsIZipReader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPREADER

  nsZipReader();

private:
  ~nsZipReader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZipReader, nsIZipReader)

nsZipReader::nsZipReader()
{
  /* member initializers and constructor code */
}

nsZipReader::~nsZipReader()
{
  /* destructor code */
}

/* void open (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReader::Open(nsIFile *zipFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void openInner (in nsIZipReader zipReader, in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::OpenInner(nsIZipReader *zipReader, const nsACString & zipEntry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile file; */
NS_IMETHODIMP nsZipReader::GetFile(nsIFile * *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsZipReader::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void test (in AUTF8String aEntryName); */
NS_IMETHODIMP nsZipReader::Test(const nsACString & aEntryName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void extract (in AUTF8String zipEntry, in nsIFile outFile); */
NS_IMETHODIMP nsZipReader::Extract(const nsACString & zipEntry, nsIFile *outFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipEntry getEntry (in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::GetEntry(const nsACString & zipEntry, nsIZipEntry * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasEntry (in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::HasEntry(const nsACString & zipEntry, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIUTF8StringEnumerator findEntries (in AUTF8String aPattern); */
NS_IMETHODIMP nsZipReader::FindEntries(const nsACString & aPattern, nsIUTF8StringEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream getInputStream (in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::GetInputStream(const nsACString & zipEntry, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIInputStream getInputStreamWithSpec (in AUTF8String aJarSpec, in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReader::GetInputStreamWithSpec(const nsACString & aJarSpec, const nsACString & zipEntry, nsIInputStream * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsICertificatePrincipal getCertificatePrincipal (in AUTF8String aEntryName); */
NS_IMETHODIMP nsZipReader::GetCertificatePrincipal(const nsACString & aEntryName, nsICertificatePrincipal * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint32_t manifestEntriesCount; */
NS_IMETHODIMP nsZipReader::GetManifestEntriesCount(uint32_t *aManifestEntriesCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIZipReaderCache */
#define NS_IZIPREADERCACHE_IID_STR "748050ac-3ab6-4472-bc2a-cb1564ac6a81"

#define NS_IZIPREADERCACHE_IID \
  {0x748050ac, 0x3ab6, 0x4472, \
    { 0xbc, 0x2a, 0xcb, 0x15, 0x64, 0xac, 0x6a, 0x81 }}

class NS_NO_VTABLE nsIZipReaderCache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPREADERCACHE_IID)

  /* void init (in unsigned long cacheSize); */
  NS_IMETHOD Init(uint32_t cacheSize) = 0;

  /* nsIZipReader getZip (in nsIFile zipFile); */
  NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval) = 0;

  /* bool isCached (in nsIFile zipFile); */
  NS_IMETHOD IsCached(nsIFile *zipFile, bool *_retval) = 0;

  /* nsIZipReader getInnerZip (in nsIFile zipFile, in AUTF8String zipEntry); */
  NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipReaderCache, NS_IZIPREADERCACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPREADERCACHE \
  NS_IMETHOD Init(uint32_t cacheSize); \
  NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval); \
  NS_IMETHOD IsCached(nsIFile *zipFile, bool *_retval); \
  NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPREADERCACHE(_to) \
  NS_IMETHOD Init(uint32_t cacheSize) { return _to Init(cacheSize); } \
  NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval) { return _to GetZip(zipFile, _retval); } \
  NS_IMETHOD IsCached(nsIFile *zipFile, bool *_retval) { return _to IsCached(zipFile, _retval); } \
  NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval) { return _to GetInnerZip(zipFile, zipEntry, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPREADERCACHE(_to) \
  NS_IMETHOD Init(uint32_t cacheSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(cacheSize); } \
  NS_IMETHOD GetZip(nsIFile *zipFile, nsIZipReader * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetZip(zipFile, _retval); } \
  NS_IMETHOD IsCached(nsIFile *zipFile, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsCached(zipFile, _retval); } \
  NS_IMETHOD GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerZip(zipFile, zipEntry, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipReaderCache : public nsIZipReaderCache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPREADERCACHE

  nsZipReaderCache();

private:
  ~nsZipReaderCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZipReaderCache, nsIZipReaderCache)

nsZipReaderCache::nsZipReaderCache()
{
  /* member initializers and constructor code */
}

nsZipReaderCache::~nsZipReaderCache()
{
  /* destructor code */
}

/* void init (in unsigned long cacheSize); */
NS_IMETHODIMP nsZipReaderCache::Init(uint32_t cacheSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipReader getZip (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReaderCache::GetZip(nsIFile *zipFile, nsIZipReader * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* bool isCached (in nsIFile zipFile); */
NS_IMETHODIMP nsZipReaderCache::IsCached(nsIFile *zipFile, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipReader getInnerZip (in nsIFile zipFile, in AUTF8String zipEntry); */
NS_IMETHODIMP nsZipReaderCache::GetInnerZip(nsIFile *zipFile, const nsACString & zipEntry, nsIZipReader * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#define NS_ZIPREADER_CID                             \
{ /* 88e2fd0b-f7f4-480c-9483-7846b00e8dad */         \
   0x88e2fd0b, 0xf7f4, 0x480c,                       \
  { 0x94, 0x83, 0x78, 0x46, 0xb0, 0x0e, 0x8d, 0xad } \
}
#define NS_ZIPREADERCACHE_CID                        \
{ /* 608b7f6f-4b60-40d6-87ed-d933bf53d8c1 */         \
   0x608b7f6f, 0x4b60, 0x40d6,                       \
  { 0x87, 0xed, 0xd9, 0x33, 0xbf, 0x53, 0xd8, 0xc1 } \
}

#endif /* __gen_nsIZipReader_h__ */
