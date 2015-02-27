/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/js/src/xpconnect/idl/nsIXPCScriptNotify.idl
 */

#ifndef __gen_nsIXPCScriptNotify_h__
#define __gen_nsIXPCScriptNotify_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIXPCScriptNotify */
#define NS_IXPCSCRIPTNOTIFY_IID_STR "13aceb15-812a-476a-9326-2adc00250b76"

#define NS_IXPCSCRIPTNOTIFY_IID \
  {0x13aceb15, 0x812a, 0x476a, \
    { 0x93, 0x26, 0x2a, 0xdc, 0x00, 0x25, 0x0b, 0x76 }}

class NS_NO_VTABLE nsIXPCScriptNotify : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXPCSCRIPTNOTIFY_IID)

  /**
     * Method invoked when a script has been executed by XPConnect
     */
  /* void ScriptExecuted (); */
  NS_IMETHOD ScriptExecuted(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXPCScriptNotify, NS_IXPCSCRIPTNOTIFY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXPCSCRIPTNOTIFY \
  NS_IMETHOD ScriptExecuted(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXPCSCRIPTNOTIFY(_to) \
  NS_IMETHOD ScriptExecuted(void) { return _to ScriptExecuted(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXPCSCRIPTNOTIFY(_to) \
  NS_IMETHOD ScriptExecuted(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptExecuted(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXPCScriptNotify : public nsIXPCScriptNotify
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXPCSCRIPTNOTIFY

  nsXPCScriptNotify();

private:
  ~nsXPCScriptNotify();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXPCScriptNotify, nsIXPCScriptNotify)

nsXPCScriptNotify::nsXPCScriptNotify()
{
  /* member initializers and constructor code */
}

nsXPCScriptNotify::~nsXPCScriptNotify()
{
  /* destructor code */
}

/* void ScriptExecuted (); */
NS_IMETHODIMP nsXPCScriptNotify::ScriptExecuted()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXPCScriptNotify_h__ */
