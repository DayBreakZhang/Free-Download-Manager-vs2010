/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/apps/nsIDOMApplicationRegistry2.idl
 */

#ifndef __gen_nsIDOMApplicationRegistry2_h__
#define __gen_nsIDOMApplicationRegistry2_h__


#ifndef __gen_nsIDOMApplicationRegistry_h__
#include "nsIDOMApplicationRegistry.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMRequest; /* forward declaration */


/* starting interface:    mozIDOMApplicationRegistry2 */
#define MOZIDOMAPPLICATIONREGISTRY2_IID_STR "34498a66-3aee-4b80-8b8b-a9c5d5ba32b6"

#define MOZIDOMAPPLICATIONREGISTRY2_IID \
  {0x34498a66, 0x3aee, 0x4b80, \
    { 0x8b, 0x8b, 0xa9, 0xc5, 0xd5, 0xba, 0x32, 0xb6 }}

class NS_NO_VTABLE mozIDOMApplicationRegistry2 : public mozIDOMApplicationRegistry {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(MOZIDOMAPPLICATIONREGISTRY2_IID)

  /* nsIDOMDOMRequest installPackage (in DOMString packageUrl, [optional] in jsval parameters); */
  NS_IMETHOD InstallPackage(const nsAString & packageUrl, const JS::Value & parameters, nsIDOMDOMRequest * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(mozIDOMApplicationRegistry2, MOZIDOMAPPLICATIONREGISTRY2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_MOZIDOMAPPLICATIONREGISTRY2 \
  NS_IMETHOD InstallPackage(const nsAString & packageUrl, const JS::Value & parameters, nsIDOMDOMRequest * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_MOZIDOMAPPLICATIONREGISTRY2(_to) \
  NS_IMETHOD InstallPackage(const nsAString & packageUrl, const JS::Value & parameters, nsIDOMDOMRequest * *_retval) { return _to InstallPackage(packageUrl, parameters, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_MOZIDOMAPPLICATIONREGISTRY2(_to) \
  NS_IMETHOD InstallPackage(const nsAString & packageUrl, const JS::Value & parameters, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InstallPackage(packageUrl, parameters, _retval); } 

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

/* nsIDOMDOMRequest installPackage (in DOMString packageUrl, [optional] in jsval parameters); */
NS_IMETHODIMP _MYCLASS_::InstallPackage(const nsAString & packageUrl, const JS::Value & parameters, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMApplicationRegistry2_h__ */
