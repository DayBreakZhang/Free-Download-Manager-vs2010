/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHTMLMenu.idl
 */

#ifndef __gen_nsIHTMLMenu_h__
#define __gen_nsIHTMLMenu_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMenuBuilder; /* forward declaration */


/* starting interface:    nsIHTMLMenu */
#define NS_IHTMLMENU_IID_STR "d3d068d8-e223-4228-ba39-4d6df21ba616"

#define NS_IHTMLMENU_IID \
  {0xd3d068d8, 0xe223, 0x4228, \
    { 0xba, 0x39, 0x4d, 0x6d, 0xf2, 0x1b, 0xa6, 0x16 }}

class NS_NO_VTABLE nsIHTMLMenu : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTMLMENU_IID)

  /* void sendShowEvent (); */
  NS_IMETHOD SendShowEvent(void) = 0;

  /* nsIMenuBuilder createBuilder (); */
  NS_IMETHOD CreateBuilder(nsIMenuBuilder * *_retval) = 0;

  /* void build (in nsIMenuBuilder aBuilder); */
  NS_IMETHOD Build(nsIMenuBuilder *aBuilder) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHTMLMenu, NS_IHTMLMENU_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTMLMENU \
  NS_IMETHOD SendShowEvent(void); \
  NS_IMETHOD CreateBuilder(nsIMenuBuilder * *_retval); \
  NS_IMETHOD Build(nsIMenuBuilder *aBuilder); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTMLMENU(_to) \
  NS_IMETHOD SendShowEvent(void) { return _to SendShowEvent(); } \
  NS_IMETHOD CreateBuilder(nsIMenuBuilder * *_retval) { return _to CreateBuilder(_retval); } \
  NS_IMETHOD Build(nsIMenuBuilder *aBuilder) { return _to Build(aBuilder); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTMLMENU(_to) \
  NS_IMETHOD SendShowEvent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendShowEvent(); } \
  NS_IMETHOD CreateBuilder(nsIMenuBuilder * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateBuilder(_retval); } \
  NS_IMETHOD Build(nsIMenuBuilder *aBuilder) { return !_to ? NS_ERROR_NULL_POINTER : _to->Build(aBuilder); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHTMLMenu : public nsIHTMLMenu
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTMLMENU

  nsHTMLMenu();

private:
  ~nsHTMLMenu();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHTMLMenu, nsIHTMLMenu)

nsHTMLMenu::nsHTMLMenu()
{
  /* member initializers and constructor code */
}

nsHTMLMenu::~nsHTMLMenu()
{
  /* destructor code */
}

/* void sendShowEvent (); */
NS_IMETHODIMP nsHTMLMenu::SendShowEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIMenuBuilder createBuilder (); */
NS_IMETHODIMP nsHTMLMenu::CreateBuilder(nsIMenuBuilder * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void build (in nsIMenuBuilder aBuilder); */
NS_IMETHODIMP nsHTMLMenu::Build(nsIMenuBuilder *aBuilder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHTMLMenu_h__ */
