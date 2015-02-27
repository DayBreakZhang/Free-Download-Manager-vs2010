/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIConsoleListener.idl
 */

#ifndef __gen_nsIConsoleListener_h__
#define __gen_nsIConsoleListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIConsoleMessage; /* forward declaration */


/* starting interface:    nsIConsoleListener */
#define NS_ICONSOLELISTENER_IID_STR "35c400a4-5792-438c-b915-65e30d58d557"

#define NS_ICONSOLELISTENER_IID \
  {0x35c400a4, 0x5792, 0x438c, \
    { 0xb9, 0x15, 0x65, 0xe3, 0x0d, 0x58, 0xd5, 0x57 }}

class NS_NO_VTABLE nsIConsoleListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONSOLELISTENER_IID)

  /* void observe (in nsIConsoleMessage aMessage); */
  NS_IMETHOD Observe(nsIConsoleMessage *aMessage) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIConsoleListener, NS_ICONSOLELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONSOLELISTENER \
  NS_IMETHOD Observe(nsIConsoleMessage *aMessage); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONSOLELISTENER(_to) \
  NS_IMETHOD Observe(nsIConsoleMessage *aMessage) { return _to Observe(aMessage); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONSOLELISTENER(_to) \
  NS_IMETHOD Observe(nsIConsoleMessage *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->Observe(aMessage); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsConsoleListener : public nsIConsoleListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONSOLELISTENER

  nsConsoleListener();

private:
  ~nsConsoleListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsConsoleListener, nsIConsoleListener)

nsConsoleListener::nsConsoleListener()
{
  /* member initializers and constructor code */
}

nsConsoleListener::~nsConsoleListener()
{
  /* destructor code */
}

/* void observe (in nsIConsoleMessage aMessage); */
NS_IMETHODIMP nsConsoleListener::Observe(nsIConsoleMessage *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIConsoleListener_h__ */
