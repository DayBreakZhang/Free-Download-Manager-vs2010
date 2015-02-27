/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/layout/xul/base/public/nsISliderListener.idl
 */

#ifndef __gen_nsISliderListener_h__
#define __gen_nsISliderListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISliderListener */
#define NS_ISLIDERLISTENER_IID_STR "e5b3074e-ee18-4538-83b9-2487d90a2a34"

#define NS_ISLIDERLISTENER_IID \
  {0xe5b3074e, 0xee18, 0x4538, \
    { 0x83, 0xb9, 0x24, 0x87, 0xd9, 0x0a, 0x2a, 0x34 }}

class NS_NO_VTABLE nsISliderListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISLIDERLISTENER_IID)

  /* void valueChanged (in AString which, in long newValue, in boolean userChanged); */
  NS_IMETHOD ValueChanged(const nsAString & which, int32_t newValue, bool userChanged) = 0;

  /* void dragStateChanged (in boolean isDragging); */
  NS_IMETHOD DragStateChanged(bool isDragging) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISliderListener, NS_ISLIDERLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISLIDERLISTENER \
  NS_IMETHOD ValueChanged(const nsAString & which, int32_t newValue, bool userChanged); \
  NS_IMETHOD DragStateChanged(bool isDragging); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISLIDERLISTENER(_to) \
  NS_IMETHOD ValueChanged(const nsAString & which, int32_t newValue, bool userChanged) { return _to ValueChanged(which, newValue, userChanged); } \
  NS_IMETHOD DragStateChanged(bool isDragging) { return _to DragStateChanged(isDragging); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISLIDERLISTENER(_to) \
  NS_IMETHOD ValueChanged(const nsAString & which, int32_t newValue, bool userChanged) { return !_to ? NS_ERROR_NULL_POINTER : _to->ValueChanged(which, newValue, userChanged); } \
  NS_IMETHOD DragStateChanged(bool isDragging) { return !_to ? NS_ERROR_NULL_POINTER : _to->DragStateChanged(isDragging); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSliderListener : public nsISliderListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISLIDERLISTENER

  nsSliderListener();

private:
  ~nsSliderListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSliderListener, nsISliderListener)

nsSliderListener::nsSliderListener()
{
  /* member initializers and constructor code */
}

nsSliderListener::~nsSliderListener()
{
  /* destructor code */
}

/* void valueChanged (in AString which, in long newValue, in boolean userChanged); */
NS_IMETHODIMP nsSliderListener::ValueChanged(const nsAString & which, int32_t newValue, bool userChanged)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void dragStateChanged (in boolean isDragging); */
NS_IMETHODIMP nsSliderListener::DragStateChanged(bool isDragging)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISliderListener_h__ */
