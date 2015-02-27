/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/base/nsIDOMWindow2.idl
 */

#ifndef __gen_nsIDOMWindow2_h__
#define __gen_nsIDOMWindow2_h__


#ifndef __gen_nsIDOMWindow_h__
#include "nsIDOMWindow.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMOfflineResourceList; /* forward declaration */

class nsIDOMBlob; /* forward declaration */


/* starting interface:    nsIDOMWindow2 */
#define NS_IDOMWINDOW2_IID_STR "efff0d88-3b94-4375-bdeb-676a847ecd7d"

#define NS_IDOMWINDOW2_IID \
  {0xefff0d88, 0x3b94, 0x4375, \
    { 0xbd, 0xeb, 0x67, 0x6a, 0x84, 0x7e, 0xcd, 0x7d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMWindow2 : public nsIDOMWindow {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMWINDOW2_IID)

  /**
   * Get the window root for this window. This is useful for hooking
   * up event listeners to this window and every other window nested
   * in the window root.
   */
  /* [noscript] readonly attribute nsIDOMEventTarget windowRoot; */
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget **aWindowRoot) = 0;

  /**
   * Get the application cache object for this window.
   */
  /* readonly attribute nsIDOMOfflineResourceList applicationCache; */
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList **aApplicationCache) = 0;

  /**
   * Deprecated, but can't remove yet since we don't want to change interfaces.
   */
  /* [noscript] DOMString createBlobURL (in nsIDOMBlob blob); */
  NS_IMETHOD CreateBlobURL(nsIDOMBlob *blob, nsAString & _retval NS_OUTPARAM) = 0;

  /* [noscript] void revokeBlobURL (in DOMString URL); */
  NS_IMETHOD RevokeBlobURL(const nsAString & URL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMWindow2, NS_IDOMWINDOW2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMWINDOW2 \
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget **aWindowRoot); \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList **aApplicationCache); \
  NS_IMETHOD CreateBlobURL(nsIDOMBlob *blob, nsAString & _retval NS_OUTPARAM); \
  NS_IMETHOD RevokeBlobURL(const nsAString & URL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMWINDOW2(_to) \
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget **aWindowRoot) { return _to GetWindowRoot(aWindowRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList **aApplicationCache) { return _to GetApplicationCache(aApplicationCache); } \
  NS_IMETHOD CreateBlobURL(nsIDOMBlob *blob, nsAString & _retval NS_OUTPARAM) { return _to CreateBlobURL(blob, _retval); } \
  NS_IMETHOD RevokeBlobURL(const nsAString & URL) { return _to RevokeBlobURL(URL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMWINDOW2(_to) \
  NS_IMETHOD GetWindowRoot(nsIDOMEventTarget **aWindowRoot) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowRoot(aWindowRoot); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationCache(nsIDOMOfflineResourceList **aApplicationCache) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationCache(aApplicationCache); } \
  NS_IMETHOD CreateBlobURL(nsIDOMBlob *blob, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateBlobURL(blob, _retval); } \
  NS_IMETHOD RevokeBlobURL(const nsAString & URL) { return !_to ? NS_ERROR_NULL_POINTER : _to->RevokeBlobURL(URL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMWindow2 : public nsIDOMWindow2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMWINDOW2

  nsDOMWindow2();

private:
  ~nsDOMWindow2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMWindow2, nsIDOMWindow2)

nsDOMWindow2::nsDOMWindow2()
{
  /* member initializers and constructor code */
}

nsDOMWindow2::~nsDOMWindow2()
{
  /* destructor code */
}

/* [noscript] readonly attribute nsIDOMEventTarget windowRoot; */
NS_IMETHODIMP nsDOMWindow2::GetWindowRoot(nsIDOMEventTarget **aWindowRoot)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMOfflineResourceList applicationCache; */
NS_IMETHODIMP nsDOMWindow2::GetApplicationCache(nsIDOMOfflineResourceList **aApplicationCache)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] DOMString createBlobURL (in nsIDOMBlob blob); */
NS_IMETHODIMP nsDOMWindow2::CreateBlobURL(nsIDOMBlob *blob, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void revokeBlobURL (in DOMString URL); */
NS_IMETHODIMP nsDOMWindow2::RevokeBlobURL(const nsAString & URL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWindow2_h__ */
