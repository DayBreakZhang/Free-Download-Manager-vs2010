/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLTableSectionElement.idl
 */

#ifndef __gen_nsIDOMHTMLTableSectionElement_h__
#define __gen_nsIDOMHTMLTableSectionElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLTableSectionElement */
#define NS_IDOMHTMLTABLESECTIONELEMENT_IID_STR "233c3242-5379-4977-81c5-58bf90743a09"

#define NS_IDOMHTMLTABLESECTIONELEMENT_IID \
  {0x233c3242, 0x5379, 0x4977, \
    { 0x81, 0xc5, 0x58, 0xbf, 0x90, 0x74, 0x3a, 0x09 }}

class NS_NO_VTABLE nsIDOMHTMLTableSectionElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLTABLESECTIONELEMENT_IID)

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

  /* attribute DOMString ch; */
  NS_IMETHOD GetCh(nsAString & aCh) = 0;
  NS_IMETHOD SetCh(const nsAString & aCh) = 0;

  /* attribute DOMString chOff; */
  NS_IMETHOD GetChOff(nsAString & aChOff) = 0;
  NS_IMETHOD SetChOff(const nsAString & aChOff) = 0;

  /* attribute DOMString vAlign; */
  NS_IMETHOD GetVAlign(nsAString & aVAlign) = 0;
  NS_IMETHOD SetVAlign(const nsAString & aVAlign) = 0;

  /* readonly attribute nsIDOMHTMLCollection rows; */
  NS_IMETHOD GetRows(nsIDOMHTMLCollection * *aRows) = 0;

  /* nsIDOMHTMLElement insertRow (in long index) raises (DOMException); */
  NS_IMETHOD InsertRow(int32_t index, nsIDOMHTMLElement * *_retval) = 0;

  /* void deleteRow (in long index) raises (DOMException); */
  NS_IMETHOD DeleteRow(int32_t index) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLTableSectionElement, NS_IDOMHTMLTABLESECTIONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLTABLESECTIONELEMENT \
  NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_IMETHOD SetAlign(const nsAString & aAlign); \
  NS_IMETHOD GetCh(nsAString & aCh); \
  NS_IMETHOD SetCh(const nsAString & aCh); \
  NS_IMETHOD GetChOff(nsAString & aChOff); \
  NS_IMETHOD SetChOff(const nsAString & aChOff); \
  NS_IMETHOD GetVAlign(nsAString & aVAlign); \
  NS_IMETHOD SetVAlign(const nsAString & aVAlign); \
  NS_IMETHOD GetRows(nsIDOMHTMLCollection * *aRows); \
  NS_IMETHOD InsertRow(int32_t index, nsIDOMHTMLElement * *_retval); \
  NS_IMETHOD DeleteRow(int32_t index); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLTABLESECTIONELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } \
  NS_IMETHOD GetCh(nsAString & aCh) { return _to GetCh(aCh); } \
  NS_IMETHOD SetCh(const nsAString & aCh) { return _to SetCh(aCh); } \
  NS_IMETHOD GetChOff(nsAString & aChOff) { return _to GetChOff(aChOff); } \
  NS_IMETHOD SetChOff(const nsAString & aChOff) { return _to SetChOff(aChOff); } \
  NS_IMETHOD GetVAlign(nsAString & aVAlign) { return _to GetVAlign(aVAlign); } \
  NS_IMETHOD SetVAlign(const nsAString & aVAlign) { return _to SetVAlign(aVAlign); } \
  NS_IMETHOD GetRows(nsIDOMHTMLCollection * *aRows) { return _to GetRows(aRows); } \
  NS_IMETHOD InsertRow(int32_t index, nsIDOMHTMLElement * *_retval) { return _to InsertRow(index, _retval); } \
  NS_IMETHOD DeleteRow(int32_t index) { return _to DeleteRow(index); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLTABLESECTIONELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } \
  NS_IMETHOD GetCh(nsAString & aCh) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCh(aCh); } \
  NS_IMETHOD SetCh(const nsAString & aCh) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCh(aCh); } \
  NS_IMETHOD GetChOff(nsAString & aChOff) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChOff(aChOff); } \
  NS_IMETHOD SetChOff(const nsAString & aChOff) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChOff(aChOff); } \
  NS_IMETHOD GetVAlign(nsAString & aVAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVAlign(aVAlign); } \
  NS_IMETHOD SetVAlign(const nsAString & aVAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVAlign(aVAlign); } \
  NS_IMETHOD GetRows(nsIDOMHTMLCollection * *aRows) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRows(aRows); } \
  NS_IMETHOD InsertRow(int32_t index, nsIDOMHTMLElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertRow(index, _retval); } \
  NS_IMETHOD DeleteRow(int32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteRow(index); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLTableSectionElement : public nsIDOMHTMLTableSectionElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLTABLESECTIONELEMENT

  nsDOMHTMLTableSectionElement();

private:
  ~nsDOMHTMLTableSectionElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLTableSectionElement, nsIDOMHTMLTableSectionElement)

nsDOMHTMLTableSectionElement::nsDOMHTMLTableSectionElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLTableSectionElement::~nsDOMHTMLTableSectionElement()
{
  /* destructor code */
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLTableSectionElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableSectionElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString ch; */
NS_IMETHODIMP nsDOMHTMLTableSectionElement::GetCh(nsAString & aCh)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableSectionElement::SetCh(const nsAString & aCh)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString chOff; */
NS_IMETHODIMP nsDOMHTMLTableSectionElement::GetChOff(nsAString & aChOff)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableSectionElement::SetChOff(const nsAString & aChOff)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString vAlign; */
NS_IMETHODIMP nsDOMHTMLTableSectionElement::GetVAlign(nsAString & aVAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableSectionElement::SetVAlign(const nsAString & aVAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection rows; */
NS_IMETHODIMP nsDOMHTMLTableSectionElement::GetRows(nsIDOMHTMLCollection * *aRows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMHTMLElement insertRow (in long index) raises (DOMException); */
NS_IMETHODIMP nsDOMHTMLTableSectionElement::InsertRow(int32_t index, nsIDOMHTMLElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteRow (in long index) raises (DOMException); */
NS_IMETHODIMP nsDOMHTMLTableSectionElement::DeleteRow(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLTableSectionElement_h__ */
