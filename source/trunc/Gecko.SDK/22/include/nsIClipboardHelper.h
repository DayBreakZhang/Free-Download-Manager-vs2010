/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/widget/nsIClipboardHelper.idl
 */

#ifndef __gen_nsIClipboardHelper_h__
#define __gen_nsIClipboardHelper_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIClipboard_h__
#include "nsIClipboard.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsString.h" // needed for AString -> nsAString, unfortunately
class nsIDOMDocument; /* forward declaration */


/* starting interface:    nsIClipboardHelper */
#define NS_ICLIPBOARDHELPER_IID_STR "c9d5a750-c3a8-11e1-9b21-0800200c9a66"

#define NS_ICLIPBOARDHELPER_IID \
  {0xc9d5a750, 0xc3a8, 0x11e1, \
    { 0x9b, 0x21, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE nsIClipboardHelper : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICLIPBOARDHELPER_IID)

  /* void copyStringToClipboard (in AString aString, in long aClipboardID, [optional] in nsIDOMDocument aDoc); */
  NS_IMETHOD CopyStringToClipboard(const nsAString & aString, int32_t aClipboardID, nsIDOMDocument *aDoc) = 0;

  /* void copyString (in AString aString, [optional] in nsIDOMDocument aDoc); */
  NS_IMETHOD CopyString(const nsAString & aString, nsIDOMDocument *aDoc) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIClipboardHelper, NS_ICLIPBOARDHELPER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICLIPBOARDHELPER \
  NS_IMETHOD CopyStringToClipboard(const nsAString & aString, int32_t aClipboardID, nsIDOMDocument *aDoc); \
  NS_IMETHOD CopyString(const nsAString & aString, nsIDOMDocument *aDoc); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICLIPBOARDHELPER(_to) \
  NS_IMETHOD CopyStringToClipboard(const nsAString & aString, int32_t aClipboardID, nsIDOMDocument *aDoc) { return _to CopyStringToClipboard(aString, aClipboardID, aDoc); } \
  NS_IMETHOD CopyString(const nsAString & aString, nsIDOMDocument *aDoc) { return _to CopyString(aString, aDoc); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICLIPBOARDHELPER(_to) \
  NS_IMETHOD CopyStringToClipboard(const nsAString & aString, int32_t aClipboardID, nsIDOMDocument *aDoc) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyStringToClipboard(aString, aClipboardID, aDoc); } \
  NS_IMETHOD CopyString(const nsAString & aString, nsIDOMDocument *aDoc) { return !_to ? NS_ERROR_NULL_POINTER : _to->CopyString(aString, aDoc); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsClipboardHelper : public nsIClipboardHelper
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICLIPBOARDHELPER

  nsClipboardHelper();

private:
  ~nsClipboardHelper();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsClipboardHelper, nsIClipboardHelper)

nsClipboardHelper::nsClipboardHelper()
{
  /* member initializers and constructor code */
}

nsClipboardHelper::~nsClipboardHelper()
{
  /* destructor code */
}

/* void copyStringToClipboard (in AString aString, in long aClipboardID, [optional] in nsIDOMDocument aDoc); */
NS_IMETHODIMP nsClipboardHelper::CopyStringToClipboard(const nsAString & aString, int32_t aClipboardID, nsIDOMDocument *aDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void copyString (in AString aString, [optional] in nsIDOMDocument aDoc); */
NS_IMETHODIMP nsClipboardHelper::CopyString(const nsAString & aString, nsIDOMDocument *aDoc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIClipboardHelper_h__ */
