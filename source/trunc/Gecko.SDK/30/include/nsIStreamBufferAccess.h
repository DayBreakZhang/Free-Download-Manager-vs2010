/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIStreamBufferAccess.idl
 */

#ifndef __gen_nsIStreamBufferAccess_h__
#define __gen_nsIStreamBufferAccess_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStreamBufferAccess */
#define NS_ISTREAMBUFFERACCESS_IID_STR "ac923b72-ac87-4892-ac7a-ca385d429435"

#define NS_ISTREAMBUFFERACCESS_IID \
  {0xac923b72, 0xac87, 0x4892, \
    { 0xac, 0x7a, 0xca, 0x38, 0x5d, 0x42, 0x94, 0x35 }}

class NS_NO_VTABLE nsIStreamBufferAccess : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTREAMBUFFERACCESS_IID)

  /* [noscript,notxpcom] charPtr getBuffer (in uint32_t aLength, in uint32_t aAlignMask); */
  NS_IMETHOD_(char *) GetBuffer(uint32_t aLength, uint32_t aAlignMask) = 0;

  /* [noscript,notxpcom] void putBuffer (in charPtr aBuffer, in uint32_t aLength); */
  NS_IMETHOD_(void) PutBuffer(char *aBuffer, uint32_t aLength) = 0;

  /* void disableBuffering (); */
  NS_IMETHOD DisableBuffering(void) = 0;

  /* void enableBuffering (); */
  NS_IMETHOD EnableBuffering(void) = 0;

  /* readonly attribute nsISupports unbufferedStream; */
  NS_IMETHOD GetUnbufferedStream(nsISupports * *aUnbufferedStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStreamBufferAccess, NS_ISTREAMBUFFERACCESS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTREAMBUFFERACCESS \
  NS_IMETHOD_(char *) GetBuffer(uint32_t aLength, uint32_t aAlignMask); \
  NS_IMETHOD_(void) PutBuffer(char *aBuffer, uint32_t aLength); \
  NS_IMETHOD DisableBuffering(void); \
  NS_IMETHOD EnableBuffering(void); \
  NS_IMETHOD GetUnbufferedStream(nsISupports * *aUnbufferedStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTREAMBUFFERACCESS(_to) \
  NS_IMETHOD_(char *) GetBuffer(uint32_t aLength, uint32_t aAlignMask) { return _to GetBuffer(aLength, aAlignMask); } \
  NS_IMETHOD_(void) PutBuffer(char *aBuffer, uint32_t aLength) { return _to PutBuffer(aBuffer, aLength); } \
  NS_IMETHOD DisableBuffering(void) { return _to DisableBuffering(); } \
  NS_IMETHOD EnableBuffering(void) { return _to EnableBuffering(); } \
  NS_IMETHOD GetUnbufferedStream(nsISupports * *aUnbufferedStream) { return _to GetUnbufferedStream(aUnbufferedStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTREAMBUFFERACCESS(_to) \
  NS_IMETHOD_(char *) GetBuffer(uint32_t aLength, uint32_t aAlignMask); \
  NS_IMETHOD_(void) PutBuffer(char *aBuffer, uint32_t aLength); \
  NS_IMETHOD DisableBuffering(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DisableBuffering(); } \
  NS_IMETHOD EnableBuffering(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableBuffering(); } \
  NS_IMETHOD GetUnbufferedStream(nsISupports * *aUnbufferedStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnbufferedStream(aUnbufferedStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStreamBufferAccess : public nsIStreamBufferAccess
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTREAMBUFFERACCESS

  nsStreamBufferAccess();

private:
  ~nsStreamBufferAccess();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStreamBufferAccess, nsIStreamBufferAccess)

nsStreamBufferAccess::nsStreamBufferAccess()
{
  /* member initializers and constructor code */
}

nsStreamBufferAccess::~nsStreamBufferAccess()
{
  /* destructor code */
}

/* [noscript,notxpcom] charPtr getBuffer (in uint32_t aLength, in uint32_t aAlignMask); */
NS_IMETHODIMP_(char *) nsStreamBufferAccess::GetBuffer(uint32_t aLength, uint32_t aAlignMask)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void putBuffer (in charPtr aBuffer, in uint32_t aLength); */
NS_IMETHODIMP_(void) nsStreamBufferAccess::PutBuffer(char *aBuffer, uint32_t aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disableBuffering (); */
NS_IMETHODIMP nsStreamBufferAccess::DisableBuffering()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableBuffering (); */
NS_IMETHODIMP nsStreamBufferAccess::EnableBuffering()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports unbufferedStream; */
NS_IMETHODIMP nsStreamBufferAccess::GetUnbufferedStream(nsISupports * *aUnbufferedStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/**
 * These macros get and put a buffer given either an sba parameter that may
 * point to an object implementing nsIStreamBufferAccess, nsIObjectInputStream,
 * or nsIObjectOutputStream.
 */
#define NS_GET_BUFFER(sba,n,a)  ((sba)->GetBuffer(n, a))
#define NS_PUT_BUFFER(sba,p,n)  ((sba)->PutBuffer(p, n))

#endif /* __gen_nsIStreamBufferAccess_h__ */
