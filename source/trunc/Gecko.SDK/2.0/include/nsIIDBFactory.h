/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/indexedDB/nsIIDBFactory.idl
 */

#ifndef __gen_nsIIDBFactory_h__
#define __gen_nsIIDBFactory_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIIDBKeyRange; /* forward declaration */

class nsIIDBRequest; /* forward declaration */

class nsIVariant; /* forward declaration */

#include "jsapi.h"

/* starting interface:    nsIIDBFactory */
#define NS_IIDBFACTORY_IID_STR "137d17a5-fac5-4788-87b5-bc3806d7cfaf"

#define NS_IIDBFACTORY_IID \
  {0x137d17a5, 0xfac5, 0x4788, \
    { 0x87, 0xb5, 0xbc, 0x38, 0x06, 0xd7, 0xcf, 0xaf }}

/**
 * Interface that defines the indexedDB property on a window.  See
 * http://dvcs.w3.org/hg/IndexedDB/raw-file/tip/Overview.html#idl-def-IDBFactory
 * for more information.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBFactory : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBFACTORY_IID)

  /* [implicit_jscontext] nsIIDBRequest open (in AString name); */
  NS_SCRIPTABLE NS_IMETHOD Open(const nsAString & name, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBFactory, NS_IIDBFACTORY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBFACTORY \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsAString & name, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsAString & name, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) { return _to Open(name, cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBFACTORY(_to) \
  NS_SCRIPTABLE NS_IMETHOD Open(const nsAString & name, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(name, cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBFactory : public nsIIDBFactory
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBFACTORY

  nsIDBFactory();

private:
  ~nsIDBFactory();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBFactory, nsIIDBFactory)

nsIDBFactory::nsIDBFactory()
{
  /* member initializers and constructor code */
}

nsIDBFactory::~nsIDBFactory()
{
  /* destructor code */
}

/* [implicit_jscontext] nsIIDBRequest open (in AString name); */
NS_IMETHODIMP nsIDBFactory::Open(const nsAString & name, JSContext *cx, nsIIDBRequest **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBFactory_h__ */
