/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/power/nsIDOMWakeLockListener.idl
 */

#ifndef __gen_nsIDOMWakeLockListener_h__
#define __gen_nsIDOMWakeLockListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozWakeLockListener */
#define NS_IDOMMOZWAKELOCKLISTENER_IID_STR "4e258af8-cffb-47bc-b16d-e8241243426e"

#define NS_IDOMMOZWAKELOCKLISTENER_IID \
  {0x4e258af8, 0xcffb, 0x47bc, \
    { 0xb1, 0x6d, 0xe8, 0x24, 0x12, 0x43, 0x42, 0x6e }}

class NS_NO_VTABLE nsIDOMMozWakeLockListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZWAKELOCKLISTENER_IID)

  /* void callback (in DOMString aTopic, in DOMString aState); */
  NS_IMETHOD Callback(const nsAString & aTopic, const nsAString & aState) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozWakeLockListener, NS_IDOMMOZWAKELOCKLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZWAKELOCKLISTENER \
  NS_IMETHOD Callback(const nsAString & aTopic, const nsAString & aState); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZWAKELOCKLISTENER(_to) \
  NS_IMETHOD Callback(const nsAString & aTopic, const nsAString & aState) { return _to Callback(aTopic, aState); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZWAKELOCKLISTENER(_to) \
  NS_IMETHOD Callback(const nsAString & aTopic, const nsAString & aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->Callback(aTopic, aState); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozWakeLockListener : public nsIDOMMozWakeLockListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZWAKELOCKLISTENER

  nsDOMMozWakeLockListener();

private:
  ~nsDOMMozWakeLockListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozWakeLockListener, nsIDOMMozWakeLockListener)

nsDOMMozWakeLockListener::nsDOMMozWakeLockListener()
{
  /* member initializers and constructor code */
}

nsDOMMozWakeLockListener::~nsDOMMozWakeLockListener()
{
  /* destructor code */
}

/* void callback (in DOMString aTopic, in DOMString aState); */
NS_IMETHODIMP nsDOMMozWakeLockListener::Callback(const nsAString & aTopic, const nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMWakeLockListener_h__ */
