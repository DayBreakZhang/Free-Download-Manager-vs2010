/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrivacyTransitionObserver.idl
 */

#ifndef __gen_nsIPrivacyTransitionObserver_h__
#define __gen_nsIPrivacyTransitionObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIPrivacyTransitionObserver */
#define NS_IPRIVACYTRANSITIONOBSERVER_IID_STR "b4b1449d-0ef0-47f5-b62e-adc57fd49702"

#define NS_IPRIVACYTRANSITIONOBSERVER_IID \
  {0xb4b1449d, 0x0ef0, 0x47f5, \
    { 0xb6, 0x2e, 0xad, 0xc5, 0x7f, 0xd4, 0x97, 0x02 }}

class NS_NO_VTABLE nsIPrivacyTransitionObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRIVACYTRANSITIONOBSERVER_IID)

  /* void privateModeChanged (in bool enabled); */
  NS_IMETHOD PrivateModeChanged(bool enabled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrivacyTransitionObserver, NS_IPRIVACYTRANSITIONOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRIVACYTRANSITIONOBSERVER \
  NS_IMETHOD PrivateModeChanged(bool enabled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRIVACYTRANSITIONOBSERVER(_to) \
  NS_IMETHOD PrivateModeChanged(bool enabled) { return _to PrivateModeChanged(enabled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRIVACYTRANSITIONOBSERVER(_to) \
  NS_IMETHOD PrivateModeChanged(bool enabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrivateModeChanged(enabled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrivacyTransitionObserver : public nsIPrivacyTransitionObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRIVACYTRANSITIONOBSERVER

  nsPrivacyTransitionObserver();

private:
  ~nsPrivacyTransitionObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrivacyTransitionObserver, nsIPrivacyTransitionObserver)

nsPrivacyTransitionObserver::nsPrivacyTransitionObserver()
{
  /* member initializers and constructor code */
}

nsPrivacyTransitionObserver::~nsPrivacyTransitionObserver()
{
  /* destructor code */
}

/* void privateModeChanged (in bool enabled); */
NS_IMETHODIMP nsPrivacyTransitionObserver::PrivateModeChanged(bool enabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrivacyTransitionObserver_h__ */
