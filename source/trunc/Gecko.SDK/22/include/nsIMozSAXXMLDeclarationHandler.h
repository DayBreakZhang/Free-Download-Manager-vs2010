/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/parser/xml/public/nsIMozSAXXMLDeclarationHandler.idl
 */

#ifndef __gen_nsIMozSAXXMLDeclarationHandler_h__
#define __gen_nsIMozSAXXMLDeclarationHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMozSAXXMLDeclarationHandler */
#define NS_IMOZSAXXMLDECLARATIONHANDLER_IID_STR "c0e461cb-0e5e-284c-b97d-cffeec467eba"

#define NS_IMOZSAXXMLDECLARATIONHANDLER_IID \
  {0xc0e461cb, 0x0e5e, 0x284c, \
    { 0xb9, 0x7d, 0xcf, 0xfe, 0xec, 0x46, 0x7e, 0xba }}

class NS_NO_VTABLE nsIMozSAXXMLDeclarationHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOZSAXXMLDECLARATIONHANDLER_IID)

  /* void handleXMLDeclaration (in AString version, in AString encoding, in boolean standalone); */
  NS_IMETHOD HandleXMLDeclaration(const nsAString & version, const nsAString & encoding, bool standalone) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMozSAXXMLDeclarationHandler, NS_IMOZSAXXMLDECLARATIONHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOZSAXXMLDECLARATIONHANDLER \
  NS_IMETHOD HandleXMLDeclaration(const nsAString & version, const nsAString & encoding, bool standalone); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOZSAXXMLDECLARATIONHANDLER(_to) \
  NS_IMETHOD HandleXMLDeclaration(const nsAString & version, const nsAString & encoding, bool standalone) { return _to HandleXMLDeclaration(version, encoding, standalone); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOZSAXXMLDECLARATIONHANDLER(_to) \
  NS_IMETHOD HandleXMLDeclaration(const nsAString & version, const nsAString & encoding, bool standalone) { return !_to ? NS_ERROR_NULL_POINTER : _to->HandleXMLDeclaration(version, encoding, standalone); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMozSAXXMLDeclarationHandler : public nsIMozSAXXMLDeclarationHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOZSAXXMLDECLARATIONHANDLER

  nsMozSAXXMLDeclarationHandler();

private:
  ~nsMozSAXXMLDeclarationHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMozSAXXMLDeclarationHandler, nsIMozSAXXMLDeclarationHandler)

nsMozSAXXMLDeclarationHandler::nsMozSAXXMLDeclarationHandler()
{
  /* member initializers and constructor code */
}

nsMozSAXXMLDeclarationHandler::~nsMozSAXXMLDeclarationHandler()
{
  /* destructor code */
}

/* void handleXMLDeclaration (in AString version, in AString encoding, in boolean standalone); */
NS_IMETHODIMP nsMozSAXXMLDeclarationHandler::HandleXMLDeclaration(const nsAString & version, const nsAString & encoding, bool standalone)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMozSAXXMLDeclarationHandler_h__ */
