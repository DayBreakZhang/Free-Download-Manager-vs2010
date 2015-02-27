/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMDOMImplementation.idl
 */

#ifndef __gen_nsIDOMDOMImplementation_h__
#define __gen_nsIDOMDOMImplementation_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDOMImplementation */
#define NS_IDOMDOMIMPLEMENTATION_IID_STR "03a6f574-99ec-42f8-9e6c-812a4a9bcbf7"

#define NS_IDOMDOMIMPLEMENTATION_IID \
  {0x03a6f574, 0x99ec, 0x42f8, \
    { 0x9e, 0x6c, 0x81, 0x2a, 0x4a, 0x9b, 0xcb, 0xf7 }}

class NS_NO_VTABLE nsIDOMDOMImplementation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMIMPLEMENTATION_IID)

  /* boolean hasFeature (in DOMString feature, in DOMString version); */
  NS_IMETHOD HasFeature(const nsAString & feature, const nsAString & version, bool *_retval) = 0;

  /* nsIDOMDocumentType createDocumentType (in DOMString qualifiedName, in DOMString publicId, in DOMString systemId) raises (DOMException); */
  NS_IMETHOD CreateDocumentType(const nsAString & qualifiedName, const nsAString & publicId, const nsAString & systemId, nsIDOMDocumentType * *_retval) = 0;

  /* nsIDOMDocument createDocument (in DOMString namespaceURI, in DOMString qualifiedName, in nsIDOMDocumentType doctype) raises (DOMException); */
  NS_IMETHOD CreateDocument(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMDocumentType *doctype, nsIDOMDocument * *_retval) = 0;

  /* nsIDOMDocument createHTMLDocument ([Null (Stringify)] in DOMString title); */
  NS_IMETHOD CreateHTMLDocument(const nsAString & title, nsIDOMDocument * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMImplementation, NS_IDOMDOMIMPLEMENTATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMIMPLEMENTATION \
  NS_IMETHOD HasFeature(const nsAString & feature, const nsAString & version, bool *_retval); \
  NS_IMETHOD CreateDocumentType(const nsAString & qualifiedName, const nsAString & publicId, const nsAString & systemId, nsIDOMDocumentType * *_retval); \
  NS_IMETHOD CreateDocument(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMDocumentType *doctype, nsIDOMDocument * *_retval); \
  NS_IMETHOD CreateHTMLDocument(const nsAString & title, nsIDOMDocument * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMIMPLEMENTATION(_to) \
  NS_IMETHOD HasFeature(const nsAString & feature, const nsAString & version, bool *_retval) { return _to HasFeature(feature, version, _retval); } \
  NS_IMETHOD CreateDocumentType(const nsAString & qualifiedName, const nsAString & publicId, const nsAString & systemId, nsIDOMDocumentType * *_retval) { return _to CreateDocumentType(qualifiedName, publicId, systemId, _retval); } \
  NS_IMETHOD CreateDocument(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMDocumentType *doctype, nsIDOMDocument * *_retval) { return _to CreateDocument(namespaceURI, qualifiedName, doctype, _retval); } \
  NS_IMETHOD CreateHTMLDocument(const nsAString & title, nsIDOMDocument * *_retval) { return _to CreateHTMLDocument(title, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMIMPLEMENTATION(_to) \
  NS_IMETHOD HasFeature(const nsAString & feature, const nsAString & version, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasFeature(feature, version, _retval); } \
  NS_IMETHOD CreateDocumentType(const nsAString & qualifiedName, const nsAString & publicId, const nsAString & systemId, nsIDOMDocumentType * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateDocumentType(qualifiedName, publicId, systemId, _retval); } \
  NS_IMETHOD CreateDocument(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMDocumentType *doctype, nsIDOMDocument * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateDocument(namespaceURI, qualifiedName, doctype, _retval); } \
  NS_IMETHOD CreateHTMLDocument(const nsAString & title, nsIDOMDocument * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateHTMLDocument(title, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMImplementation : public nsIDOMDOMImplementation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMIMPLEMENTATION

  nsDOMDOMImplementation();

private:
  ~nsDOMDOMImplementation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMImplementation, nsIDOMDOMImplementation)

nsDOMDOMImplementation::nsDOMDOMImplementation()
{
  /* member initializers and constructor code */
}

nsDOMDOMImplementation::~nsDOMDOMImplementation()
{
  /* destructor code */
}

/* boolean hasFeature (in DOMString feature, in DOMString version); */
NS_IMETHODIMP nsDOMDOMImplementation::HasFeature(const nsAString & feature, const nsAString & version, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocumentType createDocumentType (in DOMString qualifiedName, in DOMString publicId, in DOMString systemId) raises (DOMException); */
NS_IMETHODIMP nsDOMDOMImplementation::CreateDocumentType(const nsAString & qualifiedName, const nsAString & publicId, const nsAString & systemId, nsIDOMDocumentType * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument createDocument (in DOMString namespaceURI, in DOMString qualifiedName, in nsIDOMDocumentType doctype) raises (DOMException); */
NS_IMETHODIMP nsDOMDOMImplementation::CreateDocument(const nsAString & namespaceURI, const nsAString & qualifiedName, nsIDOMDocumentType *doctype, nsIDOMDocument * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDocument createHTMLDocument ([Null (Stringify)] in DOMString title); */
NS_IMETHODIMP nsDOMDOMImplementation::CreateHTMLDocument(const nsAString & title, nsIDOMDocument * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMImplementation_h__ */
