/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/dom/interfaces/xul/nsIDOMXULCheckboxElement.idl
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
#define NS_IDOMXULCHECKBOXELEMENT_IID_STR "6713cd76-65ef-4883-bb58-31b2e400bb78"

#define NS_IDOMXULCHECKBOXELEMENT_IID \
  {0x6713cd76, 0x65ef, 0x4883, \
    { 0xbb, 0x58, 0x31, 0xb2, 0xe4, 0x00, 0xbb, 0x78 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULCheckboxElement : public nsIDOMXULLabeledControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCHECKBOXELEMENT_IID)

  enum { CHECKSTATE_UNCHECKED = 0 };

  enum { CHECKSTATE_CHECKED = 1 };

  enum { CHECKSTATE_MIXED = 2 };

  /* attribute boolean checked; */
  NS_SCRIPTABLE NS_IMETHOD GetChecked(PRBool *aChecked) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetChecked(PRBool aChecked) = 0;

  /* attribute long checkState; */
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState) = 0;

  /* attribute boolean autoCheck; */
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(PRBool *aAutoCheck) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(PRBool aAutoCheck) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULCheckboxElement, NS_IDOMXULCHECKBOXELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCHECKBOXELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetChecked(PRBool *aChecked); \
  NS_SCRIPTABLE NS_IMETHOD SetChecked(PRBool aChecked); \
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState); \
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState); \
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(PRBool *aAutoCheck); \
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(PRBool aAutoCheck); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCHECKBOXELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChecked(PRBool *aChecked) { return _to GetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD SetChecked(PRBool aChecked) { return _to SetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState) { return _to GetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState) { return _to SetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(PRBool *aAutoCheck) { return _to GetAutoCheck(aAutoCheck); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(PRBool aAutoCheck) { return _to SetAutoCheck(aAutoCheck); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCHECKBOXELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChecked(PRBool *aChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD SetChecked(PRBool aChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(PRBool *aAutoCheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoCheck(aAutoCheck); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(PRBool aAutoCheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutoCheck(aAutoCheck); } 

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
NS_IMETHODIMP nsDOMXULCheckboxElement::GetChecked(PRBool *aChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCheckboxElement::SetChecked(PRBool aChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long checkState; */
NS_IMETHODIMP nsDOMXULCheckboxElement::GetCheckState(PRInt32 *aCheckState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCheckboxElement::SetCheckState(PRInt32 aCheckState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean autoCheck; */
NS_IMETHODIMP nsDOMXULCheckboxElement::GetAutoCheck(PRBool *aAutoCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCheckboxElement::SetAutoCheck(PRBool aAutoCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULCheckboxElement_h__ */
