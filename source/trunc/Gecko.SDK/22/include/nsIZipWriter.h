/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/modules/libjar/zipwriter/public/nsIZipWriter.idl
 */

#ifndef __gen_nsIZipWriter_h__
#define __gen_nsIZipWriter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIInputStream; /* forward declaration */

class nsIRequestObserver; /* forward declaration */

class nsIFile; /* forward declaration */

class nsIZipEntry; /* forward declaration */


/* starting interface:    nsIZipWriter */
#define NS_IZIPWRITER_IID_STR "6d4ef074-206c-4649-9884-57bc355864d6"

#define NS_IZIPWRITER_IID \
  {0x6d4ef074, 0x206c, 0x4649, \
    { 0x98, 0x84, 0x57, 0xbc, 0x35, 0x58, 0x64, 0xd6 }}

class NS_NO_VTABLE nsIZipWriter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IZIPWRITER_IID)

  enum {
    COMPRESSION_NONE = 0U,
    COMPRESSION_FASTEST = 1U,
    COMPRESSION_DEFAULT = 6U,
    COMPRESSION_BEST = 9U
  };

  /* attribute ACString comment; */
  NS_IMETHOD GetComment(nsACString & aComment) = 0;
  NS_IMETHOD SetComment(const nsACString & aComment) = 0;

  /* readonly attribute boolean inQueue; */
  NS_IMETHOD GetInQueue(bool *aInQueue) = 0;

  /* readonly attribute nsIFile file; */
  NS_IMETHOD GetFile(nsIFile * *aFile) = 0;

  /* void open (in nsIFile aFile, in int32_t aIoFlags); */
  NS_IMETHOD Open(nsIFile *aFile, int32_t aIoFlags) = 0;

  /* nsIZipEntry getEntry (in AUTF8String aZipEntry); */
  NS_IMETHOD GetEntry(const nsACString & aZipEntry, nsIZipEntry * *_retval) = 0;

  /* boolean hasEntry (in AUTF8String aZipEntry); */
  NS_IMETHOD HasEntry(const nsACString & aZipEntry, bool *_retval) = 0;

  /* void addEntryDirectory (in AUTF8String aZipEntry, in PRTime aModTime, in boolean aQueue); */
  NS_IMETHOD AddEntryDirectory(const nsACString & aZipEntry, PRTime aModTime, bool aQueue) = 0;

  /* void addEntryFile (in AUTF8String aZipEntry, in int32_t aCompression, in nsIFile aFile, in boolean aQueue); */
  NS_IMETHOD AddEntryFile(const nsACString & aZipEntry, int32_t aCompression, nsIFile *aFile, bool aQueue) = 0;

  /* void addEntryChannel (in AUTF8String aZipEntry, in PRTime aModTime, in int32_t aCompression, in nsIChannel aChannel, in boolean aQueue); */
  NS_IMETHOD AddEntryChannel(const nsACString & aZipEntry, PRTime aModTime, int32_t aCompression, nsIChannel *aChannel, bool aQueue) = 0;

  /* void addEntryStream (in AUTF8String aZipEntry, in PRTime aModTime, in int32_t aCompression, in nsIInputStream aStream, in boolean aQueue); */
  NS_IMETHOD AddEntryStream(const nsACString & aZipEntry, PRTime aModTime, int32_t aCompression, nsIInputStream *aStream, bool aQueue) = 0;

  /* void removeEntry (in AUTF8String aZipEntry, in boolean aQueue); */
  NS_IMETHOD RemoveEntry(const nsACString & aZipEntry, bool aQueue) = 0;

  /* void processQueue (in nsIRequestObserver aObserver, in nsISupports aContext); */
  NS_IMETHOD ProcessQueue(nsIRequestObserver *aObserver, nsISupports *aContext) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIZipWriter, NS_IZIPWRITER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIZIPWRITER \
  NS_IMETHOD GetComment(nsACString & aComment); \
  NS_IMETHOD SetComment(const nsACString & aComment); \
  NS_IMETHOD GetInQueue(bool *aInQueue); \
  NS_IMETHOD GetFile(nsIFile * *aFile); \
  NS_IMETHOD Open(nsIFile *aFile, int32_t aIoFlags); \
  NS_IMETHOD GetEntry(const nsACString & aZipEntry, nsIZipEntry * *_retval); \
  NS_IMETHOD HasEntry(const nsACString & aZipEntry, bool *_retval); \
  NS_IMETHOD AddEntryDirectory(const nsACString & aZipEntry, PRTime aModTime, bool aQueue); \
  NS_IMETHOD AddEntryFile(const nsACString & aZipEntry, int32_t aCompression, nsIFile *aFile, bool aQueue); \
  NS_IMETHOD AddEntryChannel(const nsACString & aZipEntry, PRTime aModTime, int32_t aCompression, nsIChannel *aChannel, bool aQueue); \
  NS_IMETHOD AddEntryStream(const nsACString & aZipEntry, PRTime aModTime, int32_t aCompression, nsIInputStream *aStream, bool aQueue); \
  NS_IMETHOD RemoveEntry(const nsACString & aZipEntry, bool aQueue); \
  NS_IMETHOD ProcessQueue(nsIRequestObserver *aObserver, nsISupports *aContext); \
  NS_IMETHOD Close(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIZIPWRITER(_to) \
  NS_IMETHOD GetComment(nsACString & aComment) { return _to GetComment(aComment); } \
  NS_IMETHOD SetComment(const nsACString & aComment) { return _to SetComment(aComment); } \
  NS_IMETHOD GetInQueue(bool *aInQueue) { return _to GetInQueue(aInQueue); } \
  NS_IMETHOD GetFile(nsIFile * *aFile) { return _to GetFile(aFile); } \
  NS_IMETHOD Open(nsIFile *aFile, int32_t aIoFlags) { return _to Open(aFile, aIoFlags); } \
  NS_IMETHOD GetEntry(const nsACString & aZipEntry, nsIZipEntry * *_retval) { return _to GetEntry(aZipEntry, _retval); } \
  NS_IMETHOD HasEntry(const nsACString & aZipEntry, bool *_retval) { return _to HasEntry(aZipEntry, _retval); } \
  NS_IMETHOD AddEntryDirectory(const nsACString & aZipEntry, PRTime aModTime, bool aQueue) { return _to AddEntryDirectory(aZipEntry, aModTime, aQueue); } \
  NS_IMETHOD AddEntryFile(const nsACString & aZipEntry, int32_t aCompression, nsIFile *aFile, bool aQueue) { return _to AddEntryFile(aZipEntry, aCompression, aFile, aQueue); } \
  NS_IMETHOD AddEntryChannel(const nsACString & aZipEntry, PRTime aModTime, int32_t aCompression, nsIChannel *aChannel, bool aQueue) { return _to AddEntryChannel(aZipEntry, aModTime, aCompression, aChannel, aQueue); } \
  NS_IMETHOD AddEntryStream(const nsACString & aZipEntry, PRTime aModTime, int32_t aCompression, nsIInputStream *aStream, bool aQueue) { return _to AddEntryStream(aZipEntry, aModTime, aCompression, aStream, aQueue); } \
  NS_IMETHOD RemoveEntry(const nsACString & aZipEntry, bool aQueue) { return _to RemoveEntry(aZipEntry, aQueue); } \
  NS_IMETHOD ProcessQueue(nsIRequestObserver *aObserver, nsISupports *aContext) { return _to ProcessQueue(aObserver, aContext); } \
  NS_IMETHOD Close(void) { return _to Close(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIZIPWRITER(_to) \
  NS_IMETHOD GetComment(nsACString & aComment) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetComment(aComment); } \
  NS_IMETHOD SetComment(const nsACString & aComment) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetComment(aComment); } \
  NS_IMETHOD GetInQueue(bool *aInQueue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInQueue(aInQueue); } \
  NS_IMETHOD GetFile(nsIFile * *aFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFile(aFile); } \
  NS_IMETHOD Open(nsIFile *aFile, int32_t aIoFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(aFile, aIoFlags); } \
  NS_IMETHOD GetEntry(const nsACString & aZipEntry, nsIZipEntry * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEntry(aZipEntry, _retval); } \
  NS_IMETHOD HasEntry(const nsACString & aZipEntry, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasEntry(aZipEntry, _retval); } \
  NS_IMETHOD AddEntryDirectory(const nsACString & aZipEntry, PRTime aModTime, bool aQueue) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEntryDirectory(aZipEntry, aModTime, aQueue); } \
  NS_IMETHOD AddEntryFile(const nsACString & aZipEntry, int32_t aCompression, nsIFile *aFile, bool aQueue) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEntryFile(aZipEntry, aCompression, aFile, aQueue); } \
  NS_IMETHOD AddEntryChannel(const nsACString & aZipEntry, PRTime aModTime, int32_t aCompression, nsIChannel *aChannel, bool aQueue) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEntryChannel(aZipEntry, aModTime, aCompression, aChannel, aQueue); } \
  NS_IMETHOD AddEntryStream(const nsACString & aZipEntry, PRTime aModTime, int32_t aCompression, nsIInputStream *aStream, bool aQueue) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddEntryStream(aZipEntry, aModTime, aCompression, aStream, aQueue); } \
  NS_IMETHOD RemoveEntry(const nsACString & aZipEntry, bool aQueue) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveEntry(aZipEntry, aQueue); } \
  NS_IMETHOD ProcessQueue(nsIRequestObserver *aObserver, nsISupports *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessQueue(aObserver, aContext); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsZipWriter : public nsIZipWriter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIZIPWRITER

  nsZipWriter();

private:
  ~nsZipWriter();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsZipWriter, nsIZipWriter)

