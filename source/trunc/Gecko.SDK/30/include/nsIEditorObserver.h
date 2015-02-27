/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIEditorObserver.idl
 */

#ifndef __gen_nsIEditorObserver_h__
#define __gen_nsIEditorObserver_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIEditorObserver */
#define NS_IEDITOROBSERVER_IID_STR "e52a09fd-d33a-4f85-be0a-fbd348f0fa27"

#define NS_IEDITOROBSERVER_IID \
  {0xe52a09fd, 0xd33a, 0x4f85, \
    { 0xbe, 0x0a, 0xfb, 0xd3, 0x48, 0xf0, 0xfa, 0x27 }}

class NS_NO_VTABLE nsIEditorObserver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITOROBSERVER_IID)

  /* void EditAction (); */
  NS_IMETHOD EditAction(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorObserver, NS_IEDITOROBSERVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITOROBSERVER \
  NS_IMETHOD EditAction(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITOROBSERVER(_to) \
  NS_IMETHOD EditAction(void) { return _to EditAction(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITOROBSERVER(_to) \
  NS_IMETHOD EditAction(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EditAction(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorObserver : public nsIEditorObserver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITOROBSERVER

  nsEditorObserver();

private:
  ~nsEditorObserver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditorObserver, nsIEditorObserver)

nsEditorObserver::nsEditorObserver()
{
  /* member initializers and constructor code */
}

nsEditorObserver::~nsEditorObserver()
{
  /* destructor code */
}

/* void EditAction (); */
NS_IMETHODIMP nsEditorObserver::EditAction()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorObserver_h__ */
