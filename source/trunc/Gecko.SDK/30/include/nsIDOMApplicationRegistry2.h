/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMApplicationRegistry2.idl
 */

#ifndef __gen_nsIDOMApplicationRegistry2_h__
#define __gen_nsIDOMApplicationRegistry2_h__


#ifndef __gen_nsIDOMApplicationRegistry_h__
#include "nsIDOMApplicationRegistry.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMRequest; /* forward declaration */


/* starting interface:    mozIDOMApplicationRegistry2 */
#define MOZIDOMAPPLICATIONREGISTRY2_IID_STR "5bd838b2-cf3d-406e-bbef-f633cf9e68de"

#define MOZIDOMAPPLICATIONREGISTRY2_IID \
  {0x5bd838b2, 0xcf3d, 0x406e, \
    { 0xbb, 0xef, 0xf6, 0x33, 0xcf, 0x9e, 0x68, 0xde }}

class NS_NO_VTABLE mozIDOMApplicationRegistry2 : public mozIDOMApplicationRegistry {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIDOMAPPLICATIONREGISTRY2_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIDOMApplicationRegistry2, MOZIDOMAPPLICATIONREGISTRY2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIDOMAPPLICATIONREGISTRY2 \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIDOMAPPLICATIONREGISTRY2(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIDOMAPPLICATIONREGISTRY2(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public mozIDOMApplicationRegistry2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_MOZIDOMAPPLICATIONREGISTRY2

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, mozIDOMApplicationRegistry2)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMApplicationRegistry2_h__ */
