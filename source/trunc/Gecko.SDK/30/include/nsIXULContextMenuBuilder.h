/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIXULContextMenuBuilder.idl
 */

#ifndef __gen_nsIXULContextMenuBuilder_h__
#define __gen_nsIXULContextMenuBuilder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDocumentFragment; /* forward declaration */


/* starting interface:    nsIXULContextMenuBuilder */
#define NS_IXULCONTEXTMENUBUILDER_IID_STR "eb6b42c0-2f1c-4760-b5ca-bdc9b3ec77d4"

#define NS_IXULCONTEXTMENUBUILDER_IID \
  {0xeb6b42c0, 0x2f1c, 0x4760, \
    { 0xb5, 0xca, 0xbd, 0xc9, 0xb3, 0xec, 0x77, 0xd4 }}

class NS_NO_VTABLE nsIXULContextMenuBuilder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IXULCONTEXTMENUBUILDER_IID)

  /* void init (in nsIDOMDocumentFragment aDocumentFragment, in AString aGeneratedItemIdAttrName); */
  NS_IMETHOD Init(nsIDOMDocumentFragment *aDocumentFragment, const nsAString & aGeneratedItemIdAttrName) = 0;

  /* void click (in DOMString aGeneratedItemId); */
  NS_IMETHOD Click(const nsAString & aGeneratedItemId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIXULContextMenuBuilder, NS_IXULCONTEXTMENUBUILDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIXULCONTEXTMENUBUILDER \
  NS_IMETHOD Init(nsIDOMDocumentFragment *aDocumentFragment, const nsAString & aGeneratedItemIdAttrName); \
  NS_IMETHOD Click(const nsAString & aGeneratedItemId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIXULCONTEXTMENUBUILDER(_to) \
  NS_IMETHOD Init(nsIDOMDocumentFragment *aDocumentFragment, const nsAString & aGeneratedItemIdAttrName) { return _to Init(aDocumentFragment, aGeneratedItemIdAttrName); } \
  NS_IMETHOD Click(const nsAString & aGeneratedItemId) { return _to Click(aGeneratedItemId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIXULCONTEXTMENUBUILDER(_to) \
  NS_IMETHOD Init(nsIDOMDocumentFragment *aDocumentFragment, const nsAString & aGeneratedItemIdAttrName) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aDocumentFragment, aGeneratedItemIdAttrName); } \
  NS_IMETHOD Click(const nsAString & aGeneratedItemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->Click(aGeneratedItemId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsXULContextMenuBuilder : public nsIXULContextMenuBuilder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIXULCONTEXTMENUBUILDER

  nsXULContextMenuBuilder();

private:
  ~nsXULContextMenuBuilder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsXULContextMenuBuilder, nsIXULContextMenuBuilder)

nsXULContextMenuBuilder::nsXULContextMenuBuilder()
{
  /* member initializers and constructor code */
}

nsXULContextMenuBuilder::~nsXULContextMenuBuilder()
{
  /* destructor code */
}

/* void init (in nsIDOMDocumentFragment aDocumentFragment, in AString aGeneratedItemIdAttrName); */
NS_IMETHODIMP nsXULContextMenuBuilder::Init(nsIDOMDocumentFragment *aDocumentFragment, const nsAString & aGeneratedItemIdAttrName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void click (in DOMString aGeneratedItemId); */
NS_IMETHODIMP nsXULContextMenuBuilder::Click(const nsAString & aGeneratedItemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIXULContextMenuBuilder_h__ */
