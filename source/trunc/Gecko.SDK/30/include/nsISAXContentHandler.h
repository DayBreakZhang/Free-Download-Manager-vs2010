/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISAXContentHandler.idl
 */

#ifndef __gen_nsISAXContentHandler_h__
#define __gen_nsISAXContentHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISAXAttributes; /* forward declaration */


/* starting interface:    nsISAXContentHandler */
#define NS_ISAXCONTENTHANDLER_IID_STR "2a99c757-dfee-4806-bff3-f721440412e0"

#define NS_ISAXCONTENTHANDLER_IID \
  {0x2a99c757, 0xdfee, 0x4806, \
    { 0xbf, 0xf3, 0xf7, 0x21, 0x44, 0x04, 0x12, 0xe0 }}

class NS_NO_VTABLE nsISAXContentHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXCONTENTHANDLER_IID)

  /* void startDocument (); */
  NS_IMETHOD StartDocument(void) = 0;

  /* void endDocument (); */
  NS_IMETHOD EndDocument(void) = 0;

  /* void startElement (in AString uri, in AString localName, in AString qName, in nsISAXAttributes attributes); */
  NS_IMETHOD StartElement(const nsAString & uri, const nsAString & localName, const nsAString & qName, nsISAXAttributes *attributes) = 0;

  /* void endElement (in AString uri, in AString localName, in AString qName); */
  NS_IMETHOD EndElement(const nsAString & uri, const nsAString & localName, const nsAString & qName) = 0;

  /* void characters (in AString value); */
  NS_IMETHOD Characters(const nsAString & value) = 0;

  /* void processingInstruction (in AString target, in AString data); */
  NS_IMETHOD ProcessingInstruction(const nsAString & target, const nsAString & data) = 0;

  /* void ignorableWhitespace (in AString whitespace); */
  NS_IMETHOD IgnorableWhitespace(const nsAString & whitespace) = 0;

  /* void startPrefixMapping (in AString prefix, in AString uri); */
  NS_IMETHOD StartPrefixMapping(const nsAString & prefix, const nsAString & uri) = 0;

  /* void endPrefixMapping (in AString prefix); */
  NS_IMETHOD EndPrefixMapping(const nsAString & prefix) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXContentHandler, NS_ISAXCONTENTHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXCONTENTHANDLER \
  NS_IMETHOD StartDocument(void); \
  NS_IMETHOD EndDocument(void); \
  NS_IMETHOD StartElement(const nsAString & uri, const nsAString & localName, const nsAString & qName, nsISAXAttributes *attributes); \
  NS_IMETHOD EndElement(const nsAString & uri, const nsAString & localName, const nsAString & qName); \
  NS_IMETHOD Characters(const nsAString & value); \
  NS_IMETHOD ProcessingInstruction(const nsAString & target, const nsAString & data); \
  NS_IMETHOD IgnorableWhitespace(const nsAString & whitespace); \
  NS_IMETHOD StartPrefixMapping(const nsAString & prefix, const nsAString & uri); \
  NS_IMETHOD EndPrefixMapping(const nsAString & prefix); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXCONTENTHANDLER(_to) \
  NS_IMETHOD StartDocument(void) { return _to StartDocument(); } \
  NS_IMETHOD EndDocument(void) { return _to EndDocument(); } \
  NS_IMETHOD StartElement(const nsAString & uri, const nsAString & localName, const nsAString & qName, nsISAXAttributes *attributes) { return _to StartElement(uri, localName, qName, attributes); } \
  NS_IMETHOD EndElement(const nsAString & uri, const nsAString & localName, const nsAString & qName) { return _to EndElement(uri, localName, qName); } \
  NS_IMETHOD Characters(const nsAString & value) { return _to Characters(value); } \
  NS_IMETHOD ProcessingInstruction(const nsAString & target, const nsAString & data) { return _to ProcessingInstruction(target, data); } \
  NS_IMETHOD IgnorableWhitespace(const nsAString & whitespace) { return _to IgnorableWhitespace(whitespace); } \
  NS_IMETHOD StartPrefixMapping(const nsAString & prefix, const nsAString & uri) { return _to StartPrefixMapping(prefix, uri); } \
  NS_IMETHOD EndPrefixMapping(const nsAString & prefix) { return _to EndPrefixMapping(prefix); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXCONTENTHANDLER(_to) \
  NS_IMETHOD StartDocument(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartDocument(); } \
  NS_IMETHOD EndDocument(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndDocument(); } \
  NS_IMETHOD StartElement(const nsAString & uri, const nsAString & localName, const nsAString & qName, nsISAXAttributes *attributes) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartElement(uri, localName, qName, attributes); } \
  NS_IMETHOD EndElement(const nsAString & uri, const nsAString & localName, const nsAString & qName) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndElement(uri, localName, qName); } \
  NS_IMETHOD Characters(const nsAString & value) { return !_to ? NS_ERROR_NULL_POINTER : _to->Characters(value); } \
  NS_IMETHOD ProcessingInstruction(const nsAString & target, const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessingInstruction(target, data); } \
  NS_IMETHOD IgnorableWhitespace(const nsAString & whitespace) { return !_to ? NS_ERROR_NULL_POINTER : _to->IgnorableWhitespace(whitespace); } \
  NS_IMETHOD StartPrefixMapping(const nsAString & prefix, const nsAString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartPrefixMapping(prefix, uri); } \
  NS_IMETHOD EndPrefixMapping(const nsAString & prefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndPrefixMapping(prefix); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXContentHandler : public nsISAXContentHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXCONTENTHANDLER

  nsSAXContentHandler();

private:
  ~nsSAXContentHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXContentHandler, nsISAXContentHandler)

nsSAXContentHandler::nsSAXContentHandler()
{
  /* member initializers and constructor code */
}

nsSAXContentHandler::~nsSAXContentHandler()
{
  /* destructor code */
}

/* void startDocument (); */
NS_IMETHODIMP nsSAXContentHandler::StartDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endDocument (); */
NS_IMETHODIMP nsSAXContentHandler::EndDocument()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startElement (in AString uri, in AString localName, in AString qName, in nsISAXAttributes attributes); */
NS_IMETHODIMP nsSAXContentHandler::StartElement(const nsAString & uri, const nsAString & localName, const nsAString & qName, nsISAXAttributes *attributes)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endElement (in AString uri, in AString localName, in AString qName); */
NS_IMETHODIMP nsSAXContentHandler::EndElement(const nsAString & uri, const nsAString & localName, const nsAString & qName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void characters (in AString value); */
NS_IMETHODIMP nsSAXContentHandler::Characters(const nsAString & value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void processingInstruction (in AString target, in AString data); */
NS_IMETHODIMP nsSAXContentHandler::ProcessingInstruction(const nsAString & target, const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ignorableWhitespace (in AString whitespace); */
NS_IMETHODIMP nsSAXContentHandler::IgnorableWhitespace(const nsAString & whitespace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startPrefixMapping (in AString prefix, in AString uri); */
NS_IMETHODIMP nsSAXContentHandler::StartPrefixMapping(const nsAString & prefix, const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endPrefixMapping (in AString prefix); */
NS_IMETHODIMP nsSAXContentHandler::EndPrefixMapping(const nsAString & prefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXContentHandler_h__ */
