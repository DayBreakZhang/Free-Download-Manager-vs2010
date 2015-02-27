/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIBoxObject.idl
 */

#ifndef __gen_nsIBoxObject_h__
#define __gen_nsIBoxObject_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIBoxObject */
#define NS_IBOXOBJECT_IID_STR "ce572460-b0f2-4650-a9e7-c53a99d3b6ad"

#define NS_IBOXOBJECT_IID \
  {0xce572460, 0xb0f2, 0x4650, \
    { 0xa9, 0xe7, 0xc5, 0x3a, 0x99, 0xd3, 0xb6, 0xad }}

class NS_NO_VTABLE nsIBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBOXOBJECT_IID)

  /* readonly attribute nsIDOMElement element; */
  NS_IMETHOD GetElement(nsIDOMElement * *aElement) = 0;

  /* readonly attribute long x; */
  NS_IMETHOD GetX(int32_t *aX) = 0;

  /* readonly attribute long y; */
  NS_IMETHOD GetY(int32_t *aY) = 0;

  /* readonly attribute long screenX; */
  NS_IMETHOD GetScreenX(int32_t *aScreenX) = 0;

  /* readonly attribute long screenY; */
  NS_IMETHOD GetScreenY(int32_t *aScreenY) = 0;

  /* readonly attribute long width; */
  NS_IMETHOD GetWidth(int32_t *aWidth) = 0;

  /* readonly attribute long height; */
  NS_IMETHOD GetHeight(int32_t *aHeight) = 0;

  /* nsISupports getPropertyAsSupports (in wstring propertyName); */
  NS_IMETHOD GetPropertyAsSupports(const char16_t * propertyName, nsISupports * *_retval) = 0;

  /* void setPropertyAsSupports (in wstring propertyName, in nsISupports value); */
  NS_IMETHOD SetPropertyAsSupports(const char16_t * propertyName, nsISupports *value) = 0;

  /* wstring getProperty (in wstring propertyName); */
  NS_IMETHOD GetProperty(const char16_t * propertyName, char16_t * *_retval) = 0;

  /* void setProperty (in wstring propertyName, in wstring propertyValue); */
  NS_IMETHOD SetProperty(const char16_t * propertyName, const char16_t * propertyValue) = 0;

  /* void removeProperty (in wstring propertyName); */
  NS_IMETHOD RemoveProperty(const char16_t * propertyName) = 0;

  /* readonly attribute nsIDOMElement parentBox; */
  NS_IMETHOD GetParentBox(nsIDOMElement * *aParentBox) = 0;

  /* readonly attribute nsIDOMElement firstChild; */
  NS_IMETHOD GetFirstChild(nsIDOMElement * *aFirstChild) = 0;

  /* readonly attribute nsIDOMElement lastChild; */
  NS_IMETHOD GetLastChild(nsIDOMElement * *aLastChild) = 0;

  /* readonly attribute nsIDOMElement nextSibling; */
  NS_IMETHOD GetNextSibling(nsIDOMElement * *aNextSibling) = 0;

  /* readonly attribute nsIDOMElement previousSibling; */
  NS_IMETHOD GetPreviousSibling(nsIDOMElement * *aPreviousSibling) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBoxObject, NS_IBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBOXOBJECT \
  NS_IMETHOD GetElement(nsIDOMElement * *aElement); \
  NS_IMETHOD GetX(int32_t *aX); \
  NS_IMETHOD GetY(int32_t *aY); \
  NS_IMETHOD GetScreenX(int32_t *aScreenX); \
  NS_IMETHOD GetScreenY(int32_t *aScreenY); \
  NS_IMETHOD GetWidth(int32_t *aWidth); \
  NS_IMETHOD GetHeight(int32_t *aHeight); \
  NS_IMETHOD GetPropertyAsSupports(const char16_t * propertyName, nsISupports * *_retval); \
  NS_IMETHOD SetPropertyAsSupports(const char16_t * propertyName, nsISupports *value); \
  NS_IMETHOD GetProperty(const char16_t * propertyName, char16_t * *_retval); \
  NS_IMETHOD SetProperty(const char16_t * propertyName, const char16_t * propertyValue); \
  NS_IMETHOD RemoveProperty(const char16_t * propertyName); \
  NS_IMETHOD GetParentBox(nsIDOMElement * *aParentBox); \
  NS_IMETHOD GetFirstChild(nsIDOMElement * *aFirstChild); \
  NS_IMETHOD GetLastChild(nsIDOMElement * *aLastChild); \
  NS_IMETHOD GetNextSibling(nsIDOMElement * *aNextSibling); \
  NS_IMETHOD GetPreviousSibling(nsIDOMElement * *aPreviousSibling); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBOXOBJECT(_to) \
  NS_IMETHOD GetElement(nsIDOMElement * *aElement) { return _to GetElement(aElement); } \
  NS_IMETHOD GetX(int32_t *aX) { return _to GetX(aX); } \
  NS_IMETHOD GetY(int32_t *aY) { return _to GetY(aY); } \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) { return _to GetScreenX(aScreenX); } \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) { return _to GetScreenY(aScreenY); } \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return _to GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(int32_t *aHeight) { return _to GetHeight(aHeight); } \
  NS_IMETHOD GetPropertyAsSupports(const char16_t * propertyName, nsISupports * *_retval) { return _to GetPropertyAsSupports(propertyName, _retval); } \
  NS_IMETHOD SetPropertyAsSupports(const char16_t * propertyName, nsISupports *value) { return _to SetPropertyAsSupports(propertyName, value); } \
  NS_IMETHOD GetProperty(const char16_t * propertyName, char16_t * *_retval) { return _to GetProperty(propertyName, _retval); } \
  NS_IMETHOD SetProperty(const char16_t * propertyName, const char16_t * propertyValue) { return _to SetProperty(propertyName, propertyValue); } \
  NS_IMETHOD RemoveProperty(const char16_t * propertyName) { return _to RemoveProperty(propertyName); } \
  NS_IMETHOD GetParentBox(nsIDOMElement * *aParentBox) { return _to GetParentBox(aParentBox); } \
  NS_IMETHOD GetFirstChild(nsIDOMElement * *aFirstChild) { return _to GetFirstChild(aFirstChild); } \
  NS_IMETHOD GetLastChild(nsIDOMElement * *aLastChild) { return _to GetLastChild(aLastChild); } \
  NS_IMETHOD GetNextSibling(nsIDOMElement * *aNextSibling) { return _to GetNextSibling(aNextSibling); } \
  NS_IMETHOD GetPreviousSibling(nsIDOMElement * *aPreviousSibling) { return _to GetPreviousSibling(aPreviousSibling); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBOXOBJECT(_to) \
  NS_IMETHOD GetElement(nsIDOMElement * *aElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetElement(aElement); } \
  NS_IMETHOD GetX(int32_t *aX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX(aX); } \
  NS_IMETHOD GetY(int32_t *aY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY(aY); } \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenX(aScreenX); } \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenY(aScreenY); } \
  NS_IMETHOD GetWidth(int32_t *aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_IMETHOD GetHeight(int32_t *aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_IMETHOD GetPropertyAsSupports(const char16_t * propertyName, nsISupports * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPropertyAsSupports(propertyName, _retval); } \
  NS_IMETHOD SetPropertyAsSupports(const char16_t * propertyName, nsISupports *value) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPropertyAsSupports(propertyName, value); } \
  NS_IMETHOD GetProperty(const char16_t * propertyName, char16_t * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProperty(propertyName, _retval); } \
  NS_IMETHOD SetProperty(const char16_t * propertyName, const char16_t * propertyValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProperty(propertyName, propertyValue); } \
  NS_IMETHOD RemoveProperty(const char16_t * propertyName) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveProperty(propertyName); } \
  NS_IMETHOD GetParentBox(nsIDOMElement * *aParentBox) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentBox(aParentBox); } \
  NS_IMETHOD GetFirstChild(nsIDOMElement * *aFirstChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFirstChild(aFirstChild); } \
  NS_IMETHOD GetLastChild(nsIDOMElement * *aLastChild) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastChild(aLastChild); } \
  NS_IMETHOD GetNextSibling(nsIDOMElement * *aNextSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextSibling(aNextSibling); } \
  NS_IMETHOD GetPreviousSibling(nsIDOMElement * *aPreviousSibling) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPreviousSibling(aPreviousSibling); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBoxObject : public nsIBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBOXOBJECT

  nsBoxObject();

