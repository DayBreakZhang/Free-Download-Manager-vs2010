/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/html/content/public/nsIMenuBuilder.idl
 */

#ifndef __gen_nsIMenuBuilder_h__
#define __gen_nsIMenuBuilder_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLMenuItemElement; /* forward declaration */


/* starting interface:    nsIMenuBuilder */
#define NS_IMENUBUILDER_IID_STR "12724737-f7db-43b4-94ab-708a7b86e115"

#define NS_IMENUBUILDER_IID \
  {0x12724737, 0xf7db, 0x43b4, \
    { 0x94, 0xab, 0x70, 0x8a, 0x7b, 0x86, 0xe1, 0x15 }}

class NS_NO_VTABLE nsIMenuBuilder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMENUBUILDER_IID)

  /* void openContainer (in DOMString aLabel); */
  NS_IMETHOD OpenContainer(const nsAString & aLabel) = 0;

  /* void addItemFor (in nsIDOMHTMLMenuItemElement aElement, in boolean aCanLoadIcon); */
  NS_IMETHOD AddItemFor(nsIDOMHTMLMenuItemElement *aElement, bool aCanLoadIcon) = 0;

  /* void addSeparator (); */
  NS_IMETHOD AddSeparator(void) = 0;

  /* void undoAddSeparator (); */
  NS_IMETHOD UndoAddSeparator(void) = 0;

  /* void closeContainer (); */
  NS_IMETHOD CloseContainer(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMenuBuilder, NS_IMENUBUILDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMENUBUILDER \
  NS_IMETHOD OpenContainer(const nsAString & aLabel); \
  NS_IMETHOD AddItemFor(nsIDOMHTMLMenuItemElement *aElement, bool aCanLoadIcon); \
  NS_IMETHOD AddSeparator(void); \
  NS_IMETHOD UndoAddSeparator(void); \
  NS_IMETHOD CloseContainer(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMENUBUILDER(_to) \
  NS_IMETHOD OpenContainer(const nsAString & aLabel) { return _to OpenContainer(aLabel); } \
  NS_IMETHOD AddItemFor(nsIDOMHTMLMenuItemElement *aElement, bool aCanLoadIcon) { return _to AddItemFor(aElement, aCanLoadIcon); } \
  NS_IMETHOD AddSeparator(void) { return _to AddSeparator(); } \
  NS_IMETHOD UndoAddSeparator(void) { return _to UndoAddSeparator(); } \
  NS_IMETHOD CloseContainer(void) { return _to CloseContainer(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMENUBUILDER(_to) \
  NS_IMETHOD OpenContainer(const nsAString & aLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->OpenContainer(aLabel); } \
  NS_IMETHOD AddItemFor(nsIDOMHTMLMenuItemElement *aElement, bool aCanLoadIcon) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddItemFor(aElement, aCanLoadIcon); } \
  NS_IMETHOD AddSeparator(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSeparator(); } \
  NS_IMETHOD UndoAddSeparator(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->UndoAddSeparator(); } \
  NS_IMETHOD CloseContainer(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CloseContainer(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMenuBuilder : public nsIMenuBuilder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMENUBUILDER

  nsMenuBuilder();

private:
  ~nsMenuBuilder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMenuBuilder, nsIMenuBuilder)

nsMenuBuilder::nsMenuBuilder()
{
  /* member initializers and constructor code */
}

nsMenuBuilder::~nsMenuBuilder()
{
  /* destructor code */
}

/* void openContainer (in DOMString aLabel); */
NS_IMETHODIMP nsMenuBuilder::OpenContainer(const nsAString & aLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addItemFor (in nsIDOMHTMLMenuItemElement aElement, in boolean aCanLoadIcon); */
NS_IMETHODIMP nsMenuBuilder::AddItemFor(nsIDOMHTMLMenuItemElement *aElement, bool aCanLoadIcon)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSeparator (); */
NS_IMETHODIMP nsMenuBuilder::AddSeparator()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void undoAddSeparator (); */
NS_IMETHODIMP nsMenuBuilder::UndoAddSeparator()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void closeContainer (); */
NS_IMETHODIMP nsMenuBuilder::CloseContainer()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMenuBuilder_h__ */
