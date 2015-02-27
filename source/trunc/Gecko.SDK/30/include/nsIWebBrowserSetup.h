/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebBrowserSetup.idl
 */

#ifndef __gen_nsIWebBrowserSetup_h__
#define __gen_nsIWebBrowserSetup_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWebBrowserSetup */
#define NS_IWEBBROWSERSETUP_IID_STR "f15398a0-8018-11d3-af70-00a024ffc08c"

#define NS_IWEBBROWSERSETUP_IID \
  {0xf15398a0, 0x8018, 0x11d3, \
    { 0xaf, 0x70, 0x00, 0xa0, 0x24, 0xff, 0xc0, 0x8c }}

class NS_NO_VTABLE nsIWebBrowserSetup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERSETUP_IID)

  enum {
    SETUP_ALLOW_PLUGINS = 1U,
    SETUP_ALLOW_JAVASCRIPT = 2U,
    SETUP_ALLOW_META_REDIRECTS = 3U,
    SETUP_ALLOW_SUBFRAMES = 4U,
    SETUP_ALLOW_IMAGES = 5U,
    SETUP_FOCUS_DOC_BEFORE_CONTENT = 6U,
    SETUP_USE_GLOBAL_HISTORY = 256U,
    SETUP_IS_CHROME_WRAPPER = 7U,
    SETUP_ALLOW_DNS_PREFETCH = 8U
  };

  /* void setProperty (in unsigned long aId, in unsigned long aValue); */
  NS_IMETHOD SetProperty(uint32_t aId, uint32_t aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserSetup, NS_IWEBBROWSERSETUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERSETUP \
  NS_IMETHOD SetProperty(uint32_t aId, uint32_t aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERSETUP(_to) \
  NS_IMETHOD SetProperty(uint32_t aId, uint32_t aValue) { return _to SetProperty(aId, aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERSETUP(_to) \
  NS_IMETHOD SetProperty(uint32_t aId, uint32_t aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProperty(aId, aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserSetup : public nsIWebBrowserSetup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERSETUP

  nsWebBrowserSetup();

private:
  ~nsWebBrowserSetup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserSetup, nsIWebBrowserSetup)

nsWebBrowserSetup::nsWebBrowserSetup()
{
  /* member initializers and constructor code */
}

nsWebBrowserSetup::~nsWebBrowserSetup()
{
  /* destructor code */
}

/* void setProperty (in unsigned long aId, in unsigned long aValue); */
NS_IMETHODIMP nsWebBrowserSetup::SetProperty(uint32_t aId, uint32_t aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowserSetup_h__ */
