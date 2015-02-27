/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIFileStreams.idl
 */

#ifndef __gen_nsIFileStreams_h__
#define __gen_nsIFileStreams_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

#ifndef __gen_nsIOutputStream_h__
#include "nsIOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFile; /* forward declaration */


/* starting interface:    nsIFileInputStream */
#define NS_IFILEINPUTSTREAM_IID_STR "e3d56a20-c7ec-11d3-8cda-0060b0fc14a3"

#define NS_IFILEINPUTSTREAM_IID \
  {0xe3d56a20, 0xc7ec, 0x11d3, \
    { 0x8c, 0xda, 0x00, 0x60, 0xb0, 0xfc, 0x14, 0xa3 }}

class NS_NO_VTABLE nsIFileInputStream : public nsIInputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILEINPUTSTREAM_IID)

  /* void init (in nsIFile file, in long ioFlags, in long perm, in long behaviorFlags); */
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) = 0;

  enum {
    DELETE_ON_CLOSE = 2,
    CLOSE_ON_EOF = 4,
    REOPEN_ON_REWIND = 8,
    DEFER_OPEN = 16
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFileInputStream, NS_IFILEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILEINPUTSTREAM \
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILEINPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) { return _to Init(file, ioFlags, perm, behaviorFlags); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILEINPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(file, ioFlags, perm, behaviorFlags); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFileInputStream : public nsIFileInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILEINPUTSTREAM

  nsFileInputStream();

private:
  ~nsFileInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFileInputStream, nsIFileInputStream)

nsFileInputStream::nsFileInputStream()
{
  /* member initializers and constructor code */
}

nsFileInputStream::~nsFileInputStream()
{
  /* destructor code */
}

/* void init (in nsIFile file, in long ioFlags, in long perm, in long behaviorFlags); */
NS_IMETHODIMP nsFileInputStream::Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFileOutputStream */
#define NS_IFILEOUTPUTSTREAM_IID_STR "e6f68040-c7ec-11d3-8cda-0060b0fc14a3"

#define NS_IFILEOUTPUTSTREAM_IID \
  {0xe6f68040, 0xc7ec, 0x11d3, \
    { 0x8c, 0xda, 0x00, 0x60, 0xb0, 0xfc, 0x14, 0xa3 }}

class NS_NO_VTABLE nsIFileOutputStream : public nsIOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILEOUTPUTSTREAM_IID)

  /* void init (in nsIFile file, in long ioFlags, in long perm, in long behaviorFlags); */
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) = 0;

  enum {
    DEFER_OPEN = 1
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFileOutputStream, NS_IFILEOUTPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILEOUTPUTSTREAM \
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILEOUTPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) { return _to Init(file, ioFlags, perm, behaviorFlags); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILEOUTPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(file, ioFlags, perm, behaviorFlags); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFileOutputStream : public nsIFileOutputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILEOUTPUTSTREAM

  nsFileOutputStream();

private:
  ~nsFileOutputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFileOutputStream, nsIFileOutputStream)

nsFileOutputStream::nsFileOutputStream()
{
  /* member initializers and constructor code */
}

nsFileOutputStream::~nsFileOutputStream()
{
  /* destructor code */
}

/* void init (in nsIFile file, in long ioFlags, in long perm, in long behaviorFlags); */
NS_IMETHODIMP nsFileOutputStream::Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIPartialFileInputStream */
#define NS_IPARTIALFILEINPUTSTREAM_IID_STR "3ce03a2f-97f7-4375-b6bb-1788a60cad3b"

#define NS_IPARTIALFILEINPUTSTREAM_IID \
  {0x3ce03a2f, 0x97f7, 0x4375, \
    { 0xb6, 0xbb, 0x17, 0x88, 0xa6, 0x0c, 0xad, 0x3b }}

