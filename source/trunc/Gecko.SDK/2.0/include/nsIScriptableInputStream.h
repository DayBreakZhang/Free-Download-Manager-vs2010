/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/xpcom/io/nsIScriptableInputStream.idl
 */

#ifndef __gen_nsIScriptableInputStream_h__
#define __gen_nsIScriptableInputStream_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIInputStream; /* forward declaration */


/* starting interface:    nsIScriptableInputStream */
#define NS_ISCRIPTABLEINPUTSTREAM_IID_STR "e546afd6-1248-4deb-8940-4b000b618a58"

#define NS_ISCRIPTABLEINPUTSTREAM_IID \
  {0xe546afd6, 0x1248, 0x4deb, \
    { 0x89, 0x40, 0x4b, 0x00, 0x0b, 0x61, 0x8a, 0x58 }}

/**
 * nsIScriptableInputStream provides scriptable access to an nsIInputStream
 * instance.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIScriptableInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEINPUTSTREAM_IID)

  /** 
     * Closes the stream. 
     */
  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /**
     * Wrap the given nsIInputStream with this nsIScriptableInputStream. 
     *
     * @param aInputStream parameter providing the stream to wrap 
     */
  /* void init (in nsIInputStream aInputStream); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aInputStream) = 0;

  /**
     * Return the number of bytes currently available in the stream 
     *
     * @return the number of bytes 
     *
     * @throws NS_BASE_STREAM_CLOSED if called after the stream has been closed
     */
  /* unsigned long available (); */
  NS_SCRIPTABLE NS_IMETHOD Available(PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
     * Read data from the stream.
     *
     * WARNING: If the data contains a null byte, then this method will return
     * a truncated string.
     *
     * @param aCount the maximum number of bytes to read 
     *
     * @return the data, which will be an empty string if the stream is at EOF.
     *
     * @throws NS_BASE_STREAM_CLOSED if called after the stream has been closed
     * @throws NS_ERROR_NOT_INITIALIZED if init was not called
     */
  /* string read (in unsigned long aCount); */
  NS_SCRIPTABLE NS_IMETHOD Read(PRUint32 aCount, char **_retval NS_OUTPARAM) = 0;

  /**
     * Read data from the stream, including NULL bytes.
     *
     * @param aCount the maximum number of bytes to read.
     *
     * @return the data from the stream, which will be an empty string if EOF
     *         has been reached.
     *
     * @throws NS_BASE_STREAM_WOULD_BLOCK if reading from the input stream
     *         would block the calling thread (non-blocking mode only).
     * @throws NS_ERROR_FAILURE if there are not enough bytes available to read
     *         aCount amount of data.
     */
  /* ACString readBytes (in unsigned long aCount); */
  NS_SCRIPTABLE NS_IMETHOD ReadBytes(PRUint32 aCount, nsACString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableInputStream, NS_ISCRIPTABLEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEINPUTSTREAM \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aInputStream); \
  NS_SCRIPTABLE NS_IMETHOD Available(PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Read(PRUint32 aCount, char **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ReadBytes(PRUint32 aCount, nsACString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aInputStream) { return _to Init(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD Available(PRUint32 *_retval NS_OUTPARAM) { return _to Available(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Read(PRUint32 aCount, char **_retval NS_OUTPARAM) { return _to Read(aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadBytes(PRUint32 aCount, nsACString & _retval NS_OUTPARAM) { return _to ReadBytes(aCount, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEINPUTSTREAM(_to) \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIInputStream *aInputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aInputStream); } \
  NS_SCRIPTABLE NS_IMETHOD Available(PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Available(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD Read(PRUint32 aCount, char **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Read(aCount, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReadBytes(PRUint32 aCount, nsACString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadBytes(aCount, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsScriptableInputStream : public nsIScriptableInputStream
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISCRIPTABLEINPUTSTREAM

  nsScriptableInputStream();

private:
  ~nsScriptableInputStream();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsScriptableInputStream, nsIScriptableInputStream)

nsScriptableInputStream::nsScriptableInputStream()
{
  /* member initializers and constructor code */
}

nsScriptableInputStream::~nsScriptableInputStream()
{
  /* destructor code */
}

/* void close (); */
NS_IMETHODIMP nsScriptableInputStream::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void init (in nsIInputStream aInputStream); */
NS_IMETHODIMP nsScriptableInputStream::Init(nsIInputStream *aInputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long available (); */
NS_IMETHODIMP nsScriptableInputStream::Available(PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string read (in unsigned long aCount); */
NS_IMETHODIMP nsScriptableInputStream::Read(PRUint32 aCount, char **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString readBytes (in unsigned long aCount); */
NS_IMETHODIMP nsScriptableInputStream::ReadBytes(PRUint32 aCount, nsACString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptableInputStream_h__ */
