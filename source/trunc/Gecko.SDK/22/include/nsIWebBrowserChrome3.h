/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/embedding/browser/webBrowser/nsIWebBrowserChrome3.idl
 */

#ifndef __gen_nsIWebBrowserChrome3_h__
#define __gen_nsIWebBrowserChrome3_h__


#ifndef __gen_nsIWebBrowserChrome2_h__
#include "nsIWebBrowserChrome2.h"
#endif

#ifndef __gen_nsIURI_h__
#include "nsIURI.h"
#endif

#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIWebBrowserChrome3 */
#define NS_IWEBBROWSERCHROME3_IID_STR "7f2aa813-b250-4e46-afeb-97b1e91bc9a5"

#define NS_IWEBBROWSERCHROME3_IID \
  {0x7f2aa813, 0xb250, 0x4e46, \
    { 0xaf, 0xeb, 0x97, 0xb1, 0xe9, 0x1b, 0xc9, 0xa5 }}

class NS_NO_VTABLE nsIWebBrowserChrome3 : public nsIWebBrowserChrome2 {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBBROWSERCHROME3_IID)

  /* AString onBeforeLinkTraversal (in AString originalTarget, in nsIURI linkURI, in nsIDOMNode linkNode, in boolean isAppTab); */
  NS_IMETHOD OnBeforeLinkTraversal(const nsAString & originalTarget, nsIURI *linkURI, nsIDOMNode *linkNode, bool isAppTab, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebBrowserChrome3, NS_IWEBBROWSERCHROME3_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBBROWSERCHROME3 \
  NS_IMETHOD OnBeforeLinkTraversal(const nsAString & originalTarget, nsIURI *linkURI, nsIDOMNode *linkNode, bool isAppTab, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBBROWSERCHROME3(_to) \
  NS_IMETHOD OnBeforeLinkTraversal(const nsAString & originalTarget, nsIURI *linkURI, nsIDOMNode *linkNode, bool isAppTab, nsAString & _retval) { return _to OnBeforeLinkTraversal(originalTarget, linkURI, linkNode, isAppTab, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBBROWSERCHROME3(_to) \
  NS_IMETHOD OnBeforeLinkTraversal(const nsAString & originalTarget, nsIURI *linkURI, nsIDOMNode *linkNode, bool isAppTab, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnBeforeLinkTraversal(originalTarget, linkURI, linkNode, isAppTab, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebBrowserChrome3 : public nsIWebBrowserChrome3
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBBROWSERCHROME3

  nsWebBrowserChrome3();

private:
  ~nsWebBrowserChrome3();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebBrowserChrome3, nsIWebBrowserChrome3)

nsWebBrowserChrome3::nsWebBrowserChrome3()
{
  /* member initializers and constructor code */
}

nsWebBrowserChrome3::~nsWebBrowserChrome3()
{
  /* destructor code */
}

/* AString onBeforeLinkTraversal (in AString originalTarget, in nsIURI linkURI, in nsIDOMNode linkNode, in boolean isAppTab); */
NS_IMETHODIMP nsWebBrowserChrome3::OnBeforeLinkTraversal(const nsAString & originalTarget, nsIURI *linkURI, nsIDOMNode *linkNode, bool isAppTab, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebBrowserChrome3_h__ */
