/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/toolkit/components/alerts/nsIAlertsService.idl
 */

#ifndef __gen_nsIAlertsService_h__
#define __gen_nsIAlertsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIObserver_h__
#include "nsIObserver.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAlertsService */
#define NS_IALERTSSERVICE_IID_STR "160e87e1-d57d-456b-b6ea-17826f6ea7a8"

#define NS_IALERTSSERVICE_IID \
  {0x160e87e1, 0xd57d, 0x456b, \
    { 0xb6, 0xea, 0x17, 0x82, 0x6f, 0x6e, 0xa7, 0xa8 }}

class NS_NO_VTABLE nsIAlertsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IALERTSSERVICE_IID)

  /* void showAlertNotification (in AString imageUrl, in AString title, in AString text, [optional] in boolean textClickable, [optional] in AString cookie, [optional] in nsIObserver alertListener, [optional] in AString name, [optional] in AString dir, [optional] in AString lang); */
  NS_IMETHOD ShowAlertNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & cookie, nsIObserver *alertListener, const nsAString & name, const nsAString & dir, const nsAString & lang) = 0;

  /* void closeAlert ([optional] in AString name); */
  NS_IMETHOD CloseAlert(const nsAString & name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAlertsService, NS_IALERTSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIALERTSSERVICE \
  NS_IMETHOD ShowAlertNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & cookie, nsIObserver *alertListener, const nsAString & name, const nsAString & dir, const nsAString & lang); \
  NS_IMETHOD CloseAlert(const nsAString & name); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIALERTSSERVICE(_to) \
  NS_IMETHOD ShowAlertNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & cookie, nsIObserver *alertListener, const nsAString & name, const nsAString & dir, const nsAString & lang) { return _to ShowAlertNotification(imageUrl, title, text, textClickable, cookie, alertListener, name, dir, lang); } \
  NS_IMETHOD CloseAlert(const nsAString & name) { return _to CloseAlert(name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIALERTSSERVICE(_to) \
  NS_IMETHOD ShowAlertNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & cookie, nsIObserver *alertListener, const nsAString & name, const nsAString & dir, const nsAString & lang) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowAlertNotification(imageUrl, title, text, textClickable, cookie, alertListener, name, dir, lang); } \
  NS_IMETHOD CloseAlert(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseAlert(name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAlertsService : public nsIAlertsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIALERTSSERVICE

  nsAlertsService();

private:
  ~nsAlertsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAlertsService, nsIAlertsService)

nsAlertsService::nsAlertsService()
{
  /* member initializers and constructor code */
}

nsAlertsService::~nsAlertsService()
{
  /* destructor code */
}

/* void showAlertNotification (in AString imageUrl, in AString title, in AString text, [optional] in boolean textClickable, [optional] in AString cookie, [optional] in nsIObserver alertListener, [optional] in AString name, [optional] in AString dir, [optional] in AString lang); */
NS_IMETHODIMP nsAlertsService::ShowAlertNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & cookie, nsIObserver *alertListener, const nsAString & name, const nsAString & dir, const nsAString & lang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closeAlert ([optional] in AString name); */
NS_IMETHODIMP nsAlertsService::CloseAlert(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIAlertsProgressListener */
#define NS_IALERTSPROGRESSLISTENER_IID_STR "df1bd4b0-3a8c-40e6-806a-203f38b0bd9f"

#define NS_IALERTSPROGRESSLISTENER_IID \
  {0xdf1bd4b0, 0x3a8c, 0x40e6, \
    { 0x80, 0x6a, 0x20, 0x3f, 0x38, 0xb0, 0xbd, 0x9f }}

class NS_NO_VTABLE nsIAlertsProgressListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IALERTSPROGRESSLISTENER_IID)

  /* void onProgress (in AString name, in long long progress, in long long progressMax, [optional] in AString text); */
  NS_IMETHOD OnProgress(const nsAString & name, int64_t progress, int64_t progressMax, const nsAString & text) = 0;

  /* void onCancel (in AString name); */
  NS_IMETHOD OnCancel(const nsAString & name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAlertsProgressListener, NS_IALERTSPROGRESSLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIALERTSPROGRESSLISTENER \
  NS_IMETHOD OnProgress(const nsAString & name, int64_t progress, int64_t progressMax, const nsAString & text); \
  NS_IMETHOD OnCancel(const nsAString & name); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIALERTSPROGRESSLISTENER(_to) \
  NS_IMETHOD OnProgress(const nsAString & name, int64_t progress, int64_t progressMax, const nsAString & text) { return _to OnProgress(name, progress, progressMax, text); } \
  NS_IMETHOD OnCancel(const nsAString & name) { return _to OnCancel(name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIALERTSPROGRESSLISTENER(_to) \
  NS_IMETHOD OnProgress(const nsAString & name, int64_t progress, int64_t progressMax, const nsAString & text) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProgress(name, progress, progressMax, text); } \
  NS_IMETHOD OnCancel(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCancel(name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAlertsProgressListener : public nsIAlertsProgressListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIALERTSPROGRESSLISTENER

  nsAlertsProgressListener();

private:
  ~nsAlertsProgressListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAlertsProgressListener, nsIAlertsProgressListener)

nsAlertsProgressListener::nsAlertsProgressListener()
{
  /* member initializers and constructor code */
}

nsAlertsProgressListener::~nsAlertsProgressListener()
{
  /* destructor code */
}

/* void onProgress (in AString name, in long long progress, in long long progressMax, [optional] in AString text); */
NS_IMETHODIMP nsAlertsProgressListener::OnProgress(const nsAString & name, int64_t progress, int64_t progressMax, const nsAString & text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCancel (in AString name); */
NS_IMETHODIMP nsAlertsProgressListener::OnCancel(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAlertsService_h__ */
