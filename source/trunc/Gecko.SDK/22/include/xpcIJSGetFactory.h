/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/js/xpconnect/idl/xpcIJSGetFactory.idl
 */

#ifndef __gen_xpcIJSGetFactory_h__
#define __gen_xpcIJSGetFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIFactory; /* forward declaration */


/* starting interface:    xpcIJSGetFactory */
#define XPCIJSGETFACTORY_IID_STR "3fe0c205-d75b-4cac-9347-d2b855050143"

#define XPCIJSGETFACTORY_IID \
  {0x3fe0c205, 0xd75b, 0x4cac, \
    { 0x93, 0x47, 0xd2, 0xb8, 0x55, 0x05, 0x01, 0x43 }}

class NS_NO_VTABLE xpcIJSGetFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(XPCIJSGETFACTORY_IID)

  /* nsIFactory get (in nsCIDRef aCID); */
  NS_IMETHOD Get(const nsCID & aCID, nsIFactory * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(xpcIJSGetFactory, XPCIJSGETFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_XPCIJSGETFACTORY \
  NS_IMETHOD Get(const nsCID & aCID, nsIFactory * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_XPCIJSGETFACTORY(_to) \
  NS_IMETHOD Get(const nsCID & aCID, nsIFactory * *_retval) { return _to Get(aCID, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_XPCIJSGETFACTORY(_to) \
  NS_IMETHOD Get(const nsCID & aCID, nsIFactory * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aCID, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public xpcIJSGetFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_XPCIJSGETFACTORY

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, xpcIJSGetFactory)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* nsIFactory get (in nsCIDRef aCID); */
NS_IMETHODIMP _MYCLASS_::Get(const nsCID & aCID, nsIFactory * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_xpcIJSGetFactory_h__ */
