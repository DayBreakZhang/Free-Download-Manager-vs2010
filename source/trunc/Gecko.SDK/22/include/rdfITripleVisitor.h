/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/rdf/base/idl/rdfITripleVisitor.idl
 */

#ifndef __gen_rdfITripleVisitor_h__
#define __gen_rdfITripleVisitor_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRDFResource; /* forward declaration */

class nsIRDFNode; /* forward declaration */


/* starting interface:    rdfITripleVisitor */
#define RDFITRIPLEVISITOR_IID_STR "aafea151-c271-4505-9978-a100d292800c"

#define RDFITRIPLEVISITOR_IID \
  {0xaafea151, 0xc271, 0x4505, \
    { 0x99, 0x78, 0xa1, 0x00, 0xd2, 0x92, 0x80, 0x0c }}

class NS_NO_VTABLE rdfITripleVisitor : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(RDFITRIPLEVISITOR_IID)

  /* void visit (in nsIRDFNode aSubject, in nsIRDFResource aPredicate, in nsIRDFNode aObject, in boolean aTruthValue); */
  NS_IMETHOD Visit(nsIRDFNode *aSubject, nsIRDFResource *aPredicate, nsIRDFNode *aObject, bool aTruthValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(rdfITripleVisitor, RDFITRIPLEVISITOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_RDFITRIPLEVISITOR \
  NS_IMETHOD Visit(nsIRDFNode *aSubject, nsIRDFResource *aPredicate, nsIRDFNode *aObject, bool aTruthValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_RDFITRIPLEVISITOR(_to) \
  NS_IMETHOD Visit(nsIRDFNode *aSubject, nsIRDFResource *aPredicate, nsIRDFNode *aObject, bool aTruthValue) { return _to Visit(aSubject, aPredicate, aObject, aTruthValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_RDFITRIPLEVISITOR(_to) \
  NS_IMETHOD Visit(nsIRDFNode *aSubject, nsIRDFResource *aPredicate, nsIRDFNode *aObject, bool aTruthValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->Visit(aSubject, aPredicate, aObject, aTruthValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public rdfITripleVisitor
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_RDFITRIPLEVISITOR

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, rdfITripleVisitor)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void visit (in nsIRDFNode aSubject, in nsIRDFResource aPredicate, in nsIRDFNode aObject, in boolean aTruthValue); */
NS_IMETHODIMP _MYCLASS_::Visit(nsIRDFNode *aSubject, nsIRDFResource *aPredicate, nsIRDFNode *aObject, bool aTruthValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_rdfITripleVisitor_h__ */
