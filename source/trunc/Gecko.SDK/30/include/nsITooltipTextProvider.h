/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsITooltipTextProvider.idl
 */

#ifndef __gen_nsITooltipTextProvider_h__
#define __gen_nsITooltipTextProvider_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMNode; /* forward declaration */


/* starting interface:    nsITooltipTextProvider */
#define NS_ITOOLTIPTEXTPROVIDER_IID_STR "b128a1e6-44f3-4331-8fbe-5af360ff21ee"

#define NS_ITOOLTIPTEXTPROVIDER_IID \
  {0xb128a1e6, 0x44f3, 0x4331, \
    { 0x8f, 0xbe, 0x5a, 0xf3, 0x60, 0xff, 0x21, 0xee }}

class NS_NO_VTABLE nsITooltipTextProvider : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOOLTIPTEXTPROVIDER_IID)

  /* boolean getNodeText (in nsIDOMNode aNode, out wstring aText); */
  NS_IMETHOD GetNodeText(nsIDOMNode *aNode, char16_t * *aText, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITooltipTextProvider, NS_ITOOLTIPTEXTPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOOLTIPTEXTPROVIDER \
  NS_IMETHOD GetNodeText(nsIDOMNode *aNode, char16_t * *aText, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOOLTIPTEXTPROVIDER(_to) \
  NS_IMETHOD GetNodeText(nsIDOMNode *aNode, char16_t * *aText, bool *_retval) { return _to GetNodeText(aNode, aText, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOOLTIPTEXTPROVIDER(_to) \
  NS_IMETHOD GetNodeText(nsIDOMNode *aNode, char16_t * *aText, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNodeText(aNode, aText, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTooltipTextProvider : public nsITooltipTextProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOOLTIPTEXTPROVIDER

  nsTooltipTextProvider();

private:
  ~nsTooltipTextProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTooltipTextProvider, nsITooltipTextProvider)

nsTooltipTextProvider::nsTooltipTextProvider()
{
  /* member initializers and constructor code */
}

nsTooltipTextProvider::~nsTooltipTextProvider()
{
  /* destructor code */
}

/* boolean getNodeText (in nsIDOMNode aNode, out wstring aText); */
NS_IMETHODIMP nsTooltipTextProvider::GetNodeText(nsIDOMNode *aNode, char16_t * *aText, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITooltipTextProvider_h__ */
