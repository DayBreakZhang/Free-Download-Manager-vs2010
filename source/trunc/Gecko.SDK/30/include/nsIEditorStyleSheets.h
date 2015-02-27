/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIEditorStyleSheets.idl
 */

#ifndef __gen_nsIEditorStyleSheets_h__
#define __gen_nsIEditorStyleSheets_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsCSSStyleSheet;

/* starting interface:    nsIEditorStyleSheets */
#define NS_IEDITORSTYLESHEETS_IID_STR "4805e682-49b9-11d3-9ce4-ed60bd6cb5bc"

#define NS_IEDITORSTYLESHEETS_IID \
  {0x4805e682, 0x49b9, 0x11d3, \
    { 0x9c, 0xe4, 0xed, 0x60, 0xbd, 0x6c, 0xb5, 0xbc }}

class NS_NO_VTABLE nsIEditorStyleSheets : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEDITORSTYLESHEETS_IID)

  /* void replaceStyleSheet (in AString aURL); */
  NS_IMETHOD ReplaceStyleSheet(const nsAString & aURL) = 0;

  /* void addStyleSheet (in AString aURL); */
  NS_IMETHOD AddStyleSheet(const nsAString & aURL) = 0;

  /* void replaceOverrideStyleSheet (in AString aURL); */
  NS_IMETHOD ReplaceOverrideStyleSheet(const nsAString & aURL) = 0;

  /* void addOverrideStyleSheet (in AString aURL); */
  NS_IMETHOD AddOverrideStyleSheet(const nsAString & aURL) = 0;

  /* void removeStyleSheet (in AString aURL); */
  NS_IMETHOD RemoveStyleSheet(const nsAString & aURL) = 0;

  /* void removeOverrideStyleSheet (in AString aURL); */
  NS_IMETHOD RemoveOverrideStyleSheet(const nsAString & aURL) = 0;

  /* void enableStyleSheet (in AString aURL, in boolean aEnable); */
  NS_IMETHOD EnableStyleSheet(const nsAString & aURL, bool aEnable) = 0;

  /* [noscript] nsCSSStyleSheet getStyleSheetForURL (in AString aURL); */
  NS_IMETHOD GetStyleSheetForURL(const nsAString & aURL, nsCSSStyleSheet **_retval) = 0;

  /* [noscript] AString getURLForStyleSheet (in nsCSSStyleSheet aStyleSheet); */
  NS_IMETHOD GetURLForStyleSheet(nsCSSStyleSheet *aStyleSheet, nsAString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEditorStyleSheets, NS_IEDITORSTYLESHEETS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEDITORSTYLESHEETS \
  NS_IMETHOD ReplaceStyleSheet(const nsAString & aURL); \
  NS_IMETHOD AddStyleSheet(const nsAString & aURL); \
  NS_IMETHOD ReplaceOverrideStyleSheet(const nsAString & aURL); \
  NS_IMETHOD AddOverrideStyleSheet(const nsAString & aURL); \
  NS_IMETHOD RemoveStyleSheet(const nsAString & aURL); \
  NS_IMETHOD RemoveOverrideStyleSheet(const nsAString & aURL); \
  NS_IMETHOD EnableStyleSheet(const nsAString & aURL, bool aEnable); \
  NS_IMETHOD GetStyleSheetForURL(const nsAString & aURL, nsCSSStyleSheet **_retval); \
  NS_IMETHOD GetURLForStyleSheet(nsCSSStyleSheet *aStyleSheet, nsAString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEDITORSTYLESHEETS(_to) \
  NS_IMETHOD ReplaceStyleSheet(const nsAString & aURL) { return _to ReplaceStyleSheet(aURL); } \
  NS_IMETHOD AddStyleSheet(const nsAString & aURL) { return _to AddStyleSheet(aURL); } \
  NS_IMETHOD ReplaceOverrideStyleSheet(const nsAString & aURL) { return _to ReplaceOverrideStyleSheet(aURL); } \
  NS_IMETHOD AddOverrideStyleSheet(const nsAString & aURL) { return _to AddOverrideStyleSheet(aURL); } \
  NS_IMETHOD RemoveStyleSheet(const nsAString & aURL) { return _to RemoveStyleSheet(aURL); } \
  NS_IMETHOD RemoveOverrideStyleSheet(const nsAString & aURL) { return _to RemoveOverrideStyleSheet(aURL); } \
  NS_IMETHOD EnableStyleSheet(const nsAString & aURL, bool aEnable) { return _to EnableStyleSheet(aURL, aEnable); } \
  NS_IMETHOD GetStyleSheetForURL(const nsAString & aURL, nsCSSStyleSheet **_retval) { return _to GetStyleSheetForURL(aURL, _retval); } \
  NS_IMETHOD GetURLForStyleSheet(nsCSSStyleSheet *aStyleSheet, nsAString & _retval) { return _to GetURLForStyleSheet(aStyleSheet, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEDITORSTYLESHEETS(_to) \
  NS_IMETHOD ReplaceStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceStyleSheet(aURL); } \
  NS_IMETHOD AddStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddStyleSheet(aURL); } \
  NS_IMETHOD ReplaceOverrideStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReplaceOverrideStyleSheet(aURL); } \
  NS_IMETHOD AddOverrideStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddOverrideStyleSheet(aURL); } \
  NS_IMETHOD RemoveStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveStyleSheet(aURL); } \
  NS_IMETHOD RemoveOverrideStyleSheet(const nsAString & aURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveOverrideStyleSheet(aURL); } \
  NS_IMETHOD EnableStyleSheet(const nsAString & aURL, bool aEnable) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnableStyleSheet(aURL, aEnable); } \
  NS_IMETHOD GetStyleSheetForURL(const nsAString & aURL, nsCSSStyleSheet **_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStyleSheetForURL(aURL, _retval); } \
  NS_IMETHOD GetURLForStyleSheet(nsCSSStyleSheet *aStyleSheet, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURLForStyleSheet(aStyleSheet, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEditorStyleSheets : public nsIEditorStyleSheets
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEDITORSTYLESHEETS

  nsEditorStyleSheets();

private:
  ~nsEditorStyleSheets();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEditorStyleSheets, nsIEditorStyleSheets)

nsEditorStyleSheets::nsEditorStyleSheets()
{
  /* member initializers and constructor code */
}

nsEditorStyleSheets::~nsEditorStyleSheets()
{
  /* destructor code */
}

/* void replaceStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::ReplaceStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::AddStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void replaceOverrideStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::ReplaceOverrideStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addOverrideStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::AddOverrideStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::RemoveStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeOverrideStyleSheet (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::RemoveOverrideStyleSheet(const nsAString & aURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void enableStyleSheet (in AString aURL, in boolean aEnable); */
NS_IMETHODIMP nsEditorStyleSheets::EnableStyleSheet(const nsAString & aURL, bool aEnable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] nsCSSStyleSheet getStyleSheetForURL (in AString aURL); */
NS_IMETHODIMP nsEditorStyleSheets::GetStyleSheetForURL(const nsAString & aURL, nsCSSStyleSheet **_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] AString getURLForStyleSheet (in nsCSSStyleSheet aStyleSheet); */
NS_IMETHODIMP nsEditorStyleSheets::GetURLForStyleSheet(nsCSSStyleSheet *aStyleSheet, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEditorStyleSheets_h__ */
