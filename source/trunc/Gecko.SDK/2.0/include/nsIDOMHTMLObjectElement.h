/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/html/nsIDOMHTMLObjectElement.idl
 */

#ifndef __gen_nsIDOMHTMLObjectElement_h__
#define __gen_nsIDOMHTMLObjectElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMValidityState; /* forward declaration */


/* starting interface:    nsIDOMHTMLObjectElement */
#define NS_IDOMHTMLOBJECTELEMENT_IID_STR "9b93aab4-7fe8-4f79-9ad2-0623178a0c46"

#define NS_IDOMHTMLOBJECTELEMENT_IID \
  {0x9b93aab4, 0x7fe8, 0x4f79, \
    { 0x9a, 0xd2, 0x06, 0x23, 0x17, 0x8a, 0x0c, 0x46 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLObjectElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLOBJECTELEMENT_IID)

  /* readonly attribute nsIDOMHTMLFormElement form; */
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) = 0;

  /* attribute DOMString code; */
  NS_SCRIPTABLE NS_IMETHOD GetCode(nsAString & aCode) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCode(const nsAString & aCode) = 0;

  /* attribute DOMString align; */
  NS_SCRIPTABLE NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

  /* attribute DOMString archive; */
  NS_SCRIPTABLE NS_IMETHOD GetArchive(nsAString & aArchive) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetArchive(const nsAString & aArchive) = 0;

  /* attribute DOMString border; */
  NS_SCRIPTABLE NS_IMETHOD GetBorder(nsAString & aBorder) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetBorder(const nsAString & aBorder) = 0;

  /* attribute DOMString codeBase; */
  NS_SCRIPTABLE NS_IMETHOD GetCodeBase(nsAString & aCodeBase) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCodeBase(const nsAString & aCodeBase) = 0;

  /* attribute DOMString codeType; */
  NS_SCRIPTABLE NS_IMETHOD GetCodeType(nsAString & aCodeType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCodeType(const nsAString & aCodeType) = 0;

  /* attribute DOMString data; */
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & aData) = 0;

  /* attribute boolean declare; */
  NS_SCRIPTABLE NS_IMETHOD GetDeclare(PRBool *aDeclare) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDeclare(PRBool aDeclare) = 0;

  /* attribute DOMString height; */
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsAString & aHeight) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHeight(const nsAString & aHeight) = 0;

  /* attribute long hspace; */
  NS_SCRIPTABLE NS_IMETHOD GetHspace(PRInt32 *aHspace) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHspace(PRInt32 aHspace) = 0;

  /* attribute DOMString name; */
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) = 0;

  /* attribute DOMString standby; */
  NS_SCRIPTABLE NS_IMETHOD GetStandby(nsAString & aStandby) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetStandby(const nsAString & aStandby) = 0;

  /* attribute long tabIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) = 0;

  /* attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute DOMString useMap; */
  NS_SCRIPTABLE NS_IMETHOD GetUseMap(nsAString & aUseMap) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUseMap(const nsAString & aUseMap) = 0;

  /* attribute long vspace; */
  NS_SCRIPTABLE NS_IMETHOD GetVspace(PRInt32 *aVspace) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetVspace(PRInt32 aVspace) = 0;

  /* attribute DOMString width; */
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsAString & aWidth) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetWidth(const nsAString & aWidth) = 0;

  /* readonly attribute nsIDOMDocument contentDocument; */
  NS_SCRIPTABLE NS_IMETHOD GetContentDocument(nsIDOMDocument **aContentDocument) = 0;

  /* readonly attribute boolean willValidate; */
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) = 0;

  /* readonly attribute nsIDOMValidityState validity; */
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) = 0;

  /* readonly attribute DOMString validationMessage; */
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) = 0;

  /* boolean checkValidity (); */
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) = 0;

  /* void setCustomValidity (in DOMString error); */
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLObjectElement, NS_IDOMHTMLOBJECTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLOBJECTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm); \
  NS_SCRIPTABLE NS_IMETHOD GetCode(nsAString & aCode); \
  NS_SCRIPTABLE NS_IMETHOD SetCode(const nsAString & aCode); \
  NS_SCRIPTABLE NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_SCRIPTABLE NS_IMETHOD SetAlign(const nsAString & aAlign); \
  NS_SCRIPTABLE NS_IMETHOD GetArchive(nsAString & aArchive); \
  NS_SCRIPTABLE NS_IMETHOD SetArchive(const nsAString & aArchive); \
  NS_SCRIPTABLE NS_IMETHOD GetBorder(nsAString & aBorder); \
  NS_SCRIPTABLE NS_IMETHOD SetBorder(const nsAString & aBorder); \
  NS_SCRIPTABLE NS_IMETHOD GetCodeBase(nsAString & aCodeBase); \
  NS_SCRIPTABLE NS_IMETHOD SetCodeBase(const nsAString & aCodeBase); \
  NS_SCRIPTABLE NS_IMETHOD GetCodeType(nsAString & aCodeType); \
  NS_SCRIPTABLE NS_IMETHOD SetCodeType(const nsAString & aCodeType); \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData); \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & aData); \
  NS_SCRIPTABLE NS_IMETHOD GetDeclare(PRBool *aDeclare); \
  NS_SCRIPTABLE NS_IMETHOD SetDeclare(PRBool aDeclare); \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsAString & aHeight); \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(const nsAString & aHeight); \
  NS_SCRIPTABLE NS_IMETHOD GetHspace(PRInt32 *aHspace); \
  NS_SCRIPTABLE NS_IMETHOD SetHspace(PRInt32 aHspace); \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName); \
  NS_SCRIPTABLE NS_IMETHOD GetStandby(nsAString & aStandby); \
  NS_SCRIPTABLE NS_IMETHOD SetStandby(const nsAString & aStandby); \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetUseMap(nsAString & aUseMap); \
  NS_SCRIPTABLE NS_IMETHOD SetUseMap(const nsAString & aUseMap); \
  NS_SCRIPTABLE NS_IMETHOD GetVspace(PRInt32 *aVspace); \
  NS_SCRIPTABLE NS_IMETHOD SetVspace(PRInt32 aVspace); \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsAString & aWidth); \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(const nsAString & aWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetContentDocument(nsIDOMDocument **aContentDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate); \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity); \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage); \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLOBJECTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) { return _to GetForm(aForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetCode(nsAString & aCode) { return _to GetCode(aCode); } \
  NS_SCRIPTABLE NS_IMETHOD SetCode(const nsAString & aCode) { return _to SetCode(aCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD GetArchive(nsAString & aArchive) { return _to GetArchive(aArchive); } \
  NS_SCRIPTABLE NS_IMETHOD SetArchive(const nsAString & aArchive) { return _to SetArchive(aArchive); } \
  NS_SCRIPTABLE NS_IMETHOD GetBorder(nsAString & aBorder) { return _to GetBorder(aBorder); } \
  NS_SCRIPTABLE NS_IMETHOD SetBorder(const nsAString & aBorder) { return _to SetBorder(aBorder); } \
  NS_SCRIPTABLE NS_IMETHOD GetCodeBase(nsAString & aCodeBase) { return _to GetCodeBase(aCodeBase); } \
  NS_SCRIPTABLE NS_IMETHOD SetCodeBase(const nsAString & aCodeBase) { return _to SetCodeBase(aCodeBase); } \
  NS_SCRIPTABLE NS_IMETHOD GetCodeType(nsAString & aCodeType) { return _to GetCodeType(aCodeType); } \
  NS_SCRIPTABLE NS_IMETHOD SetCodeType(const nsAString & aCodeType) { return _to SetCodeType(aCodeType); } \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) { return _to GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & aData) { return _to SetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetDeclare(PRBool *aDeclare) { return _to GetDeclare(aDeclare); } \
  NS_SCRIPTABLE NS_IMETHOD SetDeclare(PRBool aDeclare) { return _to SetDeclare(aDeclare); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsAString & aHeight) { return _to GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(const nsAString & aHeight) { return _to SetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetHspace(PRInt32 *aHspace) { return _to GetHspace(aHspace); } \
  NS_SCRIPTABLE NS_IMETHOD SetHspace(PRInt32 aHspace) { return _to SetHspace(aHspace); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return _to GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return _to SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetStandby(nsAString & aStandby) { return _to GetStandby(aStandby); } \
  NS_SCRIPTABLE NS_IMETHOD SetStandby(const nsAString & aStandby) { return _to SetStandby(aStandby); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) { return _to GetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) { return _to SetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetUseMap(nsAString & aUseMap) { return _to GetUseMap(aUseMap); } \
  NS_SCRIPTABLE NS_IMETHOD SetUseMap(const nsAString & aUseMap) { return _to SetUseMap(aUseMap); } \
  NS_SCRIPTABLE NS_IMETHOD GetVspace(PRInt32 *aVspace) { return _to GetVspace(aVspace); } \
  NS_SCRIPTABLE NS_IMETHOD SetVspace(PRInt32 aVspace) { return _to SetVspace(aVspace); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsAString & aWidth) { return _to GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(const nsAString & aWidth) { return _to SetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentDocument(nsIDOMDocument **aContentDocument) { return _to GetContentDocument(aContentDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) { return _to GetWillValidate(aWillValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) { return _to GetValidity(aValidity); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return _to GetValidationMessage(aValidationMessage); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return _to CheckValidity(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) { return _to SetCustomValidity(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLOBJECTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetForm(nsIDOMHTMLFormElement **aForm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForm(aForm); } \
  NS_SCRIPTABLE NS_IMETHOD GetCode(nsAString & aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCode(aCode); } \
  NS_SCRIPTABLE NS_IMETHOD SetCode(const nsAString & aCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCode(aCode); } \
  NS_SCRIPTABLE NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } \
  NS_SCRIPTABLE NS_IMETHOD GetArchive(nsAString & aArchive) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetArchive(aArchive); } \
  NS_SCRIPTABLE NS_IMETHOD SetArchive(const nsAString & aArchive) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetArchive(aArchive); } \
  NS_SCRIPTABLE NS_IMETHOD GetBorder(nsAString & aBorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBorder(aBorder); } \
  NS_SCRIPTABLE NS_IMETHOD SetBorder(const nsAString & aBorder) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBorder(aBorder); } \
  NS_SCRIPTABLE NS_IMETHOD GetCodeBase(nsAString & aCodeBase) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCodeBase(aCodeBase); } \
  NS_SCRIPTABLE NS_IMETHOD SetCodeBase(const nsAString & aCodeBase) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCodeBase(aCodeBase); } \
  NS_SCRIPTABLE NS_IMETHOD GetCodeType(nsAString & aCodeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCodeType(aCodeType); } \
  NS_SCRIPTABLE NS_IMETHOD SetCodeType(const nsAString & aCodeType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCodeType(aCodeType); } \
  NS_SCRIPTABLE NS_IMETHOD GetData(nsAString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD SetData(const nsAString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetData(aData); } \
  NS_SCRIPTABLE NS_IMETHOD GetDeclare(PRBool *aDeclare) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeclare(aDeclare); } \
  NS_SCRIPTABLE NS_IMETHOD SetDeclare(PRBool aDeclare) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDeclare(aDeclare); } \
  NS_SCRIPTABLE NS_IMETHOD GetHeight(nsAString & aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD SetHeight(const nsAString & aHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHeight(aHeight); } \
  NS_SCRIPTABLE NS_IMETHOD GetHspace(PRInt32 *aHspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHspace(aHspace); } \
  NS_SCRIPTABLE NS_IMETHOD SetHspace(PRInt32 aHspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHspace(aHspace); } \
  NS_SCRIPTABLE NS_IMETHOD GetName(nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD SetName(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_SCRIPTABLE NS_IMETHOD GetStandby(nsAString & aStandby) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStandby(aStandby); } \
  NS_SCRIPTABLE NS_IMETHOD SetStandby(const nsAString & aStandby) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStandby(aStandby); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetUseMap(nsAString & aUseMap) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUseMap(aUseMap); } \
  NS_SCRIPTABLE NS_IMETHOD SetUseMap(const nsAString & aUseMap) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUseMap(aUseMap); } \
  NS_SCRIPTABLE NS_IMETHOD GetVspace(PRInt32 *aVspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVspace(aVspace); } \
  NS_SCRIPTABLE NS_IMETHOD SetVspace(PRInt32 aVspace) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetVspace(aVspace); } \
  NS_SCRIPTABLE NS_IMETHOD GetWidth(nsAString & aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD SetWidth(const nsAString & aWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWidth(aWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentDocument(nsIDOMDocument **aContentDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentDocument(aContentDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetWillValidate(PRBool *aWillValidate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWillValidate(aWillValidate); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidity(nsIDOMValidityState **aValidity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidity(aValidity); } \
  NS_SCRIPTABLE NS_IMETHOD GetValidationMessage(nsAString & aValidationMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValidationMessage(aValidationMessage); } \
  NS_SCRIPTABLE NS_IMETHOD CheckValidity(PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckValidity(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetCustomValidity(const nsAString & error) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCustomValidity(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLObjectElement : public nsIDOMHTMLObjectElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLOBJECTELEMENT

  nsDOMHTMLObjectElement();

private:
  ~nsDOMHTMLObjectElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLObjectElement, nsIDOMHTMLObjectElement)

nsDOMHTMLObjectElement::nsDOMHTMLObjectElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLObjectElement::~nsDOMHTMLObjectElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMHTMLFormElement form; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetForm(nsIDOMHTMLFormElement **aForm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString code; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetCode(nsAString & aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetCode(const nsAString & aCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString archive; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetArchive(nsAString & aArchive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetArchive(const nsAString & aArchive)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString border; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetBorder(nsAString & aBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetBorder(const nsAString & aBorder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString codeBase; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetCodeBase(nsAString & aCodeBase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetCodeBase(const nsAString & aCodeBase)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString codeType; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetCodeType(nsAString & aCodeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetCodeType(const nsAString & aCodeType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString data; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetData(nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetData(const nsAString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean declare; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetDeclare(PRBool *aDeclare)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetDeclare(PRBool aDeclare)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString height; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetHeight(nsAString & aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetHeight(const nsAString & aHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long hspace; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetHspace(PRInt32 *aHspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetHspace(PRInt32 aHspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString name; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetName(nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetName(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString standby; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetStandby(nsAString & aStandby)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetStandby(const nsAString & aStandby)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long tabIndex; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetTabIndex(PRInt32 *aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetTabIndex(PRInt32 aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString useMap; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetUseMap(nsAString & aUseMap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetUseMap(const nsAString & aUseMap)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long vspace; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetVspace(PRInt32 *aVspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetVspace(PRInt32 aVspace)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString width; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetWidth(nsAString & aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLObjectElement::SetWidth(const nsAString & aWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDocument contentDocument; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetContentDocument(nsIDOMDocument **aContentDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean willValidate; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetWillValidate(PRBool *aWillValidate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMValidityState validity; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetValidity(nsIDOMValidityState **aValidity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString validationMessage; */
NS_IMETHODIMP nsDOMHTMLObjectElement::GetValidationMessage(nsAString & aValidationMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkValidity (); */
NS_IMETHODIMP nsDOMHTMLObjectElement::CheckValidity(PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCustomValidity (in DOMString error); */
NS_IMETHODIMP nsDOMHTMLObjectElement::SetCustomValidity(const nsAString & error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLObjectElement_h__ */
