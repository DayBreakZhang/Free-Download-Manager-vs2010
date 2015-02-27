/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsPIPromptService.idl
 */

#ifndef __gen_nsPIPromptService_h__
#define __gen_nsPIPromptService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDialogParamBlock; /* forward declaration */


/* starting interface:    nsPIPromptService */
#define NS_PIPROMPTSERVICE_IID_STR "c60a1955-6cb3-4827-8ef8-4f5c668af0b3"

#define NS_PIPROMPTSERVICE_IID \
  {0xc60a1955, 0x6cb3, 0x4827, \
    { 0x8e, 0xf8, 0x4f, 0x5c, 0x66, 0x8a, 0xf0, 0xb3 }}

class nsPIPromptService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIPROMPTSERVICE_IID)

   // eOpeningSound is obsolete but we need to support it for the compatibility.
  // The implementers should use eSoundEventId instead.
  enum {eMsg=0, eCheckboxMsg=1, eIconClass=2, eTitleMessage=3, eEditfield1Msg=4,
        eEditfield2Msg=5, eEditfield1Value=6, eEditfield2Value=7,
        eButton0Text=8, eButton1Text=9, eButton2Text=10, eButton3Text=11,
        eDialogTitle=12, eOpeningSound=13};
  enum {eButtonPressed=0, eCheckboxState=1, eNumberButtons=2,
        eNumberEditfields=3, eEditField1Password=4, eDefaultButton=5,
        eDelayButtonEnable=6, eSoundEventId=7};
  /* void doDialog (in nsIDOMWindow aParent, in nsIDialogParamBlock aParamBlock, in string aChromeURL); */
  NS_IMETHOD DoDialog(nsIDOMWindow *aParent, nsIDialogParamBlock *aParamBlock, const char * aChromeURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIPromptService, NS_PIPROMPTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIPROMPTSERVICE \
  NS_IMETHOD DoDialog(nsIDOMWindow *aParent, nsIDialogParamBlock *aParamBlock, const char * aChromeURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIPROMPTSERVICE(_to) \
  NS_IMETHOD DoDialog(nsIDOMWindow *aParent, nsIDialogParamBlock *aParamBlock, const char * aChromeURL) { return _to DoDialog(aParent, aParamBlock, aChromeURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIPROMPTSERVICE(_to) \
  NS_IMETHOD DoDialog(nsIDOMWindow *aParent, nsIDialogParamBlock *aParamBlock, const char * aChromeURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoDialog(aParent, aParamBlock, aChromeURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIPromptService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIPROMPTSERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIPromptService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void doDialog (in nsIDOMWindow aParent, in nsIDialogParamBlock aParamBlock, in string aChromeURL); */
NS_IMETHODIMP _MYCLASS_::DoDialog(nsIDOMWindow *aParent, nsIDialogParamBlock *aParamBlock, const char * aChromeURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIPromptService_h__ */
