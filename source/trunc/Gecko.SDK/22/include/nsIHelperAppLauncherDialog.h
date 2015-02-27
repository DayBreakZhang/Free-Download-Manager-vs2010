/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/uriloader/exthandler/nsIHelperAppLauncherDialog.idl
 */

#ifndef __gen_nsIHelperAppLauncherDialog_h__
#define __gen_nsIHelperAppLauncherDialog_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHelperAppLauncher; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsIHelperAppLauncherDialog */
#define NS_IHELPERAPPLAUNCHERDIALOG_IID_STR "f3704fdc-8ae6-4eba-a3c3-f02958ac0649"

#define NS_IHELPERAPPLAUNCHERDIALOG_IID \
  {0xf3704fdc, 0x8ae6, 0x4eba, \
    { 0xa3, 0xc3, 0xf0, 0x29, 0x58, 0xac, 0x06, 0x49 }}

class NS_NO_VTABLE nsIHelperAppLauncherDialog : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHELPERAPPLAUNCHERDIALOG_IID)

  enum {
    REASON_CANTHANDLE = 0U,
    REASON_SERVERREQUEST = 1U,
    REASON_TYPESNIFFED = 2U
  };

  /* void show (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in unsigned long aReason); */
  NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, uint32_t aReason) = 0;

  /* nsIFile promptForSaveToFile (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in wstring aDefaultFileName, in wstring aSuggestedFileExtension, in boolean aForcePrompt); */
  NS_IMETHOD PromptForSaveToFile(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const PRUnichar * aDefaultFileName, const PRUnichar * aSuggestedFileExtension, bool aForcePrompt, nsIFile * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHelperAppLauncherDialog, NS_IHELPERAPPLAUNCHERDIALOG_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHELPERAPPLAUNCHERDIALOG \
  NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, uint32_t aReason); \
  NS_IMETHOD PromptForSaveToFile(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const PRUnichar * aDefaultFileName, const PRUnichar * aSuggestedFileExtension, bool aForcePrompt, nsIFile * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHELPERAPPLAUNCHERDIALOG(_to) \
  NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, uint32_t aReason) { return _to Show(aLauncher, aWindowContext, aReason); } \
  NS_IMETHOD PromptForSaveToFile(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const PRUnichar * aDefaultFileName, const PRUnichar * aSuggestedFileExtension, bool aForcePrompt, nsIFile * *_retval) { return _to PromptForSaveToFile(aLauncher, aWindowContext, aDefaultFileName, aSuggestedFileExtension, aForcePrompt, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHELPERAPPLAUNCHERDIALOG(_to) \
  NS_IMETHOD Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, uint32_t aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->Show(aLauncher, aWindowContext, aReason); } \
  NS_IMETHOD PromptForSaveToFile(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const PRUnichar * aDefaultFileName, const PRUnichar * aSuggestedFileExtension, bool aForcePrompt, nsIFile * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PromptForSaveToFile(aLauncher, aWindowContext, aDefaultFileName, aSuggestedFileExtension, aForcePrompt, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHelperAppLauncherDialog : public nsIHelperAppLauncherDialog
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHELPERAPPLAUNCHERDIALOG

  nsHelperAppLauncherDialog();

private:
  ~nsHelperAppLauncherDialog();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHelperAppLauncherDialog, nsIHelperAppLauncherDialog)

nsHelperAppLauncherDialog::nsHelperAppLauncherDialog()
{
  /* member initializers and constructor code */
}

nsHelperAppLauncherDialog::~nsHelperAppLauncherDialog()
{
  /* destructor code */
}

/* void show (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in unsigned long aReason); */
NS_IMETHODIMP nsHelperAppLauncherDialog::Show(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, uint32_t aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIFile promptForSaveToFile (in nsIHelperAppLauncher aLauncher, in nsISupports aWindowContext, in wstring aDefaultFileName, in wstring aSuggestedFileExtension, in boolean aForcePrompt); */
NS_IMETHODIMP nsHelperAppLauncherDialog::PromptForSaveToFile(nsIHelperAppLauncher *aLauncher, nsISupports *aWindowContext, const PRUnichar * aDefaultFileName, const PRUnichar * aSuggestedFileExtension, bool aForcePrompt, nsIFile * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_HELPERAPPLAUNCHERDLG_CONTRACTID    "@mozilla.org/helperapplauncherdialog;1"

#endif /* __gen_nsIHelperAppLauncherDialog_h__ */