nsZipWriter::nsZipWriter()
{
  /* member initializers and constructor code */
}

nsZipWriter::~nsZipWriter()
{
  /* destructor code */
}

/* attribute ACString comment; */
NS_IMETHODIMP nsZipWriter::GetComment(nsACString & aComment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsZipWriter::SetComment(const nsACString & aComment)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean inQueue; */
NS_IMETHODIMP nsZipWriter::GetInQueue(bool *aInQueue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIFile file; */
NS_IMETHODIMP nsZipWriter::GetFile(nsIFile * *aFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void open (in nsIFile aFile, in int32_t aIoFlags); */
NS_IMETHODIMP nsZipWriter::Open(nsIFile *aFile, int32_t aIoFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIZipEntry getEntry (in AUTF8String aZipEntry); */
NS_IMETHODIMP nsZipWriter::GetEntry(const nsACString & aZipEntry, nsIZipEntry * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean hasEntry (in AUTF8String aZipEntry); */
NS_IMETHODIMP nsZipWriter::HasEntry(const nsACString & aZipEntry, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEntryDirectory (in AUTF8String aZipEntry, in PRTime aModTime, in boolean aQueue); */
NS_IMETHODIMP nsZipWriter::AddEntryDirectory(const nsACString & aZipEntry, PRTime aModTime, bool aQueue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEntryFile (in AUTF8String aZipEntry, in int32_t aCompression, in nsIFile aFile, in boolean aQueue); */
NS_IMETHODIMP nsZipWriter::AddEntryFile(const nsACString & aZipEntry, int32_t aCompression, nsIFile *aFile, bool aQueue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEntryChannel (in AUTF8String aZipEntry, in PRTime aModTime, in int32_t aCompression, in nsIChannel aChannel, in boolean aQueue); */
NS_IMETHODIMP nsZipWriter::AddEntryChannel(const nsACString & aZipEntry, PRTime aModTime, int32_t aCompression, nsIChannel *aChannel, bool aQueue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addEntryStream (in AUTF8String aZipEntry, in PRTime aModTime, in int32_t aCompression, in nsIInputStream aStream, in boolean aQueue); */
NS_IMETHODIMP nsZipWriter::AddEntryStream(const nsACString & aZipEntry, PRTime aModTime, int32_t aCompression, nsIInputStream *aStream, bool aQueue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeEntry (in AUTF8String aZipEntry, in boolean aQueue); */
NS_IMETHODIMP nsZipWriter::RemoveEntry(const nsACString & aZipEntry, bool aQueue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void processQueue (in nsIRequestObserver aObserver, in nsISupports aContext); */
NS_IMETHODIMP nsZipWriter::ProcessQueue(nsIRequestObserver *aObserver, nsISupports *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsZipWriter::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIZipWriter_h__ */
