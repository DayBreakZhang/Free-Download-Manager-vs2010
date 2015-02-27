/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITaskbarOverlayIconController.idl
 */

#ifndef __gen_nsITaskbarOverlayIconController_h__
#define __gen_nsITaskbarOverlayIconController_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class imgIContainer; /* forward declaration */


/* starting interface:    nsITaskbarOverlayIconController */
#define NS_ITASKBAROVERLAYICONCONTROLLER_IID_STR "b1858889-a698-428a-a14b-b5d60cff6de2"

#define NS_ITASKBAROVERLAYICONCONTROLLER_IID \
  {0xb1858889, 0xa698, 0x428a, \
    { 0xa1, 0x4b, 0xb5, 0xd6, 0x0c, 0xff, 0x6d, 0xe2 }}

class NS_NO_VTABLE nsITaskbarOverlayIconController : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITASKBAROVERLAYICONCONTROLLER_IID)

  /* void setOverlayIcon (in imgIContainer statusIcon, in AString statusDescription); */
  NS_IMETHOD SetOverlayIcon(imgIContainer *statusIcon, const nsAString & statusDescription) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITaskbarOverlayIconController, NS_ITASKBAROVERLAYICONCONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITASKBAROVERLAYICONCONTROLLER \
  NS_IMETHOD SetOverlayIcon(imgIContainer *statusIcon, const nsAString & statusDescription); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITASKBAROVERLAYICONCONTROLLER(_to) \
  NS_IMETHOD SetOverlayIcon(imgIContainer *statusIcon, const nsAString & statusDescription) { return _to SetOverlayIcon(statusIcon, statusDescription); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITASKBAROVERLAYICONCONTROLLER(_to) \
  NS_IMETHOD SetOverlayIcon(imgIContainer *statusIcon, const nsAString & statusDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOverlayIcon(statusIcon, statusDescription); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTaskbarOverlayIconController : public nsITaskbarOverlayIconController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITASKBAROVERLAYICONCONTROLLER

  nsTaskbarOverlayIconController();

private:
  ~nsTaskbarOverlayIconController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTaskbarOverlayIconController, nsITaskbarOverlayIconController)

nsTaskbarOverlayIconController::nsTaskbarOverlayIconController()
{
  /* member initializers and constructor code */
}

nsTaskbarOverlayIconController::~nsTaskbarOverlayIconController()
{
  /* destructor code */
}

/* void setOverlayIcon (in imgIContainer statusIcon, in AString statusDescription); */
NS_IMETHODIMP nsTaskbarOverlayIconController::SetOverlayIcon(imgIContainer *statusIcon, const nsAString & statusDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITaskbarOverlayIconController_h__ */
