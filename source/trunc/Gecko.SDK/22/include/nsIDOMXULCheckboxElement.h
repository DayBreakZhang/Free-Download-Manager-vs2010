/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/interfaces/xul/nsIDOMXULCheckboxElement.idl
 */

#ifndef __gen_nsIDOMXULCheckboxElement_h__
#define __gen_nsIDOMXULCheckboxElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

#ifndef __gen_nsIDOMXULLabeledControlEl_h__
#include "nsIDOMXULLabeledControlEl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULCheckboxElement */
#define NS_IDOMXULCHECKBOXELEMENT_IID_STR "b0539219-67c8-47c1-934c-08040701b33b"

#define NS_IDOMXULCHECKBOXELEMENT_IID \
  {0xb0539219, 0x67c8, 0x47c1, \
    { 0x93, 0x4c, 0x08, 0x04, 0x07, 0x01, 0xb3, 0x3b }}

class NS_NO_VTABLE nsIDOMXULCheckboxElement : public nsIDOMXULLabeledControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCHECKBOXELEMENT_IID)

  enum {
    CHECKSTATE_UNCHECKED = 0,
    CHECKSTATE_CHECKED = 1,
    CHECKSTATE_MIXED = 2
  };

  /* attribute boolean checked; */
  NS_IMETHOD GetChecked(bool *aChecked) = 0;
  NS_IMETHOD SetChecked(bool aChecked) = 0;

  /* attribute long checkState; */
  NS_IMETHOD GetCheckState(int32_t *aCheckState) = 0;
  NS_IMETHOD SetCheckState(int32_t aCheckState) = 0;

  /* attribute boolean autoCheck; */
  NS_IMETHOD GetAutoCheck(bool *aAutoCheck) = 0;
  NS_IMETHOD SetAutoCheck(bool aAutoCheck) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULCheckboxElement, NS_IDOMXULCHECKBOXELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCHECKBOXELEMENT \
  NS_IMETHOD GetChecked(bool *aChecked); \
  NS_IMETHOD SetChecked(bool aChecked); \
  NS_IMETHOD GetCheckState(int32_t *aCheckState); \
  NS_IMETHOD SetCheckState(int32_t aCheckState); \
  NS_IMETHOD GetAutoCheck(bool *aAutoCheck); \
  NS_IMETHOD SetAutoCheck(bool aAutoCheck); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCHECKBOXELEMENT(_to) \
  NS_IMETHOD GetChecked(bool *aChecked) { return _to GetChecked(aChecked); } \
  NS_IMETHOD SetChecked(bool aChecked) { return _to SetChecked(aChecked); } \
  NS_IMETHOD GetCheckState(int32_t *aCheckState) { return _to GetCheckState(aCheckState); } \
  NS_IMETHOD SetCheckState(int32_t aCheckState) { return _to SetCheckState(aCheckState); } \
  NS_IMETHOD GetAutoCheck(bool *aAutoCheck) { return _to GetAutoCheck(aAutoCheck); } \
  NS_IMETHOD SetAutoCheck(bool aAutoCheck) { return _to SetAutoCheck(aAutoCheck); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCHECKBOXELEMENT(_to) \
  NS_IMETHOD GetChecked(bool *aChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChecked(aChecked); } \
  NS_IMETHOD SetChecked(bool aChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChecked(aChecked); } \
  NS_IMETHOD GetCheckState(int32_t *aCheckState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCheckState(aCheckState); } \
  NS_IMETHOD SetCheckState(int32_t aCheckState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCheckState(aCheckState); } \
  NS_IMETHOD GetAutoCheck(bool *aAutoCheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoCheck(aAutoCheck); } \
  NS_IMETHOD SetAutoCheck(bool aAutoCheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutoCheck(aAutoCheck); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULCheckboxElement : public nsIDOMXULCheckboxElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCHECKBOXELEMENT

  nsDOMXULCheckboxElement();

private:
  ~nsDOMXULCheckboxElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULCheckboxElement, nsIDOMXULCheckboxElement)

nsDOMXULCheckboxElement::nsDOMXULCheckboxElement()
{
  /* member initializers and constructor code */
}

nsDOMXULCheckboxElement::~nsDOMXULCheckboxElement()
{
  /* destructor code */
}

/* attribute boolean checked; */
NS_IMETHODIMP nsDOMXULCheckboxElement::GetChecked(bool *aChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCheckboxElement::SetChecked(bool aChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long checkState; */
NS_IMETHODIMP nsDOMXULCheckboxElement::GetCheckState(int32_t *aCheckState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCheckboxElement::SetCheckState(int32_t aCheckState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean autoCheck; */
NS_IMETHODIMP nsDOMXULCheckboxElement::GetAutoCheck(bool *aAutoCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCheckboxElement::SetAutoCheck(bool aAutoCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULCheckboxElement_h__ */
