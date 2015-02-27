/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/events/nsIDOMEventListener.idl
 */

#ifndef __gen_nsIDOMEventListener_h__
#define __gen_nsIDOMEventListener_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMEventListener */
#define NS_IDOMEVENTLISTENER_IID_STR "df31c120-ded6-11d1-bd85-00805f8ae3f4"

#define NS_IDOMEVENTLISTENER_IID \
  {0xdf31c120, 0xded6, 0x11d1, \
    { 0xbd, 0x85, 0x00, 0x80, 0x5f, 0x8a, 0xe3, 0xf4 }}

class NS_NO_VTABLE nsIDOMEventListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMEVENTLISTENER_IID)

  /* void handleEvent (in nsIDOMEvent event); */
  NS_IMETHOD HandleEvent(nsIDOMEvent *event) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMEventListener, NS_IDOMEVENTLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMEVENTLISTENER \
  NS_IMETHOD HandleEvent(nsIDOMEvent *event); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMEVENTLISTENER(_to) \
  NS_IMETHOD HandleEvent(nsIDOMEvent *event) { return _to HandleEvent(event); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMEVENTLISTENER(_to) \
  NS_IMETHOD HandleEvent(nsIDOMEvent *event) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleEvent(event); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMEventListener : public nsIDOMEventListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMEVENTLISTENER

  nsDOMEventListener();

private:
  ~nsDOMEventListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMEventListener, nsIDOMEventListener)

nsDOMEventListener::nsDOMEventListener()
{
  /* member initializers and constructor code */
}

nsDOMEventListener::~nsDOMEventListener()
{
  /* destructor code */
}

/* void handleEvent (in nsIDOMEvent event); */
NS_IMETHODIMP nsDOMEventListener::HandleEvent(nsIDOMEvent *event)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMEventListener_h__ */
