/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/startupcache/nsIStartupCache.idl
 */

#ifndef __gen_nsIStartupCache_h__
#define __gen_nsIStartupCache_h__


#ifndef __gen_nsIInputStream_h__
#include "nsIInputStream.h"
#endif

#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIObserver_h__
#include "nsIObserver.h"
#endif

#ifndef __gen_nsIObjectOutputStream_h__
#include "nsIObjectOutputStream.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIStartupCache */
#define NS_ISTARTUPCACHE_IID_STR "de798fab-af49-4a61-8144-81550986e1da"

#define NS_ISTARTUPCACHE_IID \
  {0xde798fab, 0xaf49, 0x4a61, \
    { 0x81, 0x44, 0x81, 0x55, 0x09, 0x86, 0xe1, 0xda }}

class NS_NO_VTABLE nsIStartupCache : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTARTUPCACHE_IID)

  /** This interface is provided for testing purposes only, basically
   *  just to solve link vagaries. See docs in StartupCache.h
   *  GetBuffer, PutBuffer, and InvalidateCache act as described 
   *  in that file. */
  /* PRUint32 getBuffer (in string aID, out charPtr aBuffer); */
  NS_IMETHOD GetBuffer(const char *aID, char **aBuffer NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* void putBuffer (in string aID, in charPtr aBuffer, in PRUint32 aLength); */
  NS_IMETHOD PutBuffer(const char *aID, char *aBuffer, PRUint32 aLength) = 0;

  /* void invalidateCache (); */
  NS_IMETHOD InvalidateCache(void) = 0;

  /** In debug builds, wraps this object output stream with a stream that will 
   *  detect and prevent the write of a multiply-referenced non-singleton object 
   *  during serialization. In non-debug, returns an add-ref'd pointer to
   *  original stream, unwrapped. */
  /* nsIObjectOutputStream getDebugObjectOutputStream (in nsIObjectOutputStream aStream); */
  NS_IMETHOD GetDebugObjectOutputStream(nsIObjectOutputStream *aStream, nsIObjectOutputStream **_retval NS_OUTPARAM) = 0;

  /* boolean startupWriteComplete (); */
  NS_IMETHOD StartupWriteComplete(PRBool *_retval NS_OUTPARAM) = 0;

  /* void resetStartupWriteTimer (); */
  NS_IMETHOD ResetStartupWriteTimer(void) = 0;

  /* readonly attribute nsIObserver observer; */
  NS_IMETHOD GetObserver(nsIObserver **aObserver) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStartupCache, NS_ISTARTUPCACHE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTARTUPCACHE \
  NS_IMETHOD GetBuffer(const char *aID, char **aBuffer NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM); \
  NS_IMETHOD PutBuffer(const char *aID, char *aBuffer, PRUint32 aLength); \
  NS_IMETHOD InvalidateCache(void); \
  NS_IMETHOD GetDebugObjectOutputStream(nsIObjectOutputStream *aStream, nsIObjectOutputStream **_retval NS_OUTPARAM); \
  NS_IMETHOD StartupWriteComplete(PRBool *_retval NS_OUTPARAM); \
  NS_IMETHOD ResetStartupWriteTimer(void); \
  NS_IMETHOD GetObserver(nsIObserver **aObserver); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTARTUPCACHE(_to) \
  NS_IMETHOD GetBuffer(const char *aID, char **aBuffer NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return _to GetBuffer(aID, aBuffer, _retval); } \
  NS_IMETHOD PutBuffer(const char *aID, char *aBuffer, PRUint32 aLength) { return _to PutBuffer(aID, aBuffer, aLength); } \
  NS_IMETHOD InvalidateCache(void) { return _to InvalidateCache(); } \
  NS_IMETHOD GetDebugObjectOutputStream(nsIObjectOutputStream *aStream, nsIObjectOutputStream **_retval NS_OUTPARAM) { return _to GetDebugObjectOutputStream(aStream, _retval); } \
  NS_IMETHOD StartupWriteComplete(PRBool *_retval NS_OUTPARAM) { return _to StartupWriteComplete(_retval); } \
  NS_IMETHOD ResetStartupWriteTimer(void) { return _to ResetStartupWriteTimer(); } \
  NS_IMETHOD GetObserver(nsIObserver **aObserver) { return _to GetObserver(aObserver); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTARTUPCACHE(_to) \
  NS_IMETHOD GetBuffer(const char *aID, char **aBuffer NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBuffer(aID, aBuffer, _retval); } \
  NS_IMETHOD PutBuffer(const char *aID, char *aBuffer, PRUint32 aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->PutBuffer(aID, aBuffer, aLength); } \
  NS_IMETHOD InvalidateCache(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->InvalidateCache(); } \
  NS_IMETHOD GetDebugObjectOutputStream(nsIObjectOutputStream *aStream, nsIObjectOutputStream **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDebugObjectOutputStream(aStream, _retval); } \
  NS_IMETHOD StartupWriteComplete(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartupWriteComplete(_retval); } \
  NS_IMETHOD ResetStartupWriteTimer(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetStartupWriteTimer(); } \
  NS_IMETHOD GetObserver(nsIObserver **aObserver) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetObserver(aObserver); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStartupCache : public nsIStartupCache
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTARTUPCACHE

  nsStartupCache();

private:
  ~nsStartupCache();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStartupCache, nsIStartupCache)

nsStartupCache::nsStartupCache()
{
  /* member initializers and constructor code */
}

nsStartupCache::~nsStartupCache()
{
  /* destructor code */
}

/* PRUint32 getBuffer (in string aID, out charPtr aBuffer); */
NS_IMETHODIMP nsStartupCache::GetBuffer(const char *aID, char **aBuffer NS_OUTPARAM, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void putBuffer (in string aID, in charPtr aBuffer, in PRUint32 aLength); */
NS_IMETHODIMP nsStartupCache::PutBuffer(const char *aID, char *aBuffer, PRUint32 aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void invalidateCache (); */
NS_IMETHODIMP nsStartupCache::InvalidateCache()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIObjectOutputStream getDebugObjectOutputStream (in nsIObjectOutputStream aStream); */
NS_IMETHODIMP nsStartupCache::GetDebugObjectOutputStream(nsIObjectOutputStream *aStream, nsIObjectOutputStream **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean startupWriteComplete (); */
NS_IMETHODIMP nsStartupCache::StartupWriteComplete(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetStartupWriteTimer (); */
NS_IMETHODIMP nsStartupCache::ResetStartupWriteTimer()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIObserver observer; */
NS_IMETHODIMP nsStartupCache::GetObserver(nsIObserver **aObserver)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStartupCache_h__ */
