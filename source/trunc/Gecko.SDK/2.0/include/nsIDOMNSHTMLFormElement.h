/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/html/nsIDOMNSHTMLFormElement.idl
 */

#ifndef __gen_nsIDOMNSHTMLFormElement_h__
#define __gen_nsIDOMNSHTMLFormElement_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMFormData; /* forward declaration */


/* starting interface:    nsIDOMNSHTMLFormElement */
#define NS_IDOMNSHTMLFORMELEMENT_IID_STR "d38a782f-f33c-4a8d-85a9-0d5da3650064"

#define NS_IDOMNSHTMLFORMELEMENT_IID \
  {0xd38a782f, 0xf33c, 0x4a8d, \
    { 0x85, 0xa9, 0x0d, 0x5d, 0xa3, 0x65, 0x00, 0x64 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMNSHTMLFormElement : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMNSHTMLFORMELEMENT_IID)

  /* attribute DOMString encoding; */
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) = 0;

  /* boolean checkValidity (); */
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMNSHTMLFormElement, NS_IDOMNSHTMLFORMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMNSHTMLFORMELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding); \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding); \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMNSHTMLFORMELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) { return _to GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) { return _to SetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return _to CheckValidity(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMNSHTMLFORMELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetEncoding(nsAString & aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD SetEncoding(const nsAString & aEncoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEncoding(aEncoding); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckValidity(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMNSHTMLFormElement : public nsIDOMNSHTMLFormElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMNSHTMLFORMELEMENT

  nsDOMNSHTMLFormElement();

private:
  ~nsDOMNSHTMLFormElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMNSHTMLFormElement, nsIDOMNSHTMLFormElement)

nsDOMNSHTMLFormElement::nsDOMNSHTMLFormElement()
{
  /* member initializers and constructor code */
}

nsDOMNSHTMLFormElement::~nsDOMNSHTMLFormElement()
{
  /* destructor code */
}

/* attribute DOMString encoding; */
NS_IMETHODIMP nsDOMNSHTMLFormElement::GetEncoding(nsAString & aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMNSHTMLFormElement::SetEncoding(const nsAString & aEncoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkValidity (); */
NS_IMETHODIMP nsDOMNSHTMLFormElement::CheckValidity(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMNSHTMLFormElement_h__ */
