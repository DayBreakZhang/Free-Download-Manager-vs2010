/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/html/nsIDOMHTMLTableRowElement.idl
 */

#ifndef __gen_nsIDOMHTMLTableRowElement_h__
#define __gen_nsIDOMHTMLTableRowElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLTableRowElement */
#define NS_IDOMHTMLTABLEROWELEMENT_IID_STR "ccbaf4d5-1c2d-4edb-9faf-094e357da044"

#define NS_IDOMHTMLTABLEROWELEMENT_IID \
  {0xccbaf4d5, 0x1c2d, 0x4edb, \
    { 0x9f, 0xaf, 0x09, 0x4e, 0x35, 0x7d, 0xa0, 0x44 }}

class NS_NO_VTABLE nsIDOMHTMLTableRowElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLTABLEROWELEMENT_IID)

  /* readonly attribute long rowIndex; */
  NS_IMETHOD GetRowIndex(int32_t *aRowIndex) = 0;

  /* readonly attribute long sectionRowIndex; */
  NS_IMETHOD GetSectionRowIndex(int32_t *aSectionRowIndex) = 0;

  /* readonly attribute nsIDOMHTMLCollection cells; */
  NS_IMETHOD GetCells(nsIDOMHTMLCollection * *aCells) = 0;

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

  /* attribute DOMString bgColor; */
  NS_IMETHOD GetBgColor(nsAString & aBgColor) = 0;
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) = 0;

  /* attribute DOMString ch; */
  NS_IMETHOD GetCh(nsAString & aCh) = 0;
  NS_IMETHOD SetCh(const nsAString & aCh) = 0;

  /* attribute DOMString chOff; */
  NS_IMETHOD GetChOff(nsAString & aChOff) = 0;
  NS_IMETHOD SetChOff(const nsAString & aChOff) = 0;

  /* attribute DOMString vAlign; */
  NS_IMETHOD GetVAlign(nsAString & aVAlign) = 0;
  NS_IMETHOD SetVAlign(const nsAString & aVAlign) = 0;

  /* nsIDOMHTMLElement insertCell (in long index) raises (DOMException); */
  NS_IMETHOD InsertCell(int32_t index, nsIDOMHTMLElement * *_retval) = 0;

  /* void deleteCell (in long index) raises (DOMException); */
  NS_IMETHOD DeleteCell(int32_t index) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLTableRowElement, NS_IDOMHTMLTABLEROWELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLTABLEROWELEMENT \
  NS_IMETHOD GetRowIndex(int32_t *aRowIndex); \
  NS_IMETHOD GetSectionRowIndex(int32_t *aSectionRowIndex); \
  NS_IMETHOD GetCells(nsIDOMHTMLCollection * *aCells); \
  NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_IMETHOD SetAlign(const nsAString & aAlign); \
  NS_IMETHOD GetBgColor(nsAString & aBgColor); \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor); \
  NS_IMETHOD GetCh(nsAString & aCh); \
  NS_IMETHOD SetCh(const nsAString & aCh); \
  NS_IMETHOD GetChOff(nsAString & aChOff); \
  NS_IMETHOD SetChOff(const nsAString & aChOff); \
  NS_IMETHOD GetVAlign(nsAString & aVAlign); \
  NS_IMETHOD SetVAlign(const nsAString & aVAlign); \
  NS_IMETHOD InsertCell(int32_t index, nsIDOMHTMLElement * *_retval); \
  NS_IMETHOD DeleteCell(int32_t index); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLTABLEROWELEMENT(_to) \
  NS_IMETHOD GetRowIndex(int32_t *aRowIndex) { return _to GetRowIndex(aRowIndex); } \
  NS_IMETHOD GetSectionRowIndex(int32_t *aSectionRowIndex) { return _to GetSectionRowIndex(aSectionRowIndex); } \
  NS_IMETHOD GetCells(nsIDOMHTMLCollection * *aCells) { return _to GetCells(aCells); } \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } \
  NS_IMETHOD GetBgColor(nsAString & aBgColor) { return _to GetBgColor(aBgColor); } \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) { return _to SetBgColor(aBgColor); } \
  NS_IMETHOD GetCh(nsAString & aCh) { return _to GetCh(aCh); } \
  NS_IMETHOD SetCh(const nsAString & aCh) { return _to SetCh(aCh); } \
  NS_IMETHOD GetChOff(nsAString & aChOff) { return _to GetChOff(aChOff); } \
  NS_IMETHOD SetChOff(const nsAString & aChOff) { return _to SetChOff(aChOff); } \
  NS_IMETHOD GetVAlign(nsAString & aVAlign) { return _to GetVAlign(aVAlign); } \
  NS_IMETHOD SetVAlign(const nsAString & aVAlign) { return _to SetVAlign(aVAlign); } \
  NS_IMETHOD InsertCell(int32_t index, nsIDOMHTMLElement * *_retval) { return _to InsertCell(index, _retval); } \
  NS_IMETHOD DeleteCell(int32_t index) { return _to DeleteCell(index); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLTABLEROWELEMENT(_to) \
  NS_IMETHOD GetRowIndex(int32_t *aRowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRowIndex(aRowIndex); } \
  NS_IMETHOD GetSectionRowIndex(int32_t *aSectionRowIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSectionRowIndex(aSectionRowIndex); } \
  NS_IMETHOD GetCells(nsIDOMHTMLCollection * *aCells) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCells(aCells); } \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } \
  NS_IMETHOD GetBgColor(nsAString & aBgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBgColor(aBgColor); } \
  NS_IMETHOD SetBgColor(const nsAString & aBgColor) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBgColor(aBgColor); } \
  NS_IMETHOD GetCh(nsAString & aCh) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCh(aCh); } \
  NS_IMETHOD SetCh(const nsAString & aCh) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCh(aCh); } \
  NS_IMETHOD GetChOff(nsAString & aChOff) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChOff(aChOff); } \
  NS_IMETHOD SetChOff(const nsAString & aChOff) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChOff(aChOff); } \
  NS_IMETHOD GetVAlign(nsAString & aVAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVAlign(aVAlign); } \
  NS_IMETHOD SetVAlign(const nsAString & aVAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVAlign(aVAlign); } \
  NS_IMETHOD InsertCell(int32_t index, nsIDOMHTMLElement * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertCell(index, _retval); } \
  NS_IMETHOD DeleteCell(int32_t index) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteCell(index); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLTableRowElement : public nsIDOMHTMLTableRowElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLTABLEROWELEMENT

  nsDOMHTMLTableRowElement();

