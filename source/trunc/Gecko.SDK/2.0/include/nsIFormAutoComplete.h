/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/toolkit/components/satchel/public/nsIFormAutoComplete.idl
 */

#ifndef __gen_nsIFormAutoComplete_h__
#define __gen_nsIFormAutoComplete_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAutoCompleteResult; /* forward declaration */

class nsIDOMHTMLInputElement; /* forward declaration */


/* starting interface:    nsIFormAutoComplete */
#define NS_IFORMAUTOCOMPLETE_IID_STR "997c0c05-5d1d-47e5-9cbc-765c0b8ec699"

#define NS_IFORMAUTOCOMPLETE_IID \
  {0x997c0c05, 0x5d1d, 0x47e5, \
    { 0x9c, 0xbc, 0x76, 0x5c, 0x0b, 0x8e, 0xc6, 0x99 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIFormAutoComplete : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IFORMAUTOCOMPLETE_IID)

  /**
     * Generate results for a form input autocomplete menu.
     */
  /* nsIAutoCompleteResult autoCompleteSearch (in AString aInputName, in AString aSearchString, in nsIDOMHTMLInputElement aField, in nsIAutoCompleteResult aPreviousResult); */
  NS_SCRIPTABLE NS_IMETHOD AutoCompleteSearch(const nsAString & aInputName, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult *aPreviousResult, nsIAutoCompleteResult **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIFormAutoComplete, NS_IFORMAUTOCOMPLETE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIFORMAUTOCOMPLETE \
  NS_SCRIPTABLE NS_IMETHOD AutoCompleteSearch(const nsAString & aInputName, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult *aPreviousResult, nsIAutoCompleteResult **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIFORMAUTOCOMPLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD AutoCompleteSearch(const nsAString & aInputName, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult *aPreviousResult, nsIAutoCompleteResult **_retval NS_OUTPARAM) { return _to AutoCompleteSearch(aInputName, aSearchString, aField, aPreviousResult, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIFORMAUTOCOMPLETE(_to) \
  NS_SCRIPTABLE NS_IMETHOD AutoCompleteSearch(const nsAString & aInputName, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult *aPreviousResult, nsIAutoCompleteResult **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AutoCompleteSearch(aInputName, aSearchString, aField, aPreviousResult, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsFormAutoComplete : public nsIFormAutoComplete
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIFORMAUTOCOMPLETE

  nsFormAutoComplete();

private:
  ~nsFormAutoComplete();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsFormAutoComplete, nsIFormAutoComplete)

nsFormAutoComplete::nsFormAutoComplete()
{
  /* member initializers and constructor code */
}

nsFormAutoComplete::~nsFormAutoComplete()
{
  /* destructor code */
}

/* nsIAutoCompleteResult autoCompleteSearch (in AString aInputName, in AString aSearchString, in nsIDOMHTMLInputElement aField, in nsIAutoCompleteResult aPreviousResult); */
NS_IMETHODIMP nsFormAutoComplete::AutoCompleteSearch(const nsAString & aInputName, const nsAString & aSearchString, nsIDOMHTMLInputElement *aField, nsIAutoCompleteResult *aPreviousResult, nsIAutoCompleteResult **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIFormAutoComplete_h__ */