class NS_NO_VTABLE nsIPartialFileInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPARTIALFILEINPUTSTREAM_IID)

  /* void init (in nsIFile file, in unsigned long long start, in unsigned long long length, in long ioFlags, in long perm, in long behaviorFlags); */
  NS_IMETHOD Init(nsIFile *file, uint64_t start, uint64_t length, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPartialFileInputStream, NS_IPARTIALFILEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPARTIALFILEINPUTSTREAM \
  NS_IMETHOD Init(nsIFile *file, uint64_t start, uint64_t length, int32_t ioFlags, int32_t perm, int32_t behaviorFlags); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPARTIALFILEINPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIFile *file, uint64_t start, uint64_t length, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) { return _to Init(file, start, length, ioFlags, perm, behaviorFlags); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPARTIALFILEINPUTSTREAM(_to) \
  NS_IMETHOD Init(nsIFile *file, uint64_t start, uint64_t length, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(file, start, length, ioFlags, perm, behaviorFlags); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPartialFileInputStream : public nsIPartialFileInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPARTIALFILEINPUTSTREAM

  nsPartialFileInputStream();

private:
  ~nsPartialFileInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPartialFileInputStream, nsIPartialFileInputStream)

nsPartialFileInputStream::nsPartialFileInputStream()
{
  /* member initializers and constructor code */
}

nsPartialFileInputStream::~nsPartialFileInputStream()
{
  /* destructor code */
}

/* void init (in nsIFile file, in unsigned long long start, in unsigned long long length, in long ioFlags, in long perm, in long behaviorFlags); */
NS_IMETHODIMP nsPartialFileInputStream::Init(nsIFile *file, uint64_t start, uint64_t length, int32_t ioFlags, int32_t perm, int32_t behaviorFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFileStream */
#define NS_IFILESTREAM_IID_STR "82cf605a-8393-4550-83ab-43cd5578e006"

#define NS_IFILESTREAM_IID \
  {0x82cf605a, 0x8393, 0x4550, \
    { 0x83, 0xab, 0x43, 0xcd, 0x55, 0x78, 0xe0, 0x06 }}

class NS_NO_VTABLE nsIFileStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILESTREAM_IID)

  /* void init (in nsIFile file, in long ioFlags, in long perm, in long behaviorFlags); */
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) = 0;

  enum {
    DEFER_OPEN = 1
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFileStream, NS_IFILESTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILESTREAM \
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILESTREAM(_to) \
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) { return _to Init(file, ioFlags, perm, behaviorFlags); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILESTREAM(_to) \
  NS_IMETHOD Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(file, ioFlags, perm, behaviorFlags); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFileStream : public nsIFileStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILESTREAM

  nsFileStream();

private:
  ~nsFileStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFileStream, nsIFileStream)

nsFileStream::nsFileStream()
{
  /* member initializers and constructor code */
}

nsFileStream::~nsFileStream()
{
  /* destructor code */
}

/* void init (in nsIFile file, in long ioFlags, in long perm, in long behaviorFlags); */
NS_IMETHODIMP nsFileStream::Init(nsIFile *file, int32_t ioFlags, int32_t perm, int32_t behaviorFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIFileMetadata */
#define NS_IFILEMETADATA_IID_STR "07f679e4-9601-4bd1-b510-cd3852edb881"

#define NS_IFILEMETADATA_IID \
  {0x07f679e4, 0x9601, 0x4bd1, \
    { 0xb5, 0x10, 0xcd, 0x38, 0x52, 0xed, 0xb8, 0x81 }}

class NS_NO_VTABLE nsIFileMetadata : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFILEMETADATA_IID)

  /* readonly attribute long long size; */
  NS_IMETHOD GetSize(int64_t *aSize) = 0;

  /* readonly attribute long long lastModified; */
  NS_IMETHOD GetLastModified(int64_t *aLastModified) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFileMetadata, NS_IFILEMETADATA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFILEMETADATA \
  NS_IMETHOD GetSize(int64_t *aSize); \
  NS_IMETHOD GetLastModified(int64_t *aLastModified); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFILEMETADATA(_to) \
  NS_IMETHOD GetSize(int64_t *aSize) { return _to GetSize(aSize); } \
  NS_IMETHOD GetLastModified(int64_t *aLastModified) { return _to GetLastModified(aLastModified); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFILEMETADATA(_to) \
  NS_IMETHOD GetSize(int64_t *aSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSize(aSize); } \
  NS_IMETHOD GetLastModified(int64_t *aLastModified) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastModified(aLastModified); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFileMetadata : public nsIFileMetadata
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILEMETADATA

  nsFileMetadata();

private:
  ~nsFileMetadata();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFileMetadata, nsIFileMetadata)

nsFileMetadata::nsFileMetadata()
{
  /* member initializers and constructor code */
}

nsFileMetadata::~nsFileMetadata()
{
  /* destructor code */
}

/* readonly attribute long long size; */
NS_IMETHODIMP nsFileMetadata::GetSize(int64_t *aSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long lastModified; */
NS_IMETHODIMP nsFileMetadata::GetLastModified(int64_t *aLastModified)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFileStreams_h__ */
