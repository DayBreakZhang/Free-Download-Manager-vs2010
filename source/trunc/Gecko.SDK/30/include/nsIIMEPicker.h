/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIIMEPicker.idl
 */

#ifndef __gen_nsIIMEPicker_h__
#define __gen_nsIIMEPicker_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIMEPicker */
#define NS_IIMEPICKER_IID_STR "9e631b1d-7a07-4925-a47e-697c6edaf408"

#define NS_IIMEPICKER_IID \
  {0x9e631b1d, 0x7a07, 0x4925, \
    { 0xa4, 0x7e, 0x69, 0x7c, 0x6e, 0xda, 0xf4, 0x08 }}

class NS_NO_VTABLE nsIIMEPicker : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIMEPICKER_IID)

  /* void show (); */
  NS_IMETHOD Show(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIMEPicker, NS_IIMEPICKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIMEPICKER \
  NS_IMETHOD Show(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIMEPICKER(_to) \
  NS_IMETHOD Show(void) { return _to Show(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIMEPICKER(_to) \
  NS_IMETHOD Show(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIMEPicker : public nsIIMEPicker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIMEPICKER

  nsIMEPicker();

private:
  ~nsIMEPicker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIMEPicker, nsIIMEPicker)

nsIMEPicker::nsIMEPicker()
{
  /* member initializers and constructor code */
}

nsIMEPicker::~nsIMEPicker()
{
  /* destructor code */
}

/* void show (); */
NS_IMETHODIMP nsIMEPicker::Show()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIMEPicker_h__ */
