/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/battery/nsINavigatorBattery.idl
 */

#ifndef __gen_nsINavigatorBattery_h__
#define __gen_nsINavigatorBattery_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsINavigatorBattery */
#define NS_INAVIGATORBATTERY_IID_STR "16ed7adc-b3e0-43c6-a121-5a2b500e90d0"

#define NS_INAVIGATORBATTERY_IID \
  {0x16ed7adc, 0xb3e0, 0x43c6, \
    { 0xa1, 0x21, 0x5a, 0x2b, 0x50, 0x0e, 0x90, 0xd0 }}

class NS_NO_VTABLE nsINavigatorBattery : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_INAVIGATORBATTERY_IID)

  /* readonly attribute nsISupports battery; */
  NS_IMETHOD GetBattery(nsISupports * *aBattery) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsINavigatorBattery, NS_INAVIGATORBATTERY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSINAVIGATORBATTERY \
  NS_IMETHOD GetBattery(nsISupports * *aBattery); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSINAVIGATORBATTERY(_to) \
  NS_IMETHOD GetBattery(nsISupports * *aBattery) { return _to GetBattery(aBattery); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSINAVIGATORBATTERY(_to) \
  NS_IMETHOD GetBattery(nsISupports * *aBattery) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBattery(aBattery); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsNavigatorBattery : public nsINavigatorBattery
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSINAVIGATORBATTERY

  nsNavigatorBattery();

private:
  ~nsNavigatorBattery();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsNavigatorBattery, nsINavigatorBattery)

nsNavigatorBattery::nsNavigatorBattery()
{
  /* member initializers and constructor code */
}

nsNavigatorBattery::~nsNavigatorBattery()
{
  /* destructor code */
}

/* readonly attribute nsISupports battery; */
NS_IMETHODIMP nsNavigatorBattery::GetBattery(nsISupports * *aBattery)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsINavigatorBattery_h__ */
