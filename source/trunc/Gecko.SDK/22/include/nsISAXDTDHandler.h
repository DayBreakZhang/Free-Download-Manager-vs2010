/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/parser/xml/public/nsISAXDTDHandler.idl
 */

#ifndef __gen_nsISAXDTDHandler_h__
#define __gen_nsISAXDTDHandler_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISAXDTDHandler */
#define NS_ISAXDTDHANDLER_IID_STR "4d01f225-6cc5-11da-be43-001422106990"

#define NS_ISAXDTDHANDLER_IID \
  {0x4d01f225, 0x6cc5, 0x11da, \
    { 0xbe, 0x43, 0x00, 0x14, 0x22, 0x10, 0x69, 0x90 }}

class NS_NO_VTABLE nsISAXDTDHandler : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISAXDTDHANDLER_IID)

  /* void notationDecl (in AString name, in AString publicId, in AString systemId); */
  NS_IMETHOD NotationDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId) = 0;

  /* void unparsedEntityDecl (in AString name, in AString publicId, in AString systemId, in AString notationName); */
  NS_IMETHOD UnparsedEntityDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId, const nsAString & notationName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISAXDTDHandler, NS_ISAXDTDHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISAXDTDHANDLER \
  NS_IMETHOD NotationDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId); \
  NS_IMETHOD UnparsedEntityDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId, const nsAString & notationName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISAXDTDHANDLER(_to) \
  NS_IMETHOD NotationDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId) { return _to NotationDecl(name, publicId, systemId); } \
  NS_IMETHOD UnparsedEntityDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId, const nsAString & notationName) { return _to UnparsedEntityDecl(name, publicId, systemId, notationName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISAXDTDHANDLER(_to) \
  NS_IMETHOD NotationDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotationDecl(name, publicId, systemId); } \
  NS_IMETHOD UnparsedEntityDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId, const nsAString & notationName) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnparsedEntityDecl(name, publicId, systemId, notationName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSAXDTDHandler : public nsISAXDTDHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISAXDTDHANDLER

  nsSAXDTDHandler();

private:
  ~nsSAXDTDHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSAXDTDHandler, nsISAXDTDHandler)

nsSAXDTDHandler::nsSAXDTDHandler()
{
  /* member initializers and constructor code */
}

nsSAXDTDHandler::~nsSAXDTDHandler()
{
  /* destructor code */
}

/* void notationDecl (in AString name, in AString publicId, in AString systemId); */
NS_IMETHODIMP nsSAXDTDHandler::NotationDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unparsedEntityDecl (in AString name, in AString publicId, in AString systemId, in AString notationName); */
NS_IMETHODIMP nsSAXDTDHandler::UnparsedEntityDecl(const nsAString & name, const nsAString & publicId, const nsAString & systemId, const nsAString & notationName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISAXDTDHandler_h__ */
