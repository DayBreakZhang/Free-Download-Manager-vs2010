/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMXULContainerElement.idl
 */

#ifndef __gen_nsIDOMXULContainerElement_h__
#define __gen_nsIDOMXULContainerElement_h__


#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULContainerElement; /* forward declaration */


/* starting interface:    nsIDOMXULContainerItemElement */
#define NS_IDOMXULCONTAINERITEMELEMENT_IID_STR "6f59f65f-afc9-4076-a80f-7b25d5a42fe4"

#define NS_IDOMXULCONTAINERITEMELEMENT_IID \
  {0x6f59f65f, 0xafc9, 0x4076, \
    { 0xa8, 0x0f, 0x7b, 0x25, 0xd5, 0xa4, 0x2f, 0xe4 }}

class NS_NO_VTABLE nsIDOMXULContainerItemElement : public nsIDOMXULElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCONTAINERITEMELEMENT_IID)

  /* readonly attribute nsIDOMXULContainerElement parentContainer; */
  NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULContainerItemElement, NS_IDOMXULCONTAINERITEMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCONTAINERITEMELEMENT \
  NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCONTAINERITEMELEMENT(_to) \
  NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) { return _to GetParentContainer(aParentContainer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCONTAINERITEMELEMENT(_to) \
  NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentContainer(aParentContainer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULContainerItemElement : public nsIDOMXULContainerItemElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCONTAINERITEMELEMENT

  nsDOMXULContainerItemElement();

private:
  ~nsDOMXULContainerItemElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULContainerItemElement, nsIDOMXULContainerItemElement)

nsDOMXULContainerItemElement::nsDOMXULContainerItemElement()
{
  /* member initializers and constructor code */
}

nsDOMXULContainerItemElement::~nsDOMXULContainerItemElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMXULContainerElement parentContainer; */
NS_IMETHODIMP nsDOMXULContainerItemElement::GetParentContainer(nsIDOMXULContainerElement * *aParentContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMXULContainerElement */
#define NS_IDOMXULCONTAINERELEMENT_IID_STR "b2bc96b8-31fc-42f4-937a-bd27291af40b"

#define NS_IDOMXULCONTAINERELEMENT_IID \
  {0xb2bc96b8, 0x31fc, 0x42f4, \
    { 0x93, 0x7a, 0xbd, 0x27, 0x29, 0x1a, 0xf4, 0x0b }}

class NS_NO_VTABLE nsIDOMXULContainerElement : public nsIDOMXULContainerItemElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCONTAINERELEMENT_IID)

  /* nsIDOMXULElement appendItem (in DOMString aLabel, in DOMString aValue); */
  NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) = 0;

  /* nsIDOMXULElement insertItemAt (in long aIndex, in DOMString aLabel, in DOMString aValue); */
  NS_IMETHOD InsertItemAt(int32_t aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) = 0;

  /* nsIDOMXULElement removeItemAt (in long aIndex); */
  NS_IMETHOD RemoveItemAt(int32_t aIndex, nsIDOMXULElement * *_retval) = 0;

  /* readonly attribute unsigned long itemCount; */
  NS_IMETHOD GetItemCount(uint32_t *aItemCount) = 0;

  /* long getIndexOfItem (in nsIDOMXULElement aItem); */
  NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, int32_t *_retval) = 0;

  /* nsIDOMXULElement getItemAtIndex (in long aIndex); */
  NS_IMETHOD GetItemAtIndex(int32_t aIndex, nsIDOMXULElement * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULContainerElement, NS_IDOMXULCONTAINERELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCONTAINERELEMENT \
  NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval); \
  NS_IMETHOD InsertItemAt(int32_t aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval); \
  NS_IMETHOD RemoveItemAt(int32_t aIndex, nsIDOMXULElement * *_retval); \
  NS_IMETHOD GetItemCount(uint32_t *aItemCount); \
  NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, int32_t *_retval); \
  NS_IMETHOD GetItemAtIndex(int32_t aIndex, nsIDOMXULElement * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCONTAINERELEMENT(_to) \
  NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) { return _to AppendItem(aLabel, aValue, _retval); } \
  NS_IMETHOD InsertItemAt(int32_t aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) { return _to InsertItemAt(aIndex, aLabel, aValue, _retval); } \
  NS_IMETHOD RemoveItemAt(int32_t aIndex, nsIDOMXULElement * *_retval) { return _to RemoveItemAt(aIndex, _retval); } \
  NS_IMETHOD GetItemCount(uint32_t *aItemCount) { return _to GetItemCount(aItemCount); } \
  NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, int32_t *_retval) { return _to GetIndexOfItem(aItem, _retval); } \
  NS_IMETHOD GetItemAtIndex(int32_t aIndex, nsIDOMXULElement * *_retval) { return _to GetItemAtIndex(aIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCONTAINERELEMENT(_to) \
  NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(aLabel, aValue, _retval); } \
  NS_IMETHOD InsertItemAt(int32_t aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemAt(aIndex, aLabel, aValue, _retval); } \
  NS_IMETHOD RemoveItemAt(int32_t aIndex, nsIDOMXULElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemAt(aIndex, _retval); } \
  NS_IMETHOD GetItemCount(uint32_t *aItemCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemCount(aItemCount); } \
  NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfItem(aItem, _retval); } \
  NS_IMETHOD GetItemAtIndex(int32_t aIndex, nsIDOMXULElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAtIndex(aIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULContainerElement : public nsIDOMXULContainerElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCONTAINERELEMENT

  nsDOMXULContainerElement();

private:
  ~nsDOMXULContainerElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULContainerElement, nsIDOMXULContainerElement)

nsDOMXULContainerElement::nsDOMXULContainerElement()
{
  /* member initializers and constructor code */
}

nsDOMXULContainerElement::~nsDOMXULContainerElement()
{
  /* destructor code */
}

/* nsIDOMXULElement appendItem (in DOMString aLabel, in DOMString aValue); */
NS_IMETHODIMP nsDOMXULContainerElement::AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement insertItemAt (in long aIndex, in DOMString aLabel, in DOMString aValue); */
NS_IMETHODIMP nsDOMXULContainerElement::InsertItemAt(int32_t aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement removeItemAt (in long aIndex); */
NS_IMETHODIMP nsDOMXULContainerElement::RemoveItemAt(int32_t aIndex, nsIDOMXULElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long itemCount; */
NS_IMETHODIMP nsDOMXULContainerElement::GetItemCount(uint32_t *aItemCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfItem (in nsIDOMXULElement aItem); */
NS_IMETHODIMP nsDOMXULContainerElement::GetIndexOfItem(nsIDOMXULElement *aItem, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement getItemAtIndex (in long aIndex); */
NS_IMETHODIMP nsDOMXULContainerElement::GetItemAtIndex(int32_t aIndex, nsIDOMXULElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULContainerElement_h__ */
