/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMModalContentWindow.idl
 */

#ifndef __gen_nsIDOMModalContentWindow_h__
#define __gen_nsIDOMModalContentWindow_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIDOMModalContentWindow */
#define NS_IDOMMODALCONTENTWINDOW_IID_STR "3f4cb2d0-5f7e-44a9-9f4f-370945f8db08"

#define NS_IDOMMODALCONTENTWINDOW_IID \
  {0x3f4cb2d0, 0x5f7e, 0x44a9, \
    { 0x9f, 0x4f, 0x37, 0x09, 0x45, 0xf8, 0xdb, 0x08 }}

class NS_NO_VTABLE nsIDOMModalContentWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMODALCONTENTWINDOW_IID)

  /* readonly attribute nsIVariant dialogArguments; */
  NS_IMETHOD GetDialogArguments(nsIVariant * *aDialogArguments) = 0;

  /* attribute nsIVariant returnValue; */
  NS_IMETHOD GetReturnValue(nsIVariant * *aReturnValue) = 0;
  NS_IMETHOD SetReturnValue(nsIVariant *aReturnValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMModalContentWindow, NS_IDOMMODALCONTENTWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMODALCONTENTWINDOW \
  NS_IMETHOD GetDialogArguments(nsIVariant * *aDialogArguments); \
  NS_IMETHOD GetReturnValue(nsIVariant * *aReturnValue); \
  NS_IMETHOD SetReturnValue(nsIVariant *aReturnValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMODALCONTENTWINDOW(_to) \
  NS_IMETHOD GetDialogArguments(nsIVariant * *aDialogArguments) { return _to GetDialogArguments(aDialogArguments); } \
  NS_IMETHOD GetReturnValue(nsIVariant * *aReturnValue) { return _to GetReturnValue(aReturnValue); } \
  NS_IMETHOD SetReturnValue(nsIVariant *aReturnValue) { return _to SetReturnValue(aReturnValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMODALCONTENTWINDOW(_to) \
  NS_IMETHOD GetDialogArguments(nsIVariant * *aDialogArguments) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDialogArguments(aDialogArguments); } \
  NS_IMETHOD GetReturnValue(nsIVariant * *aReturnValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReturnValue(aReturnValue); } \
  NS_IMETHOD SetReturnValue(nsIVariant *aReturnValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetReturnValue(aReturnValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMModalContentWindow : public nsIDOMModalContentWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMODALCONTENTWINDOW

  nsDOMModalContentWindow();

private:
  ~nsDOMModalContentWindow();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMModalContentWindow, nsIDOMModalContentWindow)

nsDOMModalContentWindow::nsDOMModalContentWindow()
{
  /* member initializers and constructor code */
}

nsDOMModalContentWindow::~nsDOMModalContentWindow()
{
  /* destructor code */
}

/* readonly attribute nsIVariant dialogArguments; */
NS_IMETHODIMP nsDOMModalContentWindow::GetDialogArguments(nsIVariant * *aDialogArguments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIVariant returnValue; */
NS_IMETHODIMP nsDOMModalContentWindow::GetReturnValue(nsIVariant * *aReturnValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMModalContentWindow::SetReturnValue(nsIVariant *aReturnValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMModalContentWindow_h__ */
