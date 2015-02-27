/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/components/satchel/public/nsIInputListAutoComplete.idl
 */

#ifndef __gen_nsIInputListAutoComplete_h__
#define __gen_nsIInputListAutoComplete_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAutoCompleteResult; /* forward declaration */

class nsIDOMHTMLInputElement; /* forward declaration */


/* starting interface:    nsIInputListAutoComplete */
#define NS_IINPUTLISTAUTOCOMPLETE_IID_STR "9e7ba3eb-a9cf-4861-93e0-82e93d836f7a"

#define NS_IINPUTLISTAUTOCOMPLETE_IID \
  {0x9e7ba3eb, 0xa9cf, 0x4861, \
    { 0x93, 0xe0, 0x82, 0xe9, 0x3d, 0x83, 0x6f, 0x7a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIInputListAutoComplete : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IINPUTLISTAUTOCOMPLETE_IID)

  /**
   * Generate results for a form input autocomplete menu.
   */
  /* nsIAutoCompleteResult autoCompleteSearch (in nsIAutoCompleteResult aResult, in AString aSearchString, in nsIDOMHTMLInputElement aField); */
  NS_SCRIPTABLE NS_IMETHOD AutoCompleteSearch(nsIAutoCompleteResult *aResult, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIInputListAutoComplete, NS_IINPUTLISTAUTOCOMPLETE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIINPUTLISTAUTOCOMPLETE \
  NS_SCRIPTABLE NS_IMETHOD AutoCompleteSearch(nsIAutoCompleteResult *aResult, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIINPUTLISTAUTOCOMPLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD AutoCompleteSearch(nsIAutoCompleteResult *aResult, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult **_retval NS_OUTPARAM) { return _to AutoCompleteSearch(aResult, aSearchString, aField, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIINPUTLISTAUTOCOMPLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD AutoCompleteSearch(nsIAutoCompleteResult *aResult, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoCompleteSearch(aResult, aSearchString, aField, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsInputListAutoComplete : public nsIInputListAutoComplete
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIINPUTLISTAUTOCOMPLETE

  nsInputListAutoComplete();

private:
  ~nsInputListAutoComplete();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsInputListAutoComplete, nsIInputListAutoComplete)

nsInputListAutoComplete::nsInputListAutoComplete()
{
  /* member initializers and constructor code */
}

nsInputListAutoComplete::~nsInputListAutoComplete()
{
  /* destructor code */
}

/* nsIAutoCompleteResult autoCompleteSearch (in nsIAutoCompleteResult aResult, in AString aSearchString, in nsIDOMHTMLInputElement aField); */
NS_IMETHODIMP nsInputListAutoComplete::AutoCompleteSearch(nsIAutoCompleteResult *aResult, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIInputListAutoComplete_h__ */
