/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISAXLexicalHandler.idl
 */

#ifndef __gen_nsISAXLexicalHandler_h__
#define __gen_nsISAXLexicalHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXLexicalHandler */
#define NS_ISAXLEXICALHANDLER_IID_STR "23c26a56-adff-440c-8caf-95c2dc2e399b"

#define NS_ISAXLEXICALHANDLER_IID \
  {0x23c26a56, 0xadff, 0x440c, \
    { 0x8c, 0xaf, 0x95, 0xc2, 0xdc, 0x2e, 0x39, 0x9b }}

class NS_NO_VTABLE nsISAXLexicalHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXLEXICALHANDLER_IID)

  /* void comment (in AString chars); */
  NS_IMETHOD Comment(const nsAString & chars) = 0;

  /* void startDTD (in AString name, in AString publicId, in AString systemId); */
  NS_IMETHOD StartDTD(const nsAString & name, const nsAString & publicId, const nsAString & systemId) = 0;

  /* void endDTD (); */
  NS_IMETHOD EndDTD(void) = 0;

  /* void startCDATA (); */
  NS_IMETHOD StartCDATA(void) = 0;

  /* void endCDATA (); */
  NS_IMETHOD EndCDATA(void) = 0;

  /* void startEntity (in AString name); */
  NS_IMETHOD StartEntity(const nsAString & name) = 0;

  /* void endEntity (in AString name); */
  NS_IMETHOD EndEntity(const nsAString & name) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXLexicalHandler, NS_ISAXLEXICALHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXLEXICALHANDLER \
  NS_IMETHOD Comment(const nsAString & chars); \
  NS_IMETHOD StartDTD(const nsAString & name, const nsAString & publicId, const nsAString & systemId); \
  NS_IMETHOD EndDTD(void); \
  NS_IMETHOD StartCDATA(void); \
  NS_IMETHOD EndCDATA(void); \
  NS_IMETHOD StartEntity(const nsAString & name); \
  NS_IMETHOD EndEntity(const nsAString & name); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXLEXICALHANDLER(_to) \
  NS_IMETHOD Comment(const nsAString & chars) { return _to Comment(chars); } \
  NS_IMETHOD StartDTD(const nsAString & name, const nsAString & publicId, const nsAString & systemId) { return _to StartDTD(name, publicId, systemId); } \
  NS_IMETHOD EndDTD(void) { return _to EndDTD(); } \
  NS_IMETHOD StartCDATA(void) { return _to StartCDATA(); } \
  NS_IMETHOD EndCDATA(void) { return _to EndCDATA(); } \
  NS_IMETHOD StartEntity(const nsAString & name) { return _to StartEntity(name); } \
  NS_IMETHOD EndEntity(const nsAString & name) { return _to EndEntity(name); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXLEXICALHANDLER(_to) \
  NS_IMETHOD Comment(const nsAString & chars) { return !_to ? NS_ERROR_NULL_POINTER : _to->Comment(chars); } \
  NS_IMETHOD StartDTD(const nsAString & name, const nsAString & publicId, const nsAString & systemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartDTD(name, publicId, systemId); } \
  NS_IMETHOD EndDTD(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndDTD(); } \
  NS_IMETHOD StartCDATA(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartCDATA(); } \
  NS_IMETHOD EndCDATA(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndCDATA(); } \
  NS_IMETHOD StartEntity(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->StartEntity(name); } \
  NS_IMETHOD EndEntity(const nsAString & name) { return !_to ? NS_ERROR_NULL_POINTER : _to->EndEntity(name); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXLexicalHandler : public nsISAXLexicalHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXLEXICALHANDLER

  nsSAXLexicalHandler();

private:
  ~nsSAXLexicalHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXLexicalHandler, nsISAXLexicalHandler)

nsSAXLexicalHandler::nsSAXLexicalHandler()
{
  /* member initializers and constructor code */
}

nsSAXLexicalHandler::~nsSAXLexicalHandler()
{
  /* destructor code */
}

/* void comment (in AString chars); */
NS_IMETHODIMP nsSAXLexicalHandler::Comment(const nsAString & chars)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startDTD (in AString name, in AString publicId, in AString systemId); */
NS_IMETHODIMP nsSAXLexicalHandler::StartDTD(const nsAString & name, const nsAString & publicId, const nsAString & systemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endDTD (); */
NS_IMETHODIMP nsSAXLexicalHandler::EndDTD()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startCDATA (); */
NS_IMETHODIMP nsSAXLexicalHandler::StartCDATA()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endCDATA (); */
NS_IMETHODIMP nsSAXLexicalHandler::EndCDATA()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void startEntity (in AString name); */
NS_IMETHODIMP nsSAXLexicalHandler::StartEntity(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void endEntity (in AString name); */
NS_IMETHODIMP nsSAXLexicalHandler::EndEntity(const nsAString & name)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXLexicalHandler_h__ */
