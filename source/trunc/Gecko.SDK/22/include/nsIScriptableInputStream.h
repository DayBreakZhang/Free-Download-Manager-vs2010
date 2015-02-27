/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsIScriptableInputStream.idl
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
#define NS_ISCRIPTABLEINPUTSTREAM_IID_STR "3fce9015-472a-4080-ac3e-cd875dbe361e"

#define NS_ISCRIPTABLEINPUTSTREAM_IID \
  {0x3fce9015, 0x472a, 0x4080, \
    { 0xac, 0x3e, 0xcd, 0x87, 0x5d, 0xbe, 0x36, 0x1e }}

class NS_NO_VTABLE nsIScriptableInputStream : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISCRIPTABLEINPUTSTREAM_IID)

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void init (in nsIInputStream aInputStream); */
  NS_IMETHOD Init(nsIInputStream *aInputStream) = 0;

  /* unsigned long long available (); */
  NS_IMETHOD Available(uint64_t *_retval) = 0;

  /* string read (in unsigned long aCount); */
  NS_IMETHOD Read(uint32_t aCount, char * *_retval) = 0;

  /* ACString readBytes (in unsigned long aCount); */
  NS_IMETHOD ReadBytes(uint32_t aCount, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIScriptableInputStream, NS_ISCRIPTABLEINPUTSTREAM_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISCRIPTABLEINPUTSTREAM \
  NS_IMETHOD Close(void); \
  NS_IMETHOD Init(nsIInputStream *aInputStream); \
  NS_IMETHOD Available(uint64_t *_retval); \
  NS_IMETHOD Read(uint32_t aCount, char * *_retval); \
  NS_IMETHOD ReadBytes(uint32_t aCount, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISCRIPTABLEINPUTSTREAM(_to) \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD Init(nsIInputStream *aInputStream) { return _to Init(aInputStream); } \
  NS_IMETHOD Available(uint64_t *_retval) { return _to Available(_retval); } \
  NS_IMETHOD Read(uint32_t aCount, char * *_retval) { return _to Read(aCount, _retval); } \
  NS_IMETHOD ReadBytes(uint32_t aCount, nsACString & _retval) { return _to ReadBytes(aCount, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISCRIPTABLEINPUTSTREAM(_to) \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD Init(nsIInputStream *aInputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aInputStream); } \
  NS_IMETHOD Available(uint64_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Available(_retval); } \
  NS_IMETHOD Read(uint32_t aCount, char * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Read(aCount, _retval); } \
  NS_IMETHOD ReadBytes(uint32_t aCount, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadBytes(aCount, _retval); } 

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

/* unsigned long long available (); */
NS_IMETHODIMP nsScriptableInputStream::Available(uint64_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* string read (in unsigned long aCount); */
NS_IMETHODIMP nsScriptableInputStream::Read(uint32_t aCount, char * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString readBytes (in unsigned long aCount); */
NS_IMETHODIMP nsScriptableInputStream::ReadBytes(uint32_t aCount, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIScriptableInputStream_h__ */
