/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDocumentFragment.idl
 */

#ifndef __gen_nsIDOMDocumentFragment_h__
#define __gen_nsIDOMDocumentFragment_h__


#ifndef __gen_nsIDOMNode_h__
#include "nsIDOMNode.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDocumentFragment */
#define NS_IDOMDOCUMENTFRAGMENT_IID_STR "75a237af-133e-40f0-8196-2a172867c41a"

#define NS_IDOMDOCUMENTFRAGMENT_IID \
  {0x75a237af, 0x133e, 0x40f0, \
    { 0x81, 0x96, 0x2a, 0x17, 0x28, 0x67, 0xc4, 0x1a }}

class NS_NO_VTABLE nsIDOMDocumentFragment : public nsIDOMNode {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOCUMENTFRAGMENT_IID)

  /* nsIDOMElement querySelector ([Null (Stringify)] in DOMString selectors); */
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) = 0;

  /* nsIDOMNodeList querySelectorAll ([Null (Stringify)] in DOMString selectors); */
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDocumentFragment, NS_IDOMDOCUMENTFRAGMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOCUMENTFRAGMENT \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval); \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOCUMENTFRAGMENT(_to) \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) { return _to QuerySelector(selectors, _retval); } \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) { return _to QuerySelectorAll(selectors, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOCUMENTFRAGMENT(_to) \
  NS_IMETHOD QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->QuerySelector(selectors, _retval); } \
  NS_IMETHOD QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->QuerySelectorAll(selectors, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDocumentFragment : public nsIDOMDocumentFragment
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOCUMENTFRAGMENT

  nsDOMDocumentFragment();

private:
  ~nsDOMDocumentFragment();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDocumentFragment, nsIDOMDocumentFragment)

nsDOMDocumentFragment::nsDOMDocumentFragment()
{
  /* member initializers and constructor code */
}

nsDOMDocumentFragment::~nsDOMDocumentFragment()
{
  /* destructor code */
}

/* nsIDOMElement querySelector ([Null (Stringify)] in DOMString selectors); */
NS_IMETHODIMP nsDOMDocumentFragment::QuerySelector(const nsAString & selectors, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNodeList querySelectorAll ([Null (Stringify)] in DOMString selectors); */
NS_IMETHODIMP nsDOMDocumentFragment::QuerySelectorAll(const nsAString & selectors, nsIDOMNodeList * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDocumentFragment_h__ */
