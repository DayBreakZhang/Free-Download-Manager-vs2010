/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/xul/nsIDOMXULSelectCntrlEl.idl
 */

#ifndef __gen_nsIDOMXULSelectCntrlEl_h__
#define __gen_nsIDOMXULSelectCntrlEl_h__


#ifndef __gen_nsIDOMXULControlElement_h__
#include "nsIDOMXULControlElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULSelectControlItemElement; /* forward declaration */


/* starting interface:    nsIDOMXULSelectControlElement */
#define NS_IDOMXULSELECTCONTROLELEMENT_IID_STR "f9cbf59c-0cdd-416e-a809-40da4a7a8cb5"

#define NS_IDOMXULSELECTCONTROLELEMENT_IID \
  {0xf9cbf59c, 0x0cdd, 0x416e, \
    { 0xa8, 0x09, 0x40, 0xda, 0x4a, 0x7a, 0x8c, 0xb5 }}

class NS_NO_VTABLE nsIDOMXULSelectControlElement : public nsIDOMXULControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULSELECTCONTROLELEMENT_IID)

  /* attribute nsIDOMXULSelectControlItemElement selectedItem; */
  NS_IMETHOD GetSelectedItem(nsIDOMXULSelectControlItemElement * *aSelectedItem) = 0;
  NS_IMETHOD SetSelectedItem(nsIDOMXULSelectControlItemElement *aSelectedItem) = 0;

  /* attribute long selectedIndex; */
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex) = 0;
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex) = 0;

  /* attribute DOMString value; */
  NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* nsIDOMXULSelectControlItemElement appendItem (in DOMString label, in DOMString value); */
  NS_IMETHOD AppendItem(const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement * *_retval) = 0;

  /* nsIDOMXULSelectControlItemElement insertItemAt (in long index, in DOMString label, in DOMString value); */
  NS_IMETHOD InsertItemAt(int32_t index, const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement * *_retval) = 0;

  /* nsIDOMXULSelectControlItemElement removeItemAt (in long index); */
  NS_IMETHOD RemoveItemAt(int32_t index, nsIDOMXULSelectControlItemElement * *_retval) = 0;

  /* readonly attribute unsigned long itemCount; */
  NS_IMETHOD GetItemCount(uint32_t *aItemCount) = 0;

  /* long getIndexOfItem (in nsIDOMXULSelectControlItemElement item); */
  NS_IMETHOD GetIndexOfItem(nsIDOMXULSelectControlItemElement *item, int32_t *_retval) = 0;

  /* nsIDOMXULSelectControlItemElement getItemAtIndex (in long index); */
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMXULSelectControlItemElement * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULSelectControlElement, NS_IDOMXULSELECTCONTROLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULSELECTCONTROLELEMENT \
  NS_IMETHOD GetSelectedItem(nsIDOMXULSelectControlItemElement * *aSelectedItem); \
  NS_IMETHOD SetSelectedItem(nsIDOMXULSelectControlItemElement *aSelectedItem); \
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex); \
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex); \
  NS_IMETHOD GetValue(nsAString & aValue); \
  NS_IMETHOD SetValue(const nsAString & aValue); \
  NS_IMETHOD AppendItem(const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement * *_retval); \
  NS_IMETHOD InsertItemAt(int32_t index, const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement * *_retval); \
  NS_IMETHOD RemoveItemAt(int32_t index, nsIDOMXULSelectControlItemElement * *_retval); \
  NS_IMETHOD GetItemCount(uint32_t *aItemCount); \
  NS_IMETHOD GetIndexOfItem(nsIDOMXULSelectControlItemElement *item, int32_t *_retval); \
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMXULSelectControlItemElement * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULSELECTCONTROLELEMENT(_to) \
  NS_IMETHOD GetSelectedItem(nsIDOMXULSelectControlItemElement * *aSelectedItem) { return _to GetSelectedItem(aSelectedItem); } \
  NS_IMETHOD SetSelectedItem(nsIDOMXULSelectControlItemElement *aSelectedItem) { return _to SetSelectedItem(aSelectedItem); } \
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex) { return _to GetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex) { return _to SetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } \
  NS_IMETHOD AppendItem(const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement * *_retval) { return _to AppendItem(label, value, _retval); } \
  NS_IMETHOD InsertItemAt(int32_t index, const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement * *_retval) { return _to InsertItemAt(index, label, value, _retval); } \
  NS_IMETHOD RemoveItemAt(int32_t index, nsIDOMXULSelectControlItemElement * *_retval) { return _to RemoveItemAt(index, _retval); } \
  NS_IMETHOD GetItemCount(uint32_t *aItemCount) { return _to GetItemCount(aItemCount); } \
  NS_IMETHOD GetIndexOfItem(nsIDOMXULSelectControlItemElement *item, int32_t *_retval) { return _to GetIndexOfItem(item, _retval); } \
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMXULSelectControlItemElement * *_retval) { return _to GetItemAtIndex(index, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULSELECTCONTROLELEMENT(_to) \
  NS_IMETHOD GetSelectedItem(nsIDOMXULSelectControlItemElement * *aSelectedItem) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedItem(aSelectedItem); } \
  NS_IMETHOD SetSelectedItem(nsIDOMXULSelectControlItemElement *aSelectedItem) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedItem(aSelectedItem); } \
  NS_IMETHOD GetSelectedIndex(int32_t *aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetSelectedIndex(int32_t aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD AppendItem(const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(label, value, _retval); } \
  NS_IMETHOD InsertItemAt(int32_t index, const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemAt(index, label, value, _retval); } \
  NS_IMETHOD RemoveItemAt(int32_t index, nsIDOMXULSelectControlItemElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemAt(index, _retval); } \
  NS_IMETHOD GetItemCount(uint32_t *aItemCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemCount(aItemCount); } \
  NS_IMETHOD GetIndexOfItem(nsIDOMXULSelectControlItemElement *item, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfItem(item, _retval); } \
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMXULSelectControlItemElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAtIndex(index, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULSelectControlElement : public nsIDOMXULSelectControlElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULSELECTCONTROLELEMENT

  nsDOMXULSelectControlElement();

private:
  ~nsDOMXULSelectControlElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULSelectControlElement, nsIDOMXULSelectControlElement)

nsDOMXULSelectControlElement::nsDOMXULSelectControlElement()
{
  /* member initializers and constructor code */
}

nsDOMXULSelectControlElement::~nsDOMXULSelectControlElement()
{
  /* destructor code */
}

/* attribute nsIDOMXULSelectControlItemElement selectedItem; */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetSelectedItem(nsIDOMXULSelectControlItemElement * *aSelectedItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlElement::SetSelectedItem(nsIDOMXULSelectControlItemElement *aSelectedItem)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectedIndex; */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetSelectedIndex(int32_t *aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlElement::SetSelectedIndex(int32_t aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULSelectControlElement::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULSelectControlItemElement appendItem (in DOMString label, in DOMString value); */
NS_IMETHODIMP nsDOMXULSelectControlElement::AppendItem(const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULSelectControlItemElement insertItemAt (in long index, in DOMString label, in DOMString value); */
NS_IMETHODIMP nsDOMXULSelectControlElement::InsertItemAt(int32_t index, const nsAString & label, const nsAString & value, nsIDOMXULSelectControlItemElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULSelectControlItemElement removeItemAt (in long index); */
NS_IMETHODIMP nsDOMXULSelectControlElement::RemoveItemAt(int32_t index, nsIDOMXULSelectControlItemElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long itemCount; */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetItemCount(uint32_t *aItemCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfItem (in nsIDOMXULSelectControlItemElement item); */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetIndexOfItem(nsIDOMXULSelectControlItemElement *item, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULSelectControlItemElement getItemAtIndex (in long index); */
NS_IMETHODIMP nsDOMXULSelectControlElement::GetItemAtIndex(int32_t index, nsIDOMXULSelectControlItemElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULSelectCntrlEl_h__ */
