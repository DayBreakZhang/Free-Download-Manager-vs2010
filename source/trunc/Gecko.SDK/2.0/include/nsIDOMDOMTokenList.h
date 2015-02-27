/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/core/nsIDOMDOMTokenList.idl
 */

#ifndef __gen_nsIDOMDOMTokenList_h__
#define __gen_nsIDOMDOMTokenList_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMDOMTokenList */
#define NS_IDOMDOMTOKENLIST_IID_STR "c6f1e160-eeeb-404a-98b0-6f1246520b6e"

#define NS_IDOMDOMTOKENLIST_IID \
  {0xc6f1e160, 0xeeeb, 0x404a, \
    { 0x98, 0xb0, 0x6f, 0x12, 0x46, 0x52, 0x0b, 0x6e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMDOMTokenList : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMDOMTOKENLIST_IID)

  /**
 * The DOMTokenList interface represents an interface to an underlying string
 * that consists of a set of space-separated tokens.
 *
 * For more information on this interface please see
 * <http://www.whatwg.org/html5/#domtokenlist>
 */
  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* DOMString item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsAString & _retval NS_OUTPARAM) = 0;

  /* boolean contains ([Null (Stringify)] in DOMString token); */
  NS_SCRIPTABLE NS_IMETHOD Contains(const nsAString & token, PRBool *_retval NS_OUTPARAM) = 0;

  /* void add ([Null (Stringify)] in DOMString token); */
  NS_SCRIPTABLE NS_IMETHOD Add(const nsAString & token) = 0;

  /* void remove ([Null (Stringify)] in DOMString token); */
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsAString & token) = 0;

  /* boolean toggle ([Null (Stringify)] in DOMString token); */
  NS_SCRIPTABLE NS_IMETHOD Toggle(const nsAString & token, PRBool *_retval NS_OUTPARAM) = 0;

  /* DOMString toString (); */
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMDOMTokenList, NS_IDOMDOMTOKENLIST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMDOMTOKENLIST \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Contains(const nsAString & token, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Add(const nsAString & token); \
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsAString & token); \
  NS_SCRIPTABLE NS_IMETHOD Toggle(const nsAString & token, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMDOMTOKENLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return _to Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Contains(const nsAString & token, PRBool *_retval NS_OUTPARAM) { return _to Contains(token, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Add(const nsAString & token) { return _to Add(token); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsAString & token) { return _to Remove(token); } \
  NS_SCRIPTABLE NS_IMETHOD Toggle(const nsAString & token, PRBool *_retval NS_OUTPARAM) { return _to Toggle(token, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return _to ToString(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMDOMTOKENLIST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Contains(const nsAString & token, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Contains(token, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Add(const nsAString & token) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(token); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsAString & token) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(token); } \
  NS_SCRIPTABLE NS_IMETHOD Toggle(const nsAString & token, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Toggle(token, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ToString(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ToString(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMDOMTokenList : public nsIDOMDOMTokenList
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMDOMTOKENLIST

  nsDOMDOMTokenList();

private:
  ~nsDOMDOMTokenList();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMDOMTokenList, nsIDOMDOMTokenList)

nsDOMDOMTokenList::nsDOMDOMTokenList()
{
  /* member initializers and constructor code */
}

nsDOMDOMTokenList::~nsDOMDOMTokenList()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMDOMTokenList::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString item (in unsigned long index); */
NS_IMETHODIMP nsDOMDOMTokenList::Item(PRUint32 index, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean contains ([Null (Stringify)] in DOMString token); */
NS_IMETHODIMP nsDOMDOMTokenList::Contains(const nsAString & token, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void add ([Null (Stringify)] in DOMString token); */
NS_IMETHODIMP nsDOMDOMTokenList::Add(const nsAString & token)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove ([Null (Stringify)] in DOMString token); */
NS_IMETHODIMP nsDOMDOMTokenList::Remove(const nsAString & token)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean toggle ([Null (Stringify)] in DOMString token); */
NS_IMETHODIMP nsDOMDOMTokenList::Toggle(const nsAString & token, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* DOMString toString (); */
NS_IMETHODIMP nsDOMDOMTokenList::ToString(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDOMTokenList_h__ */