private:
  ~nsDOMHTMLTableRowElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLTableRowElement, nsIDOMHTMLTableRowElement)

nsDOMHTMLTableRowElement::nsDOMHTMLTableRowElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLTableRowElement::~nsDOMHTMLTableRowElement()
{
  /* destructor code */
}

/* readonly attribute long rowIndex; */
NS_IMETHODIMP nsDOMHTMLTableRowElement::GetRowIndex(int32_t *aRowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long sectionRowIndex; */
NS_IMETHODIMP nsDOMHTMLTableRowElement::GetSectionRowIndex(int32_t *aSectionRowIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLCollection cells; */
NS_IMETHODIMP nsDOMHTMLTableRowElement::GetCells(nsIDOMHTMLCollection * *aCells)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLTableRowElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableRowElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString bgColor; */
NS_IMETHODIMP nsDOMHTMLTableRowElement::GetBgColor(nsAString & aBgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableRowElement::SetBgColor(const nsAString & aBgColor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString ch; */
NS_IMETHODIMP nsDOMHTMLTableRowElement::GetCh(nsAString & aCh)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableRowElement::SetCh(const nsAString & aCh)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString chOff; */
NS_IMETHODIMP nsDOMHTMLTableRowElement::GetChOff(nsAString & aChOff)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableRowElement::SetChOff(const nsAString & aChOff)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString vAlign; */
NS_IMETHODIMP nsDOMHTMLTableRowElement::GetVAlign(nsAString & aVAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLTableRowElement::SetVAlign(const nsAString & aVAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMHTMLElement insertCell (in long index) raises (DOMException); */
NS_IMETHODIMP nsDOMHTMLTableRowElement::InsertCell(int32_t index, nsIDOMHTMLElement * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteCell (in long index) raises (DOMException); */
NS_IMETHODIMP nsDOMHTMLTableRowElement::DeleteCell(int32_t index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLTableRowElement_h__ */