private:
  ~nsBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBoxObject, nsIBoxObject)

nsBoxObject::nsBoxObject()
{
  /* member initializers and constructor code */
}

nsBoxObject::~nsBoxObject()
{
  /* destructor code */
}

/* readonly attribute nsIDOMElement element; */
NS_IMETHODIMP nsBoxObject::GetElement(nsIDOMElement * *aElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long x; */
NS_IMETHODIMP nsBoxObject::GetX(int32_t *aX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long y; */
NS_IMETHODIMP nsBoxObject::GetY(int32_t *aY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long screenX; */
NS_IMETHODIMP nsBoxObject::GetScreenX(int32_t *aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long screenY; */
NS_IMETHODIMP nsBoxObject::GetScreenY(int32_t *aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long width; */
NS_IMETHODIMP nsBoxObject::GetWidth(int32_t *aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long height; */
NS_IMETHODIMP nsBoxObject::GetHeight(int32_t *aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISupports getPropertyAsSupports (in wstring propertyName); */
NS_IMETHODIMP nsBoxObject::GetPropertyAsSupports(const char16_t * propertyName, nsISupports * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setPropertyAsSupports (in wstring propertyName, in nsISupports value); */
NS_IMETHODIMP nsBoxObject::SetPropertyAsSupports(const char16_t * propertyName, nsISupports *value)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* wstring getProperty (in wstring propertyName); */
NS_IMETHODIMP nsBoxObject::GetProperty(const char16_t * propertyName, char16_t * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setProperty (in wstring propertyName, in wstring propertyValue); */
NS_IMETHODIMP nsBoxObject::SetProperty(const char16_t * propertyName, const char16_t * propertyValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeProperty (in wstring propertyName); */
NS_IMETHODIMP nsBoxObject::RemoveProperty(const char16_t * propertyName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement parentBox; */
NS_IMETHODIMP nsBoxObject::GetParentBox(nsIDOMElement * *aParentBox)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement firstChild; */
NS_IMETHODIMP nsBoxObject::GetFirstChild(nsIDOMElement * *aFirstChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement lastChild; */
NS_IMETHODIMP nsBoxObject::GetLastChild(nsIDOMElement * *aLastChild)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement nextSibling; */
NS_IMETHODIMP nsBoxObject::GetNextSibling(nsIDOMElement * *aNextSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement previousSibling; */
NS_IMETHODIMP nsBoxObject::GetPreviousSibling(nsIDOMElement * *aPreviousSibling)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewBoxObject(nsIBoxObject** aResult);

#endif /* __gen_nsIBoxObject_h__ */
