/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/content/html/content/public/nsIFormSubmitObserver.idl
 */

#ifndef __gen_nsIFormSubmitObserver_h__
#define __gen_nsIFormSubmitObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLFormElement; /* forward declaration */

class nsIDOMWindowInternal; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIFormSubmitObserver */
#define NS_IFORMSUBMITOBSERVER_IID_STR "0b3cc84d-25d2-448e-ae71-746ee6e41c2d"

#define NS_IFORMSUBMITOBSERVER_IID \
  {0x0b3cc84d, 0x25d2, 0x448e, \
    { 0xae, 0x71, 0x74, 0x6e, 0xe6, 0xe4, 0x1c, 0x2d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFormSubmitObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMSUBMITOBSERVER_IID)

  /* void notify (in nsIDOMHTMLFormElement formNode, in nsIDOMWindowInternal window, in nsIURI actionURL, out boolean cancelSubmit); */
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIDOMHTMLFormElement *formNode, nsIDOMWindowInternal *window, nsIURI *actionURL, PRBool *cancelSubmit NS_OUTPARAM) = 0;

  /* void notifyInvalidSubmit (in nsIDOMHTMLFormElement formNode, in nsIArray invalidElements); */
  NS_SCRIPTABLE NS_IMETHOD NotifyInvalidSubmit(nsIDOMHTMLFormElement *formNode, nsIArray *invalidElements) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormSubmitObserver, NS_IFORMSUBMITOBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMSUBMITOBSERVER \
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIDOMHTMLFormElement *formNode, nsIDOMWindowInternal *window, nsIURI *actionURL, PRBool *cancelSubmit NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NotifyInvalidSubmit(nsIDOMHTMLFormElement *formNode, nsIArray *invalidElements); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMSUBMITOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIDOMHTMLFormElement *formNode, nsIDOMWindowInternal *window, nsIURI *actionURL, PRBool *cancelSubmit NS_OUTPARAM) { return _to Notify(formNode, window, actionURL, cancelSubmit); } \
  NS_SCRIPTABLE NS_IMETHOD NotifyInvalidSubmit(nsIDOMHTMLFormElement *formNode, nsIArray *invalidElements) { return _to NotifyInvalidSubmit(formNode, invalidElements); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMSUBMITOBSERVER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Notify(nsIDOMHTMLFormElement *formNode, nsIDOMWindowInternal *window, nsIURI *actionURL, PRBool *cancelSubmit NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Notify(formNode, window, actionURL, cancelSubmit); } \
  NS_SCRIPTABLE NS_IMETHOD NotifyInvalidSubmit(nsIDOMHTMLFormElement *formNode, nsIArray *invalidElements) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyInvalidSubmit(formNode, invalidElements); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormSubmitObserver : public nsIFormSubmitObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMSUBMITOBSERVER

  nsFormSubmitObserver();

private:
  ~nsFormSubmitObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFormSubmitObserver, nsIFormSubmitObserver)

nsFormSubmitObserver::nsFormSubmitObserver()
{
  /* member initializers and constructor code */
}

nsFormSubmitObserver::~nsFormSubmitObserver()
{
  /* destructor code */
}

/* void notify (in nsIDOMHTMLFormElement formNode, in nsIDOMWindowInternal window, in nsIURI actionURL, out boolean cancelSubmit); */
NS_IMETHODIMP nsFormSubmitObserver::Notify(nsIDOMHTMLFormElement *formNode, nsIDOMWindowInternal *window, nsIURI *actionURL, PRBool *cancelSubmit NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyInvalidSubmit (in nsIDOMHTMLFormElement formNode, in nsIArray invalidElements); */
NS_IMETHODIMP nsFormSubmitObserver::NotifyInvalidSubmit(nsIDOMHTMLFormElement *formNode, nsIArray *invalidElements)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_FORMSUBMIT_SUBJECT "formsubmit"
#define NS_EARLYFORMSUBMIT_SUBJECT "earlyformsubmit"
#define NS_FIRST_FORMSUBMIT_CATEGORY "firstformsubmit"
#define NS_PASSWORDMANAGER_CATEGORY "passwordmanager"
#define NS_INVALIDFORMSUBMIT_SUBJECT "invalidformsubmit"

#endif /* __gen_nsIFormSubmitObserver_h__ */
