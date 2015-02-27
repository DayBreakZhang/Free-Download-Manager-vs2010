/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/xpcom/io/nsIStreamBufferAccess.idl
 */

#ifndef __gen_nsIStreamBufferAccess_h__
#define __gen_nsIStreamBufferAccess_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsrootidl_h__
#include "nsrootidl.h"
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


// Swap macros, used to convert to/from canonical (big-endian) format
#if defined IS_LITTLE_ENDIAN
# define NS_SWAP16(x) ((((x) & 0xff) << 8) | (((x) >> 8) & 0xff))
# define NS_SWAP32(x) ((NS_SWAP16((x) & 0xffff) << 16) | (NS_SWAP16((x) >> 16)))
// We want to avoid casting to 32-bit types if possible, since that violates
// aliasing rules (a standard compiler may assume that pointers of two types
// do not address overlapping storage).
//
// XXX What if we have a compiler that follows aliasing rules strictly but
// doesn't have a 64-bit int type?
//
// XXXbe shouldn't NSPR's LL_INIT work for non-constant arguments in all cases?
# if defined HAVE_LONG_LONG
#  if PR_BYTES_PER_LONG == 8
#   define ULL_(x)     x ## UL
#  elif defined WIN32 && defined _MSC_VER
#   define ULL_(x)     x ## ui64
#  else
#   define ULL_(x)     x ## ULL
#  endif
#  define NS_SWAP64(x) ((((x)    & ULL_(0xff00000000000000))    >> 56) |      \
                        (((x)    & ULL_(0x00ff000000000000))    >> 40) |      \
                        (((x)    & ULL_(0x0000ff0000000000))    >> 24) |      \
                        (((x)    & ULL_(0x000000ff00000000))    >> 8)  |      \
                        (((x)    & ULL_(0x00000000ff000000))    << 8)  |      \
                        (((x)    & ULL_(0x0000000000ff0000))    << 24) |      \
                        (((x)    & ULL_(0x000000000000ff00))    << 40) |      \
                        (((x) /* & ULL_(0x00000000000000ff) */) << 56))
# else
#  define NS_SWAP64(x) LL_INIT((((x).lo /* & 0xff000000ul */) >> 24) |        \
                               (((x).lo    & 0x00ff0000ul)    >> 8)  |        \
                               (((x).lo    & 0x0000ff00ul)    << 8)  |        \
                               (((x).lo /* & 0x000000fful */) << 24),         \
                               (((x).hi /* & 0xff000000ul */) >> 24) |        \
                               (((x).hi    & 0x00ff0000ul)    >> 8)  |        \
                               (((x).hi    & 0x0000ff00ul)    << 8)  |        \
                               (((x).hi /* & 0x000000fful */) << 24))
# endif
#elif defined IS_BIG_ENDIAN
# define NS_SWAP16(x) (x)
# define NS_SWAP32(x) (x)
# define NS_SWAP64(x) (x)
#else
# error "Unknown byte order"
#endif
/**
 * These macros get and put a buffer given either an sba parameter that may
 * point to an object implementing nsIStreamBufferAccess, nsIObjectInputStream,
 * or nsIObjectOutputStream.
 */
#define NS_GET_BUFFER(sba,n,a)  ((sba)->GetBuffer(n, a))
#define NS_PUT_BUFFER(sba,p,n)  ((sba)->PutBuffer(p, n))
#define NS_GET8(p)              (*(uint8_t*)(p))
#define NS_GET16(p)             NS_SWAP16(*(uint16_t*)(p))
#define NS_GET32(p)             NS_SWAP32(*(uint32_t*)(p))
#define NS_GET64(p)             NS_SWAP64(*(uint64_t*)(p))
#define NS_PUT8(p,x)            (*(uint8_t*)(p) = (x))
#define NS_PUT16(p,x)           (*(uint16_t*)(p) = NS_SWAP16(x))
#define NS_PUT32(p,x)           (*(uint32_t*)(p) = NS_SWAP32(x))
#define NS_PUT64(p,x)           (*(uint64_t*)(p) = NS_SWAP64(x))

#endif /* __gen_nsIStreamBufferAccess_h__ */
