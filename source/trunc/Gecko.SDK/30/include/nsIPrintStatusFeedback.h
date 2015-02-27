/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrintStatusFeedback.idl
 */

#ifndef __gen_nsIPrintStatusFeedback_h__
#define __gen_nsIPrintStatusFeedback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDocShell; /* forward declaration */

class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIPrintStatusFeedback */
#define NS_IPRINTSTATUSFEEDBACK_IID_STR "e439d3eb-b1ed-449c-aaf7-c693e399b16f"

#define NS_IPRINTSTATUSFEEDBACK_IID \
  {0xe439d3eb, 0xb1ed, 0x449c, \
    { 0xaa, 0xf7, 0xc6, 0x93, 0xe3, 0x99, 0xb1, 0x6f }}

class NS_NO_VTABLE nsIPrintStatusFeedback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINTSTATUSFEEDBACK_IID)

  /* void showStatusString (in wstring status); */
  NS_IMETHOD ShowStatusString(const char16_t * status) = 0;

  /* void startMeteors (); */
  NS_IMETHOD StartMeteors(void) = 0;

  /* void stopMeteors (); */
  NS_IMETHOD StopMeteors(void) = 0;

  /* void showProgress (in long percent); */
  NS_IMETHOD ShowProgress(int32_t percent) = 0;

  /* [noscript] void setDocShell (in nsIDocShell shell, in nsIDOMWindow window); */
  NS_IMETHOD SetDocShell(nsIDocShell *shell, nsIDOMWindow *window) = 0;

  /* void closeWindow (); */
  NS_IMETHOD CloseWindow(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrintStatusFeedback, NS_IPRINTSTATUSFEEDBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINTSTATUSFEEDBACK \
  NS_IMETHOD ShowStatusString(const char16_t * status); \
  NS_IMETHOD StartMeteors(void); \
  NS_IMETHOD StopMeteors(void); \
  NS_IMETHOD ShowProgress(int32_t percent); \
  NS_IMETHOD SetDocShell(nsIDocShell *shell, nsIDOMWindow *window); \
  NS_IMETHOD CloseWindow(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINTSTATUSFEEDBACK(_to) \
  NS_IMETHOD ShowStatusString(const char16_t * status) { return _to ShowStatusString(status); } \
  NS_IMETHOD StartMeteors(void) { return _to StartMeteors(); } \
  NS_IMETHOD StopMeteors(void) { return _to StopMeteors(); } \
  NS_IMETHOD ShowProgress(int32_t percent) { return _to ShowProgress(percent); } \
  NS_IMETHOD SetDocShell(nsIDocShell *shell, nsIDOMWindow *window) { return _to SetDocShell(shell, window); } \
  NS_IMETHOD CloseWindow(void) { return _to CloseWindow(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINTSTATUSFEEDBACK(_to) \
  NS_IMETHOD ShowStatusString(const char16_t * status) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowStatusString(status); } \
  NS_IMETHOD StartMeteors(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartMeteors(); } \
  NS_IMETHOD StopMeteors(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StopMeteors(); } \
  NS_IMETHOD ShowProgress(int32_t percent) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowProgress(percent); } \
  NS_IMETHOD SetDocShell(nsIDocShell *shell, nsIDOMWindow *window) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocShell(shell, window); } \
  NS_IMETHOD CloseWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseWindow(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrintStatusFeedback : public nsIPrintStatusFeedback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINTSTATUSFEEDBACK

  nsPrintStatusFeedback();

private:
  ~nsPrintStatusFeedback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrintStatusFeedback, nsIPrintStatusFeedback)

nsPrintStatusFeedback::nsPrintStatusFeedback()
{
  /* member initializers and constructor code */
}

nsPrintStatusFeedback::~nsPrintStatusFeedback()
{
  /* destructor code */
}

/* void showStatusString (in wstring status); */
NS_IMETHODIMP nsPrintStatusFeedback::ShowStatusString(const char16_t * status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startMeteors (); */
NS_IMETHODIMP nsPrintStatusFeedback::StartMeteors()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void stopMeteors (); */
NS_IMETHODIMP nsPrintStatusFeedback::StopMeteors()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void showProgress (in long percent); */
NS_IMETHODIMP nsPrintStatusFeedback::ShowProgress(int32_t percent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setDocShell (in nsIDocShell shell, in nsIDOMWindow window); */
NS_IMETHODIMP nsPrintStatusFeedback::SetDocShell(nsIDocShell *shell, nsIDOMWindow *window)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closeWindow (); */
NS_IMETHODIMP nsPrintStatusFeedback::CloseWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrintStatusFeedback_h__ */
