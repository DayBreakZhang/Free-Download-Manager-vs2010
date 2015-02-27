/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/cache/nsIDiskCacheStreamInternal.idl
 */

#ifndef __gen_nsIDiskCacheStreamInternal_h__
#define __gen_nsIDiskCacheStreamInternal_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDiskCacheStreamInternal */
#define NS_IDISKCACHESTREAMINTERNAL_IID_STR "61ff88f7-516e-4924-93af-42e7c412d18b"

#define NS_IDISKCACHESTREAMINTERNAL_IID \
  {0x61ff88f7, 0x516e, 0x4924, \
    { 0x93, 0xaf, 0x42, 0xe7, 0xc4, 0x12, 0xd1, 0x8b }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDiskCacheStreamInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDISKCACHESTREAMINTERNAL_IID)

  /**
     * We use this method internally to close nsDiskCacheOutputStream under
     * the cache service lock.
     */
  /* void closeInternal (); */
  NS_SCRIPTABLE NS_IMETHOD CloseInternal(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDiskCacheStreamInternal, NS_IDISKCACHESTREAMINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDISKCACHESTREAMINTERNAL \
  NS_SCRIPTABLE NS_IMETHOD CloseInternal(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDISKCACHESTREAMINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD CloseInternal(void) { return _to CloseInternal(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDISKCACHESTREAMINTERNAL(_to) \
  NS_SCRIPTABLE NS_IMETHOD CloseInternal(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseInternal(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDiskCacheStreamInternal : public nsIDiskCacheStreamInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDISKCACHESTREAMINTERNAL

  nsDiskCacheStreamInternal();

private:
  ~nsDiskCacheStreamInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDiskCacheStreamInternal, nsIDiskCacheStreamInternal)

nsDiskCacheStreamInternal::nsDiskCacheStreamInternal()
{
  /* member initializers and constructor code */
}

nsDiskCacheStreamInternal::~nsDiskCacheStreamInternal()
{
  /* destructor code */
}

/* void closeInternal (); */
NS_IMETHODIMP nsDiskCacheStreamInternal::CloseInternal()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDiskCacheStreamInternal_h__ */
