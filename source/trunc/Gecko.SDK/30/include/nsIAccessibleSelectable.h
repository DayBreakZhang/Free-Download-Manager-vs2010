/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIAccessibleSelectable.idl
 */

#ifndef __gen_nsIAccessibleSelectable_h__
#define __gen_nsIAccessibleSelectable_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIAccessible; /* forward declaration */

class nsIArray; /* forward declaration */


/* starting interface:    nsIAccessibleSelectable */
#define NS_IACCESSIBLESELECTABLE_IID_STR "3e507fc4-4fcc-4223-a674-a095f591eba1"

#define NS_IACCESSIBLESELECTABLE_IID \
  {0x3e507fc4, 0x4fcc, 0x4223, \
    { 0xa6, 0x74, 0xa0, 0x95, 0xf5, 0x91, 0xeb, 0xa1 }}

class NS_NO_VTABLE nsIAccessibleSelectable : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IACCESSIBLESELECTABLE_IID)

  /* readonly attribute nsIArray selectedItems; */
  NS_IMETHOD GetSelectedItems(nsIArray * *aSelectedItems) = 0;

  /* readonly attribute unsigned long selectedItemCount; */
  NS_IMETHOD GetSelectedItemCount(uint32_t *aSelectedItemCount) = 0;

  /* nsIAccessible getSelectedItemAt (in unsigned long index); */
  NS_IMETHOD GetSelectedItemAt(uint32_t index, nsIAccessible * *_retval) = 0;

  /* [binaryname(ScriptableIsItemSelected)] boolean isItemSelected (in unsigned long index); */
  NS_IMETHOD ScriptableIsItemSelected(uint32_t index, bool *_retval) = 0;

  /* [binaryname(ScriptableAddItemToSelection)] void addItemToSelection (in unsigned long index); */
  NS_IMETHOD ScriptableAddItemToSelection(uint32_t index) = 0;

  /* [binaryname(ScriptableRemoveItemFromSelection)] void removeItemFromSelection (in unsigned long index); */
  NS_IMETHOD ScriptableRemoveItemFromSelection(uint32_t index) = 0;

  /* [binaryname(ScriptableSelectAll)] boolean selectAll (); */
  NS_IMETHOD ScriptableSelectAll(bool *_retval) = 0;

  /* [binaryname(ScriptableUnselectAll)] void unselectAll (); */
  NS_IMETHOD ScriptableUnselectAll(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAccessibleSelectable, NS_IACCESSIBLESELECTABLE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIACCESSIBLESELECTABLE \
  NS_IMETHOD GetSelectedItems(nsIArray * *aSelectedItems); \
  NS_IMETHOD GetSelectedItemCount(uint32_t *aSelectedItemCount); \
  NS_IMETHOD GetSelectedItemAt(uint32_t index, nsIAccessible * *_retval); \
  NS_IMETHOD ScriptableIsItemSelected(uint32_t index, bool *_retval); \
  NS_IMETHOD ScriptableAddItemToSelection(uint32_t index); \
  NS_IMETHOD ScriptableRemoveItemFromSelection(uint32_t index); \
  NS_IMETHOD ScriptableSelectAll(bool *_retval); \
  NS_IMETHOD ScriptableUnselectAll(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIACCESSIBLESELECTABLE(_to) \
  NS_IMETHOD GetSelectedItems(nsIArray * *aSelectedItems) { return _to GetSelectedItems(aSelectedItems); } \
  NS_IMETHOD GetSelectedItemCount(uint32_t *aSelectedItemCount) { return _to GetSelectedItemCount(aSelectedItemCount); } \
  NS_IMETHOD GetSelectedItemAt(uint32_t index, nsIAccessible * *_retval) { return _to GetSelectedItemAt(index, _retval); } \
  NS_IMETHOD ScriptableIsItemSelected(uint32_t index, bool *_retval) { return _to ScriptableIsItemSelected(index, _retval); } \
  NS_IMETHOD ScriptableAddItemToSelection(uint32_t index) { return _to ScriptableAddItemToSelection(index); } \
  NS_IMETHOD ScriptableRemoveItemFromSelection(uint32_t index) { return _to ScriptableRemoveItemFromSelection(index); } \
  NS_IMETHOD ScriptableSelectAll(bool *_retval) { return _to ScriptableSelectAll(_retval); } \
  NS_IMETHOD ScriptableUnselectAll(void) { return _to ScriptableUnselectAll(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIACCESSIBLESELECTABLE(_to) \
  NS_IMETHOD GetSelectedItems(nsIArray * *aSelectedItems) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedItems(aSelectedItems); } \
  NS_IMETHOD GetSelectedItemCount(uint32_t *aSelectedItemCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedItemCount(aSelectedItemCount); } \
  NS_IMETHOD GetSelectedItemAt(uint32_t index, nsIAccessible * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedItemAt(index, _retval); } \
  NS_IMETHOD ScriptableIsItemSelected(uint32_t index, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableIsItemSelected(index, _retval); } \
  NS_IMETHOD ScriptableAddItemToSelection(uint32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableAddItemToSelection(index); } \
  NS_IMETHOD ScriptableRemoveItemFromSelection(uint32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableRemoveItemFromSelection(index); } \
  NS_IMETHOD ScriptableSelectAll(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableSelectAll(_retval); } \
  NS_IMETHOD ScriptableUnselectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScriptableUnselectAll(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAccessibleSelectable : public nsIAccessibleSelectable
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIACCESSIBLESELECTABLE

  nsAccessibleSelectable();

private:
  ~nsAccessibleSelectable();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAccessibleSelectable, nsIAccessibleSelectable)

nsAccessibleSelectable::nsAccessibleSelectable()
{
  /* member initializers and constructor code */
}

nsAccessibleSelectable::~nsAccessibleSelectable()
{
  /* destructor code */
}

/* readonly attribute nsIArray selectedItems; */
NS_IMETHODIMP nsAccessibleSelectable::GetSelectedItems(nsIArray * *aSelectedItems)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long selectedItemCount; */
NS_IMETHODIMP nsAccessibleSelectable::GetSelectedItemCount(uint32_t *aSelectedItemCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIAccessible getSelectedItemAt (in unsigned long index); */
NS_IMETHODIMP nsAccessibleSelectable::GetSelectedItemAt(uint32_t index, nsIAccessible * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableIsItemSelected)] boolean isItemSelected (in unsigned long index); */
NS_IMETHODIMP nsAccessibleSelectable::ScriptableIsItemSelected(uint32_t index, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableAddItemToSelection)] void addItemToSelection (in unsigned long index); */
NS_IMETHODIMP nsAccessibleSelectable::ScriptableAddItemToSelection(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableRemoveItemFromSelection)] void removeItemFromSelection (in unsigned long index); */
NS_IMETHODIMP nsAccessibleSelectable::ScriptableRemoveItemFromSelection(uint32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableSelectAll)] boolean selectAll (); */
NS_IMETHODIMP nsAccessibleSelectable::ScriptableSelectAll(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(ScriptableUnselectAll)] void unselectAll (); */
NS_IMETHODIMP nsAccessibleSelectable::ScriptableUnselectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAccessibleSelectable_h__ */
