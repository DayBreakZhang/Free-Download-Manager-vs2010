/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMMozNamedAttrMap.idl
 */

#ifndef __gen_nsIDOMMozNamedAttrMap_h__
#define __gen_nsIDOMMozNamedAttrMap_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozNamedAttrMap */
#define NS_IDOMMOZNAMEDATTRMAP_IID_STR "cb5564cd-26ec-418f-a6d6-1d57cd2c971c"

#define NS_IDOMMOZNAMEDATTRMAP_IID \
  {0xcb5564cd, 0x26ec, 0x418f, \
    { 0xa6, 0xd6, 0x1d, 0x57, 0xcd, 0x2c, 0x97, 0x1c }}

class NS_NO_VTABLE nsIDOMMozNamedAttrMap : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZNAMEDATTRMAP_IID)

  /* nsIDOMAttr getNamedItem (in DOMString name); */
  NS_IMETHOD GetNamedItem(const nsAString & name, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMAttr setNamedItem (in nsIDOMAttr arg) raises (DOMException); */
  NS_IMETHOD SetNamedItem(nsIDOMAttr *arg, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMAttr removeNamedItem (in DOMString name) raises (DOMException); */
  NS_IMETHOD RemoveNamedItem(const nsAString & name, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMAttr item (in unsigned long index); */
  NS_IMETHOD Item(uint32_t index, nsIDOMAttr * *_retval) = 0;

  /* readonly attribute unsigned long length; */
  NS_IMETHOD GetLength(uint32_t *aLength) = 0;

  /* nsIDOMAttr getNamedItemNS (in DOMString namespaceURI, in DOMString localName); */
  NS_IMETHOD GetNamedItemNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMAttr setNamedItemNS (in nsIDOMAttr arg) raises (DOMException); */
  NS_IMETHOD SetNamedItemNS(nsIDOMAttr *arg, nsIDOMAttr * *_retval) = 0;

  /* nsIDOMAttr removeNamedItemNS (in DOMString namespaceURI, in DOMString localName) raises (DOMException); */
  NS_IMETHOD RemoveNamedItemNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozNamedAttrMap, NS_IDOMMOZNAMEDATTRMAP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZNAMEDATTRMAP \
  NS_IMETHOD GetNamedItem(const nsAString & name, nsIDOMAttr * *_retval); \
  NS_IMETHOD SetNamedItem(nsIDOMAttr *arg, nsIDOMAttr * *_retval); \
  NS_IMETHOD RemoveNamedItem(const nsAString & name, nsIDOMAttr * *_retval); \
  NS_IMETHOD Item(uint32_t index, nsIDOMAttr * *_retval); \
  NS_IMETHOD GetLength(uint32_t *aLength); \
  NS_IMETHOD GetNamedItemNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval); \
  NS_IMETHOD SetNamedItemNS(nsIDOMAttr *arg, nsIDOMAttr * *_retval); \
  NS_IMETHOD RemoveNamedItemNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZNAMEDATTRMAP(_to) \
  NS_IMETHOD GetNamedItem(const nsAString & name, nsIDOMAttr * *_retval) { return _to GetNamedItem(name, _retval); } \
  NS_IMETHOD SetNamedItem(nsIDOMAttr *arg, nsIDOMAttr * *_retval) { return _to SetNamedItem(arg, _retval); } \
  NS_IMETHOD RemoveNamedItem(const nsAString & name, nsIDOMAttr * *_retval) { return _to RemoveNamedItem(name, _retval); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMAttr * *_retval) { return _to Item(index, _retval); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return _to GetLength(aLength); } \
  NS_IMETHOD GetNamedItemNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval) { return _to GetNamedItemNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD SetNamedItemNS(nsIDOMAttr *arg, nsIDOMAttr * *_retval) { return _to SetNamedItemNS(arg, _retval); } \
  NS_IMETHOD RemoveNamedItemNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval) { return _to RemoveNamedItemNS(namespaceURI, localName, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZNAMEDATTRMAP(_to) \
  NS_IMETHOD GetNamedItem(const nsAString & name, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNamedItem(name, _retval); } \
  NS_IMETHOD SetNamedItem(nsIDOMAttr *arg, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNamedItem(arg, _retval); } \
  NS_IMETHOD RemoveNamedItem(const nsAString & name, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveNamedItem(name, _retval); } \
  NS_IMETHOD Item(uint32_t index, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_IMETHOD GetLength(uint32_t *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_IMETHOD GetNamedItemNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNamedItemNS(namespaceURI, localName, _retval); } \
  NS_IMETHOD SetNamedItemNS(nsIDOMAttr *arg, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNamedItemNS(arg, _retval); } \
  NS_IMETHOD RemoveNamedItemNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveNamedItemNS(namespaceURI, localName, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozNamedAttrMap : public nsIDOMMozNamedAttrMap
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZNAMEDATTRMAP

  nsDOMMozNamedAttrMap();

private:
  ~nsDOMMozNamedAttrMap();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozNamedAttrMap, nsIDOMMozNamedAttrMap)

nsDOMMozNamedAttrMap::nsDOMMozNamedAttrMap()
{
  /* member initializers and constructor code */
}

nsDOMMozNamedAttrMap::~nsDOMMozNamedAttrMap()
{
  /* destructor code */
}

/* nsIDOMAttr getNamedItem (in DOMString name); */
NS_IMETHODIMP nsDOMMozNamedAttrMap::GetNamedItem(const nsAString & name, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr setNamedItem (in nsIDOMAttr arg) raises (DOMException); */
NS_IMETHODIMP nsDOMMozNamedAttrMap::SetNamedItem(nsIDOMAttr *arg, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr removeNamedItem (in DOMString name) raises (DOMException); */
NS_IMETHODIMP nsDOMMozNamedAttrMap::RemoveNamedItem(const nsAString & name, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr item (in unsigned long index); */
NS_IMETHODIMP nsDOMMozNamedAttrMap::Item(uint32_t index, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMMozNamedAttrMap::GetLength(uint32_t *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr getNamedItemNS (in DOMString namespaceURI, in DOMString localName); */
NS_IMETHODIMP nsDOMMozNamedAttrMap::GetNamedItemNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr setNamedItemNS (in nsIDOMAttr arg) raises (DOMException); */
NS_IMETHODIMP nsDOMMozNamedAttrMap::SetNamedItemNS(nsIDOMAttr *arg, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMAttr removeNamedItemNS (in DOMString namespaceURI, in DOMString localName) raises (DOMException); */
NS_IMETHODIMP nsDOMMozNamedAttrMap::RemoveNamedItemNS(const nsAString & namespaceURI, const nsAString & localName, nsIDOMAttr * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozNamedAttrMap_h__ */
