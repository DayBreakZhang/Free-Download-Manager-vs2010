/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIRedirectResultListener.idl
 */

#ifndef __gen_nsIRedirectResultListener_h__
#define __gen_nsIRedirectResultListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIRedirectResultListener */
#define NS_IREDIRECTRESULTLISTENER_IID_STR "85cd2640-e91e-41ac-bdca-1dbf10dc131e"

#define NS_IREDIRECTRESULTLISTENER_IID \
  {0x85cd2640, 0xe91e, 0x41ac, \
    { 0xbd, 0xca, 0x1d, 0xbf, 0x10, 0xdc, 0x13, 0x1e }}

class NS_NO_VTABLE nsIRedirectResultListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IREDIRECTRESULTLISTENER_IID)

  /* void onRedirectResult (in boolean proceeding); */
  NS_IMETHOD OnRedirectResult(bool proceeding) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIRedirectResultListener, NS_IREDIRECTRESULTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIREDIRECTRESULTLISTENER \
  NS_IMETHOD OnRedirectResult(bool proceeding); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIREDIRECTRESULTLISTENER(_to) \
  NS_IMETHOD OnRedirectResult(bool proceeding) { return _to OnRedirectResult(proceeding); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIREDIRECTRESULTLISTENER(_to) \
  NS_IMETHOD OnRedirectResult(bool proceeding) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnRedirectResult(proceeding); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsRedirectResultListener : public nsIRedirectResultListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIREDIRECTRESULTLISTENER

  nsRedirectResultListener();

private:
  ~nsRedirectResultListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsRedirectResultListener, nsIRedirectResultListener)

nsRedirectResultListener::nsRedirectResultListener()
{
  /* member initializers and constructor code */
}

nsRedirectResultListener::~nsRedirectResultListener()
{
  /* destructor code */
}

/* void onRedirectResult (in boolean proceeding); */
NS_IMETHODIMP nsRedirectResultListener::OnRedirectResult(bool proceeding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIRedirectResultListener_h__ */
