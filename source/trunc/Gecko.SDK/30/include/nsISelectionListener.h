/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISelectionListener.idl
 */

#ifndef __gen_nsISelectionListener_h__
#define __gen_nsISelectionListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocument; /* forward declaration */

class nsISelection; /* forward declaration */


/* starting interface:    nsISelectionListener */
#define NS_ISELECTIONLISTENER_IID_STR "280cd784-23c2-468d-8624-354e0b3804bd"

#define NS_ISELECTIONLISTENER_IID \
  {0x280cd784, 0x23c2, 0x468d, \
    { 0x86, 0x24, 0x35, 0x4e, 0x0b, 0x38, 0x04, 0xbd }}

class NS_NO_VTABLE nsISelectionListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISELECTIONLISTENER_IID)

  enum {
    NO_REASON = 0,
    DRAG_REASON = 1,
    MOUSEDOWN_REASON = 2,
    MOUSEUP_REASON = 4,
    KEYPRESS_REASON = 8,
    SELECTALL_REASON = 16,
    COLLAPSETOSTART_REASON = 32,
    COLLAPSETOEND_REASON = 64
  };

  /* void notifySelectionChanged (in nsIDOMDocument doc, in nsISelection sel, in short reason); */
  NS_IMETHOD NotifySelectionChanged(nsIDOMDocument *doc, nsISelection *sel, int16_t reason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISelectionListener, NS_ISELECTIONLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISELECTIONLISTENER \
  NS_IMETHOD NotifySelectionChanged(nsIDOMDocument *doc, nsISelection *sel, int16_t reason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISELECTIONLISTENER(_to) \
  NS_IMETHOD NotifySelectionChanged(nsIDOMDocument *doc, nsISelection *sel, int16_t reason) { return _to NotifySelectionChanged(doc, sel, reason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISELECTIONLISTENER(_to) \
  NS_IMETHOD NotifySelectionChanged(nsIDOMDocument *doc, nsISelection *sel, int16_t reason) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySelectionChanged(doc, sel, reason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSelectionListener : public nsISelectionListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISELECTIONLISTENER

  nsSelectionListener();

private:
  ~nsSelectionListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSelectionListener, nsISelectionListener)

nsSelectionListener::nsSelectionListener()
{
  /* member initializers and constructor code */
}

nsSelectionListener::~nsSelectionListener()
{
  /* destructor code */
}

/* void notifySelectionChanged (in nsIDOMDocument doc, in nsISelection sel, in short reason); */
NS_IMETHODIMP nsSelectionListener::NotifySelectionChanged(nsIDOMDocument *doc, nsISelection *sel, int16_t reason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISelectionListener_h__ */
