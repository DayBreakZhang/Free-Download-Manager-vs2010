/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/parser/html/nsIParserUtils.idl
 */

#ifndef __gen_nsIParserUtils_h__
#define __gen_nsIParserUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */

class nsIDOMDocumentFragment; /* forward declaration */

class nsIURI; /* forward declaration */


/* starting interface:    nsIParserUtils */
#define NS_IPARSERUTILS_IID_STR "a1101145-0025-411e-8873-fdf57bf28128"

#define NS_IPARSERUTILS_IID \
  {0xa1101145, 0x0025, 0x411e, \
    { 0x88, 0x73, 0xfd, 0xf5, 0x7b, 0xf2, 0x81, 0x28 }}

class NS_NO_VTABLE nsIParserUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPARSERUTILS_IID)

  enum {
    SanitizerAllowComments = 1U,
    SanitizerAllowStyle = 2U,
    SanitizerCidEmbedsOnly = 4U,
    SanitizerDropNonCSSPresentation = 8U,
    SanitizerDropForms = 16U,
    SanitizerDropMedia = 32U
  };

  /* AString sanitize (in AString src, in unsigned long flags); */
  NS_IMETHOD Sanitize(const nsAString & src, uint32_t flags, nsAString & _retval) = 0;

  /* AString convertToPlainText (in AString src, in unsigned long flags, in unsigned long wrapCol); */
  NS_IMETHOD ConvertToPlainText(const nsAString & src, uint32_t flags, uint32_t wrapCol, nsAString & _retval) = 0;

  /* nsIDOMDocumentFragment parseFragment (in AString fragment, in unsigned long flags, in boolean isXML, in nsIURI baseURI, in nsIDOMElement element); */
  NS_IMETHOD ParseFragment(const nsAString & fragment, uint32_t flags, bool isXML, nsIURI *baseURI, nsIDOMElement *element, nsIDOMDocumentFragment * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIParserUtils, NS_IPARSERUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPARSERUTILS \
  NS_IMETHOD Sanitize(const nsAString & src, uint32_t flags, nsAString & _retval); \
  NS_IMETHOD ConvertToPlainText(const nsAString & src, uint32_t flags, uint32_t wrapCol, nsAString & _retval); \
  NS_IMETHOD ParseFragment(const nsAString & fragment, uint32_t flags, bool isXML, nsIURI *baseURI, nsIDOMElement *element, nsIDOMDocumentFragment * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPARSERUTILS(_to) \
  NS_IMETHOD Sanitize(const nsAString & src, uint32_t flags, nsAString & _retval) { return _to Sanitize(src, flags, _retval); } \
  NS_IMETHOD ConvertToPlainText(const nsAString & src, uint32_t flags, uint32_t wrapCol, nsAString & _retval) { return _to ConvertToPlainText(src, flags, wrapCol, _retval); } \
  NS_IMETHOD ParseFragment(const nsAString & fragment, uint32_t flags, bool isXML, nsIURI *baseURI, nsIDOMElement *element, nsIDOMDocumentFragment * *_retval) { return _to ParseFragment(fragment, flags, isXML, baseURI, element, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPARSERUTILS(_to) \
  NS_IMETHOD Sanitize(const nsAString & src, uint32_t flags, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Sanitize(src, flags, _retval); } \
  NS_IMETHOD ConvertToPlainText(const nsAString & src, uint32_t flags, uint32_t wrapCol, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ConvertToPlainText(src, flags, wrapCol, _retval); } \
  NS_IMETHOD ParseFragment(const nsAString & fragment, uint32_t flags, bool isXML, nsIURI *baseURI, nsIDOMElement *element, nsIDOMDocumentFragment * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ParseFragment(fragment, flags, isXML, baseURI, element, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsParserUtils : public nsIParserUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPARSERUTILS

  nsParserUtils();

private:
  ~nsParserUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsParserUtils, nsIParserUtils)

nsParserUtils::nsParserUtils()
{
  /* member initializers and constructor code */
}

nsParserUtils::~nsParserUtils()
{
  /* destructor code */
}

/* AString sanitize (in AString src, in unsigned long flags); */
NS_IMETHODIMP nsParserUtils::Sanitize(const nsAString & src, uint32_t flags, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString convertToPlainText (in AString src, in unsigned long flags, in unsigned long wrapCol); */
NS_IMETHODIMP nsParserUtils::ConvertToPlainText(const nsAString & src, uint32_t flags, uint32_t wrapCol, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentFragment parseFragment (in AString fragment, in unsigned long flags, in boolean isXML, in nsIURI baseURI, in nsIDOMElement element); */
NS_IMETHODIMP nsParserUtils::ParseFragment(const nsAString & fragment, uint32_t flags, bool isXML, nsIURI *baseURI, nsIDOMElement *element, nsIDOMDocumentFragment * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_PARSERUTILS_CONTRACTID \
    "@mozilla.org/parserutils;1"
#define NS_PARSERUTILS_CID  \
{ 0xaf7b24cb, 0x893f, 0x41bb, { 0x96, 0x1f, 0x5a, 0x69, 0x38, 0x8e, 0x27, 0xc3 } }

#endif /* __gen_nsIParserUtils_h__ */
