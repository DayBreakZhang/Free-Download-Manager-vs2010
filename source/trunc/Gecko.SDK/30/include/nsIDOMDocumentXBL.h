/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDocumentXBL.idl
 */

#ifndef __gen_nsIDOMDocumentXBL_h__
#define __gen_nsIDOMDocumentXBL_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDocumentXBL */
#define NS_IDOMDOCUMENTXBL_IID_STR "af628000-e3fa-40d2-9118-fbaa9f3ec6b9"

#define NS_IDOMDOCUMENTXBL_IID \
  {0xaf628000, 0xe3fa, 0x40d2, \
    { 0x91, 0x18, 0xfb, 0xaa, 0x9f, 0x3e, 0xc6, 0xb9 }}

class NS_NO_VTABLE nsIDOMDocumentXBL : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTXBL_IID)

  /* nsIDOMNodeList getAnonymousNodes (in nsIDOMElement elt); */
  NS_IMETHOD GetAnonymousNodes(nsIDOMElement *elt, nsIDOMNodeList * *_retval) = 0;

  /* nsIDOMElement getAnonymousElementByAttribute (in nsIDOMElement elt, in DOMString attrName, in DOMString attrValue); */
  NS_IMETHOD GetAnonymousElementByAttribute(nsIDOMElement *elt, const nsAString & attrName, const nsAString & attrValue, nsIDOMElement * *_retval) = 0;

  /* nsIDOMElement getBindingParent (in nsIDOMNode node); */
  NS_IMETHOD GetBindingParent(nsIDOMNode *node, nsIDOMElement * *_retval) = 0;

  /* void loadBindingDocument (in DOMString documentURL); */
  NS_IMETHOD LoadBindingDocument(const nsAString & documentURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentXBL, NS_IDOMDOCUMENTXBL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTXBL \
  NS_IMETHOD GetAnonymousNodes(nsIDOMElement *elt, nsIDOMNodeList * *_retval); \
  NS_IMETHOD GetAnonymousElementByAttribute(nsIDOMElement *elt, const nsAString & attrName, const nsAString & attrValue, nsIDOMElement * *_retval); \
  NS_IMETHOD GetBindingParent(nsIDOMNode *node, nsIDOMElement * *_retval); \
  NS_IMETHOD LoadBindingDocument(const nsAString & documentURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTXBL(_to) \
  NS_IMETHOD GetAnonymousNodes(nsIDOMElement *elt, nsIDOMNodeList * *_retval) { return _to GetAnonymousNodes(elt, _retval); } \
  NS_IMETHOD GetAnonymousElementByAttribute(nsIDOMElement *elt, const nsAString & attrName, const nsAString & attrValue, nsIDOMElement * *_retval) { return _to GetAnonymousElementByAttribute(elt, attrName, attrValue, _retval); } \
  NS_IMETHOD GetBindingParent(nsIDOMNode *node, nsIDOMElement * *_retval) { return _to GetBindingParent(node, _retval); } \
  NS_IMETHOD LoadBindingDocument(const nsAString & documentURL) { return _to LoadBindingDocument(documentURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTXBL(_to) \
  NS_IMETHOD GetAnonymousNodes(nsIDOMElement *elt, nsIDOMNodeList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnonymousNodes(elt, _retval); } \
  NS_IMETHOD GetAnonymousElementByAttribute(nsIDOMElement *elt, const nsAString & attrName, const nsAString & attrValue, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnonymousElementByAttribute(elt, attrName, attrValue, _retval); } \
  NS_IMETHOD GetBindingParent(nsIDOMNode *node, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBindingParent(node, _retval); } \
  NS_IMETHOD LoadBindingDocument(const nsAString & documentURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadBindingDocument(documentURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentXBL : public nsIDOMDocumentXBL
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTXBL

  nsDOMDocumentXBL();

private:
  ~nsDOMDocumentXBL();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDocumentXBL, nsIDOMDocumentXBL)

nsDOMDocumentXBL::nsDOMDocumentXBL()
{
  /* member initializers and constructor code */
}

nsDOMDocumentXBL::~nsDOMDocumentXBL()
{
  /* destructor code */
}

/* nsIDOMNodeList getAnonymousNodes (in nsIDOMElement elt); */
NS_IMETHODIMP nsDOMDocumentXBL::GetAnonymousNodes(nsIDOMElement *elt, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getAnonymousElementByAttribute (in nsIDOMElement elt, in DOMString attrName, in DOMString attrValue); */
NS_IMETHODIMP nsDOMDocumentXBL::GetAnonymousElementByAttribute(nsIDOMElement *elt, const nsAString & attrName, const nsAString & attrValue, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getBindingParent (in nsIDOMNode node); */
NS_IMETHODIMP nsDOMDocumentXBL::GetBindingParent(nsIDOMNode *node, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadBindingDocument (in DOMString documentURL); */
NS_IMETHODIMP nsDOMDocumentXBL::LoadBindingDocument(const nsAString & documentURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocumentXBL_h__ */
