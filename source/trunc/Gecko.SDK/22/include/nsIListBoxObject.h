/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/layout/xul/base/public/nsIListBoxObject.idl
 */

#ifndef __gen_nsIListBoxObject_h__
#define __gen_nsIListBoxObject_h__


#ifndef __gen_nsIBoxObject_h__
#include "nsIBoxObject.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIListBoxObject */
#define NS_ILISTBOXOBJECT_IID_STR "aa9def4e-2e59-412d-a6df-b76f52167795"

#define NS_ILISTBOXOBJECT_IID \
  {0xaa9def4e, 0x2e59, 0x412d, \
    { 0xa6, 0xdf, 0xb7, 0x6f, 0x52, 0x16, 0x77, 0x95 }}

class NS_NO_VTABLE nsIListBoxObject : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ILISTBOXOBJECT_IID)

  /* long getRowCount (); */
  NS_IMETHOD GetRowCount(int32_t *_retval) = 0;

  /* long getNumberOfVisibleRows (); */
  NS_IMETHOD GetNumberOfVisibleRows(int32_t *_retval) = 0;

  /* long getIndexOfFirstVisibleRow (); */
  NS_IMETHOD GetIndexOfFirstVisibleRow(int32_t *_retval) = 0;

  /* void ensureIndexIsVisible (in long rowIndex); */
  NS_IMETHOD EnsureIndexIsVisible(int32_t rowIndex) = 0;

  /* void scrollToIndex (in long rowIndex); */
  NS_IMETHOD ScrollToIndex(int32_t rowIndex) = 0;

  /* void scrollByLines (in long numLines); */
  NS_IMETHOD ScrollByLines(int32_t numLines) = 0;

  /* nsIDOMElement getItemAtIndex (in long index); */
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMElement * *_retval) = 0;

  /* long getIndexOfItem (in nsIDOMElement item); */
  NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIListBoxObject, NS_ILISTBOXOBJECT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSILISTBOXOBJECT \
  NS_IMETHOD GetRowCount(int32_t *_retval); \
  NS_IMETHOD GetNumberOfVisibleRows(int32_t *_retval); \
  NS_IMETHOD GetIndexOfFirstVisibleRow(int32_t *_retval); \
  NS_IMETHOD EnsureIndexIsVisible(int32_t rowIndex); \
  NS_IMETHOD ScrollToIndex(int32_t rowIndex); \
  NS_IMETHOD ScrollByLines(int32_t numLines); \
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMElement * *_retval); \
  NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, int32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSILISTBOXOBJECT(_to) \
  NS_IMETHOD GetRowCount(int32_t *_retval) { return _to GetRowCount(_retval); } \
  NS_IMETHOD GetNumberOfVisibleRows(int32_t *_retval) { return _to GetNumberOfVisibleRows(_retval); } \
  NS_IMETHOD GetIndexOfFirstVisibleRow(int32_t *_retval) { return _to GetIndexOfFirstVisibleRow(_retval); } \
  NS_IMETHOD EnsureIndexIsVisible(int32_t rowIndex) { return _to EnsureIndexIsVisible(rowIndex); } \
  NS_IMETHOD ScrollToIndex(int32_t rowIndex) { return _to ScrollToIndex(rowIndex); } \
  NS_IMETHOD ScrollByLines(int32_t numLines) { return _to ScrollByLines(numLines); } \
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMElement * *_retval) { return _to GetItemAtIndex(index, _retval); } \
  NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, int32_t *_retval) { return _to GetIndexOfItem(item, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSILISTBOXOBJECT(_to) \
  NS_IMETHOD GetRowCount(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowCount(_retval); } \
  NS_IMETHOD GetNumberOfVisibleRows(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNumberOfVisibleRows(_retval); } \
  NS_IMETHOD GetIndexOfFirstVisibleRow(int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfFirstVisibleRow(_retval); } \
  NS_IMETHOD EnsureIndexIsVisible(int32_t rowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsureIndexIsVisible(rowIndex); } \
  NS_IMETHOD ScrollToIndex(int32_t rowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollToIndex(rowIndex); } \
  NS_IMETHOD ScrollByLines(int32_t numLines) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollByLines(numLines); } \
  NS_IMETHOD GetItemAtIndex(int32_t index, nsIDOMElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAtIndex(index, _retval); } \
  NS_IMETHOD GetIndexOfItem(nsIDOMElement *item, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfItem(item, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsListBoxObject : public nsIListBoxObject
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSILISTBOXOBJECT

  nsListBoxObject();

private:
  ~nsListBoxObject();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsListBoxObject, nsIListBoxObject)

nsListBoxObject::nsListBoxObject()
{
  /* member initializers and constructor code */
}

nsListBoxObject::~nsListBoxObject()
{
  /* destructor code */
}

/* long getRowCount (); */
NS_IMETHODIMP nsListBoxObject::GetRowCount(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getNumberOfVisibleRows (); */
NS_IMETHODIMP nsListBoxObject::GetNumberOfVisibleRows(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfFirstVisibleRow (); */
NS_IMETHODIMP nsListBoxObject::GetIndexOfFirstVisibleRow(int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensureIndexIsVisible (in long rowIndex); */
NS_IMETHODIMP nsListBoxObject::EnsureIndexIsVisible(int32_t rowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollToIndex (in long rowIndex); */
NS_IMETHODIMP nsListBoxObject::ScrollToIndex(int32_t rowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollByLines (in long numLines); */
NS_IMETHODIMP nsListBoxObject::ScrollByLines(int32_t numLines)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMElement getItemAtIndex (in long index); */
NS_IMETHODIMP nsListBoxObject::GetItemAtIndex(int32_t index, nsIDOMElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfItem (in nsIDOMElement item); */
NS_IMETHODIMP nsListBoxObject::GetIndexOfItem(nsIDOMElement *item, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

nsresult
NS_NewListBoxObject(nsIBoxObject** aResult);

#endif /* __gen_nsIListBoxObject_h__ */
