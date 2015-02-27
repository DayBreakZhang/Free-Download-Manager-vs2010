/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/protocol/http/nsIHttpHeaderVisitor.idl
 */

#ifndef __gen_nsIHttpHeaderVisitor_h__
#define __gen_nsIHttpHeaderVisitor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHttpHeaderVisitor */
#define NS_IHTTPHEADERVISITOR_IID_STR "35412859-b9d9-423c-8866-2d4559fdd2be"

#define NS_IHTTPHEADERVISITOR_IID \
  {0x35412859, 0xb9d9, 0x423c, \
    { 0x88, 0x66, 0x2d, 0x45, 0x59, 0xfd, 0xd2, 0xbe }}

class NS_NO_VTABLE nsIHttpHeaderVisitor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPHEADERVISITOR_IID)

  /* void visitHeader (in ACString aHeader, in ACString aValue); */
  NS_IMETHOD VisitHeader(const nsACString & aHeader, const nsACString & aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpHeaderVisitor, NS_IHTTPHEADERVISITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPHEADERVISITOR \
  NS_IMETHOD VisitHeader(const nsACString & aHeader, const nsACString & aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPHEADERVISITOR(_to) \
  NS_IMETHOD VisitHeader(const nsACString & aHeader, const nsACString & aValue) { return _to VisitHeader(aHeader, aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPHEADERVISITOR(_to) \
  NS_IMETHOD VisitHeader(const nsACString & aHeader, const nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->VisitHeader(aHeader, aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpHeaderVisitor : public nsIHttpHeaderVisitor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPHEADERVISITOR

  nsHttpHeaderVisitor();

private:
  ~nsHttpHeaderVisitor();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpHeaderVisitor, nsIHttpHeaderVisitor)

nsHttpHeaderVisitor::nsHttpHeaderVisitor()
{
  /* member initializers and constructor code */
}

nsHttpHeaderVisitor::~nsHttpHeaderVisitor()
{
  /* destructor code */
}

/* void visitHeader (in ACString aHeader, in ACString aValue); */
NS_IMETHODIMP nsHttpHeaderVisitor::VisitHeader(const nsACString & aHeader, const nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpHeaderVisitor_h__ */
