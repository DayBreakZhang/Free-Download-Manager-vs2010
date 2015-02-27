/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/core/nsIDOMDOMSettableTokenList.idl
 */

#ifndef __gen_nsIDOMDOMSettableTokenList_h__
#define __gen_nsIDOMDOMSettableTokenList_h__


#ifndef __gen_nsIDOMDOMTokenList_h__
#include "nsIDOMDOMTokenList.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDOMSettableTokenList */
#define NS_IDOMDOMSETTABLETOKENLIST_IID_STR "cdac274e-6619-4b5f-ba1a-cd1dbfae44b8"

#define NS_IDOMDOMSETTABLETOKENLIST_IID \
  {0xcdac274e, 0x6619, 0x4b5f, \
    { 0xba, 0x1a, 0xcd, 0x1d, 0xbf, 0xae, 0x44, 0xb8 }}

/**
 * The DOMSettableTokenList interface is the same as the DOMTokenList interface,
 * except that it allows the underlying string to be directly changed.
 *
 * For more information on this interface please see:
 * http://dev.w3.org/html5/spec/infrastructure.html#domsettabletokenlist
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDOMSettableTokenList : public nsIDOMDOMTokenList {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMSETTABLETOKENLIST_IID)

  /* attribute DOMString value; */
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMSettableTokenList, NS_IDOMDOMSETTABLETOKENLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMSETTABLETOKENLIST \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue); \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMSETTABLETOKENLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMSETTABLETOKENLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_SCRIPTABLE NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMSettableTokenList : public nsIDOMDOMSettableTokenList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMSETTABLETOKENLIST

  nsDOMDOMSettableTokenList();

private:
  ~nsDOMDOMSettableTokenList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMSettableTokenList, nsIDOMDOMSettableTokenList)

nsDOMDOMSettableTokenList::nsDOMDOMSettableTokenList()
{
  /* member initializers and constructor code */
}

nsDOMDOMSettableTokenList::~nsDOMDOMSettableTokenList()
{
  /* destructor code */
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMDOMSettableTokenList::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMDOMSettableTokenList::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMSettableTokenList_h__ */
