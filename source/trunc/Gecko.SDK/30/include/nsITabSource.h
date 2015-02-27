/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITabSource.idl
 */

#ifndef __gen_nsITabSource_h__
#define __gen_nsITabSource_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIDOMWindow_h__
#include "nsIDOMWindow.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsITabSource */
#define NS_ITABSOURCE_IID_STR "ff9c0e45-4646-45ec-b2f0-3b16d9e41875"

#define NS_ITABSOURCE_IID \
  {0xff9c0e45, 0x4646, 0x45ec, \
    { 0xb2, 0xf0, 0x3b, 0x16, 0xd9, 0xe4, 0x18, 0x75 }}

class NS_NO_VTABLE nsITabSource : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITABSOURCE_IID)

  /* nsIDOMWindow getTabToStream (); */
  NS_IMETHOD GetTabToStream(nsIDOMWindow * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITabSource, NS_ITABSOURCE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITABSOURCE \
  NS_IMETHOD GetTabToStream(nsIDOMWindow * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITABSOURCE(_to) \
  NS_IMETHOD GetTabToStream(nsIDOMWindow * *_retval) { return _to GetTabToStream(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITABSOURCE(_to) \
  NS_IMETHOD GetTabToStream(nsIDOMWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabToStream(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTabSource : public nsITabSource
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITABSOURCE

  nsTabSource();

private:
  ~nsTabSource();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTabSource, nsITabSource)

nsTabSource::nsTabSource()
{
  /* member initializers and constructor code */
}

nsTabSource::~nsTabSource()
{
  /* destructor code */
}

/* nsIDOMWindow getTabToStream (); */
NS_IMETHODIMP nsTabSource::GetTabToStream(nsIDOMWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_TABSOURCESERVICE_CONTRACTID "@mozilla.org/tab-source-service;1"

#endif /* __gen_nsITabSource_h__ */
